# pyQ3
Tools for interacting with DEW, EQPT, and EQ3, via python

The first step is to import DEW into ENKI by making phase objects for each DEW species. This is done in the import_DEW.ipnb notebook.

For demonstrations of how to create custom DATA0 files, and for running EQ3 calculations, see the notebooks in the tutorial folder.

To install the module, navigate to the folder and run `pip install .`. This will install the python component of the module. I have not yet got an automated installation working for the coder part. To install this, navigate to the directory the python module is installed in, move in dew_cleaned.csv and dew_setup.py. Run `ipython dew_setup.py`. Repeat for dew_berman.csv and `ipython dew_minerals_setup.py`

To use a binder instance of the code, go here:
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/simonwmatthews/myBinder_pydew/HEAD?filepath=pyQ3%2Fnotebooks%2Ftutorials%2Ftutorial1_DATA0.ipynb)

To use the docker image directly, obtain it from dockerhub at simonwmatthews/pydew
