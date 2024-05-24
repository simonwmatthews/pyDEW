# This is to get the cython code to compile

from setuptools import Extension, setup
from Cython.Build import cythonize


sourcefiles = ['eqlibr.pyx']

extensions = [Extension("eqlibr", sourcefiles, 
                        libraries=['f2c']
                        # extra_compile_args=['-L/usr/local/lib', '-lf2c', '-lm']
                        )]

setup(
    ext_modules = cythonize(extensions),
)


