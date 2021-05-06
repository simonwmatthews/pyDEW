from pyQ3 import defaultsystem
from pyQ3 import core

import numpy as np
from thermoengine import chem
from copy import copy

from ctypes import cdll
from ctypes import util
from rubicon.objc import ObjCClass, objc_method
cdll.LoadLibrary(util.find_library('phaseobjc'))

DEWFluid = ObjCClass('DEWDielectricConstant')
obj = DEWFluid.alloc().init()

class system:
    """
    A class used to represent a chemical system for aqueous speciation calculations.

    Attributes
    ----------
    elements : list
        The elements in the system, as strings, in the format ['O', 'H', ...].
    basis_species : list
        List of basis species objects in the order [<H2O>, <H+>, ... <O2>]
        with the basis species in the same order as the elements.
    other_species : list
        List of the species objects in the system, but are not basis species.
    hydrated_species : dict
        The number of water molecules to add to the species when writing the
        chemical reaction in DATA0. Keys are the names of the species to hydrate.
    minerals : list
        List of pure mineral objects to include in the system.
    solid_solutions : dict
        Dictionary containing the solid solution names as keys, with list of the
        pure endmember name strings as the values.
    """

    def __init__(self,
                elements= defaultsystem.elements,
                basis_species= defaultsystem.basis_species_names,
                other_species= defaultsystem.other_species_names,
                dummy_species = [],
                minerals= defaultsystem.minerals,
                solid_solutions= defaultsystem.solid_solutions,
                hydrated_species= defaultsystem.hydrated_species,
                ion_size= defaultsystem.ion_size
                ):
        """Initialisation routine for a system class.

        Parameters
        ----------
        elements:    list
            List of element name strings. Must include O and H. Will use the default
            system unless specified. The order doesn't matter.
        basis_species:   list of species objects, or strings
            List of basis_species objects, or strings if the species are in
            the DEW2019 database. Will use the default system unless specified.
            The list must include H2O, H+, O2. The order does not matter.
        other_species:   list of species objects, or strings
            List of species objects that are included in the system, but are not
            part of the basis set. Must include OH-. If the species are in DEW2019,
            the species name as a string may be passed instead. Will use the default
            system, unless specified.
        dummy_species:  list of dicts
            For each dummy species provide a dictionary with keys abbrev (str), charge (float),
            formula (dict).
        minerals:    list
            List of mineral objects. Will use the default system, unless specified. The
            minerals can be pure or solution phases. If solution phases are provided,
            the endmembers in the system defined by the elements will be extracted and
            treated as pure phases.
        solid_solutions:    list
            Dictionary containing the solid solution names as keys, with list of the
            pure endmember name strings as the values.
        hydrated_species:   dict
            The number of water molecules to add to the species when writing the
            chemical reaction in DATA0. Keys are the names of the species to hydrate.
            This is only important if using with a version of EQ3 where a(H2O) is not
            set to 1.0.
        ion_size : dict
            A dictionary of complexes to assign a special ion size to. This is used in
            the DEW EQ3 versions as a flag for species behaviour, so it probably shouldn't
            be changed. The default ion size is 3.7.
        """

        # The element list must start with O and H:
        self.elements = ['O','H']
        for el in elements:
            if el not in self.elements:
                self.elements.append(el)

        # If any of the basis species are strings, import DEW2019:
        find_species = []
        for sp in basis_species + other_species:
            if isinstance(sp,str):
                find_species.append(sp)
        if len(find_species) > 0:
            dewdb = core.DEW_species()

        _basis_species_unordered = []
        _basis_species_names_unordered = []
        for sp in basis_species:
            if isinstance(sp,str) == False:
                _basis_species_unordered.append(sp)
                _basis_species_names_unordered.append(sp.abbrev)
            else:
                _basis_species_names_unordered.append(sp)
                _basis_species_unordered.append(dewdb[sp])

        #---
        # Create a list of the basis species in the order of the elements:
        self.basis_species = [_basis_species_unordered[_basis_species_names_unordered.index('H2O')],
                              _basis_species_unordered[_basis_species_names_unordered.index('H+')]]
        _basis_species_unordered.pop(_basis_species_names_unordered.index('H2O'))
        _basis_species_names_unordered.pop(_basis_species_names_unordered.index('H2O'))
        _basis_species_unordered.pop(_basis_species_names_unordered.index('H+'))
        _basis_species_names_unordered.pop(_basis_species_names_unordered.index('H+'))

        # O2 must go at the end of the list, but will interfere with finding the other basis species.
        _O2 = _basis_species_unordered[_basis_species_names_unordered.index('O2')]
        _basis_species_unordered.pop(_basis_species_names_unordered.index('O2'))
        _basis_species_names_unordered.pop(_basis_species_names_unordered.index('O2'))

        # Construct an array describing which species could be basis species for each element:
        _potentialbasis = np.zeros([len(elements)-2]*2)
        for i,el in zip(range(len(self.elements[2:])),self.elements[2:]):
            for j,sp in zip(range(len(_basis_species_unordered)),_basis_species_unordered):
                if el in core.formula_to_dict(chem.get_Berman_formula(sp.props['element_comp'][0])).keys():
                    _potentialbasis[i,j] = 1

        _basis_dict = {}
        _speciesfound = []
        # Check which basis species contain a single element (other than H and O):
        for i in range(len(self.elements)-2):
            if np.sum(_potentialbasis[i,:]) == 1:
                _basis_dict[elements[2+i]] = _basis_species_unordered[i]
                _speciesfound.append(i)

        # Delete those species from the matrix
        if len(_speciesfound) > 0:
            for i in _speciesfound:
                _potentialbasis[i,:] = np.zeros(len(self.elements)-2)
                _potentialbasis[:,i] = np.zeros(len(self.elements)-2)
        # Check if this has solved the problem:
        for i in range(len(self.elements)-2):
            if np.sum(_potentialbasis[i,:]) == 1:
                _basis_dict[elements[2+i]] = _basis_species_unordered[i]
                _speciesfound.append(i)

        # At the moment I haven't made the code intelligent enough to deal with more complex
        # sets of basis species. This scenario is unlikely to arise, and is probably avoidable,
        # so I will just raise an error for now.
        if len(_speciesfound) != len(self.elements) - 2:
            raise core.InputError('Something has gone wrong with assigning basis species.')

        # Build the basis species in order:
        for el in self.elements[2:]:
            self.basis_species.append(_basis_dict[el])
        self.basis_species.append(_O2)

        # Prepare some other useful variables
        self.basis_species_names = []
        self.basis_species_names_soln = []
        self.basis_species_soln = []
        self.species = dict()
        for species in self.basis_species:
            self.basis_species_names.append(species.abbrev)
            self.species[species.abbrev] = species
            if species.abbrev != 'O2' and species.abbrev != 'O2,g':
                self.basis_species_names_soln.append(species.abbrev)
                self.basis_species_soln.append(species)

        #----
        # Check whether there are any duplicate species in other_species, and lookup any if needed.
        self.other_species = []
        for sp in other_species:
            if isinstance(sp,str):
                if sp not in self.basis_species_names:
                    self.other_species.append(dewdb[sp])
            else:
                if sp.abbrev not in self.basis_species_names:
                    self.other_species.append(sp)

        # Prepare some other useful variables
        self.other_species_names = []
        for species in self.other_species:
            self.other_species_names.append(species.abbrev)
            self.species[species.abbrev] = species

        #------
        # Extract minerals if needed.
        self.minerals = []
        if any(isinstance(min,str) for min in minerals):
            db = core.berman_database()
        for min in minerals:
            if isinstance(min,str):
                try:
                    _phobj = db.get_phase(min)
                    _phobj.enable_gibbs_energy_reference_state()
                    self.minerals.append(_phobj)
                except:
                    raise core.InputError(min+' phase string not recognised. Make sure you are using the thermoengine mineral abbreviations.')
            else:
                self.minerals.append(min)

        #------
        # Store the other information, which shouldn't need processing
        self.hydrated_species = hydrated_species
        self.solid_solutions = solid_solutions
        self.ion_size = ion_size
        self.dummy_species = dummy_species

        self.n_elements = len(self.elements)
        self.n_basis_species = len(self.basis_species)

        self._valid = True
        self._error = ''
        self._validate()
        if self._valid == False:
            raise core.InputError(self._error)

        # Set up basis species matrices. The OH matrix is created for using
        # in calculations where H+ molalities are negative.
        self._basis_species_matrix = self._make_basis_species_matrix()
        self._basis_species_matrix_OH = self._make_basis_species_matrix(swap_H_OH=True,exclude_gas=True)
        self._basis_species_matrix_soln = self._make_basis_species_matrix(exclude_gas=True)

        self._stoichiometry = dict()
        for species in self.other_species + self.minerals:
            self._find_reaction(species)

    def _validate(self):
        if self.basis_species_names[0] != 'H2O':
            self._valid = False
            self._error += 'H2O must be first basis species. '
        if self.basis_species_names[1] != 'H+':
            self._valid = False
            self._error += 'H+ must be second basis species. '
        if 'OH-' in self.basis_species_names:
            self._valid = False
            self._error += 'OH- cannot be a basis species. '
        if 'O2' not in self.basis_species_names:
            self._valid = False
            self._error += 'O2 must be a basis species. '
        if self.n_basis_species -1 != self.n_elements:
            self._valid = False
            self._error += 'There must be a basis species for each element, plus O2,g. '
        if 'H' not in self.elements:
            self._valid = False
            self._error += 'H must be an element. '
        if 'O' not in self.elements:
            self._valid = False
            self._error += 'O must be an element. '


    def _d0_preamble(self,s=''):
        s += 'data0\n'
        s += '   ' + str(len(self.elements))+'   ' + str(len(self.basis_species)) +'\n'
        s += '\n\n\n\n'
        s += 'ELEMENTS, ATOMIC WEIGHTS, OXIDES, AND GRAVIMETRIC FACTORS\n'

        element_lines ={'O': 'O         15.99940     NONE            0.00000\n',
                        'Na':'NA        22.98977     NA2O            1.34797\n',
                        'K': 'K         39.09830     K2O             1.20459\n',
                        'Ca':'CA        40.08000     CAO             1.39919\n',
                        'Mg':'MG        24.30500     MGO             1.65809\n',
                        'Al':'AL        26.98154     AL2O3           1.88947\n',
                        'Si':'SI        28.08550     SIO2            2.13931\n',
                        'Sr':'SR        87.62000     SRO             1.18260\n',
                        'Zn':'ZN        65.38000     ZNO             1.24476\n',
                        'Pb':'PB       207.20000     PBO             1.07723\n',
                        'Ag':'AG       107.86800     AG2O            1.07416\n',
                        'Ba':'BA       137.33000     BAO             1.11649\n',
                        'H': 'H          1.00790     H2O             8.93645\n',
                        'C': 'C         12.01100     CO2             3.66409\n',
                        'N': 'N         14.00670     NH3             1.21589\n',
                        'Cl':'CL        35.45300     HCL             1.02843\n',
                        'S': 'S         32.06000     H2S             1.06288\n',
                        'F': 'F         18.99840     HF              1.05305\n',
                        'Hg':'HG       200.59000     HGO             1.07971\n',
                        'Mn':'MN        54.93800     MNO             1.29123\n',
                        'Fe':'FE        55.84700     FEO             1.28649\n',
                        'Cu':'CU        63.54600     CU2O            1.12590\n',
                        'Au':'AU       196.96650     AU              1.00000\n',
                        'Cs':'CS       132.90540     CS2O            1.06019\n',
                        'Cd':'CD       112.40000     CDO             1.00000\n',
                        'U': 'U        238.02900     U3O8            1.17925\n',
                        'P': 'P         30.97376     P2O5            2.29137\n',
                        'Cr':'CR        51.99610     CR2O3           1.46156\n',
                        'Ti':'TI        47.86700     TIO2            1.66849\n',
                        'Zr':'ZR        91.22400     ZRO2            1.35077\n',
                        'Eu':'EU       151.96400     EU2O3           2.31585\n'
                        }
        for el in self.elements:
            s += element_lines[el]

        return s


    def _d0_t_p_block(self,T,P,s='',dT=50.0):
        """
        Construct the Temperature and Pressure grid. Puts the same T and P value at all positions.

        parameters
        ----------
        s : str
            The T P block will be added on to the end of the string passed.
        T : float
            Temperature in K at which to start.
        P : float
            Pressure in bar
        dT : float
            Temperature interval
        """

        T = T-273.15

        # Characters to first period
        indent = 10
        # Characters between periods
        spacing = 9

        temps = np.linspace(T,T+dT*7,8)

        # Convert Temperature and Pressure to string
        sT = list()
        for t in temps:
            sT.append('{0:.4f}'.format(t))
        sP = '{0:.3f}'.format(P)

        s += 'temperatures\n'
        s += ' '*(indent-len(sT[0].split('.')[0]))
        for i in range(4):
            s += sT[i] + ' '*(spacing-len(sT[i])+1)
        s += '\n'
        s += ' '*(indent-len(sT[3].split('.')[0]))
        for i in range(4):
            s += sT[i+4] + ' '*(spacing-len(sT[i])+1)
        s += '\n'
        s += 'pressures\n'
        s += (' '*(indent-len(sP.split('.')[0])) + sP + (' '*(spacing-len(sP)+1)+sP)*3 + '\n')*2

        return s



    def _d0_h2o_props_block(self,T,P,s='',dT=50.0):
        """
        """
        s_dha = []
        s_dhb = []
        for i in range(8):
            t = T+i*dT
            dha = obj.AgammaFromT_andP_(T,P)
            dhb = obj.BgammaFromT_andP_(T,P)
            s_dha.append('{0:0.4f}'.format(dha))
            s_dhb.append('{0:0.4f}'.format(dhb/1e8))

        s += 'debye huckel a (adh)\n'
        s += ' '*(10-len(s_dha[0].split('.')[0]))
        for i in range(4):
            s += (s_dha[i] + ' '*(10-len(s_dha[i])))
        s += '\n'
        s += ' '*(10-len(s_dha[4].split('.')[0]))
        for i in range(4):
            s += (s_dha[i+4] + ' '*(10-len(s_dha[i+4])))
        s += '\n'

        s += 'debye huckel b (bdh)\n'
        s += ' '*(10-len(s_dhb[0].split('.')[0]))
        for i in range(4):
            s += (s_dhb[i] + ' '*(10-len(s_dhb[i])))
        s += '\n'
        s += ' '*(10-len(s_dhb[4].split('.')[0]))
        for i in range(4):
            s += (s_dhb[i+4] + ' '*(10-len(s_dhb[i+4])))
        s += '\n'

        s += 'bdot\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += 'c co2 1\n'
        s += '       0.        0.        0.        0.      \n'
        s += '       0.        0.        0.        0.      \n'
        s += 'c co2 2\n'
        s += '       0.        0.        0.        0.      \n'
        s += '       0.        0.        0.        0.      \n'
        s += 'c co2 3\n'
        s += '       0.        0.        0.        0.      \n'
        s += '       0.        0.        0.        0.      \n'
        s += 'c co2 4\n'
        s += '       0.        0.        0.        0.\n'
        s += '       0.        0.        0.        0.\n'
        s += 'c h2o 1\n'
        s += '       0.        0.        0.        0.\n'
        s += '       0.        0.        0.        0.\n'
        s += 'c h2o 2\n'
        s += '       0.        0.        0.        0.\n'
        s += '       0.        0.        0.        0.\n'
        s += 'c h2o 3\n'
        s += '       0.        0.        0.        0.\n'
        s += '       0.        0.        0.        0.\n'
        s += 'c h2o 4\n'
        s += '       0.        0.        0.        0.\n'
        s += '       0.        0.        0.        0.\n'
        s += 'log k for eh reaction\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += 'log k for o2 gas solubility\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += 'log k for h2 gas solubility\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += 'log k for n2 gas solubility\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'
        s += '         0.0000    0.0000    0.0000    0.0000\n'

        return s

    def _d0_init_aq_species(self,s=''):
        s += 'aqueous species\n'
        return s

    def _d0_basis_set(self,species,s=''):
        # Spaces between = and .
        spacing = 4

        # characters until first, second, third . in elements
        el_1 = 8
        el_2 = 30
        el_3 = 52

        # characters between . and element name
        el_name = 4

        charge = core.get_charge(species)
        sCharge = '{0:.1f}'.format(charge)

        ion = '3.7'

        if species.abbrev in self.ion_size.keys():
            ion = '{0:.1f}'.format(self.ion_size[species.abbrev])

        formula = chem.get_Berman_formula(species.props['element_comp'][0])
        if species.abbrev in self.hydrated_species:
            formula = core.formula_to_dict(formula,add_H2O=self.hydrated_species[species.abbrev])
        else:
            formula = core.formula_to_dict(formula)

        s += species.abbrev + '\n'
        s += '    ENTERED BY=                         DATE=   /  /   \n'
        s += '        SOURCE=                      QUALITY= \n'
        s += '        CHARGE=' + ' '*(spacing-len(sCharge.split('.')[0])) + sCharge +'           TITR. FACTOR=   0.0 EQ/MOL\n'
        s += '      ION SIZE=' + ' '*(6-len(ion)) + ion + ' A         HYDR. NUMBER=  0.0\n'

        s += '     '+str(len(formula)) + ' CHEMICAL ELEMENTS=\n'
        sel = ''
        for i in range(len(formula)):
            sStoich = '{0:.3f}'.format(formula[list(formula.keys())[i]])
            if i%3 == 0:
                sel += ' '*(el_1 - len(sStoich.split('.')[0]))
            if i%3 == 1:
                sel += ' '*(el_2 - len(sStoich.split('.')[0]) - len(sel))
            if i%3 == 2:
                sel += ' '*(el_3 - len(sStoich.split('.')[0]) - len(sel))
            sel += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + list(formula.keys())[i].upper()
            if i%3 == 2 or i == len(formula) - 1:
                sel += '\n'
        s += sel
        s += '+----------------------------------------------------------------------------\n'

        return s

    def _d0_aqueous_species(self,species,t,p,s='',dT=50.0):
        # distance from = to .
        charge_space = 4

        # distance from . to TITR.
        titr_space = 12

        # characters until first, second, third . in elements and species
        el_1 = 8
        el_2 = 30
        el_3 = 52

        # characters between . and element name
        el_name = 4

        # logK margin to .
        margin_lk = 10

        # logK spacing between .
        spacing_lk = 9

        charge = core.get_charge(species)
        s_charge = '{0:.1f}'.format(charge)

        formula = chem.get_Berman_formula(species.props['element_comp'][0])
        if species.abbrev in self.hydrated_species:
            formula = core.formula_to_dict(formula,add_H2O=self.hydrated_species[species.abbrev])
        else:
            formula = core.formula_to_dict(formula)

        ion = '3.7'
        if species.abbrev in self.ion_size.keys():
            ion = '{0:.1f}'.format(self.ion_size[species.abbrev])

        s += species.abbrev + '\n'
        s += '    ENTERED BY=                         DATE=   /  /   \n'
        s += '        SOURCE=                      QUALITY=\n'
        s += '        CHARGE=' + ' '*(charge_space-len(s_charge.split('.')[0])) + s_charge + ' '*(titr_space-len(s_charge.split('.')[1])) + 'TITR. FACTOR=   1.0 EQ/MOL\n'
        s += '      ION SIZE=' + ' '*(6-len(ion)) + ion + ' A         HYDR. NUMBER=  0.0\n'
        s += '     ' + str(len(formula)) + ' CHEMICAL ELEMENTS=\n'

        sel = ''
        for i in range(len(formula)):
            sStoich = '{0:.3f}'.format(formula[list(formula.keys())[i]])
            if i%3 == 0:
                sel += ' '*(el_1 - len(sStoich.split('.')[0]))
            if i%3 == 1:
                sel += ' '*(el_2 - len(sStoich.split('.')[0]) - len(sel))
            if i%3 == 2:
                sel += ' '*(el_3 - len(sStoich.split('.')[0]) - len(sel))
            sel += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + list(formula.keys())[i].upper()
            if i%3 == 2 or i == len(formula) - 1:
                sel += '\n'
                s += sel
                sel = ''

        stoichiometry = self._stoichiometry[species.abbrev].copy()
        extra_h2o_in_rxn = 0

        for species_name in list(stoichiometry.keys()):
            if species_name in self.hydrated_species:
                extra_h2o_in_rxn = extra_h2o_in_rxn - stoichiometry[species_name]*self.hydrated_species[species_name]

        if extra_h2o_in_rxn != 0:
            if 'H2O' in stoichiometry:
                stoichiometry['H2O'] += extra_h2o_in_rxn
            else:
                stoichiometry['H2O'] = extra_h2o_in_rxn

        s += '     ' + str(len(stoichiometry)) + ' SPECIES IN REACTION=\n'
        srx = ''

        species_in_order = [species.abbrev]
        for species_name in list(stoichiometry.keys()):
            if species_name not in species_in_order:
                species_in_order.append(species_name)

        for i in range(len(stoichiometry)):
            sStoich = '{0:.3f}'.format(stoichiometry[species_in_order[i]])
            if i%3 == 0:
                srx += ' '*(el_1 - len(sStoich.split('.')[0]))
            if i%3 == 1:
                srx += ' '*(el_2 - len(sStoich.split('.')[0]) - len(srx))
            if i%3 == 2:
                srx += ' '*(el_3 - len(sStoich.split('.')[0]) - len(srx))
            srx += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + species_in_order[i]
            if i%3 == 2 or i == len(stoichiometry) - 1:
                srx += '\n'
                s += srx
                srx = ''

        slogK = []
        for i in range(8):
            logKr = self.logK(species, t+dT*i, p)
            slogK.append('{0:.4f}'.format(logKr))

        s += ' '*(margin_lk - len(slogK[0].split('.')[0])) + slogK[0]
        for i in range(3):
            s += (' '*(spacing_lk-len(slogK[i+1])+1) + slogK[i+1])
        s += '\n'
        s += ' '*(margin_lk - len(slogK[4].split('.')[0])) + slogK[4]
        for i in range(3):
            s += (' '*(spacing_lk-len(slogK[i+5])+1) + slogK[i+5])
        s += '\n'

        s += '         0.0000    0.0000    0.0000    0.0000   \n'*2
        s += '+----------------------------------------------------------------------------\n'

        return(s)

    def _d0_dummy_species(self,abbrev,charge,formula,s=''):
        # distance from = to .
        charge_space = 4

        # distance from . to TITR.
        titr_space = 12

        # characters until first, second, third . in elements and species
        el_1 = 8
        el_2 = 30
        el_3 = 52

        # characters between . and element name
        el_name = 4

        # logK margin to .
        margin_lk = 10

        # logK spacing between .
        spacing_lk = 9

        s_charge = '{0:.1f}'.format(charge)

        ion = '3.7'

        s += abbrev + '\n'
        s += '    ENTERED BY=                         DATE=   /  /   \n'
        s += '        SOURCE=                      QUALITY=\n'
        s += '        CHARGE=' + ' '*(charge_space-len(s_charge.split('.')[0])) + s_charge + ' '*(titr_space-len(s_charge.split('.')[1])) + 'TITR. FACTOR=   1.0 EQ/MOL\n'
        s += '      ION SIZE=' + ' '*(6-len(ion)) + ion + ' A         HYDR. NUMBER=  0.0\n'
        s += '     ' + str(len(formula)) + ' CHEMICAL ELEMENTS=\n'

        sel = ''
        for i in range(len(formula)):
            sStoich = '{0:.3f}'.format(formula[list(formula.keys())[i]])
            if i%3 == 0:
                sel += ' '*(el_1 - len(sStoich.split('.')[0]))
            if i%3 == 1:
                sel += ' '*(el_2 - len(sStoich.split('.')[0]) - len(sel))
            if i%3 == 2:
                sel += ' '*(el_3 - len(sStoich.split('.')[0]) - len(sel))
            sel += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + list(formula.keys())[i].upper()
            if i%3 == 2 or i == len(formula) - 1:
                sel += '\n'
                s += sel
                sel = ''

        ### FIND STOICHIOMETRY- MODIFIED FIND_REACTION FUNCTION
        matrix = np.zeros([np.shape(self._basis_species_matrix)[0]+1,np.shape(self._basis_species_matrix)[1]+1])
        matrix[:-1,:-1] = self._basis_species_matrix
        for i in range(len(self.elements)):
            if self.elements[i] in list(formula.keys()):
                matrix[-1,i] = formula[self.elements[i]]
        matrix[-1,-2] = charge
        matrix[-1,-1] = 1

        b = np.zeros(len(self.basis_species)+1)
        b[-1] = -1

        soln = np.linalg.solve(matrix.T,b)

        stoich = {}

        for i in range(len(soln)):
            if np.abs(soln[i]) > 1e-15 and i<len(soln)-1:
                stoich[self.basis_species[i].abbrev] = soln[i]
            if i == len(soln)-1:
                stoich[abbrev] = soln[i]


        s += '     ' + str(len(stoich)) + ' SPECIES IN REACTION=\n'
        srx = ''

        species_in_order = [abbrev]
        for species_name in list(stoich.keys()):
            if species_name not in species_in_order:
                species_in_order.append(species_name)

        for i in range(len(stoich)):
            sStoich = '{0:.3f}'.format(stoich[species_in_order[i]])
            if i%3 == 0:
                srx += ' '*(el_1 - len(sStoich.split('.')[0]))
            if i%3 == 1:
                srx += ' '*(el_2 - len(sStoich.split('.')[0]) - len(srx))
            if i%3 == 2:
                srx += ' '*(el_3 - len(sStoich.split('.')[0]) - len(srx))
            srx += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + species_in_order[i]
            if i%3 == 2 or i == len(stoich) - 1:
                srx += '\n'
                s += srx
                srx = ''

        logKr = 1.0

        slogK = '{0:.4f}'.format(logKr)

        s += (' '*(margin_lk - len(slogK.split('.')[0])) + slogK + (' '*(spacing_lk-len(slogK)+1) + slogK)*3 + '\n')*2

        s += '         0.0000    0.0000    0.0000    0.0000   \n'*2
        s += '+----------------------------------------------------------------------------\n'

        return(s)

    def _d0_minerals(self,species,t,p,s='',dT=50.0):
        # distance from = to .
        charge_space = 4

        # distance from . to TITR.
        titr_space = 12

        # characters until first, second, third . in elements and species
        el_1 = 8
        el_2 = 30
        el_3 = 52

        # characters between . and element name
        el_name = 4

        # logK margin to .
        margin_lk = 10

        # logK spacing between .
        spacing_lk = 9

        # If the mineral is a pure phase
        if species.endmember_num == 1:
            formula = chem.get_Berman_formula(species.props['element_comp'][0])
            formula = core.formula_to_dict(formula)

            if len(species.phase_name) > 13:
                phname = species.phase_name[:13]
            else:
                phname = species.phase_name
            s += phname.upper() + '\n'
            s += '    ENTERED BY=                         DATE=   /  /   \n'
            s += '        SOURCE=                      QUALITY=\n'
            s += '        VOLUME=   10.000 CC/MOL \n'
            s += '     ' + str(len(formula)) + ' CHEMICAL ELEMENTS=\n'

            sel = ''
            for i in range(len(formula)):
                sStoich = '{0:.3f}'.format(formula[list(formula.keys())[i]])
                if i%3 == 0:
                    sel += ' '*(el_1 - len(sStoich.split('.')[0]))
                if i%3 == 1:
                    sel += ' '*(el_2 - len(sStoich.split('.')[0]) - len(sel))
                if i%3 == 2:
                    sel += ' '*(el_3 - len(sStoich.split('.')[0]) - len(sel))
                sel += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + list(formula.keys())[i].upper()
                if i%3 == 2 or i == len(formula) - 1:
                    sel += '\n'
                    s += sel
                    sel = ''

            stoichiometry = self._stoichiometry[species.abbrev].copy()
            extra_h2o_in_rxn = 0

            for species_name in list(stoichiometry.keys()):
                if species_name in self.hydrated_species:
                    extra_h2o_in_rxn -= stoichiometry[species_name]*self.hydrated_species[species_name]

            if 'H2O' in stoichiometry:
                totH2O = stoichiometry['H2O'] + extra_h2o_in_rxn
            else:
                totH2O = extra_h2o_in_rxn
            if totH2O != 0:
                if 'H2O' in stoichiometry:
                    stoichiometry['H2O'] += extra_h2o_in_rxn
                else:
                    stoichiometry['H2O'] = extra_h2o_in_rxn

            s += '     ' + str(len(stoichiometry)) + ' SPECIES IN REACTION=\n'
            srx = ''

            species_in_order = [species.abbrev]
            species_names_in_order = [species.phase_name.upper()]
            for species_name in list(stoichiometry.keys()):
                if species_name not in species_in_order:
                    species_in_order.append(species_name)
                    species_names_in_order.append(species_name)

            for i in range(len(stoichiometry)):
                sStoich = '{0:.3f}'.format(stoichiometry[species_in_order[i]])
                if i%3 == 0:
                    srx += ' '*(el_1 - len(sStoich.split('.')[0]))
                if i%3 == 1:
                    srx += ' '*(el_2 - len(sStoich.split('.')[0]) - len(srx))
                if i%3 == 2:
                    srx += ' '*(el_3 - len(sStoich.split('.')[0]) - len(srx))
                if len(species_names_in_order[i]) > 13:
                    species_name_to_print = species_names_in_order[i][:13]
                else:
                    species_name_to_print = species_names_in_order[i]
                srx += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + species_name_to_print
                if i%3 == 2 or i == len(stoichiometry) - 1:
                    srx += '\n'
                    s += srx
                    srx = ''

            slogK = []
            for i in range(8):
                logKr = self.logK(species,t+dT*i,p,mineral=True)
                slogK.append('{0:.4f}'.format(logKr))

            s += ' '*(margin_lk - len(slogK[0].split('.')[0])) + slogK[0]
            for i in range(3):
                s += (' '*(spacing_lk-len(slogK[i+1])+1) + slogK[i+1])
            s += '\n'
            s += ' '*(margin_lk - len(slogK[4].split('.')[0])) + slogK[4]
            for i in range(3):
                s += (' '*(spacing_lk-len(slogK[i+5])+1) + slogK[i+5])
            s += '\n'

            s += '         0.0000    0.0000    0.0000    0.0000   \n'*2
            s += '+----------------------------------------------------------------------------\n'

        # If the mineral is a solid solution
        else:
            for ei in range(species.endmember_num):
                endm_name = species.endmember_names[ei]
                if len(endm_name) > 15:
                    endm_name = endm_name[:15]

                endm = np.zeros(species.endmember_num)
                endm[ei] = 1
                formula = formula_from_ss(species,ei)

                # Check endmember is in the chemical system in use
                if all(el in self.elements for el in formula):

                    s += endm_name + '\n'
                    s += '    ENTERED BY=                         DATE=   /  /   \n'
                    s += '        SOURCE=                      QUALITY=\n'
                    s += '        VOLUME=   10.000 CC/MOL \n'
                    s += '     ' + str(len(formula)) + ' CHEMICAL ELEMENTS=\n'

                    sel = ''
                    for i in range(len(formula)):
                        sStoich = '{0:.3f}'.format(formula[list(formula.keys())[i]])
                        if i%3 == 0:
                            sel += ' '*(el_1 - len(sStoich.split('.')[0]))
                        if i%3 == 1:
                            sel += ' '*(el_2 - len(sStoich.split('.')[0]) - len(sel))
                        if i%3 == 2:
                            sel += ' '*(el_3 - len(sStoich.split('.')[0]) - len(sel))
                        sel += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + list(formula.keys())[i].upper()
                        if i%3 == 2 or i == len(formula) - 1:
                            sel += '\n'
                            s += sel
                            sel = ''

                    stoichiometry = self._stoichiometry[species.endmember_names[ei]].copy()
                    extra_h2o_in_rxn = 0

                    for species_name in list(stoichiometry.keys()):
                        if species_name in self.hydrated_species:
                            extra_h2o_in_rxn -= stoichiometry[species_name]*self.hydrated_species[species_name]

                    if 'H2O' in stoichiometry:
                        totH2O = stoichiometry['H2O'] + extra_h2o_in_rxn
                    else:
                        totH2O = extra_h2o_in_rxn
                    if totH2O != 0:
                        if 'H2O' in stoichiometry:
                            stoichiometry['H2O'] += extra_h2o_in_rxn
                        else:
                            stoichiometry['H2O'] = extra_h2o_in_rxn

                    s += '     ' + str(len(stoichiometry)) + ' SPECIES IN REACTION=\n'
                    srx = ''

                    species_in_order = [species.endmember_names[ei]]
                    for species_name in list(stoichiometry.keys()):
                        if species_name not in species_in_order:
                            species_in_order.append(species_name)

                    for i in range(len(stoichiometry)):
                        sStoich = '{0:.3f}'.format(stoichiometry[species_in_order[i]])
                        if i%3 == 0:
                            srx += ' '*(el_1 - len(sStoich.split('.')[0]))
                        if i%3 == 1:
                            srx += ' '*(el_2 - len(sStoich.split('.')[0]) - len(srx))
                        if i%3 == 2:
                            srx += ' '*(el_3 - len(sStoich.split('.')[0]) - len(srx))
                        if i == 0:
                            srx += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + endm_name
                        else:
                            srx += sStoich + ' '*(el_name-len(sStoich.split('.')[1])) + species_in_order[i]
                        if i%3 == 2 or i == len(stoichiometry) - 1:
                            srx += '\n'
                            s += srx
                            srx = ''

                    slogK = []
                    for i in range(8):
                        logKr = self.logK(species,t,p,mineral=True,endi=ei)
                        slogK.append('{0:.4f}'.format(logKr))

                    s += ' '*(margin_lk - len(slogK[0].split('.')[0])) + slogK[0]
                    for i in range(3):
                        s += ' '*(spacing_lk-len(slogK[i+1])+1) + slogK[i+1]
                    s += '\n'
                    s += ' '*(margin_lk - len(slogK[4].split('.')[0])) + slogK[4]
                    for i in range(3):
                        s += ' '*(spacing_lk-len(slogK[i+5])+1) + slogK[i+5]
                    s += '\n'

                    s += '         0.0000    0.0000    0.0000    0.0000   \n'*2
                    s += '+----------------------------------------------------------------------------\n'

        return(s)


    def _d0_end_species(self,s=''):
        s += 'endit.\n'
        s += 'minerals \n'
        return s

    def _d0_end_minerals(self,s=''):
        s += 'endit.\n'
        s += 'gases \n'
        s += 'O2                   X\n'
        s += '    ENTERED BY=                         DATE=   /  /    \n'
        s += '        SOURCE=                      QUALITY=        \n'
        s += '        VOLUME=    0.000 CC/MOL      \n'
        s += '     1 CHEMICAL ELEMENTS=    \n'
        s += '       2.000 O  \n'
        s += '     2 SPECIES IN REACTION=  \n'
        s += '      -1.000 O2              1.000 O2      \n'
        s += '         0.0000    0.0000    0.0000    0.0000  \n'
        s += '         0.0000    0.0000    0.0000    0.0000  \n'
        s += '         0.0000    0.0000    0.0000    0.0000   \n'
        s += '         0.0000    0.0000    0.0000    0.0000   \n'
        s += '+----------------------------------------------------------------------------\n'
        return s

    def _d0_end_gases(self,s=''):
        s += 'endit.\n'
        s += 'solid solutions \n'
        return s

    def _d0_solid_solution(self,ss,s=''):
        ss_name = ss[0]
        ss_endmembers = ss[1]
        s += ss_name + (24-len(ss_name))*' '+str(len(ss_endmembers))+'    0\n'
        for i in range(len(ss_endmembers)):
            if i%2 == 0:
                s += '       1.000 ' + ss_endmembers[i] + (22-len(ss_endmembers[i]))*' '
            else:
                s += '1.000 ' + ss_endmembers[i] + '\n'
        if len(ss_endmembers)%2 == 1:
            s += '\n'
        s += '\n'
        s += '    0.0000    0.0000    0.0000    0.0000    0.0000    0.0000\n'*2
        s += '+----------------------------------------------------------------------\n'
        return s

    def _d0_end_solid_solutions(self,s=''):
        s += 'endit.\n'
        s += 'stop.'
        return s


    def _find_reaction(self,species):
        if species.endmember_num == 1:
            formula = core.formula_to_dict(chem.get_Berman_formula(species.props['element_comp'][0]))
            matrix = np.zeros([np.shape(self._basis_species_matrix)[0]+1,np.shape(self._basis_species_matrix)[1]+1])
            matrix[:-1,:-1] = self._basis_species_matrix
            for i in range(len(self.elements)):
                if self.elements[i] in list(formula.keys()):
                    matrix[-1,i] = formula[self.elements[i]]
            matrix[-1,-2] = core.get_charge(species)
            matrix[-1,-1] = 1

            b = np.zeros(len(self.basis_species)+1)
            b[-1] = -1

            soln = np.linalg.solve(matrix.T,b)

            stoich = {}

            for i in range(len(soln)):
                if np.abs(soln[i]) > 1e-15 and i<len(soln)-1:
                    stoich[self.basis_species[i].abbrev] = soln[i]
                if i == len(soln)-1:
                    stoich[species.abbrev] = soln[i]

            self._stoichiometry[species.abbrev] = stoich
        else:
            for i in range(species.endmember_num):
                endm = np.zeros(species.endmember_num)
                endm[i] = 1
                formula = core.formula_from_ss(species,i)

                matrix = np.zeros([np.shape(self._basis_species_matrix)[0]+1,np.shape(self._basis_species_matrix)[1]+1])
                matrix[:-1,:-1] = self._basis_species_matrix
                for j in range(len(self.elements)):
                    if self.elements[j] in list(formula.keys()):
                        matrix[-1,j] = formula[self.elements[j]]
                matrix[-1,-2] = core.get_charge(species)
                matrix[-1,-1] = 1

                b = np.zeros(len(self.basis_species)+1)
                b[-1] = -1

                soln = np.linalg.solve(matrix.T,b)

                stoich = {}

                for j in range(len(soln)):
                    if np.abs(soln[j]) > 1e-15 and j<len(soln)-1:
                        stoich[self.basis_species[j].abbrev] = soln[j]
                    if j == len(soln)-1:
                        stoich[species.endmember_names[i]] = soln[j]

                self._stoichiometry[species.endmember_names[i]] = stoich



    def _make_basis_species_matrix(self,swap_H_OH = False, exclude_gas = False):
        formulae = list()

        if exclude_gas == True:
            basis_species_use = self.basis_species_soln
        else:
            basis_species_use = self.basis_species

        if swap_H_OH == True:
            basis_species_use = copy(basis_species_use)
            basis_species_use[1] = self.other_species[self.other_species_names.index('OH-')]

        for s in basis_species_use:
            formula = core.formula_to_dict(chem.get_Berman_formula(s.props['element_comp'][0]))
            formulae += [formula]

        matrix = np.zeros([len(basis_species_use),self.n_elements+1])
        for i in range(len(basis_species_use)):
            for j in range(self.n_elements):
                if self.elements[j] in list(formulae[i].keys()):
                    matrix[i,j] = formulae[i][self.elements[j]]
            matrix[i,-1] = core.get_charge(basis_species_use[i])

        return matrix


    def make_data0(self,t,p,dT=50.0):
        s = self._d0_preamble()
        s = self._d0_t_p_block(t,p,s,dT=dT)
        s = self._d0_h2o_props_block(t,p,s,dT=dT)
        s = self._d0_init_aq_species(s)
        for spec in self.basis_species:
            s = self._d0_basis_set(spec,s=s)
        for spec in self.other_species:
            s = self._d0_aqueous_species(spec,t,p,s=s,dT=dT)
        for dummy in self.dummy_species:
            s = self._d0_dummy_species(dummy['abbrev'],dummy['charge'],
                                      dummy['formula'],s)
        s = self._d0_end_species(s=s)
        for miner in self.minerals:
            s = self._d0_minerals(miner,t,p,s=s,dT=dT)
        s = self._d0_end_minerals(s=s)
        s = self._d0_end_gases(s=s)
        for ss in self.solid_solutions.items():
            s = self._d0_solid_solution(ss,s=s)
        s = self._d0_end_solid_solutions(s=s)

        file = open('DATA0','w')
        file.write(s)
        file.close()

    def logK(self,species,t,p,mineral=False,endi=0):
        DG = 0.0
        if species.abbrev == 'O2':
            DG += self._stoichiometry[species.abbrev][species.abbrev]*self.muO2(t,p)
        elif species.endmember_num == 1:
            DG += self._stoichiometry[species.abbrev][species.abbrev]*species.gibbs_energy(t,p)
        else:
            endm = np.zeros(species.endmember_num)
            endm[endi] = 1
            DG += self._stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]*species.gibbs_energy(t,p,mol=endm)

        if mineral == True:
            if species.endmember_num == 1:
                formula = core.formula_to_dict(chem.get_Berman_formula(species.props['element_comp'][0]))
                if 'Na' in formula:
                    DG += -1626*4.184*formula['Na']*self._stoichiometry[species.abbrev][species.abbrev]
                if 'K' in formula:
                    DG += -1600*4.184*formula['K']*self._stoichiometry[species.abbrev][species.abbrev]
            else:
                endm = np.zeros(species.endmember_num)
                endm[endi] = 1
                formula = formula_from_ss(species,endi)

                # Add reference state corrections
#                 for el in formula:
#                     DG += formula[el]*self.stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]*robieref[el]*298.15

                if 'Na' in formula:
                    DG += -1626*4.184*formula['Na']*self._stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]
                if 'K' in formula:
                    DG += -1600*4.184*formula['K']*self._stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]

        if species.endmember_num == 1:
            species_name = species.abbrev
        else:
            species_name = species.endmember_names[endi]

        for s in self.basis_species:
            if s.abbrev in list(self._stoichiometry[species_name].keys()) and s.abbrev != 'H+':
                if s.abbrev == 'O2':
                    DG += self._stoichiometry[species_name][s.abbrev]*self.muO2(t,p)
                else:
                    DG += self._stoichiometry[species_name][s.abbrev]*s.gibbs_energy(t,p)
        return -DG/(8.3145*t)/2.303

    def muO2(self,t, p):
        tr = 298.15
        hs = 23.10248*(t-tr) + 2.0*804.8876*(np.sqrt(t)-np.sqrt(tr)) - 1762835.0*(1.0/t-1.0/tr) \
           - 18172.91960*np.log(t/tr) + 0.5*0.002676*(t*t-tr*tr)
        ss = 205.15 + 23.10248*np.log(t/tr)  - 2.0*804.8876*(1.0/np.sqrt(t)-1.0/np.sqrt(tr)) \
           - 0.5*1762835.0*(1.0/(t*t)-1.0/(tr*tr)) + 18172.91960*(1.0/t-1.0/tr) + 0.002676*(t-tr)
        return hs - t*ss + 205.15*298.15
