Project to integrate EQ3 calculations directly into the thermoengine coder module using the pyQ3
wrapper.


- How to deal with O in the endmembers and specifically moles variable. Should it be eliminated? How
  does thermoengine deal with it?
- I am not sure I am using the correct vectors for differentiation.
- How best to transfer information about system and fO2. Could pickle system so that the DEWFluid
  module can then pick it up. Also save fO2 to file?
- dG3dn3 may be need for use with fO2 constraint? Have coded something, but not tested yet...


Need to ensure charge balance- use neutral basis species? But- what about Cl-? That might be ok
because H+ can be increased to compensate. Na+ would be problematic because H+ can only be decreased
to a certain point. Even if bulk comp is sensible, derivatives may take it to non-sensible places.


Potential problems
- EQ3 assumes a mole of solvent. The input we have tells us the total H2O in the system, including
  in complexes. So there will be mass creation in the process of running an EQ3 calculation. Maybe
  the only way to get around this is by iteration?
- There is some inefficiency from the current pyQ3 structure- e.g., rerunning DATA0 every time a
  fluid object is created.
- Need to catch unsuccessful EQ3 runs
- Issue with numerical precision- zeros turn into numbers - seems to have gone?
- Need to eliminate O from mole routine altogether- it is meaningless. - But maybe I don't need 
  to do this. I think thermoengine requires it to be there.


Old notes:
# Don't need P and T derivatives. Need first and second compositional derivatives.
# If omni-component, probably doesn't look at the third compositional derivatives.
# Sympy/numpy methods which will construct high order derivatives. Look at functional forms.
# Functions to fit surfaces to get second derivations, don't just use numerical differences.
# 5th order finite difference for second derivatives. central limit for first order.

# Check tolerance in EQ3 to check tolerance is better than increment.
# Validate matrix with numpy methods, ensure it is postive definite.


# Coder has function templates for testing the composition is reasonable.
# Find an example and mimic.
# Run just aqueous species on its own in equilibrate, and put it on debug level 3.
# Remember to set Berman flag to calculate minerals properly.
