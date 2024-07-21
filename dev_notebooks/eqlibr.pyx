# Cython wrapper for the EQ3/6 code.
# Simon Matthews (simonm@hi.is) May 2024
# University of Iceland

# The * preceding the variable name means the function is expecting a pointer to the
# location in memory that the variable is stored. Cython has a process for handling this
# either from the definition of variables, or by conversion of e.g., numpy arrays.
# The f2c code collapses the array dimensions into one- which will require some care
# to make sure is propagated correctly into this wrapper.
# The f2c code also defines some odd variable types which are derived directly from
# normal c types. This may cause an issue, but hopefully not.

# Note that this is using a modified version of eqlibr, where I moved some functions
# in from (I think) eq3nr. I forgot that I did this when I started making the cython
# wrapper, but this could be a very useful thing anyway.

# To do:
# - Need to wrap gcsts function to calculate csts, cxistq, gntpr_

import numpy as np

cdef extern from "eqlibr136.c":
    int test_(int *testint)
    int test_array_pass_(double *testarray, int arraylen)
    int bdmlx_(int *nst)
    int bdslx_(int *nst)
    int arrset_(double *ars, double *amn, double *ags, double *cess, double *cdrs, 
                double *cdrm, double *cdrg, double *csts, double *cstor, double *xbarlg, 
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
                int *ntprmx, int *ker, int *nloop, int *noutpt, int *nttyo, bint *qhydth, 
                bint *qpt4, bint *qbswx, bint *qbassw, long int uzvec1_len, 
                long int uspec_len, long int umin_len, long int ugas_len, long int ujtype_len)
    int evdatc_(double *prop, double *arr, double *tempc, int *ntpr, int *narxmx, int *ntprmx)
    int testbool_(bint testbool)

def cy_testbool(testbool):
    result = testbool_(testbool)
    return result

def cy_test(int testint):
    print('hi')
    result = test_(&testint)
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
# csts : nsqpa1 x nstpar
#          101  x  750
# This is calculated immediately before arrset is called by gcsts
#
# cstor : 2 x nstpar
#         2     750
# Stoichiometric factors for H and O. Look in the EQ3 code for exactly how it is set up
#
# xbarlg : iktpar x nxtpar
#            20      20
# log mole fractions of solid solution endmembers (endmembers x solid solns)
#
# lamlg : iktpar x nxtpar
#            20      20
# log activity coefficients for ss endmembers (endmembers x solid solns)
#
# csp : nsqpa1
#        101
# Constraining parameter array for the aqueous species
#
# cxistq : nstpar
#           750
# Calculated from csts immediately before running arrset- see EQ3 code
#
# mwtss : nstpar
#          750
# Molecular weights of aqueous species
#
# z : nstpar
#       750
# Electrical charges on aqueous species
#
# zsq2 : nstpar
#          750
# Z^2/2, calculated in EQ3 code before running arrset
#
# titr : nstpar
#          750
# ?Alkalinity? It seems to be either 1 or 0 in old DATA0, not sure it is important.
#
# azero : nstpar
#          750
# Ion size- I think it is used as a switch in DATA0 for behaviour in modified code- should follow up on what this is
#
# hydn : nstpar
#          750
# I think this is hydration number in DATA0 which appears to always be zero.
#
# xlkeh 
# log K Eh - related to fO2 see eqn. 69 on p.32 of manual.
#
# ehfac
# Calculated by gntpr_
#
# tempc
# Temperature degC
#
# tempk
# Temperature K. Calculated in gntpr_
#
# press
# Pressure bars
#
# fo2lg
# fO2 - I think this is where you pass fO2, rather than it being a calculated variable.
#
# eh
# redox potential- I think this can be used instead of fo2lg if iopt specifies so
#
# uzvec1 : kpar
#          800
# Names of species corresponding to the master iteration variables (basis species?).
# kpar = 100, strings are 8 characters long I think- I guess it is an
# abbreviated version
#
# uspec: nstpar 750 x 24
#          18000
# Names of species 
#
# umin: nmtpar 750 x 24
#          18000
# Names of pure minerals
#
# ugas: ngtpar 15 x 24
#          360
# Names of pure gases
#
# ujtype: nsqpar 100 ?? would fit with 31 x 24 
#          744
# Character strings that describe jflag options
#
# nend: iktpar x nxtpar; 20 x 20
#          400
# Array that stores the indices of pure minerals thay correspond to end-member components
# of solid solutions.
#
# jflag: nsqpar
#         100
# jflag values
#
# nsp: nsqpar
#         100
# Indices of species that define basis species constraints. Description is a bit mysterious- maybe best to print out from a run.
#
# nspec: nsqpar
#         100
# Array that contains the indices of the basis species which appear on the input file
#
# jsflag
#         750
# Status switch array for aqueous species. 0 = species in model, 2 = thermodynamically suppressed, 3 = doesn't appear
#
# jsort
#         750
# Array of species indices in order of concentration- needs to be initialised- see EQ3 code.
#
# iindx1: kpar
#         100
# Array containing indices of basis species that correspond to master iteration variables
#
# ibswx: nsqpar
#         100
# Array that contains indices o species which are candidates for switching into the basis set. If not 0, gives index of a species to switch.
#
# iopt1, 2
# Option switch
#
# iopg1, 2
# Activity coefficient option switches
#
# iodb1, 2
# Debugging print option switches
#
# ntpr
# Index of the temperature range specified on the input file
#
# iacion
# No def in manual- probably the index of the acion
#
# iebal
# The index of the aqueous species chosen for electrical balancing
#
# nhydr
# The index of the H+ spcies
#
# nchlor
# The index of the Cl- spcies
#
# nct
# Total number of chemical elements
#
# nsb
# The number of strict basis species, also the indec denoting O2
#
# nsb1
# Index denoting the first species in the auxiliary basis set nsb + 1
#
# nsq
# Number of aqueous basis species
#
# nsqb
# Number of basis species that appear on input file
#
# nst
# Total number of aqueous species, includes all basis species but only those non-basis species appearing in the system for a given problem
#
# nrst
# Total number of reactions among aqueous species
#
# nmt
# Total number of pure minerals
#
# ngt
# Total number of gas species
#
# nxt
# Total number of solid solution phases
#
# kct
# Number of chemical elements present in the aqueous system currently modelled
#
# ksb
# Position of O2(g), ksb = kct + 1
#
# ksq
# Number of active basis species
#
# kebal
# Variable denoting the position of the species selected for electrical balancing in the set of master iteration variables
#
# kdim
# Dimension of jacobian matrix, kdim=ksq
#
# kmax
# Maximum number of master vairables readable by EQ6. Corresponds to kpar
#
# nctmax
# Maximum number of chemical elements, Corresponds to nctpar
#
# nsqmax
# Maximum number of aqueous basis species, corresponds to nsqpar.
#
# nsqmx1
# Variable equal to nsqmax + 1
#
# nstmax
# Maxmimum number of aqueous species
#
# iktmax
# Maximum number of endmembers in solid solution
#
# narxmx
# Max no. coefficients per temperature range for interpolating polynomial coefficient
#
# ntprmx
# MAx no. temperature ranges for an interpolating polynomial
#
# noutpt
# Unit number of the output file. Maybe need to just remove all refs to this from the function.
#
# nttyo
# Unit number of the screen file. Maybe need to just remove all refs to this from the function.
#
# qbswx
# logical flag indicating if there are candidates for automatic basis switching.
#
# qhydth, 
# True if activity coefficient option is using hydration theory. I think this should be true.
#
# qpt4
# True if using hkf
#
# qbass
# I think this should be false for hkf. Might be set by code.

#
# aa : kpar x kpar
#       100 x 100
# The Jacobian matrix
#
# gm : kpar x kpar
#       100 x 100
# A work array used to store a copy of aa
#
# concbs : 
#           100 
# master species total concentrations defined in EQ3 master
#
# cte : 
#           100 
# equivalent total molality of an element (basis species)
#
# mte : 
#           100 
# total molalities of dissolved elements (elements)
#
# zvclg1 :  kpar
#           100 
# Array of logarithmic master variables
#
# conc : nstpar
#          750
# Concentrations of aqueous species (molal)
#
# conclg : nstpar
#          750
# Log concentrations of aqueous species (molal)
#
# act : nstpar
#          750
# Activity of the aqueous species
#
# actlg : nstpar
#          750
# Logarithmic activity of the aqueous species
#
# glg : nstpar
#          750
# Array of log activity coefficients for each aqueous species
#
# glgx : nstpar
#          750
# Not explained anywhere, presumably just used to hold values during computations. Instantiated, in EQ3
# but then not referenced again until calling arrset.
#
# xlks : nrstpa
#         679
# Log equilibrium constants for dissociation/destruction reactions of aqueous species
#
# xlkm : nmtpar
#         750
# Log equilibrium constants for pure minerals
#
# xlkg : ngtpar
#          15
# Log equilibrium constants for gases
#
# rhs : kpar
#        100
# I think this is used as a storage variable in the calculations.
#
# ee : kpar
#        100
# A work array
#
# res : kpar
#        100
# A work array
#
# xi
# The ionic strength- presumably it is calculated.
#
# xisteq
# Related to the ionic strength- calculated in the code.
#
# dshm
# Calculated in the code.
#
# shm
# Calculated in the code.
#
# ibasis : nstpar
#           750
# Records basis switching- initialized as all zeros I think.
#
# ir : kpar
#       100
# Work array
#
# kill : 
#       100
# Unclear, but I think its a work array
#
# nsq1
# Unclear, but I think its a work integer
#
# khydr
# Variable denoting position of H+ in the set of master iteration variables. I think this is set in the routine.
#
# ker
# Internal integer- I think to do with reporting whether the routines worked well or not
#
# nloop
# Loop counter for basis switching



# al10
# log(10)
# Might be calculated in the code?
# shmlim
# om - 1
# Might be calculated in the code?

def cy_arrset(ars, amn, ags, cess, cdrs, 
              cdrm, cdrg, csts, cstor, xbarlg, 
	          lamlg, csp, cxistq, mwtss, z, 
              zsq2, titr, azero, hydn,
              xlkeh, ehfac, #om, omlg, omi, 
              tempc, 
              tempk, press, fo2lg, 
	          eh, uzvec1, uspec, umin, ugas, ujtype, 
	          nend, jflag, nsp, nspec, jsflag, jsort, 
              iindx1, ibswx, int iopt1, 
              int iopt2, int iopg1, int iodb1, int iodb2, int ntpr, int iacion, 
              int iebal, int nhydr, int nchlor, int nct, int nsb, int nsb1, int nsq, 
              int nsqb, int nst, int nrst, int nmt, int ngt, int nxt, 
              int kct, int ksb, int ksq, int kebal, int kdim, int kmax,
              int nctmax, int nsqmax, int nsqmx1, int nstmax, int iktmax, int narxmx, 
              int ntprmx, int noutpt, int nttyo, bint qhydth, bint qpt4,
              bint qbswx, bint qbassw,
              ):
              
              # Input parameters
              cdef double[::1] ars_memview = ars
              cdef double[::1] amn_memview = amn
              cdef double[::1] ags_memview = ags
              cdef double[::1] cess_memview = cess
              cdef double[::1] cdrs_memview = cdrs
              cdef double[::1] cdrm_memview = cdrm
              cdef double[::1] cdrg_memview = cdrg
              cdef double[::1] csts_memview = csts
              cdef double[::1] cstor_memview = cstor
              cdef double[::1] xbarlg_memview = xbarlg
              cdef double[::1] lamlg_memview = lamlg
              cdef double[::1] csp_memview = csp
              cdef double[::1] cxistq_memview = cxistq
              cdef double[::1] mwtss_memview = mwtss
              cdef double[::1] z_memview = z # Named z__ in the c code
              cdef double[::1] zsq2_memview = zsq2
              cdef double[::1] titr_memview = titr
              cdef double[::1] azero_memview = azero
              cdef double[::1] hydn_memview = hydn
              cdef double[::1] xlkeh_memview = xlkeh
              cdef double[::1] ehfac_memview = ehfac
              cdef double[::1] tempc_memview = tempc
              cdef double[::1] tempk_memview = tempk
              cdef double[::1] press_memview = press
              cdef double[::1] fo2lg_memview = fo2lg
              cdef double[::1] eh_memview = eh
              cdef char[::1] uzvec1_memview = uzvec1 # Maybe this isn't defined right?
              cdef char[::1] uspec_memview = uspec 
              cdef char[::1] umin_memview = umin 
              cdef char[::1] ugas_memview = ugas 
              cdef char[::1] ujtype_memview = ujtype
              cdef int[::1] nend_memview = nend
              cdef int[::1] jflag_memview = jflag
              cdef int[::1] nsp_memview = nsp
              cdef int[::1] nspec_memview = nspec
              cdef int[::1] jsflag_memview = jsflag
              cdef int[::1] jsort_memview = jsort
              cdef int[::1] iindx1_memview = iindx1
              cdef int[::1] ibswx_memview = ibswx
            #   cdef int[::1] iopt1_memview = iopt1
            #   cdef int[::1] iopt2_memview = iopt2
            #   cdef int[::1] iopg1_memview = iopg1
            #   cdef int[::1] iodb1_memview = iodb1
            #   cdef int[::1] iodb2_memview = iodb2
            #   cdef int[::1] ntpr_memview = ntpr
            #   cdef int[::1] iacion_memview = iacion
            #   cdef int[::1] iebal_memview = iebal
            #   cdef int[::1] nhydr_memview = nhydr
            #   cdef int[::1] nchlor_memview = nchlor
            #   cdef int[::1] nct_memview = nct
            #   cdef int[::1] nsb_memview = nsb
            #   cdef int[::1] nsb1_memview = nsb1
            #   cdef int[::1] nsq_memview = nsq
            #   cdef int[::1] nsqb_memview = nsqb
            #   cdef int[::1] nst_memview = nst
            #   cdef int[::1] nrst_memview = nrst
            #   cdef int[::1] nmt_memview = nmt
            #   cdef int[::1] ngt_memview = ngt
            #   cdef int[::1] nxt_memview = nxt
            #   cdef int[::1] kct_memview = kct
            #   cdef int[::1] ksb_memview = ksb
            #   cdef int[::1] ksq_memview = ksq
            #   cdef int[::1] kebal_memview = kebal
            #   cdef int[::1] kdim_memview = kdim
            #   cdef int[::1] kmax_memview = kmax
            #   cdef int[::1] nctmax_memview = nctmax
            #   cdef int[::1] nsqmax_memview = nsqmax
            #   cdef int[::1] nsqmx1_memview = nsqmx1
            #   cdef int[::1] nstmax_memview = nstmax
            #   cdef int[::1] iktmax_memview = iktmax
            #   cdef int[::1] narxmx_memview = narxmx
            #   cdef int[::1] ntprmx_memview = ntprmx

              # Outputs to be filled in
              cdef double[10000] aa
              cdef double[::1] aa_memview = aa
              cdef double[10000] gm
              cdef double[::1] gm_memview = gm
              cdef double[100] concbs
              cdef double[::1] concbs_memview = concbs
              cdef double[100] cte
              cdef double[::1] cte_memview = cte
              cdef double[100] mte
              cdef double[::1] mte_memview = mte
              cdef double[100] zvclg1
              cdef double[::1] zvclg1_memview = zvclg1
              cdef double[750] conc
              cdef double[::1] conc_memview = conc
              cdef double[750] conclg
              cdef double[::1] conclg_memview = conclg
              cdef double[750] act
              cdef double[::1] act_memview = act
              cdef double[750] actlg
              cdef double[::1] actlg_memview = actlg
              cdef double[750] glg
              cdef double[::1] glg_memview = glg
              cdef double[750] glgx
              cdef double[::1] glgx_memview = glgx
              cdef double[679] xlks
              cdef double[::1] xlks_memview = xlks
              cdef double[750] xlkm
              cdef double[::1] xlkm_memview = xlkm
              cdef double[15] xlkg
              cdef double[::1] xlkg_memview = xlkg
              cdef double[100] rhs
              cdef double[::1] rhs_memview = rhs
              cdef double[100] ee
              cdef double[::1] ee_memview = ee
              cdef double[100] res
              cdef double[::1] res_memview = res
              cdef double xi
            #   cdef double[::1] xi_memview = xi
              cdef double xisteq
            #   cdef double[::1] xisteq_memview = xisteq
              cdef double dshm
            #   cdef double[::1] dshm_memview = dshm
              cdef double shm
            #   cdef double[::1] shm_memview = shm
              cdef int[100] ir
              cdef int[::1] ir_memview = ir
              cdef int[100] kill
              cdef int[::1] kill_memview = kill
              cdef int nsq1
              cdef int khydr
              cdef int ker
              cdef int nloop

              ibasis = np.zeros([750])
              cdef int[::1] ibasis_memview = ibasis
              

              # Defining this here may be unnecessary- it might be calculated in the c code, but I am not certain
              cdef double al10
              al10 = np.log(10)
            #   cdef double[::1] al10_memview = al10
              cdef double rconst
              rconst = 1.98726
            #   cdef double[::1] rconst_memview = rconst
              cdef double om
              om = 55.5086815578
            #   cdef double[::1] om_memview = om
              cdef double omlg
              omlg = np.log(om)
            #   cdef double[::1] omlg_memview = omlg
              cdef double omi
              omi = 1.0 / om
            #   cdef double[::1] omi_memview = omi
              cdef double shmlim
              shmlim = om - 1.0
            #   cdef double[::1] shmlim_memview = shmlim

              result = arrset_(&ars_memview[0], &amn_memview[0], &ags_memview[0], 
                               &cess_memview[0], &cdrs_memview[0], 
                               &cdrm_memview[0], &cdrg_memview[0], 
                               &csts_memview[0], &cstor_memview[0], &xbarlg_memview[0], 
                               &lamlg_memview[0], &aa_memview[0], &gm_memview[0], &csp_memview[0], &concbs_memview[0], 
                               &cte_memview[0], &mte_memview[0], &zvclg1_memview[0], &cxistq_memview[0], &conc_memview[0], 
                               &conclg_memview[0], &act_memview[0], &actlg_memview[0], &glg_memview[0], &glgx_memview[0],
                               &xlks_memview[0], &xlkm_memview[0], &xlkg_memview[0], &mwtss_memview[0], &z_memview[0], 
                               &zsq2_memview[0], &titr_memview[0], &azero_memview[0], &hydn_memview[0], &rhs_memview[0], 
                               &ee_memview[0], &res_memview[0], &al10, &rconst, &xlkeh_memview[0], 
                               &ehfac_memview[0], &om, &omlg, &omi, &tempc_memview[0], 
                               &tempk_memview[0], &press_memview[0], &xi, &xisteq, &fo2lg_memview[0], 
                               &eh_memview[0], &dshm, &shm, &shmlim,
                               &uzvec1_memview[0], &uspec_memview[0], &umin_memview[0], &ugas_memview[0], &ujtype_memview[0], 
                               &nend_memview[0], &jflag_memview[0], &nsp_memview[0], &nspec_memview[0], &jsflag_memview[0], &jsort_memview[0], 
                               &iindx1_memview[0], &ibswx_memview[0], &ibasis_memview[0], &ir_memview[0], &kill_memview[0], &iopt1, 
                               &iopt2, &iopg1, &iodb1, &iodb2, &ntpr, &iacion, 
                               &iebal, &nhydr, &nchlor, &nct, &nsb, &nsb1, &nsq, 
                               &nsqb, &nsq1, &nst, &nrst, &nmt, &ngt, &nxt, 
                               &kct, &ksb, &ksq, &kebal, &kdim, &kmax, &khydr, 
                               &nctmax, &nsqmax, &nsqmx1, &nstmax, &iktmax, &narxmx, 
                               &ntprmx, &ker, &nloop, &noutpt, &nttyo, &qhydth, 
                               &qpt4, &qbswx, &qbassw, <long int> uzvec1_memview[1], 
                               <long int> uspec_memview[1], <long int> umin_memview[1], <long int> ugas_memview[1], <long int> ujtype_memview[1])
            
              return result










