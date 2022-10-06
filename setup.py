from setuptools import setup, find_packages
# from setuptools.command.install import install
from subprocess import check_call


setup(name='pyQ3',
      version='0.12',
      description='pyQ3 wrapper for DEW-EQ3 calculations',
      url='http://github.com/simonwmatthews/pyQ3',
      author='Simon Matthews',
      author_email='simonm@hi.is',
      license='MIT',
      packages=['pyQ3'],
      # ext_modules = cythonize(extensions),
      package_data={'pyQ3':['dew2019_coderfiles/*',
                            'dew_minerals_coderfiles/*',
                            'DEW2019.pkl',
                            'DEW2019_oldTE.pkl',
                            'dewminerals.pkl',
                            'dewminerals_oldTE.pkl',
                            'executables/*']},
      install_requires=[
         'dill',
         'thermoengine',
         'numpy',
         'pandas',
         'cython',
      ],
      include_package_data=True,
      zip_safe=False,
      test_suite='tests',
      tests_require=['unittest'])
