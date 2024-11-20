# pyDEW
Tools for interacting with DEW, EQPT, and EQ3, via python (formally known as pyQ3).

The first step is to import DEW into ENKI by making phase objects for each DEW species. This is done in the import_DEW.ipnb notebook.

For demonstrations of how to create custom DATA0 files, and for running EQ3 calculations, see the notebooks in the tutorial folder.

To install the module, navigate to the folder and run `pip install .`. The first time you create an instance of a DEW System in a notebook or script, the module will take some time to compile the ThermoEngine Coder generated code. Be patient!

To use a binder instance of the code, go here:
[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/simonwmatthews/myBinder_pydew/HEAD?labpath=tutorials%2Ftutorial1_DATA0.ipynb)

## Running pyDEW in Docker
At the time of writing (May 2023) the capacity of myBinder has reduced substantially, making it rather unreliable for running pyDEW. We will soon have pyDEW available on the ENKI server, but until then the easiest way to get pyDEW running is to use a [Docker](http://www.docker.com) container. Once you have Docker installed, and running, you can run the following command (at least in OSX or linux)| in a terminal to download and run the pyDEW container:

`docker run -p 8888:8888 --env JUPYTER_ENABLE_LAB=yes --user root -e GRANT_SUDO=yes simonwmatthews/pydew:v2.15`

You may run into issues if you already have an instance of Jupyter Lab running on your computer. Feel free to get in touch with me if you would like help in getting pyDEW running on your computer.
