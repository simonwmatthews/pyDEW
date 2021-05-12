# From the Import DEW Jupyter notebook
import pandas as pd
import dill
import numpy as np
import sympy as sym
import os
import thermoengine
import pyximport
import importlib


# CORE.IPYNB -----------------------------------------

def load_coder_modules(working_dir='working'):
    pyximport.install(language_level=3)
    
    working_dir_code = np.array(os.listdir(working_dir))
    mask = np.array([file.endswith('.pyx') for file in working_dir_code ])
    mod_names = [os.path.splitext(file)[0] for file in working_dir_code[mask]]
        
    os.chdir(working_dir)
    [importlib.import_module(mod_name) for mod_name in mod_names]
    os.chdir('..')

def make_custom_database(mod_name, phase_params, 
                         working_dir='working',calib=False):
    
    modelDB = None
    coder_mod = None
    
    model.set_module_name(mod_name)
    os.mkdir(working_dir)
    os.chdir(working_dir)
    
    try:
        phase_info = {}
        
        sources_list = ''
        os.system('rm '+mod_name+'.pyx')
        
        for phs in phase_params:
            param_dict = phase_params[phs]
            phs_nm = param_dict['Phase']
            phase_info[phs] = [phs_nm, 'pure']
            
            sources_list = _add_model_phase(
                param_dict, mod_name, sources_list=sources_list,calib=calib)
            
        pyxbld_filenm = mod_name+'.pyxbld'
        _rewrite_pyxbld_sources(pyxbld_filenm, sources_list)
        
        
        phase_tuple =  (mod_name, phase_info)
        
        coder_mod = importlib.import_module(mod_name)
        
        
        modelDB = thermoengine.model.Database(
            database='CoderModule', phase_tuple=phase_tuple,calib=calib)
    except:
        print('There is something wrong with this custom database attempt')
        raise
    
    os.chdir('..')
    return modelDB, coder_mod


def _add_model_phase(param_dict, mod_name, sources_list=None, 
                    calib=False):
    filenm = mod_name+'.pyx'
    tmpnm = 'tmpfile.pyx'
    tmpnm2 = 'tmpfile2.pyx'
    
    os.system('touch '+ filenm)
    os.system('mv '+filenm+' '+tmpnm)
    
    
    phase_name = param_dict.pop('Phase', None)
    formula = param_dict.pop('Formula', None)
    if calib == True:
        module_type = 'calib'
    else:
        module_type = 'fast'
    result = model.create_code_module(phase=phase_name, formula=formula, 
                                      params=param_dict, module_type=module_type)
    
    os.system('cat '+filenm+' '+tmpnm+' > '+tmpnm2)
    os.system('mv '+tmpnm2 + ' ' + filenm)
    os.system('rm '+tmpnm)
    os.system('rm '+tmpnm2)
    
    
    if sources_list is None:
        sources_list = ''
        
    if calib == True:
        source_file = phase_name+'_'+mod_name+'_calib.c'
    else:
        source_file = phase_name+'_'+mod_name+'_calc.c'
    sources_list += "'"+source_file + "', "
    
    return sources_list


def _rewrite_pyxbld_sources(filename, sources_list):
    with open(filename,'r') as file:
        lines = file.readlines()
        for ind, line in enumerate(lines):
            is_source_line = line.strip().startswith('sources')
            if is_source_line:
                ind_source = ind
            
        file.close()
        
        
    sources_update = ('                     sources=[pyxfilename, '+
                      sources_list[:-2] + '],\r\n')
    
    lines[ind_source] = sources_update
    
    with open(filename,'w') as file:
        file.writelines( lines )

# ----------------------

from thermoengine import coder
from thermoengine.coder import B, Q, Y, U, N, X, dUdT, dUdP, dNdT, dNdP, dXdT, gSolvent

model = coder.StdStateModel()

T = model.get_symbol_for_t()
P = model.get_symbol_for_p()
Tr = model.get_symbol_for_tr()
Pr = model.get_symbol_for_pr()

eta, rH, omega0, z = sym.symbols('eta rH omega0 z', real=True)

omega_def = sym.Piecewise((omega0, sym.Eq(z,0)), \
            ((omega0 + z*eta/rH)/(1 + sym.Abs(z)*gSolvent(T,P)*(omega0/eta + z/rH)/z**2) - eta*z/(rH + gSolvent(T,P)), True))

a1,a2,a3,a4 = sym.symbols('a1 a2 a3 a4')
Psi,theta = sym.symbols('Psi theta')
omega = sym.Function('omega')(T,P)

vtp = a1 + a2/(Psi+P) + (a3 + a4/(Psi+P))/(T-theta) - omega*Q(T,P) - (B(T,P)+1)*omega.diff(P)

deltaG = sym.integrate(a1 + a2/(Psi+P) + (a3 + a4/(Psi+P))/(T-theta), (P,Pr,P)) - (1+B(T,P))*omega + (1+B(T,Pr))*omega.subs(P,Pr)

c1,c2 = sym.symbols('c1 c2')
ctpr = c1 + c2/(T-theta)**2 + (T*((B(T,P)+1)*omega).diff(T,2)).subs(P,Pr)

Gref,Sref = sym.symbols('G_ref S_ref')

gtp = Gref - Sref*(T-Tr) - sym.integrate(sym.integrate((c1 + c2/(T-theta)**2)/T, (T,Tr,T)), (T,Tr,T)) \
    - (B(T,Pr)+1)*omega.subs(P,Pr) + (B(Tr,Pr)+1)*omega.subs(P,Pr).subs(T,Tr) \
    + Y(Tr,Pr)*(T-Tr)*omega.subs(P,Pr).subs(T,Tr) + (B(Tr,Pr)+1)*(T-Tr)*omega.diff(T).subs(P,Pr) \
    + sym.integrate(a1 + a2/(Psi+P) + (a3 + a4/(Psi+P))/(T-theta), (P,Pr,P)) - (1+B(T,P))*omega + (1+B(T,Pr))*omega.subs(P,Pr)

gtp = gtp.subs(omega.subs(T,Tr).subs(P,Pr), omega0)
gtp = gtp.subs(omega.diff(T).subs(P,Pr),0)
gtp = gtp.subs(Y(Tr,Pr),-5.79865E-05)
gtp = gtp.subs(B(Tr,Pr),-1/78.47)

gtp = gtp.subs(omega,omega_def)

params = [('G_ref','J',Gref), ('S_ref','J/K',Sref), 
          ('a1','J/bar-m',a1), ('a2','J/bar^2-m',a2), ('a3','J/bar-m',a3),  ('a4','J/bar^2-m',a4), 
          ('c1','J/K-m',c1), ('c2','J-K/m',c2), 
          ('Psi', 'bar', Psi), ('eta', 'Å-J/mole', eta), ('rH', 'Å', rH), ('omega0','J',omega0), 
          ('theta','K',theta), ('z', '', z)]
model.add_expression_to_model(gtp, params)

model.set_module_name('dew2019')
model.set_include_born_code(True)

dew = pd.read_csv('dew2019_cleaned.csv')
dew = dew.fillna(0)

multipliers = {'a1': 4.184/10,
               'a2': 4.184*100,
               'a3': 4.184,
               'a4': 4.184*1e4,
               'c1': 4.184,
               'c2': 4.184*1e4,
               'G_ref': 4.184,
               'H_ref': 4.184,
               'S_ref': 4.184,
               'V_ref': 0.1,
               'Cp_ref': 4.184,
               'omega0': 4.184*1e5}

for col in list(multipliers.keys()):
    dew[col] = dew[col] * multipliers[col]

def HKF_params(species='H+',Formula='', z=0.0,
                   G_ref=0.0, S_ref=0.0, V_ref=0.0, Cp_ref = 0.0,
                   a1=0.0, a2=0.0, a3=0.0, a4=0.0,
                   c1=0.0, c2=0.0, omega0=0.0,
                   theta=228.0, Psi=2600.0, eta=694657.0, rH=3.082,
                   T_r=298.15, P_r=1.0):
    
    species_name = species
    
    if species_name[-1] == '-':
        species_name = species_name[:-1]+'_n'
    if species_name[-2] == '-':
        species_name = species_name[:-2]+'_n'+species_name[-1]
    species_name = species_name.replace('-','_')
    species_name = species_name.replace('+','_p')
    species_name = species_name.replace('(','_l_')
    species_name = species_name.replace(')','_r_')
        
    species_name = species_name.replace(',','_')
    
    param_dict = {'Phase': species_name,
                  'Formula': Formula,
                  'G_ref':G_ref,
                  'S_ref':S_ref,
                  'v_ref':V_ref,
                  'C_p_ref':Cp_ref,
                  'a1':a1,
                  'a2':a2,
                  'a3':a3,
                  'a4':a4,
                  'c1':c1,
                  'c2':c2,
                  'omega0':omega0,
                  'theta':theta,
                  'Psi':Psi,
                  'eta':eta,
                  'rH':rH,
                  'z':z,
                  'T_r':T_r,
                  'P_r':P_r}
    return param_dict

phase_params = {}
for i, row in dew.iterrows():
    phase_params[row['EQ_name']] = HKF_params(species=row['EQ_name'],Formula=row['formula'], z=row['z'],
                   G_ref=row['G_ref'], S_ref=row['S_ref'], V_ref=row['V_ref'], Cp_ref = row['Cp_ref'],
                   a1=row['a1'], a2=row['a2'], a3=row['a3'], a4=row['a4'],
                   c1=row['c1'], c2=row['c2'], omega0=row['omega0'])
    
mod_name = 'dew2019'
modelDB, codermod = make_custom_database(mod_name,phase_params,working_dir='dew2019_coderfiles',calib=False)

output = {}
for phsnm in phase_params:
    iphs = modelDB.get_phase(phsnm)
    output[phsnm] = iphs

with open('DEW2019.pkl','wb') as file:
    dill.dump(output, file)
    file.close()