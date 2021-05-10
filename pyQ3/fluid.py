from pyQ3 import core
from pyQ3 import output

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
    eq3output: pyQ3.output object or nonetype
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
                 nxmods=[]
                 ):
        """
        Initialises a DEW fluid object

        parameters
        ----------
        system:   pyQ3.system object
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
        nxmods = list
            nxmods to apply to the input file. NEED TO CHECK THE FORMAT.
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

        # If O2 is being set by mineral equilibrium:
        if 'O2' in self.mineral_eq:
            self.fO2 = None

        # Create DATA0 and run EQPT
        self.system.make_data0(self.T-50.0,self.P,dT=50.0)
        core.run_eqpt()

        # Create input file and run EQ3
        self._make_input()
        core.run_eq3()

        # Collect output
        self.eq3output = output.eq3output()
        self.elemental_comp = self.eq3output.elemental_comp
        self.pH = float(self.eq3output.electrochemistry['pH'][0])
        self.aqueous_species = self.eq3output.aqueous_species
        self.fO2 = float(self.eq3output.redox['log_fO2'][0])
        self.mineral_saturation = self.eq3output.mineral_saturation


    def _input_preamble(self, s='', using_solid_solutions=False, uebal='H+', uacion='', fep=-12.6):
        T_s = '{0:.2f}'.format(self.T-273.15)

        s += '\n \nendit. \n'
        s += '     tempc=' + ' '*(13-len(T_s)) + T_s +'\n'
        s += '       rho=      1.02336    tdspkg=           0.     tdspl=           0.\n'
        if fep is None:
            s += '       fep=                 uredox=\n'
        else:
            s += '       fep=        ' + '{:.1f}'.format(fep)+ '    uredox=\n'
        s += '     tolbt=        .1E-7     toldl=        .1E-7    tolsat=           0.\n'
        s += '    itermx=  0\n'
        s += '*               1    2    3    4    5    6    7    8    9  10\n'
        if fep is None:
            s += '  iopt1-10=    -3'
        else:
            s += '  iopt1-10=     0'
        if using_solid_solutions == True:
            s += '    0    0    2    0    0    0    0    0   0\n'
        else:
            s += '    0    0    0    0    0    0    0    0   0\n'
        s += '  iopg1-10=     0   -1    0    0    1    0    0    0    0   0\n'
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

    def _make_input(self):
        if len(self.solid_solutions) > 0:
            using_solid_solutions = True
        else:
            using_solid_solutions = False
        s = self._input_preamble(using_solid_solutions=using_solid_solutions,uebal=self.uebal,
                                uacion=self.uacion,fep=self.fO2)
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

        file = open('input','w')
        file.write(s)
        file.close()
