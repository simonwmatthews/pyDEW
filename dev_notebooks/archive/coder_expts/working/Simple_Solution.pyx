# Cython numpy wrapper code for arrays is taken from:
# http://gael-varoquaux.info/programming/cython-example-of-exposing-c-computed-arrays-in-python-without-data-copies.html
# Author: Gael Varoquaux, BSD license

# Declare the prototype of the C functions
cdef extern from "Feldspar_Simple_Solution_calib.h":
    const char *Feldspar_Simple_Solution_calib_identifier();
    const char *Feldspar_Simple_Solution_calib_name();
    char *Feldspar_Simple_Solution_calib_formula(double T, double P, double n[3]);
    double *Feldspar_Simple_Solution_calib_conv_elm_to_moles(double *e);
    int Feldspar_Simple_Solution_calib_test_moles(double *n);
    const char *Feldspar_Simple_Solution_calib_endmember_name(int index);
    const char *Feldspar_Simple_Solution_calib_endmember_formula(int index);
    const double Feldspar_Simple_Solution_calib_endmember_mw(int index);
    const double *Feldspar_Simple_Solution_calib_endmember_elements(int index);
    double Feldspar_Simple_Solution_calib_endmember_mu0(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_dmu0dT(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_dmu0dP(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d2mu0dT2(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d2mu0dTdP(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d2mu0dP2(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d3mu0dT3(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d3mu0dT2dP(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d3mu0dTdP2(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_endmember_d3mu0dP3(int index, double t, double p);
    double Feldspar_Simple_Solution_calib_g(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_dgdt(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_dgdp(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d2gdt2(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d2gdtdp(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d2gdp2(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d3gdt3(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d3gdt2dp(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d3gdtdp2(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_d3gdp3(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_s(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_v(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_cv(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_cp(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_dcpdt(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_alpha(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_beta(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_K(double t, double p, double n[3])
    double Feldspar_Simple_Solution_calib_Kp(double t, double p, double n[3])

    void Feldspar_Simple_Solution_calib_dgdn(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d2gdndt(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d2gdndp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d3gdndt2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d3gdndtdp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d3gdndp2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdndt3(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdndt2dp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdndtdp2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdndp3(double T, double P, double n[3], double result[3])

    void Feldspar_Simple_Solution_calib_d2gdn2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d3gdn2dt(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d3gdn2dp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdn2dt2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdn2dtdp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdn2dp2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn2dt3(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn2dt2dp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn2dtdp2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn2dp3(double T, double P, double n[3], double result[3])

    void Feldspar_Simple_Solution_calib_d3gdn3(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdn3dt(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d4gdn3dp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn3dt2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn3dtdp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d5gdn3dp2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d6gdn3dt3(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d6gdn3dt2dp(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d6gdn3dtdp2(double T, double P, double n[3], double result[3])
    void Feldspar_Simple_Solution_calib_d6gdn3dp3(double T, double P, double n[3], double result[3])

    int Feldspar_Simple_Solution_get_param_number()
    const char **Feldspar_Simple_Solution_get_param_names()
    const char **Feldspar_Simple_Solution_get_param_units()
    void Feldspar_Simple_Solution_get_param_values(double **values)
    int Feldspar_Simple_Solution_set_param_values(double *values)
    double Feldspar_Simple_Solution_get_param_value(int index)
    int Feldspar_Simple_Solution_set_param_value(int index, double value)

    double Feldspar_Simple_Solution_dparam_g(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_dgdt(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_dgdp(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d2gdt2(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d2gdtdp(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d2gdp2(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d3gdt3(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d3gdt2dp(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d3gdtdp2(double t, double p, double n[3], int index);
    double Feldspar_Simple_Solution_dparam_d3gdp3(double t, double p, double n[3], int index);

    void Feldspar_Simple_Solution_dparam_dgdn(double t, double p, double n[3], int index, double result[3])

from libc.stdlib cimport malloc, free
from cpython cimport PyObject, Py_INCREF
import ctypes

# Import the Python-level symbols of numpy
import numpy as np

# Import the C-level symbols of numpy
cimport numpy as np

# Numpy must be initialized. When using numpy from C or Cython you must
# _always_ do that, or you will have segfaults
np.import_array()

# here is the "wrapper" signature
def cy_Feldspar_Simple_Solution_calib_identifier():
    result = <bytes> Feldspar_Simple_Solution_calib_identifier()
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_name():
    result = <bytes> Feldspar_Simple_Solution_calib_name()
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_formula(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    r = Feldspar_Simple_Solution_calib_formula(<double> t, <double> p, <double *> m)
    result = <bytes> r
    free (m)
    free (r)
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_conv_elm_to_moles(np_array):
    cdef double *e = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        e[i] = np_array[i]
    r = Feldspar_Simple_Solution_calib_conv_elm_to_moles(<double *> e)
    result = []
    for i in range(3):
        result.append(r[i])
    free (e)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_conv_elm_to_tot_moles(np_array):
    cdef double *e = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        e[i] = np_array[i]
    r = Feldspar_Simple_Solution_calib_conv_elm_to_moles(<double *> e)
    result = 0.0
    for i in range(3):
        result += r[i]
    free (e)
    free (r)
    return result
def cy_Feldspar_Simple_Solution_calib_conv_elm_to_tot_grams(np_array):
    cdef double *e = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        e[i] = np_array[i]
    r = Feldspar_Simple_Solution_calib_conv_elm_to_moles(<double *> e)
    result = 0.0
    for i in range(3):
        mw = cy_Feldspar_Simple_Solution_calib_endmember_mw(i)
        result += r[i]*mw
    free (e)
    free (r)
    return result
def cy_Feldspar_Simple_Solution_calib_conv_moles_to_tot_moles(np_array):
    result = 0.0
    for i in range(3):
        result += np_array[i]
    return result
def cy_Feldspar_Simple_Solution_calib_conv_moles_to_mole_frac(np_array):
    result = np.zeros(3)
    sum = np.sum(np_array)
    for i in range(3):
        result[i] += np_array[i]/sum
    return result
def cy_Feldspar_Simple_Solution_calib_conv_moles_to_elm(np_array):
    result = np.zeros(106)
    for i in range(3):
        end = cy_Feldspar_Simple_Solution_calib_endmember_elements(i)
        for j in range(0,106):
            result[j] += np_array[i]*end[j]
    return result
def cy_Feldspar_Simple_Solution_calib_test_moles(np_array):
    cdef double *n = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        n[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_test_moles(<double *> n)
    free (n)
    return False if result == 0 else True

def cy_Feldspar_Simple_Solution_calib_endmember_number():
    return 3
def cy_Feldspar_Simple_Solution_calib_endmember_name(int index):
    assert index in range(0,3), "index out of range"
    result = Feldspar_Simple_Solution_calib_endmember_name(index);
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_endmember_formula(int index):
    assert index in range(0,3), "index out of range"
    result = Feldspar_Simple_Solution_calib_endmember_formula(index);
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_endmember_mw(int index):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_mw(index);
def cy_Feldspar_Simple_Solution_calib_endmember_elements(int index):
    assert index in range(0,3), "index out of range"
    r = Feldspar_Simple_Solution_calib_endmember_elements(index);
    result = []
    for i in range(0,106):
        result.append(r[i])
    return np.array(result)

def cy_Feldspar_Simple_Solution_calib_species_number():
    return 3
def cy_Feldspar_Simple_Solution_calib_species_name(int index):
    assert index in range(0,3), "index out of range"
    result = Feldspar_Simple_Solution_calib_endmember_name(index);
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_species_formula(int index):
    assert index in range(0,3), "index out of range"
    result = Feldspar_Simple_Solution_calib_endmember_formula(index);
    return result.decode('UTF-8')
def cy_Feldspar_Simple_Solution_calib_species_mw(int index):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_mw(index);
def cy_Feldspar_Simple_Solution_calib_species_elements(int index):
    assert index in range(0,3), "index out of range"
    r = Feldspar_Simple_Solution_calib_endmember_elements(index);
    result = []
    for i in range(0,106):
        result.append(r[i])
    return np.array(result)

def cy_Feldspar_Simple_Solution_calib_endmember_mu0(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_mu0(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_dmu0dT(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_dmu0dT(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_dmu0dP(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_dmu0dP(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d2mu0dT2(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d2mu0dT2(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d2mu0dTdP(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d2mu0dTdP(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d2mu0dP2(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d2mu0dP2(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d3mu0dT3(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d3mu0dT3(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d3mu0dT2dP(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d3mu0dT2dP(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d3mu0dTdP2(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d3mu0dTdP2(index, <double> t, <double> p);
def cy_Feldspar_Simple_Solution_calib_endmember_d3mu0dP3(int index, double t, double p):
    assert index in range(0,3), "index out of range"
    return Feldspar_Simple_Solution_calib_endmember_d3mu0dP3(index, <double> t, <double> p);

def cy_Feldspar_Simple_Solution_calib_g(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_g(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_dgdt(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_dgdt(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_dgdp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_dgdp(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d2gdt2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d2gdt2(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d2gdtdp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d2gdtdp(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d2gdp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d2gdp2(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d3gdt3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d3gdt3(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d3gdt2dp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d3gdt2dp(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d3gdtdp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d3gdtdp2(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_d3gdp3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_d3gdp3(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_s(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_s(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_v(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_v(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_cv(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_cv(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_cp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_cp(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_dcpdt(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_dcpdt(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_alpha(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_alpha(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_beta(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_beta(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_K(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_K(<double> t, <double> p, <double *> m)
    free (m)
    return result
def cy_Feldspar_Simple_Solution_calib_Kp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_calib_Kp(<double> t, <double> p, <double *> m)
    free (m)
    return result

def cy_Feldspar_Simple_Solution_calib_dgdn(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_dgdn(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d2gdndt(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d2gdndt(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d2gdndp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d2gdndp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d3gdndt2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d3gdndt2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d3gdndtdp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d3gdndtdp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d3gdndp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d3gdndp2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdndt3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdndt3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdndt2dp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdndt2dp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdndtdp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdndtdp2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdndp3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    cdef double *r = <double *>malloc(3*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdndp3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(3):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)

def cy_Feldspar_Simple_Solution_calib_d2gdn2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d2gdn2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d3gdn2dt(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d3gdn2dt(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d3gdn2dp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d3gdn2dp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdn2dt2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdn2dt2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdn2dtdp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdn2dtdp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdn2dp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdn2dp2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn2dt3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn2dt3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn2dt2dp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn2dt2dp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn2dtdp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn2dtdp2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn2dp3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    ndim = int(3*(3-1)/2 + 3)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn2dp3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)

def cy_Feldspar_Simple_Solution_calib_d3gdn3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d3gdn3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdn3dt(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdn3dt(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d4gdn3dp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d4gdn3dp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn3dt2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn3dt2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn3dtdp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn3dtdp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d5gdn3dp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d5gdn3dp2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d6gdn3dt3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d6gdn3dt3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d6gdn3dt2dp(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d6gdn3dt2dp(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d6gdn3dtdp2(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d6gdn3dtdp2(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)
def cy_Feldspar_Simple_Solution_calib_d6gdn3dp3(double t, double p, np_array):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    nc = 3
    ndim = int(nc*(nc+1)*(nc+2)/6)
    cdef double *r = <double *>malloc(ndim*sizeof(double))
    Feldspar_Simple_Solution_calib_d6gdn3dp3(<double> t, <double> p, <double *> m, <double *> r)
    result = []
    for i in range(ndim):
        result.append(r[i])
    free (m)
    free (r)
    return np.array(result)


def cy_Feldspar_Simple_Solution_get_param_number():
    result = Feldspar_Simple_Solution_get_param_number()
    return result
def cy_Feldspar_Simple_Solution_get_param_names():
    cdef const char **names = Feldspar_Simple_Solution_get_param_names()
    n = Feldspar_Simple_Solution_get_param_number()
    result = []
    for i in range(0,n):
        entry = <bytes> names[i]
        result.append(entry.decode('UTF-8'))
    return result
def cy_Feldspar_Simple_Solution_get_param_units():
    cdef const char **units = Feldspar_Simple_Solution_get_param_units()
    n = Feldspar_Simple_Solution_get_param_number()
    result = []
    for i in range(0,n):
        entry = <bytes> units[i]
        result.append(entry.decode('UTF-8'))
    return result
def cy_Feldspar_Simple_Solution_get_param_values():
    n = Feldspar_Simple_Solution_get_param_number()
    cdef double *m = <double *>malloc(n*sizeof(double))
    Feldspar_Simple_Solution_get_param_values(&m)
    np_array = np.zeros(n)
    for i in range(n):
        np_array[i] = m[i]
    free(m)
    return np_array
def cy_Feldspar_Simple_Solution_set_param_values(np_array):
    n = len(np_array)
    cdef double *m = <double *>malloc(n*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_set_param_values(m);
    free(m)
    return result
def cy_Feldspar_Simple_Solution_get_param_value(int index):
    result = Feldspar_Simple_Solution_get_param_value(<int> index)
    return result
def cy_Feldspar_Simple_Solution_set_param_value(int index, double value):
    result = Feldspar_Simple_Solution_set_param_value(<int> index, <double> value)
    return result

def cy_Feldspar_Simple_Solution_dparam_g(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_g(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_dgdt(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_dgdt(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_dgdp(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_dgdp(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d2gdt2(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d2gdt2(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d2gdtdp(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d2gdtdp(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d2gdp2(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d2gdp2(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d3gdt3(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d3gdt3(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d3gdt2dp(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d3gdt2dp(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d3gdtdp2(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d3gdtdp2(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result
def cy_Feldspar_Simple_Solution_dparam_d3gdp3(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    result = Feldspar_Simple_Solution_dparam_d3gdp3(<double> t, <double> p, <double *> m, <int> index)
    free(m)
    return result

def cy_Feldspar_Simple_Solution_dparam_dgdn(double t, double p, np_array, int index):
    cdef double *m = <double *>malloc(len(np_array)*sizeof(double))
    cdef double *r = <double *>malloc(len(np_array)*sizeof(double))
    for i in range(np_array.size):
        m[i] = np_array[i]
    Feldspar_Simple_Solution_dparam_dgdn(<double> t, <double> p, <double *> m, <int> index, <double *> r)
    r_np_array = np.zeros(len(np_array))
    for i in range(r_np_array.size):
        r_np_array[i] = r[i]
    free(m)
    free(r)
    return r_np_array

