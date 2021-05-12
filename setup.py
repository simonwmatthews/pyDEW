from setuptools import setup
from setuptools.command.install import install
from subprocess import check_call


setup(name='pyQ3',
      version='0.1',
      description='pyQ3 wrapper for DEW-EQ3 calculations',
      url='http://github.com/simonwmatthews/pyQ3',
      author='Simon Matthews',
      author_email='simonm@hi.is',
      license='MIT',
      packages=['pyQ3'],
      zip_safe=False,)
