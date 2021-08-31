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

model = coder.StdStateModel()

T = model.get_symbol_for_t()
P = model.get_symbol_for_p()
Tr = model.get_symbol_for_tr()
Pr = model.get_symbol_for_pr()

k0,k1,k2,k3,k5 = sym.symbols('k0 k1 k2 k3 k5')
CpPr = k0+k1/sym.sqrt(T)+k2/T**2+k3/T**3+k5*T
STrPr,HTrPr = sym.symbols('S_TrPr H_TrPr')

params = [('H_TrPr','J',HTrPr), ('S_TrPr','J/K',STrPr), ('k0','J/K-m',k0), ('k1','J-K^(1/2)-m',k1),
          ('k2','J-K/m',k2),  ('k3','J-K^2',k3), ('k5','J-K^2',k5)]

GPr = HTrPr + sym.integrate(CpPr,(T,Tr,T)) - T*(STrPr + sym.integrate(CpPr/T,(T,Tr,T)))

model.add_expression_to_model(GPr, params)

VTrPr,v1,v2,v3,v4 = sym.symbols('V_TrPr v1 v2 v3 v4')
params = [('V_TrPr', 'J/bar-m', VTrPr), ('v1','1/bar',v1), ('v2','1/bar^2',v2), ('v3','1/K',v3),  ('v4','1/K^2',v4)]

GPrToP = sym.integrate(VTrPr*(1+v1*(P-Pr)+v2*(P-Pr)**2+v3*(T-Tr)+v4*(T-Tr)**2),(P,Pr,P))
model.add_expression_to_model(GPrToP, params)

l1,l2 = sym.symbols('l1 l2')
kl = sym.symbols('k_lambda')
TlPr, Tlref = sym.symbols('T_lambda_Pr T_lambda_ref')
params = [('l1','(J/m)^(1/2)-K', l1), ('l2', '(J/m)^(1/2)/K^2', l2), ('k_lambda', 'K/bar', kl),
          ('T_lambda_Pr', 'K', TlPr), ('T_lambda_ref', 'K', Tlref)]


Tl = TlPr + kl*(P-Pr)

td = TlPr - Tl

tr = Tlref - td

Cpl = (T+td)*(l1+l2*(T+td))**2

Gl = sym.integrate(Cpl,(T,tr,T)) - T*sym.integrate(Cpl/T,(T,tr,T))

model.add_expression_to_model(Gl, params, exp_type='restricted', lower_limits=(tr,Pr), upper_limits=(Tl,None))

deltaHt = sym.symbols('H_t')
params = [('H_t','J/m', deltaHt)]

GaboveTl = -(T-Tl)*deltaHt/Tl

model.add_expression_to_model(GaboveTl , params, exp_type='restricted', lower_limits=(Tl,None), upper_limits=(Tl,None))

d0,d1,d2,d3,d4,d5 = sym.symbols('d0 d1 d2 d3 d4 d5')
TD,TDref = sym.symbols('T_D T_D_ref')
params = [('d0','J/K-m', d0), ('d1','J/K^(1/2)-m',d1), ('d2','J-K/m',d2), ('d3','J/K^2-m',d3),
          ('d4','J/K^3-m',d4), ('d5','bar',d5), ('T_D','K',TD), ('T_D_ref','K',TDref)]


CpDs = d0 + d1/sym.sqrt(T) + d2/T**2 + d3*T + d4*T**2
HDs = sym.integrate(CpDs,(T,TDref,T))
SDs = sym.integrate(CpDs/T,(T,TDref,T))
VDs = HDs/d5
GDs = HDs - T*SDs + VDs*(P-Pr)

model.add_expression_to_model(GDs , params, exp_type='restricted', lower_limits=(TDref,None), upper_limits=(TD,None))

d = pd.read_csv('dew_berman.csv')

params = {}
for i, row in d.iterrows():
    params[row['name']] = {  'Phase': row['name'],
                          'Formula': row.formula,
                          'H_TrPr':row.H_ref + row.ref_state*298.15,
                          'S_TrPr': row.S_ref,
                          'k0': row.k0,
                          'k1': row.k1,
                          'k2': row.k2,
                          'k3': row.k3,
                          'k5': row.k5,
                          'V_TrPr': row.v0,
                          'v1': row.v3*1e-5,
                          'v2': row.v4*1e-8,
                          'v3': row.v1*1e-5,
                          'v4': row.v2*1e-5,
                          'l1': row.l1,
                          'l2': row.l2,
                          'k_lambda': row.kl,
                          'T_lambda_Pr': row.Tl,
                          'T_lambda_ref': row.Tlref,
                          'H_t': row.dHt,
                          'd0': row.d0,
                          'd1': row.d1,
                          'd2': row.d2,
                          'd3': row.d3,
                          'd4': row.d4,
                          'd5': row.d5,
                          'T_D': row.Td,
                          'T_D_ref': row.Tdref,
                          'T_r': 298.15,
                          'P_r': 1.0}

mod_name = 'dewminerals'
modelDB, codermod = make_custom_database(mod_name, params, working_dir='dew_minerals_coderfiles')

modelDB.phase_info

output = {}
for phsnm in params:
    iphs = modelDB.get_phase(phsnm)
    output[phsnm] = iphs
with open('dewminerals.pkl','wb') as file:
    dill.dump(output, file)
    file.close()
