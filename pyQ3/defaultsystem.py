# Specifies variables to use when constructing the default DEW system

elements = ['O', 'H', 'Ag', 'Al', 'Au', 'Ba', 'Ca', 'C', 'Si', 'Cl', 'S', 'Cd', 'N', 'Cr', 'Cs',
            'Cu', 'Eu', 'F', 'Fe', 'P', 'Hg', 'K', 'Mg', 'Mn', 'Na', 'Pb', 'Sr', 'U', 'Zn']

basis_species_names = ['H2O', 'H+', 'AG+', 'AL+3', 'AU+', 'BA+2', 'CA+2', 'CO2(AQ)', 'H4SIO4(AQ)',
                       'CL-', 'SO4-2', 'CD+2', 'N2(AQ)', 'CR+2', 'CS+', 'CU+', 'EU+2', 'F-',
                       'FE+2', 'H3PO4(AQ)', 'HG+2', 'K+', 'MG+2', 'MN+2', 'NA+', 'PB+2', 'SR+2',
                       'U+4', 'ZN+2', 'O2(G)']

other_species_names = ['CH3COO-','CH3COOH(AQ)','AG+','AL+3','AL(OH)4-','AL(OH)SI(OH)-','AU+','BA+2','CA(HCO3)+','CA(HCOO)+','CA(H3SIO4)+',
    'CA(OH)+','CA+2','CACL+','CACO3(AQ)','CASO4(AQ)','CD+2','CL-','CN-','CO(AQ)','CO2(AQ)','CO3-2','CR+2','CS+','CU+','CU+2','DIGLYCINE(AQ)',
    'DKP(AQ)','ETHANE(AQ)','ETHANOL(AQ)','ETHYLENE(AQ)','EU+2','F-','FE(HCOO)+','FE(OH)+','FE+2','FE+3','FECL+','FECL+2','FECL2(AQ)',
    'FECL3(AQ)','FECL4-','FE(OH)2(AQ)','HCOO-','HCOOH(AQ)','GLUTAMIC(AQ)','GLYCINE(AQ)','H+','H2(AQ)','H2CO3(AQ)','H2PO4-','H2S(AQ)',
    'H3PO4(AQ)','AL(OH)3(AQ)','HCL(AQ)','HCO3-','FE(OH)3-','HG+2','HG2+2','HPO4-2','HS-','H3SIO4-','HSO4-','K+','KCL(AQ)','KOH(AQ)','KSO4-',
    'METHANE(AQ)','METHANOL(AQ)','MG(HCO3)+','MG(H3SIO4)+','MG+2','MGCL+','MGCO3(AQ)','MG(OH)+','MGSIC+','MGSO4(AQ)','MN+2','N2(AQ)','NA+',
    'NACL(AQ)','NACO3-','NAHCO3(AQ)','NAOH(AQ)','NH3(AQ)','NH4+','NO3-','O2(AQ)','OH-','PB+2','PROPANE(AQ)','CH3CH2COO-','PROPANOL(AQ)','S3-',
    'H6SI2O7(AQ)','H8SI3O10(AQ)','H4SIO4(AQ)','SO4-2','SR+2','SRCL+','U+4','UO2+2','UREA(AQ)','ZN+2']

hydrated_species = { 'AL(OH)4-': 2, 'AL(OH)SI(OH)-': 3, 'CA(H3SIO4)+': 1, 'FE(OH)2(AQ)': 1,
    'AL(OH)3(AQ)': 1, 'FE(OH)3-': 1, 'H3SIO4-': 1, 'MG(H3SIO4)+': 1, 'MGSIC+': 1,
    'H6SI2O7(AQ)': 3, 'H8SI3O10(AQ)': 4, 'H4SIO4(AQ)': 2,}

gases = ['H2(G)']


ion_size = {'O2(AQ)':-0.5, 'H2(AQ)':-0.5, 'N2(AQ)':-0.5, 'CO(AQ)':-0.5, 'CH4(AQ)':-0.5,
            'ETHANE(AQ)':-0.5, 'PROPANE(AQ)':-0.5,'METHANE(AQ)':-0.5, 'METHANOL(AQ)':-0.5,
            'ETHANOL(AQ)':-0.5, 'PROPANOL(AQ)':-0.5, 'CO2(AQ)':-0.5, 'H2CO3(AQ)':-0.5,
            'ACETIC(AQ)':-0.5, 'PROPANOIC(AQ)':-0.5, 'GLUTAMIC(AQ)':-0.5, 'H2O':0.0,
            'O2(G)':0.0, 'FORMIC(AQ)':0.0}


minerals = ['HYDROXYAPATITE', 'FLUORAPATITE', 'CHLORAPATITE', 'DIAMOND', 'MAGNETITE', 'CORUNDUM',
            'HEMATITE', 'PERICLASE', 'LIME', 'SPINEL', 'BRUCITE', 'DIASPORE', 'CALCITE',
            'MAGNESITE', 'SIDERITE', 'ARAGONITE', 'DOLOMITE', 'ANDALUSITE', 'KYANITE',
            'SILLIMANITE', 'GLAUCOPHANE', 'LAWSONITE', 'PUMPELLYITE', 'ZOISITE', 'CLINOZOISITE',
            'FORSTERITE', 'FAYALITE', 'MONTICELLITE', 'MERWINITE', 'CHRYSOTILE', 'ENSTATITE_CL',
            'ENSTATITE_OR', 'ENSTATITE_PR', 'DIOPSIDE', 'HEDENBERGITE', 'JADEITE', 'CAALPYROXENE',
            'FERROSILITE', 'WOLLASTONITE', 'PSEUDOWOLLA', 'TREMOLITE', 'ANTHOPHYLLITE',
            'CORDIERITE', 'KFELDSPAR', 'ALBITE', 'ANORTHITE', 'GEHLENITE', 'KAOLINITE',
            'ANTIGORITE', 'PYROPHYLLITE', 'TALC', 'MUSCOVITE', 'ANNITE', 'PHLOGOPITE',
            'PARAGONITE', 'MARGARITE', 'PREHNITE', 'CLINOCHLORE', 'CHAMOSITE', 'PYROPE',
            'ALMANDINE', 'GROSSULAR', 'MEIONITE', 'QUARTZ_ALPHA', 'QUARTZ_BETA', 'COESITE',
            'IRON_ALPHA', 'IRON_GAMMA', 'GRAPHITE', 'BARITE', 'PYRRHOTITE', 'PYRITE',
            'HALITE', 'SYLVITE', 'STRONTIANITE', 'ANHYDRITE', 'CELESTITE', 'CRISTO_ALPHA',
            'CRISTO_BETA', 'ALUNITE', 'HERCYNITE']

solid_solutions = {'KFELDSPAR(SS)':     ['KFELDSPAR',
                                         'ALBITE'
                                         ],
                   'PLAGIOCLASE(SS)':   ['ALBITE',
                                         'ANORTHITE'
                                         ],
                   'ORTHOPYROXENE(SS)': ['ENSTATITE_OR',
                                         'FERROSILITE'
                                         ],
                   'OLIVINE(SS)':       ['FORSTERITE',
                                         'FAYALITE'
                                         ],
                   'BIOTITE(SS)':       ['PHLOGOPITE',
                                         'ANNITE'
                                         ],
                   'GARNET(SS)':        ['PYROPE',
                                         'ALMANDINE',
                                         'GROSSULAR'
                                         ],
                   'CLINOPYROXENE(SS)': ['DIOPSIDE',
                                         'JADEITE',
                                         'HEDENBERGITE'
                                         ],
                   'CPX_SUBCALCIC(SS)': ['DIOPSIDE',
                                         'HEDENBERGITE',
                                         'ENSTATITE_CL'
                                         ],
                   'CA_AMPHIBOLE(SS)': ['TREMOLITE',
                                        'FERROTREMOLITE'
                                        ],
                   'CHLORITE(SS)':     ['CLINOCHLORE',
                                        'CHAMOSITE'
                                        ],
                   'CALCITE(SS)':      ['CALCITE',
                                        'MAGNESITE',
                                        'SIDERITE'
                                        ],
                   'APATITE(SS)':      ['HYDROXYAPATITE',
                                        'FLUORAPATITE',
                                        'CHLORAPATITE'
                                        ],
                   }
