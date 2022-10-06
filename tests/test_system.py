"""
Test DEW imports

This module tests that the DEW databases can be imported. During installation this will also
cause the coder code to be compiled.
"""

import unittest
import pyQ3

class test_system(unittest.TestCase):
    print('hi')
    def test_import(self):
        try:
            system = pyQ3.System()
        except Exception:
            self.fail("Something went wrong with creating a DEW system. Most likely "
                      "this is a problem with compiling the C code.")
