# pyDEW
Tools for interacting with DEW, EQPT, and EQ3, via python (formerly known as pyQ3).

This software is *in development*. A significant refactoring is likely to take place following a major update to the ThermoEngine library on which it is built (due in mid 2025).

For help getting started, or any other queries, please feel free to contact me.

# Installation
PyDEW relies on the ENKI ThemoEngine library, and this must be installed before pyDEW. Unfortunately, the installation of ThermoEngine is not straightforward. The ThermoEngine developers are working on making ThermoEngine easily installable (and we are optimistic this will happen by summer 2025). Until then, we offer the following methods for getting pyDEW running.

## 1. Use pyDEW in the cloud (the easiest method)
There is a mybinder instance of the pyDEW code: [![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/simonwmatthews/myBinder_pydew/HEAD?labpath=tutorials%2Ftutorial1_DATA0.ipynb)

While this is the quickest and easiest way to get up and running with pyDEW, make sure to download your work as it will not be saved between sessions!

## 2. Use Docker
[Docker](http://www.docker.com) is a software tool that runs a virtual machine on your computer. You can use docker to run an image that already has ThermoEngine and pyDEW installed on it. Once you have Docker installed, you can run the following command (at least on MacOS or linux) in a terminal to download and run the pyDEW container:

`docker run -p 8888:8888 --env JUPYTER_ENABLE_LAB=yes --user root -e GRANT_SUDO=yes simonwmatthews/pydew:v2.15`

Then follow the JupyterLab url provided by the output printed in the terminal window.

A similar procedure should apply to Windows, but I do not have access to a Windows machine to test this.

If you are already running an instance of JupyterLab on your computer, this may cause conflicts with JupyterLab instance running in the Docker container.

## 3. Complete Local Installation

*Not recommmended*

At the present time, ThermoEngine installation is only possible on Linux and MacOS. It will not work on Windows. You must have a C compiler installed on your system.

To install ThermoEngine follow the instructions on the [ThermoEngine GitLab Page](https://gitlab.com/ENKI-portal/ThermoEngine). Note that you may need to manually move the GSL libraries, or add their location to your PATH variable. You may also need to disable installation of the SulfLiq module if your setup is unable to compile it.

Once thermoengine is installed, download the pyDEW code, navigate into the pyDEW folder within a terminal window, and run the command `pip install pyDEW`. The installation process requires compiling a substantial amount of ThermoEngine coder generated code. This will take some time.


# Getting started

For demonstrations of how to create custom DATA0 files, and for running EQ3 calculations, see the notebooks in the tutorial folder.
