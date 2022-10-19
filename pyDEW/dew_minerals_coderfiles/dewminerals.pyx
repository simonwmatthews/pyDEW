import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "H2O_l_G_r__dewminerals_calc.h":
    const char *H2O_l_G_r__dewminerals_identifier();
    const char *H2O_l_G_r__dewminerals_name();
    const char *H2O_l_G_r__dewminerals_formula();
    const double H2O_l_G_r__dewminerals_mw();
    const double *H2O_l_G_r__dewminerals_elements();
    double H2O_l_G_r__dewminerals_g(double t, double p)
    double H2O_l_G_r__dewminerals_dgdt(double t, double p)
    double H2O_l_G_r__dewminerals_dgdp(double t, double p)
    double H2O_l_G_r__dewminerals_d2gdt2(double t, double p)
    double H2O_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double H2O_l_G_r__dewminerals_d2gdp2(double t, double p)
    double H2O_l_G_r__dewminerals_d3gdt3(double t, double p)
    double H2O_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double H2O_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double H2O_l_G_r__dewminerals_d3gdp3(double t, double p)
    double H2O_l_G_r__dewminerals_s(double t, double p)
    double H2O_l_G_r__dewminerals_v(double t, double p)
    double H2O_l_G_r__dewminerals_cv(double t, double p)
    double H2O_l_G_r__dewminerals_cp(double t, double p)
    double H2O_l_G_r__dewminerals_dcpdt(double t, double p)
    double H2O_l_G_r__dewminerals_alpha(double t, double p)
    double H2O_l_G_r__dewminerals_beta(double t, double p)
    double H2O_l_G_r__dewminerals_K(double t, double p)
    double H2O_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_H2O_l_G_r__dewminerals_identifier():
    result = <bytes> H2O_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_H2O_l_G_r__dewminerals_name():
    result = <bytes> H2O_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_H2O_l_G_r__dewminerals_formula():
    result = <bytes> H2O_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_H2O_l_G_r__dewminerals_mw():
    result = H2O_l_G_r__dewminerals_mw()
    return result
def cy_H2O_l_G_r__dewminerals_elements():
    cdef const double *e = H2O_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_H2O_l_G_r__dewminerals_g(double t, double p):
    result = H2O_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_dgdt(double t, double p):
    result = H2O_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_dgdp(double t, double p):
    result = H2O_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = H2O_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = H2O_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = H2O_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = H2O_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = H2O_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = H2O_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = H2O_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_s(double t, double p):
    result = H2O_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_v(double t, double p):
    result = H2O_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_cv(double t, double p):
    result = H2O_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_cp(double t, double p):
    result = H2O_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_dcpdt(double t, double p):
    result = H2O_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_alpha(double t, double p):
    result = H2O_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_beta(double t, double p):
    result = H2O_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_K(double t, double p):
    result = H2O_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_H2O_l_G_r__dewminerals_Kp(double t, double p):
    result = H2O_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "H2S_l_G_r__dewminerals_calc.h":
    const char *H2S_l_G_r__dewminerals_identifier();
    const char *H2S_l_G_r__dewminerals_name();
    const char *H2S_l_G_r__dewminerals_formula();
    const double H2S_l_G_r__dewminerals_mw();
    const double *H2S_l_G_r__dewminerals_elements();
    double H2S_l_G_r__dewminerals_g(double t, double p)
    double H2S_l_G_r__dewminerals_dgdt(double t, double p)
    double H2S_l_G_r__dewminerals_dgdp(double t, double p)
    double H2S_l_G_r__dewminerals_d2gdt2(double t, double p)
    double H2S_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double H2S_l_G_r__dewminerals_d2gdp2(double t, double p)
    double H2S_l_G_r__dewminerals_d3gdt3(double t, double p)
    double H2S_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double H2S_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double H2S_l_G_r__dewminerals_d3gdp3(double t, double p)
    double H2S_l_G_r__dewminerals_s(double t, double p)
    double H2S_l_G_r__dewminerals_v(double t, double p)
    double H2S_l_G_r__dewminerals_cv(double t, double p)
    double H2S_l_G_r__dewminerals_cp(double t, double p)
    double H2S_l_G_r__dewminerals_dcpdt(double t, double p)
    double H2S_l_G_r__dewminerals_alpha(double t, double p)
    double H2S_l_G_r__dewminerals_beta(double t, double p)
    double H2S_l_G_r__dewminerals_K(double t, double p)
    double H2S_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_H2S_l_G_r__dewminerals_identifier():
    result = <bytes> H2S_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_H2S_l_G_r__dewminerals_name():
    result = <bytes> H2S_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_H2S_l_G_r__dewminerals_formula():
    result = <bytes> H2S_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_H2S_l_G_r__dewminerals_mw():
    result = H2S_l_G_r__dewminerals_mw()
    return result
def cy_H2S_l_G_r__dewminerals_elements():
    cdef const double *e = H2S_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_H2S_l_G_r__dewminerals_g(double t, double p):
    result = H2S_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_dgdt(double t, double p):
    result = H2S_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_dgdp(double t, double p):
    result = H2S_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = H2S_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = H2S_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = H2S_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = H2S_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = H2S_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = H2S_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = H2S_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_s(double t, double p):
    result = H2S_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_v(double t, double p):
    result = H2S_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_cv(double t, double p):
    result = H2S_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_cp(double t, double p):
    result = H2S_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_dcpdt(double t, double p):
    result = H2S_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_alpha(double t, double p):
    result = H2S_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_beta(double t, double p):
    result = H2S_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_K(double t, double p):
    result = H2S_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_H2S_l_G_r__dewminerals_Kp(double t, double p):
    result = H2S_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "H2_l_G_r__dewminerals_calc.h":
    const char *H2_l_G_r__dewminerals_identifier();
    const char *H2_l_G_r__dewminerals_name();
    const char *H2_l_G_r__dewminerals_formula();
    const double H2_l_G_r__dewminerals_mw();
    const double *H2_l_G_r__dewminerals_elements();
    double H2_l_G_r__dewminerals_g(double t, double p)
    double H2_l_G_r__dewminerals_dgdt(double t, double p)
    double H2_l_G_r__dewminerals_dgdp(double t, double p)
    double H2_l_G_r__dewminerals_d2gdt2(double t, double p)
    double H2_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double H2_l_G_r__dewminerals_d2gdp2(double t, double p)
    double H2_l_G_r__dewminerals_d3gdt3(double t, double p)
    double H2_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double H2_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double H2_l_G_r__dewminerals_d3gdp3(double t, double p)
    double H2_l_G_r__dewminerals_s(double t, double p)
    double H2_l_G_r__dewminerals_v(double t, double p)
    double H2_l_G_r__dewminerals_cv(double t, double p)
    double H2_l_G_r__dewminerals_cp(double t, double p)
    double H2_l_G_r__dewminerals_dcpdt(double t, double p)
    double H2_l_G_r__dewminerals_alpha(double t, double p)
    double H2_l_G_r__dewminerals_beta(double t, double p)
    double H2_l_G_r__dewminerals_K(double t, double p)
    double H2_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_H2_l_G_r__dewminerals_identifier():
    result = <bytes> H2_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_H2_l_G_r__dewminerals_name():
    result = <bytes> H2_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_H2_l_G_r__dewminerals_formula():
    result = <bytes> H2_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_H2_l_G_r__dewminerals_mw():
    result = H2_l_G_r__dewminerals_mw()
    return result
def cy_H2_l_G_r__dewminerals_elements():
    cdef const double *e = H2_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_H2_l_G_r__dewminerals_g(double t, double p):
    result = H2_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_dgdt(double t, double p):
    result = H2_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_dgdp(double t, double p):
    result = H2_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = H2_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = H2_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = H2_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = H2_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = H2_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = H2_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = H2_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_s(double t, double p):
    result = H2_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_v(double t, double p):
    result = H2_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_cv(double t, double p):
    result = H2_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_cp(double t, double p):
    result = H2_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_dcpdt(double t, double p):
    result = H2_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_alpha(double t, double p):
    result = H2_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_beta(double t, double p):
    result = H2_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_K(double t, double p):
    result = H2_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_H2_l_G_r__dewminerals_Kp(double t, double p):
    result = H2_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CH4_l_G_r__dewminerals_calc.h":
    const char *CH4_l_G_r__dewminerals_identifier();
    const char *CH4_l_G_r__dewminerals_name();
    const char *CH4_l_G_r__dewminerals_formula();
    const double CH4_l_G_r__dewminerals_mw();
    const double *CH4_l_G_r__dewminerals_elements();
    double CH4_l_G_r__dewminerals_g(double t, double p)
    double CH4_l_G_r__dewminerals_dgdt(double t, double p)
    double CH4_l_G_r__dewminerals_dgdp(double t, double p)
    double CH4_l_G_r__dewminerals_d2gdt2(double t, double p)
    double CH4_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double CH4_l_G_r__dewminerals_d2gdp2(double t, double p)
    double CH4_l_G_r__dewminerals_d3gdt3(double t, double p)
    double CH4_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double CH4_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double CH4_l_G_r__dewminerals_d3gdp3(double t, double p)
    double CH4_l_G_r__dewminerals_s(double t, double p)
    double CH4_l_G_r__dewminerals_v(double t, double p)
    double CH4_l_G_r__dewminerals_cv(double t, double p)
    double CH4_l_G_r__dewminerals_cp(double t, double p)
    double CH4_l_G_r__dewminerals_dcpdt(double t, double p)
    double CH4_l_G_r__dewminerals_alpha(double t, double p)
    double CH4_l_G_r__dewminerals_beta(double t, double p)
    double CH4_l_G_r__dewminerals_K(double t, double p)
    double CH4_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CH4_l_G_r__dewminerals_identifier():
    result = <bytes> CH4_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CH4_l_G_r__dewminerals_name():
    result = <bytes> CH4_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_CH4_l_G_r__dewminerals_formula():
    result = <bytes> CH4_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_CH4_l_G_r__dewminerals_mw():
    result = CH4_l_G_r__dewminerals_mw()
    return result
def cy_CH4_l_G_r__dewminerals_elements():
    cdef const double *e = CH4_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CH4_l_G_r__dewminerals_g(double t, double p):
    result = CH4_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_dgdt(double t, double p):
    result = CH4_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_dgdp(double t, double p):
    result = CH4_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = CH4_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = CH4_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = CH4_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = CH4_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = CH4_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = CH4_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = CH4_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_s(double t, double p):
    result = CH4_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_v(double t, double p):
    result = CH4_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_cv(double t, double p):
    result = CH4_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_cp(double t, double p):
    result = CH4_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_dcpdt(double t, double p):
    result = CH4_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_alpha(double t, double p):
    result = CH4_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_beta(double t, double p):
    result = CH4_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_K(double t, double p):
    result = CH4_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_CH4_l_G_r__dewminerals_Kp(double t, double p):
    result = CH4_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "S2_l_G_r__dewminerals_calc.h":
    const char *S2_l_G_r__dewminerals_identifier();
    const char *S2_l_G_r__dewminerals_name();
    const char *S2_l_G_r__dewminerals_formula();
    const double S2_l_G_r__dewminerals_mw();
    const double *S2_l_G_r__dewminerals_elements();
    double S2_l_G_r__dewminerals_g(double t, double p)
    double S2_l_G_r__dewminerals_dgdt(double t, double p)
    double S2_l_G_r__dewminerals_dgdp(double t, double p)
    double S2_l_G_r__dewminerals_d2gdt2(double t, double p)
    double S2_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double S2_l_G_r__dewminerals_d2gdp2(double t, double p)
    double S2_l_G_r__dewminerals_d3gdt3(double t, double p)
    double S2_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double S2_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double S2_l_G_r__dewminerals_d3gdp3(double t, double p)
    double S2_l_G_r__dewminerals_s(double t, double p)
    double S2_l_G_r__dewminerals_v(double t, double p)
    double S2_l_G_r__dewminerals_cv(double t, double p)
    double S2_l_G_r__dewminerals_cp(double t, double p)
    double S2_l_G_r__dewminerals_dcpdt(double t, double p)
    double S2_l_G_r__dewminerals_alpha(double t, double p)
    double S2_l_G_r__dewminerals_beta(double t, double p)
    double S2_l_G_r__dewminerals_K(double t, double p)
    double S2_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_S2_l_G_r__dewminerals_identifier():
    result = <bytes> S2_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_S2_l_G_r__dewminerals_name():
    result = <bytes> S2_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_S2_l_G_r__dewminerals_formula():
    result = <bytes> S2_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_S2_l_G_r__dewminerals_mw():
    result = S2_l_G_r__dewminerals_mw()
    return result
def cy_S2_l_G_r__dewminerals_elements():
    cdef const double *e = S2_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_S2_l_G_r__dewminerals_g(double t, double p):
    result = S2_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_dgdt(double t, double p):
    result = S2_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_dgdp(double t, double p):
    result = S2_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = S2_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = S2_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = S2_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = S2_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = S2_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = S2_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = S2_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_s(double t, double p):
    result = S2_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_v(double t, double p):
    result = S2_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_cv(double t, double p):
    result = S2_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_cp(double t, double p):
    result = S2_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_dcpdt(double t, double p):
    result = S2_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_alpha(double t, double p):
    result = S2_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_beta(double t, double p):
    result = S2_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_K(double t, double p):
    result = S2_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_S2_l_G_r__dewminerals_Kp(double t, double p):
    result = S2_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "O2_l_G_r__dewminerals_calc.h":
    const char *O2_l_G_r__dewminerals_identifier();
    const char *O2_l_G_r__dewminerals_name();
    const char *O2_l_G_r__dewminerals_formula();
    const double O2_l_G_r__dewminerals_mw();
    const double *O2_l_G_r__dewminerals_elements();
    double O2_l_G_r__dewminerals_g(double t, double p)
    double O2_l_G_r__dewminerals_dgdt(double t, double p)
    double O2_l_G_r__dewminerals_dgdp(double t, double p)
    double O2_l_G_r__dewminerals_d2gdt2(double t, double p)
    double O2_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double O2_l_G_r__dewminerals_d2gdp2(double t, double p)
    double O2_l_G_r__dewminerals_d3gdt3(double t, double p)
    double O2_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double O2_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double O2_l_G_r__dewminerals_d3gdp3(double t, double p)
    double O2_l_G_r__dewminerals_s(double t, double p)
    double O2_l_G_r__dewminerals_v(double t, double p)
    double O2_l_G_r__dewminerals_cv(double t, double p)
    double O2_l_G_r__dewminerals_cp(double t, double p)
    double O2_l_G_r__dewminerals_dcpdt(double t, double p)
    double O2_l_G_r__dewminerals_alpha(double t, double p)
    double O2_l_G_r__dewminerals_beta(double t, double p)
    double O2_l_G_r__dewminerals_K(double t, double p)
    double O2_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_O2_l_G_r__dewminerals_identifier():
    result = <bytes> O2_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_O2_l_G_r__dewminerals_name():
    result = <bytes> O2_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_O2_l_G_r__dewminerals_formula():
    result = <bytes> O2_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_O2_l_G_r__dewminerals_mw():
    result = O2_l_G_r__dewminerals_mw()
    return result
def cy_O2_l_G_r__dewminerals_elements():
    cdef const double *e = O2_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_O2_l_G_r__dewminerals_g(double t, double p):
    result = O2_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_dgdt(double t, double p):
    result = O2_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_dgdp(double t, double p):
    result = O2_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = O2_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = O2_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = O2_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = O2_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = O2_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = O2_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = O2_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_s(double t, double p):
    result = O2_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_v(double t, double p):
    result = O2_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_cv(double t, double p):
    result = O2_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_cp(double t, double p):
    result = O2_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_dcpdt(double t, double p):
    result = O2_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_alpha(double t, double p):
    result = O2_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_beta(double t, double p):
    result = O2_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_K(double t, double p):
    result = O2_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_O2_l_G_r__dewminerals_Kp(double t, double p):
    result = O2_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CO2_l_G_r__dewminerals_calc.h":
    const char *CO2_l_G_r__dewminerals_identifier();
    const char *CO2_l_G_r__dewminerals_name();
    const char *CO2_l_G_r__dewminerals_formula();
    const double CO2_l_G_r__dewminerals_mw();
    const double *CO2_l_G_r__dewminerals_elements();
    double CO2_l_G_r__dewminerals_g(double t, double p)
    double CO2_l_G_r__dewminerals_dgdt(double t, double p)
    double CO2_l_G_r__dewminerals_dgdp(double t, double p)
    double CO2_l_G_r__dewminerals_d2gdt2(double t, double p)
    double CO2_l_G_r__dewminerals_d2gdtdp(double t, double p)
    double CO2_l_G_r__dewminerals_d2gdp2(double t, double p)
    double CO2_l_G_r__dewminerals_d3gdt3(double t, double p)
    double CO2_l_G_r__dewminerals_d3gdt2dp(double t, double p)
    double CO2_l_G_r__dewminerals_d3gdtdp2(double t, double p)
    double CO2_l_G_r__dewminerals_d3gdp3(double t, double p)
    double CO2_l_G_r__dewminerals_s(double t, double p)
    double CO2_l_G_r__dewminerals_v(double t, double p)
    double CO2_l_G_r__dewminerals_cv(double t, double p)
    double CO2_l_G_r__dewminerals_cp(double t, double p)
    double CO2_l_G_r__dewminerals_dcpdt(double t, double p)
    double CO2_l_G_r__dewminerals_alpha(double t, double p)
    double CO2_l_G_r__dewminerals_beta(double t, double p)
    double CO2_l_G_r__dewminerals_K(double t, double p)
    double CO2_l_G_r__dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CO2_l_G_r__dewminerals_identifier():
    result = <bytes> CO2_l_G_r__dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CO2_l_G_r__dewminerals_name():
    result = <bytes> CO2_l_G_r__dewminerals_name()
    return result.decode('UTF-8')
def cy_CO2_l_G_r__dewminerals_formula():
    result = <bytes> CO2_l_G_r__dewminerals_formula()
    return result.decode('UTF-8')
def cy_CO2_l_G_r__dewminerals_mw():
    result = CO2_l_G_r__dewminerals_mw()
    return result
def cy_CO2_l_G_r__dewminerals_elements():
    cdef const double *e = CO2_l_G_r__dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CO2_l_G_r__dewminerals_g(double t, double p):
    result = CO2_l_G_r__dewminerals_g(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_dgdt(double t, double p):
    result = CO2_l_G_r__dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_dgdp(double t, double p):
    result = CO2_l_G_r__dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d2gdt2(double t, double p):
    result = CO2_l_G_r__dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d2gdtdp(double t, double p):
    result = CO2_l_G_r__dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d2gdp2(double t, double p):
    result = CO2_l_G_r__dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d3gdt3(double t, double p):
    result = CO2_l_G_r__dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d3gdt2dp(double t, double p):
    result = CO2_l_G_r__dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d3gdtdp2(double t, double p):
    result = CO2_l_G_r__dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_d3gdp3(double t, double p):
    result = CO2_l_G_r__dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_s(double t, double p):
    result = CO2_l_G_r__dewminerals_s(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_v(double t, double p):
    result = CO2_l_G_r__dewminerals_v(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_cv(double t, double p):
    result = CO2_l_G_r__dewminerals_cv(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_cp(double t, double p):
    result = CO2_l_G_r__dewminerals_cp(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_dcpdt(double t, double p):
    result = CO2_l_G_r__dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_alpha(double t, double p):
    result = CO2_l_G_r__dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_beta(double t, double p):
    result = CO2_l_G_r__dewminerals_beta(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_K(double t, double p):
    result = CO2_l_G_r__dewminerals_K(<double> t, <double> p)
    return result
def cy_CO2_l_G_r__dewminerals_Kp(double t, double p):
    result = CO2_l_G_r__dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "HERCYNITE_dewminerals_calc.h":
    const char *HERCYNITE_dewminerals_identifier();
    const char *HERCYNITE_dewminerals_name();
    const char *HERCYNITE_dewminerals_formula();
    const double HERCYNITE_dewminerals_mw();
    const double *HERCYNITE_dewminerals_elements();
    double HERCYNITE_dewminerals_g(double t, double p)
    double HERCYNITE_dewminerals_dgdt(double t, double p)
    double HERCYNITE_dewminerals_dgdp(double t, double p)
    double HERCYNITE_dewminerals_d2gdt2(double t, double p)
    double HERCYNITE_dewminerals_d2gdtdp(double t, double p)
    double HERCYNITE_dewminerals_d2gdp2(double t, double p)
    double HERCYNITE_dewminerals_d3gdt3(double t, double p)
    double HERCYNITE_dewminerals_d3gdt2dp(double t, double p)
    double HERCYNITE_dewminerals_d3gdtdp2(double t, double p)
    double HERCYNITE_dewminerals_d3gdp3(double t, double p)
    double HERCYNITE_dewminerals_s(double t, double p)
    double HERCYNITE_dewminerals_v(double t, double p)
    double HERCYNITE_dewminerals_cv(double t, double p)
    double HERCYNITE_dewminerals_cp(double t, double p)
    double HERCYNITE_dewminerals_dcpdt(double t, double p)
    double HERCYNITE_dewminerals_alpha(double t, double p)
    double HERCYNITE_dewminerals_beta(double t, double p)
    double HERCYNITE_dewminerals_K(double t, double p)
    double HERCYNITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_HERCYNITE_dewminerals_identifier():
    result = <bytes> HERCYNITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_HERCYNITE_dewminerals_name():
    result = <bytes> HERCYNITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_HERCYNITE_dewminerals_formula():
    result = <bytes> HERCYNITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_HERCYNITE_dewminerals_mw():
    result = HERCYNITE_dewminerals_mw()
    return result
def cy_HERCYNITE_dewminerals_elements():
    cdef const double *e = HERCYNITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_HERCYNITE_dewminerals_g(double t, double p):
    result = HERCYNITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_dgdt(double t, double p):
    result = HERCYNITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_dgdp(double t, double p):
    result = HERCYNITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d2gdt2(double t, double p):
    result = HERCYNITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d2gdtdp(double t, double p):
    result = HERCYNITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d2gdp2(double t, double p):
    result = HERCYNITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d3gdt3(double t, double p):
    result = HERCYNITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d3gdt2dp(double t, double p):
    result = HERCYNITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d3gdtdp2(double t, double p):
    result = HERCYNITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_d3gdp3(double t, double p):
    result = HERCYNITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_s(double t, double p):
    result = HERCYNITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_v(double t, double p):
    result = HERCYNITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_cv(double t, double p):
    result = HERCYNITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_cp(double t, double p):
    result = HERCYNITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_dcpdt(double t, double p):
    result = HERCYNITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_alpha(double t, double p):
    result = HERCYNITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_beta(double t, double p):
    result = HERCYNITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_K(double t, double p):
    result = HERCYNITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_HERCYNITE_dewminerals_Kp(double t, double p):
    result = HERCYNITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ALUNITE_dewminerals_calc.h":
    const char *ALUNITE_dewminerals_identifier();
    const char *ALUNITE_dewminerals_name();
    const char *ALUNITE_dewminerals_formula();
    const double ALUNITE_dewminerals_mw();
    const double *ALUNITE_dewminerals_elements();
    double ALUNITE_dewminerals_g(double t, double p)
    double ALUNITE_dewminerals_dgdt(double t, double p)
    double ALUNITE_dewminerals_dgdp(double t, double p)
    double ALUNITE_dewminerals_d2gdt2(double t, double p)
    double ALUNITE_dewminerals_d2gdtdp(double t, double p)
    double ALUNITE_dewminerals_d2gdp2(double t, double p)
    double ALUNITE_dewminerals_d3gdt3(double t, double p)
    double ALUNITE_dewminerals_d3gdt2dp(double t, double p)
    double ALUNITE_dewminerals_d3gdtdp2(double t, double p)
    double ALUNITE_dewminerals_d3gdp3(double t, double p)
    double ALUNITE_dewminerals_s(double t, double p)
    double ALUNITE_dewminerals_v(double t, double p)
    double ALUNITE_dewminerals_cv(double t, double p)
    double ALUNITE_dewminerals_cp(double t, double p)
    double ALUNITE_dewminerals_dcpdt(double t, double p)
    double ALUNITE_dewminerals_alpha(double t, double p)
    double ALUNITE_dewminerals_beta(double t, double p)
    double ALUNITE_dewminerals_K(double t, double p)
    double ALUNITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ALUNITE_dewminerals_identifier():
    result = <bytes> ALUNITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ALUNITE_dewminerals_name():
    result = <bytes> ALUNITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ALUNITE_dewminerals_formula():
    result = <bytes> ALUNITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ALUNITE_dewminerals_mw():
    result = ALUNITE_dewminerals_mw()
    return result
def cy_ALUNITE_dewminerals_elements():
    cdef const double *e = ALUNITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ALUNITE_dewminerals_g(double t, double p):
    result = ALUNITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_dgdt(double t, double p):
    result = ALUNITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_dgdp(double t, double p):
    result = ALUNITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d2gdt2(double t, double p):
    result = ALUNITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d2gdtdp(double t, double p):
    result = ALUNITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d2gdp2(double t, double p):
    result = ALUNITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d3gdt3(double t, double p):
    result = ALUNITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d3gdt2dp(double t, double p):
    result = ALUNITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d3gdtdp2(double t, double p):
    result = ALUNITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_d3gdp3(double t, double p):
    result = ALUNITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_s(double t, double p):
    result = ALUNITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_v(double t, double p):
    result = ALUNITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_cv(double t, double p):
    result = ALUNITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_cp(double t, double p):
    result = ALUNITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_dcpdt(double t, double p):
    result = ALUNITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_alpha(double t, double p):
    result = ALUNITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_beta(double t, double p):
    result = ALUNITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_K(double t, double p):
    result = ALUNITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ALUNITE_dewminerals_Kp(double t, double p):
    result = ALUNITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CRISTO_BETA_dewminerals_calc.h":
    const char *CRISTO_BETA_dewminerals_identifier();
    const char *CRISTO_BETA_dewminerals_name();
    const char *CRISTO_BETA_dewminerals_formula();
    const double CRISTO_BETA_dewminerals_mw();
    const double *CRISTO_BETA_dewminerals_elements();
    double CRISTO_BETA_dewminerals_g(double t, double p)
    double CRISTO_BETA_dewminerals_dgdt(double t, double p)
    double CRISTO_BETA_dewminerals_dgdp(double t, double p)
    double CRISTO_BETA_dewminerals_d2gdt2(double t, double p)
    double CRISTO_BETA_dewminerals_d2gdtdp(double t, double p)
    double CRISTO_BETA_dewminerals_d2gdp2(double t, double p)
    double CRISTO_BETA_dewminerals_d3gdt3(double t, double p)
    double CRISTO_BETA_dewminerals_d3gdt2dp(double t, double p)
    double CRISTO_BETA_dewminerals_d3gdtdp2(double t, double p)
    double CRISTO_BETA_dewminerals_d3gdp3(double t, double p)
    double CRISTO_BETA_dewminerals_s(double t, double p)
    double CRISTO_BETA_dewminerals_v(double t, double p)
    double CRISTO_BETA_dewminerals_cv(double t, double p)
    double CRISTO_BETA_dewminerals_cp(double t, double p)
    double CRISTO_BETA_dewminerals_dcpdt(double t, double p)
    double CRISTO_BETA_dewminerals_alpha(double t, double p)
    double CRISTO_BETA_dewminerals_beta(double t, double p)
    double CRISTO_BETA_dewminerals_K(double t, double p)
    double CRISTO_BETA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CRISTO_BETA_dewminerals_identifier():
    result = <bytes> CRISTO_BETA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CRISTO_BETA_dewminerals_name():
    result = <bytes> CRISTO_BETA_dewminerals_name()
    return result.decode('UTF-8')
def cy_CRISTO_BETA_dewminerals_formula():
    result = <bytes> CRISTO_BETA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CRISTO_BETA_dewminerals_mw():
    result = CRISTO_BETA_dewminerals_mw()
    return result
def cy_CRISTO_BETA_dewminerals_elements():
    cdef const double *e = CRISTO_BETA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CRISTO_BETA_dewminerals_g(double t, double p):
    result = CRISTO_BETA_dewminerals_g(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_dgdt(double t, double p):
    result = CRISTO_BETA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_dgdp(double t, double p):
    result = CRISTO_BETA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d2gdt2(double t, double p):
    result = CRISTO_BETA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d2gdtdp(double t, double p):
    result = CRISTO_BETA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d2gdp2(double t, double p):
    result = CRISTO_BETA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d3gdt3(double t, double p):
    result = CRISTO_BETA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d3gdt2dp(double t, double p):
    result = CRISTO_BETA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d3gdtdp2(double t, double p):
    result = CRISTO_BETA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_d3gdp3(double t, double p):
    result = CRISTO_BETA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_s(double t, double p):
    result = CRISTO_BETA_dewminerals_s(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_v(double t, double p):
    result = CRISTO_BETA_dewminerals_v(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_cv(double t, double p):
    result = CRISTO_BETA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_cp(double t, double p):
    result = CRISTO_BETA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_dcpdt(double t, double p):
    result = CRISTO_BETA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_alpha(double t, double p):
    result = CRISTO_BETA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_beta(double t, double p):
    result = CRISTO_BETA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_K(double t, double p):
    result = CRISTO_BETA_dewminerals_K(<double> t, <double> p)
    return result
def cy_CRISTO_BETA_dewminerals_Kp(double t, double p):
    result = CRISTO_BETA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CRISTO_ALPHA_dewminerals_calc.h":
    const char *CRISTO_ALPHA_dewminerals_identifier();
    const char *CRISTO_ALPHA_dewminerals_name();
    const char *CRISTO_ALPHA_dewminerals_formula();
    const double CRISTO_ALPHA_dewminerals_mw();
    const double *CRISTO_ALPHA_dewminerals_elements();
    double CRISTO_ALPHA_dewminerals_g(double t, double p)
    double CRISTO_ALPHA_dewminerals_dgdt(double t, double p)
    double CRISTO_ALPHA_dewminerals_dgdp(double t, double p)
    double CRISTO_ALPHA_dewminerals_d2gdt2(double t, double p)
    double CRISTO_ALPHA_dewminerals_d2gdtdp(double t, double p)
    double CRISTO_ALPHA_dewminerals_d2gdp2(double t, double p)
    double CRISTO_ALPHA_dewminerals_d3gdt3(double t, double p)
    double CRISTO_ALPHA_dewminerals_d3gdt2dp(double t, double p)
    double CRISTO_ALPHA_dewminerals_d3gdtdp2(double t, double p)
    double CRISTO_ALPHA_dewminerals_d3gdp3(double t, double p)
    double CRISTO_ALPHA_dewminerals_s(double t, double p)
    double CRISTO_ALPHA_dewminerals_v(double t, double p)
    double CRISTO_ALPHA_dewminerals_cv(double t, double p)
    double CRISTO_ALPHA_dewminerals_cp(double t, double p)
    double CRISTO_ALPHA_dewminerals_dcpdt(double t, double p)
    double CRISTO_ALPHA_dewminerals_alpha(double t, double p)
    double CRISTO_ALPHA_dewminerals_beta(double t, double p)
    double CRISTO_ALPHA_dewminerals_K(double t, double p)
    double CRISTO_ALPHA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CRISTO_ALPHA_dewminerals_identifier():
    result = <bytes> CRISTO_ALPHA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CRISTO_ALPHA_dewminerals_name():
    result = <bytes> CRISTO_ALPHA_dewminerals_name()
    return result.decode('UTF-8')
def cy_CRISTO_ALPHA_dewminerals_formula():
    result = <bytes> CRISTO_ALPHA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CRISTO_ALPHA_dewminerals_mw():
    result = CRISTO_ALPHA_dewminerals_mw()
    return result
def cy_CRISTO_ALPHA_dewminerals_elements():
    cdef const double *e = CRISTO_ALPHA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CRISTO_ALPHA_dewminerals_g(double t, double p):
    result = CRISTO_ALPHA_dewminerals_g(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_dgdt(double t, double p):
    result = CRISTO_ALPHA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_dgdp(double t, double p):
    result = CRISTO_ALPHA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d2gdt2(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d2gdtdp(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d2gdp2(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d3gdt3(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d3gdt2dp(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d3gdtdp2(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_d3gdp3(double t, double p):
    result = CRISTO_ALPHA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_s(double t, double p):
    result = CRISTO_ALPHA_dewminerals_s(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_v(double t, double p):
    result = CRISTO_ALPHA_dewminerals_v(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_cv(double t, double p):
    result = CRISTO_ALPHA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_cp(double t, double p):
    result = CRISTO_ALPHA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_dcpdt(double t, double p):
    result = CRISTO_ALPHA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_alpha(double t, double p):
    result = CRISTO_ALPHA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_beta(double t, double p):
    result = CRISTO_ALPHA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_K(double t, double p):
    result = CRISTO_ALPHA_dewminerals_K(<double> t, <double> p)
    return result
def cy_CRISTO_ALPHA_dewminerals_Kp(double t, double p):
    result = CRISTO_ALPHA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CELESTITE_dewminerals_calc.h":
    const char *CELESTITE_dewminerals_identifier();
    const char *CELESTITE_dewminerals_name();
    const char *CELESTITE_dewminerals_formula();
    const double CELESTITE_dewminerals_mw();
    const double *CELESTITE_dewminerals_elements();
    double CELESTITE_dewminerals_g(double t, double p)
    double CELESTITE_dewminerals_dgdt(double t, double p)
    double CELESTITE_dewminerals_dgdp(double t, double p)
    double CELESTITE_dewminerals_d2gdt2(double t, double p)
    double CELESTITE_dewminerals_d2gdtdp(double t, double p)
    double CELESTITE_dewminerals_d2gdp2(double t, double p)
    double CELESTITE_dewminerals_d3gdt3(double t, double p)
    double CELESTITE_dewminerals_d3gdt2dp(double t, double p)
    double CELESTITE_dewminerals_d3gdtdp2(double t, double p)
    double CELESTITE_dewminerals_d3gdp3(double t, double p)
    double CELESTITE_dewminerals_s(double t, double p)
    double CELESTITE_dewminerals_v(double t, double p)
    double CELESTITE_dewminerals_cv(double t, double p)
    double CELESTITE_dewminerals_cp(double t, double p)
    double CELESTITE_dewminerals_dcpdt(double t, double p)
    double CELESTITE_dewminerals_alpha(double t, double p)
    double CELESTITE_dewminerals_beta(double t, double p)
    double CELESTITE_dewminerals_K(double t, double p)
    double CELESTITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CELESTITE_dewminerals_identifier():
    result = <bytes> CELESTITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CELESTITE_dewminerals_name():
    result = <bytes> CELESTITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CELESTITE_dewminerals_formula():
    result = <bytes> CELESTITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CELESTITE_dewminerals_mw():
    result = CELESTITE_dewminerals_mw()
    return result
def cy_CELESTITE_dewminerals_elements():
    cdef const double *e = CELESTITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CELESTITE_dewminerals_g(double t, double p):
    result = CELESTITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_dgdt(double t, double p):
    result = CELESTITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_dgdp(double t, double p):
    result = CELESTITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d2gdt2(double t, double p):
    result = CELESTITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d2gdtdp(double t, double p):
    result = CELESTITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d2gdp2(double t, double p):
    result = CELESTITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d3gdt3(double t, double p):
    result = CELESTITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d3gdt2dp(double t, double p):
    result = CELESTITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d3gdtdp2(double t, double p):
    result = CELESTITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_d3gdp3(double t, double p):
    result = CELESTITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_s(double t, double p):
    result = CELESTITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_v(double t, double p):
    result = CELESTITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_cv(double t, double p):
    result = CELESTITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_cp(double t, double p):
    result = CELESTITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_dcpdt(double t, double p):
    result = CELESTITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_alpha(double t, double p):
    result = CELESTITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_beta(double t, double p):
    result = CELESTITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_K(double t, double p):
    result = CELESTITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CELESTITE_dewminerals_Kp(double t, double p):
    result = CELESTITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ANHYDRITE_dewminerals_calc.h":
    const char *ANHYDRITE_dewminerals_identifier();
    const char *ANHYDRITE_dewminerals_name();
    const char *ANHYDRITE_dewminerals_formula();
    const double ANHYDRITE_dewminerals_mw();
    const double *ANHYDRITE_dewminerals_elements();
    double ANHYDRITE_dewminerals_g(double t, double p)
    double ANHYDRITE_dewminerals_dgdt(double t, double p)
    double ANHYDRITE_dewminerals_dgdp(double t, double p)
    double ANHYDRITE_dewminerals_d2gdt2(double t, double p)
    double ANHYDRITE_dewminerals_d2gdtdp(double t, double p)
    double ANHYDRITE_dewminerals_d2gdp2(double t, double p)
    double ANHYDRITE_dewminerals_d3gdt3(double t, double p)
    double ANHYDRITE_dewminerals_d3gdt2dp(double t, double p)
    double ANHYDRITE_dewminerals_d3gdtdp2(double t, double p)
    double ANHYDRITE_dewminerals_d3gdp3(double t, double p)
    double ANHYDRITE_dewminerals_s(double t, double p)
    double ANHYDRITE_dewminerals_v(double t, double p)
    double ANHYDRITE_dewminerals_cv(double t, double p)
    double ANHYDRITE_dewminerals_cp(double t, double p)
    double ANHYDRITE_dewminerals_dcpdt(double t, double p)
    double ANHYDRITE_dewminerals_alpha(double t, double p)
    double ANHYDRITE_dewminerals_beta(double t, double p)
    double ANHYDRITE_dewminerals_K(double t, double p)
    double ANHYDRITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ANHYDRITE_dewminerals_identifier():
    result = <bytes> ANHYDRITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ANHYDRITE_dewminerals_name():
    result = <bytes> ANHYDRITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ANHYDRITE_dewminerals_formula():
    result = <bytes> ANHYDRITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ANHYDRITE_dewminerals_mw():
    result = ANHYDRITE_dewminerals_mw()
    return result
def cy_ANHYDRITE_dewminerals_elements():
    cdef const double *e = ANHYDRITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ANHYDRITE_dewminerals_g(double t, double p):
    result = ANHYDRITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_dgdt(double t, double p):
    result = ANHYDRITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_dgdp(double t, double p):
    result = ANHYDRITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d2gdt2(double t, double p):
    result = ANHYDRITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d2gdtdp(double t, double p):
    result = ANHYDRITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d2gdp2(double t, double p):
    result = ANHYDRITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d3gdt3(double t, double p):
    result = ANHYDRITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d3gdt2dp(double t, double p):
    result = ANHYDRITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d3gdtdp2(double t, double p):
    result = ANHYDRITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_d3gdp3(double t, double p):
    result = ANHYDRITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_s(double t, double p):
    result = ANHYDRITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_v(double t, double p):
    result = ANHYDRITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_cv(double t, double p):
    result = ANHYDRITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_cp(double t, double p):
    result = ANHYDRITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_dcpdt(double t, double p):
    result = ANHYDRITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_alpha(double t, double p):
    result = ANHYDRITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_beta(double t, double p):
    result = ANHYDRITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_K(double t, double p):
    result = ANHYDRITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ANHYDRITE_dewminerals_Kp(double t, double p):
    result = ANHYDRITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "STRONTIANITE_dewminerals_calc.h":
    const char *STRONTIANITE_dewminerals_identifier();
    const char *STRONTIANITE_dewminerals_name();
    const char *STRONTIANITE_dewminerals_formula();
    const double STRONTIANITE_dewminerals_mw();
    const double *STRONTIANITE_dewminerals_elements();
    double STRONTIANITE_dewminerals_g(double t, double p)
    double STRONTIANITE_dewminerals_dgdt(double t, double p)
    double STRONTIANITE_dewminerals_dgdp(double t, double p)
    double STRONTIANITE_dewminerals_d2gdt2(double t, double p)
    double STRONTIANITE_dewminerals_d2gdtdp(double t, double p)
    double STRONTIANITE_dewminerals_d2gdp2(double t, double p)
    double STRONTIANITE_dewminerals_d3gdt3(double t, double p)
    double STRONTIANITE_dewminerals_d3gdt2dp(double t, double p)
    double STRONTIANITE_dewminerals_d3gdtdp2(double t, double p)
    double STRONTIANITE_dewminerals_d3gdp3(double t, double p)
    double STRONTIANITE_dewminerals_s(double t, double p)
    double STRONTIANITE_dewminerals_v(double t, double p)
    double STRONTIANITE_dewminerals_cv(double t, double p)
    double STRONTIANITE_dewminerals_cp(double t, double p)
    double STRONTIANITE_dewminerals_dcpdt(double t, double p)
    double STRONTIANITE_dewminerals_alpha(double t, double p)
    double STRONTIANITE_dewminerals_beta(double t, double p)
    double STRONTIANITE_dewminerals_K(double t, double p)
    double STRONTIANITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_STRONTIANITE_dewminerals_identifier():
    result = <bytes> STRONTIANITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_STRONTIANITE_dewminerals_name():
    result = <bytes> STRONTIANITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_STRONTIANITE_dewminerals_formula():
    result = <bytes> STRONTIANITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_STRONTIANITE_dewminerals_mw():
    result = STRONTIANITE_dewminerals_mw()
    return result
def cy_STRONTIANITE_dewminerals_elements():
    cdef const double *e = STRONTIANITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_STRONTIANITE_dewminerals_g(double t, double p):
    result = STRONTIANITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_dgdt(double t, double p):
    result = STRONTIANITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_dgdp(double t, double p):
    result = STRONTIANITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d2gdt2(double t, double p):
    result = STRONTIANITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d2gdtdp(double t, double p):
    result = STRONTIANITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d2gdp2(double t, double p):
    result = STRONTIANITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d3gdt3(double t, double p):
    result = STRONTIANITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d3gdt2dp(double t, double p):
    result = STRONTIANITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d3gdtdp2(double t, double p):
    result = STRONTIANITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_d3gdp3(double t, double p):
    result = STRONTIANITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_s(double t, double p):
    result = STRONTIANITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_v(double t, double p):
    result = STRONTIANITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_cv(double t, double p):
    result = STRONTIANITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_cp(double t, double p):
    result = STRONTIANITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_dcpdt(double t, double p):
    result = STRONTIANITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_alpha(double t, double p):
    result = STRONTIANITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_beta(double t, double p):
    result = STRONTIANITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_K(double t, double p):
    result = STRONTIANITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_STRONTIANITE_dewminerals_Kp(double t, double p):
    result = STRONTIANITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "SYLVITE_dewminerals_calc.h":
    const char *SYLVITE_dewminerals_identifier();
    const char *SYLVITE_dewminerals_name();
    const char *SYLVITE_dewminerals_formula();
    const double SYLVITE_dewminerals_mw();
    const double *SYLVITE_dewminerals_elements();
    double SYLVITE_dewminerals_g(double t, double p)
    double SYLVITE_dewminerals_dgdt(double t, double p)
    double SYLVITE_dewminerals_dgdp(double t, double p)
    double SYLVITE_dewminerals_d2gdt2(double t, double p)
    double SYLVITE_dewminerals_d2gdtdp(double t, double p)
    double SYLVITE_dewminerals_d2gdp2(double t, double p)
    double SYLVITE_dewminerals_d3gdt3(double t, double p)
    double SYLVITE_dewminerals_d3gdt2dp(double t, double p)
    double SYLVITE_dewminerals_d3gdtdp2(double t, double p)
    double SYLVITE_dewminerals_d3gdp3(double t, double p)
    double SYLVITE_dewminerals_s(double t, double p)
    double SYLVITE_dewminerals_v(double t, double p)
    double SYLVITE_dewminerals_cv(double t, double p)
    double SYLVITE_dewminerals_cp(double t, double p)
    double SYLVITE_dewminerals_dcpdt(double t, double p)
    double SYLVITE_dewminerals_alpha(double t, double p)
    double SYLVITE_dewminerals_beta(double t, double p)
    double SYLVITE_dewminerals_K(double t, double p)
    double SYLVITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_SYLVITE_dewminerals_identifier():
    result = <bytes> SYLVITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_SYLVITE_dewminerals_name():
    result = <bytes> SYLVITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_SYLVITE_dewminerals_formula():
    result = <bytes> SYLVITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_SYLVITE_dewminerals_mw():
    result = SYLVITE_dewminerals_mw()
    return result
def cy_SYLVITE_dewminerals_elements():
    cdef const double *e = SYLVITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_SYLVITE_dewminerals_g(double t, double p):
    result = SYLVITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_dgdt(double t, double p):
    result = SYLVITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_dgdp(double t, double p):
    result = SYLVITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d2gdt2(double t, double p):
    result = SYLVITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d2gdtdp(double t, double p):
    result = SYLVITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d2gdp2(double t, double p):
    result = SYLVITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d3gdt3(double t, double p):
    result = SYLVITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d3gdt2dp(double t, double p):
    result = SYLVITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d3gdtdp2(double t, double p):
    result = SYLVITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_d3gdp3(double t, double p):
    result = SYLVITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_s(double t, double p):
    result = SYLVITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_v(double t, double p):
    result = SYLVITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_cv(double t, double p):
    result = SYLVITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_cp(double t, double p):
    result = SYLVITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_dcpdt(double t, double p):
    result = SYLVITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_alpha(double t, double p):
    result = SYLVITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_beta(double t, double p):
    result = SYLVITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_K(double t, double p):
    result = SYLVITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_SYLVITE_dewminerals_Kp(double t, double p):
    result = SYLVITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "HALITE_dewminerals_calc.h":
    const char *HALITE_dewminerals_identifier();
    const char *HALITE_dewminerals_name();
    const char *HALITE_dewminerals_formula();
    const double HALITE_dewminerals_mw();
    const double *HALITE_dewminerals_elements();
    double HALITE_dewminerals_g(double t, double p)
    double HALITE_dewminerals_dgdt(double t, double p)
    double HALITE_dewminerals_dgdp(double t, double p)
    double HALITE_dewminerals_d2gdt2(double t, double p)
    double HALITE_dewminerals_d2gdtdp(double t, double p)
    double HALITE_dewminerals_d2gdp2(double t, double p)
    double HALITE_dewminerals_d3gdt3(double t, double p)
    double HALITE_dewminerals_d3gdt2dp(double t, double p)
    double HALITE_dewminerals_d3gdtdp2(double t, double p)
    double HALITE_dewminerals_d3gdp3(double t, double p)
    double HALITE_dewminerals_s(double t, double p)
    double HALITE_dewminerals_v(double t, double p)
    double HALITE_dewminerals_cv(double t, double p)
    double HALITE_dewminerals_cp(double t, double p)
    double HALITE_dewminerals_dcpdt(double t, double p)
    double HALITE_dewminerals_alpha(double t, double p)
    double HALITE_dewminerals_beta(double t, double p)
    double HALITE_dewminerals_K(double t, double p)
    double HALITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_HALITE_dewminerals_identifier():
    result = <bytes> HALITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_HALITE_dewminerals_name():
    result = <bytes> HALITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_HALITE_dewminerals_formula():
    result = <bytes> HALITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_HALITE_dewminerals_mw():
    result = HALITE_dewminerals_mw()
    return result
def cy_HALITE_dewminerals_elements():
    cdef const double *e = HALITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_HALITE_dewminerals_g(double t, double p):
    result = HALITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_dgdt(double t, double p):
    result = HALITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_dgdp(double t, double p):
    result = HALITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d2gdt2(double t, double p):
    result = HALITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d2gdtdp(double t, double p):
    result = HALITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d2gdp2(double t, double p):
    result = HALITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d3gdt3(double t, double p):
    result = HALITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d3gdt2dp(double t, double p):
    result = HALITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d3gdtdp2(double t, double p):
    result = HALITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_d3gdp3(double t, double p):
    result = HALITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_s(double t, double p):
    result = HALITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_v(double t, double p):
    result = HALITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_cv(double t, double p):
    result = HALITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_cp(double t, double p):
    result = HALITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_dcpdt(double t, double p):
    result = HALITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_alpha(double t, double p):
    result = HALITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_beta(double t, double p):
    result = HALITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_K(double t, double p):
    result = HALITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_HALITE_dewminerals_Kp(double t, double p):
    result = HALITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PYRITE_dewminerals_calc.h":
    const char *PYRITE_dewminerals_identifier();
    const char *PYRITE_dewminerals_name();
    const char *PYRITE_dewminerals_formula();
    const double PYRITE_dewminerals_mw();
    const double *PYRITE_dewminerals_elements();
    double PYRITE_dewminerals_g(double t, double p)
    double PYRITE_dewminerals_dgdt(double t, double p)
    double PYRITE_dewminerals_dgdp(double t, double p)
    double PYRITE_dewminerals_d2gdt2(double t, double p)
    double PYRITE_dewminerals_d2gdtdp(double t, double p)
    double PYRITE_dewminerals_d2gdp2(double t, double p)
    double PYRITE_dewminerals_d3gdt3(double t, double p)
    double PYRITE_dewminerals_d3gdt2dp(double t, double p)
    double PYRITE_dewminerals_d3gdtdp2(double t, double p)
    double PYRITE_dewminerals_d3gdp3(double t, double p)
    double PYRITE_dewminerals_s(double t, double p)
    double PYRITE_dewminerals_v(double t, double p)
    double PYRITE_dewminerals_cv(double t, double p)
    double PYRITE_dewminerals_cp(double t, double p)
    double PYRITE_dewminerals_dcpdt(double t, double p)
    double PYRITE_dewminerals_alpha(double t, double p)
    double PYRITE_dewminerals_beta(double t, double p)
    double PYRITE_dewminerals_K(double t, double p)
    double PYRITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PYRITE_dewminerals_identifier():
    result = <bytes> PYRITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PYRITE_dewminerals_name():
    result = <bytes> PYRITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PYRITE_dewminerals_formula():
    result = <bytes> PYRITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PYRITE_dewminerals_mw():
    result = PYRITE_dewminerals_mw()
    return result
def cy_PYRITE_dewminerals_elements():
    cdef const double *e = PYRITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PYRITE_dewminerals_g(double t, double p):
    result = PYRITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_dgdt(double t, double p):
    result = PYRITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_dgdp(double t, double p):
    result = PYRITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d2gdt2(double t, double p):
    result = PYRITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d2gdtdp(double t, double p):
    result = PYRITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d2gdp2(double t, double p):
    result = PYRITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d3gdt3(double t, double p):
    result = PYRITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d3gdt2dp(double t, double p):
    result = PYRITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d3gdtdp2(double t, double p):
    result = PYRITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_d3gdp3(double t, double p):
    result = PYRITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_s(double t, double p):
    result = PYRITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_v(double t, double p):
    result = PYRITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_cv(double t, double p):
    result = PYRITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_cp(double t, double p):
    result = PYRITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_dcpdt(double t, double p):
    result = PYRITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_alpha(double t, double p):
    result = PYRITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_beta(double t, double p):
    result = PYRITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_K(double t, double p):
    result = PYRITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PYRITE_dewminerals_Kp(double t, double p):
    result = PYRITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PYRRHOTITE_dewminerals_calc.h":
    const char *PYRRHOTITE_dewminerals_identifier();
    const char *PYRRHOTITE_dewminerals_name();
    const char *PYRRHOTITE_dewminerals_formula();
    const double PYRRHOTITE_dewminerals_mw();
    const double *PYRRHOTITE_dewminerals_elements();
    double PYRRHOTITE_dewminerals_g(double t, double p)
    double PYRRHOTITE_dewminerals_dgdt(double t, double p)
    double PYRRHOTITE_dewminerals_dgdp(double t, double p)
    double PYRRHOTITE_dewminerals_d2gdt2(double t, double p)
    double PYRRHOTITE_dewminerals_d2gdtdp(double t, double p)
    double PYRRHOTITE_dewminerals_d2gdp2(double t, double p)
    double PYRRHOTITE_dewminerals_d3gdt3(double t, double p)
    double PYRRHOTITE_dewminerals_d3gdt2dp(double t, double p)
    double PYRRHOTITE_dewminerals_d3gdtdp2(double t, double p)
    double PYRRHOTITE_dewminerals_d3gdp3(double t, double p)
    double PYRRHOTITE_dewminerals_s(double t, double p)
    double PYRRHOTITE_dewminerals_v(double t, double p)
    double PYRRHOTITE_dewminerals_cv(double t, double p)
    double PYRRHOTITE_dewminerals_cp(double t, double p)
    double PYRRHOTITE_dewminerals_dcpdt(double t, double p)
    double PYRRHOTITE_dewminerals_alpha(double t, double p)
    double PYRRHOTITE_dewminerals_beta(double t, double p)
    double PYRRHOTITE_dewminerals_K(double t, double p)
    double PYRRHOTITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PYRRHOTITE_dewminerals_identifier():
    result = <bytes> PYRRHOTITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PYRRHOTITE_dewminerals_name():
    result = <bytes> PYRRHOTITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PYRRHOTITE_dewminerals_formula():
    result = <bytes> PYRRHOTITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PYRRHOTITE_dewminerals_mw():
    result = PYRRHOTITE_dewminerals_mw()
    return result
def cy_PYRRHOTITE_dewminerals_elements():
    cdef const double *e = PYRRHOTITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PYRRHOTITE_dewminerals_g(double t, double p):
    result = PYRRHOTITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_dgdt(double t, double p):
    result = PYRRHOTITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_dgdp(double t, double p):
    result = PYRRHOTITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d2gdt2(double t, double p):
    result = PYRRHOTITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d2gdtdp(double t, double p):
    result = PYRRHOTITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d2gdp2(double t, double p):
    result = PYRRHOTITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d3gdt3(double t, double p):
    result = PYRRHOTITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d3gdt2dp(double t, double p):
    result = PYRRHOTITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d3gdtdp2(double t, double p):
    result = PYRRHOTITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_d3gdp3(double t, double p):
    result = PYRRHOTITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_s(double t, double p):
    result = PYRRHOTITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_v(double t, double p):
    result = PYRRHOTITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_cv(double t, double p):
    result = PYRRHOTITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_cp(double t, double p):
    result = PYRRHOTITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_dcpdt(double t, double p):
    result = PYRRHOTITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_alpha(double t, double p):
    result = PYRRHOTITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_beta(double t, double p):
    result = PYRRHOTITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_K(double t, double p):
    result = PYRRHOTITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PYRRHOTITE_dewminerals_Kp(double t, double p):
    result = PYRRHOTITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "BARITE_dewminerals_calc.h":
    const char *BARITE_dewminerals_identifier();
    const char *BARITE_dewminerals_name();
    const char *BARITE_dewminerals_formula();
    const double BARITE_dewminerals_mw();
    const double *BARITE_dewminerals_elements();
    double BARITE_dewminerals_g(double t, double p)
    double BARITE_dewminerals_dgdt(double t, double p)
    double BARITE_dewminerals_dgdp(double t, double p)
    double BARITE_dewminerals_d2gdt2(double t, double p)
    double BARITE_dewminerals_d2gdtdp(double t, double p)
    double BARITE_dewminerals_d2gdp2(double t, double p)
    double BARITE_dewminerals_d3gdt3(double t, double p)
    double BARITE_dewminerals_d3gdt2dp(double t, double p)
    double BARITE_dewminerals_d3gdtdp2(double t, double p)
    double BARITE_dewminerals_d3gdp3(double t, double p)
    double BARITE_dewminerals_s(double t, double p)
    double BARITE_dewminerals_v(double t, double p)
    double BARITE_dewminerals_cv(double t, double p)
    double BARITE_dewminerals_cp(double t, double p)
    double BARITE_dewminerals_dcpdt(double t, double p)
    double BARITE_dewminerals_alpha(double t, double p)
    double BARITE_dewminerals_beta(double t, double p)
    double BARITE_dewminerals_K(double t, double p)
    double BARITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_BARITE_dewminerals_identifier():
    result = <bytes> BARITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_BARITE_dewminerals_name():
    result = <bytes> BARITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_BARITE_dewminerals_formula():
    result = <bytes> BARITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_BARITE_dewminerals_mw():
    result = BARITE_dewminerals_mw()
    return result
def cy_BARITE_dewminerals_elements():
    cdef const double *e = BARITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_BARITE_dewminerals_g(double t, double p):
    result = BARITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_dgdt(double t, double p):
    result = BARITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_dgdp(double t, double p):
    result = BARITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d2gdt2(double t, double p):
    result = BARITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d2gdtdp(double t, double p):
    result = BARITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d2gdp2(double t, double p):
    result = BARITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d3gdt3(double t, double p):
    result = BARITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d3gdt2dp(double t, double p):
    result = BARITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d3gdtdp2(double t, double p):
    result = BARITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_d3gdp3(double t, double p):
    result = BARITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_s(double t, double p):
    result = BARITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_v(double t, double p):
    result = BARITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_cv(double t, double p):
    result = BARITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_cp(double t, double p):
    result = BARITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_dcpdt(double t, double p):
    result = BARITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_alpha(double t, double p):
    result = BARITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_beta(double t, double p):
    result = BARITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_K(double t, double p):
    result = BARITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_BARITE_dewminerals_Kp(double t, double p):
    result = BARITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "GRAPHITE_dewminerals_calc.h":
    const char *GRAPHITE_dewminerals_identifier();
    const char *GRAPHITE_dewminerals_name();
    const char *GRAPHITE_dewminerals_formula();
    const double GRAPHITE_dewminerals_mw();
    const double *GRAPHITE_dewminerals_elements();
    double GRAPHITE_dewminerals_g(double t, double p)
    double GRAPHITE_dewminerals_dgdt(double t, double p)
    double GRAPHITE_dewminerals_dgdp(double t, double p)
    double GRAPHITE_dewminerals_d2gdt2(double t, double p)
    double GRAPHITE_dewminerals_d2gdtdp(double t, double p)
    double GRAPHITE_dewminerals_d2gdp2(double t, double p)
    double GRAPHITE_dewminerals_d3gdt3(double t, double p)
    double GRAPHITE_dewminerals_d3gdt2dp(double t, double p)
    double GRAPHITE_dewminerals_d3gdtdp2(double t, double p)
    double GRAPHITE_dewminerals_d3gdp3(double t, double p)
    double GRAPHITE_dewminerals_s(double t, double p)
    double GRAPHITE_dewminerals_v(double t, double p)
    double GRAPHITE_dewminerals_cv(double t, double p)
    double GRAPHITE_dewminerals_cp(double t, double p)
    double GRAPHITE_dewminerals_dcpdt(double t, double p)
    double GRAPHITE_dewminerals_alpha(double t, double p)
    double GRAPHITE_dewminerals_beta(double t, double p)
    double GRAPHITE_dewminerals_K(double t, double p)
    double GRAPHITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_GRAPHITE_dewminerals_identifier():
    result = <bytes> GRAPHITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_GRAPHITE_dewminerals_name():
    result = <bytes> GRAPHITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_GRAPHITE_dewminerals_formula():
    result = <bytes> GRAPHITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_GRAPHITE_dewminerals_mw():
    result = GRAPHITE_dewminerals_mw()
    return result
def cy_GRAPHITE_dewminerals_elements():
    cdef const double *e = GRAPHITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_GRAPHITE_dewminerals_g(double t, double p):
    result = GRAPHITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_dgdt(double t, double p):
    result = GRAPHITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_dgdp(double t, double p):
    result = GRAPHITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d2gdt2(double t, double p):
    result = GRAPHITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d2gdtdp(double t, double p):
    result = GRAPHITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d2gdp2(double t, double p):
    result = GRAPHITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d3gdt3(double t, double p):
    result = GRAPHITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d3gdt2dp(double t, double p):
    result = GRAPHITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d3gdtdp2(double t, double p):
    result = GRAPHITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_d3gdp3(double t, double p):
    result = GRAPHITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_s(double t, double p):
    result = GRAPHITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_v(double t, double p):
    result = GRAPHITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_cv(double t, double p):
    result = GRAPHITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_cp(double t, double p):
    result = GRAPHITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_dcpdt(double t, double p):
    result = GRAPHITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_alpha(double t, double p):
    result = GRAPHITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_beta(double t, double p):
    result = GRAPHITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_K(double t, double p):
    result = GRAPHITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_GRAPHITE_dewminerals_Kp(double t, double p):
    result = GRAPHITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "IRON_GAMMA_dewminerals_calc.h":
    const char *IRON_GAMMA_dewminerals_identifier();
    const char *IRON_GAMMA_dewminerals_name();
    const char *IRON_GAMMA_dewminerals_formula();
    const double IRON_GAMMA_dewminerals_mw();
    const double *IRON_GAMMA_dewminerals_elements();
    double IRON_GAMMA_dewminerals_g(double t, double p)
    double IRON_GAMMA_dewminerals_dgdt(double t, double p)
    double IRON_GAMMA_dewminerals_dgdp(double t, double p)
    double IRON_GAMMA_dewminerals_d2gdt2(double t, double p)
    double IRON_GAMMA_dewminerals_d2gdtdp(double t, double p)
    double IRON_GAMMA_dewminerals_d2gdp2(double t, double p)
    double IRON_GAMMA_dewminerals_d3gdt3(double t, double p)
    double IRON_GAMMA_dewminerals_d3gdt2dp(double t, double p)
    double IRON_GAMMA_dewminerals_d3gdtdp2(double t, double p)
    double IRON_GAMMA_dewminerals_d3gdp3(double t, double p)
    double IRON_GAMMA_dewminerals_s(double t, double p)
    double IRON_GAMMA_dewminerals_v(double t, double p)
    double IRON_GAMMA_dewminerals_cv(double t, double p)
    double IRON_GAMMA_dewminerals_cp(double t, double p)
    double IRON_GAMMA_dewminerals_dcpdt(double t, double p)
    double IRON_GAMMA_dewminerals_alpha(double t, double p)
    double IRON_GAMMA_dewminerals_beta(double t, double p)
    double IRON_GAMMA_dewminerals_K(double t, double p)
    double IRON_GAMMA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_IRON_GAMMA_dewminerals_identifier():
    result = <bytes> IRON_GAMMA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_IRON_GAMMA_dewminerals_name():
    result = <bytes> IRON_GAMMA_dewminerals_name()
    return result.decode('UTF-8')
def cy_IRON_GAMMA_dewminerals_formula():
    result = <bytes> IRON_GAMMA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_IRON_GAMMA_dewminerals_mw():
    result = IRON_GAMMA_dewminerals_mw()
    return result
def cy_IRON_GAMMA_dewminerals_elements():
    cdef const double *e = IRON_GAMMA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_IRON_GAMMA_dewminerals_g(double t, double p):
    result = IRON_GAMMA_dewminerals_g(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_dgdt(double t, double p):
    result = IRON_GAMMA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_dgdp(double t, double p):
    result = IRON_GAMMA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d2gdt2(double t, double p):
    result = IRON_GAMMA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d2gdtdp(double t, double p):
    result = IRON_GAMMA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d2gdp2(double t, double p):
    result = IRON_GAMMA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d3gdt3(double t, double p):
    result = IRON_GAMMA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d3gdt2dp(double t, double p):
    result = IRON_GAMMA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d3gdtdp2(double t, double p):
    result = IRON_GAMMA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_d3gdp3(double t, double p):
    result = IRON_GAMMA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_s(double t, double p):
    result = IRON_GAMMA_dewminerals_s(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_v(double t, double p):
    result = IRON_GAMMA_dewminerals_v(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_cv(double t, double p):
    result = IRON_GAMMA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_cp(double t, double p):
    result = IRON_GAMMA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_dcpdt(double t, double p):
    result = IRON_GAMMA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_alpha(double t, double p):
    result = IRON_GAMMA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_beta(double t, double p):
    result = IRON_GAMMA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_K(double t, double p):
    result = IRON_GAMMA_dewminerals_K(<double> t, <double> p)
    return result
def cy_IRON_GAMMA_dewminerals_Kp(double t, double p):
    result = IRON_GAMMA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "IRON_ALPHA_dewminerals_calc.h":
    const char *IRON_ALPHA_dewminerals_identifier();
    const char *IRON_ALPHA_dewminerals_name();
    const char *IRON_ALPHA_dewminerals_formula();
    const double IRON_ALPHA_dewminerals_mw();
    const double *IRON_ALPHA_dewminerals_elements();
    double IRON_ALPHA_dewminerals_g(double t, double p)
    double IRON_ALPHA_dewminerals_dgdt(double t, double p)
    double IRON_ALPHA_dewminerals_dgdp(double t, double p)
    double IRON_ALPHA_dewminerals_d2gdt2(double t, double p)
    double IRON_ALPHA_dewminerals_d2gdtdp(double t, double p)
    double IRON_ALPHA_dewminerals_d2gdp2(double t, double p)
    double IRON_ALPHA_dewminerals_d3gdt3(double t, double p)
    double IRON_ALPHA_dewminerals_d3gdt2dp(double t, double p)
    double IRON_ALPHA_dewminerals_d3gdtdp2(double t, double p)
    double IRON_ALPHA_dewminerals_d3gdp3(double t, double p)
    double IRON_ALPHA_dewminerals_s(double t, double p)
    double IRON_ALPHA_dewminerals_v(double t, double p)
    double IRON_ALPHA_dewminerals_cv(double t, double p)
    double IRON_ALPHA_dewminerals_cp(double t, double p)
    double IRON_ALPHA_dewminerals_dcpdt(double t, double p)
    double IRON_ALPHA_dewminerals_alpha(double t, double p)
    double IRON_ALPHA_dewminerals_beta(double t, double p)
    double IRON_ALPHA_dewminerals_K(double t, double p)
    double IRON_ALPHA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_IRON_ALPHA_dewminerals_identifier():
    result = <bytes> IRON_ALPHA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_IRON_ALPHA_dewminerals_name():
    result = <bytes> IRON_ALPHA_dewminerals_name()
    return result.decode('UTF-8')
def cy_IRON_ALPHA_dewminerals_formula():
    result = <bytes> IRON_ALPHA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_IRON_ALPHA_dewminerals_mw():
    result = IRON_ALPHA_dewminerals_mw()
    return result
def cy_IRON_ALPHA_dewminerals_elements():
    cdef const double *e = IRON_ALPHA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_IRON_ALPHA_dewminerals_g(double t, double p):
    result = IRON_ALPHA_dewminerals_g(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_dgdt(double t, double p):
    result = IRON_ALPHA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_dgdp(double t, double p):
    result = IRON_ALPHA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d2gdt2(double t, double p):
    result = IRON_ALPHA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d2gdtdp(double t, double p):
    result = IRON_ALPHA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d2gdp2(double t, double p):
    result = IRON_ALPHA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d3gdt3(double t, double p):
    result = IRON_ALPHA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d3gdt2dp(double t, double p):
    result = IRON_ALPHA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d3gdtdp2(double t, double p):
    result = IRON_ALPHA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_d3gdp3(double t, double p):
    result = IRON_ALPHA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_s(double t, double p):
    result = IRON_ALPHA_dewminerals_s(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_v(double t, double p):
    result = IRON_ALPHA_dewminerals_v(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_cv(double t, double p):
    result = IRON_ALPHA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_cp(double t, double p):
    result = IRON_ALPHA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_dcpdt(double t, double p):
    result = IRON_ALPHA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_alpha(double t, double p):
    result = IRON_ALPHA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_beta(double t, double p):
    result = IRON_ALPHA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_K(double t, double p):
    result = IRON_ALPHA_dewminerals_K(<double> t, <double> p)
    return result
def cy_IRON_ALPHA_dewminerals_Kp(double t, double p):
    result = IRON_ALPHA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "COESITE_dewminerals_calc.h":
    const char *COESITE_dewminerals_identifier();
    const char *COESITE_dewminerals_name();
    const char *COESITE_dewminerals_formula();
    const double COESITE_dewminerals_mw();
    const double *COESITE_dewminerals_elements();
    double COESITE_dewminerals_g(double t, double p)
    double COESITE_dewminerals_dgdt(double t, double p)
    double COESITE_dewminerals_dgdp(double t, double p)
    double COESITE_dewminerals_d2gdt2(double t, double p)
    double COESITE_dewminerals_d2gdtdp(double t, double p)
    double COESITE_dewminerals_d2gdp2(double t, double p)
    double COESITE_dewminerals_d3gdt3(double t, double p)
    double COESITE_dewminerals_d3gdt2dp(double t, double p)
    double COESITE_dewminerals_d3gdtdp2(double t, double p)
    double COESITE_dewminerals_d3gdp3(double t, double p)
    double COESITE_dewminerals_s(double t, double p)
    double COESITE_dewminerals_v(double t, double p)
    double COESITE_dewminerals_cv(double t, double p)
    double COESITE_dewminerals_cp(double t, double p)
    double COESITE_dewminerals_dcpdt(double t, double p)
    double COESITE_dewminerals_alpha(double t, double p)
    double COESITE_dewminerals_beta(double t, double p)
    double COESITE_dewminerals_K(double t, double p)
    double COESITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_COESITE_dewminerals_identifier():
    result = <bytes> COESITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_COESITE_dewminerals_name():
    result = <bytes> COESITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_COESITE_dewminerals_formula():
    result = <bytes> COESITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_COESITE_dewminerals_mw():
    result = COESITE_dewminerals_mw()
    return result
def cy_COESITE_dewminerals_elements():
    cdef const double *e = COESITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_COESITE_dewminerals_g(double t, double p):
    result = COESITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_dgdt(double t, double p):
    result = COESITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_dgdp(double t, double p):
    result = COESITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d2gdt2(double t, double p):
    result = COESITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d2gdtdp(double t, double p):
    result = COESITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d2gdp2(double t, double p):
    result = COESITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d3gdt3(double t, double p):
    result = COESITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d3gdt2dp(double t, double p):
    result = COESITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d3gdtdp2(double t, double p):
    result = COESITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_d3gdp3(double t, double p):
    result = COESITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_s(double t, double p):
    result = COESITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_v(double t, double p):
    result = COESITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_cv(double t, double p):
    result = COESITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_cp(double t, double p):
    result = COESITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_dcpdt(double t, double p):
    result = COESITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_alpha(double t, double p):
    result = COESITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_beta(double t, double p):
    result = COESITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_K(double t, double p):
    result = COESITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_COESITE_dewminerals_Kp(double t, double p):
    result = COESITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "QUARTZ_BETA_dewminerals_calc.h":
    const char *QUARTZ_BETA_dewminerals_identifier();
    const char *QUARTZ_BETA_dewminerals_name();
    const char *QUARTZ_BETA_dewminerals_formula();
    const double QUARTZ_BETA_dewminerals_mw();
    const double *QUARTZ_BETA_dewminerals_elements();
    double QUARTZ_BETA_dewminerals_g(double t, double p)
    double QUARTZ_BETA_dewminerals_dgdt(double t, double p)
    double QUARTZ_BETA_dewminerals_dgdp(double t, double p)
    double QUARTZ_BETA_dewminerals_d2gdt2(double t, double p)
    double QUARTZ_BETA_dewminerals_d2gdtdp(double t, double p)
    double QUARTZ_BETA_dewminerals_d2gdp2(double t, double p)
    double QUARTZ_BETA_dewminerals_d3gdt3(double t, double p)
    double QUARTZ_BETA_dewminerals_d3gdt2dp(double t, double p)
    double QUARTZ_BETA_dewminerals_d3gdtdp2(double t, double p)
    double QUARTZ_BETA_dewminerals_d3gdp3(double t, double p)
    double QUARTZ_BETA_dewminerals_s(double t, double p)
    double QUARTZ_BETA_dewminerals_v(double t, double p)
    double QUARTZ_BETA_dewminerals_cv(double t, double p)
    double QUARTZ_BETA_dewminerals_cp(double t, double p)
    double QUARTZ_BETA_dewminerals_dcpdt(double t, double p)
    double QUARTZ_BETA_dewminerals_alpha(double t, double p)
    double QUARTZ_BETA_dewminerals_beta(double t, double p)
    double QUARTZ_BETA_dewminerals_K(double t, double p)
    double QUARTZ_BETA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_QUARTZ_BETA_dewminerals_identifier():
    result = <bytes> QUARTZ_BETA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_QUARTZ_BETA_dewminerals_name():
    result = <bytes> QUARTZ_BETA_dewminerals_name()
    return result.decode('UTF-8')
def cy_QUARTZ_BETA_dewminerals_formula():
    result = <bytes> QUARTZ_BETA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_QUARTZ_BETA_dewminerals_mw():
    result = QUARTZ_BETA_dewminerals_mw()
    return result
def cy_QUARTZ_BETA_dewminerals_elements():
    cdef const double *e = QUARTZ_BETA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_QUARTZ_BETA_dewminerals_g(double t, double p):
    result = QUARTZ_BETA_dewminerals_g(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_dgdt(double t, double p):
    result = QUARTZ_BETA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_dgdp(double t, double p):
    result = QUARTZ_BETA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d2gdt2(double t, double p):
    result = QUARTZ_BETA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d2gdtdp(double t, double p):
    result = QUARTZ_BETA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d2gdp2(double t, double p):
    result = QUARTZ_BETA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d3gdt3(double t, double p):
    result = QUARTZ_BETA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d3gdt2dp(double t, double p):
    result = QUARTZ_BETA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d3gdtdp2(double t, double p):
    result = QUARTZ_BETA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_d3gdp3(double t, double p):
    result = QUARTZ_BETA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_s(double t, double p):
    result = QUARTZ_BETA_dewminerals_s(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_v(double t, double p):
    result = QUARTZ_BETA_dewminerals_v(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_cv(double t, double p):
    result = QUARTZ_BETA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_cp(double t, double p):
    result = QUARTZ_BETA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_dcpdt(double t, double p):
    result = QUARTZ_BETA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_alpha(double t, double p):
    result = QUARTZ_BETA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_beta(double t, double p):
    result = QUARTZ_BETA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_K(double t, double p):
    result = QUARTZ_BETA_dewminerals_K(<double> t, <double> p)
    return result
def cy_QUARTZ_BETA_dewminerals_Kp(double t, double p):
    result = QUARTZ_BETA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "QUARTZ_ALPHA_dewminerals_calc.h":
    const char *QUARTZ_ALPHA_dewminerals_identifier();
    const char *QUARTZ_ALPHA_dewminerals_name();
    const char *QUARTZ_ALPHA_dewminerals_formula();
    const double QUARTZ_ALPHA_dewminerals_mw();
    const double *QUARTZ_ALPHA_dewminerals_elements();
    double QUARTZ_ALPHA_dewminerals_g(double t, double p)
    double QUARTZ_ALPHA_dewminerals_dgdt(double t, double p)
    double QUARTZ_ALPHA_dewminerals_dgdp(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d2gdt2(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d2gdtdp(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d2gdp2(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d3gdt3(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d3gdt2dp(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d3gdtdp2(double t, double p)
    double QUARTZ_ALPHA_dewminerals_d3gdp3(double t, double p)
    double QUARTZ_ALPHA_dewminerals_s(double t, double p)
    double QUARTZ_ALPHA_dewminerals_v(double t, double p)
    double QUARTZ_ALPHA_dewminerals_cv(double t, double p)
    double QUARTZ_ALPHA_dewminerals_cp(double t, double p)
    double QUARTZ_ALPHA_dewminerals_dcpdt(double t, double p)
    double QUARTZ_ALPHA_dewminerals_alpha(double t, double p)
    double QUARTZ_ALPHA_dewminerals_beta(double t, double p)
    double QUARTZ_ALPHA_dewminerals_K(double t, double p)
    double QUARTZ_ALPHA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_QUARTZ_ALPHA_dewminerals_identifier():
    result = <bytes> QUARTZ_ALPHA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_QUARTZ_ALPHA_dewminerals_name():
    result = <bytes> QUARTZ_ALPHA_dewminerals_name()
    return result.decode('UTF-8')
def cy_QUARTZ_ALPHA_dewminerals_formula():
    result = <bytes> QUARTZ_ALPHA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_QUARTZ_ALPHA_dewminerals_mw():
    result = QUARTZ_ALPHA_dewminerals_mw()
    return result
def cy_QUARTZ_ALPHA_dewminerals_elements():
    cdef const double *e = QUARTZ_ALPHA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_QUARTZ_ALPHA_dewminerals_g(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_g(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_dgdt(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_dgdp(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d2gdt2(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d2gdtdp(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d2gdp2(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d3gdt3(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d3gdt2dp(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d3gdtdp2(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_d3gdp3(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_s(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_s(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_v(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_v(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_cv(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_cp(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_dcpdt(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_alpha(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_beta(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_K(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_K(<double> t, <double> p)
    return result
def cy_QUARTZ_ALPHA_dewminerals_Kp(double t, double p):
    result = QUARTZ_ALPHA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MEIONITE_dewminerals_calc.h":
    const char *MEIONITE_dewminerals_identifier();
    const char *MEIONITE_dewminerals_name();
    const char *MEIONITE_dewminerals_formula();
    const double MEIONITE_dewminerals_mw();
    const double *MEIONITE_dewminerals_elements();
    double MEIONITE_dewminerals_g(double t, double p)
    double MEIONITE_dewminerals_dgdt(double t, double p)
    double MEIONITE_dewminerals_dgdp(double t, double p)
    double MEIONITE_dewminerals_d2gdt2(double t, double p)
    double MEIONITE_dewminerals_d2gdtdp(double t, double p)
    double MEIONITE_dewminerals_d2gdp2(double t, double p)
    double MEIONITE_dewminerals_d3gdt3(double t, double p)
    double MEIONITE_dewminerals_d3gdt2dp(double t, double p)
    double MEIONITE_dewminerals_d3gdtdp2(double t, double p)
    double MEIONITE_dewminerals_d3gdp3(double t, double p)
    double MEIONITE_dewminerals_s(double t, double p)
    double MEIONITE_dewminerals_v(double t, double p)
    double MEIONITE_dewminerals_cv(double t, double p)
    double MEIONITE_dewminerals_cp(double t, double p)
    double MEIONITE_dewminerals_dcpdt(double t, double p)
    double MEIONITE_dewminerals_alpha(double t, double p)
    double MEIONITE_dewminerals_beta(double t, double p)
    double MEIONITE_dewminerals_K(double t, double p)
    double MEIONITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MEIONITE_dewminerals_identifier():
    result = <bytes> MEIONITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MEIONITE_dewminerals_name():
    result = <bytes> MEIONITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MEIONITE_dewminerals_formula():
    result = <bytes> MEIONITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MEIONITE_dewminerals_mw():
    result = MEIONITE_dewminerals_mw()
    return result
def cy_MEIONITE_dewminerals_elements():
    cdef const double *e = MEIONITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MEIONITE_dewminerals_g(double t, double p):
    result = MEIONITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_dgdt(double t, double p):
    result = MEIONITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_dgdp(double t, double p):
    result = MEIONITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d2gdt2(double t, double p):
    result = MEIONITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d2gdtdp(double t, double p):
    result = MEIONITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d2gdp2(double t, double p):
    result = MEIONITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d3gdt3(double t, double p):
    result = MEIONITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d3gdt2dp(double t, double p):
    result = MEIONITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d3gdtdp2(double t, double p):
    result = MEIONITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_d3gdp3(double t, double p):
    result = MEIONITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_s(double t, double p):
    result = MEIONITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_v(double t, double p):
    result = MEIONITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_cv(double t, double p):
    result = MEIONITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_cp(double t, double p):
    result = MEIONITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_dcpdt(double t, double p):
    result = MEIONITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_alpha(double t, double p):
    result = MEIONITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_beta(double t, double p):
    result = MEIONITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_K(double t, double p):
    result = MEIONITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MEIONITE_dewminerals_Kp(double t, double p):
    result = MEIONITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "GROSSULAR_dewminerals_calc.h":
    const char *GROSSULAR_dewminerals_identifier();
    const char *GROSSULAR_dewminerals_name();
    const char *GROSSULAR_dewminerals_formula();
    const double GROSSULAR_dewminerals_mw();
    const double *GROSSULAR_dewminerals_elements();
    double GROSSULAR_dewminerals_g(double t, double p)
    double GROSSULAR_dewminerals_dgdt(double t, double p)
    double GROSSULAR_dewminerals_dgdp(double t, double p)
    double GROSSULAR_dewminerals_d2gdt2(double t, double p)
    double GROSSULAR_dewminerals_d2gdtdp(double t, double p)
    double GROSSULAR_dewminerals_d2gdp2(double t, double p)
    double GROSSULAR_dewminerals_d3gdt3(double t, double p)
    double GROSSULAR_dewminerals_d3gdt2dp(double t, double p)
    double GROSSULAR_dewminerals_d3gdtdp2(double t, double p)
    double GROSSULAR_dewminerals_d3gdp3(double t, double p)
    double GROSSULAR_dewminerals_s(double t, double p)
    double GROSSULAR_dewminerals_v(double t, double p)
    double GROSSULAR_dewminerals_cv(double t, double p)
    double GROSSULAR_dewminerals_cp(double t, double p)
    double GROSSULAR_dewminerals_dcpdt(double t, double p)
    double GROSSULAR_dewminerals_alpha(double t, double p)
    double GROSSULAR_dewminerals_beta(double t, double p)
    double GROSSULAR_dewminerals_K(double t, double p)
    double GROSSULAR_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_GROSSULAR_dewminerals_identifier():
    result = <bytes> GROSSULAR_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_GROSSULAR_dewminerals_name():
    result = <bytes> GROSSULAR_dewminerals_name()
    return result.decode('UTF-8')
def cy_GROSSULAR_dewminerals_formula():
    result = <bytes> GROSSULAR_dewminerals_formula()
    return result.decode('UTF-8')
def cy_GROSSULAR_dewminerals_mw():
    result = GROSSULAR_dewminerals_mw()
    return result
def cy_GROSSULAR_dewminerals_elements():
    cdef const double *e = GROSSULAR_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_GROSSULAR_dewminerals_g(double t, double p):
    result = GROSSULAR_dewminerals_g(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_dgdt(double t, double p):
    result = GROSSULAR_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_dgdp(double t, double p):
    result = GROSSULAR_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d2gdt2(double t, double p):
    result = GROSSULAR_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d2gdtdp(double t, double p):
    result = GROSSULAR_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d2gdp2(double t, double p):
    result = GROSSULAR_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d3gdt3(double t, double p):
    result = GROSSULAR_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d3gdt2dp(double t, double p):
    result = GROSSULAR_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d3gdtdp2(double t, double p):
    result = GROSSULAR_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_d3gdp3(double t, double p):
    result = GROSSULAR_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_s(double t, double p):
    result = GROSSULAR_dewminerals_s(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_v(double t, double p):
    result = GROSSULAR_dewminerals_v(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_cv(double t, double p):
    result = GROSSULAR_dewminerals_cv(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_cp(double t, double p):
    result = GROSSULAR_dewminerals_cp(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_dcpdt(double t, double p):
    result = GROSSULAR_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_alpha(double t, double p):
    result = GROSSULAR_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_beta(double t, double p):
    result = GROSSULAR_dewminerals_beta(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_K(double t, double p):
    result = GROSSULAR_dewminerals_K(<double> t, <double> p)
    return result
def cy_GROSSULAR_dewminerals_Kp(double t, double p):
    result = GROSSULAR_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ALMANDINE_dewminerals_calc.h":
    const char *ALMANDINE_dewminerals_identifier();
    const char *ALMANDINE_dewminerals_name();
    const char *ALMANDINE_dewminerals_formula();
    const double ALMANDINE_dewminerals_mw();
    const double *ALMANDINE_dewminerals_elements();
    double ALMANDINE_dewminerals_g(double t, double p)
    double ALMANDINE_dewminerals_dgdt(double t, double p)
    double ALMANDINE_dewminerals_dgdp(double t, double p)
    double ALMANDINE_dewminerals_d2gdt2(double t, double p)
    double ALMANDINE_dewminerals_d2gdtdp(double t, double p)
    double ALMANDINE_dewminerals_d2gdp2(double t, double p)
    double ALMANDINE_dewminerals_d3gdt3(double t, double p)
    double ALMANDINE_dewminerals_d3gdt2dp(double t, double p)
    double ALMANDINE_dewminerals_d3gdtdp2(double t, double p)
    double ALMANDINE_dewminerals_d3gdp3(double t, double p)
    double ALMANDINE_dewminerals_s(double t, double p)
    double ALMANDINE_dewminerals_v(double t, double p)
    double ALMANDINE_dewminerals_cv(double t, double p)
    double ALMANDINE_dewminerals_cp(double t, double p)
    double ALMANDINE_dewminerals_dcpdt(double t, double p)
    double ALMANDINE_dewminerals_alpha(double t, double p)
    double ALMANDINE_dewminerals_beta(double t, double p)
    double ALMANDINE_dewminerals_K(double t, double p)
    double ALMANDINE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ALMANDINE_dewminerals_identifier():
    result = <bytes> ALMANDINE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ALMANDINE_dewminerals_name():
    result = <bytes> ALMANDINE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ALMANDINE_dewminerals_formula():
    result = <bytes> ALMANDINE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ALMANDINE_dewminerals_mw():
    result = ALMANDINE_dewminerals_mw()
    return result
def cy_ALMANDINE_dewminerals_elements():
    cdef const double *e = ALMANDINE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ALMANDINE_dewminerals_g(double t, double p):
    result = ALMANDINE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_dgdt(double t, double p):
    result = ALMANDINE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_dgdp(double t, double p):
    result = ALMANDINE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d2gdt2(double t, double p):
    result = ALMANDINE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d2gdtdp(double t, double p):
    result = ALMANDINE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d2gdp2(double t, double p):
    result = ALMANDINE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d3gdt3(double t, double p):
    result = ALMANDINE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d3gdt2dp(double t, double p):
    result = ALMANDINE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d3gdtdp2(double t, double p):
    result = ALMANDINE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_d3gdp3(double t, double p):
    result = ALMANDINE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_s(double t, double p):
    result = ALMANDINE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_v(double t, double p):
    result = ALMANDINE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_cv(double t, double p):
    result = ALMANDINE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_cp(double t, double p):
    result = ALMANDINE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_dcpdt(double t, double p):
    result = ALMANDINE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_alpha(double t, double p):
    result = ALMANDINE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_beta(double t, double p):
    result = ALMANDINE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_K(double t, double p):
    result = ALMANDINE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ALMANDINE_dewminerals_Kp(double t, double p):
    result = ALMANDINE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PYROPE_dewminerals_calc.h":
    const char *PYROPE_dewminerals_identifier();
    const char *PYROPE_dewminerals_name();
    const char *PYROPE_dewminerals_formula();
    const double PYROPE_dewminerals_mw();
    const double *PYROPE_dewminerals_elements();
    double PYROPE_dewminerals_g(double t, double p)
    double PYROPE_dewminerals_dgdt(double t, double p)
    double PYROPE_dewminerals_dgdp(double t, double p)
    double PYROPE_dewminerals_d2gdt2(double t, double p)
    double PYROPE_dewminerals_d2gdtdp(double t, double p)
    double PYROPE_dewminerals_d2gdp2(double t, double p)
    double PYROPE_dewminerals_d3gdt3(double t, double p)
    double PYROPE_dewminerals_d3gdt2dp(double t, double p)
    double PYROPE_dewminerals_d3gdtdp2(double t, double p)
    double PYROPE_dewminerals_d3gdp3(double t, double p)
    double PYROPE_dewminerals_s(double t, double p)
    double PYROPE_dewminerals_v(double t, double p)
    double PYROPE_dewminerals_cv(double t, double p)
    double PYROPE_dewminerals_cp(double t, double p)
    double PYROPE_dewminerals_dcpdt(double t, double p)
    double PYROPE_dewminerals_alpha(double t, double p)
    double PYROPE_dewminerals_beta(double t, double p)
    double PYROPE_dewminerals_K(double t, double p)
    double PYROPE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PYROPE_dewminerals_identifier():
    result = <bytes> PYROPE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PYROPE_dewminerals_name():
    result = <bytes> PYROPE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PYROPE_dewminerals_formula():
    result = <bytes> PYROPE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PYROPE_dewminerals_mw():
    result = PYROPE_dewminerals_mw()
    return result
def cy_PYROPE_dewminerals_elements():
    cdef const double *e = PYROPE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PYROPE_dewminerals_g(double t, double p):
    result = PYROPE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_dgdt(double t, double p):
    result = PYROPE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_dgdp(double t, double p):
    result = PYROPE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d2gdt2(double t, double p):
    result = PYROPE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d2gdtdp(double t, double p):
    result = PYROPE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d2gdp2(double t, double p):
    result = PYROPE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d3gdt3(double t, double p):
    result = PYROPE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d3gdt2dp(double t, double p):
    result = PYROPE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d3gdtdp2(double t, double p):
    result = PYROPE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_d3gdp3(double t, double p):
    result = PYROPE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_s(double t, double p):
    result = PYROPE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_v(double t, double p):
    result = PYROPE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_cv(double t, double p):
    result = PYROPE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_cp(double t, double p):
    result = PYROPE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_dcpdt(double t, double p):
    result = PYROPE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_alpha(double t, double p):
    result = PYROPE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_beta(double t, double p):
    result = PYROPE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_K(double t, double p):
    result = PYROPE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PYROPE_dewminerals_Kp(double t, double p):
    result = PYROPE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CHAMOSITE_dewminerals_calc.h":
    const char *CHAMOSITE_dewminerals_identifier();
    const char *CHAMOSITE_dewminerals_name();
    const char *CHAMOSITE_dewminerals_formula();
    const double CHAMOSITE_dewminerals_mw();
    const double *CHAMOSITE_dewminerals_elements();
    double CHAMOSITE_dewminerals_g(double t, double p)
    double CHAMOSITE_dewminerals_dgdt(double t, double p)
    double CHAMOSITE_dewminerals_dgdp(double t, double p)
    double CHAMOSITE_dewminerals_d2gdt2(double t, double p)
    double CHAMOSITE_dewminerals_d2gdtdp(double t, double p)
    double CHAMOSITE_dewminerals_d2gdp2(double t, double p)
    double CHAMOSITE_dewminerals_d3gdt3(double t, double p)
    double CHAMOSITE_dewminerals_d3gdt2dp(double t, double p)
    double CHAMOSITE_dewminerals_d3gdtdp2(double t, double p)
    double CHAMOSITE_dewminerals_d3gdp3(double t, double p)
    double CHAMOSITE_dewminerals_s(double t, double p)
    double CHAMOSITE_dewminerals_v(double t, double p)
    double CHAMOSITE_dewminerals_cv(double t, double p)
    double CHAMOSITE_dewminerals_cp(double t, double p)
    double CHAMOSITE_dewminerals_dcpdt(double t, double p)
    double CHAMOSITE_dewminerals_alpha(double t, double p)
    double CHAMOSITE_dewminerals_beta(double t, double p)
    double CHAMOSITE_dewminerals_K(double t, double p)
    double CHAMOSITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CHAMOSITE_dewminerals_identifier():
    result = <bytes> CHAMOSITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CHAMOSITE_dewminerals_name():
    result = <bytes> CHAMOSITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CHAMOSITE_dewminerals_formula():
    result = <bytes> CHAMOSITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CHAMOSITE_dewminerals_mw():
    result = CHAMOSITE_dewminerals_mw()
    return result
def cy_CHAMOSITE_dewminerals_elements():
    cdef const double *e = CHAMOSITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CHAMOSITE_dewminerals_g(double t, double p):
    result = CHAMOSITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_dgdt(double t, double p):
    result = CHAMOSITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_dgdp(double t, double p):
    result = CHAMOSITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d2gdt2(double t, double p):
    result = CHAMOSITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d2gdtdp(double t, double p):
    result = CHAMOSITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d2gdp2(double t, double p):
    result = CHAMOSITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d3gdt3(double t, double p):
    result = CHAMOSITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d3gdt2dp(double t, double p):
    result = CHAMOSITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d3gdtdp2(double t, double p):
    result = CHAMOSITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_d3gdp3(double t, double p):
    result = CHAMOSITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_s(double t, double p):
    result = CHAMOSITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_v(double t, double p):
    result = CHAMOSITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_cv(double t, double p):
    result = CHAMOSITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_cp(double t, double p):
    result = CHAMOSITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_dcpdt(double t, double p):
    result = CHAMOSITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_alpha(double t, double p):
    result = CHAMOSITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_beta(double t, double p):
    result = CHAMOSITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_K(double t, double p):
    result = CHAMOSITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CHAMOSITE_dewminerals_Kp(double t, double p):
    result = CHAMOSITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CLINOCHLORE_dewminerals_calc.h":
    const char *CLINOCHLORE_dewminerals_identifier();
    const char *CLINOCHLORE_dewminerals_name();
    const char *CLINOCHLORE_dewminerals_formula();
    const double CLINOCHLORE_dewminerals_mw();
    const double *CLINOCHLORE_dewminerals_elements();
    double CLINOCHLORE_dewminerals_g(double t, double p)
    double CLINOCHLORE_dewminerals_dgdt(double t, double p)
    double CLINOCHLORE_dewminerals_dgdp(double t, double p)
    double CLINOCHLORE_dewminerals_d2gdt2(double t, double p)
    double CLINOCHLORE_dewminerals_d2gdtdp(double t, double p)
    double CLINOCHLORE_dewminerals_d2gdp2(double t, double p)
    double CLINOCHLORE_dewminerals_d3gdt3(double t, double p)
    double CLINOCHLORE_dewminerals_d3gdt2dp(double t, double p)
    double CLINOCHLORE_dewminerals_d3gdtdp2(double t, double p)
    double CLINOCHLORE_dewminerals_d3gdp3(double t, double p)
    double CLINOCHLORE_dewminerals_s(double t, double p)
    double CLINOCHLORE_dewminerals_v(double t, double p)
    double CLINOCHLORE_dewminerals_cv(double t, double p)
    double CLINOCHLORE_dewminerals_cp(double t, double p)
    double CLINOCHLORE_dewminerals_dcpdt(double t, double p)
    double CLINOCHLORE_dewminerals_alpha(double t, double p)
    double CLINOCHLORE_dewminerals_beta(double t, double p)
    double CLINOCHLORE_dewminerals_K(double t, double p)
    double CLINOCHLORE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CLINOCHLORE_dewminerals_identifier():
    result = <bytes> CLINOCHLORE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CLINOCHLORE_dewminerals_name():
    result = <bytes> CLINOCHLORE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CLINOCHLORE_dewminerals_formula():
    result = <bytes> CLINOCHLORE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CLINOCHLORE_dewminerals_mw():
    result = CLINOCHLORE_dewminerals_mw()
    return result
def cy_CLINOCHLORE_dewminerals_elements():
    cdef const double *e = CLINOCHLORE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CLINOCHLORE_dewminerals_g(double t, double p):
    result = CLINOCHLORE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_dgdt(double t, double p):
    result = CLINOCHLORE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_dgdp(double t, double p):
    result = CLINOCHLORE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d2gdt2(double t, double p):
    result = CLINOCHLORE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d2gdtdp(double t, double p):
    result = CLINOCHLORE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d2gdp2(double t, double p):
    result = CLINOCHLORE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d3gdt3(double t, double p):
    result = CLINOCHLORE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d3gdt2dp(double t, double p):
    result = CLINOCHLORE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d3gdtdp2(double t, double p):
    result = CLINOCHLORE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_d3gdp3(double t, double p):
    result = CLINOCHLORE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_s(double t, double p):
    result = CLINOCHLORE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_v(double t, double p):
    result = CLINOCHLORE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_cv(double t, double p):
    result = CLINOCHLORE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_cp(double t, double p):
    result = CLINOCHLORE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_dcpdt(double t, double p):
    result = CLINOCHLORE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_alpha(double t, double p):
    result = CLINOCHLORE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_beta(double t, double p):
    result = CLINOCHLORE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_K(double t, double p):
    result = CLINOCHLORE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CLINOCHLORE_dewminerals_Kp(double t, double p):
    result = CLINOCHLORE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PREHNITE_dewminerals_calc.h":
    const char *PREHNITE_dewminerals_identifier();
    const char *PREHNITE_dewminerals_name();
    const char *PREHNITE_dewminerals_formula();
    const double PREHNITE_dewminerals_mw();
    const double *PREHNITE_dewminerals_elements();
    double PREHNITE_dewminerals_g(double t, double p)
    double PREHNITE_dewminerals_dgdt(double t, double p)
    double PREHNITE_dewminerals_dgdp(double t, double p)
    double PREHNITE_dewminerals_d2gdt2(double t, double p)
    double PREHNITE_dewminerals_d2gdtdp(double t, double p)
    double PREHNITE_dewminerals_d2gdp2(double t, double p)
    double PREHNITE_dewminerals_d3gdt3(double t, double p)
    double PREHNITE_dewminerals_d3gdt2dp(double t, double p)
    double PREHNITE_dewminerals_d3gdtdp2(double t, double p)
    double PREHNITE_dewminerals_d3gdp3(double t, double p)
    double PREHNITE_dewminerals_s(double t, double p)
    double PREHNITE_dewminerals_v(double t, double p)
    double PREHNITE_dewminerals_cv(double t, double p)
    double PREHNITE_dewminerals_cp(double t, double p)
    double PREHNITE_dewminerals_dcpdt(double t, double p)
    double PREHNITE_dewminerals_alpha(double t, double p)
    double PREHNITE_dewminerals_beta(double t, double p)
    double PREHNITE_dewminerals_K(double t, double p)
    double PREHNITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PREHNITE_dewminerals_identifier():
    result = <bytes> PREHNITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PREHNITE_dewminerals_name():
    result = <bytes> PREHNITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PREHNITE_dewminerals_formula():
    result = <bytes> PREHNITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PREHNITE_dewminerals_mw():
    result = PREHNITE_dewminerals_mw()
    return result
def cy_PREHNITE_dewminerals_elements():
    cdef const double *e = PREHNITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PREHNITE_dewminerals_g(double t, double p):
    result = PREHNITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_dgdt(double t, double p):
    result = PREHNITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_dgdp(double t, double p):
    result = PREHNITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d2gdt2(double t, double p):
    result = PREHNITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d2gdtdp(double t, double p):
    result = PREHNITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d2gdp2(double t, double p):
    result = PREHNITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d3gdt3(double t, double p):
    result = PREHNITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d3gdt2dp(double t, double p):
    result = PREHNITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d3gdtdp2(double t, double p):
    result = PREHNITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_d3gdp3(double t, double p):
    result = PREHNITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_s(double t, double p):
    result = PREHNITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_v(double t, double p):
    result = PREHNITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_cv(double t, double p):
    result = PREHNITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_cp(double t, double p):
    result = PREHNITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_dcpdt(double t, double p):
    result = PREHNITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_alpha(double t, double p):
    result = PREHNITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_beta(double t, double p):
    result = PREHNITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_K(double t, double p):
    result = PREHNITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PREHNITE_dewminerals_Kp(double t, double p):
    result = PREHNITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MARGARITE_dewminerals_calc.h":
    const char *MARGARITE_dewminerals_identifier();
    const char *MARGARITE_dewminerals_name();
    const char *MARGARITE_dewminerals_formula();
    const double MARGARITE_dewminerals_mw();
    const double *MARGARITE_dewminerals_elements();
    double MARGARITE_dewminerals_g(double t, double p)
    double MARGARITE_dewminerals_dgdt(double t, double p)
    double MARGARITE_dewminerals_dgdp(double t, double p)
    double MARGARITE_dewminerals_d2gdt2(double t, double p)
    double MARGARITE_dewminerals_d2gdtdp(double t, double p)
    double MARGARITE_dewminerals_d2gdp2(double t, double p)
    double MARGARITE_dewminerals_d3gdt3(double t, double p)
    double MARGARITE_dewminerals_d3gdt2dp(double t, double p)
    double MARGARITE_dewminerals_d3gdtdp2(double t, double p)
    double MARGARITE_dewminerals_d3gdp3(double t, double p)
    double MARGARITE_dewminerals_s(double t, double p)
    double MARGARITE_dewminerals_v(double t, double p)
    double MARGARITE_dewminerals_cv(double t, double p)
    double MARGARITE_dewminerals_cp(double t, double p)
    double MARGARITE_dewminerals_dcpdt(double t, double p)
    double MARGARITE_dewminerals_alpha(double t, double p)
    double MARGARITE_dewminerals_beta(double t, double p)
    double MARGARITE_dewminerals_K(double t, double p)
    double MARGARITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MARGARITE_dewminerals_identifier():
    result = <bytes> MARGARITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MARGARITE_dewminerals_name():
    result = <bytes> MARGARITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MARGARITE_dewminerals_formula():
    result = <bytes> MARGARITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MARGARITE_dewminerals_mw():
    result = MARGARITE_dewminerals_mw()
    return result
def cy_MARGARITE_dewminerals_elements():
    cdef const double *e = MARGARITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MARGARITE_dewminerals_g(double t, double p):
    result = MARGARITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_dgdt(double t, double p):
    result = MARGARITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_dgdp(double t, double p):
    result = MARGARITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d2gdt2(double t, double p):
    result = MARGARITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d2gdtdp(double t, double p):
    result = MARGARITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d2gdp2(double t, double p):
    result = MARGARITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d3gdt3(double t, double p):
    result = MARGARITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d3gdt2dp(double t, double p):
    result = MARGARITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d3gdtdp2(double t, double p):
    result = MARGARITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_d3gdp3(double t, double p):
    result = MARGARITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_s(double t, double p):
    result = MARGARITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_v(double t, double p):
    result = MARGARITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_cv(double t, double p):
    result = MARGARITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_cp(double t, double p):
    result = MARGARITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_dcpdt(double t, double p):
    result = MARGARITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_alpha(double t, double p):
    result = MARGARITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_beta(double t, double p):
    result = MARGARITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_K(double t, double p):
    result = MARGARITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MARGARITE_dewminerals_Kp(double t, double p):
    result = MARGARITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PARAGONITE_dewminerals_calc.h":
    const char *PARAGONITE_dewminerals_identifier();
    const char *PARAGONITE_dewminerals_name();
    const char *PARAGONITE_dewminerals_formula();
    const double PARAGONITE_dewminerals_mw();
    const double *PARAGONITE_dewminerals_elements();
    double PARAGONITE_dewminerals_g(double t, double p)
    double PARAGONITE_dewminerals_dgdt(double t, double p)
    double PARAGONITE_dewminerals_dgdp(double t, double p)
    double PARAGONITE_dewminerals_d2gdt2(double t, double p)
    double PARAGONITE_dewminerals_d2gdtdp(double t, double p)
    double PARAGONITE_dewminerals_d2gdp2(double t, double p)
    double PARAGONITE_dewminerals_d3gdt3(double t, double p)
    double PARAGONITE_dewminerals_d3gdt2dp(double t, double p)
    double PARAGONITE_dewminerals_d3gdtdp2(double t, double p)
    double PARAGONITE_dewminerals_d3gdp3(double t, double p)
    double PARAGONITE_dewminerals_s(double t, double p)
    double PARAGONITE_dewminerals_v(double t, double p)
    double PARAGONITE_dewminerals_cv(double t, double p)
    double PARAGONITE_dewminerals_cp(double t, double p)
    double PARAGONITE_dewminerals_dcpdt(double t, double p)
    double PARAGONITE_dewminerals_alpha(double t, double p)
    double PARAGONITE_dewminerals_beta(double t, double p)
    double PARAGONITE_dewminerals_K(double t, double p)
    double PARAGONITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PARAGONITE_dewminerals_identifier():
    result = <bytes> PARAGONITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PARAGONITE_dewminerals_name():
    result = <bytes> PARAGONITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PARAGONITE_dewminerals_formula():
    result = <bytes> PARAGONITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PARAGONITE_dewminerals_mw():
    result = PARAGONITE_dewminerals_mw()
    return result
def cy_PARAGONITE_dewminerals_elements():
    cdef const double *e = PARAGONITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PARAGONITE_dewminerals_g(double t, double p):
    result = PARAGONITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_dgdt(double t, double p):
    result = PARAGONITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_dgdp(double t, double p):
    result = PARAGONITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d2gdt2(double t, double p):
    result = PARAGONITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d2gdtdp(double t, double p):
    result = PARAGONITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d2gdp2(double t, double p):
    result = PARAGONITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d3gdt3(double t, double p):
    result = PARAGONITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d3gdt2dp(double t, double p):
    result = PARAGONITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d3gdtdp2(double t, double p):
    result = PARAGONITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_d3gdp3(double t, double p):
    result = PARAGONITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_s(double t, double p):
    result = PARAGONITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_v(double t, double p):
    result = PARAGONITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_cv(double t, double p):
    result = PARAGONITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_cp(double t, double p):
    result = PARAGONITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_dcpdt(double t, double p):
    result = PARAGONITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_alpha(double t, double p):
    result = PARAGONITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_beta(double t, double p):
    result = PARAGONITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_K(double t, double p):
    result = PARAGONITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PARAGONITE_dewminerals_Kp(double t, double p):
    result = PARAGONITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PHLOGOPITE_dewminerals_calc.h":
    const char *PHLOGOPITE_dewminerals_identifier();
    const char *PHLOGOPITE_dewminerals_name();
    const char *PHLOGOPITE_dewminerals_formula();
    const double PHLOGOPITE_dewminerals_mw();
    const double *PHLOGOPITE_dewminerals_elements();
    double PHLOGOPITE_dewminerals_g(double t, double p)
    double PHLOGOPITE_dewminerals_dgdt(double t, double p)
    double PHLOGOPITE_dewminerals_dgdp(double t, double p)
    double PHLOGOPITE_dewminerals_d2gdt2(double t, double p)
    double PHLOGOPITE_dewminerals_d2gdtdp(double t, double p)
    double PHLOGOPITE_dewminerals_d2gdp2(double t, double p)
    double PHLOGOPITE_dewminerals_d3gdt3(double t, double p)
    double PHLOGOPITE_dewminerals_d3gdt2dp(double t, double p)
    double PHLOGOPITE_dewminerals_d3gdtdp2(double t, double p)
    double PHLOGOPITE_dewminerals_d3gdp3(double t, double p)
    double PHLOGOPITE_dewminerals_s(double t, double p)
    double PHLOGOPITE_dewminerals_v(double t, double p)
    double PHLOGOPITE_dewminerals_cv(double t, double p)
    double PHLOGOPITE_dewminerals_cp(double t, double p)
    double PHLOGOPITE_dewminerals_dcpdt(double t, double p)
    double PHLOGOPITE_dewminerals_alpha(double t, double p)
    double PHLOGOPITE_dewminerals_beta(double t, double p)
    double PHLOGOPITE_dewminerals_K(double t, double p)
    double PHLOGOPITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PHLOGOPITE_dewminerals_identifier():
    result = <bytes> PHLOGOPITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PHLOGOPITE_dewminerals_name():
    result = <bytes> PHLOGOPITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PHLOGOPITE_dewminerals_formula():
    result = <bytes> PHLOGOPITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PHLOGOPITE_dewminerals_mw():
    result = PHLOGOPITE_dewminerals_mw()
    return result
def cy_PHLOGOPITE_dewminerals_elements():
    cdef const double *e = PHLOGOPITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PHLOGOPITE_dewminerals_g(double t, double p):
    result = PHLOGOPITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_dgdt(double t, double p):
    result = PHLOGOPITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_dgdp(double t, double p):
    result = PHLOGOPITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d2gdt2(double t, double p):
    result = PHLOGOPITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d2gdtdp(double t, double p):
    result = PHLOGOPITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d2gdp2(double t, double p):
    result = PHLOGOPITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d3gdt3(double t, double p):
    result = PHLOGOPITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d3gdt2dp(double t, double p):
    result = PHLOGOPITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d3gdtdp2(double t, double p):
    result = PHLOGOPITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_d3gdp3(double t, double p):
    result = PHLOGOPITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_s(double t, double p):
    result = PHLOGOPITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_v(double t, double p):
    result = PHLOGOPITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_cv(double t, double p):
    result = PHLOGOPITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_cp(double t, double p):
    result = PHLOGOPITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_dcpdt(double t, double p):
    result = PHLOGOPITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_alpha(double t, double p):
    result = PHLOGOPITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_beta(double t, double p):
    result = PHLOGOPITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_K(double t, double p):
    result = PHLOGOPITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PHLOGOPITE_dewminerals_Kp(double t, double p):
    result = PHLOGOPITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ANNITE_dewminerals_calc.h":
    const char *ANNITE_dewminerals_identifier();
    const char *ANNITE_dewminerals_name();
    const char *ANNITE_dewminerals_formula();
    const double ANNITE_dewminerals_mw();
    const double *ANNITE_dewminerals_elements();
    double ANNITE_dewminerals_g(double t, double p)
    double ANNITE_dewminerals_dgdt(double t, double p)
    double ANNITE_dewminerals_dgdp(double t, double p)
    double ANNITE_dewminerals_d2gdt2(double t, double p)
    double ANNITE_dewminerals_d2gdtdp(double t, double p)
    double ANNITE_dewminerals_d2gdp2(double t, double p)
    double ANNITE_dewminerals_d3gdt3(double t, double p)
    double ANNITE_dewminerals_d3gdt2dp(double t, double p)
    double ANNITE_dewminerals_d3gdtdp2(double t, double p)
    double ANNITE_dewminerals_d3gdp3(double t, double p)
    double ANNITE_dewminerals_s(double t, double p)
    double ANNITE_dewminerals_v(double t, double p)
    double ANNITE_dewminerals_cv(double t, double p)
    double ANNITE_dewminerals_cp(double t, double p)
    double ANNITE_dewminerals_dcpdt(double t, double p)
    double ANNITE_dewminerals_alpha(double t, double p)
    double ANNITE_dewminerals_beta(double t, double p)
    double ANNITE_dewminerals_K(double t, double p)
    double ANNITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ANNITE_dewminerals_identifier():
    result = <bytes> ANNITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ANNITE_dewminerals_name():
    result = <bytes> ANNITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ANNITE_dewminerals_formula():
    result = <bytes> ANNITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ANNITE_dewminerals_mw():
    result = ANNITE_dewminerals_mw()
    return result
def cy_ANNITE_dewminerals_elements():
    cdef const double *e = ANNITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ANNITE_dewminerals_g(double t, double p):
    result = ANNITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_dgdt(double t, double p):
    result = ANNITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_dgdp(double t, double p):
    result = ANNITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d2gdt2(double t, double p):
    result = ANNITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d2gdtdp(double t, double p):
    result = ANNITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d2gdp2(double t, double p):
    result = ANNITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d3gdt3(double t, double p):
    result = ANNITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d3gdt2dp(double t, double p):
    result = ANNITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d3gdtdp2(double t, double p):
    result = ANNITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_d3gdp3(double t, double p):
    result = ANNITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_s(double t, double p):
    result = ANNITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_v(double t, double p):
    result = ANNITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_cv(double t, double p):
    result = ANNITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_cp(double t, double p):
    result = ANNITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_dcpdt(double t, double p):
    result = ANNITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_alpha(double t, double p):
    result = ANNITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_beta(double t, double p):
    result = ANNITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_K(double t, double p):
    result = ANNITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ANNITE_dewminerals_Kp(double t, double p):
    result = ANNITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MUSCOVITE_dewminerals_calc.h":
    const char *MUSCOVITE_dewminerals_identifier();
    const char *MUSCOVITE_dewminerals_name();
    const char *MUSCOVITE_dewminerals_formula();
    const double MUSCOVITE_dewminerals_mw();
    const double *MUSCOVITE_dewminerals_elements();
    double MUSCOVITE_dewminerals_g(double t, double p)
    double MUSCOVITE_dewminerals_dgdt(double t, double p)
    double MUSCOVITE_dewminerals_dgdp(double t, double p)
    double MUSCOVITE_dewminerals_d2gdt2(double t, double p)
    double MUSCOVITE_dewminerals_d2gdtdp(double t, double p)
    double MUSCOVITE_dewminerals_d2gdp2(double t, double p)
    double MUSCOVITE_dewminerals_d3gdt3(double t, double p)
    double MUSCOVITE_dewminerals_d3gdt2dp(double t, double p)
    double MUSCOVITE_dewminerals_d3gdtdp2(double t, double p)
    double MUSCOVITE_dewminerals_d3gdp3(double t, double p)
    double MUSCOVITE_dewminerals_s(double t, double p)
    double MUSCOVITE_dewminerals_v(double t, double p)
    double MUSCOVITE_dewminerals_cv(double t, double p)
    double MUSCOVITE_dewminerals_cp(double t, double p)
    double MUSCOVITE_dewminerals_dcpdt(double t, double p)
    double MUSCOVITE_dewminerals_alpha(double t, double p)
    double MUSCOVITE_dewminerals_beta(double t, double p)
    double MUSCOVITE_dewminerals_K(double t, double p)
    double MUSCOVITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MUSCOVITE_dewminerals_identifier():
    result = <bytes> MUSCOVITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MUSCOVITE_dewminerals_name():
    result = <bytes> MUSCOVITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MUSCOVITE_dewminerals_formula():
    result = <bytes> MUSCOVITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MUSCOVITE_dewminerals_mw():
    result = MUSCOVITE_dewminerals_mw()
    return result
def cy_MUSCOVITE_dewminerals_elements():
    cdef const double *e = MUSCOVITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MUSCOVITE_dewminerals_g(double t, double p):
    result = MUSCOVITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_dgdt(double t, double p):
    result = MUSCOVITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_dgdp(double t, double p):
    result = MUSCOVITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d2gdt2(double t, double p):
    result = MUSCOVITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d2gdtdp(double t, double p):
    result = MUSCOVITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d2gdp2(double t, double p):
    result = MUSCOVITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d3gdt3(double t, double p):
    result = MUSCOVITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d3gdt2dp(double t, double p):
    result = MUSCOVITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d3gdtdp2(double t, double p):
    result = MUSCOVITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_d3gdp3(double t, double p):
    result = MUSCOVITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_s(double t, double p):
    result = MUSCOVITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_v(double t, double p):
    result = MUSCOVITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_cv(double t, double p):
    result = MUSCOVITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_cp(double t, double p):
    result = MUSCOVITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_dcpdt(double t, double p):
    result = MUSCOVITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_alpha(double t, double p):
    result = MUSCOVITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_beta(double t, double p):
    result = MUSCOVITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_K(double t, double p):
    result = MUSCOVITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MUSCOVITE_dewminerals_Kp(double t, double p):
    result = MUSCOVITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "TALC_dewminerals_calc.h":
    const char *TALC_dewminerals_identifier();
    const char *TALC_dewminerals_name();
    const char *TALC_dewminerals_formula();
    const double TALC_dewminerals_mw();
    const double *TALC_dewminerals_elements();
    double TALC_dewminerals_g(double t, double p)
    double TALC_dewminerals_dgdt(double t, double p)
    double TALC_dewminerals_dgdp(double t, double p)
    double TALC_dewminerals_d2gdt2(double t, double p)
    double TALC_dewminerals_d2gdtdp(double t, double p)
    double TALC_dewminerals_d2gdp2(double t, double p)
    double TALC_dewminerals_d3gdt3(double t, double p)
    double TALC_dewminerals_d3gdt2dp(double t, double p)
    double TALC_dewminerals_d3gdtdp2(double t, double p)
    double TALC_dewminerals_d3gdp3(double t, double p)
    double TALC_dewminerals_s(double t, double p)
    double TALC_dewminerals_v(double t, double p)
    double TALC_dewminerals_cv(double t, double p)
    double TALC_dewminerals_cp(double t, double p)
    double TALC_dewminerals_dcpdt(double t, double p)
    double TALC_dewminerals_alpha(double t, double p)
    double TALC_dewminerals_beta(double t, double p)
    double TALC_dewminerals_K(double t, double p)
    double TALC_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_TALC_dewminerals_identifier():
    result = <bytes> TALC_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_TALC_dewminerals_name():
    result = <bytes> TALC_dewminerals_name()
    return result.decode('UTF-8')
def cy_TALC_dewminerals_formula():
    result = <bytes> TALC_dewminerals_formula()
    return result.decode('UTF-8')
def cy_TALC_dewminerals_mw():
    result = TALC_dewminerals_mw()
    return result
def cy_TALC_dewminerals_elements():
    cdef const double *e = TALC_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_TALC_dewminerals_g(double t, double p):
    result = TALC_dewminerals_g(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_dgdt(double t, double p):
    result = TALC_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_dgdp(double t, double p):
    result = TALC_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d2gdt2(double t, double p):
    result = TALC_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d2gdtdp(double t, double p):
    result = TALC_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d2gdp2(double t, double p):
    result = TALC_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d3gdt3(double t, double p):
    result = TALC_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d3gdt2dp(double t, double p):
    result = TALC_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d3gdtdp2(double t, double p):
    result = TALC_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_d3gdp3(double t, double p):
    result = TALC_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_s(double t, double p):
    result = TALC_dewminerals_s(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_v(double t, double p):
    result = TALC_dewminerals_v(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_cv(double t, double p):
    result = TALC_dewminerals_cv(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_cp(double t, double p):
    result = TALC_dewminerals_cp(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_dcpdt(double t, double p):
    result = TALC_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_alpha(double t, double p):
    result = TALC_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_beta(double t, double p):
    result = TALC_dewminerals_beta(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_K(double t, double p):
    result = TALC_dewminerals_K(<double> t, <double> p)
    return result
def cy_TALC_dewminerals_Kp(double t, double p):
    result = TALC_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PYROPHYLLITE_dewminerals_calc.h":
    const char *PYROPHYLLITE_dewminerals_identifier();
    const char *PYROPHYLLITE_dewminerals_name();
    const char *PYROPHYLLITE_dewminerals_formula();
    const double PYROPHYLLITE_dewminerals_mw();
    const double *PYROPHYLLITE_dewminerals_elements();
    double PYROPHYLLITE_dewminerals_g(double t, double p)
    double PYROPHYLLITE_dewminerals_dgdt(double t, double p)
    double PYROPHYLLITE_dewminerals_dgdp(double t, double p)
    double PYROPHYLLITE_dewminerals_d2gdt2(double t, double p)
    double PYROPHYLLITE_dewminerals_d2gdtdp(double t, double p)
    double PYROPHYLLITE_dewminerals_d2gdp2(double t, double p)
    double PYROPHYLLITE_dewminerals_d3gdt3(double t, double p)
    double PYROPHYLLITE_dewminerals_d3gdt2dp(double t, double p)
    double PYROPHYLLITE_dewminerals_d3gdtdp2(double t, double p)
    double PYROPHYLLITE_dewminerals_d3gdp3(double t, double p)
    double PYROPHYLLITE_dewminerals_s(double t, double p)
    double PYROPHYLLITE_dewminerals_v(double t, double p)
    double PYROPHYLLITE_dewminerals_cv(double t, double p)
    double PYROPHYLLITE_dewminerals_cp(double t, double p)
    double PYROPHYLLITE_dewminerals_dcpdt(double t, double p)
    double PYROPHYLLITE_dewminerals_alpha(double t, double p)
    double PYROPHYLLITE_dewminerals_beta(double t, double p)
    double PYROPHYLLITE_dewminerals_K(double t, double p)
    double PYROPHYLLITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PYROPHYLLITE_dewminerals_identifier():
    result = <bytes> PYROPHYLLITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PYROPHYLLITE_dewminerals_name():
    result = <bytes> PYROPHYLLITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PYROPHYLLITE_dewminerals_formula():
    result = <bytes> PYROPHYLLITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PYROPHYLLITE_dewminerals_mw():
    result = PYROPHYLLITE_dewminerals_mw()
    return result
def cy_PYROPHYLLITE_dewminerals_elements():
    cdef const double *e = PYROPHYLLITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PYROPHYLLITE_dewminerals_g(double t, double p):
    result = PYROPHYLLITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_dgdt(double t, double p):
    result = PYROPHYLLITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_dgdp(double t, double p):
    result = PYROPHYLLITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d2gdt2(double t, double p):
    result = PYROPHYLLITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d2gdtdp(double t, double p):
    result = PYROPHYLLITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d2gdp2(double t, double p):
    result = PYROPHYLLITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d3gdt3(double t, double p):
    result = PYROPHYLLITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d3gdt2dp(double t, double p):
    result = PYROPHYLLITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d3gdtdp2(double t, double p):
    result = PYROPHYLLITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_d3gdp3(double t, double p):
    result = PYROPHYLLITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_s(double t, double p):
    result = PYROPHYLLITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_v(double t, double p):
    result = PYROPHYLLITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_cv(double t, double p):
    result = PYROPHYLLITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_cp(double t, double p):
    result = PYROPHYLLITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_dcpdt(double t, double p):
    result = PYROPHYLLITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_alpha(double t, double p):
    result = PYROPHYLLITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_beta(double t, double p):
    result = PYROPHYLLITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_K(double t, double p):
    result = PYROPHYLLITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PYROPHYLLITE_dewminerals_Kp(double t, double p):
    result = PYROPHYLLITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ANTIGORITE_dewminerals_calc.h":
    const char *ANTIGORITE_dewminerals_identifier();
    const char *ANTIGORITE_dewminerals_name();
    const char *ANTIGORITE_dewminerals_formula();
    const double ANTIGORITE_dewminerals_mw();
    const double *ANTIGORITE_dewminerals_elements();
    double ANTIGORITE_dewminerals_g(double t, double p)
    double ANTIGORITE_dewminerals_dgdt(double t, double p)
    double ANTIGORITE_dewminerals_dgdp(double t, double p)
    double ANTIGORITE_dewminerals_d2gdt2(double t, double p)
    double ANTIGORITE_dewminerals_d2gdtdp(double t, double p)
    double ANTIGORITE_dewminerals_d2gdp2(double t, double p)
    double ANTIGORITE_dewminerals_d3gdt3(double t, double p)
    double ANTIGORITE_dewminerals_d3gdt2dp(double t, double p)
    double ANTIGORITE_dewminerals_d3gdtdp2(double t, double p)
    double ANTIGORITE_dewminerals_d3gdp3(double t, double p)
    double ANTIGORITE_dewminerals_s(double t, double p)
    double ANTIGORITE_dewminerals_v(double t, double p)
    double ANTIGORITE_dewminerals_cv(double t, double p)
    double ANTIGORITE_dewminerals_cp(double t, double p)
    double ANTIGORITE_dewminerals_dcpdt(double t, double p)
    double ANTIGORITE_dewminerals_alpha(double t, double p)
    double ANTIGORITE_dewminerals_beta(double t, double p)
    double ANTIGORITE_dewminerals_K(double t, double p)
    double ANTIGORITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ANTIGORITE_dewminerals_identifier():
    result = <bytes> ANTIGORITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ANTIGORITE_dewminerals_name():
    result = <bytes> ANTIGORITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ANTIGORITE_dewminerals_formula():
    result = <bytes> ANTIGORITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ANTIGORITE_dewminerals_mw():
    result = ANTIGORITE_dewminerals_mw()
    return result
def cy_ANTIGORITE_dewminerals_elements():
    cdef const double *e = ANTIGORITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ANTIGORITE_dewminerals_g(double t, double p):
    result = ANTIGORITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_dgdt(double t, double p):
    result = ANTIGORITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_dgdp(double t, double p):
    result = ANTIGORITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d2gdt2(double t, double p):
    result = ANTIGORITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d2gdtdp(double t, double p):
    result = ANTIGORITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d2gdp2(double t, double p):
    result = ANTIGORITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d3gdt3(double t, double p):
    result = ANTIGORITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d3gdt2dp(double t, double p):
    result = ANTIGORITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d3gdtdp2(double t, double p):
    result = ANTIGORITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_d3gdp3(double t, double p):
    result = ANTIGORITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_s(double t, double p):
    result = ANTIGORITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_v(double t, double p):
    result = ANTIGORITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_cv(double t, double p):
    result = ANTIGORITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_cp(double t, double p):
    result = ANTIGORITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_dcpdt(double t, double p):
    result = ANTIGORITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_alpha(double t, double p):
    result = ANTIGORITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_beta(double t, double p):
    result = ANTIGORITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_K(double t, double p):
    result = ANTIGORITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ANTIGORITE_dewminerals_Kp(double t, double p):
    result = ANTIGORITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "KAOLINITE_dewminerals_calc.h":
    const char *KAOLINITE_dewminerals_identifier();
    const char *KAOLINITE_dewminerals_name();
    const char *KAOLINITE_dewminerals_formula();
    const double KAOLINITE_dewminerals_mw();
    const double *KAOLINITE_dewminerals_elements();
    double KAOLINITE_dewminerals_g(double t, double p)
    double KAOLINITE_dewminerals_dgdt(double t, double p)
    double KAOLINITE_dewminerals_dgdp(double t, double p)
    double KAOLINITE_dewminerals_d2gdt2(double t, double p)
    double KAOLINITE_dewminerals_d2gdtdp(double t, double p)
    double KAOLINITE_dewminerals_d2gdp2(double t, double p)
    double KAOLINITE_dewminerals_d3gdt3(double t, double p)
    double KAOLINITE_dewminerals_d3gdt2dp(double t, double p)
    double KAOLINITE_dewminerals_d3gdtdp2(double t, double p)
    double KAOLINITE_dewminerals_d3gdp3(double t, double p)
    double KAOLINITE_dewminerals_s(double t, double p)
    double KAOLINITE_dewminerals_v(double t, double p)
    double KAOLINITE_dewminerals_cv(double t, double p)
    double KAOLINITE_dewminerals_cp(double t, double p)
    double KAOLINITE_dewminerals_dcpdt(double t, double p)
    double KAOLINITE_dewminerals_alpha(double t, double p)
    double KAOLINITE_dewminerals_beta(double t, double p)
    double KAOLINITE_dewminerals_K(double t, double p)
    double KAOLINITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_KAOLINITE_dewminerals_identifier():
    result = <bytes> KAOLINITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_KAOLINITE_dewminerals_name():
    result = <bytes> KAOLINITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_KAOLINITE_dewminerals_formula():
    result = <bytes> KAOLINITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_KAOLINITE_dewminerals_mw():
    result = KAOLINITE_dewminerals_mw()
    return result
def cy_KAOLINITE_dewminerals_elements():
    cdef const double *e = KAOLINITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_KAOLINITE_dewminerals_g(double t, double p):
    result = KAOLINITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_dgdt(double t, double p):
    result = KAOLINITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_dgdp(double t, double p):
    result = KAOLINITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d2gdt2(double t, double p):
    result = KAOLINITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d2gdtdp(double t, double p):
    result = KAOLINITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d2gdp2(double t, double p):
    result = KAOLINITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d3gdt3(double t, double p):
    result = KAOLINITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d3gdt2dp(double t, double p):
    result = KAOLINITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d3gdtdp2(double t, double p):
    result = KAOLINITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_d3gdp3(double t, double p):
    result = KAOLINITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_s(double t, double p):
    result = KAOLINITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_v(double t, double p):
    result = KAOLINITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_cv(double t, double p):
    result = KAOLINITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_cp(double t, double p):
    result = KAOLINITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_dcpdt(double t, double p):
    result = KAOLINITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_alpha(double t, double p):
    result = KAOLINITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_beta(double t, double p):
    result = KAOLINITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_K(double t, double p):
    result = KAOLINITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_KAOLINITE_dewminerals_Kp(double t, double p):
    result = KAOLINITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "GEHLENITE_dewminerals_calc.h":
    const char *GEHLENITE_dewminerals_identifier();
    const char *GEHLENITE_dewminerals_name();
    const char *GEHLENITE_dewminerals_formula();
    const double GEHLENITE_dewminerals_mw();
    const double *GEHLENITE_dewminerals_elements();
    double GEHLENITE_dewminerals_g(double t, double p)
    double GEHLENITE_dewminerals_dgdt(double t, double p)
    double GEHLENITE_dewminerals_dgdp(double t, double p)
    double GEHLENITE_dewminerals_d2gdt2(double t, double p)
    double GEHLENITE_dewminerals_d2gdtdp(double t, double p)
    double GEHLENITE_dewminerals_d2gdp2(double t, double p)
    double GEHLENITE_dewminerals_d3gdt3(double t, double p)
    double GEHLENITE_dewminerals_d3gdt2dp(double t, double p)
    double GEHLENITE_dewminerals_d3gdtdp2(double t, double p)
    double GEHLENITE_dewminerals_d3gdp3(double t, double p)
    double GEHLENITE_dewminerals_s(double t, double p)
    double GEHLENITE_dewminerals_v(double t, double p)
    double GEHLENITE_dewminerals_cv(double t, double p)
    double GEHLENITE_dewminerals_cp(double t, double p)
    double GEHLENITE_dewminerals_dcpdt(double t, double p)
    double GEHLENITE_dewminerals_alpha(double t, double p)
    double GEHLENITE_dewminerals_beta(double t, double p)
    double GEHLENITE_dewminerals_K(double t, double p)
    double GEHLENITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_GEHLENITE_dewminerals_identifier():
    result = <bytes> GEHLENITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_GEHLENITE_dewminerals_name():
    result = <bytes> GEHLENITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_GEHLENITE_dewminerals_formula():
    result = <bytes> GEHLENITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_GEHLENITE_dewminerals_mw():
    result = GEHLENITE_dewminerals_mw()
    return result
def cy_GEHLENITE_dewminerals_elements():
    cdef const double *e = GEHLENITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_GEHLENITE_dewminerals_g(double t, double p):
    result = GEHLENITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_dgdt(double t, double p):
    result = GEHLENITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_dgdp(double t, double p):
    result = GEHLENITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d2gdt2(double t, double p):
    result = GEHLENITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d2gdtdp(double t, double p):
    result = GEHLENITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d2gdp2(double t, double p):
    result = GEHLENITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d3gdt3(double t, double p):
    result = GEHLENITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d3gdt2dp(double t, double p):
    result = GEHLENITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d3gdtdp2(double t, double p):
    result = GEHLENITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_d3gdp3(double t, double p):
    result = GEHLENITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_s(double t, double p):
    result = GEHLENITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_v(double t, double p):
    result = GEHLENITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_cv(double t, double p):
    result = GEHLENITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_cp(double t, double p):
    result = GEHLENITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_dcpdt(double t, double p):
    result = GEHLENITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_alpha(double t, double p):
    result = GEHLENITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_beta(double t, double p):
    result = GEHLENITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_K(double t, double p):
    result = GEHLENITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_GEHLENITE_dewminerals_Kp(double t, double p):
    result = GEHLENITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ANORTHITE_dewminerals_calc.h":
    const char *ANORTHITE_dewminerals_identifier();
    const char *ANORTHITE_dewminerals_name();
    const char *ANORTHITE_dewminerals_formula();
    const double ANORTHITE_dewminerals_mw();
    const double *ANORTHITE_dewminerals_elements();
    double ANORTHITE_dewminerals_g(double t, double p)
    double ANORTHITE_dewminerals_dgdt(double t, double p)
    double ANORTHITE_dewminerals_dgdp(double t, double p)
    double ANORTHITE_dewminerals_d2gdt2(double t, double p)
    double ANORTHITE_dewminerals_d2gdtdp(double t, double p)
    double ANORTHITE_dewminerals_d2gdp2(double t, double p)
    double ANORTHITE_dewminerals_d3gdt3(double t, double p)
    double ANORTHITE_dewminerals_d3gdt2dp(double t, double p)
    double ANORTHITE_dewminerals_d3gdtdp2(double t, double p)
    double ANORTHITE_dewminerals_d3gdp3(double t, double p)
    double ANORTHITE_dewminerals_s(double t, double p)
    double ANORTHITE_dewminerals_v(double t, double p)
    double ANORTHITE_dewminerals_cv(double t, double p)
    double ANORTHITE_dewminerals_cp(double t, double p)
    double ANORTHITE_dewminerals_dcpdt(double t, double p)
    double ANORTHITE_dewminerals_alpha(double t, double p)
    double ANORTHITE_dewminerals_beta(double t, double p)
    double ANORTHITE_dewminerals_K(double t, double p)
    double ANORTHITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ANORTHITE_dewminerals_identifier():
    result = <bytes> ANORTHITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ANORTHITE_dewminerals_name():
    result = <bytes> ANORTHITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ANORTHITE_dewminerals_formula():
    result = <bytes> ANORTHITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ANORTHITE_dewminerals_mw():
    result = ANORTHITE_dewminerals_mw()
    return result
def cy_ANORTHITE_dewminerals_elements():
    cdef const double *e = ANORTHITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ANORTHITE_dewminerals_g(double t, double p):
    result = ANORTHITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_dgdt(double t, double p):
    result = ANORTHITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_dgdp(double t, double p):
    result = ANORTHITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d2gdt2(double t, double p):
    result = ANORTHITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d2gdtdp(double t, double p):
    result = ANORTHITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d2gdp2(double t, double p):
    result = ANORTHITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d3gdt3(double t, double p):
    result = ANORTHITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d3gdt2dp(double t, double p):
    result = ANORTHITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d3gdtdp2(double t, double p):
    result = ANORTHITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_d3gdp3(double t, double p):
    result = ANORTHITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_s(double t, double p):
    result = ANORTHITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_v(double t, double p):
    result = ANORTHITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_cv(double t, double p):
    result = ANORTHITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_cp(double t, double p):
    result = ANORTHITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_dcpdt(double t, double p):
    result = ANORTHITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_alpha(double t, double p):
    result = ANORTHITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_beta(double t, double p):
    result = ANORTHITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_K(double t, double p):
    result = ANORTHITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ANORTHITE_dewminerals_Kp(double t, double p):
    result = ANORTHITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ALBITE_dewminerals_calc.h":
    const char *ALBITE_dewminerals_identifier();
    const char *ALBITE_dewminerals_name();
    const char *ALBITE_dewminerals_formula();
    const double ALBITE_dewminerals_mw();
    const double *ALBITE_dewminerals_elements();
    double ALBITE_dewminerals_g(double t, double p)
    double ALBITE_dewminerals_dgdt(double t, double p)
    double ALBITE_dewminerals_dgdp(double t, double p)
    double ALBITE_dewminerals_d2gdt2(double t, double p)
    double ALBITE_dewminerals_d2gdtdp(double t, double p)
    double ALBITE_dewminerals_d2gdp2(double t, double p)
    double ALBITE_dewminerals_d3gdt3(double t, double p)
    double ALBITE_dewminerals_d3gdt2dp(double t, double p)
    double ALBITE_dewminerals_d3gdtdp2(double t, double p)
    double ALBITE_dewminerals_d3gdp3(double t, double p)
    double ALBITE_dewminerals_s(double t, double p)
    double ALBITE_dewminerals_v(double t, double p)
    double ALBITE_dewminerals_cv(double t, double p)
    double ALBITE_dewminerals_cp(double t, double p)
    double ALBITE_dewminerals_dcpdt(double t, double p)
    double ALBITE_dewminerals_alpha(double t, double p)
    double ALBITE_dewminerals_beta(double t, double p)
    double ALBITE_dewminerals_K(double t, double p)
    double ALBITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ALBITE_dewminerals_identifier():
    result = <bytes> ALBITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ALBITE_dewminerals_name():
    result = <bytes> ALBITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ALBITE_dewminerals_formula():
    result = <bytes> ALBITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ALBITE_dewminerals_mw():
    result = ALBITE_dewminerals_mw()
    return result
def cy_ALBITE_dewminerals_elements():
    cdef const double *e = ALBITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ALBITE_dewminerals_g(double t, double p):
    result = ALBITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_dgdt(double t, double p):
    result = ALBITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_dgdp(double t, double p):
    result = ALBITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d2gdt2(double t, double p):
    result = ALBITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d2gdtdp(double t, double p):
    result = ALBITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d2gdp2(double t, double p):
    result = ALBITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d3gdt3(double t, double p):
    result = ALBITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d3gdt2dp(double t, double p):
    result = ALBITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d3gdtdp2(double t, double p):
    result = ALBITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_d3gdp3(double t, double p):
    result = ALBITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_s(double t, double p):
    result = ALBITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_v(double t, double p):
    result = ALBITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_cv(double t, double p):
    result = ALBITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_cp(double t, double p):
    result = ALBITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_dcpdt(double t, double p):
    result = ALBITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_alpha(double t, double p):
    result = ALBITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_beta(double t, double p):
    result = ALBITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_K(double t, double p):
    result = ALBITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ALBITE_dewminerals_Kp(double t, double p):
    result = ALBITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "KFELDSPAR_dewminerals_calc.h":
    const char *KFELDSPAR_dewminerals_identifier();
    const char *KFELDSPAR_dewminerals_name();
    const char *KFELDSPAR_dewminerals_formula();
    const double KFELDSPAR_dewminerals_mw();
    const double *KFELDSPAR_dewminerals_elements();
    double KFELDSPAR_dewminerals_g(double t, double p)
    double KFELDSPAR_dewminerals_dgdt(double t, double p)
    double KFELDSPAR_dewminerals_dgdp(double t, double p)
    double KFELDSPAR_dewminerals_d2gdt2(double t, double p)
    double KFELDSPAR_dewminerals_d2gdtdp(double t, double p)
    double KFELDSPAR_dewminerals_d2gdp2(double t, double p)
    double KFELDSPAR_dewminerals_d3gdt3(double t, double p)
    double KFELDSPAR_dewminerals_d3gdt2dp(double t, double p)
    double KFELDSPAR_dewminerals_d3gdtdp2(double t, double p)
    double KFELDSPAR_dewminerals_d3gdp3(double t, double p)
    double KFELDSPAR_dewminerals_s(double t, double p)
    double KFELDSPAR_dewminerals_v(double t, double p)
    double KFELDSPAR_dewminerals_cv(double t, double p)
    double KFELDSPAR_dewminerals_cp(double t, double p)
    double KFELDSPAR_dewminerals_dcpdt(double t, double p)
    double KFELDSPAR_dewminerals_alpha(double t, double p)
    double KFELDSPAR_dewminerals_beta(double t, double p)
    double KFELDSPAR_dewminerals_K(double t, double p)
    double KFELDSPAR_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_KFELDSPAR_dewminerals_identifier():
    result = <bytes> KFELDSPAR_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_KFELDSPAR_dewminerals_name():
    result = <bytes> KFELDSPAR_dewminerals_name()
    return result.decode('UTF-8')
def cy_KFELDSPAR_dewminerals_formula():
    result = <bytes> KFELDSPAR_dewminerals_formula()
    return result.decode('UTF-8')
def cy_KFELDSPAR_dewminerals_mw():
    result = KFELDSPAR_dewminerals_mw()
    return result
def cy_KFELDSPAR_dewminerals_elements():
    cdef const double *e = KFELDSPAR_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_KFELDSPAR_dewminerals_g(double t, double p):
    result = KFELDSPAR_dewminerals_g(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_dgdt(double t, double p):
    result = KFELDSPAR_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_dgdp(double t, double p):
    result = KFELDSPAR_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d2gdt2(double t, double p):
    result = KFELDSPAR_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d2gdtdp(double t, double p):
    result = KFELDSPAR_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d2gdp2(double t, double p):
    result = KFELDSPAR_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d3gdt3(double t, double p):
    result = KFELDSPAR_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d3gdt2dp(double t, double p):
    result = KFELDSPAR_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d3gdtdp2(double t, double p):
    result = KFELDSPAR_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_d3gdp3(double t, double p):
    result = KFELDSPAR_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_s(double t, double p):
    result = KFELDSPAR_dewminerals_s(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_v(double t, double p):
    result = KFELDSPAR_dewminerals_v(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_cv(double t, double p):
    result = KFELDSPAR_dewminerals_cv(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_cp(double t, double p):
    result = KFELDSPAR_dewminerals_cp(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_dcpdt(double t, double p):
    result = KFELDSPAR_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_alpha(double t, double p):
    result = KFELDSPAR_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_beta(double t, double p):
    result = KFELDSPAR_dewminerals_beta(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_K(double t, double p):
    result = KFELDSPAR_dewminerals_K(<double> t, <double> p)
    return result
def cy_KFELDSPAR_dewminerals_Kp(double t, double p):
    result = KFELDSPAR_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CORDIERITE_dewminerals_calc.h":
    const char *CORDIERITE_dewminerals_identifier();
    const char *CORDIERITE_dewminerals_name();
    const char *CORDIERITE_dewminerals_formula();
    const double CORDIERITE_dewminerals_mw();
    const double *CORDIERITE_dewminerals_elements();
    double CORDIERITE_dewminerals_g(double t, double p)
    double CORDIERITE_dewminerals_dgdt(double t, double p)
    double CORDIERITE_dewminerals_dgdp(double t, double p)
    double CORDIERITE_dewminerals_d2gdt2(double t, double p)
    double CORDIERITE_dewminerals_d2gdtdp(double t, double p)
    double CORDIERITE_dewminerals_d2gdp2(double t, double p)
    double CORDIERITE_dewminerals_d3gdt3(double t, double p)
    double CORDIERITE_dewminerals_d3gdt2dp(double t, double p)
    double CORDIERITE_dewminerals_d3gdtdp2(double t, double p)
    double CORDIERITE_dewminerals_d3gdp3(double t, double p)
    double CORDIERITE_dewminerals_s(double t, double p)
    double CORDIERITE_dewminerals_v(double t, double p)
    double CORDIERITE_dewminerals_cv(double t, double p)
    double CORDIERITE_dewminerals_cp(double t, double p)
    double CORDIERITE_dewminerals_dcpdt(double t, double p)
    double CORDIERITE_dewminerals_alpha(double t, double p)
    double CORDIERITE_dewminerals_beta(double t, double p)
    double CORDIERITE_dewminerals_K(double t, double p)
    double CORDIERITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CORDIERITE_dewminerals_identifier():
    result = <bytes> CORDIERITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CORDIERITE_dewminerals_name():
    result = <bytes> CORDIERITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CORDIERITE_dewminerals_formula():
    result = <bytes> CORDIERITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CORDIERITE_dewminerals_mw():
    result = CORDIERITE_dewminerals_mw()
    return result
def cy_CORDIERITE_dewminerals_elements():
    cdef const double *e = CORDIERITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CORDIERITE_dewminerals_g(double t, double p):
    result = CORDIERITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_dgdt(double t, double p):
    result = CORDIERITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_dgdp(double t, double p):
    result = CORDIERITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d2gdt2(double t, double p):
    result = CORDIERITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d2gdtdp(double t, double p):
    result = CORDIERITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d2gdp2(double t, double p):
    result = CORDIERITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d3gdt3(double t, double p):
    result = CORDIERITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d3gdt2dp(double t, double p):
    result = CORDIERITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d3gdtdp2(double t, double p):
    result = CORDIERITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_d3gdp3(double t, double p):
    result = CORDIERITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_s(double t, double p):
    result = CORDIERITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_v(double t, double p):
    result = CORDIERITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_cv(double t, double p):
    result = CORDIERITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_cp(double t, double p):
    result = CORDIERITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_dcpdt(double t, double p):
    result = CORDIERITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_alpha(double t, double p):
    result = CORDIERITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_beta(double t, double p):
    result = CORDIERITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_K(double t, double p):
    result = CORDIERITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CORDIERITE_dewminerals_Kp(double t, double p):
    result = CORDIERITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ANTHOPHYLLITE_dewminerals_calc.h":
    const char *ANTHOPHYLLITE_dewminerals_identifier();
    const char *ANTHOPHYLLITE_dewminerals_name();
    const char *ANTHOPHYLLITE_dewminerals_formula();
    const double ANTHOPHYLLITE_dewminerals_mw();
    const double *ANTHOPHYLLITE_dewminerals_elements();
    double ANTHOPHYLLITE_dewminerals_g(double t, double p)
    double ANTHOPHYLLITE_dewminerals_dgdt(double t, double p)
    double ANTHOPHYLLITE_dewminerals_dgdp(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d2gdt2(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d2gdtdp(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d2gdp2(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d3gdt3(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d3gdt2dp(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d3gdtdp2(double t, double p)
    double ANTHOPHYLLITE_dewminerals_d3gdp3(double t, double p)
    double ANTHOPHYLLITE_dewminerals_s(double t, double p)
    double ANTHOPHYLLITE_dewminerals_v(double t, double p)
    double ANTHOPHYLLITE_dewminerals_cv(double t, double p)
    double ANTHOPHYLLITE_dewminerals_cp(double t, double p)
    double ANTHOPHYLLITE_dewminerals_dcpdt(double t, double p)
    double ANTHOPHYLLITE_dewminerals_alpha(double t, double p)
    double ANTHOPHYLLITE_dewminerals_beta(double t, double p)
    double ANTHOPHYLLITE_dewminerals_K(double t, double p)
    double ANTHOPHYLLITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ANTHOPHYLLITE_dewminerals_identifier():
    result = <bytes> ANTHOPHYLLITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ANTHOPHYLLITE_dewminerals_name():
    result = <bytes> ANTHOPHYLLITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ANTHOPHYLLITE_dewminerals_formula():
    result = <bytes> ANTHOPHYLLITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ANTHOPHYLLITE_dewminerals_mw():
    result = ANTHOPHYLLITE_dewminerals_mw()
    return result
def cy_ANTHOPHYLLITE_dewminerals_elements():
    cdef const double *e = ANTHOPHYLLITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ANTHOPHYLLITE_dewminerals_g(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_dgdt(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_dgdp(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d2gdt2(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d2gdtdp(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d2gdp2(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d3gdt3(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d3gdt2dp(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d3gdtdp2(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_d3gdp3(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_s(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_v(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_cv(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_cp(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_dcpdt(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_alpha(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_beta(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_K(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ANTHOPHYLLITE_dewminerals_Kp(double t, double p):
    result = ANTHOPHYLLITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "TREMOLITE_dewminerals_calc.h":
    const char *TREMOLITE_dewminerals_identifier();
    const char *TREMOLITE_dewminerals_name();
    const char *TREMOLITE_dewminerals_formula();
    const double TREMOLITE_dewminerals_mw();
    const double *TREMOLITE_dewminerals_elements();
    double TREMOLITE_dewminerals_g(double t, double p)
    double TREMOLITE_dewminerals_dgdt(double t, double p)
    double TREMOLITE_dewminerals_dgdp(double t, double p)
    double TREMOLITE_dewminerals_d2gdt2(double t, double p)
    double TREMOLITE_dewminerals_d2gdtdp(double t, double p)
    double TREMOLITE_dewminerals_d2gdp2(double t, double p)
    double TREMOLITE_dewminerals_d3gdt3(double t, double p)
    double TREMOLITE_dewminerals_d3gdt2dp(double t, double p)
    double TREMOLITE_dewminerals_d3gdtdp2(double t, double p)
    double TREMOLITE_dewminerals_d3gdp3(double t, double p)
    double TREMOLITE_dewminerals_s(double t, double p)
    double TREMOLITE_dewminerals_v(double t, double p)
    double TREMOLITE_dewminerals_cv(double t, double p)
    double TREMOLITE_dewminerals_cp(double t, double p)
    double TREMOLITE_dewminerals_dcpdt(double t, double p)
    double TREMOLITE_dewminerals_alpha(double t, double p)
    double TREMOLITE_dewminerals_beta(double t, double p)
    double TREMOLITE_dewminerals_K(double t, double p)
    double TREMOLITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_TREMOLITE_dewminerals_identifier():
    result = <bytes> TREMOLITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_TREMOLITE_dewminerals_name():
    result = <bytes> TREMOLITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_TREMOLITE_dewminerals_formula():
    result = <bytes> TREMOLITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_TREMOLITE_dewminerals_mw():
    result = TREMOLITE_dewminerals_mw()
    return result
def cy_TREMOLITE_dewminerals_elements():
    cdef const double *e = TREMOLITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_TREMOLITE_dewminerals_g(double t, double p):
    result = TREMOLITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_dgdt(double t, double p):
    result = TREMOLITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_dgdp(double t, double p):
    result = TREMOLITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d2gdt2(double t, double p):
    result = TREMOLITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d2gdtdp(double t, double p):
    result = TREMOLITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d2gdp2(double t, double p):
    result = TREMOLITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d3gdt3(double t, double p):
    result = TREMOLITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d3gdt2dp(double t, double p):
    result = TREMOLITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d3gdtdp2(double t, double p):
    result = TREMOLITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_d3gdp3(double t, double p):
    result = TREMOLITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_s(double t, double p):
    result = TREMOLITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_v(double t, double p):
    result = TREMOLITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_cv(double t, double p):
    result = TREMOLITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_cp(double t, double p):
    result = TREMOLITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_dcpdt(double t, double p):
    result = TREMOLITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_alpha(double t, double p):
    result = TREMOLITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_beta(double t, double p):
    result = TREMOLITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_K(double t, double p):
    result = TREMOLITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_TREMOLITE_dewminerals_Kp(double t, double p):
    result = TREMOLITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PSEUDOWOLLA_dewminerals_calc.h":
    const char *PSEUDOWOLLA_dewminerals_identifier();
    const char *PSEUDOWOLLA_dewminerals_name();
    const char *PSEUDOWOLLA_dewminerals_formula();
    const double PSEUDOWOLLA_dewminerals_mw();
    const double *PSEUDOWOLLA_dewminerals_elements();
    double PSEUDOWOLLA_dewminerals_g(double t, double p)
    double PSEUDOWOLLA_dewminerals_dgdt(double t, double p)
    double PSEUDOWOLLA_dewminerals_dgdp(double t, double p)
    double PSEUDOWOLLA_dewminerals_d2gdt2(double t, double p)
    double PSEUDOWOLLA_dewminerals_d2gdtdp(double t, double p)
    double PSEUDOWOLLA_dewminerals_d2gdp2(double t, double p)
    double PSEUDOWOLLA_dewminerals_d3gdt3(double t, double p)
    double PSEUDOWOLLA_dewminerals_d3gdt2dp(double t, double p)
    double PSEUDOWOLLA_dewminerals_d3gdtdp2(double t, double p)
    double PSEUDOWOLLA_dewminerals_d3gdp3(double t, double p)
    double PSEUDOWOLLA_dewminerals_s(double t, double p)
    double PSEUDOWOLLA_dewminerals_v(double t, double p)
    double PSEUDOWOLLA_dewminerals_cv(double t, double p)
    double PSEUDOWOLLA_dewminerals_cp(double t, double p)
    double PSEUDOWOLLA_dewminerals_dcpdt(double t, double p)
    double PSEUDOWOLLA_dewminerals_alpha(double t, double p)
    double PSEUDOWOLLA_dewminerals_beta(double t, double p)
    double PSEUDOWOLLA_dewminerals_K(double t, double p)
    double PSEUDOWOLLA_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PSEUDOWOLLA_dewminerals_identifier():
    result = <bytes> PSEUDOWOLLA_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PSEUDOWOLLA_dewminerals_name():
    result = <bytes> PSEUDOWOLLA_dewminerals_name()
    return result.decode('UTF-8')
def cy_PSEUDOWOLLA_dewminerals_formula():
    result = <bytes> PSEUDOWOLLA_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PSEUDOWOLLA_dewminerals_mw():
    result = PSEUDOWOLLA_dewminerals_mw()
    return result
def cy_PSEUDOWOLLA_dewminerals_elements():
    cdef const double *e = PSEUDOWOLLA_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PSEUDOWOLLA_dewminerals_g(double t, double p):
    result = PSEUDOWOLLA_dewminerals_g(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_dgdt(double t, double p):
    result = PSEUDOWOLLA_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_dgdp(double t, double p):
    result = PSEUDOWOLLA_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d2gdt2(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d2gdtdp(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d2gdp2(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d3gdt3(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d3gdt2dp(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d3gdtdp2(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_d3gdp3(double t, double p):
    result = PSEUDOWOLLA_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_s(double t, double p):
    result = PSEUDOWOLLA_dewminerals_s(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_v(double t, double p):
    result = PSEUDOWOLLA_dewminerals_v(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_cv(double t, double p):
    result = PSEUDOWOLLA_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_cp(double t, double p):
    result = PSEUDOWOLLA_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_dcpdt(double t, double p):
    result = PSEUDOWOLLA_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_alpha(double t, double p):
    result = PSEUDOWOLLA_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_beta(double t, double p):
    result = PSEUDOWOLLA_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_K(double t, double p):
    result = PSEUDOWOLLA_dewminerals_K(<double> t, <double> p)
    return result
def cy_PSEUDOWOLLA_dewminerals_Kp(double t, double p):
    result = PSEUDOWOLLA_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "WOLLASTONITE_dewminerals_calc.h":
    const char *WOLLASTONITE_dewminerals_identifier();
    const char *WOLLASTONITE_dewminerals_name();
    const char *WOLLASTONITE_dewminerals_formula();
    const double WOLLASTONITE_dewminerals_mw();
    const double *WOLLASTONITE_dewminerals_elements();
    double WOLLASTONITE_dewminerals_g(double t, double p)
    double WOLLASTONITE_dewminerals_dgdt(double t, double p)
    double WOLLASTONITE_dewminerals_dgdp(double t, double p)
    double WOLLASTONITE_dewminerals_d2gdt2(double t, double p)
    double WOLLASTONITE_dewminerals_d2gdtdp(double t, double p)
    double WOLLASTONITE_dewminerals_d2gdp2(double t, double p)
    double WOLLASTONITE_dewminerals_d3gdt3(double t, double p)
    double WOLLASTONITE_dewminerals_d3gdt2dp(double t, double p)
    double WOLLASTONITE_dewminerals_d3gdtdp2(double t, double p)
    double WOLLASTONITE_dewminerals_d3gdp3(double t, double p)
    double WOLLASTONITE_dewminerals_s(double t, double p)
    double WOLLASTONITE_dewminerals_v(double t, double p)
    double WOLLASTONITE_dewminerals_cv(double t, double p)
    double WOLLASTONITE_dewminerals_cp(double t, double p)
    double WOLLASTONITE_dewminerals_dcpdt(double t, double p)
    double WOLLASTONITE_dewminerals_alpha(double t, double p)
    double WOLLASTONITE_dewminerals_beta(double t, double p)
    double WOLLASTONITE_dewminerals_K(double t, double p)
    double WOLLASTONITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_WOLLASTONITE_dewminerals_identifier():
    result = <bytes> WOLLASTONITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_WOLLASTONITE_dewminerals_name():
    result = <bytes> WOLLASTONITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_WOLLASTONITE_dewminerals_formula():
    result = <bytes> WOLLASTONITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_WOLLASTONITE_dewminerals_mw():
    result = WOLLASTONITE_dewminerals_mw()
    return result
def cy_WOLLASTONITE_dewminerals_elements():
    cdef const double *e = WOLLASTONITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_WOLLASTONITE_dewminerals_g(double t, double p):
    result = WOLLASTONITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_dgdt(double t, double p):
    result = WOLLASTONITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_dgdp(double t, double p):
    result = WOLLASTONITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d2gdt2(double t, double p):
    result = WOLLASTONITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d2gdtdp(double t, double p):
    result = WOLLASTONITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d2gdp2(double t, double p):
    result = WOLLASTONITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d3gdt3(double t, double p):
    result = WOLLASTONITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d3gdt2dp(double t, double p):
    result = WOLLASTONITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d3gdtdp2(double t, double p):
    result = WOLLASTONITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_d3gdp3(double t, double p):
    result = WOLLASTONITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_s(double t, double p):
    result = WOLLASTONITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_v(double t, double p):
    result = WOLLASTONITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_cv(double t, double p):
    result = WOLLASTONITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_cp(double t, double p):
    result = WOLLASTONITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_dcpdt(double t, double p):
    result = WOLLASTONITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_alpha(double t, double p):
    result = WOLLASTONITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_beta(double t, double p):
    result = WOLLASTONITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_K(double t, double p):
    result = WOLLASTONITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_WOLLASTONITE_dewminerals_Kp(double t, double p):
    result = WOLLASTONITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "FERROSILITE_dewminerals_calc.h":
    const char *FERROSILITE_dewminerals_identifier();
    const char *FERROSILITE_dewminerals_name();
    const char *FERROSILITE_dewminerals_formula();
    const double FERROSILITE_dewminerals_mw();
    const double *FERROSILITE_dewminerals_elements();
    double FERROSILITE_dewminerals_g(double t, double p)
    double FERROSILITE_dewminerals_dgdt(double t, double p)
    double FERROSILITE_dewminerals_dgdp(double t, double p)
    double FERROSILITE_dewminerals_d2gdt2(double t, double p)
    double FERROSILITE_dewminerals_d2gdtdp(double t, double p)
    double FERROSILITE_dewminerals_d2gdp2(double t, double p)
    double FERROSILITE_dewminerals_d3gdt3(double t, double p)
    double FERROSILITE_dewminerals_d3gdt2dp(double t, double p)
    double FERROSILITE_dewminerals_d3gdtdp2(double t, double p)
    double FERROSILITE_dewminerals_d3gdp3(double t, double p)
    double FERROSILITE_dewminerals_s(double t, double p)
    double FERROSILITE_dewminerals_v(double t, double p)
    double FERROSILITE_dewminerals_cv(double t, double p)
    double FERROSILITE_dewminerals_cp(double t, double p)
    double FERROSILITE_dewminerals_dcpdt(double t, double p)
    double FERROSILITE_dewminerals_alpha(double t, double p)
    double FERROSILITE_dewminerals_beta(double t, double p)
    double FERROSILITE_dewminerals_K(double t, double p)
    double FERROSILITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_FERROSILITE_dewminerals_identifier():
    result = <bytes> FERROSILITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_FERROSILITE_dewminerals_name():
    result = <bytes> FERROSILITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_FERROSILITE_dewminerals_formula():
    result = <bytes> FERROSILITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_FERROSILITE_dewminerals_mw():
    result = FERROSILITE_dewminerals_mw()
    return result
def cy_FERROSILITE_dewminerals_elements():
    cdef const double *e = FERROSILITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_FERROSILITE_dewminerals_g(double t, double p):
    result = FERROSILITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_dgdt(double t, double p):
    result = FERROSILITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_dgdp(double t, double p):
    result = FERROSILITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d2gdt2(double t, double p):
    result = FERROSILITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d2gdtdp(double t, double p):
    result = FERROSILITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d2gdp2(double t, double p):
    result = FERROSILITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d3gdt3(double t, double p):
    result = FERROSILITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d3gdt2dp(double t, double p):
    result = FERROSILITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d3gdtdp2(double t, double p):
    result = FERROSILITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_d3gdp3(double t, double p):
    result = FERROSILITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_s(double t, double p):
    result = FERROSILITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_v(double t, double p):
    result = FERROSILITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_cv(double t, double p):
    result = FERROSILITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_cp(double t, double p):
    result = FERROSILITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_dcpdt(double t, double p):
    result = FERROSILITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_alpha(double t, double p):
    result = FERROSILITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_beta(double t, double p):
    result = FERROSILITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_K(double t, double p):
    result = FERROSILITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_FERROSILITE_dewminerals_Kp(double t, double p):
    result = FERROSILITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CAALPYROXENE_dewminerals_calc.h":
    const char *CAALPYROXENE_dewminerals_identifier();
    const char *CAALPYROXENE_dewminerals_name();
    const char *CAALPYROXENE_dewminerals_formula();
    const double CAALPYROXENE_dewminerals_mw();
    const double *CAALPYROXENE_dewminerals_elements();
    double CAALPYROXENE_dewminerals_g(double t, double p)
    double CAALPYROXENE_dewminerals_dgdt(double t, double p)
    double CAALPYROXENE_dewminerals_dgdp(double t, double p)
    double CAALPYROXENE_dewminerals_d2gdt2(double t, double p)
    double CAALPYROXENE_dewminerals_d2gdtdp(double t, double p)
    double CAALPYROXENE_dewminerals_d2gdp2(double t, double p)
    double CAALPYROXENE_dewminerals_d3gdt3(double t, double p)
    double CAALPYROXENE_dewminerals_d3gdt2dp(double t, double p)
    double CAALPYROXENE_dewminerals_d3gdtdp2(double t, double p)
    double CAALPYROXENE_dewminerals_d3gdp3(double t, double p)
    double CAALPYROXENE_dewminerals_s(double t, double p)
    double CAALPYROXENE_dewminerals_v(double t, double p)
    double CAALPYROXENE_dewminerals_cv(double t, double p)
    double CAALPYROXENE_dewminerals_cp(double t, double p)
    double CAALPYROXENE_dewminerals_dcpdt(double t, double p)
    double CAALPYROXENE_dewminerals_alpha(double t, double p)
    double CAALPYROXENE_dewminerals_beta(double t, double p)
    double CAALPYROXENE_dewminerals_K(double t, double p)
    double CAALPYROXENE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CAALPYROXENE_dewminerals_identifier():
    result = <bytes> CAALPYROXENE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CAALPYROXENE_dewminerals_name():
    result = <bytes> CAALPYROXENE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CAALPYROXENE_dewminerals_formula():
    result = <bytes> CAALPYROXENE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CAALPYROXENE_dewminerals_mw():
    result = CAALPYROXENE_dewminerals_mw()
    return result
def cy_CAALPYROXENE_dewminerals_elements():
    cdef const double *e = CAALPYROXENE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CAALPYROXENE_dewminerals_g(double t, double p):
    result = CAALPYROXENE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_dgdt(double t, double p):
    result = CAALPYROXENE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_dgdp(double t, double p):
    result = CAALPYROXENE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d2gdt2(double t, double p):
    result = CAALPYROXENE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d2gdtdp(double t, double p):
    result = CAALPYROXENE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d2gdp2(double t, double p):
    result = CAALPYROXENE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d3gdt3(double t, double p):
    result = CAALPYROXENE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d3gdt2dp(double t, double p):
    result = CAALPYROXENE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d3gdtdp2(double t, double p):
    result = CAALPYROXENE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_d3gdp3(double t, double p):
    result = CAALPYROXENE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_s(double t, double p):
    result = CAALPYROXENE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_v(double t, double p):
    result = CAALPYROXENE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_cv(double t, double p):
    result = CAALPYROXENE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_cp(double t, double p):
    result = CAALPYROXENE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_dcpdt(double t, double p):
    result = CAALPYROXENE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_alpha(double t, double p):
    result = CAALPYROXENE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_beta(double t, double p):
    result = CAALPYROXENE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_K(double t, double p):
    result = CAALPYROXENE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CAALPYROXENE_dewminerals_Kp(double t, double p):
    result = CAALPYROXENE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "JADEITE_dewminerals_calc.h":
    const char *JADEITE_dewminerals_identifier();
    const char *JADEITE_dewminerals_name();
    const char *JADEITE_dewminerals_formula();
    const double JADEITE_dewminerals_mw();
    const double *JADEITE_dewminerals_elements();
    double JADEITE_dewminerals_g(double t, double p)
    double JADEITE_dewminerals_dgdt(double t, double p)
    double JADEITE_dewminerals_dgdp(double t, double p)
    double JADEITE_dewminerals_d2gdt2(double t, double p)
    double JADEITE_dewminerals_d2gdtdp(double t, double p)
    double JADEITE_dewminerals_d2gdp2(double t, double p)
    double JADEITE_dewminerals_d3gdt3(double t, double p)
    double JADEITE_dewminerals_d3gdt2dp(double t, double p)
    double JADEITE_dewminerals_d3gdtdp2(double t, double p)
    double JADEITE_dewminerals_d3gdp3(double t, double p)
    double JADEITE_dewminerals_s(double t, double p)
    double JADEITE_dewminerals_v(double t, double p)
    double JADEITE_dewminerals_cv(double t, double p)
    double JADEITE_dewminerals_cp(double t, double p)
    double JADEITE_dewminerals_dcpdt(double t, double p)
    double JADEITE_dewminerals_alpha(double t, double p)
    double JADEITE_dewminerals_beta(double t, double p)
    double JADEITE_dewminerals_K(double t, double p)
    double JADEITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_JADEITE_dewminerals_identifier():
    result = <bytes> JADEITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_JADEITE_dewminerals_name():
    result = <bytes> JADEITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_JADEITE_dewminerals_formula():
    result = <bytes> JADEITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_JADEITE_dewminerals_mw():
    result = JADEITE_dewminerals_mw()
    return result
def cy_JADEITE_dewminerals_elements():
    cdef const double *e = JADEITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_JADEITE_dewminerals_g(double t, double p):
    result = JADEITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_dgdt(double t, double p):
    result = JADEITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_dgdp(double t, double p):
    result = JADEITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d2gdt2(double t, double p):
    result = JADEITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d2gdtdp(double t, double p):
    result = JADEITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d2gdp2(double t, double p):
    result = JADEITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d3gdt3(double t, double p):
    result = JADEITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d3gdt2dp(double t, double p):
    result = JADEITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d3gdtdp2(double t, double p):
    result = JADEITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_d3gdp3(double t, double p):
    result = JADEITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_s(double t, double p):
    result = JADEITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_v(double t, double p):
    result = JADEITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_cv(double t, double p):
    result = JADEITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_cp(double t, double p):
    result = JADEITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_dcpdt(double t, double p):
    result = JADEITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_alpha(double t, double p):
    result = JADEITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_beta(double t, double p):
    result = JADEITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_K(double t, double p):
    result = JADEITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_JADEITE_dewminerals_Kp(double t, double p):
    result = JADEITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "HEDENBERGITE_dewminerals_calc.h":
    const char *HEDENBERGITE_dewminerals_identifier();
    const char *HEDENBERGITE_dewminerals_name();
    const char *HEDENBERGITE_dewminerals_formula();
    const double HEDENBERGITE_dewminerals_mw();
    const double *HEDENBERGITE_dewminerals_elements();
    double HEDENBERGITE_dewminerals_g(double t, double p)
    double HEDENBERGITE_dewminerals_dgdt(double t, double p)
    double HEDENBERGITE_dewminerals_dgdp(double t, double p)
    double HEDENBERGITE_dewminerals_d2gdt2(double t, double p)
    double HEDENBERGITE_dewminerals_d2gdtdp(double t, double p)
    double HEDENBERGITE_dewminerals_d2gdp2(double t, double p)
    double HEDENBERGITE_dewminerals_d3gdt3(double t, double p)
    double HEDENBERGITE_dewminerals_d3gdt2dp(double t, double p)
    double HEDENBERGITE_dewminerals_d3gdtdp2(double t, double p)
    double HEDENBERGITE_dewminerals_d3gdp3(double t, double p)
    double HEDENBERGITE_dewminerals_s(double t, double p)
    double HEDENBERGITE_dewminerals_v(double t, double p)
    double HEDENBERGITE_dewminerals_cv(double t, double p)
    double HEDENBERGITE_dewminerals_cp(double t, double p)
    double HEDENBERGITE_dewminerals_dcpdt(double t, double p)
    double HEDENBERGITE_dewminerals_alpha(double t, double p)
    double HEDENBERGITE_dewminerals_beta(double t, double p)
    double HEDENBERGITE_dewminerals_K(double t, double p)
    double HEDENBERGITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_HEDENBERGITE_dewminerals_identifier():
    result = <bytes> HEDENBERGITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_HEDENBERGITE_dewminerals_name():
    result = <bytes> HEDENBERGITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_HEDENBERGITE_dewminerals_formula():
    result = <bytes> HEDENBERGITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_HEDENBERGITE_dewminerals_mw():
    result = HEDENBERGITE_dewminerals_mw()
    return result
def cy_HEDENBERGITE_dewminerals_elements():
    cdef const double *e = HEDENBERGITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_HEDENBERGITE_dewminerals_g(double t, double p):
    result = HEDENBERGITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_dgdt(double t, double p):
    result = HEDENBERGITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_dgdp(double t, double p):
    result = HEDENBERGITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d2gdt2(double t, double p):
    result = HEDENBERGITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d2gdtdp(double t, double p):
    result = HEDENBERGITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d2gdp2(double t, double p):
    result = HEDENBERGITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d3gdt3(double t, double p):
    result = HEDENBERGITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d3gdt2dp(double t, double p):
    result = HEDENBERGITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d3gdtdp2(double t, double p):
    result = HEDENBERGITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_d3gdp3(double t, double p):
    result = HEDENBERGITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_s(double t, double p):
    result = HEDENBERGITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_v(double t, double p):
    result = HEDENBERGITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_cv(double t, double p):
    result = HEDENBERGITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_cp(double t, double p):
    result = HEDENBERGITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_dcpdt(double t, double p):
    result = HEDENBERGITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_alpha(double t, double p):
    result = HEDENBERGITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_beta(double t, double p):
    result = HEDENBERGITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_K(double t, double p):
    result = HEDENBERGITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_HEDENBERGITE_dewminerals_Kp(double t, double p):
    result = HEDENBERGITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "DIOPSIDE_dewminerals_calc.h":
    const char *DIOPSIDE_dewminerals_identifier();
    const char *DIOPSIDE_dewminerals_name();
    const char *DIOPSIDE_dewminerals_formula();
    const double DIOPSIDE_dewminerals_mw();
    const double *DIOPSIDE_dewminerals_elements();
    double DIOPSIDE_dewminerals_g(double t, double p)
    double DIOPSIDE_dewminerals_dgdt(double t, double p)
    double DIOPSIDE_dewminerals_dgdp(double t, double p)
    double DIOPSIDE_dewminerals_d2gdt2(double t, double p)
    double DIOPSIDE_dewminerals_d2gdtdp(double t, double p)
    double DIOPSIDE_dewminerals_d2gdp2(double t, double p)
    double DIOPSIDE_dewminerals_d3gdt3(double t, double p)
    double DIOPSIDE_dewminerals_d3gdt2dp(double t, double p)
    double DIOPSIDE_dewminerals_d3gdtdp2(double t, double p)
    double DIOPSIDE_dewminerals_d3gdp3(double t, double p)
    double DIOPSIDE_dewminerals_s(double t, double p)
    double DIOPSIDE_dewminerals_v(double t, double p)
    double DIOPSIDE_dewminerals_cv(double t, double p)
    double DIOPSIDE_dewminerals_cp(double t, double p)
    double DIOPSIDE_dewminerals_dcpdt(double t, double p)
    double DIOPSIDE_dewminerals_alpha(double t, double p)
    double DIOPSIDE_dewminerals_beta(double t, double p)
    double DIOPSIDE_dewminerals_K(double t, double p)
    double DIOPSIDE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_DIOPSIDE_dewminerals_identifier():
    result = <bytes> DIOPSIDE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_DIOPSIDE_dewminerals_name():
    result = <bytes> DIOPSIDE_dewminerals_name()
    return result.decode('UTF-8')
def cy_DIOPSIDE_dewminerals_formula():
    result = <bytes> DIOPSIDE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_DIOPSIDE_dewminerals_mw():
    result = DIOPSIDE_dewminerals_mw()
    return result
def cy_DIOPSIDE_dewminerals_elements():
    cdef const double *e = DIOPSIDE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_DIOPSIDE_dewminerals_g(double t, double p):
    result = DIOPSIDE_dewminerals_g(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_dgdt(double t, double p):
    result = DIOPSIDE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_dgdp(double t, double p):
    result = DIOPSIDE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d2gdt2(double t, double p):
    result = DIOPSIDE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d2gdtdp(double t, double p):
    result = DIOPSIDE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d2gdp2(double t, double p):
    result = DIOPSIDE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d3gdt3(double t, double p):
    result = DIOPSIDE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d3gdt2dp(double t, double p):
    result = DIOPSIDE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d3gdtdp2(double t, double p):
    result = DIOPSIDE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_d3gdp3(double t, double p):
    result = DIOPSIDE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_s(double t, double p):
    result = DIOPSIDE_dewminerals_s(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_v(double t, double p):
    result = DIOPSIDE_dewminerals_v(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_cv(double t, double p):
    result = DIOPSIDE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_cp(double t, double p):
    result = DIOPSIDE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_dcpdt(double t, double p):
    result = DIOPSIDE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_alpha(double t, double p):
    result = DIOPSIDE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_beta(double t, double p):
    result = DIOPSIDE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_K(double t, double p):
    result = DIOPSIDE_dewminerals_K(<double> t, <double> p)
    return result
def cy_DIOPSIDE_dewminerals_Kp(double t, double p):
    result = DIOPSIDE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ENSTATITE_PR_dewminerals_calc.h":
    const char *ENSTATITE_PR_dewminerals_identifier();
    const char *ENSTATITE_PR_dewminerals_name();
    const char *ENSTATITE_PR_dewminerals_formula();
    const double ENSTATITE_PR_dewminerals_mw();
    const double *ENSTATITE_PR_dewminerals_elements();
    double ENSTATITE_PR_dewminerals_g(double t, double p)
    double ENSTATITE_PR_dewminerals_dgdt(double t, double p)
    double ENSTATITE_PR_dewminerals_dgdp(double t, double p)
    double ENSTATITE_PR_dewminerals_d2gdt2(double t, double p)
    double ENSTATITE_PR_dewminerals_d2gdtdp(double t, double p)
    double ENSTATITE_PR_dewminerals_d2gdp2(double t, double p)
    double ENSTATITE_PR_dewminerals_d3gdt3(double t, double p)
    double ENSTATITE_PR_dewminerals_d3gdt2dp(double t, double p)
    double ENSTATITE_PR_dewminerals_d3gdtdp2(double t, double p)
    double ENSTATITE_PR_dewminerals_d3gdp3(double t, double p)
    double ENSTATITE_PR_dewminerals_s(double t, double p)
    double ENSTATITE_PR_dewminerals_v(double t, double p)
    double ENSTATITE_PR_dewminerals_cv(double t, double p)
    double ENSTATITE_PR_dewminerals_cp(double t, double p)
    double ENSTATITE_PR_dewminerals_dcpdt(double t, double p)
    double ENSTATITE_PR_dewminerals_alpha(double t, double p)
    double ENSTATITE_PR_dewminerals_beta(double t, double p)
    double ENSTATITE_PR_dewminerals_K(double t, double p)
    double ENSTATITE_PR_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ENSTATITE_PR_dewminerals_identifier():
    result = <bytes> ENSTATITE_PR_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ENSTATITE_PR_dewminerals_name():
    result = <bytes> ENSTATITE_PR_dewminerals_name()
    return result.decode('UTF-8')
def cy_ENSTATITE_PR_dewminerals_formula():
    result = <bytes> ENSTATITE_PR_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ENSTATITE_PR_dewminerals_mw():
    result = ENSTATITE_PR_dewminerals_mw()
    return result
def cy_ENSTATITE_PR_dewminerals_elements():
    cdef const double *e = ENSTATITE_PR_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ENSTATITE_PR_dewminerals_g(double t, double p):
    result = ENSTATITE_PR_dewminerals_g(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_dgdt(double t, double p):
    result = ENSTATITE_PR_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_dgdp(double t, double p):
    result = ENSTATITE_PR_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d2gdt2(double t, double p):
    result = ENSTATITE_PR_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d2gdtdp(double t, double p):
    result = ENSTATITE_PR_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d2gdp2(double t, double p):
    result = ENSTATITE_PR_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d3gdt3(double t, double p):
    result = ENSTATITE_PR_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d3gdt2dp(double t, double p):
    result = ENSTATITE_PR_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d3gdtdp2(double t, double p):
    result = ENSTATITE_PR_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_d3gdp3(double t, double p):
    result = ENSTATITE_PR_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_s(double t, double p):
    result = ENSTATITE_PR_dewminerals_s(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_v(double t, double p):
    result = ENSTATITE_PR_dewminerals_v(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_cv(double t, double p):
    result = ENSTATITE_PR_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_cp(double t, double p):
    result = ENSTATITE_PR_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_dcpdt(double t, double p):
    result = ENSTATITE_PR_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_alpha(double t, double p):
    result = ENSTATITE_PR_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_beta(double t, double p):
    result = ENSTATITE_PR_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_K(double t, double p):
    result = ENSTATITE_PR_dewminerals_K(<double> t, <double> p)
    return result
def cy_ENSTATITE_PR_dewminerals_Kp(double t, double p):
    result = ENSTATITE_PR_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ENSTATITE_OR_dewminerals_calc.h":
    const char *ENSTATITE_OR_dewminerals_identifier();
    const char *ENSTATITE_OR_dewminerals_name();
    const char *ENSTATITE_OR_dewminerals_formula();
    const double ENSTATITE_OR_dewminerals_mw();
    const double *ENSTATITE_OR_dewminerals_elements();
    double ENSTATITE_OR_dewminerals_g(double t, double p)
    double ENSTATITE_OR_dewminerals_dgdt(double t, double p)
    double ENSTATITE_OR_dewminerals_dgdp(double t, double p)
    double ENSTATITE_OR_dewminerals_d2gdt2(double t, double p)
    double ENSTATITE_OR_dewminerals_d2gdtdp(double t, double p)
    double ENSTATITE_OR_dewminerals_d2gdp2(double t, double p)
    double ENSTATITE_OR_dewminerals_d3gdt3(double t, double p)
    double ENSTATITE_OR_dewminerals_d3gdt2dp(double t, double p)
    double ENSTATITE_OR_dewminerals_d3gdtdp2(double t, double p)
    double ENSTATITE_OR_dewminerals_d3gdp3(double t, double p)
    double ENSTATITE_OR_dewminerals_s(double t, double p)
    double ENSTATITE_OR_dewminerals_v(double t, double p)
    double ENSTATITE_OR_dewminerals_cv(double t, double p)
    double ENSTATITE_OR_dewminerals_cp(double t, double p)
    double ENSTATITE_OR_dewminerals_dcpdt(double t, double p)
    double ENSTATITE_OR_dewminerals_alpha(double t, double p)
    double ENSTATITE_OR_dewminerals_beta(double t, double p)
    double ENSTATITE_OR_dewminerals_K(double t, double p)
    double ENSTATITE_OR_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ENSTATITE_OR_dewminerals_identifier():
    result = <bytes> ENSTATITE_OR_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ENSTATITE_OR_dewminerals_name():
    result = <bytes> ENSTATITE_OR_dewminerals_name()
    return result.decode('UTF-8')
def cy_ENSTATITE_OR_dewminerals_formula():
    result = <bytes> ENSTATITE_OR_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ENSTATITE_OR_dewminerals_mw():
    result = ENSTATITE_OR_dewminerals_mw()
    return result
def cy_ENSTATITE_OR_dewminerals_elements():
    cdef const double *e = ENSTATITE_OR_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ENSTATITE_OR_dewminerals_g(double t, double p):
    result = ENSTATITE_OR_dewminerals_g(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_dgdt(double t, double p):
    result = ENSTATITE_OR_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_dgdp(double t, double p):
    result = ENSTATITE_OR_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d2gdt2(double t, double p):
    result = ENSTATITE_OR_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d2gdtdp(double t, double p):
    result = ENSTATITE_OR_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d2gdp2(double t, double p):
    result = ENSTATITE_OR_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d3gdt3(double t, double p):
    result = ENSTATITE_OR_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d3gdt2dp(double t, double p):
    result = ENSTATITE_OR_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d3gdtdp2(double t, double p):
    result = ENSTATITE_OR_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_d3gdp3(double t, double p):
    result = ENSTATITE_OR_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_s(double t, double p):
    result = ENSTATITE_OR_dewminerals_s(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_v(double t, double p):
    result = ENSTATITE_OR_dewminerals_v(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_cv(double t, double p):
    result = ENSTATITE_OR_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_cp(double t, double p):
    result = ENSTATITE_OR_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_dcpdt(double t, double p):
    result = ENSTATITE_OR_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_alpha(double t, double p):
    result = ENSTATITE_OR_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_beta(double t, double p):
    result = ENSTATITE_OR_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_K(double t, double p):
    result = ENSTATITE_OR_dewminerals_K(<double> t, <double> p)
    return result
def cy_ENSTATITE_OR_dewminerals_Kp(double t, double p):
    result = ENSTATITE_OR_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ENSTATITE_CL_dewminerals_calc.h":
    const char *ENSTATITE_CL_dewminerals_identifier();
    const char *ENSTATITE_CL_dewminerals_name();
    const char *ENSTATITE_CL_dewminerals_formula();
    const double ENSTATITE_CL_dewminerals_mw();
    const double *ENSTATITE_CL_dewminerals_elements();
    double ENSTATITE_CL_dewminerals_g(double t, double p)
    double ENSTATITE_CL_dewminerals_dgdt(double t, double p)
    double ENSTATITE_CL_dewminerals_dgdp(double t, double p)
    double ENSTATITE_CL_dewminerals_d2gdt2(double t, double p)
    double ENSTATITE_CL_dewminerals_d2gdtdp(double t, double p)
    double ENSTATITE_CL_dewminerals_d2gdp2(double t, double p)
    double ENSTATITE_CL_dewminerals_d3gdt3(double t, double p)
    double ENSTATITE_CL_dewminerals_d3gdt2dp(double t, double p)
    double ENSTATITE_CL_dewminerals_d3gdtdp2(double t, double p)
    double ENSTATITE_CL_dewminerals_d3gdp3(double t, double p)
    double ENSTATITE_CL_dewminerals_s(double t, double p)
    double ENSTATITE_CL_dewminerals_v(double t, double p)
    double ENSTATITE_CL_dewminerals_cv(double t, double p)
    double ENSTATITE_CL_dewminerals_cp(double t, double p)
    double ENSTATITE_CL_dewminerals_dcpdt(double t, double p)
    double ENSTATITE_CL_dewminerals_alpha(double t, double p)
    double ENSTATITE_CL_dewminerals_beta(double t, double p)
    double ENSTATITE_CL_dewminerals_K(double t, double p)
    double ENSTATITE_CL_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ENSTATITE_CL_dewminerals_identifier():
    result = <bytes> ENSTATITE_CL_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ENSTATITE_CL_dewminerals_name():
    result = <bytes> ENSTATITE_CL_dewminerals_name()
    return result.decode('UTF-8')
def cy_ENSTATITE_CL_dewminerals_formula():
    result = <bytes> ENSTATITE_CL_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ENSTATITE_CL_dewminerals_mw():
    result = ENSTATITE_CL_dewminerals_mw()
    return result
def cy_ENSTATITE_CL_dewminerals_elements():
    cdef const double *e = ENSTATITE_CL_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ENSTATITE_CL_dewminerals_g(double t, double p):
    result = ENSTATITE_CL_dewminerals_g(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_dgdt(double t, double p):
    result = ENSTATITE_CL_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_dgdp(double t, double p):
    result = ENSTATITE_CL_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d2gdt2(double t, double p):
    result = ENSTATITE_CL_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d2gdtdp(double t, double p):
    result = ENSTATITE_CL_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d2gdp2(double t, double p):
    result = ENSTATITE_CL_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d3gdt3(double t, double p):
    result = ENSTATITE_CL_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d3gdt2dp(double t, double p):
    result = ENSTATITE_CL_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d3gdtdp2(double t, double p):
    result = ENSTATITE_CL_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_d3gdp3(double t, double p):
    result = ENSTATITE_CL_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_s(double t, double p):
    result = ENSTATITE_CL_dewminerals_s(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_v(double t, double p):
    result = ENSTATITE_CL_dewminerals_v(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_cv(double t, double p):
    result = ENSTATITE_CL_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_cp(double t, double p):
    result = ENSTATITE_CL_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_dcpdt(double t, double p):
    result = ENSTATITE_CL_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_alpha(double t, double p):
    result = ENSTATITE_CL_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_beta(double t, double p):
    result = ENSTATITE_CL_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_K(double t, double p):
    result = ENSTATITE_CL_dewminerals_K(<double> t, <double> p)
    return result
def cy_ENSTATITE_CL_dewminerals_Kp(double t, double p):
    result = ENSTATITE_CL_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CHRYSOTILE_dewminerals_calc.h":
    const char *CHRYSOTILE_dewminerals_identifier();
    const char *CHRYSOTILE_dewminerals_name();
    const char *CHRYSOTILE_dewminerals_formula();
    const double CHRYSOTILE_dewminerals_mw();
    const double *CHRYSOTILE_dewminerals_elements();
    double CHRYSOTILE_dewminerals_g(double t, double p)
    double CHRYSOTILE_dewminerals_dgdt(double t, double p)
    double CHRYSOTILE_dewminerals_dgdp(double t, double p)
    double CHRYSOTILE_dewminerals_d2gdt2(double t, double p)
    double CHRYSOTILE_dewminerals_d2gdtdp(double t, double p)
    double CHRYSOTILE_dewminerals_d2gdp2(double t, double p)
    double CHRYSOTILE_dewminerals_d3gdt3(double t, double p)
    double CHRYSOTILE_dewminerals_d3gdt2dp(double t, double p)
    double CHRYSOTILE_dewminerals_d3gdtdp2(double t, double p)
    double CHRYSOTILE_dewminerals_d3gdp3(double t, double p)
    double CHRYSOTILE_dewminerals_s(double t, double p)
    double CHRYSOTILE_dewminerals_v(double t, double p)
    double CHRYSOTILE_dewminerals_cv(double t, double p)
    double CHRYSOTILE_dewminerals_cp(double t, double p)
    double CHRYSOTILE_dewminerals_dcpdt(double t, double p)
    double CHRYSOTILE_dewminerals_alpha(double t, double p)
    double CHRYSOTILE_dewminerals_beta(double t, double p)
    double CHRYSOTILE_dewminerals_K(double t, double p)
    double CHRYSOTILE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CHRYSOTILE_dewminerals_identifier():
    result = <bytes> CHRYSOTILE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CHRYSOTILE_dewminerals_name():
    result = <bytes> CHRYSOTILE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CHRYSOTILE_dewminerals_formula():
    result = <bytes> CHRYSOTILE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CHRYSOTILE_dewminerals_mw():
    result = CHRYSOTILE_dewminerals_mw()
    return result
def cy_CHRYSOTILE_dewminerals_elements():
    cdef const double *e = CHRYSOTILE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CHRYSOTILE_dewminerals_g(double t, double p):
    result = CHRYSOTILE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_dgdt(double t, double p):
    result = CHRYSOTILE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_dgdp(double t, double p):
    result = CHRYSOTILE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d2gdt2(double t, double p):
    result = CHRYSOTILE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d2gdtdp(double t, double p):
    result = CHRYSOTILE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d2gdp2(double t, double p):
    result = CHRYSOTILE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d3gdt3(double t, double p):
    result = CHRYSOTILE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d3gdt2dp(double t, double p):
    result = CHRYSOTILE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d3gdtdp2(double t, double p):
    result = CHRYSOTILE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_d3gdp3(double t, double p):
    result = CHRYSOTILE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_s(double t, double p):
    result = CHRYSOTILE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_v(double t, double p):
    result = CHRYSOTILE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_cv(double t, double p):
    result = CHRYSOTILE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_cp(double t, double p):
    result = CHRYSOTILE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_dcpdt(double t, double p):
    result = CHRYSOTILE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_alpha(double t, double p):
    result = CHRYSOTILE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_beta(double t, double p):
    result = CHRYSOTILE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_K(double t, double p):
    result = CHRYSOTILE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CHRYSOTILE_dewminerals_Kp(double t, double p):
    result = CHRYSOTILE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MERWINITE_dewminerals_calc.h":
    const char *MERWINITE_dewminerals_identifier();
    const char *MERWINITE_dewminerals_name();
    const char *MERWINITE_dewminerals_formula();
    const double MERWINITE_dewminerals_mw();
    const double *MERWINITE_dewminerals_elements();
    double MERWINITE_dewminerals_g(double t, double p)
    double MERWINITE_dewminerals_dgdt(double t, double p)
    double MERWINITE_dewminerals_dgdp(double t, double p)
    double MERWINITE_dewminerals_d2gdt2(double t, double p)
    double MERWINITE_dewminerals_d2gdtdp(double t, double p)
    double MERWINITE_dewminerals_d2gdp2(double t, double p)
    double MERWINITE_dewminerals_d3gdt3(double t, double p)
    double MERWINITE_dewminerals_d3gdt2dp(double t, double p)
    double MERWINITE_dewminerals_d3gdtdp2(double t, double p)
    double MERWINITE_dewminerals_d3gdp3(double t, double p)
    double MERWINITE_dewminerals_s(double t, double p)
    double MERWINITE_dewminerals_v(double t, double p)
    double MERWINITE_dewminerals_cv(double t, double p)
    double MERWINITE_dewminerals_cp(double t, double p)
    double MERWINITE_dewminerals_dcpdt(double t, double p)
    double MERWINITE_dewminerals_alpha(double t, double p)
    double MERWINITE_dewminerals_beta(double t, double p)
    double MERWINITE_dewminerals_K(double t, double p)
    double MERWINITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MERWINITE_dewminerals_identifier():
    result = <bytes> MERWINITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MERWINITE_dewminerals_name():
    result = <bytes> MERWINITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MERWINITE_dewminerals_formula():
    result = <bytes> MERWINITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MERWINITE_dewminerals_mw():
    result = MERWINITE_dewminerals_mw()
    return result
def cy_MERWINITE_dewminerals_elements():
    cdef const double *e = MERWINITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MERWINITE_dewminerals_g(double t, double p):
    result = MERWINITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_dgdt(double t, double p):
    result = MERWINITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_dgdp(double t, double p):
    result = MERWINITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d2gdt2(double t, double p):
    result = MERWINITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d2gdtdp(double t, double p):
    result = MERWINITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d2gdp2(double t, double p):
    result = MERWINITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d3gdt3(double t, double p):
    result = MERWINITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d3gdt2dp(double t, double p):
    result = MERWINITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d3gdtdp2(double t, double p):
    result = MERWINITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_d3gdp3(double t, double p):
    result = MERWINITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_s(double t, double p):
    result = MERWINITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_v(double t, double p):
    result = MERWINITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_cv(double t, double p):
    result = MERWINITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_cp(double t, double p):
    result = MERWINITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_dcpdt(double t, double p):
    result = MERWINITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_alpha(double t, double p):
    result = MERWINITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_beta(double t, double p):
    result = MERWINITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_K(double t, double p):
    result = MERWINITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MERWINITE_dewminerals_Kp(double t, double p):
    result = MERWINITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MONTICELLITE_dewminerals_calc.h":
    const char *MONTICELLITE_dewminerals_identifier();
    const char *MONTICELLITE_dewminerals_name();
    const char *MONTICELLITE_dewminerals_formula();
    const double MONTICELLITE_dewminerals_mw();
    const double *MONTICELLITE_dewminerals_elements();
    double MONTICELLITE_dewminerals_g(double t, double p)
    double MONTICELLITE_dewminerals_dgdt(double t, double p)
    double MONTICELLITE_dewminerals_dgdp(double t, double p)
    double MONTICELLITE_dewminerals_d2gdt2(double t, double p)
    double MONTICELLITE_dewminerals_d2gdtdp(double t, double p)
    double MONTICELLITE_dewminerals_d2gdp2(double t, double p)
    double MONTICELLITE_dewminerals_d3gdt3(double t, double p)
    double MONTICELLITE_dewminerals_d3gdt2dp(double t, double p)
    double MONTICELLITE_dewminerals_d3gdtdp2(double t, double p)
    double MONTICELLITE_dewminerals_d3gdp3(double t, double p)
    double MONTICELLITE_dewminerals_s(double t, double p)
    double MONTICELLITE_dewminerals_v(double t, double p)
    double MONTICELLITE_dewminerals_cv(double t, double p)
    double MONTICELLITE_dewminerals_cp(double t, double p)
    double MONTICELLITE_dewminerals_dcpdt(double t, double p)
    double MONTICELLITE_dewminerals_alpha(double t, double p)
    double MONTICELLITE_dewminerals_beta(double t, double p)
    double MONTICELLITE_dewminerals_K(double t, double p)
    double MONTICELLITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MONTICELLITE_dewminerals_identifier():
    result = <bytes> MONTICELLITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MONTICELLITE_dewminerals_name():
    result = <bytes> MONTICELLITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MONTICELLITE_dewminerals_formula():
    result = <bytes> MONTICELLITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MONTICELLITE_dewminerals_mw():
    result = MONTICELLITE_dewminerals_mw()
    return result
def cy_MONTICELLITE_dewminerals_elements():
    cdef const double *e = MONTICELLITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MONTICELLITE_dewminerals_g(double t, double p):
    result = MONTICELLITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_dgdt(double t, double p):
    result = MONTICELLITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_dgdp(double t, double p):
    result = MONTICELLITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d2gdt2(double t, double p):
    result = MONTICELLITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d2gdtdp(double t, double p):
    result = MONTICELLITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d2gdp2(double t, double p):
    result = MONTICELLITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d3gdt3(double t, double p):
    result = MONTICELLITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d3gdt2dp(double t, double p):
    result = MONTICELLITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d3gdtdp2(double t, double p):
    result = MONTICELLITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_d3gdp3(double t, double p):
    result = MONTICELLITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_s(double t, double p):
    result = MONTICELLITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_v(double t, double p):
    result = MONTICELLITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_cv(double t, double p):
    result = MONTICELLITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_cp(double t, double p):
    result = MONTICELLITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_dcpdt(double t, double p):
    result = MONTICELLITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_alpha(double t, double p):
    result = MONTICELLITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_beta(double t, double p):
    result = MONTICELLITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_K(double t, double p):
    result = MONTICELLITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MONTICELLITE_dewminerals_Kp(double t, double p):
    result = MONTICELLITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "FAYALITE_dewminerals_calc.h":
    const char *FAYALITE_dewminerals_identifier();
    const char *FAYALITE_dewminerals_name();
    const char *FAYALITE_dewminerals_formula();
    const double FAYALITE_dewminerals_mw();
    const double *FAYALITE_dewminerals_elements();
    double FAYALITE_dewminerals_g(double t, double p)
    double FAYALITE_dewminerals_dgdt(double t, double p)
    double FAYALITE_dewminerals_dgdp(double t, double p)
    double FAYALITE_dewminerals_d2gdt2(double t, double p)
    double FAYALITE_dewminerals_d2gdtdp(double t, double p)
    double FAYALITE_dewminerals_d2gdp2(double t, double p)
    double FAYALITE_dewminerals_d3gdt3(double t, double p)
    double FAYALITE_dewminerals_d3gdt2dp(double t, double p)
    double FAYALITE_dewminerals_d3gdtdp2(double t, double p)
    double FAYALITE_dewminerals_d3gdp3(double t, double p)
    double FAYALITE_dewminerals_s(double t, double p)
    double FAYALITE_dewminerals_v(double t, double p)
    double FAYALITE_dewminerals_cv(double t, double p)
    double FAYALITE_dewminerals_cp(double t, double p)
    double FAYALITE_dewminerals_dcpdt(double t, double p)
    double FAYALITE_dewminerals_alpha(double t, double p)
    double FAYALITE_dewminerals_beta(double t, double p)
    double FAYALITE_dewminerals_K(double t, double p)
    double FAYALITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_FAYALITE_dewminerals_identifier():
    result = <bytes> FAYALITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_FAYALITE_dewminerals_name():
    result = <bytes> FAYALITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_FAYALITE_dewminerals_formula():
    result = <bytes> FAYALITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_FAYALITE_dewminerals_mw():
    result = FAYALITE_dewminerals_mw()
    return result
def cy_FAYALITE_dewminerals_elements():
    cdef const double *e = FAYALITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_FAYALITE_dewminerals_g(double t, double p):
    result = FAYALITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_dgdt(double t, double p):
    result = FAYALITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_dgdp(double t, double p):
    result = FAYALITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d2gdt2(double t, double p):
    result = FAYALITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d2gdtdp(double t, double p):
    result = FAYALITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d2gdp2(double t, double p):
    result = FAYALITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d3gdt3(double t, double p):
    result = FAYALITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d3gdt2dp(double t, double p):
    result = FAYALITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d3gdtdp2(double t, double p):
    result = FAYALITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_d3gdp3(double t, double p):
    result = FAYALITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_s(double t, double p):
    result = FAYALITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_v(double t, double p):
    result = FAYALITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_cv(double t, double p):
    result = FAYALITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_cp(double t, double p):
    result = FAYALITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_dcpdt(double t, double p):
    result = FAYALITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_alpha(double t, double p):
    result = FAYALITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_beta(double t, double p):
    result = FAYALITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_K(double t, double p):
    result = FAYALITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_FAYALITE_dewminerals_Kp(double t, double p):
    result = FAYALITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "FORSTERITE_dewminerals_calc.h":
    const char *FORSTERITE_dewminerals_identifier();
    const char *FORSTERITE_dewminerals_name();
    const char *FORSTERITE_dewminerals_formula();
    const double FORSTERITE_dewminerals_mw();
    const double *FORSTERITE_dewminerals_elements();
    double FORSTERITE_dewminerals_g(double t, double p)
    double FORSTERITE_dewminerals_dgdt(double t, double p)
    double FORSTERITE_dewminerals_dgdp(double t, double p)
    double FORSTERITE_dewminerals_d2gdt2(double t, double p)
    double FORSTERITE_dewminerals_d2gdtdp(double t, double p)
    double FORSTERITE_dewminerals_d2gdp2(double t, double p)
    double FORSTERITE_dewminerals_d3gdt3(double t, double p)
    double FORSTERITE_dewminerals_d3gdt2dp(double t, double p)
    double FORSTERITE_dewminerals_d3gdtdp2(double t, double p)
    double FORSTERITE_dewminerals_d3gdp3(double t, double p)
    double FORSTERITE_dewminerals_s(double t, double p)
    double FORSTERITE_dewminerals_v(double t, double p)
    double FORSTERITE_dewminerals_cv(double t, double p)
    double FORSTERITE_dewminerals_cp(double t, double p)
    double FORSTERITE_dewminerals_dcpdt(double t, double p)
    double FORSTERITE_dewminerals_alpha(double t, double p)
    double FORSTERITE_dewminerals_beta(double t, double p)
    double FORSTERITE_dewminerals_K(double t, double p)
    double FORSTERITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_FORSTERITE_dewminerals_identifier():
    result = <bytes> FORSTERITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_FORSTERITE_dewminerals_name():
    result = <bytes> FORSTERITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_FORSTERITE_dewminerals_formula():
    result = <bytes> FORSTERITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_FORSTERITE_dewminerals_mw():
    result = FORSTERITE_dewminerals_mw()
    return result
def cy_FORSTERITE_dewminerals_elements():
    cdef const double *e = FORSTERITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_FORSTERITE_dewminerals_g(double t, double p):
    result = FORSTERITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_dgdt(double t, double p):
    result = FORSTERITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_dgdp(double t, double p):
    result = FORSTERITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d2gdt2(double t, double p):
    result = FORSTERITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d2gdtdp(double t, double p):
    result = FORSTERITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d2gdp2(double t, double p):
    result = FORSTERITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d3gdt3(double t, double p):
    result = FORSTERITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d3gdt2dp(double t, double p):
    result = FORSTERITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d3gdtdp2(double t, double p):
    result = FORSTERITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_d3gdp3(double t, double p):
    result = FORSTERITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_s(double t, double p):
    result = FORSTERITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_v(double t, double p):
    result = FORSTERITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_cv(double t, double p):
    result = FORSTERITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_cp(double t, double p):
    result = FORSTERITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_dcpdt(double t, double p):
    result = FORSTERITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_alpha(double t, double p):
    result = FORSTERITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_beta(double t, double p):
    result = FORSTERITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_K(double t, double p):
    result = FORSTERITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_FORSTERITE_dewminerals_Kp(double t, double p):
    result = FORSTERITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CLINOZOISITE_dewminerals_calc.h":
    const char *CLINOZOISITE_dewminerals_identifier();
    const char *CLINOZOISITE_dewminerals_name();
    const char *CLINOZOISITE_dewminerals_formula();
    const double CLINOZOISITE_dewminerals_mw();
    const double *CLINOZOISITE_dewminerals_elements();
    double CLINOZOISITE_dewminerals_g(double t, double p)
    double CLINOZOISITE_dewminerals_dgdt(double t, double p)
    double CLINOZOISITE_dewminerals_dgdp(double t, double p)
    double CLINOZOISITE_dewminerals_d2gdt2(double t, double p)
    double CLINOZOISITE_dewminerals_d2gdtdp(double t, double p)
    double CLINOZOISITE_dewminerals_d2gdp2(double t, double p)
    double CLINOZOISITE_dewminerals_d3gdt3(double t, double p)
    double CLINOZOISITE_dewminerals_d3gdt2dp(double t, double p)
    double CLINOZOISITE_dewminerals_d3gdtdp2(double t, double p)
    double CLINOZOISITE_dewminerals_d3gdp3(double t, double p)
    double CLINOZOISITE_dewminerals_s(double t, double p)
    double CLINOZOISITE_dewminerals_v(double t, double p)
    double CLINOZOISITE_dewminerals_cv(double t, double p)
    double CLINOZOISITE_dewminerals_cp(double t, double p)
    double CLINOZOISITE_dewminerals_dcpdt(double t, double p)
    double CLINOZOISITE_dewminerals_alpha(double t, double p)
    double CLINOZOISITE_dewminerals_beta(double t, double p)
    double CLINOZOISITE_dewminerals_K(double t, double p)
    double CLINOZOISITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CLINOZOISITE_dewminerals_identifier():
    result = <bytes> CLINOZOISITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CLINOZOISITE_dewminerals_name():
    result = <bytes> CLINOZOISITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CLINOZOISITE_dewminerals_formula():
    result = <bytes> CLINOZOISITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CLINOZOISITE_dewminerals_mw():
    result = CLINOZOISITE_dewminerals_mw()
    return result
def cy_CLINOZOISITE_dewminerals_elements():
    cdef const double *e = CLINOZOISITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CLINOZOISITE_dewminerals_g(double t, double p):
    result = CLINOZOISITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_dgdt(double t, double p):
    result = CLINOZOISITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_dgdp(double t, double p):
    result = CLINOZOISITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d2gdt2(double t, double p):
    result = CLINOZOISITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d2gdtdp(double t, double p):
    result = CLINOZOISITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d2gdp2(double t, double p):
    result = CLINOZOISITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d3gdt3(double t, double p):
    result = CLINOZOISITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d3gdt2dp(double t, double p):
    result = CLINOZOISITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d3gdtdp2(double t, double p):
    result = CLINOZOISITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_d3gdp3(double t, double p):
    result = CLINOZOISITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_s(double t, double p):
    result = CLINOZOISITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_v(double t, double p):
    result = CLINOZOISITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_cv(double t, double p):
    result = CLINOZOISITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_cp(double t, double p):
    result = CLINOZOISITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_dcpdt(double t, double p):
    result = CLINOZOISITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_alpha(double t, double p):
    result = CLINOZOISITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_beta(double t, double p):
    result = CLINOZOISITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_K(double t, double p):
    result = CLINOZOISITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CLINOZOISITE_dewminerals_Kp(double t, double p):
    result = CLINOZOISITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ZOISITE_dewminerals_calc.h":
    const char *ZOISITE_dewminerals_identifier();
    const char *ZOISITE_dewminerals_name();
    const char *ZOISITE_dewminerals_formula();
    const double ZOISITE_dewminerals_mw();
    const double *ZOISITE_dewminerals_elements();
    double ZOISITE_dewminerals_g(double t, double p)
    double ZOISITE_dewminerals_dgdt(double t, double p)
    double ZOISITE_dewminerals_dgdp(double t, double p)
    double ZOISITE_dewminerals_d2gdt2(double t, double p)
    double ZOISITE_dewminerals_d2gdtdp(double t, double p)
    double ZOISITE_dewminerals_d2gdp2(double t, double p)
    double ZOISITE_dewminerals_d3gdt3(double t, double p)
    double ZOISITE_dewminerals_d3gdt2dp(double t, double p)
    double ZOISITE_dewminerals_d3gdtdp2(double t, double p)
    double ZOISITE_dewminerals_d3gdp3(double t, double p)
    double ZOISITE_dewminerals_s(double t, double p)
    double ZOISITE_dewminerals_v(double t, double p)
    double ZOISITE_dewminerals_cv(double t, double p)
    double ZOISITE_dewminerals_cp(double t, double p)
    double ZOISITE_dewminerals_dcpdt(double t, double p)
    double ZOISITE_dewminerals_alpha(double t, double p)
    double ZOISITE_dewminerals_beta(double t, double p)
    double ZOISITE_dewminerals_K(double t, double p)
    double ZOISITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ZOISITE_dewminerals_identifier():
    result = <bytes> ZOISITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ZOISITE_dewminerals_name():
    result = <bytes> ZOISITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ZOISITE_dewminerals_formula():
    result = <bytes> ZOISITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ZOISITE_dewminerals_mw():
    result = ZOISITE_dewminerals_mw()
    return result
def cy_ZOISITE_dewminerals_elements():
    cdef const double *e = ZOISITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ZOISITE_dewminerals_g(double t, double p):
    result = ZOISITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_dgdt(double t, double p):
    result = ZOISITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_dgdp(double t, double p):
    result = ZOISITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d2gdt2(double t, double p):
    result = ZOISITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d2gdtdp(double t, double p):
    result = ZOISITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d2gdp2(double t, double p):
    result = ZOISITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d3gdt3(double t, double p):
    result = ZOISITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d3gdt2dp(double t, double p):
    result = ZOISITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d3gdtdp2(double t, double p):
    result = ZOISITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_d3gdp3(double t, double p):
    result = ZOISITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_s(double t, double p):
    result = ZOISITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_v(double t, double p):
    result = ZOISITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_cv(double t, double p):
    result = ZOISITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_cp(double t, double p):
    result = ZOISITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_dcpdt(double t, double p):
    result = ZOISITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_alpha(double t, double p):
    result = ZOISITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_beta(double t, double p):
    result = ZOISITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_K(double t, double p):
    result = ZOISITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ZOISITE_dewminerals_Kp(double t, double p):
    result = ZOISITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PUMPELLYITE_dewminerals_calc.h":
    const char *PUMPELLYITE_dewminerals_identifier();
    const char *PUMPELLYITE_dewminerals_name();
    const char *PUMPELLYITE_dewminerals_formula();
    const double PUMPELLYITE_dewminerals_mw();
    const double *PUMPELLYITE_dewminerals_elements();
    double PUMPELLYITE_dewminerals_g(double t, double p)
    double PUMPELLYITE_dewminerals_dgdt(double t, double p)
    double PUMPELLYITE_dewminerals_dgdp(double t, double p)
    double PUMPELLYITE_dewminerals_d2gdt2(double t, double p)
    double PUMPELLYITE_dewminerals_d2gdtdp(double t, double p)
    double PUMPELLYITE_dewminerals_d2gdp2(double t, double p)
    double PUMPELLYITE_dewminerals_d3gdt3(double t, double p)
    double PUMPELLYITE_dewminerals_d3gdt2dp(double t, double p)
    double PUMPELLYITE_dewminerals_d3gdtdp2(double t, double p)
    double PUMPELLYITE_dewminerals_d3gdp3(double t, double p)
    double PUMPELLYITE_dewminerals_s(double t, double p)
    double PUMPELLYITE_dewminerals_v(double t, double p)
    double PUMPELLYITE_dewminerals_cv(double t, double p)
    double PUMPELLYITE_dewminerals_cp(double t, double p)
    double PUMPELLYITE_dewminerals_dcpdt(double t, double p)
    double PUMPELLYITE_dewminerals_alpha(double t, double p)
    double PUMPELLYITE_dewminerals_beta(double t, double p)
    double PUMPELLYITE_dewminerals_K(double t, double p)
    double PUMPELLYITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PUMPELLYITE_dewminerals_identifier():
    result = <bytes> PUMPELLYITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PUMPELLYITE_dewminerals_name():
    result = <bytes> PUMPELLYITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PUMPELLYITE_dewminerals_formula():
    result = <bytes> PUMPELLYITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PUMPELLYITE_dewminerals_mw():
    result = PUMPELLYITE_dewminerals_mw()
    return result
def cy_PUMPELLYITE_dewminerals_elements():
    cdef const double *e = PUMPELLYITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PUMPELLYITE_dewminerals_g(double t, double p):
    result = PUMPELLYITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_dgdt(double t, double p):
    result = PUMPELLYITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_dgdp(double t, double p):
    result = PUMPELLYITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d2gdt2(double t, double p):
    result = PUMPELLYITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d2gdtdp(double t, double p):
    result = PUMPELLYITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d2gdp2(double t, double p):
    result = PUMPELLYITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d3gdt3(double t, double p):
    result = PUMPELLYITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d3gdt2dp(double t, double p):
    result = PUMPELLYITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d3gdtdp2(double t, double p):
    result = PUMPELLYITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_d3gdp3(double t, double p):
    result = PUMPELLYITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_s(double t, double p):
    result = PUMPELLYITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_v(double t, double p):
    result = PUMPELLYITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_cv(double t, double p):
    result = PUMPELLYITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_cp(double t, double p):
    result = PUMPELLYITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_dcpdt(double t, double p):
    result = PUMPELLYITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_alpha(double t, double p):
    result = PUMPELLYITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_beta(double t, double p):
    result = PUMPELLYITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_K(double t, double p):
    result = PUMPELLYITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PUMPELLYITE_dewminerals_Kp(double t, double p):
    result = PUMPELLYITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "LAWSONITE_dewminerals_calc.h":
    const char *LAWSONITE_dewminerals_identifier();
    const char *LAWSONITE_dewminerals_name();
    const char *LAWSONITE_dewminerals_formula();
    const double LAWSONITE_dewminerals_mw();
    const double *LAWSONITE_dewminerals_elements();
    double LAWSONITE_dewminerals_g(double t, double p)
    double LAWSONITE_dewminerals_dgdt(double t, double p)
    double LAWSONITE_dewminerals_dgdp(double t, double p)
    double LAWSONITE_dewminerals_d2gdt2(double t, double p)
    double LAWSONITE_dewminerals_d2gdtdp(double t, double p)
    double LAWSONITE_dewminerals_d2gdp2(double t, double p)
    double LAWSONITE_dewminerals_d3gdt3(double t, double p)
    double LAWSONITE_dewminerals_d3gdt2dp(double t, double p)
    double LAWSONITE_dewminerals_d3gdtdp2(double t, double p)
    double LAWSONITE_dewminerals_d3gdp3(double t, double p)
    double LAWSONITE_dewminerals_s(double t, double p)
    double LAWSONITE_dewminerals_v(double t, double p)
    double LAWSONITE_dewminerals_cv(double t, double p)
    double LAWSONITE_dewminerals_cp(double t, double p)
    double LAWSONITE_dewminerals_dcpdt(double t, double p)
    double LAWSONITE_dewminerals_alpha(double t, double p)
    double LAWSONITE_dewminerals_beta(double t, double p)
    double LAWSONITE_dewminerals_K(double t, double p)
    double LAWSONITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_LAWSONITE_dewminerals_identifier():
    result = <bytes> LAWSONITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_LAWSONITE_dewminerals_name():
    result = <bytes> LAWSONITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_LAWSONITE_dewminerals_formula():
    result = <bytes> LAWSONITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_LAWSONITE_dewminerals_mw():
    result = LAWSONITE_dewminerals_mw()
    return result
def cy_LAWSONITE_dewminerals_elements():
    cdef const double *e = LAWSONITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_LAWSONITE_dewminerals_g(double t, double p):
    result = LAWSONITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_dgdt(double t, double p):
    result = LAWSONITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_dgdp(double t, double p):
    result = LAWSONITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d2gdt2(double t, double p):
    result = LAWSONITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d2gdtdp(double t, double p):
    result = LAWSONITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d2gdp2(double t, double p):
    result = LAWSONITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d3gdt3(double t, double p):
    result = LAWSONITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d3gdt2dp(double t, double p):
    result = LAWSONITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d3gdtdp2(double t, double p):
    result = LAWSONITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_d3gdp3(double t, double p):
    result = LAWSONITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_s(double t, double p):
    result = LAWSONITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_v(double t, double p):
    result = LAWSONITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_cv(double t, double p):
    result = LAWSONITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_cp(double t, double p):
    result = LAWSONITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_dcpdt(double t, double p):
    result = LAWSONITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_alpha(double t, double p):
    result = LAWSONITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_beta(double t, double p):
    result = LAWSONITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_K(double t, double p):
    result = LAWSONITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_LAWSONITE_dewminerals_Kp(double t, double p):
    result = LAWSONITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "GLAUCOPHANE_dewminerals_calc.h":
    const char *GLAUCOPHANE_dewminerals_identifier();
    const char *GLAUCOPHANE_dewminerals_name();
    const char *GLAUCOPHANE_dewminerals_formula();
    const double GLAUCOPHANE_dewminerals_mw();
    const double *GLAUCOPHANE_dewminerals_elements();
    double GLAUCOPHANE_dewminerals_g(double t, double p)
    double GLAUCOPHANE_dewminerals_dgdt(double t, double p)
    double GLAUCOPHANE_dewminerals_dgdp(double t, double p)
    double GLAUCOPHANE_dewminerals_d2gdt2(double t, double p)
    double GLAUCOPHANE_dewminerals_d2gdtdp(double t, double p)
    double GLAUCOPHANE_dewminerals_d2gdp2(double t, double p)
    double GLAUCOPHANE_dewminerals_d3gdt3(double t, double p)
    double GLAUCOPHANE_dewminerals_d3gdt2dp(double t, double p)
    double GLAUCOPHANE_dewminerals_d3gdtdp2(double t, double p)
    double GLAUCOPHANE_dewminerals_d3gdp3(double t, double p)
    double GLAUCOPHANE_dewminerals_s(double t, double p)
    double GLAUCOPHANE_dewminerals_v(double t, double p)
    double GLAUCOPHANE_dewminerals_cv(double t, double p)
    double GLAUCOPHANE_dewminerals_cp(double t, double p)
    double GLAUCOPHANE_dewminerals_dcpdt(double t, double p)
    double GLAUCOPHANE_dewminerals_alpha(double t, double p)
    double GLAUCOPHANE_dewminerals_beta(double t, double p)
    double GLAUCOPHANE_dewminerals_K(double t, double p)
    double GLAUCOPHANE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_GLAUCOPHANE_dewminerals_identifier():
    result = <bytes> GLAUCOPHANE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_GLAUCOPHANE_dewminerals_name():
    result = <bytes> GLAUCOPHANE_dewminerals_name()
    return result.decode('UTF-8')
def cy_GLAUCOPHANE_dewminerals_formula():
    result = <bytes> GLAUCOPHANE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_GLAUCOPHANE_dewminerals_mw():
    result = GLAUCOPHANE_dewminerals_mw()
    return result
def cy_GLAUCOPHANE_dewminerals_elements():
    cdef const double *e = GLAUCOPHANE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_GLAUCOPHANE_dewminerals_g(double t, double p):
    result = GLAUCOPHANE_dewminerals_g(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_dgdt(double t, double p):
    result = GLAUCOPHANE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_dgdp(double t, double p):
    result = GLAUCOPHANE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d2gdt2(double t, double p):
    result = GLAUCOPHANE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d2gdtdp(double t, double p):
    result = GLAUCOPHANE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d2gdp2(double t, double p):
    result = GLAUCOPHANE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d3gdt3(double t, double p):
    result = GLAUCOPHANE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d3gdt2dp(double t, double p):
    result = GLAUCOPHANE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d3gdtdp2(double t, double p):
    result = GLAUCOPHANE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_d3gdp3(double t, double p):
    result = GLAUCOPHANE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_s(double t, double p):
    result = GLAUCOPHANE_dewminerals_s(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_v(double t, double p):
    result = GLAUCOPHANE_dewminerals_v(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_cv(double t, double p):
    result = GLAUCOPHANE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_cp(double t, double p):
    result = GLAUCOPHANE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_dcpdt(double t, double p):
    result = GLAUCOPHANE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_alpha(double t, double p):
    result = GLAUCOPHANE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_beta(double t, double p):
    result = GLAUCOPHANE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_K(double t, double p):
    result = GLAUCOPHANE_dewminerals_K(<double> t, <double> p)
    return result
def cy_GLAUCOPHANE_dewminerals_Kp(double t, double p):
    result = GLAUCOPHANE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "SILLIMANITE_dewminerals_calc.h":
    const char *SILLIMANITE_dewminerals_identifier();
    const char *SILLIMANITE_dewminerals_name();
    const char *SILLIMANITE_dewminerals_formula();
    const double SILLIMANITE_dewminerals_mw();
    const double *SILLIMANITE_dewminerals_elements();
    double SILLIMANITE_dewminerals_g(double t, double p)
    double SILLIMANITE_dewminerals_dgdt(double t, double p)
    double SILLIMANITE_dewminerals_dgdp(double t, double p)
    double SILLIMANITE_dewminerals_d2gdt2(double t, double p)
    double SILLIMANITE_dewminerals_d2gdtdp(double t, double p)
    double SILLIMANITE_dewminerals_d2gdp2(double t, double p)
    double SILLIMANITE_dewminerals_d3gdt3(double t, double p)
    double SILLIMANITE_dewminerals_d3gdt2dp(double t, double p)
    double SILLIMANITE_dewminerals_d3gdtdp2(double t, double p)
    double SILLIMANITE_dewminerals_d3gdp3(double t, double p)
    double SILLIMANITE_dewminerals_s(double t, double p)
    double SILLIMANITE_dewminerals_v(double t, double p)
    double SILLIMANITE_dewminerals_cv(double t, double p)
    double SILLIMANITE_dewminerals_cp(double t, double p)
    double SILLIMANITE_dewminerals_dcpdt(double t, double p)
    double SILLIMANITE_dewminerals_alpha(double t, double p)
    double SILLIMANITE_dewminerals_beta(double t, double p)
    double SILLIMANITE_dewminerals_K(double t, double p)
    double SILLIMANITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_SILLIMANITE_dewminerals_identifier():
    result = <bytes> SILLIMANITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_SILLIMANITE_dewminerals_name():
    result = <bytes> SILLIMANITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_SILLIMANITE_dewminerals_formula():
    result = <bytes> SILLIMANITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_SILLIMANITE_dewminerals_mw():
    result = SILLIMANITE_dewminerals_mw()
    return result
def cy_SILLIMANITE_dewminerals_elements():
    cdef const double *e = SILLIMANITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_SILLIMANITE_dewminerals_g(double t, double p):
    result = SILLIMANITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_dgdt(double t, double p):
    result = SILLIMANITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_dgdp(double t, double p):
    result = SILLIMANITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d2gdt2(double t, double p):
    result = SILLIMANITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d2gdtdp(double t, double p):
    result = SILLIMANITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d2gdp2(double t, double p):
    result = SILLIMANITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d3gdt3(double t, double p):
    result = SILLIMANITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d3gdt2dp(double t, double p):
    result = SILLIMANITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d3gdtdp2(double t, double p):
    result = SILLIMANITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_d3gdp3(double t, double p):
    result = SILLIMANITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_s(double t, double p):
    result = SILLIMANITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_v(double t, double p):
    result = SILLIMANITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_cv(double t, double p):
    result = SILLIMANITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_cp(double t, double p):
    result = SILLIMANITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_dcpdt(double t, double p):
    result = SILLIMANITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_alpha(double t, double p):
    result = SILLIMANITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_beta(double t, double p):
    result = SILLIMANITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_K(double t, double p):
    result = SILLIMANITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_SILLIMANITE_dewminerals_Kp(double t, double p):
    result = SILLIMANITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "KYANITE_dewminerals_calc.h":
    const char *KYANITE_dewminerals_identifier();
    const char *KYANITE_dewminerals_name();
    const char *KYANITE_dewminerals_formula();
    const double KYANITE_dewminerals_mw();
    const double *KYANITE_dewminerals_elements();
    double KYANITE_dewminerals_g(double t, double p)
    double KYANITE_dewminerals_dgdt(double t, double p)
    double KYANITE_dewminerals_dgdp(double t, double p)
    double KYANITE_dewminerals_d2gdt2(double t, double p)
    double KYANITE_dewminerals_d2gdtdp(double t, double p)
    double KYANITE_dewminerals_d2gdp2(double t, double p)
    double KYANITE_dewminerals_d3gdt3(double t, double p)
    double KYANITE_dewminerals_d3gdt2dp(double t, double p)
    double KYANITE_dewminerals_d3gdtdp2(double t, double p)
    double KYANITE_dewminerals_d3gdp3(double t, double p)
    double KYANITE_dewminerals_s(double t, double p)
    double KYANITE_dewminerals_v(double t, double p)
    double KYANITE_dewminerals_cv(double t, double p)
    double KYANITE_dewminerals_cp(double t, double p)
    double KYANITE_dewminerals_dcpdt(double t, double p)
    double KYANITE_dewminerals_alpha(double t, double p)
    double KYANITE_dewminerals_beta(double t, double p)
    double KYANITE_dewminerals_K(double t, double p)
    double KYANITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_KYANITE_dewminerals_identifier():
    result = <bytes> KYANITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_KYANITE_dewminerals_name():
    result = <bytes> KYANITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_KYANITE_dewminerals_formula():
    result = <bytes> KYANITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_KYANITE_dewminerals_mw():
    result = KYANITE_dewminerals_mw()
    return result
def cy_KYANITE_dewminerals_elements():
    cdef const double *e = KYANITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_KYANITE_dewminerals_g(double t, double p):
    result = KYANITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_dgdt(double t, double p):
    result = KYANITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_dgdp(double t, double p):
    result = KYANITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d2gdt2(double t, double p):
    result = KYANITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d2gdtdp(double t, double p):
    result = KYANITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d2gdp2(double t, double p):
    result = KYANITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d3gdt3(double t, double p):
    result = KYANITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d3gdt2dp(double t, double p):
    result = KYANITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d3gdtdp2(double t, double p):
    result = KYANITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_d3gdp3(double t, double p):
    result = KYANITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_s(double t, double p):
    result = KYANITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_v(double t, double p):
    result = KYANITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_cv(double t, double p):
    result = KYANITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_cp(double t, double p):
    result = KYANITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_dcpdt(double t, double p):
    result = KYANITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_alpha(double t, double p):
    result = KYANITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_beta(double t, double p):
    result = KYANITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_K(double t, double p):
    result = KYANITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_KYANITE_dewminerals_Kp(double t, double p):
    result = KYANITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ANDALUSITE_dewminerals_calc.h":
    const char *ANDALUSITE_dewminerals_identifier();
    const char *ANDALUSITE_dewminerals_name();
    const char *ANDALUSITE_dewminerals_formula();
    const double ANDALUSITE_dewminerals_mw();
    const double *ANDALUSITE_dewminerals_elements();
    double ANDALUSITE_dewminerals_g(double t, double p)
    double ANDALUSITE_dewminerals_dgdt(double t, double p)
    double ANDALUSITE_dewminerals_dgdp(double t, double p)
    double ANDALUSITE_dewminerals_d2gdt2(double t, double p)
    double ANDALUSITE_dewminerals_d2gdtdp(double t, double p)
    double ANDALUSITE_dewminerals_d2gdp2(double t, double p)
    double ANDALUSITE_dewminerals_d3gdt3(double t, double p)
    double ANDALUSITE_dewminerals_d3gdt2dp(double t, double p)
    double ANDALUSITE_dewminerals_d3gdtdp2(double t, double p)
    double ANDALUSITE_dewminerals_d3gdp3(double t, double p)
    double ANDALUSITE_dewminerals_s(double t, double p)
    double ANDALUSITE_dewminerals_v(double t, double p)
    double ANDALUSITE_dewminerals_cv(double t, double p)
    double ANDALUSITE_dewminerals_cp(double t, double p)
    double ANDALUSITE_dewminerals_dcpdt(double t, double p)
    double ANDALUSITE_dewminerals_alpha(double t, double p)
    double ANDALUSITE_dewminerals_beta(double t, double p)
    double ANDALUSITE_dewminerals_K(double t, double p)
    double ANDALUSITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ANDALUSITE_dewminerals_identifier():
    result = <bytes> ANDALUSITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ANDALUSITE_dewminerals_name():
    result = <bytes> ANDALUSITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ANDALUSITE_dewminerals_formula():
    result = <bytes> ANDALUSITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ANDALUSITE_dewminerals_mw():
    result = ANDALUSITE_dewminerals_mw()
    return result
def cy_ANDALUSITE_dewminerals_elements():
    cdef const double *e = ANDALUSITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ANDALUSITE_dewminerals_g(double t, double p):
    result = ANDALUSITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_dgdt(double t, double p):
    result = ANDALUSITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_dgdp(double t, double p):
    result = ANDALUSITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d2gdt2(double t, double p):
    result = ANDALUSITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d2gdtdp(double t, double p):
    result = ANDALUSITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d2gdp2(double t, double p):
    result = ANDALUSITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d3gdt3(double t, double p):
    result = ANDALUSITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d3gdt2dp(double t, double p):
    result = ANDALUSITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d3gdtdp2(double t, double p):
    result = ANDALUSITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_d3gdp3(double t, double p):
    result = ANDALUSITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_s(double t, double p):
    result = ANDALUSITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_v(double t, double p):
    result = ANDALUSITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_cv(double t, double p):
    result = ANDALUSITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_cp(double t, double p):
    result = ANDALUSITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_dcpdt(double t, double p):
    result = ANDALUSITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_alpha(double t, double p):
    result = ANDALUSITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_beta(double t, double p):
    result = ANDALUSITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_K(double t, double p):
    result = ANDALUSITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ANDALUSITE_dewminerals_Kp(double t, double p):
    result = ANDALUSITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "DOLOMITE_dewminerals_calc.h":
    const char *DOLOMITE_dewminerals_identifier();
    const char *DOLOMITE_dewminerals_name();
    const char *DOLOMITE_dewminerals_formula();
    const double DOLOMITE_dewminerals_mw();
    const double *DOLOMITE_dewminerals_elements();
    double DOLOMITE_dewminerals_g(double t, double p)
    double DOLOMITE_dewminerals_dgdt(double t, double p)
    double DOLOMITE_dewminerals_dgdp(double t, double p)
    double DOLOMITE_dewminerals_d2gdt2(double t, double p)
    double DOLOMITE_dewminerals_d2gdtdp(double t, double p)
    double DOLOMITE_dewminerals_d2gdp2(double t, double p)
    double DOLOMITE_dewminerals_d3gdt3(double t, double p)
    double DOLOMITE_dewminerals_d3gdt2dp(double t, double p)
    double DOLOMITE_dewminerals_d3gdtdp2(double t, double p)
    double DOLOMITE_dewminerals_d3gdp3(double t, double p)
    double DOLOMITE_dewminerals_s(double t, double p)
    double DOLOMITE_dewminerals_v(double t, double p)
    double DOLOMITE_dewminerals_cv(double t, double p)
    double DOLOMITE_dewminerals_cp(double t, double p)
    double DOLOMITE_dewminerals_dcpdt(double t, double p)
    double DOLOMITE_dewminerals_alpha(double t, double p)
    double DOLOMITE_dewminerals_beta(double t, double p)
    double DOLOMITE_dewminerals_K(double t, double p)
    double DOLOMITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_DOLOMITE_dewminerals_identifier():
    result = <bytes> DOLOMITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_DOLOMITE_dewminerals_name():
    result = <bytes> DOLOMITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_DOLOMITE_dewminerals_formula():
    result = <bytes> DOLOMITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_DOLOMITE_dewminerals_mw():
    result = DOLOMITE_dewminerals_mw()
    return result
def cy_DOLOMITE_dewminerals_elements():
    cdef const double *e = DOLOMITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_DOLOMITE_dewminerals_g(double t, double p):
    result = DOLOMITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_dgdt(double t, double p):
    result = DOLOMITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_dgdp(double t, double p):
    result = DOLOMITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d2gdt2(double t, double p):
    result = DOLOMITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d2gdtdp(double t, double p):
    result = DOLOMITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d2gdp2(double t, double p):
    result = DOLOMITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d3gdt3(double t, double p):
    result = DOLOMITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d3gdt2dp(double t, double p):
    result = DOLOMITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d3gdtdp2(double t, double p):
    result = DOLOMITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_d3gdp3(double t, double p):
    result = DOLOMITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_s(double t, double p):
    result = DOLOMITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_v(double t, double p):
    result = DOLOMITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_cv(double t, double p):
    result = DOLOMITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_cp(double t, double p):
    result = DOLOMITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_dcpdt(double t, double p):
    result = DOLOMITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_alpha(double t, double p):
    result = DOLOMITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_beta(double t, double p):
    result = DOLOMITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_K(double t, double p):
    result = DOLOMITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_DOLOMITE_dewminerals_Kp(double t, double p):
    result = DOLOMITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "ARAGONITE_dewminerals_calc.h":
    const char *ARAGONITE_dewminerals_identifier();
    const char *ARAGONITE_dewminerals_name();
    const char *ARAGONITE_dewminerals_formula();
    const double ARAGONITE_dewminerals_mw();
    const double *ARAGONITE_dewminerals_elements();
    double ARAGONITE_dewminerals_g(double t, double p)
    double ARAGONITE_dewminerals_dgdt(double t, double p)
    double ARAGONITE_dewminerals_dgdp(double t, double p)
    double ARAGONITE_dewminerals_d2gdt2(double t, double p)
    double ARAGONITE_dewminerals_d2gdtdp(double t, double p)
    double ARAGONITE_dewminerals_d2gdp2(double t, double p)
    double ARAGONITE_dewminerals_d3gdt3(double t, double p)
    double ARAGONITE_dewminerals_d3gdt2dp(double t, double p)
    double ARAGONITE_dewminerals_d3gdtdp2(double t, double p)
    double ARAGONITE_dewminerals_d3gdp3(double t, double p)
    double ARAGONITE_dewminerals_s(double t, double p)
    double ARAGONITE_dewminerals_v(double t, double p)
    double ARAGONITE_dewminerals_cv(double t, double p)
    double ARAGONITE_dewminerals_cp(double t, double p)
    double ARAGONITE_dewminerals_dcpdt(double t, double p)
    double ARAGONITE_dewminerals_alpha(double t, double p)
    double ARAGONITE_dewminerals_beta(double t, double p)
    double ARAGONITE_dewminerals_K(double t, double p)
    double ARAGONITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_ARAGONITE_dewminerals_identifier():
    result = <bytes> ARAGONITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_ARAGONITE_dewminerals_name():
    result = <bytes> ARAGONITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_ARAGONITE_dewminerals_formula():
    result = <bytes> ARAGONITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_ARAGONITE_dewminerals_mw():
    result = ARAGONITE_dewminerals_mw()
    return result
def cy_ARAGONITE_dewminerals_elements():
    cdef const double *e = ARAGONITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_ARAGONITE_dewminerals_g(double t, double p):
    result = ARAGONITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_dgdt(double t, double p):
    result = ARAGONITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_dgdp(double t, double p):
    result = ARAGONITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d2gdt2(double t, double p):
    result = ARAGONITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d2gdtdp(double t, double p):
    result = ARAGONITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d2gdp2(double t, double p):
    result = ARAGONITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d3gdt3(double t, double p):
    result = ARAGONITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d3gdt2dp(double t, double p):
    result = ARAGONITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d3gdtdp2(double t, double p):
    result = ARAGONITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_d3gdp3(double t, double p):
    result = ARAGONITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_s(double t, double p):
    result = ARAGONITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_v(double t, double p):
    result = ARAGONITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_cv(double t, double p):
    result = ARAGONITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_cp(double t, double p):
    result = ARAGONITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_dcpdt(double t, double p):
    result = ARAGONITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_alpha(double t, double p):
    result = ARAGONITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_beta(double t, double p):
    result = ARAGONITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_K(double t, double p):
    result = ARAGONITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_ARAGONITE_dewminerals_Kp(double t, double p):
    result = ARAGONITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "SIDERITE_dewminerals_calc.h":
    const char *SIDERITE_dewminerals_identifier();
    const char *SIDERITE_dewminerals_name();
    const char *SIDERITE_dewminerals_formula();
    const double SIDERITE_dewminerals_mw();
    const double *SIDERITE_dewminerals_elements();
    double SIDERITE_dewminerals_g(double t, double p)
    double SIDERITE_dewminerals_dgdt(double t, double p)
    double SIDERITE_dewminerals_dgdp(double t, double p)
    double SIDERITE_dewminerals_d2gdt2(double t, double p)
    double SIDERITE_dewminerals_d2gdtdp(double t, double p)
    double SIDERITE_dewminerals_d2gdp2(double t, double p)
    double SIDERITE_dewminerals_d3gdt3(double t, double p)
    double SIDERITE_dewminerals_d3gdt2dp(double t, double p)
    double SIDERITE_dewminerals_d3gdtdp2(double t, double p)
    double SIDERITE_dewminerals_d3gdp3(double t, double p)
    double SIDERITE_dewminerals_s(double t, double p)
    double SIDERITE_dewminerals_v(double t, double p)
    double SIDERITE_dewminerals_cv(double t, double p)
    double SIDERITE_dewminerals_cp(double t, double p)
    double SIDERITE_dewminerals_dcpdt(double t, double p)
    double SIDERITE_dewminerals_alpha(double t, double p)
    double SIDERITE_dewminerals_beta(double t, double p)
    double SIDERITE_dewminerals_K(double t, double p)
    double SIDERITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_SIDERITE_dewminerals_identifier():
    result = <bytes> SIDERITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_SIDERITE_dewminerals_name():
    result = <bytes> SIDERITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_SIDERITE_dewminerals_formula():
    result = <bytes> SIDERITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_SIDERITE_dewminerals_mw():
    result = SIDERITE_dewminerals_mw()
    return result
def cy_SIDERITE_dewminerals_elements():
    cdef const double *e = SIDERITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_SIDERITE_dewminerals_g(double t, double p):
    result = SIDERITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_dgdt(double t, double p):
    result = SIDERITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_dgdp(double t, double p):
    result = SIDERITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d2gdt2(double t, double p):
    result = SIDERITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d2gdtdp(double t, double p):
    result = SIDERITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d2gdp2(double t, double p):
    result = SIDERITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d3gdt3(double t, double p):
    result = SIDERITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d3gdt2dp(double t, double p):
    result = SIDERITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d3gdtdp2(double t, double p):
    result = SIDERITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_d3gdp3(double t, double p):
    result = SIDERITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_s(double t, double p):
    result = SIDERITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_v(double t, double p):
    result = SIDERITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_cv(double t, double p):
    result = SIDERITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_cp(double t, double p):
    result = SIDERITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_dcpdt(double t, double p):
    result = SIDERITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_alpha(double t, double p):
    result = SIDERITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_beta(double t, double p):
    result = SIDERITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_K(double t, double p):
    result = SIDERITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_SIDERITE_dewminerals_Kp(double t, double p):
    result = SIDERITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MAGNESITE_dewminerals_calc.h":
    const char *MAGNESITE_dewminerals_identifier();
    const char *MAGNESITE_dewminerals_name();
    const char *MAGNESITE_dewminerals_formula();
    const double MAGNESITE_dewminerals_mw();
    const double *MAGNESITE_dewminerals_elements();
    double MAGNESITE_dewminerals_g(double t, double p)
    double MAGNESITE_dewminerals_dgdt(double t, double p)
    double MAGNESITE_dewminerals_dgdp(double t, double p)
    double MAGNESITE_dewminerals_d2gdt2(double t, double p)
    double MAGNESITE_dewminerals_d2gdtdp(double t, double p)
    double MAGNESITE_dewminerals_d2gdp2(double t, double p)
    double MAGNESITE_dewminerals_d3gdt3(double t, double p)
    double MAGNESITE_dewminerals_d3gdt2dp(double t, double p)
    double MAGNESITE_dewminerals_d3gdtdp2(double t, double p)
    double MAGNESITE_dewminerals_d3gdp3(double t, double p)
    double MAGNESITE_dewminerals_s(double t, double p)
    double MAGNESITE_dewminerals_v(double t, double p)
    double MAGNESITE_dewminerals_cv(double t, double p)
    double MAGNESITE_dewminerals_cp(double t, double p)
    double MAGNESITE_dewminerals_dcpdt(double t, double p)
    double MAGNESITE_dewminerals_alpha(double t, double p)
    double MAGNESITE_dewminerals_beta(double t, double p)
    double MAGNESITE_dewminerals_K(double t, double p)
    double MAGNESITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MAGNESITE_dewminerals_identifier():
    result = <bytes> MAGNESITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MAGNESITE_dewminerals_name():
    result = <bytes> MAGNESITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MAGNESITE_dewminerals_formula():
    result = <bytes> MAGNESITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MAGNESITE_dewminerals_mw():
    result = MAGNESITE_dewminerals_mw()
    return result
def cy_MAGNESITE_dewminerals_elements():
    cdef const double *e = MAGNESITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MAGNESITE_dewminerals_g(double t, double p):
    result = MAGNESITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_dgdt(double t, double p):
    result = MAGNESITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_dgdp(double t, double p):
    result = MAGNESITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d2gdt2(double t, double p):
    result = MAGNESITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d2gdtdp(double t, double p):
    result = MAGNESITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d2gdp2(double t, double p):
    result = MAGNESITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d3gdt3(double t, double p):
    result = MAGNESITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d3gdt2dp(double t, double p):
    result = MAGNESITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d3gdtdp2(double t, double p):
    result = MAGNESITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_d3gdp3(double t, double p):
    result = MAGNESITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_s(double t, double p):
    result = MAGNESITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_v(double t, double p):
    result = MAGNESITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_cv(double t, double p):
    result = MAGNESITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_cp(double t, double p):
    result = MAGNESITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_dcpdt(double t, double p):
    result = MAGNESITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_alpha(double t, double p):
    result = MAGNESITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_beta(double t, double p):
    result = MAGNESITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_K(double t, double p):
    result = MAGNESITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MAGNESITE_dewminerals_Kp(double t, double p):
    result = MAGNESITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CALCITE_dewminerals_calc.h":
    const char *CALCITE_dewminerals_identifier();
    const char *CALCITE_dewminerals_name();
    const char *CALCITE_dewminerals_formula();
    const double CALCITE_dewminerals_mw();
    const double *CALCITE_dewminerals_elements();
    double CALCITE_dewminerals_g(double t, double p)
    double CALCITE_dewminerals_dgdt(double t, double p)
    double CALCITE_dewminerals_dgdp(double t, double p)
    double CALCITE_dewminerals_d2gdt2(double t, double p)
    double CALCITE_dewminerals_d2gdtdp(double t, double p)
    double CALCITE_dewminerals_d2gdp2(double t, double p)
    double CALCITE_dewminerals_d3gdt3(double t, double p)
    double CALCITE_dewminerals_d3gdt2dp(double t, double p)
    double CALCITE_dewminerals_d3gdtdp2(double t, double p)
    double CALCITE_dewminerals_d3gdp3(double t, double p)
    double CALCITE_dewminerals_s(double t, double p)
    double CALCITE_dewminerals_v(double t, double p)
    double CALCITE_dewminerals_cv(double t, double p)
    double CALCITE_dewminerals_cp(double t, double p)
    double CALCITE_dewminerals_dcpdt(double t, double p)
    double CALCITE_dewminerals_alpha(double t, double p)
    double CALCITE_dewminerals_beta(double t, double p)
    double CALCITE_dewminerals_K(double t, double p)
    double CALCITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CALCITE_dewminerals_identifier():
    result = <bytes> CALCITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CALCITE_dewminerals_name():
    result = <bytes> CALCITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CALCITE_dewminerals_formula():
    result = <bytes> CALCITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CALCITE_dewminerals_mw():
    result = CALCITE_dewminerals_mw()
    return result
def cy_CALCITE_dewminerals_elements():
    cdef const double *e = CALCITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CALCITE_dewminerals_g(double t, double p):
    result = CALCITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_dgdt(double t, double p):
    result = CALCITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_dgdp(double t, double p):
    result = CALCITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d2gdt2(double t, double p):
    result = CALCITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d2gdtdp(double t, double p):
    result = CALCITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d2gdp2(double t, double p):
    result = CALCITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d3gdt3(double t, double p):
    result = CALCITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d3gdt2dp(double t, double p):
    result = CALCITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d3gdtdp2(double t, double p):
    result = CALCITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_d3gdp3(double t, double p):
    result = CALCITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_s(double t, double p):
    result = CALCITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_v(double t, double p):
    result = CALCITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_cv(double t, double p):
    result = CALCITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_cp(double t, double p):
    result = CALCITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_dcpdt(double t, double p):
    result = CALCITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_alpha(double t, double p):
    result = CALCITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_beta(double t, double p):
    result = CALCITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_K(double t, double p):
    result = CALCITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CALCITE_dewminerals_Kp(double t, double p):
    result = CALCITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "DIASPORE_dewminerals_calc.h":
    const char *DIASPORE_dewminerals_identifier();
    const char *DIASPORE_dewminerals_name();
    const char *DIASPORE_dewminerals_formula();
    const double DIASPORE_dewminerals_mw();
    const double *DIASPORE_dewminerals_elements();
    double DIASPORE_dewminerals_g(double t, double p)
    double DIASPORE_dewminerals_dgdt(double t, double p)
    double DIASPORE_dewminerals_dgdp(double t, double p)
    double DIASPORE_dewminerals_d2gdt2(double t, double p)
    double DIASPORE_dewminerals_d2gdtdp(double t, double p)
    double DIASPORE_dewminerals_d2gdp2(double t, double p)
    double DIASPORE_dewminerals_d3gdt3(double t, double p)
    double DIASPORE_dewminerals_d3gdt2dp(double t, double p)
    double DIASPORE_dewminerals_d3gdtdp2(double t, double p)
    double DIASPORE_dewminerals_d3gdp3(double t, double p)
    double DIASPORE_dewminerals_s(double t, double p)
    double DIASPORE_dewminerals_v(double t, double p)
    double DIASPORE_dewminerals_cv(double t, double p)
    double DIASPORE_dewminerals_cp(double t, double p)
    double DIASPORE_dewminerals_dcpdt(double t, double p)
    double DIASPORE_dewminerals_alpha(double t, double p)
    double DIASPORE_dewminerals_beta(double t, double p)
    double DIASPORE_dewminerals_K(double t, double p)
    double DIASPORE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_DIASPORE_dewminerals_identifier():
    result = <bytes> DIASPORE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_DIASPORE_dewminerals_name():
    result = <bytes> DIASPORE_dewminerals_name()
    return result.decode('UTF-8')
def cy_DIASPORE_dewminerals_formula():
    result = <bytes> DIASPORE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_DIASPORE_dewminerals_mw():
    result = DIASPORE_dewminerals_mw()
    return result
def cy_DIASPORE_dewminerals_elements():
    cdef const double *e = DIASPORE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_DIASPORE_dewminerals_g(double t, double p):
    result = DIASPORE_dewminerals_g(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_dgdt(double t, double p):
    result = DIASPORE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_dgdp(double t, double p):
    result = DIASPORE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d2gdt2(double t, double p):
    result = DIASPORE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d2gdtdp(double t, double p):
    result = DIASPORE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d2gdp2(double t, double p):
    result = DIASPORE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d3gdt3(double t, double p):
    result = DIASPORE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d3gdt2dp(double t, double p):
    result = DIASPORE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d3gdtdp2(double t, double p):
    result = DIASPORE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_d3gdp3(double t, double p):
    result = DIASPORE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_s(double t, double p):
    result = DIASPORE_dewminerals_s(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_v(double t, double p):
    result = DIASPORE_dewminerals_v(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_cv(double t, double p):
    result = DIASPORE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_cp(double t, double p):
    result = DIASPORE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_dcpdt(double t, double p):
    result = DIASPORE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_alpha(double t, double p):
    result = DIASPORE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_beta(double t, double p):
    result = DIASPORE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_K(double t, double p):
    result = DIASPORE_dewminerals_K(<double> t, <double> p)
    return result
def cy_DIASPORE_dewminerals_Kp(double t, double p):
    result = DIASPORE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "BRUCITE_dewminerals_calc.h":
    const char *BRUCITE_dewminerals_identifier();
    const char *BRUCITE_dewminerals_name();
    const char *BRUCITE_dewminerals_formula();
    const double BRUCITE_dewminerals_mw();
    const double *BRUCITE_dewminerals_elements();
    double BRUCITE_dewminerals_g(double t, double p)
    double BRUCITE_dewminerals_dgdt(double t, double p)
    double BRUCITE_dewminerals_dgdp(double t, double p)
    double BRUCITE_dewminerals_d2gdt2(double t, double p)
    double BRUCITE_dewminerals_d2gdtdp(double t, double p)
    double BRUCITE_dewminerals_d2gdp2(double t, double p)
    double BRUCITE_dewminerals_d3gdt3(double t, double p)
    double BRUCITE_dewminerals_d3gdt2dp(double t, double p)
    double BRUCITE_dewminerals_d3gdtdp2(double t, double p)
    double BRUCITE_dewminerals_d3gdp3(double t, double p)
    double BRUCITE_dewminerals_s(double t, double p)
    double BRUCITE_dewminerals_v(double t, double p)
    double BRUCITE_dewminerals_cv(double t, double p)
    double BRUCITE_dewminerals_cp(double t, double p)
    double BRUCITE_dewminerals_dcpdt(double t, double p)
    double BRUCITE_dewminerals_alpha(double t, double p)
    double BRUCITE_dewminerals_beta(double t, double p)
    double BRUCITE_dewminerals_K(double t, double p)
    double BRUCITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_BRUCITE_dewminerals_identifier():
    result = <bytes> BRUCITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_BRUCITE_dewminerals_name():
    result = <bytes> BRUCITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_BRUCITE_dewminerals_formula():
    result = <bytes> BRUCITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_BRUCITE_dewminerals_mw():
    result = BRUCITE_dewminerals_mw()
    return result
def cy_BRUCITE_dewminerals_elements():
    cdef const double *e = BRUCITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_BRUCITE_dewminerals_g(double t, double p):
    result = BRUCITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_dgdt(double t, double p):
    result = BRUCITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_dgdp(double t, double p):
    result = BRUCITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d2gdt2(double t, double p):
    result = BRUCITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d2gdtdp(double t, double p):
    result = BRUCITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d2gdp2(double t, double p):
    result = BRUCITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d3gdt3(double t, double p):
    result = BRUCITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d3gdt2dp(double t, double p):
    result = BRUCITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d3gdtdp2(double t, double p):
    result = BRUCITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_d3gdp3(double t, double p):
    result = BRUCITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_s(double t, double p):
    result = BRUCITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_v(double t, double p):
    result = BRUCITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_cv(double t, double p):
    result = BRUCITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_cp(double t, double p):
    result = BRUCITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_dcpdt(double t, double p):
    result = BRUCITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_alpha(double t, double p):
    result = BRUCITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_beta(double t, double p):
    result = BRUCITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_K(double t, double p):
    result = BRUCITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_BRUCITE_dewminerals_Kp(double t, double p):
    result = BRUCITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "SPINEL_dewminerals_calc.h":
    const char *SPINEL_dewminerals_identifier();
    const char *SPINEL_dewminerals_name();
    const char *SPINEL_dewminerals_formula();
    const double SPINEL_dewminerals_mw();
    const double *SPINEL_dewminerals_elements();
    double SPINEL_dewminerals_g(double t, double p)
    double SPINEL_dewminerals_dgdt(double t, double p)
    double SPINEL_dewminerals_dgdp(double t, double p)
    double SPINEL_dewminerals_d2gdt2(double t, double p)
    double SPINEL_dewminerals_d2gdtdp(double t, double p)
    double SPINEL_dewminerals_d2gdp2(double t, double p)
    double SPINEL_dewminerals_d3gdt3(double t, double p)
    double SPINEL_dewminerals_d3gdt2dp(double t, double p)
    double SPINEL_dewminerals_d3gdtdp2(double t, double p)
    double SPINEL_dewminerals_d3gdp3(double t, double p)
    double SPINEL_dewminerals_s(double t, double p)
    double SPINEL_dewminerals_v(double t, double p)
    double SPINEL_dewminerals_cv(double t, double p)
    double SPINEL_dewminerals_cp(double t, double p)
    double SPINEL_dewminerals_dcpdt(double t, double p)
    double SPINEL_dewminerals_alpha(double t, double p)
    double SPINEL_dewminerals_beta(double t, double p)
    double SPINEL_dewminerals_K(double t, double p)
    double SPINEL_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_SPINEL_dewminerals_identifier():
    result = <bytes> SPINEL_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_SPINEL_dewminerals_name():
    result = <bytes> SPINEL_dewminerals_name()
    return result.decode('UTF-8')
def cy_SPINEL_dewminerals_formula():
    result = <bytes> SPINEL_dewminerals_formula()
    return result.decode('UTF-8')
def cy_SPINEL_dewminerals_mw():
    result = SPINEL_dewminerals_mw()
    return result
def cy_SPINEL_dewminerals_elements():
    cdef const double *e = SPINEL_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_SPINEL_dewminerals_g(double t, double p):
    result = SPINEL_dewminerals_g(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_dgdt(double t, double p):
    result = SPINEL_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_dgdp(double t, double p):
    result = SPINEL_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d2gdt2(double t, double p):
    result = SPINEL_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d2gdtdp(double t, double p):
    result = SPINEL_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d2gdp2(double t, double p):
    result = SPINEL_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d3gdt3(double t, double p):
    result = SPINEL_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d3gdt2dp(double t, double p):
    result = SPINEL_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d3gdtdp2(double t, double p):
    result = SPINEL_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_d3gdp3(double t, double p):
    result = SPINEL_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_s(double t, double p):
    result = SPINEL_dewminerals_s(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_v(double t, double p):
    result = SPINEL_dewminerals_v(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_cv(double t, double p):
    result = SPINEL_dewminerals_cv(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_cp(double t, double p):
    result = SPINEL_dewminerals_cp(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_dcpdt(double t, double p):
    result = SPINEL_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_alpha(double t, double p):
    result = SPINEL_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_beta(double t, double p):
    result = SPINEL_dewminerals_beta(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_K(double t, double p):
    result = SPINEL_dewminerals_K(<double> t, <double> p)
    return result
def cy_SPINEL_dewminerals_Kp(double t, double p):
    result = SPINEL_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "LIME_dewminerals_calc.h":
    const char *LIME_dewminerals_identifier();
    const char *LIME_dewminerals_name();
    const char *LIME_dewminerals_formula();
    const double LIME_dewminerals_mw();
    const double *LIME_dewminerals_elements();
    double LIME_dewminerals_g(double t, double p)
    double LIME_dewminerals_dgdt(double t, double p)
    double LIME_dewminerals_dgdp(double t, double p)
    double LIME_dewminerals_d2gdt2(double t, double p)
    double LIME_dewminerals_d2gdtdp(double t, double p)
    double LIME_dewminerals_d2gdp2(double t, double p)
    double LIME_dewminerals_d3gdt3(double t, double p)
    double LIME_dewminerals_d3gdt2dp(double t, double p)
    double LIME_dewminerals_d3gdtdp2(double t, double p)
    double LIME_dewminerals_d3gdp3(double t, double p)
    double LIME_dewminerals_s(double t, double p)
    double LIME_dewminerals_v(double t, double p)
    double LIME_dewminerals_cv(double t, double p)
    double LIME_dewminerals_cp(double t, double p)
    double LIME_dewminerals_dcpdt(double t, double p)
    double LIME_dewminerals_alpha(double t, double p)
    double LIME_dewminerals_beta(double t, double p)
    double LIME_dewminerals_K(double t, double p)
    double LIME_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_LIME_dewminerals_identifier():
    result = <bytes> LIME_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_LIME_dewminerals_name():
    result = <bytes> LIME_dewminerals_name()
    return result.decode('UTF-8')
def cy_LIME_dewminerals_formula():
    result = <bytes> LIME_dewminerals_formula()
    return result.decode('UTF-8')
def cy_LIME_dewminerals_mw():
    result = LIME_dewminerals_mw()
    return result
def cy_LIME_dewminerals_elements():
    cdef const double *e = LIME_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_LIME_dewminerals_g(double t, double p):
    result = LIME_dewminerals_g(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_dgdt(double t, double p):
    result = LIME_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_dgdp(double t, double p):
    result = LIME_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d2gdt2(double t, double p):
    result = LIME_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d2gdtdp(double t, double p):
    result = LIME_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d2gdp2(double t, double p):
    result = LIME_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d3gdt3(double t, double p):
    result = LIME_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d3gdt2dp(double t, double p):
    result = LIME_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d3gdtdp2(double t, double p):
    result = LIME_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_d3gdp3(double t, double p):
    result = LIME_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_s(double t, double p):
    result = LIME_dewminerals_s(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_v(double t, double p):
    result = LIME_dewminerals_v(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_cv(double t, double p):
    result = LIME_dewminerals_cv(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_cp(double t, double p):
    result = LIME_dewminerals_cp(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_dcpdt(double t, double p):
    result = LIME_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_alpha(double t, double p):
    result = LIME_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_beta(double t, double p):
    result = LIME_dewminerals_beta(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_K(double t, double p):
    result = LIME_dewminerals_K(<double> t, <double> p)
    return result
def cy_LIME_dewminerals_Kp(double t, double p):
    result = LIME_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "PERICLASE_dewminerals_calc.h":
    const char *PERICLASE_dewminerals_identifier();
    const char *PERICLASE_dewminerals_name();
    const char *PERICLASE_dewminerals_formula();
    const double PERICLASE_dewminerals_mw();
    const double *PERICLASE_dewminerals_elements();
    double PERICLASE_dewminerals_g(double t, double p)
    double PERICLASE_dewminerals_dgdt(double t, double p)
    double PERICLASE_dewminerals_dgdp(double t, double p)
    double PERICLASE_dewminerals_d2gdt2(double t, double p)
    double PERICLASE_dewminerals_d2gdtdp(double t, double p)
    double PERICLASE_dewminerals_d2gdp2(double t, double p)
    double PERICLASE_dewminerals_d3gdt3(double t, double p)
    double PERICLASE_dewminerals_d3gdt2dp(double t, double p)
    double PERICLASE_dewminerals_d3gdtdp2(double t, double p)
    double PERICLASE_dewminerals_d3gdp3(double t, double p)
    double PERICLASE_dewminerals_s(double t, double p)
    double PERICLASE_dewminerals_v(double t, double p)
    double PERICLASE_dewminerals_cv(double t, double p)
    double PERICLASE_dewminerals_cp(double t, double p)
    double PERICLASE_dewminerals_dcpdt(double t, double p)
    double PERICLASE_dewminerals_alpha(double t, double p)
    double PERICLASE_dewminerals_beta(double t, double p)
    double PERICLASE_dewminerals_K(double t, double p)
    double PERICLASE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_PERICLASE_dewminerals_identifier():
    result = <bytes> PERICLASE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_PERICLASE_dewminerals_name():
    result = <bytes> PERICLASE_dewminerals_name()
    return result.decode('UTF-8')
def cy_PERICLASE_dewminerals_formula():
    result = <bytes> PERICLASE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_PERICLASE_dewminerals_mw():
    result = PERICLASE_dewminerals_mw()
    return result
def cy_PERICLASE_dewminerals_elements():
    cdef const double *e = PERICLASE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_PERICLASE_dewminerals_g(double t, double p):
    result = PERICLASE_dewminerals_g(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_dgdt(double t, double p):
    result = PERICLASE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_dgdp(double t, double p):
    result = PERICLASE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d2gdt2(double t, double p):
    result = PERICLASE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d2gdtdp(double t, double p):
    result = PERICLASE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d2gdp2(double t, double p):
    result = PERICLASE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d3gdt3(double t, double p):
    result = PERICLASE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d3gdt2dp(double t, double p):
    result = PERICLASE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d3gdtdp2(double t, double p):
    result = PERICLASE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_d3gdp3(double t, double p):
    result = PERICLASE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_s(double t, double p):
    result = PERICLASE_dewminerals_s(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_v(double t, double p):
    result = PERICLASE_dewminerals_v(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_cv(double t, double p):
    result = PERICLASE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_cp(double t, double p):
    result = PERICLASE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_dcpdt(double t, double p):
    result = PERICLASE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_alpha(double t, double p):
    result = PERICLASE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_beta(double t, double p):
    result = PERICLASE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_K(double t, double p):
    result = PERICLASE_dewminerals_K(<double> t, <double> p)
    return result
def cy_PERICLASE_dewminerals_Kp(double t, double p):
    result = PERICLASE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "HEMATITE_dewminerals_calc.h":
    const char *HEMATITE_dewminerals_identifier();
    const char *HEMATITE_dewminerals_name();
    const char *HEMATITE_dewminerals_formula();
    const double HEMATITE_dewminerals_mw();
    const double *HEMATITE_dewminerals_elements();
    double HEMATITE_dewminerals_g(double t, double p)
    double HEMATITE_dewminerals_dgdt(double t, double p)
    double HEMATITE_dewminerals_dgdp(double t, double p)
    double HEMATITE_dewminerals_d2gdt2(double t, double p)
    double HEMATITE_dewminerals_d2gdtdp(double t, double p)
    double HEMATITE_dewminerals_d2gdp2(double t, double p)
    double HEMATITE_dewminerals_d3gdt3(double t, double p)
    double HEMATITE_dewminerals_d3gdt2dp(double t, double p)
    double HEMATITE_dewminerals_d3gdtdp2(double t, double p)
    double HEMATITE_dewminerals_d3gdp3(double t, double p)
    double HEMATITE_dewminerals_s(double t, double p)
    double HEMATITE_dewminerals_v(double t, double p)
    double HEMATITE_dewminerals_cv(double t, double p)
    double HEMATITE_dewminerals_cp(double t, double p)
    double HEMATITE_dewminerals_dcpdt(double t, double p)
    double HEMATITE_dewminerals_alpha(double t, double p)
    double HEMATITE_dewminerals_beta(double t, double p)
    double HEMATITE_dewminerals_K(double t, double p)
    double HEMATITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_HEMATITE_dewminerals_identifier():
    result = <bytes> HEMATITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_HEMATITE_dewminerals_name():
    result = <bytes> HEMATITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_HEMATITE_dewminerals_formula():
    result = <bytes> HEMATITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_HEMATITE_dewminerals_mw():
    result = HEMATITE_dewminerals_mw()
    return result
def cy_HEMATITE_dewminerals_elements():
    cdef const double *e = HEMATITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_HEMATITE_dewminerals_g(double t, double p):
    result = HEMATITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_dgdt(double t, double p):
    result = HEMATITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_dgdp(double t, double p):
    result = HEMATITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d2gdt2(double t, double p):
    result = HEMATITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d2gdtdp(double t, double p):
    result = HEMATITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d2gdp2(double t, double p):
    result = HEMATITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d3gdt3(double t, double p):
    result = HEMATITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d3gdt2dp(double t, double p):
    result = HEMATITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d3gdtdp2(double t, double p):
    result = HEMATITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_d3gdp3(double t, double p):
    result = HEMATITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_s(double t, double p):
    result = HEMATITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_v(double t, double p):
    result = HEMATITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_cv(double t, double p):
    result = HEMATITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_cp(double t, double p):
    result = HEMATITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_dcpdt(double t, double p):
    result = HEMATITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_alpha(double t, double p):
    result = HEMATITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_beta(double t, double p):
    result = HEMATITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_K(double t, double p):
    result = HEMATITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_HEMATITE_dewminerals_Kp(double t, double p):
    result = HEMATITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CORUNDUM_dewminerals_calc.h":
    const char *CORUNDUM_dewminerals_identifier();
    const char *CORUNDUM_dewminerals_name();
    const char *CORUNDUM_dewminerals_formula();
    const double CORUNDUM_dewminerals_mw();
    const double *CORUNDUM_dewminerals_elements();
    double CORUNDUM_dewminerals_g(double t, double p)
    double CORUNDUM_dewminerals_dgdt(double t, double p)
    double CORUNDUM_dewminerals_dgdp(double t, double p)
    double CORUNDUM_dewminerals_d2gdt2(double t, double p)
    double CORUNDUM_dewminerals_d2gdtdp(double t, double p)
    double CORUNDUM_dewminerals_d2gdp2(double t, double p)
    double CORUNDUM_dewminerals_d3gdt3(double t, double p)
    double CORUNDUM_dewminerals_d3gdt2dp(double t, double p)
    double CORUNDUM_dewminerals_d3gdtdp2(double t, double p)
    double CORUNDUM_dewminerals_d3gdp3(double t, double p)
    double CORUNDUM_dewminerals_s(double t, double p)
    double CORUNDUM_dewminerals_v(double t, double p)
    double CORUNDUM_dewminerals_cv(double t, double p)
    double CORUNDUM_dewminerals_cp(double t, double p)
    double CORUNDUM_dewminerals_dcpdt(double t, double p)
    double CORUNDUM_dewminerals_alpha(double t, double p)
    double CORUNDUM_dewminerals_beta(double t, double p)
    double CORUNDUM_dewminerals_K(double t, double p)
    double CORUNDUM_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CORUNDUM_dewminerals_identifier():
    result = <bytes> CORUNDUM_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CORUNDUM_dewminerals_name():
    result = <bytes> CORUNDUM_dewminerals_name()
    return result.decode('UTF-8')
def cy_CORUNDUM_dewminerals_formula():
    result = <bytes> CORUNDUM_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CORUNDUM_dewminerals_mw():
    result = CORUNDUM_dewminerals_mw()
    return result
def cy_CORUNDUM_dewminerals_elements():
    cdef const double *e = CORUNDUM_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CORUNDUM_dewminerals_g(double t, double p):
    result = CORUNDUM_dewminerals_g(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_dgdt(double t, double p):
    result = CORUNDUM_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_dgdp(double t, double p):
    result = CORUNDUM_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d2gdt2(double t, double p):
    result = CORUNDUM_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d2gdtdp(double t, double p):
    result = CORUNDUM_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d2gdp2(double t, double p):
    result = CORUNDUM_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d3gdt3(double t, double p):
    result = CORUNDUM_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d3gdt2dp(double t, double p):
    result = CORUNDUM_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d3gdtdp2(double t, double p):
    result = CORUNDUM_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_d3gdp3(double t, double p):
    result = CORUNDUM_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_s(double t, double p):
    result = CORUNDUM_dewminerals_s(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_v(double t, double p):
    result = CORUNDUM_dewminerals_v(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_cv(double t, double p):
    result = CORUNDUM_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_cp(double t, double p):
    result = CORUNDUM_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_dcpdt(double t, double p):
    result = CORUNDUM_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_alpha(double t, double p):
    result = CORUNDUM_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_beta(double t, double p):
    result = CORUNDUM_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_K(double t, double p):
    result = CORUNDUM_dewminerals_K(<double> t, <double> p)
    return result
def cy_CORUNDUM_dewminerals_Kp(double t, double p):
    result = CORUNDUM_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "MAGNETITE_dewminerals_calc.h":
    const char *MAGNETITE_dewminerals_identifier();
    const char *MAGNETITE_dewminerals_name();
    const char *MAGNETITE_dewminerals_formula();
    const double MAGNETITE_dewminerals_mw();
    const double *MAGNETITE_dewminerals_elements();
    double MAGNETITE_dewminerals_g(double t, double p)
    double MAGNETITE_dewminerals_dgdt(double t, double p)
    double MAGNETITE_dewminerals_dgdp(double t, double p)
    double MAGNETITE_dewminerals_d2gdt2(double t, double p)
    double MAGNETITE_dewminerals_d2gdtdp(double t, double p)
    double MAGNETITE_dewminerals_d2gdp2(double t, double p)
    double MAGNETITE_dewminerals_d3gdt3(double t, double p)
    double MAGNETITE_dewminerals_d3gdt2dp(double t, double p)
    double MAGNETITE_dewminerals_d3gdtdp2(double t, double p)
    double MAGNETITE_dewminerals_d3gdp3(double t, double p)
    double MAGNETITE_dewminerals_s(double t, double p)
    double MAGNETITE_dewminerals_v(double t, double p)
    double MAGNETITE_dewminerals_cv(double t, double p)
    double MAGNETITE_dewminerals_cp(double t, double p)
    double MAGNETITE_dewminerals_dcpdt(double t, double p)
    double MAGNETITE_dewminerals_alpha(double t, double p)
    double MAGNETITE_dewminerals_beta(double t, double p)
    double MAGNETITE_dewminerals_K(double t, double p)
    double MAGNETITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_MAGNETITE_dewminerals_identifier():
    result = <bytes> MAGNETITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_MAGNETITE_dewminerals_name():
    result = <bytes> MAGNETITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_MAGNETITE_dewminerals_formula():
    result = <bytes> MAGNETITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_MAGNETITE_dewminerals_mw():
    result = MAGNETITE_dewminerals_mw()
    return result
def cy_MAGNETITE_dewminerals_elements():
    cdef const double *e = MAGNETITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_MAGNETITE_dewminerals_g(double t, double p):
    result = MAGNETITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_dgdt(double t, double p):
    result = MAGNETITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_dgdp(double t, double p):
    result = MAGNETITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d2gdt2(double t, double p):
    result = MAGNETITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d2gdtdp(double t, double p):
    result = MAGNETITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d2gdp2(double t, double p):
    result = MAGNETITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d3gdt3(double t, double p):
    result = MAGNETITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d3gdt2dp(double t, double p):
    result = MAGNETITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d3gdtdp2(double t, double p):
    result = MAGNETITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_d3gdp3(double t, double p):
    result = MAGNETITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_s(double t, double p):
    result = MAGNETITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_v(double t, double p):
    result = MAGNETITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_cv(double t, double p):
    result = MAGNETITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_cp(double t, double p):
    result = MAGNETITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_dcpdt(double t, double p):
    result = MAGNETITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_alpha(double t, double p):
    result = MAGNETITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_beta(double t, double p):
    result = MAGNETITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_K(double t, double p):
    result = MAGNETITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_MAGNETITE_dewminerals_Kp(double t, double p):
    result = MAGNETITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "DIAMOND_dewminerals_calc.h":
    const char *DIAMOND_dewminerals_identifier();
    const char *DIAMOND_dewminerals_name();
    const char *DIAMOND_dewminerals_formula();
    const double DIAMOND_dewminerals_mw();
    const double *DIAMOND_dewminerals_elements();
    double DIAMOND_dewminerals_g(double t, double p)
    double DIAMOND_dewminerals_dgdt(double t, double p)
    double DIAMOND_dewminerals_dgdp(double t, double p)
    double DIAMOND_dewminerals_d2gdt2(double t, double p)
    double DIAMOND_dewminerals_d2gdtdp(double t, double p)
    double DIAMOND_dewminerals_d2gdp2(double t, double p)
    double DIAMOND_dewminerals_d3gdt3(double t, double p)
    double DIAMOND_dewminerals_d3gdt2dp(double t, double p)
    double DIAMOND_dewminerals_d3gdtdp2(double t, double p)
    double DIAMOND_dewminerals_d3gdp3(double t, double p)
    double DIAMOND_dewminerals_s(double t, double p)
    double DIAMOND_dewminerals_v(double t, double p)
    double DIAMOND_dewminerals_cv(double t, double p)
    double DIAMOND_dewminerals_cp(double t, double p)
    double DIAMOND_dewminerals_dcpdt(double t, double p)
    double DIAMOND_dewminerals_alpha(double t, double p)
    double DIAMOND_dewminerals_beta(double t, double p)
    double DIAMOND_dewminerals_K(double t, double p)
    double DIAMOND_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_DIAMOND_dewminerals_identifier():
    result = <bytes> DIAMOND_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_DIAMOND_dewminerals_name():
    result = <bytes> DIAMOND_dewminerals_name()
    return result.decode('UTF-8')
def cy_DIAMOND_dewminerals_formula():
    result = <bytes> DIAMOND_dewminerals_formula()
    return result.decode('UTF-8')
def cy_DIAMOND_dewminerals_mw():
    result = DIAMOND_dewminerals_mw()
    return result
def cy_DIAMOND_dewminerals_elements():
    cdef const double *e = DIAMOND_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_DIAMOND_dewminerals_g(double t, double p):
    result = DIAMOND_dewminerals_g(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_dgdt(double t, double p):
    result = DIAMOND_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_dgdp(double t, double p):
    result = DIAMOND_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d2gdt2(double t, double p):
    result = DIAMOND_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d2gdtdp(double t, double p):
    result = DIAMOND_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d2gdp2(double t, double p):
    result = DIAMOND_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d3gdt3(double t, double p):
    result = DIAMOND_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d3gdt2dp(double t, double p):
    result = DIAMOND_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d3gdtdp2(double t, double p):
    result = DIAMOND_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_d3gdp3(double t, double p):
    result = DIAMOND_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_s(double t, double p):
    result = DIAMOND_dewminerals_s(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_v(double t, double p):
    result = DIAMOND_dewminerals_v(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_cv(double t, double p):
    result = DIAMOND_dewminerals_cv(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_cp(double t, double p):
    result = DIAMOND_dewminerals_cp(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_dcpdt(double t, double p):
    result = DIAMOND_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_alpha(double t, double p):
    result = DIAMOND_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_beta(double t, double p):
    result = DIAMOND_dewminerals_beta(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_K(double t, double p):
    result = DIAMOND_dewminerals_K(<double> t, <double> p)
    return result
def cy_DIAMOND_dewminerals_Kp(double t, double p):
    result = DIAMOND_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "CHLORAPATITE_dewminerals_calc.h":
    const char *CHLORAPATITE_dewminerals_identifier();
    const char *CHLORAPATITE_dewminerals_name();
    const char *CHLORAPATITE_dewminerals_formula();
    const double CHLORAPATITE_dewminerals_mw();
    const double *CHLORAPATITE_dewminerals_elements();
    double CHLORAPATITE_dewminerals_g(double t, double p)
    double CHLORAPATITE_dewminerals_dgdt(double t, double p)
    double CHLORAPATITE_dewminerals_dgdp(double t, double p)
    double CHLORAPATITE_dewminerals_d2gdt2(double t, double p)
    double CHLORAPATITE_dewminerals_d2gdtdp(double t, double p)
    double CHLORAPATITE_dewminerals_d2gdp2(double t, double p)
    double CHLORAPATITE_dewminerals_d3gdt3(double t, double p)
    double CHLORAPATITE_dewminerals_d3gdt2dp(double t, double p)
    double CHLORAPATITE_dewminerals_d3gdtdp2(double t, double p)
    double CHLORAPATITE_dewminerals_d3gdp3(double t, double p)
    double CHLORAPATITE_dewminerals_s(double t, double p)
    double CHLORAPATITE_dewminerals_v(double t, double p)
    double CHLORAPATITE_dewminerals_cv(double t, double p)
    double CHLORAPATITE_dewminerals_cp(double t, double p)
    double CHLORAPATITE_dewminerals_dcpdt(double t, double p)
    double CHLORAPATITE_dewminerals_alpha(double t, double p)
    double CHLORAPATITE_dewminerals_beta(double t, double p)
    double CHLORAPATITE_dewminerals_K(double t, double p)
    double CHLORAPATITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_CHLORAPATITE_dewminerals_identifier():
    result = <bytes> CHLORAPATITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_CHLORAPATITE_dewminerals_name():
    result = <bytes> CHLORAPATITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_CHLORAPATITE_dewminerals_formula():
    result = <bytes> CHLORAPATITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_CHLORAPATITE_dewminerals_mw():
    result = CHLORAPATITE_dewminerals_mw()
    return result
def cy_CHLORAPATITE_dewminerals_elements():
    cdef const double *e = CHLORAPATITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_CHLORAPATITE_dewminerals_g(double t, double p):
    result = CHLORAPATITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_dgdt(double t, double p):
    result = CHLORAPATITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_dgdp(double t, double p):
    result = CHLORAPATITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d2gdt2(double t, double p):
    result = CHLORAPATITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d2gdtdp(double t, double p):
    result = CHLORAPATITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d2gdp2(double t, double p):
    result = CHLORAPATITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d3gdt3(double t, double p):
    result = CHLORAPATITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d3gdt2dp(double t, double p):
    result = CHLORAPATITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d3gdtdp2(double t, double p):
    result = CHLORAPATITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_d3gdp3(double t, double p):
    result = CHLORAPATITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_s(double t, double p):
    result = CHLORAPATITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_v(double t, double p):
    result = CHLORAPATITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_cv(double t, double p):
    result = CHLORAPATITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_cp(double t, double p):
    result = CHLORAPATITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_dcpdt(double t, double p):
    result = CHLORAPATITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_alpha(double t, double p):
    result = CHLORAPATITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_beta(double t, double p):
    result = CHLORAPATITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_K(double t, double p):
    result = CHLORAPATITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_CHLORAPATITE_dewminerals_Kp(double t, double p):
    result = CHLORAPATITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "FLUORAPATITE_dewminerals_calc.h":
    const char *FLUORAPATITE_dewminerals_identifier();
    const char *FLUORAPATITE_dewminerals_name();
    const char *FLUORAPATITE_dewminerals_formula();
    const double FLUORAPATITE_dewminerals_mw();
    const double *FLUORAPATITE_dewminerals_elements();
    double FLUORAPATITE_dewminerals_g(double t, double p)
    double FLUORAPATITE_dewminerals_dgdt(double t, double p)
    double FLUORAPATITE_dewminerals_dgdp(double t, double p)
    double FLUORAPATITE_dewminerals_d2gdt2(double t, double p)
    double FLUORAPATITE_dewminerals_d2gdtdp(double t, double p)
    double FLUORAPATITE_dewminerals_d2gdp2(double t, double p)
    double FLUORAPATITE_dewminerals_d3gdt3(double t, double p)
    double FLUORAPATITE_dewminerals_d3gdt2dp(double t, double p)
    double FLUORAPATITE_dewminerals_d3gdtdp2(double t, double p)
    double FLUORAPATITE_dewminerals_d3gdp3(double t, double p)
    double FLUORAPATITE_dewminerals_s(double t, double p)
    double FLUORAPATITE_dewminerals_v(double t, double p)
    double FLUORAPATITE_dewminerals_cv(double t, double p)
    double FLUORAPATITE_dewminerals_cp(double t, double p)
    double FLUORAPATITE_dewminerals_dcpdt(double t, double p)
    double FLUORAPATITE_dewminerals_alpha(double t, double p)
    double FLUORAPATITE_dewminerals_beta(double t, double p)
    double FLUORAPATITE_dewminerals_K(double t, double p)
    double FLUORAPATITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_FLUORAPATITE_dewminerals_identifier():
    result = <bytes> FLUORAPATITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_FLUORAPATITE_dewminerals_name():
    result = <bytes> FLUORAPATITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_FLUORAPATITE_dewminerals_formula():
    result = <bytes> FLUORAPATITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_FLUORAPATITE_dewminerals_mw():
    result = FLUORAPATITE_dewminerals_mw()
    return result
def cy_FLUORAPATITE_dewminerals_elements():
    cdef const double *e = FLUORAPATITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_FLUORAPATITE_dewminerals_g(double t, double p):
    result = FLUORAPATITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_dgdt(double t, double p):
    result = FLUORAPATITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_dgdp(double t, double p):
    result = FLUORAPATITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d2gdt2(double t, double p):
    result = FLUORAPATITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d2gdtdp(double t, double p):
    result = FLUORAPATITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d2gdp2(double t, double p):
    result = FLUORAPATITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d3gdt3(double t, double p):
    result = FLUORAPATITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d3gdt2dp(double t, double p):
    result = FLUORAPATITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d3gdtdp2(double t, double p):
    result = FLUORAPATITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_d3gdp3(double t, double p):
    result = FLUORAPATITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_s(double t, double p):
    result = FLUORAPATITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_v(double t, double p):
    result = FLUORAPATITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_cv(double t, double p):
    result = FLUORAPATITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_cp(double t, double p):
    result = FLUORAPATITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_dcpdt(double t, double p):
    result = FLUORAPATITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_alpha(double t, double p):
    result = FLUORAPATITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_beta(double t, double p):
    result = FLUORAPATITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_K(double t, double p):
    result = FLUORAPATITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_FLUORAPATITE_dewminerals_Kp(double t, double p):
    result = FLUORAPATITE_dewminerals_Kp(<double> t, <double> p)
    return result
import numpy as np
cimport numpy as cnp # cimport gives us access to NumPy's C API

# here we just replicate the function signature from the header
cdef extern from "HYDROXYAPATITE_dewminerals_calc.h":
    const char *HYDROXYAPATITE_dewminerals_identifier();
    const char *HYDROXYAPATITE_dewminerals_name();
    const char *HYDROXYAPATITE_dewminerals_formula();
    const double HYDROXYAPATITE_dewminerals_mw();
    const double *HYDROXYAPATITE_dewminerals_elements();
    double HYDROXYAPATITE_dewminerals_g(double t, double p)
    double HYDROXYAPATITE_dewminerals_dgdt(double t, double p)
    double HYDROXYAPATITE_dewminerals_dgdp(double t, double p)
    double HYDROXYAPATITE_dewminerals_d2gdt2(double t, double p)
    double HYDROXYAPATITE_dewminerals_d2gdtdp(double t, double p)
    double HYDROXYAPATITE_dewminerals_d2gdp2(double t, double p)
    double HYDROXYAPATITE_dewminerals_d3gdt3(double t, double p)
    double HYDROXYAPATITE_dewminerals_d3gdt2dp(double t, double p)
    double HYDROXYAPATITE_dewminerals_d3gdtdp2(double t, double p)
    double HYDROXYAPATITE_dewminerals_d3gdp3(double t, double p)
    double HYDROXYAPATITE_dewminerals_s(double t, double p)
    double HYDROXYAPATITE_dewminerals_v(double t, double p)
    double HYDROXYAPATITE_dewminerals_cv(double t, double p)
    double HYDROXYAPATITE_dewminerals_cp(double t, double p)
    double HYDROXYAPATITE_dewminerals_dcpdt(double t, double p)
    double HYDROXYAPATITE_dewminerals_alpha(double t, double p)
    double HYDROXYAPATITE_dewminerals_beta(double t, double p)
    double HYDROXYAPATITE_dewminerals_K(double t, double p)
    double HYDROXYAPATITE_dewminerals_Kp(double t, double p)

# here is the "wrapper" signature
def cy_HYDROXYAPATITE_dewminerals_identifier():
    result = <bytes> HYDROXYAPATITE_dewminerals_identifier()
    return result.decode('UTF-8')
def cy_HYDROXYAPATITE_dewminerals_name():
    result = <bytes> HYDROXYAPATITE_dewminerals_name()
    return result.decode('UTF-8')
def cy_HYDROXYAPATITE_dewminerals_formula():
    result = <bytes> HYDROXYAPATITE_dewminerals_formula()
    return result.decode('UTF-8')
def cy_HYDROXYAPATITE_dewminerals_mw():
    result = HYDROXYAPATITE_dewminerals_mw()
    return result
def cy_HYDROXYAPATITE_dewminerals_elements():
    cdef const double *e = HYDROXYAPATITE_dewminerals_elements()
    np_array = np.zeros(106)
    for i in range(0,106):
        np_array[i] = e[i]
    return np_array
def cy_HYDROXYAPATITE_dewminerals_g(double t, double p):
    result = HYDROXYAPATITE_dewminerals_g(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_dgdt(double t, double p):
    result = HYDROXYAPATITE_dewminerals_dgdt(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_dgdp(double t, double p):
    result = HYDROXYAPATITE_dewminerals_dgdp(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d2gdt2(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d2gdt2(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d2gdtdp(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d2gdtdp(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d2gdp2(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d2gdp2(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d3gdt3(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d3gdt3(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d3gdt2dp(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d3gdt2dp(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d3gdtdp2(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d3gdtdp2(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_d3gdp3(double t, double p):
    result = HYDROXYAPATITE_dewminerals_d3gdp3(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_s(double t, double p):
    result = HYDROXYAPATITE_dewminerals_s(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_v(double t, double p):
    result = HYDROXYAPATITE_dewminerals_v(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_cv(double t, double p):
    result = HYDROXYAPATITE_dewminerals_cv(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_cp(double t, double p):
    result = HYDROXYAPATITE_dewminerals_cp(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_dcpdt(double t, double p):
    result = HYDROXYAPATITE_dewminerals_dcpdt(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_alpha(double t, double p):
    result = HYDROXYAPATITE_dewminerals_alpha(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_beta(double t, double p):
    result = HYDROXYAPATITE_dewminerals_beta(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_K(double t, double p):
    result = HYDROXYAPATITE_dewminerals_K(<double> t, <double> p)
    return result
def cy_HYDROXYAPATITE_dewminerals_Kp(double t, double p):
    result = HYDROXYAPATITE_dewminerals_Kp(<double> t, <double> p)
    return result
