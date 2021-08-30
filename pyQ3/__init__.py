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
# from pyQ3 import defaultsystem
from pyQ3 import system
from pyQ3 import fluid
from pyQ3 import reaction


class System(system.system):
    pass


class Fluid(fluid.fluid):
    pass


class Reaction(reaction.reaction):
    pass
