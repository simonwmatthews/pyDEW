import numpy as np
from thermoengine import chem
from thermoengine import phases
from thermoengine import model
from thermoengine import core
import dill
import subprocess
import numdifftools as nd
from copy import copy
import os
from scipy.optimize import root_scalar

import pyDEW

# from ctypes import cdll
# from ctypes import util
# from rubicon.objc import ObjCClass, objc_method
# cdll.LoadLibrary(util.find_library('phaseobjc'))
#
# DEWFluid = ObjCClass('DEWDielectricConstant')
# obj = DEWFluid.alloc().init()

element_list = core.chem.PERIODIC_ORDER.tolist()

# print('WARNING. Code can only deal with O2 in the gas phase currently.')

### IMPORT A FILE WITH INFO ABOUT ENDMEMBERS

elements = ['O', 'H', 'Si', 'Na', 'Cl']
basis_species = ['H2O', 'H+', 'H4SIO4(AQ)', 'NA+', 'CL-', 'O2(G)']
other_species = ['H6SI2O7(AQ)', 'H8SI3O10(AQ)', 'H3SIO4-', 'OH-', 'O2(AQ)', 'NACL(AQ)', 'NAOH(AQ)', 'HCL(AQ)']
# elements = ['O', 'H', 'Si']
# basis_species = ['H2O', 'H+', 'H4SIO4(AQ)', 'O2(G)']
# other_species = ['H6SI2O7(AQ)', 'H8SI3O10(AQ)', 'H3SIO4-', 'OH-', 'O2(AQ)']

# elements = pyQ3.defaultsystem.elements
# basis_species = pyQ3.defaultsystem.basis_species_names
# other_species = pyQ3.defaultsystem.other_species_names

system = pyDEW.System(basis_species=basis_species,
                      other_species=other_species,
                      elements=elements,
                      minerals=[],
                      gases=[],
                      # hydrated_species={},
                      solid_solutions={})

### Helper functions

# Define a new version of the pyQ3 fluid class, which takes mole elements as input


from pyDEW import core
from pyDEW import output
import os


from pyDEW import core
from pyDEW import output
import os


class fluid_equilibrate(pyDEW.fluid.fluid):
    """
    NEED TO UPDATE THIS FOR EQUILIBRATE MODS
    
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
                 n,
                 pH=5.0,
                 fO2=-12.6,
                 molalities=[],
                 mineral_eq=[],
                 solid_solutions={},
                 uebal='H+',
                 uacion='',
                 nxmods=[],
                 max_iterations=99,
                 eq3_working_directory =  'eq_working',
                 eqpt_working_directory = 'eq_working',
                 data0_filename = None,
                 input_filename = 'input',
                 eq3_executable_name = None,
                 eqpt_executable_name = None,
                 dummy_temperature = 300.0,
                 aH2O_mode='unity',
                 read_pickup=True,
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
        read_pickup : bool, default: True
            The pickup is required if the Fluid will be used as a starting point for a Reaction (EQ6)
            calculation. You might be able to speed up the runs without reading this though.
        """

        self.system = system
        self.T = T
        self.P = P
        self.n = n
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
        self.eq3_working_directory = eq3_working_directory
        self.eq3_executable_name = eq3_executable_name
        self.eqpt_working_directory = eqpt_working_directory
        self.eqpt_executable_name = eqpt_executable_name
        self.input_filename = input_filename

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
        
        
        ### ADDITIONS FOR THE EQUILIBRATE FLUID ##############
        
        # Since the fluid will be calculated during iteration,
        # this should be the only line required...
        
        self.k = self._calculate_k()
        
        
        #######################################################

        
    
    
    def _element_projection(self):
        """
        Convert mole components to moles of basis species
        """

        # Need to reformat the basis species matrix to:
        # - Remove O as a component
        # - Remove charges (charge balance not necessary if O is open system)
        # - Remove H+ as a basis species, as all H should be mapped on to H2O

        matrix = np.zeros((np.shape(self.system._basis_species_matrix)[0] - 2, 
                           np.shape(self.system._basis_species_matrix)[1] - 2,))

        matrix[0, :] = self.system._basis_species_matrix[0, 1:-1]
        matrix[1:, :] = self.system._basis_species_matrix[2:-1, 1:-1]

        n = np.zeros(self.system.n_elements-1)
        # Ignore O:
        # n = self.n[1:] # Just altered code to combine H and O into H2O
        n[0] = n[0] * 2 # Convert from moles H2O to moles H
        x = np.linalg.solve(matrix.T, n)

        return x
    
    def _make_fluid_from_k(self, k, debug=False):
        # Transform mole element components to mole basis species
        # H2O will be the 0th element, then the basis species that are not H+ and O2(G).
        basis_species_molality = self._element_projection()

        # Create an index of the basis species in the transformed composition
        basis_species = []
        for sp in self.system.basis_species_names:
            if sp not in ['H+', 'O2(G)']:
                basis_species.append(sp)

        molalities = {}

        for i in range(len(basis_species)):
            if i > 0: # Exclude H2O!
                molalities[basis_species[i]] = basis_species_molality[i] * k
        
        self.molalities = molalities

        if debug is True:
            print(f"The molalities calculated within make_fluid_from_k: {molalities}")

        # Create the eq3 working directory if it doesn't exist:
        if not os.path.isdir(self.eq3_working_directory):
            os.makedirs(eq3_working_directory)

        # Check to see if the working directories are different:
        if self.eq3_working_directory != self.eqpt_working_directory:
            os.system("cp " + self.eqpt_working_directory + '/data1 ' +
                      self.eq3_working_directory + '/data1')

        # Create input file and run EQ3
        self._make_input(filepath = self.eq3_working_directory + '/' + self.input_filename, format='pyDEW')
        core.run_eq3(working_directory = self.eq3_working_directory,
                     executable_name = self.eq3_executable_name)

        # Collect output
        self.eq3output = output.eq3output(filepath = self.eq3_working_directory + '/output')
        self.elemental_comp = self.eq3output.elemental_comp.set_index('element').astype('float')
        self.elemental_comp_ppm = dict(self.elemental_comp.ppm)
        self.elemental_comp_molality = dict(self.elemental_comp.molality)
        self.pH = float(self.eq3output.electrochemistry['pH'].iloc[0])
        self.aqueous_species = self.eq3output.aqueous_species
        self.fO2 = float(self.eq3output.redox['log_fO2'].iloc[0])
        self.mineral_saturation = self.eq3output.mineral_saturation

            

    def _H_conservation_rootfinder(self, k, debug=False):
        
        if debug is True:
            print(f"Value of k on entering H_conservation_rootfinder: {k}")
            
        self._make_fluid_from_k(k)

        misfit_H = k * self.n[0] * 2 - self.elemental_comp_molality['H']

        if debug is True:
            print(f"The H_conservation_rootfinder misfit: {misfit_H}")

        return misfit_H
    
    def _calculate_k(self):
        """
        Numerically solve for k.
        """
        
        m_H2O = 55.5086815578

        print(self.n)
        print(self.system.elements)

        soln = root_scalar(self._H_conservation_rootfinder,
                           x0 = 2 * m_H2O / self.n[self.system.elements.index('H')],
                           x1 = 2 * m_H2O / self.n[self.system.elements.index('H')] + 10,
                           )
        
        if soln.converged is True:
            return soln.root
        else:
            raise core.InputError("Something wrong with the composition supplied, mass balance could "
                                  "not be obtained.")
    
    def gibbs_energy(self):
        g = 0
        g += 55.5086815578 * \
            self.system.species['H2O'].gibbs_energy(self.T, self.T)/self.k
        for i, row in self.aqueous_species.iterrows():
            if row.species != 'H+':
                g += (self.system.species[row.species].gibbs_energy(self.T, self.P)
                      + 8.314*self.T*np.log(row.activity))*row.molality/self.k
            else:
                g += (8.314*self.T*np.log(row.activity))*row.molality/self.k
        return g


### Functions for coder/equilibrate
def DEWFluid_identifier():
    return ''


def DEWFluid_name():
    return 'DEW'


def DEWFluid_identifier():
    return 'identifier'


def DEWFluid_conv_elm_to_moles(elm):
    return None


def DEWFluid_conv_elm_to_tot_moles(elm):
    return None


def DEWFluid_conv_elm_to_tot_grams(elm):
    return None


def DEWFluid_conv_moles_to_tot_moles(elm):
    return None


def DEWFluid_conv_moles_to_mole_frac(elm):
    return None


def DEWFluid_endmember_number():
    return len(elements) - 1


def DEWFluid_species_number():
    return len(elements) - 1


def DEWFluid_species_name(i):
    if i == 0:
        return 'H2O'
    else:
        return elements[i+1]


def DEWFluid_species_formula(i):
    if i == 0:
        return 'H2O'
    else:
        return elements[i+1]


def DEWFluid_species_mw(i):
    if i == 0:
        return (chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == 'H'][0] * 2
                + chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == 'O'][0])
    else:
        return chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == elements[i+1]][0]


def DEWFluid_species_elements(i):
    if i == 0:
        els = np.zeros(107)
        els[chem.PERIODIC_ORDER == 'H'] = 2
        els[chem.PERIODIC_ORDER == 'O'] = 1

    else:
        i_pt = np.where(chem.PERIODIC_ORDER == elements[i+1])[0][0]
        els = np.zeros(107)
        els[i_pt] = 1
    
    return els


def DEWFluid_endmember_name(i):
    if i == 0:
        return 'H2O'
    else:
        return elements[i+1]


def DEWFluid_endmember_formula(i):
    if i == 0:
        return 'H2O'
    else:
        return elements[i+1]


def DEWFluid_endmember_mw(i):
    if i == 0:
        return (chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == 'H'][0] * 2
                + chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == 'O'][0])
    else:
        return chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == elements[i+1]][0]


def DEWFluid_endmember_elements(i):
    if i == 0:
        els = np.zeros(107)
        els[chem.PERIODIC_ORDER == 'H'][0] = 2
        els[chem.PERIODIC_ORDER == 'O'][0] = 1

    else:
        i_pt = np.where(chem.PERIODIC_ORDER == elements[i+1])[0][0]
        els = np.zeros(107)
        els[i_pt] = 1
    
    return els


def DEWFluid_endmember_mu0(i, t, p):
    return 0


def DEWFluid_endmember_dmu0dT(i, t, p):
    return 0


def DEWFluid_endmember_dmu0dP(i, t, p):
    return 0


def DEWFluid_endmember_d2mu0dT2(i, t, p):
    return 0


def DEWFluid_endmember_d2mu0dTdP(i, t, p):
    return 0


def DEWFluid_endmember_d2mu0dP2(i, t, p):
    return 0


def DEWFluid_endmember_d3mu0dT3(i, t, p):
    return 0


def DEWFluid_endmember_d3mu0dT2dP(i, t, p):
    return 0


def DEWFluid_endmember_d3mu0dP3(i, t, p):
    return 0


def DEWFluid_g(t, p, n):
    fluid = fluid_equilibrate(system, t, p, n, fO2=-12.0)

    #print(fluid.eq3output.aqueous_species)

    g = fluid.gibbs_energy()

    return g


def DEWFluid_g_fordiff(x):
    fluid = fluid_equilibrate(system, x[0], x[1], x[2:], fO2=-12.0)

    g = fluid.gibbs_energy()

    return g


def DEWFluid_dgdt(t, p, n):
    return 0


def DEWFluid_dgdp(t, p, n):
    return 0


def DEWFluid_dgdn(t, p, n):

    print("Entered dgdn")

    dgdn = np.zeros(len(n))

    x0 = np.empty(len(n)+2)
    x0[0] = t
    x0[1] = p
    x0[2:] = n

    for i in range(len(n)):
        step = 1e-3
        vec = np.zeros(len(n)+2)

        # vec[2:] = - 1/(len(n)-1)
        vec[2+i] = 1

        dgdn[i] = nd.directionaldiff(
            DEWFluid_g_fordiff, x0, vec, step=step, method='forward')

    return dgdn


def DEWFluid_d2gdt2(t, p, n):
    return 0


def DEWFluid_d2gdtdp(t, p, n):
    return 0


def DEWFluid_d2gdndt(t, p, n):
    return 0


def DEWFluid_d2gdp2(t, p, n):
    return 0


def DEWFluid_d2gdndp(t, p, n):
    return 0


def DEWFluid_d2gdn2(t, p, n):

    print("Entered d2gdn2")

    dgdn = np.zeros([len(n)]*2)

    x0 = np.empty(len(n)+2)
    x0[0] = t
    x0[1] = p
    x0[2:] = n

    for i in range(len(n)):
        for j in range(len(n)):
            vec = np.zeros(len(n)+2)
            if i != j:
                # vec[2:] = - 1/(len(n)-2)
                vec[2+i] = 0.5 #*n[i]
                vec[2+j] = 0.5 #*n[j]
            else:
                # vec[2:] = - 1/(len(n)-1)
                vec[2+i] = 1*n[i]
            dgdn[i, j] = nd.directionaldiff(
                DEWFluid_g_fordiff, x0, vec, step=1e-5, order=2, n=2, method='forward')

    return dgdn


def DEWFluid_d3gdt3(t, p, n):
    return 0


def DEWFluid_d3gdt2dp(t, p, n):
    return 0


def DEWFluid_d3gdndt2(t, p, n):
    return 0


def DEWFluid_d3gdtdp2(t, p, n):
    return 0


def DEWFluid_d3gdndtdp(t, p, n):
    return 0


def DEWFluid_d3gdn2dt(t, p, n):
    return 0


def DEWFluid_d3gdp3(t, p, n):
    return 0


def DEWFluid_d3gdndp2(t, p, n):
    return 0


def DEWFluid_d3gdn2dp(t, p, n):
    return 0


def DEWFluid_d3gdn3(t, p, n):
    dgdn = np.zeros([len(n)]*3)

    x0 = np.empty(len(n)+2)
    x0[0] = t
    x0[1] = p
    x0[2:] = n

    for i in range(len(n)):
        for j in range(len(n)):
            for k in range(len(n)):
                vec = np.zeros(len(n)+2)
                if i != j and i != k:
                    # if n > 3:
                    #     vec[2:] = - 1/(len(n)-3)
                    vec[2+i] = 1/3*n[i]
                    vec[2+j] = 1/3*n[j]
                    vec[2+k] = 1/3*n[j]
                elif i == j and i != k:
                    # vec[2:] = - 1/(len(n)-2)
                    vec[2+i] = 1/2*n[i]
                    vec[2+k] = 1/2*n[j]
                elif i != j and i == k:
                    # vec[2:] = - 1/(len(n)-2)
                    vec[2+i] = 1/2*n[i]
                    vec[2+j] = 1/2*n[j]
                elif i == j and i != k:
                    # vec[2:] = - 1/(len(n)-2)
                    vec[2+i] = 1/2*n[i]
                    vec[2+k] = 1/2*n[j]
                else:
                    # vec[2:] = - 1/(len(n)-1)
                    vec[2+i] = 1*n[i]
                dgdn[i, j, k] = nd.directionaldiff(
                    DEWFluid_g_fordiff, x0, vec, step=1e-5, order=2, n=3, method='forward')

    return dgdn


def DEWFluid_s(t, p, n):
    return 0


def DEWFluid_v(t, p, n):
    return 0


def DEWFluid_cv(t, p, n):
    return 0


def DEWFluid_cp(t, p, n):
    return 0


def DEWFluid_dcpdt(t, p, n):
    return 0


def DEWFluid_alpha(t, p, n):
    return 0


def DEWFluid_beta(t, p, n):
    return 0


def DEWFluid_K(t, p, n):
    return 0


def DEWFluid_Kp(t, p, n):
    return 0


def DEWFluid_conv_moles_to_elm(n):
    ne = len(element_list)
    conv = np.zeros(ne)
    for i in range(0, ne):
        if element_list[i] in elements:
            conv[i] = n[elements.index(element_list[i])]
    return conv


def DEWFluid_test_moles(n):
    if all(n >= 0):  # and np.sum(n) == 1:
        return True
    else:
        return False
