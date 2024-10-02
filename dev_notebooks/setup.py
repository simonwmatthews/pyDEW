# This is to get the cython code to compile

import numpy as np
from setuptools import Extension, setup
from Cython.Build import cythonize


sourcefiles = [
               'eqlibr.pyx', 
            #    'eq3nr.pyx'
               ]

extensions = [
              Extension("eqlibr", sourcefiles, 
                        # libraries=['f2c'],
                        extra_compile_args=['-L/usr/local/lib', '-lf2c', '-lm']
                        ),
            #   Extension("eq3nr", sourcefiles, 
            #             libraries=['f2c', 'eq'], #include_dirs=[np.get_include()]
                        # extra_compile_args=['libeq.dylib']
                        # )
              ]
setup(
    ext_modules = cythonize(extensions),
)


