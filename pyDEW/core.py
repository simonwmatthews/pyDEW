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


# MAYBE MOVE ALL OF THIS INTO SYSTEM DEFINITION?
# IF DEFINING A SMALL SYSTEM COULD AUTOMATE EXTRACTING DATA
# AND PROMPT IF THERE IS AN ELEMENT MISSING

# For the purpose of 'oxides' negative ions will be hydrides
oxideMass = {'SiO2':  60.083,
             'MgO':   40.304,
             'FeO':   71.844,
             'CaO':   56.077,
             'Al2O3': 101.961,
             'Na2O':  61.979,
             'K2O':   94.195,
             'MnO':   70.937,
             'TiO2':  79.867,
             'P2O5':  141.943,
             'Cr2O3': 151.992,
             'NiO':   74.692,
             'CoO':   44.01,
             'Fe2O3': 159.687,
             'H2O':   18.02,
             'CO2':   44.01,
             'Ag2O': 231.735,
             'Au2O': 409.93,
             'BaO': 153.3394,
             'HCl': 36.461,
             'SO2': 64.065,
             'CdO': 128.41,
             'NO2': 46.006,
             'Cs2O': 281.81,
             'Cu2O': 143.09,
             'EuO': 167.96,
             'HF': 20.006,
             'HgO': 216.59,
             'PbO2': 239.1988,
             'SrO': 103.62,
             'UO4': 302.3,
             'ZnO': 81.379,
             }

# For Cl, F, they will be 'cations'
CationNum = {'SiO2': 1, 'MgO': 1, 'FeO': 1, 'CaO': 1, 'Al2O3': 2, 'Na2O': 2,
             'K2O': 2, 'MnO': 1, 'TiO2': 1, 'P2O5': 2, 'Cr2O3': 2,
             'NiO': 1, 'CoO': 1, 'Fe2O3': 2, 'H2O': 2, 'CO2': 1, 'HF': 2,
             'Ag2O': 2, 'Au2O': 2, 'BaO': 1, 'HCl': 1, 'SO2': 1, 'CdO': 1,
             'NO2': 1, 'Cs2O': 2, 'Cu2O': 2, 'EuO': 1, 'HgO': 1, 'PbO2': 1,
             'SrO': 1, 'UO4': 1, 'ZnO': 1}

# For Cl, F, H will be 'oxygen'
OxygenNum = {'SiO2': 2, 'MgO': 1, 'FeO': 1, 'CaO': 1, 'Al2O3': 3, 'Na2O': 1,
             'K2O': 1, 'MnO': 1, 'TiO2': 2, 'P2O5': 5, 'Cr2O3': 3,
             'NiO': 1, 'CoO': 1, 'Fe2O3': 3, 'H2O': 1, 'CO2': 2, 'HF': 1,
             'Ag2O': 1, 'Au2O': 1, 'BaO': 1, 'HCl': 1, 'SO2': 2, 'CdO': 1,
             'NO2': 2, 'Cs2O': 1, 'Cu2O': 1, 'EuO': 1, 'HgO': 1, 'PbO2': 2,
             'SrO': 1, 'UO4': 4, 'ZnO': 1}

CationCharge = {'SiO2': 4, 'MgO': 2, 'FeO': 2, 'CaO': 2, 'Al2O3': 3, 'Na2O': 1,
                'K2O': 1, 'MnO': 2, 'TiO2': 4, 'P2O5': 5, 'Cr2O3': 3,
                'NiO': 2, 'CoO': 2, 'Fe2O3': 3, 'H2O': 1, 'CO2': 4, 'HF': -1,
                'Ag2O': 1, 'Au2O': 1, 'BaO': 2, 'HCl': -1, 'SO2': 4, 'CdO': 2,
                'NO2': 4, 'Cs2O': 1, 'Cu2O': 1, 'EuO': 2, 'HgO': 2, 'PbO2': 4,
                'SrO': 2, 'UO4': 8, 'ZnO': 2}

CationMass = {'SiO2': 28.085, 'MgO': 24.305, 'FeO': 55.845, 'CaO': 40.078, 'Al2O3': 26.982,
              'Na2O': 22.990, 'K2O': 39.098, 'MnO': 54.938, 'TiO2': 47.867, 'P2O5': 30.974,
              'Cr2O3': 51.996, 'NiO': 58.693, 'CoO': 28.01, 'Fe2O3': 55.845, 'H2O': 1.01,
              'CO2': 12.011, 'F2O': 18.998}

oxides_to_cations = {'SiO2': 'Si', 'MgO': 'Mg', 'FeO': 'Fe', 'CaO': 'Ca', 'Al2O3': 'Al',
                     'Na2O': 'Na', 'K2O': 'K', 'MnO': 'Mn', 'TiO2': 'Ti', 'P2O5': 'P',
                     'Cr2O3': 'Cr', 'NiO': 'Ni', 'CoO': 'Co', 'Fe2O3': 'Fe3', 'H2O': 'H',
                     'CO2': 'C', 'F2O': 'F'}
cations_to_oxides = {'Si': 'SiO2', 'Mg': 'MgO', 'Fe': 'FeO', 'Ca': 'CaO', 'Al': 'Al2O3',
                     'Na': 'Na2O', 'K': 'K2O', 'Mn': 'MnO', 'Ti': 'TiO2', 'P': 'P2O5',
                     'Cr': 'Cr2O3', 'Ni': 'NiO', 'Co': 'CoO', 'Fe3': 'Fe2O3', 'H': 'H2O',
                     'C': 'CO2', 'F': 'F2O'}


# Get the installation directory. This is necessary for importing files and finding the
# executables.
dir_path = os.path.dirname(os.path.realpath(__file__))
# Get the current working directory.
w_path = os.getcwd()
# Get the operating system, and check that it is one of Mac OSX or Linux
operatingsystem = platform.system()
if operatingsystem not in ["Linux", "Darwin"]:
    raise CompatibilityError(
        "The pyDEW package is only compatible with Mac OSX and Linux."
    )


def convert_wtptoxides_to_mol_elements(oxides_wtpt, capitalise_elements=True):
    """
    Converts wtpt oxides to moles of elements, intended to be used with the reaction class
    for specifying bulk compositions more conveniently.

    Parameters
    ----------
    oxide_wtpt : dict
        The oxide wtpt values, keys are oxide names.
    capitalise_elements : bool, default: True
        Return capitalised element names in the dictionary.

    Returns
    -------
    dict
        Element moles formatted in capitals ('SI') or normal ('Si').
    """

    mol_elements = {'O' : 0.0}
    sum_mols = 0.0

    for ox in oxides_wtpt:
        if capitalise_elements:
            element_name = oxides_to_cations[ox].upper()
        else:
            element_name = oxides_to_cations[ox]

        mol_elements[element_name] = oxides_wtpt[ox] / oxideMass[ox] * CationNum[ox]
        mol_elements['O'] += oxides_wtpt[ox] / oxideMass[ox] * OxygenNum[ox]

        sum_mols += oxides_wtpt[ox] / oxideMass[ox] * (CationNum[ox] + OxygenNum[ox])

    for el in mol_elements:
        mol_elements[el] = mol_elements[el] / sum_mols

    return mol_elements


def load_coder_modules(working_dir=dir_path + "/dew2019_coderfiles"):
    """Imports previously generated coder modules. This is required for loading
    the DEW2019 species, but might also be useful for loading mineral models, or
    other aqueous species.

    Parameters
    ----------
    working_dir     str
        The directory in which to look for the module files. Default is dew2019_coderfiles.
    """
    pyximport.install(language_level=3)

    working_dir_code = np.array(os.listdir(working_dir))
    mask = np.array([file.endswith(".pyx") for file in working_dir_code])
    mod_names = [os.path.splitext(file)[0] for file in working_dir_code[mask]]

    os.chdir(working_dir)
    [importlib.import_module(mod_name) for mod_name in mod_names]
    os.chdir(w_path)


def DEW_species(
    working_dir=dir_path + "/dew2019_coderfiles", pickle_file=dir_path + "/DEW2019.pkl",
    alternative_pickle_file=dir_path + "/DEW2019_oldTE.pkl"
):
    """Returns the DEW2019 database (or any other database if the working_dir is set).

    Parameters
    ----------
    working_dir : str
        The directory in which to look for the module files. Default is dew2019_coderfiles.
    pickle_file : str
        The filename for the pickle file containing the coder objects for the DEW2019
        aqueous species.
    alternative_pickle_file : str
        Filename for an alternative pickle file if the first one fails. Added to get around
        cluster ThermoEngine being older than current.

    Returns
    -------
    dict
        Keys are the aqueous species names, the values are the phase objects.
    """
    load_coder_modules(working_dir)
    try:
        with open(pickle_file, "rb") as file:
            dew = dill.load(file)
            file.close()
    except:
        with open(alternative_pickle_file, "rb") as file:
            dew = dill.load(file)
            file.close()

    # Load the SWIM model and O2.
    _db = berman_database()
    dew["H2O"] = _db.get_phase("H2O")
    dew["O2(G)"] = _db.get_phase("O2")
    dew["O2(G)"]._abbrev = "O2(G)"
    dew["H2(G)"] = _db.get_phase("H2")
    dew["H2(G)"]._abbrev = "H2(G)"

    return dew


def DEW_minerals(
    working_dir=dir_path + "/dew_minerals_coderfiles",
    pickle_file=dir_path + "/dewminerals.pkl",
    alternative_pickle_file=dir_path + "/dewminerals_oldTE.pkl"
):
    """Returns the DEW Minerals database (or any other database if the working_dir is set).

    Parameters
    ----------
    working_dir : str
        The directory in which to look for the module files. Default is dew2019_coderfiles.
    pickle_file : str
        The filename for the pickle file containing the coder objects for the DEW2019
        aqueous species.
    alternative_pickle_file : str
        Filename for an alternative pickle file if the first one fails. Added to get around
        cluster ThermoEngine being older than current.

    Returns
    -------
    dict
        Keys are the mineral names, the values are the phase objects.
    """
    load_coder_modules(working_dir)
    try:
        with open(pickle_file, "rb") as file:
            dew = dill.load(file)
            file.close()
    except:
        with open(alternative_pickle_file, "rb") as file:
            dew = dill.load(file)
            file.close()

    return dew


def berman_database():
    """Returns the Berman database from thermoengine.

    Returns
    -------
    thermoengine database
        The Berman database.
    """
    db = model.Database()
    return db


def get_charge(species):
    """Infers the charge of an aqueous species from its name.

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
    if abbrev[-3:] == "(AQ)" or abbrev[-3:] == ",aq":
        charge = 0.0
    elif abbrev[-1] == "-":
        charge = -1.0
    elif abbrev[-1] == "+":
        charge = 1.0
    elif abbrev[-2] == "+":
        charge = float(abbrev[-1])
    elif abbrev[-2] == "-":
        charge = -float(abbrev[-1])
    return charge


def formula_to_dict(formula, add_H2O=0):
    """Converts a Berman formula to a dictionary representation of the formula.

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
    split1 = formula.split("(")
    split2 = list()
    for s in split1:
        split2 += s.split(")")
    split2 = split2[:-1]

    d = {}
    elements = int(len(split2) / 2)
    for i in range(elements):
        d[split2[i * 2]] = float(split2[i * 2 + 1])
    if add_H2O > 0:
        if "H" in d:
            d["H"] = d["H"] + 2 * add_H2O
        else:
            d["H"] = 2 * add_H2O
        if "O" in d:
            d["O"] = d["O"] + add_H2O
        else:
            d["O"] = add_H2O

    return d


def formula_from_ss(mineral, endi):
    endm = np.zeros(mineral.endmember_num)
    endm[endi] = 1.0
    fs = mineral.compute_formula(298.15, 1.0, endm)
    split = {}
    el = ""
    st = ""
    inbracket = False
    els_in_bracket = []
    look_for_bracket_multiplier = False
    for j in range(len(fs)):

        if fs[j] == "(":
            inbracket = True

        if fs[j] not in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."]:
            if look_for_bracket_multiplier == True:
                for el in els_in_bracket:
                    split[el] = split[el] * float(st)
                st = ""
                el = ""
                look_for_bracket_multiplier = False

            if len(st) > 0:  # and look_for_bracket_multiplier == False:
                split[el] = float(st)
                if inbracket == True:
                    els_in_bracket += [el]
                el = ""
                st = ""
                if fs[j] != ")":
                    el += fs[j]
            elif fs[j] != "(" and fs[j] != ")" and fs[j] != "'":
                el += fs[j]

        else:
            st += fs[j]

        if j == len(fs) - 1:
            split[el] = float(st)

        if fs[j] == ")":
            inbracket = False
            look_for_bracket_multiplier = True

    formula = {}
    Fetot = 0.0
    for el in split:
        if "Fe" not in el and split[el] > 0.0:
            formula[el] = split[el]
        else:
            Fetot += split[el]
    if Fetot > 0:
        formula["Fe"] = Fetot

    return formula


def convert_float(string):
    if len(string[1:].split("-")) > 1:
        if string[1:].split("-")[0][-1] != "E":
            return float(
                string[0]
                + string[1:].split("-")[0]
                + "E"
                + "".join(string[1:].split("-")[1:])
            )
    if string[0] == ".":
        return float("0" + string)
    elif string[0] == "-":
        return float("-0" + string[1:])
    else:
        return string


def run_eqpt(working_directory="", executable_name=None):
    # Keep track of whether to delete EQPT or not:
    tidyup = False
    # Commands for EQPT when running
    cmnds = b"n\n n\n n\n"

    # Copy the executable into the working folder
    if executable_name is None:
        if operatingsystem == "Darwin":
            tidyup = True
            os.system(
                "cp "
                + dir_path
                + "/executables/EQPT_mac "
                + working_directory
                + "/EQPT"
            )
            executable_name = "EQPT"
        elif operatingsystem == "Linux":
        # Setting this up now so it will run eqpt from compiled library
        #     os.system(
        #         "cp "
        #         + dir_path
        #         + "/executables/EQPT_linux "
        #         + working_directory
        #         + "/EQPT"
        #     )

            proc = subprocess.Popen(
                bytes('eqpt', "utf-8"),
                cwd=working_directory + "/",
                shell=True,
                stdin=subprocess.PIPE,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )

    if executable_name is not None:
        proc = subprocess.Popen(
            bytes("./" + executable_name, "utf-8"),
            cwd=working_directory + "/",
            shell=True,
            stdin=subprocess.PIPE,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )

    proc.communicate(cmnds)
    proc.terminate()

    if tidyup:
        os.system("rm " + working_directory + "/EQPT")


def run_eq3(working_directory="", executable_name=None):
    # Keep track of whether to delete EQPT or not:
    tidyup = False
    # Copy the executable into the working folder
    if executable_name is None:
        if operatingsystem == "Darwin":
            tidyup = True
            os.system(
                "cp " + dir_path + "/executables/EQ3_mac " + working_directory + "/EQ3"
            )
            executable_name = "EQ3"

        elif operatingsystem == "Linux":
            # os.system(
            #     "cp "
            #     + dir_path
            #     + "/executables/EQ3_linux "
            #     + working_directory
            #     + "/EQ3"
            # )
            proc = subprocess.Popen(
                bytes('eq3', "utf-8"),
                cwd=working_directory + "/",
                shell=True,
                stdin=subprocess.PIPE,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )

    if executable_name is not None:
        proc = subprocess.Popen(
            bytes("./" + executable_name, "utf-8"),
            cwd=working_directory + "/",
            shell=True,
            stdin=subprocess.PIPE,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )

    proc.communicate(b"\n")
    proc.terminate()

    if tidyup:
        os.system("rm " + working_directory + "/EQ3")


def run_eq6(working_directory="", executable_name=None):
    # Keep track of whether to delete EQ6 or not:
    tidyup = False
    # Copy the executable into the working folder
    if executable_name is None:
        if operatingsystem == "Darwin":
            tidyup = True
            executable_name = "EQ6"
            os.system(
                "cp " + dir_path + "/executables/EQ6_mac " + working_directory + "/EQ6"
            )
        elif operatingsystem == "Linux":
            # os.system(
            #     "cp "
            #     + dir_path
            #     + "/executables/EQ6_linux "
            #     + working_directory
            #     + "/EQ6"
            # )
            proc = subprocess.Popen(
                bytes('eq6', "utf-8"),
                cwd=working_directory + "/",
                shell=True,
                stdin=subprocess.PIPE,
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
            )

    if executable_name is not None:
        proc = subprocess.Popen(
            bytes("./" + executable_name, "utf-8"),
            cwd=working_directory + "/",
            shell=True,
            stdin=subprocess.PIPE,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )
    proc.communicate(b"\n")
    proc.terminate()

    if tidyup:
        os.system("rm " + working_directory + "/EQ6")
