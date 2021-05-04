import numpy as np
import pandas as pd
from thermoengine import phases
from thermoengine import model
from thermoengine import chem
import dill
import subprocess
from copy import copy

from ctypes import cdll
from ctypes import util
from rubicon.objc import ObjCClass, objc_method
cdll.LoadLibrary(util.find_library('phaseobjc'))

DEWFluid = ObjCClass('DEWDielectricConstant')
obj = DEWFluid.alloc().init()

import sympy as sym
import os
import thermoengine

import pyximport
import importlib

# Reference state entropies from Robie et al. (1979)
robieref ={"H" :   130.68/2.0 ,
           "He":   126.15     ,
           "Li":    29.12     ,
           "Be":     9.54     ,
           "B" :     5.90     ,
           "C" :     5.74     ,
           "N" :   191.61/2.0 ,
           "O" :   205.15/2.0 ,
           "F" :   202.79/2.0 ,
           "Ne":   146.32     ,
           "Na":    51.30     ,
           "Mg":    32.68     ,
           "Al":    28.35     ,
           "Si":    18.81     ,
           "P" :    22.85     ,
           "S" :    31.80     ,
           "Cl":   223.08/2.0 ,
           "Ar":   154.84     ,
           "K" :    64.68     ,
           "Ca":    41.63     ,
           "Sc":    34.64     ,
           "Ti":    30.63     ,
           "V" :    28.91     ,
           "Cr":    23.64     ,
           "Mn":    32.01     ,
           "Fe":    27.28     ,
           "Co":    30.04     ,
           "Ni":    29.87     ,
           "Cu":    33.15     ,
           "Zn":    41.63     ,
           "Ga":    40.83     ,
           "Ge":    31.09     ,
           "As":    35.69     ,
           "Se":    42.27     ,
           "Br":   245.46/2.0 ,
           "Kr":   164.08     ,
           "Rb":    76.78     ,
           "Sr":    55.40     ,
           "Y" :    44.43     ,
           "Zr":    38.99     ,
           "Nb":    36.40     ,
           "Mo":    28.66     ,
           "Ru":    28.53     ,
           "Rh":    31.54     ,
           "Pd":    37.82     ,
           "Ag":    42.55     ,
           "Cd":    51.80     ,
           "In":    57.84     ,
           "Sn":    51.20     ,
           "Sb":    45.52     ,
           "Te":    49.50     ,
           "I" :   116.15/2.0 ,
           "Xe":   169.68     ,
           "Cs":    85.23     ,
           "Ba":    62.42     ,
           "La":    56.90     ,
           "Ce":    69.46     ,
           "Pr":    73.93     ,
           "Nd":    71.09     ,
           "Sm":    69.50     ,
           "Eu":    80.79     ,
           "Gd":    68.45     ,
           "Tb":    73.30     ,
           "Dy":    74.89     ,
           "Ho":    75.02     ,
           "Er":    73.18     ,
           "Tm":    74.01     ,
           "Yb":    59.83     ,
           "Lu":    50.96     ,
           "Hf":    43.56     ,
           "Ta":    41.51     ,
           "W" :    32.64     ,
           "Re":    36.53     ,
           "Os":    32.64     ,
           "Ir":    35.48     ,
           "Pt":    41.63     ,
           "Au":    47.49     ,
           "Hg":    75.90     ,
           "Tl":    64.18     ,
           "Pb":    65.06     ,
           "Bi":    56.74     ,
           "Rn":   176.23     ,
           "Th":    53.39     ,
           "U" :    50.29     ,
           "Pu":    51.46}

# Default number of H2O molecules to add. For species that aren't included in the DEW DATA0s, H2O has been set to 0.
waters = {'acetate,aq': 0,
         'acetic-acid,aq': 0,
         'Ag+': 0,
         'AgCl,aq': 0,
         'AgCl2-': 0,
         'Al+3': 0,
         'AlO2-': 2,
         'AlO2(SiO2)-': 3,
         'Ar,aq': 0,
         'Au+': 0,
         'Au+3': 0,
         'B(OH)3,aq': 0,
         'Ba+2': 0,
         'BaCl+': 0,
         'Be+2': 0,
         'benzene,aq': 0,
         'BO(OH),aq': 0,
         'BO2-': 0,
         'Br-': 0,
         'Ca(HCO3)+': 0,
         'Ca(HCOO)+': 0,
         'Ca(HSiO3)+': 1,
         'Ca(OH)+': 0,
         'Ca+2': 0,
         'CaCl+': 0,
         'CaCl2,aq': 0,
         'CaCO3,aq': 0,
         'CaO,aq': 1,
         'CaSO4,aq': 0,
         'Cd+2': 0,
         'Ce+3': 0,
         'Ce+4': 0,
         'Cl-': 0,
         'CN-': 0,
         'CO,aq': 0,
         'Co+2': 0,
         'Co+3': 0,
         'CO2,aq': 0,
         'CO3-2': 0,
         'Cr+2': 0,
         'Cr+3': 0,
         'Cr2O7-2': 0,
         'CrO4-2': 0,
         'Cs+': 0,
         'Cu+': 0,
         'Cu+2': 0,
         'diglycine,aq': 0,
         'diketopiper,aq': 0,
         'Dy+3': 0,
         'Er+3': 0,
         'ethane,aq': 0,
         'ethanol,aq': 0,
         'ethylene,aq': 0,
         'Eu+2': 0,
         'Eu+3': 0,
         'F-': 0,
         'Fe(CH3COO)+': 0,
         'Fe(CH3COO)2,aq': 0,
         'Fe(HCOO)+': 0,
         'Fe(HSiO3)+': 1,
         'Fe(OH)+': 0,
         'Fe+2': 0,
         'Fe+3': 0,
         'FeCl+': 0,
         'FeCl+2': 0,
         'FeCl2,aq': 0,
         'FeCl2+': 0,
         'FeCl3,aq': 0,
         'FeCl4-': 0,
         'FeO,aq': 1,
         'formate,aq': 0,
         'formic-acid,aq': 0,
         'Ga+3': 0,
         'Gd+3': 0,
         'glutamate-': 0,
         'glutamic-ac,aq': 0,
         'glutamine,aq': 0,
         'glutarate-': 0,
         'glutaric-ac,aq': 0,
         'glycinate-': 0,
         'glycine,aq': 0,
         'glycolate-': 0,
         'glycolic-ac,aq': 0,
         'H-succinate,aq': 0,
         'H+': 0,
         'H2,aq': 0,
         'H2AsO3-': 0,
         'H2AsO4-': 0,
         'H2CO3,aq': 0,
         'H2P2O7-2': 0,
         'H2PO4-': 0,
         'H2S,aq': 0,
         'H2VO4-': 0,
         'H3P2O7-': 0,
         'H3PO4,aq': 0,
         'HAlO2,aq': 1,
         'HAsO4-2': 0,
         'HCl,aq': 0,
         'HCN,aq': 0,
         'HCO3-': 0,
         'HCrO4-': 0,
         'He,aq': 0,
         'hexane,aq': 0,
         'HFeO2-': 1,
         'Hg+2': 0,
         'Hg2+2': 0,
         'Ho+3': 0,
         'HO2-': 0,
         'HPO4-2': 0,
         'HS-': 0,
         'HSe-': 0,
         'HSeO3-': 0,
         'HSeO4-': 0,
         'HSiO3-': 1,
         'HSO3-': 0,
         'HSO4-': 0,
         'HSO5-': 0,
         'HVO4-2': 0,
         'I-': 0,
         'In+3': 0,
         'isobutane,aq': 0,
         'K+': 0,
         'KCl,aq': 0,
         'KOH,aq': 0,
         'Kr,aq': 0,
         'KSO4-': 0,
         'La+3': 0,
         'lactate-': 0,
         'lactic-acid,aq': 0,
         'leucine,aq': 0,
         'Li+': 0,
         'Lu+3': 0,
         'methane,aq': 0,
         'methanol,aq': 0,
         'Mg(HCO3)+': 0,
         'Mg(HSiO3)+': 1,
         'Mg+2': 0,
         'MgCl+': 0,
         'MgCO3,aq': 0,
         'MgO,aq': 1,
         'MgOH+': 0,
         'MgSiO2HCO3+': 1,
         'MgSO4,aq': 0,
         'Mn+2': 0,
         'MnCl+': 0,
         'MnO4-': 0,
         'MnO4-2': 0,
         'MnSO4,aq': 0,
         'MoO4-2': 0,
         'N2,aq': 0,
         'Na(Ac),aq': 0,
         'Na(Ac)2-': 0,
         'Na+': 0,
         'NaCl,aq': 0,
         'NaCO3-': 0,
         'NaHCO3,aq': 0,
         'NaHSiO3,aq': 0,
         'NaOH,aq': 0,
         'Nd+3': 0,
         'Ne,aq': 0,
         'NH3,aq': 0,
         'NH4+': 0,
         'Ni+2': 0,
         'NO2-': 0,
         'NO3-': 0,
         'O2,aq': 0,
         'OH-': 0,
         'Pb+2': 0,
         'PbCl+': 0,
         'PbCl2,aq': 0,
         'PbCl3-': 0,
         'Pd+2': 0,
         'PO4-3': 0,
         'Pr+3': 0,
         'propane,aq': 0,
         'propanoate-': 0,
         'propanoic-a,aq': 0,
         'propanol,aq': 0,
         'Ra+2': 0,
         'Rb+': 0,
         'ReO4-': 0,
         'Rn,aq': 0,
         'S2-2': 0,
         'S2O3-2': 0,
         'S2O4-2': 0,
         'S2O5-2': 0,
         'S2O6-2': 0,
         'S2O8-2': 0,
         'S3-': 0,
         'S3-2': 0,
         'S3O6-2': 0,
         'S4-2': 0,
         'S4O6-2': 0,
         'S5-2': 0,
         'S5O6-2': 0,
         'Sc+3': 0,
         'SeO3-2': 0,
         'SeO4-2': 0,
         'Si2O4,aq': 3,
         'Si3O6,aq': 4,
         'SiO2,aq': 2,
         'Sm+2': 0,
         'Sm+3': 0,
         'Sn+2': 0,
         'SO2,aq': 0,
         'SO3-2': 0,
         'SO4-2': 0,
         'Sr+2': 0,
         'SrCl+': 0,
         'Tb+3': 0,
         'Tl+': 0,
         'Tl+3': 0,
         'Tm+3': 0,
         'toluene,aq': 0,
         'U+4': 0,
         'UO2+2': 0,
         'urea,aq': 0,
         'VO+2': 0,
         'VO2+': 0,
         'WO4-2': 0,
         'Xe,aq': 0,
         'Y+3': 0,
         'Yb+2': 0,
         'Yb+3': 0,
         'Zn+2': 0,
         'ZnCl+': 0,
         'ZnCl2,aq': 0,
         'ZnCl3-': 0}

# Which species to include in default DATA0 generation (based on whether they're in the DEW DATA0s)
includespecies = {'acetate,aq': 1,
                 'acetic-acid,aq': 1,
                 'Ag+': 1,
                 'AgCl,aq': 0,
                 'AgCl2-': 0,
                 'Al+3': 1,
                 'AlO2-': 1,
                 'AlO2(SiO2)-': 1,
                 'Ar,aq': 0,
                 'Au+': 1,
                 'Au+3': 0,
                 'B(OH)3,aq': 0,
                 'Ba+2': 1,
                 'BaCl+': 0,
                 'Be+2': 0,
                 'benzene,aq': 0,
                 'BO(OH),aq': 0,
                 'BO2-': 0,
                 'Br-': 0,
                 'Ca(HCO3)+': 1,
                 'Ca(HCOO)+': 1,
                 'Ca(HSiO3)+': 1,
                 'Ca(OH)+': 1,
                 'Ca+2': 1,
                 'CaCl+': 1,
                 'CaCl2,aq': 1,
                 'CaCO3,aq': 1,
                 'CaO,aq': 0,
                 'CaSO4,aq': 1,
                 'Cd+2': 1,
                 'Ce+3': 0,
                 'Ce+4': 0,
                 'Cl-': 1,
                 'CN-': 1,
                 'CO,aq': 1,
                 'Co+2': 0,
                 'Co+3': 0,
                 'CO2,aq': 1,
                 'CO3-2': 1,
                 'Cr+2': 1,
                 'Cr+3': 0,
                 'Cr2O7-2': 0,
                 'CrO4-2': 0,
                 'Cs+': 1,
                 'Cu+': 1,
                 'Cu+2': 1,
                 'diglycine,aq': 1,
                 'diketopiper,aq': 1,
                 'Dy+3': 0,
                 'Er+3': 0,
                 'ethane,aq': 1,
                 'ethanol,aq': 1,
                 'ethylene,aq': 1,
                 'Eu+2': 1,
                 'Eu+3': 0,
                 'F-': 1,
                 'Fe(CH3COO)+': 0,
                 'Fe(CH3COO)2,aq': 0,
                 'Fe(HCOO)+': 1,
                 'Fe(HSiO3)+': 0,
                 'Fe(OH)+': 1,
                 'Fe+2': 1,
                 'Fe+3': 1,
                 'FeCl+': 1,
                 'FeCl+2': 1,
                 'FeCl2,aq': 1,
                 'FeCl2+': 0,
                 'FeCl3,aq': 1,
                 'FeCl4-': 1,
                 'FeO,aq': 1,
                 'formate,aq': 1,
                 'formic-acid,aq': 1,
                 'Ga+3': 0,
                 'Gd+3': 0,
                 'glutamate-': 0,
                 'glutamic-ac,aq': 1,
                 'glutamine,aq': 0,
                 'glutarate-': 0,
                 'glutaric-ac,aq': 0,
                 'glycinate-': 0,
                 'glycine,aq': 1,
                 'glycolate-': 0,
                 'glycolic-ac,aq': 0,
                 'H-succinate,aq': 0,
                 'H+': 1,
                 'H2,aq': 1,
                 'H2AsO3-': 0,
                 'H2AsO4-': 0,
                 'H2CO3,aq': 1,
                 'H2P2O7-2': 0,
                 'H2PO4-': 1,
                 'H2S,aq': 1,
                 'H2VO4-': 0,
                 'H3P2O7-': 0,
                 'H3PO4,aq': 1,
                 'HAlO2,aq': 1,
                 'HAsO4-2': 0,
                 'HCl,aq': 1,
                 'HCN,aq': 0,
                 'HCO3-': 1,
                 'HCrO4-': 0,
                 'He,aq': 0,
                 'hexane,aq': 0,
                 'HFeO2-': 1,
                 'Hg+2': 1,
                 'Hg2+2': 1,
                 'Ho+3': 0,
                 'HO2-': 0,
                 'HPO4-2': 1,
                 'HS-': 1,
                 'HSe-': 0,
                 'HSeO3-': 0,
                 'HSeO4-': 0,
                 'HSiO3-': 1,
                 'HSO3-': 0,
                 'HSO4-': 1,
                 'HSO5-': 0,
                 'HVO4-2': 0,
                 'I-': 0,
                 'In+3': 0,
                 'isobutane,aq': 0,
                 'K+': 1,
                 'KCl,aq': 1,
                 'KOH,aq': 1,
                 'Kr,aq': 0,
                 'KSO4-': 1,
                 'La+3': 0,
                 'lactate-': 0,
                 'lactic-acid,aq': 0,
                 'leucine,aq': 0,
                 'Li+': 0,
                 'Lu+3': 0,
                 'methane,aq': 1,
                 'methanol,aq': 1,
                 'Mg(HCO3)+': 1,
                 'Mg(HSiO3)+': 1,
                 'Mg+2': 1,
                 'MgCl+': 1,
                 'MgCO3,aq': 1,
                 'MgO,aq': 0,
                 'MgOH+': 1,
                 'MgSiO2HCO3+': 1,
                 'MgSO4,aq': 1,
                 'Mn+2': 1,
                 'MnCl+': 0,
                 'MnO4-': 0,
                 'MnO4-2': 0,
                 'MnSO4,aq': 0,
                 'MoO4-2': 0,
                 'N2,aq': 1,
                 'Na(Ac),aq': 0,
                 'Na(Ac)2-': 0,
                 'Na+': 1,
                 'NaCl,aq': 1,
                 'NaCO3-': 1,
                 'NaHCO3,aq': 1,
                 'NaHSiO3,aq': 0,
                 'NaOH,aq': 1,
                 'Nd+3': 0,
                 'Ne,aq': 0,
                 'NH3,aq': 1,
                 'NH4+': 1,
                 'Ni+2': 0,
                 'NO2-': 0,
                 'NO3-': 1,
                 'O2,aq': 1,
                 'OH-': 1,
                 'Pb+2': 1,
                 'PbCl+': 0,
                 'PbCl2,aq': 0,
                 'PbCl3-': 0,
                 'Pd+2': 0,
                 'PO4-3': 0,
                 'Pr+3': 0,
                 'propane,aq': 1,
                 'propanoate-': 1,
                 'propanoic-a,aq': 0,
                 'propanol,aq': 1,
                 'Ra+2': 0,
                 'Rb+': 0,
                 'ReO4-': 0,
                 'Rn,aq': 0,
                 'S2-2': 0,
                 'S2O3-2': 0,
                 'S2O4-2': 0,
                 'S2O5-2': 0,
                 'S2O6-2': 0,
                 'S2O8-2': 0,
                 'S3-': 1,
                 'S3-2': 0,
                 'S3O6-2': 0,
                 'S4-2': 0,
                 'S4O6-2': 0,
                 'S5-2': 0,
                 'S5O6-2': 0,
                 'Sc+3': 0,
                 'SeO3-2': 0,
                 'SeO4-2': 0,
                 'Si2O4,aq': 1,
                 'Si3O6,aq': 1,
                 'SiO2,aq': 1,
                 'Sm+2': 0,
                 'Sm+3': 0,
                 'Sn+2': 0,
                 'SO2,aq': 0,
                 'SO3-2': 0,
                 'SO4-2': 1,
                 'Sr+2': 1,
                 'SrCl+': 1,
                 'Tb+3': 0,
                 'Tl+': 0,
                 'Tl+3': 0,
                 'Tm+3': 0,
                 'toluene,aq': 0,
                 'U+4': 1,
                 'UO2+2': 1,
                 'urea,aq': 1,
                 'VO+2': 0,
                 'VO2+': 0,
                 'WO4-2': 0,
                 'Xe,aq': 0,
                 'Y+3': 0,
                 'Yb+2': 0,
                 'Yb+3': 0,
                 'Zn+2': 1,
                 'ZnCl+': 0,
                 'ZnCl2,aq': 0,
                 'ZnCl3-': 0}

ion_size = {'O2,aq':-0.5,'H2,aq':-0.5,'N2,aq':-0.5,'CO,aq':-0.5,'CH4,aq':-0.5,'ethane,aq':-0.5,'propane,aq':-0.5,'methane,aq':-0.5,
            'methanol,aq':-0.5,'ethanol,aq':-0.5,'propanol,aq':-0.5,'CO2,aq':-0.5,'H2CO3,aq':-0.5,'acetic-acid,aq':-0.5,
            'propanoic-a,aq':-0.5,'glutamic-ac,aq':-0.5,'H2O':0.0,'O2':0.0,'formic-acid,aq':0.0}

### FUNCTION FOR LOADING THE CODER OBJECTS (FROM CORE.IPYNB)
def load_coder_modules(working_dir='working'):
    pyximport.install(language_level=3)

    working_dir_code = np.array(os.listdir(working_dir))
    mask = np.array([file.endswith('.pyx') for file in working_dir_code ])
    mod_names = [os.path.splitext(file)[0] for file in working_dir_code[mask]]

    os.chdir('working')
    [importlib.import_module(mod_name) for mod_name in mod_names]
    os.chdir('..')




### FUNCTIONS FOR WRITING DATA0






# NEED TO BUILD A CHARGE FUNCTION INTO THE CODER PHASES, THEN
# WE CAN GET RID OF THIS FUNCTION.
def get_charge(species):
    abbrev = species.abbrev
    charge = 0.0
    if abbrev[-3:] == ',aq':
        charge = 0.0
    elif abbrev[-1] == '-':
        charge = -1.0
    elif abbrev[-1] == '+':
        charge = 1.0
    elif abbrev[-2] == '+':
        charge = float(abbrev[-1])
    elif abbrev[-2] == '-':
        charge = - float(abbrev[-1])
    return charge

def formula_to_dict(formula,add_H2O=0):
    split1 = formula.split('(')
    split2 = list()
    for s in split1:
        split2 += s.split(')')
    split2 = split2[:-1]

    d = {}
    elements = int(len(split2)/2)
    for i in range(elements):
        d[split2[i*2]] = float(split2[i*2+1])
    if add_H2O > 0:
        if 'H' in d:
            d['H'] = d['H'] + 2*add_H2O
        else:
            d['H'] = 2*add_H2O
        if 'O' in d:
            d['O'] = d['O'] + add_H2O
        else:
            d['O'] = add_H2O

    return d


def formula_from_ss(mineral,endi):
    endm = np.zeros(mineral.endmember_num)
    endm[endi] = 1.0
    fs = mineral.compute_formula(298.15,1.0,endm)
    split = {}
    el = ''
    st = ''
    inbracket = False
    els_in_bracket = []
    look_for_bracket_multiplier = False
    for j in range(len(fs)):

        if fs[j] == '(':
            inbracket = True

        if fs[j] not in ['0','1','2','3','4','5','6','7','8','9','.']:
            if look_for_bracket_multiplier == True:
                for el in els_in_bracket:
                    split[el] = split[el]*float(st)
                st = ''
                el = ''
                look_for_bracket_multiplier = False

            if len(st) > 0: #and look_for_bracket_multiplier == False:
                split[el] = float(st)
                if inbracket == True:
                    els_in_bracket += [el]
                el = ''
                st = ''
                if fs[j] != ')':
                    el += fs[j]
            elif fs[j] != '(' and fs[j] != ')' and fs[j] != "'":
                el += fs[j]


        else:
            st += fs[j]

        if j == len(fs)-1:
            split[el] = float(st)

        if fs[j] == ')':
            inbracket = False
            look_for_bracket_multiplier = True

    formula = {}
    Fetot = 0.0
    for el in split:
        if 'Fe' not in el and split[el] > 0.0:
            formula[el] = split[el]
        else:
            Fetot += split[el]
    if Fetot > 0:
        formula['Fe'] = Fetot

    return formula





class eq3output:
    def __init__(self,filename='output',suppress_warnings=False):
        f = open(filename,'r',encoding='mac-roman')

        # Variable to store important parameters from the input printout
        self.calc_props = dict()
        self.jflags = []
        self.solid_solution_input = dict()
        self.basis_species = []
        self.elemental_comp = pd.DataFrame(columns=['element','ppm','molality'])
        self.basis_species_comp = pd.DataFrame(columns=['species','ppm','molality'])
        self.electrochemistry = pd.DataFrame(columns=['scale','pH','Eh','pe'])
        self.aqueous_species = pd.DataFrame(columns=['species','molality','log_g','activity'])
        self.solid_solutions = dict()
        self.electrical_balance = dict()
        self.redox = pd.DataFrame(columns=['couple','Eh','pe','log_fO2','ah'])
        self.mineral_saturation = pd.DataFrame(columns=['mineral','log_q_k','aff','state'])
        self.gases = pd.DataFrame(columns=['gas','fugacity'])

        found_ss = False
        first_ss = True

        # List of variables to extract from input printout
        calc_props_flags = ['tempc','rho','fep','uebal','uacion']

        # Variable to track position in the file
        # 0 - preamble
        # 1 - input printout
        # 2 - calculation printout
        # 3 - strict basis species
        # 4 - Elemental composition of the aqueous phase
        # 5 - Elemental composition as strict basis species
        # 6 - Equivalent composition of the aqueous phase (cte balances)
        # 7 - Electrical balance totals
        # 8 - activity ratios of ions
        # 9 - distribution of aqueous species
        # 10 - major aqueous species contribution to mass balances
        # 11 - summary of aqueous redox reactions
        # 12 - summary of aqueous non-equilibrium non-redox reactions
        # 13 - summary of stoichiometric mineral saturation states
        # 14 - summary of gases
        # 15 - end of output
        # 16 - solid solution information in the input file printout (out of sequence)
        # 17 - summary of input solid solutions
        # 18 - summary of hypothetical solid solutions
        p = 0

        for l in f:
            s = l.split()
            if len(s)>0:

                ### CHECK FOR SECTION CHANGE ###########################################
                if p == 0 and s[0] == 'endit':
                    p = 1
                    continue
                if p > 0: # This should mean keywords can appear in the preamble.
                    if s == ' solid solutions'.split():
                        p = 16
                        continue
                    if s == ' --- the input file has been successfuly read ---'.split():
                        p = 2
                        continue
                    if s == '--- strict basis species ---'.split():
                        p = 3
                        continue
                    if s == ['-----','Elemental','composition','of','the','aqueous','phase','-----']:
                        p = 4
                        continue
                    elif s == ['-----','elemental','composition','as','strict','basis','species','-----']:
                        p = 5
                        continue
                    elif s == ['---','equivalent','composition','of','the','aqueous','phase','(cte','balances)','---']:
                        p = 6
                        continue
                    elif s == ['-----','electrical','balance','totals','-----']:
                        p = 7
                        continue
                    elif s == ['-----','activity','ratios','of','ions','-----']:
                        p = 8
                        continue
                    elif s == ['-----','distribution','of','aqueous','species','-----']:
                        p = 9
                        continue
                    elif s == ['-----','major','aqueous','species','contributing','to','mass','balances','-----']:
                        p = 10
                        continue
                    elif s == ['-----','summary','of','aqueous','redox','reactions','-----']:
                        p = 11
                        continue
                    elif s == '----- summary of aqueous non-equilibrium non-redox reactions -----'.split():
                        p = 12
                        continue
                    elif s == '----- summary of stoichiometric mineral saturation states -----'.split():
                        p = 13
                        continue
                    elif s == '----- summary of input solid solutions -----'.split():
                        p = 17
                        continue
                    elif s == '----- summary of hypothetical solid solutions -----'.split():
                        p = 18
                        continue
                    elif s == '----- summary of gases -----'.split():
                        p = 14
                        continue
                    elif s == '----- end of output -----'.split():
                        p = 15
                        continue

                ### PREAMBLE ###########################################################
                if p == 0:
                    if s == ['endit.']:
                        p += 1
                        continue
                    continue

                ### INPUT FILE PRINTOUT ################################################
                if p == 1:

                    for flag in calc_props_flags:
                        if flag+'=' in s:
                            flag_pos = s.index(flag+'=')
                            if len(s) > flag_pos+1 and flag in ['uebal','uacion']:
                                self.calc_props[flag] = s[flag_pos+1]
                            elif len(s) > flag_pos+1:
                                self.calc_props[flag] = convert_float(s[flag_pos+1])

                    # Check for a jflag block:
                    if s[0] == 'data':
                        jblock = [s[-1]]
                    if s[0] == 'jflag=':
                        jblock += [s[1],convert_float(s[-1])]
                        self.jflags.append(jblock)
                    if s[0] == 'uphas1=':
                        self.jflags[-1].append(s[1])
                        if len(s) > 3 and '\x00' not in s[3]:
                            self.jflags[-1].append(s[3])

                    # Check whether nxmod is set and warn that the script won't read this
                    if s[0] == 'nxmod=' and s[1] == '1' and suppress_warnings == False:
                        print('WARNING: DATA0 modified with nxmod. This will not be read by the script.')
                    continue

                ### READ SOLID SOLUTION COMPOSITION ############################
                if p == 16:
                    if s[0] != 'endit.' and len(s) == 1:
                        ss_name = s[0]
                        ss_info = pd.Series()
                        stored = False
                    elif s[0] != 'component' and len(s) > 1:
                        ss_info[s[0]]=convert_float(s[1])
                    if s[0] == 'endit.' and stored == False:
                        self.solid_solution_input.update({ss_name:ss_info})
                        stored = True


                ### STRICT BASIS SPECIES ###########################################
                if p == 3:
                    if '---' in l:
                        p = 2
                    else:
                        self.basis_species.append(s[0])


                ### ELEMENTAL COMPOSITION ##############################################
                if p == 4:
                    if s[0] != 'element':
                        row = {'element':s[0],
                               'ppm':s[2],
                               'molality':s[3]}
                        self.elemental_comp = self.elemental_comp.append(row,ignore_index=True)

                ### BASIS SPECIES ##################################################
                if p == 5:
                    if s[0] != 'species':
                        for species in self.basis_species:
                            if s[0] in species:
                                row = {'species':species,
                                       'ppm':convert_float(s[2]),
                                       'molality':convert_float(s[3])}
                            else:
                                row = {'species':s[0],
                                       'ppm':convert_float(s[2]),
                                       'molality':convert_float(s[3])}
                        self.basis_species_comp = self.basis_species_comp.append(row,ignore_index=True)

                ### EQUIVALENT COMPOSITION #########################################
                if p == 6:
                    if s[:3] == 'internal ph scale'.split() or s[:3] == 'rational ph scale'.split():
                        row = {'scale':' '.join(s[:2]),
                               'pH':convert_float(s[3]),
                               'Eh':convert_float(s[4]),
                               'pe':convert_float(s[5])}
                        self.electrochemistry = self.electrochemistry.append(row,ignore_index=True)
                    elif s[:4] == 'modified nbs ph scale'.split():
                        row = {'scale': ' '.join(s[:3]),
                               'pH': convert_float(s[4]),
                               'Eh': convert_float(s[5]),
                               'pe': convert_float(s[6])}
                        self.electrochemistry = self.electrochemistry.append(row,ignore_index=True)

                ### ELECTRICAL BALANCE #############################################
                if p == 7:
                    if len(s)>2 and s[-2] == '=':
                        self.electrical_balance[' '.join(s[:-2])] = convert_float(s[-1])

                ### DISTRIBUTION OF AQUEOUS SPECIES ################################
                if p == 9:
                    if s[0] != 'species':
                        row = {'species': s[0],
                               'molality': convert_float(s[1]),
                               'log_g': convert_float(s[3]),
                               'activity': convert_float(s[4])}
                        self.aqueous_species = self.aqueous_species.append(row,ignore_index=True)

                ### SUMMARY OF AQUEOUS REDOX REACTIONS #############################
                if p == 11:
                    if s[0] != 'couple':
                        row = {'couple':' '.join(s[:-4]),
                               'Eh':convert_float(s[-4]),
                               'pe':convert_float(s[-3]),
                               'log_fO2':convert_float(s[-2]),
                               'ah':convert_float(s[-1])}
                        self.redox = self.redox.append(row,ignore_index=True)

                ### MINERAL SATURATION STATES ######################################
                if p == 13:
                    if 'mineral' not in s and 'approx.' not in s and 'saturated' not in s\
                    and 'supersaturated' not in s and 'supersatd.' not in s and len(s)>1:
                        row = {'mineral': s[0],
                               'log_q_k': convert_float(s[1]),
                               'aff': convert_float(s[2])}
                        if len(s) > 3 and (s[3] == 'satd' or s[3] == 'ssatd'):
                            row.update({'state': s[3]})
                        self.mineral_saturation = self.mineral_saturation.append(row,ignore_index=True)

                        if len(s) > 4:
                            if s[3] == 'satd' or s[3] == 'ssatd':
                                row = {'mineral': s[4],
                                       'log_q_k': convert_float(s[5]),
                                       'aff': convert_float(s[6])}
                                if len(s) > 7:
                                       row.update({'state':s[7]})
                            else:
                                row = {'mineral': s[3],
                                       'log_q_k': convert_float(s[4]),
                                       'aff': convert_float(s[5])}
                                if len(s) > 6:
                                       row.update({'state':s[6]})
                            self.mineral_saturation = self.mineral_saturation.append(row,ignore_index=True)

                ### SUMMARY OF GASES ###############################################
                if p == 14:
                    if s[0] != 'gas':
                        row = {'gas':s[0],
                               'fugacity':convert_float(s[1])}
                        self.gases = self.gases.append(row,ignore_index=True)

                ### SOLID SOLUTIONS ############################################
                if p == 18:
                    if ((len(s)> 1 and (s[1] == 'saturated' or s[1] == 'supersatd.')) == False):
                        if s[0] != 'mineral' and s[0] != 'ideal' and s[0] != 'xbar':
                            if l[0] == '_' and first_ss == False:
                                self.solid_solutions.update({ss_mineral : [ss_info,ss_endmembers]})
                                found_ss = False
                            elif l[0] != '_' and found_ss == False:
                                first_ss = False
                                ss_mineral = s[0]
                                ss_info = {'log_q_k':convert_float(s[1]),
                                           'aff':convert_float(s[2]),
                                           'state':' '.join(s[3:])}
                                found_ss = True
                                ss_endmembers = pd.DataFrame(columns=['endmember','xbar','lamda','activity'])
                            elif len(s) == 7:
                                row = {'endmember': s[0],
                                       'xbar': convert_float(s[1]),
                                       'lamda': convert_float(s[2]),
                                       'activity': convert_float(s[3])}
                                ss_endmembers = ss_endmembers.append(row,ignore_index=True)




def convert_float(string):
    if len(string[1:].split('-')) > 1:
        if string[1:].split('-')[0][-1] != 'E':
            return float(string[0] + string[1:].split('-')[0] + 'E' + ''.join(string[1:].split('-')[1:]))
    if string[0] == '.':
        return float('0'+string)
    elif string[0] == '-':
        return float('-0'+string[1:])
    else:
        return string

def run_eqpt():
    cmnds = b'n\n n\n n\n'

    proc = subprocess.Popen("./EQPT",shell=True,
                        stdin=subprocess.PIPE,
                        stdout=subprocess.PIPE)
    proc.communicate(cmnds)
    proc.terminate()


def run_eq3():
    proc = subprocess.Popen("./EQ3",shell=True,
                        stdin=subprocess.PIPE,
                        stdout=subprocess.PIPE)
    proc.communicate(b'\n')
    proc.terminate()


class system:
    """
    Parameters
    ----------
    basis_species:   list
        List of basis_species objects. Must start with H2O,
        and include H+ and O2,g. There must be a basis species
        for each element, plus O2,g, giving elements+1 basis
        species.
    other_species:   list
        List of species objects that are included in the
        system, but are not part of the basis set. Must
        include OH-.
    elements:    list
        List of element name strings. Must include O and H.
    minerals:    list
        List of mineral objects. If running with the equilibrate
        module, this should not be used.
    """

    def __init__(self,basis_species,other_species,elements,minerals=[],hydrated_species={},solid_solutions={}):
        self.basis_species = basis_species
        self.other_species = other_species
        self.elements = elements
        self.minerals = minerals
        self.hydrated_species = hydrated_species
        self.solid_solutions = solid_solutions

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

        self.other_species_names = []
        for species in self.other_species:
            self.other_species_names.append(species.abbrev)
            self.species[species.abbrev] = species

        self.n_elements = len(self.elements)
        self.n_basis_species = len(self.basis_species)

        self.valid = True
        self.error = ''
        self.validate()
        if self.valid == False:
            print(self.error)

        # Set up basis species matrices. The OH matrix is created for using
        # in calculations where H+ molalities are negative.
        self.basis_species_matrix = self.make_basis_species_matrix()
        self.basis_species_matrix_OH = self.make_basis_species_matrix(swap_H_OH=True,exclude_gas=True)
        self.basis_species_matrix_soln = self.make_basis_species_matrix(exclude_gas=True)

        self.stoichiometry = dict()
        for species in self.other_species + self.minerals:
            self.find_reaction(species)

    def validate(self):
        if self.basis_species_names[0] != 'H2O':
            self.valid = False
            self.error += 'H2O must be first basis species. '
        if self.basis_species_names[1] != 'H+':
            self.valid = False
            self.error += 'H+ must be second basis species. '
        if 'OH-' in self.basis_species_names:
            self.valid = False
            self.error += 'OH- cannot be a basis species. '
        if 'O2' not in self.basis_species_names:
            self.valid = False
            self.error += 'O2 must be a basis species. '
        if self.n_basis_species -1 != self.n_elements:
            self.valid = False
            self.error += 'There must be a basis species for each element, plus O2,g. '
        if 'H' not in self.elements:
            self.valid = False
            self.error += 'H must be an element. '
        if 'O' not in self.elements:
            self.valid = False
            self.error += 'O must be an element. '
        print('Validation routine should check the basis species are compatible with the elements.')


    def d0_preamble(self,s=''):
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


    def d0_t_p_block(self,T,P,s=''):
        """
        Construct the Temperature and Pressure grid. Puts the same T and P value at all positions.

        parameters
        ----------
        s : str
            The T P block will be added on to the end of the string passed.
        T : float
            Temperature in degC
        P : float
            Pressure in bar
        """

        T = T-273.15

        # Characters to first period
        indent = 10
        # Characters between periods
        spacing = 9

        temps = np.linspace(T,T+350,8)

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



    def d0_h2o_props_block(self,T,P,s=''):
        dha = obj.AgammaFromT_andP_(T,P)
        dhb = obj.BgammaFromT_andP_(T,P)

        s_dha = '{0:0.4f}'.format(dha)
        s_dhb = '{0:0.4f}'.format(dhb/1e8)

        s += 'debye huckel a (adh)\n'
        s += (' '*(10-len(s_dha.split('.')[0])) + (s_dha + ' '*(10-len(s_dha)))*4 + '\n')*2

        s += 'debye huckel b (bdh)\n'
        s += (' '*(10-len(s_dhb.split('.')[0])) + (s_dhb + ' '*(10-len(s_dhb)))*4 + '\n')*2

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

    def d0_init_aq_species(self,s=''):
        s += 'aqueous species\n'
        return s

    def d0_basis_set(self,species,s='',ion_size_dict=ion_size):
        # Spaces between = and .
        spacing = 4

        # characters until first, second, third . in elements
        el_1 = 8
        el_2 = 30
        el_3 = 52

        # characters between . and element name
        el_name = 4

        charge = get_charge(species)
        sCharge = '{0:.1f}'.format(charge)

        ion = '3.7'

        if species.abbrev in ion_size_dict.keys():
            ion = '{0:.1f}'.format(ion_size_dict[species.abbrev])

        formula = chem.get_Berman_formula(species.props['element_comp'][0])
        if species.abbrev in self.hydrated_species:
            formula = formula_to_dict(formula,add_H2O=self.hydrated_species[species.abbrev])
        else:
            formula = formula_to_dict(formula)

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

    def d0_aqueous_species(self,species,t,p,s='',ion_size_dict=ion_size):
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

        charge = get_charge(species)
        s_charge = '{0:.1f}'.format(charge)

        formula = chem.get_Berman_formula(species.props['element_comp'][0])
        if species.abbrev in self.hydrated_species:
            formula = formula_to_dict(formula,add_H2O=self.hydrated_species[species.abbrev])
        else:
            formula = formula_to_dict(formula)

        ion = '3.7'
        if species.abbrev in ion_size_dict.keys():
            ion = '{0:.1f}'.format(ion_size_dict[species.abbrev])

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

        stoichiometry = self.stoichiometry[species.abbrev].copy()
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

        logKr = self.logK(species,t,p)

        slogK = '{0:.4f}'.format(logKr)

        s += (' '*(margin_lk - len(slogK.split('.')[0])) + slogK + (' '*(spacing_lk-len(slogK)+1) + slogK)*3 + '\n')*2

        s += '         0.0000    0.0000    0.0000    0.0000   \n'*2
        s += '+----------------------------------------------------------------------------\n'

        return(s)

    def d0_dummy_species(self,abbrev,charge,formula,s=''):
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
        matrix = np.zeros([np.shape(self.basis_species_matrix)[0]+1,np.shape(self.basis_species_matrix)[1]+1])
        matrix[:-1,:-1] = self.basis_species_matrix
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

    def d0_minerals(self,species,t,p,s='',ion_size_dict=ion_size):
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
            formula = formula_to_dict(formula)


            s += species.abbrev + '\n'
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

            stoichiometry = self.stoichiometry[species.abbrev].copy()
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

            logKr = self.logK(species,t,p,mineral=True)

            slogK = '{0:.4f}'.format(logKr)

            s += (' '*(margin_lk - len(slogK.split('.')[0])) + slogK + (' '*(spacing_lk-len(slogK)+1) + slogK)*3 + '\n')*2

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

                    stoichiometry = self.stoichiometry[species.endmember_names[ei]].copy()
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

                    logKr = self.logK(species,t,p,mineral=True,endi=ei)

                    slogK = '{0:.4f}'.format(logKr)

                    s += (' '*(margin_lk - len(slogK.split('.')[0])) + slogK + (' '*(spacing_lk-len(slogK)+1) + slogK)*3 + '\n')*2

                    s += '         0.0000    0.0000    0.0000    0.0000   \n'*2
                    s += '+----------------------------------------------------------------------------\n'

        return(s)


    def d0_end_species(self,s=''):
        s += 'endit.\n'
        s += 'minerals \n'
        return s

    def d0_end_minerals(self,s=''):
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

    def d0_end_gases(self,s=''):
        s += 'endit.\n'
        s += 'solid solutions \n'
        return s

    def d0_solid_solution(self,ss,s=''):
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

    def d0_end_solid_solutions(self,s=''):
        s += 'endit.\n'
        s += 'stop.'
        return s

    # def d0_final_components(self,s=''):
    #     s += 'endit.\n'
    #     s += 'gases \n'
    #     s += 'endit.\n'
    #     s += 'solid solutions \n'
    #     s += 'endit.\n'
    #     s += 'stop.'
    #     return s

    def find_reaction(self,species):
        if species.endmember_num == 1:
            formula = formula_to_dict(chem.get_Berman_formula(species.props['element_comp'][0]))
            matrix = np.zeros([np.shape(self.basis_species_matrix)[0]+1,np.shape(self.basis_species_matrix)[1]+1])
            matrix[:-1,:-1] = self.basis_species_matrix
            for i in range(len(self.elements)):
                if self.elements[i] in list(formula.keys()):
                    matrix[-1,i] = formula[self.elements[i]]
            matrix[-1,-2] = get_charge(species)
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

            self.stoichiometry[species.abbrev] = stoich
        else:
            for i in range(species.endmember_num):
                endm = np.zeros(species.endmember_num)
                endm[i] = 1
                formula = formula_from_ss(species,i)

                matrix = np.zeros([np.shape(self.basis_species_matrix)[0]+1,np.shape(self.basis_species_matrix)[1]+1])
                matrix[:-1,:-1] = self.basis_species_matrix
                for j in range(len(self.elements)):
                    if self.elements[j] in list(formula.keys()):
                        matrix[-1,j] = formula[self.elements[j]]
                matrix[-1,-2] = get_charge(species)
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

                self.stoichiometry[species.endmember_names[i]] = stoich



    def make_basis_species_matrix(self,swap_H_OH = False, exclude_gas = False):
        formulae = list()

        if exclude_gas == True:
            basis_species_use = self.basis_species_soln
        else:
            basis_species_use = self.basis_species

        if swap_H_OH == True:
            basis_species_use = copy(basis_species_use)
            basis_species_use[1] = self.other_species[self.other_species_names.index('OH-')]

        for s in basis_species_use:
            formula = formula_to_dict(chem.get_Berman_formula(s.props['element_comp'][0]))
            formulae += [formula]

        matrix = np.zeros([len(basis_species_use),self.n_elements+1])
        for i in range(len(basis_species_use)):
            for j in range(self.n_elements):
                if self.elements[j] in list(formulae[i].keys()):
                    matrix[i,j] = formulae[i][self.elements[j]]
            matrix[i,-1] = get_charge(basis_species_use[i])

        return matrix


    def make_data0(self,t,p,dummy_species=[]):
        s = self.d0_preamble()
        s = self.d0_t_p_block(t,p,s)
        s = self.d0_h2o_props_block(t,p,s)
        s = self.d0_init_aq_species(s)
        for spec in self.basis_species:
            s = self.d0_basis_set(spec,s=s)
        for spec in self.other_species:
            s = self.d0_aqueous_species(spec,t,p,s=s)
        for dummy in dummy_species:
            s = self.d0_dummy_species(dummy['abbrev'],dummy['charge'],
                                      dummy['formula'],s)
        s = self.d0_end_species(s=s)
        for miner in self.minerals:
            s = self.d0_minerals(miner,t,p,s=s)
        s = self.d0_end_minerals(s=s)
        s = self.d0_end_gases(s=s)
        for ss in self.solid_solutions.items():
            s = self.d0_solid_solution(ss,s=s)
        s = self.d0_end_solid_solutions(s=s)

        file = open('DATA0','w')
        file.write(s)
        file.close()

    def logK(self,species,t,p,mineral=False,endi=0):
        DG = 0.0
        if species.abbrev == 'O2':
            DG += self.stoichiometry[species.abbrev][species.abbrev]*self.muO2(t,p)
        elif species.endmember_num == 1:
            DG += self.stoichiometry[species.abbrev][species.abbrev]*species.gibbs_energy(t,p)
        else:
            endm = np.zeros(species.endmember_num)
            endm[endi] = 1
            DG += self.stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]*species.gibbs_energy(t,p,mol=endm)

        if mineral == True:
            if species.endmember_num == 1:
                formula = formula_to_dict(chem.get_Berman_formula(species.props['element_comp'][0]))
                if 'Na' in formula:
                    DG += -1626*4.184*formula['Na']*self.stoichiometry[species.abbrev][species.abbrev]
                if 'K' in formula:
                    DG += -1600*4.184*formula['K']*self.stoichiometry[species.abbrev][species.abbrev]
            else:
                endm = np.zeros(species.endmember_num)
                endm[endi] = 1
                formula = formula_from_ss(species,endi)

                # Add reference state corrections
#                 for el in formula:
#                     DG += formula[el]*self.stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]*robieref[el]*298.15

                if 'Na' in formula:
                    DG += -1626*4.184*formula['Na']*self.stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]
                if 'K' in formula:
                    DG += -1600*4.184*formula['K']*self.stoichiometry[species.endmember_names[endi]][species.endmember_names[endi]]

        if species.endmember_num == 1:
            species_name = species.abbrev
        else:
            species_name = species.endmember_names[endi]

        for s in self.basis_species:
            if s.abbrev in list(self.stoichiometry[species_name].keys()) and s.abbrev != 'H+':
                if s.abbrev == 'O2':
                    DG += self.stoichiometry[species_name][s.abbrev]*self.muO2(t,p)
                else:
                    DG += self.stoichiometry[species_name][s.abbrev]*s.gibbs_energy(t,p)
        return -DG/(8.3145*t)/2.303

    def muO2(self,t, p):
        tr = 298.15
        hs = 23.10248*(t-tr) + 2.0*804.8876*(np.sqrt(t)-np.sqrt(tr)) - 1762835.0*(1.0/t-1.0/tr) \
           - 18172.91960*np.log(t/tr) + 0.5*0.002676*(t*t-tr*tr)
        ss = 205.15 + 23.10248*np.log(t/tr)  - 2.0*804.8876*(1.0/np.sqrt(t)-1.0/np.sqrt(tr)) \
           - 0.5*1762835.0*(1.0/(t*t)-1.0/(tr*tr)) + 18172.91960*(1.0/t-1.0/tr) + 0.002676*(t-tr)
        return hs - t*ss + 205.15*298.15


class fluid:
    """
    parameters
    ----------
    system:   DEW_tools.system object
        The system object for the system the fluid belongs to.
    mols:   numpy.ndarray
        Array of mol fractions of elements in the fluid (including
        water molecules)
    """
    def __init__(self,system,mols,t,p):
        self.system = system
        self.mols = mols
        self.t = t
        self.p = p
        self.k = None
        self.calc_basis_species_molalities()
        self.eq3output = None
        self.gibbs_energy = None

    def calc_basis_species_molalities(self):
        n = np.zeros(self.system.n_elements+1)
        n[:-1] = self.mols
        x = np.linalg.solve(self.system.basis_species_matrix.T,n)
        k = 55.5/x[0]
        x = x*k
        self.basis_species_molalities = x
        self.k = k

    def input_preamble(self,s='',using_solid_solutions=False,uebal='H+',uacion='',fep=-12.6):
        T_s = '{0:.2f}'.format(self.t-273.15)

        s += '\n \nendit. \n'
        s += '     tempc=' + ' '*(13-len(T_s)) + T_s +'\n'
        s += '       rho=      1.02336    tdspkg=           0.     tdspl=           0.\n'
        s += '       fep=        ' + '{:.1f}'.format(fep)+ '    uredox=\n'
        # s += '       fep=        -12.6    uredox=\n'
        s += '     tolbt=        .1E-7     toldl=        .1E-7    tolsat=           0.\n'
        s += '    itermx=  0\n'
        s += '*               1    2    3    4    5    6    7    8    9  10\n'
        if using_solid_solutions == False:
            s += '  iopt1-10=     0    0    0    0    0    0    0    0    0   0\n'
        else:
            s += '  iopt1-10=     0    0    0    2    0    0    0    0    0   0\n'
        s += '  iopg1-10=     0   -1    0    0    1    0    0    0    0   0\n'
        s += '  iopr1-10=     0    2    0    0    0    0    1         0   \n'
        s += ' iopr11-20=     0    0    0    0    0    0    0  \n'
        s += '  iodb1-10=     0    0    0    0    0    0    0  \n'
        s += '     uebal= '+uebal+'\n'
        s += '    uacion= '+uacion+'\n'
        return s

    def input_nxmod(self,s,nxmods=[]):
        number = len(nxmods)
        s += '     nxmod=  {}\n'.format(number)
        for nxm in nxmods:
            s += '   SPECIES= ' + nxm[0] +'\n'
            s += '      TYPE=' + ' '*(3-len(str(nxm[1])))+'{}'.format(nxm[1])
            s += '              OPTION=' + ' '*(3-len(str(nxm[2])))+'{}'.format(nxm[2])
            xlkmod = '{0:.3f}'.format(nxm[3])
            s += '              XLKMOD=' + ' '*(4-len(xlkmod.split('.')[0]))+xlkmod+'\n'

        return s

    def input_basis_species_conc(self,species_name, molality,s=''):
        mol_s = '{0:.4E}'.format(molality)
        s += 'data file master species= ' + species_name + '\n'
        s += '   switch with species=  \n'
        s += '   jflag=  0   csp= ' + mol_s + '\n'
        return s

    def input_basis_species_logact(self,species_name, logact,s=''):
        act_s = '{0:.4E}'.format(logact)
        s += 'data file master species= ' + species_name + '\n'
        s += '   switch with species=  \n'
        s += '   jflag= 16   csp= ' + act_s + '\n'
        return s

    def input_basis_species_mineral(self,species_name,mineral,s=''):
        s += 'data file master species= ' + species_name + '\n'
        s += '   switch with species=  \n'
        if type(mineral) == str:
            s += '   jflag= 19   csp= ' + '\n'
            s += '   uphase= ' + mineral +'\n'
        elif type(mineral) == list and len(mineral) == 2:
            s += '   jflag= 20   csp= ' + '\n'
            s += '   uphase= ' + mineral[0] + ' '*(24-len(mineral[0]))  + 'uphase=    ' + mineral[1] + '\n'
        return s

    def input_end_file(self,s=''):
        s += 'endit.\n'
        return s

    def make_input_solid_solution(self,solid_solution,s=''):
        ss_name = solid_solution[0]
        ss_minerals = solid_solution[1]
        s += '   ' + ss_name + '\n'
        for mineral in ss_minerals:
            s += '      ' + mineral[0] + ' '*(31-len(mineral[0])) + '{:.4f}'.format(mineral[1]) + '\n'
        s += '      endit.\n'
        return s

    def make_input_molalities(self,nxmods=[],molalities=[],pH=5.0,mineral_eq=[],solid_solutions={},
                              uebal='H+',uacion='',fo2=-12.6):
        if len(solid_solutions) > 0:
            using_solid_solutions = True
        else:
            using_solid_solutions = False
        s = self.input_preamble(using_solid_solutions=using_solid_solutions,uebal=uebal,uacion=uacion,fep=fo2)
        s = self.input_nxmod(s,nxmods)
        for i in range(len(molalities)):
            s = self.input_basis_species_conc(molalities[i][0],
                                               molalities[i][1],s=s)
        if type(pH) != type(None):
            s = self.input_basis_species_logact('H+',-pH,s=s)
        for i in range(len(mineral_eq)):
            s = self.input_basis_species_mineral(mineral_eq[i][0],
                                            mineral_eq[i][1],s=s)
        s = self.input_end_file(s)

        if len(solid_solutions) > 0:
            for ss in solid_solutions.items():
                s = self.make_input_solid_solution(ss,s=s)
            s += '   endit.\n'

        file = open('input','w')
        file.write(s)
        file.close()



    def make_input(self,nxmods=[]):
        s = self.input_preamble()
        s = self.input_nxmod(s,nxmods)
        for i in range(self.system.n_basis_species):
            if self.system.basis_species_names_soln[i] not in ['H2O','H+']:
                s = self.input_basis_species_conc(self.system.basis_species_names[i],self.basis_species_molalities[i],s)
            elif self.system.basis_species_names_soln[i] == 'H+':
                s = self.input_basis_species_logact('H+',-4.0,s)
        s = self.input_end_file(s)

        file = open('input','w')
        file.write(s)
        file.close()

    def read_eq3(self):
        self.eq3output = eq3output()

        g = 0
        g+= 55.5*self.system.species['H2O'].gibbs_energy(self.t,self.p)/self.k
        for i,row in self.eq3output.aqueous_species.iterrows():
            if row.species != 'H+':
                g += (self.system.species[row.species].gibbs_energy(self.t,self.p) +\
                      8.314*self.t*np.log(row.activity))*row.molality/self.k
            else:
                g += (8.314*self.t*np.log(row.activity))*row.molality/self.k
        self.gibbs_energy = g
