
static const char *identifier = "Thu May  6 14:22:44 2021";

static const double T_r = 298.15;
static const double P_r = 1.0;
static const double G_ref = -427395.60000000003;
static const double S_ref = 246.85600000000002;
static const double a1 = 5.155412693904;
static const double a2 = 3116.400095816;
static const double a3 = -5.888105933112001;
static const double a4 = -129156.55799248;
static const double c1 = 24.732066817824002;
static const double c2 = -229237.29616448004;
static const double Psi = 2600.0;
static const double eta = 694657.0;
static const double rH = 3.082;
static const double omega0 = 307775.04000000004;
static const double theta = 228.0;
static const double z = -1;

#include <math.h>

double born_B(double t, double p);
double born_Q(double t, double p);
double born_N(double t, double p);
double born_U(double t, double p);
double born_Y(double t, double p);
double born_X(double t, double p);
double born_dUdT(double t, double p);
double born_dUdP(double t, double p);
double born_dNdT(double t, double p);
double born_dNdP(double t, double p);
double born_dXdT(double t, double p);
double gSolvent(double t, double p);
double DgSolventDt(double t, double p);
double DgSolventDp(double t, double p);
double D2gSolventDt2(double t, double p);
double D2gSolventDtDp(double t, double p);
double D2gSolventDp2(double t, double p);
double D3gSolventDt3(double t, double p);
double D3gSolventDt2Dp(double t, double p);
double D3gSolventDtDp2(double t, double p);
double D3gSolventDp3(double t, double p);
double D4gSolventDt4(double t, double p);

static double dew2019_g(double T, double P) {
    double result = 0.0;
    result += G_ref + P*(T*a1 - a1*theta + a3)/(T - theta) - P_r*(T*a1 - a1*theta + a3)/(T - theta) - S_ref*(T - T_r) + T*c2*log(T + (-c1*((theta)*(theta)*(theta)) - 2*c2*theta)/(c1*((theta)*(theta)) + 2*c2))/((theta)*(theta)) - T*(-T_r*c1*((theta)*(theta))*log(T_r) - T_r*c1*((theta)*(theta)) - T_r*c2*log(T_r) + T_r*c2*log(T_r - c1*((theta)*(theta)*(theta))/(c1*((theta)*(theta)) + 2*c2) - 2*c2*theta/(c1*((theta)*(theta)) + 2*c2)) + c1*((theta)*(theta)*(theta))*log(T_r) + c1*((theta)*(theta)*(theta)) + c2*theta*log(T_r) - c2*theta*log(T_r - c1*((theta)*(theta)*(theta))/(c1*((theta)*(theta)) + 2*c2) - 2*c2*theta/(c1*((theta)*(theta)) + 2*c2)) + c2*theta)/(T_r*((theta)*(theta)) - ((theta)*(theta)*(theta))) - T_r*c2*log(T_r + (-c1*((theta)*(theta)*(theta)) - 2*c2*theta)/(c1*((theta)*(theta)) + 2*c2))/((theta)*(theta)) + T_r*(-T_r*c1*((theta)*(theta))*log(T_r) - T_r*c1*((theta)*(theta)) - T_r*c2*log(T_r) + T_r*c2*log(T_r - c1*((theta)*(theta)*(theta))/(c1*((theta)*(theta)) + 2*c2) - 2*c2*theta/(c1*((theta)*(theta)) + 2*c2)) + c1*((theta)*(theta)*(theta))*log(T_r) + c1*((theta)*(theta)*(theta)) + c2*theta*log(T_r) - c2*theta*log(T_r - c1*((theta)*(theta)*(theta))/(c1*((theta)*(theta)) + 2*c2) - 2*c2*theta/(c1*((theta)*(theta)) + 2*c2)) + c2*theta)/(T_r*((theta)*(theta)) - ((theta)*(theta)*(theta))) - 5.7986499999999998e-5*omega0*(T - T_r) + 0.9872562762839302*omega0 - (born_B(T, P) + 1)*((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
)) + (T*a2 - a2*theta + a4)*log(P + Psi)/(T - theta) - (T*a2 - a2*theta + a4)*log(P_r + Psi)/(T - theta) - (T*c1*((theta)*(theta)) + T*c2)*log(T + (-c1*((theta)*(theta)*(theta)) - c2*theta + theta*(c1*((theta)*(theta)) + c2))/(c1*((theta)*(theta)) + 2*c2))/((theta)*(theta)) + (T_r*c1*((theta)*(theta)) + T_r*c2)*log(T_r + (-c1*((theta)*(theta)*(theta)) - c2*theta + theta*(c1*((theta)*(theta)) + c2))/(c1*((theta)*(theta)) + 2*c2))/((theta)*(theta));
    return result;
}

static double dew2019_dgdt(double T, double P) {
    double result = 0.0;
    result += P*a1/(T - theta) - P*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)) - P_r*a1/(T - theta) + P_r*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)) - S_ref + T*c2/(((theta)*(theta))*(T + (-c1*((theta)*(theta)*(theta)) - 2*c2*theta)/(c1*((theta)*(theta)) + 2*c2))) + a2*log(P + Psi)/(T - theta) - a2*log(P_r + Psi)/(T - theta) + c2*log(T + (-c1*((theta)*(theta)*(theta)) - 2*c2*theta)/(c1*((theta)*(theta)) + 2*c2))/((theta)*(theta)) - 5.7986499999999998e-5*omega0 + (-born_B(T, P) - 1)*((z == 0) ? (
   0
)
: (
   eta*z*DgSolventDt(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*DgSolventDt(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_Y(T, P) - (-T_r*c1*((theta)*(theta))*log(T_r) - T_r*c1*((theta)*(theta)) - T_r*c2*log(T_r) + T_r*c2*log(T_r - c1*((theta)*(theta)*(theta))/(c1*((theta)*(theta)) + 2*c2) - 2*c2*theta/(c1*((theta)*(theta)) + 2*c2)) + c1*((theta)*(theta)*(theta))*log(T_r) + c1*((theta)*(theta)*(theta)) + c2*theta*log(T_r) - c2*theta*log(T_r - c1*((theta)*(theta)*(theta))/(c1*((theta)*(theta)) + 2*c2) - 2*c2*theta/(c1*((theta)*(theta)) + 2*c2)) + c2*theta)/(T_r*((theta)*(theta)) - ((theta)*(theta)*(theta))) - (T*a2 - a2*theta + a4)*log(P + Psi)/((T - theta)*(T - theta)) + (T*a2 - a2*theta + a4)*log(P_r + Psi)/((T - theta)*(T - theta)) - (c1*((theta)*(theta)) + c2)*log(T + (-c1*((theta)*(theta)*(theta)) - c2*theta + theta*(c1*((theta)*(theta)) + c2))/(c1*((theta)*(theta)) + 2*c2))/((theta)*(theta)) - (T*c1*((theta)*(theta)) + T*c2)/(((theta)*(theta))*(T + (-c1*((theta)*(theta)*(theta)) - c2*theta + theta*(c1*((theta)*(theta)) + c2))/(c1*((theta)*(theta)) + 2*c2)));
    return result;
}

static double dew2019_dgdp(double T, double P) {
    double result = 0.0;
    result += (-born_B(T, P) - 1)*((z == 0) ? (
   0
)
: (
   eta*z*DgSolventDp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*DgSolventDp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_Q(T, P) + (T*a1 - a1*theta + a3)/(T - theta) + (T*a2 - a2*theta + a4)/((P + Psi)*(T - theta));
    return result;
}

static double dew2019_d2gdt2(double T, double P) {
    double result = 0.0;
    result += -2*P*a1/((T - theta)*(T - theta)) + 2*P*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)*(T - theta)) + 2*P_r*a1/((T - theta)*(T - theta)) - 2*P_r*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)*(T - theta)) - T*c2/(((theta)*(theta))*((T - theta)*(T - theta))) - 2*a2*log(P + Psi)/((T - theta)*(T - theta)) + 2*a2*log(P_r + Psi)/((T - theta)*(T - theta)) + 2*c2/(((theta)*(theta))*(T - theta)) - (born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDt2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDt2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - 2*((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDt(T, P)
))*born_Y(T, P) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_X(T, P) + 2*(T*a2 - a2*theta + a4)*log(P + Psi)/((T - theta)*(T - theta)*(T - theta)) - 2*(T*a2 - a2*theta + a4)*log(P_r + Psi)/((T - theta)*(T - theta)*(T - theta)) - (c1*((theta)*(theta)) + c2)/(T*((theta)*(theta)));
    return result;
}

static double dew2019_d2gdtdp(double T, double P) {
    double result = 0.0;
    result += a1/(T - theta) + a2/((P + Psi)*(T - theta)) - (born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDtDp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*DgSolventDp(T, P)*DgSolventDt(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDtDp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDp(T, P)*DgSolventDt(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - ((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDp(T, P)
))*born_Y(T, P) - ((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDt(T, P)
))*born_Q(T, P) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_U(T, P) - (T*a1 - a1*theta + a3)/((T - theta)*(T - theta)) - (T*a2 - a2*theta + a4)/((P + Psi)*((T - theta)*(T - theta)));
    return result;
}

static double dew2019_d2gdp2(double T, double P) {
    double result = 0.0;
    result += -((born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDp2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*((DgSolventDp(T, P))*(DgSolventDp(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDp2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*((DgSolventDp(T, P))*(DgSolventDp(T, P)))/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) + 2*((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDp(T, P)
))*born_Q(T, P) + ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_N(T, P) + (T*a2 - a2*theta + a4)/(((P + Psi)*(P + Psi))*(T - theta)));
    return result;
}

static double dew2019_d3gdt3(double T, double P) {
    double result = 0.0;
    result += 6*P*a1/((T - theta)*(T - theta)*(T - theta)) - 6*P*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)*(T - theta)*(T - theta)) - 6*P_r*a1/((T - theta)*(T - theta)*(T - theta)) + 6*P_r*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)*(T - theta)*(T - theta)) + 2*T*c2/(((theta)*(theta))*((T - theta)*(T - theta)*(T - theta))) + 6*a2*log(P + Psi)/((T - theta)*(T - theta)*(T - theta)) - 6*a2*log(P_r + Psi)/((T - theta)*(T - theta)*(T - theta)) - 3*c2/(((theta)*(theta))*((T - theta)*(T - theta))) - (born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D3gSolventDt3(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 6*eta*z*DgSolventDt(T, P)*D2gSolventDt2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) + 6*eta*z*((DgSolventDt(T, P))*(DgSolventDt(T, P))*(DgSolventDt(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D3gSolventDt3(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 6*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDt(T, P)*D2gSolventDt2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) - 6*((z/rH + omega0/eta)*(z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*fabs(z)*((DgSolventDt(T, P))*(DgSolventDt(T, P))*(DgSolventDt(T, P)))/(((z)*(z)*(z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - 3*((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDt(T, P)
))*born_X(T, P) - 3*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDt2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDt2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
))*born_Y(T, P) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_dXdT(T, P) - 6*(T*a2 - a2*theta + a4)*log(P + Psi)/((T - theta)*(T - theta)*(T - theta)*(T - theta)) + 6*(T*a2 - a2*theta + a4)*log(P_r + Psi)/((T - theta)*(T - theta)*(T - theta)*(T - theta)) + (c1*((theta)*(theta)) + c2)/(((T)*(T))*((theta)*(theta)));
    return result;
}

static double dew2019_d3gdt2dp(double T, double P) {
    double result = 0.0;
    result += -2*a1/((T - theta)*(T - theta)) - 2*a2/((P + Psi)*((T - theta)*(T - theta))) - (born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D3gSolventDt2Dp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*DgSolventDp(T, P)*D2gSolventDt2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 4*eta*z*DgSolventDt(T, P)*D2gSolventDtDp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) + 6*eta*z*DgSolventDp(T, P)*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D3gSolventDt2Dp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDp(T, P)*D2gSolventDt2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 4*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDt(T, P)*D2gSolventDtDp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) - 6*((z/rH + omega0/eta)*(z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*fabs(z)*DgSolventDp(T, P)*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/(((z)*(z)*(z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - ((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDp(T, P)
))*born_X(T, P) - 2*((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDt(T, P)
))*born_U(T, P) - ((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDt2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDt2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*((DgSolventDt(T, P))*(DgSolventDt(T, P)))/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
))*born_Q(T, P) - 2*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDtDp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*DgSolventDp(T, P)*DgSolventDt(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDtDp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDp(T, P)*DgSolventDt(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
))*born_Y(T, P) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_dUdT(T, P) + 2*(T*a1 - a1*theta + a3)/((T - theta)*(T - theta)*(T - theta)) + 2*(T*a2 - a2*theta + a4)/((P + Psi)*((T - theta)*(T - theta)*(T - theta)));
    return result;
}

static double dew2019_d3gdtdp2(double T, double P) {
    double result = 0.0;
    result += -a2/(((P + Psi)*(P + Psi))*(T - theta)) - (born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D3gSolventDtDp2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 4*eta*z*DgSolventDp(T, P)*D2gSolventDtDp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*D2gSolventDp2(T, P)*DgSolventDt(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) + 6*eta*z*((DgSolventDp(T, P))*(DgSolventDp(T, P)))*DgSolventDt(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D3gSolventDtDp2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 4*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDp(T, P)*D2gSolventDtDp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*D2gSolventDp2(T, P)*DgSolventDt(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) - 6*((z/rH + omega0/eta)*(z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*fabs(z)*((DgSolventDp(T, P))*(DgSolventDp(T, P)))*DgSolventDt(T, P)/(((z)*(z)*(z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - 2*((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDp(T, P)
))*born_U(T, P) - ((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDt(T, P)
))*born_N(T, P) - ((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDp2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*((DgSolventDp(T, P))*(DgSolventDp(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDp2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*((DgSolventDp(T, P))*(DgSolventDp(T, P)))/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
))*born_Y(T, P) - 2*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDtDp(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*DgSolventDp(T, P)*DgSolventDt(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDtDp(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDp(T, P)*DgSolventDt(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
))*born_Q(T, P) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_dNdT(T, P) + (T*a2 - a2*theta + a4)/(((P + Psi)*(P + Psi))*((T - theta)*(T - theta)));
    return result;
}

static double dew2019_d3gdp3(double T, double P) {
    double result = 0.0;
    result += -(born_B(T, P) + 1)*((z == 0) ? (
   0
)
: (
   eta*z*D3gSolventDp3(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 6*eta*z*DgSolventDp(T, P)*D2gSolventDp2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) + 6*eta*z*((DgSolventDp(T, P))*(DgSolventDp(T, P))*(DgSolventDp(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D3gSolventDp3(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 6*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*DgSolventDp(T, P)*D2gSolventDp2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) - 6*((z/rH + omega0/eta)*(z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*fabs(z)*((DgSolventDp(T, P))*(DgSolventDp(T, P))*(DgSolventDp(T, P)))/(((z)*(z)*(z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
)) - 3*((z == 0) ? (
   0
)
: (
   (eta*z/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))))*DgSolventDp(T, P)
))*born_N(T, P) - 3*((z == 0) ? (
   0
)
: (
   eta*z*D2gSolventDp2(T, P)/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - 2*eta*z*((DgSolventDp(T, P))*(DgSolventDp(T, P)))/((rH + gSolvent(T, P))*(rH + gSolvent(T, P))*(rH + gSolvent(T, P))) - (z/rH + omega0/eta)*(eta*z/rH + omega0)*fabs(z)*D2gSolventDp2(T, P)/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z))))) + 2*((z/rH + omega0/eta)*(z/rH + omega0/eta))*(eta*z/rH + omega0)*((DgSolventDp(T, P))*(DgSolventDp(T, P)))/(((z)*(z))*((1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))*(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))))
))*born_Q(T, P) - ((z == 0) ? (
   omega0
)
: (
   -eta*z/(rH + gSolvent(T, P)) + (eta*z/rH + omega0)/(1 + (z/rH + omega0/eta)*fabs(z)*gSolvent(T, P)/((z)*(z)))
))*born_dNdP(T, P) + 2*(T*a2 - a2*theta + a4)/(((P + Psi)*(P + Psi)*(P + Psi))*(T - theta));
    return result;
}


static double dew2019_s(double T, double P) {
    double result = -dew2019_dgdt(T, P);
    return result;
}

static double dew2019_v(double T, double P) {
    double result = dew2019_dgdp(T, P);
    return result;
}

static double dew2019_cv(double T, double P) {
    double result = -T*dew2019_d2gdt2(T, P);
    double dvdt = dew2019_d2gdtdp(T, P);
    double dvdp = dew2019_d2gdp2(T, P);
    result += T*dvdt*dvdt/dvdp;
    return result;
}

static double dew2019_cp(double T, double P) {
    double result = -T*dew2019_d2gdt2(T, P);
    return result;
}

static double dew2019_dcpdt(double T, double P) {
    double result = -T*dew2019_d3gdt3(T, P) - dew2019_d2gdt2(T, P);
    return result;
}

static double dew2019_alpha(double T, double P) {
    double result = dew2019_d2gdtdp(T, P)/dew2019_dgdp(T, P);
    return result;
}

static double dew2019_beta(double T, double P) {
    double result = -dew2019_d2gdp2(T, P)/dew2019_dgdp(T, P);
    return result;
}

static double dew2019_K(double T, double P) {
    double result = -dew2019_dgdp(T, P)/dew2019_d2gdp2(T, P);
    return result;
}

static double dew2019_Kp(double T, double P) {
    double result = dew2019_dgdp(T, P);
    result *= dew2019_d3gdp3(T, P);
    result /= pow(dew2019_d2gdp2(T, P), 2.0);
    return result - 1.0;
}


const char *PBCL3_n_dew2019_identifier(void) {
    return identifier;
}

const char *PBCL3_n_dew2019_name(void) {
    return "PBCL3_n";
}

const char *PBCL3_n_dew2019_formula(void) {
    return "PbCl3";
}

const double PBCL3_n_dew2019_mw(void) {
    return 313.55899999999997;
}

static const double elmformula[106] = {
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,3.0,
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
        0.0,0.0,0.0,0.0,1.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0
    };

const double *PBCL3_n_dew2019_elements(void) {
    return elmformula;
}

double PBCL3_n_dew2019_g(double T, double P) {
    return dew2019_g(T, P);
}

double PBCL3_n_dew2019_dgdt(double T, double P) {
    return dew2019_dgdt(T, P);
}

double PBCL3_n_dew2019_dgdp(double T, double P) {
    return dew2019_dgdp(T, P);
}

double PBCL3_n_dew2019_d2gdt2(double T, double P) {
    return dew2019_d2gdt2(T, P);
}

double PBCL3_n_dew2019_d2gdtdp(double T, double P) {
    return dew2019_d2gdtdp(T, P);
}

double PBCL3_n_dew2019_d2gdp2(double T, double P) {
    return dew2019_d2gdp2(T, P);
}

double PBCL3_n_dew2019_d3gdt3(double T, double P) {
    return dew2019_d3gdt3(T, P);
}

double PBCL3_n_dew2019_d3gdt2dp(double T, double P) {
    return dew2019_d3gdt2dp(T, P);
}

double PBCL3_n_dew2019_d3gdtdp2(double T, double P) {
    return dew2019_d3gdtdp2(T, P);
}

double PBCL3_n_dew2019_d3gdp3(double T, double P) {
    return dew2019_d3gdp3(T, P);
}

double PBCL3_n_dew2019_s(double T, double P) {
    return dew2019_s(T, P);
}

double PBCL3_n_dew2019_v(double T, double P) {
    return dew2019_v(T, P);
}

double PBCL3_n_dew2019_cv(double T, double P) {
    return dew2019_cv(T, P);
}

double PBCL3_n_dew2019_cp(double T, double P) {
    return dew2019_cp(T, P);
}

double PBCL3_n_dew2019_dcpdt(double T, double P) {
    return dew2019_dcpdt(T, P);
}

double PBCL3_n_dew2019_alpha(double T, double P) {
    return dew2019_alpha(T, P);
}

double PBCL3_n_dew2019_beta(double T, double P) {
    return dew2019_beta(T, P);
}

double PBCL3_n_dew2019_K(double T, double P) {
    return dew2019_K(T, P);
}

double PBCL3_n_dew2019_Kp(double T, double P) {
    return dew2019_Kp(T, P);
}

