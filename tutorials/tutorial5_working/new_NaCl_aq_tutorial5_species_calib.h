
const char *new_NaCl_aq_tutorial5_species_calib_identifier(void);
const char *new_NaCl_aq_tutorial5_species_calib_name(void);
const char *new_NaCl_aq_tutorial5_species_calib_formula(void);
const double new_NaCl_aq_tutorial5_species_calib_mw(void);
const double *new_NaCl_aq_tutorial5_species_calib_elements(void);

double new_NaCl_aq_tutorial5_species_calib_g(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_dgdt(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_dgdp(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d2gdt2(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d2gdtdp(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d2gdp2(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d3gdt3(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d3gdt2dp(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d3gdtdp2(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_d3gdp3(double T, double P);

double new_NaCl_aq_tutorial5_species_calib_s(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_v(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_cv(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_cp(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_dcpdt(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_alpha(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_beta(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_K(double T, double P);
double new_NaCl_aq_tutorial5_species_calib_Kp(double T, double P);

int new_NaCl_aq_tutorial5_species_get_param_number(void);
const char **new_NaCl_aq_tutorial5_species_get_param_names(void);
const char **new_NaCl_aq_tutorial5_species_get_param_units(void);
void new_NaCl_aq_tutorial5_species_get_param_values(double **values);
int new_NaCl_aq_tutorial5_species_set_param_values(double *values);
double new_NaCl_aq_tutorial5_species_get_param_value(int index);
int new_NaCl_aq_tutorial5_species_set_param_value(int index, double value);

double new_NaCl_aq_tutorial5_species_dparam_g(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_dgdt(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_dgdp(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d2gdt2(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d2gdtdp(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d2gdp2(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d3gdt3(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d3gdt2dp(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d3gdtdp2(double T, double P, int index);
double new_NaCl_aq_tutorial5_species_dparam_d3gdp3(double T, double P, int index);

