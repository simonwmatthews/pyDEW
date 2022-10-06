
static const char *identifier = "Tue Oct  4 14:31:23 2022";

static const double T_r = 298.15;
static const double P_r = 1.0;
static const double H_TrPr = -1614036.5885349999;
static const double S_TrPr = 113.3356667;
static const double k0 = 191.3206367;
static const double k1 = -494.3756667;
static const double k2 = -9763989.333;
static const double k3 = 1674025643.0;
static const double k5 = 0.0;
static const double k6 = 0.0;
static const double V_TrPr = 3.837;
static const double v1 = -1.8592773000000002e-07;
static const double v2 = 1.07e-13;
static const double v3 = 6.20416707e-06;
static const double v4 = 2.48463e-09;
static const double l1 = 0.0;
static const double l2 = 0.0;
static const double k_lambda = 0.0;
static const double T_lambda_Pr = 0.0;
static const double T_lambda_ref = 0.0;
static const double H_t = 0;
static const double d0 = 0.0;
static const double d1 = 0.0;
static const double d2 = 0;
static const double d3 = 0.0;
static const double d4 = 0.0;
static const double d5 = 0;
static const double T_D = 0;
static const double T_D_ref = 0;

#include <math.h>

static double dewminerals_g(double T, double P) {
    double result = 0.0;
    result += H_TrPr + 2*sqrt(T)*k1 + (1.0/2.0)*((T)*(T))*k5 + T*k0 - T*(S_TrPr + T*k5 - T_r*k5 + k0*log(T) - k0*log(T_r) + k6/T_r + (1.0/2.0)*k2/((T_r)*(T_r)) + (1.0/3.0)*k3/((T_r)*(T_r)*(T_r)) + 2*k1/sqrt(T_r) - k6/T - 1.0/2.0*k2/((T)*(T)) - 1.0/3.0*k3/((T)*(T)*(T)) - 2*k1/sqrt(T)) - 2*sqrt(T_r)*k1 - 1.0/2.0*((T_r)*(T_r))*k5 - T_r*k0 + k6*log(T) - k6*log(T_r) + k2/T_r + (1.0/2.0)*k3/((T_r)*(T_r)) - k2/T - 1.0/2.0*k3/((T)*(T));
    result += (1.0/3.0)*((P)*(P)*(P))*V_TrPr*v2 + ((P)*(P))*(-P_r*V_TrPr*v2 + (1.0/2.0)*V_TrPr*v1) + P*(((P_r)*(P_r))*V_TrPr*v2 - P_r*V_TrPr*v1 + ((T)*(T))*V_TrPr*v4 - 2*T*T_r*V_TrPr*v4 + T*V_TrPr*v3 + ((T_r)*(T_r))*V_TrPr*v4 - T_r*V_TrPr*v3 + V_TrPr) - 1.0/3.0*((P_r)*(P_r)*(P_r))*V_TrPr*v2 - ((P_r)*(P_r))*(-P_r*V_TrPr*v2 + (1.0/2.0)*V_TrPr*v1) - P_r*(((P_r)*(P_r))*V_TrPr*v2 - P_r*V_TrPr*v1 + ((T)*(T))*V_TrPr*v4 - 2*T*T_r*V_TrPr*v4 + T*V_TrPr*v3 + ((T_r)*(T_r))*V_TrPr*v4 - T_r*V_TrPr*v3 + V_TrPr);
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += (1.0/4.0)*((T)*(T)*(T)*(T))*((l2)*(l2)) + ((T)*(T)*(T))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) + ((T)*(T))*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) - T*((1.0/3.0)*((T)*(T)*(T))*((l2)*(l2)) + ((T)*(T))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) + T*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) - 1.0/3.0*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - (T_lambda_ref + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1)))) + T*(-((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 - 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 - P*k_lambda*((l1)*(l1)) + ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 + P_r*k_lambda*((l1)*(l1))) - 1.0/4.0*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) - ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) - (T_lambda_ref + k_lambda*(P - P_r))*(-((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 - 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 - P*k_lambda*((l1)*(l1)) + ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 + P_r*k_lambda*((l1)*(l1)));
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += (-T + T_lambda_Pr + k_lambda*(P - P_r))*(((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 + 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 + P*k_lambda*((l1)*(l1)) - ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 - P_r*k_lambda*((l1)*(l1)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) - 2.0/3.0*((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 1.0/3.0*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + ((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - 3*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) - 2*(T_lambda_Pr + k_lambda*(P - P_r))*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) + (T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))) + (T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) + ((l1)*(l1)) + ((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2)) - ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - (T_lambda_ref + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += H_t*(-T + T_lambda_Pr + k_lambda*(P - P_r))/(T_lambda_Pr + k_lambda*(P - P_r));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += H_t*(-T + T_lambda_Pr + k_lambda*(P - P_r))/(T_lambda_Pr + k_lambda*(P - P_r));
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += 2*sqrt(T)*d1 + (1.0/3.0)*((T)*(T)*(T))*d4 + (1.0/2.0)*((T)*(T))*d3 + T*d0 - T*((1.0/2.0)*((T)*(T))*d4 + T*d3 - 1.0/2.0*((T_D_ref)*(T_D_ref))*d4 - T_D_ref*d3 + d0*log(T) - d0*log(T_D_ref) + (1.0/2.0)*d2/((T_D_ref)*(T_D_ref)) + 2*d1/sqrt(T_D_ref) - 1.0/2.0*d2/((T)*(T)) - 2*d1/sqrt(T)) - 2*sqrt(T_D_ref)*d1 - 1.0/3.0*((T_D_ref)*(T_D_ref)*(T_D_ref))*d4 - 1.0/2.0*((T_D_ref)*(T_D_ref))*d3 - T_D_ref*d0 + (P - P_r)*(2*sqrt(T)*d1 + (1.0/3.0)*((T)*(T)*(T))*d4 + (1.0/2.0)*((T)*(T))*d3 + T*d0 - 2*sqrt(T_D_ref)*d1 - 1.0/3.0*((T_D_ref)*(T_D_ref)*(T_D_ref))*d4 - 1.0/2.0*((T_D_ref)*(T_D_ref))*d3 - T_D_ref*d0 + d2/T_D_ref - d2/T)/d5 + d2/T_D_ref - d2/T;
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D))) {
             result += (-T + T_D)*(-1.0/2.0*((T_D)*(T_D))*d4 + T_D*(T_D*d4 + d3 + d0/T_D + d2/((T_D)*(T_D)*(T_D)) + d1/pow(T_D, 3.0/2.0)) - 1.0/2.0*((T_D_ref)*(T_D_ref))*d4 - T_D_ref*d3 + d0*log(T_D) - d0*log(T_D_ref) - d0 - (P - P_r)*(((T_D)*(T_D))*d4 + T_D*d3 + d0 + d2/((T_D)*(T_D)) + d1/sqrt(T_D))/d5 + (1.0/2.0)*d2/((T_D_ref)*(T_D_ref)) + 2*d1/sqrt(T_D_ref) - 3.0/2.0*d2/((T_D)*(T_D)) - 3*d1/sqrt(T_D));
        }
    }
    return result;
}

static double dewminerals_dgdt(double T, double P) {
    double result = 0.0;
    result += -S_TrPr - T*(k5 + k0/T + k6/((T)*(T)) + k2/((T)*(T)*(T)) + k3/((T)*(T)*(T)*(T)) + k1/pow(T, 3.0/2.0)) + T_r*k5 - k0*log(T) + k0*log(T_r) + k0 - k6/T_r - 1.0/2.0*k2/((T_r)*(T_r)) - 1.0/3.0*k3/((T_r)*(T_r)*(T_r)) - 2*k1/sqrt(T_r) + 2*k6/T + (3.0/2.0)*k2/((T)*(T)) + (4.0/3.0)*k3/((T)*(T)*(T)) + 3*k1/sqrt(T);
    result += P*(2*T*V_TrPr*v4 - 2*T_r*V_TrPr*v4 + V_TrPr*v3) - P_r*(2*T*V_TrPr*v4 - 2*T_r*V_TrPr*v4 + V_TrPr*v3);
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 - 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 - P*k_lambda*((l1)*(l1)) + ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 + P_r*k_lambda*((l1)*(l1)) + (2.0/3.0)*((T)*(T)*(T))*((l2)*(l2)) - ((T)*(T))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) + 3*((T)*(T))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) + 2*T*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) - T*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))) - T*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((T)*(T))*((l2)*(l2)) + 2*T*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) + ((l1)*(l1)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/T) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) + (1.0/3.0)*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) + (T_lambda_ref + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1)));
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 - 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 - P*k_lambda*((l1)*(l1)) + ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 + P_r*k_lambda*((l1)*(l1)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_Pr + k_lambda*(P - P_r)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) + (2.0/3.0)*((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + (1.0/3.0)*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - ((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) + 3*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) - (T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))) - (T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) + ((l1)*(l1)) + ((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2)) + ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) + (T_lambda_ref + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -H_t/(T_lambda_Pr + k_lambda*(P - P_r));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -H_t/(T_lambda_Pr + k_lambda*(P - P_r));
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += (1.0/2.0)*((T)*(T))*d4 - T*(T*d4 + d3 + d0/T + d2/((T)*(T)*(T)) + d1/pow(T, 3.0/2.0)) + (1.0/2.0)*((T_D_ref)*(T_D_ref))*d4 + T_D_ref*d3 - d0*log(T) + d0*log(T_D_ref) + d0 + (P - P_r)*(((T)*(T))*d4 + T*d3 + d0 + d2/((T)*(T)) + d1/sqrt(T))/d5 - 1.0/2.0*d2/((T_D_ref)*(T_D_ref)) - 2*d1/sqrt(T_D_ref) + (3.0/2.0)*d2/((T)*(T)) + 3*d1/sqrt(T);
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D))) {
             result += (1.0/2.0)*((T_D)*(T_D))*d4 - T_D*(T_D*d4 + d3 + d0/T_D + d2/((T_D)*(T_D)*(T_D)) + d1/pow(T_D, 3.0/2.0)) + (1.0/2.0)*((T_D_ref)*(T_D_ref))*d4 + T_D_ref*d3 - d0*log(T_D) + d0*log(T_D_ref) + d0 + (P - P_r)*(((T_D)*(T_D))*d4 + T_D*d3 + d0 + d2/((T_D)*(T_D)) + d1/sqrt(T_D))/d5 - 1.0/2.0*d2/((T_D_ref)*(T_D_ref)) - 2*d1/sqrt(T_D_ref) + (3.0/2.0)*d2/((T_D)*(T_D)) + 3*d1/sqrt(T_D);
        }
    }
    return result;
}

static double dewminerals_dgdp(double T, double P) {
    double result = 0.0;
    result += ((P)*(P))*V_TrPr*v2 + 2*P*(-P_r*V_TrPr*v2 + (1.0/2.0)*V_TrPr*v1) + ((P_r)*(P_r))*V_TrPr*v2 - P_r*V_TrPr*v1 + ((T)*(T))*V_TrPr*v4 - 2*T*T_r*V_TrPr*v4 + T*V_TrPr*v3 + ((T_r)*(T_r))*V_TrPr*v4 - T_r*V_TrPr*v3 + V_TrPr;
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -((T)*(T)*(T))*k_lambda*((l2)*(l2)) + ((T)*(T))*(3*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*k_lambda*l1*l2) + T*(-3*((P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 6*P*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P*((k_lambda)*(k_lambda))*l1*l2 - 3*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P_r*((k_lambda)*(k_lambda))*l1*l2 - k_lambda*((l1)*(l1))) - T*(-3.0/2.0*((T)*(T))*k_lambda*((l2)*(l2)) + T*(6*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*k_lambda*l1*l2) + 2*((k_lambda)*(k_lambda))*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T) - 2*((k_lambda)*(k_lambda))*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) + ((k_lambda)*(k_lambda))*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) + (1.0/2.0)*k_lambda*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - 2*k_lambda*(T_lambda_ref + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - k_lambda*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T) + k_lambda*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) - k_lambda*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))) + (-T_lambda_ref - k_lambda*(P - P_r))*(6*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*k_lambda*l1*l2)) - 3*k_lambda*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) - 2*k_lambda*(T_lambda_ref + k_lambda*(P - P_r))*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) - k_lambda*(-((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 - 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 - P*k_lambda*((l1)*(l1)) + ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 + P_r*k_lambda*((l1)*(l1))) + (-T_lambda_ref - k_lambda*(P - P_r))*(-3*((P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 6*P*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P*((k_lambda)*(k_lambda))*l1*l2 - 3*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P_r*((k_lambda)*(k_lambda))*l1*l2 - k_lambda*((l1)*(l1))) - ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(3*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*k_lambda*l1*l2);
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += k_lambda*(((P)*(P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 3*((P)*(P))*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 2*((P)*(P))*((k_lambda)*(k_lambda))*l1*l2 + 3*P*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P*P_r*((k_lambda)*(k_lambda))*l1*l2 + P*k_lambda*((l1)*(l1)) - ((P_r)*(P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 2*((P_r)*(P_r))*((k_lambda)*(k_lambda))*l1*l2 - P_r*k_lambda*((l1)*(l1)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) - 2.0/3.0*((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 1.0/3.0*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + ((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - 3*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) - 2*(T_lambda_Pr + k_lambda*(P - P_r))*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) + (T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1))) + (T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) + ((l1)*(l1)) + ((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2)) - ((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - (T_lambda_ref + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + ((l1)*(l1)))) + (-T + T_lambda_Pr + k_lambda*(P - P_r))*(3*((P)*(P))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*((k_lambda)*(k_lambda))*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*((k_lambda)*(k_lambda))*l1*l2 + 2*((k_lambda)*(k_lambda))*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_Pr + k_lambda*(P - P_r)) - 2*((k_lambda)*(k_lambda))*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) + ((k_lambda)*(k_lambda))*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) - ((k_lambda)*(k_lambda))*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*((l1)*(l1)) - 1.0/2.0*k_lambda*((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + (1.0/2.0)*k_lambda*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 2*k_lambda*(T_lambda_Pr + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - 6*k_lambda*(T_lambda_Pr + k_lambda*(P - P_r))*(-P*k_lambda*((l2)*(l2)) + P_r*k_lambda*((l2)*(l2)) + (2.0/3.0)*l1*l2) - 2*k_lambda*(T_lambda_ref + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - k_lambda*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)) - 2*k_lambda*((3.0/2.0)*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*P*k_lambda*l1*l2 + (3.0/2.0)*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*P_r*k_lambda*l1*l2 + (1.0/2.0)*((l1)*(l1))) + k_lambda*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) + ((l1)*(l1)) + ((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2)) + (-2*T_lambda_Pr - 2*k_lambda*(P - P_r))*(3*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 3*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 2*k_lambda*l1*l2) + (T_lambda_Pr + k_lambda*(P - P_r))*(6*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*k_lambda*l1*l2) + (T_lambda_Pr + k_lambda*(P - P_r))*(6*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) + 2*((k_lambda)*(k_lambda))*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) + ((k_lambda)*(k_lambda))*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 4*k_lambda*l1*l2 + 2*k_lambda*((l2)*(l2))*(T_lambda_Pr + k_lambda*(P - P_r)) - 3.0/2.0*k_lambda*((l2)*(l2))*(2*T_lambda_Pr + 2*k_lambda*(P - P_r)) + 2*k_lambda*(-3.0/2.0*P*k_lambda*((l2)*(l2)) + (3.0/2.0)*P_r*k_lambda*((l2)*(l2)) + l1*l2) - k_lambda*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r))) + (-T_lambda_ref - k_lambda*(P - P_r))*(6*P*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*k_lambda*l1*l2));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += H_t*k_lambda/(T_lambda_Pr + k_lambda*(P - P_r)) - H_t*k_lambda*(-T + T_lambda_Pr + k_lambda*(P - P_r))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += H_t*k_lambda/(T_lambda_Pr + k_lambda*(P - P_r)) - H_t*k_lambda*(-T + T_lambda_Pr + k_lambda*(P - P_r))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += (2*sqrt(T)*d1 + (1.0/3.0)*((T)*(T)*(T))*d4 + (1.0/2.0)*((T)*(T))*d3 + T*d0 - 2*sqrt(T_D_ref)*d1 - 1.0/3.0*((T_D_ref)*(T_D_ref)*(T_D_ref))*d4 - 1.0/2.0*((T_D_ref)*(T_D_ref))*d3 - T_D_ref*d0 + d2/T_D_ref - d2/T)/d5;
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D))) {
             result += -(-T + T_D)*(((T_D)*(T_D))*d4 + T_D*d3 + d0 + d2/((T_D)*(T_D)) + d1/sqrt(T_D))/d5;
        }
    }
    return result;
}

static double dewminerals_d2gdt2(double T, double P) {
    double result = 0.0;
    result += (1.0/2.0)*T*(2*k0/((T)*(T)) + 4*k6/((T)*(T)*(T)) + 6*k2/((T)*(T)*(T)*(T)) + 8*k3/pow(T, 5) + 3*k1/pow(T, 5.0/2.0)) - k5 - 2*k0/T - 3*k6/((T)*(T)) - 4*k2/((T)*(T)*(T)) - 5*k3/((T)*(T)*(T)*(T)) - 5.0/2.0*k1/pow(T, 3.0/2.0);
    result += 2*V_TrPr*v4*(P - P_r);
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P*k_lambda*l1*l2 - 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P_r*k_lambda*l1*l2 + ((T)*(T))*((l2)*(l2)) - T*(-3*P*k_lambda*((l2)*(l2)) + 3*P_r*k_lambda*((l2)*(l2)) + 2*T*((l2)*(l2)) + 2*l1*l2 + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T)*(T))) - ((l1)*(l1)) + 2*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/T;
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += (1.0/2.0)*T*(-2*d4 + 2*d0/((T)*(T)) + 6*d2/((T)*(T)*(T)*(T)) + 3*d1/pow(T, 5.0/2.0)) - d3 + (1.0/2.0)*(P - P_r)*(4*T*d4 + 2*d3 - 4*d2/((T)*(T)*(T)) - d1/pow(T, 3.0/2.0))/d5 - 2*d0/T - 4*d2/((T)*(T)*(T)) - 5.0/2.0*d1/pow(T, 3.0/2.0);
        }
    }
    return result;
}

static double dewminerals_d2gdtdp(double T, double P) {
    double result = 0.0;
    result += V_TrPr*(2*T*v4 - 2*T_r*v4 + v3);
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += k_lambda*(-3.0/2.0*((T)*(T))*((l2)*(l2)) + T*(-6*P*k_lambda*((l2)*(l2)) + 6*P_r*k_lambda*((l2)*(l2)) + 3*T*((l2)*(l2)) + 4*l1*l2 - 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/T + ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/T) - 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) - 1.0/2.0*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - l2*(T_lambda_ref + k_lambda*(P - P_r))*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) + ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)));
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += k_lambda*(-3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P*k_lambda*l1*l2 - 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P_r*k_lambda*l1*l2 - 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_Pr + k_lambda*(P - P_r)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) + 2*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) - ((l1)*(l1)) - 1.0/2.0*((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 1.0/2.0*((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - l2*(T_lambda_ref + k_lambda*(P - P_r))*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - (T_lambda_Pr + k_lambda*(P - P_r))*(6*P*k_lambda*((l2)*(l2)) - 6*P_r*k_lambda*((l2)*(l2)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 4*l1*l2 - ((l2)*(l2))*(T_lambda_Pr + k_lambda*(P - P_r)) + l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r))) + ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_Pr + k_lambda*(P - P_r)) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += H_t*k_lambda/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += H_t*k_lambda/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += (((T)*(T))*d4 + T*d3 + d0 + d2/((T)*(T)) + d1/sqrt(T))/d5;
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D))) {
             result += (((T_D)*(T_D))*d4 + T_D*d3 + d0 + d2/((T_D)*(T_D)) + d1/sqrt(T_D))/d5;
        }
    }
    return result;
}

static double dewminerals_d2gdp2(double T, double P) {
    double result = 0.0;
    result += V_TrPr*(2*P*v2 - 2*P_r*v2 + v1);
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += ((k_lambda)*(k_lambda))*(3*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 6*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 4*P*k_lambda*l1*l2 + 3*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 4*P_r*k_lambda*l1*l2 + 3*((T)*(T))*((l2)*(l2)) + 2*T*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) + T*(-6*T*((l2)*(l2)) + 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T) - 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_ref + k_lambda*(P - P_r)) + 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 2*((l2)*(l2))*(T_lambda_ref + k_lambda*(P - P_r)) - 3*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T) + 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) - 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r))) + ((l1)*(l1)));
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += ((k_lambda)*(k_lambda))*(6*((P)*(P))*((k_lambda)*(k_lambda))*((l2)*(l2)) - 12*P*P_r*((k_lambda)*(k_lambda))*((l2)*(l2)) - 8*P*k_lambda*l1*l2 + 6*((P_r)*(P_r))*((k_lambda)*(k_lambda))*((l2)*(l2)) + 8*P_r*k_lambda*l1*l2 + 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_Pr + k_lambda*(P - P_r)) - 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) + 2*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) - 4*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)) + 2*((l1)*(l1)) + ((l2)*(l2))*((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + ((l2)*(l2))*((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 2*l2*(T_lambda_ref + k_lambda*(P - P_r))*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(6*P*k_lambda*((l2)*(l2)) - 6*P_r*k_lambda*((l2)*(l2)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 4*l1*l2 - ((l2)*(l2))*(T_lambda_Pr + k_lambda*(P - P_r)) + l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r))) - (-T + T_lambda_Pr + k_lambda*(P - P_r))*(-18*P*k_lambda*((l2)*(l2)) + 18*P_r*k_lambda*((l2)*(l2)) + 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_Pr + k_lambda*(P - P_r)) - 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_ref + k_lambda*(P - P_r)) + 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) - 8*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - 3*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 12*l1*l2 + 2*((l2)*(l2))*(T_lambda_ref + k_lambda*(P - P_r)) - 4*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_Pr + k_lambda*(P - P_r)) + 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(k_lambda*((l2)*(l2))*(P - P_r)/(T_lambda_Pr + k_lambda*(P - P_r)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - ((l2)*(l2)) - 2*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))) - 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) + 4*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r))) - 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_Pr + k_lambda*(P - P_r)) + 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))*log(T_lambda_ref + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += 2*H_t*((k_lambda)*(k_lambda))*(-1 + (-T + T_lambda_Pr + k_lambda*(P - P_r))/(T_lambda_Pr + k_lambda*(P - P_r)))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += 2*H_t*((k_lambda)*(k_lambda))*(-1 + (-T + T_lambda_Pr + k_lambda*(P - P_r))/(T_lambda_Pr + k_lambda*(P - P_r)))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    return result;
}

static double dewminerals_d3gdt3(double T, double P) {
    double result = 0.0;
    result += -1.0/4.0*T*(8*k0/((T)*(T)*(T)) + 24*k6/((T)*(T)*(T)*(T)) + 48*k2/pow(T, 5) + 80*k3/pow(T, 6) + 15*k1/pow(T, 7.0/2.0)) + 3*k0/((T)*(T)) + 8*k6/((T)*(T)*(T)) + 15*k2/((T)*(T)*(T)*(T)) + 24*k3/pow(T, 5) + (21.0/4.0)*k1/pow(T, 5.0/2.0);
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += 3*P*k_lambda*((l2)*(l2)) - 3*P_r*k_lambda*((l2)*(l2)) - 2*T*(((l2)*(l2)) - k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T)*(T)*(T))) - 2*l1*l2 - 3*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T)*(T));
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += -1.0/4.0*T*(8*d0/((T)*(T)*(T)) + 48*d2/pow(T, 5) + 15*d1/pow(T, 7.0/2.0)) - d4 + (1.0/4.0)*(P - P_r)*(8*d4 + 24*d2/((T)*(T)*(T)*(T)) + 3*d1/pow(T, 5.0/2.0))/d5 + 3*d0/((T)*(T)) + 15*d2/((T)*(T)*(T)*(T)) + (21.0/4.0)*d1/pow(T, 5.0/2.0);
        }
    }
    return result;
}

static double dewminerals_d3gdt2dp(double T, double P) {
    double result = 0.0;
    result += 2*V_TrPr*v4;
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += k_lambda*(-6*P*k_lambda*((l2)*(l2)) + 6*P_r*k_lambda*((l2)*(l2)) + T*(3*((l2)*(l2)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T)*(T)) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T)*(T))) + 4*l1*l2 - 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/T + 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/T);
        }
    }
    if(((d0) != 0.0) || ((d1) != 0.0) || ((d2) != 0.0) || ((d3) != 0.0) || ((d4) != 0.0) || ((d5) != 0.0) || ((T_D) != 0.0) || ((T_D_ref) != 0.0)) {
        if((T > (T_D_ref)) && (T <= (T_D))) {
             result += (2*T*d4 + d3 - 2*d2/((T)*(T)*(T)) - 1.0/2.0*d1/pow(T, 3.0/2.0))/d5;
        }
    }
    return result;
}

static double dewminerals_d3gdtdp2(double T, double P) {
    double result = 0.0;
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += ((k_lambda)*(k_lambda))*(-6*P*k_lambda*((l2)*(l2)) + 6*P_r*k_lambda*((l2)*(l2)) - 2*T*l2*(3*l2 - k_lambda*l2*(P - P_r)/T + 2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/T) + 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T) - 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_ref + k_lambda*(P - P_r)) + 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 4*l1*l2 + 2*((l2)*(l2))*(T_lambda_ref + k_lambda*(P - P_r)) - 3*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T) + 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) - 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)));
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += ((k_lambda)*(k_lambda))*(-18*P*k_lambda*((l2)*(l2)) + 18*P_r*k_lambda*((l2)*(l2)) + 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_Pr + k_lambda*(P - P_r)) - 2*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_ref + k_lambda*(P - P_r)) + 4*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) - 8*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - 3*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 12*l1*l2 + 2*((l2)*(l2))*(T_lambda_ref + k_lambda*(P - P_r)) - 4*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) - 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_Pr + k_lambda*(P - P_r)) + 4*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) + 2*(T_lambda_Pr + k_lambda*(P - P_r))*(k_lambda*((l2)*(l2))*(P - P_r)/(T_lambda_Pr + k_lambda*(P - P_r)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - ((l2)*(l2)) - 2*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))) - 2*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) + 4*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -2*H_t*((k_lambda)*(k_lambda))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += -2*H_t*((k_lambda)*(k_lambda))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    return result;
}

static double dewminerals_d3gdp3(double T, double P) {
    double result = 0.0;
    result += 2*V_TrPr*v2;
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_ref + k_lambda*(P - P_r))) && (P > (P_r)) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += ((k_lambda)*(k_lambda)*(k_lambda))*(-6*T*((l2)*(l2)) - T*(6*k_lambda*((l2)*(l2))*(P - P_r)/(T_lambda_ref + k_lambda*(P - P_r)) + 6*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 2*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - 6*((l2)*(l2))*log(T) + 6*((l2)*(l2))*log(T_lambda_ref + k_lambda*(P - P_r)) - 11*((l2)*(l2)) - 12*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) - 3*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r)))) - 2*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1));
        }
    }
    if(((l1) != 0.0) || ((l2) != 0.0) || ((k_lambda) != 0.0) || ((T_lambda_Pr) != 0.0) || ((T_lambda_ref) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += ((k_lambda)*(k_lambda)*(k_lambda))*(54*P*k_lambda*((l2)*(l2)) - 54*P_r*k_lambda*((l2)*(l2)) - 6*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_Pr + k_lambda*(P - P_r)) + 6*k_lambda*((l2)*(l2))*(P - P_r)*log(T_lambda_ref + k_lambda*(P - P_r)) - 12*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) + 24*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) - 3*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 9*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 36*l1*l2 - 6*((l2)*(l2))*(T_lambda_ref + k_lambda*(P - P_r)) + 12*l2*(-3*P*k_lambda*l2 + 3*P_r*k_lambda*l2 + 2*l1) + 12*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_Pr + k_lambda*(P - P_r)) - 12*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*log(T_lambda_ref + k_lambda*(P - P_r)) - 6*(T_lambda_Pr + k_lambda*(P - P_r))*(k_lambda*((l2)*(l2))*(P - P_r)/(T_lambda_Pr + k_lambda*(P - P_r)) + 2*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - ((l2)*(l2)) - 2*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) - ((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))) + (-T + T_lambda_Pr + k_lambda*(P - P_r))*(6*k_lambda*((l2)*(l2))*(P - P_r)/(T_lambda_ref + k_lambda*(P - P_r)) - 6*k_lambda*((l2)*(l2))*(P - P_r)/(T_lambda_Pr + k_lambda*(P - P_r)) + 6*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - 6*k_lambda*l2*(P - P_r)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) + 2*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) - 2*k_lambda*(P - P_r)*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))) - 6*((l2)*(l2))*log(T_lambda_Pr + k_lambda*(P - P_r)) + 6*((l2)*(l2))*log(T_lambda_ref + k_lambda*(P - P_r)) - 12*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_ref + k_lambda*(P - P_r)) + 12*l2*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)/(T_lambda_Pr + k_lambda*(P - P_r)) - 3*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_ref + k_lambda*(P - P_r))*(T_lambda_ref + k_lambda*(P - P_r))) + 3*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)))) + 6*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_ref + k_lambda*(P - P_r)) - 12*((-P*k_lambda*l2 + P_r*k_lambda*l2 + l1)*(-P*k_lambda*l2 + P_r*k_lambda*l2 + l1))/(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r))) && (T <= (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += 6*H_t*((k_lambda)*(k_lambda)*(k_lambda))*(1 - (-T + T_lambda_Pr + k_lambda*(P - P_r))/(T_lambda_Pr + k_lambda*(P - P_r)))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    if(((H_t) != 0.0)) {
        if((T > (T_lambda_Pr + k_lambda*(P - P_r)))) {
             result += 6*H_t*((k_lambda)*(k_lambda)*(k_lambda))*(1 - (-T + T_lambda_Pr + k_lambda*(P - P_r))/(T_lambda_Pr + k_lambda*(P - P_r)))/((T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r))*(T_lambda_Pr + k_lambda*(P - P_r)));
        }
    }
    return result;
}


static double dewminerals_s(double T, double P) {
    double result = -dewminerals_dgdt(T, P);
    return result;
}

static double dewminerals_v(double T, double P) {
    double result = dewminerals_dgdp(T, P);
    return result;
}

static double dewminerals_cv(double T, double P) {
    double result = -T*dewminerals_d2gdt2(T, P);
    double dvdt = dewminerals_d2gdtdp(T, P);
    double dvdp = dewminerals_d2gdp2(T, P);
    result += T*dvdt*dvdt/dvdp;
    return result;
}

static double dewminerals_cp(double T, double P) {
    double result = -T*dewminerals_d2gdt2(T, P);
    return result;
}

static double dewminerals_dcpdt(double T, double P) {
    double result = -T*dewminerals_d3gdt3(T, P) - dewminerals_d2gdt2(T, P);
    return result;
}

static double dewminerals_alpha(double T, double P) {
    double result = dewminerals_d2gdtdp(T, P)/dewminerals_dgdp(T, P);
    return result;
}

static double dewminerals_beta(double T, double P) {
    double result = -dewminerals_d2gdp2(T, P)/dewminerals_dgdp(T, P);
    return result;
}

static double dewminerals_K(double T, double P) {
    double result = -dewminerals_dgdp(T, P)/dewminerals_d2gdp2(T, P);
    return result;
}

static double dewminerals_Kp(double T, double P) {
    double result = dewminerals_dgdp(T, P);
    result *= dewminerals_d3gdp3(T, P);
    result /= pow(dewminerals_d2gdp2(T, P), 2.0);
    return result - 1.0;
}


const char *ALMANDINE_dewminerals_identifier(void) {
    return identifier;
}

const char *ALMANDINE_dewminerals_name(void) {
    return "ALMANDINE";
}

const char *ALMANDINE_dewminerals_formula(void) {
    return "SiFe1.001Al0.666O4";
}

const double ALMANDINE_dewminerals_mw(void) {
    return 165.95565263999998;
}

static const double elmformula[106] = {
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,4.0,0.0,0.0,0.0,
        0.0,0.666,1.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,1.001,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0
    };

const double *ALMANDINE_dewminerals_elements(void) {
    return elmformula;
}

double ALMANDINE_dewminerals_g(double T, double P) {
    return dewminerals_g(T, P);
}

double ALMANDINE_dewminerals_dgdt(double T, double P) {
    return dewminerals_dgdt(T, P);
}

double ALMANDINE_dewminerals_dgdp(double T, double P) {
    return dewminerals_dgdp(T, P);
}

double ALMANDINE_dewminerals_d2gdt2(double T, double P) {
    return dewminerals_d2gdt2(T, P);
}

double ALMANDINE_dewminerals_d2gdtdp(double T, double P) {
    return dewminerals_d2gdtdp(T, P);
}

double ALMANDINE_dewminerals_d2gdp2(double T, double P) {
    return dewminerals_d2gdp2(T, P);
}

double ALMANDINE_dewminerals_d3gdt3(double T, double P) {
    return dewminerals_d3gdt3(T, P);
}

double ALMANDINE_dewminerals_d3gdt2dp(double T, double P) {
    return dewminerals_d3gdt2dp(T, P);
}

double ALMANDINE_dewminerals_d3gdtdp2(double T, double P) {
    return dewminerals_d3gdtdp2(T, P);
}

double ALMANDINE_dewminerals_d3gdp3(double T, double P) {
    return dewminerals_d3gdp3(T, P);
}

double ALMANDINE_dewminerals_s(double T, double P) {
    return dewminerals_s(T, P);
}

double ALMANDINE_dewminerals_v(double T, double P) {
    return dewminerals_v(T, P);
}

double ALMANDINE_dewminerals_cv(double T, double P) {
    return dewminerals_cv(T, P);
}

double ALMANDINE_dewminerals_cp(double T, double P) {
    return dewminerals_cp(T, P);
}

double ALMANDINE_dewminerals_dcpdt(double T, double P) {
    return dewminerals_dcpdt(T, P);
}

double ALMANDINE_dewminerals_alpha(double T, double P) {
    return dewminerals_alpha(T, P);
}

double ALMANDINE_dewminerals_beta(double T, double P) {
    return dewminerals_beta(T, P);
}

double ALMANDINE_dewminerals_K(double T, double P) {
    return dewminerals_K(T, P);
}

double ALMANDINE_dewminerals_Kp(double T, double P) {
    return dewminerals_Kp(T, P);
}

