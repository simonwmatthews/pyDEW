from setuptools import setup, find_packages
# from setuptools.command.install import install
from subprocess import check_call

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(name='pyDEW',
      version='0.14',
      description='Python library for performing Deep Earth Water (DEW) calculations.',
      long_description=long_description,
      long_description_content_type="text/markdown",
      url='http://github.com/simonwmatthews/pyDEW',
      author='Simon Matthews',
      author_email='simonm@hi.is',
      license='MIT',
      packages=['pyDEW'],
      package_data={'pyDEW':['dew2019_coderfiles/*',
                             'dew_minerals_coderfiles/*',
                             'DEW2019.pkl',
                             'DEW2019_oldTE.pkl',
                             'dewminerals.pkl',
                             'dewminerals_oldTE.pkl',
                             'executables/*']},
      install_requires=[
         'dill>=0.3.4',
         'thermoengine>=1.0',
         'numpy>=1.20.3',
         'pandas>=1.3.3',
         'cython>=0.29.24',
      ],
      include_package_data=True,
      zip_safe=False,
      test_suite='tests',
      tests_require=['unittest'])
