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


# ars : narxpa x ntprpa x nrstpa
#          5   x    2   x  679
def cy_arrset(double ars, double amn, double ags, double cess, double cdrs, 
              double cdrm, double cdrg, double csts, double cstor, double xbarlg, 
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

              result = arrset_(&ars, &amn, &ags, &cess, &cdrs, 
                               &cdrm, &cdrg, &csts, &cstor, &xbarlg, 
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










