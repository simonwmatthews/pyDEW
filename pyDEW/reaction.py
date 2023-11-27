from pyDEW import core
from pyDEW import eq6_output

import numpy as np
import os


class reaction:
    """ Class for enabling EQ6 calculations. The working directory will be the same as used when
    generating the Fluid.

    Attributes
    ----------

    Parameters
    ----------
    fluid : pyDEW.Fluid object
        The fluid object to react with
    t : float
        The temperature (K)
    p : float
        The pressure (bars)
    reactants : list of dicts, default: []
        The reactants for the calculation. The dicts should be formatted with keys and values:
        - reactant (str)
          The name of the mineral
        - moles (float)
          The moles in the reaction (relative to 1 kg of water)
        - composition (dict)
          If the mineral is a solid solution this must be provided. Each endmember should be given
          as a key, and its mole-fraction as the value.
    bulk_composition : dict, default: {}
        A bulk composition (units specified by bulk_composition_units argument) to be added to the 
        reaction. This uses EQ6's special reactant feature.
    bulk_composition_units : str, default: 'mol_elements'
        The units the bulk composition has been provided in. One of:
        - 'mol_elements' : the mole fraction of elements in the bulk composition (including O). The
          keys of the bulk_composition should be element names of the System (as they appear in DATA0, 
          probably capitalised). EQ6 will normalise to 1.
        - 'wtpt_oxides' : Wt% of oxides. No need to normalise (EQ6 will normalise mole fraction to 1).
    mols_bulk_composition : float, default : 1.0
        The total moles of the bulk composition to add during the reaction (assuming zimax is 
        sufficiently high).
    dT : float
        The temperature change during the calculation (K)
    calculation_mode : str, default: 'closed'
        The EQ6 calculation mode to use. Must be one of:
        - 'closed'
          The fluid will react with a the specified minerals in a closed system.
        - 'titration'
          The minerals will be added step wise, as if being titrated into the fluid. The code
          does not currently support titration of one fluid into another, as allowed in EQ6.
        - 'open'
          Fluid-centered flow-through open system. The fluid will flow through a solid mineral
          assemblage, react with that assemblage, produce secondary minerals, and then continue.
          The secondary minerals are lost at each stage.
    point_calculation : bool, default: False
        Run a point calculation or not. Equivalent to running only the first step of a reaction
        path- i.e., allowing an EQ3 fluid to equilibrate by precipitating minerals.
    zimax : float, default: 1.0
        The maximum reaction progress.
    eq3_working_directory : string, default: 'working'
        The directory where the EQ3 pickup file is located.
    eqpt_working_directory : string, default: 'working'
        The directory where DATA0 should be generated, and EQPT should be run.
    eqpt_executable_name : string or None, default: None
        Use to specify a particular EQPT executable to use, otherwise (if set to None) a version of
        EQPT will be copied into the working directory, according to the operating system in use.
    eq6_executable_name : str or None, default: None
        Use to specify a particular version of EQ6 to use, otherwise (if set to None) a version
        of EQ3 will be copied into the working directory, according to the operating system
        in use.
    dummy_temperature : float, default = 500.0
        The dummy temperature (in degC) to provide DATA0 if the pyDEW format is being used. This
        value is just provided to the EQ3/EQ6 interpolation routine, and should have no influence
        on the calculation results. An exception to this is carbon species in some versions of
        EQ3.

    """

    def __init__(self,
                 fluid,
                 T,
                 P,
                 reactants=[],
                 bulk_composition={},
                 bulk_composition_units='mol_elements',
                 mols_bulk_composition=1.0,
                 dT=0.0,
                 calculation_mode='closed',
                 point_calculation=False,
                 zimax=1.0,
                 eq6_executable_name=None,
                 eq3_working_directory='working',
                 eqpt_working_directory='working',
                 eq6_working_directory='working',
                 eqpt_executable_name=None,
                 dummy_temperature=300.0
                 ):
        self.fluid = fluid
        self.calculation_mode = calculation_mode
        self.T = T
        self.P = P
        self.dT = dT
        self.reactants = reactants
        self.calculation_mode = calculation_mode
        self.zimax = zimax
        self.dummy_temperature = dummy_temperature
        self.output = None
        self.point_calculation = point_calculation


        # PROCESS BULK COMP
        if bulk_composition_units == 'wtpt_oxides':
            self.bulk_composition = core.convert_wtptoxides_to_mol_elements(bulk_composition)
        elif bulk_composition_units == 'mol_elements':
            self.bulk_composition = bulk_composition
        else:
            raise core.InputError(
                'Bulk composition unit type "{}" not recognised. '
                'Use one of "wtpt_oxides" or "mol_elements"'.format(bulk_composition_units)
                )
        self.mols_bulk_composition = mols_bulk_composition

        pickup = self.fluid.pickup

        # Check if pressure is the same as fluid, if not, regenerate DATA0 and run EQPT
        # Also need to re-run DATA0 if there is a temperature change during the calculation.
        if self.P != self.fluid.P or self.dT != 0.0 or self.T != self.fluid.T:
            if core.operatingsystem == 'Darwin':
                data0_filename = 'DATA0'
            elif core.operatingsystem == 'Linux':
                data0_filename = 'data0'

            if self.dT == 0.0:
                self.fluid.system.make_data0(self.T, self.P, format='pyDEW',
                                             filepath=eqpt_working_directory+'/'+data0_filename,
                                             dummy_temperature = self.dummy_temperature)
            else:
                if dT < 0:
                    t = self.T - 2*dT
                else:
                    t = self.T
                self.fluid.system.make_data0(t, self.P, format=='traditional',
                                             filepath=eqpt_working_directory+'/'+data0_filename)

            # Create the working directory if it doesn't exist:
            if not os.path.isdir(eqpt_working_directory):
                os.makedirs(eqpt_working_directory)

            # Run EQPT
            core.run_eqpt(working_directory=eqpt_working_directory,
                          executable_name=eqpt_executable_name)

        # Make the input file
        if dT == 0 and self.T == self.fluid.T:
            self._make_input(pickup, self.dummy_temperature+273.15, self.reactants, self.dT,
                             self.calculation_mode, self.zimax, self.bulk_composition,
                             self.mols_bulk_composition, eq6_working_directory)
        else:
            self._make_input(pickup, self.T, self.reactants, self.dT,
                             self.calculation_mode, self.zimax, self.bulk_composition,
                             self.mols_bulk_composition,  eq6_working_directory)

        # Run EQ6
        core.run_eq6(eq6_working_directory, eq6_executable_name)

        # Read the output file
        self.output = eq6_output.eq6output(fluid,
                                           tab_filepath=eq6_working_directory+'/tab',
                                           output_filepath=eq6_working_directory+'/output')
        self.minerals = self.output.minerals
        self.solid_solutions = self.output.solid_solutions
        self.elements = self.output.elements
        self.species_concs = self.output.species_concs
        self.logzi = np.array(self.output.table_pH.index)
        self.pH = np.array(self.output.pH)
        self.T = np.array(self.output.T)
        self.fO2 = np.array(self.output.fO2)


    def _read_pickup(self,directory):
        """
        Read the EQ3 pickup file generated when the Fluid class was generated.

        THIS IS NOW REDUNDANT, BUT IS RETAINED HERE IN CASE THE FACILITY TO USE AN 
        EQ6 PICKUP IS ADDED.

        Parameters
        ----------
        directory : str
            The directory in which the pickup file is stored.
        Returns
        -------
        str
            The contents of the pickup file
        """

        if os.path.isfile(directory+'/pickup'):
            text_file = open(directory+'/pickup', 'r')
            pickup = text_file.read()
            text_file.close()
            return pickup
        else:
            raise core.InputError('The EQ3 pickup file was not found.')

    def _make_input(self, pickup, t, reactants, dt, calculation_mode, zimax,
                    bulk_composition, mols_bulk_composition,
                    eq6_working_directory):
        """
        Make the EQ6 input file, and save in the specified directory.

        Parameters
        ----------
        pickup : str
            The contents of the EQ3 pickup file.
        t : float
            The temperature (in K).
        reactants : list of dicts
            The reactants and their molar proportions (see class definition).
        dt : float
            The temperature change during the calculation (in K).
        calculation_mode : str
            The calculation mode, see the class definition.
        zimax : float
            The reaction progress
        """

        s = ''
        s = self._input_preamble(s)
        s = self._input_setup(s, calculation_mode, t, dt, zimax, reactants,
                              bulk_composition, mols_bulk_composition)
        if len(bulk_composition) > 0:
            s = self._input_specialreactant(s, bulk_composition, mols_bulk_composition)
        for reactant in reactants:
            s = self._input_reactant(s, reactant)
        s = self._input_parameters(s)
        s += pickup

        file = open(eq6_working_directory+'/input','w')
        file.write(s)
        file.close()

    def _input_preamble(self, s):
        s += '\n'*16 + 'endit. \n'
        return s

    def _input_setup(self, s, calculation_mode, t, dt, zimax, reactants, bulk_composition,
                     mols_bulk_composition):
        if calculation_mode == 'titration':
            mode_int = '1'
        elif calculation_mode == 'closed':
            mode_int = '2'
        elif calculation_mode == 'open':
            mode_int = '3'
        else:
            raise core.InputError('Calculation mode not recognised.')

        s += '    nmodl1=  ' + mode_int + '              nmodl2=  0\n'

        t_string = '{:.1f}'.format(t-273.15)
        s += '    tempc0=' + (12 - len(t_string.split('.')[0]))*' ' + t_string
        s += (5-len(t_string.split('.')[1]))*' ' + 'jtemp=  0\n'

        dt_string = '{:.1f}'.format(dt)
        s += '       tk1=' + \
            (12 - len(dt_string.split('.')[0]))*' ' + dt_string
        s += ((7-len(dt_string.split('.')[1]))*' ' +
              'tk2=           0.       tk3=           0.\n')

        zi_string = '{:.1f}'.format(zimax)
        s += '    zistrt=          0.0     zimax=' + \
            (10 - len(zi_string.split('.')[0]))*' '
        s += zi_string + ' \n'

        s += '     tstrt=           0.    timemx=           0. \n'

        if self.point_calculation is False:
            s += '    kstpmx=        10000     cplim=           0. \n'
        else:
            s += '    kstpmx=            0     cplim=           0. \n'
        s += '     dzipr=       1.e+38    dzprlg=         0.05    ksppmx= 10000 \n'
        s += '    dzplot=       1.e+38    dzpllg=       10000.    ksplmx= 10000 \n'
        s += '     ifile= 60 \n'
        s += '  iopt1-10=     0    0    0    1    0    0    0    0    0    0 \n'
        s += '     11-20=     0    0 \n'
        s += '  iopr1-10=     0    0    0    0    1    0    0    1    0    0 \n'
        s += '     11-20=     0    0 \n'
        s += '  iodb1-10=     0    0    0    0    0    0    0    0    0    0 \n'
        s += '     11-20=     0    0    0 \n'
        s += '     nxopt=  0 \n'
        s += '      NFFG=  0 \n'

        numreac = len(reactants)
        if len(bulk_composition) > 0:
            numreac += 1

        number_reactants = '{}'.format(numreac)
        s += '      nrct= ' + (2 - len(number_reactants))*' ' + number_reactants + '\n'

        return s

    def _input_specialreactant(self, s, bulk_composition, mols_bulk_composition):
        s += '  reactant= Bulk Composition\n'
        s += '     jcode= 2                jreac=  0\n'

        mol_string = '{:.1f}'.format(mols_bulk_composition)
        s += '      morr=' + (7 - len(mol_string.split('.')[0]))*' ' + mol_string
        s += '          modr=           0.\n'

        s += '     vreac=      0.0\n'

        for el in bulk_composition:
            s += '   ' + el + ' ' * (9 - len(el)) + '{:.8f}'.format(bulk_composition[el]) + '\n'

        s += '   endit.\n'

        s += '       nsk=  0                  sk=           0.        fk=           0.\n'
        s += '       nrk=  1                nrpk=  0\n'
        s += '       rk1=      1.0           rk2=           0.       rk3=           0.\n'

        return s

    def _input_reactant(self, s, reactant):
        s += '  reactant= ' + reactant['reactant'] + '\n'

        if 'composition' in reactant.keys():
            jcode = '1'
        else:
            jcode = '0'

        s += '     jcode= ' + jcode + '                jreac=  0\n'

        mol_string = '{:.2f}'.format(reactant['moles'])
        s += '      morr=' + (7 - len(mol_string.split('.')[0]))*' ' + mol_string
        s += '          modr=           0.\n'

        if jcode == '1':
            for endmember in reactant['composition'].keys():
                x_string = '{:.4f}'.format(reactant['composition'][endmember])
                s += '   ' + endmember + (28 - len(endmember) - len(x_string.split('.')[0]))*' '
                s += x_string + '\n'
            s += '   endit.\n'

        s += '       nsk=  0                  sk=           0.        fk=           0.\n'
        s += '       nrk=  1                nrpk=  0\n'
        s += '       rk1=      1.0           rk2=           0.       rk3=           0.\n'

        return s

    def _input_parameters(self, s):
        s += '    dlzidp=           0.\n'
        s += '     tolbt=       1.e-10     toldl=       1.e-10      tolx=           0.\n'
        s += '    tolsat=           0.    tolsst=           0.\n'
        s += '    screw1=           0.    screw2=           0.    screw3=           0.\n'
        s += '    screw4=           0.    screw5=           0.    screw6=           0.\n'
        s += '    zklogu=           0.    zklogl=           0.\n'
        s += '    dlzmx1=           0.    dlzmx2=           0.\n'
        s += '    itermx=  0              ntrymx=  0\n'
        s += '    npslmx=  0              nsslmx=  0\n'

        return s

    def _read_output(self):

        pass
