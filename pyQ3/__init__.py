"""pyQ3 - a python wrapper for EQ3 for DEW calculations

Developed and maintained by Simon Matthews (simonm@hi.is).

This module facilitates the automatic generation of DATA0 and input files, runs EQPT and EQ3 in the background,
and reads the output files. It is designed for use with the Deep Earth Water (DEW) model for calculations at
elevated pressures and temperatures.

This module requires the ENKI ThermoEngine along with many other scientific computing packages commonly installed
with scientific python distributions. The ThermoEngine coder objects for the DEW aqueous species must be generated
and compiled separately to this model. See the Jupyter notebooks supplied in the repository.
"""

# Import pyQ3 classes and methods
from robieref import robieref
import pyQ3.defaultsystem





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
