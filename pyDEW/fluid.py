from pyDEW import core
from pyDEW import output
import os

class fluid:
    """
    A class for generating EQ3 input files and storing calculation results. When the fluid
    is initialised:
    - A DATA0 file will be generated at the specified P and T
    - EQPT will be run to process DATA0
    - An EQ3 input file will be created
    - EQ3 will be run
    - The output will be read in and stored.
    Below the attributes most likely to be useful are listed.

    Attributes
    ----------
    T : float
        The temperature of the fluid in K
    P : bar
        The pressure of the fluid in bar
    eq3output: pyDEW.output object or nonetype
        The results of an EQ3 calculation, once calculated.
    pH : float
        The pH of the system (from the eq3 output)
    fO2 : float
        The fO2 of the system (from the eq3 output)
    elemental_comp : pandas.DataFrame
        The composition of the fluid in elemental abundance
    aqueous_species : pandas.DataFrame
        The abundance of all species in the solution
    mineral_saturation : pandas.DataFrame
        The saturation state of minerals included in the system.

    """
    def __init__(self,
                 system,
                 T,
                 P,
                 pH=5.0,
                 fO2=-12.6,
                 molalities=[],
                 mineral_eq=[],
                 solid_solutions={},
                 uebal='H+',
                 uacion='',
                 nxmods=[],
                 max_iterations=99,
                 eq3_working_directory =  'working',
                 eqpt_working_directory = 'working',
                 data0_filename = None,
                 input_filename = 'input',
                 eq3_executable_name = None,
                 eqpt_executable_name = None,
                 dummy_temperature = 300.0,
                 aH2O_mode='unity'
                 ):
        """
        Initialises a DEW fluid object

        parameters
        ----------
        system:   pyDEW.system object
            The system object for the system the fluid belongs to.
        T:  float
            Temperature of the fluid in K.
        P:  float
            Pressure of the fluid in bar.
        pH : float
            If H+ is not obtained by charge balance (setting uebal to H+)
            the pH may be specified. Default is 5.0, but will be ignored
            anyway if uebal has the default value.
        fO2 : float
            If not setting fO2 by equilibrium, it can be set here. If the
            system is not redox sensitive, then this can be ignored. Default
            is -12.6 (abitrarily).
        molalities : dict
            Molalities of basis species present in the solution. Species names
            should be the keys.
        mineral_eq : dict
            Which basis species should be controlled by mineral equilibria. Species
            names should be the keys, mineral names should be the values if the minerals
            are pure. If being set by a solid solution, the solid solution name, and the
            endmember should be provided as elements in a list.
        solid_solutions : dict
            The composition of the mineral solid solutions. The solid solution name should
            be the key, then another dict should be the value, with the endmember names as the
            keys, and the mole fractions as the values.
        uebal : str
            The name of the basis species to be set by charge balance. Default is H+.
        uacion : str
            The name of the basis species to use as uacion. Default is empty.
        nxmods : list
            nxmods to apply to the input file. NEED TO CHECK THE FORMAT.
        max_iterations : int , default = 99
            The maximum iterations for EQ3 to perform. Default value is the maximum number of
            iterations supported by EQ3 (99).
        eq3_working_directory : str, default='working'
            The working directory for EQ3.
        eqpt_working_directory : str, default='working'
            The working directory for EQPT.
        data0_filename : str or None, default=None
            The filename for DATA0. If running on with the linux executables, this must be 'data0',
            for OSX it must be 'DATA0'. If set to None, pyDEW will choose the correct name based
            on the operating system.
        input_filename : str, default='input'
            The filename for the EQ3 input file.
        eq3_executable_name : str or None, default=None
            Use to specify a particular version of EQ3 to use, otherwise (if set to None) a version
            of EQ3 will be copied into the working directory, according to the operating system
            in use. If specified, the EQ3 executable must be in the working directory set by
            eq3_working_directory.
        eqpt_executable_name : str or None, default=None
            Use to specify a particular version of EQPT to use, otherwise (if set to None) a
            version of EQPT will be copied into the working directory, according to the operating
            system in use. If specified, the EQPT executable must be in the working directory
            set by eqpt_working_directory.
        dummy_temperature : float, default = 500.0
            The dummy temperature (in degC) to provide DATA0 and input files. This might be useful
            for calculations above 1000 degC. This value is just provided to the EQ3 interpolation
            routine, and should have no influence on the calculation results.
        aH2O_mode : string, default: 'unity'
            Either 'molfraction' or 'unity'. If 'molfraction', the activity of water will be set to
            the mole fraction of water. If 'unity', the activity of water will always be 1.
        """

        self.system = system
        self.T = T
        self.P = P
        self.pH = pH
        self.fO2 = fO2
        self.molalities = molalities
        self.mineral_eq = mineral_eq
        self.solid_solutions = solid_solutions
        self.uebal = uebal
        self.uacion = uacion
        self.nxmods = nxmods
        self.dummy_temperature = dummy_temperature
        if max_iterations > 99:
            raise core.InputError("EQ3 only supports a maximum of 99 iterations.")
        elif max_iterations < 0 or isinstance(max_iterations, int) is False:
            raise core.InputError("Maximum iterations must be a positive integer.")
        self.max_iterations = max_iterations

        if aH2O_mode not in ['unity', 'molfraction']:
            raise core.InputError("aH2O mode note recognised.")
        self.aH2O_mode = aH2O_mode

        # If O2 is being set by mineral equilibrium:
        if 'O2(G)' in self.mineral_eq:
            self.fO2 = None

        # Create DATA0 and run EQPT
        # Determine filename automatically
        if data0_filename is None and core.operatingsystem == 'Darwin':
            data0_filename = 'DATA0'
        elif data0_filename is None and core.operatingsystem == 'Linux':
            data0_filename = 'data0'
        # Create the working directory if it doesn't exist:
        if not os.path.isdir(eqpt_working_directory):
            os.makedirs(eqpt_working_directory)
        # Create DATA0
        self.system.make_data0(self.T, self.P, format='pyDEW',
                               filepath = eqpt_working_directory + '/' + data0_filename,
                               dummy_temperature = self.dummy_temperature)
        # Run EQPT
        core.run_eqpt(working_directory = eqpt_working_directory,
                      executable_name = eqpt_executable_name)

        # Create the eq3 working directory if it doesn't exist:
        if not os.path.isdir(eq3_working_directory):
            os.makedirs(eq3_working_directory)

        # Check to see if the working directories are different:
        if eq3_working_directory != eqpt_working_directory:
            os.system("cp " + eqpt_working_directory + '/data1 ' +
                      eq3_working_directory + '/data1')

        # Create input file and run EQ3
        self._make_input(filepath = eq3_working_directory + '/' + input_filename, format='pyDEW')
        core.run_eq3(working_directory = eq3_working_directory,
                     executable_name = eq3_executable_name)

        # Collect output
        self.eq3output = output.eq3output(filepath = eq3_working_directory + '/output')
        self.elemental_comp = self.eq3output.elemental_comp.set_index('element').astype('float')
        self.elemental_comp_ppm = dict(self.elemental_comp.ppm)
        self.elemental_comp_molality = dict(self.elemental_comp.molality)
        self.pH = float(self.eq3output.electrochemistry['pH'][0])
        self.aqueous_species = self.eq3output.aqueous_species
        self.fO2 = float(self.eq3output.redox['log_fO2'][0])
        self.mineral_saturation = self.eq3output.mineral_saturation


    def _input_preamble(self, s='', using_solid_solutions=False, uebal='H+', uacion='', fep=-12.6,
                        t=None):
        if t is None:
            T_s = '{0:.2f}'.format(self.T-273.15)
        else:
            T_s = '{0:.2f}'.format(t)

        s += '\n \nendit. \n'
        s += '     tempc=' + ' '*(13-len(T_s)) + T_s +'\n'
        s += '       rho=      1.02336    tdspkg=           0.     tdspl=           0.\n'
        if fep is None:
            s += '       fep=                 uredox=\n'
        else:
            s += '       fep=        ' + '{:.1f}'.format(fep)+ '    uredox=\n'
        s += '     tolbt=        .1E-7     toldl=        .1E-7    tolsat=           0.\n'
        s += '    itermx= ' + ' '*(2-len(str(int(self.max_iterations))))
        s += '{}\n'.format(int(self.max_iterations))
        s += '*               1    2    3    4    5    6    7    8    9  10\n'
        if fep is None:
            s += '  iopt1-10=    -3'
        else:
            s += '  iopt1-10=     0'
        if using_solid_solutions == True:
            s += '    0    0    2    0    0    0    0    0   0\n'
        else:
            s += '    0    0    0    0    0    0    0    0   0\n'
        s += '  iopg1-10=     0   -1    0    0    '

        if self.system.carbon_activity_mode == 'sverjensky22':
            s += '0'
        elif self.system.carbon_activity_mode == 'huang19':
            s += '2'
        else:
            s += '1'

        s += '    0    '

        if self.aH2O_mode == 'molfraction':
            s += '1    '
        else:
            s += '0    '

        if (t is None and self.T >= 650+273.15) or (t is not None and t >= 650):
            s += '1'
        else:
            s += '0'

        s += '    '

        if self.system.carbon_activity_mode == 'sverjensky22':
            if 'C' in self.system.elements:
                carb_pos = self.system.elements.index('C') + 1
                s += str(carb_pos)
            else:
                raise InputError("Carbon not found in the system.")
        else:
            s += '0'

        s += '   0\n'
        s += '  iopr1-10=     0    2    0    0    0    0    1         0   \n'
        s += ' iopr11-20=     0    0    0    0    0    0    0  \n'
        s += '  iodb1-10=     0    0    0    0    0    0    0  \n'
        s += '     uebal= '+uebal+'\n'
        s += '    uacion= '+uacion+'\n'
        return s

    def _input_nxmod(self,s,nxmods=[]):
        number = len(nxmods)
        s += '     nxmod=  {}\n'.format(number)
        for nxm in nxmods:
            s += '   SPECIES= ' + nxm[0] +'\n'
            s += '      TYPE=' + ' '*(3-len(str(nxm[1])))+'{}'.format(nxm[1])
            s += '              OPTION=' + ' '*(3-len(str(nxm[2])))+'{}'.format(nxm[2])
            xlkmod = '{0:.3f}'.format(nxm[3])
            s += '              XLKMOD=' + ' '*(4-len(xlkmod.split('.')[0]))+xlkmod+'\n'

        return s

    def _input_basis_species_conc(self,species_name, molality,s=''):
        mol_s = '{0:.4E}'.format(molality)
        s += 'data file master species= ' + species_name + '\n'
        s += '   switch with species=  \n'
        s += '   jflag=  0   csp= ' + mol_s + '\n'
        return s

    def _input_basis_species_logact(self,species_name, logact,s=''):
        act_s = '{0:.4E}'.format(logact)
        s += 'data file master species= ' + species_name + '\n'
        s += '   switch with species=  \n'
        s += '   jflag= 16   csp= ' + act_s + '\n'
        return s

    def _input_basis_species_mineral(self,species_name,mineral,s=''):
        s += 'data file master species= ' + species_name + '\n'
        s += '   switch with species=  \n'
        if type(mineral) == str:
            s += '   jflag= 19   csp= ' + '\n'
            s += '   uphase= ' + mineral +'\n'
        elif type(mineral) == list and len(mineral) == 2:
            s += '   jflag= 20   csp= ' + '\n'
            s += '   uphase= ' + mineral[0] + ' '*(24-len(mineral[0]))  + 'uphase=    ' + mineral[1] + '\n'
        return s

    def _input_end_file(self,s=''):
        s += 'endit.\n'
        return s

    def _make_input_solid_solution(self,ss_name,ss_minerals,s=''):
        s += '   ' + ss_name + '\n'
        for mineral in ss_minerals:
            s += '      ' + mineral + ' '*(31-len(mineral)) + '{:.4f}'.format(ss_minerals[mineral]) + '\n'
        s += '      endit.\n'
        return s

    def _make_input(self, filepath='input', format='traditional'):
        if len(self.solid_solutions) > 0:
            using_solid_solutions = True
        else:
            using_solid_solutions = False
        if format == 'traditional':
            s = self._input_preamble(using_solid_solutions=using_solid_solutions,uebal=self.uebal,
                                    uacion=self.uacion,fep=self.fO2)
        elif format == 'pyDEW':
            s = self._input_preamble(using_solid_solutions=using_solid_solutions,uebal=self.uebal,
                                    uacion=self.uacion,fep=self.fO2,t=self.dummy_temperature)
        s = self._input_nxmod(s,self.nxmods)
        for sp in self.molalities:
            s = self._input_basis_species_conc(sp, self.molalities[sp],s=s)
        if type(self.pH) != type(None):
            s = self._input_basis_species_logact('H+',-self.pH,s=s)
        for sp in self.mineral_eq:
            s = self._input_basis_species_mineral(sp, self.mineral_eq[sp],s=s)
        s = self._input_end_file(s)

        if len(self.solid_solutions) > 0:
            for ss_name in self.solid_solutions:
                s = self._make_input_solid_solution(ss_name,self.solid_solutions[ss_name],s=s)
            s += '   endit.\n'

        file = open(filepath,'w')
        file.write(s)
        file.close()
