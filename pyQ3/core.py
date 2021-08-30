import dill
import pyximport
import importlib
import numpy as np
import os
from thermoengine import model
import subprocess
import platform


class Error(Exception):
    pass


class InputError(Error):
    def __init__(self, message):
        self.message = message


class CompatibilityError(Error):
    def __init__(self, message):
        self.message = message


# Get the installation directory. This is necessary for importing files and finding the
# executables.
dir_path = os.path.dirname(os.path.realpath(__file__))
# Get the current working directory.
w_path = os.getcwd()
# Get the operating system, and check that it is one of Mac OSX or Linux
operatingsystem = platform.system()
if operatingsystem not in ['Linux', 'Darwin']:
    raise CompatibilityError(
        'The pyQ3 package is only compatible with Mac OSX and Linux.')


def load_coder_modules(working_dir=dir_path+'/dew2019_coderfiles'):
    """ Imports previously generated coder modules. This is required for loading
    the DEW2019 species, but might also be useful for loading mineral models, or
    other aqueous species.

    Parameters
    ----------
    working_dir     str
        The directory in which to look for the module files. Default is dew2019_coderfiles.
    """
    pyximport.install(language_level=3)

    working_dir_code = np.array(os.listdir(working_dir))
    mask = np.array([file.endswith('.pyx') for file in working_dir_code])
    mod_names = [os.path.splitext(file)[0] for file in working_dir_code[mask]]

    os.chdir(working_dir)
    [importlib.import_module(mod_name) for mod_name in mod_names]
    os.chdir(w_path)


def DEW_species(working_dir=dir_path+'/dew2019_coderfiles', pickle_file=dir_path+'/DEW2019.pkl'):
    """ Returns the DEW2019 database (or any other database if the working_dir is set).

    Parameters
    ----------
    working_dir : str
        The directory in which to look for the module files. Default is dew2019_coderfiles.
    pickle_file : str
        The filename for the pickle file containing the coder objects for the DEW2019
        aqueous species.

    Returns
    -------
    dict
        Keys are the aqueous species names, the values are the phase objects.
    """
    load_coder_modules(working_dir)
    with open(pickle_file, 'rb') as file:
        dew = dill.load(file)
        file.close()

    # Load the SWIM model and O2.
    _db = berman_database()
    dew['H2O'] = _db.get_phase('H2O')
    dew['O2(G)'] = _db.get_phase('O2')
    dew['O2(G)']._abbrev = 'O2(G)'
    dew['H2(G)'] = _db.get_phase('H2')
    dew['H2(G)']._abbrev = 'H2(G)'

    return dew


def DEW_minerals(working_dir=dir_path+'/dew_minerals_coderfiles', pickle_file=dir_path+'/dewminerals.pkl'):
    """ Returns the DEW Minerals database (or any other database if the working_dir is set).

    Parameters
    ----------
    working_dir : str
        The directory in which to look for the module files. Default is dew2019_coderfiles.
    pickle_file : str
        The filename for the pickle file containing the coder objects for the DEW2019
        aqueous species.

    Returns
    -------
    dict
        Keys are the mineral names, the values are the phase objects.
    """
    load_coder_modules(working_dir)
    with open(pickle_file, 'rb') as file:
        dew = dill.load(file)
        file.close()

    return dew


def berman_database():
    """ Returns the Berman database from thermoengine.

    Returns
    -------
    thermoengine database
        The Berman database.
    """
    db = model.Database()
    return db


def get_charge(species):
    """ Infers the charge of an aqueous species from its name.

    Parameters
    ----------
    species : species object
        The species for which to return the charge

    Returns
    -------
    float
        The charge of the species.
    """
    abbrev = species.abbrev
    charge = 0.0
    if abbrev[-3:] == '(AQ)' or abbrev[-3:] == ',aq':
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


def formula_to_dict(formula, add_H2O=0):
    """ Converts a Berman formula to a dictionary representation of the formula.

    Parameters
    ----------
    formula : str
        The Berman formula
    add_H2O : float
        The number of H2O molecules to add to the formula, defaults to zero.

    Returns
    -------
    dict
        The formula as a dictionary, with the element name as the key.
    """
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


def formula_from_ss(mineral, endi):
    endm = np.zeros(mineral.endmember_num)
    endm[endi] = 1.0
    fs = mineral.compute_formula(298.15, 1.0, endm)
    split = {}
    el = ''
    st = ''
    inbracket = False
    els_in_bracket = []
    look_for_bracket_multiplier = False
    for j in range(len(fs)):

        if fs[j] == '(':
            inbracket = True

        if fs[j] not in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.']:
            if look_for_bracket_multiplier == True:
                for el in els_in_bracket:
                    split[el] = split[el]*float(st)
                st = ''
                el = ''
                look_for_bracket_multiplier = False

            if len(st) > 0:  # and look_for_bracket_multiplier == False:
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


def run_eqpt(working_directory='', executable_name=None):
    # Keep track of whether to delete EQPT or not:
    tidyup = False
    # Copy the executable into the working folder
    if executable_name is None:
        tidyup = True
        if operatingsystem == 'Darwin':
            os.system("cp " + dir_path + '/executables/EQPT_mac '
                      + working_directory + '/EQPT')
        elif operatingsystem == 'Linux':
            os.system("cp " + dir_path + '/executables/EQPT_linux '
                      + working_directory + '/EQPT')
        executable_name = 'EQPT'

    cmnds = b'n\n n\n n\n'

    proc = subprocess.Popen(bytes("./" + executable_name, 'utf-8'), cwd=working_directory + '/',
                            shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE)

    proc.communicate(cmnds)
    proc.terminate()

    if tidyup:
        os.system('rm ' + working_directory + '/EQPT')


def run_eq3(working_directory='', executable_name=None):
    # Keep track of whether to delete EQPT or not:
    tidyup = False
    # Copy the executable into the working folder
    if executable_name is None:
        tidyup = True
        if operatingsystem == 'Darwin':
            os.system("cp " + dir_path + '/executables/EQ3_mac '
                      + working_directory + '/EQ3')
        elif operatingsystem == 'Linux':
            os.system("cp " + dir_path + '/executables/EQ3_linux '
                      + working_directory + '/EQ3')
        executable_name = 'EQ3'

    proc = subprocess.Popen(bytes("./" + executable_name, 'utf-8'), cwd=working_directory + '/',
                            shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    proc.communicate(b'\n')
    proc.terminate()

    if tidyup:
        os.system('rm ' + working_directory + '/EQ3')


def run_eq6(working_directory='', executable_name=None):
    # Keep track of whether to delete EQ6 or not:
    tidyup = False
    # Copy the executable into the working folder
    if executable_name is None:
        tidyup = True
        if operatingsystem == 'Darwin':
            os.system("cp " + dir_path + '/executables/EQ6_mac '
                      + working_directory + '/EQ6')
        elif operatingsystem == 'Linux':
            os.system("cp " + dir_path + '/executables/EQ6_linux '
                      + working_directory + '/EQ6')
        executable_name = 'EQ6'

    proc = subprocess.Popen(bytes("./" + executable_name, 'utf-8'), cwd=working_directory + '/',
                            shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    proc.communicate(b'\n')
    proc.terminate()

    if tidyup:
        os.system('rm ' + working_directory + '/EQ6')
