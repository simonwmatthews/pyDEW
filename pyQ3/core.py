import dill
import pyximport
import importlib
sym.init_printing()

def load_coder_modules(working_dir='dew2019_coderfiles'):
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
    mask = np.array([file.endswith('.pyx') for file in working_dir_code ])
    mod_names = [os.path.splitext(file)[0] for file in working_dir_code[mask]]

    os.chdir('working')
    [importlib.import_module(mod_name) for mod_name in mod_names]
    os.chdir('..')


def DEW_species(working_dir='dew2019_coderfiles',pickle_file='DEW2019.pkl'):
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
    with open('DEW2019.pkl','rb') as file:
        dew = dill.load(file)
        file.close()
    return dew


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

def formula_to_dict(formula,add_H2O=0):
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

class Error(Exception):
    pass

class InputError(Error):
    def __init__(self, message):
        self.message = message
