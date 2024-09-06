/* eqlibr_source/eqlibr136.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal xltxp, xutxp, yutxp;
    logical qtxppr;
} eqltxp_;

#define eqltxp_1 eqltxp_

struct {
    integer noutpl, nttyol;
} eqlun_;

#define eqlun_1 eqlun_

struct {
    doublereal eps, smpos, eps10, eps100, smp10, smp100;
    integer irang;
} eqleps_;

#define eqleps_1 eqleps_

struct {
    doublereal palpha[10]	/* was [2][5] */;
    integer napt;
} eqlpal_;

#define eqlpal_1 eqlpal_

struct {
    doublereal pslm[1500]	/* was [3][500] */;
    integer nslm, nslmt, nslmx[1000]	/* was [2][500] */, nalpha[500];
} eqlpsa_;

#define eqlpsa_1 eqlpsa_

struct {
    doublereal pslam[1500]	/* was [3][500] */;
} eqlslm_;

#define eqlslm_1 eqlslm_

struct {
    doublereal pmu[500];
    integer nmu, nmut, nmux[1500]	/* was [3][500] */;
} eqlpmu_;

#define eqlpmu_1 eqlpmu_

struct {
    integer nsxt, nslx, nsxi[1500]	/* was [2][750] */, nsxx[1000]	/* 
	    was [2][500] */;
} eqlpsl_;

#define eqlpsl_1 eqlpsl_

struct {
    integer nmxt, nmlx, nmxi[1500]	/* was [2][750] */, nmxx[3000]	/* 
	    was [3][1000] */;
} eqlpmx_;

#define eqlpmx_1 eqlpmx_

struct {
    doublereal bmu[500], dmu1[500], dmu2[500];
} eqlpmb_;

#define eqlpmb_1 eqlpmb_

struct {
    doublereal bslm[1500]	/* was [3][500] */, dslm1[1500]	/* was [3][
	    500] */, dslm2[1500]	/* was [3][500] */;
} eqlpsb_;

#define eqlpsb_1 eqlpsb_

struct {
    doublereal hkfaz, omega[500], bji[500], mslt[50];
    integer ibjmax, ibjuse, ibjius, icnt, indx1[500], indx2[1000]	/* 
	    was [2][500] */, islt[200]	/* was [4][50] */;
} eqlhkf_;

#define eqlhkf_1 eqlhkf_

struct {
    doublereal al10, farad, rconst, afcnst, ehfac, volg, om, omlg, omi, 
	    tcnst1, tcnst2;
} eqlpp_;

#define eqlpp_1 eqlpp_

struct {
    doublereal adh, bdh, bdot, aphi, bt;
} eqldd_;

#define eqldd_1 eqldd_

struct {
    doublereal cco2[4], ch2o[4], dterm, xjterm, bterm, oscoff;
} eqlej_;

#define eqlej_1 eqlej_

struct {
    doublereal elam[300]	/* was [3][10][10] */;
} eqlelm_;

#define eqlelm_1 eqlelm_

struct {
    integer iopg1, iopg2, iopg3, iopg4, iopg5, iopg6, iopg7, iopg8, iopg9, 
	    iopg10;
} eqlgp_;

#define eqlgp_1 eqlgp_

struct {
    integer ielam;
    logical qhydth, qpt4;
} eqlgpa_;

#define eqlgpa_1 eqlgpa_

struct {
    char udpitz[320], udhkf[320], uactop[32], uelam[8];
} eqlgpc_;

#define eqlgpc_1 eqlgpc_

struct {
    integer izm, izoff;
} eqlsz_;

#define eqlsz_1 eqlsz_

struct {
    doublereal selm[21], selmp[21];
} eqlsza_;

#define eqlsza_1 eqlsza_

struct {
    doublereal beta[100], betamx, alpha[100], bbig, bneg, bgamx, bfac[100], 
	    efac[100];
    integer nfac[100], ibetmx;
} bt_;

#define bt_1 bt_

struct {
    char ubbig[24], ubneg[24], ubgamx[24];
} btc_;

#define btc_1 btc_

struct {
    doublereal cdrs[68579]	/* was [101][679] */, cdrm[75750]	/* 
	    was [101][750] */, cdrg[1515]	/* was [101][15] */, csts[
	    75000]	/* was [100][750] */, cess[52500]	/* was [70][
	    750] */;
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    integer kct, ksb, ksq, kebal, kdim, kmax, khydr, kcarb;
} ki_;

#define ki_1 ki_

struct {
    doublereal aa[10000]	/* was [100][100] */, gm[10000]	/* was [100][
	    100] */, rhs[100], ee[100], res[100];
    integer ir[100], kill[100];
} nn_;

#define nn_1 nn_

struct {
    char uzvec1[800];
} nnu_;

#define nnu_1 nnu_

struct {
    integer iopt1, iopt2, iopt3, iopt4, iopt5, iopt6, iopt7, iopt8, iopt9, 
	    iopt10;
} op_;

#define op_1 op_

struct {
    integer iodb1, iodb2, iodb3, iodb4, iodb5, iodb6, iodb7, iodb8, iodb9, 
	    iodb10;
} op2_;

#define op2_1 op2_

struct {
    integer noutpt, nttyo, nad1, npkup, nrlst, ninpt, nahv;
} un_;

#define un_1 un_

struct {
    doublereal cspb[100], csp[100];
    integer jflagb[100], nsp[100], nspec[100], ibasis[750], ibswx[100];
    logical qbswx, qbassw;
} ww_;

#define ww_1 ww_

struct {
    char uphas1[2400], uphas2[2400], uspecb[2400], ubasis[2400];
} wwc_;

#define wwc_1 wwc_

struct {
    doublereal xlks[679], xlkm[750], xlkg[15], xlkeh;
} xx_;

#define xx_1 xx_

struct {
    doublereal zvclg1[100], del[100];
} zg_;

#define zg_1 zg_

struct {
    doublereal rho, tdspkg, tdspl, eh, pe;
    integer jflag[100], jcflag[70];
} jj_;

#define jj_1 jj_

struct {
    char uredox[24];
} jjc_;

#define jjc_1 jjc_

struct {
    integer iindx1[100], jsflag[750], jmflag[750], jkflag[400]	/* was [20][
	    20] */, jxflag[20], jgflag[15];
} ka_;

#define ka_1 ka_

struct {
    doublereal store[750], csort[750], cstor[1500]	/* was [750][2] */;
    integer jsort[750], istack[750], jstack[750];
} st_;

#define st_1 st_

struct {
    integer nct, nsb, nsb1, nsq, nsq1, nst, nrst, nmt, ngt, nxt, nsqmax, nsqb,
	     nstmax, nrstmx, nmtmax, ngtmax, nxtmax, iktmax, iapxmx, nctmax, 
	    nsqmx1;
} tt_;

#define tt_1 tt_

struct {
    doublereal conc[750], conclg[750], act[750], actlg[750], mte[70], cte[100]
	    ;
} yy_;

#define yy_1 yy_

struct {
    doublereal w[400]	/* was [20][20] */, sx[400]	/* was [20][20] */;
    integer nend[400]	/* was [20][20] */;
} an_;

#define an_1 an_

struct {
    doublereal xi, xisteq, alk, fo2, fo2lg, dshm, shm, shmlim;
} cc_;

#define cc_1 cc_

struct {
    doublereal z__[750], zsq2[750], titr[750], azero[750], hydn[750], glg[750]
	    ;
} ccp_;

#define ccp_1 ccp_

struct {
    integer iacion, iebal;
} ee_;

#define ee_1 ee_

struct {
    char uacion[24], uebal[24];
} eec_;

#define eec_1 eec_

struct {
    char uxtype[320], ujtype[744], uspec[18000], umin[18000], ugas[360], 
	    usolx[480], uelem[568];
} gg_;

#define gg_1 gg_

struct {
    doublereal tempc, tempk, press, tempc1, tempc2;
    integer ntpr;
} hh_;

#define hh_1 hh_

struct {
    integer iopr1, iopr2, iopr3, iopr4, iopr5, iopr6, iopr7, iopr8, iopr9, 
	    iopr10, iopr11, iopr12, iopr13, iopr14, iopr15, iopr16, iopr17, 
	    iopr18, iopr19, iopr20;
} op1_;

#define op1_1 op1_

struct {
    integer nhydr, nchlor, nsodiu, ncarb;
} tu_;

#define tu_1 tu_

struct {
    doublereal xbarlm[400]	/* was [20][20] */, xbarlg[400]	/* was [20][
	    20] */, xlqk[750], affx[400]	/* was [20][20] */, afflcx[20]
	    , si[400]	/* was [20][20] */, siss[20];
} uu_;

#define uu_1 uu_

struct {
    char ussnp[9600]	/* was [20][20] */;
} uuc_;

#define uuc_1 uuc_

struct {
    doublereal xbar[400]	/* was [20][20] */, lamlg[400]	/* was [20][
	    20] */, apx[240]	/* was [12][20] */;
    integer ncomp[20], jsol[20];
} vv_;

#define vv_1 vv_

struct {
    doublereal xlkmod[20];
    integer nxmod, jxmod[20], kxmod[20], nxmdmx;
} nx_;

#define nx_1 nx_

struct {
    char uxmod[480];
} nxc_;

#define nxc_1 nxc_

struct {
    doublereal mwtss[750], atwt[70];
} oo_;

#define oo_1 oo_

struct {
    doublereal tolbt, tolsat, tolxat, toldl;
    integer itermx;
} ps_;

#define ps_1 ps_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b158 = 10.;
static integer c__2 = 2;
static doublereal c_b365 = .33333333333333331;
static integer c__9 = 9;
static integer c__3 = 3;

/* eqlib    version 3245R136, last revised 02/09/88 by rmm */
/* *eqlib  f77 check, ok 04/06/87 by tjw */
/*   Be sure to put the correct release and stage numbers in parameters */
/*   urelno and ustage in routine eqlib. */

/*     This is the principal subroutine of the EQLIB library, part of */
/*     the EQ3/6 software package.  This library is copyrighted as */
/*     follows- */

/*     Copyright (c) 1987 The Regents of the University of California, */
/*     Lawrence Livermore National Laboratory. All rights reserved. */

/*     The following subroutines have been taken and in some cases */
/*     adapted from the non-proprietary libraries of others and are */
/*     excluded from the above copyright: dsiplx, sgeco, sgefa, sgesl, */
/*     isamax, sasum, saxpy, sdot, and sscal. */

/*     The person responsible for this library is */

/*               Thomas J. Wolery */
/*               L-219 */
/*               Lawrence Livermore National Laboratory */
/*               P.O. Box 808 */
/*               Livermore, CA  94550 */
/*               (415) 422-5789 */
/*               FTS 532-5789 */

/*     The modification history is in file eqlib.his. */

/* Subroutine */ int eqlib_(char *u1, char *u2, integer *noutpt, integer *
	nttyo, logical *qtrue, logical *qfalse, ftnlen u1_len, ftnlen u2_len)
{
    /* Initialized data */

    static char urelno[8] = "3245    ";
    static char ustage[8] = "R136    ";

    /* Format strings */
    static char fmt_1000[] = "(/\002 Supported by EQLIB, version \002,a4,a4,"
	    "//\002   Copyright (c) 1987 The Regents of the University of\002,"
	    "\002 California,\002,/\002   Lawrence Livermore National Laborat"
	    "ory. All\002,\002 rights reserved.\002,//)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    extern /* Subroutine */ int chump_(void), flpars_(void);
    static integer islmax;
    extern /* Subroutine */ int undflw_(void);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___4 = { 0, 0, 0, fmt_1000, 0 };



/*     this routine provides eqlib version identification to the */
/*     calling code.  it also sets nttyol to nttyo and noutpl to */
/*     noutpt.  noutpl is used to make debugging prints by eqlib */
/*     routines. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */
/*   ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqltxp.h */
/* -------------------------------------------------------------------- */
/* eqlun.h */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */
/* eqlpal.h */

/*      napt  total number of entries allowed */
/*      palpha  alpha pairs from file data1p */

/* -------------------------------------------------------------------- */
/* eqlpsa.h */
/*      nslm  = number of entries in use */
/*      nslmt = maximum number allowed */
/*      nslmx = species index pairs */
/*      pslm =  lambda triples from file data1p */
/*      nalpha = indices into palpha array */

/* -------------------------------------------------------------------- */
/* eqlslm.h */
/*      pslam  triples */
/*       s-lambda */
/*       s-lambda first derivative */
/*       s-lambda second derivative */
/*       indexed same as pslm array */
/* ------------------------------------------------------------------- */
/* eqlpmu.h */

/*      nmu = actual number of entries in use */
/*      nmut = maximum number of entries allowed */
/*      nmux = triples of aqueous species indices */
/*      pmu = mu(ijk) values array */

/* ------------------------------------------------------------------- */
/* eqlpsl.h */
/*     derived index arrays, s-lambda data */

/*     nsxt   max number of entries in array nsxx */

/*     nslx   actual number of entries in use */

/*     nsxi  array of pairs, indexed by species index */
/*      1) index in array nsxx to first occurrence, this species */
/*      2)  index of last occurrence in nsxx */
/*             (may = first index-1 if no entries) */

/*     nsxx  array of pairs, in sets corresponding to species index */
/*      1) second species index from nslmx */
/*      2) index into pslam, nslmx, ... */

/* -------------------------------------------------------------------- */
/* eqlpmx.h */
/*      base values (25c) */

/*      bmu   mu values */
/*      dmu   derivatives wrt temp */


/*     derived index arrays, mu data */

/*     nmxt   max number of entries in array nmxx */

/*     nmlx   actual number of entries in use */

/*     nmxi  array of pairs, indexed by species index */
/*      1) index in array nmxx to first occurrence, this species */
/*      2) index of last ocurrence in nmxx */
/*           ( may = first index-1 if no entries) */

/*      nmxx  array of triples */
/*       1) second species index from nmux */
/*       2) third species index from nmux */
/*       3) index into pmu, nmux,... */

/* ------------------------------------------------------------------ */
/* eqlpmb.h */
/* -------------------------------------------------------------------- */
/* eqlpsb.h */

/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */


/* ---------------------------------------------------------------------- */

/*     set two logical variables, qtrue and qfalse, which can be used as */
/*     a test in a debugger to confirm which of the possible integer */
/*     values (-1, 0, or 1) correspond to a logical true or a logical */
/*     false. */

    *qtrue = TRUE_;
    *qfalse = FALSE_;

/* ---------------------------------------------------------------------- */

/*     set identification variables */

    s_copy(u1, urelno, (ftnlen)8, (ftnlen)8);
    s_copy(u2, ustage, (ftnlen)8, (ftnlen)8);

/*     equate device number variables for the output file */
/*     and the tty file */

    eqlun_1.noutpl = *noutpt;
    eqlun_1.nttyol = *nttyo;

/*     print version numbers and copyright notice */

    io___3.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___3);
    do_fio(&c__1, u1, (ftnlen)8);
    do_fio(&c__1, u2, (ftnlen)8);
    e_wsfe();
    io___4.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___4);
    do_fio(&c__1, u1, (ftnlen)8);
    do_fio(&c__1, u2, (ftnlen)8);
    e_wsfe();


/*     set parameters to variables for hkf and pitzer arrays */

    eqlpmu_1.nmut = 500;
    eqlpsa_1.nslmt = 500;
    eqlpal_1.napt = 5;
    eqlhkf_1.ibjmax = 500;
    eqlpsl_1.nsxt = 500;
    eqlpmx_1.nmxt = 1000;
    islmax = 50;

/*     avoid underflow trapping on the ridge computer.  if not operating */
/*     on a ridge computer, comment out this call and/or make undflw */
/*     (another eqlib routine) into a dummy routine. */

    undflw_();

/*     get the real*8 machine epsilon, smallest positive number, and */
/*     the exponent range (assumed to be symmetrical).  also get */
/*     parameters for routine texp.  flpars is another eqlib routine. */

    flpars_();

/*     test for sufficient precision and exponent range */

    chump_();

    return 0;
} /* eqlib_ */

/* alters   last revised 12/12/87 by tjw */
/* *alters created in f77 12/08/87 by tjw */
/* Subroutine */ int alters_(integer *nxmod, integer *jxmod, integer *kxmod, 
	doublereal *xlkmod, char *uxmod, doublereal *ars, doublereal *amn, 
	doublereal *ags, doublereal *apress, doublereal *cdrs, doublereal *
	cdrm, doublereal *cdrg, doublereal *tempc, doublereal *afcnst, char *
	uspec, char *umin, char *ugas, char *usolx, integer *nsb, integer *
	nsq, integer *nsq1, integer *nst, integer *nmt, integer *ngt, integer 
	*nxt, integer *ntpr, integer *nsqmx1, integer *narxmx, integer *
	ntprmx, integer *noutpt, integer *nttyo, ftnlen uxmod_len, ftnlen 
	uspec_len, ftnlen umin_len, ftnlen ugas_len, ftnlen usolx_len)
{
    /* Initialized data */

    static char ufix[8] = "fix     ";
    static char uaq[24] = "aqueous species         ";
    static char umn[24] = "minerals                ";
    static char ugs[24] = "gases                   ";
    static char uss[24] = "solid solutions         ";

    /* Format strings */
    static char fmt_237[] = "(\002 * note- alter species \002,a24,\002 was n"
	    "ot among the\002,/7x,\002loaded \002,a24,\002 (eqlib/alters)\002"
	    ",/)";
    static char fmt_1017[] = "(\002 * note- \002,a24,\002 is in the strict b"
	    "asis so\002,/7x,\002it has no alter function (eqlib/alters)\002,"
	    "/)";
    static char fmt_1026[] = "(/7x,\002log k of the above reaction at \002,f"
	    "10.3,/7x,\002 deg celsius and \002,f10.3,\002 bars was changed f"
	    "rom \002,/7x,f10.4,\002 to \002,f10.4,/)";
    static char fmt_1216[] = "(\002 * note- \002,a24,\002 is a fictive fugac"
	    "ity fixing\002,/7x\002mineral so it has no alter function  (eqli"
	    "b/alters)\002,/)";
    static char fmt_1098[] = "(\002 * note- \002,a24,\002 is a solid solut"
	    "ion\002,/7x,\002so it has no alter function (eqlib/alters)\002,/)"
	    ;

    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, apress_dim1, apress_offset, 
	    cdrs_dim1, cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, 
	    cdrg_offset, i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j, n, ng, nm, ns, nx, nrs;
    static doublereal pgrid;
    extern /* Subroutine */ int evdatc_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *), prreac_(
	    doublereal *, char *, char *, integer *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen), evdatk_(doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    integer *);
    static doublereal xlkdel, xlkold;
    static char unamsp[24];
    static doublereal xlknew;

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_1017, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_1017, 0 };
    static cilist io___24 = { 0, 0, 0, fmt_1026, 0 };
    static cilist io___25 = { 0, 0, 0, fmt_1026, 0 };
    static cilist io___26 = { 0, 0, 0, fmt_1216, 0 };
    static cilist io___27 = { 0, 0, 0, fmt_1216, 0 };
    static cilist io___29 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_1026, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_1026, 0 };
    static cilist io___34 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___35 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___36 = { 0, 0, 0, fmt_1026, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_1026, 0 };
    static cilist io___39 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___41 = { 0, 0, 0, fmt_1098, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_1098, 0 };



/*     This routine may appear first in the concatenated source file */
/*     of the eqlib library, part of the eq3/6 software package.  The */
/*     copyright notice and other information are contained in */
/*     eqlib, the principal subroutine of the eqlib library. */

/*     this routine alters the log k values of reactions after they are */
/*     read from the data file.  this is done before the reactions are */
/*     re-written by any basis switching.  the reactions are identified */
/*     on the input file by the names (uxmod) of the associated species. */
/*     the log k values (actually here the corresponding interpolating */
/*     polynomial coefficients) are altered according the following */
/*     options- */

/*        kxmod = 0   replace the log k value by xlkmod */
/*        kxmod = 1   augment the log k value by xlkmod */
/*        kxmod = 2   destablize the associated species by xlkmod kcal */

/*     this routine maps any kxmod = 0 or 2 options into the equivalent */
/*     kxmod = 1 option.  an unaltered pickup file (written by eq3nr or */
/*     eq6) therefore may have only the kxmod = 1 alter option in */
/*     addition to the kxmod = -1 suppression option (which is handled */
/*     by routine supprs).  the effect of this is that if temperature */
/*     in eq6 is a function of reaction progress, the augmentation is */
/*     constant, corresponding to a fixed offset in log k, a corres- */
/*     ponding fixed offset in the gibbs energy and enthalpy of reaction, */
/*     and a corresponding fixed offset in the gibbs energy and enthalpy */
/*     of formation  of the associated species.  the entropy and heat */
/*     capacity of reaction and the corresponding functions of the */
/*     associated species are unchanged. */

/*     changing the log k value to 500. (values that would exceed 500. */
/*     are truncated) has the effect of suppressing the associated */
/*     species.  a suppressed species is excluded from the model. */
/*     some species on the data file may be automatically suppressed */
/*     because no log k data are available (the data file gives the */
/*     equivalent of log k = 500.). */

/*     user-defined suppression, however, is more properly done by */
/*     specifying kxmod = -1.  the species status flags are then marked */
/*     for suppression, but the log k values are preserved.  this allows */
/*     calculation of saturation indices, which would otherwise be */
/*     impossible. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include:'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


    /* Parameter adjustments */
    --jxmod;
    --kxmod;
    --xlkmod;
    uxmod -= uxmod_len;
    uspec -= uspec_len;
    umin -= umin_len;
    ugas -= ugas_len;
    usolx -= usolx_len;
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    apress_dim1 = *narxmx;
    apress_offset = 1 + apress_dim1;
    apress -= apress_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */

/* -------------------------------------------------------------------- */

    if (*nxmod <= 0) {
	goto L999;
    }

/*     compute the grid pressure */

    evdatc_(&pgrid, &apress[apress_offset], tempc, ntpr, narxmx, ntprmx);

    i__1 = *nxmod;
    for (n = 1; n <= i__1; ++n) {
	if (kxmod[n] < 0) {
	    goto L1200;
	}
	s_copy(unamsp, uxmod + n * uxmod_len, (ftnlen)24, uxmod_len);
	xlkdel = xlkmod[n];

/*     aqueous species */

	if (jxmod[n] == 0) {
	    i__2 = *nst;
	    for (ns = 1; ns <= i__2; ++ns) {
		if (s_cmp(unamsp, uspec + ns * uspec_len, (ftnlen)24, 
			uspec_len) == 0) {
		    goto L1007;
		}
/* L1005: */
	    }

	    io___16.ciunit = *noutpt;
	    s_wsfe(&io___16);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uaq, (ftnlen)24);
	    e_wsfe();
	    io___17.ciunit = *nttyo;
	    s_wsfe(&io___17);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uaq, (ftnlen)24);
	    e_wsfe();
	    goto L1200;

L1007:
	    if (ns <= *nsb) {
		io___18.ciunit = *noutpt;
		s_wsfe(&io___18);
		do_fio(&c__1, unamsp, (ftnlen)24);
		e_wsfe();
		io___19.ciunit = *nttyo;
		s_wsfe(&io___19);
		do_fio(&c__1, unamsp, (ftnlen)24);
		e_wsfe();
		goto L1200;
	    }

	    nrs = ns - *nsb;
	    evdatk_(&xlkold, &nrs, &ars[ars_offset], tempc, ntpr, narxmx, 
		    ntprmx);

	    if (kxmod[n] == 0) {
		kxmod[n] = 1;
		xlkdel -= xlkold;
		xlkmod[n] = xlkdel;
	    } else if (kxmod[n] == 2) {
		xlkdel = -cdrs[*nsq1 + nrs * cdrs_dim1] * xlkdel / *afcnst;
		kxmod[n] = 1;
		xlkmod[n] = xlkdel;
	    }
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		ars[(j + nrs * ars_dim2) * ars_dim1 + 1] += xlkdel;
/* L300: */
	    }

	    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs, nsq, 
		    nsq1, nsqmx1, noutpt, uspec_len, (ftnlen)24);
	    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs, nsq, 
		    nsq1, nsqmx1, nttyo, uspec_len, (ftnlen)24);
	    xlknew = xlkold + xlkdel;
	    io___24.ciunit = *noutpt;
	    s_wsfe(&io___24);
	    do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pgrid, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlkold, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlknew, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    io___25.ciunit = *nttyo;
	    s_wsfe(&io___25);
	    do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pgrid, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlkold, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlknew, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    goto L1200;
	}

/*     minerals */

	if (jxmod[n] == 1) {
	    if (s_cmp(unamsp, ufix, (ftnlen)8, (ftnlen)8) == 0) {
		io___26.ciunit = *noutpt;
		s_wsfe(&io___26);
		do_fio(&c__1, unamsp, (ftnlen)24);
		e_wsfe();
		io___27.ciunit = *nttyo;
		s_wsfe(&io___27);
		do_fio(&c__1, unamsp, (ftnlen)24);
		e_wsfe();
		goto L1200;
	    }

	    i__2 = *nmt;
	    for (nm = 1; nm <= i__2; ++nm) {
		if (s_cmp(unamsp, umin + nm * umin_len, (ftnlen)24, umin_len) 
			== 0) {
		    goto L1037;
		}
/* L1035: */
	    }

	    io___29.ciunit = *noutpt;
	    s_wsfe(&io___29);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, umn, (ftnlen)24);
	    e_wsfe();
	    io___30.ciunit = *nttyo;
	    s_wsfe(&io___30);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, umn, (ftnlen)24);
	    e_wsfe();
	    goto L1200;

L1037:
	    evdatk_(&xlkold, &nm, &amn[amn_offset], tempc, ntpr, narxmx, 
		    ntprmx);

	    if (kxmod[n] == 0) {
		kxmod[n] = 1;
		xlkdel -= xlkold;
		xlkmod[n] = xlkdel;
	    } else if (kxmod[n] == 2) {
		xlkdel = -cdrm[*nsq1 + nm * cdrm_dim1] * xlkdel / *afcnst;
		kxmod[n] = 1;
		xlkmod[n] = xlkdel;
	    }
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		amn[(j + nm * amn_dim2) * amn_dim1 + 1] += xlkdel;
/* L305: */
	    }

	    prreac_(&cdrm[cdrm_offset], uspec + uspec_len, unamsp, &nm, nsq, 
		    nsq1, nsqmx1, noutpt, uspec_len, (ftnlen)24);
	    prreac_(&cdrm[cdrm_offset], uspec + uspec_len, unamsp, &nm, nsq, 
		    nsq1, nsqmx1, nttyo, uspec_len, (ftnlen)24);
	    xlknew = xlkold + xlkdel;
	    io___31.ciunit = *noutpt;
	    s_wsfe(&io___31);
	    do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pgrid, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlkold, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlknew, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    io___32.ciunit = *nttyo;
	    s_wsfe(&io___32);
	    do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pgrid, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlkold, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlknew, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    goto L1200;
	}

/*     gases */

	if (jxmod[n] == 2) {
	    i__2 = *ngt;
	    for (ng = 1; ng <= i__2; ++ng) {
		if (s_cmp(unamsp, ugas + ng * ugas_len, (ftnlen)24, ugas_len) 
			== 0) {
		    goto L1067;
		}
/* L1065: */
	    }

	    io___34.ciunit = *noutpt;
	    s_wsfe(&io___34);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, ugs, (ftnlen)24);
	    e_wsfe();
	    io___35.ciunit = *nttyo;
	    s_wsfe(&io___35);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, ugs, (ftnlen)24);
	    e_wsfe();
	    goto L1200;

L1067:
	    evdatk_(&xlkold, &ng, &ags[ags_offset], tempc, ntpr, narxmx, 
		    ntprmx);

	    if (kxmod[n] == 0) {
		kxmod[n] = 1;
		xlkdel -= xlkold;
		xlkmod[n] = xlkdel;
	    } else if (kxmod[n] == 2) {
		xlkdel = -cdrg[*nsq1 + nm * cdrg_dim1] * xlkdel / *afcnst;
		kxmod[n] = 1;
		xlkmod[n] = xlkdel;
	    }
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		ags[(j + ng * ags_dim2) * ags_dim1 + 1] += xlkdel;
/* L310: */
	    }

	    prreac_(&cdrg[cdrg_offset], uspec + uspec_len, unamsp, &ng, nsq, 
		    nsq1, nsqmx1, noutpt, uspec_len, (ftnlen)24);
	    prreac_(&cdrg[cdrg_offset], uspec + uspec_len, unamsp, &ng, nsq, 
		    nsq1, nsqmx1, nttyo, uspec_len, (ftnlen)24);
	    xlknew = xlkold + xlkdel;
	    io___36.ciunit = *noutpt;
	    s_wsfe(&io___36);
	    do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pgrid, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlkold, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlknew, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    io___37.ciunit = *nttyo;
	    s_wsfe(&io___37);
	    do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pgrid, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlkold, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xlknew, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    goto L1200;
	}

/*     solid solutions */

	if (jxmod[n] == 3) {
	    i__2 = *nxt;
	    for (nx = 1; nx <= i__2; ++nx) {
		if (s_cmp(unamsp, usolx + nx * usolx_len, (ftnlen)24, 
			usolx_len) != 0) {
		    goto L1095;
		}
		goto L1097;
L1095:
		;
	    }

	    io___39.ciunit = *noutpt;
	    s_wsfe(&io___39);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uss, (ftnlen)24);
	    e_wsfe();
	    io___40.ciunit = *nttyo;
	    s_wsfe(&io___40);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uss, (ftnlen)24);
	    e_wsfe();
	    goto L1200;

L1097:
	    io___41.ciunit = *noutpt;
	    s_wsfe(&io___41);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    e_wsfe();
	    io___42.ciunit = *nttyo;
	    s_wsfe(&io___42);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    e_wsfe();
	}

L1200:
	;
    }

L999:
    return 0;
} /* alters_ */

/* autosw   last revised 12/11/87 by tjw */
/* Subroutine */ int autosw_(integer *icode, doublereal *ars, doublereal *amn,
	 doublereal *ags, doublereal *cess, doublereal *cdrs, doublereal *
	cdrm, doublereal *cdrg, doublereal *cxistq, doublereal *mwtss, 
	doublereal *z__, doublereal *zsq2, doublereal *titr, doublereal *
	azero, doublereal *hydn, doublereal *csp, char *uzvec1, char *uspec, 
	integer *jflag, integer *jsflag, integer *iindx1, integer *ibswx, 
	integer *ibasis, integer *nsp, integer *iopg1, integer *iacion, 
	integer *iebal, integer *nhydr, integer *nchlor, integer *nct, 
	integer *nsb, integer *nsq, integer *nsq1, integer *nst, integer *
	nrst, integer *nmt, integer *ngt, integer *ksq, integer *nctmax, 
	integer *nsqmx1, integer *narxmx, integer *ntprmx, integer *nerr, 
	integer *noutpt, integer *nttyo, logical *qhydth, logical *qpt4, 
	logical *qbassw, ftnlen uzvec1_len, ftnlen uspec_len)
{
    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, cess_dim1, cess_offset, cdrs_dim1,
	     cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, cdrg_offset, 
	    i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer is2, ns1, ns2, krow;
    extern /* Subroutine */ int switch_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, logical *, 
	    logical *, logical *, ftnlen);


/*     this routine executes automatic basis switching for the purpose */
/*     of reducing mass balance residuals.  the eqlib routine */
/*     fbassw finds candidates for basis switching, and eqlib routine */
/*     gabswx resolves any conflicts. */

/*     input */
/*       icode = 3 if this routine is being used by eq3nr */
/*       uzvec1 = array of names of components in the matrix. */
/*       uspec = array of names of aqueous species */
/*       iindx1 = array relating matrix indexing to the regular indexing */
/*         of species */
/*       ibswx = array of indices of non-master species that are */
/*         candidates for basis switching */
/*       ibasis = array of indices of data file non-master species that */
/*         are currently used in basis switching */
/*       iebal = 'ns' index of the aqueous species whose concentration */
/*               is adjusted to achieve electrical balance; = 0 */
/*               if no such adjustment is being made */
/*       ksq = matrix index of last auxiliary basis species */
/*       iopg1 = activity coefficient option switch */
/*       nerr = error flag */

/*     output */
/*       none (makes basis switches) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --cxistq;
    --mwtss;
    --z__;
    --zsq2;
    --titr;
    --azero;
    --hydn;
    --csp;
    uzvec1 -= uzvec1_len;
    uspec -= uspec_len;
    --jflag;
    --jsflag;
    --iindx1;
    --ibswx;
    --ibasis;
    --nsp;
    cess_dim1 = *nctmax;
    cess_offset = 1 + cess_dim1;
    cess -= cess_offset;
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */
    i__1 = *ksq;
    for (krow = 2; krow <= i__1; ++krow) {
	ns2 = ibswx[krow];
	if (ns2 == 0) {
	    goto L25;
	}
	ns1 = iindx1[krow];
	is2 = ibasis[ns1];

/*     if the ns1-th species is not currently involved in a switch, */
/*     go make the switch.  if it is, that switch must first be undone, */
/*     unless it is a discretionary switch (switch of a strict basis */
/*     species with an auxiliary basis species).  if the switch called */
/*     for undoes the switch made previously, avoid undoing it twice. */

	if (ns2 == is2) {

/*       case 1. the switch called for undoes a current switch */

	    ibasis[ns2] = ns2;
	    ibasis[ns1] = ns1;
	} else {

/*       case 2.  ns1 is not already involved in a switch */
/*       case 3.  ns1 is already switched with another species */

	    ibasis[ns1] = ns2;
	    ibasis[ns2] = ns1;
	    if (is2 != ns1) {

/*         case 3.  undo the existing switch */

		ibasis[is2] = is2;
		switch_(&ns1, &is2, icode, &ars[ars_offset], &amn[amn_offset],
			 &ags[ags_offset], &cess[cess_offset], &cdrs[
			cdrs_offset], &cdrm[cdrm_offset], &cdrg[cdrg_offset], 
			&cxistq[1], &mwtss[1], &z__[1], &zsq2[1], &titr[1], &
			azero[1], &hydn[1], &csp[1], uspec + uspec_len, &
			jflag[1], &jsflag[1], &ibasis[1], &nsp[1], iopg1, 
			iacion, iebal, nhydr, nchlor, nct, nsb, nsq, nsq1, 
			nst, nrst, nmt, ngt, nctmax, nsqmx1, narxmx, ntprmx, 
			nerr, noutpt, nttyo, qhydth, qpt4, qbassw, uspec_len);
	    }
	}

	switch_(&ns1, &ns2, icode, &ars[ars_offset], &amn[amn_offset], &ags[
		ags_offset], &cess[cess_offset], &cdrs[cdrs_offset], &cdrm[
		cdrm_offset], &cdrg[cdrg_offset], &cxistq[1], &mwtss[1], &z__[
		1], &zsq2[1], &titr[1], &azero[1], &hydn[1], &csp[1], uspec + 
		uspec_len, &jflag[1], &jsflag[1], &ibasis[1], &nsp[1], iopg1, 
		iacion, iebal, nhydr, nchlor, nct, nsb, nsq, nsq1, nst, nrst, 
		nmt, ngt, nctmax, nsqmx1, narxmx, ntprmx, nerr, noutpt, nttyo,
		 qhydth, qpt4, qbassw, uspec_len);

/*     reset names in the uzvec1 array */

	s_copy(uzvec1 + krow * uzvec1_len, uspec + ns1 * uspec_len, 
		uzvec1_len, uspec_len);

L25:
	;
    }
    return 0;
} /* autosw_ */

/* azpt4      last modified 11/25/87 by tjw and rmm */
/* Subroutine */ int azpt4_(integer *nst, integer *nsq, integer *nsb, 
	doublereal *msum, doublereal *conc, doublereal *azero, doublereal *
	z__, doublereal *concbs)
{
    /* Format strings */
    static char fmt_9999[] = "(\002 fatal error in azpt4 \002,/,\002  ns    "
	    "    concbs\002)";
    static char fmt_9997[] = "(1x,i4,x,g13.5)";
    static char fmt_9996[] = "(\002 hypothetical salt solution \002,/,\002 c"
	    "at    an    catsf   ansf       mol. salt\002)";
    static char fmt_9995[] = "(4(5x,i5),5x,g13.5)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer ii, jj, ns, ian;
    static doublereal zan, sum;
    static integer icat, ierr;
    static doublereal zcat, zdum, rtot;
    static integer ierr1, ierr2;
    static logical qflag;
    static doublereal omean;
    static integer iansf;
    static doublereal limit, const__;
    extern /* Subroutine */ int omega4_(integer *, doublereal *, doublereal *,
	     integer *);
    static integer icatsf;
    static doublereal omecat, conrat, omegns;
    static integer nusalt;

    /* Fortran I/O blocks */
    static cilist io___69 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___70 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___71 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___72 = { 0, 0, 0, fmt_9996, 0 };
    static cilist io___73 = { 0, 0, 0, fmt_9995, 0 };



/*              created 9/29/87 by rmm */

/*              calculates azero used in hkf equations */
/*     input   nst     number of aqueous species read in from datafile */
/*             nsq     number of basis species */
/*             nsb     number of strict basis species */
/*             conc    array of concentrations  mi */
/*             azero   array of ion size parameters (hydn. theory) */
/*             z       array of charges */
/*             concbs */
/*     output  hkfaz   in eqlhkf */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */


/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --concbs;
    --z__;
    --azero;
    --conc;

    /* Function Body */
    qflag = FALSE_;
    limit = .001f;
    if (qflag) {
/*               hkf using l.h.s. eqn 124 */
	eqlhkf_1.hkfaz = 0.f;
	omegns = 0.f;
	ii = 0;
	i__1 = *nst;
	for (ns = 2; ns <= i__1; ++ns) {
	    conrat = conc[ns] / *msum;
	    if (conrat <= limit) {
		goto L100;
	    }
	    ++ii;
	    zdum = z__[ns];
	    omega4_(&ns, &omegns, &zdum, &ierr);
	    eqlhkf_1.hkfaz += zdum * zdum / omegns;
L100:
	    ;
	}
	rtot = (real) ii;
	eqlhkf_1.hkfaz = eqlhkf_1.hkfaz * 332054.f / rtot;

    } else {
/*              hkf   using  r.h.s. */
/*              calculate azero for hkf equations using salts */

	sum = 0.f;
	nusalt = 0;
	const__ = 332054.f;

	i__1 = eqlhkf_1.icnt;
	for (ii = 1; ii <= i__1; ++ii) {
/*              cation */
	    icat = eqlhkf_1.islt[(ii << 2) - 4];
	    conrat = concbs[icat] / *msum;
	    if (conrat <= limit) {
		goto L200;
	    }
/*              anion */
	    ian = eqlhkf_1.islt[(ii << 2) - 3];
	    conrat = concbs[ian] / *msum;
	    if (conrat <= limit) {
		goto L200;
	    }
/*              both cation and anion ok - get information */
	    icatsf = eqlhkf_1.islt[(ii << 2) - 2];
	    iansf = eqlhkf_1.islt[(ii << 2) - 1];
	    zcat = z__[icat];
	    zan = z__[ian];
	    omega4_(&icat, &omecat, &zcat, &ierr1);
	    omega4_(&ian, &omean, &zan, &ierr2);
/*              calculate both sums used */
	    if (ierr1 == 0 && ierr2 == 0) {
		nusalt = nusalt + icatsf + iansf;
		sum = sum + (real) icatsf * (zcat * zcat / omecat) + (real) 
			iansf * (zan * zan / omean);
	    }
L200:
	    ;
	}

	if (nusalt == 0) {
	    io___69.ciunit = eqlun_1.nttyol;
	    s_wsfe(&io___69);
	    e_wsfe();
	    io___70.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___70);
	    e_wsfe();
	    i__1 = *nsq;
	    for (ns = 1; ns <= i__1; ++ns) {
		io___71.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___71);
		do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&concbs[ns], (ftnlen)sizeof(doublereal))
			;
		e_wsfe();
/* L9998: */
	    }

	    io___72.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___72);
	    e_wsfe();
	    io___73.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___73);
	    i__1 = eqlhkf_1.icnt;
	    for (ii = 1; ii <= i__1; ++ii) {
		for (jj = 1; jj <= 4; ++jj) {
		    do_fio(&c__1, (char *)&eqlhkf_1.islt[jj + (ii << 2) - 5], 
			    (ftnlen)sizeof(integer));
		}
		do_fio(&c__1, (char *)&eqlhkf_1.mslt[ii - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    goto L999;
	}

/*                   r.h.s. in eqn 124 hkf */
	eqlhkf_1.hkfaz = const__ * sum / (real) nusalt;

    }
L999:
    return 0;
} /* azpt4_ */

/* bdmlx    last revised 12/12/87 by tjw  TEST */
/* *bdmlx  f77 rewrite 04/06/87 by tjw */

/* Subroutine */ int bdmlx_(integer *nst)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer k, ns, nx1, nx2, nxx;


/*     input  nst =  number of species */
/*     output derived mu arrays nmxi, nmxx */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqlpmx.h */
/*      base values (25c) */

/*      bmu   mu values */
/*      dmu   derivatives wrt temp */


/*     derived index arrays, mu data */

/*     nmxt   max number of entries in array nmxx */

/*     nmlx   actual number of entries in use */

/*     nmxi  array of pairs, indexed by species index */
/*      1) index in array nmxx to first occurrence, this species */
/*      2) index of last ocurrence in nmxx */
/*           ( may = first index-1 if no entries) */

/*      nmxx  array of triples */
/*       1) second species index from nmux */
/*       2) third species index from nmux */
/*       3) index into pmu, nmux,... */

/* ------------------------------------------------------------------- */
/* eqlpmu.h */

/*      nmu = actual number of entries in use */
/*      nmut = maximum number of entries allowed */
/*      nmux = triples of aqueous species indices */
/*      pmu = mu(ijk) values array */



/* ----------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* eqlun.h */
    nxx = 1;

    i__1 = *nst;
    for (ns = 2; ns <= i__1; ++ns) {

/*     set first index into nmxx */

	eqlpmx_1.nmxi[(ns << 1) - 2] = nxx;
/*                             *----------------------------------------- */
/*                             * search col 1, nmux array */
/*                             *----------------------------------------- */
	i__2 = eqlpmu_1.nmu;
	for (k = 1; k <= i__2; ++k) {
	    if (eqlpmu_1.nmux[k * 3 - 3] == ns) {

/*       found one, get two other indices and nmux index */

		eqlpmx_1.nmxx[nxx * 3 - 3] = eqlpmu_1.nmux[k * 3 - 2];
		eqlpmx_1.nmxx[nxx * 3 - 2] = eqlpmu_1.nmux[k * 3 - 1];
		eqlpmx_1.nmxx[nxx * 3 - 1] = k;
		++nxx;
		if (nxx > eqlpmx_1.nmxt) {
/*          write (noutpl,1010) */
/*          write (nttyol,1010) */
/* 1010     format(' * error - mu index array index overflow ', */
/*     $    '(eqlib/bdmlx)') */
		    s_stop("", (ftnlen)0);
		}
	    }
/* L20: */
	}
/*                             *----------------------------------------- */
/*                             * search col 2, nmux array */
/*                             *----------------------------------------- */
	i__2 = eqlpmu_1.nmu;
	for (k = 1; k <= i__2; ++k) {
	    if (eqlpmu_1.nmux[k * 3 - 2] == ns) {

/*       found one, get other index */

		nx1 = eqlpmu_1.nmux[k * 3 - 3];

/*       skip if duplicate */

		if (ns != nx1) {
		    eqlpmx_1.nmxx[nxx * 3 - 3] = nx1;
		    eqlpmx_1.nmxx[nxx * 3 - 2] = eqlpmu_1.nmux[k * 3 - 1];
		    eqlpmx_1.nmxx[nxx * 3 - 1] = k;
		    ++nxx;
		    if (nxx > eqlpmx_1.nmxt) {
/*            write (noutpl,1010) */
/*            write (nttyol,1010) */
			s_stop("", (ftnlen)0);
		    }
		}
	    }
/* L25: */
	}
/*                             *----------------------------------------- */
/*                             * search col 3, nmux array */
/*                             *----------------------------------------- */
	i__2 = eqlpmu_1.nmu;
	for (k = 1; k <= i__2; ++k) {
	    if (eqlpmu_1.nmux[k * 3 - 1] == ns) {

/*       found one, get other indices */

		nx1 = eqlpmu_1.nmux[k * 3 - 3];
		nx2 = eqlpmu_1.nmux[k * 3 - 2];

/*       skip if duplicate */

		if (ns != nx1 && ns != nx2) {
		    eqlpmx_1.nmxx[nxx * 3 - 3] = nx1;
		    eqlpmx_1.nmxx[nxx * 3 - 2] = nx2;
		    eqlpmx_1.nmxx[nxx * 3 - 1] = k;
		    ++nxx;
		    if (nxx > eqlpmx_1.nmxt) {
/*            write (noutpl,1010) */
/*            write (nttyol,1010) */
			s_stop("", (ftnlen)0);
		    }
		}
	    }
/* L30: */
	}

/*     set last index into nmxx */

	eqlpmx_1.nmxi[(ns << 1) - 1] = nxx - 1;
/* L40: */
    }

    eqlpmx_1.nmlx = nxx - 1;

    return 0;
} /* bdmlx_ */

/* bdslx    last revised 07/24/87 by rmm */
/* *bdslx  f77 rewrite 04/06/87 by tjw */
/* Subroutine */ int bdslx_(integer *nst)
{
    /* Format strings */
    static char fmt_1010[] = "(\002 * error - s-lambda index array overflow"
	    " \002,\002(eqlib/bdslx)\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer k, ns, nxx, nsl1, nsl2;

    /* Fortran I/O blocks */
    static cilist io___83 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___84 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___87 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___88 = { 0, 0, 0, fmt_1010, 0 };



/*     input  nst = number of species */
/*     output derived s-lambda arrays nsxi, nsxx */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* ------------------------------------------------------------------- */
/* eqlpsl.h */
/*     derived index arrays, s-lambda data */

/*     nsxt   max number of entries in array nsxx */

/*     nslx   actual number of entries in use */

/*     nsxi  array of pairs, indexed by species index */
/*      1) index in array nsxx to first occurrence, this species */
/*      2)  index of last occurrence in nsxx */
/*             (may = first index-1 if no entries) */

/*     nsxx  array of pairs, in sets corresponding to species index */
/*      1) second species index from nslmx */
/*      2) index into pslam, nslmx, ... */

/* -------------------------------------------------------------------- */
/* eqlpsa.h */
/*      nslm  = number of entries in use */
/*      nslmt = maximum number allowed */
/*      nslmx = species index pairs */
/*      pslm =  lambda triples from file data1p */
/*      nalpha = indices into palpha array */



/* ----------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* eqlun.h */
    nxx = 1;

    i__1 = *nst;
    for (ns = 2; ns <= i__1; ++ns) {

/*     set first species index into nsxx */

	eqlpsl_1.nsxi[(ns << 1) - 2] = nxx;

/*     search col 1, nslmx array */

	i__2 = eqlpsa_1.nslm;
	for (k = 1; k <= i__2; ++k) {
	    if (eqlpsa_1.nslmx[(k << 1) - 2] == ns) {

/*       found one.  get other species index, nslmx index */

		eqlpsl_1.nsxx[(nxx << 1) - 2] = eqlpsa_1.nslmx[(k << 1) - 1];
		eqlpsl_1.nsxx[(nxx << 1) - 1] = k;
		++nxx;
		if (nxx > eqlpsl_1.nsxt) {
		    io___83.ciunit = eqlun_1.noutpl;
		    s_wsfe(&io___83);
		    e_wsfe();
		    io___84.ciunit = eqlun_1.nttyol;
		    s_wsfe(&io___84);
		    e_wsfe();
		    s_stop("", (ftnlen)0);
		}
	    }
/* L20: */
	}

/*     search col 2 */

	i__2 = eqlpsa_1.nslm;
	for (k = 1; k <= i__2; ++k) {
	    nsl2 = eqlpsa_1.nslmx[(k << 1) - 1];
	    nsl1 = eqlpsa_1.nslmx[(k << 1) - 2];
	    if (nsl2 == ns) {

/*       found one - skip if equal pair */

		if (nsl1 != nsl2) {
		    eqlpsl_1.nsxx[(nxx << 1) - 2] = nsl1;
		    eqlpsl_1.nsxx[(nxx << 1) - 1] = k;
		    ++nxx;
		    if (nxx > eqlpsl_1.nsxt) {
			io___87.ciunit = eqlun_1.noutpl;
			s_wsfe(&io___87);
			e_wsfe();
			io___88.ciunit = eqlun_1.nttyol;
			s_wsfe(&io___88);
			e_wsfe();
			s_stop("", (ftnlen)0);
		    }
		}
	    }
/* L30: */
	}

/*     set last index into nsxx */

	eqlpsl_1.nsxi[(ns << 1) - 1] = nxx - 1;
/* L40: */
    }

    eqlpsl_1.nslx = nxx - 1;

    return 0;
} /* bdslx_ */

/* betgam   last revised 10/28/87 by tjw */
/* *betgam created in f77 10/22/87 by tjw */
/* Subroutine */ int betgam_(char *uspec, doublereal *conc, doublereal *glgc, 
	doublereal *glgo, integer *nst, doublereal *bgamx, char *ubgamx, 
	ftnlen uspec_len, ftnlen ubgamx_len)
{
    /* Format strings */
    static char fmt_1000[] = "(\002 * error- entry to betgam with iopg1 ="
	    " \002,i5,\002 (eqlib/betgam)\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer ns;
    static doublereal dgam;
    static integer iopg1;
    static doublereal adgam;

    /* Fortran I/O blocks */
    static cilist io___90 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___91 = { 0, 0, 0, fmt_1000, 0 };



/*     this routine finds the activity coefficient residual with the */
/*     largest magnitude (bgamx).  the range of activiity coefficient */
/*     residuals covers all aqueous species, including water. */

/*     input */
/*       uspec = name array for aqueous species */
/*       conc = concentration array for aqueous species */
/*       glgc = most recently calculated values of the log of the */
/*              activity coefficients */
/*       glgo = previous values of the log of the activity coefficients */
/*       nst = total number of aqueous species */

/*       note- glgc(1) is the most recently calculated value of the */
/*         activity of water, and glgo(1) is the previous value of the */
/*         same quantity. */

/*     output */
/*       bgamx = the largest magntitude of any activity coefficient */
/*               residual for an aqueous species.  an activity coefficient */
/*               residual is the difference between the most recently */
/*               calculated value of the activity coefficient and */
/*               the corresponding previous value */
/*       ubgamx = the name of the aquoeus species the value of */
/*               whose activity coefficient residual is bgamx */


/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --glgo;
    --glgc;
    --conc;
    uspec -= 24;

    /* Function Body */
    if (iopg1 >= 101) {
	io___90.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___90);
	do_fio(&c__1, (char *)&iopg1, (ftnlen)sizeof(integer));
	e_wsfe();
	io___91.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___91);
	do_fio(&c__1, (char *)&iopg1, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    *bgamx = -1.f;

/*     calculate activity coefficient residuals */

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	if (conc[ns] > 0.f) {
	    dgam = glgc[ns] - glgo[ns];
	    adgam = abs(dgam);
	    if (adgam > *bgamx) {
		*bgamx = adgam;
		s_copy(ubgamx, uspec + ns * 24, (ftnlen)24, (ftnlen)24);
	    }
	}
/* L540: */
    }

/* L999: */
    return 0;
} /* betgam_ */

/* chump    last revised 04/17/87 by tjw */
/* *chump  f77 check, ok 04/17/87 by tjw */
/* Subroutine */ int chump_(void)
{
    /* Initialized data */

    static doublereal epstst = 1e-14;
    static integer irgtst = 38;

    /* Format strings */
    static char fmt_1007[] = "(\002 * error - insufficient floating point ep"
	    "silon = \002,e12.5,/5x,\002needs to be at least as small as \002"
	    ",e12.5,\002 (eqlib/chump)\002)";
    static char fmt_1008[] = "(\002 * error - insufficient floating point ex"
	    "ponent range =\002,\002 +/- \002,i4,/5x,\002needs to be +/- at l"
	    "east \002,i4,\002 (eqlib/chump)\002)";
    static char fmt_1009[] = "(/\002 * sorry, your computer is not adequat"
	    "e\002,\002 (eqlib/chump)\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static logical qstop;

    /* Fortran I/O blocks */
    static cilist io___98 = { 0, 0, 0, fmt_1007, 0 };
    static cilist io___99 = { 0, 0, 0, fmt_1007, 0 };
    static cilist io___100 = { 0, 0, 0, fmt_1008, 0 };
    static cilist io___101 = { 0, 0, 0, fmt_1008, 0 };
    static cilist io___102 = { 0, 0, 0, fmt_1009, 0 };
    static cilist io___103 = { 0, 0, 0, fmt_1009, 0 };



/*     this routine tests the floating point precision and exponent */
/*     range for adequacy for eq3/6 calculations.  this is essentially */
/*     a trap to insure that most floating point variables are real*8. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/*     epstst = test on floating point epsilon */
/*       (should be at least 1.e-14) */
/*     irgtst = requirement on the floating point exponent range */
/*       (should be at least 75) */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ----------------------------------------------------------------------- */

    qstop = FALSE_;
    if (eqleps_1.eps > epstst) {
	io___98.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___98);
	do_fio(&c__1, (char *)&eqleps_1.eps, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&epstst, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___99.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___99);
	do_fio(&c__1, (char *)&eqleps_1.eps, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&epstst, (ftnlen)sizeof(doublereal));
	e_wsfe();
	qstop = TRUE_;
    }
    if (eqleps_1.irang < irgtst) {
	io___100.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___100);
	do_fio(&c__1, (char *)&eqleps_1.irang, (ftnlen)sizeof(integer));
	e_wsfe();
	io___101.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___101);
	do_fio(&c__1, (char *)&eqleps_1.irang, (ftnlen)sizeof(integer));
	e_wsfe();
	qstop = TRUE_;
    }
    if (qstop) {
	io___102.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___102);
	e_wsfe();
	io___103.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___103);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    return 0;
} /* chump_ */

/* dscram   last revised 04/07/87 by tjw */
/* *dscram f77 check, ok 04/07/87 by tjw */
/* Subroutine */ int dscram_(integer *nf1, integer *nf2)
{
    /* Initialized data */

    static integer ialph = 26;
    static char ualph[1*26] = "a" "b" "c" "d" "e" "f" "g" "h" "i" "j" "k" 
	    "l" "m" "n" "o" "p" "q" "r" "s" "t" "u" "v" "w" "x" "y" "z";

    /* Format strings */
    static char fmt_1000[] = "(a1,a128)";
    static char fmt_1005[] = "(a128)";

    /* System generated locals */
    integer i__1, i__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, j;
    static char utm[1], utx[1], uline[128];

    /* Fortran I/O blocks */
    static cilist io___109 = { 0, 0, 1, fmt_1000, 0 };
    static cilist io___112 = { 0, 0, 0, fmt_1005, 0 };



/*     this routine unscrambles a file of tables whose lines are */
/*     interspersed, but which are marked 'a', 'b', 'c', etc., in */
/*     column one. */

/*     input */
/*       nf1 = unit number of the scrambled file. */
/*       nf2 = unit number of the unscrambled file, which must */
/*         already be open.  the record length will be 128 characters. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */



/* ---------------------------------------------------------------------- */

    al__1.aerr = 0;
    al__1.aunit = *nf2;
    f_rew(&al__1);
    i__1 = ialph;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*(unsigned char *)utx = *(unsigned char *)&ualph[i__ - 1];
	al__1.aerr = 0;
	al__1.aunit = *nf1;
	f_rew(&al__1);
	for (j = 1; j <= 10000; ++j) {
	    io___109.ciunit = *nf1;
	    i__2 = s_rsfe(&io___109);
	    if (i__2 != 0) {
		goto L20;
	    }
	    i__2 = do_fio(&c__1, utm, (ftnlen)1);
	    if (i__2 != 0) {
		goto L20;
	    }
	    i__2 = do_fio(&c__1, uline, (ftnlen)128);
	    if (i__2 != 0) {
		goto L20;
	    }
	    i__2 = e_rsfe();
	    if (i__2 != 0) {
		goto L20;
	    }
	    if (*(unsigned char *)utm == *(unsigned char *)utx) {
		io___112.ciunit = *nf2;
		s_wsfe(&io___112);
		do_fio(&c__1, uline, (ftnlen)128);
		e_wsfe();
	    }
/* L10: */
	}
L20:
	;
    }
    return 0;
} /* dscram_ */

/* ssfunc   last revised 11/25/87 by tjw */
/* *ssfunc f77 check, 07/08/87 by tjw */

/*     routine that computes the value of the saturation */
/*     index of a solid solution given the composition of the */
/*     solid solution and the composition of the aqueous phase */
/*     in equilibrium with it. this routine is called by simplex */
/*     subroutine. */

/*     comp is array containing composition of solid solution */
/*     (note that dsiplx provides ncomp-1 compositions of endmember */
/*     phases, ss computes the last one) */

doublereal ssfunc_(doublereal *comp, integer *nend, doublereal *w, integer *
	ndbug1, doublereal *xbar, doublereal *lamlg, integer *ncomp, integer *
	jsol, integer *nn, doublereal *xqk, integer *nnm1, integer *nx, 
	doublereal *tempk, doublereal *press, doublereal *al10, doublereal *
	rconst, doublereal *afkst, integer *idbg, integer *iktmax)
{
    /* Format strings */
    static char fmt_12[] = "(5x,16(d10.4,2x))";

    /* System generated locals */
    integer nend_dim1, nend_offset, w_dim1, w_offset, xbar_dim1, xbar_offset, 
	    lamlg_dim1, lamlg_offset, i__1;
    doublereal ret_val, d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, nm;
    extern doublereal tlg_(doublereal *);
    static doublereal ssi, sum, xdum;
    extern /* Subroutine */ int lamda_(doublereal *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal lamdax;

    /* Fortran I/O blocks */
    static cilist io___117 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___118 = { 0, 0, 0, fmt_12, 0 };



/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

/*     compute comp(nn) which is dependent variable */

    /* Parameter adjustments */
    --comp;
    --ncomp;
    --jsol;
    --xqk;
    lamlg_dim1 = *iktmax;
    lamlg_offset = 1 + lamlg_dim1;
    lamlg -= lamlg_offset;
    xbar_dim1 = *iktmax;
    xbar_offset = 1 + xbar_dim1;
    xbar -= xbar_offset;
    w_dim1 = *iktmax;
    w_offset = 1 + w_dim1;
    w -= w_offset;
    nend_dim1 = *iktmax;
    nend_offset = 1 + nend_dim1;
    nend -= nend_offset;

    /* Function Body */
    sum = 0.f;
    i__1 = *nnm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum += comp[i__];
/* L9: */
    }
    comp[*nn] = 1.f - sum;

/*     need to put current values of comp back into xbar */

    j = 1;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	nm = nend[i__ + *nx * nend_dim1];

/*     component not present */

	if (nm == 0) {
	    goto L10;
	}
	xbar[i__ + *nx * xbar_dim1] = comp[j];
	++j;
L10:
	;
    }

    lamda_(al10, &jsol[1], &lamlg[lamlg_offset], &ncomp[1], nx, rconst, tempk,
	     &xbar[xbar_offset], &w[w_offset], iktmax);

    if (*idbg >= 1) {
	io___117.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___117);
	i__1 = ncomp[*nx];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&xbar[i__ + *nx * xbar_dim1], (ftnlen)
		    sizeof(doublereal));
	}
	do_fio(&c__1, (char *)&ret_val, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (*idbg >= 1) {
	io___118.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___118);
	i__1 = ncomp[*nx];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&lamlg[i__ + *nx * lamlg_dim1], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
    }

    ssi = 0.f;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (nend[i__ + *nx * nend_dim1] == 0) {
	    goto L11;
	}
	lamdax = pow_dd(&c_b158, &lamlg[i__ + *nx * lamlg_dim1]);
	xdum = xbar[i__ + *nx * xbar_dim1];

/*     avoid xbar>1 or xbar<0 areas */

	if (xdum <= 0.f) {
	    xdum = -xdum;
	    d__2 = xqk[i__] / (xdum * lamdax);
	    ssi -= (d__1 = xdum * tlg_(&d__2), abs(d__1));

/*       lower limit for calculation */

	    xbar[i__ + *nx * xbar_dim1] = 1e-20f;
	} else if (xdum >= 1.f) {
	    d__2 = xqk[i__] / (xdum * lamdax);
	    ssi -= (d__1 = xdum * tlg_(&d__2), abs(d__1));
	} else {
	    d__1 = xqk[i__] / (xdum * lamdax);
	    ssi += xdum * tlg_(&d__1);
	}
L11:
	;
    }

/*     ssfunc is the value that is maximized */

/*     affinity for solid solution */

    ret_val = ssi;

    return ret_val;
} /* ssfunc_ */

/* dsiplx   last revised 11/25/87 by tjw */
/* *dsiplx f77 partial rewrite 04/07/87 by tjw (needs a lot more work) */
/* Subroutine */ int dsiplx_(D_fp ssfunc, doublereal *axx, integer *n, 
	integer *nm, doublereal *alpha, doublereal *deps, integer *nmin, 
	integer *itr, doublereal *xbarh, doublereal *fmin, integer *nit, 
	integer *nend, doublereal *w, integer *ndbug1, integer *ntty, integer 
	*noutpt, doublereal *xbar, doublereal *lamlg, integer *ncomp, integer 
	*iktmax, integer *jsol, integer *nn, doublereal *xqkx, integer *nx, 
	doublereal *tempk, doublereal *press, doublereal *al10, doublereal *
	rconst, doublereal *afkst, integer *idbg)
{
    /* Initialized data */

    static doublereal small = 1e-25;

    /* Format strings */
    static char fmt_1000[] = "(\002 (subr. dsiplx) the argument n is inval"
	    "id.\002,5x,\002n=\002,i7)";
    static char fmt_1010[] = "(\002 (subr. dsiplx) the argument nm is invali"
	    "d.\002,5x,\002m=\002,i7)";
    static char fmt_1020[] = "(\002 (subr. dsiplx) the argument array alpha "
	    "invalid.\002,5x,\002alpha=\002,1p3e24.16)";
    static char fmt_1030[] = "(\002 (subr. dsiplx) the argument deps is inva"
	    "lid.\002,5x,\002deps=\002,1p2e24.16)";
    static char fmt_1040[] = "(\002 (subr. dsiplx) the argument itr is inval"
	    "id.\002,5x,\002itr=\002,i7)";
    static char fmt_1050[] = "(\002 (subr. dsiplx) the argument axx is inval"
	    "id.\002,5x,\002axx(\002,i2,\002,n+1 )=\002,1pe24.16)";

    /* System generated locals */
    integer axx_dim1, axx_offset, w_dim1, w_offset, xbar_dim1, xbar_offset, 
	    lamlg_dim1, lamlg_offset, nend_dim1, nend_offset, i__1, i__2, 
	    i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal f[101];
    static integer i__, j, k, i1, n1;
    static doublereal fc, fe, sd, fr, xr[100], gam, bet, alp;
    static integer ier, ker;
    static doublereal sum, gam1, bet1, alp1;
    static integer nnm1;
    static doublereal sum2;
    static integer imin, imax;
    static doublereal fmax;
    static integer ieps;
    static doublereal aint, test[200];
    static integer nitm1, nitm2;
    static doublereal check;
    static integer icode;
    static doublereal aintm, fsmax;
    static integer itest;
    static doublereal xlast;
    static integer nstop;

    /* Fortran I/O blocks */
    static cilist io___126 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___128 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___134 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_1030, 0 };
    static cilist io___138 = { 0, 0, 0, fmt_1040, 0 };
    static cilist io___140 = { 0, 0, 0, fmt_1050, 0 };



/*     *** to find a local minimum or maximum of a function by use of */
/*           simplex method proposed by j.a.nelder & r.mead *** */

/*     Adapted from a nonpproprietary routine from the computer library */
/*     of Tokyo University. */

/*     this routine is used to find maximum of affinity function */
/*     in hypothetical solid solution subroutine hpsat */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */



    /* Parameter adjustments */
    --alpha;
    --deps;
    --xbarh;
    --ncomp;
    lamlg_dim1 = *iktmax;
    lamlg_offset = 1 + lamlg_dim1;
    lamlg -= lamlg_offset;
    xbar_dim1 = *iktmax;
    xbar_offset = 1 + xbar_dim1;
    xbar -= xbar_offset;
    w_dim1 = *iktmax;
    w_offset = 1 + w_dim1;
    w -= w_offset;
    nend_dim1 = *iktmax;
    nend_offset = 1 + nend_dim1;
    nend -= nend_offset;
    axx_dim1 = *iktmax;
    axx_offset = 1 + axx_dim1;
    axx -= axx_offset;
    --jsol;
    --xqkx;

    /* Function Body */

/* ----------------------------------------------------------------------- */

/*     *** argument check and preparation *** */

    nnm1 = *n;
    ier = 0;

/*     wlb - itest = flag for oscillating solution */

    itest = 0;
    if (*n <= 0 || *n > 100) {
	io___126.ciunit = *noutpt;
	s_wsfe(&io___126);
	do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
	e_wsfe();
	ier = 3;
    }

    n1 = *n + 1;
    if (*nm < *n || *nm < 1) {
	io___128.ciunit = *noutpt;
	s_wsfe(&io___128);
	do_fio(&c__1, (char *)&(*nm), (ftnlen)sizeof(integer));
	e_wsfe();
	ier = 3;
    }

    ker = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	if (alpha[i__] < -small) {
	    ker = 1;
	}
/* L30: */
    }

    if (ker == 1) {
	goto L40;
    }
    if (alpha[2] >= 1.f) {
	goto L40;
    }
    if (alpha[3] <= 1.f && alpha[3] > small) {
	goto L40;
    }

    alp = alpha[1];
    bet = alpha[2];
    gam = alpha[3];
    if (abs(alpha[1]) <= small) {
	alp = 1.f;
    }
    if (abs(alpha[2]) <= small) {
	bet = .5f;
    }
    if (abs(alpha[3]) <= small) {
	gam = 2.f;
    }
    goto L60;

L40:
    io___134.ciunit = *noutpt;
    s_wsfe(&io___134);
    for (j = 1; j <= 3; ++j) {
	do_fio(&c__1, (char *)&alpha[j], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    ier = 3;

L60:
    if (deps[1] > -small && deps[2] > -small) {
	goto L80;
    }

L70:
    io___136.ciunit = *noutpt;
    s_wsfe(&io___136);
    do_fio(&c__1, (char *)&deps[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&deps[2], (ftnlen)sizeof(doublereal));
    e_wsfe();
    ier = 3;
    goto L140;

L80:
    if (abs(deps[1]) > small) {
	goto L110;
    }
    if (abs(deps[2]) <= small) {
	goto L70;
    }
    ieps = 2;
    goto L140;
L110:
    if (abs(deps[2]) - small <= 0.) {
	goto L120;
    } else {
	goto L130;
    }
L120:
    ieps = 1;
    goto L140;
L130:
    ieps = 3;
L140:
    if (*itr < 0) {
	goto L150;
    } else if (*itr == 0) {
	goto L160;
    } else {
	goto L170;
    }
L150:
    io___138.ciunit = *noutpt;
    s_wsfe(&io___138);
    do_fio(&c__1, (char *)&(*itr), (ftnlen)sizeof(integer));
    e_wsfe();
    ier = 3;
    goto L180;
L160:
    nstop = 500;
    goto L180;
L170:
    nstop = *itr;
L180:
    if (*n <= 0 || *n > 100) {
	goto L195;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = axx[i__ + n1 * axx_dim1], abs(d__1)) > small) {
	    goto L190;
	}
	io___140.ciunit = *noutpt;
	s_wsfe(&io___140);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&axx[i__ + n1 * axx_dim1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	ier = 3;
L190:
	;
    }
L195:
    if (ier != 3) {
	goto L197;
    }
    goto L999;

/*        *** set the vertices of the initial simplex *** */

L197:
    i__1 = n1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i1 = i__ - 1;
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    if (i1 == j) {
		goto L200;
	    }
	    axx[j + i__ * axx_dim1] = axx[j + axx_dim1];
	    goto L210;
L200:
	    axx[j + i__ * axx_dim1] = axx[j + axx_dim1] + axx[j + n1 * 
		    axx_dim1];
L210:
	    ;
	}
    }
    icode = 1;
    *nit = 1;

/*        *** beginning of the loop for the simplex method *** */
L220:
    if (*nit <= nstop) {
	goto L230;
    }
    --(*nit);
    ier = 1;
    if (icode <= 0) {
	goto L640;
    } else {
	goto L235;
    }

/*       *** values of the function at the vertices *** */
L230:
    if (icode == 0) {
	goto L300;
    }
L235:
    i__2 = n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/* L240: */
	    xbarh[j] = axx[j + i__ * axx_dim1];
	}
	if (*nmin <= 0) {
	    goto L250;
	} else {
	    goto L260;
	}
L250:
	f[i__ - 1] = (*ssfunc)(&xbarh[1], &nend[nend_offset], &w[w_offset], 
		ndbug1, &xbar[xbar_offset], &lamlg[lamlg_offset], &ncomp[1], &
		jsol[1], nn, &xqkx[1], &nnm1, nx, tempk, press, al10, rconst, 
		afkst, idbg, iktmax);
	goto L270;
L260:
	f[i__ - 1] = -(*ssfunc)(&xbarh[1], &nend[nend_offset], &w[w_offset], 
		ndbug1, &xbar[xbar_offset], &lamlg[lamlg_offset], &ncomp[1], &
		jsol[1], nn, &xqkx[1], &nnm1, nx, tempk, press, al10, rconst, 
		afkst, idbg, iktmax);
L270:
	;
    }
    icode = 0;

/*        *** find the maximum and minimum points *** */

L300:
    imax = 1;
    imin = 1;
    fmax = f[0];
    *fmin = f[0];
    i__2 = n1;
    for (i__ = 2; i__ <= i__2; ++i__) {
	if (f[i__ - 1] - fmax <= 0.) {
	    goto L320;
	} else {
	    goto L310;
	}
L310:
	fmax = f[i__ - 1];
	imax = i__;
	goto L340;
L320:
	if (f[i__ - 1] - *fmin >= 0.) {
	    goto L340;
	} else {
	    goto L330;
	}
L330:
	*fmin = f[i__ - 1];
	imin = i__;
L340:
	;
    }
    if (ier == 1) {
	goto L645;
    }

/*        *** calculate the centroid of the points with i.ne.imax *** */
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
	sum = 0.f;
	i__1 = n1;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L350: */
	    sum += axx[j + i__ * axx_dim1];
	}
	xbarh[j] = (sum - axx[j + imax * axx_dim1]) / *n;
/* L360: */
    }

/*        *** reflection of the maximum point *** */
    alp1 = alp + 1.f;
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
/* L370: */
	xr[j - 1] = alp1 * xbarh[j] - alp * axx[j + imax * axx_dim1];
    }
    fr = (*ssfunc)(xr, &nend[nend_offset], &w[w_offset], ndbug1, &xbar[
	    xbar_offset], &lamlg[lamlg_offset], &ncomp[1], &jsol[1], nn, &
	    xqkx[1], &nnm1, nx, tempk, press, al10, rconst, afkst, idbg, 
	    iktmax);
    if (*nmin > 0) {
	fr = -fr;
    }

/*        *** see if func(reflec)<fmin *** */
    if (fr - *fmin >= 0.) {
	goto L380;
    } else {
	goto L420;
    }

/*        *** find the next maximum point (when func(reflec).ge.fmin ) *** */
L380:
    fsmax = -1e30;
    i__2 = n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	if (i__ == imax) {
	    goto L390;
	}
	if (f[i__ - 1] <= fsmax) {
	    goto L390;
	}
	fsmax = f[i__ - 1];
L390:
	;
    }

/*        *** see if func(reflec)>fsmax *** */
    if (fr - fsmax <= 0.) {
	goto L400;
    } else {
	goto L460;
    }
L400:
    f[imax - 1] = fr;
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
/* L410: */
	xbarh[j] = xr[j - 1];
    }
    goto L445;

/*        *** expansion of the reflection (when  func(reflec).lt.fmin ) *** */
L420:
    gam1 = 1.f - gam;
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
/* L430: */
	xbarh[j] = gam * xr[j - 1] + gam1 * xbarh[j];
    }
    fe = (*ssfunc)(&xbarh[1], &nend[nend_offset], &w[w_offset], ndbug1, &xbar[
	    xbar_offset], &lamlg[lamlg_offset], &ncomp[1], &jsol[1], nn, &
	    xqkx[1], &nnm1, nx, tempk, press, al10, rconst, afkst, idbg, 
	    iktmax);
    if (*nmin > 0) {
	fe = -fe;
    }

/*        *** see if func(expans)<func(reflec) *** */
    if (fe - fr >= 0.) {
	goto L400;
    } else {
	goto L440;
    }
L440:
    f[imax - 1] = fe;

/*        *** replace the maximum point with a new vertex *** */
L445:
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
/* L450: */
	axx[j + imax * axx_dim1] = xbarh[j];
    }
    goto L500;

/*        *** in case of func(reflec)>fsmax *** */
L460:
    if (fr >= fmax) {
	goto L480;
    }
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
/* L470: */
	axx[j + imax * axx_dim1] = xr[j - 1];
    }

/*        *** contraction of the maximum point or of its reflection *** */
L480:
    bet1 = 1.f - bet;
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
/* L490: */
	xbarh[j] = bet * axx[j + imax * axx_dim1] + bet1 * xbarh[j];
    }
    fc = (*ssfunc)(&xbarh[1], &nend[nend_offset], &w[w_offset], ndbug1, &xbar[
	    xbar_offset], &lamlg[lamlg_offset], &ncomp[1], &jsol[1], nn, &
	    xqkx[1], &nnm1, nx, tempk, press, al10, rconst, afkst, idbg, 
	    iktmax);
    if (*nmin > 0) {
	fc = -fc;
    }

/*        *** see if func(contrac)>fmax *** */
    if (fc - fmax >= 0.) {
	goto L620;
    } else {
	goto L495;
    }
L495:
    f[imax - 1] = fc;
    goto L445;

/*        *** convergence check *** */
L500:
    switch (ieps) {
	case 1:  goto L520;
	case 2:  goto L550;
	case 3:  goto L520;
    }
L520:
    sum2 = 0.f;
    sum = 0.f;
    i__2 = n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	sum += f[i__ - 1];
/* L530: */
    }
    sum /= n1;
    i__2 = n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing 2nd power */
	d__1 = f[i__ - 1] - sum;
	sum2 = d__1 * d__1 + sum2;
/* L535: */
    }
    sd = sqrt(sum2 / n1);
    if (sd - deps[1] <= 0.) {
	goto L540;
    } else {
	goto L550;
    }
L540:
    if (ieps == 1) {
	goto L640;
    }
    ieps = 4;
L550:
    aintm = -1e30;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i1 = i__ + 1;
	i__1 = n1;
	for (k = i1; k <= i__1; ++k) {
	    i__3 = *n;
	    for (j = 1; j <= i__3; ++j) {
		aint = (d__1 = axx[j + i__ * axx_dim1] - axx[j + k * axx_dim1]
			, abs(d__1));
/* L560: */
		if (aint > aintm) {
		    aintm = aint;
		}
	    }
/* L570: */
	}
/* L580: */
    }
    switch (ieps) {
	case 1:  goto L600;
	case 2:  goto L590;
	case 3:  goto L600;
	case 4:  goto L590;
    }
L590:
    if (aintm <= deps[2]) {
	goto L640;
    }
L600:
    if (aintm > 1e15f) {
	goto L680;
    }
    if (ieps == 4) {
	ieps = 3;
    }
L610:
    ++(*nit);

/*   wlb  add test for oscillating solution.  if the solution is */
/*   oscillating back and forth between two solutions that */
/*   are identical every other iteration, terminate with message. */

    test[*nit - 1] = *fmin;
    if (*nit <= 2) {
	goto L220;
    }
    nitm2 = *nit - 2;
    if (test[*nit - 1] == test[nitm2 - 1]) {
	++itest;
    }
    if (itest <= 150) {
	xlast = xbarh[1];
    }
    if (itest <= 150) {
	goto L220;
    }

    nitm1 = *nit - 1;
    check = (d__1 = xlast - xbarh[1], abs(d__1));
/*     check how big oscillation is */
    ier = 0;
    if (check <= 1e-4f) {
	ier = 4;
    }
    if (check <= 1e-5f) {
	ier = 5;
    }
    if (check <= 1e-7f) {
	ier = 7;
    }
    if (check <= 1e-9f) {
	ier = 9;
    }
    goto L640;

/*        *** reduce the simplex size *** */
L620:
    icode = 1;
    i__2 = n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
/* L630: */
	    axx[j + i__ * axx_dim1] = (axx[j + i__ * axx_dim1] + axx[j + imin 
		    * axx_dim1]) * .5f;
	}
    }
    goto L610;

/*        *** terminate *** */
L640:
    if (*fmin > f[imax - 1]) {
	goto L660;
    }
L645:
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* L650: */
	xbarh[j] = axx[j + imin * axx_dim1];
    }
    goto L690;
L660:
    *fmin = f[imax - 1];
    goto L690;
L680:
    ier = 2;
L690:
    *itr = *nit;
    if (*nmin > 0) {
	*fmin = -(*fmin);
    }
L999:

    return 0;
} /* dsiplx_ */

/* echolk   last revised 12/22/87 by tjw */
/* *echolk f77 rewrite and move from eq3nr to eqlib 12/02/87 by tjw */
/* Subroutine */ int echolk_(integer *ilevel, integer *nf, doublereal *tempc, 
	doublereal *press, doublereal *cdrs, doublereal *cdrm, doublereal *
	cdrg, doublereal *ars, doublereal *amn, doublereal *ags, doublereal *
	xlks, doublereal *xlkm, doublereal *xlkg, char *uspec, char *umin, 
	char *ugas, integer *jsflag, integer *jmflag, integer *jgflag, 
	integer *nsb, integer *nsq, integer *nsq1, integer *nrst, integer *
	nst, integer *nmt, integer *ngt, integer *nxt, integer *ntpr, integer 
	*nsqmx1, integer *narxmx, integer *ntprmx, ftnlen uspec_len, ftnlen 
	umin_len, ftnlen ugas_len)
{
    /* Format strings */
    static char fmt_2005[] = "(//\002 ---listing of species and reactions "
	    "---\002,/)";
    static char fmt_2040[] = "(7x,\002temperature= \002,f10.3,\002 degrees c"
	    "elsius\002,/7x,\002pressure= \002,g13.6,\002 bars\002,/)";
    static char fmt_2007[] = "(8x,\002--- strict basis species ---\002,/)";
    static char fmt_2009[] = "(30x,a24)";
    static char fmt_2010[] = "(//8x,\002--- aqueous species dissociation rea"
	    "ctions ---\002,/)";
    static char fmt_2050[] = "(\002 ----------------------------------------"
	    "----------\002)";
    static char fmt_2060[] = "(/10x,\002log k= \002,f12.4,/)";
    static char fmt_2070[] = "(/3x,\002coefficients for range \002,i2,/3x,3("
	    "2x,g13.6),/3x,3(2x,g13.6),/)";
    static char fmt_2020[] = "(/8x,\002--- mineral dissolution reactions -"
	    "---\002,/)";
    static char fmt_2025[] = "(/8x,\002--- gas dissolution reactions ---\002"
	    ",/)";

    /* System generated locals */
    integer cdrs_dim1, cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, 
	    cdrg_offset, ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, 
	    amn_offset, ags_dim1, ags_dim2, ags_offset, i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, ng, nm, ns, nrs;
    extern /* Subroutine */ int prreac_(doublereal *, char *, char *, integer 
	    *, integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    static char unamsp[24];

    /* Fortran I/O blocks */
    static cilist io___166 = { 0, 0, 0, fmt_2005, 0 };
    static cilist io___167 = { 0, 0, 0, fmt_2040, 0 };
    static cilist io___168 = { 0, 0, 0, fmt_2007, 0 };
    static cilist io___170 = { 0, 0, 0, fmt_2009, 0 };
    static cilist io___171 = { 0, 0, 0, fmt_2010, 0 };
    static cilist io___173 = { 0, 0, 0, fmt_2050, 0 };
    static cilist io___175 = { 0, 0, 0, fmt_2060, 0 };
    static cilist io___177 = { 0, 0, 0, fmt_2070, 0 };
    static cilist io___179 = { 0, 0, 0, fmt_2050, 0 };
    static cilist io___180 = { 0, 0, 0, fmt_2020, 0 };
    static cilist io___182 = { 0, 0, 0, fmt_2050, 0 };
    static cilist io___183 = { 0, 0, 0, fmt_2060, 0 };
    static cilist io___184 = { 0, 0, 0, fmt_2070, 0 };
    static cilist io___185 = { 0, 0, 0, fmt_2050, 0 };
    static cilist io___186 = { 0, 0, 0, fmt_2025, 0 };
    static cilist io___188 = { 0, 0, 0, fmt_2050, 0 };
    static cilist io___189 = { 0, 0, 0, fmt_2060, 0 };
    static cilist io___190 = { 0, 0, 0, fmt_2070, 0 };
    static cilist io___191 = { 0, 0, 0, fmt_2050, 0 };



/*     this routine prints the species and reactions that are active */
/*     in the current problem, along with the log k values that */
/*     correspond to the reactions.  optionally, the coefficients */
/*     of the interpolating polynomials may also be printed. */

/*     input */
/*       ilevel = print level switch */
/*                  =  0  no print */
/*                  =  1  print species and reactions only */
/*                  =  2  also print equilibrium constants */
/*                  =  3  also print the coefficients of the */
/*                        interpolating polynomials */
/*       nf = unit number of the file to write on */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* -------------------------------------------------------------------- */

    /* Parameter adjustments */
    --xlks;
    --xlkm;
    --xlkg;
    uspec -= uspec_len;
    umin -= umin_len;
    ugas -= ugas_len;
    --jsflag;
    --jmflag;
    --jgflag;
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */
    if (*ilevel <= 0) {
	goto L999;
    }

    io___166.ciunit = *nf;
    s_wsfe(&io___166);
    e_wsfe();
    if (*ilevel >= 2) {
	io___167.ciunit = *nf;
	s_wsfe(&io___167);
	do_fio(&c__1, (char *)&(*tempc), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*press), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    io___168.ciunit = *nf;
    s_wsfe(&io___168);
    e_wsfe();

    i__1 = *nsb;
    for (ns = 1; ns <= i__1; ++ns) {
	if (jsflag[ns] <= 0) {
	    io___170.ciunit = *nf;
	    s_wsfe(&io___170);
	    do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
	    e_wsfe();
	}
/* L5: */
    }

    io___171.ciunit = *nf;
    s_wsfe(&io___171);
    e_wsfe();
    i__1 = *nrst;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	ns = nrs + *nsb;
	if (jsflag[ns] <= 0) {
	    io___173.ciunit = *nf;
	    s_wsfe(&io___173);
	    e_wsfe();
	    s_copy(unamsp, uspec + ns * uspec_len, (ftnlen)24, uspec_len);
	    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs, nsq, 
		    nsq1, nsqmx1, nf, uspec_len, (ftnlen)24);
	    if (*ilevel >= 2) {
		io___175.ciunit = *nf;
		s_wsfe(&io___175);
		do_fio(&c__1, (char *)&xlks[nrs], (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    if (*ilevel >= 3) {
		i__2 = *ntprmx;
		for (j = 1; j <= i__2; ++j) {
		    io___177.ciunit = *nf;
		    s_wsfe(&io___177);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			do_fio(&c__1, (char *)&ars[i__ + (j + nrs * ars_dim2) 
				* ars_dim1], (ftnlen)sizeof(doublereal));
		    }
		    e_wsfe();
/* L105: */
		}
	    }
	}
/* L15: */
    }
    io___179.ciunit = *nf;
    s_wsfe(&io___179);
    e_wsfe();

    io___180.ciunit = *nf;
    s_wsfe(&io___180);
    e_wsfe();
    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	if (jmflag[nm] <= 0) {
	    io___182.ciunit = *nf;
	    s_wsfe(&io___182);
	    e_wsfe();
	    s_copy(unamsp, umin + nm * umin_len, (ftnlen)24, umin_len);
	    prreac_(&cdrm[cdrm_offset], uspec + uspec_len, unamsp, &nm, nsq, 
		    nsq1, nsqmx1, nf, uspec_len, (ftnlen)24);
	    if (*ilevel >= 2) {
		io___183.ciunit = *nf;
		s_wsfe(&io___183);
		do_fio(&c__1, (char *)&xlkm[nm], (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    if (*ilevel >= 3) {
		i__2 = *ntprmx;
		for (j = 1; j <= i__2; ++j) {
		    io___184.ciunit = *nf;
		    s_wsfe(&io___184);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			do_fio(&c__1, (char *)&amn[i__ + (j + nm * amn_dim2) *
				 amn_dim1], (ftnlen)sizeof(doublereal));
		    }
		    e_wsfe();
/* L110: */
		}
	    }
	}
/* L20: */
    }
    io___185.ciunit = *nf;
    s_wsfe(&io___185);
    e_wsfe();

    io___186.ciunit = *nf;
    s_wsfe(&io___186);
    e_wsfe();
    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	if (jgflag[ng] <= 0) {
	    io___188.ciunit = *nf;
	    s_wsfe(&io___188);
	    e_wsfe();
	    s_copy(unamsp, ugas + ng * ugas_len, (ftnlen)24, ugas_len);
	    prreac_(&cdrg[cdrg_offset], uspec + uspec_len, unamsp, &ng, nsq, 
		    nsq1, nsqmx1, nf, uspec_len, (ftnlen)24);
	    if (*ilevel >= 2) {
		io___189.ciunit = *nf;
		s_wsfe(&io___189);
		do_fio(&c__1, (char *)&xlkg[ng], (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    if (*ilevel >= 3) {
		i__2 = *ntprmx;
		for (j = 1; j <= i__2; ++j) {
		    io___190.ciunit = *nf;
		    s_wsfe(&io___190);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			do_fio(&c__1, (char *)&ags[i__ + (j + ng * ags_dim2) *
				 ags_dim1], (ftnlen)sizeof(doublereal));
		    }
		    e_wsfe();
/* L115: */
		}
	    }
	}
/* L25: */
    }
    io___191.ciunit = *nf;
    s_wsfe(&io___191);
    e_wsfe();

L999:
    return 0;
} /* echolk_ */

/* elim    last revised 12/10/87 by tjw */
/* *elim f77 rewrite 12/08/87 by tjw */
/* Subroutine */ int elim_(integer *nse, doublereal *ars, doublereal *amn, 
	doublereal *ags, doublereal *cdrs, doublereal *cdrm, doublereal *cdrg,
	 doublereal *eps100, integer *nsb, integer *nsq1, integer *nrst, 
	integer *nmt, integer *ngt, integer *nsqmx1, integer *narxmx, integer 
	*ntprmx, integer *noutpt, integer *nttyo)
{
    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, cdrs_dim1, cdrs_offset, cdrm_dim1,
	     cdrm_offset, cdrg_dim1, cdrg_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, ng;
    static doublereal cx;
    static integer nm, nrs, nss, nrse;
    static doublereal stofac;


/*     this routine rewrites reaction equations so that the auxiliary */
/*     basis species with index nse and jflag = 30 is eliminated from */
/*     all reactions except the one linking it with its corresponding */
/*     strict basis variable.  the polynomial coefficients for computing */
/*     the equilibrium coefficients are recomputed accordingly. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */

    /* Parameter adjustments */
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */
    nrse = *nse - *nsb;
    cdrs[*nse + nrse * cdrs_dim1] = cdrs[*nsq1 + nrse * cdrs_dim1];
    cdrs[*nsq1 + nrse * cdrs_dim1] = 0.f;

    i__1 = *nrst;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	if (nrs == nrse) {
	    goto L120;
	}
	if (cdrs[*nse + nrs * cdrs_dim1] != 0.f) {
	    stofac = cdrs[*nse + nrs * cdrs_dim1] / cdrs[*nse + nrse * 
		    cdrs_dim1];
	    i__2 = *nsq1;
	    for (nss = 1; nss <= i__2; ++nss) {
		cx = cdrs[nss + nrs * cdrs_dim1] - stofac * cdrs[nss + nrse * 
			cdrs_dim1];
		if (abs(cx) <= *eps100) {
		    cx = 0.f;
		}
		cdrs[nss + nrs * cdrs_dim1] = cx;
/* L105: */
	    }
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		if (ars[(j + nrs * ars_dim2) * ars_dim1 + 1] <= 500.f) {
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			ars[i__ + (j + nrs * ars_dim2) * ars_dim1] -= stofac *
				 ars[i__ + (j + nrse * ars_dim2) * ars_dim1];
/* L110: */
		    }
		}
/* L115: */
	    }
	}
L120:
	;
    }

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	if (cdrm[*nse + nm * cdrm_dim1] != 0.f) {
	    stofac = cdrm[*nse + nm * cdrm_dim1] / cdrs[*nse + nrse * 
		    cdrs_dim1];
	    i__2 = *nsq1;
	    for (nss = 1; nss <= i__2; ++nss) {
		cx = cdrm[nss + nm * cdrm_dim1] - stofac * cdrs[nss + nrse * 
			cdrs_dim1];
		if (abs(cx) <= *eps100) {
		    cx = 0.f;
		}
		cdrm[nss + nm * cdrm_dim1] = cx;
/* L135: */
	    }
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		if (amn[(j + nm * amn_dim2) * amn_dim1 + 1] <= 500.f) {
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			amn[i__ + (j + nm * amn_dim2) * amn_dim1] -= stofac * 
				ars[i__ + (j + nrse * ars_dim2) * ars_dim1];
/* L140: */
		    }
		}
/* L145: */
	    }
	}
/* L150: */
    }

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	if (cdrg[*nse + ng * cdrg_dim1] != 0.f) {
	    stofac = cdrg[*nse + ng * cdrg_dim1] / cdrs[*nse + nrse * 
		    cdrs_dim1];
	    i__2 = *nsq1;
	    for (nss = 1; nss <= i__2; ++nss) {
		cx = cdrg[nss + ng * cdrg_dim1] - stofac * cdrs[nss + nrse * 
			cdrs_dim1];
		if (abs(cx) <= *eps100) {
		    cx = 0.f;
		}
		cdrg[nss + ng * cdrg_dim1] = cx;
/* L155: */
	    }
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		if (ags[(j + ng * ags_dim2) * ags_dim1 + 1] <= 500.f) {
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			ags[i__ + (j + ng * ags_dim2) * ags_dim1] -= stofac * 
				ars[i__ + (j + nrse * ars_dim2) * ars_dim1];
/* L160: */
		    }
		}
/* L165: */
	    }
	}
/* L170: */
    }

    cdrs[*nsq1 + nrse * cdrs_dim1] = cdrs[*nse + nrse * cdrs_dim1];
    cdrs[*nse + nrse * cdrs_dim1] = 0.f;

    return 0;
} /* elim_ */

/* elmdd    last revised 04/07/87 by tjw */
/* *elmdd f77 rewrite 04/07/87 by tjw */
/* Subroutine */ int elmdd_(doublereal *zi, doublereal *zj, doublereal *a, 
	doublereal *xi, integer *jopt, doublereal *el, doublereal *elp, 
	doublereal *elpp, integer *ier)
{
    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal c__, x, ck, ri, rj, xp, zp, rjp, sqi, sjp, xpp;
    extern /* Subroutine */ int hjdd_(doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *), pjdd_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal rjpp, sjpp;


/*     input */
/*       zi, zj  charges */
/*       a       a phi */
/*       xi      i */
/*       jopt     j option = 0/1  pitzer j / harvie j */

/*     output */
/*       el      e lambda (i,j) */
/*       elp        "           first derivative */
/*       elpp       "           second derivative */

/*     ier = 0/-1  ok/error in computing j function */

/*     note -   el = elp = elpp = 0 */
/*              if zi*zj .le. 0. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* ----------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
    *ier = 0;
    *el = 0.f;
    *elp = 0.f;
    *elpp = 0.f;

    zp = *zi * *zj;
    if (zp <= 0.f) {
	goto L999;
    }

    sqi = sqrt(*xi);
    c__ = zp * 3.f * *a;
    x = c__ * 2.f * sqi;

/*     compute x' and x'' */

    xp = c__ / sqi;
    xpp = -xp / (*xi * 2.f);

/*     get j, j', j'', functions of x */

    if (*jopt == 0) {

/*       pitzer j */

	pjdd_(&x, &rj, &rjp, &rjpp, ier);
    } else {

/*       harvie j */

	hjdd_(&x, &rj, &rjp, &rjpp, ier);
    }

    if (*ier == 0) {

/*       convert derivatives to same wrt i */

	sjp = rjp * xp;
	sjpp = rjp * xpp + rjpp * xp * xp;

	ck = zp / 4.f;
	ri = 1.f / *xi;

	*el = ri * ck * rj;
	*elp = ri * (ck * sjp - *el);
	*elpp = ri * (ck * sjpp - *elp * 2.f);

    }

L999:
    return 0;
} /* elmdd_ */

/* evdata  last revised 12/12/87 by tjw */
/* *evdata created in f77 12/09/87 by tjw */
/* Subroutine */ int evdata_(doublereal *tempc, doublereal *press, doublereal 
	*ars, doublereal *amn, doublereal *ags, doublereal *ac2, doublereal *
	awo, doublereal *apress, doublereal *aadh, doublereal *abdh, 
	doublereal *abdot, doublereal *aeh, doublereal *apx, doublereal *w, 
	doublereal *xlks, doublereal *xlkm, doublereal *xlkg, doublereal *
	cco2, doublereal *ch2o, doublereal *al10, doublereal *rconst, 
	doublereal *ehfac, doublereal *tempk, doublereal *pgrid, doublereal *
	adh, doublereal *bdh, doublereal *bdot, doublereal *xlkeh, doublereal 
	*aphi, doublereal *bt, char *uspec, char *usolx, integer *jsol, 
	integer *iopt1, integer *iopt4, integer *iopg1, integer *nrst, 
	integer *nst, integer *nmt, integer *ngt, integer *nxt, integer *ntpr,
	 integer *narxmx, integer *ntprmx, integer *iktmax, integer *iapxmx, 
	integer *noutpt, integer *nttyo, ftnlen uspec_len, ftnlen usolx_len)
{
    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, ac2_dim1, ac2_dim2, ac2_offset, 
	    awo_dim1, awo_dim2, awo_offset, apress_dim1, apress_offset, 
	    aadh_dim1, aadh_offset, abdh_dim1, abdh_offset, abdot_dim1, 
	    abdot_offset, aeh_dim1, aeh_offset, apx_dim1, apx_offset, w_dim1, 
	    w_offset;

    /* Local variables */
    static integer k;
    static doublereal prop;
    extern /* Subroutine */ int wterm_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen), 
	    evdatc_(doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, integer *), evdatk_(doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    evdatr_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), tmpcor_(doublereal *);


/*     this routine evaluates thermodynamic properties as a function */
/*     of temperature and pressure. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* -------------------------------------------------------------------- */

/*     compute the grid pressure */

    /* Parameter adjustments */
    --xlks;
    --xlkm;
    --xlkg;
    --cco2;
    --ch2o;
    uspec -= uspec_len;
    usolx -= usolx_len;
    --jsol;
    aeh_dim1 = *narxmx;
    aeh_offset = 1 + aeh_dim1;
    aeh -= aeh_offset;
    abdot_dim1 = *narxmx;
    abdot_offset = 1 + abdot_dim1;
    abdot -= abdot_offset;
    abdh_dim1 = *narxmx;
    abdh_offset = 1 + abdh_dim1;
    abdh -= abdh_offset;
    aadh_dim1 = *narxmx;
    aadh_offset = 1 + aadh_dim1;
    aadh -= aadh_offset;
    apress_dim1 = *narxmx;
    apress_offset = 1 + apress_dim1;
    apress -= apress_offset;
    awo_dim1 = *narxmx;
    awo_dim2 = *ntprmx;
    awo_offset = 1 + awo_dim1 * (1 + awo_dim2);
    awo -= awo_offset;
    ac2_dim1 = *narxmx;
    ac2_dim2 = *ntprmx;
    ac2_offset = 1 + ac2_dim1 * (1 + ac2_dim2);
    ac2 -= ac2_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;
    w_dim1 = *iktmax;
    w_offset = 1 + w_dim1;
    w -= w_offset;
    apx_dim1 = *iapxmx;
    apx_offset = 1 + apx_dim1;
    apx -= apx_offset;

    /* Function Body */
    evdatc_(pgrid, &apress[apress_offset], tempc, ntpr, narxmx, ntprmx);
    *press = *pgrid;

/*     compute the debye-huckel 'a' parameter */

    evdatc_(adh, &aadh[aadh_offset], tempc, ntpr, narxmx, ntprmx);
    *aphi = *adh * *al10 / 3.f;

/*     compute the debye-huckel 'b' parameter */

    evdatc_(bdh, &abdh[abdh_offset], tempc, ntpr, narxmx, ntprmx);
    *bt = *bdh * 1.2f / .3283f;

/*     note   0.3283 = b(25c) */

/*     if using pitzer's equations, set bt to the pitzer value */

    if (*iopg1 == 1) {
	*bt = 1.2f;
    }

/*     compute the helgeson bdot parameter */

    evdatc_(bdot, &abdot[abdot_offset], tempc, ntpr, narxmx, ntprmx);

/*     compute the polynomial coefficients for computing gamma */
/*     of co2(aq) as a function of ionic strength */

    for (k = 1; k <= 4; ++k) {
	evdatk_(&prop, &k, &ac2[ac2_offset], tempc, ntpr, narxmx, ntprmx);
	cco2[k] = prop;
/* L205: */
    }

/*     compute the polynomial coefficients for computing the activity */
/*     of water as a function of equivalent stoichiometric ionic */
/*     strength. */

    for (k = 1; k <= 4; ++k) {
	evdatk_(&prop, &k, &awo[awo_offset], tempc, ntpr, narxmx, ntprmx);
	ch2o[k] = prop;
/* L210: */
    }

/*     compute the log k for the 'eh' reaction */

    evdatc_(xlkeh, &aeh[aeh_offset], tempc, ntpr, narxmx, ntprmx);

/*     compute the log k values for aqueous dissocation reactions */
/*     and  mineral and gas dissolution reactions */

    evdatr_(tempc, tempk, press, pgrid, &ars[ars_offset], &amn[amn_offset], &
	    ags[ags_offset], &xlks[1], &xlkm[1], &xlkg[1], rconst, nrst, nst, 
	    nmt, ngt, nxt, ntpr, narxmx, ntprmx, noutpt, nttyo);

/*     do temperature correction of pitzer parameters */

    if (*iopg1 == 1) {
	tmpcor_(tempc);
    }

    if (*iopt4 >= 1) {
	wterm_(&apx[apx_offset], &w[w_offset], tempk, press, rconst, usolx + 
		usolx_len, iopt4, &jsol[1], nxt, iktmax, iapxmx, noutpt, 
		nttyo, usolx_len);
    }

    return 0;
} /* evdata_ */

/* evdatc  last revised 12/03/87 by tjw */
/* *evdatc created in f77 12/02/87 by tjw */
/* Subroutine */ int evdatc_(doublereal *prop, doublereal *arr, doublereal *
	tempc, integer *ntpr, integer *narxmx, integer *ntprmx)
{
    /* System generated locals */
    integer arr_dim1, arr_offset, i__1;

    /* Local variables */
    static integer i__, ii;


/*     this routine evaluates a thermodynamic property as a function of */
/*     temperature, using an interpolating polynomial whose coefficients */
/*     are stored in a two-dimensional array arr.  the second dimension */
/*     of this array corresponds to a temperature range.  this routine */
/*     this routine is identical to evdatk.f, except that in that */
/*     routine the array arr is three-dimensional and its calling sequence */
/*     contains an additional variable. */

/*     input */
/*       arr = two dimensional array of polynomial coefficients */
/*             describing some thermodynamic function */
/*       tempc = temperature, deg celsius */
/*       ntpr = temperature range flag */
/*       narxmx = first dimension of the arr array, the number */
/*                of coefficients per temperature range */
/*       ntprmx = second dimension of the arr array, the number */
/*                of temperature ranges. */

/*     output */
/*       prop = the calculated property */

/*     other */
/*       tempc1 = boundary between the first and second temperature */
/*                ranges */
/*       tempc2 = boundary between the second and third temperature */
/*                ranges */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     evaluate the polynomial */

    /* Parameter adjustments */
    arr_dim1 = *narxmx;
    arr_offset = 1 + arr_dim1;
    arr -= arr_offset;

    /* Function Body */
    *prop = 0.f;
    i__1 = *narxmx;
    for (ii = 1; ii <= i__1; ++ii) {
	i__ = *narxmx + 1 - ii;
	*prop = arr[i__ + *ntpr * arr_dim1] + *tempc * *prop;
/* L10: */
    }

    return 0;
} /* evdatc_ */

/* evdatk  last revised 12/03/87 by tjw */
/* *evdatk created in f77 12/02/87 by tjw */
/* Subroutine */ int evdatk_(doublereal *prop, integer *k, doublereal *arr, 
	doublereal *tempc, integer *ntpr, integer *narxmx, integer *ntprmx)
{
    /* System generated locals */
    integer arr_dim1, arr_dim2, arr_offset, i__1;

    /* Local variables */
    static integer i__, ii;


/*     this routine evaluates a thermodynamic property as a function of */
/*     temperature, using an interpolating polynomial whose coefficients */
/*     are stored in a two-dimensional array arr.  the second dimension */
/*     of this array corresponds to a temperature range.  this routine */
/*     this routine is identical to evdatk.c, except that in that */
/*     routine the array arr is two-dimensional and its calling sequence */
/*     does not contain the variabale k. */

/*     input */
/*       k = index for the third dimension of array arr */
/*       arr = two dimensional array of polynomial coefficients */
/*             describing some thermodynamic function */
/*       tempc = temperature, deg celsius */
/*       ntpr = temperature range flag */
/*       narxmx = first dimension of the arr array, the number */
/*                of coefficients per temperature range */
/*       ntprmx = second dimension of the arr array, the number */
/*                of temperature ranges. */

/*     output */
/*       prop = the calculated property */

/*     other */
/*       tempc1 = boundary between the first and second temperature */
/*                ranges */
/*       tempc2 = boundary between the second and third temperature */
/*                ranges */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     evaluate the polynomial */

    /* Parameter adjustments */
    arr_dim1 = *narxmx;
    arr_dim2 = *ntprmx;
    arr_offset = 1 + arr_dim1 * (1 + arr_dim2);
    arr -= arr_offset;

    /* Function Body */
    *prop = 0.f;
    i__1 = *narxmx;
    for (ii = 1; ii <= i__1; ++ii) {
	i__ = *narxmx + 1 - ii;
	*prop = arr[i__ + (*ntpr + *k * arr_dim2) * arr_dim1] + *tempc * *
		prop;
/* L10: */
    }

    return 0;
} /* evdatk_ */

/* evdatr  last revised 12/09/87 by tjw */
/* *evdatr created in f77 12/09/87 by tjw */
/* Subroutine */ int evdatr_(doublereal *tempc, doublereal *tempk, doublereal 
	*press, doublereal *pgrid, doublereal *ars, doublereal *amn, 
	doublereal *ags, doublereal *xlks, doublereal *xlkm, doublereal *xlkg,
	 doublereal *rconst, integer *nrst, integer *nst, integer *nmt, 
	integer *ngt, integer *nxt, integer *ntpr, integer *narxmx, integer *
	ntprmx, integer *noutpt, integer *nttyo)
{
    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, i__1;

    /* Local variables */
    static integer ng, nm, nrs;
    static doublereal prop;
    extern /* Subroutine */ int evdatk_(doublereal *, integer *, doublereal *,
	     doublereal *, integer *, integer *, integer *);


/*     this routine evaluates equilibrium constants as a function */
/*     of temperature and pressure.  note- pressure corrections off */
/*     the standard grid have not yet been incorporated. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */

/*     compute the log k values for aqueous dissocation reactions */

    /* Parameter adjustments */
    --xlks;
    --xlkm;
    --xlkg;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */
    i__1 = *nrst;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	evdatk_(&prop, &nrs, &ars[ars_offset], tempc, ntpr, narxmx, ntprmx);
	xlks[nrs] = prop;
/* L220: */
    }

/*     compute the log k values for mineral dissolution reactions */

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	evdatk_(&prop, &nm, &amn[amn_offset], tempc, ntpr, narxmx, ntprmx);
	xlkm[nm] = prop;
/* L230: */
    }

/*     compute the log k values for gas dissolution reactions */

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	evdatk_(&prop, &ng, &ags[ags_offset], tempc, ntpr, narxmx, ntprmx);
	xlkg[ng] = prop;
/* L250: */
    }

    return 0;
} /* evdatr_ */

/* fbassw   last revised 12/27/87 by tjw */
/* *fbassw f77 check, ok 04/08/87 by tjw */
/* Subroutine */ int fbassw_(integer *nse, integer *jsort, doublereal *weight,
	 doublereal *conc, integer *ibasis, integer *jflag, integer *nsb, 
	integer *nsq, integer *nst, integer *ise, doublereal *wse)
{
    /* Initialized data */

    static doublereal test = 100.;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal c0, c1, p0, p1;
    static logical q1;
    static doublereal w0, w1;
    static integer is, ns;
    static doublereal rat;
    static integer nsi, nss;


/*     this routine finds the optimal species for basis switching. */
/*     the function here is much like that of routine fdomsp, which */
/*     finds the species that dominates a mass balance.  however, */
/*     this routine takes into account basis switching rules, which */
/*     may sometimes not allow selection of the species which is the */
/*     largest contributor to a mass balance. */

/*     input */
/*       nse = aqueous species index that defines the balance */
/*       jsort = array of aqueous species indices in order of increasing */
/*         concentration */
/*       weight = stoichiometric weighting factor */
/*       conc = array of concentrations */
/*       (note - total = sum over ns of weight(ns) * conc(ns) ) */
/*       ibasis = array of aqueous species indices defining basis */
/*         switches */
/*       jflag = jflag array defining constraint types imposed on */
/*         aqueous species */
/*       nsb = index of last strict basis species */
/*       nsq = index of last auxiliary basis species */
/*       nst = number of aqeuous species */
/*     output */
/*       ise = index of the aqeuous species that would represent the */
/*         optimal basis switch */
/*       wse = weight(ise) */

/*     note - to save time, it is assumed that the ratio of the */
/*     largest value of weight to the smallest non-zero value is */
/*     no greater than 100. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


    /* Parameter adjustments */
    --jflag;
    --ibasis;
    --conc;
    --weight;
    --jsort;

    /* Function Body */

/* ---------------------------------------------------------------------- */

/*     notes on restrictions on candidates for basis switching- */
/*       a species which is currently in the master set (even if */
/*       it has been switched in) can not be a candidate.  the variable */
/*       q1 = .true. if ns is in the master set.  furthermore, a species */
/*       is ineligible for consideration if it is already involved */
/*       in a basis switch.  each current switch involves a pair o */
/*       species, one of which is in the current master set and hence */
/*       has already been eliminated from consideration by the q1 test. */
/*       the other will be a data file master species that has been */
/*       switched out of the active master set.  a species currently */
/*       involved in a switch can be identified by the condition that */
/*       ibasis(ns) is not ns.  there is one execption to this.  if */
/*       a switch has already occurred, the code should be able to */
/*       switch back in the data file master species.  if ns is such */
/*       a species, then ibasis(ns) will be nse. */

    c0 = 0.f;
    w0 = 1.f;
    p0 = 0.f;
    *ise = 0;
    i__1 = *nst;
    for (nsi = 1; nsi <= i__1; ++nsi) {
	nss = *nst + 1 - nsi;
	ns = jsort[nss];
	w1 = weight[ns];
	c1 = conc[ns];
	if (w1 != 0.f) {
	    q1 = ns > *nsq;
	    if (! q1) {
		q1 = jflag[ns] == 30;
	    }
	    if (q1) {
		is = ibasis[ns];
		if (is == ns || is == *nse) {
		    p1 = w1 * c1;
		    if (p1 > p0) {
			c0 = c1;
			w0 = w1;
			p0 = p1;
			*ise = ns;
			goto L15;
		    }
		}
	    }
	}
	if (c1 <= eqleps_1.smp100) {
	    if (ns > 1) {
		goto L20;
	    }
	} else {
	    rat = c0 / c1;
	    if (rat > test) {
		goto L20;
	    }
	}
L15:
	;
    }

L20:
    *wse = w0;
    return 0;
} /* fbassw_ */

/* fcopya   last revised 04/10/87 by tjw */
/* *fcopya f77 check, ok 04/10/87 by tjw */
/* Subroutine */ int fcopya_(integer *nf1, integer *nf2)
{
    /* Format strings */
    static char fmt_1000[] = "(a128)";

    /* System generated locals */
    integer i__1;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer j;
    static char uline[128];

    /* Fortran I/O blocks */
    static cilist io___238 = { 0, 0, 1, fmt_1000, 0 };
    static cilist io___240 = { 0, 0, 0, fmt_1000, 0 };



/*     this routine appends the contents of the file whose unit */
/*     number is nf1 to the file whose unit number is nf2.  line */
/*     length is assumed to be 128 characters. */

/*     input */
/*       nf1 = unit number of the first file. */
/*       nf2 = unit number of the second file.  it must already be */
/*         open and correctly positioned. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    al__1.aerr = 0;
    al__1.aunit = *nf1;
    f_rew(&al__1);
    for (j = 1; j <= 10000; ++j) {
	io___238.ciunit = *nf1;
	i__1 = s_rsfe(&io___238);
	if (i__1 != 0) {
	    goto L20;
	}
	i__1 = do_fio(&c__1, uline, (ftnlen)128);
	if (i__1 != 0) {
	    goto L20;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L20;
	}
	io___240.ciunit = *nf2;
	s_wsfe(&io___240);
	do_fio(&c__1, uline, (ftnlen)128);
	e_wsfe();
/* L1005: */
/* L10: */
    }
L20:
    return 0;
} /* fcopya_ */

/* fdd      last revised 11/02/87 by tjw */
/* *fdd f77 rewrite 04/10/87 by tjw */
/* Subroutine */ int fdd_(doublereal *xi, doublereal *a, doublereal *b, 
	integer *iocflg, doublereal *f, doublereal *fp, doublereal *fpp, 
	doublereal *fgam, doublereal *fphi, integer *ier)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), log(doublereal);

    /* Local variables */
    static doublereal v, fc, vp1, fcp, sqi, fcpp, alvp1, vp1sq, fconst;


/*     input xi, a, b values, */
/*           iocflg   0/1  f(dho) / f(dhc) */

/*     compute f */
/*             fp  = f' */
/*             fpp = f'' */
/*             fgam = f'/2 */
/*             fphi = (f' - f/xi) / 2 */

/*     ier = 0/-1  ok/xi is .lt. zero */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* ----------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
    if (*xi >= 0.f) {
	*ier = 0;
    } else {
	*ier = -1;
	goto L999;
    }

    sqi = sqrt(*xi);
    v = *b * sqi;
    vp1 = v + 1.f;
    vp1sq = vp1 * vp1;
    alvp1 = log(vp1);
    if (*iocflg <= 0) {

/*       f(dho) here */

	fconst = *a * -4.f / *b;
	*f = fconst * *xi * alvp1;
	*fp = fconst * (v / (vp1 * 2.f) + alvp1);
	*fpp = -(*a) / sqi * ((vp1 * 2.f + 1.f) / vp1sq);

    } else {

/*       f(dhc) here */

	fcp = *a * -6.f;
/* Computing 3rd power */
	d__1 = *b;
	fc = fcp / (d__1 * (d__1 * d__1));
	fcpp = *a * -3.f;

	*f = fc * (v * (v - 2.f) + alvp1 * 2.f);
	*fp = fcp * sqi / vp1;
	*fpp = fcpp / (sqi * vp1sq);

    }

    *fgam = *fp / 2.f;
    *fphi = (*fp - *f / *xi) / 2.f;

L999:
    return 0;
} /* fdd_ */

/* fdomsp   last revised 12/27/87 by tjw */
/* *fdomsp f77 check, ok 04/10/87 by tjw */
/* Subroutine */ int fdomsp_(integer *nse, integer *jsort, doublereal *weight,
	 doublereal *conc, integer *nst, integer *ise, doublereal *wse)
{
    /* Initialized data */

    static doublereal test = 100.;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal c0, c1, p0, p1, w0, w1;
    static integer ns;
    static doublereal rat;
    static integer nsi, nss;


/*     this routine finds the species that dominates a mass balance. */
/*     it is very similar in function to routine fbassw, which finds */
/*     the optimal species for a basis switch.  certain rules govern */
/*     basis switching which may not allow the dominant species to */
/*     be chosen for a basis switch. */

/*     input */
/*       nse = aqueous species index that defines the balance */
/*       jsort = array of aqueous species indices in order of increasing */
/*         concentration */
/*       weight = stoichiometric weighting factor */
/*       conc = array of concentrations */
/*       nst = number of aqueous species */
/*       (note - total = sum over ns of weight(ns) * conc(ns) ) */
/*     output */
/*       ise = index of the dominant aqeuous species */
/*       wse = weight(ise) */

/*     note - to save time, it is assumed that the ratio of the */
/*     largest value of weight to the smallest non-zero value is */
/*     no greater than 100. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


    /* Parameter adjustments */
    --conc;
    --weight;
    --jsort;

    /* Function Body */

/* ----------------------------------------------------------------------- */

    c0 = 0.f;
    w0 = 1.f;
    p0 = 0.f;
    *ise = 0;
    i__1 = *nst;
    for (nsi = 1; nsi <= i__1; ++nsi) {
	nss = *nst + 1 - nsi;
	ns = jsort[nss];
	w1 = weight[ns];
	c1 = conc[ns];
	if (w1 != 0.f) {
	    p1 = w1 * c1;
	    if (p1 > p0) {
		c0 = c1;
		w0 = w1;
		p0 = p1;
		*ise = ns;
		goto L15;
	    }
	}
	if (c1 <= eqleps_1.smp100) {
	    if (ns > 1) {
		goto L20;
	    }
	} else {
	    rat = c0 / c1;
	    if (rat > test) {
		goto L20;
	    }
	}
L15:
	;
    }

L20:
    *wse = w0;
    return 0;
} /* fdomsp_ */

/* flen     last revised 04/10/87 by tjw */
/* *flen f77 rewrite 04/10/87 by tjw */
/* Subroutine */ int flen_(char *ust, integer *nch, integer *len, ftnlen 
	ust_len)
{
    /* Initialized data */

    static char ublank[8] = "        ";
    static char umark[8] = "$       ";

    static integer k;


/*     find the length of a string */

/*     input  ust  ascii string */
/*            nch  number of characters allowed in ust */
/*                  (maximum of 80) */
/*     output len  length of ust up to last non-blank character */

/*     ust may be right-delimited by $ */
/*      if so, length is from the first character to but not */
/*             including the $. */
/*      else,  length is from the first character to and including */
/*             the right-most non-blank. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* ----------------------------------------------------------------------- */
/* impliciti.h */
/*   standard implicit statement for eq3/6 routines not requiring */
/*   floating point variables */


/* ----------------------------------------------------------------------- */

/*     find number of trailing blanks */

    for (k = *nch; k >= 1; --k) {
	if (*(unsigned char *)&ust[k - 1] != *(unsigned char *)&ublank[0]) {
	    goto L15;
	}
/* L10: */
    }

/*     all blank */

    *len = 0;
    goto L999;

L15:
    if (*(unsigned char *)&ust[k - 1] == *(unsigned char *)&umark[0]) {
	--k;
    }
    *len = k;

L999:
    return 0;
} /* flen_ */

/* flpars   last revised 11/18/87 by tjw */
/* *flpars f77 check, ok 04/10/87 by tjw */
/* Subroutine */ int flpars_(void)
{
    /* Initialized data */

    static integer i1 = 1;
    static integer j1 = 1;

    /* Format strings */
    static char fmt_100[] = "(\002 * error - machine epsilon .le. smallest p"
	    "ositive \002,\002number\002,/7x,\002eps = \002,e12.5,\002, smpos"
	    " = \002,e12.5,/5x,\002the compiler is too clever (eqlib/flpar"
	    "s\002)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer pow_ii(integer *, integer *), s_wsfe(cilist *), do_fio(integer *, 
	    char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double d_lg10(doublereal *), log(doublereal);
    integer i_nint(real *);
    double exp(doublereal);

    /* Local variables */
    static integer i__, j, n, n1;
    static doublereal x10, efac;
    static integer idiv, idum;
    static doublereal enum__, snum, etest;

    /* Fortran I/O blocks */
    static cilist io___274 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___275 = { 0, 0, 0, fmt_100, 0 };



/*     this routines calculates */
/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */
/* eqlpp.h */
/* -------------------------------------------------------------------- */
/* eqltxp.h */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/*     set loop parameters.  setting n=31 would be more efficient, */
/*     but does not work because 2**31 is returned as a negative */
/*     number (at least on a ridge 32 computer). */

    n = 30;
    n1 = n + 1;

/*     find eps */

    enum__ = 1.f;
    eqleps_1.eps = enum__;
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = n1 - i__;
	idiv = pow_ii(&c__2, &i__2);
	for (j = 1; j <= 100; ++j) {
	    enum__ /= idiv;
	    etest = i1 + enum__;
	    etest -= j1;
	    if (etest > 0.f) {
		eqleps_1.eps = enum__;
		goto L5;
	    } else {
		enum__ = eqleps_1.eps;
		goto L10;
	    }
L5:
	    ;
	}
L10:
	;
    }

/*     find smpos */

    snum = eqleps_1.eps;
    eqleps_1.smpos = snum;
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = n1 - i__;
	idiv = pow_ii(&c__2, &i__2);
	for (j = 1; j <= 100; ++j) {
	    snum /= idiv;
	    if (snum > 0.f) {
		eqleps_1.smpos = snum;
		goto L15;
	    } else {
		snum = eqleps_1.smpos;
		goto L20;
	    }
L15:
	    ;
	}
L20:
	;
    }

    if (eqleps_1.eps <= eqleps_1.smpos) {
	io___274.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___274);
	do_fio(&c__1, (char *)&eqleps_1.eps, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&eqleps_1.smpos, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___275.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___275);
	do_fio(&c__1, (char *)&eqleps_1.eps, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&eqleps_1.smpos, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    eqleps_1.eps10 = eqleps_1.eps * 10;
    eqleps_1.eps100 = eqleps_1.eps * 100;
    eqleps_1.smp10 = eqleps_1.smpos * 10;
    eqleps_1.smp100 = eqleps_1.smpos * 100;

/*     calculate the exponent range */

    eqleps_1.irang = (integer) (-d_lg10(&eqleps_1.smpos));

/*     calculate natural log of 10. */

    x10 = 10.f;
    eqlpp_1.al10 = log(x10);

/*     calculate parameters required for routine texp */

    eqltxp_1.xltxp = (doublereal) (-eqleps_1.irang);
    eqltxp_1.xutxp = (doublereal) eqleps_1.irang;
    r__1 = eqleps_1.irang * .9f;
    idum = i_nint(&r__1);
    idum = min(300,idum);
    efac = eqlpp_1.al10 * idum;
    eqltxp_1.yutxp = exp(efac);

    return 0;
} /* flpars_ */

/* gabar    last revised 10/30/87 by tjw */
/* *gabar f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gabar_(doublereal *sigmam, doublereal *conc, integer *
	jsort, integer *nst, doublereal *azero, doublereal *abar)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns;
    static doublereal sma;
    static integer nss;


/*     this routine calculates a compositionally averaged ion size */
/*     parameter (abar).  note that a sorted summation is used. */

/*       input */
/*         sigmam      sum(mi) */
/*         conc    array of concentrations  mi */
/*         jsort   array of aqueous species indices, in order of */
/*                 increasing concentration */
/*         nst     number of elements in array */
/*         azero   array of ion size parameters */

/*       output */
/*         abar    sum(mi*ai)/sum(mi) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --azero;
    --jsort;
    --conc;

    /* Function Body */
    sma = 0.f;
    *abar = 0.f;

/*     note - this calculation presumes that either conc(1) or */
/*     azero(1) is zero, so that there is no contribution from */
/*     the solvent. */

    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = jsort[nss];
	sma += conc[ns] * azero[ns];
/* L10: */
    }
    *abar = sma / *sigmam;

    return 0;
} /* gabar_ */

/* gabswx  last revised 10/16/87 by tjw */
/* *gabswx f77 check, ok 07/01/87 by tjw */
/* Subroutine */ int gabswx_(doublereal *beta, integer *ksq, integer *ibswx)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer isj;
    static doublereal bbig;
    static integer kbig;
    static doublereal frac;
    static integer kcol, isej, klim, krow, ksqm1;


/*     this routine supports automatic basis switching as a means of */
/*     optimization prior to newton-raphson iteration by resolving */
/*     conflicts in the ibswx array.  this array could call for a */
/*     given aqueous species to be switched with more than one master */
/*     species.  the approach here is to use the size of the associated */
/*     residual (beta) to resolve conflicts.  this routine is therefore */
/*     somewhat similar to routine gbfac, which resolves conflicts */
/*     affecting continued fraction calculations. */

/*     input */
/*       ibswx = array of indices of non-master species that are */
/*         candidates for basis switching */
/*       beta = array of mass balance residuals */
/*       ksq = matrix index of last auxiliary basis species */
/*     output */
/*       ibswx = input array modified to remove conflicts. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/* ---------------------------------------------------------------------- */

/*     find the largest residual among potential basis switching cases */

    /* Parameter adjustments */
    --ibswx;
    --beta;

    /* Function Body */
    kbig = 0;
    bbig = 0.f;
    i__1 = *ksq;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	if (ibswx[kcol] > 0) {
	    if (beta[kcol] > bbig) {
		kbig = kcol;
		bbig = beta[kcol];
	    }
	}
/* L5: */
    }

/*     do basis switching only for the cases of the largest residuals */

    if (bbig > eqleps_1.eps100) {
	i__1 = *ksq;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    if (ibswx[kcol] > 0) {
		frac = beta[kcol] / bbig;
		if (frac <= .01f) {
		    ibswx[kcol] = 0;
		}
	    }
/* L7: */
	}
    }

    ksqm1 = *ksq - 1;
    i__1 = ksqm1;
    for (krow = 2; krow <= i__1; ++krow) {
	isej = ibswx[krow];
	if (isej > 0) {
	    klim = krow + 1;
	    i__2 = *ksq;
	    for (kcol = klim; kcol <= i__2; ++kcol) {
		isj = ibswx[kcol];
		if (isj == isej) {
		    if (beta[krow] > beta[kcol]) {
			ibswx[kcol] = 0;
		    } else {
			ibswx[krow] = 0;
			goto L15;
		    }
		}
/* L10: */
	    }
	}
L15:
	;
    }

    return 0;
} /* gabswx_ */

/* gafscl   last revised 12/17/87 by tjw */
/* *gafscl created in f77  12/17/87 by tjw */
/* Subroutine */ int gafscl_(doublereal *cdrm, doublereal *cscale, integer *
	nsq, integer *nmt, integer *nsqmx1)
{
    /* System generated locals */
    integer cdrm_dim1, cdrm_offset, i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer nm;
    static doublereal cx;
    static integer ns;


/*     compute the cscale array of affinity scaling factors. */
/*     affinity scaling is used to help choose which one of a set */
/*     of supersaturated phases is the best choice to precipitate. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --cscale;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;

    /* Function Body */
    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	cx = 0.f;
	i__2 = *nsq;
	for (ns = 1; ns <= i__2; ++ns) {
	    cx += (d__1 = cdrm[ns + nm * cdrm_dim1], abs(d__1));
/* L100: */
	}
	cscale[nm] = cx;
/* L105: */
    }

    return 0;
} /* gafscl_ */

/* gbdot    last revised 11/02/87 by tjw */
/* *gbdot created in  f77  10/18/87 by tjw */
/* Subroutine */ int gbdot_(integer *iacion, integer *iopg5, integer *nst, 
	doublereal *xi, doublereal *xisteq, doublereal *z__, doublereal *zsq2,
	 doublereal *azero, doublereal *glgc, doublereal *sigmam, integer *
	iopg7, doublereal *concbs, integer *nsq, integer *iopg9)
{

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), log(doublereal), d_lg10(doublereal *), pow_dd(
	    doublereal *, doublereal *);

    /* Local variables */
    static doublereal az;
    static integer ns;
    static doublereal zz, art, brt, xco2, xh2o, epmix, glgco2, bdotxi, xisqrt;


/*     this routine computes activity coefficients of aqueous */
/*     species using the 'bdot equation plus others' model.  the activity */
/*     coefficient of charged species is calculated using an extended */
/*     debye-huckel approximation due to helgeson (1969).  the activity of */
/*     water and the activity coefficient of dissolved co2 (whose value is */
/*     assigned to the activity coefficients of neutral nonpolar species) */
/*     are special cases.  the equations for these are not actually */
/*     consistent with the bdot equation, but the numerical results may be */
/*     a reasonable approximation in dilute solutions. */
/*     all activity coefficients are in logarithmic form. */

/*      input  iacion  index of na+ or cl- */
/*             iopg5   option switch to replace the polynomial */
/*                     for the activity coefficient of aqeuous co2 */
/*                     by a bdot term */
/*             nst     number of aqueous species in model */
/*             xi      ionic strength */
/*             xisteq  equiv. stoich. ionic strength */
/*             z       array of charges */
/*             zsq2    array of one-half the charge squared */
/*             azero   array of d-h ion size parameters */

/*      output glgc    array of molal activity coefficients */
/*          note- glgc(1) contains the activity of water */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlej.h */
/* -------------------------------------------------------------------- */
/* eqlpp.h */


/* -------------------------------------------------------------------- */
/* eqlun.h */

    /* Parameter adjustments */
    --concbs;
    --glgc;
    --azero;
    --zsq2;
    --z__;

    /* Function Body */

/* ---------------------------------------------------------------------- */

/*     log(aw) */

    glgc[1] = 0.f;
    if (*iacion > 0) {
/* Computing 3rd power */
	d__1 = eqlej_1.ch2o[0];
	eqlej_1.dterm = eqlpp_1.al10 * eqldd_1.adh / (*xisteq * (d__1 * (d__1 
		* d__1)));
	eqlej_1.bterm = eqlej_1.ch2o[0] * sqrt(*xisteq) + 1.f;
	eqlej_1.xjterm = eqlej_1.bterm - log(eqlej_1.bterm) * 2.f - 1.f / 
		eqlej_1.bterm;
/* Computing 2nd power */
	d__1 = *xisteq;
	eqlej_1.oscoff = 1.f - eqlej_1.dterm * eqlej_1.xjterm + eqlej_1.ch2o[
		1] * *xisteq + eqlej_1.ch2o[2] * (d__1 * d__1);
/* Computing 3rd power */
	d__1 = *xisteq;
	eqlej_1.oscoff += eqlej_1.ch2o[3] * (d__1 * (d__1 * d__1));
/*        glgc(1)=-2.*xisteq*oscoff/(al10*om) */
    }
    if (*iopg7 > 0) {
	d__1 = 55.51f / (*sigmam + 55.51f);
	glgc[1] = d_lg10(&d__1);
    }

/*     note- the formula below tends to blow up in concentrated */
/*     solutions.  setting iopg5=1 replaces it by a more stable */
/*     expression. */

    if (*iopg5 <= 0) {
	xco2 = concbs[*iopg9] / (concbs[*iopg9] + 55.55f);
	xh2o = 1.f - xco2;
	epmix = xco2 * pow_dd(&eqlej_1.cco2[1], &c_b365) + xh2o * pow_dd(&
		eqlej_1.cco2[2], &c_b365);
/* Computing 3rd power */
	d__1 = epmix;
	epmix = d__1 * (d__1 * d__1);
	glgco2 = eqlej_1.cco2[0] * (1.f / epmix - 1.f / eqlej_1.cco2[2]) + 
		eqlej_1.cco2[3] * xco2;
	d__1 = *sigmam * .0180153f + 1.f;
	glgco2 -= d_lg10(&d__1);
    } else if (*iopg5 == 1) {
	glgco2 = eqldd_1.bdot * *xi;
    } else {
	d__1 = *sigmam * .0180153f + 1.f;
	glgco2 = eqlej_1.cco2[0] - d_lg10(&d__1);
    }

/*     log(gi) calc here, b dot equations */

    xisqrt = sqrt(*xi);
    art = eqldd_1.adh * 2 * xisqrt;
    brt = eqldd_1.bdh * xisqrt;

    bdotxi = eqldd_1.bdot * *xi;
    i__1 = *nst;
    for (ns = 2; ns <= i__1; ++ns) {
	zz = z__[ns];
	az = azero[ns];
	if (zz != 0.f) {
	    glgc[ns] = -(art * zsq2[ns] / (brt * az + 1.f)) + bdotxi;
	} else {

/*       note- nonpolar neutral solute species are marked on the data */
/*       file by a negative value of the 'ion size' */

	    if (az >= 0.f) {

/*         for polar neutral solutes */

		glgc[ns] = 0.f;
	    } else {

/*         for nonpolar neutral solutes */

		glgc[ns] = glgco2;
	    }
	}
/* L30: */
    }

/* L999: */
    return 0;
} /* gbdot_ */

/* gbfac   last revised 12/27/87 by tjw */
/* *gbfac f77 check, ok 07/01/87 by tjw */
/* Subroutine */ int gbfac_(integer *nfac, doublereal *beta, doublereal *efac,
	 integer *ksq, doublereal *bfac)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer kcol, klim, krow, ksqm1;


/*     this routine gets the bfac array, which is used in making */
/*     continued fraction corrections.  it resolves conflicts when the */
/*     same aqueous species dominates more than one mass balance (the */
/*     species dominating a given mass balance is determined by routine */
/*     fdomsp).  the continued fraction algorithm can be applied */
/*     to the master species associated with only one mass balance in */
/*     such a set, otherwise, oscillatory behavior will occur. */
/*     in each set of mass balances with a common dominant species, */
/*     this routine finds the mass balance with the greatest residual and */
/*     completes the calculation of its bfac factor by doing the */
/*     appropriate exponentiation.  it sets bfac to unity for the others */
/*     in the set. */

/*     input */
/*       nfac = array of indices of dominant aqueous species */
/*       beta = array of mass balance residuals */
/*       efac = array of corresponding reciprocal stoichiometric weights */
/*       ksq = matrix index of last auxiliary basis species */
/*     output */
/*       bfac = array (in terms of matrix indexing) of the quantity */
/*         used in making a continued fraction correction */
/*         ( e.g., conc (new) = conc (old) / bfac ).  in the absence of */
/*         a conflict, bfac = ( beta + 1. )**efac. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --bfac;
    --efac;
    --beta;
    --nfac;

    /* Function Body */
    i__1 = *ksq;
    for (krow = 1; krow <= i__1; ++krow) {
	bfac[krow] = beta[krow] + 1.f;
/* L5: */
    }

    ksqm1 = *ksq - 1;
    i__1 = ksqm1;
    for (krow = 1; krow <= i__1; ++krow) {
	if (nfac[krow] > 0) {
	    klim = krow + 1;
	    i__2 = *ksq;
	    for (kcol = klim; kcol <= i__2; ++kcol) {
		if (nfac[kcol] == nfac[krow]) {
		    if (bfac[krow] > bfac[kcol]) {
			nfac[kcol] = 0;
		    } else {
			nfac[krow] = 0;
			goto L15;
		    }
		}
/* L10: */
	    }
	}
L15:
	;
    }

    i__1 = *ksq;
    for (krow = 1; krow <= i__1; ++krow) {
	if (nfac[krow] > 0) {
	    bfac[krow] = pow_dd(&bfac[krow], &efac[krow]);
	} else {
	    bfac[krow] = 1.f;
	}
/* L20: */
    }

    return 0;
} /* gbfac_ */

/* gcdrst   last revised 12/22/87 by tjw */
/* *gcdrst created in f77  12/16/87 by tjw */
/* Subroutine */ int gcdrst_(doublereal *cdrs, doublereal *cdrm, doublereal *
	cdrg, doublereal *cdrst, doublereal *cdrmt, doublereal *cdrgt, 
	integer *nsb, integer *nsq, integer *nsq1, integer *nrst, integer *
	nmt, integer *ngt, integer *nsqmx1)
{
    /* System generated locals */
    integer cdrs_dim1, cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, 
	    cdrg_offset, i__1, i__2;

    /* Local variables */
    static integer ng;
    static doublereal cx;
    static integer nm, ns, nrs;


/*     this routine computes the cdrst, cdrmt, and cdrgt arrays. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     programming note - if ns .eq. nsb in the following do loops */
/*     there should be no contribution to the sum accumulated in the */
/*     variable cx.  the contribution is effectively subtracted before */
/*     each do loop in order to avoid an if test inside the loop. */

    /* Parameter adjustments */
    --cdrst;
    --cdrmt;
    --cdrgt;
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;

    /* Function Body */
    i__1 = *nrst;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	cx = -cdrs[*nsb + nrs * cdrs_dim1];
	i__2 = *nsq1;
	for (ns = 2; ns <= i__2; ++ns) {
	    cx += cdrs[ns + nrs * cdrs_dim1];
/* L100: */
	}
	cdrst[nrs] = cx;
/* L105: */
    }

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	cx = -cdrm[*nsb + nm * cdrm_dim1];
	i__2 = *nsq;
	for (ns = 2; ns <= i__2; ++ns) {
	    cx += cdrm[ns + nm * cdrm_dim1];
/* L110: */
	}
	cdrmt[nm] = cx;
/* L115: */
    }

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	cx = -cdrg[*nsb + ng * cdrg_dim1];
	i__2 = *nsq;
	for (ns = 2; ns <= i__2; ++ns) {
	    cx += cdrg[ns + ng * cdrg_dim1];
/* L120: */
	}
	cdrgt[ng] = cx;
/* L125: */
    }

    return 0;
} /* gcdrst_ */

/* gcoeff   last revised 11/25/87 by tjw */
/* *gcoeff f77 rewrite, 07/01/87 by tjw */
/* Subroutine */ int gcoeff_(doublereal *conc, doublereal *z__, doublereal *
	zsq2, doublereal *azero, doublereal *hydn, doublereal *concbs, 
	doublereal *glgc, doublereal *xi, doublereal *xisteq, doublereal *
	dshm, doublereal *tempc, doublereal *press, integer *jsflag, integer *
	jsort, integer *iacion, integer *nsb, integer *nst, integer *nsq, 
	integer *nhydr, integer *nchlor)
{
    /* Format strings */
    static char fmt_205[] = "(\002 * error- bad activity coefficient option "
	    "encountered\002,\002 (eqlib/gcoeff)\002)";
    static char fmt_1011[] = "(\002 * error - error, bad fdd call (eqlib/gco"
	    "eff)\002)";
    static char fmt_1010[] = "(\002 * error - error, bad fdd call (eqlib/gco"
	    "eff)\002)";
    static char fmt_2000[] = "(\002 xi,xistoc,sigmam,sum1,hkfaz,caplam,cap"
	    "gam\002)";
    static char fmt_2001[] = "(7(1x,g13.5))";
    static char fmt_2002[] = "(\002 ns,conc,concbs \002)";
    static char fmt_2003[] = "(1x,i3,2(1x,g13.5))";
    static char fmt_2005[] = "(\002 hypothetical salt solution \002,/,\002 c"
	    "at    an    catsf   ansf       mol. salt\002)";
    static char fmt_2006[] = "(4(5x,i5),5x,g13.5)";
    static char fmt_2007[] = "(\002 major loop in gcoeff - a.c. and logaw"
	    " \002,/,\002 ns     z      anum     omega    sum2  \002,\002 par"
	    "tb    glgc   sltsum   third    osmsum\002)";
    static char fmt_2008[] = "(1x,i3,6(1x,g10.4),\002*\002,3(1x,g10.4))";
    static char fmt_9000[] = "(\002osmcof,glgc(1) = \002,2(x,e13.5))";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double log(doublereal);
    integer i_dnnt(doublereal *), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static doublereal b, f;
    static integer i__;
    static doublereal bb, fg;
    static integer ii, jj;
    static doublereal fp;
    static integer ns, iz, nu;
    static doublereal xx, zz;
    extern /* Subroutine */ int fdd_(doublereal *, doublereal *, doublereal *,
	     integer *, doublereal *, doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *);
    static doublereal alm;
    static logical qck;
    static integer ier;
    static doublereal dum, fpp;
    extern doublereal tlg_(doublereal *);
    static doublereal fqt, dum3, sum1, sum2, abar, fphi, lnaw, anum;
    static integer ierr;
    static doublereal esum, zdum, ssum, znum;
    extern /* Subroutine */ int azpt4_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), gabar_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *);
    static doublereal acube;
    extern /* Subroutine */ int gelam_(doublereal *, doublereal *, integer *, 
	    integer *, integer *, doublereal *), gbdot_(integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, doublereal *
	    , integer *, integer *);
    static doublereal sigma;
    extern /* Subroutine */ int gslam_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *), gsigm_(doublereal *, integer *, integer 
	    *, doublereal *), gselm_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *)
	    ;
    static doublereal aterm;
    extern /* Subroutine */ int gsdsm_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), gmdsm_(integer *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *), 
	    gesum_(doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), gsgsm_(
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    static doublereal elsum, lamtm, partb;
    extern /* Subroutine */ int gmsum_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *), kisum_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *);
    static doublereal third;
    extern /* Subroutine */ int gssum_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal slsum, xitmp, musum;
    extern /* Subroutine */ int omega4_(integer *, doublereal *, doublereal *,
	     integer *);
    static integer nttyo;
    static doublereal capgam;
    extern /* Subroutine */ int gcscal_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);
    static doublereal caplam, delglg, aldshm, lnacti;
    extern /* Subroutine */ int nbsgam_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal sigmam, factor, osmgam, salmol, omegns, osmcof, glgnbs, 
	    dshmsq;
    extern /* Subroutine */ int kilsum_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal elpsum;
    extern /* Subroutine */ int molslt_(doublereal *, doublereal *, integer *)
	    ;
    static doublereal xistoc;
    extern /* Subroutine */ int gxisto_(doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *);
    static doublereal slpsum, osmsum, sltsum, xisqrt;

    /* Fortran I/O blocks */
    static cilist io___319 = { 0, 0, 0, fmt_205, 0 };
    static cilist io___320 = { 0, 0, 0, fmt_205, 0 };
    static cilist io___332 = { 0, 0, 0, fmt_1011, 0 };
    static cilist io___334 = { 0, 0, 0, fmt_1011, 0 };
    static cilist io___345 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___346 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___366 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___367 = { 0, 0, 0, fmt_2001, 0 };
    static cilist io___368 = { 0, 0, 0, fmt_2002, 0 };
    static cilist io___370 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___371 = { 0, 0, 0, fmt_2005, 0 };
    static cilist io___372 = { 0, 0, 0, fmt_2006, 0 };
    static cilist io___375 = { 0, 0, 0, fmt_2007, 0 };
    static cilist io___385 = { 0, 0, 0, fmt_2008, 0 };
    static cilist io___388 = { 0, 0, 0, fmt_9000, 0 };



/*     this routine computes activity coefficients of aqueous */
/*     species using various models.  the exact model used is determined */
/*     by the variable iopg1- */

/*        -1  davies equation */
/*         0  b-dot equation plus others */
/*         1  pitzer equations (standard).  the use or non-use of */
/*              higher order electrostatic terms is determined by */
/*              the data file. */
/*         2  not used */
/*         3  dh(o/c)a + e-l hydr. theory */
/*         4  dh(o/c)a hydration theory */
/*         5  hkf equations - part iv */

/*     after their calculation, activity coefficients may be normalized */
/*     to make them consistent with a given ph convention.  this is */
/*     determined by the variable iopg2- */

/*        -1  no normalization */
/*         0  normalization to the nbs ph scale */
/*         1  normaliation to the rational ph scale */

/*     logical flags such as qhydth only mark generic classes of */
/*     models and may be set to .true. for more than one value of */
/*     iopg1. */

/*      input  iacion  index of na+ or cl- */
/*             tempc   temperature,deg celsius */
/*             press   pressure, bars */
/*             jsflag  array of status switches, aqueous species */
/*             nsb     index of o2(g) */
/*             nst     number of aqueous species in model */
/*             conc    array of concentrations */
/*             concbs  array of master species total concentrations */
/*             jsort   array of aqueous species indices, arranged in */
/*                     order of increasing concentration */
/*             z       array of charges */
/*             zsq2    array of factors equal to one-half the charge */
/*                     squared */
/*             xi      ionic strength */
/*             xisteq  equiv. stoich. ionic strength */
/*             azero   array of d-h ion size parameters */
/*             hydn    array of hydration numbers */
/*             ielam  -1/0/1  omit e-lambda / include:e-lambda terms / */
/*     include:absolute e-lambda terms */
/*             nsq     number of aqueous master species */
/*             nhydr     ns index of the hydrogen ion */
/*             nchlor    ns index of the chloride ion */

/*      output glgc    array of molal activity coefficients */
/*          note- glgc(1) contains the activity of water */

/*      other major variables */

/*             iopg1   activity coefficient switch */
/*             iopg6   0/1  pitzer j / harvie j function */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlelm.h */

/*     elam  triples */
/*      elam(1,i,j)   e lambda for charges i,j (abs values) */
/*      elam(2,i,j)   e lambda"    "        "     " */
/*      elam(3,i,j)   e lambda""   "        "     " */

/* -------------------------------------------------------------------- */
/* eqlej.h */
/* -------------------------------------------------------------------- */
/* eqlgp.h */


/* ------------------------------------------------------------------- */
/* eqlpmu.h */

/*      nmu = actual number of entries in use */
/*      nmut = maximum number of entries allowed */
/*      nmux = triples of aqueous species indices */
/*      pmu = mu(ijk) values array */

/* -------------------------------------------------------------------- */
/* eqlpmx.h */
/*      base values (25c) */

/*      bmu   mu values */
/*      dmu   derivatives wrt temp */


/*     derived index arrays, mu data */

/*     nmxt   max number of entries in array nmxx */

/*     nmlx   actual number of entries in use */

/*     nmxi  array of pairs, indexed by species index */
/*      1) index in array nmxx to first occurrence, this species */
/*      2) index of last ocurrence in nmxx */
/*           ( may = first index-1 if no entries) */

/*      nmxx  array of triples */
/*       1) second species index from nmux */
/*       2) third species index from nmux */
/*       3) index into pmu, nmux,... */

/* -------------------------------------------------------------------- */
/* eqlpp.h */
/* -------------------------------------------------------------------- */
/* eqlpsa.h */
/*      nslm  = number of entries in use */
/*      nslmt = maximum number allowed */
/*      nslmx = species index pairs */
/*      pslm =  lambda triples from file data1p */
/*      nalpha = indices into palpha array */

/* ------------------------------------------------------------------- */
/* eqlpsl.h */
/*     derived index arrays, s-lambda data */

/*     nsxt   max number of entries in array nsxx */

/*     nslx   actual number of entries in use */

/*     nsxi  array of pairs, indexed by species index */
/*      1) index in array nsxx to first occurrence, this species */
/*      2)  index of last occurrence in nsxx */
/*             (may = first index-1 if no entries) */

/*     nsxx  array of pairs, in sets corresponding to species index */
/*      1) second species index from nslmx */
/*      2) index into pslam, nslmx, ... */

/* -------------------------------------------------------------------- */
/* eqlslm.h */
/*      pslam  triples */
/*       s-lambda */
/*       s-lambda first derivative */
/*       s-lambda second derivative */
/*       indexed same as pslm array */
/* -------------------------------------------------------------------- */
/* eqlsz.h */
/*      izm = max(izmax,-izmin) */
/*      izoff =  index into szv of zero charge */

/* -------------------------------------------------------------------- */
/* eqlsza.h */
/*      selm   =  array of sums (e lambda * concentration) */
/*                 for each charge */
/*      selmp   =  array of sums (e-lambda prime * concentration) */
/*                 for each charge */

/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */



/* -------------------------------------------------------------------- */
/* eqlun.h */


/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jsort;
    --jsflag;
    --glgc;
    --concbs;
    --hydn;
    --azero;
    --zsq2;
    --z__;
    --conc;

    /* Function Body */
    if (eqlgp_1.iopg1 <= 0) {
	if (eqlgp_1.iopg1 == 0) {

/*                            *------------------------------------------ */
/*                            * b dot equations */
/*                            *------------------------------------------ */
	    gsigm_(&conc[1], &jsort[1], nst, &sigmam);
	    gbdot_(iacion, &eqlgp_1.iopg5, nst, xi, xisteq, &z__[1], &zsq2[1],
		     &azero[1], &glgc[1], &sigmam, &eqlgp_1.iopg7, &concbs[1],
		     nsq, &eqlgp_1.iopg9);
	} else if (eqlgp_1.iopg1 == -1) {

/*                            *------------------------------------------ */
/*                            * the davies equation */
/*                            *------------------------------------------ */

	    glgc[1] = 0.f;
	    xisqrt = sqrt(*xi);
/* tom */
/*         test- make the davies equation closer numerically to the */
/*         bdot equation */
/*         factor = ( xisqrt / ( 1. + ( 1.5 * xisqrt ) ) ) - 0.07 * xi */
/* end */
	    factor = xisqrt / (xisqrt + 1.f) - *xi * .2f;
	    factor = eqldd_1.adh * -2 * factor;
	    i__1 = *nst;
	    for (ns = 2; ns <= i__1; ++ns) {
		glgc[ns] = zsq2[ns] * factor;
/* L201: */
	    }
	} else {

/*                            *------------------------------------------ */
/*                            * other simple equations */
/*                            *------------------------------------------ */

	    io___319.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___319);
	    e_wsfe();
	    io___320.ciunit = eqlun_1.nttyol;
	    s_wsfe(&io___320);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

    if (eqlgp_1.iopg1 == 3 || eqlgp_1.iopg1 == 4) {

/*                             *---------------------------------------- */
/*                             * hydration theory here */
/*                             *---------------------------------------- */

/*     get e-lambda, deriv arrays, e-lambda sums */

	gelam_(xi, &eqldd_1.aphi, &eqlgp_1.iopg6, &eqlgpa_1.ielam, &
		eqlsz_1.izm, eqlelm_1.elam);
	gesum_(eqlelm_1.elam, nst, &conc[1], &z__[1], xi, &esum, &elpsum, &
		dum);
	gselm_(eqlelm_1.elam, nst, &jsflag[1], &conc[1], &z__[1], &
		eqlsz_1.izoff, eqlsza_1.selm, eqlsza_1.selmp);

/*     get sigma m (sigmam) and the average ion size (abar) */

	gsigm_(&conc[1], &jsort[1], nst, &sigmam);
	gabar_(&sigmam, &conc[1], &jsort[1], nst, &azero[1], &abar);

/*     get hydration theory b (b-gamma * azero) */

	b = eqldd_1.bdh * abar;

/*     get f terms */

	fdd_(xi, &eqldd_1.aphi, &b, &eqlgp_1.iopg4, &f, &fp, &fpp, &fg, &fphi,
		 &ier);
	if (ier != 0) {
	    io___332.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___332);
	    e_wsfe();
	    io___334.ciunit = nttyo;
	    s_wsfe(&io___334);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}

	alm = log(sigmam / (*dshm * eqlpp_1.om) + 1.f);
	aldshm = log(*dshm);
	dshmsq = *dshm * *dshm;

	lnaw = -(alm + *xi * 2.f * fphi / eqlpp_1.om) - esum / (eqlpp_1.om * *
		dshm);
	glgc[1] = lnaw / eqlpp_1.al10;
	fqt = (*xi * 2.f * fp - f * 3.f) / (abar * sigmam / *dshm);

	i__1 = *nst;
	for (ns = 2; ns <= i__1; ++ns) {
	    glgc[ns] = 0.f;
	    if (ns == *nsb) {
		goto L28;
	    }
	    if (jsflag[ns] != 0) {
		goto L28;
	    }
	    zz = z__[ns];
	    aterm = 0.f;

/*     get esum */

	    iz = i_dnnt(&zz) + eqlsz_1.izoff;
	    elsum = eqlsza_1.selm[iz - 1];
	    lnacti = -alm - aldshm - hydn[ns] * lnaw + zsq2[ns] * (fp + 
		    elpsum / dshmsq) + elsum * 2.f / *dshm;
	    aterm = fqt * (azero[ns] - abar);
	    glgc[ns] = (lnacti + aterm) / eqlpp_1.al10;
L28:
	    ;
	}

    }

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*                             *---------------------------------------- */
/*                             * standard pitzer equations here */
/*                             *---------------------------------------- */

    if (eqlgp_1.iopg1 == 1) {

/*     get e-lambda, deriv arrays, e-lambda sums */

	gelam_(xi, &eqldd_1.aphi, &eqlgp_1.iopg6, &eqlgpa_1.ielam, &
		eqlsz_1.izm, eqlelm_1.elam);
	gesum_(eqlelm_1.elam, nst, &conc[1], &z__[1], xi, &esum, &elpsum, &
		dum);

/*     get sum(e-lambda*mj) */

	gselm_(eqlelm_1.elam, nst, &jsflag[1], &conc[1], &z__[1], &
		eqlsz_1.izoff, eqlsza_1.selm, eqlsza_1.selmp);
	gsigm_(&conc[1], &jsort[1], nst, &sigmam);

/*     get f terms */

	fdd_(xi, &eqldd_1.aphi, &eqldd_1.bt, &eqlgp_1.iopg4, &f, &fp, &fpp, &
		fg, &fphi, &ier);
	if (ier != 0) {
	    io___345.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___345);
	    e_wsfe();
	    io___346.ciunit = nttyo;
	    s_wsfe(&io___346);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}

/*     get s-lambda's and s-lambda sum */

	gslam_(xi, &eqlpsa_1.nslm, eqlpsa_1.pslm, eqlpsa_1.nalpha, 
		eqlslm_1.pslam);
	gssum_(xi, &eqlpsa_1.nslm, eqlpsa_1.nslmx, eqlslm_1.pslam, &conc[1], &
		ssum);

/*     get mu sum */

	gmsum_(&eqlpmu_1.nmu, eqlpmu_1.nmux, eqlpmu_1.pmu, &conc[1], &musum);

	glgc[1] = -(1.f / (eqlpp_1.al10 * eqlpp_1.om)) * (sigmam + *xi * fp - 
		f + esum + ssum + musum * 2.f);

/*     log(gi) calc here, standard pitzer equations */

/*     get s-lambda prime sum . . slpsum */

	gsdsm_(&eqlpsa_1.nslm, eqlpsa_1.nslmx, eqlslm_1.pslam, &conc[1], &
		slpsum, &dum);

	dum3 = (fp + elpsum + slpsum) / 2.f;

	i__1 = *nst;
	for (ns = 2; ns <= i__1; ++ns) {
	    glgc[ns] = 0.f;
	    if (ns == *nsb) {
		goto L40;
	    }
	    if (jsflag[ns] != 0) {
		goto L40;
	    }
	    zz = z__[ns];

/*     get e-lambda sum . . elsum */

	    iz = i_dnnt(&zz) + eqlsz_1.izoff;
	    elsum = eqlsza_1.selm[iz - 1];

/*     get s-lambda sum . . slsum */

	    gsgsm_(&ns, eqlpsl_1.nsxi, eqlpsl_1.nsxx, eqlslm_1.pslam, &conc[1]
		    , &slsum, &dum);

/*     get mu sum . . musum */

	    gmdsm_(&ns, eqlpmx_1.nmxi, eqlpmx_1.nmxx, eqlpmu_1.pmu, &conc[1], 
		    &musum);

	    glgc[ns] = (zsq2[ns] * 2 * dum3 + (elsum + slsum) * 2.f + musum * 
		    1.f) / eqlpp_1.al10;
L40:
	    ;
	}
    }

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


/*                             *---------------------------------------- */
/*                             * hkf equations (part iv) here */
/*                             *---------------------------------------- */

    if (eqlgp_1.iopg1 == 5) {

/*              set up - qck is logical flag for error rept. writes */

	qck = FALSE_;
/*              calculate sum of molalities */
	gsigm_(&conc[1], &jsort[1], nst, &sigmam);

/*     note gabar call is commmented out pending a revision of */
/*     how the hkf model treats the average ion size. */

/*     call gabar(sigmam,conc,jsort,nst,azero,abar) */
/*              calculate moles of salts */
	molslt_(&z__[1], &concbs[1], nsq);
/*              calculate hkfaz -- azero for hkf equations */
	azpt4_(nst, nsq, nsb, &sigmam, &conc[1], &azero[1], &z__[1], &concbs[
		1]);
/*              calculate ionic strength variables */
	gxisto_(&zsq2[1], &conc[1], nsq, &concbs[1], &xistoc);


	d__1 = eqlpp_1.omi * sigmam + 1;
	capgam = -tlg_(&d__1);
	osmgam = capgam / (eqlpp_1.omi * sigmam);
	sltsum = 0.f;
	osmsum = 0.f;
	xitmp = sqrt(*xi);
/* Computing 3rd power */
	d__1 = eqlhkf_1.hkfaz;
	acube = d__1 * (d__1 * d__1);
/* Computing 3rd power */
	d__1 = eqldd_1.bdh;
	bb = d__1 * (d__1 * d__1);
/* Computing 3rd power */
	d__1 = xitmp;
	xx = d__1 * (d__1 * d__1);
	caplam = eqlhkf_1.hkfaz * eqldd_1.bdh * xitmp + 1.f;
	lamtm = caplam - 1.f / caplam - log(caplam) * 2.f;
	sigma = lamtm * 3.f / (acube * bb * xx);

/*              do third term for a.c. of species */

	kisum_(&conc[1], &xistoc, &z__[1], nst, &sum1);

/*              debug writes */

	if (qck) {
	    io___366.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___366);
	    e_wsfe();
	    io___367.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___367);
	    do_fio(&c__1, (char *)&(*xi), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xistoc, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sigmam, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sum1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&eqlhkf_1.hkfaz, (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, (char *)&caplam, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&capgam, (ftnlen)sizeof(doublereal));
	    e_wsfe();

	    io___368.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___368);
	    e_wsfe();
	    i__1 = *nst;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		io___370.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___370);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&conc[i__], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&concbs[i__], (ftnlen)sizeof(doublereal)
			);
		e_wsfe();
/* L2004: */
	    }

	    io___371.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___371);
	    e_wsfe();
	    io___372.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___372);
	    i__1 = eqlhkf_1.icnt;
	    for (ii = 1; ii <= i__1; ++ii) {
		for (jj = 1; jj <= 4; ++jj) {
		    do_fio(&c__1, (char *)&eqlhkf_1.islt[jj + (ii << 2) - 5], 
			    (ftnlen)sizeof(integer));
		}
		do_fio(&c__1, (char *)&eqlhkf_1.mslt[ii - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    io___375.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___375);
	    e_wsfe();
	}

/*              loop through all species in model */

/* -----------  main loop for glgc ----------------- */
	i__1 = *nst;
	for (ns = 2; ns <= i__1; ++ns) {
	    if (jsflag[ns] != 0) {
		goto L90;
	    }
	    zdum = z__[ns];
	    anum = eqldd_1.adh * zdum * zdum * xitmp;

/*              get omega */
	    omega4_(&ns, &omegns, &zdum, &ierr);

/*              calculate fourth term in a.c. of species */

	    kilsum_(&ns, eqlhkf_1.indx2, &eqlhkf_1.ibjius, &conc[1], 
		    eqlhkf_1.bji, &sum2);

/*              calculate activity coefficient of species */

	    partb = omegns * *xi * sum1;
	    if (abs(zdum) <= 1e-10f) {
		glgc[ns] = capgam + partb + sum2;
	    } else {
		glgc[ns] = -(anum / caplam) + capgam + partb + sum2;
	    }

/*              calculate sum over salts of (nu sub j,k * msub k) */
	    sltsum = 0.f;
	    i__2 = eqlhkf_1.icnt;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		salmol = eqlhkf_1.mslt[i__ - 1];
		if (ns == eqlhkf_1.islt[(i__ << 2) - 4]) {
		    nu = eqlhkf_1.islt[(i__ << 2) - 2];
		    goto L80;
		} else if (ns == eqlhkf_1.islt[(i__ << 2) - 3]) {
		    nu = eqlhkf_1.islt[(i__ << 2) - 1];
		    goto L80;
		} else {
		    goto L85;
		}
L80:
		sltsum += nu * salmol;
L85:
		;
	    }

/*              major sum for osmotic coefficient */
	    third = anum * sigma / 3.f;
	    osmsum += sltsum * (third + osmgam - (*xi * omegns * sum1 + sum2) 
		    / 2.f);

/*              debug writes */

	    if (qck) {
		io___385.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___385);
		do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&znum, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&anum, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&omegns, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&sum2, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&partb, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&glgc[ns], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&sltsum, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&third, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&osmsum, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }

L90:
	    ;
	}

/*              calculate log(activity water) -- base 10 */

	osmcof = -eqlpp_1.al10 * osmsum / sigmam;
	glgc[1] = -(osmcof * sigmam * eqlpp_1.omi) / eqlpp_1.al10;

	if (qck) {
	    io___388.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___388);
	    do_fio(&c__1, (char *)&osmcof, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&glgc[1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }

/* -------------------------------------------------------------------- */

/*     make activity coefficients consistent with a specified ph */
/*     scale */

/*       iopg2 = -1   use activity coefficients as is */
/*              = 0   make consistent with modified nbs ph scale */
/*              = 2   make consistent with the rational ph scale */

    if (eqlgp_1.iopg2 == 0) {
	nbsgam_(&glgnbs, xi, &eqldd_1.adh, nchlor);
	delglg = glgnbs - glgc[*nchlor];
	gcscal_(&glgc[1], &z__[1], &delglg, nchlor, nst);
    }

    if (eqlgp_1.iopg2 == 1) {
	delglg = -glgc[*nhydr];
	gcscal_(&glgc[1], &z__[1], &delglg, nhydr, nst);
    }

/* L999: */
    return 0;
} /* gcoeff_ */

/* gcscal   last revised 11/20/87 by tjw */
/* *gcscal created in f77 11/19/87 by tjw */
/* Subroutine */ int gcscal_(doublereal *glgc, doublereal *z__, doublereal *
	delglg, integer *nref, integer *nst)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns;
    static doublereal zz, zref;


/*     this routine rescales the activity coefficients to make them */
/*     consistent with a given ph scale, which has been used to */
/*     define the correction parameter delglg. */

/*     input */
/*       z = array of charges of aqeuous species */
/*       delglg = log gamma of the reference ion (new scale) - */
/*                log gamma of the reference ion (old scale) - */
/*       nref = the ns index of the reference ion */

/*     input/output */
/*       glgc = array of activity coefficients */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --z__;
    --glgc;

    /* Function Body */
    zref = z__[*nref];
    i__1 = *nst;
    for (ns = 2; ns <= i__1; ++ns) {
	zz = z__[ns];
	if (zz != 0.f) {
	    glgc[ns] += zz / zref * *delglg;
	}
/* L10: */
    }

    return 0;
} /* gcscal_ */

/* gcsts    last revised 12/15/87 by tjw */
/* *gcsts created in f77 12/14/87 by tjw */
/* Subroutine */ int gcsts_(doublereal *csts, doublereal *cdrs, doublereal *
	cstor, integer *ibasis, integer *jsflag, integer *jflag, integer *
	nhydr, integer *nct, integer *nsb, integer *nsb1, integer *nsq, 
	integer *nsq1, integer *nst, integer *nsqmax, integer *nsqmx1, 
	integer *nstmax, logical *qbassw)
{
    /* System generated locals */
    integer csts_dim1, csts_offset, cdrs_dim1, cdrs_offset, cstor_dim1, 
	    cstor_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer is, ns, nse, nsg, nsi, nrs;
    static doublereal cx1a, cx1b, cx3a, cx3b, csum;
    static integer nrsi;


/*     this routine computes stoichiometric factors which relate */
/*     each aqueous species to the nse-th basis species.  these */
/*     stoichiometric factors permit calculation of sums which */
/*     correspond to 'total' masses or concentrations of master */
/*     species that have physical meaning.  if we just used the */
/*     ration -cdrs(nse,nrs)/cdrs(nsq1,nrs), using the definition */
/*     of 'mark reed' components, the resulting calculated 'total' */
/*     concentration of, say, chloride, might be non-physical; i.e., */
/*     it would not correspond to the quantity determined in an */
/*     analytical laboratory.  to see this, consider the effect of */
/*     switching hgcl3- into the basis for hg++.  before the switch, */
/*     we have- */
/*       hg++ (master species) */
/*       cl- (master species) */
/*       hgcl3- = hg++ + 3 cl- */
/*       hgbr3- = hg++ + 3 br- */
/*     after the switch, we have */
/*       hgcl3- (master species) */
/*       cl- (master species) */
/*       hg++ + 3 cl- = hgcl3- */
/*       hgbr3- + 3 cl- = hgcl3- + 3 br- */
/*     if we use the 'mark reed' component approach, we find that */
/*     when we go to calculate total cl-, hgbr3- has a stoichiometric */
/*     factor of -3!.  with the approach used in this routine, the */
/*     three chlorides produced by the formation of hgcl3- are */
/*     accounted for and hgbr3- then has a stoichiometric factor */
/*     of zero. */

/*     the use of the cstor array in this routine is only temporary */
/*     until this routine, extended to produce parallel stoichiometric */
/*     factors for minerals and gases, is applied in eq6.  presently */
/*     that code caclulates mass balances in terms of stoichiometric */
/*     numbers describing elemental composition (e.g., the cess, cemn, */
/*     and cegs arrays).  the cstor array presently just provides a */
/*     temporary matchup so that eq3nr can write a pickup file that */
/*     is consistent with the present version of eq6.  once that is */
/*     no longer necessary, the stoichiometric factors for h2o and h+ */
/*     should be calculated the same as for the other master species. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ------------------------------------------------------------------ */

    /* Parameter adjustments */
    --ibasis;
    --jsflag;
    --jflag;
    csts_dim1 = *nsqmax;
    csts_offset = 1 + csts_dim1;
    csts -= csts_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    cstor_dim1 = *nstmax;
    cstor_offset = 1 + cstor_dim1;
    cstor -= cstor_offset;

    /* Function Body */
    i__1 = *nsqmax;
    for (nse = 1; nse <= i__1; ++nse) {

	i__2 = *nst;
	for (ns = 1; ns <= i__2; ++ns) {
	    csts[nse + ns * csts_dim1] = 0.f;
/* L10: */
	}

/*     get stoichiometric factors for h2o (o--) */

	if (nse == 1) {
	    i__2 = *nst;
	    for (ns = 1; ns <= i__2; ++ns) {
		is = ibasis[ns];
		csts[nse + ns * csts_dim1] = cstor[is + cstor_dim1];
/* L15: */
	    }
	    goto L100;
	}

/*     get stoichiometric factors for h+ (h+) */

	if (nse == *nhydr) {
	    i__2 = *nst;
	    for (ns = 1; ns <= i__2; ++ns) {
		is = ibasis[ns];
		csts[nse + ns * csts_dim1] = cstor[is + (cstor_dim1 << 1)];
/* L20: */
	    }
	    goto L100;
	}

/*     compute stoichiometric factors for other master species */

	csts[nse + nse * csts_dim1] = 1.f;

	if (*qbassw) {
	    i__2 = *nct;
	    for (ns = 1; ns <= i__2; ++ns) {
		nsi = ibasis[ns];
		if (ns != nsi && ns != nse) {
		    nrsi = nsi - *nsb;
		    csts[nse + ns * csts_dim1] = -cdrs[nse + nrsi * cdrs_dim1]
			     / cdrs[ns + nrsi * cdrs_dim1];
		}
/* L25: */
	    }
	}

/*     compute stoichiometric factors for species not in the strict */
/*     basis. */

	i__2 = *nst;
	for (ns = *nsb1; ns <= i__2; ++ns) {
	    nrs = ns - *nsb;
	    if (jsflag[ns] > 0) {
		goto L35;
	    }
	    if (ns < *nsq) {
		if (jflag[ns] != 30) {
		    goto L35;
		}
	    }
	    csum = -cdrs[nse + nrs * cdrs_dim1] / cdrs[*nsq1 + nrs * 
		    cdrs_dim1];

	    if (*qbassw) {
		i__3 = *nsq;
		for (nsg = 2; nsg <= i__3; ++nsg) {
		    cx1a = cdrs[nsg + nrs * cdrs_dim1];
		    if (cx1a != 0.f) {
			nsi = ibasis[nsg];
			if (nsg != nsi && nsg != nse) {
			    nrsi = nsi - *nsb;
			    cx1b = cdrs[nse + nrsi * cdrs_dim1];
			    if (cx1b != 0.f) {
				cx3a = -cx1a / cdrs[*nsq1 + nrs * cdrs_dim1];
				cx3b = -cx1b / cdrs[nsg + nrsi * cdrs_dim1];
				csum += cx3a * cx3b;
			    }
			}
		    }
/* L30: */
		}
	    }

	    csts[nse + ns * csts_dim1] = csum;
L35:
	    ;
	}

L100:
	;
    }

    return 0;
} /* gcsts_ */

/* gdd      last revised 07/24/87 by rmm */
/* *gdd f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gdd_(doublereal *xi, integer *nax, doublereal *g, 
	doublereal *gp, doublereal *gpp, integer *ier)
{
    /* Builtin functions */
    double sqrt(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal a;
    static integer k;
    static doublereal x, fac, emx, gpx[2], xsq, dxdi, gppx[2], gdump, gdumpp;


/*     input */
/*       xi  real value of i */
/*       nax  index to alpha pair array palpha */

/*     compute 6 g values, in sets of 2 - */

/*       g(1) = g(i,a1)    a1 = palpha(1,nax) */
/*         2  = g(i,a2)    a2 = palpha(2,nax) */

/*       gpx(1) = dg(x)/dx, where x = a1*sqrt(i) */
/*           2  = as above, but with x = a2*sqrt(i) */

/*       gp(1)  = dg(i,a1)/di = dg(x)/dx * dx/di, where x = a1*sqrt(i) */
/*          2   = dg(i,a2)/di = as above, but with x = a2*sqrt(i) */

/*       gppx(1) = d2g(x)/dx, where x = a1*sqrt(i) */
/*            2    as above, but with x = a2*sqrt(i) */

/*       gpp(1) = d2g(i,a1)/di = d2g(x)/dx2 * dx/di + dg(x)/dx * d2x/di2, */
/*              = dxdi( d2g(x)/dx2*dx/di - (dg(x)/dx)/(2i) ), */
/*                                  where x = a1*sqrt(i) */
/*           2  = d2g(i,a2)/di = as above, but with x = a2*sqrt(i) */

/*     note- */
/*      d2x/di2 = -(dx/di)/2i */
/*     note - */
/*      a1=0 implies g(i,a1) = g'(i,a1) = g''(i,a1) = 0 */
/*      a2=0   "         a2         a2          a2  = 0 */

/*     ier = 0/-1  ok/xi out of range */
/*     xi must be .gt. 0. and .le. 50. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */


/* -------------------------------------------------------------------- */
/* eqlpal.h */

/*      napt  total number of entries allowed */
/*      palpha  alpha pairs from file data1p */


/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --gpp;
    --gp;
    --g;

    /* Function Body */
    *ier = 1;

    if (*xi <= 0.f || *xi > 50.f) {
	goto L999;
    }
    *ier = 0;
    fac = 1.f / (*xi * 2.f);

    for (k = 1; k <= 2; ++k) {
	g[k] = 0.f;
	gpx[k - 1] = 0.f;
	gppx[k - 1] = 0.f;
	gp[k] = 0.f;
	gpp[k] = 0.f;
	a = eqlpal_1.palpha[k + (*nax << 1) - 3];

	if (a != 0.f) {

	    x = a * sqrt(*xi);
	    xsq = x * x;
	    emx = exp(-x);

	    g[k] = 2.f / xsq * (1.f - emx * (x + 1.f));

/*       calculate derivatives with respect to x */

	    gdump = -2.f / (xsq * x) * (2.f - emx * (x * (x + 2.f) + 2.f));
	    gpx[k - 1] = gdump;
	    gdumpp = -2.f / (xsq * xsq) * (emx * (x * (x * (x + 3.f) + 6.f) + 
		    6.f) - 6.f);
	    gppx[k - 1] = gdumpp;

/*       calculate derivatives with respect to xi. */

	    dxdi = a / (sqrt(*xi) * 2.f);
	    gpp[k] = dxdi * (gdumpp * dxdi - fac * gdump);
	    gp[k] = dxdi * gdump;
	}

/* L40: */
    }

L999:
    return 0;
} /* gdd_ */

/* gelam    last revised 07/06/87 by tjw */
/* *gelam f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gelam_(doublereal *xi, doublereal *aphi, integer *iopthp,
	 integer *ielam, integer *izm, doublereal *elam)
{
    /* Format strings */
    static char fmt_1010[] = "(\002 * error in e-lambda calc (eqlib/gelam"
	    ")\002)";
    static char fmt_1012[] = "(10x,\002zj=\002,f6.0,2x,\002zi=\002,f6.0,2x"
	    ",\002xip=\002,e15.5)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal el;
    static integer ii, ij, jj;
    static doublereal wi, wj, zi, zj;
    static integer ier;
    static doublereal elp, elpp;
    extern /* Subroutine */ int elmdd_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal pelam[300]	/* was [3][100] */;

    /* Fortran I/O blocks */
    static cilist io___427 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___428 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___429 = { 0, 0, 0, fmt_1012, 0 };
    static cilist io___430 = { 0, 0, 0, fmt_1012, 0 };



/*     input  xi       i value */
/*            aphi     adh/3 */
/*            iopthp   0/1  use pitzer j / use harvie j */
/*            ielam  -1/0/1  set e-lambda values = 0 / compute them */
/*                     in the standard way / compute them in the */
/*                     absolute way */
/*            izm      index to zero charge */
/*     output elam     array of e-lambda and */
/*                                  '    first derivative */
/*                                  '    second derivative */
/*                     corresponding to all legal charge pairs */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    elam -= 34;

    /* Function Body */
    i__1 = *izm;
    for (j = 1; j <= i__1; ++j) {

/*     associated charge value */

	zj = (real) j;

	i__2 = *izm;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ij = i__ * j;
	    if (*ielam < 0) {

/*       skip e-lambda's here */

		pelam[ij * 3 - 3] = 0.f;
		pelam[ij * 3 - 2] = 0.f;
		pelam[ij * 3 - 1] = 0.f;
		elam[(i__ + j * 10) * 3 + 1] = 0.f;
		elam[(i__ + j * 10) * 3 + 2] = 0.f;
		elam[(i__ + j * 10) * 3 + 3] = 0.f;
	    } else {

/*       associated charge value */

		zi = (real) i__;

/*       reduce to triangular set */

		if (i__ >= j) {

/*         get e-lambda's and derivs */

		    elmdd_(&zj, &zi, aphi, xi, iopthp, &el, &elp, &elpp, &ier)
			    ;
		    if (ier != 0) {
			io___427.ciunit = eqlun_1.noutpl;
			s_wsfe(&io___427);
			e_wsfe();
			io___428.ciunit = eqlun_1.nttyol;
			s_wsfe(&io___428);
			e_wsfe();
			io___429.ciunit = eqlun_1.noutpl;
			s_wsfe(&io___429);
			do_fio(&c__1, (char *)&zj, (ftnlen)sizeof(doublereal))
				;
			do_fio(&c__1, (char *)&zi, (ftnlen)sizeof(doublereal))
				;
			do_fio(&c__1, (char *)&(*xi), (ftnlen)sizeof(
				doublereal));
			e_wsfe();
			io___430.ciunit = eqlun_1.nttyol;
			s_wsfe(&io___430);
			do_fio(&c__1, (char *)&zj, (ftnlen)sizeof(doublereal))
				;
			do_fio(&c__1, (char *)&zi, (ftnlen)sizeof(doublereal))
				;
			do_fio(&c__1, (char *)&(*xi), (ftnlen)sizeof(
				doublereal));
			e_wsfe();
			s_stop("", (ftnlen)0);
		    }
		    pelam[ij * 3 - 3] = el;
		    pelam[ij * 3 - 2] = elp;
		    pelam[ij * 3 - 1] = elpp;
		}
	    }

/* L30: */
	}

/* L40: */
    }

    if (*ielam <= -1) {
	goto L999;
    }

/*     compute elam values */

    i__1 = *izm;
    for (j = 1; j <= i__1; ++j) {
	zj = (real) j;
	jj = j * j;

	i__2 = *izm;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ij = i__ * j;
	    ii = i__ * i__;
	    zi = (real) i__;

	    wj = zi / (zj * 2.f);
	    wi = zj / (zi * 2.f);

	    if (*ielam <= 0) {
		elam[(i__ + j * 10) * 3 + 1] = pelam[ij * 3 - 3] - wj * pelam[
			jj * 3 - 3] - wi * pelam[ii * 3 - 3];
		elam[(i__ + j * 10) * 3 + 2] = pelam[ij * 3 - 2] - wj * pelam[
			jj * 3 - 2] - wi * pelam[ii * 3 - 2];
		elam[(i__ + j * 10) * 3 + 3] = pelam[ij * 3 - 1] - wj * pelam[
			jj * 3 - 1] - wi * pelam[ii * 3 - 1];
	    } else {
		elam[(i__ + j * 10) * 3 + 1] = pelam[ij * 3 - 3];
		elam[(i__ + j * 10) * 3 + 2] = pelam[ij * 3 - 2];
		elam[(i__ + j * 10) * 3 + 3] = pelam[ij * 3 - 1];
	    }
/* L60: */
	}

/* L70: */
    }

    if (*ielam <= 0) {

/*       set diagonal elements to zero */

	i__1 = *izm;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    elam[(i__ + i__ * 10) * 3 + 1] = 0.f;
	    elam[(i__ + i__ * 10) * 3 + 2] = 0.f;
	    elam[(i__ + i__ * 10) * 3 + 3] = 0.f;
/* L75: */
	}
    }

L999:
    return 0;
} /* gelam_ */

/* gesum    last revised 10/27/87 by tjw */
/* *gesum f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gesum_(doublereal *elam, integer *nst, doublereal *conc, 
	doublereal *z__, doublereal *xi, doublereal *sumw, doublereal *sums, 
	doublereal *sump)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal el;
    static integer ij;
    static doublereal cp, mi, mj, zi, xl, zj;
    static integer iz, jz;
    static doublereal elp, elpp;


/*     input  elam   array of e-lambda values */
/*            nst    number of species */
/*            conc   array of concentrations */
/*            z      array of charges */
/*            xi     i value */
/*     output sumw   sum(elam(ij) + i*elam'(ij))*mi*mj */
/*            sums   sum(elam'(ij)*mi*mj */
/*            sump   sum(elam''(ij)*mi*mj */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --z__;
    --conc;
    elam -= 34;

    /* Function Body */
    *sumw = 0.f;
    *sums = 0.f;
    *sump = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

    i__1 = *nst;
    for (i__ = 2; i__ <= i__1; ++i__) {
	mi = conc[i__];
	if (mi < xl) {
	    goto L20;
	}
	zi = z__[i__];
	if (zi == 0.f) {
	    goto L20;
	}

	i__2 = *nst;
	for (j = 2; j <= i__2; ++j) {

/*     skip diagonal terms */

	    if (i__ == j) {
		goto L10;
	    }
	    mj = conc[j];
	    if (mj == 0.f) {
		goto L10;
	    }
	    zj = z__[j];
	    if (zj == 0.f) {
		goto L10;
	    }
	    d__1 = zi * zj;
	    ij = i_dnnt(&d__1);
	    if (ij < 0) {
		goto L10;
	    }

	    d__1 = abs(zi);
	    iz = i_dnnt(&d__1);
	    d__1 = abs(zj);
	    jz = i_dnnt(&d__1);
	    el = elam[(iz + jz * 10) * 3 + 1];
	    elp = elam[(iz + jz * 10) * 3 + 2];
	    elpp = elam[(iz + jz * 10) * 3 + 3];
	    cp = mi * mj;

	    *sumw += (el + *xi * elp) * cp;
	    *sums += elp * cp;
	    *sump += elpp * cp;
L10:
	    ;
	}

L20:
	;
    }

    return 0;
} /* gesum_ */

/* getlu    last revised 07/06/87 by tjw */
/* *getlu f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int getlu_(integer *nlu, integer *nerr)
{
    /* Initialized data */

    static integer iumax = 19;
    static integer iumin = 0;

    /* System generated locals */
    integer i__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *);

    /* Local variables */
    static logical qopen;


/*     purpose  to get a currently unused unit number. */
/*     output arguments */
/*         nlu   unit number  not currently in use. */
/*         nerr  0/1  ok/error */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ------------------------------------------------------------------- */

    *nerr = 0;

/*    loop through all valid file numbers, beginning with the largest */

    i__1 = iumin;
    for (*nlu = iumax; *nlu >= i__1; --(*nlu)) {
	ioin__1.inerr = 0;
	ioin__1.inunit = *nlu;
	ioin__1.infile = 0;
	ioin__1.inex = 0;
	ioin__1.inopen = &qopen;
	ioin__1.innum = 0;
	ioin__1.innamed = 0;
	ioin__1.inname = 0;
	ioin__1.inacc = 0;
	ioin__1.inseq = 0;
	ioin__1.indir = 0;
	ioin__1.infmt = 0;
	ioin__1.inform = 0;
	ioin__1.inunf = 0;
	ioin__1.inrecl = 0;
	ioin__1.innrec = 0;
	ioin__1.inblank = 0;
	f_inqu(&ioin__1);
	if (! qopen) {
	    goto L999;
	}
/* L10: */
    }

    *nerr = 1;

L999:
    return 0;
} /* getlu_ */

/* gkey     last revised 10/20/87 by tjw */
/* *gkey f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gkey_(char *uflag, char *udata, ftnlen uflag_len, ftnlen 
	udata_len)
{
    /* Initialized data */

    static char usfipc[8] = "stfipc  ";
    static char uspitz[8] = "stpitz  ";
    static char ushkf[8] = "sthkf   ";

    /* Format strings */
    static char fmt_300[] = "(\002 * error - act. coeff. option not compatib"
	    "le with\002,\002 supporting data file \002,a8,/3x,\002iopg1= "
	    "\002,i3,\002, data file key= \002,a6,\002, correct key= \002,a6,"
	    "/5x,\002provide the correct set of data files and try again\002,"
	    "/5x,\002do not change the keys on the data files (eqlib/gkey)"
	    "\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static char ukey[8];

    /* Fortran I/O blocks */
    static cilist io___456 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___457 = { 0, 0, 0, fmt_300, 0 };



/*     this routine checks an alphanumeric flag (uflag) read from data1, */
/*     data2, or data3 and checks it against a key-list to test whether */
/*     or not the data files provided are consistent with the activity */
/*     coefficient option that has been chosen. */

/*           option                  iopg1      legal key */

/*        davies equation             -1          stfipc */
/*        b-dot equation               0          stfipc */
/*        standard pitzer equations    1          stpitz */
/*        hkf equations - part iv      5          sthkf */
/*        standard pitzer equations  101          stpitz */

/*     'stfipc' = standard full ion pairs and complexes' */
/*     'stpitz' = standard pitzer equations */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ----------------------------------------------------------------- */

/*     set the correct key */

    s_copy(ukey, usfipc, (ftnlen)8, (ftnlen)8);
    if (eqlgp_1.iopg1 == 1 || eqlgp_1.iopg1 == 101) {
	s_copy(ukey, uspitz, (ftnlen)8, (ftnlen)8);
    } else if (eqlgp_1.iopg1 == 5) {
	s_copy(ukey, ushkf, (ftnlen)8, (ftnlen)8);
    }

    if (s_cmp(uflag, ukey, (ftnlen)6, (ftnlen)6) != 0) {

/*       error, bad combination */

	io___456.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___456);
	do_fio(&c__1, udata, (ftnlen)8);
	do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
	do_fio(&c__1, uflag, (ftnlen)8);
	do_fio(&c__1, ukey, (ftnlen)8);
	e_wsfe();
	io___457.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___457);
	do_fio(&c__1, udata, (ftnlen)8);
	do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
	do_fio(&c__1, uflag, (ftnlen)8);
	do_fio(&c__1, ukey, (ftnlen)8);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    return 0;
} /* gkey_ */

/* gmdsm    last revised 11/02/87 by tjw */
/* *gmdsm f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gmdsm_(integer *i__, integer *nmxi, integer *nmxx, 
	doublereal *pmu, doublereal *conc, doublereal *sum)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, ii, kk;
    static doublereal sm, xl;
    static integer ifx, ilx;


/*     find mu sum contribution for derivatives of water */
/*       with respect to molality */

/*     input  i       species index */
/*            nmxi, */
/*            nmxx    arrays of mu indices */
/*            pmu     array of mu values */
/*            conc    array of concentration values */
/*     output sum     sum(mu(ijk)*mj*mk) */
/*                     note that symmetry requires multipliers for */
/*                     various terms */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --conc;
    --pmu;
    nmxx -= 4;
    nmxi -= 3;

    /* Function Body */
    *sum = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

/*     get first, last indices of contributing values */

    ifx = nmxi[(*i__ << 1) + 1];
    ilx = nmxi[(*i__ << 1) + 2];

/*     exit if no values */

    if (ilx < ifx) {
	goto L999;
    }

    i__1 = ilx;
    for (kk = ifx; kk <= i__1; ++kk) {
	sm = 1.f;
	j = nmxx[kk * 3 + 1];
	k = nmxx[kk * 3 + 2];
	ii = nmxx[kk * 3 + 3];
	if (conc[j] < xl) {
	    goto L20;
	}
	if (conc[k] < xl) {
	    goto L20;
	}
	if (*i__ != j && *i__ != k) {
	    if (j != k) {
		sm = 2.f;
	    }
	    *sum += sm * pmu[ii] * conc[j] * conc[k];
	} else {
	    *sum += pmu[ii] * 2.f * conc[j] * conc[k];
	}
L20:
	;
    }

    *sum *= 3.f;
L999:
    return 0;
} /* gmdsm_ */

/* gmsum    last revised 11/02/87 by tjw */
/* *gmsum f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gmsum_(integer *nmu, integer *nmux, doublereal *pmu, 
	doublereal *conc, doublereal *sum)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k, kk;
    static doublereal xl;


/*     input  nmu     number of mu values */
/*            nmux    array of triples of species indices */
/*            pmu     array of mu values */
/*            conc    array of concentration values */
/*     output sum     sum(mu(ijk)*mi*mj*mk) */
/*                     note that data includes single occurrence of */
/*                     each value - triple sum symmetry requires */
/*                     multiplication by 3 */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */
    /* Parameter adjustments */
    --conc;
    --pmu;
    nmux -= 4;

    /* Function Body */
    *sum = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

    i__1 = *nmu;
    for (kk = 1; kk <= i__1; ++kk) {
	i__ = nmux[kk * 3 + 1];
	j = nmux[kk * 3 + 2];
	k = nmux[kk * 3 + 3];
	if (conc[i__] < xl) {
	    goto L10;
	}
	if (conc[j] < xl) {
	    goto L10;
	}
	if (conc[k] < xl) {
	    goto L10;
	}
	*sum += pmu[kk] * conc[i__] * conc[j] * conc[k];
L10:
	;
    }

    *sum *= 3.f;
/* L999: */
    return 0;
} /* gmsum_ */

/* gntpr    last revised 12/12/87 by tjw */
/* *gntpr created in f77  12/12/87 by tjw */
/* Subroutine */ int gntpr_(doublereal *tempc, doublereal *al10, doublereal *
	rconst, doublereal *farad, doublereal *tempk, doublereal *afcnst, 
	doublereal *ehfac, integer *ntpr, integer *iopg8)
{
    /* Initialized data */

    static doublereal tconst = 273.15;
    static doublereal tempc1 = 450.;
    static doublereal tempc2 = 999.;


/*     this routine finds the value of the temperature range flag */
/*     ntpr. */

/*     input */
/*       tempc = temperature, degrees celsius */
/*       al10 = ln 10 */
/*       rconst = the gas constant */
/*       farad = the faraday constant */

/*     output */
/*       tempk = temperature, degrees kelvin */
/*       afcnst = affinity constant */
/*       ehfac = eh factor */
/*       ntpr = temperature range flag */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
    if (*iopg8 == 1) {
	tempc1 = 800.f;
    }

/* ---------------------------------------------------------------------- */

    *tempk = *tempc + tconst;
    *afcnst = *al10 * .001f * *rconst * *tempk;
    *ehfac = *al10 * *rconst * *tempk / *farad;


/*     determine the temperature range flag (ntpr) */
/*       ntpr = 1  tempc .le. tempc1 */
/*            = 2  tempc1 .lt. tempc .le. tempc2 */
/*            = 3  tempc .gt. tempc2 */

    if (*tempc <= tempc1) {
	*ntpr = 1;
    } else if (*tempc <= tempc2) {
	*ntpr = 2;
    } else {
	*ntpr = 3;
    }

    return 0;
} /* gntpr_ */

/* gpheh    last revised 12/26/87 by tjw */
/* *gpheh created in f77  12/12/87 by tjw */
/* Subroutine */ int gpheh_(doublereal *actlg, doublereal *glg, doublereal *
	fo2lg, doublereal *xi, doublereal *adh, doublereal *xlkeh, doublereal 
	*ehfac, doublereal *ph, doublereal *phnbs, doublereal *phrat, 
	doublereal *phcl, doublereal *eh, doublereal *ehnbs, doublereal *
	ehrat, doublereal *pe, doublereal *penbs, doublereal *perat, integer *
	iopg2, integer *nhydr, integer *nchlor, logical *qnochb)
{
    static doublereal pcl, efac, eterm, eterm0, eterm1, delglg;
    extern /* Subroutine */ int nbsgam_(doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal glgnbs;


/*     this routine computes the ph, redox potential, and pe */
/*     (electron activity function) on the operational ph scale used */
/*     in the calculations (see iopg2), the modified nbs ph scale, */
/*     and the rational ph scale. */

/*     input */
/*       actlg = array of logarithms of aqueous species activities; */
/*               actlg(1) is the log activity of water */
/*       glg = array of logarithms of aqueous species activity */
/*             coefficients */
/*       fo2lg = log oxygen fugacity */
/*       xi = ionic strength */
/*       adh = debye-huckel 'a' parameter */
/*       xlkeh = log k for special reaction for calculating eh */
/*               from log oxygen fugacity */
/*       ehfac = eh factor */
/*       iopg2 = activity coefficient option switch, defines the */
/*               operational ph scale used in the computation */
/*               = -1   internal scale defined for the activity */
/*                      coefficinet model defined by iopg1 */
/*                = 0   the modified nbs ph scale (log gamma cl- */
/*                      defined by bates-guggenheim expression) */
/*                = 2   the rational ph scale (log gamma h+ defined */
/*                      as zero) */
/*       nhydr = species index of the hydrogen ion */
/*       nchlor = species index of the chloride ion */
/*       qnochb = logical flag, = .true. if no oxidation-reduction */
/*                in the modeled system */

/*     output */
/*       ph = ph on scale used in computation */
/*       phnbs = ph on the modified nbs scale */
/*       phrat = ph on the rational scale */
/*       phcl = ph + pcl */
/*       eh = eh corresponding to the ph used in the computation */
/*       ehnbs = eh corresponding to the phnbs */
/*       ehrat = eh corresponding to the phrat */
/*       pe = pe function corresonding to eh */
/*       penbs = pe function corresonding to ehnbs */
/*       perat = pe function corresonding to ehrat */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     compute ph, eh, and pe for the operational ph scale */

    /* Parameter adjustments */
    --glg;
    --actlg;

    /* Function Body */
    *ph = -actlg[*nhydr];
    *eh = -999.f;
    *pe = -999.f;
    if (! (*qnochb)) {
	efac = *ehfac * .25f;
	eterm = *fo2lg - *ph * 4.f - actlg[1] * 2.f - *xlkeh;
	*eh = efac * eterm;
	*pe = *eh / *ehfac;
    }

/*     compute ph, eh, and pe consistent with the modified nbs ph scale */
/*     note that this can not be done if the activity coefficient of */
/*     chloride ion on the operational scale is not available. */

    *phnbs = -999.f;
    *ehnbs = -999.f;
    *penbs = -999.f;
    if (*nchlor > 0) {
	if (*iopg2 == 0) {
	    *phnbs = *ph;
	    *ehnbs = *eh;
	    *penbs = *pe;
	} else {
	    nbsgam_(&glgnbs, xi, adh, nchlor);
	    delglg = glgnbs - glg[*nchlor];
	    *phnbs = *ph - delglg;
	    if (! (*qnochb)) {
		eterm0 = eterm + (*ph - *phnbs) * 4.f;
		*ehnbs = efac * eterm0;
		*penbs = *ehnbs / *ehfac;
	    }
	}
    }

    *ehrat = -999.f;
    *perat = -999.f;
    if (*iopg2 == 1) {
	*phrat = *ph;
	*ehrat = *eh;
	*perat = *pe;
    } else {
	delglg = -glg[*nhydr];
	*phrat = *ph - delglg;
	if (! (*qnochb)) {
	    eterm1 = eterm + (*ph - *phrat) * 4.f;
	    *ehrat = efac * eterm1;
	    *perat = *ehrat / *ehfac;
	}
    }

/*     compute phcl = ph + pcl */

    *phcl = -999.f;
    if (*nchlor > 0) {
	pcl = -actlg[*nchlor];
	*phcl = *ph + pcl;
    }

    return 0;
} /* gpheh_ */

/* gsdsm    last revised 07/06/87 by tjw */
/* *gsdsm  f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gsdsm_(integer *nslm, integer *nslmx, doublereal *pslam, 
	doublereal *conc, doublereal *sum, doublereal *sump)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, n;
    static doublereal cp, xl;


/*     input  nslm    number of s-lambda's */
/*            nslmx   array of species index pairs */
/*            pslam   array of s-lambda values */
/*            conc    array of concentration values */
/*     output sum     sum(slam'(jk)*mj*mk) */
/*            sump    sum(slam''(jk)*mj*mk) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --conc;
    pslam -= 4;
    nslmx -= 3;

    /* Function Body */
    *sum = 0.f;
    *sump = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

    i__1 = *nslm;
    for (n = 1; n <= i__1; ++n) {
	i__ = nslmx[(n << 1) + 1];
	j = nslmx[(n << 1) + 2];
	if (conc[i__] < xl) {
	    goto L20;
	}
	if (conc[j] < xl) {
	    goto L20;
	}
	cp = conc[i__] * conc[j];
	*sum += pslam[n * 3 + 2] * cp;
	*sump += pslam[n * 3 + 3] * cp;
L20:
	;
    }

    *sum *= 2.f;
    *sump *= 2.f;

    return 0;
} /* gsdsm_ */

/* gselm    last revised 08/07/87 by rmm */
/* *gselm f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gselm_(doublereal *elam, integer *nst, integer *jsflag, 
	doublereal *conc, doublereal *z__, integer *izoff, doublereal *selm, 
	doublereal *selmp)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer i__, j, ij;
    static doublereal mj, zi, xl;
    static integer iz;
    static doublereal zj;
    static integer jz, ise;
    static doublereal sum, sump;

/*  references to int replaced by nint 07/06/87 by tjw */

/*     input  elam    array of e-lambda values */
/*            nst     number of species */
/*            jsflag  array of status flags, aqueous species */
/*            conc    array of concentrations */
/*            z       array of charges */
/*            izoff   index to zero charge */
/*     output selm    array of sums  sum(el(ij)*mj) */
/*            selmp   array of sums  sum(el'(ij)*mj) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --selmp;
    --selm;
    --z__;
    --conc;
    --jsflag;
    elam -= 34;

    /* Function Body */
    selm[*izoff] = 0.f;
    selmp[*izoff] = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

    i__1 = *nst;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (jsflag[i__] != 0) {
	    goto L20;
	}
	zi = z__[i__];
	if (zi == 0.f) {
	    goto L20;
	}
	iz = i_dnnt(&zi);
	ise = iz + *izoff;
	sum = 0.f;
	sump = 0.f;

	i__2 = *nst;
	for (j = 2; j <= i__2; ++j) {
	    if (jsflag[j] != 0) {
		goto L10;
	    }

/*      skip diagonal terms */

	    if (i__ == j) {
		goto L10;
	    }
	    mj = conc[j];
	    if (mj < xl) {
		goto L10;
	    }
	    zj = z__[j];
	    if (zj == 0.f) {
		goto L10;
	    }
	    d__1 = zi * zj;
	    ij = i_dnnt(&d__1);
	    if (ij < 0) {
		goto L10;
	    }

	    d__1 = abs(zi);
	    iz = i_dnnt(&d__1);
	    d__1 = abs(zj);
	    jz = i_dnnt(&d__1);
	    sum += elam[(iz + jz * 10) * 3 + 1] * mj;
	    sump += elam[(iz + jz * 10) * 3 + 2] * mj;
L10:
	    ;
	}

	selm[ise] = sum;
	selmp[ise] = sump;
L20:
	;
    }

    return 0;
} /* gselm_ */

/* gsgsm    last revised 07/06/87 by tjw */
/* *gsgsm f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gsgsm_(integer *i__, integer *nsxi, integer *nsxx, 
	doublereal *pslam, doublereal *conc, doublereal *sum, doublereal *
	sump)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k;
    static doublereal cj;
    static integer ii;
    static doublereal xl;
    static integer ixf, ixl;


/*     input  i      species index */
/*            nsxi, */
/*            nsxx   sets of s-lambda indices */
/*            pslam  array of s-lambda values */
/*            conc   array of concentration values */
/*     output sum    sum(slam(ij)*mj) */
/*            sump   sum(slam'(ij)*mj) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --conc;
    pslam -= 4;
    nsxx -= 3;
    nsxi -= 3;

    /* Function Body */
    *sum = 0.f;
    *sump = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

/*     get first and last indices to nsxx array */

    ixf = nsxi[(*i__ << 1) + 1];
    ixl = nsxi[(*i__ << 1) + 2];

/*     exit if no entries */

    if (ixl >= ixf) {
	i__1 = ixl;
	for (ii = ixf; ii <= i__1; ++ii) {
	    k = nsxx[(ii << 1) + 2];
	    j = nsxx[(ii << 1) + 1];
	    cj = conc[j];
	    if (cj >= xl) {
		*sum += pslam[k * 3 + 1] * cj;
		*sump += pslam[k * 3 + 2] * cj;
	    }
/* L20: */
	}
    }
    return 0;
} /* gsgsm_ */

/* gshm     last revised 11/02/87 by tjw */
/* *gshm f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gshm_(doublereal *hydn, doublereal *conc, integer *jsort,
	 integer *nst, doublereal *shmc, doublereal *dshmc)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns, nss;


/*     input   hydn   array of hydration numbers */
/*             conc   array of concentrations  mj */
/*             jsort   array of aqueous species indices, in order of */
/*                     increasing concentration */
/*             nst    number of elements in arrays */
/*     output  shmc    sum(hj*mj) */
/*             dshmc  ( 1 - (shmc/om) ) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqlpp.h */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jsort;
    --conc;
    --hydn;

    /* Function Body */
    *shmc = 0.f;

/*     note - this calculation presumes that either conc(1) or */
/*     hydn(1) is zero, so that there is no contribution from */
/*     the solvent.  it should be always safe to assume that hydn(1) = 0. */

    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = jsort[nss];
	*shmc += hydn[ns] * conc[ns];
/* L20: */
    }
    *dshmc = 1.f - *shmc / eqlpp_1.om;
    return 0;
} /* gshm_ */

/* gsigm    last revised 11/05/87 by tjw */
/* *gsigm f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gsigm_(doublereal *conc, integer *jsort, integer *nst, 
	doublereal *sigmmc)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns, nss;


/*     this routine calculates the sum of concentrations ('sigma m'). */
/*     note that a sorted summation is used. */

/*       input */
/*         conc    array of concentrations  mi */
/*         jsort   array of aqueous species indices, in order of */
/*                 increasing concentration */
/*         nst     number of elements in array */

/*       output */
/*         sigmmc      sum(mi) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     note - this calculation presumes that conc(1) 1) is zero, so that */
/*     there is no contribution from the solvent. */

    /* Parameter adjustments */
    --jsort;
    --conc;

    /* Function Body */
    *sigmmc = 0.f;
    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = jsort[nss];
	*sigmmc += conc[ns];
/* L10: */
    }

    return 0;
} /* gsigm_ */

/* gslam    last revised 11/02/87 by tjw */
/* *gslam f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gslam_(doublereal *xi, integer *nslm, doublereal *pslm, 
	integer *nalpha, doublereal *pslam)
{
    /* Format strings */
    static char fmt_1010[] = "(\002 * error - bad call to gdd for s-lambda c"
	    "alc.\002,\002 (eqlib/gslam)\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal g[2];
    static integer k;
    static doublereal gp[2], pl0, pl1, pl2;
    extern /* Subroutine */ int gdd_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static integer ier;
    static doublereal gpp[2];

    /* Fortran I/O blocks */
    static cilist io___514 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___515 = { 0, 0, 0, fmt_1010, 0 };



/*     input  xi       i value */
/*            nslm     number of lambda values */
/*            pslm     array of lambda triples */
/*            nalpha   indices into palpha array */
/*     output pslam    array of s-lambda and */
/*                                 '     first derivative */
/*                                 '     second derivative */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    pslam -= 4;
    --nalpha;
    pslm -= 4;

    /* Function Body */
    i__1 = *nslm;
    for (k = 1; k <= i__1; ++k) {

/*     get g and derivatives */

	gdd_(xi, &nalpha[k], g, gp, gpp, &ier);
	if (ier != 0) {
	    io___514.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___514);
	    e_wsfe();
	    io___515.ciunit = eqlun_1.nttyol;
	    s_wsfe(&io___515);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}

	pl0 = pslm[k * 3 + 1];
	pl1 = pslm[k * 3 + 2];
	pl2 = pslm[k * 3 + 3];

	pslam[k * 3 + 1] = pl0 + g[0] * pl1 + g[1] * pl2;
	pslam[k * 3 + 2] = gp[0] * pl1 + gp[1] * pl2;
	pslam[k * 3 + 3] = gpp[0] * pl1 + gpp[1] * pl2;

/* L20: */
    }

    return 0;
} /* gslam_ */

/* gspion   last revised 12/18/87 by tjw */
/* *gspion created in f77 12/18/87 by tjw */
/* Subroutine */ int gspion_(char *uspec, integer *nst, integer *nhydr, 
	integer *nchlor, ftnlen uspec_len)
{
    /* Initialized data */

    static char uhydr[8] = "H+      ";
    static char uchlor[8] = "CL-     ";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer ns;


/*     this routine finds the indices of the h+ and cl- ions */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

    /* Parameter adjustments */
    uspec -= uspec_len;

    /* Function Body */

/* ------------------------------------------------------------------ */

    *nhydr = 0;
    *nchlor = 0;

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	if (s_cmp(uspec + ns * uspec_len, uhydr, (ftnlen)8, (ftnlen)8) == 0) {
	    *nhydr = ns;
	    goto L15;
	}
/* L10: */
    }

L15:
    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	if (s_cmp(uspec + ns * uspec_len, uchlor, (ftnlen)8, (ftnlen)8) == 0) 
		{
	    *nchlor = ns;
	    goto L25;
	}
/* L20: */
    }

L25:

    return 0;
} /* gspion_ */

/* gssum    last revised 07/06/87 by tjw */
/* *gssum f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gssum_(doublereal *xi, integer *nslm, integer *nslmx, 
	doublereal *pslam, doublereal *conc, doublereal *sum)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, n;
    static doublereal xl;


/*     input  xi     i value */
/*            nslm   number of s-lambda values */
/*            nslmx  array of s-lambda species index pairs */
/*            pslam  array of s-lambda values */
/*            conc   array of concentration values */
/*     output sum    sum((slam(ij) + i*slam'(ij))*mi*mj) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --conc;
    pslam -= 4;
    nslmx -= 3;

    /* Function Body */
    *sum = 0.f;

/*     xl is lower limit for conc of one species */

    xl = 1e-9f;

    i__1 = *nslm;
    for (n = 1; n <= i__1; ++n) {
	i__ = nslmx[(n << 1) + 1];
	j = nslmx[(n << 1) + 2];
	if (conc[i__] < xl) {
	    goto L20;
	}
	if (conc[j] < xl) {
	    goto L20;
	}
	*sum += (pslam[n * 3 + 1] + *xi * pslam[n * 3 + 2]) * conc[i__] * 
		conc[j];
L20:
	;
    }

    *sum *= 2.f;

    return 0;
} /* gssum_ */

/* gszm     last revised 10/30/87 by tjw */
/* *gszm created in f77  10/27/87 by tjw */
/* Subroutine */ int gszm_(doublereal *z__, doublereal *conc, integer *jsort, 
	integer *nst, doublereal *sigzc, doublereal *sigza, doublereal *sigzm,
	 doublereal *sigzi)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static doublereal ec;
    static integer ns, nss;


/*     this routine calculates the sums of equivalent concentrations */
/*     and the charge imbalance.  note that a sorted summation is */
/*     used. */

/*       input */
/*         z       array of charges zi */
/*         conc    array of concentrations  mi */
/*         jsort   array of aqueous species indices, in order of */
/*                 increasing concentration */
/*         nst     number of elements in array */

/*       output */
/*         sigzc    the sum of equivalent concentrations of aqueous */
/*                  cations, sigma(i) zi * mi, for zi .gt. 0 */
/*         sigza    the sum of equivalent concentrations of aqueous */
/*                  anions, sigma(i) abs(zi) * mi, for zi .lt. 0 */
/*         sigzm    the sum of equivalent concentrations of aqueous */
/*                  ions, sigzc + sigza */
/*         sigzi    the calculated charge imbalance, sigzc - sigza */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jsort;
    --conc;
    --z__;

    /* Function Body */
    *sigzc = 0.f;
    *sigza = 0.f;
    *sigzm = 0.f;
    *sigzi = 0.f;

/*     note - this calculation presumes that either conc(1) or */
/*     z(1) is zero, so that there is no contribution from */
/*     the solvent.  it is always safe to assume that z(1) = 0. */

    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = jsort[nss];
	if (z__[ns] > 0.f) {
	    ec = z__[ns] * conc[ns];
	    *sigzc += ec;
	    *sigzi += ec;
	    *sigzm += ec;
	} else if (z__[ns] < 0.f) {
	    ec = -z__[ns] * conc[ns];
	    *sigza += ec;
	    *sigzi -= ec;
	    *sigzm += ec;
	}
/* L10: */
    }

    return 0;
} /* gszm_ */

/* gtime    last revised 07/06/87 by tjw */
/* *gtime f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int gtime_(char *utime, ftnlen utime_len)
{

/*     get time in ascii (ridge/sun dependent) */
/*     see also timdat */
/*     utime is returned in the form  hh:mm:ss */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     fdate is a ridge/sun routine */

/* DAS      call fdate(utd) */
/* DAS      utime = utd(12:19) */
    return 0;
} /* gtime_ */

/* gxi      last revised 10/30/87 by tjw */
/* *gxi created in f77  10/27/87 by tjw */
/* Subroutine */ int gxi_(doublereal *zsq2, doublereal *conc, integer *jsort, 
	integer *nst, doublereal *xic)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns, nss;


/*     this routine calculates the ion strength.  note that a sorted */
/*     summation is used. */

/*       input */
/*         zsq2    array of charge squared factors 0.5 * zi * zi */
/*         conc    array of concentrations  mi */
/*         jsort   array of aqueous species indices, in order of */
/*                 increasing concentration */
/*         nst     number of elements in array */

/*       output */
/*         xic     ionic strength */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jsort;
    --conc;
    --zsq2;

    /* Function Body */
    *xic = 0.f;

/*     note - this calculation presumes that either conc(1) or */
/*     zsq2(1) is zero, so that there is no contribution from */
/*     the solvent.  it is always safe to assume that zsq2(1) = 0. */

    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = jsort[nss];
	*xic += zsq2[ns] * conc[ns];
/* L10: */
    }

    return 0;
} /* gxi_ */

/* gxisto   last revised 11/03/87 by tjw */
/* *gxisto f77 check, ok 07/08/87 by tjw */
/* Subroutine */ int gxisto_(doublereal *zsq2, doublereal *conc, integer *nsq,
	 doublereal *concbs, doublereal *xistoc)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns;


/*     this routine was formerly known as truexi. */
/*     for hkf equations--calculates xistoc (stoichiometric ionic strength) */

/*     input */
/*       zsq2    array of one-half the charge squared */
/*       conc    array of concentrations  mi */
/*       nsq     number of basis species */
/*     output */
/*       xistoc  stochiometric ionic strength -- */
/*                     sum of (1/2)*z*z*(total conc of basis species) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */


/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */


/* ---------------------------------------------------------------------- */

/*     calculate xistoc */

    /* Parameter adjustments */
    --concbs;
    --conc;
    --zsq2;

    /* Function Body */
    *xistoc = 0.f;
    i__1 = *nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	*xistoc += zsq2[ns] * concbs[ns];
/* L20: */
    }

    return 0;
} /* gxisto_ */

/* gxistq   last revised 10/30/87 by tjw */
/* *gxistq created in f77  10/27/87 by tjw */
/* Subroutine */ int gxistq_(doublereal *store, doublereal *conc, integer *
	jsort, integer *nst, doublereal *xistqc)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ns, nss;


/*     this routine calculates the equivalent stoichiometric */
/*     ionic strength used to estimate the activity of water */
/*     when using the bdot option.  note that a sorted summation is used. */

/*       input */
/*         store   array of stoichiometric factors */
/*         conc    array of concentrations  mi */
/*         jsort   array of aqueous species indices, in order of */
/*                 increasing concentration */
/*         nst     number of elements in array */

/*       output */
/*         xistqc     equivalent stoichiometric ionic strength */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jsort;
    --conc;
    --store;

    /* Function Body */
    *xistqc = 0.f;

/*     note - this calculation presumes that either conc(1) or */
/*     store(1) is zero, so that there is no contribution from */
/*     the solvent.  it should be safe to assume that store(1) = 0. */

    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = jsort[nss];
	*xistqc += store[ns] * conc[ns];
/* L10: */
    }

    return 0;
} /* gxistq_ */

/* hjdd     last revised 07/06/87 by tjw */
/* *hjdd f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int hjdd_(doublereal *x, doublereal *rjz, doublereal *rjz1, 
	doublereal *rjz2, integer *ier)
{
    /* Initialized data */

    static struct {
	doublereal fill_1[21];
	doublereal e_2[2];
	} equiv_556 = { {0}, 0., 0. };

#define b ((doublereal *)&equiv_556)

    static struct {
	doublereal fill_1[21];
	doublereal e_2[2];
	} equiv_557 = { {0}, 0., 0. };

#define d__ ((doublereal *)&equiv_557)

    static struct {
	doublereal fill_1[21];
	doublereal e_2[2];
	} equiv_558 = { {0}, 0., 0. };

#define e ((doublereal *)&equiv_558)

    static doublereal ai[21] = { 1.925154014814667,-.060076477753119,
	    -.029779077456514,-.007299499690937,3.88260636404e-4,
	    6.36874599598e-4,3.6583601823e-5,-4.5036975204e-5,-4.53789571e-6,
	    2.937706971e-6,3.96566462e-7,-2.02099617e-7,-2.5267769e-8,
	    1.352261e-8,1.229405e-9,-8.21969e-10,-5.0847e-11,4.6333e-11,
	    1.943e-12,-2.563e-12,-1.0991e-11 };
    static doublereal aii[21] = { .628023320520852,.462762985338493,
	    .150044637187895,-.028796057604906,-.036552745910311,
	    -.001668087945272,.006519840398744,.001130378079086,
	    -8.87171310131e-4,-2.42107641309e-4,8.7294451594e-5,
	    3.4682122751e-5,-4.583768938e-6,-3.548684306e-6,-2.5045388e-7,
	    2.16991779e-7,8.077957e-8,4.558555e-9,-6.944757e-9,-2.849257e-9,
	    2.37816e-10 };
    static doublereal cii = .222222222222222;
    static doublereal d1j = .8;
    static doublereal d1k = -.444444444444444;
    static doublereal d1l = -1.1;
    static doublereal d2i = -.64;
    static doublereal d2j = -1.8;
    static doublereal d2k = .488888888888889;
    static doublereal d2l = -2.1;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double log(doublereal), exp(doublereal);

    /* Local variables */
    static integer k;
    static doublereal z__;
    static integer ki;
    static doublereal dz, dz2, alx, bdif, ddif, edif;


/*     input x */
/*     compute rjz = j0(x) */
/*             rjz1 = j0'(x) */
/*             rjz2 = j0''(x) */

/*     ier = 0/-1  ok/x out of range */
/*     x must be .gt. 0 and .le. 900. */

/*     reference - harvie (1981), appendix b */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */





/* ---------------------------------------------------------------------- */

    *rjz = 0.f;
    *rjz1 = 0.f;
    *rjz2 = 0.f;
    *ier = -1;

    if (*x <= 0.f || *x > 900.f) {
	goto L999;
    }
    *ier = 0;
    alx = log(*x);

    if (*x <= 1.f) {
/*                             *---------------------------------------- */
/*                             * case i here */
/*                             *---------------------------------------- */
	z__ = exp(alx / 5.f) * 4.f - 2.f;
	dz = d1j * exp(-alx * d1j);
	dz2 = d2i * exp(alx * d2j);

/*       generate the b's, d's and e's */

	for (ki = 1; ki <= 21; ++ki) {
	    k = 22 - ki;
	    b[k - 1] = z__ * b[k] - b[k + 1] + ai[k - 1];
	    d__[k - 1] = b[k] + z__ * d__[k] - d__[k + 1];
	    e[k - 1] = d__[k] * 2.f + z__ * e[k] - e[k + 1];
/* L10: */
	}

    } else {
/*                             *---------------------------------------- */
/*                             * case ii here */
/*                             *---------------------------------------- */
	z__ = cii * (exp(-alx / 10.f) * 20.f - 11.f);
	dz = d1k * exp(alx * d1l);
	dz2 = d2k * exp(alx * d2l);

/*       generate the b's, d's and e's */

	for (ki = 1; ki <= 21; ++ki) {
	    k = 22 - ki;
	    b[k - 1] = z__ * b[k] - b[k + 1] + aii[k - 1];
	    d__[k - 1] = b[k] + z__ * d__[k] - d__[k + 1];
	    e[k - 1] = d__[k] * 2.f + z__ * e[k] - e[k + 1];
/* L50: */
	}
    }

/* ----------------------------------------------------------------------- */

/*     compute (b0 - b2), (d0 - d2), and (e0 - e2) */

    bdif = b[0] - b[2];
    ddif = d__[0] - d__[2];
    edif = e[0] - e[2];

    *rjz = *x / 4.f - 1.f + bdif / 2.f;
    *rjz1 = dz * .5f * ddif + .25f;
/* Computing 2nd power */
    d__1 = dz;
    *rjz2 = (edif * (d__1 * d__1) + ddif * dz2) * .5f;

L999:
    return 0;
} /* hjdd_ */

#undef e
#undef d__
#undef b


/* hkfrd    last revised 07/24/87 by rmm */
/* *hkfrd f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int hkfrd_(char *uspec, integer *jsflag, integer *nad1, 
	integer *nst, ftnlen uspec_len)
{
    /* Initialized data */

    static char uendit[8] = "endit.  ";
    static char ufnam1[8] = "hkf     ";

    /* Format strings */
    static char fmt_1003[] = "(\002 * error - data file error at start of hk"
	    "f data\002,/3x,\002key= \002,a8,\002, correct key= \002,a8,/5x"
	    ",\002append the correct hkf data to\002,\002 data1 or data2 and "
	    "try again\002,/5x,\002do not change the key (eqlib/hkfrd)\002)";
    static char fmt_1010[] = "(\002 * error, omega array overflow (eqlib/hkf"
	    "rd)\002)";
    static char fmt_1030[] = "(/,\002    name                   omega       "
	    "      \002)";
    static char fmt_1040[] = "(x,a24,2x,e15.5)";
    static char fmt_1050[] = "(/,\002    name            name              b"
	    "ji   \002)";
    static char fmt_1060[] = "(x,a24,2x,a24,2x,e15.5)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void),
	     s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, n, jj, ix1, ix2;
    static char udum[8], unam1[24], unam2[24];
    extern /* Subroutine */ int srchn_(char *, integer *, char *, integer *, 
	    ftnlen, ftnlen);
    static doublereal bjitmp, omgtmp;

    /* Fortran I/O blocks */
    static cilist io___562 = { 0, 0, 0, 0, 0 };
    static cilist io___564 = { 0, 0, 0, fmt_1003, 0 };
    static cilist io___565 = { 0, 0, 0, fmt_1003, 0 };
    static cilist io___567 = { 0, 0, 0, 0, 0 };
    static cilist io___568 = { 0, 0, 0, 0, 0 };
    static cilist io___572 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___573 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___574 = { 0, 0, 0, 0, 0 };
    static cilist io___578 = { 0, 0, 0, fmt_1030, 0 };
    static cilist io___580 = { 0, 0, 0, fmt_1040, 0 };
    static cilist io___581 = { 0, 0, 0, fmt_1050, 0 };
    static cilist io___582 = { 0, 0, 0, fmt_1060, 0 };



/*        created 17sept86  rmm */

/*     read hkf (part iv) parameter base values from data file nad1 */

/*     called by subprogram indpt */
/*      input  uspec   array of species names */
/*             jsflag  array of status switches, aqueous species */
/*             nad1    unit number of input file */
/*             nst     number of aqueous species */

/*      output parameters are in common /eqlhkf/ */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */

/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* -------------------------------------------------------------------- */
/* eqlun.h */

    /* Parameter adjustments */
    --jsflag;
    uspec -= 24;

    /* Function Body */

/* ---------------------------------------------------------------------- */
    jj = 0;

/*     read header line */

    io___562.ciunit = *nad1;
    s_rsue(&io___562);
    do_uio(&c__1, udum, (ftnlen)8);
    e_rsue();
    if (s_cmp(udum, ufnam1, (ftnlen)8, (ftnlen)8) != 0) {
	io___564.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___564);
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, ufnam1, (ftnlen)8);
	e_wsfe();
	io___565.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___565);
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, ufnam1, (ftnlen)8);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     read a four line title */

    for (i__ = 1; i__ <= 4; ++i__) {
	io___567.ciunit = *nad1;
	s_rsue(&io___567);
	do_uio(&c__1, eqlgpc_1.udhkf + (i__ - 1) * 80, (ftnlen)80);
	e_rsue();
/* L5: */
    }


/*               single ion parameter - omega */
/*               read in one line */

L310:
    io___568.ciunit = *nad1;
    s_rsue(&io___568);
    do_uio(&c__1, unam1, (ftnlen)24);
    do_uio(&c__1, (char *)&omgtmp, (ftnlen)sizeof(doublereal));
    e_rsue();
    if (s_cmp(unam1, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	goto L400;
    }

/*               map ion name to index */

    srchn_(uspec + 24, nst, unam1, &ix1, (ftnlen)24, (ftnlen)24);

/*               skip if species not found */

    if (ix1 <= 0) {
	goto L310;
    }

/*               skip if ion is not in current model */

    if (jsflag[ix1] != 0) {
	goto L310;
    }

/*               put into common */

    ++jj;
    if (jj > eqlhkf_1.ibjmax) {
	io___572.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___572);
	e_wsfe();
	io___573.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___573);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    eqlhkf_1.indx1[jj - 1] = ix1;
    eqlhkf_1.omega[jj - 1] = omgtmp;

    goto L310;

L400:
    eqlhkf_1.ibjuse = jj;
    jj = 0;

/*               do ion-ion parameters */

L410:
    io___574.ciunit = *nad1;
    s_rsue(&io___574);
    do_uio(&c__1, unam1, (ftnlen)24);
    do_uio(&c__1, unam2, (ftnlen)24);
    do_uio(&c__1, (char *)&bjitmp, (ftnlen)sizeof(doublereal));
    e_rsue();
    if (s_cmp(unam1, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	goto L500;
    }

/*               map ion names to indexes */

    srchn_(uspec + 24, nst, unam1, &ix1, (ftnlen)24, (ftnlen)24);
    srchn_(uspec + 24, nst, unam2, &ix2, (ftnlen)24, (ftnlen)24);

/*               skip if species not found */

    if (ix1 <= 0 || ix2 <= 0) {
	goto L410;
    }

/*               skip if not in current model */

    if (jsflag[ix1] != 0 || jsflag[ix2] != 0) {
	goto L410;
    }

/*                put into common */

    ++jj;
    eqlhkf_1.indx2[(jj << 1) - 2] = ix1;
    eqlhkf_1.indx2[(jj << 1) - 1] = ix2;
    eqlhkf_1.bji[jj - 1] = bjitmp;

    goto L410;

L500:
    eqlhkf_1.ibjius = jj;

/*              print out both single and double interaction parms */

    io___578.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___578);
    e_wsfe();

    i__1 = eqlhkf_1.ibjuse;
    for (n = 1; n <= i__1; ++n) {
	io___580.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___580);
	do_fio(&c__1, uspec + eqlhkf_1.indx1[n - 1] * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&eqlhkf_1.omega[n - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
/* L600: */
    }

    io___581.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___581);
    e_wsfe();

    i__1 = eqlhkf_1.ibjius;
    for (n = 1; n <= i__1; ++n) {
	io___582.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___582);
	do_fio(&c__1, uspec + eqlhkf_1.indx2[(n << 1) - 2] * 24, (ftnlen)24);
	do_fio(&c__1, uspec + eqlhkf_1.indx2[(n << 1) - 1] * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&eqlhkf_1.bji[n - 1], (ftnlen)sizeof(doublereal)
		);
	e_wsfe();
/* L700: */
    }

    return 0;
} /* hkfrd_ */

/* hpsat    last revised 01/26/88 by tjw */
/* *hpsat partial f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int hpsat_(doublereal *axx, doublereal *si, doublereal *affx,
	 doublereal *lamlg, doublereal *xbarlg, doublereal *xbar, doublereal *
	w, doublereal *xbarh, doublereal *xqkx, doublereal *xlkm, doublereal *
	afflcx, doublereal *siss, doublereal *aff, doublereal *al10, 
	doublereal *fo2lg, doublereal *tempk, doublereal *rconst, char *ussnp,
	 char *umin, integer *nend, integer *jsflag, integer *jmflag, integer 
	*jxflag, integer *ncomp, integer *jsol, integer *itracx, integer *nsb,
	 integer *nsq, integer *nsq1, integer *nnm1, integer *iktmax, integer 
	*nx, integer *ier, integer *nn, integer *idbg, integer *ndbug1, 
	ftnlen ussnp_len, ftnlen umin_len)
{
    /* Initialized data */

    static integer nsize = 12;
    static doublereal alpha[3] = { 1.,.5,2. };
    static doublereal deps[2] = { 0.,1e-7 };
    static integer imin = 1;
    static doublereal amult = .05;

    /* Format strings */
    static char fmt_131[] = "(\002 for ideal solution\002)";
    static char fmt_121[] = "(\002 component  mole percent     ksp\002)";
    static char fmt_122[] = "(4x,i2,7x,g9.3,5x,f6.2,5x,g10.4,1x,g10.3)";
    static char fmt_123[] = "(9x,\002sum=\002,f6.1)";
    static char fmt_1050[] = "(2x,\002optimum value =\002,1pd10.2)";
    static char fmt_1002[] = "(5x,\002  mole fractions                functi"
	    "on value\002)";
    static char fmt_126[] = "(\002 component  mole percent     ksp        ac"
	    "t coef\002)";
    static char fmt_127[] = "(4x,i2,7x,g9.3,5x,f6.2,5x,g10.4)";
    static char fmt_128[] = "(9x,\002sum=\002,f6.1)";
    static char fmt_1051[] = "(2x,\002itr=\002,i5,5x,\002ier=\002,i2,/2x,"
	    "\002optimum value =\002,1pd10.2,/2x,\002mole fractions = \002,10"
	    "(/,g11.3))";

    /* System generated locals */
    integer ussnp_dim1, ussnp_offset, axx_dim1, axx_offset, affx_dim1, 
	    affx_offset, xbar_dim1, xbar_offset, lamlg_dim1, lamlg_offset, 
	    si_dim1, si_offset, w_dim1, w_offset, xbarlg_dim1, xbarlg_offset, 
	    nend_dim1, nend_offset, i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, 
	    char *, ftnlen);
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, ik, nm;
    extern doublereal tlg_(doublereal *);
    static integer nit, itr;
    static doublereal sum, xxx, fmin;
    static integer nold, ncpt;
    extern doublereal texp_(doublereal *);
    extern /* Subroutine */ int lamda_(doublereal *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static doublereal xbarf, afkst, press, lamdax;
    extern doublereal ssfunc_(doublereal *, integer *, doublereal *, integer *
	    , doublereal *, doublereal *, integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);
    extern /* Subroutine */ int dsiplx_(D_fp, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___591 = { 0, 0, 0, 0, 0 };
    static cilist io___593 = { 0, 0, 0, fmt_131, 0 };
    static cilist io___594 = { 0, 0, 0, fmt_121, 0 };
    static cilist io___595 = { 0, 0, 0, fmt_122, 0 };
    static cilist io___596 = { 0, 0, 0, fmt_123, 0 };
    static cilist io___597 = { 0, 0, 0, fmt_1050, 0 };
    static cilist io___605 = { 0, 0, 0, fmt_1002, 0 };
    static cilist io___609 = { 0, 0, 0, 0, 0 };
    static cilist io___611 = { 0, 0, 0, fmt_126, 0 };
    static cilist io___612 = { 0, 0, 0, fmt_127, 0 };
    static cilist io___613 = { 0, 0, 0, fmt_128, 0 };
    static cilist io___614 = { 0, 0, 0, fmt_1051, 0 };



/*     dimension axx(iktpar,iktpar),xbarh(iktpar),xqkx(iktpar),itracx(iktpar) */

/*     this routine calculates the most stable (least soluble) */
/*     composition of a given solid solution, given the composition */
/*     of the aqueous phase it is in equilibrium with.  it first */
/*     solves for the case of ideal mixing.  if the input data for */
/*     the solid solution include data for a non-ideal mixing model, */
/*     the ideal composition is used as a starting estimate for the */
/*     solution to the non-ideal case */

/*     routines called: */

/*     ssfunc    function that computes value of saturation index */
/*     dsiplx    routine that finds maximum of function using */
/*               simplex method (non-linear) */
/*     lamda    routine that returns activity coefficients */
/*               for components of solid solution (regular soln) */

/*     variables: */

/*     ncomp     number of components in solid solution mineral in data */
/*               base */
/*     nn        number of components in solid solution present in */
/*               problem */
/*     nnm1      number of independent components (nn-1) */
/*     xlkm      array of log solubility products of endmembers of */
/*               solid solutions */
/*     xqkx      saturation indices for endmember components */
/*     aff       array holding affinities for all mineral phases */
/*     lamlg     array of log activity coefficients for components of */
/*               solid solution */
/*     xbarh     array that holds solid solution composition in */
/*               in subroutine dsiplx */
/*     xbar      array that holds composition of solid solution */
/*               in subroutines hpsat, ssfunc and at output */
/*               (note that xbar has the same dimension as the */
/*                total number of components for a solid solution */
/*                in the data base; comp holds a compressed version */
/*                of xbar with the zeros removed.  comp is passed */
/*                to dsiplx) */
/*     axx       the first column of this 2-d array initially holds the */
/*               ideal composition used as a starting estimate. the */
/*               last column x(10,nn) holds the simplex net coordinates. */
/*               after convergence, the array 'comp' is returned that */
/*               holds the solution. */
/*     siss      saturation index for solid solution */
/*     jmflag    suppress endmember solid (2-suppress 0-leave it) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */




/* ----------------------------------------------------------------------- */

/*     note- in the future, should pass afcnst instead of defining afkst; */
/*           also, should pass and use jkflag instead of jmflag - tjw */

    /* Parameter adjustments */
    --xbarh;
    --xqkx;
    --xlkm;
    --afflcx;
    --siss;
    --aff;
    umin -= umin_len;
    --jsflag;
    --jmflag;
    --jxflag;
    --ncomp;
    --jsol;
    --itracx;
    nend_dim1 = *iktmax;
    nend_offset = 1 + nend_dim1;
    nend -= nend_offset;
    ussnp_dim1 = *iktmax;
    ussnp_offset = 1 + ussnp_dim1;
    ussnp -= ussnp_offset * ussnp_len;
    w_dim1 = *iktmax;
    w_offset = 1 + w_dim1;
    w -= w_offset;
    xbar_dim1 = *iktmax;
    xbar_offset = 1 + xbar_dim1;
    xbar -= xbar_offset;
    xbarlg_dim1 = *iktmax;
    xbarlg_offset = 1 + xbarlg_dim1;
    xbarlg -= xbarlg_offset;
    lamlg_dim1 = *iktmax;
    lamlg_offset = 1 + lamlg_dim1;
    lamlg -= lamlg_offset;
    affx_dim1 = *iktmax;
    affx_offset = 1 + affx_dim1;
    affx -= affx_offset;
    si_dim1 = *iktmax;
    si_offset = 1 + si_dim1;
    si -= si_offset;
    axx_dim1 = *iktmax;
    axx_offset = 1 + axx_dim1;
    axx -= axx_offset;

    /* Function Body */
    afkst = *al10 * .001f * *rconst * *tempk;

/*     if solid solution is suppressed, return */

    if (jxflag[*nx] == 4) {
	goto L999;
    }

/*     initialize error flag, affinity function, and sum of q/k values */

    *ier = 0;
    afflcx[*nx] = -999.f;
    sum = 0.f;

/*     look through array of solid solution endmembers to see */
/*     how many are present in this problem and calculate q/k */
/*     ratios for those present */

    ncpt = ncomp[*nx];
    *nn = ncpt;
    i__1 = ncpt;
    for (ik = 1; ik <= i__1; ++ik) {
	xbar[ik + *nx * xbar_dim1] = 0.f;
	xbarlg[ik + *nx * xbarlg_dim1] = -999.f;
	affx[ik + *nx * affx_dim1] = -999.f;
	nm = nend[ik + *nx * nend_dim1];

/*     transfer name of solid not present to ussnp */

/*     note- should test on jkflag here.  then we might be able to */
/*     eliminate the test below on sum - tjw */

	if (jmflag[nm] >= 2) {
	    s_copy(ussnp + (ik + *nx * ussnp_dim1) * ussnp_len, umin + nm * 
		    umin_len, ussnp_len, umin_len);
	    nend[ik + *nx * nend_dim1] = 0;
	    nm = 0;
	}
	if (nm == 0) {
	    --(*nn);
	    goto L10;
	}

/*     get q/k values from array arr and sum them */

	xxx = aff[nm] / afkst;
	xqkx[ik] = texp_(&xxx);
	sum += xqkx[ik];
L10:
	;
    }

/*     return if no components present */

    if (*nn < 1) {
	goto L999;
    }
/*     save this nn value */
    nold = *nn;

/*     return if all components are effectively suppressed */

    if (sum <= 0.f) {
	goto L999;
    }

/*   now calculate composition assuming ideal solution */

/*     analytic solution is this: */

/*        xi = q/k / (sum of all the q/k values) */

    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
/*     initialize itracx array */
	itracx[i__] = 0;
	if (nend[i__ + *nx * nend_dim1] == 0) {
	    goto L30;
	}
	xbar[i__ + *nx * xbar_dim1] = xqkx[i__] / sum;
	if (xbar[i__ + *nx * xbar_dim1] < 0.f) {
	    io___591.ciunit = eqlun_1.noutpl;
	    s_wsle(&io___591);
	    do_lio(&c__9, &c__1, "xbar(", (ftnlen)5);
	    do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&(*nx), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, "< 0", (ftnlen)3);
	    e_wsle();
	}

/*     check for trace components - if one is present and a non-ideal */
/*     solution model is operative, remove that component and recalculate */
/*     its mole fraction after the non-ideal solution is obtained. */

	if (xbar[i__ + *nx * xbar_dim1] < 1e-8f) {
/*       reduce number of active components */
	    --(*nn);
/*       flag for trace components */
	    itracx[i__] = 1;
/*       log mole fraction */
	}
	xbarlg[i__ + *nx * xbarlg_dim1] = tlg_(&xbar[i__ + *nx * xbar_dim1]);
L30:
	;
    }

/*     compute value of saturation index and affinity */

/*     afflcx - affinity for solid solution */
/*     affx   - affinity for endmember of solid solution */
/*     si     - saturation index for solid solution endmember */
/*     siss   - saturation index for solid solution */

    siss[*nx] = 0.f;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
/*     skip if component not present */
	if (nend[i__ + *nx * nend_dim1] == 0) {
	    goto L110;
	}
/*     def of si for endmember */
	xbarf = xbar[i__ + *nx * xbar_dim1];
	if (xbarf <= 0.f) {
	    xbarf = 1e-25f;
	}
	d__1 = xqkx[i__] / xbarf;
	si[i__ + *nx * si_dim1] = tlg_(&d__1);
/*     affinity for endmember */
	affx[i__ + *nx * affx_dim1] = afkst * si[i__ + *nx * si_dim1];
/*     affinity for solid solution */
	siss[*nx] += si[i__ + *nx * si_dim1] * xbar[i__ + *nx * xbar_dim1];
L110:
	;
    }
/*     si for solid solution */
    afflcx[*nx] = siss[*nx] * afkst;

/*     output results to dbug1 */

    if (*idbg <= 0) {
	goto L1001;
    }
    io___593.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___593);
    e_wsfe();
    io___594.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___594);
    e_wsfe();
    sum = 0.f;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	io___595.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___595);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	d__1 = xbar[i__ + *nx * xbar_dim1] * 100.f;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xlkm[nend[i__ + *nx * nend_dim1]], (ftnlen)
		sizeof(doublereal));
	e_wsfe();
	sum += xbar[i__ + *nx * xbar_dim1];
/* L120: */
    }
    io___596.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___596);
    d__1 = sum * 100.f;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___597.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___597);
    do_fio(&c__1, (char *)&afflcx[*nx], (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     test for non-ideal solution */

L1001:
    if (jsol[*nx] == 0) {
	goto L1000;
    }
/*     if only one major component-abort */
    if (*nn == 1) {
	goto L1000;
    }

/*     non-ideal solid solution */

/*     initialize max number iterations */
    itr = 200;

/*     parameters needed by dsiplx */
/*     itr       - maximum number of iterations */
/*     imin      - find maximum for function when imin=1 */
/*     alpha     - see subroutine writeup */
/*     amulvt    - multiplier for simplex grid */
/*     deps(1)    - absolute precision desired  (= 0.0) */
/*     deps(2)    - maximum difference between last two iterations. */

/*     put ideal solution into first column of matrix x that dsiplx uses */
/*     as starting estimate */

    *nnm1 = *nn - 1;
    j = 0;
/*     strip array holding composition of */
    i__1 = *nnm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/*     all absent and trace components */
	++j;
L15:
	if ((real) nend[j + *nx * nend_dim1] != 0.f && itracx[j] == 0) {
	    goto L16;
	}
	++j;
	goto L15;
L16:
	axx[i__ + axx_dim1] = xbar[j + *nx * xbar_dim1];
/* L14: */
    }

/*     create simplex net */

    i__1 = *nnm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/*     put initial guess in last col */
	axx[i__ + *nn * axx_dim1] = amult * axx[i__ + axx_dim1];
/* L13: */
    }
    if (*idbg >= 1) {
	io___605.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___605);
	e_wsfe();
    }

/*     call simplex routine */

    dsiplx_((D_fp)ssfunc_, &axx[axx_offset], nnm1, &nsize, alpha, deps, &imin,
	     &itr, &xbarh[1], &fmin, &nit, &nend[nend_offset], &w[w_offset], 
	    ndbug1, &eqlun_1.nttyol, &eqlun_1.noutpl, &xbar[xbar_offset], &
	    lamlg[lamlg_offset], &ncomp[1], iktmax, &jsol[1], nn, &xqkx[1], 
	    nx, tempk, &press, al10, rconst, &afkst, idbg);

/*     composition of solid solution is now in array 'xbarh' */
/*     this array contains only nn-1 mole fractions, the last */
/*     component is fixed by the sum of the others. */

    sum = 0.f;
    i__1 = *nnm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum += xbarh[i__];
/* L9: */
    }
/*     composition of last component */
    xbarh[*nn] = 1.f - sum;

/*     convert array xbarh back to xbar putting back in zeros for */
/*     components not present in current problem */

    j = 1;
/*     nn # components present, check to see if xbarh is present, */
/*     if not, increment index */
    i__1 = *nn;
    for (i__ = 1; i__ <= i__1; ++i__) {
L44:
	if (nend[i__ + *nx * nend_dim1] != 0 && itracx[i__] == 0) {
	    goto L45;
	}
	++j;
	goto L44;
L45:
	xbar[j + *nx * xbar_dim1] = xbarh[i__];
	if (xbar[j + *nx * xbar_dim1] < 0.f) {
	    io___609.ciunit = eqlun_1.noutpl;
	    s_wsle(&io___609);
	    do_lio(&c__9, &c__1, "xbar(", (ftnlen)5);
	    do_lio(&c__3, &c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&(*nx), (ftnlen)sizeof(integer));
	    do_lio(&c__9, &c__1, " < 0", (ftnlen)4);
	    e_wsle();
	}
/*     log mole fraction */
	xbarlg[j + *nx * xbarlg_dim1] = tlg_(&xbarh[i__]);
	++j;
/* L26: */
    }

/*     recompute mole fractions of trace components using activity */
/*     coefficients for major components */

    lamda_(al10, &jsol[1], &lamlg[lamlg_offset], &ncomp[1], nx, rconst, tempk,
	     &xbar[xbar_offset], &w[w_offset], iktmax);
/*     initialize sum of q/k values */
    sum = 0.f;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	nm = nend[i__ + *nx * nend_dim1];
	if (nm == 0) {
	    goto L17;
	}
	xxx = lamlg[i__ + *nx * lamlg_dim1];
	lamdax = texp_(&xxx);
	sum += xqkx[i__] / lamdax;
L17:
	;
    }
/*     recalculate only trace components */
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (nend[i__ + *nx * nend_dim1] == 0 || itracx[i__] == 0) {
	    goto L32;
	}
	xbar[i__ + *nx * xbar_dim1] = xqkx[i__] / sum;
	xbarlg[i__ + *nx * xbarlg_dim1] = tlg_(&xbar[i__ + *nx * xbar_dim1]);
L32:
	;
    }
    siss[*nx] = 0.f;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	lamdax = pow_dd(&c_b158, &lamlg[i__ + *nx * lamlg_dim1]);
/*     skip if component not present */
	if (nend[i__ + *nx * nend_dim1] == 0) {
	    goto L111;
	}
/*     def of si for endmember */
	d__1 = xqkx[i__] / xbar[i__ + *nx * xbar_dim1] / lamdax;
	si[i__ + *nx * si_dim1] = tlg_(&d__1);
/*     affinity for endmember */
	affx[i__ + *nx * affx_dim1] = afkst * si[i__ + *nx * si_dim1];
/*     affinity for solid solution */
	siss[*nx] += si[i__ + *nx * si_dim1] * xbar[i__ + *nx * xbar_dim1];
L111:
	;
    }

/*     si for solid solution */
    afflcx[*nx] = siss[*nx] * afkst;

/*     now print it out */

/*     skip debug output if desired */
    if (*idbg == 0) {
	goto L1000;
    }

    io___611.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___611);
    e_wsfe();
    sum = 0.f;
    i__1 = ncomp[*nx];
    for (i__ = 1; i__ <= i__1; ++i__) {
	io___612.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___612);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	d__1 = xbar[i__ + *nx * xbar_dim1] * 100.f;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xlkm[nend[i__ + *nx * nend_dim1]], (ftnlen)
		sizeof(doublereal));
	d__2 = pow_dd(&c_b158, &lamlg[i__ + *nx * lamlg_dim1]);
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	e_wsfe();
	sum += xbar[i__ + *nx * xbar_dim1];
/* L125: */
    }
    io___613.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___613);
    d__1 = sum * 100.f;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___614.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___614);
    do_fio(&c__1, (char *)&nit, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ier), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&fmin, (ftnlen)sizeof(doublereal));
    i__1 = ncomp[*nx];
    for (j = 1; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&xbarh[j], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
L1000:
    *nn = nold;

L999:
    return 0;
} /* hpsat_ */

/* indatc  last revised 12/02/87 by tjw */
/* *indatc created in f77 12/02/87 by tjw */
/* Subroutine */ int indatc_(doublereal *arr, integer *nf, integer *narxmx, 
	integer *ntprmx)
{
    /* System generated locals */
    integer arr_dim1, arr_offset, i__1, i__2;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);

    /* Local variables */
    static integer i__;
    static char ustr[8];

    /* Fortran I/O blocks */
    static cilist io___615 = { 0, 0, 0, 0, 0 };



/*     this routine reads an unformatted data file in order to load */
/*     a two-dimensional array arr with polynomial coefficients */
/*     for describing a thermodynamic property as a function of */
/*     temperature.  this routine is identical to indatk.f, except */
/*     that in that routine the array arr is three-dimensional and its */
/*     calling sequence contains an additional variable. */

/*     input */
/*       nf = file unit number of an unformatted data file */
/*       narxmx = first dimension of the arr array, the number */
/*                of coefficients per temperature range */
/*       ntprmx = second dimension of the arr array, the number */
/*                of temperature ranges. */

/*     output */
/*       arr = two dimensional array of polynomial coefficients */
/*             describing some thermodynamic function */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     read (nf) ustr,((arr(i,j), i=1,narxmx), j=1,ntprmx) */
    /* Parameter adjustments */
    arr_dim1 = *narxmx;
    arr_offset = 1 + arr_dim1;
    arr -= arr_offset;

    /* Function Body */
    io___615.ciunit = *nf;
    s_rsue(&io___615);
    do_uio(&c__1, ustr, (ftnlen)8);
    i__1 = *narxmx;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&arr[i__ + arr_dim1], (ftnlen)sizeof(doublereal)
		);
    }
    i__2 = *narxmx;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&arr[i__ + (arr_dim1 << 1)], (ftnlen)sizeof(
		doublereal));
    }
    e_rsue();

    return 0;
} /* indatc_ */

/* indatk  last revised 12/01/87 by tjw */
/* *indatk created in f77 12/01/87 by tjw */
/* Subroutine */ int indatk_(integer *k, doublereal *arr, integer *nf, 
	integer *narxmx, integer *ntprmx)
{
    /* System generated locals */
    integer arr_dim1, arr_dim2, arr_offset, i__1, i__2;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);

    /* Local variables */
    static integer i__;
    static char ustr[8];

    /* Fortran I/O blocks */
    static cilist io___618 = { 0, 0, 0, 0, 0 };



/*     this routine reads an unformatted data file in order to load */
/*     a three-dimensional array arr with polynomial coefficients */
/*     for describing a thermodynamic property as a function of */
/*     temperature.  this routine is identical to indatk.c, except */
/*     that in that routine the array arr is two-dimensional and */
/*     its calling seqence does not contain the variable k. */

/*     input */
/*       k = index for the third dimension of array arr */
/*       nf = file unit number of an unformatted data file */
/*       narxmx = first dimension of the arr array, the number */
/*                of coefficients per temperature range */
/*       ntprmx = second dimension of the arr array, the number */
/*                of temperature ranges. */

/*     output */
/*       arr = two dimensional array of polynomial coefficients */
/*             describing some thermodynamic function */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     read (nf) ustr,((arr(i,j,k), i=1,narxmx), j=1,ntprmx) */
    /* Parameter adjustments */
    arr_dim1 = *narxmx;
    arr_dim2 = *ntprmx;
    arr_offset = 1 + arr_dim1 * (1 + arr_dim2);
    arr -= arr_offset;

    /* Function Body */
    io___618.ciunit = *nf;
    s_rsue(&io___618);
    do_uio(&c__1, ustr, (ftnlen)8);
    i__1 = *narxmx;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&arr[i__ + (*k * arr_dim2 + 1) * arr_dim1], (
		ftnlen)sizeof(doublereal));
    }
    i__2 = *narxmx;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&arr[i__ + (*k * arr_dim2 + 2) * arr_dim1], (
		ftnlen)sizeof(doublereal));
    }
    e_rsue();

    return 0;
} /* indatk_ */

/* inupt    last revised 01/25/88 by rmm */
/* *inupt f77 rewrite, 07/06/87 by tjw */
/* Subroutine */ int inupt_(char *uspec, integer *jsflag, integer *ndats1, 
	integer *nst, integer *iopr9, ftnlen uspec_len)
{
    /* Initialized data */

    static char ufnam[8] = "dpt2    ";
    static char uendit[8] = "endit.  ";
    static char uterm[8] = "+-------";
    static char uoff[8] = "off     ";
    static char uon[8] = "on      ";
    static char uonp[8] = "onplus  ";

    /* Format strings */
    static char fmt_1003[] = "(\002 * error - data file error at start of pi"
	    "tzer data\002,/3x,\002key= \002,a8,\002, correct key= \002,a8,/5"
	    "x,\002append the correct pitzer data (in lambda and mu form) t"
	    "o\002,\002 data1 or data2 and try again\002,/5x,\002do not chang"
	    "e the key\002,\002 (eqlib/inupt)\002)";
    static char fmt_317[] = "(\002 * error - bad elambda flag on the data fi"
	    "le = \002,a8,/3x,\002allowed values are off/on/onplus (eqlib/inu"
	    "pt)\002)";
    static char fmt_1014[] = "(\002 * error - lambda array index overflow (e"
	    "qlib/inupt)\002)";
    static char fmt_1020[] = "(\002 * error - palpha array index overflow (e"
	    "qlib/inupt)\002)";
    static char fmt_1032[] = "(\002 * error -  mu array index overflow (eqli"
	    "b/inupt)\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void),
	     s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer i__, k, ja, jj, kk;
    static doublereal mu, dl1[3], dl2[3];
    static integer ix1, ix2, ix3;
    static doublereal lam[3], alx, alph[2];
    static char udum[8], unam1[24], unam2[24], unam3[24], uline[80];
    extern /* Subroutine */ int srchn_(char *, integer *, char *, integer *, 
	    ftnlen, ftnlen);
    static char udum72[72];
    static doublereal deriv1, deriv2;
    extern /* Subroutine */ int ptztab_(integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___627 = { 0, 0, 0, 0, 0 };
    static cilist io___629 = { 0, 0, 0, fmt_1003, 0 };
    static cilist io___630 = { 0, 0, 0, fmt_1003, 0 };
    static cilist io___632 = { 0, 0, 0, 0, 0 };
    static cilist io___633 = { 0, 0, 0, 0, 0 };
    static cilist io___635 = { 0, 0, 0, fmt_317, 0 };
    static cilist io___636 = { 0, 0, 0, fmt_317, 0 };
    static cilist io___640 = { 0, 0, 0, 0, 0 };
    static cilist io___643 = { 0, 0, 0, 0, 0 };
    static cilist io___645 = { 0, 0, 0, 0, 0 };
    static cilist io___647 = { 0, 0, 0, 0, 0 };
    static cilist io___650 = { 0, 0, 0, 0, 0 };
    static cilist io___654 = { 0, 0, 0, fmt_1014, 0 };
    static cilist io___655 = { 0, 0, 0, fmt_1014, 0 };
    static cilist io___658 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___659 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___660 = { 0, 0, 0, 0, 0 };
    static cilist io___662 = { 0, 0, 0, 0, 0 };
    static cilist io___666 = { 0, 0, 0, 0, 0 };
    static cilist io___668 = { 0, 0, 0, fmt_1032, 0 };
    static cilist io___669 = { 0, 0, 0, fmt_1032, 0 };



/*     adapted from indpt 1/20/87 by rlh */
/*     read pitzer parameter base values from */
/*      unformatted data file ndats1 */

/*      input  uspec   array of species names */
/*             jsflag  array of status switches, aqueous species */
/*             ndats1  unit number of unformatted input file */
/*             nst     number of aqueous species */

/*      output mu values in common /eqlpmu/ */
/*             lambda values in common /eqlpsa/ */
/*             associated alpha values in common /eqlpal/ */

/*     ndats1 is assumed to be positioned after the line */
/*     'endit.' which terminates the solid solution data */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqlpal.h */

/*      napt  total number of entries allowed */
/*      palpha  alpha pairs from file data1p */

/* ------------------------------------------------------------------- */
/* eqlpmu.h */

/*      nmu = actual number of entries in use */
/*      nmut = maximum number of entries allowed */
/*      nmux = triples of aqueous species indices */
/*      pmu = mu(ijk) values array */

/* ------------------------------------------------------------------ */
/* eqlpmb.h */
/* -------------------------------------------------------------------- */
/* eqlpsa.h */
/*      nslm  = number of entries in use */
/*      nslmt = maximum number allowed */
/*      nslmx = species index pairs */
/*      pslm =  lambda triples from file data1p */
/*      nalpha = indices into palpha array */

/* -------------------------------------------------------------------- */
/* eqlpsb.h */
/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* -------------------------------------------------------------------- */
/* eqlun.h */


    /* Parameter adjustments */
    --jsflag;
    uspec -= 24;

    /* Function Body */

/* ---------------------------------------------------------------------- */

/*      read header line */

    io___627.ciunit = *ndats1;
    s_rsue(&io___627);
    do_uio(&c__1, udum, (ftnlen)8);
    e_rsue();
    if (s_cmp(udum, ufnam, (ftnlen)8, (ftnlen)8) == 0) {
	goto L10;
    }
    io___629.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___629);
    do_fio(&c__1, udum, (ftnlen)8);
    do_fio(&c__1, ufnam, (ftnlen)8);
    e_wsfe();
    io___630.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___630);
    do_fio(&c__1, udum, (ftnlen)8);
    do_fio(&c__1, ufnam, (ftnlen)8);
    e_wsfe();
    s_stop("", (ftnlen)0);

L10:

/*     read a four line title */

    for (i__ = 1; i__ <= 4; ++i__) {
	io___632.ciunit = *ndats1;
	s_rsue(&io___632);
	do_uio(&c__1, eqlgpc_1.udpitz + (i__ - 1) * 80, (ftnlen)80);
	e_rsue();
/* L5: */
    }


/*     read and decode the elambda flag */

    s_copy(eqlgpc_1.uelam, " ", (ftnlen)8, (ftnlen)1);
    io___633.ciunit = *ndats1;
    s_rsue(&io___633);
    do_uio(&c__1, uline, (ftnlen)80);
    e_rsue();
    s_copy(eqlgpc_1.uelam, uline + 15, (ftnlen)6, (ftnlen)6);
    if (s_cmp(eqlgpc_1.uelam, uon, (ftnlen)8, (ftnlen)8) != 0) {
	goto L305;
    }
    eqlgpa_1.ielam = 0;
    goto L320;
L305:
    if (s_cmp(eqlgpc_1.uelam, uoff, (ftnlen)8, (ftnlen)8) != 0) {
	goto L310;
    }
    eqlgpa_1.ielam = -1;
    goto L320;
L310:
    if (s_cmp(eqlgpc_1.uelam, uonp, (ftnlen)8, (ftnlen)8) != 0) {
	goto L315;
    }
    eqlgpa_1.ielam = 1;
    goto L320;
L315:
    io___635.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___635);
    do_fio(&c__1, eqlgpc_1.uelam, (ftnlen)8);
    e_wsfe();
    io___636.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___636);
    do_fio(&c__1, eqlgpc_1.uelam, (ftnlen)8);
    e_wsfe();
    s_stop("", (ftnlen)0);

L320:

/*                             *---------------------------------------- */
/*                             * read lambda's and alpha's  (2 sets) */
/*                             *---------------------------------------- */
    ja = 0;
    jj = 0;

    for (kk = 1; kk <= 2; ++kk) {

L15:

/*      read a block */
/*       species names */

	io___640.ciunit = *ndats1;
	s_rsue(&io___640);
	do_uio(&c__1, unam1, (ftnlen)24);
	do_uio(&c__1, unam2, (ftnlen)24);
	e_rsue();
/* 1050 format(a12,2x,a12) */
	if (s_cmp(unam1, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L100;
	}

/*      lambda's */

	io___643.ciunit = *ndats1;
	s_rsue(&io___643);
	for (i__ = 1; i__ <= 3; ++i__) {
	    do_uio(&c__1, (char *)&lam[i__ - 1], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
/* 1052 format(3(13x,f8.4)) */

/*      alpha's */

	io___645.ciunit = *ndats1;
	s_rsue(&io___645);
	for (i__ = 1; i__ <= 2; ++i__) {
	    do_uio(&c__1, (char *)&alph[i__ - 1], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
/* 1054 format(18x,2(16x,f5.1)) */

/*      derivatives */

	for (i__ = 1; i__ <= 3; ++i__) {
	    io___647.ciunit = *ndats1;
	    s_rsue(&io___647);
	    do_uio(&c__1, (char *)&dl1[i__ - 1], (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&dl2[i__ - 1], (ftnlen)sizeof(doublereal));
	    e_rsue();
/* 1056 format(13x,e10.4,13x,e10.4) */
/* L350: */
	}

/*      skip to block terminator */

L18:
	io___650.ciunit = *ndats1;
	s_rsue(&io___650);
	do_uio(&c__1, udum72, (ftnlen)72);
	e_rsue();
	if (s_cmp(udum72, uterm, (ftnlen)8, (ftnlen)8) != 0) {
	    goto L18;
	}

/*      map 2 species names to indices */

	srchn_(uspec + 24, nst, unam1, &ix1, (ftnlen)24, (ftnlen)24);
	srchn_(uspec + 24, nst, unam2, &ix2, (ftnlen)24, (ftnlen)24);

/*      skip if either species not found */

	if (ix1 <= 0 || ix2 <= 0) {
	    goto L15;
	}

/*      skip if either species is not in current model */

	if (jsflag[ix1] != 0 || jsflag[ix2] != 0) {
	    goto L15;
	}

/*      put two indices into common */

	++jj;
	if (jj <= eqlpsa_1.nslmt) {
	    goto L22;
	}
	io___654.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___654);
	e_wsfe();
	io___655.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___655);
	e_wsfe();
	s_stop("", (ftnlen)0);

L22:
	eqlpsa_1.nslmx[(jj << 1) - 2] = ix1;
	eqlpsa_1.nslmx[(jj << 1) - 1] = ix2;

/*      put lambda's and derivatives into common */

	for (k = 1; k <= 3; ++k) {
	    eqlpsb_1.bslm[k + jj * 3 - 4] = lam[k - 1];
	    eqlpsb_1.dslm1[k + jj * 3 - 4] = dl1[k - 1];
	    eqlpsb_1.dslm2[k + jj * 3 - 4] = dl2[k - 1];
/* L25: */
	}

/*      test for alpha pair in palpha array */

	if (ja == 0) {
	    goto L32;
	}

	i__1 = ja;
	for (k = 1; k <= i__1; ++k) {
	    if (eqlpal_1.palpha[(k << 1) - 2] != alph[0]) {
		goto L30;
	    }
	    if (eqlpal_1.palpha[(k << 1) - 1] != alph[1]) {
		goto L30;
	    }

/*      found a pair at k */

	    alx = (doublereal) k;
	    goto L40;

L30:
	    ;
	}

L32:

/*      pair not in palpha - put them in */

	++ja;
	if (ja <= eqlpal_1.napt) {
	    goto L35;
	}
	io___658.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___658);
	e_wsfe();
	io___659.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___659);
	e_wsfe();
	s_stop("", (ftnlen)0);

L35:
	alx = (doublereal) ja;
	eqlpal_1.palpha[(ja << 1) - 2] = alph[0];
	eqlpal_1.palpha[(ja << 1) - 1] = alph[1];
L40:
	eqlpsa_1.nalpha[jj - 1] = (integer) alx;
	goto L15;

L100:
	;
    }

/*      set number of entries, large arrays */

    eqlpsa_1.nslm = jj;
/* ----------------------------------------------------------------------- */
/*                             *---------------------------------------- */
/*                             * read mu's  (2 sets) */
/*                             *---------------------------------------- */
    jj = 0;

    for (kk = 1; kk <= 2; ++kk) {

L215:

/*      read a block */
/*       species names */

	io___660.ciunit = *ndats1;
	s_rsue(&io___660);
	do_uio(&c__1, unam1, (ftnlen)24);
	do_uio(&c__1, unam2, (ftnlen)24);
	do_uio(&c__1, unam3, (ftnlen)24);
	e_rsue();
/* 1060 format(a12,2(2x,a12)) */
	if (s_cmp(unam1, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L200;
	}

/*      mu, derivative */

	io___662.ciunit = *ndats1;
	s_rsue(&io___662);
	do_uio(&c__1, (char *)&mu, (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&deriv1, (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&deriv2, (ftnlen)sizeof(doublereal));
	e_rsue();
/* 1062 format(13x,f9.5,12x,e10.3,14x,e10.3) */

/*      note - kk=1  deriv1 is dcphi/dt, deriv2 is d2cphi/dt2 */
/*                2            dpsi/dt,            d2psi/dt2 */

/*      skip to block terminator */

L218:
	io___666.ciunit = *ndats1;
	s_rsue(&io___666);
	do_uio(&c__1, udum72, (ftnlen)72);
	e_rsue();
	if (s_cmp(udum72, uterm, (ftnlen)8, (ftnlen)8) != 0) {
	    goto L218;
	}

/*      map 3 species names to indices */

	srchn_(uspec + 24, nst, unam1, &ix1, (ftnlen)24, (ftnlen)24);
	srchn_(uspec + 24, nst, unam2, &ix2, (ftnlen)24, (ftnlen)24);
	srchn_(uspec + 24, nst, unam3, &ix3, (ftnlen)24, (ftnlen)24);

/*      skip if any species name not found */

	if (ix1 <= 0 || ix2 <= 0 || ix3 <= 0) {
	    goto L215;
	}

/*      skip if any of 3 species is not in current model */

	if (jsflag[ix1] != 0 || jsflag[ix2] != 0 || jsflag[ix3] != 0) {
	    goto L215;
	}

/*      put indices into common */

	++jj;
	if (jj <= eqlpmu_1.nmut) {
	    goto L222;
	}
	io___668.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___668);
	e_wsfe();
	io___669.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___669);
	e_wsfe();
	s_stop("", (ftnlen)0);

L222:

	eqlpmu_1.nmux[jj * 3 - 3] = ix1;
	eqlpmu_1.nmux[jj * 3 - 2] = ix2;
	eqlpmu_1.nmux[jj * 3 - 1] = ix3;

/*      put mu and derivatives into common */

	eqlpmb_1.bmu[jj - 1] = mu;
	eqlpmb_1.dmu1[jj - 1] = deriv1;
	eqlpmb_1.dmu2[jj - 1] = deriv2;
	goto L215;

L200:
	;
    }

    eqlpmu_1.nmu = jj;
    ptztab_(&eqlpsa_1.nslm, eqlpsa_1.nslmx, &eqlpmu_1.nmu, eqlpmu_1.nmux, nst,
	     uspec + 24, &jsflag[1], iopr9, (ftnlen)24);

    return 0;
} /* inupt_ */

/* isamax   last revised 07/07/87 by tjw */
/* *isamax f77 rewrite, 07/07/87 by tjw */
integer isamax_(integer *n, doublereal *sx)
{
    /* System generated locals */
    integer ret_val, i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__;
    static doublereal xmag, smax;

/* ***date written  october 1979 */
/* ***author lawson c. (jpl),hanson r. (sla), */
/*                            kincaid d. (u texas), krogh f. (jpl) */
/* ***purpose */
/*    find largest component of s.p. vector */
/* ***description */
/*                b l a s  subprogram */
/*    description of parameters */

/*     --input-- */
/*        n  number of elements in input vector(s) */
/*       sx  single precision vector with n elements */

/*     --output-- */
/*   isamax  smallest index (zero if n.le.0) */

/*     find smallest index of maximum magnitude of single precision sx. */
/*      isamax = first i, i=1 to n, to minimize abs(sx(i)) */

/* ---------------------------------------------------------------------- */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --sx;

    /* Function Body */
    ret_val = 0;
    if (*n <= 0) {
	goto L999;
    }
    ret_val = 1;
    if (*n <= 1) {
	goto L999;
    }

    smax = abs(sx[1]);
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	xmag = (d__1 = sx[i__], abs(d__1));
	if (xmag > smax) {
	    ret_val = i__;
	    smax = xmag;
	}
/* L30: */
    }

L999:
    return ret_val;
} /* isamax_ */

/* iswch    last revised 07/07/87 by tjw */
/* *iswch f77 rewrite, 07/07/87 by tjw */
/* Subroutine */ int iswch_(integer *n1, integer *n2, integer *i__)
{

/*     this routine is called by routine swchlm, which is in turn */
/*     called by routine switch */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* ---------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
    if (*i__ == *n1) {
	*i__ = *n2;
    } else if (*i__ == *n2) {
	*i__ = *n1;
    }

    return 0;
} /* iswch_ */

/* itrefn   last revised 07/07/87 by tjw */
/* *itrefn f77 rewrite, 07/07/87 by tjw */
/* Subroutine */ int itrefn_(doublereal *a, doublereal *alu, integer *ilda, 
	integer *n, integer *ipvt, doublereal *b, doublereal *x0, doublereal *
	rcond, doublereal *res, doublereal *x, logical *qprnt, integer *ier)
{
    /* Initialized data */

    static integer itermx = 10;
    static doublereal const__ = 8388608.;

    /* Format strings */
    static char fmt_370[] = "(1x,\002--- itrefn summary ---\002,5x,\002rcond"
	    "= \002,e10.3)";
    static char fmt_377[] = "(/5x,\002iter\002,6x,\002rsnrm\002,8x,\002rfun"
	    "c\002,8x,\002xerr\002,9x,\002dfunc\002,8x,\002dxnrm\002,8x,\002x"
	    "nrm\002,8x,\002dxbig\002,/)";
    static char fmt_375[] = "(1x,\002--- itrefn - n = 1, no iteration ---"
	    "\002)";
    static char fmt_380[] = "(6x,i2,7(3x,e10.3))";
    static char fmt_387[] = "(\002 --- itrefn converged ---\002)";
    static char fmt_300[] = "(\002 --- itrefn- the x vector was not improved"
	    " ---\002)";
    static char fmt_305[] = "(\002 --- itrefn- the x vector was improved but"
	    " not to\002,\002 within convergence tolerance ---\002)";
    static char fmt_307[] = "(5x,\002best norm of residual = \002,e10.3,\002"
	    ", norm upon entry = \002,e10.3)";

    /* System generated locals */
    integer a_dim1, a_offset, alu_dim1, alu_offset, i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double d_mod(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j;
    static doublereal a1, a2, b2, b3, b1, d1, d2, d3, x1, x2, ba, ax, xi;
    static integer im1, im2, im3, ip1, ip2, ip3;
    static doublereal adx, dxi;
    static integer imax, iter;
    static doublereal prod, rdum, xdum, xerr, xnrm;
    extern /* Subroutine */ int stpp_(doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *, integer *);
    static integer imax2;
    static doublereal dotm1[100], dotm2[200], dotm3[100], dotp1[100], dotp2[
	    200], dotp3[100], sump1, sump2, sump3, dxbig, dfunc, rfunc;
    extern /* Subroutine */ int sgesl_(doublereal *, integer *, integer *, 
	    integer *, doublereal *);
    static doublereal dxnrm, xerrp, rsnrm, xtest, dm1min, dm2min, dm1max, 
	    dp1min, dp2min, dp1max, dp2max, dp3max, dp3min, dm2max, dm3max, 
	    dm3min, rsnrm0, rsnrmi, rsnrmp;
    static logical qrsnrm;
    extern /* Subroutine */ int srtsum_(doublereal *, integer *, doublereal *)
	    ;

    /* Fortran I/O blocks */
    static cilist io___677 = { 0, 0, 0, fmt_370, 0 };
    static cilist io___678 = { 0, 0, 0, fmt_377, 0 };
    static cilist io___680 = { 0, 0, 0, fmt_375, 0 };
    static cilist io___735 = { 0, 0, 0, fmt_380, 0 };
    static cilist io___741 = { 0, 0, 0, fmt_387, 0 };
    static cilist io___743 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___744 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___745 = { 0, 0, 0, fmt_307, 0 };



/*     purpose- */

/*       iterative refinement of a solution to the linear system ax=b, */
/*       real*8 case */

/*     description- */

/*       itrefn is designed to work with the modified slatek linear */
/*       system routines  sgeco, sgefa, and sgesl.  itrefn computes */
/*       residuals, using a partial product algorithm, and uses */
/*       these to obtain a newton-raphson correction to the x vector. */
/*       the best possible value of x (as measured by the lowest norm */
/*       of the residual vector) is returned as the solution.  this may */
/*       be the input vector x. */

/*       convergence is achieved if either */
/*         1. rsnrm .le. 0. */
/*         2. (xnrm+dxnrm).eq.xnrm (additive underflow) */
/*         3. xtest.le.0. (when iter. ge. 3) */

/*       other stop criteria are */
/*         1. ten iterations without convergence */
/*         2. rfunc .le. 0. (iter .ge. 1) (residuals are not decreasing) */
/*         3. dfunc .le. 0. (iter. ge. 2) (errors in x are not */
/*            decreasing) */

/*       note- if the condition number of the matrix (cond = 1/rcond) */
/*       becomes very high, then the likelihood of convergence becomes */
/*       poor.  this is a result of the imperfect representation of */
/*       the matrix and the right-hand-side vector by a 51 bit mantissa */
/*       (Ridge), combined with ill-conditioning of the */
/*       matrix. */

/*     reference- */
/*        wilkinson, j.w. (1967)  the solution of ill-conditioned */
/*      linear equations.  in ralston, a., and wilf, h.s., eds., */
/*      mathematical methods for digital computers, vol. 2, */
/*      john wiley and sons, pages 65-93. */

/*     parameters- */

/*       on entry */

/*         a       real (ilda,n)  the original matrix */
/*         alu     real (ilda,n)  the l-u decomposition */
/*                         ( output from sgeco or sgesl) */
/*         ilda    integer, the leading dimension of the array a */
/*         n       the order of the matrix a */
/*         ipvt    integer array, the pivot vector from sgeco or sgesl */
/*         b       the right-hand-side vector */
/*         x0      the solution vector from sgeco or sgesl, contains */
/*                 the improved vector, if any improvement, upon return */
/*         rcond   the reciprocal condition number of the matrix */
/*         qprnt   print option switch, turned on if .true */

/*       internal */

/*         iter    the iteration counter */
/*         itermx  the maximum number of iterations */
/*         res     a working vector, contains the residual vector upon */
/*                 entry to routine sgesl, contains the correction */
/*                 upon return from it */
/*         rsnrm   the norm of the residual vector */
/*         rsnrm0  the smallest rsnrm encountered */
/*         rsnrmi  the rsnrm of the input x vector */
/*         dsnrm   norm of the correction vector (the res vector, */
/*                 upon return from routine sgesl) */
/*         xnrm    norm of x vector */
/*         dxnrm   norm of the correction vector (dx) */
/*         dx      the correction vector, actually the array res */
/*         dxbig   the value of the element of dx with the largest */
/*                 absolute value */
/*         xerr    error in x, measured by dxnrm/xnrm */
/*         xerrp   the value of xerr on the previous iteration */
/*         xtest   convergence tolerance test parameter- */
/*                 xtest.le.0. is equivalent to xerr.le.eps, where */
/*                 eps is the machine epsilon. */
/*         dfunc   convergence function defined by (xerrp-xerr)/xerrp */
/*         x       the working x vector */
/*         x0      the x vector encountered with the smallest residual */
/*         sum     variable for accumulating the terms in the residual */
/*                 vector, must be higher than standard precision, else */
/*                 iterative refinement should be skipped. */

/*       on return */

/*         x0      the improved solution vector, or the input vector */
/*                 if there was no improvement */
/*         ier     error flag, returns warning values only */
/*                   =   0  converged, satisfied (dxnrm+xnrm) .eq. xnrm */
/*                          or xtest .le. 0. */
/*                   =  -1  did not converge, but the error, as measured */
/*                          by xerr was reduced */
/*                   =  -2  did not converge, the error was not reduced. */
/*                          the input solution vector was returned */
/*                          as the answer */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */


    /* Parameter adjustments */
    alu_dim1 = *ilda;
    alu_offset = 1 + alu_dim1;
    alu -= alu_offset;
    a_dim1 = *ilda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ipvt;
    --b;
    --x0;
    --res;
    --x;

    /* Function Body */
/*     const = 2**23 */

/* ---------------------------------------------------------------------- */

    imax = 100;
    imax2 = 200;
    *ier = 0;
    if (*qprnt) {
	io___677.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___677);
	do_fio(&c__1, (char *)&(*rcond), (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___678.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___678);
	e_wsfe();
    }

/*     copy the x0 vector into the working vector x */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__] = x0[i__];
/* L7: */
    }

/*     return if degree = 1 */

    if (*n <= 1) {
	if (*qprnt) {
	    io___680.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___680);
	    e_wsfe();
	}
	goto L999;
    }

    dfunc = 0.f;
    rfunc = 0.f;
    iter = 0;
    xerr = 0.f;
    rsnrm = 0.f;
    dxnrm = 0.f;
    dxbig = 0.f;
    xnrm = abs(x[1]);
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	ax = (d__1 = x[i__], abs(d__1));
	if (xnrm < ax) {
	    xnrm = ax;
	}
/* L17: */
    }

/*     this is a return point for further iteration */

L20:
    rsnrmp = rsnrm;

/*     compute residual vector and its norm */

    rsnrm = 0.f;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dp1max = 0.f;
	dp2max = 0.f;
	dp3max = 0.f;
	dp1min = 1e30f;
	dp2min = 1e30f;
	dp3min = 1e30f;

	dm1max = 0.f;
	dm2max = 0.f;
	dm3max = 0.f;
	dm1min = 1e30f;
	dm2min = 1e30f;
	dm3min = 1e30f;

	ip1 = 0;
	ip2 = 0;
	ip3 = 0;
	im1 = 0;
	im2 = 0;
	im3 = 0;

	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {

/*      split x(j) and a(i,j) */
/*       for example, x1 = high order part of x, */
/*                    x2 = low  order part of x */

	    x2 = d_mod(&x[j], &const__);
	    x1 = (x[j] - x2) / const__;
	    a2 = d_mod(&a[i__ + j * a_dim1], &const__);
	    a1 = (a[i__ + j * a_dim1] - a2) / const__;


/*      compute the partial products, */
/*       place into dotp or dotm arrays */
/*       find max and min values for each array */

	    prod = a1 * x1;
	    stpp_(&prod, dotp1, &ip1, &dp1max, &dp1min, dotm1, &im1, &dm1max, 
		    &dm1min, &imax);

	    prod = a1 * x2;
	    stpp_(&prod, dotp2, &ip2, &dp2max, &dp2min, dotm2, &im2, &dm2max, 
		    &dm2min, &imax2);

	    prod = a2 * x1;
	    stpp_(&prod, dotp2, &ip2, &dp2max, &dp2min, dotm2, &im2, &dm2max, 
		    &dm2min, &imax2);

	    prod = a2 * x2;
	    stpp_(&prod, dotp3, &ip3, &dp3max, &dp3min, dotm3, &im3, &dm3max, 
		    &dm3min, &imax);
/* L40: */
	}

/*      put b(i) into appropriate dotp or dotm array */

/*      put into some dotp */

	ba = -b[i__];
	b3 = d_mod(&ba, &const__);
	d__1 = (ba - b3) / const__;
	b2 = d_mod(&d__1, &const__);
	b1 = (ba - b2 * const__ - b3) / (const__ * const__);
	if (b3 != 0.) {
	    ++ip3;
	    dotp3[ip3 - 1] = b3;
	}
	if (b2 != 0.) {
	    ++ip2;
	    dotp2[ip2 - 1] = b2;
	}
	if (b1 != 0.) {
	    ++ip1;
	    dotp1[ip1 - 1] = b1;
	}

/*      sort into increasing order, and sum each set */

	srtsum_(dotp1, &ip1, &sump1);
	srtsum_(dotp2, &ip2, &sump2);
	srtsum_(dotp3, &ip3, &sump3);


	d1 = -sump1;
	d2 = -sump2;
	d3 = -sump3;

	d2 *= const__;
	d1 = d1 * const__ * const__;
	rdum = d3 + d2 + d1;

	res[i__] = rdum;
	rdum = abs(rdum);
	if (rdum > rsnrm) {
	    rsnrm = rdum;
	}
/* L50: */
    }

    if (iter <= 0) {
	rsnrm0 = rsnrm;
	rsnrmi = rsnrm;
    }

    if (iter > 0) {
	if (rsnrm < rsnrm0) {

/*         have found a better solution, load it into x0 */

	    rsnrm0 = rsnrm;
	    i__1 = *n;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		x0[i__] = x[i__];
/* L240: */
	    }
	}
    }

    if (iter >= 1) {
	rfunc = (rsnrmp - rsnrm) / rsnrmp;
    }
    if (iter >= 2) {
	dfunc = (xerrp - xerr) / xerrp;
    }
    if (*qprnt) {
	io___735.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___735);
	do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rsnrm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rfunc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xerr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dfunc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dxnrm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xnrm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dxbig, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/*     convergence tests */

    if (rsnrm <= 0.f) {
	goto L90;
    }
    if (iter > 0) {
	if (xnrm + dxnrm == xnrm) {
	    goto L90;
	}
    }
    if (iter <= 2) {
	goto L53;
    }
    xtest = xerr + 1.f;
    xtest += -1.f;
    if (xtest <= 0.f) {
	goto L90;
    }

/*     stop tests */

L53:
    if (iter > 0) {
	if (rfunc <= 0.f) {
	    goto L100;
	}
    }
    if (iter > 2) {
	if (dfunc <= 0.f) {
	    goto L100;
	}
    }

    if (iter >= itermx) {
	goto L100;
    }
    ++iter;

/*     solve the system a(dx) = res */

    sgesl_(&alu[alu_offset], ilda, n, &ipvt[1], &res[1]);

/*     note that res now holds the correction vector (symbolized by dx). */
/*     correct the x vector and compute its norm. */

    dxi = res[1];
    dxbig = dxi;
    dxnrm = abs(dxi);
    xi = x[1];
    xi += dxi;
    x[1] = xi;
    xnrm = abs(xi);

    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	dxi = res[i__];
	adx = abs(dxi);
	if (dxnrm < adx) {
	    dxnrm = adx;
	    dxbig = dxi;
	}
	xi = x[i__];
	xi += dxi;
	x[i__] = xi;
	ax = abs(xi);
	if (xnrm < ax) {
	    xnrm = ax;
	}
/* L60: */
    }

    xerrp = xerr;
    xdum = xnrm;
    if (xdum <= 0.f) {
	xdum = 1.f;
    }
    xerr = dxnrm / xdum;

    goto L20;

/*     convergence */

L90:
    if (*qprnt) {
	io___741.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___741);
	e_wsfe();
    }
    goto L999;

/*     no convergence.  determine whether or not the x vector was */
/*     improved */

L100:
    qrsnrm = rsnrm0 < rsnrmi;
    if (! qrsnrm) {
	*ier = -2;
	if (*qprnt) {
	    io___743.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___743);
	    e_wsfe();
	}
	goto L999;
    }

    *ier = -1;
    if (*qprnt) {
	io___744.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___744);
	e_wsfe();
	io___745.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___745);
	do_fio(&c__1, (char *)&rsnrm0, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rsnrmi, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

L999:
    return 0;
} /* itrefn_ */

/* kilsum   last revised 07/07/87 by tjw */
/* *kilsum f77 check, 07/07/87 by tjw */
/* Subroutine */ int kilsum_(integer *ns, integer *jkndex, integer *ibjius, 
	doublereal *conc, doublereal *bji, doublereal *sum)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, jj, kk;


/*     created 11sep86 rmm */

/*     purpose:  calculate fourth term in hkf equation for activity */
/*               coefficient (part iv equations) */

/*      input  ns      index to ion of interest */
/*             jkndex  array of indices of both ions in bji array */
/*             ibjius  number of entries in bji array */
/*             conc    concentration of ions */
/*             bji     array of ion-ion interaction parameters */

/*      output sum     sum over j of (bji(j)*conc(j)) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --bji;
    --conc;
    jkndex -= 3;

    /* Function Body */
    *sum = 0.f;

    i__1 = *ibjius;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jj = jkndex[(i__ << 1) + 1];
	kk = jkndex[(i__ << 1) + 2];

/*         calculate the sum if: */
/*         ion of interest,ns, is present as first ion in pair */
/*         or if */
/*         ion of interest present as second ion in pair */

	if (jj == *ns) {
	    *sum += bji[i__] * conc[kk];
	} else if (kk == *ns) {
	    *sum += bji[i__] * conc[jj];
	}

/* L20: */
    }

    return 0;
} /* kilsum_ */

/* kisum    last revised 09/25/87 by rmm */
/* *kisum f77 check, 07/07/87 by tjw */
/* Subroutine */ int kisum_(doublereal *conc, doublereal *xistoc, doublereal *
	z__, integer *nst, doublereal *sum)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k;
    static doublereal mk;
    static integer ian;
    static doublereal zan;
    static integer icat;
    static doublereal zcat;
    static integer ierr;
    static doublereal omean;
    static integer iansf;
    extern /* Subroutine */ int omega4_(integer *, doublereal *, doublereal *,
	     integer *);
    static doublereal omecat;
    static integer icatsf;
    static doublereal allslt, omeslt;


/*     created 11sep86 rmm */

/*     purpose:  calculate third term in hkf equation for activity */
/*               coefficient (part iv equations) */

/*     input   conc    concentration of ions */
/*             xistoc  ionic strength */
/*             z       charge array */
/*             nst     total number of species in the model */

/*      output sum     sum over k of (b(k)  * conc(k)) */
/*                     = (1.e-11/xistoc)*sum over k of (conc(k)* */
/*                           sum over j of (nu sub j,k * omega(j)) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */


/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */


/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --z__;
    --conc;

    /* Function Body */
    *sum = 0.f;
    allslt = 0.f;

/*              for each salt,k */
    i__1 = eqlhkf_1.icnt;
    for (k = 1; k <= i__1; ++k) {
	omecat = 0.f;
	omean = 0.f;
	omeslt = 0.f;

/*              get indexes and stoich. rxn. factor for each ion in salt */
	icat = eqlhkf_1.islt[(k << 2) - 4];
	ian = eqlhkf_1.islt[(k << 2) - 3];
	icatsf = eqlhkf_1.islt[(k << 2) - 2];
	iansf = eqlhkf_1.islt[(k << 2) - 1];

/*              get omega for ions */
	zcat = z__[icat];
	zan = z__[ian];
	omega4_(&icat, &omecat, &zcat, &ierr);
	omega4_(&ian, &omean, &zan, &ierr);

/*              calculate omega for salt */

	omeslt = (real) icatsf * omecat + (real) iansf * omean;

/*              calculate over all salts (product of molality and omega) */

	mk = eqlhkf_1.mslt[k - 1];
	allslt += omeslt * mk;
/* L100: */
    }

/*              final value */

    *sum = allslt * 1e-11f / *xistoc;

    return 0;
} /* kisum_ */

/* lamda    last revised 11/25/87 by tjw */
/* *lamda f77 rewrite, 07/07/87 by tjw */
/* Subroutine */ int lamda_(doublereal *al10, integer *jsol, doublereal *
	lamlg, integer *ncomp, integer *nx, doublereal *rconst, doublereal *
	tempk, doublereal *xbar, doublereal *w, integer *iktmax)
{
    /* Format strings */
    static char fmt_100[] = "(\002 * error- jsol value \002,i2,\002 is inval"
	    "id (eqlib/lamda)\002)";

    /* System generated locals */
    integer lamlg_dim1, lamlg_offset, xbar_dim1, xbar_offset, w_dim1, 
	    w_offset, i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal a, b, c__;
    static integer k;
    static doublereal a12, a13, a23;
    static integer ik;
    static doublereal zx, zx1, zx2, zx3, fac, zx12, zx22, zx32;
    static integer ncpt;

    /* Fortran I/O blocks */
    static cilist io___779 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___780 = { 0, 0, 0, fmt_100, 0 };



/*     this routine computes activity coefficients for solid-solution */
/*     component end-members */

/*   jsol      array holding mixing model code */
/*   lamlg     log of activity coefficients for endmember components */
/*   ncomp     number of components of solid solution nx */
/*   xbar      mole fractions of endmember components of solid solutions */
/*   w         array of non-ideal mixing parameters calculated from */
/*             apx array */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --jsol;
    --ncomp;
    w_dim1 = *iktmax;
    w_offset = 1 + w_dim1;
    w -= w_offset;
    xbar_dim1 = *iktmax;
    xbar_offset = 1 + xbar_dim1;
    xbar -= xbar_offset;
    lamlg_dim1 = *iktmax;
    lamlg_offset = 1 + lamlg_dim1;
    lamlg -= lamlg_offset;

    /* Function Body */
    fac = 1e3f / (*al10 * *rconst * *tempk);
    k = jsol[*nx];
    ncpt = ncomp[*nx];

    if (k == 0) {

/*       ideal solution */

/*       gxs = 0 */

	i__1 = ncpt;
	for (ik = 1; ik <= i__1; ++ik) {
	    lamlg[ik + *nx * lamlg_dim1] = 0.f;
/* L20: */
	}

    } else if (k == 1) {

/*       binary solution, third-order maclaurin expansion */
/*       gxs = w1*x2 + (w2/2)*x2**2 + (w3/6)*x2**3 */
/*       original pathi solid-solution model */

	zx = xbar[*nx * xbar_dim1 + 2];
	zx2 = zx * zx;
	lamlg[*nx * lamlg_dim1 + 1] = -fac * (w[*nx * w_dim1 + 2] * zx2 / 2.f 
		+ w[*nx * w_dim1 + 3] * zx * zx2 / 3.f);
	b = -(w[*nx * w_dim1 + 3] + w[*nx * w_dim1 + 2]) / 2.f;
	c__ = w[*nx * w_dim1 + 3] / 3.f;
	zx = xbar[*nx * xbar_dim1 + 1];
	zx2 = zx * zx;
	lamlg[*nx * lamlg_dim1 + 2] = fac * (a + b * zx2 + c__ * zx * zx2);

    } else if (k == 2) {

/*       binary solution, parabolic maclaurin expansion */

/*       gxs=w1*x1*x2 */

	zx = xbar[*nx * xbar_dim1 + 2];
	lamlg[*nx * lamlg_dim1 + 1] = fac * w[*nx * w_dim1 + 1] * zx * zx;
	zx = xbar[*nx * xbar_dim1 + 1];
	lamlg[*nx * lamlg_dim1 + 2] = fac * w[*nx * w_dim1 + 1] * zx * zx;

    } else if (k == 3) {

/*       binary solution, cubic macluarin with p,t dependence */

/*       gxs = w1*x1*x2**2 + w2*x2*x1**2 */

	zx = xbar[*nx * xbar_dim1 + 2];
	a = w[*nx * w_dim1 + 2] * 2.f - w[*nx * w_dim1 + 1];
	b = (w[*nx * w_dim1 + 1] - w[*nx * w_dim1 + 2]) * 2.f;
	zx2 = zx * zx;
	lamlg[*nx * lamlg_dim1 + 1] = fac * (a * zx2 + b * zx * zx2);
	zx = xbar[*nx * xbar_dim1 + 1];
	a = w[*nx * w_dim1 + 1] * 2.f - w[*nx * w_dim1 + 2];
	b = (w[*nx * w_dim1 + 2] - w[*nx * w_dim1 + 1]) * 2.f;
	zx2 = zx * zx;
	lamlg[*nx * lamlg_dim1 + 2] = fac * (a * zx2 + b * zx * zx2);

    } else if (k == 4) {

/*       binary solution, guggenheim polynomial with t-dependence */
/*       gxs = x1*x2*(w1 + w2*(x1-x2) + w3*(x1-x2)**2 ) */

	a = w[*nx * w_dim1 + 1] + w[*nx * w_dim1 + 2] * 3.f + w[*nx * w_dim1 
		+ 3] * 5.f;
	b = w[*nx * w_dim1 + 2] * -4.f - w[*nx * w_dim1 + 3] * 16.f;
	c__ = w[*nx * w_dim1 + 3] * 12.f;
	zx = xbar[*nx * xbar_dim1 + 2];
	zx2 = zx * zx;
	lamlg[*nx * lamlg_dim1 + 1] = fac * zx2 * (a + b * zx + c__ * zx2);
	zx = xbar[*nx * xbar_dim1 + 1];
	zx2 = zx * zx;
	a = w[*nx * w_dim1 + 1] - w[*nx * w_dim1 + 2] * 3.f + w[*nx * w_dim1 
		+ 3] * 5.f;
	b = w[*nx * w_dim1 + 2] * 4.f - w[*nx * w_dim1 + 3] * 16.f;
	lamlg[*nx * lamlg_dim1 + 2] = fac * zx2 * (a + b * zx + c__ * zx2);

    } else if (k == 5) {

/*       ternary regular solution */
/*       see prigogine and defay, p. 257 */

	a12 = w[*nx * w_dim1 + 1];
	a13 = w[*nx * w_dim1 + 2];
	a23 = w[*nx * w_dim1 + 3];
	zx1 = xbar[*nx * xbar_dim1 + 1];
	zx2 = xbar[*nx * xbar_dim1 + 2];
	zx3 = xbar[*nx * xbar_dim1 + 3];
	zx12 = zx1 * zx1;
	zx22 = zx2 * zx2;
	zx32 = zx3 * zx3;
	lamlg[*nx * lamlg_dim1 + 1] = fac * (a12 * zx22 + a13 * zx32 + zx2 * 
		zx3 * (a12 - a23 + a13));
	lamlg[*nx * lamlg_dim1 + 2] = fac * (a12 * zx12 + a23 * zx32 + zx1 * 
		zx3 * (a23 - a13 + a12));
	lamlg[*nx * lamlg_dim1 + 3] = fac * (a13 * zx12 + a23 * zx22 + zx1 * 
		zx2 * (a13 - a12 + a23));

    } else if (k == 6) {

/*       need to put in extrapolation of Newton et al. plag model here */

    } else {
	io___779.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___779);
	do_fio(&c__1, (char *)&jsol[*nx], (ftnlen)sizeof(integer));
	e_wsfe();
	io___780.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___780);
	do_fio(&c__1, (char *)&jsol[*nx], (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    return 0;
} /* lamda_ */

/* lsqp     last revised 11/16/87 by tjw */
/* *lsqp f77 rewrite, 07/07/87 by tjw */
/* Subroutine */ int lsqp_(doublereal *x, doublereal *y, doublereal *w, 
	integer *n, integer *kd, doublereal *c__, integer *ier)
{
    /* Initialized data */

    static logical qfalse = FALSE_;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal a[121]	/* was [11][11] */;
    static integer i__, j, k;
    static doublereal p[22], s[22], ee[11], gm[121]	/* was [11][11] */;
    static integer js;
    static doublereal res[11], rhs[11];
    static integer kdp1, kdp2, kd2p1, kd2p2, ipvt[11];
    extern /* Subroutine */ int polx_(doublereal *, doublereal *, integer *, 
	    doublereal *, integer *);
    static integer ipfmx1;
    extern /* Subroutine */ int msolvr_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, logical *, logical *);


/*     least squares fit of a polynomial, real*8 case */

/*     input */
/*      x     array of independent variable values */
/*      y     corresponding array of dependent variable values */
/*      w         "          "    "   weights */
/*      n     number of values in x,y  and w */
/*      kd    degree of polynomial to fit */
/*            note that maximum kd = 10 */

/*     output */
/*      c     array of coefficients of a polynomial of degree kd */
/*             fitting the set (x,y) */
/*             y = c(1) + c(2)*x + c(3)*x**2 + ... */
/*      ier   0/1  ok/unable to fit */
/*             note that degree kd must be .lt. number of points n */

/*     if degree = n-1, */
/*        call polx for an exact polynomial through (x,y) */
/*     else  - */
/*     method is to form the normal equations in matrix form  ac = b */
/*     where (using d for degree) */

/*      a = (sum(w)      sum(wx)      sum(wx**2) ...   ) */
/*          (sum(wx)     sum(wx**2)   sum(wx**3) ...   ) */
/*          (sum(wx**2)  sum(wx**3)   sum(wx**4) ...   ) */
/*          ( ...                                      ) */
/*          (sum(wx**d)  sum(wx**d+1) sum(wx**d+2) ... ) */

/*      c = (c(1), c(2), ... , c(d+1)) */

/*      b = (sum(wy)     ) */
/*          (sum(wxy)    ) */
/*          (sum(wx**2y  ) */
/*          (...         ) */
/*          (sum(wx**dy) ) */

/*     and solve for the coefficients c(i) */

/*     reference */
/*      "numerical methods and computers", kuo, shan s., */
/*      addison-wesley, 1965, chapter 11. */

/*     this code needs the machine epsilon, eps, which is calculated */
/*     by flpars.  this is usually initialized by a call to eqlib, which */
/*     calls flpars. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */


/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


    /* Parameter adjustments */
    --c__;
    --w;
    --y;
    --x;

    /* Function Body */

/* ---------------------------------------------------------------------- */

    *ier = 0;
    ipfmx1 = 11;

    kdp1 = *kd + 1;
    if (kdp1 > 10) {
	*ier = 1;
	goto L999;
    }

    if (*kd >= *n) {
	*ier = 1;
	goto L999;
    }

    if (*kd >= *n - 1) {

/*       exact polynomial here - degree n-1 */

	polx_(&x[1], &y[1], n, &c__[1], ier);
	goto L999;
    }

    kdp2 = *kd + 2;
    kd2p1 = (*kd << 1) + 1;
    kd2p2 = (*kd << 1) + 2;
/*                             *---------------------------------------- */
/*                             * compute all distinct terms of matrix a */
/*                             *  place into array  s */
/*                             *---------------------------------------- */
    i__1 = kd2p1;
    for (k = 1; k <= i__1; ++k) {
	s[k - 1] = 0.f;
/* L10: */
    }

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*      make up products of x's */

	p[0] = 1.f;
	i__2 = kd2p1;
	for (k = 2; k <= i__2; ++k) {
	    p[k - 1] = p[k - 2] * x[i__];
/* L20: */
	}

/*      weight products and sum */

	i__2 = kd2p1;
	for (k = 1; k <= i__2; ++k) {
	    s[k - 1] += p[k - 1] * w[i__];
/* L30: */
	}

/* L40: */
    }

/*                             *---------------------------------------- */
/*                             * fill matrix a from array s */
/*                             *---------------------------------------- */
    j = 1;
    js = 2;

/*      js = sum of indices */

L50:
    i__ = js - j;
    a[i__ + j * 11 - 12] = s[js - 2];
    ++j;
    if (j < js) {
	goto L50;
    }
    j = 1;
    ++js;
    if (js <= kdp2) {
	goto L50;
    }

/*      upper left triangle now full */

    i__ = kdp1;
    js = *kd + 3;

L60:
    j = js - i__;
    a[i__ + j * 11 - 12] = s[js - 2];
    --i__;
    if (j <= kdp1) {
	goto L60;
    }
    i__ = kdp1;
    ++js;
    if (js <= kd2p2) {
	goto L60;
    }

/*      matrix a is full */

/*                             *---------------------------------------- */
/*                             * compute values for rhs */
/*                             *---------------------------------------- */
    i__1 = kdp1;
    for (k = 1; k <= i__1; ++k) {
	rhs[k - 1] = 0.f;
/* L70: */
    }

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*      make up products of x's */

	p[0] = 1.f;
	i__2 = kdp1;
	for (k = 2; k <= i__2; ++k) {
	    p[k - 1] = p[k - 2] * x[i__];
/* L80: */
	}

/*      weight products and sum */

	i__2 = kdp1;
	for (k = 1; k <= i__2; ++k) {
	    rhs[k - 1] += w[i__] * p[k - 1] * y[i__];
/* L90: */
	}

/* L100: */
    }

/*                             *---------------------------------------- */
/*                             * solve ac = rhs */
/*                             *---------------------------------------- */

/*      factor a */

    msolvr_(a, gm, rhs, &c__[1], res, ee, ipvt, &kdp1, &ipfmx1, ier, &qfalse, 
	    &qfalse);

L999:
    return 0;
} /* lsqp_ */

/* modah    last revised 07/08/87 by tjw */
/* *modah f77 check, 07/08/87 by tjw */
/* Subroutine */ int modah_(integer *nahv, integer *nst, doublereal *azero, 
	char *uspec, doublereal *hydn, ftnlen uspec_len)
{
    /* Initialized data */

    static char uendit[24] = "endit.                  ";

    /* Format strings */
    static char fmt_1000[] = "(\002 * error - can not open file ahv (eqlib/m"
	    "odah)\002)";
    static char fmt_1005[] = "(/,\002 azero and hydration number modificatio"
	    "ns\002,/)";
    static char fmt_1010[] = "(a24,2x,f6.3,2x,f5.2)";
    static char fmt_1012[] = "(2x,a24,2x,f6.3,2x,f5.2)";
    static char fmt_1014[] = "(\002 *** species not found in array uspec\002"
	    ",/)";

    /* System generated locals */
    integer i__1;
    olist o__1;

    /* Builtin functions */
    integer f_open(olist *), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal av, hv;
    static integer ns;
    static char unam[24];

    /* Fortran I/O blocks */
    static cilist io___800 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___801 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___802 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___806 = { 0, 0, 0, fmt_1012, 0 };
    static cilist io___808 = { 0, 0, 0, fmt_1014, 0 };



/*     input   nahv    unit number of a-h file */
/*             nst     number of species in uspec */
/*     output  modified values in arrays */
/*              azero and hydn */
/*              corresponding to species names on nahv */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

    /* Parameter adjustments */
    --hydn;
    uspec -= 24;
    --azero;

    /* Function Body */

/* ---------------------------------------------------------------------- */

/*     link to the ahv input file to read the set of modified azero */
/*      and hydn values */

    o__1.oerr = 1;
    o__1.ounit = *nahv;
    o__1.ofnmlen = 3;
    o__1.ofnm = "ahv";
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L900;
    }
    goto L3;

L900:
    io___800.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___800);
    e_wsfe();
    s_stop("", (ftnlen)0);

L3:

    io___801.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___801);
    e_wsfe();

L10:
    io___802.ciunit = *nahv;
    s_rsfe(&io___802);
    do_fio(&c__1, unam, (ftnlen)24);
    do_fio(&c__1, (char *)&av, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&hv, (ftnlen)sizeof(doublereal));
    e_rsfe();

/*      test for exit */

    if (s_cmp(unam, uendit, (ftnlen)24, (ftnlen)24) == 0) {
	goto L999;
    }

    io___806.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___806);
    do_fio(&c__1, unam, (ftnlen)24);
    do_fio(&c__1, (char *)&av, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&hv, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*      search for species name in uspec */

    i__1 = *nst;
    for (ns = 2; ns <= i__1; ++ns) {
	if (s_cmp(unam, uspec + ns * 24, (ftnlen)24, (ftnlen)24) != 0) {
	    goto L20;
	}

/*      found it */

	goto L25;

L20:
	;
    }

/*      not found */

    io___808.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___808);
    e_wsfe();
    goto L10;

L25:
    azero[ns] = av;
    hydn[ns] = hv;
    goto L10;

L999:
    return 0;
} /* modah_ */

/* molint   last revised 11/25/87 by tjw and rmm */
/* *molint f77 check, 07/08/87 by tjw */
/* Subroutine */ int molint_(doublereal *conc, integer *nsq, integer *nst, 
	doublereal *cdrs, integer *ndim, integer *nsb, integer *itype, 
	doublereal *concbs)
{
    /* Format strings */
    static char fmt_9997[] = "(\002  error invalid type of program  eqlib/mo"
	    "lint\002)";
    static char fmt_9998[] = "(\002    in molint   no. rxn    cdrs  ndim="
	    "\002,i5)";
    static char fmt_9999[] = "(10(1x,f10.3))";
    static char fmt_1001[] = "(\002line 2 nrs,nsc,cdum1,cdum2,conc,mdum,mo"
	    "l\002)";
    static char fmt_1000[] = "(/,\002  **** the basis species ns-th = \002,i"
	    "3)";
    static char fmt_1200[] = "(2(x,i3),5(x,f10.3))";
    static char fmt_1250[] = "(\002 i    conc     concbs\002)";
    static char fmt_1300[] = "(x,i3,2(x,e13.5))";

    /* System generated locals */
    integer cdrs_dim1, cdrs_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, ns;
    static logical qck;
    static integer nsc;
    static doublereal mol;
    static integer nrs, nsb1;
    static doublereal mdum;
    static integer nrxn, nrst;
    static doublereal cdum1, cdum2;
    static integer ndesco;

    /* Fortran I/O blocks */
    static cilist io___811 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___812 = { 0, 0, 0, fmt_9997, 0 };
    static cilist io___816 = { 0, 0, 0, fmt_9998, 0 };
    static cilist io___818 = { 0, 0, 0, fmt_9999, 0 };
    static cilist io___823 = { 0, 0, 0, fmt_1001, 0 };
    static cilist io___825 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___828 = { 0, 0, 0, fmt_1200, 0 };
    static cilist io___829 = { 0, 0, 0, fmt_1250, 0 };
    static cilist io___830 = { 0, 0, 0, fmt_1300, 0 };



/*      created 19may87 by rmm */

/*     this routine decomposes the molality of complexes into */
/*     the basis species ( m sub j ,total -- j is basis species) */
/*     input       conc     concentration array */
/*                 nsq      number of basis species */
/*                 nst      total number of species read from datafile */
/*                 cdrs     coefficient arrray */
/*                 ndim     dimension for cdrs array */
/*                 nsb      number of strict basis species */
/*                 itype    3/6  eq3/eq6 */

/*     output      concbs   concentration array for basis species */



/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ------------------------------------------------------------------- */

/*      initialize */

    /* Parameter adjustments */
    --conc;
    cdrs_dim1 = *ndim;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    --concbs;

    /* Function Body */
    nsb1 = *nsb + 1;
    if (*itype == 3) {
	ndesco = *nsq + 1;
    } else if (*itype == 6) {
	ndesco = *nsb + 1;
    } else {
	io___811.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___811);
	e_wsfe();
	io___812.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___812);
	e_wsfe();
    }

    qck = FALSE_;
    i__1 = *nsq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	concbs[i__] = 0.f;
/* L10: */
    }

    if (qck) {
	nrst = *nst - *nsb;
	io___816.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___816);
	do_fio(&c__1, (char *)&(*ndim), (ftnlen)sizeof(integer));
	e_wsfe();
	i__1 = *ndim;
	for (ns = 1; ns <= i__1; ++ns) {
	    io___818.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___818);
	    for (nrxn = 1; nrxn <= 10; ++nrxn) {
		do_fio(&c__1, (char *)&cdrs[ns + nrxn * cdrs_dim1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
/* L999: */
	}
    }
    cdum1 = 0.f;
    cdum2 = 0.f;
    mdum = 0.f;

/*              for each basis species (strict + auxiliary) */
/*              except water */

    if (qck) {
	io___823.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___823);
	e_wsfe();
    }
    i__1 = *nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	if (ns == *nsb) {
	    goto L100;
	}
	mol = 0.f;

/*              for each reaction look for basis species selected above */

	if (qck) {
	    io___825.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___825);
	    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	i__2 = *nst;
	for (nsc = nsb1; nsc <= i__2; ++nsc) {
	    nrs = nsc - *nsb;
	    cdum1 = cdrs[ns + nrs * cdrs_dim1];

/*              is the ns-th species in this reaction */

	    if (cdum1 > 0.f) {

/*              get the reaction coefficient for the */
/*              destroyed dependent species */

		cdum2 = cdrs[ndesco + nrs * cdrs_dim1];

/*              calculate the molality of the ns-th species from this */
/*              dependent species */

		cdum2 = abs(cdum2);
		mdum = cdum1 / cdum2 * conc[nsc];
		mol += mdum;
		if (qck) {
		    io___828.ciunit = eqlun_1.noutpl;
		    s_wsfe(&io___828);
		    do_fio(&c__1, (char *)&nrs, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&nsc, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&cdum1, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&cdum2, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&conc[nsc], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, (char *)&mdum, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&mol, (ftnlen)sizeof(doublereal));
		    e_wsfe();
		}
	    }
/* L50: */
	}

	concbs[ns] = mol + conc[ns];

L100:
	;
    }

    if (qck) {
	io___829.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___829);
	e_wsfe();
	i__1 = *nst;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    io___830.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___830);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&conc[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&concbs[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L900: */
	}
    }

    return 0;
} /* molint_ */

/* molslt   last revised 11/25/87 by tjw and rmm */
/* *molslt f77 check, 07/08/87 by tjw */
/* Subroutine */ int molslt_(doublereal *z__, doublereal *concbs, integer *
	nsq)
{
    /* Format strings */
    static char fmt_9200[] = "(\002 molslt-- i,conc \002,i3,x,e15.5)";
    static char fmt_9300[] = "(\002 no cation left- minus before\002,e15.5"
	    ",\002 sfplus\002,e15.5)";
    static char fmt_9000[] = "(\002 cation gone--nsplus,nsmin,minus left,msa"
	    "lt created\002,2(x,i3),2(e15.5))";
    static char fmt_9400[] = "(\002 no anion left- plus before\002,e15.5,"
	    "\002 sfplus\002,e15.5)";
    static char fmt_9100[] = "(\002 anion gone --nsplus,nsmin,plus left,msal"
	    "t created\002,2(x,i3),2(e15.5))";
    static char fmt_1000[] = "(\002 normal exit --molslt - after making mole"
	    "s of salt\002)";
    static char fmt_2000[] = "(\002 ** warning in molslt -- conc. of remaini"
	    "ng ion is\002,\002 significant\002)";
    static char fmt_3000[] = "(\002 cation      anion  cat. s.f. \002,\002  "
	    "anion s.f.      mol. salt     \002)";
    static char fmt_4000[] = "(4(5x,i5),5x,e13.5)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j;
    static doublereal xl;
    static logical qck, qmin;
    static doublereal zmin, dumz, plus, sfmin, msalt;
    static integer nsmin;
    static doublereal minus;
    static logical qplus;
    static doublereal zplus, dumcon, sfplus;
    static integer nsplus;

    /* Fortran I/O blocks */
    static cilist io___845 = { 0, 0, 0, fmt_9200, 0 };
    static cilist io___848 = { 0, 0, 0, fmt_9300, 0 };
    static cilist io___849 = { 0, 0, 0, fmt_9000, 0 };
    static cilist io___850 = { 0, 0, 0, fmt_9400, 0 };
    static cilist io___851 = { 0, 0, 0, fmt_9100, 0 };
    static cilist io___852 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___853 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___854 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___855 = { 0, 0, 0, fmt_4000, 0 };


/*       created 21jan87 rmm */

/*     this routine calculates the molality of hypothetical */
/*     salts for the hkf equations (part iv) */
/*     input       z        charge array */
/*                 nsq      number of basis species */

/*     output      concbs   array with summed conc. of basis species */

/*     output      mslt     array with molalities of salts */
/*     in eqlhkf   islt     2-d array with indices and stoich. */
/*                          reaction factors for anion and cation */
/*                 icnt     number of salts created */


/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */


/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ------------------------------------------------------------------- */

/*      initialize */
/*      qplus, qmin -- if true go through loop and pick up new species */
/*      qck --  debug write switch */
    /* Parameter adjustments */
    --concbs;
    --z__;

    /* Function Body */
    qck = FALSE_;
    qmin = TRUE_;
    qplus = TRUE_;
    nsplus = 1;
    nsmin = 1;
    eqlhkf_1.icnt = 0;
    xl = 1e-10f;
    zplus = 0.f;
    zmin = 0.f;
    plus = 0.f;
    minus = 0.f;
    sfplus = 0.f;
    sfmin = 0.f;
    msalt = 0.f;
    if (qck) {
	i__1 = *nsq;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    io___845.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___845);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&concbs[i__], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L900: */
	}
    }

/*              cation loop */

L100:
    if (qplus) {
L200:
	++nsplus;

/*              exit if no cations left to search */

	if (nsplus >= *nsq) {
	    goto L600;
	}
	dumcon = concbs[nsplus];
	dumz = z__[nsplus];
	if (dumcon > xl && dumz > xl) {
	    plus = dumcon;
	    zplus = dumz;
	} else {
	    goto L200;
	}
    }

/*              anion loop */

/* L300: */
    if (qmin) {
L400:
	++nsmin;

/*              exit if no anions left to search */

	if (nsmin >= *nsq) {
	    goto L600;
	}
	dumcon = concbs[nsmin];
	dumz = z__[nsmin];
	if (dumcon > xl && dumz < -xl) {
	    minus = dumcon;
	    zmin = dumz;
	} else {
	    goto L400;
	}
    }

/* L500: */

/*              if equiv. chg. -- make 1:1 salt */

    if ((d__1 = abs(zplus) - abs(zmin), abs(d__1)) <= xl) {
	sfplus = 1.f;
	sfmin = 1.f;
    } else {
	sfplus = abs(zmin);
	sfmin = zplus;
    }

/*              use up all of cation */

    if (plus / sfplus < minus / sfmin) {
	msalt = plus / sfplus;
	plus = 0.f;

	if (qck) {
	    io___848.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___848);
	    do_fio(&c__1, (char *)&minus, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sfmin, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	minus -= msalt * sfmin;

	if (qck) {
	    io___849.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___849);
	    do_fio(&c__1, (char *)&nsplus, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nsmin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&minus, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&msalt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	qplus = TRUE_;
	qmin = FALSE_;
	if (minus < xl) {
	    minus = 0.f;
	    qmin = TRUE_;
	}
    } else {

/*                    use up all of anion */

	msalt = minus / sfmin;
	minus = 0.f;

	if (qck) {
	    io___850.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___850);
	    do_fio(&c__1, (char *)&plus, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sfplus, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	plus -= msalt * sfplus;

	if (qck) {
	    io___851.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___851);
	    do_fio(&c__1, (char *)&nsplus, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&nsmin, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&plus, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&msalt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	qplus = FALSE_;
	qmin = TRUE_;
	if (plus < xl) {
	    plus = 0.f;
	    qplus = TRUE_;
	}
    }

/*              fill in array islt with indices and */
/*              stoich. reaction coefficients for cations and anions */

    ++eqlhkf_1.icnt;
    eqlhkf_1.mslt[eqlhkf_1.icnt - 1] = msalt;
    eqlhkf_1.islt[(eqlhkf_1.icnt << 2) - 4] = nsplus;
    eqlhkf_1.islt[(eqlhkf_1.icnt << 2) - 3] = nsmin;
    eqlhkf_1.islt[(eqlhkf_1.icnt << 2) - 2] = (integer) sfplus;
    eqlhkf_1.islt[(eqlhkf_1.icnt << 2) - 1] = (integer) sfmin;

/*              go back for next salt */

    goto L100;

/*              exit and check to see if normal termination */

L600:
    if (qck) {
	if (minus < xl && plus < xl) {
	    io___852.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___852);
	    e_wsfe();
	} else {
	    io___853.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___853);
	    e_wsfe();
	}
    }

/*              write out list of salts */

    if (qck) {
	io___854.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___854);
	e_wsfe();
	io___855.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___855);
	i__1 = eqlhkf_1.icnt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 4; ++j) {
		do_fio(&c__1, (char *)&eqlhkf_1.islt[j + (i__ << 2) - 5], (
			ftnlen)sizeof(integer));
	    }
	    do_fio(&c__1, (char *)&eqlhkf_1.mslt[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }

    return 0;
} /* molslt_ */

/* msolvr    last modified 01/25/88 by rmm */
/* b*msolvr created in f77 11/10/87 by tjw */
/* Subroutine */ int msolvr_(doublereal *aa, doublereal *gm, doublereal *rhs, 
	doublereal *del, doublereal *res, doublereal *ee, integer *ir, 
	integer *kdim, integer *kmax, integer *ier, logical *qpr, logical *
	qpri)
{
    /* Format strings */
    static char fmt_1000[] = "(\002 --- sgeco (l-u decomp.) failed (eqlib/ms"
	    "olvr) ---\002)";
    static char fmt_1010[] = "(\002 --- itrefn (iter. impr.) failed (eqlib/m"
	    "solvr) ---\002)";

    /* System generated locals */
    integer aa_dim1, aa_offset, gm_dim1, gm_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer j, k;
    extern /* Subroutine */ int sgeco_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, doublereal *);
    static doublereal rcond;
    extern /* Subroutine */ int sgesl_(doublereal *, integer *, integer *, 
	    integer *, doublereal *), itrefn_(doublereal *, doublereal *, 
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, logical *, integer *);

    /* Fortran I/O blocks */
    static cilist io___860 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___861 = { 0, 0, 0, fmt_1010, 0 };



/*     this routine solves the matrix equation (aa) (del) = (rhs). */
/*     the method employed is l-u decomposition.  if the reciprocal */
/*     condition number (rcond) is less than 100 times the machine */
/*     epsilon, the solution is iteratively improved. */

/*     input */
/*       aa = matrix */
/*       kdim = the actual dimention of the matrix */
/*       kmax = the maximum dimension of the matrix */
/*       gm = work space for a copy of the matrix */
/*       rhs = the right hand side vector */
/*       res = work space vector */
/*       ee = work space vector */
/*       ir = work space vector */
/*       qpr = logical switch to print messages from msolvr */
/*       qpri = logical switch to turn on print messages from */
/*                routine itrefn */
/*     output */
/*       del = the solution vector */
/*       rcond = the reciprocal condition number */
/*       ier = error flag */
/*         =  -1  l-u decomposition worked, but iterative improvement */
/*                failed (this is just a warning condition) */
/*         =   0  the solution worked okay */
/*         = 800  l-u decomposition failed; rcond .lt. smpos */
/*     other */
/*       smpos = the smallest positive number (real*8) */
/*       eps100 = 100 times the machine epsilon (real*8) */

/* -------------------------------------------------------------------- */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/* -------------------------------------------------------------------- */
/* eqlun.h */

/* -------------------------------------------------------------------- */

/*     copy aa to working array gm */

    /* Parameter adjustments */
    --rhs;
    --del;
    --res;
    --ee;
    --ir;
    gm_dim1 = *kmax;
    gm_offset = 1 + gm_dim1;
    gm -= gm_offset;
    aa_dim1 = *kmax;
    aa_offset = 1 + aa_dim1;
    aa -= aa_offset;

    /* Function Body */
    i__1 = *kdim;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *kdim;
	for (k = 1; k <= i__2; ++k) {
	    gm[j + k * gm_dim1] = aa[j + k * aa_dim1];
/* L10: */
	}
/* L20: */
    }

/*     factor the matrix */

    sgeco_(&gm[gm_offset], kmax, kdim, &ir[1], &rcond, &ee[1]);

/*     note- the test rcond .lt. eps, is not sufficient to guarantee */
/*     singularity.  in practice, it has been observed that this */
/*     condition is frequently true, but the results of the matrix */
/*     decomposition are useful anyway.  on the other hand, it has */
/*     also been observed that a theoretically singular matrix can */
/*     sometimes be factored, due to rounding/truncation in the */
/*     decomposition process.  see documentation in the eqlib routines */
/*     sgeco and sgefa. */

    if (rcond < eqleps_1.smpos) {
	*ier = 800;
	if (*qpr) {
	    io___860.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___860);
	    e_wsfe();
	}
	goto L999;
    }

/*      copy rhs to del */

    i__1 = *kdim;
    for (j = 1; j <= i__1; ++j) {
	del[j] = rhs[j];
/* L30: */
    }

/*     solve the matrix equation */

    sgesl_(&gm[gm_offset], kmax, kdim, &ir[1], &del[1]);

    if (rcond <= eqleps_1.eps100) {

/*       iteratively improve the solution to the matrix equation */

	itrefn_(&aa[aa_offset], &gm[gm_offset], kmax, kdim, &ir[1], &rhs[1], &
		del[1], &rcond, &res[1], &ee[1], qpri, ier);

	if (*ier > 0) {
	    *ier = -1;
	    if (*qpr) {
		io___861.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___861);
		e_wsfe();
	    }
	}
    }

L999:
    return 0;
} /* msolvr_ */

/* nactop   last revised 11/02/87 by tjw */
/* *nactop f77 check, 07/08/87 by tjw */
/* Subroutine */ int nactop_(void)
{
    /* Initialized data */

    static char uoff[8] = "off     ";
    static char uon[8] = "on      ";
    static char uonplu[8] = "onplus  ";
    static char uerr[32] = "error                           ";
    static char um1[32] = "davies equation                 ";
    static char uze[32] = "b-dot equation plus others      ";
    static char up1[32] = "pitzer equations (standard)     ";
    static char up3[32] = "dh(o/c)a + e-l hydr. theory     ";
    static char up4[32] = "dh(o/c)a hydration theory       ";
    static char up5[32] = "hkf equations - part iv         ";

    /* Format strings */
    static char fmt_1005[] = "(\002 * error- iopg1= \002,i5,\002 is not a va"
	    "lid activity\002,\002 coefficient\002,/11x,\002option (eqlib/nac"
	    "top)\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___872 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___873 = { 0, 0, 0, fmt_1005, 0 };



/*     this routine sets the name of the option for the activity */
/*     coefficients of aqueous species.  it also sets associated */
/*     logical flags concerning the generic type of activity */
/*     coefficient option.  the variable iopg1 determines the exact */
/*     activity coefficient model as well as exactly how the model is */
/*     to be treated numerically.  more than one value of iopg1 may */
/*     set the same logical flag (e.g., qhydth, qpt4) to .true.. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ------------------------------------------------------------------- */

/*     qhydth is set to .true. if the activity coefficient option */
/*     involves hydration theory.  this activates usage of the parameter */
/*     dshm (= 1. - ( sigma(hm)/om ). */

    eqlgpa_1.qhydth = FALSE_;

/*     qpt4 is set to .true. if hkf equations are being used */

    eqlgpa_1.qpt4 = FALSE_;

/*     set for null e-lambda terms.  override later for */
/*     specific options requiring such terms. */

    s_copy(eqlgpc_1.uelam, uoff, (ftnlen)8, (ftnlen)8);
    eqlgpa_1.ielam = -1;

/*     iopg3 = switch for e-lambda treatment- 0/1 = on/onplus */

    if (eqlgp_1.iopg1 != 3) {
	eqlgp_1.iopg3 = 0;
    }

/*     iopg4 = switch for hydration theory f term- 0/1 = dhoa/dhca */

    if ((real) eqlgp_1.iopg1 != 3.f && eqlgp_1.iopg1 != 4) {
	eqlgp_1.iopg4 = 0;
    }

/*     note- iopg1 .le. 0 is used for simple ionic strength dependent */
/*     models.  iopg1 .ge. 1 is used for specific composition dependent */
/*     models, such as pitzer's equations. */

    if (eqlgp_1.iopg1 == 0) {

/*       b-dot equation and others (b-dot package) */

	s_copy(eqlgpc_1.uactop, uze, (ftnlen)32, (ftnlen)32);
    } else if (eqlgp_1.iopg1 == -1) {

/*       the davies equation */

	s_copy(eqlgpc_1.uactop, um1, (ftnlen)32, (ftnlen)32);

    } else if (eqlgp_1.iopg1 == 1) {

/*       pitzer's equations (standard) */

	s_copy(eqlgpc_1.uactop, up1, (ftnlen)32, (ftnlen)32);

/*       note- ielam is determined in routine indpt from the pitzer */
/*       data file input */

    } else if (eqlgp_1.iopg1 == 2) {

/*       reserved for pitzer style option */

	s_copy(eqlgpc_1.uactop, uerr, (ftnlen)32, (ftnlen)32);
    } else if (eqlgp_1.iopg1 == 3) {

/*       wolery - jackson dh(o/c)a + e-l hydration theory */

	s_copy(eqlgpc_1.uactop, up3, (ftnlen)32, (ftnlen)32);
	eqlgpa_1.qhydth = TRUE_;
	if (eqlgp_1.iopg3 > 0) {
	    eqlgpa_1.ielam = 1;
	    s_copy(eqlgpc_1.uelam, uonplu, (ftnlen)8, (ftnlen)8);
	} else {
	    eqlgpa_1.ielam = 0;
	    s_copy(eqlgpc_1.uelam, uon, (ftnlen)8, (ftnlen)8);
	}
    } else if (eqlgp_1.iopg1 == 4) {

/*       wolery - jackson dh(o/c)a hydration theory */

	s_copy(eqlgpc_1.uactop, up4, (ftnlen)32, (ftnlen)32);
	eqlgpa_1.qhydth = TRUE_;
	eqlgpa_1.ielam = -1;
    } else if (eqlgp_1.iopg1 == 5) {

/*       hkf equations - part iv */

	s_copy(eqlgpc_1.uactop, up5, (ftnlen)32, (ftnlen)32);
	eqlgpa_1.qpt4 = TRUE_;
    } else {

/*       error */

	s_copy(eqlgpc_1.uactop, uerr, (ftnlen)32, (ftnlen)32);
	io___872.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___872);
	do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
	e_wsfe();
	io___873.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___873);
	do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    return 0;
} /* nactop_ */

/* nbsgam   last revised 11/20/87 by tjw */
/* *nbsgam created in f77 11/19/87 by tjw */
/* Subroutine */ int nbsgam_(doublereal *glgnbs, doublereal *xi, doublereal *
	adh, integer *nchlor)
{
    /* Format strings */
    static char fmt_1000[] = "(\002 * error- no index for the chloride io"
	    "n\002,\002 (eqlib/nbsgam)\002,/7x,\002can not use the extended n"
	    "bs ph scale\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal xisqrt;

    /* Fortran I/O blocks */
    static cilist io___874 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___875 = { 0, 0, 0, fmt_1000, 0 };



/*     this routine calculates the log activity coefficient of the */
/*     chloride ion according to the nbs ph convention.  the convention */
/*     itself may be extended outside the specified limit on the */
/*     ionic strength. */

/*     reference- covington, a.k., bates, r.g., and durst, r.a., 1985, */
/*     defintion of ph scales, standard reference values, measurement */
/*     of ph and related terminology (recommendations, 1984), pure */
/*     app. chem., v. 57, p. 533-542. */

/*     input */
/*       xi = ionic strength */
/*       adh = the debye-huckel 'a' parameter */
/*       nchlor = the ns index of the chloride ion */

/*     output */
/*       glgnbs = log gamma cl-, according to the bates-guggenheim */
/*                convention */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     test the index of the chloride ion */

/* -------------------------------------------------------------------- */
/* eqlun.h */
    if (*nchlor <= 0) {
	io___874.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___874);
	e_wsfe();
	io___875.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___875);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     evaluate the nbs expression for the molal activity coefficient */
/*     of the chloride ion */

    xisqrt = sqrt(*xi);
    *glgnbs = -(*adh * xisqrt) / (xisqrt * 1.5f + 1.f);

    return 0;
} /* nbsgam_ */

/* newton   last revised 01/25/88 by rmm */
/* Subroutine */ int newton_(doublereal *cdrs, doublereal *aa, doublereal *gm,
	 doublereal *zvclg1, doublereal *del, doublereal *rhs, doublereal *ee,
	 doublereal *res, doublereal *conc, doublereal *cxistq, doublereal *
	beta, doublereal *alpha, doublereal *z__, doublereal *zsq2, 
	doublereal *azero, doublereal *hydn, doublereal *glg, doublereal *
	glgo, doublereal *betao, doublereal *delo, doublereal *concbs, 
	doublereal *screwd, doublereal *screwn, doublereal *tolbt, doublereal 
	*toldl, doublereal *tempc, doublereal *press, doublereal *betamx, 
	doublereal *bbig, doublereal *bneg, doublereal *bgamx, doublereal *xi,
	 doublereal *xisteq, doublereal *dshm, doublereal *shm, doublereal *
	shmlim, char *uspec, char *uzvec1, char *uqdel, char *uqbeta, char *
	ubbig, char *ubneg, char *ubgamx, integer *jsflag, integer *jsort, 
	integer *ir, integer *iter, integer *itermx, integer *idelmx, integer 
	*ibetmx, integer *iacion, integer *kmax, integer *kdim, integer *
	nsqmx1, integer *nsb, integer *nsq, integer *nst, integer *nhydr, 
	integer *nchlor, integer *ier, logical *qpra, logical *qprb, logical *
	qprc, integer *ncarb, ftnlen uspec_len, ftnlen uzvec1_len, ftnlen 
	uqdel_len, ftnlen uqbeta_len, ftnlen ubbig_len, ftnlen ubneg_len, 
	ftnlen ubgamx_len)
{
    /* Initialized data */

    static char ublank[8] = "        ";
    static logical qfalse = FALSE_;

    /* Format strings */
    static char fmt_2160[] = "(/3x,\002kcol\002,3x,\002uzvec1\002,10x,\002co"
	    "rrection\002,3x,\002zvclg1\002,/)";
    static char fmt_2145[] = "(3x,i3,2x,a12,3x,1pe15.8,3x,0pf15.10)";
    static char fmt_2150[] = "(//7x,\002kcol\002,3x,\002uzvec1\002,10x,\002b"
	    "eta\002,/)";
    static char fmt_2300[] = "(/3x,\002xi = \002,1pe12.5)";
    static char fmt_2302[] = "(/3x,\002xisteq = \002,1pe12.5)";
    static char fmt_2304[] = "(/3x,\002shm = \002,1pe12.5)";
    static char fmt_2137[] = "(/3x,\002--- pre-newton-raphson update of acti"
	    "vity\002,\002 coefficients ---\002,/)";
    static char fmt_2135[] = "(1x)";
    static char fmt_2095[] = "(\002 iter= \002,i3,\002, delmax= \002,1pe12"
	    ".5,\002 (unrelaxed)\002,/7x,\002 del(\002,2a8,\002)= \002,1pe12."
	    "5,\002, delfnc = \002,1pe12.5,/7x,\002beta(\002,2a8,\002)= \002,"
	    "1pe12.5,\002, betfnc = \002,1pe12.5)";
    static char fmt_2092[] = "(7x,\002no. of under-relaxation cycles= \002,i"
	    "3)";
    static char fmt_2093[] = "(8x,\002bbig= \002,1pe12.5,\002, ubbig= \002,a"
	    "24)";
    static char fmt_2094[] = "(8x,\002bneg= \002,1pe12.5,\002, ubneg= \002,a"
	    "24)";
    static char fmt_2096[] = "(7x,\002bgamx= \002,1pe12.5,\002, ubgamx= \002"
	    ",a24)";
    static char fmt_2097[] = "(9x,\002bxi= \002,1pe12.5,\002, bxistq= \002,1"
	    "pe12.5)";
    static char fmt_2098[] = "(9x,\002bxi= \002,1pe12.5,\002, bshm= \002,1pe"
	    "12.5)";
    static char fmt_2099[] = "(9x,\002bxi= \002,1pe12.5)";
    static char fmt_2040[] = "(\002 --- newton-raphson iteration pseudo-conv"
	    "erged\002,\002 ---\002,/)";
    static char fmt_2042[] = "(11x,\002del (\002,i5,2x,a24,\002) = \002,g12."
	    "5)";
    static char fmt_2030[] = "(\002 --- iteration has gone sour (iter= \002,"
	    "i3,\002) ---\002)";
    static char fmt_2139[] = "(/3x,\002--- post-newton-raphson update of act"
	    "ivity\002,\002 coefficients ---\002,/)";

    /* System generated locals */
    integer cdrs_dim1, cdrs_offset, aa_dim1, aa_offset, gm_dim1, gm_offset, 
	    i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal bx, dx;
    static integer ns;
    static doublereal bxi;
    static char utb[8], utd[8];
    static doublereal xio;
    static integer kcol;
    static doublereal bshm, shmo;
    static integer ncut;
    static logical qcdel, qcgam;
    extern /* Subroutine */ int betas_(logical *, logical *);
    static doublereal dshmo;
    static logical qconv;
    static integer negbfc, negdfc;
    static doublereal delfnc;
    extern /* Subroutine */ int betgam_(char *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, char *, ftnlen, ftnlen);
    static logical qcbeta;
    static doublereal betfnc;
    extern /* Subroutine */ int ngcadv_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, logical *, integer *, ftnlen);
    static doublereal delmax, delmxo, betmxo;
    static char udelmx[8];
    static integer npconv;
    static char ubetmx[8];
    static doublereal bxistq;
    extern /* Subroutine */ int nrstep_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, logical *, logical *, logical *, logical *, 
	    ftnlen);
    static doublereal xistqo;

    /* Fortran I/O blocks */
    static cilist io___888 = { 0, 0, 0, fmt_2160, 0 };
    static cilist io___889 = { 0, 0, 0, fmt_2145, 0 };
    static cilist io___890 = { 0, 0, 0, fmt_2150, 0 };
    static cilist io___891 = { 0, 0, 0, fmt_2145, 0 };
    static cilist io___892 = { 0, 0, 0, fmt_2300, 0 };
    static cilist io___893 = { 0, 0, 0, fmt_2302, 0 };
    static cilist io___894 = { 0, 0, 0, fmt_2304, 0 };
    static cilist io___900 = { 0, 0, 0, fmt_2137, 0 };
    static cilist io___904 = { 0, 0, 0, fmt_2150, 0 };
    static cilist io___905 = { 0, 0, 0, fmt_2145, 0 };
    static cilist io___906 = { 0, 0, 0, fmt_2135, 0 };
    static cilist io___913 = { 0, 0, 0, fmt_2095, 0 };
    static cilist io___914 = { 0, 0, 0, fmt_2092, 0 };
    static cilist io___916 = { 0, 0, 0, fmt_2093, 0 };
    static cilist io___917 = { 0, 0, 0, fmt_2094, 0 };
    static cilist io___918 = { 0, 0, 0, fmt_2096, 0 };
    static cilist io___919 = { 0, 0, 0, fmt_2097, 0 };
    static cilist io___920 = { 0, 0, 0, fmt_2098, 0 };
    static cilist io___921 = { 0, 0, 0, fmt_2099, 0 };
    static cilist io___926 = { 0, 0, 0, fmt_2040, 0 };
    static cilist io___927 = { 0, 0, 0, fmt_2042, 0 };
    static cilist io___928 = { 0, 0, 0, fmt_2030, 0 };
    static cilist io___929 = { 0, 0, 0, fmt_2139, 0 };
    static cilist io___930 = { 0, 0, 0, fmt_2150, 0 };
    static cilist io___931 = { 0, 0, 0, fmt_2145, 0 };
    static cilist io___932 = { 0, 0, 0, fmt_2135, 0 };



/*     this routine performs hybrid newton-raphson iteration to solve */
/*     for the equilibrium distribution of species which corresponds */
/*     to a set of constraints (total concentrations, ph, eh, */
/*     temperature, pressure, etc.) on an aqueous solution. */

/*     input */
/*       cdrs = array of coefficients for aqueous complex dissociation */
/*              reactions */
/*       cxistq = array of stoichiometric factors for calculating xisteq */
/*       z = electrical charge array */
/*       zsq2 = one half the charge squared array */
/*       azero = ion size array */
/*       hydn = hydration number array */
/*       screwd = under-relaxation control parameter.  it is used to */
/*                reduce the magnitude of the del vector, if necessary */
/*                so that the magnitude of the largest element of that */
/*                vector does not exceed screwd. */
/*       screwn = under-relaxation control parameter */
/*       tolbt = convergence tolerance on betamx */
/*       toldl = convergence tolerance on delmax */
/*       tempc = temperature, deg celsius */
/*       press = pressure, bars */
/*       shmlim = temporary upper limit imposed on shm */
/*       uspec = aqueous species name array */
/*       uzvec1 = name array corresponding to zvclg1 */
/*       uqdel = description of quantity type for del corrections; */
/*                e.g., 'conc' or 'moles' */
/*       uqbeta = description of quantity type for beta vector; */
/*                e.g., 'conc' or 'moles' */
/*       jsflag = status flag for aqeuous species, species active if jsflag */
/*                .le. 0 */
/*       itermx = maximum number of iterations */
/*       iacion = index of the species (na+ or cl-) used to define xisteq */
/*       kmax = maximum dimension of aa */
/*       kdim = dimension of aa */
/*       nsqmx1 = first dimension of the cdrs array */
/*       nsb = number of strict master species */
/*       nsq = number of master species */
/*       nst = number of aqeuous species */
/*       nhydr = ns index of the hydrogen ion */
/*       nchlor = ns index of the chloride ion */
/*       matrxe = external that prints aa, matrix for eq3nr, matrxz for eq6 */
/*       ncmpe = external that expands the system description so that */
/*               residuals can be calculated, ncmpx for eq3nr, ncmpz for */
/*               eq6.  mostly this involves calculating the concentrations */
/*               of dependent aqueous species. */
/*       betae = external that calculates the beta array, betas for eq3nr, */
/*               betaz for eq6. */
/*       qpra = debugging print flag, if true, prints summary information */
/*       qprb = debugging print flag, if true, causes most details to be */
/*              printed (does not cause the jacobian matrix to be printed) */
/*       qprc = debugging print flag, if true, causes the jacobian matrix */
/*              to be printed */

/*     input/output */
/*       zvclg1 = the 'log z' array, the array corrected by */
/*                newton-raphson iteration */
/*       conc = concentration array */
/*       glg = activity coefficient array */
/*       xi = ionic strength */
/*       xisteq = equivalent stoichiometric ionic strength */
/*       dshm = hydration theory 'd' parameter */
/*       shm = hydration theory 'sigma hm' parameter */

/*     work space/output */
/*       aa = jacobian matrix */
/*       gm = copy of aa */
/*       del = correction array */
/*       rhs = right hand side vector */
/*       ee = floating point work space vector */
/*       res = floating point work space vector */
/*       beta = normalized residual function array */
/*       alpha = residual function array */
/*       glgo = old activity coefficient array */
/*       betao = old beta array */
/*       delo = old delo array */
/*       concbs = total concentrations of master species array */
/*       betamx = norm (largest magnitude) of the beta array */
/*       bbig = largest magnitude positive mass balance residual */
/*       bneg = largest magnitude negative mass balance residual */
/*       bgamx = norm (largest magnitude) aqeuous phase activity */
/*               coefficient residual */
/*       ubbig = name of species corresponding to bbig */
/*       ubneg = name of species corresponding to bneg */
/*       ubgamx = name of species corresponding to bgamx */
/*       ir = integer work space vector */
/*       iter = newton-raphson iteration number */
/*       jsort = array of aqueous species indices, arranged in order of */
/*               increasing concentration or mole number */
/*       idelmx = kcol index corresponding to delmax */
/*       ibetmx = kcol index corresponding to betamx */
/*       ier = error flag, okay if .le. 0 */

/* ------------------------------------------------------------------------ */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* -------------------------------------------------------------------- */
/* eqlun.h */



    /* Parameter adjustments */
    --zvclg1;
    --del;
    --rhs;
    --ee;
    --res;
    --conc;
    --cxistq;
    --beta;
    --alpha;
    --z__;
    --zsq2;
    --azero;
    --hydn;
    --glg;
    --glgo;
    --betao;
    --delo;
    --concbs;
    uspec -= uspec_len;
    uzvec1 -= uzvec1_len;
    uqdel -= uqdel_len;
    uqbeta -= uqbeta_len;
    --jsflag;
    --jsort;
    --ir;
    gm_dim1 = *kmax;
    gm_offset = 1 + gm_dim1;
    gm -= gm_offset;
    aa_dim1 = *kmax;
    aa_offset = 1 + aa_dim1;
    aa -= aa_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;

    /* Function Body */

/* ---------------------------------------------------------------------- */

    *iter = 0;
    *ier = 0;
    *idelmx = 0;
    *ibetmx = 0;
    npconv = 0;

    delmax = 0.f;
    betfnc = 0.f;
    delfnc = 0.f;
    betmxo = 0.f;
    delmxo = 0.f;
    negdfc = 0;
    negbfc = 0;
    i__1 = *kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	del[kcol] = 0.f;
/* L40: */
    }

/*     debugging prints- state of the system prior to newton-raphson */
/*     iteration. */

    if (*qprb) {
	io___888.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___888);
	e_wsfe();
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    io___889.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___889);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
	    do_fio(&c__1, (char *)&del[kcol], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&zvclg1[kcol], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L90: */
	}

	io___890.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___890);
	e_wsfe();
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    io___891.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___891);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
	    do_fio(&c__1, (char *)&beta[kcol], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L105: */
	}
    }

    if (*qprb) {
	io___892.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___892);
	do_fio(&c__1, (char *)&(*xi), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (eqlgp_1.iopg1 == 0) {
	    io___893.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___893);
	    do_fio(&c__1, (char *)&(*xisteq), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (eqlgpa_1.qhydth) {
	    io___894.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___894);
	    do_fio(&c__1, (char *)&(*shm), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }

    xio = *xi;
    if (eqlgp_1.iopg1 == 0) {
	xistqo = *xisteq;
    }
    if (eqlgpa_1.qhydth) {
	shmo = *shm;
	dshmo = *dshm;
    }

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	glgo[ns] = glg[ns];
/* L206: */
    }

/*     the label below is the return point for iter .ge. 1. */
/*     note- do not call ncmpe here to calculate the concentrations */
/*     of dependent species, etc.  this should be unnecessary. */

/*     recompute xi, xisteq, shm, dshm.  recompute activity coefficients. */
/*     then recompute the concentrations of dependent aqueous species. */
/*     then compute the residual functions.  then do a newton-raphson */
/*     step. */

L200:
    if (*qprb) {
	io___900.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___900);
	e_wsfe();
    }

    ngcadv_(&cdrs[cdrs_offset], &glg[1], &glgo[1], &z__[1], &zsq2[1], &azero[
	    1], &hydn[1], &conc[1], &concbs[1], &cxistq[1], xi, xisteq, shm, 
	    shmlim, dshm, tempc, press, &xio, &xistqo, &shmo, uspec + 
	    uspec_len, &jsflag[1], &jsort[1], nsb, nsq, nsqmx1, nst, nhydr, 
	    nchlor, iacion, iter, ier, qprb, ncarb, uspec_len);

/*     calculate xi, etc., related residual functions.  save old values */
/*     of xi, etc., and the activity coefficients */

    bxi = (*xi - xio) / xio;
    if (eqlgp_1.iopg1 == 0) {
	bxistq = (*xisteq - xistqo) / xistqo;
    }
    if (eqlgpa_1.qhydth) {
	bshm = (*shm - shmo) / shmo;
    }
    betgam_(uspec + uspec_len, &conc[1], &glg[1], &glgo[1], nst, bgamx, 
	    ubgamx, uspec_len, ubgamx_len);

    xio = *xi;
    if (eqlgp_1.iopg1 == 0) {
	xistqo = *xisteq;
    }
    if (eqlgpa_1.qhydth) {
	shmo = *shm;
	dshmo = *dshm;
    }
    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	glgo[ns] = glg[ns];
/* L207: */
    }

/* --------------------------------------------------------------------- */

/*     set up for the newton-raphson step.  important- do not */
/*     recompute activity coefficients within this block.  it */
/*     might interfere with the resdual tracking under-relaxation */
/*     algorithm. */

/*     recalculate the newton-raphson residual functions. */

    betas_(&qfalse, &qfalse);

/*     save the current values of beta and del for use in */
/*     under-relaxation schemes. */

    i__1 = *kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	betao[kcol] = (d__1 = beta[kcol], abs(d__1));
	delo[kcol] = del[kcol];
/* L195: */
    }

    if (*qprb) {
	io___904.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___904);
	e_wsfe();
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    io___905.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___905);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
	    do_fio(&c__1, (char *)&beta[kcol], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L965: */
	}
	io___906.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___906);
	e_wsfe();
    }

    bx = 0.f;
    dx = 0.f;
    if (*ibetmx > 0) {
	bx = beta[*ibetmx];
    }
    if (*idelmx > 0) {
	dx = del[*idelmx];
    }
    delfnc = 0.f;
    if (delmxo >= eqleps_1.smpos) {
	delfnc = (delmxo - delmax) / delmxo;
    }
    delmxo = delmax;
    betfnc = 0.f;
    if (betmxo >= eqleps_1.smpos) {
	betfnc = (betmxo - *betamx) / betmxo;
    }
    betmxo = *betamx;

    if (*qpra) {

	s_copy(ubetmx, ublank, (ftnlen)8, (ftnlen)8);
	s_copy(utb, ublank, (ftnlen)8, (ftnlen)8);
	s_copy(udelmx, ublank, (ftnlen)8, (ftnlen)8);
	s_copy(utd, ublank, (ftnlen)8, (ftnlen)8);

	if (*ibetmx > 0) {
	    s_copy(utb, uqbeta + *ibetmx * uqbeta_len, (ftnlen)8, uqbeta_len);
	    s_copy(ubetmx, uzvec1 + *ibetmx * uzvec1_len, (ftnlen)8, 
		    uzvec1_len);
	}

	if (*idelmx > 0) {
	    s_copy(utd, uqdel + *idelmx * uqdel_len, (ftnlen)8, uqdel_len);
	    s_copy(udelmx, uzvec1 + *idelmx * uzvec1_len, (ftnlen)8, 
		    uzvec1_len);
	}

	io___913.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___913);
	do_fio(&c__1, (char *)&(*iter), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&delmax, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, utd, (ftnlen)8);
	do_fio(&c__1, udelmx, (ftnlen)8);
	do_fio(&c__1, (char *)&dx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&delfnc, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, utb, (ftnlen)8);
	do_fio(&c__1, ubetmx, (ftnlen)8);
	do_fio(&c__1, (char *)&bx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&betfnc, (ftnlen)sizeof(doublereal));
	e_wsfe();

	io___914.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___914);
	do_fio(&c__1, (char *)&ncut, (ftnlen)sizeof(integer));
	e_wsfe();
	io___916.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___916);
	do_fio(&c__1, (char *)&(*bbig), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, ubbig, ubbig_len);
	e_wsfe();
	io___917.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___917);
	do_fio(&c__1, (char *)&(*bneg), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, ubneg, ubneg_len);
	e_wsfe();
	io___918.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___918);
	do_fio(&c__1, (char *)&(*bgamx), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, ubgamx, ubgamx_len);
	e_wsfe();
	if (eqlgp_1.iopg1 == 0) {
	    io___919.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___919);
	    do_fio(&c__1, (char *)&bxi, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&bxistq, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else if (eqlgpa_1.qhydth) {
	    io___920.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___920);
	    do_fio(&c__1, (char *)&bxi, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&bshm, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else {
	    io___921.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___921);
	    do_fio(&c__1, (char *)&bxi, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }

/*     check to see if the iteration satisfies the convergence criteria. */
/*     note that the residual norm for activity coefficients (bgamx) is */
/*     tested, but the residuals for ionic strength, etc., are not. */
/*     both residual functions and correction terms are tested. */
/*     iteration may terminate acceptably without satisfying the */
/*     constraint on the correction terms (see below). */

    qcbeta = *betamx <= *tolbt;
    qcdel = delmax <= *toldl;
    qconv = qcbeta && qcdel;
    qcgam = *bgamx <= *tolbt;

/*     force to run at least one iteration */

    if (*iter >= 1) {

/*       test for convergence */

	if (qconv && qcgam) {
	    goto L999;
	}
    }

    nrstep_(&aa[aa_offset], &gm[gm_offset], &rhs[1], &res[1], &ee[1], &ir[1], 
	    &zvclg1[1], &alpha[1], &beta[1], &del[1], &betao[1], &delo[1], 
	    screwd, screwn, betamx, &delmax, &delfnc, &betfnc, uzvec1 + 
	    uzvec1_len, itermx, kdim, kmax, idelmx, iter, &negdfc, &negbfc, &
	    npconv, ier, &qcbeta, &qcgam, qprb, qprc, uzvec1_len);

    if (*ier > 0) {

/*       iteration has been stopped */

	if (qcbeta && qcgam) {

/*         have pseudo-convergence */

	    *ier = 0;
	    if (*qpra) {
		io___926.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___926);
		e_wsfe();
		i__1 = *kdim;
		for (kcol = 1; kcol <= i__1; ++kcol) {
		    if ((d__1 = del[kcol], abs(d__1)) > *toldl) {
			io___927.ciunit = eqlun_1.noutpl;
			s_wsfe(&io___927);
			do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
			do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
			do_fio(&c__1, (char *)&del[kcol], (ftnlen)sizeof(
				doublereal));
			e_wsfe();
		    }
/* L283: */
		}
	    }
	    goto L999;
	} else {

/*         iteration has failed */

	    io___928.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___928);
	    do_fio(&c__1, (char *)&(*iter), (ftnlen)sizeof(integer));
	    e_wsfe();
	    *ier = 1;
	    goto L999;
	}
    }


/* ---------------------------------------------------------------------- */

/*     recompute xi, xisteq, shm, dshm.  recompute activity coefficients. */
/*     then recompute the concentrations of dependent species.  then */
/*     go back to recompute xi, etc. */

    if (*qprb) {
	io___929.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___929);
	e_wsfe();
    }

/*     get coefficients for xisteq, if needed */

    ngcadv_(&cdrs[cdrs_offset], &glg[1], &glgo[1], &z__[1], &zsq2[1], &azero[
	    1], &hydn[1], &conc[1], &concbs[1], &cxistq[1], xi, xisteq, shm, 
	    shmlim, dshm, tempc, press, &xio, &xistqo, &shmo, uspec + 
	    uspec_len, &jsflag[1], &jsort[1], nsb, nsq, nsqmx1, nst, nhydr, 
	    nchlor, iacion, iter, ier, qprb, ncarb, uspec_len);

    if (*qprb) {

/*       note- the following betae call is purely in support of a */
/*       debugging print. */

	betas_(&qfalse, &qfalse);
	io___930.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___930);
	e_wsfe();
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    io___931.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___931);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
	    do_fio(&c__1, (char *)&beta[kcol], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L967: */
	}
	io___932.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___932);
	e_wsfe();
    }

    goto L200;

L999:
    return 0;
} /* newton_ */

/* ngcadv   last revised 01/15/88 by tjw */
/* Subroutine */ int ngcadv_(doublereal *cdrs, doublereal *glg, doublereal *
	glgo, doublereal *z__, doublereal *zsq2, doublereal *azero, 
	doublereal *hydn, doublereal *conc, doublereal *concbs, doublereal *
	cxistq, doublereal *xi, doublereal *xisteq, doublereal *shm, 
	doublereal *shmlim, doublereal *dshm, doublereal *tempc, doublereal *
	press, doublereal *xio, doublereal *xistqo, doublereal *shmo, char *
	uspec, integer *jsflag, integer *jsort, integer *nsb, integer *nsq, 
	integer *nsqmx1, integer *nst, integer *nhydr, integer *nchlor, 
	integer *iacion, integer *iter, integer *ier, logical *qpr, integer *
	ncarb, ftnlen uspec_len)
{
    /* Initialized data */

    static doublereal xlim = 25.;

    /* Format strings */
    static char fmt_343[] = "(/\002 hydration theory has blown up-\002,/3x"
	    ",\002the calculated value of sigma (hm) is \002,1pe12.5,/3x,\002"
	    "this exceeds the physical limit of \002,0pf10.5,/3x,\002no physi"
	    "cal solution exists.\002,/)";
    static char fmt_2205[] = "(/9x,\002ns\002,6x,\002name\002,10x,\002glg"
	    "\002,9x,\002glgo\002,/)";
    static char fmt_2206[] = "(7x,i5,2x,a12,3x,1pe12.5,3x,1pe12.5)";

    /* System generated locals */
    integer cdrs_dim1, cdrs_offset, i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer ns;
    extern /* Subroutine */ int gxi_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *), gshm_(doublereal *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *), ncmpx_(void), 
	    gcoeff_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, integer *, integer *,
	     integer *), molint_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, doublereal *), 
	    gxistq_(doublereal *, doublereal *, integer *, integer *, 
	    doublereal *);

    /* Fortran I/O blocks */
    static cilist io___934 = { 0, 0, 0, fmt_343, 0 };
    static cilist io___935 = { 0, 0, 0, fmt_2205, 0 };
    static cilist io___937 = { 0, 0, 0, fmt_2206, 0 };
    static cilist io___938 = { 0, 0, 0, fmt_2206, 0 };



/*     this routine recalculates the ionic strength, etc., and the */
/*     activity coefficients of aqueous species, and then recalculates */
/*     the concentrations of dependent aqueous species.  it operates in */
/*     direct support of newton-raphson iteration. */

/*     input */
/*       cdrs = array of coefficients for aqueous complex dissociation */
/*              reactions */
/*       glgo = old activity coefficient array */
/*       jsort = array of aqueous species indices, arranged in order of */
/*               increasing concentration or mole number */
/*       nsb = number of strict master species */
/*       nsq = number of master species */
/*       nsqmx1 = first dimension of the cdrs array */
/*       nst = number of aqeuous species */
/*       nhydr = ns index of the hydrogen ion */
/*       nchlor = ns index of the chloride ion */
/*       iacion = index of the species (na+ or cl-) used to define xisteq */
/*       z = electrical charge array */
/*       zsq2 = one half the charge squared array */
/*       azero = ion size array */
/*       hydn = hydration number array */
/*       conc = concentration array */
/*       concbs = total concentrations of master species array */
/*       cxistq = array of stoichiometric factors for calculating xisteq */
/*       shmlim = temporary upper limit imposed on shm */
/*       tempc = temperature, deg celsius */
/*       press = pressure, bars */
/*       xio = old value of xi */
/*       xistqo = old value of xisteq */
/*       shmo = old value of shm */
/*       uspec = aqueous species name array */
/*       jsflag = status flag for aqeuous species, species active if jsflag */
/*                .le. 0 */
/*       iter = newton-raphson iteration number */
/*       ncmpe = external name, ncmpx for eq3nr, ncmpz for eq6 */
/*       qpr = debugging print flag, causes prints if true */

/*     output */
/*       glg = activity coefficient array */
/*       ier = error flag, okay if .le. 0 */
/*       xi = ionic strength */
/*       xisteq = equivalent stoichiometric ionic strength */
/*       shm = hydration theory 'sigma hm' parameter */
/*       dshm = hydration theory 'd' parameter */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */
/* eqlgp.h */


/* -------------------------------------------------------------------- */
/* eqlpp.h */

/* -------------------------------------------------------------------- */
/* eqlun.h */



    /* Parameter adjustments */
    --glg;
    --glgo;
    --z__;
    --zsq2;
    --azero;
    --hydn;
    --conc;
    --concbs;
    --cxistq;
    uspec -= uspec_len;
    --jsflag;
    --jsort;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;

    /* Function Body */

/* ---------------------------------------------------------------------- */

    gxi_(&zsq2[1], &conc[1], &jsort[1], nst, xi);
    *xi = min(*xi,xlim);
    if (eqlgp_1.iopg1 == 0 && *iacion > 0) {
	gxistq_(&cxistq[1], &conc[1], &jsort[1], nst, xisteq);
	*xisteq = min(*xisteq,xlim);
    }
    if (eqlgpa_1.qhydth) {
	gshm_(&hydn[1], &conc[1], &jsort[1], nst, shm, dshm);
	if (*shm > *shmlim) {
	    if (*iter <= 4) {
		*shm = *shmlim;
		*dshm = 1.f - *shm / eqlpp_1.om;
	    } else if (eqlpp_1.om - *shm <= eqleps_1.eps100) {

/*           shm exceeds the physical limit of about 55.51. */

		io___934.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___934);
		do_fio(&c__1, (char *)&(*shm), (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&eqlpp_1.om, (ftnlen)sizeof(doublereal))
			;
		e_wsfe();
		*ier = 700;
		goto L999;
	    }
	}
    }


/*      if (qpt4) call molint(conc,nsq,nst,cdrs,nsqmx1,nsb,3,concbs) */
    molint_(&conc[1], nsq, nst, &cdrs[cdrs_offset], nsqmx1, nsb, &c__3, &
	    concbs[1]);
    gcoeff_(&conc[1], &z__[1], &zsq2[1], &azero[1], &hydn[1], &concbs[1], &
	    glg[1], xi, xisteq, dshm, tempc, press, &jsflag[1], &jsort[1], 
	    iacion, nsb, nst, nsq, nhydr, nchlor);

    if (*qpr) {
	io___935.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___935);
	e_wsfe();
	ns = 1;
	io___937.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___937);
	do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
	do_fio(&c__1, (char *)&glg[ns], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&glgo[ns], (ftnlen)sizeof(doublereal));
	e_wsfe();
	i__1 = *nst;
	for (ns = 2; ns <= i__1; ++ns) {
	    if (conc[ns] > 0.f) {
		io___938.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___938);
		do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
		do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
		do_fio(&c__1, (char *)&glg[ns], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&glgo[ns], (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
/* L300: */
	}
    }

/*     recalculate the concentrations of dependent species, etc. */

    ncmpx_();

L999:
    return 0;
} /* ngcadv_ */

/* nrstep   last revised 12/28/87 by tjw */
/* Subroutine */ int nrstep_(doublereal *aa, doublereal *gm, doublereal *rhs, 
	doublereal *res, doublereal *ee, integer *ir, doublereal *zvclg1, 
	doublereal *alpha, doublereal *beta, doublereal *del, doublereal *
	betao, doublereal *delo, doublereal *screwd, doublereal *screwn, 
	doublereal *betamx, doublereal *delmax, doublereal *delfnc, 
	doublereal *betfnc, char *uzvec1, integer *itermx, integer *kdim, 
	integer *kmax, integer *idelmx, integer *iter, integer *negdfc, 
	integer *negbfc, integer *npconv, integer *ier, logical *qcbeta, 
	logical *qcgam, logical *qprb, logical *qprc, ftnlen uzvec1_len)
{
    /* Initialized data */

    static logical qfalse = FALSE_;

    /* Format strings */
    static char fmt_2090[] = "(\002 --- the maximum number of iterations h"
	    "ave\002,\002 been done ---\002)";
    static char fmt_1210[] = "(/5x,\002--- the aa array, with rhs ---\002,/)";
    static char fmt_1216[] = "(1x,i3,2x,a24)";
    static char fmt_1212[] = "((5(2x,g10.3),2x,g10.3))";
    static char fmt_1214[] = "(\002 \002)";
    static char fmt_2133[] = "(/3x,\002ncut= \002,i3,/)";
    static char fmt_2160[] = "(/3x,\002kcol\002,3x,\002uzvec1\002,10x,\002co"
	    "rrection\002,3x,\002zvclg1\002,/)";
    static char fmt_2145[] = "(3x,i3,2x,a12,3x,1pe15.8,3x,0pf15.10)";
    static char fmt_2150[] = "(//7x,\002kcol\002,3x,\002uzvec1\002,10x,\002b"
	    "eta\002,/)";
    static char fmt_2135[] = "(1x)";
    static char fmt_2180[] = "(\002 --- residual tracking requires\002,\002 "
	    "under-relaxation ---\002)";
    static char fmt_2020[] = "(\002 --- residual tracking indicates diverg"
	    "ing\002,\002 iteration\002,/\002 --- newton terminating ----\002)"
	    ;
    static char fmt_2138[] = "(/3x,\002a newton-raphson correction has bee"
	    "n\002,\002 completed\002,/)";

    /* System generated locals */
    integer aa_dim1, aa_offset, gm_dim1, gm_offset, i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen),
	     pow_ii(integer *, integer *);

    /* Local variables */
    static integer i__;
    static doublereal adel, adum, bdum;
    static integer kcol, ncut, krow;
    extern /* Subroutine */ int betas_(logical *, logical *);
    static integer ndamp;
    extern /* Subroutine */ int ncmpx_(void);
    static doublereal divfnc, facurx, divfmx;
    extern /* Subroutine */ int matrix_(void), msolvr_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, logical 
	    *, logical *);

    /* Fortran I/O blocks */
    static cilist io___941 = { 0, 0, 0, fmt_2090, 0 };
    static cilist io___943 = { 0, 0, 0, fmt_1210, 0 };
    static cilist io___944 = { 0, 0, 0, fmt_1216, 0 };
    static cilist io___945 = { 0, 0, 0, fmt_1212, 0 };
    static cilist io___947 = { 0, 0, 0, fmt_1214, 0 };
    static cilist io___954 = { 0, 0, 0, fmt_2133, 0 };
    static cilist io___955 = { 0, 0, 0, fmt_2160, 0 };
    static cilist io___956 = { 0, 0, 0, fmt_2145, 0 };
    static cilist io___957 = { 0, 0, 0, fmt_2150, 0 };
    static cilist io___958 = { 0, 0, 0, fmt_2145, 0 };
    static cilist io___959 = { 0, 0, 0, fmt_2135, 0 };
    static cilist io___962 = { 0, 0, 0, fmt_2180, 0 };
    static cilist io___963 = { 0, 0, 0, fmt_2020, 0 };
    static cilist io___964 = { 0, 0, 0, fmt_2138, 0 };



/*     this routine performs one newton-raphson iteration step. */

/*     input */
/*       res = floating point work space vector */
/*       ee = floating point work space vector */
/*       ir = integer work space vector */
/*       screwd = under-relaxation control parameter.  it is used to */
/*                reduce the magnitude of the del vector, if necessary */
/*                so that the magnitude of the largest element of that */
/*                vector does not exceed screwd. */
/*       screwn = under-relaxation control parameter */
/*       itermx = maximum number of iterations */
/*       kdim = dimension of aa */
/*       kmax = maximum dimension of aa */
/*       matrxe = external that writes aa, matrix for eq3nr, matrxz */
/*                for eq6 */
/*       ncmpe = external that expands the system description so that */
/*               residuals can be calculated, ncmpx for eq3nr, ncmpz */
/*               for eq6.  mostly this involves calculating the */
/*               concentrations of dependent aqueous species. */
/*       betae = external that calculates the beta array, betas for */
/*               eq3nr, betaz for eq6. */
/*       qcbeta = true if the convergence criterion on betamx was met */
/*       qcgam = true if the convergence criterion on activity */
/*               coefficients was met */
/*       qprb = debugging print flag, if true, causes most details to */
/*              be printed (does not cause the jacobian matrix to be */
/*              printed) */
/*       qprc = debugging print flag, if true, causes the jacobian */
/*              matrix to be printed */

/*     output */
/*       aa = jacobian matrix */
/*       gm = copy of aa */
/*       rhs = right hand side vector */
/*       alpha = residual function array */
/*       idelmx = kcol index corresponding to delmax */
/*       delfnc = convergence function, defined by reference to delmax */
/*       betfnc = convergence function, defined by reference to betamx */
/*       uzvec1 = name array corresponding to zvclg1 */
/*       ier = error flag, okay if .le. 0 */
/*             = 1  if divergence was detected */
/*             = 2  if iteration terminated because of an ill-posed */
/*                  matrix */

/*     input/output */
/*       iter = the number of newton-raphson iterations */
/*       negdfc = the number of successive iterations that the */
/*                 convergence function delfnc has been zero or negative */
/*       negbfc = the number of successive iterations that the */
/*                 convergence function betfnc has been zero or negative */
/*       npconv = number of successive steps in which the convergence */
/*                criteria on the residual norm has been satisfied */
/*       zvclg1 = the 'log z' array, the array corrected by */
/*                newton-raphson iteration */
/*       beta = normalized residual function array */
/*       del = correction array */
/*       betao = old beta array */
/*       delo = old delo array */
/*       betamx = norm (largest magnitude) of the beta array */
/*       delmax = norm (largest magntiude) of the del array */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */
/* eqlgp.h */


/* -------------------------------------------------------------------- */
/* eqlpp.h */

/* -------------------------------------------------------------------- */
/* eqlun.h */



    /* Parameter adjustments */
    --rhs;
    --res;
    --ee;
    --zvclg1;
    --alpha;
    --beta;
    --del;
    --betao;
    --delo;
    uzvec1 -= uzvec1_len;
    gm_dim1 = *kmax;
    gm_offset = 1 + gm_dim1;
    gm -= gm_offset;
    aa_dim1 = *kmax;
    aa_offset = 1 + aa_dim1;
    aa -= aa_offset;

    /* Function Body */

/* ---------------------------------------------------------------------- */

/*     ncut is the number of times the del array has been cut in */
/*     magntitude to satisfy  the under-relaxation algorithm that limits */
/*     residual growth. */

    ncut = 0;

/*     check to see if iteration should be stopped because there is */
/*     little probability of further improvement.  if any of the */
/*     following cause iteration to stop, the result is considered */
/*     acceptable if it satisfies the convergence criteria that */
/*     apply to residual functions and activity coefficients.. */

/*        1. convergence criteria on residuals and activity coefficients */
/*           are satisfied are four consecutive iterations. */

    if (*qcbeta && *qcgam) {
	++(*npconv);
	if (*npconv >= 4) {
	    goto L210;
	}
    } else {
	*npconv = 0;
    }

/*        2. the improvement function delfnc is negative or zero for */
/*           six consecutive iterations. */

    if (*iter > 8) {
	if (*delfnc < 0.f) {
	    ++(*negdfc);
	    if (*negdfc >= 6) {
		goto L210;
	    }
	} else {
	    *negdfc = 0;
	}
    }

/*        3. the improvement function betfnc is negative or zero for */
/*           six consecutive iterations. */

    if (*iter > 8) {
	if (*betfnc < 0.f) {
	    ++(*negbfc);
	    if (*negbfc >= 6) {
		goto L210;
	    }
	} else {
	    *negbfc = 0;
	}
    }

/*        4. the maximum number of iterations have been done. */

    if (*iter >= *itermx) {
	io___941.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___941);
	e_wsfe();
	goto L210;
    }

/*     do another newton-raphson iteration. */

    ++(*iter);

/*     calculate the jacobian matrix (matrxe = matrix for eq3nr, */
/*     matrxz for eq6) */

    matrix_();

    i__1 = *kdim;
    for (krow = 1; krow <= i__1; ++krow) {
	rhs[krow] = -alpha[krow];
/* L235: */
    }

    if (*qprc) {
	io___943.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___943);
	e_wsfe();

	i__1 = *kdim;
	for (krow = 1; krow <= i__1; ++krow) {
	    io___944.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___944);
	    do_fio(&c__1, (char *)&krow, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + krow * uzvec1_len, uzvec1_len);
	    e_wsfe();
	    io___945.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___945);
	    i__2 = *kdim;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, (char *)&aa[krow + i__ * aa_dim1], (ftnlen)
			sizeof(doublereal));
	    }
	    do_fio(&c__1, (char *)&rhs[krow], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    io___947.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___947);
	    e_wsfe();
/* L22: */
	}
    }

/*     solve the jacobian system. */

    msolvr_(&aa[aa_offset], &gm[gm_offset], &rhs[1], &del[1], &res[1], &ee[1],
	     ir, kdim, kmax, ier, &qfalse, &qfalse);
    if (*ier > 0) {
	*ier = 2;
	goto L999;
    }

/*     determine which correction terms are largest in magnitude. */
/*     in the limit of the solution, the (unrelaxed) correction */
/*     terms bound the error in the variables being calculated. */

    *ier = 0;
    *delmax = 0.f;
    *idelmx = 0;
    i__1 = *kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	adel = (d__1 = del[kcol], abs(d__1));
	if (adel > *delmax) {
	    *delmax = adel;
	    *idelmx = kcol;
	}
/* L257: */
    }

/*     apply under-relaxation according to various criteria.  this */
/*     application precedes evaluation of new residuals.  another */
/*     application follows such evaluation. */

/*       maintain bound on the largest magnitude of any correction */

    adel = (d__1 = del[*idelmx], abs(d__1));
    if (adel > *screwd) {
	facurx = *screwd / adel;
	i__1 = *kdim;
	for (krow = 1; krow <= i__1; ++krow) {
	    del[krow] *= facurx;
/* L260: */
	}
    }

/*       if the residual norm was large or the convergence function */
/*       has been small, go slow. */

    if (*iter <= 8) {
	if (*betamx > 2.f || *betfnc < .2f) {
	    if (*betamx > *screwn) {
		i__1 = *kdim;
		for (kcol = 1; kcol <= i__1; ++kcol) {
		    del[kcol] *= .5f;
/* L270: */
		}
	    }
	}
    }

/*       under-relax if necessary to avoid oscillation */

    adum = del[*idelmx];
    bdum = pow_ii(&c__2, &ndamp) * delo[*idelmx];
    if (adum * bdum >= 0.f || (d__1 = (adum + bdum) / adum, abs(d__1)) > .05f)
	     {
	ndamp = 0;
    } else {
	++ndamp;
	facurx = 1.f / pow_ii(&c__2, &ndamp);
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    del[kcol] = facurx * del[kcol];
/* L920: */
	}
    }

/*     apply correction terms.  the label below is a return point */
/*     for post-residual evaluation under-relaxation. */

    ncut = -1;
L275:
    ++ncut;
    if (*qprb) {
	io___954.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___954);
	do_fio(&c__1, (char *)&ncut, (ftnlen)sizeof(integer));
	e_wsfe();
    }

    i__1 = *kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	zvclg1[kcol] += del[kcol];
/* L280: */
    }

    if (*qprb) {
	io___955.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___955);
	e_wsfe();
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    io___956.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___956);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
	    do_fio(&c__1, (char *)&del[kcol], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&zvclg1[kcol], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L281: */
	}
    }

/*     expand the system and recalculate the newton-raphson residual */
/*     functions.  it is important here to keep the activity coefficients */
/*     constant,that is, not to update them until all under-relaxation */
/*     has been completed.  ncmpe = ncmpx for eq3nr, ncmpz for eq6. */
/*     betae = betas for eq3nr, betaz for eq6. */

    ncmpx_();
    betas_(&qfalse, &qfalse);

    if (*qprb) {
	io___957.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___957);
	e_wsfe();
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    io___958.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___958);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, uzvec1 + kcol * uzvec1_len, uzvec1_len);
	    do_fio(&c__1, (char *)&beta[kcol], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L968: */
	}
	io___959.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___959);
	e_wsfe();
    }

/*       under-relax to control residual growth.  terminate */
/*       if residual tracking indicates that the iteration */
/*       is diverging. */

    if (*iter <= 12) {
	divfmx = 0.f;
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    divfnc = (d__1 = beta[kcol], abs(d__1)) - betao[kcol];
	    if (divfmx > divfnc) {
		divfmx = divfnc;
	    }
/* L160: */
	}
	if (divfmx > .1f) {
	    ++ncut;
	    if (ncut <= 8) {
		if (*qprb) {
		    io___962.ciunit = eqlun_1.noutpl;
		    s_wsfe(&io___962);
		    e_wsfe();
		}
		i__1 = *kdim;
		for (kcol = 1; kcol <= i__1; ++kcol) {
		    zvclg1[kcol] -= del[kcol];
		    del[kcol] *= .5f;
/* L175: */
		}
		goto L275;
	    }
	    if (*iter > 8) {
		io___963.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___963);
		e_wsfe();
		goto L210;
	    }
	}
    }

    if (*qprb) {
	io___964.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___964);
	e_wsfe();
    }
    goto L999;


L210:
    *ier = 1;

L999:
    return 0;
} /* nrstep_ */

/* omega4   last revised 10/27/87 by tjw */
/* *omega4 f77 check, 07/08/87 by tjw */
/* Subroutine */ int omega4_(integer *ns, doublereal *omegns, doublereal *
	zdum, integer *ierr)
{
    /* Format strings */
    static char fmt_8000[] = "(\002for ns= \002,i3,\002 izdum from omega4"
	    " \002,i3)";
    static char fmt_9000[] = "(\002 for species \002,i3,\002 omega value is"
	    " \002,e15.5)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, jj;
    static logical qck;
    static integer izdum;

    /* Fortran I/O blocks */
    static cilist io___969 = { 0, 0, 0, fmt_8000, 0 };
    static cilist io___970 = { 0, 0, 0, fmt_9000, 0 };



/*     created 10feb87 rmm */
/*     get omega for hkf equations from common eqlhkf */
/*     created 10feb87 by rmm */

/*     input   ns      index of species of interest */

/*     output  omegns  omega value for ns-th species */
/*             ierr    0/1  no error/no omega found for nsth species */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* -------------------------------------------------------------------- */
/* eqlhkf.h */
/*      ibjmax= maximum number of single interaction parameters allowed */
/*      ibjuse= actual number of entries for single parameters */
/*      icnt = number of salts created */
/*      indx1 = index to species for single interaction parameters */
/*      bj    = individual ion interaction parameter */
/*      omega = omega variable */
/*      mslt  = molality of salts */
/*      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j */

/*      ibjimx= maximum number of ion-ion interaction parameters allowed */
/*      ibjius= actual number of entries for ion-ion parameters */
/*      indx2 = indexes to both species in ion-ion interaction parameter */
/*      bij   = ion-ion interaction parameter */
/*      islt  = indices and stoich. rxn. coeff for salts */


/* ---------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* eqlun.h */
    qck = FALSE_;
    *omegns = 0.f;
    *ierr = 0;

    i__1 = eqlhkf_1.ibjuse;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jj = eqlhkf_1.indx1[i__ - 1];
	if (*ns == jj) {
	    *omegns = eqlhkf_1.omega[i__ - 1];
	    goto L200;
	}
/* L100: */
    }

/*              ns-th species not in hkf database */
/*              assign a value for omega based on charge */

    izdum = i_dnnt(zdum);
    if (qck) {
	io___969.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___969);
	do_fio(&c__1, (char *)&(*ns), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&izdum, (ftnlen)sizeof(integer));
	e_wsfe();
    }

    if (izdum >= 3) {
	*omegns = 401680.f;
    } else if (izdum == 2) {
	*omegns = 222890.f;
    } else if (izdum == 1) {
	*omegns = 68044.f;
    } else if (izdum == 0) {
	*omegns = 5e4f;
    } else if (izdum == -1) {
	*omegns = 83014.f;
    } else if (izdum <= -2) {
	*omegns = 221370.f;
    } else {
	*ierr = 1;
    }

/*     write (noutpl,1000) ns */
/* 1000 format(' ** warning no omega found for species with index = ',i3) */

L200:
/* ## debug */
    if (qck) {
	io___970.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___970);
	do_fio(&c__1, (char *)&(*ns), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*omegns), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

    return 0;
} /* omega4_ */

/* openin   last revised 07/08/87 by tjw */
/* *openin f77 check, 07/08/87 by tjw */
/* Subroutine */ int openin_(char *ufiln, char *uform, integer *ilu, ftnlen 
	ufiln_len, ftnlen uform_len)
{
    /* Format strings */
    static char fmt_100[] = "(\002 * error - file \002,a12,\002 does not exi"
	    "st (eqlib/openin)\002)";
    static char fmt_101[] = "(\002* error - file \002,a12,\002 should be for"
	    "matted \002,\002but is not (eqlib/openin)\002)";
    static char fmt_105[] = "(\002 * error - no l u available for\002,a12"
	    ",\002 (eqlib/openin)\002)";
    static char fmt_110[] = "(\002 * error - can not open \002,a12,\002 (eql"
	    "ib/openin)\002)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_open(olist *);

    /* Local variables */
    static logical qex;
    static integer nerr;
    extern /* Subroutine */ int getlu_(integer *, integer *);
    static char uformo[8];

    /* Fortran I/O blocks */
    static cilist io___973 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___974 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___975 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___976 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___978 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___979 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___980 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___981 = { 0, 0, 0, fmt_110, 0 };



/*     open an input type file.  the file must already exist. */
/*     an unused logical unit number is obtained. */

/*     input   ufiln   ascii file name to open (error message format */
/*                       assumes no more than twelve characters) */
/*             uform   file form, 'formatted' or 'unformatted' */
/*     output  ilu     logical unit number of opened file */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

/*     check to make sure the file exists. */

    ioin__1.inerr = 0;
    ioin__1.infilen = ufiln_len;
    ioin__1.infile = ufiln;
    ioin__1.inex = &qex;
    ioin__1.inopen = 0;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.informlen = 8;
    ioin__1.inform = uformo;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (! qex) {
	io___973.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___973);
	do_fio(&c__1, ufiln, ufiln_len);
	e_wsfe();
	io___974.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___974);
	do_fio(&c__1, ufiln, ufiln_len);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     check the file format */

    if (s_cmp(uform, "formatted", uform_len, (ftnlen)9) == 0 && s_cmp(uformo, 
	    "no", (ftnlen)8, (ftnlen)2) == 0) {
	io___975.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___975);
	do_fio(&c__1, ufiln, ufiln_len);
	e_wsfe();
	io___976.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___976);
	do_fio(&c__1, ufiln, ufiln_len);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    if (s_cmp(uform, "unformatted", uform_len, (ftnlen)11) == 0 && s_cmp(
	    uformo, "yes", (ftnlen)8, (ftnlen)3) == 0) {
/*       write (noutpl,102) ufiln */
/*       write (nttyol,102) ufiln */
/* 102   format('* error - file ',a12,' should be unformatted ', */
/*    $  'but is not (eqlib/openin)') */
/*     stop */
    }

/*     get logical unit number */

    getlu_(ilu, &nerr);
    if (nerr != 0) {
	io___978.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___978);
	do_fio(&c__1, ufiln, ufiln_len);
	e_wsfe();
	io___979.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___979);
	do_fio(&c__1, ufiln, ufiln_len);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    o__1.oerr = 1;
    o__1.ounit = *ilu;
    o__1.ofnmlen = ufiln_len;
    o__1.ofnm = ufiln;
    o__1.orl = 0;
    o__1.osta = "old";
    o__1.oacc = 0;
    o__1.ofm = uform;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L10;
    }
    goto L999;

L10:
    io___980.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___980);
    do_fio(&c__1, ufiln, ufiln_len);
    e_wsfe();
    io___981.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___981);
    do_fio(&c__1, ufiln, ufiln_len);
    e_wsfe();
    s_stop("", (ftnlen)0);

L999:
    return 0;
} /* openin_ */

/* openou   last revised 07/08/87 by tjw */
/* *openou f77 check, 07/08/87 by tjw */
/* Subroutine */ int openou_(char *ufiln, char *uform, integer *ilu, ftnlen 
	ufiln_len, ftnlen uform_len)
{
    /* Format strings */
    static char fmt_100[] = "(\002 * error - no l u available to open \002,a"
	    "3,\002 copy of \002,a12,\002 (eqlib/openou)\002)";
    static char fmt_105[] = "(\002 * error - can not open \002,a3,\002 copy "
	    "of \002,a12,\002 (eqlib/openou)\002)";
    static char fmt_110[] = "(\002 * error - can not delete old copy of \002"
	    ",a12,\002 (eqlib/openou)\002)";

    /* System generated locals */
    integer i__1;
    olist o__1;
    cllist cl__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_inqu(inlist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_open(olist *), f_clos(cllist *);

    /* Local variables */
    static logical qex;
    static integer nerr;
    extern /* Subroutine */ int getlu_(integer *, integer *);
    static char ustat[8];

    /* Fortran I/O blocks */
    static cilist io___985 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___986 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___987 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___988 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___989 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___990 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___991 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___992 = { 0, 0, 0, fmt_110, 0 };



/*     open an output type file.  if the file of the same name */
/*     already exists, it is first destroyed.  an unused logical */
/*     unit number is obtained. */

/*     input   ufiln   ascii file name to open (error message format */
/*                       assumes no more than twelve characters) */
/*             uform   file form, 'formatted' or 'unformatted' */
/*     output  ilu     logical unit number of opened file */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

/*     see if a file of the same name already exists.  if so, */
/*     destroy it.  this provides a logical unit number.  if a */
/*     file of the same name does not exist, get a logical unit number. */

    ioin__1.inerr = 0;
    ioin__1.infilen = ufiln_len;
    ioin__1.infile = ufiln;
    ioin__1.inex = &qex;
    ioin__1.inopen = 0;
    ioin__1.innum = 0;
    ioin__1.innamed = 0;
    ioin__1.inname = 0;
    ioin__1.inacc = 0;
    ioin__1.inseq = 0;
    ioin__1.indir = 0;
    ioin__1.infmt = 0;
    ioin__1.inform = 0;
    ioin__1.inunf = 0;
    ioin__1.inrecl = 0;
    ioin__1.innrec = 0;
    ioin__1.inblank = 0;
    f_inqu(&ioin__1);
    if (qex) {
	s_copy(ustat, "old", (ftnlen)8, (ftnlen)3);
	getlu_(ilu, &nerr);
	if (nerr != 0) {
	    io___985.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___985);
	    do_fio(&c__1, ustat, (ftnlen)8);
	    do_fio(&c__1, ufiln, ufiln_len);
	    e_wsfe();
	    io___986.ciunit = eqlun_1.nttyol;
	    s_wsfe(&io___986);
	    do_fio(&c__1, ustat, (ftnlen)8);
	    do_fio(&c__1, ufiln, ufiln_len);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	o__1.oerr = 1;
	o__1.ounit = *ilu;
	o__1.ofnmlen = ufiln_len;
	o__1.ofnm = ufiln;
	o__1.orl = 0;
	o__1.osta = ustat;
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L10;
	}
	cl__1.cerr = 1;
	cl__1.cunit = *ilu;
	cl__1.csta = "delete";
	i__1 = f_clos(&cl__1);
	if (i__1 != 0) {
	    goto L15;
	}
    } else {
	s_copy(ustat, "new", (ftnlen)8, (ftnlen)3);
	getlu_(ilu, &nerr);
	if (nerr != 0) {
	    io___987.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___987);
	    do_fio(&c__1, ustat, (ftnlen)8);
	    do_fio(&c__1, ufiln, ufiln_len);
	    e_wsfe();
	    io___988.ciunit = eqlun_1.nttyol;
	    s_wsfe(&io___988);
	    do_fio(&c__1, ustat, (ftnlen)8);
	    do_fio(&c__1, ufiln, ufiln_len);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }

/*     open the new file */

    o__1.oerr = 1;
    o__1.ounit = *ilu;
    o__1.ofnmlen = ufiln_len;
    o__1.ofnm = ufiln;
    o__1.orl = 0;
    o__1.osta = "new";
    o__1.oacc = 0;
    o__1.ofm = uform;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L10;
    }
    goto L999;

L10:
    io___989.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___989);
    do_fio(&c__1, ustat, (ftnlen)8);
    do_fio(&c__1, ufiln, ufiln_len);
    e_wsfe();
    io___990.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___990);
    do_fio(&c__1, ustat, (ftnlen)8);
    do_fio(&c__1, ufiln, ufiln_len);
    e_wsfe();
    s_stop("", (ftnlen)0);

L15:
    io___991.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___991);
    do_fio(&c__1, ufiln, ufiln_len);
    e_wsfe();
    io___992.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___992);
    do_fio(&c__1, ufiln, ufiln_len);
    e_wsfe();
    s_stop("", (ftnlen)0);

L999:
    return 0;
} /* openou_ */

/* pjdd     last revised 07/08/87 by tjw */
/* *pjdd f77 check, 07/08/87 by tjw */
/* Subroutine */ int pjdd_(doublereal *x, doublereal *pj, doublereal *pj1, 
	doublereal *pj2, integer *ier)
{
    /* Initialized data */

    static doublereal c1 = 4.581;
    static doublereal c2 = .7237;
    static doublereal c3 = .012;
    static doublereal c4 = .528;

    /* Builtin functions */
    double log(doublereal), exp(doublereal);

    /* Local variables */
    static doublereal t, bk2, bk3, xc2, alx, xc2p, c3xc4, ec3xc4;


/*     input x */
/*     compute pj = j(x) */
/*             pj1 = j'(x) */
/*             pj2 = j''(x) */
/*     using pitzer's equations   pitzer(1975) */

/*     ier = 0/-1  ok/x out of range */
/*     x must be .gt. 0. and .le. 900. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    *pj = 0.f;
    *pj1 = 0.f;
    *pj2 = 0.f;
    *ier = -1;

    if (*x <= 0.f || *x > 900.f) {
	goto L999;
    }
    *ier = 0;
    alx = log(*x);

/*      get x**(-c2) and x**(c4) and e**(-c3 x**c4) */

    xc2 = exp(-c2 * alx);
    c3xc4 = c3 * exp(c4 * alx);
    ec3xc4 = exp(-c3xc4);

    *pj = *x / (c1 * xc2 * ec3xc4 + 4.f);

/*      compute ?2? */

    t = c4 * c3xc4;
    xc2p = exp((-c2 - 1.f) * alx);
    bk2 = c1 * xc2p * (c2 + t) * ec3xc4;

    *pj1 = *pj / *x * (*pj * bk2 + 1.f);

    bk3 = t / *x * (c4 / (c2 + t) - (c2 + 1.f) / t);
    *pj2 = (*pj1 / *pj - 1.f / *x) * (*pj1 * 2.f + *pj * bk3);

L999:
    return 0;
} /* pjdd_ */

/* polx     last revised 11/16/87 by tjw */
/* *polx f77 check, 07/08/87 by tjw */
/* Subroutine */ int polx_(doublereal *x, doublereal *y, integer *n, 
	doublereal *c__, integer *ier)
{
    /* Initialized data */

    static logical qfalse = FALSE_;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal a[100]	/* was [10][10] */;
    static integer i__, j;
    static doublereal ee[10], ai, gm[100]	/* was [10][10] */, res[10], 
	    rhs[10];
    static integer ipvt[10], ipfmax;
    extern /* Subroutine */ int msolvr_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, logical *, logical *);


/*     fit an exact polynomial through n points, real*8 case */

/*     input */
/*      x     array of independent variable values */
/*      y     corresponding array of dependent variable values */
/*      n     number of values in  x,y */
/*        note - n .le. 10 */

/*     output */
/*      c     array of coefficients of a polynomial of degree n-1 */
/*            passing through the set of points  x,y */
/*      ier   0/1  ok/unable to solve matrix equation */

/*     method is to form the matrix equation  ac = b */
/*      where */
/*           a = ( 1  x(1)  x(1)**2 ... )    b = ( y(1) ) */
/*               ( 1  x(2)  x(2)**2 ... )        ( y(2) ) */
/*               ( ...                  )        ( ...  ) */
/*               ( 1  x(n)  x(n)**2 ... )        ( y(n) ) */

/*      and solve for the coefficients c(i) */
/*        y = c(1) + c(2)*x + c(3)*x**2 + ... + c(n)*x**n-1 */

/*     it is assumed that the x array contains distinct values */
/*      (no duplicates) */

/*     this code needs the machine epsilon, eps, which is calculated */
/*     by flpars.  this is usually initialized by a call to eqlib, which */
/*     calls flpars. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */


/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


    /* Parameter adjustments */
    --c__;
    --y;
    --x;

    /* Function Body */

/* ---------------------------------------------------------------------- */

/*      initialize */

    *ier = 0;
    ipfmax = 10;

/*      generate matrix of eqn values */

    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	c__[j] = 0.f;
	rhs[j - 1] = y[j];

	ai = 1.f;
	a[j - 1] = 1.f;

	i__2 = *n;
	for (i__ = 2; i__ <= i__2; ++i__) {
	    ai *= x[j];
	    a[j + i__ * 10 - 11] = ai;
/* L20: */
	}

/* L30: */
    }

/*     solve the matrix equation */

    msolvr_(a, gm, rhs, &c__[1], res, ee, ipvt, n, &ipfmax, ier, &qfalse, &
	    qfalse);

    return 0;
} /* polx_ */

/* prpheh   last revised 12/14/87 by tjw */
/* *prpheh created in f77  12/12/87 by tjw */
/* Subroutine */ int prpheh_(doublereal *ph, doublereal *phnbs, doublereal *
	phrat, doublereal *phcl, doublereal *eh, doublereal *ehnbs, 
	doublereal *ehrat, doublereal *pe, doublereal *penbs, doublereal *
	perat, integer *iopg2, integer *nchlor, integer *noutpt, logical *
	qnochb)
{
    /* Initialized data */

    static char uphscl[24*3] = "internal ph scale       " "modified nbs ph s"
	    "cale   " "rational ph scale       ";

    /* Format strings */
    static char fmt_100[] = "(//3x,\002single ion activities and activity co"
	    "efficients\002,\002 are here defined\002,/3x,\002with respect to"
	    " the \002,a24,/)";
    static char fmt_102[] = "(/39x,\002ph\002,/)";
    static char fmt_104[] = "(5x,a24,3x,f11.4)";
    static char fmt_106[] = "(//39x,\002ph\002,11x,\002eh\002,11x,\002pe\002"
	    ",/)";
    static char fmt_108[] = "(5x,a24,3x,f11.4,3x,f11.4,3x,1pe11.4)";
    static char fmt_110[] = "(/3x,\002phcl = \002,f11.4)";
    static char fmt_112[] = "(1x)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___1018 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___1019 = { 0, 0, 0, fmt_102, 0 };
    static cilist io___1020 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___1021 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___1022 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___1023 = { 0, 0, 0, fmt_106, 0 };
    static cilist io___1024 = { 0, 0, 0, fmt_108, 0 };
    static cilist io___1025 = { 0, 0, 0, fmt_108, 0 };
    static cilist io___1026 = { 0, 0, 0, fmt_108, 0 };
    static cilist io___1027 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___1028 = { 0, 0, 0, fmt_112, 0 };



/*     this routine prints the ph, redox potential, and pe */
/*     (electron activity function) on the operational ph scale used */
/*     in the calculations (see iopg2), the modified nbs ph scale, */
/*     and the rational ph scale. */

/*     input */
/*       ph = ph on scale used in computation */
/*       phnbs = ph on the modified nbs scale */
/*       phrat = ph on the rational scale */
/*       phcl = ph + pcl */
/*       eh = eh corresponding to the ph used in the computation */
/*       ehnbs = eh corresponding to the phnbs */
/*       ehrat = eh corresponding to the phrat */
/*       pe = pe function corresonding to eh */
/*       penbs = pe function corresonding to ehnbs */
/*       perat = pe function corresonding to ehrat */
/*       iopg2 = activity coefficient option switch, defines the */
/*               operational ph scale used in the computation */
/*               = -1   internal scale defined for the activity */
/*                      coefficinet model defined by iopg1 */
/*                = 0   the modified nbs ph scale (log gamma cl- */
/*                      defined by bates-guggenheim expression) */
/*                = 2   the rational ph scale (log gamma h+ defined */
/*                      as zero) */
/*       nchlor = index of the chloride ion */
/*       noutpt = unit number of the output file */
/*       qnochb = logical flag, = .true. if no oxidation-reduction */
/*                in the modeled system */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* ---------------------------------------------------------------------- */

    i__ = *iopg2 + 2;
    io___1018.ciunit = *noutpt;
    s_wsfe(&io___1018);
    do_fio(&c__1, uphscl + (i__ - 1) * 24, (ftnlen)24);
    e_wsfe();

    if (*qnochb) {
	io___1019.ciunit = *noutpt;
	s_wsfe(&io___1019);
	e_wsfe();
	if (*iopg2 == -1) {
	    io___1020.ciunit = *noutpt;
	    s_wsfe(&io___1020);
	    do_fio(&c__1, uphscl, (ftnlen)24);
	    do_fio(&c__1, (char *)&(*ph), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	io___1021.ciunit = *noutpt;
	s_wsfe(&io___1021);
	do_fio(&c__1, uphscl + 24, (ftnlen)24);
	do_fio(&c__1, (char *)&(*phnbs), (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___1022.ciunit = *noutpt;
	s_wsfe(&io___1022);
	do_fio(&c__1, uphscl + 48, (ftnlen)24);
	do_fio(&c__1, (char *)&(*phrat), (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	io___1023.ciunit = *noutpt;
	s_wsfe(&io___1023);
	e_wsfe();

	if (*iopg2 == -1) {
	    io___1024.ciunit = *noutpt;
	    s_wsfe(&io___1024);
	    do_fio(&c__1, uphscl, (ftnlen)24);
	    do_fio(&c__1, (char *)&(*ph), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*eh), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*pe), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

	io___1025.ciunit = *noutpt;
	s_wsfe(&io___1025);
	do_fio(&c__1, uphscl + 24, (ftnlen)24);
	do_fio(&c__1, (char *)&(*phnbs), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*ehnbs), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*penbs), (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___1026.ciunit = *noutpt;
	s_wsfe(&io___1026);
	do_fio(&c__1, uphscl + 48, (ftnlen)24);
	do_fio(&c__1, (char *)&(*phrat), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*ehrat), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*perat), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

    if (*nchlor > 0) {
	io___1027.ciunit = *noutpt;
	s_wsfe(&io___1027);
	do_fio(&c__1, (char *)&(*phcl), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

    io___1028.ciunit = *noutpt;
    s_wsfe(&io___1028);
    e_wsfe();

    return 0;
} /* prpheh_ */

/* prreac  last revised 12/11/87 by tjw */
/* *preac f77 rewrite 11/23/87 by tjw */
/* Subroutine */ int prreac_(doublereal *cdrx, char *uspec, char *unamsp, 
	integer *n, integer *nsq, integer *nsq1, integer *nsqmx1, integer *nf,
	 ftnlen uspec_len, ftnlen unamsp_len)
{
    /* Format strings */
    static char fmt_100[] = "(1x)";
    static char fmt_105[] = "(21x,f7.3,2x,a24)";
    static char fmt_110[] = "(20x,\002+\002,f7.3,2x,a24)";
    static char fmt_115[] = "(27x,\002==\002)";

    /* System generated locals */
    integer cdrx_dim1, cdrx_offset, i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer nj, ns;
    static doublereal coeff;

    /* Fortran I/O blocks */
    static cilist io___1029 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___1031 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___1033 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___1034 = { 0, 0, 0, fmt_115, 0 };
    static cilist io___1036 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___1037 = { 0, 0, 0, fmt_110, 0 };



/*     this routine writes the n-th reaction in a set. */

/*     input */
/*       cdrx = the array of reaction coefficients for a given set */
/*              cdrx = cdrs for aqueous species dissociation reactions */
/*              cdrx = cdrm for mineral dissolution reactions */
/*              cdrx = cdrg for gas dissolution reactions */
/*       uspec = array of aqueous species names */
/*       unamsp = name of species associated with the reaction */
/*       n = the index of the reaction */
/*       nsqmx1 = maximum number of aqueous master species plus one; */
/*                the leading dimension of cdrx */
/*       nsq = number of aqueous master species */
/*       nsq1 = number of aqueous master species plus one */
/*       nf = the unit number of the file to write on */

/*     output */
/*       none */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* -------------------------------------------------------------------- */

    /* Parameter adjustments */
    uspec -= uspec_len;
    cdrx_dim1 = *nsqmx1;
    cdrx_offset = 1 + cdrx_dim1;
    cdrx -= cdrx_offset;

    /* Function Body */
    io___1029.ciunit = *nf;
    s_wsfe(&io___1029);
    e_wsfe();

/*     print coefficient and name of the associated species */

    coeff = -cdrx[*nsq1 + *n * cdrx_dim1];
    io___1031.ciunit = *nf;
    s_wsfe(&io___1031);
    do_fio(&c__1, (char *)&coeff, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, unamsp, unamsp_len);
    e_wsfe();

/*     print the coefficients and names of other reactants */

    i__1 = *nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	coeff = -cdrx[ns + *n * cdrx_dim1];
	if (coeff > 0.f) {
	    io___1033.ciunit = *nf;
	    s_wsfe(&io___1033);
	    do_fio(&c__1, (char *)&coeff, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
	    e_wsfe();
	}
/* L5: */
    }

    io___1034.ciunit = *nf;
    s_wsfe(&io___1034);
    e_wsfe();

/*     print the coefficients and names of the products */

    nj = 0;
    i__1 = *nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	coeff = cdrx[ns + *n * cdrx_dim1];
	if (coeff > 0.f) {
	    if (nj <= 0) {
		io___1036.ciunit = *nf;
		s_wsfe(&io___1036);
		do_fio(&c__1, (char *)&coeff, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
		e_wsfe();
		nj = 1;
	    } else {
		io___1037.ciunit = *nf;
		s_wsfe(&io___1037);
		do_fio(&c__1, (char *)&coeff, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
		e_wsfe();
	    }
	}
/* L10: */
    }

/* L999: */
    return 0;
} /* prreac_ */

/* ptztab   last revised 11/19/87 by tjw */
/* *ptztab f77 check, 07/08/87 by tjw */
/* Subroutine */ int ptztab_(integer *npair, integer *ipairs, integer *ntripl,
	 integer *itripl, integer *nspec, char *uspec, integer *jsflag, 
	integer *iprint, ftnlen uspec_len)
{
    /* Initialized data */

    static char ublank[24] = "                        ";
    static char uh2[8] = "H2(AQ)  ";
    static char uo2[8] = "O2(AQ)  ";

    /* Format strings */
    static char fmt_500[] = "(\002 * info - initial choice for iopr9 was inv"
	    "alid \002,/\002   therefore, iopr9 was reset to 0 (eqlib/ptztab"
	    ")\002)";
    static char fmt_1000[] = "(/,\002 species       lamda pairs             "
	    "         mu triplets\002,/)";
    static char fmt_2000[] = "(\002**warning** \002,a12,\002 is in model but"
	    " not represented\002,\002 in pitzer coeffiecients\002)";
    static char fmt_2500[] = "(1x,a12)";
    static char fmt_3000[] = "(15x,2a8,15x,3a8)";
    static char fmt_3002[] = "(15x,2a8)";
    static char fmt_3004[] = "(15x,2a8,15x,3a8)";
    static char fmt_3500[] = "(\002-----------------------------------------"
	    "----------\002,\002-----------------\002)";
    static char fmt_4000[] = "(x,a12,4x,i3,32x,i3)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), do_fio(integer *, char *, 
	    ftnlen);

    /* Local variables */
    static integer i__, j, k, idum1, idum2;
    static char upair[24*2*500];
    static logical qdoit;
    static integer mucnt, imodel, isrcha, isrchb, lamcnt, imncnt;
    static char utripl[24*3*500];

    /* Fortran I/O blocks */
    static cilist io___1043 = { 0, 0, 0, fmt_500, 0 };
    static cilist io___1044 = { 0, 0, 0, fmt_500, 0 };
    static cilist io___1045 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___1057 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___1058 = { 0, 0, 0, fmt_2000, 0 };
    static cilist io___1060 = { 0, 0, 0, fmt_2500, 0 };
    static cilist io___1061 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___1062 = { 0, 0, 0, fmt_3002, 0 };
    static cilist io___1063 = { 0, 0, 0, fmt_3004, 0 };
    static cilist io___1064 = { 0, 0, 0, fmt_3500, 0 };
    static cilist io___1065 = { 0, 0, 0, fmt_4000, 0 };



/*  purpose:  tabulates pitzer coefficients for each species in */
/*           aqueous solution */

/*  input arguments: */
/*      npair:    number of lamda pairs in database */
/*      ipairs:   array with indexes of lamda pairs in database */
/*      ntripl:   number of mu triplets in database */
/*      itripl:  array with indexes of mu triples in database */
/*      nspec:    total number of aqueous species in database */
/*      uspec:   names of all aqueous species in database */
/*      iprint:   print variable for type of tabulation */
/*                0 = only warnings */
/*                1 = print warnings and number of pairs/triples */
/*                2 = print warnings and names of pairs/triples */
/*      jsflag:     0/1 = aqueous species in model/not in model */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* ----------------------------------------------------------------------- */
/* impliciti.h */
/*   standard implicit statement for eq3/6 routines not requiring */
/*   floating point variables */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */


/* -------------------------------------------------------------------- */
/* eqlun.h */



    /* Parameter adjustments */
    --jsflag;
    uspec -= 24;
    itripl -= 4;
    ipairs -= 3;

    /* Function Body */

/* ---------------------------------------------------------------- */

    lamcnt = 0;
    mucnt = 0;

/*  set largest dimension */

/*   check validity of iprint */

    if (*iprint > 2 || *iprint < 0) {
	io___1043.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___1043);
	e_wsfe();
	io___1044.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___1044);
	e_wsfe();
    }

/*  write out headings for tables */

    if (*iprint != 0) {
	io___1045.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___1045);
	e_wsfe();
    }

/*  begin loop -- go through each aqueous species in model */
/*  start with number 2 -- water is no. 1 */
/*  blank out arrays */

    i__1 = *nspec;
    for (imodel = 2; imodel <= i__1; ++imodel) {
	i__2 = *npair;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    s_copy(upair + ((i__ << 1) - 2) * 24, ublank, (ftnlen)24, (ftnlen)
		    24);
	    s_copy(upair + ((i__ << 1) - 1) * 24, ublank, (ftnlen)24, (ftnlen)
		    24);
/* L10: */
	}

	i__2 = *ntripl;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    s_copy(utripl + (i__ * 3 - 3) * 24, ublank, (ftnlen)24, (ftnlen)
		    24);
	    s_copy(utripl + (i__ * 3 - 2) * 24, ublank, (ftnlen)24, (ftnlen)
		    24);
	    s_copy(utripl + (i__ * 3 - 1) * 24, ublank, (ftnlen)24, (ftnlen)
		    24);
/* L12: */
	}

	lamcnt = 0;
	mucnt = 0;
	if (jsflag[imodel] != 0) {
	    goto L200;
	}

/*  check if imodel matches any component in lamda pair */

	i__2 = *npair;
	for (j = 1; j <= i__2; ++j) {
	    qdoit = FALSE_;
	    if (imodel == ipairs[(j << 1) + 1]) {
		qdoit = TRUE_;
		isrcha = 2;
	    } else if (imodel == ipairs[(j << 1) + 2]) {
		qdoit = TRUE_;
		isrcha = 1;
	    }

/*  test if other component matches any of the aqueous species in model */

	    if (qdoit) {
		i__3 = *nspec;
		for (idum1 = 1; idum1 <= i__3; ++idum1) {
		    if (jsflag[idum1] != 0) {
			goto L20;
		    }
		    if (ipairs[isrcha + (j << 1)] == idum1) {
			++lamcnt;
			s_copy(upair + ((lamcnt << 1) - 2) * 24, uspec + 
				ipairs[(j << 1) + 1] * 24, (ftnlen)24, (
				ftnlen)24);
			s_copy(upair + ((lamcnt << 1) - 1) * 24, uspec + 
				ipairs[(j << 1) + 2] * 24, (ftnlen)24, (
				ftnlen)24);
		    }
L20:
		    ;
		}
	    }
/* L25: */
	}

/*  if no match with any lamda pair then skip check of triplets */

	if (lamcnt == 0) {
	    goto L100;
	}

/*  check for mu triplets */

	i__2 = *ntripl;
	for (k = 1; k <= i__2; ++k) {
	    qdoit = FALSE_;
	    if (imodel == itripl[k * 3 + 1]) {
		qdoit = TRUE_;
		isrcha = 2;
		isrchb = 3;
	    } else if (imodel == itripl[k * 3 + 2]) {
		qdoit = TRUE_;
		isrcha = 1;
		isrchb = 3;
	    } else if (imodel == itripl[k * 3 + 3]) {
		qdoit = TRUE_;
		isrcha = 1;
		isrchb = 2;
	    }

/*  check if one other component matches */

	    if (qdoit) {
		i__3 = *nspec;
		for (idum1 = 1; idum1 <= i__3; ++idum1) {
		    if (jsflag[idum1] != 0) {
			goto L50;
		    }
		    if (itripl[isrcha + k * 3] == idum1) {
/*  check if last component is in model */
			i__4 = *nspec;
			for (idum2 = 1; idum2 <= i__4; ++idum2) {
			    if (jsflag[idum2] != 0) {
				goto L40;
			    }
			    if (itripl[isrchb + k * 3] == idum2) {
				++mucnt;
				s_copy(utripl + (mucnt * 3 - 3) * 24, uspec + 
					itripl[k * 3 + 1] * 24, (ftnlen)24, (
					ftnlen)24);
				s_copy(utripl + (mucnt * 3 - 2) * 24, uspec + 
					itripl[k * 3 + 2] * 24, (ftnlen)24, (
					ftnlen)24);
				s_copy(utripl + (mucnt * 3 - 1) * 24, uspec + 
					itripl[k * 3 + 3] * 24, (ftnlen)24, (
					ftnlen)24);
				goto L60;
			    }
L40:
			    ;
			}
		    }
L50:
		    ;
		}
	    }
L60:
	    ;
	}

/*  done with all checks */

L100:

/*  write out tables */

	if (lamcnt == 0 && mucnt == 0) {

/*       write out warnings */

	    if (s_cmp(uspec + imodel * 24, uh2, (ftnlen)8, (ftnlen)8) != 0 && 
		    s_cmp(uspec + imodel * 24, uo2, (ftnlen)8, (ftnlen)8) != 
		    0) {
		io___1057.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___1057);
		do_fio(&c__1, uspec + imodel * 24, (ftnlen)24);
		e_wsfe();
		io___1058.ciunit = eqlun_1.nttyol;
		s_wsfe(&io___1058);
		do_fio(&c__1, uspec + imodel * 24, (ftnlen)24);
		e_wsfe();
	    }
	} else if (*iprint == 2) {

/*       write maximum output - iprint = 2 - names of coefficients */

	    if (lamcnt > mucnt) {
		imncnt = lamcnt;
	    } else {
		imncnt = mucnt;
	    }
	    io___1060.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___1060);
	    do_fio(&c__1, uspec + imodel * 24, (ftnlen)24);
	    e_wsfe();
	    io___1061.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___1061);
	    i__2 = imncnt;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, upair + ((i__ << 1) - 2) * 24, (ftnlen)24);
		do_fio(&c__1, upair + ((i__ << 1) - 1) * 24, (ftnlen)24);
		do_fio(&c__1, utripl + (i__ * 3 - 3) * 24, (ftnlen)24);
		do_fio(&c__1, utripl + (i__ * 3 - 2) * 24, (ftnlen)24);
		do_fio(&c__1, utripl + (i__ * 3 - 1) * 24, (ftnlen)24);
	    }
	    e_wsfe();
	    if (lamcnt > imncnt) {
		io___1062.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___1062);
		i__2 = lamcnt;
		for (i__ = imncnt; i__ <= i__2; ++i__) {
		    do_fio(&c__1, upair + ((i__ << 1) - 2) * 24, (ftnlen)24);
		    do_fio(&c__1, upair + ((i__ << 1) - 1) * 24, (ftnlen)24);
		}
		e_wsfe();
	    }
	    if (mucnt > imncnt) {
		io___1063.ciunit = eqlun_1.noutpl;
		s_wsfe(&io___1063);
		i__2 = mucnt;
		for (i__ = imncnt; i__ <= i__2; ++i__) {
		    do_fio(&c__1, utripl + (i__ * 3 - 3) * 24, (ftnlen)24);
		    do_fio(&c__1, utripl + (i__ * 3 - 2) * 24, (ftnlen)24);
		    do_fio(&c__1, utripl + (i__ * 3 - 1) * 24, (ftnlen)24);
		}
		e_wsfe();
	    }
	    io___1064.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___1064);
	    e_wsfe();
	} else if (*iprint == 1) {

/*       write minimum requested output - iprint 2 - number of */
/*       coefficients */

	    io___1065.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___1065);
	    do_fio(&c__1, uspec + imodel * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&lamcnt, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&mucnt, (ftnlen)sizeof(integer));
	    e_wsfe();
	}

/*  end loop for one aqueous species in the model */

L200:
	;
    }

    return 0;
} /* ptztab_ */

/* qsort    last revised 07/08/87 by tjw */
/* *qsort f77 check, 07/08/87 by tjw */
/* Subroutine */ int qsort_(doublereal *a, doublereal *b, integer *n, integer 
	*j, integer *istack, integer *jstack)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ipt, jpt, iend, jend;
    static doublereal bdum;
    static integer jdum, kdum, nstack;


/*     this routine copies the n elements of array a into array b */
/*     and sorts the elements of b in order of increasing value. */

/*     the sorting algorithm is the quicksort method of */
/*     c.a.r. hoare. */

/*     note that the arrays b, j, istack, and jstack should have the */
/*     same dimension as array a.  array j contains the original */
/*     indices of the elements of array a.  arrays istack and */
/*     jstack are stacks containing the left and right indices */
/*     of lists to be sorted. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

    /* Parameter adjustments */
    --jstack;
    --istack;
    --j;
    --b;
    --a;

    /* Function Body */
    nstack = 1;
    istack[1] = 1;
    jstack[1] = *n;
    i__1 = *n;
    for (jpt = 1; jpt <= i__1; ++jpt) {
	j[jpt] = jpt;
	b[jpt] = a[jpt];
/* L10: */
    }

/*     if the stack of lists is empty the sort is finished. */

L30:
    if (nstack <= 0) {
	goto L999;
    }

/*     remove the last list from the stack. */

    iend = istack[nstack];
    jend = jstack[nstack];
    --nstack;
    ipt = iend;
    jpt = jend;

L40:
    if (ipt >= jpt) {
	goto L70;
    }

/*     move the left pointer as far as possible. */

L50:
    if (b[ipt] > b[jpt]) {
	goto L55;
    }
    ++ipt;
    if (ipt >= jpt) {
	goto L70;
    }
    goto L50;

/*     have found an out of order element.  exchange elements. */

L55:
    bdum = b[ipt];
    b[ipt] = b[jpt];
    b[jpt] = bdum;
    jdum = j[ipt];
    j[ipt] = j[jpt];
    j[jpt] = jdum;

/*     move the right pointer as far as possible. */

L60:
    if (b[ipt] > b[jpt]) {
	goto L65;
    }
    --jpt;
    if (ipt >= jpt) {
	goto L70;
    }
    goto L60;

/*     have found an out of order element.  exchange elements. */

L65:
    bdum = b[ipt];
    b[ipt] = b[jpt];
    b[jpt] = bdum;
    jdum = j[ipt];
    j[ipt] = j[jpt];
    j[jpt] = jdum;
    goto L40;

/*     jpt is the dividing point.  split the list in two, and */
/*     sort each independently.  avoid sorting empty lists. */

L70:
    kdum = jpt - 1;
    if (kdum > iend) {
	++nstack;
	istack[nstack] = iend;
	jstack[nstack] = kdum;
    }
    kdum = jpt + 1;
    if (kdum >= jend) {
	goto L30;
    }
    ++nstack;
    istack[nstack] = kdum;
    jstack[nstack] = jend;
    goto L30;

L999:
    return 0;
} /* qsort_ */

/* readr    last revised 07/08/87 by tjw */
/* *readr f77 check, 07/08/87 by tjw */
/* Subroutine */ int readr_(integer *nmdar, char *ubuf, integer *nlines, char 
	*uterm, integer *navb, integer *irfp, ftnlen ubuf_len, ftnlen 
	uterm_len)
{
    /* Format strings */
    static char fmt_1020[] = "(a80)";
    static char fmt_1010[] = "(\002 * error - reading block \002,i8,\002 of "
	    "direct access file\002,/5x,\002iostat=\002,i5,\002 (eqlib/readr"
	    ")\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rdfe(cilist *), do_fio(integer *, char *, ftnlen), e_rdfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer k, ios;

    /* Fortran I/O blocks */
    static cilist io___1076 = { 1, 0, 1, fmt_1020, 0 };
    static cilist io___1077 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___1078 = { 0, 0, 0, fmt_1010, 0 };



/*     input   nmdar   unit number of direct access data file */
/*             nlines  upper bound, number of lines (records) to read */
/*             uterm   a8 ascii terminator (in first 8 char of line) */
/*             navb    d a file index to next available record */
/*                      note - this is at eof */
/*             irfp    record number (zero is first record) */
/*                      irfp is incremented 1 for each line read */
/*     output  ubuf   output buffer, 80 character lines */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */


/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    ubuf -= 80;

    /* Function Body */
    i__1 = *nlines;
    for (k = 1; k <= i__1; ++k) {
	io___1076.ciunit = *nmdar;
	io___1076.cirec = *irfp;
	ios = s_rdfe(&io___1076);
	if (ios != 0) {
	    goto L100001;
	}
	ios = do_fio(&c__1, ubuf + k * 80, (ftnlen)80);
	if (ios != 0) {
	    goto L100001;
	}
	ios = e_rdfe();
L100001:
	if (ios > 0) {
	    goto L20;
	}
	++(*irfp);
	if (s_cmp(ubuf + k * 80, uterm, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L15;
	}
	if (*irfp >= *navb) {
	    goto L15;
	}
/* L10: */
    }

L15:
    goto L999;

L20:
    io___1077.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___1077);
    do_fio(&c__1, (char *)&(*irfp), (ftnlen)sizeof(integer));
    e_wsfe();
    io___1078.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___1078);
    do_fio(&c__1, (char *)&(*irfp), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

L999:
    return 0;
} /* readr_ */

/* rscal    last revised 07/08/87 by tjw */
/* *rscal f77 check, 07/08/87 by tjw */
/* Subroutine */ int rscal_(doublereal *c__, integer *n, doublereal *xmax, 
	doublereal *crs)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k;
    static doublereal px;


/*     rescale a set of values, real*8 case */

/*     input */
/*      array c  of n real*8 values */
/*      xmax  real*8 rescale factor */

/*      output */
/*       array crs  of n real*8 values */
/*       crs(1) = c(1) */
/*       crs(2) = c(2) / xmax */
/*       crs(3) = c(3) / xmax**2 */
/*       crs(4) = c(4) / xmax**3 */
/*        ... */
/*       crs(n) = c(n) / xmax**n-1 */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --crs;
    --c__;

    /* Function Body */
    px = 1.f;
    crs[1] = c__[1];

    i__1 = *n;
    for (k = 2; k <= i__1; ++k) {
	px /= *xmax;
	crs[k] = c__[k] * px;
/* L20: */
    }

    return 0;
} /* rscal_ */

/* sasum    last revised 07/08/87 by tjw */
/* *sasum f77 rewrite, 07/08/87 by tjw */
doublereal sasum_(integer *n, doublereal *sx)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val, d__1, d__2, d__3, d__4, d__5, d__6;

    /* Local variables */
    static integer i__, nm, nmp1;


/* ***after lawson c. (jpl),hanson r. (sla), */
/*                            kincaid d. (u texas), krogh f. (jpl) */
/* ***purpose */
/*    sum of magnitudes of real*8 vector components */
/* ***description */
/*    description of parameters */

/*     --input-- */
/*        n  number of elements in input vector(s) */
/*       sx  real*8 vector with n elements */

/*     --output-- */
/*    sasum  real*8 result (zero if n.le.0) */

/*     returns sum of magnitudes of real*8 sx. */
/*     sasum = sum from 1 to n of  abs(sx(i)) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --sx;

    /* Function Body */
    ret_val = 0.f;
    if (*n <= 0) {
	goto L999;
    }

/*        clean-up loop so remaining vector length is a multiple of 6. */

    nm = *n % 6;
    if (nm > 0) {
	i__1 = nm;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ret_val += (d__1 = sx[i__], abs(d__1));
/* L30: */
	}
	if (*n < 6) {
	    goto L999;
	}
    }

    nmp1 = nm + 1;
    i__1 = *n;
    for (i__ = nmp1; i__ <= i__1; i__ += 6) {
	ret_val = ret_val + (d__1 = sx[i__], abs(d__1)) + (d__2 = sx[i__ + 1],
		 abs(d__2)) + (d__3 = sx[i__ + 2], abs(d__3)) + (d__4 = sx[
		i__ + 3], abs(d__4)) + (d__5 = sx[i__ + 4], abs(d__5)) + (
		d__6 = sx[i__ + 5], abs(d__6));
/* L50: */
    }

L999:
    return ret_val;
} /* sasum_ */

/* saxpy    last revised 07/08/87 by tjw */
/* *saxpy f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int saxpy_(integer *n, doublereal *sa, doublereal *sx, 
	doublereal *sy)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, nm, nmp1;


/* ***after lawson c. (jpl),hanson r. (sla), */
/*                            kincaid d. (u texas), krogh f. (jpl) */
/* ***purpose */
/*  computation y = a*x + y, real*8 case */
/* ***description */
/*    description of parameters */

/*     --input-- */
/*        n  number of elements in input vector(s) */
/*       sa  real*8 scalar multiplier */
/*       sx  real*8 vector with n elements */
/*       sy  real*8 vector with n elements */

/*     --output-- */
/*       sy  real*8 result (unchanged if n.le.0) */

/*     overwrite real*8 sy with real*8 sa*sx +sy. */
/*      for i=1 to n, replace sy(i) with s(y) + sa*sx(i) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --sy;
    --sx;

    /* Function Body */
    if (*n <= 0 || *sa == 0.f) {
	goto L999;
    }

/*        clean-up loop so remaining vector length is a multiple of 4. */

    nm = *n % 4;
    if (nm > 0) {
	i__1 = nm;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    sy[i__] += *sa * sx[i__];
/* L30: */
	}
	if (*n < 4) {
	    goto L999;
	}
    }

    nmp1 = nm + 1;
    i__1 = *n;
    for (i__ = nmp1; i__ <= i__1; i__ += 4) {
	sy[i__] += *sa * sx[i__];
	sy[i__ + 1] += *sa * sx[i__ + 1];
	sy[i__ + 2] += *sa * sx[i__ + 2];
	sy[i__ + 3] += *sa * sx[i__ + 3];
/* L50: */
    }

L999:
    return 0;
} /* saxpy_ */

/* scal     last revised 07/08/87 by tjw */
/* *scal f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int scal_(doublereal *x, integer *n, doublereal *xs, 
	doublereal *xmax, integer *ier)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer k;
    static doublereal xa;


/*     scale a set of real*8 values to (-1,1) */

/*     input */
/*      array x of n real*8 values */

/*     output */
/*      array xs of n real*8 values, */
/*      xmax  the magnitude of largest x */

/*      where xs(i) = x(i) / xmax   1=1,...,n */

/*     notes   ier = 0/1  ok / all x's = 0 */
/*             if xmax .lt. 1., set xmax = 1. and */
/*             xs(i) = x(i)  i=1,...,n */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --xs;
    --x;

    /* Function Body */
    *ier = 0;

/*     find xmax */

    *xmax = abs(x[1]);
    if (*n > 1) {
	goto L10;
    }

/*     only one value in x */

    if (*xmax <= 0.f) {
	*ier = 1;
	goto L999;
    }

    if (*xmax <= 1.f) {
	*xmax = 1.f;
	xs[1] = x[1];
	goto L999;
    }

    xs[1] = x[1] / *xmax;
    goto L999;

L10:

    i__1 = *n;
    for (k = 2; k <= i__1; ++k) {
	xa = (d__1 = x[k], abs(d__1));
	if (*xmax < xa) {
	    *xmax = xa;
	}
/* L20: */
    }

    if (*xmax <= 0.f) {
	*ier = 1;
	goto L999;
    }

    if (*xmax <= 1.f) {

/*       xmax .le. 1. here */

	*xmax = 1.f;
	i__1 = *n;
	for (k = 1; k <= i__1; ++k) {
	    xs[k] = x[k];
/* L30: */
	}
	goto L999;
    }

/*     normal case */

    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	xs[k] = x[k] / *xmax;
/* L40: */
    }

L999:
    return 0;
} /* scal_ */

/* sdot     last revised 07/08/87 by tjw */
/* *sdot f77 rewrite, 07/08/87 by tjw */
doublereal sdot_(integer *n, doublereal *sx, doublereal *sy)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, nm, nmp1;


/* ***after lawson c. (jpl),hanson r. (sla), */
/*                            kincaid d. (u texas), krogh f. (jpl) */
/* ***purpose */
/*   inner product of vectors, real*8 case */
/* ***description */
/*    description of parameters */

/*     --input-- */
/*        n  number of elements in input vector(s) */
/*       sx  real*8 vector with n elements */
/*       sy  real*8 vector with n elements */

/*     --output-- */
/*     sdot  real*8 dot product (zero if n.le.0) */

/*     returns the dot product of real*8 sx and sy. */
/*     sdot = sum for i = 1 to n of sx(i) * sy(i) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --sy;
    --sx;

    /* Function Body */
    ret_val = 0.f;
    if (*n <= 0) {
	goto L999;
    }

/*        clean-up loop so remaining vector length is a multiple of 5. */

    nm = *n % 5;
    if (nm > 0) {
	i__1 = nm;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ret_val += sx[i__] * sy[i__];
/* L30: */
	}
	if (*n < 5) {
	    goto L999;
	}
    }

    nmp1 = nm + 1;
    i__1 = *n;
    for (i__ = nmp1; i__ <= i__1; i__ += 5) {
	ret_val = ret_val + sx[i__] * sy[i__] + sx[i__ + 1] * sy[i__ + 1] + 
		sx[i__ + 2] * sy[i__ + 2] + sx[i__ + 3] * sy[i__ + 3] + sx[
		i__ + 4] * sy[i__ + 4];
/* L50: */
    }

L999:
    return ret_val;
} /* sdot_ */

/* sgeco    last revised 07/08/87 by tjw */
/* *sgeco f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int sgeco_(doublereal *a, integer *ilda, integer *n, integer 
	*ipvt, doublereal *rcond, doublereal *z__)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer j, k;
    static doublereal s, t;
    static integer kb;
    static doublereal ek;
    static integer il;
    static doublereal sm, wk;
    static integer kp1;
    static doublereal wkm;
    static integer info;
    extern doublereal sdot_(integer *, doublereal *, doublereal *);
    extern /* Subroutine */ int sgefa_(doublereal *, integer *, integer *, 
	    integer *, integer *), sscal_(integer *, doublereal *, doublereal 
	    *);
    static doublereal anorm;
    extern doublereal sasum_(integer *, doublereal *);
    static doublereal ynorm;
    extern /* Subroutine */ int saxpy_(integer *, doublereal *, doublereal *, 
	    doublereal *);


/* ***after moler c.b. */
/* ***purpose */
/*  factors a real*8 matrix by gaussian elimination and estimates */
/*  the condition number of the matrix. */
/* ***description */
/*     sgeco factors a real matrix by gaussian elimination */
/*     and estimates the condition of the matrix. */

/*     if  rcond  is not needed, sgefa is slightly faster. */
/*     to solve  a*x = b , follow sgeco by sgesl. */
/*     to compute  inverse(a)*c , follow sgeco by sgesl. */

/*     on entry */

/*        a       real*8(ilda, n) */
/*                the matrix to be factored. */

/*        ilda     integer */
/*                the leading dimension of the array  a . */

/*        n       integer */
/*                the order of the matrix  a . */

/*     on return */

/*        a       an upper triangular matrix and the multipliers */
/*                which were used to obtain it. */
/*                the factorization can be written  a = l*u  where */
/*                l  is a product of permutation and unit lower */
/*                triangular matrices and  u  is upper triangular. */

/*        ipvt    integer(n) */
/*                an integer vector of pivot indices. */

/*        rcond   real*8 */
/*                an estimate of the reciprocal condition of  a . */
/*                for the system  a*x = b , relative perturbations */
/*                in  a  and  b  of size  epsilon  may cause */
/*                relative perturbations in  x  of size  epsilon/rcond . */
/*                if  rcond  is so small that the logical expression */
/*                           1.0 + rcond .eq. 1.0 */
/*                is true, then  a  may be singular to working */
/*                precision.  in particular,  rcond  is zero  if */
/*                exact singularity is detected or the estimate */
/*                underflows. */

/*                notes from 11jul86 changes: */
/*                  there are two tests for definite singularity to */
/*                  within machine precision.  if anorm is zero, this */
/*                  condition is true and there is not much reason to */
/*                  call sgefa.  rcond should be set to zero.  if info */
/*                  is returned from sgefa with a non-zero value, this */
/*                  also indicates that the same condition is true, */
/*                  and the same action should be taken. */

/*        z       real*8(n) */
/*                a work vector whose contents are usually unimportant. */
/*                if  a  is close to a singular matrix, then  z  is */
/*                an approximate null vector in the sense that */
/*                norm(a*z) = rcond*norm(a)*norm(z). */

/*     note- eqlib or flpars must be called before this routine */
/*     in order to provide a value for smpos (28jul86) */

/* ***references */
/*  dongarra j.j., bunch j.r., moler c.b., stewart g.w., */
/*   *linpack users  guide*, siam, 1979. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/* ---------------------------------------------------------------------- */

/*     set rcond to zero */

    /* Parameter adjustments */
    a_dim1 = *ilda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ipvt;
    --z__;

    /* Function Body */
    *rcond = 0.f;

/*     compute 1-norm of a */

    anorm = 0.f;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
/* Computing MAX */
	d__1 = anorm, d__2 = sasum_(n, &a[j * a_dim1 + 1]);
	anorm = max(d__1,d__2);
/* L10: */
    }

/*     test anorm */

    if (anorm <= eqleps_1.smpos) {
	goto L999;
    }

/*     factor the matrix */

    sgefa_(&a[a_offset], ilda, n, &ipvt[1], &info);

/*     test info */

    if (info != 0) {
	goto L999;
    }

/*     rcond = 1/(norm(a)*(estimate of norm(inverse(a)))) . */
/*     estimate = norm(z)/norm(y) where  a*z = y  and  trans(a)*y = e . */
/*     trans(a)  is the transpose of a .  the components of  e  are */
/*     chosen to cause maximum local growth in the elements of w  where */
/*     trans(u)*w = e .  the vectors are frequently rescaled to avoid */
/*     overflow. */

/*     solve trans(u)*w = e */

    ek = 1.f;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	z__[j] = 0.f;
/* L20: */
    }

    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	if (z__[k] != 0.f) {
	    d__1 = -z__[k];
	    ek = d_sign(&ek, &d__1);
	}
	if ((d__1 = ek - z__[k], abs(d__1)) > (d__2 = a[k + k * a_dim1], abs(
		d__2))) {
	    s = (d__1 = a[k + k * a_dim1], abs(d__1)) / (d__2 = ek - z__[k], 
		    abs(d__2));
	    sscal_(n, &s, &z__[1]);
	    ek = s * ek;
	}

	wk = ek - z__[k];
	wkm = -ek - z__[k];
	s = abs(wk);
	sm = abs(wkm);
	if (a[k + k * a_dim1] != 0.f) {
	    wk /= a[k + k * a_dim1];
	    wkm /= a[k + k * a_dim1];
	} else {
	    wk = 1.f;
	    wkm = 1.f;
	}

	kp1 = k + 1;
	if (kp1 <= *n) {
	    i__2 = *n;
	    for (j = kp1; j <= i__2; ++j) {
		sm += (d__1 = z__[j] + wkm * a[k + j * a_dim1], abs(d__1));
		z__[j] += wk * a[k + j * a_dim1];
		s += (d__1 = z__[j], abs(d__1));
/* L60: */
	    }
	    if (s < sm) {
		t = wkm - wk;
		wk = wkm;
		i__2 = *n;
		for (j = kp1; j <= i__2; ++j) {
		    z__[j] += t * a[k + j * a_dim1];
/* L70: */
		}
	    }
	}

	z__[k] = wk;
/* L100: */
    }

    s = 1.f / sasum_(n, &z__[1]);
    sscal_(n, &s, &z__[1]);

/*     solve trans(l)*y = w */

    i__1 = *n;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n + 1 - kb;
	if (k < *n) {
	    i__2 = *n - k;
	    z__[k] += sdot_(&i__2, &a[k + 1 + k * a_dim1], &z__[k + 1]);
	}
	if ((d__1 = z__[k], abs(d__1)) > 1.f) {
	    s = 1.f / (d__1 = z__[k], abs(d__1));
	    sscal_(n, &s, &z__[1]);
	}
	il = ipvt[k];
	t = z__[il];
	z__[il] = z__[k];
	z__[k] = t;
/* L120: */
    }

    s = 1.f / sasum_(n, &z__[1]);
    sscal_(n, &s, &z__[1]);

    ynorm = 1.f;

/*     solve l*v = y */

    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	il = ipvt[k];
	t = z__[il];
	z__[il] = z__[k];
	z__[k] = t;
	if (k < *n) {
	    i__2 = *n - k;
	    saxpy_(&i__2, &t, &a[k + 1 + k * a_dim1], &z__[k + 1]);
	}
	if ((d__1 = z__[k], abs(d__1)) > 1.f) {
	    s = 1.f / (d__1 = z__[k], abs(d__1));
	    sscal_(n, &s, &z__[1]);
	    ynorm = s * ynorm;
	}
/* L140: */
    }

    s = 1.f / sasum_(n, &z__[1]);
    sscal_(n, &s, &z__[1]);
    ynorm = s * ynorm;

/*     solve  u*z = v */

    i__1 = *n;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n + 1 - kb;
	if ((d__1 = z__[k], abs(d__1)) > (d__2 = a[k + k * a_dim1], abs(d__2))
		) {
	    s = (d__1 = a[k + k * a_dim1], abs(d__1)) / (d__2 = z__[k], abs(
		    d__2));
	    sscal_(n, &s, &z__[1]);
	    ynorm = s * ynorm;
	}
	if (a[k + k * a_dim1] != 0.f) {
	    z__[k] /= a[k + k * a_dim1];
	}
	if (a[k + k * a_dim1] == 0.f) {
	    z__[k] = 1.f;
	}
	t = -z__[k];
	i__2 = k - 1;
	saxpy_(&i__2, &t, &a[k * a_dim1 + 1], &z__[1]);
/* L160: */
    }

/*     make znorm = 1.0 */

    s = 1.f / sasum_(n, &z__[1]);
    sscal_(n, &s, &z__[1]);
    ynorm = s * ynorm;

    *rcond = ynorm / anorm;
L999:

    return 0;
} /* sgeco_ */

/* sgefa    last revised 07/08/87 by tjw */
/* *sgefa f77 check, 07/08/87 by tjw */
/* Subroutine */ int sgefa_(doublereal *a, integer *ilda, integer *n, integer 
	*ipvt, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer j, k;
    static doublereal t;
    static integer il, nm1, kp1;
    static doublereal div, adiv;
    extern /* Subroutine */ int sscal_(integer *, doublereal *, doublereal *),
	     saxpy_(integer *, doublereal *, doublereal *, doublereal *);
    extern integer isamax_(integer *, doublereal *);


/* ***after moler c.b. */
/* ***purpose */
/*  factors a real*8 matrix by gaussian elimination. */
/* ***description */
/*     sgefa factors a real matrix by gaussian elimination. */

/*     sgefa is usually called by sgeco, but it can be called */
/*     directly with a saving in time if  rcond  is not needed. */
/*     (time for sgeco) = (1 + 9/n)*(time for sgefa) . */

/*     on entry */

/*        a       real*8(ilda, n) */
/*                the matrix to be factored. */

/*        ilda     integer */
/*                the leading dimension of the array  a. */

/*        n       integer */
/*                the order of the matrix  a. */

/*     on return */

/*        a       an upper triangular matrix and the multipliers */
/*                which were used to obtain it. */
/*                the factorization can be written  a = l*u  where */
/*                l  is a product of permutation and unit lower */
/*                triangular matrices and  u  is upper triangular. */

/*        ipvt    integer(n) */
/*                an integer vector of pivot indices. */

/*        info    integer */
/*                = -1  singularity indicated by a would-be zero divide */
/*                      (added 11jul86 by tjw). */
/*                =  0  normal value. */
/*                =  k  if  u(k,k) .eq. 0.0 .  this is not an error */
/*                      condition for this routine, but it does */
/*                      indicate that sgesl or sgedi will divide by zero */
/*                      if called.  use  rcond  in sgeco for a reliable */
/*                      indication of singularity. */


/*     note- eqlib or flpars must be called before this routine */
/*     in order to provide a value for smpos (28jul86) */

/* ***references */
/*  dongarra j.j., bunch j.r., moler c.b., stewart g.w., */
/*   *linpack users  guide*, siam, 1979. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/* ---------------------------------------------------------------------- */

/*     gaussian elimination with partial pivoting */

    /* Parameter adjustments */
    a_dim1 = *ilda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ipvt;

    /* Function Body */
    *info = 0;
    nm1 = *n - 1;
    if (nm1 >= 1) {
	i__1 = nm1;
	for (k = 1; k <= i__1; ++k) {
	    kp1 = k + 1;

/*       find il = pivot index */

	    i__2 = *n - k + 1;
	    il = isamax_(&i__2, &a[k + k * a_dim1]) + k - 1;
	    ipvt[k] = il;

/*       zero pivot implies this column already triangularized */

	    if (a[il + k * a_dim1] != 0.f) {

/*         interchange if necessary */

		if (il != k) {
		    t = a[il + k * a_dim1];
		    a[il + k * a_dim1] = a[k + k * a_dim1];
		    a[k + k * a_dim1] = t;
		}

/*         compute multipliers */

		div = a[k + k * a_dim1];

/*           test for potential zero divide. */

		adiv = abs(div);
		if (adiv <= eqleps_1.smpos) {
		    *info = -1;
		    goto L80;
		}
		t = -1.f / div;
		i__2 = *n - k;
		sscal_(&i__2, &t, &a[k + 1 + k * a_dim1]);

/*         row elimination with column indexing */

		i__2 = *n;
		for (j = kp1; j <= i__2; ++j) {
		    t = a[il + j * a_dim1];
		    if (il != k) {
			a[il + j * a_dim1] = a[k + j * a_dim1];
			a[k + j * a_dim1] = t;
		    }
		    i__3 = *n - k;
		    saxpy_(&i__3, &t, &a[k + 1 + k * a_dim1], &a[k + 1 + j * 
			    a_dim1]);
/* L30: */
		}
		goto L50;
	    }
	    *info = k;
L50:
/* L60: */
	    ;
	}
    }
    ipvt[*n] = *n;
    if (a[*n + *n * a_dim1] == 0.f) {
	*info = *n;
    }
L80:

    return 0;
} /* sgefa_ */

/* sgesl    last revised 07/08/87 by tjw */
/* *sgesl f77 check, 07/08/87 by tjw */
/* Subroutine */ int sgesl_(doublereal *a, integer *ilda, integer *n, integer 
	*ipvt, doublereal *b)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer k;
    static doublereal t;
    static integer kb, il, nm1;
    extern /* Subroutine */ int saxpy_(integer *, doublereal *, doublereal *, 
	    doublereal *);


/* ***after  moler c.b. (unm) */
/* ***purpose */
/*  solves the real*8 system a*x=b */
/*  using the factors of sgeco or sgefa */
/* ***description */
/*     sgesl solves the real*8 system */
/*     a * x = b */
/*     using the factors computed by sgeco or sgefa. */

/*     on entry */

/*        a       real*8(ilda, n) */
/*                the output from sgeco or sgefa. */

/*        ilda     integer */
/*                the leading dimension of the array  a . */

/*        n       integer */
/*                the order of the matrix  a . */

/*        ipvt    integer(n) */
/*                the pivot vector from sgeco or sgefa. */

/*        b       real*8(n) */
/*                the right hand side vector. */


/*     on return */

/*        b       the solution vector  x . */

/*     error condition */

/*        a division by zero will occur if the input factor contains a */
/*        zero on the diagonal.  technically this indicates singularity */
/*        but it is often caused by improper arguments or improper */
/*        setting of ilda .  it will not occur if the routines are */
/*        called correctly and if sgeco has set rcond .gt. 0.0 */
/*        or sgefa has set info .eq. 0. */

/*     to compute  inverse(a) * c  where  c  is a matrix */
/*     with  p  columns */
/*           call sgeco(a,ilda,n,ipvt,rcond,z) */
/*           if (rcond is too small) go to ... */
/*           do 10 j = 1, p */
/*              call sgesl(a,ilda,n,ipvt,c(1,j),0) */
/*        10 continue */

/* ***references */
/*  dongarra j.j., bunch j.r., moler c.b., stewart g.w., */
/*   *linpack users  guide*, siam, 1979. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    a_dim1 = *ilda;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ipvt;
    --b;

    /* Function Body */
    nm1 = *n - 1;

/*     first solve  l*y = b */

    if (nm1 >= 1) {
	i__1 = nm1;
	for (k = 1; k <= i__1; ++k) {
	    il = ipvt[k];
	    t = b[il];
	    if (il != k) {
		b[il] = b[k];
		b[k] = t;
	    }
	    i__2 = *n - k;
	    saxpy_(&i__2, &t, &a[k + 1 + k * a_dim1], &b[k + 1]);
/* L20: */
	}
    }

/*     now solve  u*x = y */

    i__1 = *n;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n + 1 - kb;
	b[k] /= a[k + k * a_dim1];
	t = -b[k];
	i__2 = k - 1;
	saxpy_(&i__2, &t, &a[k * a_dim1 + 1], &b[1]);
/* L40: */
    }

    return 0;
} /* sgesl_ */

/* shelv    last revised 07/08/87 by tjw */
/* *shelv f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int shelv_(char *a, integer *nel, integer *nchars, integer *
	kcol, integer *kchars, ftnlen a_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer ia, ja, im;
    static char wa[80], wk[80];
    static integer inc;
    static char key[80];
    static integer klstc;


/*     shell sort */

/*     shell sort of nel elements of length nchars each in array a. */
/*     keys start in column kcol, of length kchars. */
/*     element length nchars must be .le. 80 */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* ----------------------------------------------------------------------- */
/* impliciti.h */
/*   standard implicit statement for eq3/6 routines not requiring */
/*   floating point variables */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    a -= a_len;

    /* Function Body */
    inc = 1;
    klstc = *kcol + *kchars - 1;

/*     generate first increment */

L10:
    inc = inc * 3 + 1;
    if (inc >= *nel) {
	goto L15;
    }
    goto L10;

L15:

/*     back up one term of sequence */

    inc = (inc - 1) / 3;

/*     begin sort */

L20:
    inc = (inc - 1) / 3;

/*     clamp */

    if (inc < 1) {
	inc = 1;
    }
    im = inc;

/*     set starting index */

    ja = im + 1;
L30:
    ia = ja - im;

/*     get working key and line image */

    s_copy(key, a + (ja * a_len + (*kcol - 1)), (ftnlen)80, klstc - (*kcol - 
	    1));
    s_copy(wa, a + ja * a_len, (ftnlen)80, (*nchars));

/*     get a key and test */

L40:
    s_copy(wk, a + (ia * a_len + (*kcol - 1)), (ftnlen)80, klstc - (*kcol - 1)
	    );
    if (s_cmp(key, wk, (ftnlen)80, (ftnlen)80) < 0) {

/*       shift a's */

	s_copy(a + (ia + im) * a_len, a + ia * a_len, (*nchars), (*nchars));
	ia -= im;
	if (ia > 0) {
	    goto L40;
	}
    }

/*     insert wa */

    s_copy(a + (ia + im) * a_len, wa, (*nchars), (ftnlen)80);
    ++ja;
    if (ja <= *nel) {
	goto L30;
    }
    if (inc > 1) {
	goto L20;
    }

    return 0;
} /* shelv_ */

/* sortr8   last revised 07/08/87 by tjw */
/* *sortr8 f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int sortr8_(doublereal *a, integer *nel)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    static integer ia, ja, im;
    static doublereal wa, wk;
    static integer inc;
    static doublereal akey;


/*     shell sort of floating point array */
/*     24jun86  att  mod for accepting absolute value of a(i) */
/*     28mar86  mlc  adapted from shelv */

/*     shell sort of real*8 array a. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --a;

    /* Function Body */
    inc = 1;

/*     generate first increment */

L10:
    inc = inc * 3 + 1;
    if (inc >= *nel) {
	goto L15;
    }
    goto L10;

L15:

/*     back up one term of sequence */

    inc = (inc - 1) / 3;

/*      begin sort */

L20:
    inc = (inc - 1) / 3;

/*     clamp */

    if (inc < 1) {
	inc = 1;
    }
    im = inc;

/*     set starting index */

    ja = im + 1;
L30:
    ia = ja - im;

/*      get working key element */

    akey = (d__1 = a[ja], abs(d__1));
    wa = a[ja];

/*      get a key and test */

L40:
    wk = (d__1 = a[ia], abs(d__1));
    if (akey < wk) {

/*       shift a's */

	a[ia + im] = a[ia];
	ia -= im;
	if (ia > 0) {
	    goto L40;
	}
    }

/*     insert wa */

    a[ia + im] = wa;
    ++ja;
    if (ja <= *nel) {
	goto L30;
    }

    if (inc > 1) {
	goto L20;
    }

    return 0;
} /* sortr8_ */

/* srchn    last revised 07/08/87 by tjw */
/* *srchn f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int srchn_(char *ua, integer *n, char *un, integer *ix, 
	ftnlen ua_len, ftnlen un_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer k;


/*     search array ua for occurrence of un */
/*     temporary- compare only the first 12 characters */
/*       until the data file reads are changed to a24 format */
/*     return index ix of un in ua */
/*     ix = -1 if not found */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    ua -= 24;

    /* Function Body */
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	if (s_cmp(ua + k * 24, un, (ftnlen)12, (ftnlen)12) == 0) {

/*       found it */

	    *ix = k;
	    goto L999;

	}
/* L10: */
    }

/*     not found */

    *ix = -1;

L999:
    return 0;
} /* srchn_ */

/* srtsum   last revised 07/08/87 by tjw */
/* *srtsum f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int srtsum_(doublereal *d__, integer *n, doublereal *sumd)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k;
    extern /* Subroutine */ int sortr8_(doublereal *, integer *);


/*     sort array and sum */

/*     input   d      array of real*8 positive terms */
/*             n      number of terms in d */
/*     output  sumd   sum of terms of d */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------- */

    /* Parameter adjustments */
    --d__;

    /* Function Body */
    if (*n > 1) {
	sortr8_(&d__[1], n);

	*sumd = 0.f;
	i__1 = *n;
	for (k = 1; k <= i__1; ++k) {
	    *sumd += d__[k];
/* L10: */
	}

    } else if (*n == 1) {
	*sumd = d__[1];
    } else {
	*sumd = 0.f;
    }

    return 0;
} /* srtsum_ */

/* sscal    last revised 07/08/87 by tjw */
/* *sscal f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int sscal_(integer *n, doublereal *sa, doublereal *sx)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, nm, nmp1;


/* ***after lawson c. (jpl),hanson r. (sla), */
/*                            kincaid d. (u texas), krogh f. (jpl) */
/* ***purpose */
/*   vector scale x = a*x, real*8 case */
/* ***description */
/*    description of parameters */

/*     --input-- */
/*        n  number of elements in input vector(s) */
/*       sa  real*8 scale factor */
/*       sx  real*8 vector with n elements */

/*     --output-- */
/*       sx  real*8 result (unchanged if n.le.0) */

/*     replace real*8 sx by real*8 sa*sx. */
/*     for i=1 to n, replace sx(i) with sa * sx(i) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --sx;

    /* Function Body */
    if (*n <= 0) {
	goto L999;
    }

/*     clean-up loop so remaining vector length is a multiple of 5. */

    nm = *n % 5;
    if (nm > 0) {
	i__1 = nm;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    sx[i__] = *sa * sx[i__];
/* L30: */
	}
	if (*n < 5) {
	    goto L999;
	}
    }

    nmp1 = nm + 1;
    i__1 = *n;
    for (i__ = nmp1; i__ <= i__1; i__ += 5) {
	sx[i__] = *sa * sx[i__];
	sx[i__ + 1] = *sa * sx[i__ + 1];
	sx[i__ + 2] = *sa * sx[i__ + 2];
	sx[i__ + 3] = *sa * sx[i__ + 3];
	sx[i__ + 4] = *sa * sx[i__ + 4];
/* L50: */
    }

L999:
    return 0;
} /* sscal_ */

/* stpp     last revised 07/08/87 by tjw */
/* *stpp  f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int stpp_(doublereal *p, doublereal *dotp, integer *ip, 
	doublereal *dpmax, doublereal *dpmin, doublereal *dotm, integer *im, 
	doublereal *dmmax, doublereal *dmmin, integer *imax)
{
    /* Format strings */
    static char fmt_1010[] = "(\002 * error - buffer index overflow, index ."
	    "gt. \002,i5,\002 (eqlib/stpp)\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___1139 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___1140 = { 0, 0, 0, fmt_1010, 0 };



/*     24jun86  mod for combining positive & neg column */
/*     13jun86  mod to real*8 */
/*     25apr86  mod to do max, min work */
/*     22apr86  mod to real*4 for tests */
/*     21apr86  mlc */

/*     store partial product */

/*     input   p       real*8 term */
/*             dotp    real*8 array of positive terms */
/*             ip      index into dotp (advanced 1 if p .gt. 0) */
/*             dpmax   set to max value in dotp */
/*             dpmin   set to min value in dotp */
/*             dotm    real*8 array of abs val of negative terms */
/*             im      index into dotm */
/*             dmmax   set to max value in dotm */
/*             dmmin   set to min value in dotm */
/*             imax    maximum value for indices ip, im */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ------------------------------------------------------------------ */

    /* Parameter adjustments */
    --dotm;
    --dotp;

    /* Function Body */
    ++(*ip);
    if (*ip > *imax) {
	io___1139.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___1139);
	do_fio(&c__1, (char *)&(*imax), (ftnlen)sizeof(integer));
	e_wsfe();
	io___1140.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___1140);
	do_fio(&c__1, (char *)&(*imax), (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    dotp[*ip] = *p;
    if (abs(*p) > *dpmax) {
	*dpmax = abs(*p);
    }
    if (abs(*p) < *dpmin) {
	*dpmin = abs(*p);
    }

    return 0;
} /* stpp_ */

/* stripl   last revised 07/08/87 by tjw */
/* *stripl f77 rewrite, 07/08/87 by tjw */
/* Subroutine */ int stripl_(integer *nin, integer *nout, integer *ilen)
{
    /* Initialized data */

    static char ufmt[5] = "(a80)";
    static char ustar[1] = "*";

    /* Format strings */
    static char fmt_1005[] = "(i2)";
    static char fmt_1010[] = "(a80)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_rsfe(cilist *), e_rsfe(void), s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static char uch[1];
    static integer illen;
    static char uibuf[80];

    /* Fortran I/O blocks */
    static icilist io___1145 = { 0, ufmt+2, 0, fmt_1005, 2, 1 };
    static cilist io___1146 = { 0, 0, 1, fmt_1010, 0 };
    static cilist io___1149 = { 0, 0, 0, ufmt, 0 };



/*     strip lines with * in col 1  write long lines */

/*     25nov85  mlc  adapted from strips */

/*     read a file from unit number nin */
/*     skip lines with * in column 1, write all other lines */
/*     to unit number nout */
/*     len is line length in characters */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* ----------------------------------------------------------------------- */

/*     clamp line length and construct format */

    illen = *ilen;
    if (illen > 80) {
	illen = 80;
    }
    if (illen < 0) {
	illen = 1;
    }
    s_wsfi(&io___1145);
    do_fio(&c__1, (char *)&illen, (ftnlen)sizeof(integer));
    e_wsfi();

L10:
    io___1146.ciunit = *nin;
    i__1 = s_rsfe(&io___1146);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = do_fio(&c__1, uibuf, (ftnlen)80);
    if (i__1 != 0) {
	goto L999;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L999;
    }

/*     skip lines with * in col 1 */

    *(unsigned char *)uch = *(unsigned char *)uibuf;
    if (*(unsigned char *)uch == *(unsigned char *)&ustar[0]) {
	goto L10;
    }

    io___1149.ciunit = *nout;
    s_wsfe(&io___1149);
    do_fio(&c__1, uibuf, (ftnlen)80);
    e_wsfe();
    goto L10;

L999:
    return 0;
} /* stripl_ */

/* supprs   last revised 12/08/87 by tjw */
/* *supprs created in f77 12/08/87 by tjw */
/* Subroutine */ int supprs_(integer *nxmod, integer *jxmod, integer *kxmod, 
	char *uxmod, char *uspec, char *umin, char *ugas, char *usolx, 
	integer *jsflag, integer *jmflag, integer *jgflag, integer *jxflag, 
	integer *nst, integer *nmt, integer *ngt, integer *nxt, integer *
	noutpt, integer *nttyo, ftnlen uxmod_len, ftnlen uspec_len, ftnlen 
	umin_len, ftnlen ugas_len, ftnlen usolx_len)
{
    /* Initialized data */

    static char uaq[24] = "aqueous species         ";
    static char umn[24] = "minerals                ";
    static char ugs[24] = "gases                   ";
    static char uss[24] = "solid solutions         ";
    static char ufix[8] = "fix     ";

    /* Format strings */
    static char fmt_1028[] = "(\002 the species \002,a24,\002 has been user-"
	    "suppressed\002,/)";
    static char fmt_237[] = "(\002 * note- suppress species \002,a24,\002 wa"
	    "s not among\002,/7x,\002the loaded \002,a24,\002 (eqlib/supprs"
	    ")\002,/)";
    static char fmt_1216[] = "(\002 * note- \002,a24,\002 is a fictive fugac"
	    "ity fixing\002,/7x,\002so it can not be suppressed (eqlib/supprs)"
	    "\002,/)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer n, ng, nm, ns, nx;
    static char unamsp[24];

    /* Fortran I/O blocks */
    static cilist io___1158 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1159 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1160 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1161 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1162 = { 0, 0, 0, fmt_1216, 0 };
    static cilist io___1163 = { 0, 0, 0, fmt_1216, 0 };
    static cilist io___1165 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1166 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1167 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1168 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1170 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1171 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1172 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1173 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1175 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1176 = { 0, 0, 0, fmt_1028, 0 };
    static cilist io___1177 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___1178 = { 0, 0, 0, fmt_237, 0 };



/*     this routine suppresses species/reactions as directed by */
/*     what is on the input file.  uxmod is the name of the associated */
/*     species and kxmod = -1.  routine alters handles the log k */
/*     alter function (kxmod = 0, 1, or 2). */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


    /* Parameter adjustments */
    --jxflag;
    --jgflag;
    --jmflag;
    --jsflag;
    usolx -= usolx_len;
    ugas -= ugas_len;
    umin -= umin_len;
    uspec -= uspec_len;
    uxmod -= uxmod_len;
    --kxmod;
    --jxmod;

    /* Function Body */

/* ----------------------------------------------------------------- */

    if (*nxmod <= 0) {
	goto L999;
    }

    i__1 = *nxmod;
    for (n = 1; n <= i__1; ++n) {
	if (kxmod[n] >= 0) {
	    goto L1200;
	}
	s_copy(unamsp, uxmod + n * uxmod_len, (ftnlen)24, uxmod_len);

/*     aqueous species */

	if (jxmod[n] == 0) {
	    i__2 = *nst;
	    for (ns = 1; ns <= i__2; ++ns) {
		if (s_cmp(unamsp, uspec + ns * uspec_len, (ftnlen)24, 
			uspec_len) == 0) {
		    jsflag[ns] = 2;
		    io___1158.ciunit = *noutpt;
		    s_wsfe(&io___1158);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    io___1159.ciunit = *nttyo;
		    s_wsfe(&io___1159);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    goto L1200;
		}
/* L1005: */
	    }
	    io___1160.ciunit = *noutpt;
	    s_wsfe(&io___1160);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uaq, (ftnlen)24);
	    e_wsfe();
	    io___1161.ciunit = *nttyo;
	    s_wsfe(&io___1161);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uaq, (ftnlen)24);
	    e_wsfe();
	    goto L1200;
	}

/*     minerals */

	if (jxmod[n] == 1) {
	    if (s_cmp(unamsp, ufix, (ftnlen)8, (ftnlen)8) == 0) {
		io___1162.ciunit = *noutpt;
		s_wsfe(&io___1162);
		do_fio(&c__1, unamsp, (ftnlen)24);
		e_wsfe();
		io___1163.ciunit = *nttyo;
		s_wsfe(&io___1163);
		do_fio(&c__1, unamsp, (ftnlen)24);
		e_wsfe();
		goto L1200;
	    }
	    i__2 = *nmt;
	    for (nm = 1; nm <= i__2; ++nm) {
		if (s_cmp(unamsp, umin + nm * umin_len, (ftnlen)24, umin_len) 
			== 0) {
		    jmflag[nm] = 2;
		    io___1165.ciunit = *noutpt;
		    s_wsfe(&io___1165);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    io___1166.ciunit = *nttyo;
		    s_wsfe(&io___1166);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    goto L1200;
		}
/* L1035: */
	    }
	    io___1167.ciunit = *noutpt;
	    s_wsfe(&io___1167);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, umn, (ftnlen)24);
	    e_wsfe();
	    io___1168.ciunit = *nttyo;
	    s_wsfe(&io___1168);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, umn, (ftnlen)24);
	    e_wsfe();
	    goto L1200;
	}

/*     gases */

	if (jxmod[n] == 2) {
	    i__2 = *ngt;
	    for (ng = 1; ng <= i__2; ++ng) {
		if (s_cmp(unamsp, ugas + ng * ugas_len, (ftnlen)24, ugas_len) 
			== 0) {
		    jgflag[ng] = 2;
		    io___1170.ciunit = *noutpt;
		    s_wsfe(&io___1170);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    io___1171.ciunit = *nttyo;
		    s_wsfe(&io___1171);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    goto L1200;
		}
/* L1065: */
	    }
	    io___1172.ciunit = *noutpt;
	    s_wsfe(&io___1172);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, ugs, (ftnlen)24);
	    e_wsfe();
	    io___1173.ciunit = *nttyo;
	    s_wsfe(&io___1173);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, ugs, (ftnlen)24);
	    e_wsfe();
	    goto L1200;
	}

/*     solid solutions */

	if (jxmod[n] == 3) {
	    i__2 = *nxt;
	    for (nx = 1; nx <= i__2; ++nx) {
		if (s_cmp(unamsp, usolx + nx * usolx_len, (ftnlen)24, 
			usolx_len) == 0) {
		    jxflag[nx] = 4;
		    io___1175.ciunit = *noutpt;
		    s_wsfe(&io___1175);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    io___1176.ciunit = *nttyo;
		    s_wsfe(&io___1176);
		    do_fio(&c__1, unamsp, (ftnlen)24);
		    e_wsfe();
		    goto L1200;
		}
/* L1095: */
	    }
	    io___1177.ciunit = *noutpt;
	    s_wsfe(&io___1177);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uss, (ftnlen)24);
	    e_wsfe();
	    io___1178.ciunit = *nttyo;
	    s_wsfe(&io___1178);
	    do_fio(&c__1, unamsp, (ftnlen)24);
	    do_fio(&c__1, uss, (ftnlen)24);
	    e_wsfe();
	    goto L1200;
	}

L1200:
	;
    }

L999:
    return 0;
} /* supprs_ */

/* swchlm   last revised 01/25/88 by rmm */
/* *swchlm f77 check, ok 04/06/87 by tjw */
/* Subroutine */ int swchlm_(integer *n1, integer *n2, integer *nst)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j;
    extern /* Subroutine */ int bdmlx_(integer *), bdslx_(integer *), iswch_(
	    integer *, integer *, integer *);


/*     this routine is called by routine switch. */

/*     switch lambda and mu indices for consistency with basis-switching, */
/*     then remake derived index arrays */

/*     input n1, n2   species indices to switch */
/*      it is assumed n1 .ne. n2 */
/*     in arrays nslmx and nmux, */
/*      if n1 occurs, replace it with n2 */
/*      if n2 occurs, replace it with n1 */
/*     and rebuild the derived index arrays in commons /eqlpmx/, /eqlpsl/ */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* ------------------------------------------------------------------- */
/* eqlpmu.h */

/*      nmu = actual number of entries in use */
/*      nmut = maximum number of entries allowed */
/*      nmux = triples of aqueous species indices */
/*      pmu = mu(ijk) values array */


/* ---------------------------------------------------------------------- */

/*     switch lambda indices */

/* -------------------------------------------------------------------- */
/* eqlpsa.h */
/*      nslm  = number of entries in use */
/*      nslmt = maximum number allowed */
/*      nslmx = species index pairs */
/*      pslm =  lambda triples from file data1p */
/*      nalpha = indices into palpha array */

    i__1 = eqlpsa_1.nslm;
    for (j = 1; j <= i__1; ++j) {
	iswch_(n1, n2, &eqlpsa_1.nslmx[(j << 1) - 2]);
	iswch_(n1, n2, &eqlpsa_1.nslmx[(j << 1) - 1]);
/* L10: */
    }

/*     switch mu indices */

    i__1 = eqlpmu_1.nmu;
    for (j = 1; j <= i__1; ++j) {
	iswch_(n1, n2, &eqlpmu_1.nmux[j * 3 - 3]);
	iswch_(n1, n2, &eqlpmu_1.nmux[j * 3 - 2]);
	iswch_(n1, n2, &eqlpmu_1.nmux[j * 3 - 1]);
/* L20: */
    }

/*     build new sets of derived index arrays */

    bdslx_(nst);
    bdmlx_(nst);

    return 0;
} /* swchlm_ */

/* switch   last revised 12/11/87 by tjw */
/* *f77 check, ok, 11/30/87 tjw */
/* Subroutine */ int switch_(integer *ns1, integer *ns2, integer *icode, 
	doublereal *ars, doublereal *amn, doublereal *ags, doublereal *cess, 
	doublereal *cdrs, doublereal *cdrm, doublereal *cdrg, doublereal *
	cxistq, doublereal *mwtss, doublereal *z__, doublereal *zsq2, 
	doublereal *titr, doublereal *azero, doublereal *hydn, doublereal *
	csp, char *uspec, integer *jflag, integer *jsflag, integer *ibasis, 
	integer *nsp, integer *iopg1, integer *iacion, integer *iebal, 
	integer *nhydr, integer *nchlor, integer *nct, integer *nsb, integer *
	nsq, integer *nsq1, integer *nst, integer *nrst, integer *nmt, 
	integer *ngt, integer *nctmax, integer *nsqmx1, integer *narxmx, 
	integer *ntprmx, integer *nerr, integer *noutpt, integer *nttyo, 
	logical *qhydth, logical *qpt4, logical *qbassw, ftnlen uspec_len)
{
    /* Format strings */
    static char fmt_1055[] = "(/6x,\002switching \002,a24,\002 from the basi"
	    "s for \002,a24,/)";

    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, cess_dim1, cess_offset, cdrs_dim1,
	     cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, cdrg_offset, 
	    i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, nc, ii, ng;
    static doublereal cx;
    static integer nn, nm;
    static logical qq;
    static doublereal xx;
    static char udm[24];
    static integer nrs, nss, nrs1, nrs2;
    extern /* Subroutine */ int prreac_(doublereal *, char *, char *, integer 
	    *, integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    static doublereal stofac;
    extern /* Subroutine */ int swchlm_(integer *, integer *, integer *);
    static char unamsp[24];
    extern /* Subroutine */ int swtchk_(doublereal *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___1181 = { 0, 0, 0, fmt_1055, 0 };



/*     this routine performs a basis-switch between to aqueous species. */
/*     the local indices of the switched species are ns1 and ns2, where */
/*     ns2 is greater in value than ns1.  if icode = 3, then this */
/*     routine is being used by eq3nr.  this causes modification of */
/*     the csp and nsp arrays. */

/*     basis switching is subject to the following rules- */

/*        1. a strict basis species can not be switched with another */
/*           strict basis species */
/*        2. an auxiliary basis species can not be switched with another */
/*           auxiliary basis species. */
/*        3. the second species, identified by the index ns2 = */
/*           ibasis(ns1), must have a reaction associated with it. */
/*           hence it can not be in the strict basis.  its associated */
/*           reaction must link it with the first species (ns1). */
/*           hence rules 1 and 2 above. */
/*        4. the positions with regard to the strict and auxiliary bases */
/*           noted above are those holding at the time of the call to */
/*           this routine. */
/*        5. switching is not permitted if ars(1,1,nrs2) = 500. for the */
/*           linking reaction (nrs2), unless the switch is a simple or */
/*           discretionary switch between a strict basis species and */
/*           an auxiliary basis species whose jflag is not 30. */
/*        6. the following species can not be switched out of the basis */
/*           set- */
/*             h20, a species (na+ or cl-) is used to define the */
/*             equivalent stoichiometric ionic strength, or a species */
/*             used to make electrical balancing adjustments. */

/*     there are three possible switching cases- */

/*        1. a species in the auxiliary basis whose jflag value is */
/*           not 30 (eliminated species) is switched into the strict */
/*           basis.  this is a 'simple' switch.  the linking reaction */
/*           must be re-written and the change in indexing must be */
/*           reflected in the reaction coefficient arrays.  all */
/*           properties of the switched species are exchanged so as to */
/*           follow the species to which they were originally assigned. */

/*        2. a species not in the basis, or an auxiliary basis species */
/*           whose jflag value is 30, is switched into the strict */
/*           basis.  the reaction coefficient arrays must be re-written */
/*           so that reactions involving the original basis species are */
/*           put in terms of the new one.  a total concentration value */
/*           is multiplied by a stoichiometric factor to maintain */
/*           consistency. */

/*        3. a species not in the basis is switched into the auxiliary */
/*           basis.  the reaction coefficient arrays must be treated as */
/*           in 2 above.  the reaction linking the auxiliary basis species */
/*           with its counterpart in the strict basis must be re-written */
/*           with special instructions.  a total concentration value is */
/*           multiplied by a stoichiometric factor to maintain consistency. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */



/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    --cxistq;
    --mwtss;
    --z__;
    --zsq2;
    --titr;
    --azero;
    --hydn;
    --csp;
    uspec -= uspec_len;
    --jflag;
    --jsflag;
    --ibasis;
    --nsp;
    cess_dim1 = *nctmax;
    cess_offset = 1 + cess_dim1;
    cess -= cess_offset;
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */
    swtchk_(&cdrs[cdrs_offset], uspec + uspec_len, &jflag[1], &jsflag[1], &
	    ibasis[1], iacion, iebal, nsb, nsq, nsq1, nsqmx1, ns1, ns2, nerr, 
	    noutpt, nttyo, uspec_len);

    if (*nerr > 0) {
	goto L999;
    }

/*     get the index of the linking reacion */

    nrs2 = *ns2 - *nsb;

    io___1181.ciunit = *noutpt;
    s_wsfe(&io___1181);
    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
    e_wsfe();

/*     print the existing linking reaction */

    s_copy(unamsp, uspec + *ns2 * uspec_len, (ftnlen)24, uspec_len);
    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs2, nsq, nsq1, 
	    nsqmx1, noutpt, uspec_len, (ftnlen)24);

    if (*ns2 > *nsq || jflag[*ns2] == 30) {
	goto L700;
    }

/* --------------------------------------------------------------------- */

/*     case 1.  this is a 'simple' switch.  a species in the auxiliary */
/*     basis whose jflag value is not 30 is switched with a species in */
/*     the strict basis.  all intrinsic and input properties are switched */
/*     so as to remain assigned to the species with which they were */
/*     originally associated. */

    if (cdrs[*ns1 + nrs2 * cdrs_dim1] > 0.f) {

/*      check to see if the linking reaction is suppressed */

	i__1 = *ntprmx;
	for (j = 1; j <= i__1; ++j) {
	    if (ars[(j + nrs2 * ars_dim2) * ars_dim1 + 1] < 500.f) {
		i__2 = *narxmx;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    ars[i__ + (j + nrs2 * ars_dim2) * ars_dim1] = -ars[i__ + (
			    j + nrs2 * ars_dim2) * ars_dim1];
/* L400: */
		}
	    }
/* L402: */
	}

/*       reverse the sign of the coefficients of the linking reaction */

	i__1 = *nsq1;
	for (nss = 1; nss <= i__1; ++nss) {
	    cdrs[nss + nrs2 * cdrs_dim1] = -cdrs[nss + nrs2 * cdrs_dim1];
/* L305: */
	}
    }

/*     exchange the positions of the two species in the linking reaction */

    cx = cdrs[*ns1 + nrs2 * cdrs_dim1];
    cdrs[*ns1 + nrs2 * cdrs_dim1] = cdrs[*nsq1 + nrs2 * cdrs_dim1];
    cdrs[*nsq1 + nrs2 * cdrs_dim1] = cx;

/*     exchange places in the aqueous species name array */

    s_copy(udm, uspec + *ns1 * uspec_len, (ftnlen)24, uspec_len);
    s_copy(uspec + *ns1 * uspec_len, uspec + *ns2 * uspec_len, uspec_len, 
	    uspec_len);
    s_copy(uspec + *ns2 * uspec_len, udm, uspec_len, (ftnlen)24);

/*     print the new linking reaction */

    s_copy(unamsp, uspec + *ns2 * uspec_len, (ftnlen)24, uspec_len);
    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs2, nsq, nsq1, 
	    nsqmx1, noutpt, uspec_len, (ftnlen)24);

/*     rewrite all other aqueous dissociation reactions */

    nn = nrs2 - 1;
    i__1 = nn;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	cx = cdrs[*ns2 + nrs * cdrs_dim1];
	cdrs[*ns2 + nrs * cdrs_dim1] = cdrs[*ns1 + nrs * cdrs_dim1];
	cdrs[*ns1 + nrs * cdrs_dim1] = cx;
/* L310: */
    }

    nn = nrs2 + 1;
    i__1 = *nrst;
    for (nrs = nn; nrs <= i__1; ++nrs) {
	cx = cdrs[*ns2 + nrs * cdrs_dim1];
	cdrs[*ns2 + nrs * cdrs_dim1] = cdrs[*ns1 + nrs * cdrs_dim1];
	cdrs[*ns1 + nrs * cdrs_dim1] = cx;
/* L312: */
    }

/*     rewrite the mineral dissolution reactions */

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	cx = cdrm[*ns2 + nm * cdrm_dim1];
	cdrm[*ns2 + nm * cdrm_dim1] = cdrm[*ns1 + nm * cdrm_dim1];
	cdrm[*ns1 + nm * cdrm_dim1] = cx;
/* L410: */
    }

/*     rewrite the gas dissolution reactions */

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	cx = cdrg[*ns2 + ng * cdrg_dim1];
	cdrg[*ns2 + ng * cdrg_dim1] = cdrg[*ns1 + ng * cdrg_dim1];
	cdrg[*ns1 + ng * cdrg_dim1] = cx;
/* L420: */
    }

/*     exchange positions in the jflag array */

    ii = jflag[*ns1];
    jflag[*ns1] = jflag[*ns2];
    jflag[*ns2] = ii;

    if (*icode == 3) {

/*       if called by eq3nr, exchange positions in the csp and nsp arrays */

	cx = csp[*ns1];
	csp[*ns1] = csp[*ns2];
	csp[*ns2] = cx;

	ii = nsp[*ns1];
	nsp[*ns1] = nsp[*ns2];
	nsp[*ns2] = ii;
    }

    goto L330;

/* --------------------------------------------------------------------- */

/*     cases 2 and 3.  switch a non-basis species into the expanded */
/*     basis or switch an auxiliary basis species whose jflag value is */
/*     30 into the strict basis. */

/*        first re-write all reactions except that which links the two */
/*        species being switched and, if ns1.gt.nsb, that */
/*        reaction which cross-links the ns1-th species with */
/*        a species in the strict basis. */

L700:
    i__1 = *nrst;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	if (nrs == nrs2) {
	    goto L720;
	}
	cx = cdrs[*ns1 + nrs * cdrs_dim1];
	if (cx != 0.f) {
	    stofac = -cx / cdrs[*ns1 + nrs2 * cdrs_dim1];
	    i__2 = *nsq;
	    for (nss = 1; nss <= i__2; ++nss) {
		xx = cdrs[nss + nrs * cdrs_dim1] + stofac * cdrs[nss + nrs2 * 
			cdrs_dim1];
		if (abs(xx) <= eqleps_1.eps100) {
		    xx = 0.f;
		}
		cdrs[nss + nrs * cdrs_dim1] = xx;
/* L710: */
	    }
	    xx = stofac * cdrs[*nsq1 + nrs2 * cdrs_dim1];
	    if (abs(xx) <= eqleps_1.eps100) {
		xx = 0.f;
	    }
	    cdrs[*ns1 + nrs * cdrs_dim1] = xx;
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		if (ars[(j + nrs * ars_dim2) * ars_dim1 + 1] < 500.f) {
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			ars[i__ + (j + nrs * ars_dim2) * ars_dim1] += stofac *
				 ars[i__ + (j + nrs2 * ars_dim2) * ars_dim1];
/* L405: */
		    }
		}
/* L407: */
	    }
	}
	if (*ns2 <= *nsq) {
	    cx = cdrs[*ns2 + nrs * cdrs_dim1];
	    cdrs[*ns1 + nrs * cdrs_dim1] += cx;
	    cdrs[*ns2 + nrs * cdrs_dim1] = 0.f;
	}
L720:
	;
    }

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	cx = cdrm[*ns1 + nm * cdrm_dim1];
	if (cx != 0.f) {
	    stofac = -cx / cdrs[*ns1 + nrs2 * cdrs_dim1];
	    i__2 = *nsq;
	    for (nss = 1; nss <= i__2; ++nss) {
		xx = cdrm[nss + nm * cdrm_dim1] + stofac * cdrs[nss + nrs2 * 
			cdrs_dim1];
		if (abs(xx) <= eqleps_1.eps100) {
		    xx = 0.f;
		}
		cdrm[nss + nm * cdrm_dim1] = xx;
/* L722: */
	    }
	    xx = stofac * cdrs[*nsq1 + nrs2 * cdrs_dim1];
	    if (abs(xx) <= eqleps_1.eps100) {
		xx = 0.f;
	    }
	    cdrm[*ns1 + nm * cdrm_dim1] = xx;
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		if (amn[(j + nm * amn_dim2) * amn_dim1 + 1] < 500.f) {
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			amn[i__ + (j + nm * amn_dim2) * amn_dim1] += stofac * 
				ars[i__ + (j + nrs2 * ars_dim2) * ars_dim1];
/* L412: */
		    }
		}
/* L414: */
	    }
	}
	if (*ns2 <= *nsq) {
	    cx = cdrm[*ns2 + nm * cdrm_dim1];
	    cdrm[*ns1 + nm * cdrm_dim1] += cx;
	    cdrm[*ns2 + nm * cdrm_dim1] = 0.f;
	}
/* L724: */
    }

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	cx = cdrg[*ns1 + ng * cdrg_dim1];
	if (cx != 0.f) {
	    stofac = -cx / cdrs[*ns1 + nrs2 * cdrs_dim1];
	    i__2 = *nsq;
	    for (nss = 1; nss <= i__2; ++nss) {
		xx = cdrg[nss + ng * cdrg_dim1] + stofac * cdrs[nss + nrs2 * 
			cdrs_dim1];
		if (abs(xx) <= eqleps_1.eps100) {
		    xx = 0.f;
		}
		cdrg[nss + ng * cdrg_dim1] = xx;
/* L726: */
	    }
	    xx = stofac * cdrs[*nsq1 + nrs2 * cdrs_dim1];
	    if (abs(xx) <= eqleps_1.eps100) {
		xx = 0.f;
	    }
	    cdrg[*ns1 + ng * cdrg_dim1] = xx;
	    i__2 = *ntprmx;
	    for (j = 1; j <= i__2; ++j) {
		if (ags[(j + ng * ags_dim2) * ags_dim1 + 1] < 500.f) {
		    i__3 = *narxmx;
		    for (i__ = 1; i__ <= i__3; ++i__) {
			ags[i__ + (j + ng * ags_dim2) * ags_dim1] += stofac * 
				ars[i__ + (j + nrs2 * ars_dim2) * ars_dim1];
/* L415: */
		    }
		}
/* L417: */
	    }
	}
	if (*ns2 <= *nsq) {
	    cx = cdrg[*ns2 + ng * cdrg_dim1];
	    cdrg[*ns1 + ng * cdrg_dim1] += cx;
	    cdrg[*ns2 + ng * cdrg_dim1] = 0.f;
	}
/* L728: */
    }

/*     re-write the dissociation/destruction reaction for the */
/*     ns1-th species if it is in the auxiliary basis. */

    if (*ns1 > *nsb) {
	nrs1 = *ns1 - *nsb;
	stofac = -cdrs[*nsq1 + nrs1 * cdrs_dim1] / cdrs[*ns1 + nrs2 * 
		cdrs_dim1];
	cdrs[*ns1 + nrs1 * cdrs_dim1] = cdrs[*nsq1 + nrs1 * cdrs_dim1];
	i__1 = *nsq;
	for (nss = 1; nss <= i__1; ++nss) {
	    xx = cdrs[nss + nrs1 * cdrs_dim1] + stofac * cdrs[nss + nrs2 * 
		    cdrs_dim1];
	    if (abs(xx) <= eqleps_1.eps100) {
		xx = 0.f;
	    }
	    cdrs[nss + nrs1 * cdrs_dim1] = xx;
/* L730: */
	}
	cdrs[*ns1 + nrs1 * cdrs_dim1] = 0.f;
	cdrs[*nsq1 + nrs1 * cdrs_dim1] = stofac * cdrs[*nsq1 + nrs2 * 
		cdrs_dim1];
	i__1 = *ntprmx;
	for (j = 1; j <= i__1; ++j) {
	    if (ars[(j + nrs * ars_dim2) * ars_dim1 + 1] < 500.f) {
		i__2 = *narxmx;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    ars[i__ + (j + nrs1 * ars_dim2) * ars_dim1] += stofac * 
			    ars[i__ + (j + nrs2 * ars_dim2) * ars_dim1];
/* L422: */
		}
	    }
/* L424: */
	}
    }

/*     re-write the reaction linking the switched species */

    i__1 = *nsq1;
    for (nss = 1; nss <= i__1; ++nss) {
	cdrs[nss + nrs2 * cdrs_dim1] = -cdrs[nss + nrs2 * cdrs_dim1];
/* L750: */
    }
    cx = cdrs[*ns1 + nrs2 * cdrs_dim1];
    cdrs[*ns1 + nrs2 * cdrs_dim1] = cdrs[*nsq1 + nrs2 * cdrs_dim1];
    cdrs[*nsq1 + nrs2 * cdrs_dim1] = cx;

    i__1 = *ntprmx;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *narxmx;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ars[i__ + (j + nrs2 * ars_dim2) * ars_dim1] = -ars[i__ + (j + 
		    nrs2 * ars_dim2) * ars_dim1];
/* L425: */
	}
/* L427: */
    }

    s_copy(udm, uspec + *ns1 * uspec_len, (ftnlen)24, uspec_len);
    s_copy(uspec + *ns1 * uspec_len, uspec + *ns2 * uspec_len, uspec_len, 
	    uspec_len);
    s_copy(uspec + *ns2 * uspec_len, udm, uspec_len, (ftnlen)24);

/*     print the new linking reaction */

    s_copy(unamsp, uspec + *ns2 * uspec_len, (ftnlen)24, uspec_len);
    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs2, nsq, nsq1, 
	    nsqmx1, noutpt, uspec_len, (ftnlen)24);

    if (*icode == 3) {

/*       if called by eq3nr, recalculate the total concentration, if */
/*       one is specified */

	if (jflag[*ns1] == 0) {
	    csp[*ns1] *= -cdrs[*ns1 + nrs2 * cdrs_dim1] / cdrs[*nsq1 + nrs2 * 
		    cdrs_dim1];
	}
    }

/* --------------------------------------------------------------------- */

/*     exchange specific properties of the switched species. */
/*     (this is done for all cases.) */

/*       z = electrical charge */
/*       zsq2 = one half the charge squared */
/*       titr = titration factor */
/*       cxistq = coefficient for calculation of xisteq */
/*       mwtss = molecular weight */
/*       cess = elemental composition */
/*       nhydr = index of hydrogen ion */
/*       nchlor = index of chloride ion */
/*       azero = ion size */
/*       hydn = hydration number */

L330:
    xx = z__[*ns1];
    z__[*ns1] = z__[*ns2];
    z__[*ns2] = xx;

    xx = zsq2[*ns1];
    zsq2[*ns1] = zsq2[*ns2];
    zsq2[*ns2] = xx;

    xx = titr[*ns1];
    titr[*ns1] = titr[*ns2];
    titr[*ns2] = xx;

    xx = cxistq[*ns1];
    cxistq[*ns1] = cxistq[*ns2];
    cxistq[*ns2] = xx;

    xx = mwtss[*ns1];
    mwtss[*ns1] = mwtss[*ns2];
    mwtss[*ns2] = xx;

    i__1 = *nct;
    for (nc = 1; nc <= i__1; ++nc) {
	xx = cess[nc + *ns1 * cess_dim1];
	cess[nc + *ns1 * cess_dim1] = cess[nc + *ns2 * cess_dim1];
	cess[nc + *ns2 * cess_dim1] = xx;
/* L32: */
    }

    qq = *nhydr == *ns2;
    if (*nhydr == *ns1) {
	*nhydr = *ns2;
    }
    if (qq) {
	*nhydr = *ns1;
    }

    qq = *nchlor == *ns2;
    if (*nchlor == *ns1) {
	*nchlor = *ns2;
    }
    if (qq) {
	*nchlor = *ns1;
    }

/*     switch ion sizes */

    xx = azero[*ns1];
    azero[*ns1] = azero[*ns2];
    azero[*ns2] = xx;

/*     switch hydration numbers */

    if (*qhydth) {
	xx = hydn[*ns1];
	hydn[*ns1] = hydn[*ns2];
	hydn[*ns2] = xx;
    }

/*     if doing pitzer's equations, switch the lambda and mu indices and */
/*     rebuild the derived index arrays */

    if (*iopg1 == 1) {
	swchlm_(ns1, ns2, nst);
    }

    *qbassw = TRUE_;

L999:
    return 0;
} /* switch_ */

/* swtchk   last revised 12/11/87 by tjw */
/* *swtchk, created in f77 11/30/87 tjw */
/* Subroutine */ int swtchk_(doublereal *cdrs, char *uspec, integer *jflag, 
	integer *jsflag, integer *ibasis, integer *iacion, integer *iebal, 
	integer *nsb, integer *nsq, integer *nsq1, integer *nsqmx1, integer *
	ns1, integer *ns2, integer *nerr, integer *noutpt, integer *nttyo, 
	ftnlen uspec_len)
{
    /* Format strings */
    static char fmt_1000[] = "(/\002 * basis switching error- \002/7x,a24"
	    ",\002 can not be switched with itself (eqlib/swtchk)\002)";
    static char fmt_1005[] = "(/\002 * basis switching error-\002,/7x,a24"
	    ",\002 can not be switched with \002,a24,\002 (eqlib/swtchk)\002)";
    static char fmt_1010[] = "(7x,\002ns2= \002,i4,\002 is less than ns1="
	    " \002,i4,/7x,\002uspec(ns2)= \002,a24,\002, uspec(ns1)= \002,a24)"
	    ;
    static char fmt_1015[] = "(/\002 * basis switching error-\002,/7x,\002at"
	    "tempt to switch \002,a24,\002 with \002,a24,/7x,\002when it is a"
	    "lso to be switched  with \002,a24,\002 (eqlib/swtchk)\002)";
    static char fmt_1020[] = "(/\002 * basis switching error-\002,/7x,a24"
	    ",\002 can not be switched (eqlib/swtchk)\002)";
    static char fmt_1025[] = "(7x,\002it defines the equiv. stoich. ionic st"
	    "rength\002)";
    static char fmt_1030[] = "(7x,\002it is adjusted for electrical balanc"
	    "ing\002)";
    static char fmt_1035[] = "(7x,a24,\002 is in the strict basis\002)";
    static char fmt_1040[] = "(7x,a24,\002 is suppressed\002)";
    static char fmt_1045[] = "(7x,\002both species are in the auxiliary ba"
	    "sis\002)";
    static char fmt_1050[] = "(7x,a24,\002 is not in the linking reaction"
	    "\002)";

    /* System generated locals */
    integer cdrs_dim1, cdrs_offset, i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer nsg, nrs2;
    static logical qreac;
    extern /* Subroutine */ int prreac_(doublereal *, char *, char *, integer 
	    *, integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    static char unamsp[24];

    /* Fortran I/O blocks */
    static cilist io___1198 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___1199 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___1200 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1201 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1202 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___1203 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___1205 = { 0, 0, 0, fmt_1015, 0 };
    static cilist io___1206 = { 0, 0, 0, fmt_1015, 0 };
    static cilist io___1207 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1208 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1209 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1210 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1211 = { 0, 0, 0, fmt_1025, 0 };
    static cilist io___1212 = { 0, 0, 0, fmt_1025, 0 };
    static cilist io___1213 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1214 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1215 = { 0, 0, 0, fmt_1030, 0 };
    static cilist io___1216 = { 0, 0, 0, fmt_1030, 0 };
    static cilist io___1217 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1218 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1219 = { 0, 0, 0, fmt_1035, 0 };
    static cilist io___1220 = { 0, 0, 0, fmt_1035, 0 };
    static cilist io___1221 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1222 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1223 = { 0, 0, 0, fmt_1040, 0 };
    static cilist io___1224 = { 0, 0, 0, fmt_1040, 0 };
    static cilist io___1226 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1227 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1228 = { 0, 0, 0, fmt_1045, 0 };
    static cilist io___1229 = { 0, 0, 0, fmt_1045, 0 };
    static cilist io___1231 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1232 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___1233 = { 0, 0, 0, fmt_1050, 0 };
    static cilist io___1234 = { 0, 0, 0, fmt_1050, 0 };



/*     this routine checks a proposed basis switch for routine switch */
/*     to see if doing the switch is ok or not. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* ---------------------------------------------------------------------- */

    /* Parameter adjustments */
    uspec -= uspec_len;
    --jflag;
    --jsflag;
    --ibasis;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;

    /* Function Body */
    *nerr = 0;
    if (*ns1 == *ns2) {
	io___1198.ciunit = *noutpt;
	s_wsfe(&io___1198);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1199.ciunit = *nttyo;
	s_wsfe(&io___1199);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	++(*nerr);
    }

/*     ns2 must be greater than ns1. */

    if (*ns2 < *ns1) {
	io___1200.ciunit = *noutpt;
	s_wsfe(&io___1200);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1201.ciunit = *nttyo;
	s_wsfe(&io___1201);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1202.ciunit = *noutpt;
	s_wsfe(&io___1202);
	do_fio(&c__1, (char *)&(*ns2), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*ns1), (ftnlen)sizeof(integer));
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1203.ciunit = *nttyo;
	s_wsfe(&io___1203);
	do_fio(&c__1, (char *)&(*ns2), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*ns1), (ftnlen)sizeof(integer));
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	++(*nerr);
    }

/*     it is not permissible to switch a species more than once */
/*     (in leapfrog fashion). */

    i__1 = *nsb;
    for (nsg = 2; nsg <= i__1; ++nsg) {
	if (ibasis[nsg] == *ns2 && nsg != *ns1) {
	    io___1205.ciunit = *noutpt;
	    s_wsfe(&io___1205);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + nsg * uspec_len, uspec_len);
	    e_wsfe();
	    io___1206.ciunit = *nttyo;
	    s_wsfe(&io___1206);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + nsg * uspec_len, uspec_len);
	    e_wsfe();
	    ++(*nerr);
	}
/* L100: */
    }

/*     h20 and the species (usually na+ or cl-) that defines the */
/*     equivalent stoichiometric ionic strength can not be switched, */
/*     nor can a species that is constrained to satisfy electrical */
/*     balance. */

    if (*ns1 == 1) {
	io___1207.ciunit = *noutpt;
	s_wsfe(&io___1207);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1208.ciunit = *nttyo;
	s_wsfe(&io___1208);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	++(*nerr);
    }

    if (*ns1 == *iacion) {
	io___1209.ciunit = *noutpt;
	s_wsfe(&io___1209);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1210.ciunit = *nttyo;
	s_wsfe(&io___1210);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1211.ciunit = *noutpt;
	s_wsfe(&io___1211);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1212.ciunit = *nttyo;
	s_wsfe(&io___1212);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	++(*nerr);
    }

    if (*ns1 == *iebal) {
	io___1213.ciunit = *noutpt;
	s_wsfe(&io___1213);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1214.ciunit = *nttyo;
	s_wsfe(&io___1214);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1215.ciunit = *noutpt;
	s_wsfe(&io___1215);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	io___1216.ciunit = *nttyo;
	s_wsfe(&io___1216);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	e_wsfe();
	++(*nerr);
    }

/*     the second species can not be in the strict basis, because */
/*     strict basis species do not have an associated reaction. */

    if (*ns2 <= *nsb) {
	io___1217.ciunit = *noutpt;
	s_wsfe(&io___1217);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1218.ciunit = *nttyo;
	s_wsfe(&io___1218);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1219.ciunit = *noutpt;
	s_wsfe(&io___1219);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1220.ciunit = *nttyo;
	s_wsfe(&io___1220);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	++(*nerr);
    }

    if (*ns2 > *nsq || jflag[*ns2] == 30) {
	if (jsflag[*ns2] > 0) {
	    io___1221.ciunit = *noutpt;
	    s_wsfe(&io___1221);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    e_wsfe();
	    io___1222.ciunit = *nttyo;
	    s_wsfe(&io___1222);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    e_wsfe();
	    io___1223.ciunit = *noutpt;
	    s_wsfe(&io___1223);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    e_wsfe();
	    io___1224.ciunit = *nttyo;
	    s_wsfe(&io___1224);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    e_wsfe();
	    ++(*nerr);
	}
    }

/*     both species can not be in the auxiliary basis, because there */
/*     then exists no linking reaction. */

    qreac = TRUE_;
    if (*ns1 > *nsb && *ns2 <= *nsq) {
	io___1226.ciunit = *noutpt;
	s_wsfe(&io___1226);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1227.ciunit = *nttyo;
	s_wsfe(&io___1227);
	do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	e_wsfe();
	io___1228.ciunit = *noutpt;
	s_wsfe(&io___1228);
	e_wsfe();
	io___1229.ciunit = *nttyo;
	s_wsfe(&io___1229);
	e_wsfe();
	++(*nerr);
	qreac = FALSE_;
    }

/*     get the index of the linking reacion */

    if (qreac) {
	nrs2 = *ns2 - *nsb;

/*       the switched species must be linked by the reaction formally */
/*       associated with the second species. */

	if (cdrs[*ns1 + nrs2 * cdrs_dim1] == 0.f) {
	    io___1231.ciunit = *noutpt;
	    s_wsfe(&io___1231);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    e_wsfe();
	    io___1232.ciunit = *nttyo;
	    s_wsfe(&io___1232);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + *ns2 * uspec_len, uspec_len);
	    e_wsfe();
	    io___1233.ciunit = *noutpt;
	    s_wsfe(&io___1233);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    e_wsfe();
	    io___1234.ciunit = *nttyo;
	    s_wsfe(&io___1234);
	    do_fio(&c__1, uspec + *ns1 * uspec_len, uspec_len);
	    e_wsfe();
	    s_copy(unamsp, uspec + *ns2 * uspec_len, (ftnlen)24, uspec_len);
	    prreac_(&cdrs[cdrs_offset], uspec + uspec_len, unamsp, &nrs2, nsq,
		     nsq1, nsqmx1, noutpt, uspec_len, (ftnlen)24);
	    ++(*nerr);
	}
    }

    return 0;
} /* swtchk_ */

/* texp     last revised 11/18/87 by tjw */
/* *texp   f77 check, ok 04/06/87 by tjw */
doublereal texp_(doublereal *x)
{
    /* Format strings */
    static char fmt_25[] = "(\002 * info - exponential truncation, texp ("
	    "\002,1pe12.5,\002) set to \002,e12.5,\002 (eqlib/texp)\002)";

    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double exp(doublereal);

    /* Local variables */
    static doublereal y;

    /* Fortran I/O blocks */
    static cilist io___1236 = { 0, 0, 0, fmt_25, 0 };



/*     function texp is the function 10**x */

/*        al10 is the natural logarithm of ten */
/*        qtxppr is a logical switch that turns on a warning print */
/*          when exponentiation is truncated. */

/*     xltxp is the lower truncation limit on the argument.  if x is */
/*     not greater than xltxp, the result is set to zero.  xutxp is the */
/*     upper trucatiion limit on the argument.  if x is not less than */
/*     xutxp, the result is truncated to yutxp (yutxp = 10**xutxp). */
/*     xutxp is used to avoid overflow when texp is called with a large */
/*     argument.  this is critical.  xltxp, xutxp, and yutxp are */
/*     calculated by routine flpars. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqltxp.h */
/* -------------------------------------------------------------------- */
/* eqlpp.h */

/* -------------------------------------------------------------------- */
/* eqlun.h */
    if (*x <= eqltxp_1.xltxp) {
	ret_val = 0.f;
    } else if (*x > eqltxp_1.xutxp) {
	ret_val = eqltxp_1.yutxp;
	if (eqltxp_1.qtxppr) {
	    io___1236.ciunit = eqlun_1.noutpl;
	    s_wsfe(&io___1236);
	    do_fio(&c__1, (char *)&(*x), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&eqltxp_1.yutxp, (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
	}
    } else {
	y = eqlpp_1.al10 * *x;
	ret_val = exp(y);
    }
    return ret_val;
} /* texp_ */

/* timdat   last revised 07/06/87 by tjw */
/* *timdat f77 rewrite, 07/06/87 by tjw */
/* DAS      subroutine timdat(udate,utime) */

/*     get current date, time in ascii (ridge/sun dependent) */
/*     see also gtime */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* das      include "implicit.h" */

/* das      character*24 utd */
/* das      character*1 ublank */
/* das      data ublank /' '/ */

/* --------------------------------------------------------------- */

/*     fdate is a ridge/sun routine */

/* DAS      call fdate(utd) */

/* DAS      udate(1:2) = utd(9:10) */
/* DAS      udate(3:5) = utd(5:7) */
/* DAS      udate(6:7) = utd(23:24) */
/* DAS      udate(8:8) = ublank */

/* DAS      utime(1:5) = utd(12:16) */
/* DAS      utime(6:8) = ublank */

/* DAS      end */
/* tlg      last revised 07/08/87 by tjw */
/* *tlg f77 check, ok 07/08/87 by tjw */
doublereal tlg_(doublereal *x)
{
    /* Format strings */
    static char fmt_20[] = "(\002 * error - log(\002,e12.5,\002) can not be "
	    "calculated\002,\002 (eqlib/tlg)\002)";

    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double d_lg10(doublereal *);

    /* Fortran I/O blocks */
    static cilist io___1238 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___1239 = { 0, 0, 0, fmt_20, 0 };



/*     function tlg is the function log10, except that the log of zero */
/*     is -999. */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/* ---------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* eqlun.h */
    if (*x < 0.f) {
	io___1238.ciunit = eqlun_1.noutpl;
	s_wsfe(&io___1238);
	do_fio(&c__1, (char *)&(*x), (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___1239.ciunit = eqlun_1.nttyol;
	s_wsfe(&io___1239);
	do_fio(&c__1, (char *)&(*x), (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    } else if (*x <= eqleps_1.smpos) {
	ret_val = -999.f;
    } else {
	ret_val = d_lg10(x);
    }

    return ret_val;
} /* tlg_ */

/* tmpcor   last revised 07/24/87 by rmm */
/* *tmpcor f77 check, ok 07/08/87 by tjw */
/* Subroutine */ int tmpcor_(doublereal *tempc)
{
    /* Initialized data */

    static doublereal baset = 25.;

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer k;
    static doublereal delt, delt2;


/*     make temperature corrections to lambda and mu values */

/*     using base values from commons /eqlpsb/ and /eqlpmb/, */
/*     compute operating values, and place them in */
/*     commons /eqlpsa/ and /eqlpmu/ */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlpar.h  last revised 11/25/87 by tjw */

/*     warning- do not duplicate any parameters here that belong to */
/*              eq3nr, eq6, mcrt, or any other code that uses the */
/*              eqlib library.  as necessary, make up work arrays */
/*              in the calling programs and pass them to eqlib */
/*              routines. */

/*     one exception, not yet eliminated */


/* ------------------------------------------------------------------- */

/*     parameters for polynomial fitting (used in polx and lsqp) */

/*       ipfpar = maximum number of points */
/*       ipfpa1 = ipfpar+1 */
/*       ipfdpa = 2*ipfpa1 */



/*  parameters for pitzer and hkf subroutines */
/*      nmupar   = nmut       dimension of mu array */
/*      nslpar   = nslmt      dimension of lambda array */
/*      nappar   = napt       dimension of palpha array */
/*      ibjpar   = ibjmax     max. no of hkf pairs */
/*      nsxpar   = nsxt       max. no of arrays of triples - pitzer */
/*      nmxpar   = nmxt       max. no of arrays of pairs- pitzer */
/*      islpar   = islmax     max. no. of hypothetical salts - hkf */
/*                            (arrays mslt and islt) */

/* ------------------------------------------------------------------- */
/* eqlpmu.h */

/*      nmu = actual number of entries in use */
/*      nmut = maximum number of entries allowed */
/*      nmux = triples of aqueous species indices */
/*      pmu = mu(ijk) values array */

/* ------------------------------------------------------------------ */
/* eqlpmb.h */
/* -------------------------------------------------------------------- */
/* eqlpsa.h */
/*      nslm  = number of entries in use */
/*      nslmt = maximum number allowed */
/*      nslmx = species index pairs */
/*      pslm =  lambda triples from file data1p */
/*      nalpha = indices into palpha array */


/* -------------------------------------------------------------------- */
/* eqlpsb.h */

/* ---------------------------------------------------------------------- */

    delt = *tempc - baset;
    delt2 = delt * .5f * delt;

    i__1 = eqlpsa_1.nslm;
    for (k = 1; k <= i__1; ++k) {
	eqlpsa_1.pslm[k * 3 - 3] = eqlpsb_1.bslm[k * 3 - 3] + eqlpsb_1.dslm1[
		k * 3 - 3] * delt + eqlpsb_1.dslm2[k * 3 - 3] * delt2;
	eqlpsa_1.pslm[k * 3 - 2] = eqlpsb_1.bslm[k * 3 - 2] + eqlpsb_1.dslm1[
		k * 3 - 2] * delt + eqlpsb_1.dslm2[k * 3 - 2] * delt2;
	eqlpsa_1.pslm[k * 3 - 1] = eqlpsb_1.bslm[k * 3 - 1] + eqlpsb_1.dslm1[
		k * 3 - 1] * delt + eqlpsb_1.dslm2[k * 3 - 1] * delt2;
/* L10: */
    }

    i__1 = eqlpmu_1.nmu;
    for (k = 1; k <= i__1; ++k) {
	eqlpmu_1.pmu[k - 1] = eqlpmb_1.bmu[k - 1] + eqlpmb_1.dmu1[k - 1] * 
		delt + eqlpmb_1.dmu2[k - 1] * delt2;
/* L20: */
    }

    return 0;
} /* tmpcor_ */

/* undflw   last revised 07/08/87 by tjw */
/* *undflw f77 check, ok 04/10/87 by tjw */
/* Subroutine */ int undflw_(void)
{

/*     this routine provides a graceful way of handling underflows. */

/*     *** caution **** */
/*     This routine is specific to the RIDGE computers. */
/*     If the computer being used is not a RIDGE; then this routine */
/*     must be modified.  This routine disables the trap used */
/*     in handling floating point underflows. */

/*     This routine does not seem to cause any harm on SUN computers. */

/*     Other computers may handle underflows automatically; making */
/*     this routine unnecessary. */

/*      integer signal */

/* ---------------------------------------------------------------------- */

/*     comment out the following line if not operating on a ridge */
/*     or sun computer. */

/*      i = signal(119,0,1) */

    return 0;
} /* undflw_ */

/* writr    last revised 07/30/87 by rlh */
/* *writr f77 check, ok 07/08/87 by tjw */
/* Subroutine */ int writr_(integer *irfil, char *ubbuf, integer *nlines, 
	integer *irfp, ftnlen ubbuf_len)
{
    /* Format strings */
    static char fmt_1010[] = "(a80)";
    static char fmt_1020[] = "(\002 * error - trouble writing direct access "
	    "block \002,i8,\002 (eqlib/writr)\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wdfe(cilist *), do_fio(integer *, char *, ftnlen), e_wdfe(void),
	     s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer k;

    /* Fortran I/O blocks */
    static cilist io___1245 = { 1, 0, 0, fmt_1010, 0 };
    static cilist io___1246 = { 0, 0, 0, fmt_1020, 0 };
    static cilist io___1247 = { 0, 0, 0, fmt_1020, 0 };



/*     14jan85  mlc */

/*     direct access write of nlines from ubbuf to irfil */

/*     input   irfil   unit number of direct access file */
/*             ubbuf   output buffer */
/*             nlines  number of lines to write */
/*             irfp    record number (one is first record) */
/*                      irfp is incremented one for each line written */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */
/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */

/* ---------------------------------------------------------------------- */

/*     write (noutpl,1310) irfil,nlines,irfp */
/* 1310 format(' writr entered',/ */
/*    $   '  irfil=',i3,'  nlines='i5,'  irfp=',i10) */

    /* Parameter adjustments */
    ubbuf -= 80;

    /* Function Body */
    i__1 = *nlines;
    for (k = 1; k <= i__1; ++k) {
	io___1245.ciunit = *irfil;
	io___1245.cirec = *irfp;
	i__2 = s_wdfe(&io___1245);
	if (i__2 != 0) {
	    goto L15;
	}
	i__2 = do_fio(&c__1, ubbuf + k * 80, (ftnlen)80);
	if (i__2 != 0) {
	    goto L15;
	}
	i__2 = e_wdfe();
	if (i__2 != 0) {
	    goto L15;
	}
	++(*irfp);
/* L10: */
    }
    goto L999;

L15:
    io___1246.ciunit = eqlun_1.noutpl;
    s_wsfe(&io___1246);
    do_fio(&c__1, (char *)&(*irfp), (ftnlen)sizeof(integer));
    e_wsfe();
    io___1247.ciunit = eqlun_1.nttyol;
    s_wsfe(&io___1247);
    do_fio(&c__1, (char *)&(*irfp), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

L999:
    return 0;
} /* writr_ */

/* wterm    last revised 11/25/87 by tjw */
/* *wterm f77 check, ok 07/08/87 by tjw */
/* Subroutine */ int wterm_(doublereal *apx, doublereal *w, doublereal *tempk,
	 doublereal *press, doublereal *rconst, char *usolx, integer *iopt4, 
	integer *jsol, integer *nxt, integer *iktmax, integer *iapxmx, 
	integer *noutpt, integer *nttyo, ftnlen usolx_len)
{
    /* Format strings */
    static char fmt_1735[] = "(3x,\002mineral \002,a18,3x,\002was assumed id"
	    "eal - inconsistent\002,\002 with data in apx array - fix this"
	    "\002)";
    static char fmt_1736[] = "(3x,\002mineral \002,a18,3x,\002was assumed id"
	    "eal because no data\002,\002 was found in apx array - fix thi"
	    "s\002)";
    static char fmt_100[] = "(3x,\002jsol value \002,i2,\002 for mineral "
	    "\002,a18,\002 is invalid\002)";

    /* System generated locals */
    integer apx_dim1, apx_offset, w_dim1, w_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, k, nx;
    static doublereal sum;
    static integer inote;

    /* Fortran I/O blocks */
    static cilist io___1252 = { 0, 0, 0, fmt_1735, 0 };
    static cilist io___1253 = { 0, 0, 0, fmt_1736, 0 };
    static cilist io___1255 = { 0, 0, 0, fmt_100, 0 };



/*   new version to combine eq3 and eq6 versions */
/*   wlb 8/23/85 */

/*     this routine computes the w(i,nx) array, which contains */
/*     the coefficients for the excess free energy function of */
/*     solid solutions.  if non-zero coefficients are */
/*     lacking, the solid solution reduces to an ideal solution */
/*     and the jsol value is changed to zero to reflect this. */

/*   apx       array of non-ideal mixing parameters */
/*   iopt4     if iop4=0 no solid solutions are considered */
/*   jsol      array holding mixing model code */
/*   usolx     name of solid solution */
/*   w         array of non-ideal mixing parameters calculated from */
/*             apx array */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* eqlun.h */


    /* Parameter adjustments */
    usolx -= usolx_len;
    --jsol;
    w_dim1 = *iktmax;
    w_offset = 1 + w_dim1;
    w -= w_offset;
    apx_dim1 = *iapxmx;
    apx_offset = 1 + apx_dim1;
    apx -= apx_offset;

    /* Function Body */
    if (*iopt4 <= 0) {
	goto L999;
    }
    i__1 = *nxt;
    for (nx = 1; nx <= i__1; ++nx) {
	sum = 0.f;
	inote = 0;
	i__2 = *iapxmx;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    sum += apx[i__ + nx * apx_dim1] * apx[i__ + nx * apx_dim1];
/* L15: */
	}

/*     flag user if inconsistent ss model/data in data file */

	if (sum == 0. && jsol[nx] != 0) {
	    inote = 1;
	}
	if (sum != 0. && jsol[nx] == 0) {
	    inote = 2;
	}
	if (inote == 2) {
	    io___1252.ciunit = *noutpt;
	    s_wsfe(&io___1252);
	    do_fio(&c__1, usolx + nx * usolx_len, usolx_len);
	    e_wsfe();
	}
	if (inote == 1) {
	    io___1253.ciunit = *noutpt;
	    s_wsfe(&io___1253);
	    do_fio(&c__1, usolx + nx * usolx_len, usolx_len);
	    e_wsfe();
	}

/*     reset jsol to 0 if no data present */
	if (sum <= 0.) {
	    jsol[nx] = 0;
	}
/* L20: */

/*     initialize w values to zero */

	i__2 = *iktmax;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    w[i__ + nx * w_dim1] = 0.f;
/* L25: */
	}

/* L30: */
    }

    i__1 = *nxt;
    for (nx = 1; nx <= i__1; ++nx) {
	k = jsol[nx];
	if (k == 0) {
	    goto L90;
	} else if (k == 1) {

/*     binary solution, third-order maclaurin expansion */
/*     original pathi solid solution model. */

	    w[nx * w_dim1 + 1] = apx[nx * apx_dim1 + 1];
	    w[nx * w_dim1 + 2] = apx[nx * apx_dim1 + 2];
	    w[nx * w_dim1 + 3] = apx[nx * apx_dim1 + 3];
	    w[nx * w_dim1 + 1] = -w[nx * w_dim1 + 2] / 2.f - w[nx * w_dim1 + 
		    3] / 6.f;

	} else if (k == 2) {

/*     binary solution, parabolic maclaurin expansion */

	    w[nx * w_dim1 + 1] = apx[nx * apx_dim1 + 1];

	} else if (k == 3) {

/*     binary solution, cubic maclaurin (p,t dependent) */

	    w[nx * w_dim1 + 1] = apx[nx * apx_dim1 + 1] + apx[nx * apx_dim1 + 
		    2] * *tempk + apx[nx * apx_dim1 + 3] * *press;
	    w[nx * w_dim1 + 2] = apx[nx * apx_dim1 + 4] + apx[nx * apx_dim1 + 
		    5] * *tempk + apx[nx * apx_dim1 + 6] * *press;

	} else if (k == 4) {

/*     binary solution, guggenheim polynomial (t dependent) */

	    w[nx * w_dim1 + 1] = apx[nx * apx_dim1 + 1] + apx[nx * apx_dim1 + 
		    2] * *tempk + apx[nx * apx_dim1 + 3] * *tempk * *tempk;
	    w[nx * w_dim1 + 2] = apx[nx * apx_dim1 + 4] + apx[nx * apx_dim1 + 
		    5] * *tempk + apx[nx * apx_dim1 + 6] * *tempk * *tempk;
	    w[nx * w_dim1 + 3] = apx[nx * apx_dim1 + 7] + apx[nx * apx_dim1 + 
		    8] * *tempk + apx[nx * apx_dim1 + 9] * *tempk * *tempk;

	} else if (k == 5) {

/*     ternary regular solution (see prigogine and defay, p. 257) */
/*     w(1,nx)=alpha12  w(2,nx)=alpha13  w(3,nx)=alpha23 */

	    w[nx * w_dim1 + 1] = apx[nx * apx_dim1 + 1];
	    w[nx * w_dim1 + 2] = apx[nx * apx_dim1 + 2];
	    w[nx * w_dim1 + 3] = apx[nx * apx_dim1 + 3];

	} else if (k == 6) {

/*   newton et al plagioclase model (gca vol 44 p. 933, 1980) */
/*   1 - albite; 2 - anorthite */
	    w[nx * w_dim1 + 1] = apx[nx * apx_dim1 + 1];
	    w[nx * w_dim1 + 2] = apx[nx * apx_dim1 + 2];
	} else {
	    io___1255.ciunit = *noutpt;
	    s_wsfe(&io___1255);
	    do_fio(&c__1, (char *)&jsol[nx], (ftnlen)sizeof(integer));
	    do_fio(&c__1, usolx + nx * usolx_len, usolx_len);
	    e_wsfe();
	}

L90:
	;
    }

L999:
    return 0;
} /* wterm_ */

/* zsrt     last revised 10/27/87 by tjw */
/* *zsrt f77 check, ok 07/08/87 by tjw */
/* Subroutine */ int zsrt_(doublereal *z__, integer *nst, integer *jsflag, 
	integer *izm, integer *izoff)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer ns;
    static doublereal zn, zmin, zmax;
    static integer izmin, izmax;


/*     input  z      charge array */
/*            nst    number of species */
/*            jsflag status array */
/*                    if value .ge. 2, species is not present */
/*     output izm    max(izmax,-izmin) */
/*            izoff  1-izmin  (the zero offset) */

/*  ************************************************ */


/*             CHANGES TO ALLOW MACHINE */
/*             GENERALITY WITH EQPTR71.F77 */


/*     include 'eqlibr136.inc' */


/*  ************************************************ */

/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* ---------------------------------------------------------------------- */

/*     find min and max charge values and associated constants */

    /* Parameter adjustments */
    --jsflag;
    --z__;

    /* Function Body */
    zmax = -100.f;
    zmin = 100.f;

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	if (jsflag[ns] >= 2) {
	    goto L10;
	}
	zn = z__[ns];
	if (zn < zmin) {
	    zmin = zn;
	}
	if (zn > zmax) {
	    zmax = zn;
	}
L10:
	;
    }

    izmin = i_dnnt(&zmin);
    izmax = i_dnnt(&zmax);

/*     zero offset */

    *izoff = 1 - izmin;

    *izm = -izmin;
    if (izmax > *izm) {
	*izm = izmax;
    }

    return 0;
} /* zsrt_ */



/* DAS      SUBROUTINE FDATE(UPASS) */
/* DAS      CHARACTER*24 UPASS */
/* DAS      CHARACTER*9 UDAT */
/* DAS      CHARACTER*8 UTIM */
/* DAS      CHARACTER*1 UZERO,UCOL */
/* DAS      DATA UZERO/'0'/,UCOL/':'/ */
/* DAS      CALL DATE(UDAT) */
/* DAS      CALL TIME(UTIM) */
/* DAS      DO 10 I=1,24 */
/* DAS   10 UPASS(I:I)=UZERO */
/* DAS      UPASS(9:10)=UDAT(1:2) */
/* DAS      UPASS(5:7)=UDAT(4:6) */
/* DAS      UPASS(23:24)=UDAT(8:9) */
/* DAS      UPASS(12:13)=UTIM(1:2) */
/* DAS      UPASS(15:16)=UTIM(4:5) */
/* DAS      UPASS(18:19)=UTIM(7:8) */
/* DAS      UPASS(14:14)=UCOL */
/* DAS      UPASS(17:17)=UCOL */
/* DAS      RETURN */
/* DAS      END */
/* arrset   last revised 12/15/87 by tjw */
/* *arrset f77 rewrite 02/24/87 by tjw */
/* Subroutine */ int arrset_(doublereal *ars, doublereal *amn, doublereal *
	ags, doublereal *cess, doublereal *cdrs, doublereal *cdrm, doublereal 
	*cdrg, doublereal *csts, doublereal *cstor, doublereal *xbarlg, 
	doublereal *lamlg, doublereal *aa, doublereal *gm, doublereal *csp, 
	doublereal *concbs, doublereal *cte, doublereal *mte, doublereal *
	zvclg1, doublereal *cxistq, doublereal *conc, doublereal *conclg, 
	doublereal *act, doublereal *actlg, doublereal *glg, doublereal *glgx,
	 doublereal *xlks, doublereal *xlkm, doublereal *xlkg, doublereal *
	mwtss, doublereal *z__, doublereal *zsq2, doublereal *titr, 
	doublereal *azero, doublereal *hydn, doublereal *rhs, doublereal *ee, 
	doublereal *res, doublereal *al10, doublereal *rconst, doublereal *
	xlkeh, doublereal *ehfac, doublereal *om, doublereal *omlg, 
	doublereal *omi, doublereal *tempc, doublereal *tempk, doublereal *
	press, doublereal *xi, doublereal *xisteq, doublereal *fo2lg, 
	doublereal *eh, doublereal *dshm, doublereal *shm, doublereal *shmlim,
	 char *uzvec1, char *uspec, char *umin, char *ugas, char *ujtype, 
	integer *nend, integer *jflag, integer *nsp, integer *nspec, integer *
	jsflag, integer *jsort, integer *iindx1, integer *ibswx, integer *
	ibasis, integer *ir, integer *kill, integer *iopt1, integer *iopt2, 
	integer *iopg1, integer *iodb1, integer *iodb2, integer *ntpr, 
	integer *iacion, integer *iebal, integer *nhydr, integer *nchlor, 
	integer *nct, integer *nsb, integer *nsb1, integer *nsq, integer *
	nsqb, integer *nsq1, integer *nst, integer *nrst, integer *nmt, 
	integer *ngt, integer *nxt, integer *kct, integer *ksb, integer *ksq, 
	integer *kebal, integer *kdim, integer *kmax, integer *khydr, integer 
	*nctmax, integer *nsqmax, integer *nsqmx1, integer *nstmax, integer *
	iktmax, integer *narxmx, integer *ntprmx, integer *ker, integer *
	nloop, integer *noutpt, integer *nttyo, logical *qhydth, logical *
	qpt4, logical *qbswx, logical *qbassw, ftnlen uzvec1_len, ftnlen 
	uspec_len, ftnlen umin_len, ftnlen ugas_len, ftnlen ujtype_len)
{
    /* Initialized data */

    static char udef[24] = "defining equation       ";
    static char ueb[24] = "elect. balance          ";
    static char ueh[24] = "eh                      ";
    static char ured[24] = "aq redox reaction       ";
    static char ublank[8] = "        ";
    static char ukilld[8] = "killed  ";
    static integer nlopmx = 12;
    static integer nplim = 4;
    static integer ncylim = 7;
    static integer nttyi = 5;
    static logical qcfrac = TRUE_;

    /* Format strings */
    static char fmt_2[] = "(\002 --- arrset ---\002)";
    static char fmt_33[] = "(5x,\002nloop= \002,i2)";
    static char fmt_30[] = "(/16x,\002--- iteration matrix structure ---\002"
	    ",//)";
    static char fmt_1050[] = "(/,\002 iteration variables\002)";
    static char fmt_1052[] = "(1x,2i5,3x,a24,3x,a24)";
    static char fmt_1054[] = "(\002  kill this variable? (y/n)\002)";
    static char fmt_1056[] = "(a8)";
    static char fmt_65[] = "(12x,2i5,3x,a24,3x,a24,2x,a8)";
    static char fmt_75[] = "(/1x)";
    static char fmt_1060[] = "(\002 variables killed are in columns\002)";
    static char fmt_1062[] = "(3x,i3)";
    static char fmt_1064[] = "(3x,\002none\002)";
    static char fmt_3[] = "(10x,\002npass= \002,i2)";
    static char fmt_6[] = "(12x,\002xi = \002,1pe12.5)";
    static char fmt_4[] = "(12x,\002xisteq= \002,1pe12.5)";
    static char fmt_7[] = "(12x,\002shm= \002,1pe12.5,\002, dshm= \002,1pe12"
	    ".5)";
    static char fmt_742[] = "(15x,\002ncycle= \002,i2)";
    static char fmt_3247[] = "(/10x,\002--- pre-iteration summary ---\002,//"
	    "3x,\002krow  iindx1  name     zvclg1       zvec1      beta\002,/)"
	    ;
    static char fmt_3250[] = "(1x,2i5,2x,a8,2x,f10.4,2x,1pe12.5,2x,1pe12.5)";
    static char fmt_642[] = "(/5x,\002--- mass balance dominants ---\002,/)";
    static char fmt_643[] = "(3x,\002master species\002,14x,\002dominant spe"
	    "cies\002,/)";
    static char fmt_644[] = "(2x,a24,5x,a24)";
    static char fmt_647[] = "(//5x,\002--- factors for continued fraction"
	    "\002,\002 corrections ---\002,/)";
    static char fmt_648[] = "(3x,\002master species\002,14x,\002bfac\00210x"
	    ",\002efac\002,/)";
    static char fmt_649[] = "(2x,a24,3x,1pe12.5,3x,1pe12.5)";
    static char fmt_553[] = "(/11x,\002--- candidate basis switches ---\002,"
	    "/)";
    static char fmt_557[] = "(6x,a12,\002 could be switched with \002,a12)";
    static char fmt_559[] = "(/1x)";
    static char fmt_573[] = "(/11x,\002--- auto basis switches ---\002,/)";
    static char fmt_554[] = "(6x,a24,\002 will be switched with \002,a24)";
    static char fmt_420[] = "(\002 * error- auto basis switching error in lo"
	    "op \002,i2,\002 (arrset)\002)";
    static char fmt_155[] = "(17x,\002betamx= \002,1pe12.5,/17x,\002bbig="
	    " \002,1pe12.5,\002, ubbig= \002,a24,/17x,\002bneg= \002,1pe12.5"
	    ",\002, ubneg= \002,a24)";
    static char fmt_162[] = "(7x,\002bxi= \002,1pe12.5)";
    static char fmt_163[] = "(7x,\002bxistq= \002,1pe12.5)";
    static char fmt_164[] = "(7x,\002bshm= \002,1pe12.5)";
    static char fmt_177[] = "(5x,\002bgamx= \002,1pe12.5,\002, ubgamx= \002,"
	    "a24)";
    static char fmt_210[] = "(\002 * note- optimization ended outside reques"
	    "ted\002,\002 limits (arrset)\002,/)";
    static char fmt_190[] = "(\002 --- arrset - optimization ended within re"
	    "quested\002,\002 limits ---\002,/)";

    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, cess_dim1, cess_offset, cdrs_dim1,
	     cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, cdrg_offset, 
	    csts_dim1, csts_offset, xbarlg_dim1, xbarlg_offset, lamlg_dim1, 
	    lamlg_offset, aa_dim1, aa_offset, gm_dim1, gm_offset, nend_dim1, 
	    nend_offset, i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_rsfe(cilist *), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer ns, ns1, ns2;
    static doublereal clg;
    static integer jfl;
    extern /* Subroutine */ int gxi_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *);
    static doublereal xic;
    extern doublereal tlg_(doublereal *);
    static doublereal bxi;
    static logical qxi;
    static char uyn[8];
    static logical qgm, qpr1, qpr2, qpr3;
    static char ust1[24], ust2[24], ust3[8];
    static doublereal bdum;
    static integer kcol;
    static doublereal cdum, shmc, zdel;
    extern /* Subroutine */ int gshm_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *);
    static integer idum;
    static char udum[8];
    static integer nerr;
    extern doublereal texp_(doublereal *);
    static integer krow;
    extern /* Subroutine */ int gszm_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *)
	    ;
    static doublereal ddum, ldum, clgo, cnew, clim, abxi, bshm;
    static integer iodb3;
    static doublereal xlim, xdel, bdum1;
    static integer jflp1;
    static doublereal xdel1, zdum1, zdum2;
    extern /* Subroutine */ int gbfac_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *);
    static doublereal abshm, dshmc;
    extern /* Subroutine */ int betas_(logical *, logical *);
    static doublereal xdiff, pgrid;
    static logical qdshm, qabsw;
    static doublereal sigza;
    extern /* Subroutine */ int gcsts_(doublereal *, doublereal *, doublereal 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, logical *);
    static doublereal tally;
    static integer npass;
    extern /* Subroutine */ int ncmpx_(void);
    static doublereal sigzc, sigzm, sigzi, xinew;
    extern /* Subroutine */ int gcoeff_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), betgam_(
	    char *, doublereal *, doublereal *, doublereal *, integer *, 
	    doublereal *, char *, ftnlen, ftnlen);
    static integer ncycle;
    static doublereal cecorr;
    static integer kkndex[100];
    extern /* Subroutine */ int molint_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, doublereal *), 
	    arrsim_(integer *, integer *, integer *, doublereal *, doublereal 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, doublereal *, char *, char *, char *, 
	    integer *, integer *, integer *, doublereal *, doublereal *, 
	    ftnlen, ftnlen, ftnlen), gabswx_(doublereal *, integer *, integer 
	    *), autosw_(integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, char *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, logical *, logical *, 
	    logical *, ftnlen, ftnlen), evdatr_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *);
    static doublereal bxecor, xecorr;
    static logical qtestc, qxistq;
    extern /* Subroutine */ int gxistq_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *);
    static doublereal xistqc, bxistq, abxstq;
    static logical qtestp;

    /* Fortran I/O blocks */
    static cilist io___1278 = { 0, 0, 0, fmt_2, 0 };
    static cilist io___1282 = { 0, 0, 0, fmt_33, 0 };
    static cilist io___1283 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___1285 = { 0, 0, 0, fmt_1050, 0 };
    static cilist io___1290 = { 0, 0, 0, fmt_1052, 0 };
    static cilist io___1291 = { 0, 0, 0, fmt_1054, 0 };
    static cilist io___1292 = { 0, 0, 0, fmt_1056, 0 };
    static cilist io___1295 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___1296 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1297 = { 0, 0, 0, fmt_1060, 0 };
    static cilist io___1299 = { 0, 0, 0, fmt_1062, 0 };
    static cilist io___1300 = { 0, 0, 0, fmt_1064, 0 };
    static cilist io___1307 = { 0, 0, 0, fmt_3, 0 };
    static cilist io___1308 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___1309 = { 0, 0, 0, fmt_4, 0 };
    static cilist io___1310 = { 0, 0, 0, fmt_7, 0 };
    static cilist io___1312 = { 0, 0, 0, fmt_742, 0 };
    static cilist io___1314 = { 0, 0, 0, fmt_3247, 0 };
    static cilist io___1320 = { 0, 0, 0, fmt_3250, 0 };
    static cilist io___1321 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1322 = { 0, 0, 0, fmt_642, 0 };
    static cilist io___1323 = { 0, 0, 0, fmt_643, 0 };
    static cilist io___1325 = { 0, 0, 0, fmt_644, 0 };
    static cilist io___1326 = { 0, 0, 0, fmt_647, 0 };
    static cilist io___1327 = { 0, 0, 0, fmt_648, 0 };
    static cilist io___1328 = { 0, 0, 0, fmt_649, 0 };
    static cilist io___1329 = { 0, 0, 0, fmt_553, 0 };
    static cilist io___1331 = { 0, 0, 0, fmt_557, 0 };
    static cilist io___1332 = { 0, 0, 0, fmt_559, 0 };
    static cilist io___1333 = { 0, 0, 0, fmt_573, 0 };
    static cilist io___1334 = { 0, 0, 0, fmt_554, 0 };
    static cilist io___1335 = { 0, 0, 0, fmt_559, 0 };
    static cilist io___1337 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___1338 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___1347 = { 0, 0, 0, fmt_155, 0 };
    static cilist io___1357 = { 0, 0, 0, fmt_162, 0 };
    static cilist io___1363 = { 0, 0, 0, fmt_163, 0 };
    static cilist io___1367 = { 0, 0, 0, fmt_164, 0 };
    static cilist io___1369 = { 0, 0, 0, fmt_177, 0 };
    static cilist io___1372 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___1373 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___1374 = { 0, 0, 0, fmt_190, 0 };
    static cilist io___1375 = { 0, 0, 0, fmt_210, 0 };



/*     build the iindx1 array.  set up the matrix structure for newton- */
/*     raphson and provide starting values for the iteration variables. */
/*     ker is returned 0 if all went well, as 1 if the input constraints */
/*     look suspiciously poor, and as 2 if they look really bad. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */



/* -------------------------------------------------------------------- */
/* bt.h */





    /* Parameter adjustments */
    --csp;
    --concbs;
    --cte;
    --mte;
    --zvclg1;
    --cxistq;
    --conc;
    --conclg;
    --act;
    --actlg;
    --glg;
    --glgx;
    --xlks;
    --xlkm;
    --xlkg;
    --mwtss;
    --z__;
    --zsq2;
    --titr;
    --azero;
    --hydn;
    --rhs;
    --ee;
    --res;
    uzvec1 -= uzvec1_len;
    uspec -= uspec_len;
    umin -= umin_len;
    ugas -= ugas_len;
    ujtype -= ujtype_len;
    --jflag;
    --nsp;
    --nspec;
    --jsflag;
    --jsort;
    --iindx1;
    --ibswx;
    --ibasis;
    --ir;
    --kill;
    gm_dim1 = *kmax;
    gm_offset = 1 + gm_dim1;
    gm -= gm_offset;
    aa_dim1 = *kmax;
    aa_offset = 1 + aa_dim1;
    aa -= aa_offset;
    cess_dim1 = *nctmax;
    cess_offset = 1 + cess_dim1;
    cess -= cess_offset;
    csts_dim1 = *nsqmax;
    csts_offset = 1 + csts_dim1;
    csts -= csts_offset;
    cdrg_dim1 = *nsqmx1;
    cdrg_offset = 1 + cdrg_dim1;
    cdrg -= cdrg_offset;
    cdrm_dim1 = *nsqmx1;
    cdrm_offset = 1 + cdrm_dim1;
    cdrm -= cdrm_offset;
    cdrs_dim1 = *nsqmx1;
    cdrs_offset = 1 + cdrs_dim1;
    cdrs -= cdrs_offset;
    nend_dim1 = *iktmax;
    nend_offset = 1 + nend_dim1;
    nend -= nend_offset;
    lamlg_dim1 = *iktmax;
    lamlg_offset = 1 + lamlg_dim1;
    lamlg -= lamlg_offset;
    xbarlg_dim1 = *iktmax;
    xbarlg_offset = 1 + xbarlg_dim1;
    xbarlg -= xbarlg_offset;
    ags_dim1 = *narxmx;
    ags_dim2 = *ntprmx;
    ags_offset = 1 + ags_dim1 * (1 + ags_dim2);
    ags -= ags_offset;
    amn_dim1 = *narxmx;
    amn_dim2 = *ntprmx;
    amn_offset = 1 + amn_dim1 * (1 + amn_dim2);
    amn -= amn_offset;
    ars_dim1 = *narxmx;
    ars_dim2 = *ntprmx;
    ars_offset = 1 + ars_dim1 * (1 + ars_dim2);
    ars -= ars_offset;

    /* Function Body */

/*   nlopmx is the maximum number of auto basis switching loops. */

/*   nplim is the maximum number of passes in the estimation.  passes */
/*   refine estimates of ionic strength, activity of water, activity */
/*   coefficients, and (if hydration theory is used) sigma(hm). */

/*   ncylim is the maximum number of cycles in the estimation.  cycles */
/*   may occur within passes, and are used to refine estimates of */
/*   species concentrations before new estimates of ionic strength, etc., */
/*   are made. */


/*     qcfrac = flag to routine betas to get efac array for continued */
/*       fraction calculations */


/* ---------------------------------------------------------------------- */
/*     Added here to save having to wrap function separately: */
    gcsts_(&csts[8 * csts_offset / 8], &cdrs[8 * cdrs_offset / 8], cstor, &
	    ibasis[1], &jsflag[1], &jflag[1], nhydr, nct, nsb, nsb1, nsq, 
	    nsq1, nst, nsqmax, nsqmx1, nstmax, qbassw);

    qabsw = *iopt2 >= 1;

    qpr1 = *iodb2 >= 1;
    qpr2 = *iodb2 >= 2;
    qpr3 = *iodb2 >= 3;
    if (qpr1) {
	io___1278.ciunit = *noutpt;
	s_wsfe(&io___1278);
	e_wsfe();
    }

/*     set up the structure of the iteration matrix.  its contents may be */
/*     altered subsequently by automatic basis switching. */

/*       build the iindx1 array, find ksq,kdim,... */

    *kebal = 0;
    iindx1[1] = 1;
    s_copy(uzvec1 + uzvec1_len, uspec + uspec_len, uzvec1_len, uspec_len);
    *ksq = 1;
    kkndex[0] = 0;

    i__1 = *nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	kkndex[ns - 1] = 0;
	jfl = jflag[ns];
	if (jfl != -1 && jfl != 30) {
	    ++(*ksq);
	    iindx1[*ksq] = ns;
	    s_copy(uzvec1 + *ksq * uzvec1_len, uspec + ns * uspec_len, 
		    uzvec1_len, (ftnlen)8);
	    if (ns == *nsb) {
		*ksb = *ksq;
	    }
	    if (ns == *nhydr) {
		*khydr = *ksq;
	    }
	}
/* L20: */
    }
    *kct = *ksb - 1;
    *kdim = *ksq;

/*     the label below is a return point after an automatic basis switch */

/*     nloop is the loop counter for auto basis switching */

    *nloop = -1;

L25:
    ++(*nloop);
    if (qpr1) {
	io___1282.ciunit = *noutpt;
	s_wsfe(&io___1282);
	do_fio(&c__1, (char *)&(*nloop), (ftnlen)sizeof(integer));
	e_wsfe();
    }

/*     get stoichiometric coefficients for the equivalent */
/*     stoichiometric ionic strength. */

/*     print the iteration matrix structure.  execute any killer options. */
/*     killer options are set only once.  they carry through after any */
/*     automatic basis switching. */

    if (qpr1) {
	io___1283.ciunit = *noutpt;
	s_wsfe(&io___1283);
	e_wsfe();
    }
    if (iodb3 != 0) {
	io___1285.ciunit = *nttyo;
	s_wsfe(&io___1285);
	e_wsfe();
    }

    i__1 = *kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	ns = iindx1[kcol];
	s_copy(ust2, udef, (ftnlen)24, (ftnlen)24);
	if (kcol <= *ksq) {
	    s_copy(ust1, uspec + ns * uspec_len, (ftnlen)24, uspec_len);
	    jfl = jflag[ns];
	    if (ns == *iebal) {
		*kebal = kcol;
		s_copy(ust2, ueb, (ftnlen)24, (ftnlen)24);
	    } else if (ns == *nsb) {
		if (*iopt1 == -1 || *iopt1 == -2) {
		    s_copy(ust2, ueh, (ftnlen)24, (ftnlen)24);
		} else if (*iopt1 == 1) {
		    s_copy(ust2, ured, (ftnlen)24, (ftnlen)24);
		}
	    } else {
		jflp1 = jfl + 1;
		s_copy(ust2, ujtype + jflp1 * ujtype_len, (ftnlen)24, 
			ujtype_len);
	    }
	}

	if (iodb3 != 0 && *nloop == 0) {
	    io___1290.ciunit = *nttyo;
	    s_wsfe(&io___1290);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ust1, (ftnlen)24);
	    do_fio(&c__1, ust2, (ftnlen)24);
	    e_wsfe();
	    io___1291.ciunit = *nttyo;
	    s_wsfe(&io___1291);
	    e_wsfe();
	    io___1292.ciunit = nttyi;
	    s_rsfe(&io___1292);
	    do_fio(&c__1, uyn, (ftnlen)8);
	    e_rsfe();
	    kill[kcol] = 0;
	    if (s_cmp(uyn, "y     ", (ftnlen)8, (ftnlen)6) == 0) {
		kill[kcol] = 1;
	    }
	}

	if (qpr1) {
	    s_copy(ust3, ublank, (ftnlen)8, (ftnlen)8);
	    if (iodb3 != 0 && kill[kcol] >= 1) {
		s_copy(ust3, ukilld, (ftnlen)8, (ftnlen)8);
	    }
	    io___1295.ciunit = *noutpt;
	    s_wsfe(&io___1295);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ust1, (ftnlen)24);
	    do_fio(&c__1, ust2, (ftnlen)24);
	    do_fio(&c__1, ust3, (ftnlen)8);
	    e_wsfe();
	}

/* L70: */
    }

    if (qpr1) {
	io___1296.ciunit = *noutpt;
	s_wsfe(&io___1296);
	e_wsfe();
    }

/*     echo killer option data */

    if (iodb3 > 0) {
	io___1297.ciunit = *nttyo;
	s_wsfe(&io___1297);
	e_wsfe();
	tally = 0.;
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    if (kill[kcol] != 0) {
		tally += 1;
		io___1299.ciunit = *nttyo;
		s_wsfe(&io___1299);
		do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
/* L232: */
	}

	if (tally == 0.) {
	    io___1300.ciunit = *nttyo;
	    s_wsfe(&io___1300);
	    e_wsfe();
	}
    }

/*     set up preliminary estimates of basis species concentrations */

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	conc[ns] = 0.f;
/* L823: */
    }

    i__1 = *ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	if (kcol == *ksb) {
	    goto L800;
	}
	ns = iindx1[kcol];
	jfl = jflag[ns];
	if (jfl <= 9) {

/*       concentrations, total and free */

	    conc[ns] = csp[ns];
	} else if (jfl <= 12) {

/*       alkalinity */

	    conc[ns] = csp[ns] / titr[ns];
	} else if (jfl == 16) {

/*       activity */

	    cdum = csp[ns];
	    conc[ns] = texp_(&cdum);
	} else {

/*       all other cases */

	    conc[ns] = 1e-7f;
	}
L800:
	;
    }

/*     calculate a starting value for the ionic strength, treating */
/*     the calculated charge imbalance among the basis species as */
/*     the equivalent of a monovalent ion. */

    gxi_(&zsq2[1], &conc[1], &jsort[1], nst, &xic);
    zdel = 0.f;
    i__1 = *nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	zdel += z__[ns] * conc[ns];
/* L805: */
    }
    *xi = xic + abs(zdel) * .5f;

/*     calculate the equivalent stoichiometric ionic strength */

    *xisteq = 0.f;
    if (*iopg1 == 0 && *iacion > 0) {
	*xisteq = csp[*iacion];
    }

/*     calculate the dshm factor for hydration theory. */
/*     'dshm' = 1 - ( (sigma)i mi)/omega ) */

    if (*qhydth) {
	gshm_(&hydn[1], &conc[1], &jsort[1], nst, &shmc, &dshmc);
	if (shmc > *shmlim) {
	    shmc = *shmlim;
	    dshmc = 1.f - shmc / *om;
	}
	*shm = shmc;
	*dshm = dshmc;
    }

/*     calculate the activity coefficients */

    if (*qpt4) {
	molint_(&conc[1], nsq, nst, &cdrs[cdrs_offset], nsqmx1, nsb, &c__3, &
		concbs[1]);
    }
    gcoeff_(&conc[1], &z__[1], &zsq2[1], &azero[1], &hydn[1], &concbs[1], &
	    glgx[1], xi, xisteq, dshm, tempc, press, &jsflag[1], &jsort[1], 
	    iacion, nsb, nst, nsq, nhydr, nchlor);

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	glg[ns] = glgx[ns];
/* L202: */
    }

/*     load the master species part of the conclg array. */

    i__1 = *ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	ns = iindx1[kcol];
	cdum = conc[ns];
	conclg[ns] = tlg_(&cdum);
/* L910: */
    }

/*     npass is the pass counter */

    npass = 0;

/*     the label below is a return point for subsequent passes.  a pass */
/*     is an adjustment for xi, xisteq, dshm, the activity of water, */
/*     and the activity coefficients of the solute species. */

L3210:
    ++npass;
    if (npass > 1) {
	qabsw = *iopt2 >= 1;
    }

    if (qpr1) {
	io___1307.ciunit = *noutpt;
	s_wsfe(&io___1307);
	do_fio(&c__1, (char *)&npass, (ftnlen)sizeof(integer));
	e_wsfe();
	io___1308.ciunit = *noutpt;
	s_wsfe(&io___1308);
	do_fio(&c__1, (char *)&(*xi), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (*iopg1 == 0) {
	    io___1309.ciunit = *noutpt;
	    s_wsfe(&io___1309);
	    do_fio(&c__1, (char *)&(*xisteq), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*qhydth) {
	    io___1310.ciunit = *noutpt;
	    s_wsfe(&io___1310);
	    do_fio(&c__1, (char *)&(*shm), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*dshm), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }

/*   ncycle is the cycle counter */

    ncycle = 0;

/*     the label below is a return point for beginning a new cycle. */
/*     a cycle is an adjustment within a pass to get basis species */
/*     concentration estimates in range to make a reasonable new estimate */
/*     of ionic strength. */

L3220:
    ++ncycle;
    if (qpr1) {
	io___1312.ciunit = *noutpt;
	s_wsfe(&io___1312);
	do_fio(&c__1, (char *)&ncycle, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    *ker = 0;
    if (ncycle > 1) {
	qabsw = FALSE_;
    }

/*     make starting estimates for the iteration variables (the */
/*     elements of the zvclg1 array).  the iteration variables represent */
/*     base ten logarithms of molalities and oxygen fugacity. */

    zvclg1[1] = *omlg;
    i__1 = *ksq;
    for (krow = 2; krow <= i__1; ++krow) {
	ns = iindx1[krow];
	jfl = jflag[ns];
	if (jfl < 16) {
	    zvclg1[krow] = conclg[ns];
	} else if (jfl == 16) {
	    cdum = csp[ns] - glgx[ns];
	    zvclg1[krow] = cdum;
	}
/* L95: */
    }

    if (*iopt1 == 0) {
	zvclg1[*ksb] = *fo2lg;
    }

/*        make starting estimates that must be evaluated simultaneously. */
/*        these include all cases of equilibrium constraints and also */
/*        that in which log fo2 is constrained by eh, pe-, or a redox */
/*        couple. */

    arrsim_(kkndex, &npass, ker, eh, ehfac, nsb, nsq, nsq1, nsqb, nsqmax, 
	    nsqmx1, nhydr, iktmax, &glgx[1], uspec + uspec_len, umin + 
	    umin_len, ugas + ugas_len, &jflag[1], &iindx1[1], &nend[
	    nend_offset], &xbarlg[xbarlg_offset], &lamlg[lamlg_offset], 
	    uspec_len, umin_len, ugas_len);

    ncmpx_();
    betas_(&qcfrac, &qabsw);

/*     print values of master iteration variables */

    if (qpr2) {
	io___1314.ciunit = *noutpt;
	s_wsfe(&io___1314);
	e_wsfe();
	i__1 = *kdim;
	for (krow = 1; krow <= i__1; ++krow) {
	    idum = iindx1[krow];
	    zdum1 = zvclg1[krow];
	    zdum2 = texp_(&zdum1);
	    s_copy(udum, uzvec1 + krow * uzvec1_len, (ftnlen)8, uzvec1_len);
	    bdum = bt_1.beta[krow - 1];
	    io___1320.ciunit = *noutpt;
	    s_wsfe(&io___1320);
	    do_fio(&c__1, (char *)&krow, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
	    do_fio(&c__1, udum, (ftnlen)8);
	    do_fio(&c__1, (char *)&zdum1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&zdum2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&bdum, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L745: */
	}
	io___1321.ciunit = *noutpt;
	s_wsfe(&io___1321);
	e_wsfe();
    }

/*     if the same species dominates more than one mass balance, */
/*     then the continued fraction algorithm can be applied to only */
/*     one of the associated master species.  otherwise, oscillatory */
/*     behavior will occur.  in each set of mass balances with a common */
/*     dominating species, find the mass balance with the greatest */
/*     residual and complete the calculation of its bfac factor by */
/*     doing the appropriate exponentiation.  set bfac to unity for */
/*     the others in the set. */

    if (qpr2) {
	io___1322.ciunit = *noutpt;
	s_wsfe(&io___1322);
	e_wsfe();
	io___1323.ciunit = *noutpt;
	s_wsfe(&io___1323);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns = iindx1[kcol];
	    ns2 = bt_1.nfac[kcol - 1];
	    if (ns2 > 0) {
		io___1325.ciunit = *noutpt;
		s_wsfe(&io___1325);
		do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
		do_fio(&c__1, uspec + ns2 * uspec_len, uspec_len);
		e_wsfe();
	    }
/* L645: */
	}
    }

    gbfac_(bt_1.nfac, bt_1.beta, bt_1.efac, ksq, bt_1.bfac);

    if (qpr3 && ! (*qbswx)) {
	io___1326.ciunit = *noutpt;
	s_wsfe(&io___1326);
	e_wsfe();
	io___1327.ciunit = *noutpt;
	s_wsfe(&io___1327);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    if (bt_1.bfac[kcol - 1] > 0.f) {
		ns = iindx1[kcol];
		io___1328.ciunit = *noutpt;
		s_wsfe(&io___1328);
		do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
		do_fio(&c__1, (char *)&bt_1.bfac[kcol - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&bt_1.efac[kcol - 1], (ftnlen)sizeof(
			doublereal));
		e_wsfe();
	    }
/* L650: */
	}
    }

/*     in automatic basis switching mode (iopt2.ge.1), try to first */
/*     reduce the magntiude of large positive mass balance residuals */
/*     by making one or more basis switches. */

    if (! (*qbswx)) {
	goto L3275;
    }
    if (*nloop >= nlopmx) {
	goto L3275;
    }

    if (qpr2) {
	io___1329.ciunit = *noutpt;
	s_wsfe(&io___1329);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns1 = iindx1[kcol];
	    ns2 = ibswx[kcol];
	    if (ns2 > 0) {
		io___1331.ciunit = *noutpt;
		s_wsfe(&io___1331);
		do_fio(&c__1, uspec + ns1 * uspec_len, uspec_len);
		do_fio(&c__1, uspec + ns2 * uspec_len, uspec_len);
		e_wsfe();
	    }
/* L570: */
	}
	io___1332.ciunit = *noutpt;
	s_wsfe(&io___1332);
	e_wsfe();
    }

/*     resolve any conflicts in candidate basis switches */

    gabswx_(bt_1.beta, ksq, &ibswx[1]);

    if (qpr1) {
	io___1333.ciunit = *noutpt;
	s_wsfe(&io___1333);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns1 = iindx1[kcol];
	    ns2 = ibswx[kcol];
	    if (ns2 > 0) {
		io___1334.ciunit = *noutpt;
		s_wsfe(&io___1334);
		do_fio(&c__1, uspec + ns1 * uspec_len, uspec_len);
		do_fio(&c__1, uspec + ns2 * uspec_len, uspec_len);
		e_wsfe();
	    }
/* L575: */
	}
	io___1335.ciunit = *noutpt;
	s_wsfe(&io___1335);
	e_wsfe();
    }

/*     make the basis switches called for */

    autosw_(&c__3, &ars[ars_offset], &amn[amn_offset], &ags[ags_offset], &
	    cess[cess_offset], &cdrs[cdrs_offset], &cdrm[cdrm_offset], &cdrg[
	    cdrg_offset], &cxistq[1], &mwtss[1], &z__[1], &zsq2[1], &titr[1], 
	    &azero[1], &hydn[1], &csp[1], uzvec1 + uzvec1_len, uspec + 
	    uspec_len, &jflag[1], &jsflag[1], &iindx1[1], &ibswx[1], &ibasis[
	    1], &nsp[1], iopg1, iacion, iebal, nhydr, nchlor, nct, nsb, nsq, 
	    nsq1, nst, nrst, nmt, ngt, ksq, nctmax, nsqmx1, narxmx, ntprmx, &
	    nerr, noutpt, nttyo, qhydth, qpt4, qbassw, uzvec1_len, uspec_len);

    if (nerr > 0) {
	io___1337.ciunit = *nttyo;
	s_wsfe(&io___1337);
	do_fio(&c__1, (char *)&(*nloop), (ftnlen)sizeof(integer));
	e_wsfe();
	io___1338.ciunit = *noutpt;
	s_wsfe(&io___1338);
	do_fio(&c__1, (char *)&(*nloop), (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     recompute the log k values for aqueous dissocation reactions */
/*     and mineral and gas dissolution reactions */

    evdatr_(tempc, tempk, press, &pgrid, &ars[ars_offset], &amn[amn_offset], &
	    ags[ags_offset], &xlks[1], &xlkm[1], &xlkg[1], rconst, nrst, nst, 
	    nmt, ngt, nxt, ntpr, narxmx, ntprmx, noutpt, nttyo);

/*     recompute the csts array of stoichiometric factors.  this is */
/*     calculated from the cdrs array of reaction coefficients. */

    gcsts_(&csts[csts_offset], &cdrs[cdrs_offset], cstor, &ibasis[1], &jsflag[
	    1], &jflag[1], nhydr, nct, nsb, nsb1, nsq, nsq1, nst, nsqmax, 
	    nsqmx1, nstmax, qbassw);

    goto L25;

L3275:

/*     calculate the electrical balance residual. */

    bxecor = 0.f;
    xecorr = 0.f;
    if (*kebal > 0) {
	cecorr = -bt_1.alpha[*kebal - 1] / z__[*iebal];
	xecorr = zsq2[*iebal] * cecorr;
	gszm_(&z__[1], &conc[1], &jsort[1], nst, &sigzc, &sigza, &sigzm, &
		sigzi);
	bxecor = abs(xecorr) / sigzm;
    }

/*     test the balance residuals for mass and alkalinity to see if */
/*     another cycle should be made before attempting to make an improved */
/*     estimate of the ionic strength. */

    if (qpr1) {
	io___1347.ciunit = *noutpt;
	s_wsfe(&io___1347);
	do_fio(&c__1, (char *)&bt_1.betamx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&bt_1.bbig, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, btc_1.ubbig, (ftnlen)24);
	do_fio(&c__1, (char *)&bt_1.bneg, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, btc_1.ubneg, (ftnlen)24);
	e_wsfe();
    }

    qtestc = bt_1.bbig <= .5f && bt_1.bneg >= -.1f;
    qtestc = qtestc && bxecor <= .25f;

    if (qtestc) {
	goto L3240;
    }
    if (ncycle >= ncylim) {
	goto L3240;
    }

/*     make improvements in concentration estimates and go back for */
/*     another cycle.  the algorithm employed here is the modified */
/*     continued fraction method proposed by t. j. wolery in */
/*     memo gcc-85-1.  the bfac array is calculated in routine betas. */

    i__1 = *ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	ns = iindx1[kcol];
	if (ns == *iebal) {
	    goto L830;
	}
	jfl = jflag[ns];
	bdum = bt_1.beta[kcol - 1];
	bdum1 = bdum + 1.f;
	if (jfl == 0) {
	    ddum = bt_1.bfac[kcol - 1];
	    if (bdum1 <= 0.f) {
		ddum = 1e-20f;
	    }
	    ldum = tlg_(&ddum);
	    ldum = min(ldum,20.);
	    conclg[ns] -= ldum;
	} else if (jfl == 10 || jfl == 12) {
	    if (bdum1 <= 0.f) {
		bdum1 = 1e-20f;
	    }
	    ldum = tlg_(&bdum1);
	    ldum = min(ldum,20.);
	    conclg[ns] -= ldum;
	}
L830:
	;
    }

    if (*iebal > 0) {
	clgo = conclg[*iebal];
	cnew = conc[*iebal] + cecorr;
	if (cecorr >= 0.f) {
	    clg = tlg_(&cnew);
	    clim = clgo + 2.f;
	    conclg[*iebal] = min(clg,clim);
	} else {
	    cnew = max(cnew,0.);
	    clg = tlg_(&cnew);
	    clim = clgo - 2.f;
	    conclg[*iebal] = max(clg,clim);
	}
    }

/*     go back for another cycle */

    goto L3220;

/*     the cycles for the current pass have been completed.  test to */
/*     see if another pass should be made. */

L3240:
    gxi_(&zsq2[1], &conc[1], &jsort[1], nst, &xic);
    bxi = (xic - *xi) / *xi;
    if (qpr1) {
	io___1357.ciunit = *noutpt;
	s_wsfe(&io___1357);
	do_fio(&c__1, (char *)&bxi, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    abxi = abs(bxi);
    qxi = abxi <= .1f;

    qxistq = TRUE_;
    if (*iacion > 0) {
	gxistq_(&cxistq[1], &conc[1], &jsort[1], nst, &xistqc);
	bxistq = (xistqc - *xisteq) / *xisteq;
	if (qpr1) {
	    io___1363.ciunit = *noutpt;
	    s_wsfe(&io___1363);
	    do_fio(&c__1, (char *)&bxistq, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	abxstq = abs(bxistq);
	qxistq = abxstq <= .1f;
    }

    qdshm = TRUE_;
    if (*qhydth) {
	gshm_(&hydn[1], &conc[1], &jsort[1], nst, &shmc, &dshmc);
	if (shmc > *shmlim) {
	    shmc = *shmlim;
	    dshmc = 1.f - shmc / *om;
	}
	bshm = (shmc - *shm) / *shm;
	if (qpr1) {
	    io___1367.ciunit = *noutpt;
	    s_wsfe(&io___1367);
	    do_fio(&c__1, (char *)&bshm, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	abshm = abs(bshm);
	qdshm = abshm <= .1f;
    }

    if (*qpt4) {
	molint_(&conc[1], nsq, nst, &cdrs[cdrs_offset], nsqmx1, nsb, &c__3, &
		concbs[1]);
    }
    gcoeff_(&conc[1], &z__[1], &zsq2[1], &azero[1], &hydn[1], &concbs[1], &
	    glgx[1], xi, xisteq, dshm, tempc, press, &jsflag[1], &jsort[1], 
	    iacion, nsb, nst, nsq, nhydr, nchlor);

    betgam_(uspec + uspec_len, &conc[1], &glgx[1], &glg[1], nst, &bt_1.bgamx, 
	    btc_1.ubgamx, uspec_len, (ftnlen)24);

    if (qpr1) {
	io___1369.ciunit = *noutpt;
	s_wsfe(&io___1369);
	do_fio(&c__1, (char *)&bt_1.bgamx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, btc_1.ubgamx, (ftnlen)24);
	e_wsfe();
    }
    qgm = bt_1.bgamx <= .1f;

    qtestp = qxi && qxistq && qdshm && qgm;

/*     are pass criteria satisfied? */

    if (! qtestp) {

/*       pass criteria are not satisfied */

/*       test for maximum no. of passes */

	if (npass >= nplim) {

/*         quit- optimization ended outside requested limits */
/*         because pass requirements were not satisfied */

	    io___1372.ciunit = *noutpt;
	    s_wsfe(&io___1372);
	    e_wsfe();
	    io___1373.ciunit = *nttyo;
	    s_wsfe(&io___1373);
	    e_wsfe();
	    goto L999;
	}

/*       set up for another pass */

	goto L10;
    }

/*     are cycle criteria satisfied? */

    if (qtestc) {

/*       optimization achieved within requested limits */

	io___1374.ciunit = *noutpt;
	s_wsfe(&io___1374);
	e_wsfe();
	goto L999;

/*     pass criteria are satisfied, but the cycle criteria are not */

    } else if (npass <= 2) {

/*     try another pass */

	goto L10;
    } else {

/*       quit- optimization ended outside requested limits */
/*       because cycle requirements were not met */

	if (qpr1) {
	    io___1375.ciunit = *noutpt;
	    s_wsfe(&io___1375);
	    e_wsfe();
	}
	goto L999;
    }

/*     make new estimates of the ionic strength, activity of water, */
/*     activity coefficients, and, where appropriate, the equivalent */
/*     stoichiometric ionic strength or sigma(hm). */

/*     include a contribution from the electrical imbalance in the new */
/*     ionic strength estimate if electrical balance is a constraint. */
/*     xecorr is the value of the full correction.  use one-half of this */
/*     to prevent oscillation.  if xecorr is negative, limit it to twenty */
/*     per cent of xic, the latest calculated value of ionic strength. */

L10:
    xlim = 22.f;
    xdel = xecorr * .5f;
    if (xdel < 0.f) {
	xdel1 = xic * -.2f;
	xdel = max(xdel,xdel1);
    }
    xinew = xic + xdel;
    xdiff = xinew - *xi;
    xdel = xdiff / *xi;
    *xi = xinew;
    *xi = min(*xi,xlim);

    if (*iopg1 == 0 && *iacion > 0) {
	xdel = xistqc - *xisteq;
	if (xdel < 0.f) {
	    xdel *= -.2f;
	    xdel = max(xdel,xdel1);
	}
	*xisteq += xdel;
	*xisteq = min(*xisteq,xlim);
    }

    if (*qhydth) {
	if (shmc > *shmlim) {
	    shmc = *shmlim;
	    dshmc = 1.f - shmc / *om;
	}
	*shm = shmc;
	*dshm = dshmc;
    }

    if (*qpt4) {
	molint_(&conc[1], nsq, nst, &cdrs[cdrs_offset], nsqmx1, nsb, &c__3, &
		concbs[1]);
    }
    gcoeff_(&conc[1], &z__[1], &zsq2[1], &azero[1], &hydn[1], &concbs[1], &
	    glgx[1], xi, xisteq, dshm, tempc, press, &jsflag[1], &jsort[1], 
	    iacion, nsb, nst, nsq, nhydr, nchlor);

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	glg[ns] = glgx[ns];
/* L205: */
    }

/*     go back for another pass */

    goto L3210;

L999:
    return 0;
} /* arrset_ */

/* arrsim   last revised 12/11/87 by tjw */
/* Subroutine */ int arrsim_(integer *kkndex, integer *npass, integer *ker, 
	doublereal *eh, doublereal *ehfac, integer *nsb, integer *nsq, 
	integer *nsq1, integer *nsqb, integer *nsqmax, integer *nsqmx1, 
	integer *nhydr, integer *iktmax, doublereal *glgx, char *uspec, char *
	umin, char *ugas, integer *jflag, integer *iindx1, integer *nend, 
	doublereal *xbarlg, doublereal *lamlg, ftnlen uspec_len, ftnlen 
	umin_len, ftnlen ugas_len)
{
    /* Initialized data */

    static char ublank[24] = "                        ";
    static char ueh[24] = "eh                      ";
    static char ured[24] = "aq. redox reaction      ";
    static char uaqeq[24] = "aq. equilibrium         ";
    static logical qfalse = FALSE_;

    /* Format strings */
    static char fmt_532[] = "(7x,\002--- structure for simultaneous evaluati"
	    "on of\002,\002 starting estimates ---\002,//)";
    static char fmt_65[] = "(4x,2i5,3x,a24,/20x,a24,3x,a24)";
    static char fmt_75[] = "(/1x)";
    static char fmt_717[] = "(/10x,\002--- zvclg1, glgx values ---\002,/)";
    static char fmt_720[] = "(2x,2i5,3x,a6,3x,f10.4,3x,f10.4)";
    static char fmt_606[] = "(/10x,\002----- matrix -----\002,/)";
    static char fmt_607[] = "(2x,10(f7.2,2x))";
    static char fmt_686[] = "(/10x,\002----- right-hand-side vector -----"
	    "\002,/)";
    static char fmt_687[] = "(2x,2i5,3x,e13.6)";
    static char fmt_695[] = "(\002 --- msolvr (matrix solver) failed (arrs"
	    "im)\002)";
    static char fmt_697[] = "(/\002 * trouble- the speciation model appears "
	    "to be\002,\002 singular (arrsim)\002,/7x,\002probable apparent p"
	    "hase rule violation\002,/)";
    static char fmt_727[] = "(/\002 --- \002,a12,\002 has a required concent"
	    "ration\002,\002 near \002,g12.5,\002 molal ---\002)";
    static char fmt_737[] = "(/\002 --- reconsider your choice of input\002"
	    ",\002 constraints ---\002)";
    static char fmt_729[] = "(6x,\002this run may crash because of\002,\002 "
	    "poor choice of input constraints\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer ik, ng, nm, ns, nx, ns1, ns2, isb, ksc, nse, nsc, ier, isq,
	     nrs;
    static logical qpr3;
    static char ust1[24], ust2[24], ust3[24];
    static integer icol;
    static doublereal awlg;
    static integer idum, kdum;
    static char udum[8];
    static doublereal gdum;
    static integer ndum;
    static doublereal rdum;
    static integer irow, krow;
    static doublereal cdum;
    static integer kcol;
    static doublereal ddum;
    static integer nerr;
    static doublereal zdum;
    extern doublereal texp_(doublereal *);
    static doublereal zdum1;
    static integer jfdum, ihydr;
    extern /* Subroutine */ int prreac_(doublereal *, char *, char *, integer 
	    *, integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    static integer jjndex[100];
    static char unamsp[24];
    extern /* Subroutine */ int msolvr_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, logical *, logical *);

    /* Fortran I/O blocks */
    static cilist io___1394 = { 0, 0, 0, fmt_532, 0 };
    static cilist io___1401 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___1402 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1403 = { 0, 0, 0, fmt_717, 0 };
    static cilist io___1409 = { 0, 0, 0, fmt_720, 0 };
    static cilist io___1410 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1420 = { 0, 0, 0, fmt_606, 0 };
    static cilist io___1421 = { 0, 0, 0, fmt_607, 0 };
    static cilist io___1422 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1428 = { 0, 0, 0, fmt_686, 0 };
    static cilist io___1429 = { 0, 0, 0, fmt_687, 0 };
    static cilist io___1430 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1432 = { 0, 0, 0, fmt_695, 0 };
    static cilist io___1433 = { 0, 0, 0, fmt_697, 0 };
    static cilist io___1434 = { 0, 0, 0, fmt_697, 0 };
    static cilist io___1436 = { 0, 0, 0, fmt_717, 0 };
    static cilist io___1438 = { 0, 0, 0, fmt_720, 0 };
    static cilist io___1439 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___1442 = { 0, 0, 0, fmt_727, 0 };
    static cilist io___1443 = { 0, 0, 0, fmt_737, 0 };
    static cilist io___1444 = { 0, 0, 0, fmt_729, 0 };



/*     this routine supports arrset.  it makes starting estimates of */
/*     concentrations that must be evaluated simultaneously. */
/*     these include all cases of equilibrium constraints and also that */
/*     in which log fo2 is constrained by eh, pe-, or a redox couple. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */


/* -------------------------------------------------------------------- */
/* blank.h */
/* -------------------------------------------------------------------- */
/* ki.h */
/* -------------------------------------------------------------------- */
/* nn.h */

/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* op2.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* zg.h */
/* -------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */




    /* Parameter adjustments */
    lamlg -= 21;
    xbarlg -= 21;
    nend -= 21;
    --iindx1;
    --jflag;
    ugas -= ugas_len;
    umin -= umin_len;
    uspec -= uspec_len;
    --glgx;
    --kkndex;

    /* Function Body */

/* ---------------------------------------------------------------------- */

    qpr3 = op2_1.iodb2 >= 3;

/*           build a structure for a matrix equation. */

    isq = 0;
    isb = 0;
    ihydr = 0;

    i__1 = ki_1.ksq;
    for (krow = 2; krow <= i__1; ++krow) {
	ns = iindx1[krow];
	jfdum = jflag[ns];
	if (jfdum == 19) {
	    goto L500;
	}
	if (jfdum == 20) {
	    goto L500;
	}
	if (jfdum == 21) {
	    goto L500;
	}
	if (jfdum == 27) {
	    goto L500;
	}
	goto L510;

L500:
	++isq;
	jjndex[isq - 1] = ns;
	kkndex[ns] = 1;
	if (ns != *nhydr) {
	    goto L530;
	}
	ihydr = isq;
	goto L530;

L510:
	if (ns != *nsb) {
	    goto L530;
	}
	if (op_1.iopt1 == 0) {
	    goto L530;
	}
	++isq;
	isb = isq;
	jjndex[isq - 1] = ns;
	kkndex[ns] = 1;
L530:
	;
    }
    if (isq <= 0) {
	goto L740;
    }

    if (! qpr3) {
	goto L570;
    }
    io___1394.ciunit = un_1.noutpt;
    s_wsfe(&io___1394);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	ns1 = jjndex[irow - 1];
	s_copy(ust1, uspec + ns1 * uspec_len, (ftnlen)24, uspec_len);
	s_copy(ust3, ublank, (ftnlen)24, (ftnlen)24);
	if (ns1 != *nsb) {
	    goto L561;
	}
	if (ww_1.nsp[ns1 - 1] == 0) {
	    goto L535;
	}

L561:
	jfdum = jflag[ns1];
	if (jfdum != 27) {
	    goto L562;
	}
	s_copy(ust2, uaqeq, (ftnlen)24, (ftnlen)24);
	goto L560;

L562:
	i__2 = *nsqb;
	for (ns = 1; ns <= i__2; ++ns) {
	    ns2 = ww_1.nspec[ns - 1];
	    if (ns1 == ns2) {
		goto L564;
	    }
/* L563: */
	}

L564:
	s_copy(ust2, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24, (ftnlen)24);
	s_copy(ust3, wwc_1.uphas2 + (ns - 1) * 24, (ftnlen)24, (ftnlen)24);
	goto L560;

L535:
	if (op_1.iopt1 < 0) {
	    goto L540;
	}
	s_copy(ust2, ured, (ftnlen)24, (ftnlen)24);
	goto L560;

L540:
	s_copy(ust2, ueh, (ftnlen)24, (ftnlen)24);

L560:
	io___1401.ciunit = un_1.noutpt;
	s_wsfe(&io___1401);
	do_fio(&c__1, (char *)&irow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	do_fio(&c__1, ust1, (ftnlen)24);
	do_fio(&c__1, ust2, (ftnlen)24);
	do_fio(&c__1, ust3, (ftnlen)24);
	e_wsfe();
/* L565: */
    }

    io___1402.ciunit = un_1.noutpt;
    s_wsfe(&io___1402);
    e_wsfe();
    io___1403.ciunit = un_1.noutpt;
    s_wsfe(&io___1403);
    e_wsfe();

    i__1 = ki_1.ksq;
    for (krow = 1; krow <= i__1; ++krow) {
	idum = iindx1[krow];
	kdum = kkndex[idum];
	if (kdum >= 1) {
	    goto L567;
	}
	zdum1 = zg_1.zvclg1[krow - 1];
	s_copy(udum, nnu_1.uzvec1 + (krow - 1 << 3), (ftnlen)8, (ftnlen)8);
	gdum = glgx[idum];
	io___1409.ciunit = un_1.noutpt;
	s_wsfe(&io___1409);
	do_fio(&c__1, (char *)&krow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, (char *)&zdum1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&gdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
L567:
	;
    }

    io___1410.ciunit = un_1.noutpt;
    s_wsfe(&io___1410);
    e_wsfe();
L570:
/*           build the matrix. */

    i__1 = isq;
    for (icol = 1; icol <= i__1; ++icol) {
	i__2 = isq;
	for (irow = 1; irow <= i__2; ++irow) {
	    nn_1.aa[irow + icol * 100 - 101] = 0.f;
/* L575: */
	}
/* L580: */
    }

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	nse = jjndex[irow - 1];
	jfdum = jflag[nse];

	if (jfdum != 27) {
	    goto L583;
	}
	nrs = nse - *nsb;

	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    ns1 = jjndex[icol - 1];
	    nn_1.aa[irow + icol * 100 - 101] = _BLNK__1.cdrs[ns1 + nrs * 101 
		    - 102];
/* L582: */
	}

	nn_1.aa[irow + irow * 100 - 101] = _BLNK__1.cdrs[*nsq1 + nrs * 101 - 
		102];
	goto L605;

L583:
	if (jfdum != 19) {
	    goto L585;
	}
	nm = ww_1.nsp[nse - 1];

	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    ns1 = jjndex[icol - 1];
	    nn_1.aa[irow + icol * 100 - 101] = _BLNK__1.cdrm[ns1 + nm * 101 - 
		    102];
/* L584: */
	}
	goto L605;

L585:
	if (jfdum != 20) {
	    goto L590;
	}
	ndum = ww_1.nsp[nse - 1];
	ndum += -50000;
	nx = (integer) (ndum / 100.f);
	ik = ndum - nx * 100;
	nm = nend[ik + nx * 20];

	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    ns1 = jjndex[icol - 1];
	    nn_1.aa[irow + icol * 100 - 101] = _BLNK__1.cdrm[ns1 + nm * 101 - 
		    102];
/* L588: */
	}
	goto L605;

L590:
	if (jfdum != 21) {
	    goto L595;
	}
	ng = ww_1.nsp[nse - 1];

	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    ns1 = jjndex[icol - 1];
	    nn_1.aa[irow + icol * 100 - 101] = _BLNK__1.cdrg[ns1 + ng * 101 - 
		    102];
/* L594: */
	}
	goto L605;

L595:
	if (op_1.iopt1 >= 0) {
	    goto L600;
	}
	nn_1.aa[irow + isb * 100 - 101] = 1.f;
	if (ihydr <= 0) {
	    goto L605;
	}
	nn_1.aa[irow + ihydr * 100 - 101] = 4.f;
	goto L605;

L600:
	nsc = op_1.iopt1 + *nsb;

	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    ns1 = jjndex[icol - 1];
	    if (kkndex[ns1] <= 0) {
		goto L604;
	    }
	    if (ns1 != nsc) {
		goto L603;
	    }
	    nn_1.aa[irow + icol * 100 - 101] = _BLNK__1.cdrs[*nsq1 + 
		    op_1.iopt1 * 101 - 102];
	    goto L604;

L603:
	    nn_1.aa[irow + icol * 100 - 101] = _BLNK__1.cdrs[ns1 + op_1.iopt1 
		    * 101 - 102];
L604:
	    ;
	}

L605:
	;
    }

    if (! qpr3) {
	goto L609;
    }
    io___1420.ciunit = un_1.noutpt;
    s_wsfe(&io___1420);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	io___1421.ciunit = un_1.noutpt;
	s_wsfe(&io___1421);
	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    do_fio(&c__1, (char *)&nn_1.aa[irow + icol * 100 - 101], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
/* L608: */
    }

    io___1422.ciunit = un_1.noutpt;
    s_wsfe(&io___1422);
    e_wsfe();
L609:

/*           build the right-hand-side vector. */

    awlg = glgx[1];
    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	nse = jjndex[irow - 1];
	jfdum = jflag[nse];

	if (jfdum != 27) {
	    goto L615;
	}
	nrs = nse - *nsb;
	if (qpr3) {
	    s_copy(unamsp, uspec + nse * uspec_len, (ftnlen)24, uspec_len);
	    prreac_(_BLNK__1.cdrs, uspec + uspec_len, unamsp, &nrs, nsq, nsq1,
		     nsqmx1, &un_1.noutpt, uspec_len, (ftnlen)24);
	}

	rdum = xx_1.xlks[nrs - 1] - _BLNK__1.cdrs[nrs * 101 - 101] * awlg;

	i__2 = ki_1.ksq;
	for (krow = 2; krow <= i__2; ++krow) {
	    ns = iindx1[krow];
	    cdum = _BLNK__1.cdrs[ns + nrs * 101 - 102];
	    if (ns == nse) {
		cdum = _BLNK__1.cdrs[*nsq1 + nrs * 101 - 102];
	    }
	    rdum -= cdum * glgx[ns];
	    if (kkndex[ns] >= 1) {
		goto L612;
	    }
	    rdum -= cdum * zg_1.zvclg1[krow - 1];
L612:
	    ;
	}

	nn_1.rhs[irow - 1] = rdum;
	goto L690;

L615:
	if (jfdum != 19) {
	    goto L620;
	}
	nm = ww_1.nsp[nse - 1];
	if (qpr3) {
	    s_copy(unamsp, umin + nm * umin_len, (ftnlen)24, umin_len);
	    prreac_(_BLNK__1.cdrm, uspec + uspec_len, unamsp, &nm, nsq, nsq1, 
		    nsqmx1, &un_1.noutpt, uspec_len, (ftnlen)24);
	}

	rdum = xx_1.xlkm[nm - 1] - _BLNK__1.cdrm[nm * 101 - 101] * awlg;

	i__2 = ki_1.ksq;
	for (krow = 2; krow <= i__2; ++krow) {
	    ns = iindx1[krow];
	    cdum = _BLNK__1.cdrm[ns + nm * 101 - 102];
	    rdum -= cdum * glgx[ns];
	    if (kkndex[ns] >= 1) {
		goto L617;
	    }
	    rdum -= cdum * zg_1.zvclg1[krow - 1];
L617:
	    ;
	}

	nn_1.rhs[irow - 1] = rdum;
	goto L690;

L620:
	if (jfdum != 20) {
	    goto L640;
	}
	ndum = ww_1.nsp[nse - 1];
	ndum += -50000;
	nx = (integer) (ndum / 100.f);
	ik = ndum - nx * 100;
	nm = nend[ik + nx * 20];
	if (qpr3) {
	    s_copy(unamsp, umin + nm * umin_len, (ftnlen)24, umin_len);
	    prreac_(_BLNK__1.cdrm, uspec + uspec_len, unamsp, &nm, nsq, nsq1, 
		    nsqmx1, &un_1.noutpt, uspec_len, (ftnlen)24);
	}

	rdum = xx_1.xlkm[nm - 1] - _BLNK__1.cdrm[nm * 101 - 101] * awlg;
	rdum -= _BLNK__1.cdrm[*nsq1 + nm * 101 - 102] * (xbarlg[ik + nx * 20] 
		+ lamlg[ik + nx * 20]);

	i__2 = ki_1.ksq;
	for (krow = 2; krow <= i__2; ++krow) {
	    ns = iindx1[krow];
	    cdum = _BLNK__1.cdrm[ns + nm * 101 - 102];
	    rdum -= cdum * glgx[ns];
	    if (kkndex[ns] >= 1) {
		goto L630;
	    }
	    rdum -= cdum * zg_1.zvclg1[krow - 1];
L630:
	    ;
	}

	nn_1.rhs[irow - 1] = rdum;
	goto L690;

L640:
	if (jfdum != 21) {
	    goto L660;
	}
	ng = ww_1.nsp[nse - 1];
	if (qpr3) {
	    s_copy(unamsp, ugas + ng * ugas_len, (ftnlen)24, ugas_len);
	    prreac_(_BLNK__1.cdrg, uspec + uspec_len, unamsp, &ng, nsq, nsq1, 
		    nsqmx1, &un_1.noutpt, uspec_len, (ftnlen)24);
	}

	rdum = xx_1.xlkg[ng - 1] - _BLNK__1.cdrg[ng * 101 - 101] * awlg;
	rdum -= _BLNK__1.cdrg[*nsq1 + ng * 101 - 102] * ww_1.csp[nse - 1];

	i__2 = ki_1.ksq;
	for (krow = 2; krow <= i__2; ++krow) {
	    ns = iindx1[krow];
	    cdum = _BLNK__1.cdrg[ns + ng * 101 - 102];
	    rdum -= cdum * glgx[ns];
	    if (kkndex[ns] >= 1) {
		goto L650;
	    }
	    rdum -= cdum * zg_1.zvclg1[krow - 1];
L650:
	    ;
	}

	nn_1.rhs[irow - 1] = rdum;
	goto L690;

L660:
	if (op_1.iopt1 >= 0) {
	    goto L670;
	}
	rdum = *eh * 4.f / *ehfac;
	rdum = rdum + xx_1.xlkeh + awlg * 2.f;
	rdum -= glgx[*nhydr] * 4.f;
	if (kkndex[*nhydr] >= 1) {
	    goto L665;
	}
	rdum -= zg_1.zvclg1[ki_1.khydr - 1] * 4.f;
L665:
	nn_1.rhs[irow - 1] = rdum;
	goto L690;

L670:
	nsc = op_1.iopt1 + *nsb;
	rdum = xx_1.xlks[op_1.iopt1 - 1] - _BLNK__1.cdrs[op_1.iopt1 * 101 - 
		101] * awlg;

	i__2 = ki_1.ksq;
	for (ksc = 2; ksc <= i__2; ++ksc) {
	    ns1 = iindx1[ksc];
	    if (ns1 == nsc) {
		goto L680;
	    }
/* L675: */
	}

L680:
	cdum = _BLNK__1.cdrs[*nsq1 + op_1.iopt1 * 101 - 102];
	rdum -= cdum * glgx[nsc];
	if (kkndex[nsc] >= 1) {
	    goto L682;
	}
	rdum -= cdum * zg_1.zvclg1[ksc - 1];
L682:

	i__2 = ki_1.ksq;
	for (krow = 2; krow <= i__2; ++krow) {
	    if (krow == ksc) {
		goto L685;
	    }
	    ns = iindx1[krow];
	    cdum = _BLNK__1.cdrs[ns + op_1.iopt1 * 101 - 102];
	    rdum -= cdum * glgx[ns];
	    if (kkndex[ns] >= 1) {
		goto L685;
	    }
	    rdum -= cdum * zg_1.zvclg1[krow - 1];
L685:
	    ;
	}

	nn_1.rhs[irow - 1] = rdum;

L690:
	;
    }

    if (! qpr3) {
	goto L689;
    }
    io___1428.ciunit = un_1.noutpt;
    s_wsfe(&io___1428);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	idum = jjndex[irow - 1];
	rdum = nn_1.rhs[irow - 1];
	io___1429.ciunit = un_1.noutpt;
	s_wsfe(&io___1429);
	do_fio(&c__1, (char *)&irow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jjndex[irow - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nn_1.rhs[irow - 1], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
/* L688: */
    }

    io___1430.ciunit = un_1.noutpt;
    s_wsfe(&io___1430);
    e_wsfe();
L689:

/* L120: */

    msolvr_(nn_1.aa, nn_1.gm, nn_1.rhs, zg_1.del, nn_1.res, nn_1.ee, nn_1.ir, 
	    &isq, &ki_1.kmax, &ier, &qfalse, &qfalse);
    if (ier > 0) {
	io___1432.ciunit = un_1.noutpt;
	s_wsfe(&io___1432);
	e_wsfe();
	io___1433.ciunit = un_1.noutpt;
	s_wsfe(&io___1433);
	e_wsfe();
	io___1434.ciunit = un_1.nttyo;
	s_wsfe(&io___1434);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    icol = 0;

    i__1 = ki_1.ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	ns1 = iindx1[kcol];
	if (kkndex[ns1] <= 0) {
	    goto L715;
	}
	++icol;
	zg_1.zvclg1[kcol - 1] = zg_1.del[icol - 1];
L715:
	;
    }

    if (! qpr3) {
	goto L725;
    }
    io___1436.ciunit = un_1.noutpt;
    s_wsfe(&io___1436);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	idum = jjndex[irow - 1];
	ddum = zg_1.del[irow - 1];
	s_copy(udum, uspec + idum * uspec_len, (ftnlen)8, (ftnlen)8);
	io___1438.ciunit = un_1.noutpt;
	s_wsfe(&io___1438);
	do_fio(&c__1, (char *)&irow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, (char *)&ddum, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L723: */
    }

    io___1439.ciunit = un_1.noutpt;
    s_wsfe(&io___1439);
    e_wsfe();
L725:

/*     check possible effects of large concentrations resulting from */
/*     equilibrium constraints. */

    idum = isq;
    if (isb > 0) {
	--idum;
    }
    if (idum <= 0) {
	goto L740;
    }
    nerr = 0;

    i__1 = ki_1.ksq;
    for (krow = 1; krow <= i__1; ++krow) {
	ns = iindx1[krow];
	if (kkndex[ns] <= 0) {
	    goto L735;
	}
	if (ns == *nsb) {
	    goto L735;
	}
	zdum = zg_1.zvclg1[krow - 1];
	cdum = texp_(&zdum);
	if (cdum <= 20.f) {
	    goto L735;
	}
	*ker = 1;
	io___1442.ciunit = un_1.noutpt;
	s_wsfe(&io___1442);
	do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
	do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (*npass <= 1) {
	    goto L735;
	}
	if (cdum <= 100.f) {
	    goto L735;
	}
	++nerr;
L735:
	;
    }

    if (nerr <= 0) {
	goto L738;
    }
    io___1443.ciunit = un_1.noutpt;
    s_wsfe(&io___1443);
    e_wsfe();
    *ker = 2;
    goto L999;

L738:
    if (*ker == 1) {
	io___1444.ciunit = un_1.noutpt;
	s_wsfe(&io___1444);
	e_wsfe();
    }

L740:
L999:
    return 0;
} /* arrsim_ */

/* balcon   last revised 10/30/87 by tjw */
/* Subroutine */ int balcon_(doublereal *weight, integer *jrs, integer *krow)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer nsc, nrr, nrs;
    static doublereal dum2, sum1;
    static integer kcol;
    static doublereal stor1[679];


/*     local routine for  routine matrix */
/*     compute matrix entries for one of the following - */
/*      mass balance constraint */
/*      charge balance constraint */
/*      alkalinity balance constraint */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */



/* -------------------------------------------------------------------- */
/* blank.h */
/* ----------------------------------------------------------------------- */
/* jj.h */

/* -------------------------------------------------------------------- */
/* ka.h */
/* -------------------------------------------------------------------- */
/* ki.h */
/* -------------------------------------------------------------------- */
/* nn.h */

/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* st.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* ---------------------------------------------------------------------- */

/*      build stor1 array */

/* -------------------------------------------------------------------- */
/* eqlpp.h */
    /* Parameter adjustments */
    --jrs;
    --weight;

    /* Function Body */
    i__1 = tt_1.nrst;
    for (nrr = 1; nrr <= i__1; ++nrr) {
	stor1[nrr - 1] = 0.f;
	nrs = jrs[nrr];
	nsc = nrs + tt_1.nsb;
	if (nsc > tt_1.nsq) {
	    goto L32;
	}
	if (jj_1.jflag[nsc - 1] < 30) {
	    goto L35;
	}
L32:
	stor1[nrr - 1] = yy_1.conc[nsc - 1] * weight[nsc] / _BLNK__1.cdrs[
		tt_1.nsq1 + nrs * 101 - 102];
L35:
	;
    }

/*     first column currently unused */

/*     build columns 2 to ksq */

    i__1 = ki_1.ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	nsc = ka_1.iindx1[kcol - 1];
	dum2 = 0.f;

	i__2 = tt_1.nrst;
	for (nrr = 1; nrr <= i__2; ++nrr) {
	    nrs = jrs[nrr];
	    dum2 -= stor1[nrr - 1] * _BLNK__1.cdrs[nsc + nrs * 101 - 102];
/* L45: */
	}

	dum2 += weight[nsc] * yy_1.conc[nsc - 1];
	nn_1.aa[*krow + kcol * 100 - 101] = eqlpp_1.al10 * dum2;
/* L50: */
    }

    sum1 = 0.f;
    i__1 = tt_1.nrst;
    for (nrr = 1; nrr <= i__1; ++nrr) {
	nrs = jrs[nrr];
	sum1 -= stor1[nrr - 1] * _BLNK__1.cdrs[nrs * 101 - 101];
/* L40: */
    }

/* L999: */
    return 0;
} /* balcon_ */

/* betas    last revised 12/14/87 by tjw */
/* Subroutine */ int betas_(logical *qcfrac, logical *qabsw)
{
    /* Initialized data */

    static char unone[8] = "none    ";

    /* Format strings */
    static char fmt_1000[] = "(1x,\002illegal jflag value = \002,i5,\002 enc"
	    "ountered for \002,a18,\002 in betas\002)";
    static char fmt_1010[] = "(\002 * illegal jflag value, routine betas\002)"
	    ;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer ik, ng, nm, ns, nx, nsc, nse;
    static doublereal dum;
    static integer nss, nsj, nsi, nrs;
    static doublereal adum, ctot, bdum, sdum;
    static integer krow;
    extern /* Subroutine */ int gszm_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *)
	    ;
    static doublereal atot, cdum;
    static integer kcol;
    static doublereal fdum, cdum1, abeta, rconc;
    static integer jfdum;
    static doublereal sigzc, sigza, sigzm, sigzi;
    extern /* Subroutine */ int fdomsp_(integer *, integer *, doublereal *, 
	    doublereal *, integer *, integer *, doublereal *), fbassw_(
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, doublereal 
	    *);

    /* Fortran I/O blocks */
    static cilist io___1456 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___1457 = { 0, 0, 0, fmt_1010, 0 };



/*     this routine computes the newton-raphson residual functions. */
/*     the calling sequence of betas.f must be identical in form to */
/*     that of eq6's betaz.f, because both are referenced by eqlib's */
/*     nrstep.f via a dummy external. */

/*     input */
/*       qcfrac = flag to get bfac array for continued fraction */
/*         calculations in arrset */
/*       qabsw = flag to find choices for auto basis switching */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */


/* -------------------------------------------------------------------- */
/* blank.h */
/* -------------------------------------------------------------------- */
/* an.h */
/* -------------------------------------------------------------------- */
/* bt.h */


/* -------------------------------------------------------------------- */
/* cc.h */

/* -------------------------------------------------------------------- */
/* ee.h */

/* -------------------------------------------------------------------- */
/* gg.h */
/* -------------------------------------------------------------------- */
/* hh.h */
/* ----------------------------------------------------------------------- */
/* jj.h */

/* -------------------------------------------------------------------- */
/* ka.h */
/* -------------------------------------------------------------------- */
/* ki.h */
/* -------------------------------------------------------------------- */
/* nn.h */

/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* op1.h */
/* -------------------------------------------------------------------- */
/* op2.h */
/* -------------------------------------------------------------------- */
/* st.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* tu.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* uu.h */


/* -------------------------------------------------------------------- */
/* vv.h */
/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlgp.h */



/* -------------------------------------------------------------------- */
/* eqlpp.h */

/* ---------------------------------------------------------------------- */

    i__1 = ki_1.kdim;
    for (krow = 1; krow <= i__1; ++krow) {
	bt_1.alpha[krow - 1] = 0.f;
	bt_1.beta[krow - 1] = 0.f;
/* L2: */
    }

    i__1 = ki_1.ksq;
    for (krow = 1; krow <= i__1; ++krow) {
	ww_1.ibswx[krow - 1] = 0;
	bt_1.nfac[krow - 1] = 0;
	bt_1.bfac[krow - 1] = 1.f;
	bt_1.efac[krow - 1] = 1.f;
/* L3: */
    }
    ww_1.qbswx = FALSE_;

/*     first residual currently defined as zero */

/*     compute residuals 2 through ksq. */

/* - - - - - - - - - - begin main loop - - - - - - - - - - - - - - - - - */
    i__1 = ki_1.ksq;
    for (krow = 2; krow <= i__1; ++krow) {
	nse = ka_1.iindx1[krow - 1];
/*      test for charge balance */
	if (nse == ee_1.iebal) {
	    goto L30;
	}
	jfdum = jj_1.jflag[nse - 1];
/*      test for mineral equilibrium */
	if (jfdum == 19) {
	    goto L170;
	}
	if (jfdum == 20) {
	    goto L170;
	}
/*      test for gas equilibrium */
	if (jfdum == 21) {
	    goto L220;
	}
/*      test for log fo2 */
	if (nse == tt_1.nsb) {
	    goto L300;
	}
/*      test for mass balance */
	if (jfdum == 0) {
	    goto L5;
	}
/*      test for alkalinity balance */
	if (jfdum == 10) {
	    goto L70;
	}
/*      test for specified activity */
	if (jfdum == 16) {
	    goto L110;
	}
/*      test for aqueous homogeneous equilibrium */
	if (jfdum == 27) {
	    goto L700;
	}
/*      test for alkalinity balance */
	if (jfdum == 12) {
	    goto L70;
	}
/*      test for free concentration */
	if (jfdum == 4) {
	    goto L140;
	}
	io___1456.ciunit = un_1.noutpt;
	s_wsfe(&io___1456);
	do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___1457.ciunit = un_1.nttyo;
	s_wsfe(&io___1457);
	e_wsfe();
	s_stop("", (ftnlen)0);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*        mass balance. */

L5:
	i__2 = tt_1.nst;
	for (ns = 1; ns <= i__2; ++ns) {
	    st_1.store[ns - 1] = _BLNK__1.csts[nse + ns * 100 - 101];
/* L7: */
	}

	dum = 0.f;
	i__2 = tt_1.nst;
	for (nss = 1; nss <= i__2; ++nss) {
	    ns = st_1.jsort[nss - 1];
	    dum += st_1.store[ns - 1] * yy_1.conc[ns - 1];
/* L10: */
	}

	ctot = ww_1.csp[nse - 1];
	adum = dum - ctot;
	bt_1.alpha[krow - 1] = adum;
	bdum = adum / ctot;
	bt_1.beta[krow - 1] = bdum;

/*     find the species that makes the largest contribution to the */
/*     mass balance. */

	if (*qcfrac) {
	    fdomsp_(&nse, st_1.jsort, st_1.store, yy_1.conc, &tt_1.nst, &nsj, 
		    &sdum);
	    bt_1.efac[krow - 1] = 1.f / sdum;
	    bt_1.nfac[krow - 1] = nsj;
	}

/*     pick candidates for automatic basis switching.  this involves */
/*     a search similar to the one above, but with a variety of special */
/*     constraints.  the indices of candidates are stored in the array */
/*     ibswx. */

	if (*qabsw) {
	    ww_1.ibswx[krow - 1] = 0;
	    fbassw_(&nse, st_1.jsort, st_1.store, yy_1.conc, ww_1.ibasis, 
		    jj_1.jflag, &tt_1.nsb, &tt_1.nsq, &tt_1.nst, &nsi, 
		    uu_1.si);
	    if (nsi > 0) {
		rconc = yy_1.conc[nsi - 1] / yy_1.conc[nse - 1];
		if (rconc > 10.f) {
		    ww_1.ibswx[krow - 1] = nsi;
		    ww_1.qbswx = TRUE_;
		}
	    }
	}

	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        charge balance. */

L30:

	gszm_(ccp_1.z__, yy_1.conc, st_1.jsort, &tt_1.nst, &sigzc, &sigza, &
		sigzm, &sigzi);

	bt_1.alpha[krow - 1] = sigzi;
	bt_1.beta[krow - 1] = sigzi / sigzm;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        alkalinity balance. */

L70:
	dum = 0.f;

	i__2 = tt_1.nst;
	for (nss = 1; nss <= i__2; ++nss) {
	    ns = st_1.jsort[nss - 1];
	    dum += ccp_1.titr[ns - 1] * yy_1.conc[ns - 1];
/* L75: */
	}

	atot = ww_1.csp[nse - 1];
	adum = dum - atot;
	bt_1.alpha[krow - 1] = adum;
	bt_1.beta[krow - 1] = adum / atot;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        specified activity. */

L110:
	dum = yy_1.conclg[nse - 1] + ccp_1.glg[nse - 1] - ww_1.csp[nse - 1];
	bt_1.alpha[krow - 1] = dum;
	bt_1.beta[krow - 1] = dum;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        specified free concentration. */

L140:
	bt_1.alpha[krow - 1] = 0.f;
	bt_1.beta[krow - 1] = 0.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        specified mineral equilibrium. */

L170:
	nm = ww_1.nsp[nse - 1];
	cdum = 0.f;
	if (nm < 50000) {
	    goto L175;
	}
	nm += -50000;
	nx = (integer) (nm / 100.f);
	ik = nm - nx * 100;
	nm = an_1.nend[ik + nx * 20 - 21];
	cdum = -_BLNK__1.cdrm[tt_1.nsq1 + nm * 101 - 102] * (uu_1.xbarlg[ik + 
		nx * 20 - 21] + vv_1.lamlg[ik + nx * 20 - 21]);
L175:
	cdum = cdum + xx_1.xlkm[nm - 1] - _BLNK__1.cdrm[nm * 101 - 101] * 
		yy_1.actlg[0] - _BLNK__1.cdrm[nse + nm * 101 - 102] * 
		ccp_1.glg[nse - 1];
	if (nse == tt_1.nsb) {
	    goto L180;
	}
	cdum -= _BLNK__1.cdrm[tt_1.nsb + nm * 101 - 102] * cc_1.fo2lg;
L180:

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == ki_1.ksb) {
		goto L185;
	    }
	    if (kcol == krow) {
		goto L185;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    cdum -= _BLNK__1.cdrm[ns + nm * 101 - 102] * (yy_1.conclg[ns - 1] 
		    + ccp_1.glg[ns - 1]);
L185:
	    ;
	}

	cdum /= _BLNK__1.cdrm[nse + nm * 101 - 102];
	cdum1 = yy_1.conclg[nse - 1];
	if (nse == tt_1.nsb) {
	    cdum1 = cc_1.fo2lg;
	}
	dum = cdum - cdum1;
	bt_1.alpha[krow - 1] = dum;
	bt_1.beta[krow - 1] = dum;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        specified gas equilibrium. */

L220:
	ng = ww_1.nsp[nse - 1];
	cdum = -_BLNK__1.cdrg[tt_1.nsq1 + ng * 101 - 102] * ww_1.csp[nse - 1];
	cdum = cdum + xx_1.xlkg[ng - 1] - _BLNK__1.cdrg[ng * 101 - 101] * 
		yy_1.actlg[0] - _BLNK__1.cdrg[nse + ng * 101 - 102] * 
		ccp_1.glg[nse - 1];
	if (nse == tt_1.nsb) {
	    goto L225;
	}
	cdum -= _BLNK__1.cdrg[tt_1.nsb + ng * 101 - 102] * cc_1.fo2lg;
L225:

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == ki_1.ksb) {
		goto L230;
	    }
	    if (kcol == krow) {
		goto L230;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    cdum -= _BLNK__1.cdrg[ns + ng * 101 - 102] * (yy_1.conclg[ns - 1] 
		    + ccp_1.glg[ns - 1]);
L230:
	    ;
	}

	cdum /= _BLNK__1.cdrg[nse + ng * 101 - 102];
	cdum1 = yy_1.conclg[nse - 1];
	if (nse == tt_1.nsb) {
	    cdum1 = cc_1.fo2lg;
	}
	dum = cdum - cdum1;
	bt_1.alpha[krow - 1] = dum;
	bt_1.beta[krow - 1] = dum;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        specified aqueous homogeneous equilibrium. */

L700:
	nrs = nse - tt_1.nsb;
	cdum = xx_1.xlks[nrs - 1] - _BLNK__1.cdrs[nrs * 101 - 101] * 
		yy_1.actlg[0] - _BLNK__1.cdrs[tt_1.nsq1 + nrs * 101 - 102] * 
		ccp_1.glg[nse - 1];
	cdum -= _BLNK__1.cdrs[tt_1.nsb + nrs * 101 - 102] * cc_1.fo2lg;

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == ki_1.ksb) {
		goto L705;
	    }
	    if (kcol == krow) {
		goto L705;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    cdum -= _BLNK__1.cdrs[ns + nrs * 101 - 102] * (yy_1.conclg[ns - 1]
		     + ccp_1.glg[ns - 1]);
L705:
	    ;
	}

	cdum /= _BLNK__1.cdrs[tt_1.nsq1 + nrs * 101 - 102];
	cdum1 = yy_1.conclg[nse - 1];
	dum = cdum - cdum1;
	bt_1.alpha[krow - 1] = dum;
	bt_1.beta[krow - 1] = dum;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        compute the log fo2 residual. */

L300:
	if (op_1.iopt1 != 0) {
	    goto L310;
	}

/*           log fo2 directly specified */

	bt_1.alpha[krow - 1] = 0.f;
	bt_1.beta[krow - 1] = 0.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*           eh residual (note--an input p e- value has been */
/*           converted to an eh value by routine setup) */

L310:
	if (op_1.iopt1 >= 1) {
	    goto L330;
	}
	fdum = jj_1.eh * 4 / eqlpp_1.ehfac;
	fdum = fdum + xx_1.xlkeh + yy_1.actlg[0] * 2.f - (yy_1.conclg[
		tu_1.nhydr - 1] + ccp_1.glg[tu_1.nhydr - 1]) * 4.f;
	dum = fdum - cc_1.fo2lg;
	bt_1.alpha[krow - 1] = dum;
	bt_1.beta[krow - 1] = dum;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*           cross-linking (homogeneous aqueous redox) equilibrium. */

L330:
	fdum = xx_1.xlks[op_1.iopt1 - 1] - _BLNK__1.cdrs[op_1.iopt1 * 101 - 
		101] * yy_1.actlg[0];
	nsc = op_1.iopt1 + tt_1.nsb;
	fdum -= _BLNK__1.cdrs[tt_1.nsq1 + op_1.iopt1 * 101 - 102] * (
		yy_1.conclg[nsc - 1] + ccp_1.glg[nsc - 1]);

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == ki_1.ksb) {
		goto L335;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    fdum -= _BLNK__1.cdrs[ns + op_1.iopt1 * 101 - 102] * (yy_1.conclg[
		    ns - 1] + ccp_1.glg[ns - 1]);
L335:
	    ;
	}

	fdum /= _BLNK__1.cdrs[tt_1.nsb + op_1.iopt1 * 101 - 102];
	dum = fdum - cc_1.fo2lg;
	bt_1.alpha[krow - 1] = dum;
	bt_1.beta[krow - 1] = dum;

L400:
	;
    }
/* - - - - - - - - - - end main loop - - - - - - - - - - - - - - - - - - */

    bt_1.betamx = 0.f;
    bt_1.ibetmx = 0;

/*      test for kill debug option */

    if (op2_1.iodb3 <= 0) {
	goto L549;
    }
    i__1 = ki_1.kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	if (nn_1.kill[kcol - 1] == 0) {
	    goto L547;
	}
	bt_1.alpha[kcol - 1] = 0.f;
	bt_1.beta[kcol - 1] = 0.f;
L547:
	;
    }
L549:

/*     get characteristic residual parameters */
/*       betamx = value of largest abs(beta) */
/*       ibetmx = iindx1 of largest abs(beta) */
/*       bbig = value of largest (positive) mass balance residual */
/*       ubbig = name of corresponding species */
/*       bneg = value of largest (negative) mass balance residual */
/*       ubneg = name of corresponding species */

    i__1 = ki_1.kdim;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	abeta = (d__1 = bt_1.beta[kcol - 1], abs(d__1));
	if (abeta <= bt_1.betamx) {
	    goto L550;
	}
	bt_1.betamx = abeta;
	bt_1.ibetmx = kcol;
L550:
	;
    }

    bt_1.bbig = 0.f;
    bt_1.bneg = 0.f;
    s_copy(btc_1.ubbig, unone, (ftnlen)24, (ftnlen)8);
    s_copy(btc_1.ubneg, unone, (ftnlen)24, (ftnlen)8);
    i__1 = ki_1.ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	if (kcol == ki_1.ksb) {
	    goto L725;
	}
	ns = ka_1.iindx1[kcol - 1];
	if (ns == tu_1.nhydr) {
	    goto L725;
	}
	if (jj_1.jflag[ns - 1] > 15) {
	    goto L725;
	}
	bdum = bt_1.beta[kcol - 1];
	if (bdum < bt_1.bneg) {
	    bt_1.bneg = bdum;
	    s_copy(btc_1.ubneg, gg_1.uspec + (ns - 1) * 24, (ftnlen)24, (
		    ftnlen)24);
	} else if (bdum > bt_1.bbig) {
	    bt_1.bbig = bdum;
	    s_copy(btc_1.ubbig, gg_1.uspec + (ns - 1) * 24, (ftnlen)24, (
		    ftnlen)24);
	}
L725:
	;
    }

    return 0;
} /* betas_ */

/* ncmpx    last revised 10/30/87 by tjw */
/* Subroutine */ int ncmpx_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ns, nsc, nrs, nss, kcol;
    static doublereal cdum, awlg;
    extern doublereal texp_(doublereal *);
    static doublereal adum;
    extern /* Subroutine */ int qsort_(doublereal *, doublereal *, integer *, 
	    integer *, integer *, integer *);


/*     this routine computes all parameters necessary to write */
/*     the matrix from the zvclg1 array. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */


/* -------------------------------------------------------------------- */
/* blank.h */
/* -------------------------------------------------------------------- */
/* an.h */
/* -------------------------------------------------------------------- */
/* bt.h */


/* -------------------------------------------------------------------- */
/* cc.h */

/* -------------------------------------------------------------------- */
/* ee.h */

/* -------------------------------------------------------------------- */
/* gg.h */
/* -------------------------------------------------------------------- */
/* hh.h */
/* ----------------------------------------------------------------------- */
/* jj.h */

/* -------------------------------------------------------------------- */
/* ka.h */
/* -------------------------------------------------------------------- */
/* ki.h */
/* -------------------------------------------------------------------- */
/* nn.h */

/* -------------------------------------------------------------------- */
/* nx.h */

/* -------------------------------------------------------------------- */
/* oo.h */
/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* op1.h */
/* -------------------------------------------------------------------- */
/* op2.h */
/* ----------------------------------------------------------------- */
/* ps.h */
/* -------------------------------------------------------------------- */
/* st.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* uu.h */


/* -------------------------------------------------------------------- */
/* vv.h */
/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* zg.h */
/* -------------------------------------------------------------------- */
/* -------------------------------------------------------------------- */
/* eqlgp.h */


/* -------------------------------------------------------------------- */
/* eqldd.h */

/* ---------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* eqlpp.h */
    i__1 = ki_1.ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	ns = ka_1.iindx1[kcol - 1];
	cdum = zg_1.zvclg1[kcol - 1];
	yy_1.conclg[ns - 1] = cdum;
	yy_1.conc[ns - 1] = texp_(&cdum);
/* L5: */
    }

    yy_1.conclg[tt_1.nsb - 1] = -999.f;
    yy_1.conc[tt_1.nsb - 1] = 0.f;
    cc_1.fo2lg = zg_1.zvclg1[ki_1.ksb - 1];
    cc_1.fo2 = texp_(&cc_1.fo2lg);

    awlg = ccp_1.glg[0];
    yy_1.actlg[0] = awlg;
    yy_1.act[0] = texp_(&awlg);

    i__1 = ki_1.ksq;
    for (kcol = 2; kcol <= i__1; ++kcol) {
	ns = ka_1.iindx1[kcol - 1];
	adum = yy_1.conclg[ns - 1] + ccp_1.glg[ns - 1];
	yy_1.actlg[ns - 1] = adum;
	yy_1.act[ns - 1] = texp_(&adum);
/* L35: */
    }

    i__1 = tt_1.nst;
    for (nsc = tt_1.nsb1; nsc <= i__1; ++nsc) {
	if (ka_1.jsflag[nsc - 1] >= 2) {
	    goto L20;
	}
	if (nsc > tt_1.nsq) {
	    goto L10;
	}
	if (jj_1.jflag[nsc - 1] == 30) {
	    goto L10;
	}
	goto L20;

L10:
	nrs = nsc - tt_1.nsb;
	cdum = -xx_1.xlks[nrs - 1] + _BLNK__1.cdrs[nrs * 101 - 101] * awlg;
	cdum += _BLNK__1.cdrs[tt_1.nsb + nrs * 101 - 102] * cc_1.fo2lg;
	cdum += _BLNK__1.cdrs[tt_1.nsq1 + nrs * 101 - 102] * ccp_1.glg[nsc - 
		1];

	i__2 = tt_1.nsq;
	for (ns = 2; ns <= i__2; ++ns) {
	    adum = _BLNK__1.cdrs[ns + nrs * 101 - 102];
	    if (adum == 0.f) {
		goto L15;
	    }
	    if (ns == tt_1.nsb) {
		goto L15;
	    }
	    if (yy_1.conclg[ns - 1] > -999.f) {
		goto L12;
	    }
	    yy_1.conclg[nsc - 1] = -999.f;
	    goto L20;

L12:
	    cdum += adum * yy_1.actlg[ns - 1];
L15:
	    ;
	}

	cdum = -cdum / _BLNK__1.cdrs[tt_1.nsq1 + nrs * 101 - 102];
	yy_1.conclg[nsc - 1] = cdum;
	yy_1.conc[nsc - 1] = texp_(&cdum);
	adum = cdum + ccp_1.glg[nsc - 1];
	yy_1.actlg[nsc - 1] = adum;
	yy_1.act[nsc - 1] = texp_(&adum);
L20:
	;
    }

    qsort_(yy_1.conclg, st_1.csort, &tt_1.nst, st_1.jsort, st_1.istack, 
	    st_1.jstack);

    i__1 = tt_1.nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = st_1.jsort[nss - 1];
	st_1.csort[nss - 1] = yy_1.conc[ns - 1];
/* L25: */
    }

    return 0;
} /* ncmpx_ */

/* ndiagx   last revised 11/18/87 by tjw */
/* *created in f77 11/18/87 by tjw */
/* Subroutine */ int ndiagx_(doublereal *del, doublereal *screwd, integer *
	jflag, integer *iindx1, integer *idelmx, integer *iebal, integer *ksb,
	 integer *kebal, integer *khydr, integer *kcarb, integer *nhydr)
{
    /* Format strings */
    static char fmt_305[] = "(/\002 * note- the ion adjusted for electrical "
	    "balance\002,/7x,\002is crashing to zero.   electrical balancing "
	    "requires an\002,/7x,\002ion of opposite charge (ndiagx)\002,/)";
    static char fmt_315[] = "(/\002 *note- carbonate or bicarbonate is crash"
	    "ing to\002,/7x,\002zero because non-carbonate alkalinity exceeds"
	    " the\002,/7x,\002 specified titration alkalinity (ndiagx)\002,/)";
    static char fmt_333[] = "(/\002 * note- fo2 is crashing, probably beca"
	    "use\002,/7x,\002a bad electrical balance constraint on h+ is cau"
	    "sing\002,/7x,\002the concentration of h+ to crash to zero (ndiag"
	    "x)\002,/)";
    static char fmt_337[] = "(/\002 * note- fo2 is crashing, probably beca"
	    "use\002,/7x,\002of a bad constraint on one of the aqueous species"
	    "\002,/7x,\002 appearing in the redox reaction that is being\002,"
	    "/7x,\002 used to constrain the fo2 (ndiagx)\002,/)";
    static char fmt_355[] = "(/\002 * note- no diagnostics were generated fr"
	    "om the\002,/7x,\002iteration crash.  look at the del and beta in"
	    "fo. in the\002,/7x,\002iteration summary for clues (ndiagx)\002,"
	    "/)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer ns;
    static doublereal dum, adum;
    static integer iopt1;
    static doublereal delmax;
    static logical qadtst, qdltst;

    /* Fortran I/O blocks */
    static cilist io___1493 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___1494 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___1496 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___1497 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___1503 = { 0, 0, 0, fmt_333, 0 };
    static cilist io___1504 = { 0, 0, 0, fmt_333, 0 };
    static cilist io___1505 = { 0, 0, 0, fmt_337, 0 };
    static cilist io___1506 = { 0, 0, 0, fmt_337, 0 };
    static cilist io___1507 = { 0, 0, 0, fmt_355, 0 };
    static cilist io___1508 = { 0, 0, 0, fmt_355, 0 };



/*     this routine attempts to generate diagnostics if hybrid newton- */
/*     raphson iteration has failed. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */



/* -------------------------------------------------------------------- */
/* un.h */

/* -------------------------------------------------------------------- */
/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */


/* ---------------------------------------------------------------------- */

/*     try to diagnose why the iteration crashed.  first look for */
/*     clues in the del vector.  then look at the condition of */
/*     the ionic strength and related parameters. */

/*     a common error is a bad input constraint associated with either */
/*     electrical balancing or titration alkalinity. */

    /* Parameter adjustments */
    --iindx1;
    --jflag;
    --del;

    /* Function Body */
    if (*idelmx == 0) {
	goto L350;
    }

/*        check to see if the ion being adjusted for electrical balance */
/*        was crashing to zero.  this implies that an ion of opposite */
/*        charge must be used to achieve electrical balance. */

    qdltst = del[*idelmx] + *screwd <= eqleps_1.eps100;
    if (*idelmx == *kebal && qdltst) {
	io___1493.ciunit = un_1.noutpt;
	s_wsfe(&io___1493);
	e_wsfe();
	io___1494.ciunit = un_1.nttyo;
	s_wsfe(&io___1494);
	e_wsfe();
	goto L999;
    }

/*        check to see if the ion associated with titration alkalinity */
/*        balance is crashing to zero.  this implies that non-carbonate */
/*        alkalinity is greater than or equal to carbonate alkalinity. */
/*        sulfide alkalinity is a likely culprit. */

    if (*idelmx == *kcarb && qdltst) {
	ns = iindx1[*idelmx];
	if (jflag[ns] == 10) {
	    io___1496.ciunit = un_1.noutpt;
	    s_wsfe(&io___1496);
	    e_wsfe();
	    io___1497.ciunit = un_1.nttyo;
	    s_wsfe(&io___1497);
	    e_wsfe();
	    goto L999;
	}
    }

/*        check to see if fo2 is crashing.  this could be due to */
/*        a bad combination of constraining the redox state by a */
/*        non-fo2 option and divergence to zero of an associated */
/*        ion that is constrained by electrical balance. */

    qadtst = delmax - *screwd <= eqleps_1.eps100;
    if (*idelmx == *ksb && qadtst) {
	if (iopt1 == -1 && *iebal == *nhydr) {
	    dum = *screwd * .1f;
	    adum = (d__1 = del[*khydr], abs(d__1));
	    if (adum >= dum) {
		io___1503.ciunit = un_1.noutpt;
		s_wsfe(&io___1503);
		e_wsfe();
		io___1504.ciunit = un_1.nttyo;
		s_wsfe(&io___1504);
		e_wsfe();
		goto L999;
	    }
	}

	if (iopt1 > 1) {
	    io___1505.ciunit = un_1.noutpt;
	    s_wsfe(&io___1505);
	    e_wsfe();
	    io___1506.ciunit = un_1.nttyo;
	    s_wsfe(&io___1506);
	    e_wsfe();
	    goto L999;
	}
    }

L350:

    io___1507.ciunit = un_1.noutpt;
    s_wsfe(&io___1507);
    e_wsfe();
    io___1508.ciunit = un_1.nttyo;
    s_wsfe(&io___1508);
    e_wsfe();

L999:
    return 0;
} /* ndiagx_ */


/* matrix   last revised 12/14/87 by tjw */
/* Subroutine */ int matrix_(void)
{
    /* Format strings */
    static char fmt_1000[] = "(1x,\002illegal jflag value = \002,i5,\002 enc"
	    "ountered for \002,a18,\002 in matrix\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer k, ik, ng, nm, ns, nx, nsc, jrs[679], nrr, nss, nrs, nse, 
	    kcol, krow, jfdum;
    extern /* Subroutine */ int balcon_(doublereal *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1518 = { 0, 0, 0, fmt_1000, 0 };



/*     this routine builds the jacobian matrix aa(kdim,kdim). */
/*     the matrix is written row-by-row. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */

/* -------------------------------------------------------------------- */
/* parset.h  last modified 12/01/87 by tjw */

/*     nctpar = nctmax = no. of elements */
/*     nsqpar = nsqmax = maximum no. of expanded basis species */
/*     nstpar = nstmax = maximum no. of aqueous species */
/*     nrstpa = nrstmx = maximum no. of aqueous reactions */
/*     nmtpar = nmtmax = maximum number of pure minerals */
/*     ngtpar = ngtmax = maximum no. of gases */
/*     nxtpar = nxtmax = maximum no. of solid-solutions */
/*     iktpar = iktmax = maximum no. of solid-solution end-members */
/*     iapxpa = iapxmx = leading dimension of the apx array, */
/*                       solid solution non-ideality parameters */
/*     kpar   = kmax   = maximum dimension of the jacobian matrix */
/*     narxpa = narxmx = maximum number of coefficients in a fitting */
/*                       polynomial describing the temperature dependence */
/*                       of a thermodynamic property */
/*     ntprpa = ntprmx = maximum number of temperature ranges for */
/*                       polynomial coefficients describing a */
/*                       thermodynamic property */



/* -------------------------------------------------------------------- */
/* blank.h */
/* -------------------------------------------------------------------- */
/* an.h */
/* -------------------------------------------------------------------- */
/* bt.h */


/* -------------------------------------------------------------------- */
/* cc.h */

/* -------------------------------------------------------------------- */
/* ee.h */

/* -------------------------------------------------------------------- */
/* gg.h */
/* -------------------------------------------------------------------- */
/* hh.h */
/* ----------------------------------------------------------------------- */
/* jj.h */

/* -------------------------------------------------------------------- */
/* ka.h */
/* -------------------------------------------------------------------- */
/* ki.h */
/* -------------------------------------------------------------------- */
/* nn.h */

/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* op1.h */
/* -------------------------------------------------------------------- */
/* op2.h */
/* ----------------------------------------------------------------- */
/* ps.h */
/* -------------------------------------------------------------------- */
/* st.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* tu.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* uu.h */


/* -------------------------------------------------------------------- */
/* vv.h */
/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* zg.h */
/* -------------------------------------------------------------------- */
/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlpp.h */

/* ---------------------------------------------------------------------- */

/*     initialize array aa to zeroes */

/* -------------------------------------------------------------------- */
/* eqlgp.h */


    i__1 = ki_1.kdim;
    for (krow = 1; krow <= i__1; ++krow) {
	i__2 = ki_1.kdim;
	for (kcol = 1; kcol <= i__2; ++kcol) {
	    nn_1.aa[krow + kcol * 100 - 101] = 0.f;
/* L5: */
	}
/* L10: */
    }

/*     arrange the reactions in order of increasing concentration of */
/*     the associated aqueous species. */

    nrr = 0;
    i__1 = tt_1.nst;
    for (nss = 1; nss <= i__1; ++nss) {
	nsc = st_1.jsort[nss - 1];
	nrs = nsc - tt_1.nsb;
	if (nrs <= 0) {
	    goto L15;
	}
	++nrr;
	jrs[nrr - 1] = nrs;
L15:
	;
    }

/*     the first row/column is currently unused */

    nn_1.aa[0] = 1.f;

/* - - - - - - - - - - begin main loop - - - - - - - - - - - - - - - - - - */

/*     write rows 2 through ksq. */

    i__1 = ki_1.ksq;
    for (krow = 2; krow <= i__1; ++krow) {
	nse = ka_1.iindx1[krow - 1];

/*      test for various constraints */

/*      test for charge balance */
	if (nse == ee_1.iebal) {
	    goto L70;
	}
	jfdum = jj_1.jflag[nse - 1];
/*      test for mineral equilibrium */
	if (jfdum == 19) {
	    goto L200;
	}
	if (jfdum == 20) {
	    goto L200;
	}
/*      test for gas equilibrium */
	if (jfdum == 21) {
	    goto L250;
	}
/*      test for log fo2 */
	if (nse == tt_1.nsb) {
	    goto L300;
	}
/*      test for mass balance */
	if (jfdum == 0) {
	    goto L30;
	}
/*      test for alkalinity balance */
	if (jfdum == 10) {
	    goto L110;
	}
/*      test for log activity */
	if (jfdum == 16) {
	    goto L170;
	}
/*      test for aqueous homogeneous equilibrium */
	if (jfdum == 27) {
	    goto L700;
	}
/*      test for free concentration */
	if (jfdum == 4) {
	    goto L175;
	}
/*      test for alkalinity balance */
	if (jfdum == 12) {
	    goto L110;
	}
	io___1518.ciunit = un_1.noutpt;
	s_wsfe(&io___1518);
	do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	e_wsfe();
	s_stop("", (ftnlen)0);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        mass balance constraint. */

L30:
	i__2 = tt_1.nst;
	for (ns = 1; ns <= i__2; ++ns) {
	    st_1.store[ns - 1] = _BLNK__1.csts[nse + ns * 100 - 101];
/* L35: */
	}

	balcon_(st_1.store, jrs, &krow);

	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        charge balance constraint. */

L70:

	balcon_(ccp_1.z__, jrs, &krow);

	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        alkalinity balance constraint. */

L110:

	balcon_(ccp_1.titr, jrs, &krow);

	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        log activity constraint. */

L170:
	nn_1.aa[krow + krow * 100 - 101] = 1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        free concentration constraint. */

L175:
	nn_1.aa[krow + krow * 100 - 101] = 1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        mineral equilibrium constraint. */

L200:
	nm = ww_1.nsp[nse - 1];
	if (nm < 50000) {
	    goto L205;
	}
	nm += -50000;
	nx = nm / 100;
	ik = nm - nx * 100;
	nm = an_1.nend[ik + nx * 20 - 21];
L205:

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == krow) {
		goto L215;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    nn_1.aa[krow + kcol * 100 - 101] = -_BLNK__1.cdrm[ns + nm * 101 - 
		    102] / _BLNK__1.cdrm[nse + nm * 101 - 102];
L215:
	    ;
	}

	nn_1.aa[krow + krow * 100 - 101] = -1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        gas equilibrium constraint. */

L250:
	ng = ww_1.nsp[nse - 1];

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == krow) {
		goto L260;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    nn_1.aa[krow + kcol * 100 - 101] = -_BLNK__1.cdrg[ns + ng * 101 - 
		    102] / _BLNK__1.cdrg[nse + ng * 101 - 102];
L260:
	    ;
	}

	nn_1.aa[krow + krow * 100 - 101] = -1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        aqueous homogeneous equilibrium constraint. */

L700:
	nrs = nse - tt_1.nsb;

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == krow) {
		goto L705;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    nn_1.aa[krow + kcol * 100 - 101] = -_BLNK__1.cdrs[ns + nrs * 101 
		    - 102] / _BLNK__1.cdrs[tt_1.nsq1 + nrs * 101 - 102];
L705:
	    ;
	}

	nn_1.aa[krow + krow * 100 - 101] = -1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*        log fo2 constraints. */

/*           identity constraint. */

L300:
	if (op_1.iopt1 != 0) {
	    goto L310;
	}
	nn_1.aa[krow + ki_1.ksb * 100 - 101] = 1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*           eh constraint (note--an input p e- value has been */
/*           converted to an eh value by routine setup) */

L310:
	if (op_1.iopt1 >= 1) {
	    goto L330;
	}
	nn_1.aa[krow + ki_1.khydr * 100 - 101] = -4.f;
	nn_1.aa[krow + krow * 100 - 101] = -1.f;
	goto L400;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/*           cross-linking (homogeneous aqueous redox) equilibrium. */

L330:
	nsc = op_1.iopt1 + tt_1.nsb;
	nn_1.aa[krow + ki_1.ksb * 100 - 101] = -1.f;

	i__2 = ki_1.ksq;
	for (kcol = 2; kcol <= i__2; ++kcol) {
	    if (kcol == ki_1.ksb) {
		goto L340;
	    }
	    ns = ka_1.iindx1[kcol - 1];
	    if (ns == nsc) {
		nn_1.aa[krow + kcol * 100 - 101] = -_BLNK__1.cdrs[tt_1.nsq1 + 
			op_1.iopt1 * 101 - 102] / _BLNK__1.cdrs[tt_1.nsb + 
			op_1.iopt1 * 101 - 102];
	    } else {
		nn_1.aa[krow + kcol * 100 - 101] = -_BLNK__1.cdrs[ns + 
			op_1.iopt1 * 101 - 102] / _BLNK__1.cdrs[tt_1.nsb + 
			op_1.iopt1 * 101 - 102];
	    }
L340:
	    ;
	}
L400:
	;
    }

/* - - - - - - - - - - end of main loop - - - - - - - - - - - - - - - - - */

    if (op2_1.iodb3 > 0) {

/*       variable-killer option here */

	i__1 = ki_1.kdim;
	for (k = 1; k <= i__1; ++k) {
	    if (nn_1.kill[k - 1] == 0) {
		goto L495;
	    }
	    i__2 = ki_1.kdim;
	    for (krow = 1; krow <= i__2; ++krow) {
		nn_1.aa[krow + k * 100 - 101] = 0.f;
/* L492: */
	    }
	    i__2 = ki_1.kdim;
	    for (kcol = 1; kcol <= i__2; ++kcol) {
		nn_1.aa[k + kcol * 100 - 101] = 0.f;
/* L493: */
	    }
	    nn_1.aa[k + k * 100 - 101] = 1.f;
L495:
	    ;
	}
    }

/* L999: */
    return 0;
} /* matrix_ */

