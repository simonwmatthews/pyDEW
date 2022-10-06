# pyQ3
Tools for interacting with DEW, EQPT, and EQ3, via python

The first step is to import DEW into ENKI by making phase objects for each DEW species. This is done in the import_DEW.ipnb notebook.

For demonstrations of how to create custom DATA0 files, and for running EQ3 calculations, see the notebooks in the tutorial folder.

To install the module, navigate to the folder and run `pip install .`. The first time you create an instance of a DEW System in a notebook or script, the module will take some time to compile the ThermoEngine Coder generated code. Be patient!

To use a binder instance of the code, go here:
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/simonwmatthews/myBinder_pydew/HEAD?filepath=pyQ3%2Fnotebooks%2Ftutorials%2Ftutorial1_DATA0.ipynb)
