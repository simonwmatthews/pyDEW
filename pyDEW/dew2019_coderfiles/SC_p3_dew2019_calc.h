
const char *SC_p3_dew2019_identifier(void);
const char *SC_p3_dew2019_name(void);
const char *SC_p3_dew2019_formula(void);
const double SC_p3_dew2019_mw(void);
const double *SC_p3_dew2019_elements(void);

double SC_p3_dew2019_g(double T, double P);
double SC_p3_dew2019_dgdt(double T, double P);
double SC_p3_dew2019_dgdp(double T, double P);
double SC_p3_dew2019_d2gdt2(double T, double P);
double SC_p3_dew2019_d2gdtdp(double T, double P);
double SC_p3_dew2019_d2gdp2(double T, double P);
double SC_p3_dew2019_d3gdt3(double T, double P);
double SC_p3_dew2019_d3gdt2dp(double T, double P);
double SC_p3_dew2019_d3gdtdp2(double T, double P);
double SC_p3_dew2019_d3gdp3(double T, double P);

double SC_p3_dew2019_s(double T, double P);
double SC_p3_dew2019_v(double T, double P);
double SC_p3_dew2019_cv(double T, double P);
double SC_p3_dew2019_cp(double T, double P);
double SC_p3_dew2019_dcpdt(double T, double P);
double SC_p3_dew2019_alpha(double T, double P);
double SC_p3_dew2019_beta(double T, double P);
double SC_p3_dew2019_K(double T, double P);
double SC_p3_dew2019_Kp(double T, double P);

