cdef extern from "eqlibr136.c":
    int test_(int testint)
    int test_array_pass_(double *testarray, int arraylen)
    int bdmlx_(int *nst)
    int bdslx_(int *nst)
    int arrset_(double *ars, double *amn, double *ags, double *cess, double *cdrs, 
                double *cdrm, double	*cdrg, double *csts, double *cstor, double *xbarlg, 
	            double *lamlg, double *aa, double *gm, double *csp, double *concbs, 
                double *cte, double *mte, double *zvclg1, double *cxistq, double *conc, 
                double *conclg, double *act, double *actlg, double *glg, double *glgx,
	            double *xlks, double *xlkm, double *xlkg, double *mwtss, double *z__, 
                double *zsq2, double *titr, double *azero, double *hydn, double *rhs, 
                double *ee, double *res, double *al10, double *rconst, double *xlkeh, 
                double *ehfac, double *om, double *omlg, double *omi, double *tempc, 
                double *tempk, double *press, double *xi, double *xisteq, double *fo2lg, 
	            double *eh, double *dshm, double *shm, double *shmlim,
	            char *uzvec1, char *uspec, char *umin, char *ugas, char *ujtype, 
	            int *nend, int *jflag, int *nsp, int *nspec, int *jsflag, int *jsort, 
                int *iindx1, int *ibswx, int *ibasis, int *ir, int *kill, int *iopt1, 
                int *iopt2, int *iopg1, int *iodb1, int *iodb2, int *ntpr, int *iacion, 
                int *iebal, int *nhydr, int *nchlor, int *nct, int *nsb, int *nsb1, int *nsq, 
                int *nsqb, int *nsq1, int *nst, int *nrst, int *nmt, int *ngt, int *nxt, 
                int *kct, int *ksb, int *ksq, int *kebal, int *kdim, int *kmax, int *khydr, 
                int *nctmax, int *nsqmax, int *nsqmx1, int *nstmax, int *iktmax, int *narxmx, 
                int *ntprmx, int *ker, int *nloop, int *noutpt, int *nttyo, long int *qhydth, 
                long int *qpt4, long int *qbswx, long int *qbassw, long int uzvec1_len, 
                long int uspec_len, long int umin_len, long int ugas_len, long int ujtype_len)
    int evdatc_(double *prop, double *arr, double *tempc, int *ntpr, int *narxmx, int *ntprmx)


def cy_test(int testint):
    result = test_(<int> testint)
    return result

def cy_test_array_pass(testarray):
    cdef double[::1] arr_memview = testarray
    result = test_array_pass_(&arr_memview[0], arr_memview.shape[0])
    return result

def cy_evdatc(double prop, arr, double tempc, int ntpr, int narxmx, int ntprmx):
    cdef double[::1] arr_memview = arr
    result = evdatc_(&prop, &arr_memview[0], &tempc, &ntpr, &narxmx, &ntprmx)
    return prop

def cy_bdmlx(int nst):
    result = bdmlx_(&nst)
    return result

def cy_bdslx(int nst):
    result = bdslx_(&nst)
    return result


# These are the original fortran shapes- they are 1D in the c implementation
#
# ars : narxpa x ntprpa x nrstpa
#          5   x    2   x  679
# polynomial coeffs for aqueous species [logK, 0, 0, 0, 0] for constant value
#
# amn : narxpa x ntprpa x nmtpar
#          5   x    2   x  750
# polynomial coeffs for minerals [logK, 0, 0, 0, 0] for constant value
#
# amn : narxpa x ntprpa x ngtpar
#          5   x    2   x   15
# polynomial coeffs for gases [logK, 0, 0, 0, 0] for constant value
#
# cess : nctpar x nstpar
#          70      750
# elemental composition (70 els) of the aqueous species (750 species)
#
# cdrs : nsqpa1 x nrstpa
#          101  x   679
# reaction coefficients for each aqueous species reaction (basis species x reactions)
#
# cdrm : nsqpa1 x nmtpar
#          101  x   750
# reaction coefficients for each mineral reaction (basis species x reactions)
#
# cdrg : nsqpa1 x ngtpar
#          101  x   15
# reaction coefficients for each gas reaction (basis species x reactions)
#
# cstor : 2 x nstpar
#         2     750
# Stoichiometric factors for H and O. Look in the EQ3 code for exactly how it is set up



# csts : nsqpa1 x nstpar
#          101  x  750
# I think this is calculated in arrset. 

def cy_arrset(ars, amn, ags, cess, cdrs, 
              cdrm, cdrg, double cstor, double xbarlg, 
	          double lamlg, double aa, double gm, double csp, double concbs, 
              double cte, double mte, double zvclg1, double cxistq, double conc, 
              double conclg, double act, double actlg, double glg, double glgx,
	          double xlks, double xlkm, double xlkg, double mwtss, double z__, 
              double zsq2, double titr, double azero, double hydn, double rhs, 
              double ee, double res, double al10, double rconst, double xlkeh, 
              double ehfac, double om, double omlg, double omi, double tempc, 
              double tempk, double press, double xi, double xisteq, double fo2lg, 
	          double eh, double dshm, double shm, double shmlim,
	          char uzvec1, char uspec, char umin, char ugas, char ujtype, 
	          int nend, int jflag, int nsp, int nspec, int jsflag, int jsort, 
              int iindx1, int ibswx, int ibasis, int ir, int kill, int iopt1, 
              int iopt2, int iopg1, int iodb1, int iodb2, int ntpr, int iacion, 
              int iebal, int nhydr, int nchlor, int nct, int nsb, int nsb1, int nsq, 
              int nsqb, int nsq1, int nst, int nrst, int nmt, int ngt, int nxt, 
              int kct, int ksb, int ksq, int kebal, int kdim, int kmax, int khydr, 
              int nctmax, int nsqmax, int nsqmx1, int nstmax, int iktmax, int narxmx, 
              int ntprmx, int ker, int nloop, int noutpt, int nttyo, long int qhydth, 
              long int qpt4, long int qbswx, long int qbassw, long int uzvec1_len, 
              long int uspec_len, long int umin_len, long int ugas_len, long int ujtype_len):
              
              # Input parameters
              cdef double[::1] ars_memview = ars
              cdef double[::1] amn_memview = amn
              cdef double[::1] ags_memview = ags
              cdef double[::1] cess_memview = cess
              cdef double[::1] cdrs_memview = cdrs
              cdef double[::1] cdrm_memview = cdrm
              cdef double[::1] cdrg_memview = cdrg

              # Outputs to be filled in
              cdef double[75000] csts
              cdef double[::1] csts_memview = csts

              result = arrset_(&ars_memview[0], &amn_memview[0], &ags_memview[0], 
                               &cess_memview[0], &cdrs_memview[0], 
                               &cdrm_memview[0], &cdrg_memview[0], 
                               &csts_memview[0], &cstor, &xbarlg, 
                               &lamlg, &aa, &gm, &csp, &concbs, 
                               &cte, &mte, &zvclg1, &cxistq, &conc, 
                               &conclg, &act, &actlg, &glg, &glgx,
                               &xlks, &xlkm, &xlkg, &mwtss, &z__, 
                               &zsq2, &titr, &azero, &hydn, &rhs, 
                               &ee, &res, &al10, &rconst, &xlkeh, 
                               &ehfac, &om, &omlg, &omi, &tempc, 
                               &tempk, &press, &xi, &xisteq, &fo2lg, 
                               &eh, &dshm, &shm, &shmlim,
                               &uzvec1, &uspec, &umin, &ugas, &ujtype, 
                               &nend, &jflag, &nsp, &nspec, &jsflag, &jsort, 
                               &iindx1, &ibswx, &ibasis, &ir, &kill, &iopt1, 
                               &iopt2, &iopg1, &iodb1, &iodb2, &ntpr, &iacion, 
                               &iebal, &nhydr, &nchlor, &nct, &nsb, &nsb1, &nsq, 
                               &nsqb, &nsq1, &nst, &nrst, &nmt, &ngt, &nxt, 
                               &kct, &ksb, &ksq, &kebal, &kdim, &kmax, &khydr, 
                               &nctmax, &nsqmax, &nsqmx1, &nstmax, &iktmax, &narxmx, 
                               &ntprmx, &ker, &nloop, &noutpt, &nttyo, &qhydth, 
                               &qpt4, &qbswx, &qbassw, <long int> uzvec1_len, 
                               <long int> uspec_len, <long int> umin_len, <long int> ugas_len, <long int> ujtype_len)
            
              return result










