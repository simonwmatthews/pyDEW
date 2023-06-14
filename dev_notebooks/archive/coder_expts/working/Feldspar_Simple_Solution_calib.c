
#include <stdlib.h>
#include <stdio.h>

#include "High_Albite_berman_calib.h"
#include "Anorthite_berman_calib.h"
#include "Potassium_Feldspar_berman_calib.h"


typedef struct _endmembers {
  const char *(*name) (void);
  const char *(*formula) (void);
  const double (*mw) (void);
  const double *(*elements) (void);
  double (*mu0) (double t, double p);
  double (*dmu0dT) (double t, double p);
  double (*dmu0dP) (double t, double p);
  double (*d2mu0dT2) (double t, double p);
  double (*d2mu0dTdP) (double t, double p);
  double (*d2mu0dP2) (double t, double p);
  double (*d3mu0dT3) (double t, double p);
  double (*d3mu0dT2dP) (double t, double p);
  double (*d3mu0dTdP2) (double t, double p);
  double (*d3mu0dP3) (double t, double p);
} Endmembers;

static Endmembers endmember[] = {
  {
    High_Albite_berman_calib_name,
    High_Albite_berman_calib_formula,
    High_Albite_berman_calib_mw,
    High_Albite_berman_calib_elements,
    High_Albite_berman_calib_g,
    High_Albite_berman_calib_dgdt,
    High_Albite_berman_calib_dgdp,
    High_Albite_berman_calib_d2gdt2,
    High_Albite_berman_calib_d2gdtdp,
    High_Albite_berman_calib_d2gdp2,
    High_Albite_berman_calib_d3gdt3,
    High_Albite_berman_calib_d3gdt2dp,
    High_Albite_berman_calib_d3gdtdp2,
    High_Albite_berman_calib_d3gdp3
  },
  {
    Anorthite_berman_calib_name,
    Anorthite_berman_calib_formula,
    Anorthite_berman_calib_mw,
    Anorthite_berman_calib_elements,
    Anorthite_berman_calib_g,
    Anorthite_berman_calib_dgdt,
    Anorthite_berman_calib_dgdp,
    Anorthite_berman_calib_d2gdt2,
    Anorthite_berman_calib_d2gdtdp,
    Anorthite_berman_calib_d2gdp2,
    Anorthite_berman_calib_d3gdt3,
    Anorthite_berman_calib_d3gdt2dp,
    Anorthite_berman_calib_d3gdtdp2,
    Anorthite_berman_calib_d3gdp3
  },
  {
    Potassium_Feldspar_berman_calib_name,
    Potassium_Feldspar_berman_calib_formula,
    Potassium_Feldspar_berman_calib_mw,
    Potassium_Feldspar_berman_calib_elements,
    Potassium_Feldspar_berman_calib_g,
    Potassium_Feldspar_berman_calib_dgdt,
    Potassium_Feldspar_berman_calib_dgdp,
    Potassium_Feldspar_berman_calib_d2gdt2,
    Potassium_Feldspar_berman_calib_d2gdtdp,
    Potassium_Feldspar_berman_calib_d2gdp2,
    Potassium_Feldspar_berman_calib_d3gdt3,
    Potassium_Feldspar_berman_calib_d3gdt2dp,
    Potassium_Feldspar_berman_calib_d3gdtdp2,
    Potassium_Feldspar_berman_calib_d3gdp3
  },

};
static int nc = (sizeof endmember / sizeof(struct _endmembers));

static const double R=8.3143;


static char *identifier = "Mon Jan 31 18:00:26 2022";
static double T_r = 298.15;
static double P_r = 1.0;
static double Wh12 = 7924.0;
static double Ws12 = 0.0;
static double Wv12 = 0.0;
static double dWh12 = -7924.0;
static double dWs12 = 0.0;
static double dWv12 = 0.0;
static double Wh13 = 46130.0;
static double Ws13 = 20.6;
static double Wv13 = 0.7866;
static double dWh13 = 8510.0;
static double dWs13 = 0.0;
static double dWv13 = -0.13379999999999997;
static double Wh23 = 79291.0;
static double Ws23 = 0.0;
static double Wv23 = -0.1037;
static double dWh23 = 1343.0;
static double dWs23 = 0.0;
static double dWv23 = 0.1037;
static double Wh123 = 12545.0;
static double Ws123 = 0.0;
static double Wv123 = -1.095;


#include "Simple_Solution_calc.h"
#include "Simple_Solution_calib.h"

const char *Feldspar_Simple_Solution_calib_identifier(void) {
    return identifier;
}

const char *Feldspar_Simple_Solution_calib_name(void) {
    return "Feldspar";
}

char *Feldspar_Simple_Solution_calib_formula(double T, double P, double n[3]) {
    double sum, elm[5];
    const double *end0 = (*endmember[0].elements)();
    const double *end1 = (*endmember[1].elements)();
    const double *end2 = (*endmember[2].elements)();
    int i;
    const char *fmt = "Ca%5.3fNa%5.3fK%5.3fAl%5.3fSi%5.3fO8";
    char *result = (char *) malloc(37*sizeof(char));
    for (i=0, sum=0.0; i<nc; i++) sum += n[i];
    if (sum == 0.0) return result;
    elm[0] = end0[20]*n[0]/sum + end1[20]*n[1]/sum + end2[20]*n[2]/sum;
    elm[1] = end0[11]*n[0]/sum + end1[11]*n[1]/sum + end2[11]*n[2]/sum;
    elm[2] = end0[19]*n[0]/sum + end1[19]*n[1]/sum + end2[19]*n[2]/sum;
    elm[3] = end0[13]*n[0]/sum + end1[13]*n[1]/sum + end2[13]*n[2]/sum;
    elm[4] = end0[14]*n[0]/sum + end1[14]*n[1]/sum + end2[14]*n[2]/sum;
    sprintf(result, fmt, elm[0], elm[1], elm[2], elm[3], elm[4]);
    return result;

}

double *Feldspar_Simple_Solution_calib_conv_elm_to_moles(double *e) {
    double *n = (double *) malloc(3*sizeof(double));
    n[0]=e[11];
    n[1]=e[20];
    n[2]=e[19];
    return n;

}

int Feldspar_Simple_Solution_calib_test_moles(double *n) {
    int result = 1;
    result &= (n[0] > 0.0);
    result &= (n[1] > 0.0);
    result &= (n[2] > 0.0);
    return result;

}

const char *Feldspar_Simple_Solution_calib_endmember_name(int index) {
    return (*endmember[index].name)();
}

const char *Feldspar_Simple_Solution_calib_endmember_formula(int index) {
    return (*endmember[index].formula)();
}

const double Feldspar_Simple_Solution_calib_endmember_mw(int index) {
    return (*endmember[index].mw)();
}

const double *Feldspar_Simple_Solution_calib_endmember_elements(int index) {
    return (*endmember[index].elements)();
}

double Feldspar_Simple_Solution_calib_endmember_mu0(int index, double t, double p) {
    return (*endmember[index].mu0)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_dmu0dT(int index, double t, double p) {
    return (*endmember[index].dmu0dT)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_dmu0dP(int index, double t, double p) {
    return (*endmember[index].dmu0dP)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d2mu0dT2(int index, double t, double p) {
    return (*endmember[index].d2mu0dT2)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d2mu0dTdP(int index, double t, double p) {
    return (*endmember[index].d2mu0dTdP)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d2mu0dP2(int index, double t, double p) {
    return (*endmember[index].d2mu0dP2)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d3mu0dT3(int index, double t, double p) {
    return (*endmember[index].d3mu0dT3)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d3mu0dT2dP(int index, double t, double p) {
    return (*endmember[index].d3mu0dT2dP)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d3mu0dTdP2(int index, double t, double p) {
    return (*endmember[index].d3mu0dTdP2)(t, p);
}

double Feldspar_Simple_Solution_calib_endmember_d3mu0dP3(int index, double t, double p) {
    return (*endmember[index].d3mu0dP3)(t, p);
}

double Feldspar_Simple_Solution_calib_g(double T, double P, double n[3]) {
    return Simple_Solution_g(T, P, n);
}

void Feldspar_Simple_Solution_calib_dgdn(double T, double P, double n[3], double result[3]) {
    Simple_Solution_dgdn(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d2gdn2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d2gdn2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d3gdn3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d3gdn3(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_dgdt(double T, double P, double n[3]) {
    return Simple_Solution_dgdt(T, P, n);
}

void Feldspar_Simple_Solution_calib_d2gdndt(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d2gdndt(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d3gdn2dt(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d3gdn2dt(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d4gdn3dt(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdn3dt(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_dgdp(double T, double P, double n[3]) {
    return Simple_Solution_dgdp(T, P, n);
}

void Feldspar_Simple_Solution_calib_d2gdndp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d2gdndp(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d3gdn2dp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d3gdn2dp(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d4gdn3dp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdn3dp(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d2gdt2(double T, double P, double n[3]) {
    return Simple_Solution_d2gdt2(T, P, n);
}

void Feldspar_Simple_Solution_calib_d3gdndt2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d3gdndt2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d4gdn2dt2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdn2dt2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn3dt2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn3dt2(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d2gdtdp(double T, double P, double n[3]) {
    return Simple_Solution_d2gdtdp(T, P, n);
}

void Feldspar_Simple_Solution_calib_d3gdndtdp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d3gdndtdp(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d4gdn2dtdp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdn2dtdp(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn3dtdp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn3dtdp(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d2gdp2(double T, double P, double n[3]) {
    return Simple_Solution_d2gdp2(T, P, n);
}

void Feldspar_Simple_Solution_calib_d3gdndp2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d3gdndp2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d4gdn2dp2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdn2dp2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn3dp2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn3dp2(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d3gdt3(double T, double P, double n[3]) {
    return Simple_Solution_d3gdt3(T, P, n);
}

void Feldspar_Simple_Solution_calib_d4gdndt3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdndt3(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn2dt3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn2dt3(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d6gdn3dt3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d6gdn3dt3(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d3gdt2dp(double T, double P, double n[3]) {
    return Simple_Solution_d3gdt2dp(T, P, n);
}

void Feldspar_Simple_Solution_calib_d4gdndt2dp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdndt2dp(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn2dt2dp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn2dt2dp(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d6gdn3dt2dp(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d6gdn3dt2dp(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d3gdtdp2(double T, double P, double n[3]) {
    return Simple_Solution_d3gdtdp2(T, P, n);
}

void Feldspar_Simple_Solution_calib_d4gdndtdp2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdndtdp2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn2dtdp2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn2dtdp2(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d6gdn3dtdp2(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d6gdn3dtdp2(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_d3gdp3(double T, double P, double n[3]) {
    return Simple_Solution_d3gdp3(T, P, n);
}

void Feldspar_Simple_Solution_calib_d4gdndp3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d4gdndp3(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d5gdn2dp3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d5gdn2dp3(T, P, n, result);
}

void Feldspar_Simple_Solution_calib_d6gdn3dp3(double T, double P, double n[3], double result[3]) {
    Simple_Solution_d6gdn3dp3(T, P, n, result);
}

double Feldspar_Simple_Solution_calib_s(double T, double P, double n[3]) {
    return Simple_Solution_s(T, P, n);
}

double Feldspar_Simple_Solution_calib_v(double T, double P, double n[3]) {
    return Simple_Solution_v(T, P, n);
}

double Feldspar_Simple_Solution_calib_cv(double T, double P, double n[3]) {
    return Simple_Solution_cv(T, P, n);
}

double Feldspar_Simple_Solution_calib_cp(double T, double P, double n[3]) {
    return Simple_Solution_cp(T, P, n);
}

double Feldspar_Simple_Solution_calib_dcpdt(double T, double P, double n[3]) {
    return Simple_Solution_dcpdt(T, P, n);
}

double Feldspar_Simple_Solution_calib_alpha(double T, double P, double n[3]) {
    return Simple_Solution_alpha(T, P, n);
}

double Feldspar_Simple_Solution_calib_beta(double T, double P, double n[3]) {
    return Simple_Solution_beta(T, P, n);
}

double Feldspar_Simple_Solution_calib_K(double T, double P, double n[3]) {
    return Simple_Solution_K(T, P, n);
}

double Feldspar_Simple_Solution_calib_Kp(double T, double P, double n[3]) {
    return Simple_Solution_Kp(T, P, n);
}

int Feldspar_Simple_Solution_get_param_number(void) {
    return Simple_Solution_get_param_number();
}

const char **Feldspar_Simple_Solution_get_param_names(void) {
    return Simple_Solution_get_param_names();
}

const char **Feldspar_Simple_Solution_get_param_units(void) {
    return Simple_Solution_get_param_units();
}

void Feldspar_Simple_Solution_get_param_values(double **values) {
    Simple_Solution_get_param_values(values);
}

int Feldspar_Simple_Solution_set_param_values(double *values) {
    return Simple_Solution_set_param_values(values);
}

double Feldspar_Simple_Solution_get_param_value(int index) {
    return Simple_Solution_get_param_value(index);
}

int Feldspar_Simple_Solution_set_param_value(int index, double value) {
    return Simple_Solution_set_param_value(index, value);
}

double Feldspar_Simple_Solution_dparam_g(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_g(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_dgdt(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_dgdt(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_dgdp(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_dgdp(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d2gdt2(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d2gdt2(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d2gdtdp(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d2gdtdp(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d2gdp2(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d2gdp2(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d3gdt3(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d3gdt3(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d3gdt2dp(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d3gdt2dp(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d3gdtdp2(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d3gdtdp2(T, P, n, index);
}

double Feldspar_Simple_Solution_dparam_d3gdp3(double T, double P, double n[3], int index) {
    return Simple_Solution_dparam_d3gdp3(T, P, n, index);
}

void Feldspar_Simple_Solution_dparam_dgdn(double T, double P, double n[3], int index, double result[3]) {
    Simple_Solution_dparam_dgdn(T, P, n, index, result);
}

