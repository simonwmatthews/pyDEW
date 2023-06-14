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
import dill

import pyQ3

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
with open('eq_working/dew_system.pkl', 'rb') as file:
        system_params = dill.load(file)
        file.close()

elements = system_params['elements']
basis_species = system_params['basis_species']
other_species = system_params['other_species']
hydrated_species = system_params['hydrated_species']

system = pyQ3.System(basis_species=basis_species,
                     other_species=other_species,
                     elements=elements,
                     minerals=[],
                     gases=[],
                     hydrated_species=hydrated_species,
                     solid_solutions={})

### Helper functions

# Define a new version of the pyQ3 fluid class, which takes mole elements as input


class Fluid(pyQ3.fluid.fluid):
    def __init__(self, system, t, p, n, fO2=-12.0):
        self.system = system
        self.T = t
        self.P = p
        self.pH = 5.0
        self.fO2 = fO2
        self.mineral_eq = {}
        self.solid_solutions = {}
        self.uebal = 'H+'
        self.uacion = ''
        self.nxmods = []
        self.dummy_temperature = 500.0

        self.eqpt_working_directory = 'eq_working'
        self.eq3_working_directory = 'eq_working'
        self.eqpt_executable_name = 'EQPT'
        self.eq3_executable_name = 'EQ3'
        self.input_filename = 'input'

        # Create DATA0 and run EQPT
        # Determine filename automatically
        # if data0_filename is None and core.operatingsystem == 'Darwin':
        data0_filename = 'DATA0'
        # elif data0_filename is None and core.operatingsystem == 'Linux':
        #     data0_filename = 'data0'
        # Create the working directory if it doesn't exist:
        if not os.path.isdir(self.eqpt_working_directory):
            os.makedirs(self.eqpt_working_directory)
        # Create DATA0
        self.system.make_data0(self.T, self.P, format='pyQ3',
                               filepath=self.eqpt_working_directory + '/' + data0_filename,
                               dummy_temperature=self.dummy_temperature - 50)
        # Run EQPT
        pyQ3.core.run_eqpt(working_directory=self.eqpt_working_directory,
                           executable_name=self.eqpt_executable_name)

        # Create the eq3 working directory if it doesn't exist:
        if not os.path.isdir(self.eq3_working_directory):
            os.makedirs(self.eq3_working_directory)

        # Check to see if the working directories are different:
        if self.eq3_working_directory != self.eqpt_working_directory:
            os.system("cp " + self.eqpt_working_directory + '/data1 '
                      + self.eq3_working_directory + '/data1')

        # EQ3 is then run during the mass conservation step.

        self._calc_basis_species_molalities(n)

        # Collect output (already started in mass balance step)
        # self.elemental_comp_ppm = dict(self.elemental_comp.ppm)
        self.elemental_comp_molality = dict(self.elemental_comp.molality)
        self.aqueous_species = self.eq3output.aqueous_species

    def _calc_basis_species_molalities(self, mols):
        # Don't need to store result as the calculation has already been performed.
        result = root_scalar(self._mass_misfit, x0=110, x1=120, args=(mols))
        if result.converged is False:
            raise pyQ3.core.Error("Something went wrong in mass conservation.")

    def _gibbs_energy(self):
        g = 0
        g += 55.5 * \
            self.system.species['H2O'].gibbs_energy(self.T, self.T)/self.k
        for i, row in self.aqueous_species.iterrows():
            if row.species != 'H+':
                g += (self.system.species[row.species].gibbs_energy(self.T, self.P)
                      + 8.314*self.T*np.log(row.activity))*row.molality/self.k
            else:
                g += (8.314*self.T*np.log(row.activity))*row.molality/self.k
        return g

    def _element_projection(self, mols, total_mols_h):
        n = np.zeros(self.system.n_elements+1)
        n[:-1] = mols
        x = np.linalg.solve(self.system._basis_species_matrix.T, n)
        # x[0] is H2O
        k = total_mols_h/x[0]*2
        x = x*k
        molalities = {}
        for i, species in zip(range(len(self.system.basis_species)),
                              self.system.basis_species_names):
            if species not in ['H+', 'H2O', 'O2(G)'] and x[i] > 0:
                molalities[species] = x[i]
        return molalities, k

    def _mass_misfit(self, total_mols_h, mols):
        self.molalities, self.k = self._element_projection(mols, total_mols_h)

        # Create input file and run EQ3
        self._make_input(filepath=self.eq3_working_directory
                         + '/' + self.input_filename, format='pyQ3')
        pyQ3.core.run_eq3(working_directory=self.eq3_working_directory,
                          executable_name=self.eq3_executable_name)

        # Collect output
        self.eq3output = pyQ3.output.eq3output(
            filepath=self.eq3_working_directory + '/output')
        self.elemental_comp = self.eq3output.elemental_comp.set_index(
            'element').astype('float')

        calc_h = self.elemental_comp.molality['H']
        return calc_h - total_mols_h


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
    return len(elements)


def DEWFluid_species_number():
    return len(elements)


def DEWFluid_species_name(i):
    return elements[i]


def DEWFluid_species_formula(i):
    return elements[i]


def DEWFluid_species_mw(i):
    return chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == elements[i]][0]


def DEWFluid_species_elements(i):
    i_pt = np.where(chem.PERIODIC_ORDER == elements[i])[0][0]
    els = np.zeros(106)
    els[i_pt] = 1
    return els


def DEWFluid_endmember_name(i):
    return elements[i]


def DEWFluid_endmember_formula(i):
    return elements[i]


def DEWFluid_endmember_mw(i):
    return chem.PERIODIC_WEIGHTS[chem.PERIODIC_ORDER == elements[i]][0]


def DEWFluid_endmember_elements(i):
    i_pt = np.where(chem.PERIODIC_ORDER == elements[i])[0][0]
    els = np.zeros(106)
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
    fluid = Fluid(system, t, p, n, fO2=-12.0)

    #print(fluid.eq3output.aqueous_species)

    g = fluid._gibbs_energy()

    return g


def DEWFluid_g_fordiff(x):
    fluid = Fluid(system, x[0], x[1], x[2:])

    g = fluid._gibbs_energy()

    return g


def DEWFluid_dgdt(t, p, n):
    return 0


def DEWFluid_dgdp(t, p, n):
    return 0


def DEWFluid_dgdn(t, p, n):
    dgdn = np.zeros(len(n))

    x0 = np.empty(len(n)+2)
    x0[0] = t
    x0[1] = p
    x0[2:] = n

    for i in range(len(n)):
        step = 1e-4
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
                vec[2+i] = 0.5*n[i]
                vec[2+j] = 0.5*n[j]
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
