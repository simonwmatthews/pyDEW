# Specifies variables to use when constructing the default DEW system

elements = ['O','H','Ag','Al','Au','Ba','Ca','C','Si','Cl','S','Cd','N','Cr','Cs','Cu','Eu','F','Fe','P','Hg','K','Mg','Mn','Na','Pb','Sr','U','Zn']

basis_species_names = ['H2O','H+','AG+','AL+3','AU+','BA+2','CA+2','CO2(AQ)','SIO2(AQ)','CL-','SO4-2','CD+2','N2(AQ)','CR+2','CS+','CU+',
    'EU+2','F-','FE+2','H3PO4(AQ)','HG+2','K+','MG+2','MN+2','NA+','PB+2','SR+2','U+4','ZN+2','O2']

other_species_names = ['ACETATE(AQ)','ACETIC-ACID(AQ)','AG+','AL+3','ALO2-','ALO2(SIO2)-','AU+','BA+2','CA(HCO3)+','CA(HCOO)+','CA(HSIO3)+',
    'CA(OH)+','CA+2','CACL+','CACO3(AQ)','CASO4(AQ)','CD+2','CL-','CN-','CO(AQ)','CO2(AQ)','CO3-2','CR+2','CS+','CU+','CU+2','DIGLYCINE(AQ)',
    'DIKETOPIPER(AQ)','ETHANE(AQ)','ETHANOL(AQ)','ETHYLENE(AQ)','EU+2','F-','FE(HCOO)+','FE(OH)+','FE+2','FE+3','FECL+','FECL+2','FECL2(AQ)',
    'FECL3(AQ)','FECL4-','FEO(AQ)','FORMATE(AQ)','FORMIC-ACID(AQ)','GLUTAMIC-AC(AQ)','GLYCINE(AQ)','H+','H2(AQ)','H2CO3(AQ)','H2PO4-','H2S(AQ)',
    'H3PO4(AQ)','HALO2(AQ)','HCL(AQ)','HCO3-','HFEO2-','HG+2','HG2+2','HPO4-2','HS-','HSIO3-','HSO4-','K+','KCL(AQ)','KOH(AQ)','KSO4-',
    'METHANE(AQ)','METHANOL(AQ)','MG(HCO3)+','MG(HSIO3)+','MG+2','MGCL+','MGCO3(AQ)','MG(OH)+','MGSIO2HCO3+','MGSO4(AQ)','MN+2','N2(AQ)','NA+',
    'NACL(AQ)','NACO3-','NAHCO3(AQ)','NAOH(AQ)','NH3(AQ)','NH4+','NO3-','O2(AQ)','OH-','PB+2','PROPANE(AQ)','PROPANOATE-','PROPANOL(AQ)','S3-',
    'SI2O4(AQ)','SI3O6(AQ)','SIO2(AQ)','SO4-2','SR+2','SRCL+','U+4','UO2+2','UREA(AQ)','ZN+2']

hydrated_species = {'ACETATE(AQ)': 0, 'ACETIC-ACID(AQ)': 0, 'AG+': 0, 'AL+3': 0, 'ALO2-': 2, 'ALO2(SIO2)-': 3, 'AU+': 0, 'BA+2': 0, 'CA(HCO3)+': 0,
    'CA(HCOO)+': 0, 'CA(HSIO3)+': 1, 'CA(OH)+': 0,'CA+2': 0,'CACL+': 0, 'CACO3(AQ)': 0, 'CASO4(AQ)': 0, 'CD+2': 0, 'CL-': 0, 'CN-': 0, 'CO(AQ)': 0,
    'CO2(AQ)': 0, 'CO3-2': 0, 'CR+2': 0, 'CS+': 0, 'CU+': 0, 'CU+2': 0, 'DIGLYCINE(AQ)': 0, 'DIKETOPIPER(AQ)': 0, 'ETHANE(AQ)': 0, 'ETHANOL(AQ)': 0,
    'ETHYLENE(AQ)': 0, 'EU+2': 0, 'F-': 0, 'FE(HCOO)+': 0, 'Fe(OH)+': 0, 'FE+2': 0, 'FE+3': 0, 'FECL+': 0, 'FECL+2': 0, 'FECL2(AQ)': 0, 'FECL3(AQ)': 0,
    'FECL4-': 0, 'FEO(AQ)': 1, 'FORMATE(AQ)': 0, 'FORMIC-ACID(AQ)': 0, 'GLUTAMIC-AC(AQ)': 0, 'GLYCINE(AQ)': 0, 'H+': 0, 'H2(AQ)': 0, 'H2CO3(AQ)': 0,
    'H2PO4-': 0, 'H2S(AQ)': 0, 'H3PO4(AQ)': 0, 'HALO2(AQ)': 1, 'HCL(AQ)': 0, 'HCO3-': 0, 'HFEO2-': 1, 'HG+2': 0, 'HG2+2': 0, 'HPO4-2': 0, 'HS-': 0,
    'HSIO3-': 1, 'HSO4-': 0, 'K+': 0, 'KCL(AQ)': 0, 'KOH(AQ)': 0, 'KSO4-': 0, 'METHANE(AQ)': 0, 'METHANOL(AQ)': 0, 'MG(HCO3)+': 0, 'MG(HSIO3)+': 1,
    'MG+2': 0, 'MGCL+': 0, 'MGCO3(AQ)': 0, 'MGOH+': 0, 'MGSIO2HCO3+': 1, 'MGSO4(AQ)': 0, 'MN+2': 0, 'N2(AQ)': 0, 'NA+': 0, 'NACL(AQ)': 0, 'NACO3-': 0,
    'NAHCO3(AQ)': 0, 'NAOH(AQ)': 0, 'NH3(AQ)': 0, 'NH4+': 0, 'NO3-': 0, 'O2,aq': 0, 'OH-': 0, 'PB+2': 0, 'PROPANE(AQ)': 0, 'PROPANOATE-': 0,
    'PROPANOL(AQ)': 0, 'S3-': 0, 'SI2O4(AQ)': 3, 'SI3O6(AQ)': 4, 'SIO2(AQ)': 2, 'SO4-2': 0, 'SR+2': 0, 'SRCL+': 0, 'U+4': 0, 'UO2+2': 0, 'UREA(AQ)': 0,
    'ZN+2': 0}


ion_size = {'O2,aq':-0.5,'H2,aq':-0.5,'N2,aq':-0.5,'CO,aq':-0.5,'CH4,aq':-0.5,'ethane,aq':-0.5,'propane,aq':-0.5,'methane,aq':-0.5,
            'methanol,aq':-0.5,'ethanol,aq':-0.5,'propanol,aq':-0.5,'CO2,aq':-0.5,'H2CO3,aq':-0.5,'acetic-acid,aq':-0.5,
            'propanoic-a,aq':-0.5,'glutamic-ac,aq':-0.5,'H2O':0.0,'O2':0.0,'formic-acid,aq':0.0}

minerals = []

solid_solutions = {}
