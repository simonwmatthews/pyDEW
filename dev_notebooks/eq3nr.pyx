# Cython wrapper for the EQ3/6 code.
# Simon Matthews (simonm@hi.is) May 2024
# University of Iceland

# The purpose of this module is to wrap the EQ3 main loop so that variables
# can be replaced with cython variables one by one, ensuring the code
# continues to work with a testing routine

import numpy as np

cdef extern from "eq3nr110.c":
    int MAIN__()
    int MAINTEST__()

def cy_main_loop():
    result = MAIN__()
    return result

def cy_maintest_loop():
    result = MAINTEST__()
    return result