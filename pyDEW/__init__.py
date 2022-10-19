"""pyDEW - a python library for performing Deep Earth Water (DEW) calculations

Developed and maintained by Simon Matthews (simonm@hi.is).

This module facilitates the automatic generation of DATA0 and input files, runs EQPT and EQ3 in the background,
and reads the output files. It is designed for use with the Deep Earth Water (DEW) model for calculations at
elevated pressures and temperatures.

This module requires the ENKI ThermoEngine along with many other scientific computing packages commonly installed
with scientific python distributions. The ThermoEngine coder objects for the DEW aqueous species must be generated
and compiled separately to this model. See the Jupyter notebooks supplied in the repository.
"""


from pyDEW import system
from pyDEW import fluid
from pyDEW import reaction


class System(system.system):
    pass


class Fluid(fluid.fluid):
    pass


class Reaction(reaction.reaction):
    pass
