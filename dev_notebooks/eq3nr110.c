 /* eq3nr110.f -- translated by f2c (version 20100827).
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
#include <stdio.h>





/* Common Block Declarations */

struct {
    doublereal cdrs[68579]	/* was [101][679] */, cdrm[75750]	/* 
	    was [101][750] */, cdrg[1515]	/* was [101][15] */, csts[
	    75000]	/* was [100][750] */, cess[52500]	/* was [70][
	    750] */;
} _BLNK__;

#define _BLNK__1 _BLNK__

struct {
    doublereal w[400]	/* was [20][20] */, sx[400]	/* was [20][20] */;
    integer nend[400]	/* was [20][20] */;
} an_;

#define an_1 an_

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

struct eqlver_1_ {
    char ucode[8], urelno[8], ustage[8], ueqlrn[8], ueqlst[8];
};

#define eqlver_1 (*(struct eqlver_1_ *) &eqlver_)

struct {
    doublereal fug[15], fuglg[15];
} fg_;

#define fg_1 fg_

struct gg_1_ {
    char uxtype[320], ujtype[744], uspec[18000], umin[18000], ugas[360], 
	    usolx[480], uelem[568];
};

#define gg_1 (*(struct gg_1_ *) &gg_)

struct {
    doublereal tempc, tempk, press, tempc1, tempc2;
    integer ntpr;
} hh_;

#define hh_1 hh_

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
    integer iopt1, iopt2, iopt3, iopt4, iopt5, iopt6, iopt7, iopt8, iopt9, 
	    iopt10;
} op_;

#define op_1 op_

struct {
    integer iopr1, iopr2, iopr3, iopr4, iopr5, iopr6, iopr7, iopr8, iopr9, 
	    iopr10, iopr11, iopr12, iopr13, iopr14, iopr15, iopr16, iopr17, 
	    iopr18, iopr19, iopr20;
} op1_;

#define op1_1 op1_

struct {
    integer iodb1, iodb2, iodb3, iodb4, iodb5, iodb6, iodb7, iodb8, iodb9, 
	    iodb10;
} op2_;

#define op2_1 op2_

struct {
    doublereal tolbt, tolsat, tolxat, toldl;
    integer itermx;
} ps_;

#define ps_1 ps_

struct {
    integer jct, jst, jrst, jmt, jxt, jgt, ist, irst, imt, igt;
} si_;

#define si_1 si_

struct {
    doublereal store[750], csort[750], cstor[1500]	/* was [750][2] */;
    integer jsort[750], istack[750], jstack[750];
} st_;

#define st_1 st_

struct {
    char udrxd[2424], unam24[2424];
} tec_;

#define tec_1 tec_

struct {
    integer ntitl, ntitmx;
} ti_;

#define ti_1 ti_

struct {
    char utitld[320], utitl[2400];
} tic_;

#define tic_1 tic_

struct {
    integer nct, nsb, nsb1, nsq, nsq1, nst, nrst, nmt, ngt, nxt, nsqmax, nsqb,
	     nstmax, nrstmx, nmtmax, ngtmax, nxtmax, iktmax, iapxmx, nctmax, 
	    nsqmx1;
} tt_;

#define tt_1 tt_

struct {
    integer nhydr, nchlor, nsodiu, ncarb;
} tu_;

#define tu_1 tu_

struct un_1_ {
    integer noutpt, nttyo, nad1, npkup, nrlst, ninpt, nahv;
};

#define un_1 (*(struct un_1_ *) &un_)

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
    doublereal xbarb[400]	/* was [20][20] */;
    integer nxtb, ncompb[20], nxspec[20];
} vw_;

#define vw_1 vw_

struct {
    char usolb[480], umemb[9600]	/* was [20][20] */;
} vwc_;

#define vwc_1 vwc_

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
    doublereal conc[750], conclg[750], act[750], actlg[750], mte[70], cte[100]
	    ;
} yy_;

#define yy_1 yy_

struct {
    doublereal zvclg1[100], del[100];
} zg_;

#define zg_1 zg_

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
    doublereal eps, smpos, eps10, eps100, smp10, smp100;
    integer irang;
} eqleps_;

#define eqleps_1 eqleps_

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
    doublereal al10, farad, rconst, afcnst, ehfac, volg, om, omlg, omi, 
	    tcnst1, tcnst2;
} eqlpp_;

#define eqlpp_1 eqlpp_

struct {
    doublereal selm[21], selmp[21];
} eqlsza_;

#define eqlsza_1 eqlsza_

struct {
    doublereal xltxp, xutxp, yutxp;
    logical qtxppr;
} eqltxp_;

#define eqltxp_1 eqltxp_

/* Initialized data */

struct {
    char e_1[24];
    char fill_2[16];
    } eqlver_ = { "eq3nr   3245    R110    " };

struct {
    char e_1[192];
    char fill_2[128];
    char e_3[744];
    char fill_4[37408];
    } gg_ = { "ideal solution                  binary, third-order maclaurin"
	    "   binary, parabolic maclaurin     binary, cubic maclaurin (p,t)"
	    "   binary, guggenheim  (t)         ternary, regular             "
	    "   ", {0}, "tot conc, molal         tot conc, molar         tot "
	    "conc, mg/l          tot conc, mg/kg         free conc, molal    "
	    "    free conc, molar        free conc, mg/l         free conc, m"
	    "g/kg        free conc, cc/cc         jflag error            tit "
	    "alk, eq/kg h2o      tit alk, eq/l           co3 alk, eq/kg h2o  "
	    "    co3 alk, eq/l            jflag error             jflag error"
	    "            log activity             jflag error             jfl"
	    "ag error            mineral equilibrium     solid solution equil"
	    "    gas equilibrium          jflag error             jflag error"
	    "             jflag error             jflag error             jfl"
	    "ag error            dependent species        jflag error        "
	    "     jflag error            eliminated species      " };

struct {
    integer e_1[4];
    integer fill_2[1];
    integer e_3;
    integer fill_4[1];
    } un_ = { 18, 0, 17, 21, {0}, 19 };


/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__0 = 0;

/* eq3nr    version 3245R110, last revised 12/26/87 by tjw */
/* *eq3nr f77 rewrite 02/23/87 by tjw */
/*     Be sure to put the correct release and stage numbers in */
/*     in parameters urelno and ustage. */

/* Test */
int MAINTEST__(void)
{
	printf("Entered main-test loop");
	return 0;
}

/* Main program */ int MAIN__(void)
{
    /* Initialized data */
	printf("Entered main loop.");


    static doublereal screwd = 2.;
    static char uh2aq[8] = "H2(AQ)  ";
    static char uconc[8] = "CONC    ";
    static char usodiu[8] = "NA+     ";
    static integer nleni = 80;
    static integer ninpts = 20;
    static doublereal screwn = .1;
    static char uhco3[8] = "HCO3-   ";
    static char uco3[8] = "CO3--   ";
    static char ublank[8] = "        ";
    static char upick1[8] = "PICK1.  ";
    static char unone[8] = "NONE    ";
    static char uo2aq[8] = "O2(AQ)  ";

    /* Format strings */
    static char fmt_1000[] = "(/\002 EQ3NR, version \002,a4,a4,//\002   Copy"
	    "right (c) 1987 The Regents of the University of\002,\002 Califor"
	    "nia,\002,/\002   Lawrence Livermore National Laboratory. All\002,"
	    "\002 rights reserved.\002)";
    static char fmt_1005[] = "(\002 Run\002,2(2x,a8),//)";
    static char fmt_1208[] = "(/,10x,\002start time = \002,a8,2x,a8,/12x,"
	    "\002end time = \002,a8,2x,a8)";
    static char fmt_1211[] = "(/10x,\002user time = \002,f10.3)";
    static char fmt_1007[] = "(\002 normal exit\002)";
    static char fmt_1171[] = "(\002 input value for iopr9 was inconsistent w"
	    "ith iopg1 \002,\002choice\002,/,\002 (activity coefficient selec"
	    "tion).  therefore, iopr9 was reset to 0\002)";
    static char fmt_1181[] = "(\002 * no lu available\002)";
    static char fmt_1191[] = "(\002 * error opening ahv\002)";
    static char fmt_1010[] = "(\002 --- pitzer data has been successfully re"
	    "ad from\002,\002 file data1 ---\002)";
    static char fmt_104[] = "(1x,\002----- conflicting redox options ----"
	    "-\002)";
    static char fmt_123[] = "(/6x,\002iopt1 = \002,i2,\002 overrides jflag(o"
	    "2(g)) = \002,i2,/)";
    static char fmt_127[] = "(/6x,\002iopt1 = \002,i2,\002 overrides uredox "
	    "= \002,a16,/)";
    static char fmt_235[] = "(/1x,\002the ion that defines equiv. stoich. io"
	    "nic strength\002,/1x\002  is \002,a24,/)";
    static char fmt_853[] = "(\002 --- \002,a24,\002 specified for electrica"
	    "l balancing\002,/3x,\002is not in the master set ---\002,/)";
    static char fmt_870[] = "(/\002 --- \002,a24,\002 specified for electric"
	    "al balancing\002,/3x,\002has no charge ---\002,/)";
    static char fmt_874[] = "(/\002 --- \002,a24,\002 specified for electric"
	    "al balancing\002,/3x,\002is not in the model ---\002,/)";
    static char fmt_852[] = "(/,\002 picking an ion for electrical balancin"
	    "g\002,/)";
    static char fmt_880[] = "(/1x,\002--- no such ion was selected ---\002,/)"
	    ;
    static char fmt_255[] = "(\002 electrical balance will be achieved by ad"
	    "justing\002,/\002   the concentration of \002,a24,/)";
    static char fmt_257[] = "(\002 * error- terminating due to basis switchi"
	    "ng errors\002)";
    static char fmt_240[] = "(/21x,\002--- inactive aqueous species ---\002,"
	    "/)";
    static char fmt_222[] = "(4(2x,a24))";
    static char fmt_223[] = "(1x)";
    static char fmt_2226[] = "(\002 * error- \002a24,\002 (for default redox"
	    " couple) is not\002,/\002   in the auxiliary basis\002)";
    static char fmt_1245[] = "(\002 * error-- the strict basis species \002,"
	    "a24,/,\002 has an illegal jflag value of \002,i2)";
    static char fmt_1002[] = "(\002 * error- nerr= \002,i4)";
    static char fmt_1100[] = "(//32x,\002--- modified input constraints --"
	    "-\002,//5x,\002species          csp       jflag \002,\002 type o"
	    "f input      controlling phase\002,/)";
    static char fmt_1105[] = "(3x,a24,3x,e12.5,3x,i2,3x,a24,3x,a24)";
    static char fmt_315[] = "(3x,a24,23x,\002not present in the model\002)";
    static char fmt_317[] = "(//,1x)";
    static char fmt_366[] = "(\002 * error- use of hydration theory with n"
	    "o\002,\002 non-zero hydration numbers\002)";
    static char fmt_2009[] = "(\002 * error- iopt1.eq.-3 but jflag is not"
	    "\002,\002 19, 20, or 21\002)";
    static char fmt_2015[] = "(\002 * error- \002,a16,\002 specifies redox c"
	    "ontrol\002,\002 by a non-redox reaction\002)";
    static char fmt_1281[] = "(\002 * error- there is no \002,a24,\002 in th"
	    "e system to define a redox couple\002)";
    static char fmt_1283[] = "(\002 * error- redox couple species \002,a24"
	    ",\002 has illegal \002,/\002     jflag value of \002,i2)";
    static char fmt_1293[] = "(\002 * error- can not find the strict basis s"
	    "pecies for \002,/\002     the cross-link reaction specified by u"
	    "redox\002)";
    static char fmt_2025[] = "(\002 * error- illegal negative csp value for"
	    " \002,a24,\002 = \002,e13.6)";
    static char fmt_2035[] = "(\002 * error- illegal alkalinity constraint o"
	    "n \002,a24,/\002     this option only works for hco3- or co3-"
	    "-\002)";
    static char fmt_407[] = "(\002 * error-\002,a24,\002 can not be constrai"
	    "ned by the \002,/\002     following reaction-\002,/)";
    static char fmt_2047[] = "(\002 * error- \002,a24,\002 can not be constr"
	    "ained by a \002,/\002     solid-solution equilibrium because iop"
	    "t4 = \002,i2,\002, not 2\002)";
    static char fmt_2055[] = "(\002 * error- bad jflag value for \002,a24"
	    ",\002 = \002,i3)";
    static char fmt_2093[] = "(\002 * error- the following heterogeneous rea"
	    "ction\002,\002constraint has been used more than once-\002,/)";
    static char fmt_2003[] = "(\002 * error- jflag(o2(g) = \002,i2,\002 but "
	    "iopt1 is not 0\002)";
    static char fmt_450[] = "(\002 * error- the input has failed \002,i4,"
	    "\002 idiot-proofing\002,\002 tests\002)";
    static char fmt_1408[] = "(//\002 * trouble- hybrid newton-raphson itera"
	    "tion failed\002,\002 after \002,i3,\002 steps\002,/)";
    static char fmt_1437[] = "(//,\002 hybrid newton-raphson iteration conve"
	    "rged in \002,i3,\002 steps \002/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;
    olist o__1;
    cllist cl__1;
    alist al__1;
    inlist ioin__1;

    /* Builtin functions */
    integer f_clos(cllist *), f_rew(alist *), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);
    integer f_inqu(inlist *);
    double d_lg10(doublereal *);
    integer f_open(olist *), s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer k, n, nc, ng, ik, jk, nm, is, ns, nx;
    static doublereal zz, ac2[40]	/* was [5][2][4] */;
    static integer jk2, ns1, ns2, ns3;
    static doublereal aeh[10]	/* was [5][2] */, ags[150]	/* was [5][2][
	    15] */, amn[7500]	/* was [5][2][750] */;
    static integer isb;
    static doublereal ars[6790]	/* was [5][2][679] */, awo[40]	/* was [5][2][
	    4] */;
    static integer nrs;
    static logical qop;
    static integer izm, nse, ker, ier;
    static doublereal aadh[10]	/* was [5][2] */, abdh[10]	/* was [5][2] 
	    */, delo[100], glgx[750];
    static integer kcol;
    static logical qend;
    static integer nerr;
    extern /* Subroutine */ int zsrt_(doublereal *, integer *, integer *, 
	    integer *, integer *);
    static doublereal cdum1, cdum2, zdum, cdum, abdot[10]	/* was [5][2] 
	    */, betao[100];
    static char usave[24*100], utemp[24], uqdel[8*100];
    extern /* Subroutine */ int ncmpx_(), betas_();
    extern /* Subroutine */ int eqlib_(char *, char *, integer *, integer *, 
	    logical *, logical *, ftnlen, ftnlen);
    static logical qtrue;
    static char utime0[8], udate0[8];
    extern /* Subroutine */ int readx_(integer *, logical *);
    static char utime1[8], udate1[8];
    static doublereal concbs[100];
    extern /* Subroutine */ int gntpr_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    integer *, integer *), evdata_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, char *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen, 
	    ftnlen);
    static logical qfalse;
    static char unamsp[24], uqbeta[8*100];
    static doublereal apress[10]	/* was [5][2] */, cxistq[750];
    extern /* Subroutine */ int matrix_();
    extern /* Subroutine */ int openou_(char *, char *, integer *, ftnlen, 
	    ftnlen), openin_(char *, char *, integer *, ftnlen, ftnlen), 
	    stripl_(integer *, integer *, integer *);
    static integer narxmx, ntprmx;
    static doublereal timdum;
    extern /* Subroutine */ int nactop_(void), indatx_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, char *, 
	    char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen,
	     ftnlen, ftnlen, ftnlen), gspion_(char *, integer *, integer *, 
	    integer *, ftnlen), flgstx_(doublereal *, doublereal *, 
	    doublereal *, char *, char *, char *, char *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    static doublereal pgrid;
    extern /* Subroutine */ int inupt_(char *, integer *, integer *, integer *
	    , integer *, ftnlen), getlu_(integer *, integer *), bdslx_(
	    integer *), bdmlx_(integer *), hkfrd_(char *, integer *, integer *
	    , integer *, ftnlen);
    static integer izoff, jfdum;
    extern /* Subroutine */ int echox_(void), setup_(void);
    static char udum1[8], udum2[8];
    static doublereal charge, charg1;
    extern /* Subroutine */ int echolk_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, char *, char *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen, ftnlen), switch_(integer *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    logical *, logical *, logical *, ftnlen);
    static integer jdum;
    static logical qelim;
    extern /* Subroutine */ int elim_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *), 
	    prreac_(doublereal *, char *, char *, integer *, integer *, 
	    integer *, integer *, integer *, ftnlen, ftnlen);
    static integer ndum;
    extern /* Subroutine */ int lamda_(doublereal *, integer *, doublereal *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    static integer nwarn, nloc;
    extern /* Subroutine */ int evdatr_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *), gcsts_(
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, logical *),
	     arrset_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, char *, char *, char *, char *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, logical *, logical *, logical *, logical *
	    , ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static integer nloop;
    static logical qretry, qpra, qprb, qprc;
    extern /* Subroutine */ int newton_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, char *, char *, char *, char *
	    , char *, char *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, U_fp, U_fp, U_fp, logical *, logical *, logical *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen)
	    ;
    static integer iter, idelmx;
    extern /* Subroutine */ int ndiagx_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *, integer *, integer *, integer *,
	     integer *, integer *), scripx_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *);
    static doublereal sigzi;
    extern /* Subroutine */ int scribx_(doublereal *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_1005, 0 };
    static cilist io___37 = { 0, 0, 0, fmt_1208, 0 };
    static cilist io___40 = { 0, 0, 0, fmt_1208, 0 };
    static cilist io___42 = { 0, 0, 0, fmt_1211, 0 };
    static cilist io___43 = { 0, 0, 0, fmt_1211, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_1007, 0 };
    static cilist io___45 = { 0, 0, 0, fmt_1007, 0 };
    static cilist io___59 = { 0, 0, 0, fmt_1171, 0 };
    static cilist io___61 = { 0, 0, 0, fmt_1181, 0 };
    static cilist io___62 = { 0, 0, 0, fmt_1191, 0 };
    static cilist io___63 = { 0, 0, 0, fmt_1010, 0 };
    static cilist io___69 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___70 = { 0, 0, 0, fmt_123, 0 };
    static cilist io___71 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___72 = { 0, 0, 0, fmt_127, 0 };
    static cilist io___78 = { 0, 0, 0, fmt_235, 0 };
    static cilist io___79 = { 0, 0, 0, fmt_853, 0 };
    static cilist io___80 = { 0, 0, 0, fmt_870, 0 };
    static cilist io___81 = { 0, 0, 0, fmt_874, 0 };
    static cilist io___82 = { 0, 0, 0, fmt_852, 0 };
    static cilist io___87 = { 0, 0, 0, fmt_880, 0 };
    static cilist io___88 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___94 = { 0, 0, 0, fmt_257, 0 };
    static cilist io___95 = { 0, 0, 0, fmt_257, 0 };
    static cilist io___96 = { 0, 0, 0, fmt_240, 0 };
    static cilist io___98 = { 0, 0, 0, fmt_222, 0 };
    static cilist io___100 = { 0, 0, 0, fmt_222, 0 };
    static cilist io___101 = { 0, 0, 0, fmt_223, 0 };
    static cilist io___102 = { 0, 0, 0, fmt_2226, 0 };
    static cilist io___103 = { 0, 0, 0, fmt_2226, 0 };
    static cilist io___104 = { 0, 0, 0, fmt_1245, 0 };
    static cilist io___105 = { 0, 0, 0, fmt_1245, 0 };
    static cilist io___106 = { 0, 0, 0, fmt_1002, 0 };
    static cilist io___107 = { 0, 0, 0, fmt_1002, 0 };
    static cilist io___110 = { 0, 0, 0, fmt_257, 0 };
    static cilist io___111 = { 0, 0, 0, fmt_257, 0 };
    static cilist io___112 = { 0, 0, 0, fmt_1100, 0 };
    static cilist io___115 = { 0, 0, 0, fmt_1105, 0 };
    static cilist io___118 = { 0, 0, 0, fmt_1105, 0 };
    static cilist io___119 = { 0, 0, 0, fmt_1105, 0 };
    static cilist io___120 = { 0, 0, 0, fmt_1105, 0 };
    static cilist io___121 = { 0, 0, 0, fmt_1105, 0 };
    static cilist io___122 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___123 = { 0, 0, 0, fmt_317, 0 };
    static cilist io___125 = { 0, 0, 0, fmt_366, 0 };
    static cilist io___126 = { 0, 0, 0, fmt_366, 0 };
    static cilist io___127 = { 0, 0, 0, fmt_2009, 0 };
    static cilist io___128 = { 0, 0, 0, fmt_2009, 0 };
    static cilist io___129 = { 0, 0, 0, fmt_2015, 0 };
    static cilist io___130 = { 0, 0, 0, fmt_2015, 0 };
    static cilist io___131 = { 0, 0, 0, fmt_1281, 0 };
    static cilist io___132 = { 0, 0, 0, fmt_1281, 0 };
    static cilist io___133 = { 0, 0, 0, fmt_1283, 0 };
    static cilist io___134 = { 0, 0, 0, fmt_1293, 0 };
    static cilist io___135 = { 0, 0, 0, fmt_1293, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_1281, 0 };
    static cilist io___137 = { 0, 0, 0, fmt_1281, 0 };
    static cilist io___138 = { 0, 0, 0, fmt_2025, 0 };
    static cilist io___139 = { 0, 0, 0, fmt_2025, 0 };
    static cilist io___140 = { 0, 0, 0, fmt_2035, 0 };
    static cilist io___141 = { 0, 0, 0, fmt_2035, 0 };
    static cilist io___142 = { 0, 0, 0, fmt_407, 0 };
    static cilist io___143 = { 0, 0, 0, fmt_407, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_2047, 0 };
    static cilist io___145 = { 0, 0, 0, fmt_2047, 0 };
    static cilist io___146 = { 0, 0, 0, fmt_407, 0 };
    static cilist io___147 = { 0, 0, 0, fmt_407, 0 };
    static cilist io___148 = { 0, 0, 0, fmt_407, 0 };
    static cilist io___149 = { 0, 0, 0, fmt_407, 0 };
    static cilist io___150 = { 0, 0, 0, fmt_2055, 0 };
    static cilist io___151 = { 0, 0, 0, fmt_2055, 0 };
    static cilist io___153 = { 0, 0, 0, fmt_2093, 0 };
    static cilist io___154 = { 0, 0, 0, fmt_2093, 0 };
    static cilist io___156 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___157 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___158 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___159 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___160 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___161 = { 0, 0, 0, fmt_2003, 0 };
    static cilist io___162 = { 0, 0, 0, fmt_450, 0 };
    static cilist io___163 = { 0, 0, 0, fmt_450, 0 };
    static cilist io___177 = { 0, 0, 0, fmt_1408, 0 };
    static cilist io___178 = { 0, 0, 0, fmt_1408, 0 };
    static cilist io___179 = { 0, 0, 0, fmt_1437, 0 };
    static cilist io___180 = { 0, 0, 0, fmt_1437, 0 };



/*     This is the main program of the EQ3NR computer code, part of the */
/*     EQ3/6 software package.  This computer code is copyrighted as */
/*     follows- */

/*     Copyright (c) 1987 The Regents of the University of California, */
/*     Lawrence Livermore National Laboratory. All rights reserved. */

/*          The person responsible for this code is */

/*               Thomas J. Wolery */
/*               L-219 */
/*               Lawrence Livermore National Laboratory */
/*               P.O. Box 808 */
/*               Livermore, CA  94550 */
/*               (415) 422-5789 */
/*               FTS 532-5789 */

/*        Comments on this code are welcome.  Users are encouraged */
/*     to report suspected or documented errors or other problems. */
/*     LLNL maintains a mailing list of known users.  If you */
/*     are using this code, you should make it a point to have your */
/*     name on it in order to receive notification of errors and */
/*     recommended fixes, announcements of new releases, and copies of */
/*     future reports. */

/*        The primary reference for this code is-- */

/*      Wolery, T.J., 1983, EQ3NR, A Geochemical Aqueous Speciation- */
/*        Solubility Code, UCRL-53414, Lawrence Livermore National */
/*        Laboratory, Livermore, California. */

/*     This report is available from LLNL as long as the supply */
/*     lasts. */

/*        The code is well-documented internally.  The internal */
/*     documentation is the final authority on matters pertaining */
/*     to the operation of this code.  Users are advised to pay */
/*     particular attention to the comment lines in the main program */
/*     and subprograms READX (reads the problem input), INDATX (reads */
/*     the secondary data file called data1), and NEWTON (solves for */
/*     the aqueous species distribution). */

/*        This code computes chemical models of aqueous solutions. */
/*     It is similar in that function to other codes such as WATEQ */
/*     and SOLMNEQ.  EQ3NR can be used by itself is the user desires */
/*     only to determine aqueous speciation and fluid-mineral saturation */
/*     relations.  The other usage of EQ3NR to front-end the EQ6 */
/*     code, which calculates reaction-progess models, including kinetic */
/*     models, of rock/water interaction. */

/*        Information is passed from  EQ3NR to EQ6 through a file called */
/*     PICKUP, which EQ3NR writes after processing a problem input. */
/*     PICKUP is then normally used as the bottom half of the EQ6 input */
/*     file, although it can be read separately by EQ6.  If an EQ3NR */
/*     run is to be used to iniitialize an EQ6 run, do not forget to */
/*     save the PICKUP file. */

/*        Solid-solution coding dealing only with molecular mixing */
/*     models exists and can be activated by setting the option */
/*     parameter iopt4 to 1 or 2. */

/*        The user defines the run parameters on the file called INPUT. */
/*     The file called DATA1 provides the basic supporting */
/*     thermodynamic, etc., data.  EQ3NR writes PICKUP and an output */
/*     file called OUTPUT. */

/*        The source code for EQ3NR is broken up into two files, */
/*     a .SRC file and a .INC file.  The .SRC file contains the */
/*     "source" of the main program and each subprogram.  It is */
/*     normally split into a set of .F files using the LLNL utility */
/*     GETALL.  The .INC file is normally split into a set of .H files */
/*     (INCLUDE files) using the LLNL utility GETINC.  Most of the .H */
/*     files contain common blocks.  PARSET.H contains the majo */
/*     dimensioning parameters.  IMPLICIT.H contains the standard */
/*     implicit statement (see below). */

/*        This code requires routines from the EQLIB library, which */
/*     is part of the EQ3/6 package. */

/*        This code has been written for use on 32 and 64 bit machines. */
/*     The standard implicit statement is located in the INCLUDE file */
/*     implicit.h (part of the .INC file). */

/*     The modification history has been moved to eq3nr.his. */

/*     This is a modified version of the code for doing DEW calculations. */
/*     Contact Simon Matthews (simonm at hi.is) for more information. */
/* ---------------------------------------------------------------------- */
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
/* eqlver.h */
/* -------------------------------------------------------------------- */
/* fg.h */
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
/* si.h */
/* -------------------------------------------------------------------- */
/* st.h */
/* -------------------------------------------------------------------- */
/* te.h */
/* -------------------------------------------------------------------- */
/* ti.h */

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
/* vw.h */

/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* zg.h */
/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlej.h */
/* -------------------------------------------------------------------- */
/* eqlelm.h */

/*     elam  triples */
/*      elam(1,i,j)   e lambda for charges i,j (abs values) */
/*      elam(2,i,j)   e lambda"    "        "     " */
/*      elam(3,i,j)   e lambda""   "        "     " */

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
/* eqlsz.h */
/*      izm = max(izmax,-izmin) */
/*      izoff =  index into szv of zero charge */

/* eqlsza.h */
/*      selm   =  array of sums (e lambda * concentration) */
/*                 for each charge */
/*      selmp   =  array of sums (e-lambda prime * concentration) */
/*                 for each charge */

/* -------------------------------------------------------------------- */

/* eqltxp.h */
/* -------------------------------------------------------------------- */

/*     note- timear is a special array used to obtain the user and cpu */
/*     times via the etime routine.  itself works on the sun 3's */
/*     and ridge 32's.  it may not work on other computers. */





/*     screwd and screwn are under-relaxation control parameters */


/*     table limits in common arrays */



/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     get time and date */

/* DAS      call timdat(udate0,utime0) */
/* DAS      timear(1)=SECNDS(0.0) */

/*     open files */

    openou_("output", "formatted", &un_1.noutpt, (ftnlen)6, (ftnlen)9);
    openin_("data1", "unformatted", &un_1.nad1, (ftnlen)5, (ftnlen)11);
    openin_("input", "formatted", &un_1.ninpt, (ftnlen)5, (ftnlen)9);

    openou_("inputs", "formatted", &ninpts, (ftnlen)6, (ftnlen)9);
    stripl_(&un_1.ninpt, &ninpts, &nleni);
    cl__1.cerr = 0;
    cl__1.cunit = un_1.ninpt;
    cl__1.csta = 0;
    f_clos(&cl__1);
    al__1.aerr = 0;
    al__1.aunit = ninpts;
    f_rew(&al__1);

/*     print version numbers and copyright notice */

    io___16.ciunit = un_1.noutpt;
    s_wsfe(&io___16);
    do_fio(&c__1, eqlver_1.urelno, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ustage, (ftnlen)8);
    e_wsfe();
    io___17.ciunit = un_1.nttyo;
    s_wsfe(&io___17);
    do_fio(&c__1, eqlver_1.urelno, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ustage, (ftnlen)8);
    e_wsfe();


/*     get eqlib release and stage number identification */

    eqlib_(eqlver_1.ueqlrn, eqlver_1.ueqlst, &un_1.noutpt, &un_1.nttyo, &
	    qtrue, &qfalse, (ftnlen)8, (ftnlen)8);

    io___20.ciunit = un_1.noutpt;
    s_wsfe(&io___20);
    do_fio(&c__1, utime0, (ftnlen)8);
    do_fio(&c__1, udate0, (ftnlen)8);
    e_wsfe();
    io___23.ciunit = un_1.nttyo;
    s_wsfe(&io___23);
    do_fio(&c__1, utime0, (ftnlen)8);
    do_fio(&c__1, udate0, (ftnlen)8);
    e_wsfe();

/*     initialize max values, array dimensions */

    ki_1.kmax = 100;
    nx_1.nxmdmx = 20;
    ti_1.ntitmx = 30;
    tt_1.nsqmax = 100;
    tt_1.nstmax = 750;
    tt_1.nrstmx = 679;
    tt_1.nmtmax = 750;
    tt_1.ngtmax = 15;
    tt_1.nxtmax = 20;
    tt_1.iktmax = 20;
    tt_1.nctmax = 70;
    tt_1.nsqmx1 = 101;
    tt_1.iapxmx = 12;
    narxmx = 5;
    ntprmx = 2;

/*     initialize some useful constants */

/*     gas constant = 1.98726 cal/mole-deg */
/*     volume of perfect gas at stp = 22413.6 cm3 */
/*     stp = 0 deg c and 1 atm pressure */
/*     faraday constant = 23062.3 cal/equiv-volt */

    eqlpp_1.rconst = 1.98726f;
    eqlpp_1.volg = 22413.6f;
    eqlpp_1.farad = 23062.3f;
    eqltxp_1.qtxppr = FALSE_;

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     initialize some arrays.  the label 20 is a return point for */
/*     processing another problem input. */

L20:

    i__1 = tt_1.nrstmx;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	i__2 = tt_1.nsqmx1;
	for (ns = 1; ns <= i__2; ++ns) {
	    _BLNK__1.cdrs[ns + nrs * 101 - 102] = 0.f;
/* L405: */
	}
/* L410: */
    }

    i__1 = tt_1.nstmax;
    for (ns = 1; ns <= i__1; ++ns) {
	i__2 = tt_1.nctmax;
	for (nc = 1; nc <= i__2; ++nc) {
	    _BLNK__1.cess[nc + ns * 70 - 71] = 0.f;
/* L412: */
	}
/* L414: */
    }

    i__1 = tt_1.nmtmax;
    for (nm = 1; nm <= i__1; ++nm) {
	i__2 = tt_1.nsqmx1;
	for (ns = 1; ns <= i__2; ++ns) {
	    _BLNK__1.cdrm[ns + nm * 101 - 102] = 0.f;
/* L415: */
	}
/* L420: */
    }

    i__1 = tt_1.ngtmax;
    for (ng = 1; ng <= i__1; ++ng) {
	i__2 = tt_1.nsqmx1;
	for (ns = 1; ns <= i__2; ++ns) {
	    _BLNK__1.cdrg[ns + ng * 101 - 102] = 0.f;
/* L425: */
	}
/* L430: */
    }

    i__1 = tt_1.nsqmax;
    for (ns = 1; ns <= i__1; ++ns) {
	ww_1.csp[ns - 1] = 0.f;
	ww_1.nsp[ns - 1] = 0;
	ww_1.nspec[ns - 1] = 0;
	s_copy(uqdel + (ns - 1 << 3), uconc, (ftnlen)8, (ftnlen)8);
	s_copy(uqbeta + (ns - 1 << 3), uconc, (ftnlen)8, (ftnlen)8);
/* L15: */
    }

    i__1 = tt_1.nctmax;
    for (nc = 1; nc <= i__1; ++nc) {
	jj_1.jcflag[nc - 1] = 0;
/* L12: */
    }

    i__1 = tt_1.nstmax;
    for (ns = 1; ns <= i__1; ++ns) {
	st_1.jsort[ns - 1] = ns;
	yy_1.conc[ns - 1] = 0.f;
	yy_1.conclg[ns - 1] = -999.f;
	yy_1.act[ns - 1] = 0.f;
	yy_1.actlg[ns - 1] = -999.f;
	ccp_1.glg[ns - 1] = 0.f;
	ccp_1.azero[ns - 1] = 0.f;
	ccp_1.hydn[ns - 1] = 0.f;
/* L1420: */
    }

    i__1 = tt_1.nxtmax;
    for (nx = 1; nx <= i__1; ++nx) {
	i__2 = tt_1.iktmax;
	for (ik = 1; ik <= i__2; ++ik) {
	    vv_1.xbar[ik + nx * 20 - 21] = 0.f;
	    uu_1.xbarlg[ik + nx * 20 - 21] = -999.f;
	    vv_1.lamlg[ik + nx * 20 - 21] = 0.f;
/* L3: */
	}
/* L7: */
    }

    i__1 = ki_1.kmax;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	zg_1.zvclg1[kcol - 1] = -999.f;
/* L201: */
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     read the problem input. */

    readx_(&un_1.ninpt, &qend); /* First arg changed from &ninpts*/


    if (qend) {

/*       get end time and date */

/* DAS        call timdat(udate1,utime1) */

	io___37.ciunit = un_1.noutpt;
	s_wsfe(&io___37);
	do_fio(&c__1, utime0, (ftnlen)8);
	do_fio(&c__1, udate0, (ftnlen)8);
	do_fio(&c__1, utime1, (ftnlen)8);
	do_fio(&c__1, udate1, (ftnlen)8);
	e_wsfe();
	io___40.ciunit = un_1.nttyo;
	s_wsfe(&io___40);
	do_fio(&c__1, utime0, (ftnlen)8);
	do_fio(&c__1, udate0, (ftnlen)8);
	do_fio(&c__1, utime1, (ftnlen)8);
	do_fio(&c__1, udate1, (ftnlen)8);
	e_wsfe();

/*       the etime call below works on sun 3's and ridge 32's. */
/*       it may not work on other machines. */

/*       timdum = SECNDS(timear(1)) */
	timdum = 0.f;
	io___42.ciunit = un_1.noutpt;
	s_wsfe(&io___42);
	do_fio(&c__1, (char *)&timdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___43.ciunit = un_1.nttyo;
	s_wsfe(&io___43);
	do_fio(&c__1, (char *)&timdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* c        timdum = etime(timear) */
/* c        write (noutpt,1211) (timear(n), n=1,2) */
/* c        write (nttyo,1211) (timear(n), n=1,2) */
/* c 1211   format(/10x,'user time = ',f10.3,/10x,' cpu time = ',f10.3) */

	if (op2_1.iodb1 == 0) {
	    cl__1.cerr = 0;
	    cl__1.cunit = ninpts;
	    cl__1.csta = "delete";
	    f_clos(&cl__1);
	}
	io___44.ciunit = un_1.noutpt;
	s_wsfe(&io___44);
	e_wsfe();
	io___45.ciunit = un_1.nttyo;
	s_wsfe(&io___45);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    gntpr_(&hh_1.tempc, &eqlpp_1.al10, &eqlpp_1.rconst, &eqlpp_1.farad, &
	    hh_1.tempk, &eqlpp_1.afcnst, &eqlpp_1.ehfac, &hh_1.ntpr, &
	    eqlgp_1.iopg8);

    if (op_1.iopt3 != -1) {
	ioin__1.inerr = 0;
	ioin__1.infilen = 6;
	ioin__1.infile = "pickup";
	ioin__1.inex = 0;
	ioin__1.inopen = &qop;
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
	if (! qop) {
	    openou_("pickup", "formatted", &un_1.npkup, (ftnlen)6, (ftnlen)9);
	}
    }
    if (op2_1.iodb7 > 0) {
	ioin__1.inerr = 0;
	ioin__1.infilen = 5;
	ioin__1.infile = "rlist";
	ioin__1.inex = 0;
	ioin__1.inopen = &qop;
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
	if (! qop) {
	    openou_("rlist", "formatted", &un_1.nrlst, (ftnlen)5, (ftnlen)9);
	}
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     get name of the option for estimating the activity coefficients */
/*     of aqueous species */

    nactop_();

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     read the supporting data file data1 */

    indatx_(_BLNK__1.cess, _BLNK__1.cdrs, _BLNK__1.cdrm, _BLNK__1.cdrg, 
	    st_1.cstor, ac2, awo, ars, amn, ags, apress, aadh, abdh, abdot, 
	    aeh, vv_1.apx, vv_1.xbar, uu_1.xbarlg, uu_1.xbarlm, ccp_1.z__, 
	    ccp_1.titr, ccp_1.azero, ccp_1.hydn, oo_1.mwtss, oo_1.atwt, 
	    nx_1.xlkmod, &hh_1.tempc, &hh_1.press, &eqlpp_1.afcnst, 
	    uuc_1.ussnp, tec_1.udrxd, gg_1.uspec, gg_1.umin, gg_1.ugas, 
	    gg_1.usolx, gg_1.uelem, nxc_1.uxmod, tic_1.utitld, jjc_1.uredox, 
	    an_1.nend, jj_1.jflag, jj_1.jcflag, vv_1.ncomp, vv_1.jsol, &
	    nx_1.nxmod, nx_1.jxmod, nx_1.kxmod, &op_1.iopt8, &op1_1.iopr1, &
	    op2_1.iodb1, &tt_1.nct, &tt_1.nsb, &tt_1.nsb1, &tt_1.nsq, &
	    tt_1.nsq1, &tt_1.nsqb, &tt_1.nst, &tt_1.nrst, &tt_1.nmt, &
	    tt_1.ngt, &tt_1.nxt, &si_1.ist, &si_1.irst, &si_1.imt, &si_1.igt, 
	    &hh_1.ntpr, &tt_1.nctmax, &tt_1.nsqmax, &tt_1.nsqmx1, &
	    tt_1.nstmax, &tt_1.nmtmax, &tt_1.ngtmax, &tt_1.nxtmax, &
	    tt_1.iktmax, &narxmx, &ntprmx, &tt_1.iapxmx, &un_1.noutpt, &
	    un_1.nttyo, &un_1.nad1, &un_1.nahv, (ftnlen)24, (ftnlen)24, (
	    ftnlen)24, (ftnlen)24, (ftnlen)24, (ftnlen)24, (ftnlen)8, (ftnlen)
	    24, (ftnlen)80, (ftnlen)24);

/*     get the indices of the hydrogen and chloride ions */

    gspion_(gg_1.uspec, &tt_1.nst, &tu_1.nhydr, &tu_1.nchlor, (ftnlen)24);

/*     set species status flags */

    flgstx_(ars, amn, ags, gg_1.uspec, gg_1.umin, gg_1.ugas, gg_1.usolx, 
	    nxc_1.uxmod, ka_1.jkflag, an_1.nend, ka_1.jsflag, ka_1.jmflag, 
	    ka_1.jgflag, ka_1.jxflag, jj_1.jflag, vv_1.ncomp, nx_1.jxmod, 
	    nx_1.kxmod, &op_1.iopt4, &si_1.jst, &si_1.jmt, &si_1.jgt, &
	    si_1.jxt, &nx_1.nxmod, &hh_1.ntpr, &tt_1.nsb, &tt_1.nsq, &
	    tt_1.nst, &tt_1.nrst, &tt_1.nmt, &tt_1.ngt, &tt_1.nxt, &
	    tt_1.iktmax, &narxmx, &ntprmx, &un_1.noutpt, &un_1.nttyo, (ftnlen)
	    24, (ftnlen)24, (ftnlen)24, (ftnlen)24, (ftnlen)24);

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     compute the thermodynamic parameters that are functions of */
/*     temperature and pressure */

    evdata_(&hh_1.tempc, &hh_1.press, ars, amn, ags, ac2, awo, apress, aadh, 
	    abdh, abdot, aeh, vv_1.apx, an_1.w, xx_1.xlks, xx_1.xlkm, 
	    xx_1.xlkg, eqlej_1.cco2, eqlej_1.ch2o, &eqlpp_1.al10, &
	    eqlpp_1.rconst, &eqlpp_1.ehfac, &hh_1.tempk, &pgrid, &eqldd_1.adh,
	     &eqldd_1.bdh, &eqldd_1.bdot, &xx_1.xlkeh, &eqldd_1.aphi, &
	    eqldd_1.bt, gg_1.uspec, gg_1.usolx, vv_1.jsol, &op_1.iopt1, &
	    op_1.iopt4, &eqlgp_1.iopg1, &tt_1.nrst, &tt_1.nst, &tt_1.nmt, &
	    tt_1.ngt, &tt_1.nxt, &hh_1.ntpr, &narxmx, &ntprmx, &tt_1.iktmax, &
	    tt_1.iapxmx, &un_1.noutpt, &un_1.nttyo, (ftnlen)24, (ftnlen)24);

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    eqlpp_1.om = 1e3f / oo_1.mwtss[0];
    eqlpp_1.omi = 1.f / eqlpp_1.om;
    eqlpp_1.omlg = d_lg10(&eqlpp_1.om);
    cc_1.shmlim = eqlpp_1.om - 1.f;

/*     make up z*z/2  for later use */

    i__1 = tt_1.nst;
    for (ns = 1; ns <= i__1; ++ns) {
	zz = ccp_1.z__[ns - 1];
	ccp_1.zsq2[ns - 1] = zz * zz / 2.f;
/* L58: */
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     if not using pitzer equations then skip next sections */

    if (eqlgp_1.iopg1 != 1) {
	if (op1_1.iopr9 != 0) {
	    io___59.ciunit = un_1.noutpt;
	    s_wsfe(&io___59);
	    e_wsfe();
	    op1_1.iopr9 = 0;
	}
	goto L57;
    }

/*     read the pitzer parameters.  note that this call must follow */
/*     call to indatx */

    inupt_(gg_1.uspec, ka_1.jsflag, &un_1.nad1, &tt_1.nst, &op1_1.iopr9, (
	    ftnlen)24);

    if (op_1.iopt8 == 1) {
	getlu_(&un_1.nahv, &nerr);
	if (nerr != 0) {
	    io___61.ciunit = un_1.nttyo;
	    s_wsfe(&io___61);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	o__1.oerr = 1;
	o__1.ounit = un_1.nahv;
	o__1.ofnmlen = 3;
	o__1.ofnm = "ahv";
	o__1.orl = 0;
	o__1.osta = "old";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L904;
	}
	goto L62;

L904:
	io___62.ciunit = un_1.nttyo;
	s_wsfe(&io___62);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
L62:

    io___63.ciunit = un_1.noutpt;
    s_wsfe(&io___63);
    e_wsfe();

/*     build s-lambda index arrays */

    bdslx_(&tt_1.nst);

/*     build mu index arrays */

    bdmlx_(&tt_1.nst);

L57:

/*              read in hkf data if iopg1 = 5 */
    if (eqlgp_1.iopg1 == 5) {
	hkfrd_(gg_1.uspec, ka_1.jsflag, &un_1.nad1, &tt_1.nst, (ftnlen)24);
    }

/*     get charge constants */

    zsrt_(ccp_1.z__, &tt_1.nst, ka_1.jsflag, &izm, &izoff);

/*     set zero charge values of e-lambda sums to zero */

    eqlsza_1.selm[izoff - 1] = 0.f;
    eqlsza_1.selmp[izoff - 1] = 0.f;

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     check default redox constraints for conflicts */

    isb = 0;
    i__1 = tt_1.nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	is = ww_1.nspec[ns - 1];
	if (is == tt_1.nsb) {
	    isb = ns;
	    goto L102;
	}
/* L101: */
    }
L102:

    jfdum = jj_1.jflag[tt_1.nsb - 1];
    if (op_1.iopt1 != -3 && jfdum != 0) {
	io___69.ciunit = un_1.noutpt;
	s_wsfe(&io___69);
	e_wsfe();
	io___70.ciunit = un_1.noutpt;
	s_wsfe(&io___70);
	do_fio(&c__1, (char *)&op_1.iopt1, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	e_wsfe();
	jj_1.jflag[tt_1.nsb - 1] = 0;
	ww_1.csp[tt_1.nsb - 1] = -999.f;
	ww_1.nsp[tt_1.nsb - 1] = 0;
	ww_1.jflagb[isb - 1] = 0;
	ww_1.cspb[isb - 1] = -999.f;
	s_copy(wwc_1.uphas1 + (tt_1.nsb - 1) * 24, ublank, (ftnlen)24, (
		ftnlen)8);
	s_copy(wwc_1.uphas2 + (tt_1.nsb - 1) * 24, ublank, (ftnlen)24, (
		ftnlen)8);
    }

    if (op_1.iopt1 != 1 && s_cmp(jjc_1.uredox, ublank, (ftnlen)8, (ftnlen)8) 
	    != 0) {
	io___71.ciunit = un_1.noutpt;
	s_wsfe(&io___71);
	e_wsfe();
	io___72.ciunit = un_1.noutpt;
	s_wsfe(&io___72);
	do_fio(&c__1, (char *)&op_1.iopt1, (ftnlen)sizeof(integer));
	do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
	e_wsfe();
	s_copy(jjc_1.uredox, ublank, (ftnlen)24, (ftnlen)8);
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     set default values */

    if (ps_1.itermx <= 0) {
	ps_1.itermx = 30;
    }
    if (jj_1.rho == 0.f) {
	jj_1.rho = 1.f;
    }
    if (jj_1.tdspkg < 0.f) {
	jj_1.tdspkg = 0.f;
    }
    if (jj_1.tdspl < 0.f) {
	jj_1.tdspl = 0.f;
    }
    if (ps_1.tolbt <= 0.f) {
	ps_1.tolbt = 1e-6f;
    }
    if (ps_1.toldl <= 0.f) {
	ps_1.toldl = 1e-6f;
    }
    if (ps_1.tolsat <= 0.f) {
	ps_1.tolsat = .5f;
    }
    ps_1.tolxat = ps_1.tolsat * .1f;

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     print an echo of the processed card data on the aqueous solution */

    echox_();

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     call routine setup to convert concentration data not on */
/*     the molal scale to that scale. */

    setup_();

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     find the index of the species (na+ or cl-) that is to define the */
/*     equivalent stoichiometric ionic strength of a sodium chloride */
/*     solution.  choose one if necessary. */

    ee_1.iacion = 0;
    if (eqlgp_1.iopg1 != 0) {
	goto L239;
    }
    s_copy(utemp, unone, (ftnlen)24, (ftnlen)8);
    s_copy(udum1, unone, (ftnlen)8, (ftnlen)8);
    s_copy(udum2, ublank, (ftnlen)8, (ftnlen)8);
    cdum1 = 0.f;
    cdum2 = 0.f;

    if (s_cmp(eec_1.uacion, ublank, (ftnlen)8, (ftnlen)8) == 0) {
	goto L233;
    }
    tu_1.nsodiu = 0;
    i__1 = tt_1.nst;
    for (ns = 2; ns <= i__1; ++ns) {
	if (s_cmp(gg_1.uspec + (ns - 1) * 24, usodiu, (ftnlen)8, (ftnlen)8) ==
		 0) {
	    tu_1.nsodiu = ns;
	    goto L210;
	}
/* L208: */
    }
L210:
    if (tu_1.nsodiu > 0) {
	cdum1 = ww_1.csp[tu_1.nsodiu - 1];
	jfdum = jj_1.jflag[tu_1.nsodiu - 1];
	if (jfdum != 0) {
	    cdum1 = 0.f;
	}
	if (ww_1.ibasis[tu_1.nsodiu - 1] != tu_1.nsodiu) {
	    cdum1 = 0.f;
	}
    }

    if (tu_1.nchlor > 0) {
	cdum2 = ww_1.csp[tu_1.nchlor - 1];
	jfdum = jj_1.jflag[tu_1.nchlor - 1];
	if (jfdum != 0) {
	    cdum2 = 0.f;
	}
	if (ww_1.ibasis[tu_1.nchlor - 1] != tu_1.nchlor) {
	    cdum2 = 0.f;
	}
    }

    if (cdum1 <= 0. && cdum2 <= 0.) {
	goto L233;
    }
    if (s_cmp(eec_1.uacion, upick1, (ftnlen)8, (ftnlen)8) == 0) {
	goto L357;
    }

    if (s_cmp(eec_1.uacion, gg_1.uspec + (tu_1.nsodiu - 1) * 24, (ftnlen)8, (
	    ftnlen)8) == 0) {
	if (cdum1 <= 0.f) {
	    goto L357;
	}
	ee_1.iacion = tu_1.nsodiu;
	goto L360;
    } else if (s_cmp(eec_1.uacion, gg_1.uspec + (tu_1.nchlor - 1) * 24, (
	    ftnlen)8, (ftnlen)8) == 0) {
	if (cdum2 <= 0.f) {
	    goto L357;
	}
	ee_1.iacion = tu_1.nchlor;
	goto L360;
    }

/*     try to pick an ion. */

L357:
    ee_1.iacion = tu_1.nsodiu;
    if (cdum1 < cdum2) {
	ee_1.iacion = tu_1.nchlor;
    }
L360:
    s_copy(utemp, gg_1.uspec + (ee_1.iacion - 1) * 24, (ftnlen)24, (ftnlen)24)
	    ;
L233:
    s_copy(eec_1.uacion, utemp, (ftnlen)24, (ftnlen)24);
    io___78.ciunit = un_1.noutpt;
    s_wsfe(&io___78);
    do_fio(&c__1, utemp, (ftnlen)24);
    e_wsfe();

L239:

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     find the index of the species to be adjusted for electrical */
/*     balance, if any.  choose one if necessary. */

    ee_1.iebal = 0;
    if (s_cmp(eec_1.uebal, ublank, (ftnlen)8, (ftnlen)8) == 0) {
	goto L387;
    }
    if (s_cmp(eec_1.uebal, unone, (ftnlen)8, (ftnlen)8) == 0) {
	goto L387;
    }
    if (s_cmp(eec_1.uebal, upick1, (ftnlen)8, (ftnlen)8) == 0) {
	goto L370;
    }

    i__1 = tt_1.nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	if (s_cmp(eec_1.uebal, gg_1.uspec + (ns - 1) * 24, (ftnlen)18, (
		ftnlen)18) == 0) {
	    ee_1.iebal = ns;
	    goto L858;
	}
/* L857: */
    }

    io___79.ciunit = un_1.noutpt;
    s_wsfe(&io___79);
    do_fio(&c__1, eec_1.uebal, (ftnlen)24);
    e_wsfe();
    goto L370;

/*        does the ion selected for electrical balancing have charge */

L858:
    if (ccp_1.z__[ee_1.iebal - 1] == 0.f) {
	io___80.ciunit = un_1.noutpt;
	s_wsfe(&io___80);
	do_fio(&c__1, eec_1.uebal, (ftnlen)24);
	e_wsfe();
	goto L370;
    }

/*        is the ion selected for electrical balancing in the model */

    if (ka_1.jsflag[ee_1.iebal - 1] <= 0) {
	goto L385;
    }
    io___81.ciunit = un_1.noutpt;
    s_wsfe(&io___81);
    do_fio(&c__1, eec_1.uebal, (ftnlen)24);
    e_wsfe();

/*        pick an ion for electrical balancing. */

L370:
    io___82.ciunit = un_1.noutpt;
    s_wsfe(&io___82);
    e_wsfe();
    ee_1.iebal = 0;
    charge = 0.f;
    i__1 = tt_1.nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	if (jj_1.jflag[ns - 1] != 0) {
	    goto L380;
	}
	zdum = ccp_1.z__[ns - 1];
	if (zdum == 0.f) {
	    goto L380;
	}
	if (ns != ww_1.ibasis[ns - 1]) {
	    goto L380;
	}
	cdum = ww_1.csp[ns - 1];
	if (cdum <= 0.f) {
	    goto L380;
	}
	charg1 = (d__1 = cdum * zdum, abs(d__1));
	if (charg1 > charge) {
	    charge = charg1;
	    ee_1.iebal = ns;
	}
L380:
	;
    }

    if (ee_1.iebal <= 0) {
	io___87.ciunit = un_1.noutpt;
	s_wsfe(&io___87);
	e_wsfe();
	goto L387;
    } else {
	s_copy(eec_1.uebal, gg_1.uspec + (ee_1.iebal - 1) * 24, (ftnlen)24, (
		ftnlen)24);
    }

L385:

    io___88.ciunit = un_1.noutpt;
    s_wsfe(&io___88);
    do_fio(&c__1, eec_1.uebal, (ftnlen)24);
    e_wsfe();

L387:

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*       temporary fix pending incorporation of the auxiliary basis */
/*         concept into eq6.  save the names of the basis species as they */
/*         were read off the data file. */
    i__1 = tt_1.nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	s_copy(usave + (ns - 1) * 24, gg_1.uspec + (ns - 1) * 24, (ftnlen)24, 
		(ftnlen)24);
/* L505: */
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     call routine switch to perform basis switching.  at this point */
/*     (before the call to routine elim) do only those switches which */
/*     pair a species in the strict basis with a species in the auxiliary */
/*     basis.  the other switches are executed after the call to */
/*     routine elim.  the species h2o, h+, and uacion (na+ or cl-) */
/*     can not be switched. */

/*     a switch that pairs a strict basis species with an auxiliary */
/*     basis species is termed discretionary if the jflag of the */
/*     species that ends up in the auxiliary basis is not 30. */
/*     discretionary switches are forgotten as soon as they are */
/*     executed (i.e., the record in the ibasis array is wiped */
/*     clean).  the record of all other switches is maintained. */

    if (op2_1.iodb7 >= 1) {
	echolk_(&c__1, &un_1.nrlst, &hh_1.tempc, &hh_1.press, _BLNK__1.cdrs, 
		_BLNK__1.cdrm, _BLNK__1.cdrg, ars, amn, ags, xx_1.xlks, 
		xx_1.xlkm, xx_1.xlkg, gg_1.uspec, gg_1.umin, gg_1.ugas, 
		ka_1.jsflag, ka_1.jmflag, ka_1.jgflag, &tt_1.nsb, &tt_1.nsq, &
		tt_1.nsq1, &tt_1.nrst, &tt_1.nst, &tt_1.nmt, &tt_1.ngt, &
		tt_1.nxt, &hh_1.ntpr, &tt_1.nsqmx1, &narxmx, &ntprmx, (ftnlen)
		24, (ftnlen)24, (ftnlen)24);
    }

    ww_1.qbassw = FALSE_;
    nerr = 0;
    i__1 = tt_1.nsq;
    for (ns1 = 2; ns1 <= i__1; ++ns1) {
	ns2 = ww_1.ibasis[ns1 - 1];
	if (ns2 > tt_1.nsq) {
	    goto L1160;
	}
	if (ns2 <= ns1) {
	    goto L1160;
	}
	switch_(&ns1, &ns2, &c__3, ars, amn, ags, _BLNK__1.cess, 
		_BLNK__1.cdrs, _BLNK__1.cdrm, _BLNK__1.cdrg, cxistq, 
		oo_1.mwtss, ccp_1.z__, ccp_1.zsq2, ccp_1.titr, ccp_1.azero, 
		ccp_1.hydn, ww_1.csp, gg_1.uspec, jj_1.jflag, ka_1.jsflag, 
		ww_1.ibasis, ww_1.nsp, &eqlgp_1.iopg1, &ee_1.iacion, &
		ee_1.iebal, &tu_1.nhydr, &tu_1.nchlor, &tt_1.nct, &tt_1.nsb, &
		tt_1.nsq, &tt_1.nsq1, &tt_1.nst, &tt_1.nrst, &tt_1.nmt, &
		tt_1.ngt, &tt_1.nctmax, &tt_1.nsqmx1, &narxmx, &ntprmx, &nerr,
		 &un_1.noutpt, &un_1.nttyo, &eqlgpa_1.qhydth, &eqlgpa_1.qpt4, 
		&ww_1.qbassw, (ftnlen)24);

	jdum = ka_1.jsflag[ns1 - 1];
	ka_1.jsflag[ns1 - 1] = ka_1.jsflag[ns2 - 1];
	ka_1.jsflag[ns2 - 1] = jdum;
	cdum = st_1.cstor[ns1 - 1];
	st_1.cstor[ns1 - 1] = st_1.cstor[ns2 - 1];
	st_1.cstor[ns2 - 1] = cdum;
	cdum = st_1.cstor[ns1 + 749];
	st_1.cstor[ns1 + 749] = st_1.cstor[ns2 + 749];
	st_1.cstor[ns2 + 749] = cdum;
	if (jj_1.jflag[ns2 - 1] == 30) {
	    goto L1160;
	}
	ww_1.ibasis[ns1 - 1] = ns1;
	ww_1.ibasis[ns2 - 1] = ns2;
L1160:
	;
    }
    if (ee_1.iebal != 0) {
	ee_1.iebal = ww_1.ibasis[ee_1.iebal - 1];
    }

    if (nerr > 0) {
	io___94.ciunit = un_1.noutpt;
	s_wsfe(&io___94);
	e_wsfe();
	io___95.ciunit = un_1.nttyo;
	s_wsfe(&io___95);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     print a list of inactive species */

    io___96.ciunit = un_1.noutpt;
    s_wsfe(&io___96);
    e_wsfe();
    ns3 = 0;
    s_copy(tec_1.unam24, unone, (ftnlen)24, (ftnlen)8);

    i__1 = tt_1.nst;
    for (ns = 1; ns <= i__1; ++ns) {
	jdum = ka_1.jsflag[ns - 1];
	if (jdum >= 3) {
	    goto L220;
	}
	if (jdum <= 0) {
	    goto L220;
	}
	if (ns == tt_1.nsb) {
	    goto L220;
	}
	++ns3;
	s_copy(tec_1.unam24 + (ns3 - 1) * 24, gg_1.uspec + (ns - 1) * 24, (
		ftnlen)24, (ftnlen)24);
	if (ns3 == 4) {
	    io___98.ciunit = un_1.noutpt;
	    s_wsfe(&io___98);
	    i__2 = ns3;
	    for (n = 1; n <= i__2; ++n) {
		do_fio(&c__1, tec_1.unam24 + (n - 1) * 24, (ftnlen)24);
	    }
	    e_wsfe();
	    ns3 = 0;
	}
L220:
	;
    }

    if (ns3 > 0) {
	io___100.ciunit = un_1.noutpt;
	s_wsfe(&io___100);
	i__1 = ns3;
	for (n = 1; n <= i__1; ++n) {
	    do_fio(&c__1, tec_1.unam24 + (n - 1) * 24, (ftnlen)24);
	}
	e_wsfe();
    }
    io___101.ciunit = un_1.noutpt;
    s_wsfe(&io___101);
    e_wsfe();

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     if iopt1.ge.1, find the index of the reaction associated with */
/*     the species whose name is uredox. */

    if (op_1.iopt1 >= 1) {
	i__1 = tt_1.nsq;
	for (ns = tt_1.nsb1; ns <= i__1; ++ns) {
	    if (s_cmp(gg_1.uspec + (ns - 1) * 24, jjc_1.uredox, (ftnlen)18, (
		    ftnlen)18) == 0) {
		op_1.iopt1 = ns - tt_1.nsb;
		goto L2200;
	    }
/* L2225: */
	}

	io___102.ciunit = un_1.noutpt;
	s_wsfe(&io___102);
	do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
	e_wsfe();
	io___103.ciunit = un_1.nttyo;
	s_wsfe(&io___103);
	do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
L2200:

/*     check to see that no species in the strict basis has a jflag */
/*     value of 30 at this point. */

    nerr = 0;
    i__1 = tt_1.nsb;
    for (ns = 1; ns <= i__1; ++ns) {
	if (jj_1.jflag[ns - 1] == 30) {
	    io___104.ciunit = un_1.noutpt;
	    s_wsfe(&io___104);
	    do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&jj_1.jflag[ns - 1], (ftnlen)sizeof(integer)
		    );
	    e_wsfe();
	    io___105.ciunit = un_1.nttyo;
	    s_wsfe(&io___105);
	    do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&jj_1.jflag[ns - 1], (ftnlen)sizeof(integer)
		    );
	    e_wsfe();
	    ++nerr;
	}
/* L1250: */
    }

    if (nerr >= 1) {
	io___106.ciunit = un_1.noutpt;
	s_wsfe(&io___106);
	e_wsfe();
	io___107.ciunit = un_1.nttyo;
	s_wsfe(&io___107);
	e_wsfe();
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     call routine elim to rewrite the reaction equations (cdr- */
/*     arrays) so that auxiliary basis variables with jflag=30 */
/*     are eliminated in all reactions except cross-link reactions. */

    qelim = FALSE_;
    i__1 = tt_1.nsq;
    for (nse = tt_1.nsb1; nse <= i__1; ++nse) {
	if (jj_1.jflag[nse - 1] == 30) {
	    if (ka_1.jsflag[nse - 1] > 0) {
		ww_1.csp[nse - 1] = 0.f;
	    } else {
		qelim = TRUE_;
		elim_(&nse, ars, amn, ags, _BLNK__1.cdrs, _BLNK__1.cdrm, 
			_BLNK__1.cdrg, &eqleps_1.eps100, &tt_1.nsb, &
			tt_1.nsq1, &tt_1.nrst, &tt_1.nmt, &tt_1.ngt, &
			tt_1.nsqmx1, &narxmx, &ntprmx, &un_1.noutpt, &
			un_1.nttyo);
	    }
	}
/* L1257: */
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     call routine switch to perform basis switching.  at this point */
/*     do those switches which bring non-basis species into the expanded */
/*     basis. */

    nerr = 0;
    i__1 = tt_1.nsq;
    for (ns1 = 2; ns1 <= i__1; ++ns1) {
	ns2 = ww_1.ibasis[ns1 - 1];
	if (ns2 > tt_1.nsq && ns2 > ns1) {
	    switch_(&ns1, &ns2, &c__3, ars, amn, ags, _BLNK__1.cess, 
		    _BLNK__1.cdrs, _BLNK__1.cdrm, _BLNK__1.cdrg, cxistq, 
		    oo_1.mwtss, ccp_1.z__, ccp_1.zsq2, ccp_1.titr, 
		    ccp_1.azero, ccp_1.hydn, ww_1.csp, gg_1.uspec, jj_1.jflag,
		     ka_1.jsflag, ww_1.ibasis, ww_1.nsp, &eqlgp_1.iopg1, &
		    ee_1.iacion, &ee_1.iebal, &tu_1.nhydr, &tu_1.nchlor, &
		    tt_1.nct, &tt_1.nsb, &tt_1.nsq, &tt_1.nsq1, &tt_1.nst, &
		    tt_1.nrst, &tt_1.nmt, &tt_1.ngt, &tt_1.nctmax, &
		    tt_1.nsqmx1, &narxmx, &ntprmx, &nerr, &un_1.noutpt, &
		    un_1.nttyo, &eqlgpa_1.qhydth, &eqlgpa_1.qpt4, &
		    ww_1.qbassw, (ftnlen)24);

	    ww_1.ibasis[ns2 - 1] = ns1;
	}
/* L1260: */
    }

    if (nerr > 0) {
	io___110.ciunit = un_1.noutpt;
	s_wsfe(&io___110);
	e_wsfe();
	io___111.ciunit = un_1.nttyo;
	s_wsfe(&io___111);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    if (op2_1.iodb7 >= 1) {
	echolk_(&c__1, &un_1.nrlst, &hh_1.tempc, &hh_1.press, _BLNK__1.cdrs, 
		_BLNK__1.cdrm, _BLNK__1.cdrg, ars, amn, ags, xx_1.xlks, 
		xx_1.xlkm, xx_1.xlkg, gg_1.uspec, gg_1.umin, gg_1.ugas, 
		ka_1.jsflag, ka_1.jmflag, ka_1.jgflag, &tt_1.nsb, &tt_1.nsq, &
		tt_1.nsq1, &tt_1.nrst, &tt_1.nst, &tt_1.nmt, &tt_1.ngt, &
		tt_1.nxt, &hh_1.ntpr, &tt_1.nsqmx1, &narxmx, &ntprmx, (ftnlen)
		24, (ftnlen)24, (ftnlen)24);
    }


/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     echo input data after modification. */

    io___112.ciunit = un_1.noutpt;
    s_wsfe(&io___112);
    e_wsfe();
    i__1 = tt_1.nsq;
    for (nse = 2; nse <= i__1; ++nse) {
	jk = jj_1.jflag[nse - 1];
	if (jk < 0) {
	    if (nse <= tt_1.nct) {
		goto L1150;
	    }
	    nrs = nse - tt_1.nsb;
	    i__2 = tt_1.nsq;
	    for (ns = 2; ns <= i__2; ++ns) {
		if (_BLNK__1.cdrs[ns + nrs * 101 - 102] != 0.f) {
		    if (jj_1.jflag[ns - 1] <= -1) {
			goto L1150;
		    }
		}
/* L305: */
	    }
	}

	cdum = ww_1.csp[nse - 1];
	k = jk + 1;
	if (jk == 19) {
	    nm = ww_1.nsp[nse - 1];
	    io___115.ciunit = un_1.noutpt;
	    s_wsfe(&io___115);
	    do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
	    do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)24);
	    prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
		    tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
		    ftnlen)24);

	    goto L1150;
	}

	if (jk == 20) {
	    ndum = ww_1.nsp[nse - 1];
	    ndum += -50000;
	    nx = (integer) (ndum / 100.f);
	    ik = ndum - nx * 100;
	    nm = an_1.nend[ik + nx * 20 - 21];
	    io___118.ciunit = un_1.noutpt;
	    s_wsfe(&io___118);
	    do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
	    do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)24);
	    prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
		    tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
		    ftnlen)24);
	    goto L1150;
	}

	if (jk == 21) {
	    ng = ww_1.nsp[nse - 1];
	    io___119.ciunit = un_1.noutpt;
	    s_wsfe(&io___119);
	    do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
	    do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, gg_1.ugas + (ng - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    s_copy(unamsp, gg_1.ugas + (ng - 1) * 24, (ftnlen)24, (ftnlen)24);
	    prreac_(_BLNK__1.cdrg, gg_1.uspec, unamsp, &ng, &tt_1.nsq, &
		    tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
		    ftnlen)24);
	    io___120.ciunit = un_1.noutpt;
	    s_wsfe(&io___120);
	    do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
	    do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    goto L1150;
	}

	if (nse != tt_1.nsb) {
	    if (k > 0) {
		io___121.ciunit = un_1.noutpt;
		s_wsfe(&io___121);
		do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
		do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
		e_wsfe();
		goto L1150;
	    } else {
		io___122.ciunit = un_1.noutpt;
		s_wsfe(&io___122);
		do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
		e_wsfe();
	    }
	}

L1150:
	;
    }

    io___123.ciunit = un_1.noutpt;
    s_wsfe(&io___123);
    e_wsfe();

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     call lamda to compute activity coefficients of solid-solution */
/*     end-members. */

    if (op_1.iopt4 == 2) {
	i__1 = tt_1.nxt;
	for (nx = 1; nx <= i__1; ++nx) {
	    lamda_(&eqlpp_1.al10, vv_1.jsol, vv_1.lamlg, vv_1.ncomp, &nx, &
		    eqlpp_1.rconst, &hh_1.tempk, vv_1.xbar, an_1.w, &
		    tt_1.iktmax);
/* L363: */
	}
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     the following section is an attempt at idiot-proofing.  it is */
/*     intended to catch the most likely errors that users are likely to */
/*     make and thus spare the author of this code the blame).  idiots */
/*     are generally creative, however.  there is no guarantee that */
/*     the following section will flag all bad input. */

/*     nwarn accumulates the no. of errors.  if nwarn has a final value */
/*     which is not zero, the computation is terminated. */

    nwarn = 0;

/*     if using hydration theory, are there any non-zero hydration */
/*     numbers */

    if (eqlgpa_1.qhydth) {
	i__1 = tt_1.nst;
	for (ns = 2; ns <= i__1; ++ns) {
	    if (ccp_1.hydn[ns - 1] > 0.f) {
		goto L368;
	    }
/* L367: */
	}
	io___125.ciunit = un_1.noutpt;
	s_wsfe(&io___125);
	e_wsfe();
	io___126.ciunit = un_1.nttyo;
	s_wsfe(&io___126);
	e_wsfe();
	++nwarn;
    }
L368:

/*     check the iopt1.eq.-3 option for the needed input constraints. */

    if (op_1.iopt1 == -3) {
	jfdum = jj_1.jflag[tt_1.nsb - 1];
	if (jfdum != 19 && jfdum != 20 && jfdum != 21) {
	    io___127.ciunit = un_1.noutpt;
	    s_wsfe(&io___127);
	    e_wsfe();
	    io___128.ciunit = un_1.nttyo;
	    s_wsfe(&io___128);
	    e_wsfe();
	    ++nwarn;
	    goto L2020;
	}
    }

/*     check the iopt1.ge.1 option to make sure it implies a redox */
/*     reaction */

    if (op_1.iopt1 <= 0) {
	goto L2020;
    }

    ns = op_1.iopt1 + tt_1.nsb;
    if (_BLNK__1.cdrs[tt_1.nsb + op_1.iopt1 * 101 - 102] == 0.f) {
	io___129.ciunit = un_1.noutpt;
	s_wsfe(&io___129);
	do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
	e_wsfe();
	io___130.ciunit = un_1.nttyo;
	s_wsfe(&io___130);
	do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
	e_wsfe();
	s_copy(unamsp, gg_1.uspec + (ns - 1) * 24, (ftnlen)24, (ftnlen)24);
	prreac_(_BLNK__1.cdrs, gg_1.uspec, unamsp, &op_1.iopt1, &tt_1.nsq, &
		tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (ftnlen)24)
		;
	prreac_(_BLNK__1.cdrs, gg_1.uspec, unamsp, &op_1.iopt1, &tt_1.nsq, &
		tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (ftnlen)24);
	++nwarn;
    }

/*     check for the needed input constraints on the iopt1.ge.1 option. */

    if (jj_1.jflag[ns - 1] < 16) {
	if (ww_1.csp[ns - 1] > 0.f) {
	    goto L1290;
	}
	io___131.ciunit = un_1.noutpt;
	s_wsfe(&io___131);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___132.ciunit = un_1.nttyo;
	s_wsfe(&io___132);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	++nwarn;
	goto L1290;
    }

    if (jj_1.jflag[ns - 1] == 27 || jj_1.jflag[ns - 1] == 30) {
	io___133.ciunit = un_1.noutpt;
	s_wsfe(&io___133);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&jj_1.jflag[ns - 1], (ftnlen)sizeof(integer));
	e_wsfe();
	++nwarn;
    }

L1290:

    s_copy(udum1, gg_1.uspec + (ns - 1) * 24, (ftnlen)8, (ftnlen)8);
    if (s_cmp(udum1, uo2aq, (ftnlen)8, (ftnlen)8) != 0 && s_cmp(udum1, uh2aq, 
	    (ftnlen)8, (ftnlen)8) != 0) {
	i__1 = tt_1.nct;
	for (ns = 2; ns <= i__1; ++ns) {
	    if (ns != tu_1.nhydr) {
		if (_BLNK__1.cdrs[ns + op_1.iopt1 * 101 - 102] != 0.f) {
		    goto L1294;
		}
	    }
/* L1292: */
	}

	io___134.ciunit = un_1.noutpt;
	s_wsfe(&io___134);
	e_wsfe();
	io___135.ciunit = un_1.nttyo;
	s_wsfe(&io___135);
	e_wsfe();
	++nwarn;
	goto L2020;

L1294:
	if (jj_1.jflag[ns - 1] < 16 && ww_1.csp[ns - 1] <= 0.f) {
	    io___136.ciunit = un_1.noutpt;
	    s_wsfe(&io___136);
	    do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    io___137.ciunit = un_1.nttyo;
	    s_wsfe(&io___137);
	    do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    ++nwarn;
	}
    }
L2020:

/*     check some jflag, csp, nsp combinations */

    i__1 = tt_1.nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	jk = jj_1.jflag[ns - 1];

/*     check for negative values for non-negative csp quantities */

	if (jk <= 15) {
	    if (ww_1.csp[ns - 1] < 0.f && ns != tt_1.nsb) {
		io___138.ciunit = un_1.noutpt;
		s_wsfe(&io___138);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&ww_1.csp[ns - 1], (ftnlen)sizeof(
			doublereal));
		e_wsfe();
		io___139.ciunit = un_1.nttyo;
		s_wsfe(&io___139);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&ww_1.csp[ns - 1], (ftnlen)sizeof(
			doublereal));
		e_wsfe();
		++nwarn;
	    }
	}

/*     check for alkalinity constraint on a species other than hco3- */
/*     or co3-- */

	if (jk == 10 || jk == 12) {
	    if (s_cmp(gg_1.uspec + (ns - 1) * 24, uhco3, (ftnlen)8, (ftnlen)8)
		     != 0 && s_cmp(gg_1.uspec + (ns - 1) * 24, uco3, (ftnlen)
		    8, (ftnlen)8) != 0) {
		io___140.ciunit = un_1.noutpt;
		s_wsfe(&io___140);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		io___141.ciunit = un_1.nttyo;
		s_wsfe(&io___141);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		++nwarn;
	    }
	}

/*     check for nsp values for heterogeneous reaction constraints. */

	if (jk == 19) {
	    nm = ww_1.nsp[ns - 1];
	    if (_BLNK__1.cdrm[ns + nm * 101 - 102] == 0.f || ka_1.jmflag[nm - 
		    1] > 0) {
		io___142.ciunit = un_1.noutpt;
		s_wsfe(&io___142);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		io___143.ciunit = un_1.nttyo;
		s_wsfe(&io___143);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)
			24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
			ftnlen)24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (
			ftnlen)24);
		++nwarn;
	    }
	    goto L2050;
	}

	if (jk == 20) {
	    ndum = ww_1.nsp[ns - 1];
	    if (op_1.iopt4 != 2) {
		io___144.ciunit = un_1.noutpt;
		s_wsfe(&io___144);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&op_1.iopt4, (ftnlen)sizeof(integer));
		e_wsfe();
		io___145.ciunit = un_1.nttyo;
		s_wsfe(&io___145);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&op_1.iopt4, (ftnlen)sizeof(integer));
		e_wsfe();
		++nwarn;
		goto L2050;
	    }
	    ndum += -50000;
	    nx = (integer) (ndum / 100.f);
	    ik = ndum - nx * 100;
	    nm = an_1.nend[ik + nx * 20 - 21];
	    if (_BLNK__1.cdrm[ns + nm * 101 - 102] == 0.f || ka_1.jmflag[nm - 
		    1] > 0) {
		io___146.ciunit = un_1.noutpt;
		s_wsfe(&io___146);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		io___147.ciunit = un_1.nttyo;
		s_wsfe(&io___147);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)
			24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
			ftnlen)24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (
			ftnlen)24);
		++nwarn;
	    }
	    goto L2050;
	}

	if (jk == 21) {
	    ng = ww_1.nsp[ns - 1];
	    if (_BLNK__1.cdrg[ns + ng * 101 - 102] == 0.f || ka_1.jgflag[ng - 
		    1] > 0) {
		io___148.ciunit = un_1.noutpt;
		s_wsfe(&io___148);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		io___149.ciunit = un_1.nttyo;
		s_wsfe(&io___149);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		e_wsfe();
		s_copy(unamsp, gg_1.ugas + (ng - 1) * 24, (ftnlen)24, (ftnlen)
			24);
		prreac_(_BLNK__1.cdrg, gg_1.uspec, unamsp, &ng, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
			ftnlen)24);
		prreac_(_BLNK__1.cdrg, gg_1.uspec, unamsp, &ng, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (
			ftnlen)24);
		++nwarn;
	    }
	}

L2050:

/*     check for illegal 27 or 30 jflag value in the strict basis */

	if (jk == 27 || jk == 30) {
	    if (ns <= tt_1.nsb) {
		io___150.ciunit = un_1.noutpt;
		s_wsfe(&io___150);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
		e_wsfe();
		io___151.ciunit = un_1.nttyo;
		s_wsfe(&io___151);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
		e_wsfe();
		++nwarn;
	    }
	}

/* L2090: */
    }

/*     check to see that a heterogeneous reaction constraint has */
/*     not been applied more than once. */

    i__1 = tt_1.nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	jk = jj_1.jflag[ns - 1];
	if (jk != 19 && jk != 20 && jk != 21) {
	    goto L2092;
	}
	i__2 = tt_1.nsq;
	for (ns2 = 1; ns2 <= i__2; ++ns2) {
	    if (ns == ns2) {
		goto L2091;
	    }
	    jk2 = jj_1.jflag[ns2 - 1];
	    if (jk2 != 19 && jk != 20 && jk2 != 21) {
		goto L2091;
	    }
	    if (jk != jk2) {
		goto L2091;
	    }
	    if (ww_1.nsp[ns - 1] != ww_1.nsp[ns2 - 1]) {
		goto L2091;
	    }
	    io___153.ciunit = un_1.noutpt;
	    s_wsfe(&io___153);
	    e_wsfe();
	    io___154.ciunit = un_1.nttyo;
	    s_wsfe(&io___154);
	    e_wsfe();
	    if (jk == 19) {
		nm = ww_1.nsp[ns - 1];
		s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)
			24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
			ftnlen)24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (
			ftnlen)24);
	    } else if (jk == 20) {
		nloc = ww_1.nsp[ns - 1];
		nloc += -50000;
		nx = (integer) (nloc / 100.f);
		ik = nloc - nx * 100;
		nm = an_1.nend[ik + nx * 20 - 21];
		s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)
			24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
			ftnlen)24);
		prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (
			ftnlen)24);
	    } else if (jk == 21) {
		ng = ww_1.nsp[ns - 1];
		s_copy(unamsp, gg_1.ugas + (ng - 1) * 24, (ftnlen)24, (ftnlen)
			24);
		prreac_(_BLNK__1.cdrg, gg_1.uspec, unamsp, &ng, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (
			ftnlen)24);
		prreac_(_BLNK__1.cdrg, gg_1.uspec, unamsp, &ng, &tt_1.nsq, &
			tt_1.nsq1, &tt_1.nsqmx1, &un_1.nttyo, (ftnlen)24, (
			ftnlen)24);
	    }
	    ++nerr;
	    goto L2092;
L2091:
	    ;
	}

L2092:
	;
    }

/*     check to see that jflag(nsb) .ne. 19, 20, or 21 unless */
/*     iopt1.eq.-3 */

    if (op_1.iopt1 != -3) {
	jfdum = jj_1.jflag[tt_1.nsb - 1];
	if (jfdum == 19) {
	    io___156.ciunit = un_1.noutpt;
	    s_wsfe(&io___156);
	    do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	    e_wsfe();
	    io___157.ciunit = un_1.nttyo;
	    s_wsfe(&io___157);
	    do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	    e_wsfe();
	    ++nwarn;
	} else if (jfdum == 20) {
	    io___158.ciunit = un_1.noutpt;
	    s_wsfe(&io___158);
	    do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	    e_wsfe();
	    io___159.ciunit = un_1.nttyo;
	    s_wsfe(&io___159);
	    do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	    e_wsfe();
	    ++nwarn;
	} else if (jfdum == 21) {
	    io___160.ciunit = un_1.noutpt;
	    s_wsfe(&io___160);
	    do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	    e_wsfe();
	    io___161.ciunit = un_1.nttyo;
	    s_wsfe(&io___161);
	    do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	    e_wsfe();
	    ++nwarn;
	}
    }

    if (nwarn >= 1) {
	io___162.ciunit = un_1.noutpt;
	s_wsfe(&io___162);
	do_fio(&c__1, (char *)&nwarn, (ftnlen)sizeof(integer));
	e_wsfe();
	io___163.ciunit = un_1.nttyo;
	s_wsfe(&io___163);
	do_fio(&c__1, (char *)&nwarn, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L20;
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     save value of titration or carbonate alkalinity.  if using */
/*     carbonate alkalinity, zero the titration factors of non-carbonate */
/*     species. */

    i__1 = tt_1.nst;
    for (ns = 2; ns <= i__1; ++ns) {
	if (s_cmp(gg_1.uspec + (ns - 1) * 24, uco3, (ftnlen)8, (ftnlen)8) == 
		0 || s_cmp(gg_1.uspec + (ns - 1) * 24, uhco3, (ftnlen)8, (
		ftnlen)8) == 0) {
	    tu_1.ncarb = ns;
	    goto L206;
	}
/* L204: */
    }
L206:
    cc_1.alk = 0.f;
    if (tu_1.ncarb > 0) {
	jk = jj_1.jflag[tu_1.ncarb - 1];
	if (jk == 10 || jk == 12) {
	    cc_1.alk = ww_1.csp[tu_1.ncarb - 1];
	    if (jk == 12) {
		i__1 = tt_1.nst;
		for (ns = 1; ns <= i__1; ++ns) {
		    if (ccp_1.titr[ns - 1] != 0.f) {
			if (ns <= tt_1.nsb) {
			    if (ns != tu_1.ncarb) {
				ccp_1.titr[ns - 1] = 0.f;
			    }
			} else {
			    nrs = ns - tt_1.nsb;
			    if (_BLNK__1.cdrs[tu_1.ncarb + nrs * 101 - 102] ==
				     0.f) {
				ccp_1.titr[ns - 1] = 0.f;
			    }
			}
		    }
/* L463: */
		}
	    }
	}
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     recompute equilibrium constants if the reactions have been */
/*     modified by elimination of auxiliary basis species or */
/*     by basis switching. */

    if (qelim || ww_1.qbassw) {
	evdatr_(&hh_1.tempc, &hh_1.tempk, &hh_1.press, &pgrid, ars, amn, ags, 
		xx_1.xlks, xx_1.xlkm, xx_1.xlkg, &eqlpp_1.rconst, &tt_1.nrst, 
		&tt_1.nst, &tt_1.nmt, &tt_1.ngt, &tt_1.nxt, &hh_1.ntpr, &
		narxmx, &ntprmx, &un_1.noutpt, &un_1.nttyo);
    }

    if (op1_1.iopr2 >= 1) {
	echolk_(&op1_1.iopr2, &un_1.noutpt, &hh_1.tempc, &hh_1.press, 
		_BLNK__1.cdrs, _BLNK__1.cdrm, _BLNK__1.cdrg, ars, amn, ags, 
		xx_1.xlks, xx_1.xlkm, xx_1.xlkg, gg_1.uspec, gg_1.umin, 
		gg_1.ugas, ka_1.jsflag, ka_1.jmflag, ka_1.jgflag, &tt_1.nsb, &
		tt_1.nsq, &tt_1.nsq1, &tt_1.nrst, &tt_1.nst, &tt_1.nmt, &
		tt_1.ngt, &tt_1.nxt, &hh_1.ntpr, &tt_1.nsqmx1, &narxmx, &
		ntprmx, (ftnlen)24, (ftnlen)24, (ftnlen)24);
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     compute the csts array of stoichiometric factors.  this is */
/*     calculated from the cdrs array of reaction coefficients. */

    gcsts_(_BLNK__1.csts, _BLNK__1.cdrs, st_1.cstor, ww_1.ibasis, ka_1.jsflag,
	     jj_1.jflag, &tu_1.nhydr, &tt_1.nct, &tt_1.nsb, &tt_1.nsb1, &
	    tt_1.nsq, &tt_1.nsq1, &tt_1.nst, &tt_1.nsqmax, &tt_1.nsqmx1, &
	    tt_1.nstmax, &ww_1.qbassw);

/*     get weights for computing the equivalent stoichiometric */
/*     ionic strength */

    if (eqlgp_1.iopg1 == 0 && ee_1.iacion > 0) {
	i__1 = tt_1.nst;
	for (ns = 1; ns <= i__1; ++ns) {
	    cxistq[ns - 1] = _BLNK__1.csts[ee_1.iacion + ns * 100 - 101];
/* L110: */
	}
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     set up the matrix for newton-raphson iteration and compute */
/*     starting values of the matrix variables. */

    arrset_(ars, amn, ags, _BLNK__1.cess, _BLNK__1.cdrs, _BLNK__1.cdrm, 
	    _BLNK__1.cdrg, _BLNK__1.csts, st_1.cstor, uu_1.xbarlg, vv_1.lamlg,
	     nn_1.aa, nn_1.gm, ww_1.csp, concbs, yy_1.cte, yy_1.mte, 
	    zg_1.zvclg1, cxistq, yy_1.conc, yy_1.conclg, yy_1.act, yy_1.actlg,
	     ccp_1.glg, glgx, xx_1.xlks, xx_1.xlkm, xx_1.xlkg, oo_1.mwtss, 
	    ccp_1.z__, ccp_1.zsq2, ccp_1.titr, ccp_1.azero, ccp_1.hydn, 
	    nn_1.rhs, nn_1.ee, nn_1.res, &eqlpp_1.al10, &eqlpp_1.rconst, &
	    xx_1.xlkeh, &eqlpp_1.ehfac, &eqlpp_1.om, &eqlpp_1.omlg, &
	    eqlpp_1.omi, &hh_1.tempc, &hh_1.tempk, &hh_1.press, &cc_1.xi, &
	    cc_1.xisteq, &cc_1.fo2lg, &jj_1.eh, &cc_1.dshm, &cc_1.shm, &
	    cc_1.shmlim, nnu_1.uzvec1, gg_1.uspec, gg_1.umin, gg_1.ugas, 
	    gg_1.ujtype, an_1.nend, jj_1.jflag, ww_1.nsp, ww_1.nspec, 
	    ka_1.jsflag, st_1.jsort, ka_1.iindx1, ww_1.ibswx, ww_1.ibasis, 
	    nn_1.ir, nn_1.kill, &op_1.iopt1, &op_1.iopt2, &eqlgp_1.iopg1, &
	    op2_1.iodb1, &op2_1.iodb2, &hh_1.ntpr, &ee_1.iacion, &ee_1.iebal, 
	    &tu_1.nhydr, &tu_1.nchlor, &tt_1.nct, &tt_1.nsb, &tt_1.nsb1, &
	    tt_1.nsq, &tt_1.nsqb, &tt_1.nsq1, &tt_1.nst, &tt_1.nrst, &
	    tt_1.nmt, &tt_1.ngt, &tt_1.nxt, &ki_1.kct, &ki_1.ksb, &ki_1.ksq, &
	    ki_1.kebal, &ki_1.kdim, &ki_1.kmax, &ki_1.khydr, &tt_1.nctmax, &
	    tt_1.nsqmax, &tt_1.nsqmx1, &tt_1.nstmax, &tt_1.iktmax, &narxmx, &
	    ntprmx, &ker, &nloop, &un_1.noutpt, &un_1.nttyo, &eqlgpa_1.qhydth,
	     &eqlgpa_1.qpt4, &ww_1.qbswx, &ww_1.qbassw, (ftnlen)8, (ftnlen)24,
	     (ftnlen)24, (ftnlen)24, (ftnlen)24);

    if (ker >= 2) {
	goto L20;
    }
    if (qretry && nloop <= 0) {
	goto L20;
    }

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     initialize some parameters. */

    qpra = TRUE_;
    qprb = op2_1.iodb4 >= 1;
    qprc = op2_1.iodb4 >= 2;
    ki_1.kcarb = 0;
    if (tu_1.ncarb > 0) {
	i__1 = ki_1.ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns = ka_1.iindx1[kcol - 1];
	    if (ns == tu_1.ncarb) {
		ki_1.kcarb = kcol;
		goto L214;
	    }
/* L212: */
	}
L214:
	;
    }

/*     call routine newton to calculate the distribution of aqueous */
/*     species. */


    newton_(_BLNK__1.cdrs, nn_1.aa, nn_1.gm, zg_1.zvclg1, zg_1.del, nn_1.rhs, 
	    nn_1.ee, nn_1.res, yy_1.conc, cxistq, bt_1.beta, bt_1.alpha, 
	    ccp_1.z__, ccp_1.zsq2, ccp_1.azero, ccp_1.hydn, ccp_1.glg, glgx, 
	    betao, delo, concbs, &screwd, &screwn, &ps_1.tolbt, &ps_1.toldl, &
	    hh_1.tempc, &hh_1.press, &bt_1.betamx, &bt_1.bbig, &bt_1.bneg, &
	    bt_1.bgamx, &cc_1.xi, &cc_1.xisteq, &cc_1.dshm, &cc_1.shm, &
	    cc_1.shmlim, gg_1.uspec, nnu_1.uzvec1, uqdel, uqbeta, btc_1.ubbig,
	     btc_1.ubneg, btc_1.ubgamx, ka_1.jsflag, st_1.jsort, nn_1.ir, &
	    iter, &ps_1.itermx, &idelmx, &bt_1.ibetmx, &ee_1.iacion, &
	    ki_1.kmax, &ki_1.kdim, &tt_1.nsqmx1, &tt_1.nsb, &tt_1.nsq, &
	    tt_1.nst, &tu_1.nhydr, &tu_1.nchlor, &ier, (U_fp)matrix_, (U_fp)
	    ncmpx_, (U_fp)betas_, &qpra, &qprb, &qprc, &tu_1.ncarb, (ftnlen)
	    24, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)24, (ftnlen)24, (
	    ftnlen)24);


    if (ier > 0) {
	io___177.ciunit = un_1.noutpt;
	s_wsfe(&io___177);
	do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
	e_wsfe();
	io___178.ciunit = un_1.nttyo;
	s_wsfe(&io___178);
	do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
	e_wsfe();
	ndiagx_(zg_1.del, &screwd, jj_1.jflag, ka_1.iindx1, &idelmx, &
		ee_1.iebal, &ki_1.ksb, &ki_1.kebal, &ki_1.khydr, &ki_1.kcarb, 
		&tu_1.nhydr);
	goto L20;
    }

    io___179.ciunit = un_1.noutpt;
    s_wsfe(&io___179);
    do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
    e_wsfe();
    io___180.ciunit = un_1.nttyo;
    s_wsfe(&io___180);
    do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
    e_wsfe();

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     output the computed solution parameters. */

    scripx_(ars, amn, ags, _BLNK__1.cdrs, _BLNK__1.cdrm, _BLNK__1.cdrg, 
	    _BLNK__1.csts, _BLNK__1.cess, concbs, &sigzi, &eqleps_1.eps100, &
	    tt_1.nct, &tt_1.nsb, &tt_1.nsb1, &tt_1.nsq, &tt_1.nsq1, &tt_1.nst,
	     &tt_1.nrst, &tt_1.nmt, &tt_1.ngt, &tt_1.nxt, &tt_1.nctmax, &
	    tt_1.nsqmax, &tt_1.nsqmx1, &tt_1.nstmax, &tt_1.iktmax, &narxmx, &
	    ntprmx, &un_1.noutpt, &un_1.nttyo);

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*     write interfacing output (the pickup file) */

    scribx_(&sigzi, usave, (ftnlen)24);

/*     go look for another problem on the input file */

    goto L20;
} /* MAIN__ */

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
    static doublereal sigza, tally;
    static integer npass;
    extern /* Subroutine */ int ncmpx_(void), gcsts_(doublereal *, doublereal 
	    *, doublereal *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, logical *);
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
    static cilist io___198 = { 0, 0, 0, fmt_2, 0 };
    static cilist io___202 = { 0, 0, 0, fmt_33, 0 };
    static cilist io___203 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___205 = { 0, 0, 0, fmt_1050, 0 };
    static cilist io___210 = { 0, 0, 0, fmt_1052, 0 };
    static cilist io___211 = { 0, 0, 0, fmt_1054, 0 };
    static cilist io___212 = { 0, 0, 0, fmt_1056, 0 };
    static cilist io___215 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___216 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___217 = { 0, 0, 0, fmt_1060, 0 };
    static cilist io___219 = { 0, 0, 0, fmt_1062, 0 };
    static cilist io___220 = { 0, 0, 0, fmt_1064, 0 };
    static cilist io___227 = { 0, 0, 0, fmt_3, 0 };
    static cilist io___228 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___229 = { 0, 0, 0, fmt_4, 0 };
    static cilist io___230 = { 0, 0, 0, fmt_7, 0 };
    static cilist io___232 = { 0, 0, 0, fmt_742, 0 };
    static cilist io___234 = { 0, 0, 0, fmt_3247, 0 };
    static cilist io___240 = { 0, 0, 0, fmt_3250, 0 };
    static cilist io___241 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___242 = { 0, 0, 0, fmt_642, 0 };
    static cilist io___243 = { 0, 0, 0, fmt_643, 0 };
    static cilist io___245 = { 0, 0, 0, fmt_644, 0 };
    static cilist io___246 = { 0, 0, 0, fmt_647, 0 };
    static cilist io___247 = { 0, 0, 0, fmt_648, 0 };
    static cilist io___248 = { 0, 0, 0, fmt_649, 0 };
    static cilist io___249 = { 0, 0, 0, fmt_553, 0 };
    static cilist io___251 = { 0, 0, 0, fmt_557, 0 };
    static cilist io___252 = { 0, 0, 0, fmt_559, 0 };
    static cilist io___253 = { 0, 0, 0, fmt_573, 0 };
    static cilist io___254 = { 0, 0, 0, fmt_554, 0 };
    static cilist io___255 = { 0, 0, 0, fmt_559, 0 };
    static cilist io___257 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___258 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___267 = { 0, 0, 0, fmt_155, 0 };
    static cilist io___277 = { 0, 0, 0, fmt_162, 0 };
    static cilist io___283 = { 0, 0, 0, fmt_163, 0 };
    static cilist io___287 = { 0, 0, 0, fmt_164, 0 };
    static cilist io___289 = { 0, 0, 0, fmt_177, 0 };
    static cilist io___292 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___293 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___294 = { 0, 0, 0, fmt_190, 0 };
    static cilist io___295 = { 0, 0, 0, fmt_210, 0 };



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

    qabsw = *iopt2 >= 1;

    qpr1 = *iodb2 >= 1;
    qpr2 = *iodb2 >= 2;
    qpr3 = *iodb2 >= 3;
    if (qpr1) {
	io___198.ciunit = *noutpt;
	s_wsfe(&io___198);
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
	io___202.ciunit = *noutpt;
	s_wsfe(&io___202);
	do_fio(&c__1, (char *)&(*nloop), (ftnlen)sizeof(integer));
	e_wsfe();
    }

/*     get stoichiometric coefficients for the equivalent */
/*     stoichiometric ionic strength. */

/*     print the iteration matrix structure.  execute any killer options. */
/*     killer options are set only once.  they carry through after any */
/*     automatic basis switching. */

    if (qpr1) {
	io___203.ciunit = *noutpt;
	s_wsfe(&io___203);
	e_wsfe();
    }
    if (iodb3 != 0) {
	io___205.ciunit = *nttyo;
	s_wsfe(&io___205);
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
	    io___210.ciunit = *nttyo;
	    s_wsfe(&io___210);
	    do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	    do_fio(&c__1, ust1, (ftnlen)24);
	    do_fio(&c__1, ust2, (ftnlen)24);
	    e_wsfe();
	    io___211.ciunit = *nttyo;
	    s_wsfe(&io___211);
	    e_wsfe();
	    io___212.ciunit = nttyi;
	    s_rsfe(&io___212);
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
	    io___215.ciunit = *noutpt;
	    s_wsfe(&io___215);
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
	io___216.ciunit = *noutpt;
	s_wsfe(&io___216);
	e_wsfe();
    }

/*     echo killer option data */

    if (iodb3 > 0) {
	io___217.ciunit = *nttyo;
	s_wsfe(&io___217);
	e_wsfe();
	tally = 0.;
	i__1 = *kdim;
	for (kcol = 1; kcol <= i__1; ++kcol) {
	    if (kill[kcol] != 0) {
		tally += 1;
		io___219.ciunit = *nttyo;
		s_wsfe(&io___219);
		do_fio(&c__1, (char *)&kcol, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
/* L232: */
	}

	if (tally == 0.) {
	    io___220.ciunit = *nttyo;
	    s_wsfe(&io___220);
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
	io___227.ciunit = *noutpt;
	s_wsfe(&io___227);
	do_fio(&c__1, (char *)&npass, (ftnlen)sizeof(integer));
	e_wsfe();
	io___228.ciunit = *noutpt;
	s_wsfe(&io___228);
	do_fio(&c__1, (char *)&(*xi), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (*iopg1 == 0) {
	    io___229.ciunit = *noutpt;
	    s_wsfe(&io___229);
	    do_fio(&c__1, (char *)&(*xisteq), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (*qhydth) {
	    io___230.ciunit = *noutpt;
	    s_wsfe(&io___230);
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
	io___232.ciunit = *noutpt;
	s_wsfe(&io___232);
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
	io___234.ciunit = *noutpt;
	s_wsfe(&io___234);
	e_wsfe();
	i__1 = *kdim;
	for (krow = 1; krow <= i__1; ++krow) {
	    idum = iindx1[krow];
	    zdum1 = zvclg1[krow];
	    zdum2 = texp_(&zdum1);
	    s_copy(udum, uzvec1 + krow * uzvec1_len, (ftnlen)8, uzvec1_len);
	    bdum = bt_1.beta[krow - 1];
	    io___240.ciunit = *noutpt;
	    s_wsfe(&io___240);
	    do_fio(&c__1, (char *)&krow, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
	    do_fio(&c__1, udum, (ftnlen)8);
	    do_fio(&c__1, (char *)&zdum1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&zdum2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&bdum, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* L745: */
	}
	io___241.ciunit = *noutpt;
	s_wsfe(&io___241);
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
	io___242.ciunit = *noutpt;
	s_wsfe(&io___242);
	e_wsfe();
	io___243.ciunit = *noutpt;
	s_wsfe(&io___243);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns = iindx1[kcol];
	    ns2 = bt_1.nfac[kcol - 1];
	    if (ns2 > 0) {
		io___245.ciunit = *noutpt;
		s_wsfe(&io___245);
		do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
		do_fio(&c__1, uspec + ns2 * uspec_len, uspec_len);
		e_wsfe();
	    }
/* L645: */
	}
    }

    gbfac_(bt_1.nfac, bt_1.beta, bt_1.efac, ksq, bt_1.bfac);

    if (qpr3 && ! (*qbswx)) {
	io___246.ciunit = *noutpt;
	s_wsfe(&io___246);
	e_wsfe();
	io___247.ciunit = *noutpt;
	s_wsfe(&io___247);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    if (bt_1.bfac[kcol - 1] > 0.f) {
		ns = iindx1[kcol];
		io___248.ciunit = *noutpt;
		s_wsfe(&io___248);
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
	io___249.ciunit = *noutpt;
	s_wsfe(&io___249);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns1 = iindx1[kcol];
	    ns2 = ibswx[kcol];
	    if (ns2 > 0) {
		io___251.ciunit = *noutpt;
		s_wsfe(&io___251);
		do_fio(&c__1, uspec + ns1 * uspec_len, uspec_len);
		do_fio(&c__1, uspec + ns2 * uspec_len, uspec_len);
		e_wsfe();
	    }
/* L570: */
	}
	io___252.ciunit = *noutpt;
	s_wsfe(&io___252);
	e_wsfe();
    }

/*     resolve any conflicts in candidate basis switches */

    gabswx_(bt_1.beta, ksq, &ibswx[1]);

    if (qpr1) {
	io___253.ciunit = *noutpt;
	s_wsfe(&io___253);
	e_wsfe();
	i__1 = *ksq;
	for (kcol = 2; kcol <= i__1; ++kcol) {
	    ns1 = iindx1[kcol];
	    ns2 = ibswx[kcol];
	    if (ns2 > 0) {
		io___254.ciunit = *noutpt;
		s_wsfe(&io___254);
		do_fio(&c__1, uspec + ns1 * uspec_len, uspec_len);
		do_fio(&c__1, uspec + ns2 * uspec_len, uspec_len);
		e_wsfe();
	    }
/* L575: */
	}
	io___255.ciunit = *noutpt;
	s_wsfe(&io___255);
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
	io___257.ciunit = *nttyo;
	s_wsfe(&io___257);
	do_fio(&c__1, (char *)&(*nloop), (ftnlen)sizeof(integer));
	e_wsfe();
	io___258.ciunit = *noutpt;
	s_wsfe(&io___258);
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
	io___267.ciunit = *noutpt;
	s_wsfe(&io___267);
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
	io___277.ciunit = *noutpt;
	s_wsfe(&io___277);
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
	    io___283.ciunit = *noutpt;
	    s_wsfe(&io___283);
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
	    io___287.ciunit = *noutpt;
	    s_wsfe(&io___287);
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
	io___289.ciunit = *noutpt;
	s_wsfe(&io___289);
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

	    io___292.ciunit = *noutpt;
	    s_wsfe(&io___292);
	    e_wsfe();
	    io___293.ciunit = *nttyo;
	    s_wsfe(&io___293);
	    e_wsfe();
	    goto L999;
	}

/*       set up for another pass */

	goto L10;
    }

/*     are cycle criteria satisfied? */

    if (qtestc) {

/*       optimization achieved within requested limits */

	io___294.ciunit = *noutpt;
	s_wsfe(&io___294);
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
	    io___295.ciunit = *noutpt;
	    s_wsfe(&io___295);
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
    static cilist io___314 = { 0, 0, 0, fmt_532, 0 };
    static cilist io___321 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___322 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___323 = { 0, 0, 0, fmt_717, 0 };
    static cilist io___329 = { 0, 0, 0, fmt_720, 0 };
    static cilist io___330 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___340 = { 0, 0, 0, fmt_606, 0 };
    static cilist io___341 = { 0, 0, 0, fmt_607, 0 };
    static cilist io___342 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___348 = { 0, 0, 0, fmt_686, 0 };
    static cilist io___349 = { 0, 0, 0, fmt_687, 0 };
    static cilist io___350 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___352 = { 0, 0, 0, fmt_695, 0 };
    static cilist io___353 = { 0, 0, 0, fmt_697, 0 };
    static cilist io___354 = { 0, 0, 0, fmt_697, 0 };
    static cilist io___356 = { 0, 0, 0, fmt_717, 0 };
    static cilist io___358 = { 0, 0, 0, fmt_720, 0 };
    static cilist io___359 = { 0, 0, 0, fmt_75, 0 };
    static cilist io___362 = { 0, 0, 0, fmt_727, 0 };
    static cilist io___363 = { 0, 0, 0, fmt_737, 0 };
    static cilist io___364 = { 0, 0, 0, fmt_729, 0 };



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

/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */



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
    io___314.ciunit = un_1.noutpt;
    s_wsfe(&io___314);
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
	io___321.ciunit = un_1.noutpt;
	s_wsfe(&io___321);
	do_fio(&c__1, (char *)&irow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	do_fio(&c__1, ust1, (ftnlen)24);
	do_fio(&c__1, ust2, (ftnlen)24);
	do_fio(&c__1, ust3, (ftnlen)24);
	e_wsfe();
/* L565: */
    }

    io___322.ciunit = un_1.noutpt;
    s_wsfe(&io___322);
    e_wsfe();
    io___323.ciunit = un_1.noutpt;
    s_wsfe(&io___323);
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
	io___329.ciunit = un_1.noutpt;
	s_wsfe(&io___329);
	do_fio(&c__1, (char *)&krow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, (char *)&zdum1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&gdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
L567:
	;
    }

    io___330.ciunit = un_1.noutpt;
    s_wsfe(&io___330);
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
    io___340.ciunit = un_1.noutpt;
    s_wsfe(&io___340);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	io___341.ciunit = un_1.noutpt;
	s_wsfe(&io___341);
	i__2 = isq;
	for (icol = 1; icol <= i__2; ++icol) {
	    do_fio(&c__1, (char *)&nn_1.aa[irow + icol * 100 - 101], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
/* L608: */
    }

    io___342.ciunit = un_1.noutpt;
    s_wsfe(&io___342);
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
    io___348.ciunit = un_1.noutpt;
    s_wsfe(&io___348);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	idum = jjndex[irow - 1];
	rdum = nn_1.rhs[irow - 1];
	io___349.ciunit = un_1.noutpt;
	s_wsfe(&io___349);
	do_fio(&c__1, (char *)&irow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jjndex[irow - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nn_1.rhs[irow - 1], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
/* L688: */
    }

    io___350.ciunit = un_1.noutpt;
    s_wsfe(&io___350);
    e_wsfe();
L689:

/* L120: */

    msolvr_(nn_1.aa, nn_1.gm, nn_1.rhs, zg_1.del, nn_1.res, nn_1.ee, nn_1.ir, 
	    &isq, &ki_1.kmax, &ier, &qfalse, &qfalse);
    if (ier > 0) {
	io___352.ciunit = un_1.noutpt;
	s_wsfe(&io___352);
	e_wsfe();
	io___353.ciunit = un_1.noutpt;
	s_wsfe(&io___353);
	e_wsfe();
	io___354.ciunit = un_1.nttyo;
	s_wsfe(&io___354);
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
    io___356.ciunit = un_1.noutpt;
    s_wsfe(&io___356);
    e_wsfe();

    i__1 = isq;
    for (irow = 1; irow <= i__1; ++irow) {
	idum = jjndex[irow - 1];
	ddum = zg_1.del[irow - 1];
	s_copy(udum, uspec + idum * uspec_len, (ftnlen)8, (ftnlen)8);
	io___358.ciunit = un_1.noutpt;
	s_wsfe(&io___358);
	do_fio(&c__1, (char *)&irow, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&idum, (ftnlen)sizeof(integer));
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, (char *)&ddum, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L723: */
    }

    io___359.ciunit = un_1.noutpt;
    s_wsfe(&io___359);
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
	io___362.ciunit = un_1.noutpt;
	s_wsfe(&io___362);
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
    io___363.ciunit = un_1.noutpt;
    s_wsfe(&io___363);
    e_wsfe();
    *ker = 2;
    goto L999;

L738:
    if (*ker == 1) {
	io___364.ciunit = un_1.noutpt;
	s_wsfe(&io___364);
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
/* eqlgp.h */


/* -------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */

/*      build stor1 array */

/* eqlpp.h */
/* -------------------------------------------------------------------- */
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
    static cilist io___376 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___377 = { 0, 0, 0, fmt_1010, 0 };



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
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlgp.h */


/* -------------------------------------------------------------------- */

/* eqlpp.h */
/* -------------------------------------------------------------------- */

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
	io___376.ciunit = un_1.noutpt;
	s_wsfe(&io___376);
	do_fio(&c__1, (char *)&jfdum, (ftnlen)sizeof(integer));
	do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___377.ciunit = un_1.nttyo;
	s_wsfe(&io___377);
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

/* echox    last revised 12/11/87 by tjw */
/* Subroutine */ int echox_(void)
{

    /* Format strings */
    static char fmt_265[] = "(//////1x,\002eeee   qqq   33333  n   n  rrrr"
	    "   \002,/1x,\002e     q   q      3  nn  n  r   r  \002,/1x,\002e"
	    "eee  q   q    33   n n n  rrrr   \002,/1x,\002e     q q q      3"
	    "  n  nn  r  r   \002,/1x,\002eeee   qqq   3333   n   n  r   r "
	    " \002,/1x,\002          q                       \002,///,\002MOD"
	    "IFIED FOR DEW CALCULATIONS     \002,///)";
    static char fmt_267[] = "(1x,\002eq3nr.\002,a4,a4,/,2x,\002supported by "
	    "eqlib.\002,a4,a4,//)";
    static char fmt_285[] = "(1x,a80)";
    static char fmt_270[] = "(1x)";
    static char fmt_730[] = "(/3x,\002the activity coefficients of aqueous s"
	    "olute species\002,/1x,\002and the activity of water are calculat"
	    "ed according to\002,/1x,a32,/)";
    static char fmt_750[] = "(3x,\002dh(o/c)a = debye-huckel-osmotic-azero f"
	    "orm\002)";
    static char fmt_757[] = "(3x,\002dh(o/c)a = debye-huckel-charging-azero "
	    "form\002)";
    static char fmt_732[] = "(/3x,\002uelam= \002,a6)";
    static char fmt_731[] = "(/7x,\002species\002,7x,\002ion size\002,3x,"
	    "\002hydr. no.\002,/)";
    static char fmt_734[] = "(5x,a12,3x,f7.3,3x,f7.3)";
    static char fmt_275[] = "(/1x,\002temperature= \002,f6.2,\002 degrees ce"
	    "lsius\002,/1x,\002pressure= \002,f9.4,\002 bars\002,/)";
    static char fmt_280[] = "(6x,i5,\002 elements are in the data base\002,/"
	    "6x,i5,\002 elements can be loaded into memory\002,/6x,i5,\002 el"
	    "ements are active in this problem\002,//)";
    static char fmt_281[] = "(6x,i5,\002 aqueous species are in the data b"
	    "ase\002,/6x,i5,\002 aqueous species were loaded into memory\002,"
	    "/6x,i5,\002 aqueous species can be loaded into memory\002,/6x,i5,"
	    "\002 aqueous species are active in this problem\002,//6x,i5,\002"
	    " aqueous reactions are in the data base\002,/6x,i5,\002 aqueous "
	    "reactions were loaded into memory\002,/6x,i5,\002 aqueous reacti"
	    "ons can be loaded into memory\002,//)";
    static char fmt_282[] = "(11x,i5,\002 minerals are in the data base\002,"
	    "/11x,i5,\002 minerals were loaded into memory\002,/11x,i5,\002 m"
	    "inerals can be loaded into memory\002,/11x,i5,\002 minerals are "
	    "active in this problem\002,//11x,i5,\002 solid solutions are in "
	    "the data base\002,/11x,i5,\002 solid solutions can be loaded int"
	    "o memory\002,/11x,i5,\002 solid solutions are active in this pro"
	    "blem\002,//)";
    static char fmt_283[] = "(11x,i5,\002 gases are in the data base\002,/11"
	    "x,i5,\002 gases were loaded into memory\002,/11x,i5,\002 gases c"
	    "an be loaded into memory\002,/11x,i5,\002 gases are active in th"
	    "is problem\002,//)";
    static char fmt_295[] = "(//6x,\002iopt1  = \002,i2,\002 (redox option s"
	    "witch)\002,/6x,\002iopt2  = \002,i2,\002 (automatic basis switch"
	    "ing switch)\002,/6x,\002iopt3  = \002,i2,\002 (interfacing outpu"
	    "t control switch)\002,/6x,\002iopt4  = \002,i2,\002 (turn-on sol"
	    "id solutions switch)\002,/6x,\002iopt5  = \002,i2,\002 (not used)"
	    "\002,/6x,\002iopt6  = \002,i2,\002 (conv. test criteria switch"
	    ")\002,/6x,\002iopt7  = \002,i2,\002 (0/1 3245/post-3245 pickup f"
	    "ile)\002,/6x,\002iopt8  = \002,i2,\002 (not used)\002,/6x,\002io"
	    "pt9  = \002,i2,\002 (not used)\002,/6x,\002iopt10 = \002,i2,\002"
	    " (not used)\002,/)";
    static char fmt_298[] = "(//11x,\002iopg1  = \002,i2,\002 (act. coeff. c"
	    "hoice)\002,/11x,\002iopg2  = \002,i2,\002 (ph scale convention s"
	    "witch)\002,/11x,\002iopg3  = \002,i2,\002 (iopg1=3 - 0/1 uelam= "
	    "on/onplus)\002,/11x,\002iopg4  = \002,i2,\002 (iopg1=3 or 4 - f "
	    "switch - 0/1 dhoa/dhca)\002,/11x,\002iopg5  = \002,i2,\002 (gamC"
	    " 0: omega-hat (C is 2nd bs), 1: bdot*xi)\002,/11x,\002iopg6  ="
	    " \002,i2,\002 (approx. of j(x) function)\002,/11x,\002iopg7  ="
	    " \002,i2,\002 (a(H2O)=1 if =0, a(H2O)=X(H2O) if =1)\002,/11x,"
	    "\002iopg8  = \002,i2,\002 (if =1 then uses high T range 650-1000"
	    " C)\002,/11x,\002iopg9  = \002,i2,\002 (position of C in the dat"
	    "afile)\002,/11x,\002iopg10 = \002,i2,\002 (not used)\002,/)";
    static char fmt_296[] = "(/16x,\002iopr1  = \002,i2,\002 (list loading o"
	    "f species)\002,/16x,\002iopr2  = \002,i2,\002 (list reactions an"
	    "d log k values)\002,/16x,\002iopr3  = \002,i2,\002 (aqueous spec"
	    "ies print order control)\002,/16x,\002iopr4  = \002,i2,\002 (aqu"
	    "eous species print cut-off control)\002,/16x,\002iopr5  = \002,i"
	    "2,\002 (mass balance percentages print control)\002,/16x,\002iop"
	    "r6  = \002,i2,\002 (mean ionic act coeff print control)\002,/16x,"
	    "\002iopr7  = \002,i2,\002 (mineral affinity print control)\002,/"
	    "16x,\002iopr8  = \002,i2,\002 (ion size and hydr. no. print cont"
	    "rol)\002,/16x,\002iopr9  = \002,i2,\002 (pitzer coefficients tab"
	    "ulation)\002,/16x,\002iopr10 = \002,i2,\002 (print concbs array"
	    ")\002)";
    static char fmt_420[] = "(16x,\002iopr11 = \002,i2,\002 (not used)\002,/"
	    "16x,\002iopr12 = \002,i2,\002 (not used)\002,/16x,\002iopr13 ="
	    " \002,i2,\002 (not used)\002,/16x,\002iopr14 = \002,i2,\002 (not"
	    " used)\002,/16x,\002iopr15 = \002,i2,\002 (not used)\002,/16x"
	    ",\002iopr16 = \002,i2,\002 (not used)\002,/16x,\002iopr17 = \002"
	    ",i2,\002 (not used)\002,/16x,\002iopr18 = \002,i2,\002 (not used)"
	    "\002,/16x,\002iopr19 = \002,i2,\002 (not used)\002,/16x,\002iopr"
	    "20 = \002,i2,\002 (not used)\002,/)";
    static char fmt_297[] = "(/21x,\002iodb1  = \002,i2,\002 (print info. me"
	    "ssages switch)\002,/21x,\002iodb2  = \002,i2,\002 (print pre-new"
	    "ton-raphson optimizations\002,\002 switch)\002,/21x,\002iodb3  = "
	    "\002,i2,\002 (request iteration variables to kill)\002,/21x,\002"
	    "iodb4  = \002,i2,\002 (print newton-raphson iterations switch"
	    ")\002,/21x,\002iodb5  = \002,i2,\002 (list stoichiometric equiva"
	    "lences)\002,/21x,\002iodb6  = \002,i2,\002 (controls iodb5 level"
	    " of detail)\002,/21x,\002iodb7  = \002,i2,\002 (write reactions "
	    "on file rlist switch)\002,/,21x,\002iodb8  = \002,i2,\002 (not u"
	    "sed)\002,/,21x,\002iodb9  = \002,i2,\002 (not used)\002,/,21x"
	    ",\002iodb10 = \002,i2,\002 (not used)\002,/)";
    static char fmt_405[] = "(/6x,\002the default redox state is constrained"
	    " by the\002,\002 couple associated with\002,/6x,\002the auxiliar"
	    "y basis species \002,a12)";
    static char fmt_303[] = "(/6x,\002the default redox state is constrained"
	    " by\002,\002 log fo2 = \002,f12.4,\002 (log bars)\002)";
    static char fmt_427[] = "(/6x,\002the default redox state is controlled "
	    "by a\002,\002 heterogeneous reaction -- see below\002)";
    static char fmt_301[] = "(/6x,\002the default redox state is constrained"
	    " by eh = \002,f8.5,\002 volts\002)";
    static char fmt_302[] = "(/6x,\002the default redox state is constrained"
	    " by pe = \002,e13.6)";
    static char fmt_300[] = "(//16x,\002solution density = \002,f8.5,\002 g/"
	    "ml\002,//16x,\002total dissolved salts = \002,f10.2,\002 mg/kg s"
	    "olution\002,/16x,\002total dissolved salts = \002,f10.2,\002 mg/l"
	    "\002,/)";
    static char fmt_305[] = "(/11x,\002tolbt  = \002,e12.5,\002 (convergence"
	    " tolerance on\002,\002 residual functions)\002,/11x,\002toldl  = "
	    "\002,e12.5,\002 (convergence\002,\002 tolerance on correction te"
	    "rms)\002,/11x,\002tolsat = \002,e12.5,\002 (phase saturation tol"
	    "erance, does not affect\002,/33x,\002 convergence)\002,/)";
    static char fmt_287[] = "(//36x,\002----- input constraints -----\002,/)";
    static char fmt_290[] = "(5x,\002species          csp       jflag \002"
	    ",\002 type of input      controlling phase\002,/)";
    static char fmt_315[] = "(3x,a24,3x,e12.5,3x,i2,3x,a24,3x,a24)";
    static char fmt_316[] = "(5x,\002switch with \002,a24)";
    static char fmt_505[] = "(\002 --- note- \002,a12,\002 is not in the mod"
	    "el ---\002,/)";
    static char fmt_323[] = "(//21x,\002----- input solid solution compositi"
	    "ons -----\002,/)";
    static char fmt_325[] = "(/6x,a18,/)";
    static char fmt_328[] = "(30x,\002mole fraction\002)";
    static char fmt_330[] = "(12x,a18,3x,f6.4)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer k, n, nc, ik, jk, ng, nm, ns, nx, ns1, ns2, nrs;
    static doublereal cdum;
    static integer ndum, ncpt;
    static doublereal xdum;
    static integer jfdum;
    extern /* Subroutine */ int prreac_(doublereal *, char *, char *, integer 
	    *, integer *, integer *, integer *, integer *, ftnlen, ftnlen);
    static char unamsp[24];

    /* Fortran I/O blocks */
    static cilist io___407 = { 0, 0, 0, fmt_265, 0 };
    static cilist io___408 = { 0, 0, 0, fmt_267, 0 };
    static cilist io___410 = { 0, 0, 0, fmt_285, 0 };
    static cilist io___411 = { 0, 0, 0, fmt_270, 0 };
    static cilist io___412 = { 0, 0, 0, fmt_285, 0 };
    static cilist io___413 = { 0, 0, 0, fmt_730, 0 };
    static cilist io___414 = { 0, 0, 0, fmt_750, 0 };
    static cilist io___415 = { 0, 0, 0, fmt_757, 0 };
    static cilist io___416 = { 0, 0, 0, fmt_285, 0 };
    static cilist io___417 = { 0, 0, 0, fmt_285, 0 };
    static cilist io___418 = { 0, 0, 0, fmt_732, 0 };
    static cilist io___419 = { 0, 0, 0, fmt_731, 0 };
    static cilist io___421 = { 0, 0, 0, fmt_734, 0 };
    static cilist io___422 = { 0, 0, 0, fmt_270, 0 };
    static cilist io___423 = { 0, 0, 0, fmt_275, 0 };
    static cilist io___424 = { 0, 0, 0, fmt_270, 0 };
    static cilist io___426 = { 0, 0, 0, fmt_280, 0 };
    static cilist io___427 = { 0, 0, 0, fmt_281, 0 };
    static cilist io___428 = { 0, 0, 0, fmt_282, 0 };
    static cilist io___429 = { 0, 0, 0, fmt_283, 0 };
    static cilist io___430 = { 0, 0, 0, fmt_295, 0 };
    static cilist io___431 = { 0, 0, 0, fmt_298, 0 };
    static cilist io___432 = { 0, 0, 0, fmt_296, 0 };
    static cilist io___433 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___434 = { 0, 0, 0, fmt_297, 0 };
    static cilist io___436 = { 0, 0, 0, fmt_405, 0 };
    static cilist io___437 = { 0, 0, 0, fmt_303, 0 };
    static cilist io___438 = { 0, 0, 0, fmt_427, 0 };
    static cilist io___439 = { 0, 0, 0, fmt_301, 0 };
    static cilist io___440 = { 0, 0, 0, fmt_302, 0 };
    static cilist io___441 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___442 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___443 = { 0, 0, 0, fmt_287, 0 };
    static cilist io___444 = { 0, 0, 0, fmt_290, 0 };
    static cilist io___450 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___451 = { 0, 0, 0, fmt_316, 0 };
    static cilist io___452 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___460 = { 0, 0, 0, fmt_505, 0 };
    static cilist io___461 = { 0, 0, 0, fmt_323, 0 };
    static cilist io___464 = { 0, 0, 0, fmt_325, 0 };
    static cilist io___465 = { 0, 0, 0, fmt_328, 0 };
    static cilist io___466 = { 0, 0, 0, fmt_330, 0 };
    static cilist io___467 = { 0, 0, 0, fmt_270, 0 };



/*     this routine echoes the problem input defining the compositional */
/*     constraints on the aqueous solution being modeled and the */
/*     options and tolerances selected. */


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
/* si.h */
/* -------------------------------------------------------------------- */
/* te.h */
/* -------------------------------------------------------------------- */
/* ti.h */

/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* uu.h */


/* -------------------------------------------------------------------- */
/* eqlver.h */
/* -------------------------------------------------------------------- */
/* vv.h */
/* -------------------------------------------------------------------- */
/* vw.h */

/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* eqlpp.h */
/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */

/* eqlgp.h */


/* -------------------------------------------------------------------- */


/* ---------------------------------------------------------------------- */

    io___407.ciunit = un_1.noutpt;
    s_wsfe(&io___407);
    e_wsfe();
    io___408.ciunit = un_1.noutpt;
    s_wsfe(&io___408);
    do_fio(&c__1, eqlver_1.urelno, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ustage, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ueqlrn, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ueqlst, (ftnlen)8);
    e_wsfe();

    i__1 = ti_1.ntitl;
    for (n = 1; n <= i__1; ++n) {
	io___410.ciunit = un_1.noutpt;
	s_wsfe(&io___410);
	do_fio(&c__1, tic_1.utitl + (n - 1) * 80, (ftnlen)80);
	e_wsfe();
/* L284: */
    }

    io___411.ciunit = un_1.noutpt;
    s_wsfe(&io___411);
    e_wsfe();

    for (n = 1; n <= 4; ++n) {
	io___412.ciunit = un_1.noutpt;
	s_wsfe(&io___412);
	do_fio(&c__1, tic_1.utitld + (n - 1) * 80, (ftnlen)80);
	e_wsfe();
/* L272: */
    }

    io___413.ciunit = un_1.noutpt;
    s_wsfe(&io___413);
    do_fio(&c__1, eqlgpc_1.uactop, (ftnlen)32);
    e_wsfe();
    if (eqlgpa_1.qhydth) {
	if (eqlgp_1.iopg4 == 0) {
	    io___414.ciunit = un_1.noutpt;
	    s_wsfe(&io___414);
	    e_wsfe();
	} else {
	    io___415.ciunit = un_1.noutpt;
	    s_wsfe(&io___415);
	    e_wsfe();
	}
    }
    if (eqlgp_1.iopg1 == 1) {
	io___416.ciunit = un_1.noutpt;
	s_wsfe(&io___416);
	do_fio(&c__4, eqlgpc_1.udpitz, (ftnlen)80);
	e_wsfe();
    } else if (eqlgp_1.iopg1 == 5) {
	io___417.ciunit = un_1.noutpt;
	s_wsfe(&io___417);
	do_fio(&c__4, eqlgpc_1.udhkf, (ftnlen)80);
	e_wsfe();
    }
    if (eqlgp_1.iopg1 >= 1) {
	io___418.ciunit = un_1.noutpt;
	s_wsfe(&io___418);
	do_fio(&c__1, eqlgpc_1.uelam, (ftnlen)8);
	e_wsfe();
    }
    if (eqlgpa_1.qhydth) {
	if (op1_1.iopr8 >= 0) {
	    io___419.ciunit = un_1.noutpt;
	    s_wsfe(&io___419);
	    e_wsfe();
	    i__1 = tt_1.nst;
	    for (ns = 2; ns <= i__1; ++ns) {
		if (ka_1.jsflag[ns - 1] > 0) {
		    goto L736;
		}
		io___421.ciunit = un_1.noutpt;
		s_wsfe(&io___421);
		do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&ccp_1.azero[ns - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&ccp_1.hydn[ns - 1], (ftnlen)sizeof(
			doublereal));
		e_wsfe();
L736:
		;
	    }
	}
    }

    io___422.ciunit = un_1.noutpt;
    s_wsfe(&io___422);
    e_wsfe();
    io___423.ciunit = un_1.noutpt;
    s_wsfe(&io___423);
    do_fio(&c__1, (char *)&hh_1.tempc, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&hh_1.press, (ftnlen)sizeof(doublereal));
    e_wsfe();

    io___424.ciunit = un_1.noutpt;
    s_wsfe(&io___424);
    e_wsfe();
    ki_1.kct = 0;
    i__1 = tt_1.nct;
    for (nc = 1; nc <= i__1; ++nc) {
	if (jj_1.jcflag[nc - 1] <= 0) {
	    goto L245;
	}
	++ki_1.kct;
L245:
	;
    }
    io___426.ciunit = un_1.noutpt;
    s_wsfe(&io___426);
    do_fio(&c__1, (char *)&tt_1.nct, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nctmax, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ki_1.kct, (ftnlen)sizeof(integer));
    e_wsfe();
    io___427.ciunit = un_1.noutpt;
    s_wsfe(&io___427);
    do_fio(&c__1, (char *)&si_1.ist, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nstmax, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&si_1.jst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&si_1.irst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nrst, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nrstmx, (ftnlen)sizeof(integer));
    e_wsfe();
    io___428.ciunit = un_1.noutpt;
    s_wsfe(&io___428);
    do_fio(&c__1, (char *)&si_1.imt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nmt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nmtmax, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&si_1.jmt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nxt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.nxtmax, (ftnlen)sizeof(integer));
    e_wsfe();
    io___429.ciunit = un_1.noutpt;
    s_wsfe(&io___429);
    do_fio(&c__1, (char *)&si_1.igt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.ngt, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tt_1.ngtmax, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&si_1.jgt, (ftnlen)sizeof(integer));
    e_wsfe();
    io___430.ciunit = un_1.noutpt;
    s_wsfe(&io___430);
    do_fio(&c__1, (char *)&op_1.iopt1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt10, (ftnlen)sizeof(integer));
    e_wsfe();
    io___431.ciunit = un_1.noutpt;
    s_wsfe(&io___431);
    do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg10, (ftnlen)sizeof(integer));
    e_wsfe();
    io___432.ciunit = un_1.noutpt;
    s_wsfe(&io___432);
    do_fio(&c__1, (char *)&op1_1.iopr1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr10, (ftnlen)sizeof(integer));
    e_wsfe();
    io___433.ciunit = un_1.noutpt;
    s_wsfe(&io___433);
    do_fio(&c__1, (char *)&op1_1.iopr11, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr12, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr13, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr14, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr15, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr16, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr17, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr18, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr19, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr20, (ftnlen)sizeof(integer));
    e_wsfe();
    io___434.ciunit = un_1.noutpt;
    s_wsfe(&io___434);
    do_fio(&c__1, (char *)&op2_1.iodb1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb10, (ftnlen)sizeof(integer));
    e_wsfe();

    jfdum = jj_1.jflag[tt_1.nsb - 1];
    if (op_1.iopt1 <= 0) {
	goto L410;
    }
    io___436.ciunit = un_1.noutpt;
    s_wsfe(&io___436);
    do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
    e_wsfe();
    goto L309;

L410:
    if (op_1.iopt1 != 0) {
	goto L423;
    }
    io___437.ciunit = un_1.noutpt;
    s_wsfe(&io___437);
    do_fio(&c__1, (char *)&cc_1.fo2lg, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L309;

L423:
    if (op_1.iopt1 != -3) {
	goto L309;
    }
    io___438.ciunit = un_1.noutpt;
    s_wsfe(&io___438);
    e_wsfe();
    goto L309;

/* L307: */
    if (op_1.iopt1 != -1) {
	goto L308;
    }
    io___439.ciunit = un_1.noutpt;
    s_wsfe(&io___439);
    do_fio(&c__1, (char *)&jj_1.eh, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L309;

L308:
    io___440.ciunit = un_1.noutpt;
    s_wsfe(&io___440);
    do_fio(&c__1, (char *)&jj_1.pe, (ftnlen)sizeof(doublereal));
    e_wsfe();

L309:
    io___441.ciunit = un_1.noutpt;
    s_wsfe(&io___441);
    do_fio(&c__1, (char *)&jj_1.rho, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.tdspkg, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.tdspl, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___442.ciunit = un_1.noutpt;
    s_wsfe(&io___442);
    do_fio(&c__1, (char *)&ps_1.tolbt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ps_1.toldl, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ps_1.tolsat, (ftnlen)sizeof(doublereal));
    e_wsfe();

    io___443.ciunit = un_1.noutpt;
    s_wsfe(&io___443);
    e_wsfe();
    io___444.ciunit = un_1.noutpt;
    s_wsfe(&io___444);
    e_wsfe();

    i__1 = tt_1.nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	jk = ww_1.jflagb[ns - 1];
	if (jk < 0) {
	    goto L520;
	}
	cdum = ww_1.cspb[ns - 1];
	if (jk == 0 && cdum == 0.f) {
	    goto L520;
	}
	k = jk + 1;
	ns1 = ww_1.nspec[ns - 1];
	ns2 = ww_1.ibasis[ns1 - 1];
	if (ns2 == ns1) {
	    goto L292;
	}
	io___450.ciunit = un_1.noutpt;
	s_wsfe(&io___450);
	do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
	do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___451.ciunit = un_1.noutpt;
	s_wsfe(&io___451);
	do_fio(&c__1, gg_1.uspec + (ns2 - 1) * 24, (ftnlen)24);
	e_wsfe();
	goto L293;
L292:
	io___452.ciunit = un_1.noutpt;
	s_wsfe(&io___452);
	do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&jk, (ftnlen)sizeof(integer));
	do_fio(&c__1, gg_1.ujtype + (k - 1) * 24, (ftnlen)24);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
L293:
	if (jk != 19 && jk != 20) {
	    goto L425;
	}
	nx = 0;
	nm = ww_1.nsp[ns1 - 1];
	if (nm <= 50000) {
	    goto L415;
	}
	nm += -50000;
	nx = (integer) (nm / 100.f);
	ik = nm - nx * 100;
	nm = an_1.nend[ik + nx * 20 - 21];
L415:
	s_copy(unamsp, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (ftnlen)24);
	prreac_(_BLNK__1.cdrm, gg_1.uspec, unamsp, &nm, &tt_1.nsq, &tt_1.nsq1,
		 &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (ftnlen)24);

	goto L185;
L425:
	if (jk != 21) {
	    goto L185;
	}
	ng = ww_1.nsp[ns1 - 1];
	s_copy(unamsp, gg_1.ugas + (ng - 1) * 24, (ftnlen)24, (ftnlen)24);
	prreac_(_BLNK__1.cdrg, gg_1.uspec, unamsp, &ng, &tt_1.nsq, &tt_1.nsq1,
		 &tt_1.nsqmx1, &un_1.noutpt, (ftnlen)24, (ftnlen)24);

L185:

	if (ns1 <= tt_1.nsb) {
	    goto L520;
	}
	nrs = ns1 - tt_1.nsb;
	i__2 = tt_1.nsq;
	for (ndum = 2; ndum <= i__2; ++ndum) {
	    cdum = _BLNK__1.cdrs[ndum + nrs * 101 - 102];
	    if (cdum == 0.f) {
		goto L510;
	    }
	    if (jj_1.jflag[ndum - 1] >= 0) {
		goto L510;
	    }
	    if (ndum == ns2) {
		goto L510;
	    }
	    io___460.ciunit = un_1.noutpt;
	    s_wsfe(&io___460);
	    do_fio(&c__1, gg_1.uspec + (ndum - 1) * 24, (ftnlen)24);
	    e_wsfe();
L510:
	    ;
	}

L520:
	;
    }

    if (op_1.iopt4 != 2) {
	goto L195;
    }
    if (vw_1.nxtb <= 0) {
	goto L195;
    }
    io___461.ciunit = un_1.noutpt;
    s_wsfe(&io___461);
    e_wsfe();
    i__1 = tt_1.nxt;
    for (nx = 1; nx <= i__1; ++nx) {
	ncpt = vv_1.ncomp[nx - 1];
	i__2 = ncpt;
	for (ik = 1; ik <= i__2; ++ik) {
	    xdum = vv_1.xbar[ik + nx * 20 - 21];
	    if (xdum != 0.f) {
		goto L329;
	    }
/* L327: */
	}
	goto L190;
L329:
	io___464.ciunit = un_1.noutpt;
	s_wsfe(&io___464);
	do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___465.ciunit = un_1.noutpt;
	s_wsfe(&io___465);
	e_wsfe();
	i__2 = ncpt;
	for (ik = 1; ik <= i__2; ++ik) {
	    nm = an_1.nend[ik + nx * 20 - 21];
	    io___466.ciunit = un_1.noutpt;
	    s_wsfe(&io___466);
	    do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&vv_1.xbar[ik + nx * 20 - 21], (ftnlen)
		    sizeof(doublereal));
	    e_wsfe();
/* L188: */
	}
L190:
	;
    }
L195:
    io___467.ciunit = un_1.noutpt;
    s_wsfe(&io___467);
    e_wsfe();

    return 0;
} /* echox_ */

/* flgstx   last revised 12/09/87 by tjw */
/* Subroutine */ int flgstx_(doublereal *ars, doublereal *amn, doublereal *
	ags, char *uspec, char *umin, char *ugas, char *usolx, char *uxmod, 
	integer *jkflag, integer *nend, integer *jsflag, integer *jmflag, 
	integer *jgflag, integer *jxflag, integer *jflag, integer *ncomp, 
	integer *jxmod, integer *kxmod, integer *iopt4, integer *jst, integer 
	*jmt, integer *jgt, integer *jxt, integer *nxmod, integer *ntpr, 
	integer *nsb, integer *nsq, integer *nst, integer *nrst, integer *nmt,
	 integer *ngt, integer *nxt, integer *iktmax, integer *narxmx, 
	integer *ntprmx, integer *noutpt, integer *nttyo, ftnlen uspec_len, 
	ftnlen umin_len, ftnlen ugas_len, ftnlen usolx_len, ftnlen uxmod_len)
{
    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, jkflag_dim1, jkflag_offset, 
	    nend_dim1, nend_offset, i__1, i__2;

    /* Local variables */
    static integer ik, ng, nm, ns, nx, nsc, nrs, jdum, ncpt, nsupc;
    extern /* Subroutine */ int supprs_(integer *, integer *, integer *, char 
	    *, char *, char *, char *, char *, integer *, integer *, integer *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);


/*     this routine sets up the status arrays jsflag, jmflag,jkflag, */
/*     jxflag, and jgflag. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* ------------------------------------------------------------------ */

/*        jsflag = control array for aqueous species */
/*           = 0   normal status */
/*           = 2   thermodynamically suppressed */
/*           = 3   not present in a system of this composition */
/*                   or suppressed by jflag = -1 on the input file */

/*        jmflag = control array for pure minerals */
/*           = 0   normal status */
/*           = 2   thermodynamically suppressed */

/*        jkflag = control array for solid-solution end-members */
/*           (same as for jmflag) */

/*        jxflag = control array for solid-solution phases */
/*           = 0   normal status */
/*           = 4   ignored, components are not present or are */
/*              thermodynamically suppressed */

/*        jgflag = control array for gas species */
/*           (same as for jmflag) */

/* ------------------------------------------------------------------ */

    /* Parameter adjustments */
    uspec -= uspec_len;
    umin -= umin_len;
    ugas -= ugas_len;
    usolx -= usolx_len;
    uxmod -= uxmod_len;
    --jsflag;
    --jmflag;
    --jgflag;
    --jxflag;
    --jflag;
    --ncomp;
    --jxmod;
    --kxmod;
    nend_dim1 = *iktmax;
    nend_offset = 1 + nend_dim1;
    nend -= nend_offset;
    jkflag_dim1 = *iktmax;
    jkflag_offset = 1 + jkflag_dim1;
    jkflag -= jkflag_offset;
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
    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	jsflag[ns] = 0;
/* L3: */
    }
    jsflag[*nsb] = 2;

    i__1 = *nrst;
    for (nrs = 1; nrs <= i__1; ++nrs) {
	nsc = nrs + *nsb;
	if (nsc > *nsq) {
	    goto L10;
	}
	if (jflag[nsc] == 27) {
	    goto L10;
	}
	if (jflag[nsc] == 30) {
	    goto L10;
	}
	goto L15;
L10:
	if (ars[(*ntpr + nrs * ars_dim2) * ars_dim1 + 1] >= 500.f) {
	    jsflag[nsc] = 2;
	}
L15:
	;
    }

    i__1 = *nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	if (jflag[ns] < 0) {
	    jsflag[ns] = 3;
	}
/* L45: */
    }

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	jmflag[nm] = 0;
	if (amn[(*ntpr + nm * amn_dim2) * amn_dim1 + 1] >= 500.f) {
	    jmflag[nm] = 2;
	}
/* L65: */
    }

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	jgflag[ng] = 0;
	if (ags[(*ntpr + ng * ags_dim2) * ags_dim1 + 1] >= 500.f) {
	    jgflag[ng] = 2;
	}
/* L145: */
    }

    if (*iopt4 <= 0) {
	goto L115;
    }
    if (*nxt <= 0) {
	goto L115;
    }
    i__1 = *nxt;
    for (nx = 1; nx <= i__1; ++nx) {
	jxflag[nx] = 0;
	nsupc = 0;
	ncpt = ncomp[nx];
	i__2 = ncpt;
	for (ik = 1; ik <= i__2; ++ik) {
	    nm = nend[ik + nx * nend_dim1];
	    if (nm <= 0) {
		goto L87;
	    }
	    jdum = jmflag[nm];
	    if (jdum < 2) {
		goto L88;
	    }
L87:
	    jdum = 4;
	    ++nsupc;
L88:
	    jkflag[ik + nx * jkflag_dim1] = jdum;
/* L90: */
	}
	if (ncpt - nsupc > 1) {
	    goto L95;
	}
	jxflag[nx] = 4;
L95:
	;
    }
L115:

    supprs_(nxmod, &jxmod[1], &kxmod[1], uxmod + uxmod_len, uspec + uspec_len,
	     umin + umin_len, ugas + ugas_len, usolx + usolx_len, &jsflag[1], 
	    &jmflag[1], &jgflag[1], &jxflag[1], nst, nmt, ngt, nxt, noutpt, 
	    nttyo, uxmod_len, uspec_len, umin_len, ugas_len, usolx_len);

    *jst = 0;
    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	if (jsflag[ns] <= 0) {
	    ++(*jst);
	}
/* L50: */
    }

    *jmt = 0;
    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	if (jmflag[nm] <= 0) {
	    ++(*jmt);
	}
/* L80: */
    }

    *jgt = 0;
    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	if (jgflag[ng] <= 0) {
	    ++(*jgt);
	}
/* L150: */
    }

    *jxt = 0;
    if (*iopt4 <= 0) {
	goto L999;
    }
    i__1 = *nxt;
    for (nx = 1; nx <= i__1; ++nx) {
	if (jxflag[nx] <= 0) {
	    ++(*jxt);
	}
/* L110: */
    }

L999:
    return 0;
} /* flgstx_ */

/* gases    last revised 05/20/87 by rlh */
/* Subroutine */ int gases_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer ng, ns;
    static doublereal cdum, fdum;
    extern doublereal texp_(doublereal *);


/*     24jul86 by tjw */


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
/* bt.h */


/* -------------------------------------------------------------------- */
/* cc.h */

/* -------------------------------------------------------------------- */
/* fg.h */
/* -------------------------------------------------------------------- */
/* gg.h */
/* -------------------------------------------------------------------- */
/* hh.h */
/* ----------------------------------------------------------------------- */
/* jj.h */

/* -------------------------------------------------------------------- */
/* ka.h */
/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* op1.h */
/* -------------------------------------------------------------------- */
/* op2.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* eqldd.h */
/* -------------------------------------------------------------------- */

/* ------------------------------------------------------------------- */

/* eqlpp.h */
/* -------------------------------------------------------------------- */
    i__1 = tt_1.ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	fg_1.fuglg[ng - 1] = -999.f;
	fg_1.fug[ng - 1] = 0.f;
	if (ka_1.jgflag[ng - 1] >= 2) {
	    goto L30;
	}
	fdum = -xx_1.xlkg[ng - 1] + _BLNK__1.cdrg[tt_1.nsb + ng * 101 - 102] *
		 cc_1.fo2lg;
	fdum += _BLNK__1.cdrg[ng * 101 - 101] * yy_1.actlg[0];
	i__2 = tt_1.nsq;
	for (ns = 2; ns <= i__2; ++ns) {
	    cdum = _BLNK__1.cdrg[ns + ng * 101 - 102];
	    if (cdum == 0.f) {
		goto L25;
	    }
	    if (ns == tt_1.nsb) {
		goto L25;
	    }
	    if (ka_1.jsflag[ns - 1] >= 2) {
		goto L30;
	    }
	    fdum += cdum * yy_1.actlg[ns - 1];
L25:
	    ;
	}
	fdum = -fdum / _BLNK__1.cdrg[tt_1.nsq1 + ng * 101 - 102];
	fg_1.fuglg[ng - 1] = fdum;
	fg_1.fug[ng - 1] = texp_(&fdum);
L30:
	;
    }

    return 0;
} /* gases_ */

/* gcsp     last revised 12/19/87 by tjw */
/* *gcsp created in f77 12/18/87 by tjw */
/* Subroutine */ int gcsp_(doublereal *csp, doublereal *cspb, char *uspecb, 
	char *uspecd, integer *jflag, integer *jflagb, integer *nspec, 
	integer *is, integer *nsqb, integer *nsb, integer *nerr, integer *
	noutpt, integer *nttyo, ftnlen uspecb_len, ftnlen uspecd_len)
{
    /* Format strings */
    static char fmt_1000[] = "(/\002 * error- \002,a24,\002 was specified mo"
	    "re than\002,/7x,\002once on the input file (gcsp)\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer ns;
    static doublereal cspi;
    static integer jflagi;

    /* Fortran I/O blocks */
    static cilist io___483 = { 0, 0, 0, fmt_1000, 0 };
    static cilist io___484 = { 0, 0, 0, fmt_1000, 0 };



/*     this routine sets up the jflag and csp arrays for aqueous */
/*     species in the basis set.  the nsp array is set up in routine */
/*     indatx after the minerals, gases, and solid solutions have */
/*     been read in. */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */


/* ------------------------------------------------------------------ */

    /* Parameter adjustments */
    --nspec;
    --jflagb;
    --jflag;
    uspecb -= uspecb_len;
    --cspb;
    --csp;

    /* Function Body */
    jflag[*is] = -1;
    if (*is > *nsb) {
	jflag[*is] = 30;
    }
    csp[*is] = 0.f;

    i__1 = *nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	if (s_cmp(uspecd, uspecb + ns * uspecb_len, (ftnlen)18, (ftnlen)18) !=
		 0) {
	    goto L100;
	}
	if (nspec[ns] > 0) {
	    io___483.ciunit = *noutpt;
	    s_wsfe(&io___483);
	    do_fio(&c__1, uspecd, uspecd_len);
	    e_wsfe();
	    io___484.ciunit = *nttyo;
	    s_wsfe(&io___484);
	    do_fio(&c__1, uspecd, uspecd_len);
	    e_wsfe();
	    ++(*nerr);
	    goto L999;
	}
	nspec[ns] = *is;
	jflagi = jflagb[ns];
	cspi = cspb[ns];
	if (jflagi <= 15) {
	    if (cspi <= 0.f) {
		jflagi = -1;
	    }
	}
	jflag[*is] = jflagi;
	csp[*is] = cspi;
	goto L999;

L100:
	;
    }

L999:
    return 0;
} /* gcsp_ */

/* indatx   last revised 12/22/87 by tjw */
/* Subroutine */ int indatx_(doublereal *cess, doublereal *cdrs, doublereal *
	cdrm, doublereal *cdrg, doublereal *cstor, doublereal *ac2, 
	doublereal *awo, doublereal *ars, doublereal *amn, doublereal *ags, 
	doublereal *apress, doublereal *aadh, doublereal *abdh, doublereal *
	abdot, doublereal *aeh, doublereal *apx, doublereal *xbar, doublereal 
	*xbarlg, doublereal *xbarlm, doublereal *z__, doublereal *titr, 
	doublereal *azero, doublereal *hydn, doublereal *mwtss, doublereal *
	atwt, doublereal *xlkmod, doublereal *tempc, doublereal *press, 
	doublereal *afcnst, char *ussnp, char *udrxd, char *uspec, char *umin,
	 char *ugas, char *usolx, char *uelem, char *uxmod, char *utitld, 
	char *uredox, integer *nend, integer *jflag, integer *jcflag, integer 
	*ncomp, integer *jsol, integer *nxmod, integer *jxmod, integer *kxmod,
	 integer *iopt8, integer *iopr1, integer *iodb1, integer *nct, 
	integer *nsb, integer *nsb1, integer *nsq, integer *nsq1, integer *
	nsqb, integer *nst, integer *nrst, integer *nmt, integer *ngt, 
	integer *nxt, integer *ist, integer *irst, integer *imt, integer *igt,
	 integer *ntpr, integer *nctmax, integer *nsqmax, integer *nsqmx1, 
	integer *nstmax, integer *nmtmax, integer *ngtmax, integer *nxtmax, 
	integer *iktmax, integer *narxmx, integer *ntprmx, integer *iapxmx, 
	integer *noutpt, integer *nttyo, integer *nad1, integer *nahv, ftnlen 
	ussnp_len, ftnlen udrxd_len, ftnlen uspec_len, ftnlen umin_len, 
	ftnlen ugas_len, ftnlen usolx_len, ftnlen uelem_len, ftnlen uxmod_len,
	 ftnlen utitld_len, ftnlen uredox_len)
{
    /* Initialized data */

    static char uendit[8] = "endit.  ";
    static char ublank[8] = "        ";
    static char uo2aq[8] = "O2(AQ)  ";
    static char uh2aq[8] = "H2(AQ)  ";
    static char uh[8] = "H       ";
    static char udata1[8] = "data1   ";
    static integer nttlmx = 30;

    /* Format strings */
    static char fmt_4001[] = "(/\002 --- reading the data1 file ---\002)";
    static char fmt_3000[] = "(\002 * error- wrong file header = \002,a8,"
	    "\002 on data1\002)";
    static char fmt_116[] = "(\002 * error- nct= \002,i5,\002 exceeds the di"
	    "mensioned\002,/7x,\002limit nctmax= \002,i5,\002 (indatx)\002)";
    static char fmt_118[] = "(\002 * error- nsq= \002,i5,\002 exceeds the di"
	    "mensioned\002,/7x,\002limit nsqmax= \002,i5,\002 (indatx)\002)";
    static char fmt_3083[] = "(/\002 * error- \002,a24,\002 has bad element "
	    "name \002,a8,/7x,\002 on file data1 (indatx)\002)";
    static char fmt_3114[] = "(15x,\002loading \002,a24,\002 into memory\002)"
	    ;
    static char fmt_3111[] = "(20x,a24,\002 not loaded into memory\002)";
    static char fmt_3115[] = "(/\002 * error- the maximum \002,i5,\002 aqueo"
	    "us species have\002,/7x,\002been exceeded reading the file data1"
	    " (indatx)\002)";
    static char fmt_3126[] = "(/\002 * error- \002,a24,\002 has bad species "
	    "name \002,a24,/7x,\002in its associated reaction on the data fil"
	    "e (indatx)\002)";
    static char fmt_3135[] = "(/\002 * error- the maximum \002,i5,\002 pure "
	    "minerals have \002,/7x,\002been exceeded reading the data file ("
	    "indatx)\002)";
    static char fmt_3155[] = "(/\002 * error- the maximum \002,i5,\002 gas s"
	    "pecies have \002,/7x,\002been exceeded reading the data file (in"
	    "datx)\002)";
    static char fmt_237[] = "(\002 * error- \002,a24,\002 was on input but w"
	    "as not read\002,/7x,\002from the data file (indatx)\002)";
    static char fmt_3132[] = "(/\002 * error- the maximum \002,i5,\002 solid"
	    " solutions have \002,/7x,\002been exceeded reading the data file"
	    " (indatx)\002)";
    static char fmt_254[] = "(\002 * error- \002,a24,\002 is specified to sw"
	    "itch with both \002,/7x,a24,\002 and \002,a24,\002 (indatx)\002)";
    static char fmt_258[] = "(\002 error- \002,a24,\002 is specified to swit"
	    "ch with \002,a24,/7x,\002but is not in the list of aqueous speci"
	    "es (indatx)\002)";
    static char fmt_255[] = "(\002 * error- \002,a24,\002 is required for a "
	    "heterogeneous\002,/7x,\002equilibrium constraint but was not rea"
	    "d from the\002,/7x,\002the data file (indatx)\002)";
    static char fmt_800[] = "(/\002 --- list of decoded input data ---\002,/"
	    "/7x,\002ns\002,6x,\002species\002,9x,\002csp\002,8x,\002jflag"
	    "\002,4x,\002nsp\002,/)";
    static char fmt_805[] = "(6x,i3,3x,a12,3x,e12.5,3x,i3,3x,i5)";
    static char fmt_843[] = "(/\002 --- matching of species from input and d"
	    "ata1\002,\002 ---\002,/)";
    static char fmt_846[] = "(3x,i3,3x,a12,5x,i3,3x,a12)";
    static char fmt_853[] = "(/\002 * error- \002,i5,\002 errors matching da"
	    "ta from input\002,/7x,\002and the data file (indatx)\002)";
    static char fmt_4007[] = "(/\002 --- the data1 file has been successfull"
	    "y read ---\002)";

    /* System generated locals */
    integer ussnp_dim1, ussnp_offset, cess_dim1, cess_offset, cdrs_dim1, 
	    cdrs_offset, cdrm_dim1, cdrm_offset, cdrg_dim1, cdrg_offset, 
	    cstor_dim1, cstor_offset, ac2_dim1, ac2_dim2, ac2_offset, 
	    awo_dim1, awo_dim2, awo_offset, ars_dim1, ars_dim2, ars_offset, 
	    amn_dim1, amn_dim2, amn_offset, ags_dim1, ags_dim2, ags_offset, 
	    apress_dim1, apress_offset, aadh_dim1, aadh_offset, abdh_dim1, 
	    abdh_offset, abdot_dim1, abdot_offset, aeh_dim1, aeh_offset, 
	    apx_dim1, apx_offset, xbar_dim1, xbar_offset, xbarlg_dim1, 
	    xbarlg_offset, xbarlm_dim1, xbarlm_offset, nend_dim1, nend_offset,
	     i__1, i__2, i__3;
    alist al__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), f_rew(alist *), s_rsue(cilist *), 
	    do_uio(integer *, char *, ftnlen), e_rsue(void), s_cmp(char *, 
	    char *, ftnlen, ftnlen), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, n, ic, nc, ik, ng, nh, nm, is;
    static doublereal zd;
    static integer ns, nx, ikb;
    static doublereal ard[10]	/* was [5][2] */;
    static integer jfl, isc, nsc, ikt, nxb, nrs;
    extern doublereal tlg_(doublereal *);
    static doublereal dum1, dum2, dum3;
    static integer iktb, ilim;
    extern /* Subroutine */ int gkey_(char *, char *, ftnlen, ftnlen), gcsp_(
	    doublereal *, doublereal *, char *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, ftnlen, ftnlen);
    static integer ndum, nerr, ncts, jdum, nlim;
    static doublereal xdum;
    static char ustr[8];
    static integer ndum1, ndum2, ndum3, ndum4, ndum5, ndum6;
    static char ustr1[8], ustr2[8], ustr3[8];
    extern /* Subroutine */ int modah_(integer *, integer *, doublereal *, 
	    char *, doublereal *, ftnlen);
    static doublereal cdrsd[101], cessd[70], oxfac[70], cessi[70];
    static char uflag[8];
    static doublereal hydnd;
    static logical qload;
    static doublereal titrd;
    static integer ndrst, kount;
    static char ustr80[80];
    static integer jflagi;
    extern /* Subroutine */ int indatc_(doublereal *, integer *, integer *, 
	    integer *);
    static char uelemd[8*70];
    extern /* Subroutine */ int indatk_(integer *, doublereal *, integer *, 
	    integer *, integer *);
    static char uspecd[24], uoxide[8*70], uspecj[24];
    static integer ntitld;
    static doublereal mwtssd, azerod;
    extern /* Subroutine */ int alters_(integer *, integer *, integer *, 
	    doublereal *, char *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, char *, char *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___495 = { 0, 0, 0, fmt_4001, 0 };
    static cilist io___496 = { 0, 0, 0, fmt_4001, 0 };
    static cilist io___497 = { 0, 0, 0, 0, 0 };
    static cilist io___499 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___500 = { 0, 0, 0, fmt_3000, 0 };
    static cilist io___501 = { 0, 0, 0, 0, 0 };
    static cilist io___503 = { 0, 0, 0, 0, 0 };
    static cilist io___504 = { 0, 0, 0, fmt_116, 0 };
    static cilist io___505 = { 0, 0, 0, fmt_116, 0 };
    static cilist io___506 = { 0, 0, 0, fmt_118, 0 };
    static cilist io___507 = { 0, 0, 0, fmt_118, 0 };
    static cilist io___510 = { 0, 0, 0, 0, 0 };
    static cilist io___511 = { 0, 0, 0, 0, 0 };
    static cilist io___514 = { 0, 0, 0, 0, 0 };
    static cilist io___520 = { 0, 0, 0, 0, 0 };
    static cilist io___524 = { 0, 0, 0, 0, 0 };
    static cilist io___531 = { 0, 0, 0, 0, 0 };
    static cilist io___537 = { 0, 0, 0, 0, 0 };
    static cilist io___542 = { 0, 0, 0, fmt_3083, 0 };
    static cilist io___543 = { 0, 0, 0, fmt_3083, 0 };
    static cilist io___544 = { 0, 0, 0, 0, 0 };
    static cilist io___546 = { 0, 0, 0, 0, 0 };
    static cilist io___548 = { 0, 0, 0, fmt_3114, 0 };
    static cilist io___549 = { 0, 0, 0, fmt_3111, 0 };
    static cilist io___550 = { 0, 0, 0, fmt_3115, 0 };
    static cilist io___551 = { 0, 0, 0, fmt_3115, 0 };
    static cilist io___554 = { 0, 0, 0, fmt_3126, 0 };
    static cilist io___555 = { 0, 0, 0, fmt_3126, 0 };
    static cilist io___557 = { 0, 0, 0, fmt_3135, 0 };
    static cilist io___558 = { 0, 0, 0, fmt_3135, 0 };
    static cilist io___559 = { 0, 0, 0, fmt_3126, 0 };
    static cilist io___560 = { 0, 0, 0, fmt_3126, 0 };
    static cilist io___561 = { 0, 0, 0, fmt_3155, 0 };
    static cilist io___562 = { 0, 0, 0, fmt_3155, 0 };
    static cilist io___563 = { 0, 0, 0, fmt_3126, 0 };
    static cilist io___564 = { 0, 0, 0, fmt_3126, 0 };
    static cilist io___565 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___566 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___570 = { 0, 0, 0, 0, 0 };
    static cilist io___572 = { 0, 0, 0, 0, 0 };
    static cilist io___578 = { 0, 0, 0, 0, 0 };
    static cilist io___580 = { 0, 0, 0, fmt_3132, 0 };
    static cilist io___581 = { 0, 0, 0, fmt_3132, 0 };
    static cilist io___582 = { 0, 0, 0, fmt_3114, 0 };
    static cilist io___583 = { 0, 0, 0, 0, 0 };
    static cilist io___585 = { 0, 0, 0, fmt_254, 0 };
    static cilist io___586 = { 0, 0, 0, fmt_254, 0 };
    static cilist io___587 = { 0, 0, 0, fmt_258, 0 };
    static cilist io___588 = { 0, 0, 0, fmt_258, 0 };
    static cilist io___590 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___591 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___594 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___595 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___596 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___597 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___599 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___600 = { 0, 0, 0, fmt_255, 0 };
    static cilist io___601 = { 0, 0, 0, fmt_800, 0 };
    static cilist io___602 = { 0, 0, 0, fmt_805, 0 };
    static cilist io___603 = { 0, 0, 0, fmt_843, 0 };
    static cilist io___604 = { 0, 0, 0, fmt_846, 0 };
    static cilist io___607 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___608 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___611 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___612 = { 0, 0, 0, fmt_237, 0 };
    static cilist io___614 = { 0, 0, 0, fmt_853, 0 };
    static cilist io___615 = { 0, 0, 0, fmt_853, 0 };
    static cilist io___623 = { 0, 0, 0, fmt_4007, 0 };
    static cilist io___624 = { 0, 0, 0, fmt_4007, 0 };



/*     this routine reads the supporting data file data1.  the first */
/*     line of this file is read by the main program and is skipped here. */


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
/* vw.h */


/* -------------------------------------------------------------------- */
/* ww.h */

/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlej.h */
/* -------------------------------------------------------------------- */

/* eqlgp.h */


/* -------------------------------------------------------------------- */




    /* Parameter adjustments */
    --z__;
    --titr;
    --azero;
    --hydn;
    --mwtss;
    --atwt;
    --xlkmod;
    udrxd -= udrxd_len;
    uspec -= uspec_len;
    umin -= umin_len;
    ugas -= ugas_len;
    usolx -= usolx_len;
    uelem -= uelem_len;
    uxmod -= uxmod_len;
    utitld -= utitld_len;
    --jflag;
    --jcflag;
    --ncomp;
    --jsol;
    --nxmod;
    --jxmod;
    --kxmod;
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
    cstor_dim1 = *nstmax;
    cstor_offset = 1 + cstor_dim1;
    cstor -= cstor_offset;
    nend_dim1 = *iktmax;
    nend_offset = 1 + nend_dim1;
    nend -= nend_offset;
    ussnp_dim1 = *iktmax;
    ussnp_offset = 1 + ussnp_dim1;
    ussnp -= ussnp_offset * ussnp_len;
    xbarlm_dim1 = *iktmax;
    xbarlm_offset = 1 + xbarlm_dim1;
    xbarlm -= xbarlm_offset;
    xbarlg_dim1 = *iktmax;
    xbarlg_offset = 1 + xbarlg_dim1;
    xbarlg -= xbarlg_offset;
    xbar_dim1 = *iktmax;
    xbar_offset = 1 + xbar_dim1;
    xbar -= xbar_offset;
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
    awo_dim1 = *narxmx;
    awo_dim2 = *ntprmx;
    awo_offset = 1 + awo_dim1 * (1 + awo_dim2);
    awo -= awo_offset;
    ac2_dim1 = *narxmx;
    ac2_dim2 = *ntprmx;
    ac2_offset = 1 + ac2_dim1 * (1 + ac2_dim2);
    ac2 -= ac2_offset;
    apx_dim1 = *iapxmx;
    apx_offset = 1 + apx_dim1;
    apx -= apx_offset;

    /* Function Body */




/* ---------------------------------------------------------------------- */

    nerr = 0;
    io___495.ciunit = *noutpt;
    s_wsfe(&io___495);
    e_wsfe();
    io___496.ciunit = *nttyo;
    s_wsfe(&io___496);
    e_wsfe();

/*     read file data1, unit number is nad1 */

    al__1.aerr = 0;
    al__1.aunit = *nad1;
    f_rew(&al__1);
    io___497.ciunit = *nad1;
    s_rsue(&io___497);
    do_uio(&c__1, ustr, (ftnlen)8);
    e_rsue();

    if (s_cmp(ustr, udata1, (ftnlen)8, (ftnlen)8) != 0) {
	io___499.ciunit = *noutpt;
	s_wsfe(&io___499);
	do_fio(&c__1, ustr, (ftnlen)8);
	e_wsfe();
	io___500.ciunit = *nttyo;
	s_wsfe(&io___500);
	do_fio(&c__1, ustr, (ftnlen)8);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     check consistency between the activity coefficient option and the */
/*     data1 file */

    io___501.ciunit = *nad1;
    s_rsue(&io___501);
    do_uio(&c__1, uflag, (ftnlen)8);
    e_rsue();
    gkey_(uflag, udata1, (ftnlen)8, (ftnlen)8);

    io___503.ciunit = *nad1;
    s_rsue(&io___503);
    do_uio(&c__1, (char *)&(*nct), (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&(*nsq), (ftnlen)sizeof(integer));
    e_rsue();

    *nsb = *nct + 1;
    *nsb1 = *nsb + 1;
    *nsq1 = *nsq + 1;
    if (*nct > *nctmax) {
	io___504.ciunit = *noutpt;
	s_wsfe(&io___504);
	do_fio(&c__1, (char *)&(*nct), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nctmax), (ftnlen)sizeof(integer));
	e_wsfe();
	io___505.ciunit = *nttyo;
	s_wsfe(&io___505);
	do_fio(&c__1, (char *)&(*nct), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nctmax), (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    if (*nsq > *nsqmax) {
	io___506.ciunit = *noutpt;
	s_wsfe(&io___506);
	do_fio(&c__1, (char *)&(*nsq), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nsqmax), (ftnlen)sizeof(integer));
	e_wsfe();
	io___507.ciunit = *nttyo;
	s_wsfe(&io___507);
	do_fio(&c__1, (char *)&(*nsq), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nsqmax), (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

    ntitld = 0;
    i__1 = nttlmx;
    for (n = 1; n <= i__1; ++n) {
	io___510.ciunit = *nad1;
	s_rsue(&io___510);
	do_uio(&c__1, utitld + n * utitld_len, utitld_len);
	e_rsue();
	++ntitld;
	if (s_cmp(utitld + n * utitld_len, uendit, (ftnlen)8, (ftnlen)8) == 0)
		 {
	    goto L4;
	}
	if (ntitld >= 4) {
	    goto L4;
	}
/* L3: */
    }
L4:

    io___511.ciunit = *nad1;
    s_rsue(&io___511);
    do_uio(&c__1, ustr80, (ftnlen)80);
    e_rsue();

/*     read elements data */

    i__1 = *nct;
    for (nc = 1; nc <= i__1; ++nc) {
	io___514.ciunit = *nad1;
	s_rsue(&io___514);
	do_uio(&c__1, uelem + nc * uelem_len, uelem_len);
	do_uio(&c__1, (char *)&atwt[nc], (ftnlen)sizeof(doublereal));
	do_uio(&c__1, uoxide + (nc - 1 << 3), (ftnlen)8);
	do_uio(&c__1, (char *)&oxfac[nc - 1], (ftnlen)sizeof(doublereal));
	e_rsue();
/* L3020: */
    }
    oxfac[0] = 0.f;

    indatc_(&apress[apress_offset], nad1, narxmx, ntprmx);
    indatc_(&aadh[aadh_offset], nad1, narxmx, ntprmx);
    indatc_(&abdh[abdh_offset], nad1, narxmx, ntprmx);
    indatc_(&abdot[abdot_offset], nad1, narxmx, ntprmx);

    for (k = 1; k <= 4; ++k) {
	indatk_(&k, &ac2[ac2_offset], nad1, narxmx, ntprmx);
/* L70: */
    }

    for (k = 1; k <= 4; ++k) {
	indatk_(&k, &awo[awo_offset], nad1, narxmx, ntprmx);
/* L75: */
    }

    indatc_(&aeh[aeh_offset], nad1, narxmx, ntprmx);

/*     the following calls read now obsolete data for xlko2,xlkh2,xlkn2 */

    indatc_(ard, nad1, narxmx, ntprmx);
    indatc_(ard, nad1, narxmx, ntprmx);
    indatc_(ard, nad1, narxmx, ntprmx);

/*     grab the necessary aqueous species, mineral, and gas data */

/*        nst = aqueous species tally */
/*        nmt = minerals tally */
/*        ngt = gases tally */

    *nst = 0;
    *nmt = 0;
    *ngt = 0;

    jcflag[1] = 1;

/* ---------- main loop ------------------------------------------------- */

/*                             *---------------------------------------- */
/*                             * ilim = 1/2/3 for */
/*                             *  aqueous species/minerals/gases */
/*                             *---------------------------------------- */
    for (ilim = 1; ilim <= 3; ++ilim) {
	io___520.ciunit = *nad1;
	s_rsue(&io___520);
	do_uio(&c__1, ustr, (ftnlen)8);
	do_uio(&c__1, ustr2, (ftnlen)8);
	do_uio(&c__1, ustr3, (ftnlen)8);
	e_rsue();

/* - - - - - - data input loop - - - - - - - - - - - - - - - - - - - - - */

	for (is = 1; is <= 10000; ++is) {
	    io___524.ciunit = *nad1;
	    s_rsue(&io___524);
	    do_uio(&c__1, uspecd, (ftnlen)24);
	    do_uio(&c__1, (char *)&ncts, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ndrst, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ndum1, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ndum2, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ndum3, (ftnlen)sizeof(integer));
	    e_rsue();
	    if (s_cmp(uspecd, uendit, (ftnlen)8, (ftnlen)8) == 0) {
		goto L3325;
	    }

/* ---------------- */
	    if (ilim <= 1 && is <= *nsq) {
		gcsp_(ww_1.csp, ww_1.cspb, wwc_1.uspecb, uspecd, &jflag[1], 
			ww_1.jflagb, ww_1.nspec, &is, nsqb, nsb, &nerr, 
			noutpt, nttyo, (ftnlen)24, (ftnlen)24);
	    }
/* ---------------- */

	    io___531.ciunit = *nad1;
	    s_rsue(&io___531);
	    do_uio(&c__1, (char *)&mwtssd, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&zd, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&titrd, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&azerod, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&hydnd, (ftnlen)sizeof(doublereal));
	    e_rsue();

	    if (ncts <= 0) {
		goto L3075;
	    }
	    io___537.ciunit = *nad1;
	    s_rsue(&io___537);
	    i__1 = ncts;
	    for (n = 1; n <= i__1; ++n) {
		do_uio(&c__1, (char *)&cessd[n - 1], (ftnlen)sizeof(
			doublereal));
		do_uio(&c__1, uelemd + (n - 1 << 3), (ftnlen)8);
	    }
	    e_rsue();

L3075:
	    i__1 = *nctmax;
	    for (nc = 1; nc <= i__1; ++nc) {
		cessi[nc - 1] = 0.f;
/* L3080: */
	    }

	    qload = TRUE_;
	    if (ncts <= 0) {
		if (is != *nsb || ilim >= 2) {
		    qload = FALSE_;
		}
		goto L3105;
	    }

	    i__1 = ncts;
	    for (n = 1; n <= i__1; ++n) {

		i__2 = *nct;
		for (nc = 1; nc <= i__2; ++nc) {
		    if (s_cmp(uelemd + (n - 1 << 3), uelem + nc * uelem_len, (
			    ftnlen)8, (ftnlen)8) == 0) {
			goto L3095;
		    }
/* L3085: */
		}

/*     error, no match */

		io___542.ciunit = *noutpt;
		s_wsfe(&io___542);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, uelemd + (n - 1 << 3), (ftnlen)8);
		e_wsfe();
		io___543.ciunit = *nttyo;
		s_wsfe(&io___543);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, uelemd + (n - 1 << 3), (ftnlen)8);
		e_wsfe();
		s_stop("", (ftnlen)0);

L3095:
		cessi[nc - 1] = cessd[n - 1];
		if (cessi[nc - 1] == 0.f) {
		    goto L3100;
		}
		if (ilim >= 2 || is > *nsq) {
		    if (jcflag[nc] != 1) {
			qload = FALSE_;
		    }
		    goto L3100;
		}
		if (jflag[is] <= 15) {
/* ---------------------------------------- */
		    if (ww_1.csp[is - 1] > 0.f) {
			jcflag[nc] = 1;
		    }
/* ---------------------------------------- */
		    goto L3100;
		}
		if (jflag[is] != 27 && jflag[is] != 30) {
		    jcflag[nc] = 1;
		}
L3100:
		;
	    }

/*        read the associated reaction data, if any */

L3105:
	    if (ndrst > 0) {
		io___544.ciunit = *nad1;
		s_rsue(&io___544);
		i__1 = ndrst;
		for (n = 1; n <= i__1; ++n) {
		    do_uio(&c__1, (char *)&cdrsd[n - 1], (ftnlen)sizeof(
			    doublereal));
		    do_uio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		}
		e_rsue();
		io___546.ciunit = *nad1;
		s_rsue(&io___546);
		i__1 = *narxmx;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    do_uio(&c__1, (char *)&ard[i__ - 1], (ftnlen)sizeof(
			    doublereal));
		}
		i__2 = *narxmx;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    do_uio(&c__1, (char *)&ard[i__ + 4], (ftnlen)sizeof(
			    doublereal));
		}
		e_rsue();
	    }

	    if (*iopr1 >= 1) {
		if (qload) {
		    io___548.ciunit = *noutpt;
		    s_wsfe(&io___548);
		    do_fio(&c__1, uspecd, (ftnlen)24);
		    e_wsfe();
		} else {
		    io___549.ciunit = *noutpt;
		    s_wsfe(&io___549);
		    do_fio(&c__1, uspecd, (ftnlen)24);
		    e_wsfe();
		}
	    }
	    if (! qload) {
		goto L3170;
	    }

/*        load the species and associated data into memory */

/*       test for minerals */
	    if (ilim == 2) {
		goto L3130;
	    }

/*       test for gases */
	    if (ilim >= 3) {
		goto L3150;
	    }

/*                             ----------------------------------------- */
/*                             * aqueous species */
/*                             ----------------------------------------- */

	    ++(*nst);
	    if (*nst > *nstmax) {
		io___550.ciunit = *noutpt;
		s_wsfe(&io___550);
		do_fio(&c__1, (char *)&(*nstmax), (ftnlen)sizeof(integer));
		e_wsfe();
		io___551.ciunit = *nttyo;
		s_wsfe(&io___551);
		do_fio(&c__1, (char *)&(*nstmax), (ftnlen)sizeof(integer));
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }

	    s_copy(uspec + *nst * uspec_len, uspecd, uspec_len, (ftnlen)24);

	    i__1 = *nct;
	    for (nc = 1; nc <= i__1; ++nc) {
		cess[nc + *nst * cess_dim1] = cessi[nc - 1];
/* L3125: */
	    }

	    mwtss[*nst] = mwtssd;
	    z__[*nst] = zd;
	    titr[*nst] = titrd;
	    azero[*nst] = azerod;
	    hydn[*nst] = hydnd;
	    if (*nst <= *nsb) {
		goto L3170;
	    }
	    nrs = *nst - *nsb;

	    i__1 = *nsq;
	    for (ns = 1; ns <= i__1; ++ns) {
		cdrs[ns + nrs * cdrs_dim1] = 0.f;
/* L3123: */
	    }

	    cdrs[*nsq1 + nrs * cdrs_dim1] = cdrsd[0];

	    i__1 = ndrst;
	    for (n = 2; n <= i__1; ++n) {

		i__2 = *nsq;
		for (ns = 1; ns <= i__2; ++ns) {
		    if (s_cmp(udrxd + n * udrxd_len, uspec + ns * uspec_len, (
			    ftnlen)12, (ftnlen)12) == 0) {
			goto L3128;
		    }
/* L3127: */
		}

/*     error, not found */

		io___554.ciunit = *noutpt;
		s_wsfe(&io___554);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		e_wsfe();
		io___555.ciunit = *nttyo;
		s_wsfe(&io___555);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		e_wsfe();
		s_stop("", (ftnlen)0);

L3128:
		cdrs[ns + nrs * cdrs_dim1] = cdrsd[n - 1];
/* L3129: */
	    }

	    i__1 = *ntprmx;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *narxmx;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    ars[i__ + (j + nrs * ars_dim2) * ars_dim1] = ard[i__ + j *
			     5 - 6];
/* L4105: */
		}
/* L4110: */
	    }

	    goto L3170;

/*                             ----------------------------------------- */
/*                             * minerals */
/*                             ----------------------------------------- */

L3130:
	    ++(*nmt);
	    if (*nmt > *nmtmax) {
		io___557.ciunit = *noutpt;
		s_wsfe(&io___557);
		do_fio(&c__1, (char *)&(*nmtmax), (ftnlen)sizeof(integer));
		e_wsfe();
		io___558.ciunit = *nttyo;
		s_wsfe(&io___558);
		do_fio(&c__1, (char *)&(*nmtmax), (ftnlen)sizeof(integer));
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }

	    s_copy(umin + *nmt * umin_len, uspecd, umin_len, (ftnlen)24);

/* --------------------------------- */







/* --------------------------------- */
	    i__1 = *nsq;
	    for (ns = 1; ns <= i__1; ++ns) {
		cdrm[ns + *nmt * cdrm_dim1] = 0.f;
/* L3143: */
	    }

	    cdrm[*nsq1 + *nmt * cdrm_dim1] = cdrsd[0];

/*       search for name in uspec */

	    i__1 = ndrst;
	    for (n = 2; n <= i__1; ++n) {

		i__2 = *nsq;
		for (ns = 1; ns <= i__2; ++ns) {
		    if (s_cmp(udrxd + n * udrxd_len, uspec + ns * uspec_len, (
			    ftnlen)12, (ftnlen)12) == 0) {
			goto L3148;
		    }
/* L3147: */
		}

/*     error, not found */

		io___559.ciunit = *noutpt;
		s_wsfe(&io___559);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		e_wsfe();
		io___560.ciunit = *nttyo;
		s_wsfe(&io___560);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		e_wsfe();
		s_stop("", (ftnlen)0);

L3148:
		cdrm[ns + *nmt * cdrm_dim1] = cdrsd[n - 1];
/* L3149: */
	    }

	    i__1 = *ntprmx;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *narxmx;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    amn[i__ + (j + *nmt * amn_dim2) * amn_dim1] = ard[i__ + j 
			    * 5 - 6];
/* L4115: */
		}
/* L4120: */
	    }

	    goto L3170;

/*                             ----------------------------------------- */
/*                             * gases */
/*                             ----------------------------------------- */

L3150:
	    ++(*ngt);
	    if (*ngt > *ngtmax) {
		io___561.ciunit = *noutpt;
		s_wsfe(&io___561);
		do_fio(&c__1, (char *)&(*ngtmax), (ftnlen)sizeof(integer));
		e_wsfe();
		io___562.ciunit = *nttyo;
		s_wsfe(&io___562);
		do_fio(&c__1, (char *)&(*ngtmax), (ftnlen)sizeof(integer));
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }

	    s_copy(ugas + *ngt * ugas_len, uspecd, ugas_len, (ftnlen)24);

/* --------------------------------- */






/* --------------------------------- */
	    i__1 = *nsq;
	    for (ns = 1; ns <= i__1; ++ns) {
		cdrg[ns + *ngt * cdrg_dim1] = 0.f;
/* L3163: */
	    }

	    cdrg[*nsq1 + *ngt * cdrg_dim1] = cdrsd[0];

/*       search for name in uspec */

	    i__1 = ndrst;
	    for (n = 2; n <= i__1; ++n) {
		i__2 = *nsq;
		for (ns = 1; ns <= i__2; ++ns) {
		    if (s_cmp(udrxd + n * udrxd_len, uspec + ns * uspec_len, (
			    ftnlen)12, (ftnlen)12) == 0) {
			goto L3168;
		    }
/* L3167: */
		}

/*     error, not found */

		io___563.ciunit = *noutpt;
		s_wsfe(&io___563);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		e_wsfe();
		io___564.ciunit = *nttyo;
		s_wsfe(&io___564);
		do_fio(&c__1, uspecd, (ftnlen)24);
		do_fio(&c__1, udrxd + n * udrxd_len, udrxd_len);
		e_wsfe();
		s_stop("", (ftnlen)0);

L3168:
		cdrg[ns + *ngt * cdrg_dim1] = cdrsd[n - 1];
/* L3169: */
	    }

	    i__1 = *ntprmx;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *narxmx;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    ags[i__ + (j + *ngt * ags_dim2) * ags_dim1] = ard[i__ + j 
			    * 5 - 6];
/* L4125: */
		}
/* L4130: */
	    }

L3170:
	    ;
	}

/* - - - - - end of data loop - - - - - - - - - - - - - - - - - - - - - - */

L3325:
	if (ilim == 1) {
	    *ist = is - 1;
	    *irst = *ist - *nsb;
	} else if (ilim == 2) {
	    *imt = is - 1;
	} else {
	    *igt = is - 1;
	}

/* L3175: */
    }

/* ----------- end of main loop ------------------------------------------ */

    *nrst = *nst - *nsb;

    i__1 = *nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	is = ww_1.nspec[ns - 1];
	if (is <= 0) {
	    ++nerr;
	    io___565.ciunit = *noutpt;
	    s_wsfe(&io___565);
	    do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    io___566.ciunit = *nttyo;
	    s_wsfe(&io___566);
	    do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	    e_wsfe();
	}
/* L243: */
    }

/*     complete setting of the jflag array */

/*        set jflag for o2(aq) and h2(aq) to 27, unless the current */
/*        jflag = 30 (normal default for auxiliary basis species). */

    jflag[1] = 0;
    if (jflag[*nsb] < 19 || jflag[*nsb] > 21) {
	jflag[*nsb] = 0;
    }
    kount = 0;

    i__1 = *nsq;
    for (ns = *nsb1; ns <= i__1; ++ns) {
	s_copy(ustr1, uspec + ns * uspec_len, (ftnlen)8, (ftnlen)8);
	if (s_cmp(ustr1, uo2aq, (ftnlen)8, (ftnlen)8) == 0 || s_cmp(ustr1, 
		uh2aq, (ftnlen)8, (ftnlen)8) == 0) {
	    ++kount;
	    if (jflag[ns] == 30) {
		jflag[ns] = 27;
	    }
	    if (kount >= 2) {
		goto L3179;
	    }
	}
/* L3178: */
    }
L3179:

/*        set jflag to -1 for auxiliary basis species that */
/*        can not appear in the model */

    i__1 = *nsq;
    for (nsc = *nsb1; nsc <= i__1; ++nsc) {
	if (jflag[nsc] >= 27) {
	    nrs = nsc - *nsb;
	    i__2 = *nsq;
	    for (ns = 1; ns <= i__2; ++ns) {
		if (cdrs[ns + nrs * cdrs_dim1] != 0.f) {
		    if (jflag[ns] < 0) {
			jflag[nsc] = -1;
			goto L205;
		    }
		}
/* L203: */
	    }
	}
L205:
	;
    }
/*                             *---------------------------------------- */
/*                             * read solid solution data */
/*                             *---------------------------------------- */
    *nxt = 0;
    io___570.ciunit = *nad1;
    s_rsue(&io___570);
    do_uio(&c__1, ustr, (ftnlen)8);
    do_uio(&c__1, ustr2, (ftnlen)8);
    do_uio(&c__1, ustr3, (ftnlen)8);
    e_rsue();

    for (nx = 1; nx <= 10000; ++nx) {
	io___572.ciunit = *nad1;
	s_rsue(&io___572);
	do_uio(&c__1, uspecd, (ftnlen)24);
	do_uio(&c__1, (char *)&ndum, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&jdum, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&ndum4, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&ndum5, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&ndum6, (ftnlen)sizeof(integer));
	e_rsue();
	if (s_cmp(uspecd, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L4005;
	}
	if (ndum <= 0) {
	    goto L3215;
	}
	io___578.ciunit = *nad1;
	s_rsue(&io___578);
	i__1 = ndum;
	for (n = 1; n <= i__1; ++n) {
	    do_uio(&c__1, (char *)&xbarlm[n + nx * xbarlm_dim1], (ftnlen)
		    sizeof(doublereal));
	    do_uio(&c__1, udrxd + n * udrxd_len, udrxd_len);
	}
	e_rsue();
	ndum2 = 0;

	i__1 = ndum;
	for (n = 1; n <= i__1; ++n) {

	    i__2 = *nmt;
	    for (nm = 1; nm <= i__2; ++nm) {
		if (s_cmp(udrxd + n * udrxd_len, umin + nm * umin_len, (
			ftnlen)18, (ftnlen)18) != 0) {
		    goto L3195;
		}
		goto L3205;

L3195:
		;
	    }
	    nend[n + nx * nend_dim1] = 0;

/*     collect the names of endmembers not present */

	    s_copy(ussnp + (n + nx * ussnp_dim1) * ussnp_len, udrxd + n * 
		    udrxd_len, ussnp_len, udrxd_len);
	    goto L3210;

L3205:
	    nend[n + nx * nend_dim1] = nm;
	    ++ndum2;
L3210:
	    ;
	}

	++(*nxt);
	if (*nxt > *nxtmax) {
	    io___580.ciunit = *noutpt;
	    s_wsfe(&io___580);
	    do_fio(&c__1, (char *)&(*nxtmax), (ftnlen)sizeof(integer));
	    e_wsfe();
	    io___581.ciunit = *nttyo;
	    s_wsfe(&io___581);
	    do_fio(&c__1, (char *)&(*nxtmax), (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}

	if (*iopr1 >= 1) {
	    io___582.ciunit = *noutpt;
	    s_wsfe(&io___582);
	    do_fio(&c__1, uspecd, (ftnlen)24);
	    e_wsfe();
	}
	s_copy(usolx + nx * usolx_len, uspecd, usolx_len, (ftnlen)24);
	ncomp[nx] = ndum;
	jsol[nx] = jdum;
	io___583.ciunit = *nad1;
	s_rsue(&io___583);
	i__1 = *iapxmx;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&apx[i__ + nx * apx_dim1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
L3215:
	;
    }

L4005:

/*     check to see that all expanded basis aqueous species on the */
/*     input file were matched with those on the data file.  set up the */
/*     array ibasis. */

    i__1 = *nst;
    for (ns = 1; ns <= i__1; ++ns) {
	ww_1.ibasis[ns - 1] = ns;
/* L233: */
    }

    i__1 = *nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	is = ww_1.nspec[ns - 1];
	if (is <= 0) {
	    goto L245;
	}
	if (s_cmp(wwc_1.ubasis + (ns - 1) * 24, ublank, (ftnlen)8, (ftnlen)8) 
		== 0) {
	    goto L245;
	}
	if (s_cmp(wwc_1.ubasis + (ns - 1) * 24, wwc_1.uspecb + (ns - 1) * 24, 
		(ftnlen)24, (ftnlen)24) == 0) {
	    goto L245;
	}

	i__2 = *nst;
	for (nsc = 1; nsc <= i__2; ++nsc) {

	    if (s_cmp(wwc_1.ubasis + (ns - 1) * 24, uspec + nsc * uspec_len, (
		    ftnlen)18, (ftnlen)18) != 0) {
		goto L253;
	    }

	    isc = ww_1.ibasis[nsc - 1];
	    if (isc == nsc) {
		goto L251;
	    }
	    if (isc == is) {
		goto L245;
	    }
	    ++nerr;
	    io___585.ciunit = *noutpt;
	    s_wsfe(&io___585);
	    do_fio(&c__1, uspec + nsc * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + is * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + isc * uspec_len, uspec_len);
	    e_wsfe();
	    io___586.ciunit = *nttyo;
	    s_wsfe(&io___586);
	    do_fio(&c__1, uspec + nsc * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + is * uspec_len, uspec_len);
	    do_fio(&c__1, uspec + isc * uspec_len, uspec_len);
	    e_wsfe();
L251:
	    ww_1.ibasis[is - 1] = nsc;
	    ww_1.ibasis[nsc - 1] = is;
	    goto L245;

L253:
	    ;
	}
	++nerr;
	io___587.ciunit = *noutpt;
	s_wsfe(&io___587);
	do_fio(&c__1, wwc_1.ubasis + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___588.ciunit = *nttyo;
	s_wsfe(&io___588);
	do_fio(&c__1, wwc_1.ubasis + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
L245:
	;
    }

    i__1 = *nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	jflagi = ww_1.jflagb[ns - 1];
	if (jflagi != 19) {
	    goto L270;
	}

	i__2 = *nmt;
	for (nm = 1; nm <= i__2; ++nm) {

	    if (s_cmp(wwc_1.uphas1 + (ns - 1) * 24, umin + nm * umin_len, (
		    ftnlen)18, (ftnlen)18) != 0) {
		goto L250;
	    }

	    is = ww_1.nspec[ns - 1];
	    ww_1.nsp[is - 1] = nm;
	    goto L300;

L250:
	    ;
	}
	++nerr;
	io___590.ciunit = *noutpt;
	s_wsfe(&io___590);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___591.ciunit = *nttyo;
	s_wsfe(&io___591);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	goto L300;

L270:
	if (jflagi != 20) {
	    goto L280;
	}

	i__2 = *nxt;
	for (nx = 1; nx <= i__2; ++nx) {

	    if (s_cmp(wwc_1.uphas1 + (ns - 1) * 24, usolx + nx * usolx_len, (
		    ftnlen)18, (ftnlen)18) != 0) {
		goto L277;
	    }

	    ikt = ncomp[nx];

	    i__3 = ikt;
	    for (ik = 1; ik <= i__3; ++ik) {
		nm = nend[ik + nx * nend_dim1];
		if (s_cmp(umin + nm * umin_len, wwc_1.uphas2 + (ns - 1) * 24, 
			(ftnlen)18, (ftnlen)18) != 0) {
		    goto L276;
		}
		is = ww_1.nspec[ns - 1];
		ww_1.nsp[is - 1] = nx * 100 + 50000 + ik;
		goto L300;

L276:
		;
	    }
	    ++nerr;
	    io___594.ciunit = *noutpt;
	    s_wsfe(&io___594);
	    do_fio(&c__1, wwc_1.uphas2 + (ns - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    io___595.ciunit = *nttyo;
	    s_wsfe(&io___595);
	    do_fio(&c__1, wwc_1.uphas2 + (ns - 1) * 24, (ftnlen)24);
	    e_wsfe();
	    goto L300;

L277:
	    ;
	}
	++nerr;
	io___596.ciunit = *noutpt;
	s_wsfe(&io___596);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___597.ciunit = *nttyo;
	s_wsfe(&io___597);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	goto L300;

L280:
	if (jflagi != 21) {
	    goto L300;
	}

	i__2 = *ngt;
	for (ng = 1; ng <= i__2; ++ng) {

	    if (s_cmp(wwc_1.uphas1 + (ns - 1) * 24, ugas + ng * ugas_len, (
		    ftnlen)24, ugas_len) != 0) {
		goto L287;
	    }

	    is = ww_1.nspec[ns - 1];
	    ww_1.nsp[is - 1] = ng;
	    goto L300;

L287:
	    ;
	}
	++nerr;
	io___599.ciunit = *noutpt;
	s_wsfe(&io___599);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	io___600.ciunit = *nttyo;
	s_wsfe(&io___600);
	do_fio(&c__1, wwc_1.uphas1 + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
L300:
	;
    }

    if (*iodb1 <= 1) {
	goto L842;
    }
    io___601.ciunit = *noutpt;
    s_wsfe(&io___601);
    e_wsfe();

    i__1 = *nsq;
    for (ns = 1; ns <= i__1; ++ns) {
	io___602.ciunit = *noutpt;
	s_wsfe(&io___602);
	do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	do_fio(&c__1, uspec + ns * uspec_len, uspec_len);
	do_fio(&c__1, (char *)&ww_1.csp[ns - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&jflag[ns], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ww_1.nsp[ns - 1], (ftnlen)sizeof(integer));
	e_wsfe();
/* L840: */
    }

L842:
    if (*iodb1 <= 1) {
	goto L850;
    }
    io___603.ciunit = *noutpt;
    s_wsfe(&io___603);
    e_wsfe();

    i__1 = *nsqb;
    for (ns = 1; ns <= i__1; ++ns) {
	is = ww_1.nspec[ns - 1];
	io___604.ciunit = *noutpt;
	s_wsfe(&io___604);
	do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
	do_fio(&c__1, wwc_1.uspecb + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&is, (ftnlen)sizeof(integer));
	do_fio(&c__1, uspec + is * uspec_len, uspec_len);
	e_wsfe();
/* L847: */
    }

L850:

/*     unpack input solid solution compositions, if any */

    if (vw_1.nxtb <= 0) {
	goto L350;
    }

    i__1 = vw_1.nxtb;
    for (nxb = 1; nxb <= i__1; ++nxb) {
	vw_1.nxspec[nxb - 1] = 0;
	s_copy(uspecj, vwc_1.usolb + (nxb - 1) * 24, (ftnlen)24, (ftnlen)24);

	i__2 = *nxt;
	for (nx = 1; nx <= i__2; ++nx) {
	    if (s_cmp(uspecj, usolx + nx * usolx_len, (ftnlen)18, (ftnlen)18) 
		    == 0) {
		goto L333;
	    }
/* L330: */
	}

	++nerr;
	io___607.ciunit = *noutpt;
	s_wsfe(&io___607);
	do_fio(&c__1, ustr1, (ftnlen)8);
	do_fio(&c__1, ustr2, (ftnlen)8);
	e_wsfe();
	io___608.ciunit = *nttyo;
	s_wsfe(&io___608);
	do_fio(&c__1, ustr1, (ftnlen)8);
	do_fio(&c__1, ustr2, (ftnlen)8);
	e_wsfe();
	goto L350;

L333:
	vw_1.nxspec[nxb - 1] = nx;
	ikt = ncomp[nx];
	iktb = vw_1.ncompb[nxb - 1];
	if (iktb <= 0) {
	    goto L350;
	}

	i__2 = iktb;
	for (ikb = 1; ikb <= i__2; ++ikb) {
	    s_copy(uspecj, vwc_1.umemb + (ikb + nxb * 20 - 21) * 24, (ftnlen)
		    24, (ftnlen)24);

	    i__3 = ikt;
	    for (ik = 1; ik <= i__3; ++ik) {
		nm = nend[ik + nx * nend_dim1];
		if (s_cmp(uspecj, umin + nm * umin_len, (ftnlen)18, (ftnlen)
			18) != 0) {
		    goto L335;
		}
		goto L337;

L335:
		;
	    }

	    ++nerr;
	    io___611.ciunit = *noutpt;
	    s_wsfe(&io___611);
	    do_fio(&c__1, uspecj, (ftnlen)24);
	    e_wsfe();
	    io___612.ciunit = *nttyo;
	    s_wsfe(&io___612);
	    do_fio(&c__1, uspecj, (ftnlen)24);
	    e_wsfe();
	    goto L340;

L337:
	    xdum = vw_1.xbarb[ikb + nxb * 20 - 21];
	    xbar[ik + nx * xbar_dim1] = xdum;
	    xbarlg[ik + nx * xbarlg_dim1] = tlg_(&xdum);
L340:
	    ;
	}
    }

L350:

/*     stop if name match errors have been encountered */

    if (nerr > 0) {
	io___614.ciunit = *noutpt;
	s_wsfe(&io___614);
	do_fio(&c__1, (char *)&nerr, (ftnlen)sizeof(integer));
	e_wsfe();
	io___615.ciunit = *nttyo;
	s_wsfe(&io___615);
	do_fio(&c__1, (char *)&nerr, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     alter any log k values as directed by the input file */

    alters_(&nxmod[1], &jxmod[1], &kxmod[1], &xlkmod[1], uxmod + uxmod_len, &
	    ars[ars_offset], &amn[amn_offset], &ags[ags_offset], &apress[
	    apress_offset], &cdrs[cdrs_offset], &cdrm[cdrm_offset], &cdrg[
	    cdrg_offset], tempc, afcnst, uspec + uspec_len, umin + umin_len, 
	    ugas + ugas_len, usolx + usolx_len, nsb, nsq, nsq1, nst, nmt, ngt,
	     nxt, ntpr, nsqmx1, narxmx, ntprmx, noutpt, nttyo, uxmod_len, 
	    uspec_len, umin_len, ugas_len, usolx_len);

/*     set stochiometric equivalences of aqueous species for h2o */
/*     (o--) and h+ (h+). */

    cstor[*nsb + cstor_dim1] = 2.f;
    cstor[*nsb + (cstor_dim1 << 1)] = 0.f;

    nh = 0;
    i__2 = *nct;
    for (nc = 1; nc <= i__2; ++nc) {
	if (s_cmp(uelem + nc * uelem_len, uh, (ftnlen)8, (ftnlen)8) == 0) {
	    nh = nc;
	    goto L402;
	}
/* L401: */
    }
L402:

    for (ic = 1; ic <= 2; ++ic) {
	nc = 1;
	if (ic >= 2) {
	    nc = nh;
	}

	i__2 = *nct;
	for (ns = 1; ns <= i__2; ++ns) {
	    cstor[ns + ic * cstor_dim1] = cess[nc + ns * cess_dim1];
/* L860: */
	}

	i__2 = *nst;
	for (nsc = *nsb1; nsc <= i__2; ++nsc) {
	    dum1 = 0.f;
	    if (nsc > *nsq) {
		goto L870;
	    }
	    jfl = jflag[nsc];
	    if (jfl == 30) {
		goto L870;
	    }
	    if (jfl == 27) {
		goto L870;
	    }
	    s_copy(uspecj, uspec + nsc * uspec_len, (ftnlen)24, uspec_len);
	    if (s_cmp(uspecj, uredox, (ftnlen)18, (ftnlen)18) != 0) {
		goto L872;
	    }
	    goto L870;

/*        the names of any auxiliary basis species with oxygen or */
/*        hydrogen in valence states other than -2 or +1, respectively, */
/*        must be identified below.  iodb6=1 can be specified on the */
/*        input file to check that correct stoichiometric numbers are */
/*        calculated. */

L872:
	    if (s_cmp(ustr1, uo2aq, (ftnlen)8, (ftnlen)8) == 0) {
		goto L880;
	    }
	    if (s_cmp(ustr1, uh2aq, (ftnlen)8, (ftnlen)8) == 0) {
		goto L880;
	    }
L870:
	    nrs = nsc - *nsb;
	    nlim = nsc - 1;
	    nlim = min(nlim,*nsq);

	    i__1 = nlim;
	    for (ns = 1; ns <= i__1; ++ns) {
		dum2 = cdrs[ns + nrs * cdrs_dim1];
		dum3 = cstor[ns + ic * cstor_dim1];
		dum1 += dum2 * dum3;
/* L875: */
	    }

	    dum1 = -dum1 / cdrs[*nsq1 + nrs * cdrs_dim1];
L880:
	    cstor[nsc + ic * cstor_dim1] = dum1;
/* L885: */
	}

/* L890: */
    }
    cstor[*nsb + cstor_dim1] = 0.f;

    io___623.ciunit = *noutpt;
    s_wsfe(&io___623);
    e_wsfe();
    io___624.ciunit = *nttyo;
    s_wsfe(&io___624);
    e_wsfe();

/*      test for mods to azeros and hydration numbers */

    if (*iopt8 == 1 && eqlgpa_1.qhydth) {
	modah_(nahv, nst, &azero[1], uspec + uspec_len, &hydn[1], uspec_len);
    }

    return 0;
} /* indatx_ */

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
    static cilist io___634 = { 0, 0, 0, fmt_1000, 0 };



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
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlpp.h */
/* -------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */

/*     initialize array aa to zeroes */

/* eqlgp.h */


/* -------------------------------------------------------------------- */
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
	io___634.ciunit = un_1.noutpt;
	s_wsfe(&io___634);
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
/* eqlgp.h */


/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */

/* ---------------------------------------------------------------------- */

/* eqlpp.h */
/* -------------------------------------------------------------------- */
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
    static cilist io___650 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___651 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___653 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___654 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___660 = { 0, 0, 0, fmt_333, 0 };
    static cilist io___661 = { 0, 0, 0, fmt_333, 0 };
    static cilist io___662 = { 0, 0, 0, fmt_337, 0 };
    static cilist io___663 = { 0, 0, 0, fmt_337, 0 };
    static cilist io___664 = { 0, 0, 0, fmt_355, 0 };
    static cilist io___665 = { 0, 0, 0, fmt_355, 0 };



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

/* eqleps.h */

/*       eps = the real*8 machine epsilon */
/*       eps10 = 10*eps */
/*       eps100 = 100*eps */
/*       smpos = smallest positive real*8 number */
/*       smp10 = 10*smpos */
/*       smp100 = 100*smpos */
/*       irang = int ( -log (smpos ) ) */

/* -------------------------------------------------------------------- */

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
	io___650.ciunit = un_1.noutpt;
	s_wsfe(&io___650);
	e_wsfe();
	io___651.ciunit = un_1.nttyo;
	s_wsfe(&io___651);
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
	    io___653.ciunit = un_1.noutpt;
	    s_wsfe(&io___653);
	    e_wsfe();
	    io___654.ciunit = un_1.nttyo;
	    s_wsfe(&io___654);
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
		io___660.ciunit = un_1.noutpt;
		s_wsfe(&io___660);
		e_wsfe();
		io___661.ciunit = un_1.nttyo;
		s_wsfe(&io___661);
		e_wsfe();
		goto L999;
	    }
	}

	if (iopt1 > 1) {
	    io___662.ciunit = un_1.noutpt;
	    s_wsfe(&io___662);
	    e_wsfe();
	    io___663.ciunit = un_1.nttyo;
	    s_wsfe(&io___663);
	    e_wsfe();
	    goto L999;
	}
    }

L350:

    io___664.ciunit = un_1.noutpt;
    s_wsfe(&io___664);
    e_wsfe();
    io___665.ciunit = un_1.nttyo;
    s_wsfe(&io___665);
    e_wsfe();

L999:
    return 0;
} /* ndiagx_ */

/* readx    last revised 12/22/87 by tjw */
/* Subroutine */ int readx_(integer *infile__, logical *qend)
{
    /* Initialized data */

    static char ublank[24] = "                        ";
    static char uendit[8] = "endit.  ";
    static char uo2g[8] = "O2(G)   ";

    /* Format strings */
    static char fmt_37[] = "(/\002 --- reading the input file ---\002)";
    static char fmt_70[] = "(a80)";
    static char fmt_30[] = "(/\002 --- no further input found ---\002)";
    static char fmt_71[] = "(1x,a80)";
    static char fmt_32[] = "(\002 * error- input file has no title (readx"
	    ")\002)";
    static char fmt_80[] = "(3(12x,e12.5))";
    static char fmt_500[] = "(7x,\002tempc= \002,e12.5)";
    static char fmt_505[] = "(9x,\002rho= \002,e12.5,4x,\002tdspkg= \002,e12"
	    ".5,5x,\002tdspl= \002,e12.5)";
    static char fmt_705[] = "(12x,e12.5,12x,a24)";
    static char fmt_510[] = "(9x,\002fep= \002,e12.5,4x,\002uredox= \002,a24)"
	    ;
    static char fmt_515[] = "(7x,\002tolbt= \002,e12.5,5x,\002toldl= \002,e1"
	    "2.5,4x,\002tolsat= \002,e12.5)";
    static char fmt_76[] = "(12x,i2)";
    static char fmt_516[] = "(5x,\002itermx= \002,i2)";
    static char fmt_525[] = "(17x,\0021    2    3    4    5    6    7    8  "
	    "  9   10\002)";
    static char fmt_300[] = "(12x,10i5)";
    static char fmt_305[] = "(3x,\002iopt1-10= \002,10i5)";
    static char fmt_307[] = "(3x,\002iopg1-10= \002,10i5)";
    static char fmt_310[] = "(3x,\002iopr1-10= \002,10i5)";
    static char fmt_312[] = "(2x,\002iopr11-20= \002,10i5)";
    static char fmt_320[] = "(3x,\002iodb1-10= \002,10i5)";
    static char fmt_710[] = "(12x,a24)";
    static char fmt_530[] = "(6x,\002uebal= \002,a24)";
    static char fmt_531[] = "(5x,\002uacion= \002,a24)";
    static char fmt_325[] = "(6x,\002nxmod= \002,i2)";
    static char fmt_1638[] = "(1x,\002----- this exceeds the maximum of \002"
	    ",i2,\002 -----\002)";
    static char fmt_73[] = "(12x,a24,/12x,i2,22x,i2,22x,e12.5)";
    static char fmt_540[] = "(4x,\002species= \002,a24,/7x,\002type= \002,i2"
	    ",14x,\002option= \002,i2,14x,\002xlkmod= \002,e12.5)";
    static char fmt_545[] = "(\002 * nerr .gt. zero\002)";
    static char fmt_97[] = "(a8,18x,a24)";
    static char fmt_98[] = "(1x,\002data file master species= \002,a24)";
    static char fmt_99[] = "(24x,a24)";
    static char fmt_101[] = "(4x,\002switch with species= \002,a24)";
    static char fmt_102[] = "(10x,i2,8x,e17.9)";
    static char fmt_103[] = "(4x,\002jflag= \002,i2,3x,\002csp= \002,e17.9)";
    static char fmt_729[] = "(1x,\002----- o2(g) input line will be ignored "
	    "because\002,\002 iopt1.ne.-3 -----\002)";
    static char fmt_104[] = "(11x,a24,11x,a24)";
    static char fmt_107[] = "(12x,\002uphas1= \002,a24,3x,\002uphas2= \002,a"
	    "24)";
    static char fmt_735[] = "(/1x,\002----- the number of basis species read"
	    " in exceeds\002,\002 the maximum nsqmax = \002,i3,\002 -----\002)"
	    ;
    static char fmt_737[] = "(\002 * nsq .gt. nsqmax\002)";
    static char fmt_565[] = "(1x,\002solid solutions\002)";
    static char fmt_370[] = "(3x,a24)";
    static char fmt_371[] = "(4x,a24)";
    static char fmt_570[] = "(1x,\002component     mole fraction\002)";
    static char fmt_375[] = "(6x,a24,3x,f10.4)";
    static char fmt_376[] = "(6x,a24,3x,f10.4)";
    static char fmt_2047[] = "(/\002 --- the input file has been successful"
	    "y\002,\002 read ---\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), s_rsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_rsfe(void), s_cmp(char *, char *, ftnlen, 
	    ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    static integer n, ns, ikb;
    static doublereal fep;
    static integer nxb;
    static char udu[8];
    static doublereal sum, cdum;
    static integer nerr, nlim;
    static char udum[8];
    extern doublereal texp_(doublereal *);
    static integer jdum, ilim, ndum;
    static doublereal xdum;
    static char udum1[24], udum2[24];

    /* Fortran I/O blocks */
    static cilist io___669 = { 0, 0, 0, fmt_37, 0 };
    static cilist io___670 = { 0, 0, 0, fmt_37, 0 };
    static cilist io___671 = { 0, 0, 1, fmt_70, 0 };
    static cilist io___672 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___673 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___674 = { 0, 0, 0, fmt_71, 0 };
    static cilist io___675 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___676 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___678 = { 0, 0, 0, fmt_70, 0 };
    static cilist io___679 = { 0, 0, 0, fmt_71, 0 };
    static cilist io___680 = { 0, 0, 0, fmt_80, 0 };
    static cilist io___681 = { 0, 0, 0, fmt_500, 0 };
    static cilist io___682 = { 0, 0, 0, fmt_80, 0 };
    static cilist io___683 = { 0, 0, 0, fmt_505, 0 };
    static cilist io___684 = { 0, 0, 0, fmt_705, 0 };
    static cilist io___686 = { 0, 0, 0, fmt_510, 0 };
    static cilist io___687 = { 0, 0, 0, fmt_80, 0 };
    static cilist io___688 = { 0, 0, 0, fmt_515, 0 };
    static cilist io___689 = { 0, 0, 0, fmt_76, 0 };
    static cilist io___690 = { 0, 0, 0, fmt_516, 0 };
    static cilist io___691 = { 0, 0, 0, fmt_525, 0 };
    static cilist io___692 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___693 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___694 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___695 = { 0, 0, 0, fmt_307, 0 };
    static cilist io___696 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___697 = { 0, 0, 0, fmt_310, 0 };
    static cilist io___698 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___699 = { 0, 0, 0, fmt_312, 0 };
    static cilist io___700 = { 0, 0, 0, fmt_300, 0 };
    static cilist io___701 = { 0, 0, 0, fmt_320, 0 };
    static cilist io___702 = { 0, 0, 0, fmt_710, 0 };
    static cilist io___703 = { 0, 0, 0, fmt_530, 0 };
    static cilist io___704 = { 0, 0, 0, fmt_710, 0 };
    static cilist io___705 = { 0, 0, 0, fmt_531, 0 };
    static cilist io___706 = { 0, 0, 0, fmt_76, 0 };
    static cilist io___707 = { 0, 0, 0, fmt_325, 0 };
    static cilist io___709 = { 0, 0, 0, fmt_1638, 0 };
    static cilist io___710 = { 0, 0, 0, fmt_73, 0 };
    static cilist io___711 = { 0, 0, 0, fmt_540, 0 };
    static cilist io___712 = { 0, 0, 0, fmt_545, 0 };
    static cilist io___715 = { 0, 0, 0, fmt_97, 0 };
    static cilist io___718 = { 0, 0, 0, fmt_97, 0 };
    static cilist io___719 = { 0, 0, 0, fmt_98, 0 };
    static cilist io___720 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___722 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___723 = { 0, 0, 0, fmt_102, 0 };
    static cilist io___726 = { 0, 0, 0, fmt_103, 0 };
    static cilist io___727 = { 0, 0, 0, fmt_729, 0 };
    static cilist io___728 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___729 = { 0, 0, 0, fmt_107, 0 };
    static cilist io___731 = { 0, 0, 0, fmt_735, 0 };
    static cilist io___732 = { 0, 0, 0, fmt_737, 0 };
    static cilist io___733 = { 0, 0, 0, fmt_565, 0 };
    static cilist io___736 = { 0, 0, 0, fmt_370, 0 };
    static cilist io___737 = { 0, 0, 0, fmt_371, 0 };
    static cilist io___738 = { 0, 0, 0, fmt_570, 0 };
    static cilist io___741 = { 0, 0, 0, fmt_375, 0 };
    static cilist io___743 = { 0, 0, 0, fmt_376, 0 };
    static cilist io___744 = { 0, 0, 0, fmt_376, 0 };
    static cilist io___746 = { 0, 0, 0, fmt_2047, 0 };
    static cilist io___747 = { 0, 0, 0, fmt_2047, 0 };



/*     this subprogram reads the input data which define a distribution- */
/*     of-species problem. */


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
/* ti.h */

/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* uu.h */


/* -------------------------------------------------------------------- */
/* vv.h */
/* -------------------------------------------------------------------- */
/* vw.h */

/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* eqlgp.h */


/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlpp.h */
/* -------------------------------------------------------------------- */

/* eqltxp.h */
/* -------------------------------------------------------------------- */


/* ---------------------------------------------------------------------- */

/*     qend is a flag which is true if the end of the input file has */
/*     been reached. */
	
    *qend = FALSE_;

/*     utitl consists of up to thirty lines of text.  if there are less */
/*     than thirty lines, utitl is terminated by a line beginning with */
/*     'endit.' */

    io___669.ciunit = un_1.noutpt;
    s_wsfe(&io___669);
    e_wsfe();
    io___670.ciunit = un_1.nttyo;
    s_wsfe(&io___670);
    e_wsfe();

    ti_1.ntitl = 1;
    io___671.ciunit = *infile__;
    i__1 = s_rsfe(&io___671);
    if (i__1 != 0) {
	goto L25;
    }
    i__1 = do_fio(&c__1, tic_1.utitl + (ti_1.ntitl - 1) * 80, (ftnlen)80);
    if (i__1 != 0) {
	goto L25;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L25;
    }
    goto L31;

L25:
    io___672.ciunit = un_1.noutpt;
    s_wsfe(&io___672);
    e_wsfe();
    io___673.ciunit = un_1.nttyo;
    s_wsfe(&io___673);
    e_wsfe();
    *qend = TRUE_;
    goto L999;

L31:
    io___674.ciunit = un_1.noutpt;
    s_wsfe(&io___674);
    do_fio(&c__1, tic_1.utitl + (ti_1.ntitl - 1) * 80, (ftnlen)80);
    e_wsfe();
    if (s_cmp(tic_1.utitl + (ti_1.ntitl - 1) * 80, uendit, (ftnlen)8, (ftnlen)
	    8) != 0) {
	goto L33;
    }
    io___675.ciunit = un_1.noutpt;
    s_wsfe(&io___675);
    e_wsfe();
    io___676.ciunit = un_1.nttyo;
    s_wsfe(&io___676);
    e_wsfe();
    s_stop("", (ftnlen)0);

L33:
    i__1 = ti_1.ntitmx;
    for (n = 2; n <= i__1; ++n) {
	io___678.ciunit = *infile__;
	s_rsfe(&io___678);
	do_fio(&c__1, tic_1.utitl + (n - 1) * 80, (ftnlen)80);
	e_rsfe();
	io___679.ciunit = un_1.noutpt;
	s_wsfe(&io___679);
	do_fio(&c__1, tic_1.utitl + (n - 1) * 80, (ftnlen)80);
	e_wsfe();
	if (s_cmp(tic_1.utitl + (n - 1) * 80, uendit, (ftnlen)8, (ftnlen)8) ==
		 0) {
	    goto L35;
	}
	ti_1.ntitl = n;
/* L34: */
    }
L35:

/*     tempc=temperature, degrees centigrade */

    io___680.ciunit = *infile__;
    s_rsfe(&io___680);
    do_fio(&c__1, (char *)&hh_1.tempc, (ftnlen)sizeof(doublereal));
    e_rsfe();
    io___681.ciunit = un_1.noutpt;
    s_wsfe(&io___681);
    do_fio(&c__1, (char *)&hh_1.tempc, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     rho = density of solution in g/ml */
/*     tdspkg = total dissolved salts, mg/kg solution */
/*     tdspl = total dissolved salts, mg/l */
/*     (enter only one of tdspkg and tdspl) */

    io___682.ciunit = *infile__;
    s_rsfe(&io___682);
    do_fio(&c__1, (char *)&jj_1.rho, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.tdspkg, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.tdspl, (ftnlen)sizeof(doublereal));
    e_rsfe();
    io___683.ciunit = un_1.noutpt;
    s_wsfe(&io___683);
    do_fio(&c__1, (char *)&jj_1.rho, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.tdspkg, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.tdspl, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     default redox parameters (fo2lg/eh/pe) */

/*        fep = one of fo2lg, eh, or pe (iopt1 = 0, -1, or -2, */
/*          respectively) */
/*        fo2lg = log oxygen fugacity */
/*        eh = eh, oxidation-reduction parameter */
/*        pe = p e-, electron activity */
/*        uredox = name (all 24 letters) of an */
/*           auxiliary basis species that is part of a redox couple */
/*           that will be used to distribute other redox couples */
/*        note- heterogeneous equilibria can be used also by setting */
/*        iopt1=0, fep=0., and jflag(o2(g))= 19, 20, or 21. */

    io___684.ciunit = *infile__;
    s_rsfe(&io___684);
    do_fio(&c__1, (char *)&fep, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
    e_rsfe();
    io___686.ciunit = un_1.noutpt;
    s_wsfe(&io___686);
    do_fio(&c__1, (char *)&fep, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, jjc_1.uredox, (ftnlen)24);
    e_wsfe();

/*     tolbt = convergence tolerance on residual functions */
/*     tolxi = convergence tolerance on correction terms */
/*     tolsat = saturation tolerance for minerals, in kcal.  tolsat */
/*              controls the printing of flags in the mineral saturation */
/*              state listing.  it does not affect convergence. */

    io___687.ciunit = *infile__;
    s_rsfe(&io___687);
    do_fio(&c__1, (char *)&ps_1.tolbt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ps_1.toldl, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ps_1.tolsat, (ftnlen)sizeof(doublereal));
    e_rsfe();
    io___688.ciunit = un_1.noutpt;
    s_wsfe(&io___688);
    do_fio(&c__1, (char *)&ps_1.tolbt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ps_1.toldl, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ps_1.tolsat, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     itermx = maximum number of newton-raphson iterations */

    io___689.ciunit = *infile__;
    s_rsfe(&io___689);
    do_fio(&c__1, (char *)&ps_1.itermx, (ftnlen)sizeof(integer));
    e_rsfe();
    io___690.ciunit = un_1.noutpt;
    s_wsfe(&io___690);
    do_fio(&c__1, (char *)&ps_1.itermx, (ftnlen)sizeof(integer));
    e_wsfe();

/*     iopt1  = option switch for default redox coupling (this is */
/*             equivalent to assuming a pool of redox couples are in */
/*             equiilbrium with one another and specifying their mutual */
/*             redox state by one of the following means */

/*                 parameters required for any of the options below */
/*                 are read in on the 'fep' line above */

/*          =  0   fo2lg (log fo2(g)) specified */
/*          = -1   eh specified in volts */
/*          = -2   p e- specified */
/*          = -3   fo2lg/eh/pe is specified indirectly by a */
/*                 heterogeneous equilibrium specified below on the */
/*                 individual species constraint line for o2(g). */
/*                 jflag must be 19, 20, or 21, and uphas1 must */
/*                 contain the name of the associated mineral or gas */
/*                 species.  if the mineral is a solid solution, */
/*                 an end-member must be specified in uphas2. */
/*          =  1   fo2lg/eh/pe is specified indirectly by a redox */
/*                 couple such as o2(aq)/h2o, hs-/so4--, or fe++/fe++. */
/*                 this option must be supported by independent */
/*                 compositional constraints on each member of the */
/*                 couple (except h2o, as in o2(aq)/h2o).  one member */
/*                 must be in the strict basis after initial basis */
/*                 switching, if any; the other must be in the auxiliary */
/*                 basis.  the couple is specified by the first two */
/*                 parts (first twelve letters) of the name of the */
/*                 auxiliary basis variable.  these are read above into */
/*                 the variable uredox. */
/*     iopt2  = option switch, controls automatic basis switching */
/*          =  0   automatic basis switching is turned off */
/*          =  1   automatic basis switching is turned on */
/*     iopt3  = option switch for producing interfacing output */
/*          = -1   no pickup file for input to eq6 is generated */
/*          =  0   a pickup file is generated */
/*     iopt4  = option switch for solid solutions */
/*          =  0   ignores all solid solutions */
/*          =  1   processes hypothetical solid solutions */
/*          =  2   reads in solid solution compositions and processes */
/*                 both input and hypothetical solid solutions. */
/*     iopt5  = option switch, not currently used */
/*     iopt6  = option switch, controls convergence criteria */
/*          = -1   only the residual functions are tested */
/*          =  0   both residual functions and correction terms are */
/*                 tested for convergence of newton-raphson iteration */
/*     iopt7  = option switch, controls pickup file format */
/*          =  0   3245 version pickup file is written */
/*          =  1   post-3245 version pickup file is written */
/*     iopt8  = allows and alternate set of azero and hydration */
/*               numbers to be read from file ahv */
/*          = 1  reads ahv */
/*          = 0 does not read ahv */
/*     iopt9  = option switch, not currently used */
/*     iopt10 = option switch, not currently used */

    io___691.ciunit = un_1.noutpt;
    s_wsfe(&io___691);
    e_wsfe();
    io___692.ciunit = *infile__;
    s_rsfe(&io___692);
    do_fio(&c__1, (char *)&op_1.iopt1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt10, (ftnlen)sizeof(integer));
    e_rsfe();
    io___693.ciunit = un_1.noutpt;
    s_wsfe(&io___693);
    do_fio(&c__1, (char *)&op_1.iopt1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt10, (ftnlen)sizeof(integer));
    e_wsfe();
    cc_1.fo2lg = -999.f;
    if (op_1.iopt1 >= 1) {
	goto L703;
    }
    if (op_1.iopt1 <= -3) {
	goto L703;
    }
    if (op_1.iopt1 <= -1) {
	goto L701;
    }
    cc_1.fo2lg = fep;
    goto L703;
L701:
    if (op_1.iopt1 != -1) {
	goto L702;
    }
    jj_1.eh = fep;
    goto L703;
L702:
    jj_1.pe = fep;
L703:
    cc_1.fo2 = texp_(&cc_1.fo2lg);

/*     iopg1  = option switch, activity coefficients */

/*           =  -1   uses davies equation instead of b-dot equation */
/*                    (analogous to b-dot) (not implemented) */
/*           =   0   uses b-dot equation */
/*           =   1   pitzer equations, standard */
/*           =   2   not used */
/*           =   3   w-j hydration theory equations with e-lambda terms */
/*           =   4   w-j hydration theory equations w/o e-lambda terms */
/*           =   5   not implemented -- hkf equations -- part iv */

/*     iopg2  = option switch, activity coefficients */
/*           =  -1   use the 'internal' ph scale for a given activity */
/*                   coefficient model (specified by iopg1) */
/*           =   0   convert the activity coefficient model to make it */
/*                   consistent with the modified nbs ph scale. */
/*                   log gamma cl- is defined by the bates-guggenheim */
/*                   expression.  the nbs scale is ambiguous about */
/*                   the precise definition of ionic strength, other than */
/*                   that it is molal as opposed to molar  (e.g., what */
/*                   set of species is to be presumed in its calculation?). */
/*                   even the so-called 'stoichiometric' ionic strength is */
/*                   always unambiguously definable independent of the */
/*                   presumed set of solute species.  here the ionic */
/*                   strength is taken as the 'true' ionic strength that */
/*                   corresponds to the speciation model used in the present */
/*                   application of the code.  the user should be aware */
/*                   that even this model may vary according to the data */
/*                   file and activity coefficient option employed.  in */
/*                   dilute solutions (less dilute say, than seawater, in */
/*                   which the ionic strength is about 0.7 molal), this is */
/*                   not too much of a problem, numerically speaking.  in */
/*                   more concentrated solutions, however, it becomes */
/*                   obvious that it was a mistake for the nbs to have */
/*                   defined a standard convention in terms of a model */
/*                   dependent parameter.  hence the proposed use of the */
/*                   rational ph scale (see below).  in this code, no */
/*                   upper limit is placed on the value of the ionic */
/*                   strength.  the nbs convention has a formal upper limit */
/*                   of 0.10 molal.) */
/*           =   1   convert the activity coefficient model to make it */
/*                   consistent with the rational ph scale. */
/*                   (log gamma h+ = 0, so ph = log molality of h+.) */
/*                   note that this convention does not depend on any */
/*                   model dependent parameters. */
/*     iopg3  = option switch for iopg1 = 3 */
/*           = 0   use uelam=on */
/*           = 1   use uelam=onplus */
/*     iopg4  = option switch for iopg1 = 3 or 4 */
/*           = 0   compute f(dho)a */
/*           = 1   compute f(dhc)c */
/*     iopg5  = option switch for bdot model (iopg1 = 1) */
/*           = 0   use the polynomial for the activity coefficient of */
/*                 aqueous co2 to estimate the activity coefficients */
/*                 of non-polar neutral solute species */
/*           = 1   substitute a bdot term instead of the polynomial */
/*                 for the activity coefficient of aqueous co2 */
/*     iopg6  = option switch, activity coefficients */
/*           = 0   use pitzer j */
/*           = 1   use harvie j in aqueous species activity */
/*                 coefficient calculation */
/*     iopg7  = option switch, not currently used */
/*     iopg8  = option switch, not currently used */
/*     iopg9  = option switch, not currently used */
/*     iopg10 = option switch, not currently used */

    io___694.ciunit = *infile__;
    s_rsfe(&io___694);
    do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg10, (ftnlen)sizeof(integer));
    e_rsfe();
    io___695.ciunit = un_1.noutpt;
    s_wsfe(&io___695);
    do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op_1.iopt8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg10, (ftnlen)sizeof(integer));
    e_wsfe();

/*     iopr1  = print control option switch */
/*          =  0   does nothing */
/*          =  1   lists the loading of species into memory */
/*     iopr2  = print control option switch */
/*          =  0   does nothing */
/*          =  1   lists all reactions (this can be quite lengthy) */
/*          =  2   also prints the log k values */
/*          =  3   also prints the coefficients of the interpolating */
/*                 polynomials */
/*     iopr3  = print control option switch */
/*          =  0   the aqueous species properties are listed in */
/*                 decreasing order of concentration */
/*          =  1   the aqueous species properties are listed in the */
/*                 order that the species appear on the thermodynamic */
/*                 data file */
/*     iopr4  = print control option switch */
/*          =  0   all species are printed */
/*          = -1   only species with concentrations .ge. 1.e-20 */
/*                 are printed */
/*          = -2   only species with concentrations .ge. 1.e-12 */
/*                 are printed */
/*          = -3   the aqueous species distribution is not printed */
/*     iopr5  = print control option switch */
/*          = -1   turns off printout summarizing the major */
/*                 species contributing to aqueous mass balances */
/*          =  0   this information is printed */
/*          =  1   the printout includes all aqueous species */
/*                 contributing to each mass balance */
/*     iopr6  = print control option switch */
/*          =  0   does nothing */
/*          =  1   prints the mean ionic properties */
/*     iopr7  = print control option switch */
/*          = -1   turns off the affinity printout for minerals */
/*          =  0   minerals with affinities less than -10 kcal */
/*                 are not printed */
/*          =  1   all minerals in memory are printed */
/*     iopr8 = print control option switch */
/*          = -1   no print */
/*          =  0   prints a list of species, ion sizes, and hydration */
/*                 numbers */
/*     iopr9 =  print control option switch */
/*          = 0 print only warnings for pitzer coefficients */
/*          = 1 print species in model and number of pitzer coefficients */
/*          = 2 print species in model and names of pitzer coefficients */
/*     iopr10 = print control option switch */
/*          =  0   does nothing */
/*          =  1   prints the concbs array (stoichiometric */
/*                 concentrations of master species) */
/*     iopr11-20 = print control option switches, not used */

    io___696.ciunit = *infile__;
    s_rsfe(&io___696);
    do_fio(&c__1, (char *)&op1_1.iopr1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr10, (ftnlen)sizeof(integer));
    e_rsfe();
    io___697.ciunit = un_1.noutpt;
    s_wsfe(&io___697);
    do_fio(&c__1, (char *)&op1_1.iopr1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr10, (ftnlen)sizeof(integer));
    e_wsfe();

    io___698.ciunit = *infile__;
    s_rsfe(&io___698);
    do_fio(&c__1, (char *)&op1_1.iopr11, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr12, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr13, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr14, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr15, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr16, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr17, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr18, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr19, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr20, (ftnlen)sizeof(integer));
    e_rsfe();
    io___699.ciunit = un_1.noutpt;
    s_wsfe(&io___699);
    do_fio(&c__1, (char *)&op1_1.iopr11, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr12, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr13, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr14, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr15, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr16, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr17, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr18, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr19, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op1_1.iopr20, (ftnlen)sizeof(integer));
    e_wsfe();

/*     iodb1  = debugging print option switch */
/*          =  0   does nothing */
/*          =  1   prints some informational messages.  also */
/*                 prevents the stripped input file from being */
/*                 deleted at the end of a run. */
/*          =  2   same as = 1, but prints more informational messages */
/*     iodb2  = debugging print option switch */
/*          =  0   does nothing */
/*          =  1   generates prints of pre-newton-raphson optimizations, */
/*                 including automatic basis switching */
/*          =  2   generates prints giving more detailed information */
/*                 on pre-newton-raphson optimizations */
/*     iodb3  = debugging print option switch */
/*          =  0   does nothing */
/*          =  1   requests iteration variables to be killed */
/*     iodb4  = debugging print option switch */
/*          =  0   prints newton-raphson iteration summary */
/*          =  1   prints newton-raphson iteration in detail */
/*     iodb5  = debugging print option switch */
/*          =  0   does nothing */
/*          =  1   prints stoichiometric equivalences for oxygen and */
/*                 hydrogen mass balances only */
/*          =  2   prints stoichiometric equivalences for all mass */
/*                 balances */
/*     iodb6  = debugging print option switch */
/*          =  0   does nothing */
/*          =  1   prints details of stoichiometric equivalence */
/*                 calculations */
/*     iodb7  = debugging print option switch */
/*          =  0   does nothing */
/*          =  1   writes reactions among aqueous species on the file */
/*                 called rlist, both as they are written on the data */
/*                 file and also after they are re-written after */
/*                 basis switching operations have been done. */
/*     iodb8  = not used debug switch */
/*     iodb9  = not used switch */
/*     iodb10 = not used switch */

    io___700.ciunit = *infile__;
    s_rsfe(&io___700);
    do_fio(&c__1, (char *)&op2_1.iodb1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb10, (ftnlen)sizeof(integer));
    e_rsfe();
    io___701.ciunit = un_1.noutpt;
    s_wsfe(&io___701);
    do_fio(&c__1, (char *)&op2_1.iodb1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&op2_1.iodb10, (ftnlen)sizeof(integer));
    e_wsfe();
    if (op2_1.iodb1 >= 1) {
	eqltxp_1.qtxppr = TRUE_;
    }

/*     uebal = name (all 24 letters) of a charged basis species whose */
/*             concentration will be adjusted to achieve electrical */
/*             balance.  leave blank if no adjustment is desired.  enter */
/*             'pick1.' to have the program pick an ion. */

    io___702.ciunit = *infile__;
    s_rsfe(&io___702);
    do_fio(&c__1, eec_1.uebal, (ftnlen)24);
    e_rsfe();
    io___703.ciunit = un_1.noutpt;
    s_wsfe(&io___703);
    do_fio(&c__1, eec_1.uebal, (ftnlen)24);
    e_wsfe();

/*     uacion = name (all 24 letters) of a species (na+ or cl-) that */
/*             defines the equivalent stoichiometric ionic strength of */
/*             a sodium chloride solution (used to estimate the activity */
/*             of water).  enter 'pick1.' to have the program pick one. */

    io___704.ciunit = *infile__;
    s_rsfe(&io___704);
    do_fio(&c__1, eec_1.uacion, (ftnlen)24);
    e_rsfe();
    io___705.ciunit = un_1.noutpt;
    s_wsfe(&io___705);
    do_fio(&c__1, eec_1.uacion, (ftnlen)24);
    e_wsfe();

/*     read in the numbers of aqueous, mineral, gas, and solid solution */
/*     species that are to be suppressed or whose associated reactions */
/*     are to have their log k values altered from those input from the */
/*     file adat1.  note that solid solutions can only be suppressed. */
/*     suppression or alteration can not apply to aqueous species in */
/*     the strict basis at the time the changes are made effective, */
/*     because these species have no assoicated reactions.  at the */
/*     present time, the changes are effected in routine indatx, just */
/*     after the data on file adat1 have been read. */

/*        nxmod = the number of suppressed/altered species/reactions */

    io___706.ciunit = *infile__;
    s_rsfe(&io___706);
    do_fio(&c__1, (char *)&nx_1.nxmod, (ftnlen)sizeof(integer));
    e_rsfe();
    io___707.ciunit = un_1.noutpt;
    s_wsfe(&io___707);
    do_fio(&c__1, (char *)&nx_1.nxmod, (ftnlen)sizeof(integer));
    e_wsfe();

/*        uxmod = the name (all 24 letters) of the species */
/*        jxmod = type of species */
/*           0 aqueous species */
/*           1 mineral */
/*           2 gas */
/*           3 solid solution */
/*        kxmod = alteration code */
/*          -1  the species is suppressed */
/*           0  the log k is replaced by xlkmod */
/*           1  the log k is augmented by xlkmod */
/*           2  same as kxmod=1, but xlkmod is input in units of kcal */
/*                 per mole of the associated species */
/*        xlkmod = log k value alteration function defined above */

    nerr = 0;
    if (nx_1.nxmod > 0) {
	if (nx_1.nxmod > nx_1.nxmdmx) {
	    io___709.ciunit = un_1.noutpt;
	    s_wsfe(&io___709);
	    do_fio(&c__1, (char *)&nx_1.nxmdmx, (ftnlen)sizeof(integer));
	    e_wsfe();
	    ++nerr;
	}
	i__1 = nx_1.nxmod;
	for (n = 1; n <= i__1; ++n) {
	    io___710.ciunit = *infile__;
	    s_rsfe(&io___710);
	    do_fio(&c__1, nxc_1.uxmod + (n - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&nx_1.jxmod[n - 1], (ftnlen)sizeof(integer))
		    ;
	    do_fio(&c__1, (char *)&nx_1.kxmod[n - 1], (ftnlen)sizeof(integer))
		    ;
	    do_fio(&c__1, (char *)&nx_1.xlkmod[n - 1], (ftnlen)sizeof(
		    doublereal));
	    e_rsfe();
	    io___711.ciunit = un_1.noutpt;
	    s_wsfe(&io___711);
	    do_fio(&c__1, nxc_1.uxmod + (n - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&nx_1.jxmod[n - 1], (ftnlen)sizeof(integer))
		    ;
	    do_fio(&c__1, (char *)&nx_1.kxmod[n - 1], (ftnlen)sizeof(integer))
		    ;
	    do_fio(&c__1, (char *)&nx_1.xlkmod[n - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
/* L105: */
	}
    }
    if (nerr > 0) {
	io___712.ciunit = un_1.nttyo;
	s_wsfe(&io___712);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*     read data and constraints on aqueous species */

/*        uspecb = name of an aqueous species in the expanded basis set. */
/*        ubasis = name of an aqueous species to be switched with the */
/*           corresponding expanded basis species (if no switch is */
/*           to be specified, enter blanks or repeat the name of the */
/*           expanded basis species).  again, only the first two */
/*           parts of the name are used. */
/*        jflag = switch defining the meaning of the csp parameter. */
/*           jflag values on the input file are read into the */
/*           array jflagb. */
/*        csp = a floating point datum (concentration, activity, etc.) */
/*           whose meaning is specified by the jflag parameter. */
/*           csp values on the input file are read into the array cspb. */
/*        uphas1 = the name of a species which must be designated */
/*           to complete a specification for the jflag = 17, 19, */
/*           20 or 21 options.  for jflag = 19, the species specified */
/*           is a mineral taken to be in equilbrium with the aqueous */
/*           solution.  for jflag = 20, the species is a solid solution */
/*           taken to be in equilibrium with the aqueous solution, */
/*           and the name of a specific end-member must be specified */
/*           in uphas2. */
/*        uphas2 = the name of an end-member of a solid solution */
/*           specified in uphas1 for the jflag = 20 option. */

/*     if a species in the auxiliary basis is being switched into the */
/*     strict basis, the switch is indicated by specifying the name */
/*     of the former as the ubasis value for the latter.  the switch is */
/*     not specified twice, as by specifying the name of the */
/*     strict basis species as the ubasis value for the auxiliary */
/*     basis species.  in such an intra-basis switch, the */
/*     input properties (jflag, csp, uphas1, uphas2) follow the species */
/*     they are originally assigned to.  in the case of an extra-basis */
/*     switch, the input properties are reassigned to the species brought */
/*     into the basis.  if the csp property is a total concentration, */
/*     it is recalculated for stoichiometric consistency with the */
/*     specification for the original basis species. */

/*     quick summary of the jflag conventions-- */

/*        = -1   not present in the system as implied by jflag.le.15 */
/*                  and csp=0.  this value is assigned internally by the */
/*                  code and need not be entered on the input file. */
/*        =  0   total concentration, molal (csp) */
/*                  note- enter jflag=0 for water and o2(g).  the */
/*                  csp parameter for o2(g) is always log fugacity. */
/*                  a line for o2(g) is not entered here unless */
/*                  iopt1 = -3 */
/*        =  1   total concentration, molar (csp) */
/*        =  2   total concentration, mg/l (csp) */
/*        =  3   total concentration, mg/kg solution (csp) */
/*        =  4   free concentration, molal (csp) */
/*        =  5   free concentration, molar (csp) */
/*        =  6   free concentration, mg/l (csp) */
/*        =  7   free concentration, mg/kg (csp) */
/*        =  8   free concentration, cc stp/cc solution (csp) */
/*        = 10   titration alkalinity, eq/kg h20 (csp) */
/*                  (this is a slightly dangerous option) */

/*        = 11   titration alkalinity, eq/l (csp) */
/*                  (this is a slightly dangerous option) */

/*        = 12   carbonate alkalinity, eq/kg h20 (csp) */
/*        = 13   carbonate alkalinity, eq/l h20 (csp) */
/*        = 16   log activity (molal scale) (csp) */
/*        = 17   log mean activity of the neutral electrolyte */
/*                  composed of the ions specified by uspecb */
/*                  and uphas1 (not currently implemented) */

/*        = 19   mineral solubility equilibrium-- uphas1 = name of */
/*                  pure mineral.  do not use the same mineral twice. */
/*                  do not expect the program to find a solution if you */
/*                  program a real or apparent violation of the phase */
/*                  rule.  the csp parameter is not used.  (this is */
/*                  a slightly dangerous option) */

/*        = 20   solid solution solubility equilibrium-- uphas1 = */
/*                  name of the solid solution and uphas2 = */
/*                  the name of one of its components. */
/*                  see comments above on jflag=19. */

/*        = 21   gas solubility equilibrium-- uphas1 = name of the gas, */
/*                  csp is its log fugacity.  see comments above on */
/*                  jflag=19. */

/*        = 27   dependent variable-- the species must be in the */
/*                  auxiliary basis when the calculation commences; */
/*                  it and its 'complexes' are treated as 'complexes' */
/*                  of the corresponding species in the strict basis, */
/*                  but are not limited by the total concentration, if */
/*                  there is one, for that corresponding species.  this */
/*                  option is intended to be applied mainly to dissolved */
/*                  gases (e.g., to estimate ch4(aq) from hco3-).  it */
/*                  is a dangerous option if used otherwise.  the danger */
/*                  is that unconstrained masses may blow up, not because */
/*                  the code is at fault, but because the problem input */
/*                  is bad.  in this case the user should rethink what */
/*                  the input constraints should be. */

/*                  for example, suppose you have a sulfate analysis */
/*                  of a water and you expect that sulfide species */
/*                  may be significant and possibly in equilibrium with */
/*                  sulfate.  if you think the sulfate analysis */
/*                  measured both sulfate and sulfide, enter the */
/*                  analytical value as the total concentration of */
/*                  sulfate and specify jflag(hs-)=30.  if you think */
/*                  the analysis measured only sulfate proper, then */
/*                  enter jflag(hs-)=27 instead.  if the redox state of */
/*                  the water is very reducing you may get an infinite */
/*                  or near-infinite amount of calculated sulfide. */

/*                  no csp datum is required.  use the jflag=30 */
/*                  option if you are not sure how jflag=27 works. */

/*        = 30   eliminated variable-- the species is treated as above, */
/*                  but it and its 'complexes' are constrained by the */
/*                  total concentration entered for the corresponding */
/*                  strict basis species.  no csp datum is required. */

    nlim = tt_1.nsqmax + 1;
    i__1 = nlim;
    for (ns = 1; ns <= i__1; ++ns) {
	io___715.ciunit = *infile__;
	s_rsfe(&io___715);
	do_fio(&c__1, udum, (ftnlen)8);
	do_fio(&c__1, udum1, (ftnlen)24);
	e_rsfe();
	if (s_cmp(udum, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	    io___718.ciunit = un_1.noutpt;
	    s_wsfe(&io___718);
	    do_fio(&c__1, uendit, (ftnlen)8);
	    e_wsfe();
	    goto L730;
	}
	io___719.ciunit = un_1.noutpt;
	s_wsfe(&io___719);
	do_fio(&c__1, udum1, (ftnlen)24);
	e_wsfe();
	s_copy(wwc_1.uspecb + (ns - 1) * 24, udum1, (ftnlen)24, (ftnlen)24);

	io___720.ciunit = *infile__;
	s_rsfe(&io___720);
	do_fio(&c__1, udum2, (ftnlen)24);
	e_rsfe();
	io___722.ciunit = un_1.noutpt;
	s_wsfe(&io___722);
	do_fio(&c__1, udum2, (ftnlen)24);
	e_wsfe();
	s_copy(wwc_1.ubasis + (ns - 1) * 24, udum2, (ftnlen)24, (ftnlen)24);

	io___723.ciunit = *infile__;
	s_rsfe(&io___723);
	do_fio(&c__1, (char *)&jdum, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	e_rsfe();
	io___726.ciunit = un_1.noutpt;
	s_wsfe(&io___726);
	do_fio(&c__1, (char *)&jdum, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
	ww_1.jflagb[ns - 1] = jdum;
	ww_1.cspb[ns - 1] = cdum;
	s_copy(wwc_1.uphas1 + (ns - 1) * 24, ublank, (ftnlen)24, (ftnlen)24);
	s_copy(wwc_1.uphas2 + (ns - 1) * 24, ublank, (ftnlen)24, (ftnlen)24);

	s_copy(udum, udum1, (ftnlen)8, (ftnlen)8);
	if (s_cmp(udum, uo2g, (ftnlen)8, (ftnlen)8) == 0 && op_1.iopt1 != -3) 
		{
	    io___727.ciunit = un_1.noutpt;
	    s_wsfe(&io___727);
	    e_wsfe();
	    ww_1.jflagb[ns - 1] = 0;
	    ww_1.cspb[ns - 1] = 0.f;
	    goto L250;
	}

	if (jdum >= 17 && jdum <= 21) {
	    io___728.ciunit = *infile__;
	    s_rsfe(&io___728);
	    do_fio(&c__1, udum1, (ftnlen)24);
	    do_fio(&c__1, udum2, (ftnlen)24);
	    e_rsfe();
	    io___729.ciunit = un_1.noutpt;
	    s_wsfe(&io___729);
	    do_fio(&c__1, udum1, (ftnlen)24);
	    do_fio(&c__1, udu, (ftnlen)8);
	    e_wsfe();
	    s_copy(wwc_1.uphas1 + (ns - 1) * 24, udum1, (ftnlen)24, (ftnlen)
		    24);
	    s_copy(wwc_1.uphas2 + (ns - 1) * 24, udum2, (ftnlen)24, (ftnlen)
		    24);
	}

L250:
	;
    }

    io___731.ciunit = un_1.noutpt;
    s_wsfe(&io___731);
    do_fio(&c__1, (char *)&tt_1.nsqmax, (ftnlen)sizeof(integer));
    e_wsfe();
    io___732.ciunit = un_1.nttyo;
    s_wsfe(&io___732);
    e_wsfe();
    s_stop("", (ftnlen)0);
L730:
    tt_1.nsqb = ns - 1;

/*     xbar=mole fraction of end member in a solid solution */

    if (op_1.iopt4 <= 1) {
	goto L65;
    }
    io___733.ciunit = un_1.noutpt;
    s_wsfe(&io___733);
    e_wsfe();
    vw_1.nxtb = 0;
    nlim = tt_1.nxtmax + 1;
    ilim = tt_1.iktmax + 1;
    i__1 = nlim;
    for (nxb = 1; nxb <= i__1; ++nxb) {
	io___736.ciunit = *infile__;
	s_rsfe(&io___736);
	do_fio(&c__1, udum1, (ftnlen)24);
	e_rsfe();
	io___737.ciunit = un_1.noutpt;
	s_wsfe(&io___737);
	do_fio(&c__1, udum1, (ftnlen)24);
	e_wsfe();
	s_copy(udum, udum1, (ftnlen)8, (ftnlen)8);
	if (s_cmp(udum, uendit, (ftnlen)8, (ftnlen)8) == 0) {
	    goto L65;
	}
	++vw_1.nxtb;
	s_copy(vwc_1.usolb + (nxb - 1) * 24, udum1, (ftnlen)24, (ftnlen)24);
	io___738.ciunit = un_1.noutpt;
	s_wsfe(&io___738);
	e_wsfe();
	ndum = 0;

	i__2 = ilim;
	for (ikb = 1; ikb <= i__2; ++ikb) {
	    io___741.ciunit = *infile__;
	    s_rsfe(&io___741);
	    do_fio(&c__1, udum1, (ftnlen)24);
	    do_fio(&c__1, (char *)&xdum, (ftnlen)sizeof(doublereal));
	    e_rsfe();
	    s_copy(udum, udum1, (ftnlen)8, (ftnlen)8);
	    if (s_cmp(udum, uendit, (ftnlen)8, (ftnlen)8) == 0) {
		goto L378;
	    }
	    io___743.ciunit = un_1.noutpt;
	    s_wsfe(&io___743);
	    do_fio(&c__1, udum1, (ftnlen)24);
	    do_fio(&c__1, (char *)&xdum, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    ++ndum;
	    s_copy(vwc_1.umemb + (ikb + nxb * 20 - 21) * 24, udum1, (ftnlen)
		    24, (ftnlen)24);
	    vw_1.xbarb[ikb + nxb * 20 - 21] = xdum;
/* L377: */
	}
	goto L379;

L378:
	io___744.ciunit = un_1.noutpt;
	s_wsfe(&io___744);
	do_fio(&c__1, udum1, (ftnlen)24);
	e_wsfe();
L379:
	vw_1.ncompb[nxb - 1] = ndum;

/*     normalize the mole fractions of the input solid-solutions */

	sum = 0.f;
	i__2 = ndum;
	for (ikb = 1; ikb <= i__2; ++ikb) {
	    sum += vv_1.xbar[ikb + nxb * 20 - 21];
/* L50: */
	}
	if (sum == 0.f) {
	    sum = 1.f;
	}
	i__2 = ndum;
	for (ikb = 1; ikb <= i__2; ++ikb) {
	    vw_1.xbarb[ikb + nxb * 20 - 21] /= sum;
/* L55: */
	}
/* L60: */
    }
L65:

    io___746.ciunit = un_1.noutpt;
    s_wsfe(&io___746);
    e_wsfe();
    io___747.ciunit = un_1.nttyo;
    s_wsfe(&io___747);
    e_wsfe();

L999:
    return 0;
} /* readx_ */

/* scribx   last revised 12/22/87 by tjw */
/* Subroutine */ int scribx_(doublereal *sigzi, char *usave, ftnlen usave_len)
{
    /* Initialized data */

    static char uelect[8] = "electr  ";
    static char uendit[8] = "endit.  ";
    static char unone[24] = "none                    ";

    /* Format strings */
    static char fmt_737[] = "(1x,\002----- no pickup file written -----\002)";
    static char fmt_1603[] = "(\002* pickup file written by eq3nr.\002a4,a4,"
	    "/,\002*  supported by eqlib.\002a4,a4)";
    static char fmt_105[] = "(\002* post-3245 format\002)";
    static char fmt_1605[] = "(a80)";
    static char fmt_1606[] = "(a6)";
    static char fmt_705[] = "(4x,\002uacion= \002,a12)";
    static char fmt_1602[] = "(4x,\002tempci= \002,e12.5)";
    static char fmt_1600[] = "(5x,\002nxmod= \002,i2)";
    static char fmt_1643[] = "(3x,\002species= \002,a18,/,6x,\002type= \002,"
	    "i2,14x,\002option= \002,i2,14x,\002xlkmod= \002,e12.5)";
    static char fmt_1652[] = "(5x,\002iopg1= \002,i2,15x,\002iopg2= \002,i2,"
	    "15x,\002iopg3= \002,i2,/5x,\002iopg4= \002,i2,15x,\002iopg5= "
	    "\002,i2,15x,\002iopg6= \002,i2,/5x,\002iopg7= \002,i2,15x,\002io"
	    "pg8= \002,i2,15x,\002iopg9= \002,i2,/4x,\002iopg10= \002,i2)";
    static char fmt_1675[] = "(7x,\002kct= \002,i2,17x,\002ksq= \002,i2,17x"
	    ",\002kmt= \002,i2,/,7x,\002kxt= \002,i2,16x,\002kdim= \002,i2,16"
	    "x,\002kprs=  0\002)";
    static char fmt_1612[] = "(3x,a6,9x,e25.15)";
    static char fmt_180[] = "(3x,a16,3x,e25.15)";
    static char fmt_1615[] = "(3x,a16,3x,a16,3x,e25.15)";
    static char fmt_787[] = "(1x,\002----- the basis species above is not i"
	    "n\002,\002 the model -----\002)";
    static char fmt_790[] = "(1x,\002----- pickup file successfully written "
	    "-----\002)";
    static char fmt_795[] = "(1x,\002----- bad pickup file written -----\002)"
	    ;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer n, nc, is, ns, ksb1, kcol, nerr, kdum;
    static char udum1[24], udum2[24];
    static integer indxn[100];

    /* Fortran I/O blocks */
    static cilist io___757 = { 0, 0, 0, fmt_737, 0 };
    static cilist io___758 = { 0, 0, 0, fmt_1603, 0 };
    static cilist io___759 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___762 = { 0, 0, 0, fmt_1605, 0 };
    static cilist io___763 = { 0, 0, 0, fmt_1606, 0 };
    static cilist io___765 = { 0, 0, 0, fmt_705, 0 };
    static cilist io___766 = { 0, 0, 0, fmt_1602, 0 };
    static cilist io___767 = { 0, 0, 0, fmt_1600, 0 };
    static cilist io___769 = { 0, 0, 0, fmt_1643, 0 };
    static cilist io___770 = { 0, 0, 0, fmt_1652, 0 };
    static cilist io___774 = { 0, 0, 0, fmt_1675, 0 };
    static cilist io___776 = { 0, 0, 0, fmt_1612, 0 };
    static cilist io___777 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___778 = { 0, 0, 0, fmt_1612, 0 };
    static cilist io___780 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___783 = { 0, 0, 0, fmt_1615, 0 };
    static cilist io___784 = { 0, 0, 0, fmt_787, 0 };
    static cilist io___785 = { 0, 0, 0, fmt_787, 0 };
    static cilist io___786 = { 0, 0, 0, fmt_790, 0 };
    static cilist io___787 = { 0, 0, 0, fmt_795, 0 };
    static cilist io___788 = { 0, 0, 0, fmt_795, 0 };



/*     this routine writes the pickup file, which is used to */
/*     communicate data from eq3nr to eq6. */


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
/* nx.h */

/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* op1.h */
/* -------------------------------------------------------------------- */
/* op2.h */
/* -------------------------------------------------------------------- */
/* st.h */
/* -------------------------------------------------------------------- */
/* te.h */
/* -------------------------------------------------------------------- */
/* ti.h */

/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* tu.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* eqlver.h */
/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* zg.h */
/* -------------------------------------------------------------------- */
/* eqlgp.h */


/* -------------------------------------------------------------------- */

/* eqlpp.h */
/* -------------------------------------------------------------------- */


    /* Parameter adjustments */
    usave -= 24;

    /* Function Body */

/*     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

    if (op_1.iopt3 >= 0) {
	goto L733;
    }
    io___757.ciunit = un_1.noutpt;
    s_wsfe(&io___757);
    e_wsfe();
    goto L999;

L733:
    io___758.ciunit = un_1.npkup;
    s_wsfe(&io___758);
    do_fio(&c__1, eqlver_1.urelno, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ustage, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ueqlrn, (ftnlen)8);
    do_fio(&c__1, eqlver_1.ueqlst, (ftnlen)8);
    e_wsfe();
    if (op_1.iopt7 >= 1) {
	io___759.ciunit = un_1.npkup;
	s_wsfe(&io___759);
	e_wsfe();
    }
    nerr = 0;

    i__1 = ti_1.ntitl;
    for (n = 1; n <= i__1; ++n) {
	io___762.ciunit = un_1.npkup;
	s_wsfe(&io___762);
	do_fio(&c__1, tic_1.utitl + (n - 1) * 80, (ftnlen)80);
	e_wsfe();
/* L775: */
    }
    if (ti_1.ntitl < ti_1.ntitmx) {
	io___763.ciunit = un_1.npkup;
	s_wsfe(&io___763);
	do_fio(&c__1, uendit, (ftnlen)8);
	e_wsfe();
    }

/*     uacion is used only with the bdot option */

    s_copy(udum1, unone, (ftnlen)24, (ftnlen)24);
    if (eqlgp_1.iopg1 == 0) {
	s_copy(udum1, eec_1.uacion, (ftnlen)24, (ftnlen)24);
    }
    io___765.ciunit = un_1.npkup;
    s_wsfe(&io___765);
    do_fio(&c__1, udum1, (ftnlen)24);
    e_wsfe();

    io___766.ciunit = un_1.npkup;
    s_wsfe(&io___766);
    do_fio(&c__1, (char *)&hh_1.tempc, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___767.ciunit = un_1.npkup;
    s_wsfe(&io___767);
    do_fio(&c__1, (char *)&nx_1.nxmod, (ftnlen)sizeof(integer));
    e_wsfe();

    if (nx_1.nxmod <= 0) {
	goto L1625;
    }
    i__1 = nx_1.nxmod;
    for (n = 1; n <= i__1; ++n) {
	kdum = nx_1.kxmod[n - 1];
	io___769.ciunit = un_1.npkup;
	s_wsfe(&io___769);
	do_fio(&c__1, nxc_1.uxmod + (n - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&nx_1.jxmod[n - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nx_1.kxmod[n - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nx_1.xlkmod[n - 1], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
/* L1650: */
    }
L1625:

    io___770.ciunit = un_1.npkup;
    s_wsfe(&io___770);
    do_fio(&c__1, (char *)&eqlgp_1.iopg1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg5, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg6, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg7, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg8, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg9, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&eqlgp_1.iopg10, (ftnlen)sizeof(integer));
    e_wsfe();

/*     restructure the iindx1 and zvclg1 arrays */
/*        a. for hydration theory or pitzer equations the activity of */
/*           water and activity coefficients of the solute species are in */
/*           the matrix */
/*        b. if iopt7.ge.1, use post-3245 format, which may include */
/*           an auxiliary basis set of aqueous species.  component */
/*           mass balances are given by cte instead of mte. */

/*      move iindx1 array to indxn array */

    i__1 = ki_1.ksb;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	indxn[kcol - 1] = ka_1.iindx1[kcol - 1];
/* L120: */
    }

/*      build new indxn array */

    kcol = ki_1.ksb;
    if (op_1.iopt7 <= 0) {
	goto L135;
    }
    i__1 = tt_1.nsq;
    for (ns = tt_1.nsb1; ns <= i__1; ++ns) {
	if (ka_1.jsflag[ns - 1] > 0) {
	    goto L130;
	}
	if (jj_1.jflag[ns - 1] == 30) {
	    goto L130;
	}
	++kcol;
	indxn[kcol - 1] = ns;
	zg_1.zvclg1[kcol - 1] = yy_1.conclg[ns - 1];
L130:
	;
    }
L135:
    ki_1.ksq = kcol;
    ki_1.kdim = ki_1.ksq;

    io___774.ciunit = un_1.npkup;
    s_wsfe(&io___774);
    do_fio(&c__1, (char *)&ki_1.kct, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ki_1.ksq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ki_1.kdim, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ki_1.kdim, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ki_1.kdim, (ftnlen)sizeof(integer));
    e_wsfe();

/*     write the components and mass balance totals */

    if (op_1.iopt7 >= 1) {
	goto L170;
    }
    i__1 = ki_1.kct;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	nc = indxn[kcol - 1];
	io___776.ciunit = un_1.npkup;
	s_wsfe(&io___776);
	do_fio(&c__1, gg_1.uelem + (nc - 1 << 3), (ftnlen)8);
	do_fio(&c__1, (char *)&yy_1.mte[nc - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L1632: */
    }
    goto L190;

L170:
    i__1 = ki_1.kct;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	ns = indxn[kcol - 1];
	io___777.ciunit = un_1.npkup;
	s_wsfe(&io___777);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&yy_1.cte[ns - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L185: */
    }
L190:

    io___778.ciunit = un_1.npkup;
    s_wsfe(&io___778);
    do_fio(&c__1, uelect, (ftnlen)8);
    do_fio(&c__1, (char *)&(*sigzi), (ftnlen)sizeof(doublereal));
    e_wsfe();

    if (ki_1.ksq <= ki_1.ksb) {
	goto L220;
    }
    ksb1 = ki_1.ksb + 1;
    i__1 = ki_1.ksq;
    for (kcol = ksb1; kcol <= i__1; ++kcol) {
	ns = indxn[kcol - 1];
	io___780.ciunit = un_1.npkup;
	s_wsfe(&io___780);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&yy_1.cte[ns - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L215: */
    }
L220:

/*     write the basis variable information */

    i__1 = ki_1.ksq;
    for (kcol = 1; kcol <= i__1; ++kcol) {
	ns = indxn[kcol - 1];
	is = ww_1.ibasis[ns - 1];
	s_copy(udum2, usave + ns * 24, (ftnlen)24, (ftnlen)24);
	if (op_1.iopt7 <= 0) {
	    goto L230;
	}
	s_copy(udum2, gg_1.uspec + (is - 1) * 24, (ftnlen)24, (ftnlen)24);
L230:
	io___783.ciunit = un_1.npkup;
	s_wsfe(&io___783);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, udum2, (ftnlen)24);
	do_fio(&c__1, (char *)&zg_1.zvclg1[kcol - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	if (jj_1.jflag[ns - 1] >= 0) {
	    goto L1635;
	}
	io___784.ciunit = un_1.noutpt;
	s_wsfe(&io___784);
	e_wsfe();
	io___785.ciunit = un_1.npkup;
	s_wsfe(&io___785);
	e_wsfe();
	++nerr;
L1635:
	;
    }

    if (nerr > 0) {
	goto L793;
    }
    io___786.ciunit = un_1.noutpt;
    s_wsfe(&io___786);
    e_wsfe();
    goto L999;

L793:
    io___787.ciunit = un_1.noutpt;
    s_wsfe(&io___787);
    e_wsfe();
    io___788.ciunit = un_1.npkup;
    s_wsfe(&io___788);
    e_wsfe();

L999:
    return 0;
} /* scribx_ */

/* scripx   last revised 12/22/87 by tjw */
/* Subroutine */ int scripx_(doublereal *ars, doublereal *amn, doublereal *
	ags, doublereal *cdrs, doublereal *cdrm, doublereal *cdrg, doublereal 
	*csts, doublereal *cess, doublereal *concbs, doublereal *sigzi, 
	doublereal *eps100, integer *nct, integer *nsb, integer *nsb1, 
	integer *nsq, integer *nsq1, integer *nst, integer *nrst, integer *
	nmt, integer *ngt, integer *nxt, integer *nctmax, integer *nsqmax, 
	integer *nsqmx1, integer *nstmax, integer *iktmax, integer *narxmx, 
	integer *ntprmx, integer *noutpt, integer *nttyo)
{
    /* Initialized data */

    static char ublank[8] = "        ";
    static char usat[8] = "satd    ";
    static char ussat[8] = "ssatd   ";
    static char uinput[8] = "input   ";
    static char ufinal[8] = "final   ";
    static char uadj[8] = "adj     ";
    static char unone[8] = "none    ";
    static char uhydx[8] = "oh-     ";

    /* Format strings */
    static char fmt_1332[] = "(//21x,\002----- Summary of the Aqueous Phase "
	    "-----\002,/)";
    static char fmt_1348[] = "(/11x,\002----- Elemental composition of the a"
	    "queous phase\002,\002 -----\002,/)";
    static char fmt_1350[] = "(/8x,\002element      mg/l\002,11x,\002mg/k"
	    "g\002,12x,\002moles/kg\002,/)";
    static char fmt_1345[] = "(10x,a3,2(3x,f13.4),3x,e17.10)";
    static char fmt_1748[] = "(//11x,\002----- elemental composition as stri"
	    "ct\002,\002 basis species -----\002,/)";
    static char fmt_1750[] = "(/8x,\002species     mg/l\002,11x,\002mg/kg"
	    "\002,12x,\002moles/kg\002,/)";
    static char fmt_1745[] = "(10x,a6,f13.4,3x,f13.4,3x,e17.10)";
    static char fmt_205[] = "(//11x,\002--- equivalent composition of the"
	    "\002,\002 aqueous phase (cte balances) ---\002,//12x,\002origina"
	    "l basis\002,24x,\002existing basis\002)";
    static char fmt_210[] = "(/2(3x,\002species              moles/kg h2o"
	    "\002),/)";
    static char fmt_227[] = "(2(5x,a12,3x,e17.10))";
    static char fmt_242[] = "(//11x,\002--- stoichiometric composition of "
	    "the\002,\002 aqueous phase (concbs) ---\002,/)";
    static char fmt_244[] = "(/3x,\002species              moles/kg h2o\002,"
	    "/)";
    static char fmt_1331[] = "(/29x,\002activity of water = \002,f10.5,/25x"
	    ",\002log activity of water = \002,f10.5)";
    static char fmt_1112[] = "(/20x,\002true osmotic coefficient= \002,f10.5"
	    ",/10x,\002stoichiometric osmotic coefficient= \002,f10.5)";
    static char fmt_1110[] = "(/20x,\002sum of true molalities= \002,f18.13,"
	    "/10x,\002sum of stoichiometric molalities= \002,f18.13)";
    static char fmt_1375[] = "(/20x,\002titration alkalinity= \002,f18.13"
	    ",\002 eq/kg h2o\002)";
    static char fmt_105[] = "(/20x,\002carbonate alkalinity= \002,f18.13,"
	    "\002 eq/kg h2o\002)";
    static char fmt_1330[] = "(/20x,\002true ionic strength= \002,f18.13,/10"
	    "x,\002stoichiometric ionic strength= \002,f18.13)";
    static char fmt_1233[] = "(/8x,\002equiv. stoich. ionic strength (\002,a"
	    "6,\002) = \002,f18.13)";
    static char fmt_1327[] = "(8x,\002sigma(hm) = \002,f18.13,/8x,\002( 1.0 "
	    "- (sigma(hm)/55.51) ) = \002,f18.13)";
    static char fmt_1792[] = "(/11x,\002----- electrical balance totals --"
	    "---\002,///47x,\002equiv/kg\002,/)";
    static char fmt_1794[] = "(22x,\002sigma(mz) cations = \002,3x,e17.10,/2"
	    "2x,\002sigma(mz) anions  = \002,3x,e17.10,/27x,\002total charge "
	    "= \002,3x,e17.10,/28x,\002mean charge = \002,3x,e17.10,/23x,\002"
	    "charge imbalance = \002,3x,e17.10,//12x,\002total charge = sigma"
	    "(mz) cations + abs ( sigma(mz) anions )\002,/12x,\002mean charge"
	    " = 1/2 total charge\002)";
    static char fmt_1793[] = "(//12x,\002the electrical imbalance is \002,//"
	    "25x,f8.2,\002 per cent of the total charge\002,/25x,f8.2,\002 pe"
	    "r cent of the mean charge\002,/25x,f8.2,\002 per cent of sigma(m"
	    "z) cations\002,/25x,f8.2,\002 per cent of abs ( sigma(mz) anions"
	    " )\002)";
    static char fmt_1775[] = "(//11x,\002----- electrical balancing on \002,"
	    "a6,\002 -----\002)";
    static char fmt_1777[] = "(/8x,\002            mg/l\002,11x,\002mg/kg"
	    "\002,12x,\002moles/kg\002,/)";
    static char fmt_1779[] = "(/8x,\002        log activity\002,/)";
    static char fmt_28[] = "(//21x,\002----- activity ratios of ions ----"
	    "-\002,/)";
    static char fmt_22[] = "(11x,\002log ( act(\002,a12,\002)               "
	    ") = \002,2x,f9.4)";
    static char fmt_30[] = "(11x,\002log ( act(\002,a12,\002) x act(h+)xx"
	    "\002,i2,\002 ) = \002,2x,f9.4)";
    static char fmt_27[] = "(11x,\002log ( act(\002,a12,\002) / act(h+)xx"
	    "\002,i2,\002 ) = \002,2x,f9.4)";
    static char fmt_705[] = "(//11x,\002----- distribution of aqueous specie"
	    "s -----\002,/)";
    static char fmt_707[] = "(16x,\002(species with concentrations .lt. 1.e-"
	    "20 are\002,\002 not listed)\002,/)";
    static char fmt_712[] = "(16x,\002(species with concentrations .lt. 1.e-"
	    "12 are\002,\002 not listed)\002,/)";
    static char fmt_1335[] = "(7x,\002species\002,10x,\002molal conc\002,3x"
	    ",\002log conc\002,6x,\002log g\002,4x,\002activity\002,5x,\002lo"
	    "g act\002,/)";
    static char fmt_1340[] = "(3x,a18,2x,e16.9,2x,f9.4,2x,f9.4,2x,e16.9,2x,f"
	    "9.4)";
    static char fmt_1116[] = "(//,11x,\002----- mean ionic properties ----"
	    "-\002,/)";
    static char fmt_1118[] = "(52x,\002true (a)\002,12x,\002stoichiometric ("
	    "b)\002,//3x,\002species\002,2x,\002species\002,3x,\002log a(+/-"
	    ")\002,4x,\002a(+/-)\002,6x,\002m(+/-)\002,6x,\002g(+/-)\002,6x"
	    ",\002m(+/-)\002,6x,\002g(+/-)\002,/)";
    static char fmt_1120[] = "(3x,2(2x,a6),2x,f10.5,5(2x,1pe10.3))";
    static char fmt_1117[] = "(/3x,\002(a) true quantities consistent with t"
	    "he speciation\002,\002 model\002,/3x,\002(b) stoichiometric quan"
	    "tities consistent with the\002,\002 cte mass\002,/3x,\002 balanc"
	    "e lumpings, except that\002,/3x,\002   1. effective cte(h+)  = c"
	    "te(h+) - conc(h2o)\002,/3x,\002   2. effective cte(oh-) = cte(h2"
	    "o) - conc(h2o)\002,/)";
    static char fmt_805[] = "(//11x,\002----- major aqueous species contribu"
	    "ting\002,\002 to mass balances -----\002,/)";
    static char fmt_808[] = "(//11x,\002----- aqueous species by contributio"
	    "n to mass\002,\002 balances -----\002,/)";
    static char fmt_810[] = "(/,\002 aqueous species accounting for 99% or m"
	    "ore of \002,a18,//,5x,\002species\002,12x,\002molal conc\002,4x"
	    ",\002per cent\002,/)";
    static char fmt_812[] = "(/1x,\002aqueous species accounting for \002,a1"
	    "8,//5x,\002species\002,12x,\002molal conc\002,4x,\002per cent"
	    "\002,/)";
    static char fmt_815[] = "(3x,a18,3x,e11.4,3x,f6.2)";
    static char fmt_865[] = "(1x,\002- - - - - - - - - - - - - - - - - - - -"
	    " - - -\002,/3x,\002total\002,30x,f6.2,/)";
    static char fmt_305[] = "(//11x,\002----- summary of aqueous redox react"
	    "ions -----\002,//6x,\002couple\002,9x,\002eh, volts\002,6x,\002p"
	    "e-\002,7x,\002log fo2\002,5x,\002ah, kcal\002,/)";
    static char fmt_314[] = "(3x,\002default\002,11x,f7.3,3x,e11.4,3x,f8.3,4"
	    "x,f8.3)";
    static char fmt_315[] = "(3x,a8,\002/\002,a8,1x,f7.3,3x,e11.4,3x,f8.3,4x"
	    ",f8.3)";
    static char fmt_420[] = "(//11x,\002----- summary of aqueous non-equilib"
	    "rium\002,\002 non-redox reactions -----\002,//6x,\002couple\002,"
	    "7x,\002affinity, kcal\002,/)";
    static char fmt_435[] = "(6x,a6,\002/\002,a6,2x,f8.3)";
    static char fmt_455[] = "(6x,\002none\002)";
    static char fmt_905[] = "(//11x,\002----- summary of stoichiometric mine"
	    "ral\002,\002 saturation states -----\002,/)";
    static char fmt_910[] = "(11x,\002(minerals with affinities .lt. -10 kca"
	    "l are not\002,\002 listed)\002,/)";
    static char fmt_915[] = "(/3x,\002mineral\002,7x,\002log q/k\002,3x,\002"
	    "aff, kcal\002,2x,\002state\002,11x,\002mineral\002,7x,\002log q/k"
	    "\002,3x,\002aff, kcal\002,2x,\002state\002,/)";
    static char fmt_935[] = "(1x,a12,2(2x,f9.3),2x,a5,10x,a12,2(2x,f9.3),2x,"
	    "a5)";
    static char fmt_1432[] = "(\0021\002,//31x,\002----- summary of input so"
	    "lid solutions -----\002,/)";
    static char fmt_1380[] = "(7x,\002mineral\002,13x,\002log q/k\002,8x,"
	    "\002aff, kcal\002,6x,\002state\002,/)";
    static char fmt_1355[] = "(/4x,a18,/)";
    static char fmt_1385[] = "(/,3x,a18,2(2x,f13.7),5x,\002approx. saturate"
	    "d\002)";
    static char fmt_1390[] = "(/,3x,a18,2(2x,f13.7),5x,\002undersaturated"
	    "\002)";
    static char fmt_1395[] = "(/,3x,a18,2(2x,f13.7),5x,\002supersaturated"
	    "\002)";
    static char fmt_1394[] = "(/,4x,\002For fixed composition solid solution"
	    " phase:\002)";
    static char fmt_1399[] = "(/,3x,a18,2(2x,f13.7))";
    static char fmt_1440[] = "(/1x,a18,/6x,a30,/)";
    static char fmt_1435[] = "(27x,\002xbar\002,9x,\002lamda\002,9x,\002acti"
	    "vity\002,5x,\002log xbar\002,5x,\002log lamda\002,4x,\002log ac"
	    "t\002,/)";
    static char fmt_1546[] = "(8x,a12,2x,e10.3,4x,f10.4,4x,e10.3,3(4x,f10.4))"
	    ;
    static char fmt_1445[] = "(8x,a12,2x,6(f10.4,4x))";
    static char fmt_1433[] = "(\0021\002,/31x,\002----- summary of hypotheti"
	    "cal solid solutions \002,\002-----\002,/)";
    static char fmt_1512[] = "(/,\002_______________________________________"
	    "___________\002,\002___________________\002)";
    static char fmt_1393[] = "(/,3x,a18,3x,\002solid solution not present in"
	    " the model\002)";
    static char fmt_1397[] = "(//,3x,a18,16x,\002failed in simplx routine"
	    "\002)";
    static char fmt_1398[] = "(//,3x,a18,3x,\002oscillatory solution - log d"
	    "iff = -\002,i1)";
    static char fmt_1392[] = "(5x,a18,\002 endmember not present or is user "
	    "suppressed\002)";
    static char fmt_1391[] = "(5x,a18,2(f13.7,2x))";
    static char fmt_1441[] = "(/5x,a30)";
    static char fmt_1446[] = "(8x,\002no components present in model\002)";
    static char fmt_1400[] = "(//1x,i5,\002 approx. saturated pure mineral"
	    "s\002,/1x,i5,\002 approx. saturated end-members of specified\002,"
	    "\002 solid solutions\002,/1x,i5,\002 saturated end-members of hy"
	    "pothetical solid\002,\002 solutions\002,/)";
    static char fmt_1405[] = "(/1x,i5,\002 supersaturated pure minerals\002,"
	    "/1x,i5,\002 supersatd. end-members of specified solid solution"
	    "s\002,/1x,i5,\002 supersatd. hypothetical solid solution phase"
	    "s\002,//)";
    static char fmt_1360[] = "(//21x,\002----- summary of gases -----\002,/)";
    static char fmt_1362[] = "(/7x,\002gas \002,18x,\002fugacity\002,4x,\002"
	    "log fugacity\002,/)";
    static char fmt_1365[] = "(3x,a18,5x,e13.6,3x,f10.5)";
    static char fmt_1410[] = "(/1x,\002----- end of output -----\002)";

    /* System generated locals */
    integer ars_dim1, ars_dim2, ars_offset, amn_dim1, amn_dim2, amn_offset, 
	    ags_dim1, ags_dim2, ags_offset, cdrs_dim1, cdrs_offset, cdrm_dim1,
	     cdrm_offset, cdrg_dim1, cdrg_offset, csts_dim1, csts_offset, 
	    cess_dim1, cess_offset, i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    double log(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer k, n, n1, n2;
    static doublereal z1, z2, af[2], ah;
    static integer nc, ik, ng;
    static doublereal ph, aw;
    static integer nm, ks, is, nn, ns, iz, nx;
    static char us[8*2];
    static doublereal xq[2], zz;
    static integer ns1, ns2;
    static doublereal aff[750];
    static integer isc, ise;
    static char una[24*2];
    static doublereal axx[400]	/* was [20][20] */, wfs;
    static integer nss, nse;
    static doublereal alw, osc, dum;
    static integer nnn;
    extern doublereal tlg_(doublereal *);
    static integer nsc, nrs;
    static doublereal xlq;
    static integer num, nxb, ier;
    static doublereal cte1, cte2;
    static char udm1[24], udm2[24];
    static doublereal dum1, dum3, dum2, dum4;
    static integer nnm1, jflc;
    extern /* Subroutine */ int elim_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *);
    static doublereal phcl, alkt, ctot;
    extern doublereal texp_(doublereal *);
    extern /* Subroutine */ int gszm_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *)
	    ;
    static doublereal cdum, zdum, gdum, xqkx[20];
    static integer ndum;
    static doublereal pdum, fdum, cdum1, cdum3, cdum2, gdum1, cdum4, pdum1, 
	    edum;
    static char udum1[8], udum2[8], udum3[8];
    static doublereal amean;
    extern /* Subroutine */ int gpheh_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    logical *);
    static doublereal osfac, ehnbs, xbarh[20];
    extern /* Subroutine */ int gcsts_(doublereal *, doublereal *, doublereal 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, integer *, integer *, integer *, integer *, integer 
	    *, integer *, logical *);
    static doublereal ctoti, phnbs, phrat, ehrat, penbs, perat;
    extern /* Subroutine */ int gsigm_(doublereal *, integer *, integer *, 
	    doublereal *);
    static doublereal stosc, sigzc, sigza, sigzm;
    static integer jfdum;
    static doublereal cfree, gfree, ctelg1, ctelg2, cstoi, gstoi, ahfac, adum;
    static integer kount;
    static doublereal ctebal, afdum, almean;
    static integer nsat, nxsat, ksat, kxsat, ncpt, itracx[20];
    extern /* Subroutine */ int molint_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, doublereal *);
    static logical qnochb;
    extern /* Subroutine */ int prpheh_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, integer *, logical *);
    static doublereal sigmam, sigstm;
    extern /* Subroutine */ int gxisto_(doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *);
    static doublereal xistoc, msigzm, sanion, acthyd, actrat;
    static integer nxhsat, kxhsat;
    static doublereal ssum, xdum, xlqkx, afss, xlamda, actxlg, actx;
    extern /* Subroutine */ int hpsat_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, char *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, ftnlen, ftnlen);
    static integer icount;
    extern /* Subroutine */ int gases_(void);

    /* Fortran I/O blocks */
    static cilist io___799 = { 0, 0, 0, fmt_1332, 0 };
    static cilist io___800 = { 0, 0, 0, fmt_1348, 0 };
    static cilist io___801 = { 0, 0, 0, fmt_1350, 0 };
    static cilist io___809 = { 0, 0, 0, fmt_1345, 0 };
    static cilist io___810 = { 0, 0, 0, fmt_1748, 0 };
    static cilist io___811 = { 0, 0, 0, fmt_1750, 0 };
    static cilist io___812 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___815 = { 0, 0, 0, fmt_205, 0 };
    static cilist io___816 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___820 = { 0, 0, 0, fmt_227, 0 };
    static cilist io___821 = { 0, 0, 0, fmt_242, 0 };
    static cilist io___822 = { 0, 0, 0, fmt_244, 0 };
    static cilist io___823 = { 0, 0, 0, fmt_227, 0 };
    static cilist io___835 = { 0, 0, 0, fmt_1331, 0 };
    static cilist io___841 = { 0, 0, 0, fmt_1112, 0 };
    static cilist io___842 = { 0, 0, 0, fmt_1110, 0 };
    static cilist io___845 = { 0, 0, 0, fmt_1375, 0 };
    static cilist io___846 = { 0, 0, 0, fmt_105, 0 };
    static cilist io___848 = { 0, 0, 0, fmt_1330, 0 };
    static cilist io___849 = { 0, 0, 0, fmt_1233, 0 };
    static cilist io___850 = { 0, 0, 0, fmt_1327, 0 };
    static cilist io___856 = { 0, 0, 0, fmt_1792, 0 };
    static cilist io___857 = { 0, 0, 0, fmt_1794, 0 };
    static cilist io___860 = { 0, 0, 0, fmt_1793, 0 };
    static cilist io___865 = { 0, 0, 0, fmt_1775, 0 };
    static cilist io___867 = { 0, 0, 0, fmt_1777, 0 };
    static cilist io___870 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___871 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___872 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___873 = { 0, 0, 0, fmt_1779, 0 };
    static cilist io___874 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___875 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___876 = { 0, 0, 0, fmt_1745, 0 };
    static cilist io___877 = { 0, 0, 0, fmt_28, 0 };
    static cilist io___882 = { 0, 0, 0, fmt_22, 0 };
    static cilist io___884 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___885 = { 0, 0, 0, fmt_27, 0 };
    static cilist io___886 = { 0, 0, 0, fmt_705, 0 };
    static cilist io___887 = { 0, 0, 0, fmt_707, 0 };
    static cilist io___888 = { 0, 0, 0, fmt_712, 0 };
    static cilist io___889 = { 0, 0, 0, fmt_1335, 0 };
    static cilist io___892 = { 0, 0, 0, fmt_1340, 0 };
    static cilist io___893 = { 0, 0, 0, fmt_1116, 0 };
    static cilist io___894 = { 0, 0, 0, fmt_1118, 0 };
    static cilist io___914 = { 0, 0, 0, fmt_1120, 0 };
    static cilist io___915 = { 0, 0, 0, fmt_1120, 0 };
    static cilist io___916 = { 0, 0, 0, fmt_1117, 0 };
    static cilist io___917 = { 0, 0, 0, fmt_805, 0 };
    static cilist io___918 = { 0, 0, 0, fmt_808, 0 };
    static cilist io___919 = { 0, 0, 0, fmt_810, 0 };
    static cilist io___920 = { 0, 0, 0, fmt_812, 0 };
    static cilist io___925 = { 0, 0, 0, fmt_815, 0 };
    static cilist io___926 = { 0, 0, 0, fmt_865, 0 };
    static cilist io___927 = { 0, 0, 0, fmt_305, 0 };
    static cilist io___930 = { 0, 0, 0, fmt_314, 0 };
    static cilist io___940 = { 0, 0, 0, fmt_315, 0 };
    static cilist io___941 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___944 = { 0, 0, 0, fmt_435, 0 };
    static cilist io___945 = { 0, 0, 0, fmt_455, 0 };
    static cilist io___955 = { 0, 0, 0, fmt_905, 0 };
    static cilist io___956 = { 0, 0, 0, fmt_910, 0 };
    static cilist io___957 = { 0, 0, 0, fmt_915, 0 };
    static cilist io___963 = { 0, 0, 0, fmt_935, 0 };
    static cilist io___965 = { 0, 0, 0, fmt_935, 0 };
    static cilist io___966 = { 0, 0, 0, fmt_1432, 0 };
    static cilist io___967 = { 0, 0, 0, fmt_1380, 0 };
    static cilist io___970 = { 0, 0, 0, fmt_1355, 0 };
    static cilist io___976 = { 0, 0, 0, fmt_1385, 0 };
    static cilist io___977 = { 0, 0, 0, fmt_1390, 0 };
    static cilist io___978 = { 0, 0, 0, fmt_1395, 0 };
    static cilist io___980 = { 0, 0, 0, fmt_1394, 0 };
    static cilist io___981 = { 0, 0, 0, fmt_1399, 0 };
    static cilist io___983 = { 0, 0, 0, fmt_1440, 0 };
    static cilist io___984 = { 0, 0, 0, fmt_1435, 0 };
    static cilist io___988 = { 0, 0, 0, fmt_1546, 0 };
    static cilist io___989 = { 0, 0, 0, fmt_1445, 0 };
    static cilist io___990 = { 0, 0, 0, fmt_1433, 0 };
    static cilist io___991 = { 0, 0, 0, fmt_1380, 0 };
    static cilist io___999 = { 0, 0, 0, fmt_1512, 0 };
    static cilist io___1000 = { 0, 0, 0, fmt_1393, 0 };
    static cilist io___1001 = { 0, 0, 0, fmt_1397, 0 };
    static cilist io___1002 = { 0, 0, 0, fmt_1398, 0 };
    static cilist io___1003 = { 0, 0, 0, fmt_1385, 0 };
    static cilist io___1004 = { 0, 0, 0, fmt_1390, 0 };
    static cilist io___1005 = { 0, 0, 0, fmt_1395, 0 };
    static cilist io___1006 = { 0, 0, 0, fmt_1392, 0 };
    static cilist io___1007 = { 0, 0, 0, fmt_1391, 0 };
    static cilist io___1008 = { 0, 0, 0, fmt_1441, 0 };
    static cilist io___1009 = { 0, 0, 0, fmt_1435, 0 };
    static cilist io___1011 = { 0, 0, 0, fmt_1546, 0 };
    static cilist io___1012 = { 0, 0, 0, fmt_1445, 0 };
    static cilist io___1013 = { 0, 0, 0, fmt_1446, 0 };
    static cilist io___1014 = { 0, 0, 0, fmt_1400, 0 };
    static cilist io___1015 = { 0, 0, 0, fmt_1405, 0 };
    static cilist io___1016 = { 0, 0, 0, fmt_1360, 0 };
    static cilist io___1017 = { 0, 0, 0, fmt_1362, 0 };
    static cilist io___1019 = { 0, 0, 0, fmt_1365, 0 };
    static cilist io___1020 = { 0, 0, 0, fmt_1410, 0 };



/*     print the output describing the computed model of the aqueous */
/*     solution. */


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
/* an.h */
/* -------------------------------------------------------------------- */
/* cc.h */

/* -------------------------------------------------------------------- */
/* ee.h */

/* -------------------------------------------------------------------- */
/* fg.h */
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
/* te.h */
/* -------------------------------------------------------------------- */
/* tu.h */
/* -------------------------------------------------------------------- */
/* uu.h */


/* -------------------------------------------------------------------- */
/* vv.h */
/* -------------------------------------------------------------------- */
/* vw.h */

/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */
/* -------------------------------------------------------------------- */
/* yy.h */
/* -------------------------------------------------------------------- */
/* zg.h */
/* -------------------------------------------------------------------- */
/* eqldd.h */
/* -------------------------------------------------------------------- */
/* eqlpp.h */
/* -------------------------------------------------------------------- */

/* eqlgp.h */


/* -------------------------------------------------------------------- */



    /* Parameter adjustments */
    --concbs;
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

/* ---------------------------------------------------------------------- */

    io___799.ciunit = *noutpt;
    s_wsfe(&io___799);
    e_wsfe();

/*     compute the mole totals of the elements in the aqueous phase */

    io___800.ciunit = *noutpt;
    s_wsfe(&io___800);
    e_wsfe();
    io___801.ciunit = *noutpt;
    s_wsfe(&io___801);
    e_wsfe();
    wfs = (1e6f - jj_1.tdspkg) / 1e6f;

    i__1 = *nct;
    for (nc = 1; nc <= i__1; ++nc) {
	yy_1.mte[nc - 1] = 0.f;
	if (jj_1.jcflag[nc - 1] <= 0) {
	    goto L1230;
	}
	dum1 = 0.f;

	i__2 = *nst;
	for (nss = 1; nss <= i__2; ++nss) {
	    ns = st_1.jsort[nss - 1];
	    dum1 += cess[nc + ns * cess_dim1] * yy_1.conc[ns - 1];
/* L1225: */
	}
	dum1 += cess[nc + cess_dim1] * eqlpp_1.om;

	yy_1.mte[nc - 1] = dum1;
	dum3 = dum1 * 1e3f * oo_1.atwt[nc - 1] * wfs;
	dum2 = dum3 * jj_1.rho;
	io___809.ciunit = *noutpt;
	s_wsfe(&io___809);
	do_fio(&c__1, gg_1.uelem + (nc - 1 << 3), (ftnlen)8);
	do_fio(&c__1, (char *)&dum2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dum3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dum1, (ftnlen)sizeof(doublereal));
	e_wsfe();
L1230:
	;
    }

/*     compute the mole totals of the elements (as their corresponding */
/*     strict basis species) in the aqueous phase */

    io___810.ciunit = *noutpt;
    s_wsfe(&io___810);
    e_wsfe();
    io___811.ciunit = *noutpt;
    s_wsfe(&io___811);
    e_wsfe();
    wfs = (1e6f - jj_1.tdspkg) / 1e6f;

    i__1 = *nct;
    for (nc = 1; nc <= i__1; ++nc) {
	if (jj_1.jcflag[nc - 1] <= 0) {
	    goto L1730;
	}
	ns = ww_1.ibasis[nc - 1];
	dum1 = yy_1.mte[nc - 1];
	dum3 = dum1 * 1e3f * oo_1.mwtss[ns - 1] * wfs;
	dum2 = dum3 * jj_1.rho;
	io___812.ciunit = *noutpt;
	s_wsfe(&io___812);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&dum2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dum3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dum1, (ftnlen)sizeof(doublereal));
	e_wsfe();
L1730:
	;
    }

/*     compute and save the calculated total concentration of the */
/*     species adjusted for electrical balance */

    if (ee_1.iebal <= 0) {
	goto L1770;
    }
    ctebal = 0.f;
    i__1 = *nst;
    for (nss = 1; nss <= i__1; ++nss) {
	ns = st_1.jsort[nss - 1];
	ctebal += csts[ee_1.iebal + ns * csts_dim1] * yy_1.conc[ns - 1];
/* L1765: */
    }
L1770:

/*     compute and output the equivalent mole totals of the elements */

/*        reset jflag parameters implying equilibrium with the */
/*        corresponding strict basis species to 30 */

    if (op_1.iopt1 > 0) {
	nse = op_1.iopt1 + *nsb;
	jj_1.jflag[nse - 1] = 30;
	elim_(&nse, &ars[ars_offset], &amn[amn_offset], &ags[ags_offset], &
		cdrs[cdrs_offset], &cdrm[cdrm_offset], &cdrg[cdrg_offset], 
		eps100, nsb, nsq1, nrst, nmt, ngt, nsqmx1, narxmx, ntprmx, 
		noutpt, nttyo);
    }

    i__1 = *nsq;
    for (nse = *nsb1; nse <= i__1; ++nse) {
	if (jj_1.jflag[nse - 1] == 27) {
	    jj_1.jflag[nse - 1] = 30;
	    elim_(&nse, &ars[ars_offset], &amn[amn_offset], &ags[ags_offset], 
		    &cdrs[cdrs_offset], &cdrm[cdrm_offset], &cdrg[cdrg_offset]
		    , eps100, nsb, nsq1, nrst, nmt, ngt, nsqmx1, narxmx, 
		    ntprmx, noutpt, nttyo);
	}
/* L204: */
    }

    gcsts_(&csts[csts_offset], &cdrs[cdrs_offset], st_1.cstor, ww_1.ibasis, 
	    ka_1.jsflag, jj_1.jflag, &tu_1.nhydr, nct, nsb, nsb1, nsq, nsq1, 
	    nst, nsqmax, nsqmx1, nstmax, &ww_1.qbassw);

    io___815.ciunit = *noutpt;
    s_wsfe(&io___815);
    e_wsfe();
    io___816.ciunit = *noutpt;
    s_wsfe(&io___816);
    e_wsfe();

    i__1 = *nsq;
    for (nse = 1; nse <= i__1; ++nse) {
	yy_1.cte[nse - 1] = 0.f;
	if (ka_1.jsflag[nse - 1] > 0) {
	    goto L230;
	}
	if (jj_1.jflag[nse - 1] == 30) {
	    goto L230;
	}
	if (nse == *nsb) {
	    goto L230;
	}
	ctot = 0.f;
	i__2 = *nst;
	for (nss = 1; nss <= i__2; ++nss) {
	    ns = st_1.jsort[nss - 1];
	    ctot += csts[nse + ns * csts_dim1] * yy_1.conc[ns - 1];
/* L225: */
	}
	ctot += csts[nse + csts_dim1] * eqlpp_1.om;
	yy_1.cte[nse - 1] = ctot;
	ise = ww_1.ibasis[nse - 1];

/*     ctoti = ctot/csts(nse,ise) */
	ctoti = 5.f;

	io___820.ciunit = *noutpt;
	s_wsfe(&io___820);
	do_fio(&c__1, gg_1.uspec + (ise - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&ctoti, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&ctot, (ftnlen)sizeof(doublereal));
	e_wsfe();
L230:
	;
    }

    molint_(yy_1.conc, nsq, nst, &cdrs[cdrs_offset], nsqmx1, nsb, &c__3, &
	    concbs[1]);
    if (op1_1.iopr10 >= 1) {
	io___821.ciunit = *noutpt;
	s_wsfe(&io___821);
	e_wsfe();
	io___822.ciunit = *noutpt;
	s_wsfe(&io___822);
	e_wsfe();
	i__1 = *nsq;
	for (nse = 2; nse <= i__1; ++nse) {
	    if (ka_1.jsflag[nse - 1] <= 0) {
		io___823.ciunit = *noutpt;
		s_wsfe(&io___823);
		do_fio(&c__1, gg_1.uspec + (nse - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&concbs[nse], (ftnlen)sizeof(doublereal)
			);
		e_wsfe();
	    }
/* L245: */
	}
    }

/*     compute and print ph, eh, and pe, all with reference to */
/*     appropriate ph scales.  compute and print phcl. */

    qnochb = FALSE_;
    gpheh_(yy_1.actlg, ccp_1.glg, &cc_1.fo2lg, &cc_1.xi, &eqldd_1.adh, &
	    xx_1.xlkeh, &eqlpp_1.ehfac, &ph, &phnbs, &phrat, &phcl, &jj_1.eh, 
	    &ehnbs, &ehrat, &jj_1.pe, &penbs, &perat, &eqlgp_1.iopg2, &
	    tu_1.nhydr, &tu_1.nchlor, &qnochb);

    prpheh_(&ph, &phnbs, &phrat, &phcl, &jj_1.eh, &ehnbs, &ehrat, &jj_1.pe, &
	    penbs, &perat, &eqlgp_1.iopg2, &tu_1.nchlor, noutpt, &qnochb);

    alw = ccp_1.glg[0];
    aw = texp_(&alw);
    io___835.ciunit = *noutpt;
    s_wsfe(&io___835);
    do_fio(&c__1, (char *)&aw, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&alw, (ftnlen)sizeof(doublereal));
    e_wsfe();

    gsigm_(yy_1.conc, st_1.jsort, nst, &sigmam);
    sigstm = 0.f;
    i__1 = *nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	sigstm += concbs[ns];
/* L240: */
    }

    osfac = -eqlpp_1.om * log(aw);
    osc = osfac / sigmam;
    stosc = osfac / sigstm;
    io___841.ciunit = *noutpt;
    s_wsfe(&io___841);
    do_fio(&c__1, (char *)&osc, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&stosc, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___842.ciunit = *noutpt;
    s_wsfe(&io___842);
    do_fio(&c__1, (char *)&sigmam, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&sigstm, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (hh_1.tempc <= 50.f) {
	alkt = 0.f;
	i__1 = *nst;
	for (nss = 1; nss <= i__1; ++nss) {
	    ns = st_1.jsort[nss - 1];
	    alkt += ccp_1.titr[ns - 1] * yy_1.conc[ns - 1];
/* L1235: */
	}
	jflc = 10;
	if (tu_1.ncarb > 0) {
	    jflc = jj_1.jflag[tu_1.ncarb - 1];
	}
	if (jflc == 10) {
	    io___845.ciunit = *noutpt;
	    s_wsfe(&io___845);
	    do_fio(&c__1, (char *)&alkt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else if (jflc == 12) {
	    io___846.ciunit = *noutpt;
	    s_wsfe(&io___846);
	    do_fio(&c__1, (char *)&alkt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }

    gxisto_(ccp_1.zsq2, yy_1.conc, nsq, &concbs[1], &xistoc);
    io___848.ciunit = *noutpt;
    s_wsfe(&io___848);
    do_fio(&c__1, (char *)&cc_1.xi, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xistoc, (ftnlen)sizeof(doublereal));
    e_wsfe();

    if (eqlgp_1.iopg1 == 0) {
	if (ee_1.iacion > 0) {
	    io___849.ciunit = *noutpt;
	    s_wsfe(&io___849);
	    do_fio(&c__1, gg_1.uspec + (ee_1.iacion - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&cc_1.xisteq, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    } else if (eqlgpa_1.qhydth) {
	io___850.ciunit = *noutpt;
	s_wsfe(&io___850);
	do_fio(&c__1, (char *)&cc_1.shm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&cc_1.dshm, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/*     calculate and print the electrical balance and the cation and */
/*     anion contributions */

    gszm_(ccp_1.z__, yy_1.conc, st_1.jsort, nst, &sigzc, &sigza, &sigzm, 
	    sigzi);

    msigzm = sigzm * .5f;
    sanion = -sigza;

    io___856.ciunit = *noutpt;
    s_wsfe(&io___856);
    e_wsfe();
    io___857.ciunit = *noutpt;
    s_wsfe(&io___857);
    do_fio(&c__1, (char *)&sigzc, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&sanion, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&sigzm, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&msigzm, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&(*sigzi), (ftnlen)sizeof(doublereal));
    e_wsfe();
    dum = *sigzi * 100.f;
    dum1 = dum / sigzm;
    dum2 = dum / msigzm;
    dum3 = dum / sigzc;
    dum4 = -dum / sanion;
    io___860.ciunit = *noutpt;
    s_wsfe(&io___860);
    do_fio(&c__1, (char *)&dum1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dum2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dum3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dum4, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     print results of electrical balancing */

    if (ee_1.iebal <= 0) {
	goto L1790;
    }
    jfdum = jj_1.jflag[ee_1.iebal - 1];
    s_copy(udum1, uinput, (ftnlen)8, (ftnlen)8);
    s_copy(udum2, ufinal, (ftnlen)8, (ftnlen)8);
    s_copy(udum3, uadj, (ftnlen)8, (ftnlen)8);
    io___865.ciunit = *noutpt;
    s_wsfe(&io___865);
    do_fio(&c__1, gg_1.uspec + (ee_1.iebal - 1) * 24, (ftnlen)24);
    e_wsfe();
    if (jfdum != 0) {
	goto L1778;
    }
    cdum1 = ww_1.csp[ee_1.iebal - 1];
    io___867.ciunit = *noutpt;
    s_wsfe(&io___867);
    e_wsfe();
    cdum3 = cdum1 * 1e3f * oo_1.mwtss[ee_1.iebal - 1] * wfs;
    cdum2 = cdum3 * jj_1.rho;
    io___870.ciunit = *noutpt;
    s_wsfe(&io___870);
    do_fio(&c__1, udum1, (ftnlen)8);
    do_fio(&c__1, (char *)&cdum2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cdum3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cdum1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    cdum1 = ctebal;
    cdum3 = cdum1 * 1e3f * oo_1.mwtss[ee_1.iebal - 1] * wfs;
    cdum2 = cdum3 * jj_1.rho;
    io___871.ciunit = *noutpt;
    s_wsfe(&io___871);
    do_fio(&c__1, udum2, (ftnlen)8);
    do_fio(&c__1, (char *)&cdum2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cdum3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cdum1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    cdum1 = ctebal - ww_1.csp[ee_1.iebal - 1];
    cdum3 = cdum1 * 1e3f * oo_1.mwtss[ee_1.iebal - 1] * wfs;
    cdum2 = cdum3 * jj_1.rho;
    io___872.ciunit = *noutpt;
    s_wsfe(&io___872);
    do_fio(&c__1, udum3, (ftnlen)8);
    do_fio(&c__1, (char *)&cdum2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cdum3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cdum1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1790;

L1778:
    if (jfdum != 16) {
	goto L1790;
    }
    io___873.ciunit = *noutpt;
    s_wsfe(&io___873);
    e_wsfe();
    cdum1 = ww_1.csp[ee_1.iebal - 1];
    cdum2 = yy_1.actlg[ee_1.iebal - 1];
    io___874.ciunit = *noutpt;
    s_wsfe(&io___874);
    do_fio(&c__1, udum1, (ftnlen)8);
    do_fio(&c__1, (char *)&cdum1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___875.ciunit = *noutpt;
    s_wsfe(&io___875);
    do_fio(&c__1, udum2, (ftnlen)8);
    do_fio(&c__1, (char *)&cdum2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    cdum3 = cdum2 - cdum1;
    io___876.ciunit = *noutpt;
    s_wsfe(&io___876);
    do_fio(&c__1, udum3, (ftnlen)8);
    do_fio(&c__1, (char *)&cdum3, (ftnlen)sizeof(doublereal));
    e_wsfe();
L1790:

/*     compute and print activity ratios of cations to hydrogen ion */

    io___877.ciunit = *noutpt;
    s_wsfe(&io___877);
    e_wsfe();
    acthyd = yy_1.actlg[tu_1.nhydr - 1];

    i__1 = *nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	if (ns == tu_1.nhydr) {
	    goto L20;
	}
	ks = ww_1.ibasis[ns - 1];
	if (ka_1.jsflag[ks - 1] >= 2) {
	    goto L20;
	}
	if (ks > *nsq) {
	    goto L29;
	}
	if (jj_1.jflag[ks - 1] <= -1) {
	    goto L20;
	}
L29:
	zz = ccp_1.z__[ks - 1];
	actrat = yy_1.actlg[ks - 1];
	if (zz != 0.f) {
	    goto L21;
	}
	io___882.ciunit = *noutpt;
	s_wsfe(&io___882);
	do_fio(&c__1, gg_1.uspec + (ks - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&actrat, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L20;

L21:
	iz = (integer) (abs(zz) + .001f);
	actrat -= zz * acthyd;
	if (zz > 0.f) {
	    goto L23;
	}
	io___884.ciunit = *noutpt;
	s_wsfe(&io___884);
	do_fio(&c__1, gg_1.uspec + (ks - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&iz, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&actrat, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L20;

L23:
	io___885.ciunit = *noutpt;
	s_wsfe(&io___885);
	do_fio(&c__1, gg_1.uspec + (ks - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&iz, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&actrat, (ftnlen)sizeof(doublereal));
	e_wsfe();
L20:
	;
    }

/*     print the aqueous species distribution */

    if (op1_1.iopr4 <= -3) {
	goto L1222;
    }
    io___886.ciunit = *noutpt;
    s_wsfe(&io___886);
    e_wsfe();
    if (op1_1.iopr4 >= 0) {
	goto L720;
    }
    if (op1_1.iopr4 <= -2) {
	goto L710;
    }
    io___887.ciunit = *noutpt;
    s_wsfe(&io___887);
    e_wsfe();
    goto L720;

L710:
    io___888.ciunit = *noutpt;
    s_wsfe(&io___888);
    e_wsfe();
L720:
    io___889.ciunit = *noutpt;
    s_wsfe(&io___889);
    e_wsfe();

    i__1 = *nst;
    for (nnn = 1; nnn <= i__1; ++nnn) {
	if (op1_1.iopr3 >= 1) {
	    goto L722;
	}
	nss = *nst + 1 - nnn;
	ns = st_1.jsort[nss - 1];
	goto L723;
L722:
	ns = ww_1.ibasis[nnn - 1];
L723:
	if (ka_1.jsflag[ns - 1] >= 2) {
	    goto L1220;
	}
	cdum = yy_1.conclg[ns - 1];
	if (cdum <= -999.f) {
	    goto L1220;
	}
	if (op1_1.iopr4 >= 0) {
	    goto L1221;
	}
	if (op1_1.iopr4 != -1) {
	    goto L1223;
	}
	if (cdum >= -20.f) {
	    goto L1221;
	}
	if (op1_1.iopr3 <= 0) {
	    goto L1222;
	}
	goto L1220;

L1223:
	if (cdum >= -12.f) {
	    goto L1221;
	}
	if (op1_1.iopr3 <= 0) {
	    goto L1222;
	}
	goto L1220;

L1221:
	io___892.ciunit = *noutpt;
	s_wsfe(&io___892);
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&yy_1.conc[ns - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&cdum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ccp_1.glg[ns - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&yy_1.act[ns - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&yy_1.actlg[ns - 1], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
L1220:
	;
    }
L1222:
    if (op1_1.iopr6 == 0) {
	goto L275;
    }

/*      output the mean ionic activity coefficients */

    io___893.ciunit = *noutpt;
    s_wsfe(&io___893);
    e_wsfe();
    io___894.ciunit = *noutpt;
    s_wsfe(&io___894);
    e_wsfe();

    i__1 = *nsq;
    for (n1 = 2; n1 <= i__1; ++n1) {
	ns1 = ww_1.ibasis[n1 - 1];
	z1 = ccp_1.z__[ns1 - 1];
	if (z1 <= 0.f) {
	    goto L270;
	}
	if (ka_1.jsflag[ns1 - 1] > 0) {
	    goto L270;
	}
	cte1 = yy_1.cte[ns1 - 1];
	if (ns1 == tu_1.nhydr) {
	    cte1 -= eqlpp_1.om;
	}

	i__2 = *nsq;
	for (n2 = 2; n2 <= i__2; ++n2) {
	    ns2 = ww_1.ibasis[n2 - 1];
	    z2 = ccp_1.z__[ns2 - 1];
	    if (z2 >= 0.f) {
		goto L260;
	    }
	    if (ka_1.jsflag[ns2 - 1] > 0) {
		goto L260;
	    }
/*   skip the h+ and oh- pair */
	    if (ns1 != tu_1.nhydr) {
		goto L262;
	    }
	    if (s_cmp(gg_1.uspec + (ns2 - 1) * 24, uhydx, (ftnlen)8, (ftnlen)
		    8) != 0) {
		goto L262;
	    }
	    goto L260;

L262:
	    zdum = z1 - z2;
	    almean = (z1 * yy_1.actlg[ns2 - 1] - z2 * yy_1.actlg[ns1 - 1]) / 
		    zdum;
	    amean = texp_(&almean);
	    cdum = (z1 * yy_1.conclg[ns2 - 1] - z2 * yy_1.conclg[ns1 - 1]) / 
		    zdum;
	    cfree = texp_(&cdum);
	    gdum = (z1 * ccp_1.glg[ns2 - 1] - z2 * ccp_1.glg[ns1 - 1]) / zdum;
	    gfree = texp_(&gdum);
	    cte2 = yy_1.cte[ns2 - 1];
	    if (s_cmp(gg_1.uspec + (ns2 - 1) * 24, uhydx, (ftnlen)8, (ftnlen)
		    8) == 0) {
		cte2 = yy_1.cte[0] - eqlpp_1.om;
	    }
	    if (cte1 <= 0.f) {
		goto L263;
	    }
	    if (cte2 <= 0.f) {
		goto L263;
	    }
	    ctelg1 = tlg_(&cte1);
	    ctelg2 = tlg_(&cte2);
	    cdum1 = (z1 * ctelg2 - z2 * ctelg1) / zdum;
	    cstoi = texp_(&cdum1);
	    gdum1 = almean - cdum1;
	    gstoi = texp_(&gdum1);

	    io___914.ciunit = *noutpt;
	    s_wsfe(&io___914);
	    do_fio(&c__1, gg_1.uspec + (ns1 - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, gg_1.uspec + (ns2 - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&almean, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&amean, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cfree, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&gfree, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cstoi, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&gstoi, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    goto L260;
L263:
	    io___915.ciunit = *noutpt;
	    s_wsfe(&io___915);
	    do_fio(&c__1, gg_1.uspec + (ns1 - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, gg_1.uspec + (ns2 - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&almean, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&amean, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cfree, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&gfree, (ftnlen)sizeof(doublereal));
	    e_wsfe();
L260:
	    ;
	}

L270:
	;
    }
    io___916.ciunit = *noutpt;
    s_wsfe(&io___916);
    e_wsfe();

L275:

/*     print the contributions of aqueous species to each mass balance */

    if (op1_1.iopr5 <= -1) {
	goto L875;
    }
    if (op1_1.iopr5 >= 1) {
	goto L807;
    }
    io___917.ciunit = *noutpt;
    s_wsfe(&io___917);
    e_wsfe();
    goto L809;

L807:
    io___918.ciunit = *noutpt;
    s_wsfe(&io___918);
    e_wsfe();
L809:

    i__1 = *nsq;
    for (nse = 2; nse <= i__1; ++nse) {
	if (nse == *nsb) {
	    goto L870;
	}
	if (nse == tu_1.nhydr) {
	    goto L870;
	}
	jfdum = jj_1.jflag[nse - 1];
	if (jfdum == -1) {
	    goto L870;
	}
	if (jfdum == 30) {
	    goto L870;
	}
	ise = ww_1.ibasis[nse - 1];
	if (op1_1.iopr5 >= 1) {
	    goto L811;
	}
	io___919.ciunit = *noutpt;
	s_wsfe(&io___919);
	do_fio(&c__1, gg_1.uspec + (ise - 1) * 24, (ftnlen)24);
	e_wsfe();
	goto L814;

L811:
	io___920.ciunit = *noutpt;
	s_wsfe(&io___920);
	do_fio(&c__1, gg_1.uspec + (ise - 1) * 24, (ftnlen)24);
	e_wsfe();
L814:

	cdum1 = yy_1.cte[nse - 1];
	if (cdum1 == 0.f) {
	    cdum1 = 1e-20f;
	}
	cdum2 = 100.f / cdum1;
	pdum1 = 0.f;

	i__2 = *nst;
	for (ndum = 1; ndum <= i__2; ++ndum) {
	    nss = *nst + 1 - ndum;
	    ns = st_1.jsort[nss - 1];
	    cdum = csts[nse + ns * csts_dim1];
	    if (cdum == 0.f) {
		goto L820;
	    }
	    cdum3 = yy_1.conc[ns - 1];
	    cdum4 = cdum * cdum3;
	    pdum = cdum4 * cdum2;
	    pdum1 += pdum;
	    io___925.ciunit = *noutpt;
	    s_wsfe(&io___925);
	    do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&cdum3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pdum, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (pdum1 < 99.f) {
		goto L820;
	    }
	    if (op1_1.iopr5 <= 0) {
		goto L860;
	    }
L820:
	    ;
	}

L860:
	io___926.ciunit = *noutpt;
	s_wsfe(&io___926);
	do_fio(&c__1, (char *)&pdum1, (ftnlen)sizeof(doublereal));
	e_wsfe();
L870:
	;
    }

L875:

/*     compute and print the state of aqueous redox reactions */

    io___927.ciunit = *noutpt;
    s_wsfe(&io___927);
    e_wsfe();
    ahfac = eqlpp_1.farad * .001f;
    jj_1.eh = eqlpp_1.ehfac / 4.f * (cc_1.fo2lg + yy_1.actlg[tu_1.nhydr - 1] *
	     4.f - alw * 2.f - xx_1.xlkeh);
    jj_1.pe = jj_1.eh / eqlpp_1.ehfac;
    ah = ahfac * jj_1.eh;
    io___930.ciunit = *noutpt;
    s_wsfe(&io___930);
    do_fio(&c__1, (char *)&jj_1.eh, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jj_1.pe, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&cc_1.fo2lg, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ah, (ftnlen)sizeof(doublereal));
    e_wsfe();

    i__1 = *nsq;
    for (nsc = *nsb1; nsc <= i__1; ++nsc) {
	if (ka_1.jsflag[nsc - 1] >= 2) {
	    goto L350;
	}
	if (nsc > *nsq) {
	    goto L312;
	}
	if (jj_1.jflag[nsc - 1] <= -1) {
	    goto L350;
	}
L312:
	nrs = nsc - *nsb;
	cdum1 = cdrs[*nsb + nrs * cdrs_dim1];
	if (cdum1 == 0.f) {
	    goto L350;
	}
	isc = ww_1.ibasis[nsc - 1];
	s_copy(udm1, gg_1.uspec + (isc - 1) * 24, (ftnlen)24, (ftnlen)24);
	s_copy(udm2, gg_1.uspec, (ftnlen)24, (ftnlen)24);
	fdum = xx_1.xlks[nrs - 1] - cdrs[nrs * cdrs_dim1 + 1] * alw - cdrs[*
		nsq1 + nrs * cdrs_dim1] * yy_1.actlg[nsc - 1];

	i__2 = *nsq;
	for (ns = 2; ns <= i__2; ++ns) {
	    if (ns == *nsb) {
		goto L310;
	    }
	    cdum = cdrs[ns + nrs * cdrs_dim1];
	    if (cdum == 0.f) {
		goto L310;
	    }
	    if (ka_1.jsflag[ns - 1] >= 2) {
		goto L350;
	    }
	    fdum -= cdum * yy_1.actlg[ns - 1];
	    if (ns == tu_1.nhydr) {
		goto L310;
	    }
	    is = ww_1.ibasis[ns - 1];
	    s_copy(udm2, gg_1.uspec + (is - 1) * 24, (ftnlen)24, (ftnlen)24);
L310:
	    ;
	}

	fdum /= cdum1;
	edum = eqlpp_1.ehfac / 4.f * (fdum + yy_1.actlg[tu_1.nhydr - 1] * 4.f 
		- alw * 2.f - xx_1.xlkeh);
	pdum = edum / eqlpp_1.ehfac;
	adum = ahfac * edum;
	io___940.ciunit = *noutpt;
	s_wsfe(&io___940);
	do_fio(&c__1, udm1, (ftnlen)24);
	do_fio(&c__1, udm2, (ftnlen)24);
	do_fio(&c__1, (char *)&edum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pdum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fdum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&adum, (ftnlen)sizeof(doublereal));
	e_wsfe();
L350:
	;
    }

/*     compute and print the state of aqueous non-equilibrium, non-redox */
/*     reactions */

    io___941.ciunit = *noutpt;
    s_wsfe(&io___941);
    e_wsfe();
    kount = 0;

    i__1 = *nsq;
    for (nsc = *nsb1; nsc <= i__1; ++nsc) {
	if (ka_1.jsflag[nsc - 1] >= 2) {
	    goto L450;
	}
	jfdum = jj_1.jflag[nsc - 1];
	if (jfdum <= -1) {
	    goto L450;
	}
	if (jfdum == 30) {
	    goto L450;
	}
	if (jfdum == 27) {
	    goto L450;
	}
	nrs = nsc - *nsb;
	cdum = cdrs[*nsb + nrs * cdrs_dim1];
	if (cdum != 0.f) {
	    goto L450;
	}
	ise = ww_1.ibasis[nsc - 1];
	s_copy(udum1, gg_1.uspec + (ise - 1) * 24, (ftnlen)8, (ftnlen)8);
	s_copy(udum2, gg_1.uspec, (ftnlen)8, (ftnlen)8);
	++kount;
	afdum = -xx_1.xlks[nrs - 1] + cdrs[nrs * cdrs_dim1 + 1] * alw + cdrs[*
		nsq1 + nrs * cdrs_dim1] * yy_1.actlg[nsc - 1];

	i__2 = *nsq;
	for (ns = 2; ns <= i__2; ++ns) {
	    cdum = cdrs[ns + nrs * cdrs_dim1];
	    if (cdum == 0.f) {
		goto L430;
	    }
	    if (ka_1.jsflag[ns - 1] >= 2) {
		goto L450;
	    }
	    adum = yy_1.actlg[ns - 1];
	    afdum += cdum * adum;
	    if (ns == tu_1.nhydr) {
		goto L430;
	    }
	    is = ww_1.ibasis[ns - 1];
	    s_copy(udum2, gg_1.uspec + (is - 1) * 24, (ftnlen)8, (ftnlen)8);
L430:
	    ;
	}
	afdum = eqlpp_1.afcnst * afdum;
	io___944.ciunit = *noutpt;
	s_wsfe(&io___944);
	do_fio(&c__1, udum1, (ftnlen)8);
	do_fio(&c__1, udum2, (ftnlen)8);
	do_fio(&c__1, (char *)&afdum, (ftnlen)sizeof(doublereal));
	e_wsfe();
L450:
	;
    }

    if (kount <= 0) {
	io___945.ciunit = *noutpt;
	s_wsfe(&io___945);
	e_wsfe();
    }

/*     compute and print mineral saturation states.  these results */
/*     refer to the mineral dissolution reactions as they are currently */
/*     written in the cdrm array. */

/*        nsat = no. of saturations of pure minerals */
/*        ksat = no. of supersaturations of pure minerals */
/*        nxsat = no. of saturated solid-solution end-members among */
/*           solid solutions of input composition. */
/*        kxsat = no. of supersaturated end-members among the */
/*           solid solutions of input composition */
/*        nxhsat = no. of saturated end-members among the hypothetical */
/*           solid solutions */
/*        kxhsat = no. of hypothetically supersaturated solid-solution */
/*           phases */

    nsat = 0;
    nxsat = 0;
    nxhsat = 0;
    ksat = 0;
    kxsat = 0;
    kxhsat = 0;

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	aff[nm - 1] = -999.f;
	uu_1.xlqk[nm - 1] = -999.f;
	xlq = cdrm[*nsb + nm * cdrm_dim1] * cc_1.fo2lg;

	i__2 = *nsq;
	for (ns = 1; ns <= i__2; ++ns) {
	    if (ns == *nsb) {
		goto L1240;
	    }
	    cdum = cdrm[ns + nm * cdrm_dim1];
	    if (cdum == 0.f) {
		goto L1240;
	    }
	    if (ka_1.jsflag[ns - 1] >= 2) {
		goto L1265;
	    }
	    xlq += cdum * yy_1.actlg[ns - 1];
L1240:
	    ;
	}

	uu_1.xlqk[nm - 1] = xlq - xx_1.xlkm[nm - 1];
	aff[nm - 1] = eqlpp_1.afcnst * uu_1.xlqk[nm - 1];
L1265:
	;
    }

/*     print a saturation state summary for stoichiometric minerals */

    if (op1_1.iopr7 <= -1) {
	goto L950;
    }
    io___955.ciunit = *noutpt;
    s_wsfe(&io___955);
    e_wsfe();
    if (op1_1.iopr7 == 0) {
	io___956.ciunit = *noutpt;
	s_wsfe(&io___956);
	e_wsfe();
    }
    io___957.ciunit = *noutpt;
    s_wsfe(&io___957);
    e_wsfe();
    num = 0;
    kount = 0;

    i__1 = *nmt;
    for (nm = 1; nm <= i__1; ++nm) {
	if (ka_1.jmflag[nm - 1] >= 2) {
	    goto L925;
	}
	if (op1_1.iopr7 >= 1) {
	    goto L920;
	}
	if (aff[nm - 1] < -10.f) {
	    goto L925;
	}
L920:
	++num;
	++kount;
	s_copy(us + (num - 1 << 3), ublank, (ftnlen)8, (ftnlen)8);
	afdum = aff[nm - 1];
	adum = abs(afdum);
	if (adum > ps_1.tolsat) {
	    goto L922;
	}
	++nsat;
	s_copy(us + (num - 1 << 3), usat, (ftnlen)8, (ftnlen)8);
	goto L923;

L922:
	if (afdum < 0.f) {
	    goto L923;
	}
	++ksat;
	s_copy(us + (num - 1 << 3), ussat, (ftnlen)8, (ftnlen)8);
L923:
	s_copy(una + (num - 1) * 24, gg_1.umin + (nm - 1) * 24, (ftnlen)24, (
		ftnlen)24);
	xq[num - 1] = uu_1.xlqk[nm - 1];
	af[num - 1] = aff[nm - 1];
L925:
	if (num <= 0) {
	    goto L940;
	}
	if (num >= 2) {
	    goto L930;
	}
	if (nm < *nmt) {
	    goto L940;
	}
L930:
	io___963.ciunit = *noutpt;
	s_wsfe(&io___963);
	i__2 = num;
	for (n = 1; n <= i__2; ++n) {
	    do_fio(&c__1, una + (n - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&xq[n - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&af[n - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, us + (n - 1 << 3), (ftnlen)8);
	}
	e_wsfe();
	num = 0;
L940:
	;
    }

    if (kount <= 0) {
	io___965.ciunit = *noutpt;
	s_wsfe(&io___965);
	do_fio(&c__1, unone, (ftnlen)8);
	e_wsfe();
    }
L950:

    if (op_1.iopt4 == 0) {
	goto L1315;
    }
    if (op_1.iopt4 != 2) {
	goto L1495;
    }

/*     compute saturation states for input solid-solution compositions. */

    io___966.ciunit = *noutpt;
    s_wsfe(&io___966);
    e_wsfe();
    io___967.ciunit = *noutpt;
    s_wsfe(&io___967);
    e_wsfe();

    i__1 = vw_1.nxtb;
    for (nxb = 1; nxb <= i__1; ++nxb) {
	nx = vw_1.nxspec[nxb - 1];
	io___970.ciunit = *noutpt;
	s_wsfe(&io___970);
	do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	e_wsfe();
	ncpt = vv_1.ncomp[nx - 1];

	ssum = 0.f;
	i__2 = ncpt;
	for (ik = 1; ik <= i__2; ++ik) {
	    nm = an_1.nend[ik + nx * 20 - 21];
	    if (nm == 0) {
		goto L1295;
	    }
/*    skip if comp not present */
	    if (ka_1.jmflag[nm - 1] >= 2) {
		goto L1295;
	    }
	    uu_1.affx[ik + nx * 20 - 21] = -999.f;
	    xdum = uu_1.xlqk[nm - 1];
	    if (xdum <= -999.f) {
		goto L1272;
	    }
	    xlqkx = xdum + cdrm[*nsq1 + nm * cdrm_dim1] * (uu_1.xbarlg[ik + 
		    nx * 20 - 21] + vv_1.lamlg[ik + nx * 20 - 21]);
	    uu_1.affx[ik + nx * 20 - 21] = eqlpp_1.afcnst * xlqkx;
/*    add up contribution for each endmember */
	    ssum += vv_1.xbar[ik + nx * 20 - 21] * xlqkx;
L1272:
	    if ((d__1 = uu_1.affx[ik + nx * 20 - 21], abs(d__1)) <= 
		    ps_1.tolsat) {
		goto L1275;
	    }
	    goto L1280;

L1275:
	    ++nxsat;
	    io___976.ciunit = *noutpt;
	    s_wsfe(&io___976);
	    do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&xlqkx, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&uu_1.affx[ik + nx * 20 - 21], (ftnlen)
		    sizeof(doublereal));
	    e_wsfe();
	    goto L1295;

L1280:
	    if (uu_1.affx[ik + nx * 20 - 21] < 0.f) {
		goto L1285;
	    }
	    goto L1290;

L1285:
	    io___977.ciunit = *noutpt;
	    s_wsfe(&io___977);
	    do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&xlqkx, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&uu_1.affx[ik + nx * 20 - 21], (ftnlen)
		    sizeof(doublereal));
	    e_wsfe();
	    goto L1295;

L1290:
	    ++kxsat;
	    io___978.ciunit = *noutpt;
	    s_wsfe(&io___978);
	    do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&xlqkx, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&uu_1.affx[ik + nx * 20 - 21], (ftnlen)
		    sizeof(doublereal));
	    e_wsfe();
L1295:
	    ;
	}
	afss = eqlpp_1.afcnst * ssum;
	io___980.ciunit = *noutpt;
	s_wsfe(&io___980);
	e_wsfe();
	io___981.ciunit = *noutpt;
	s_wsfe(&io___981);
	do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&ssum, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&afss, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L1300: */
    }

    i__1 = vw_1.nxtb;
    for (nxb = 1; nxb <= i__1; ++nxb) {
	nx = vw_1.nxspec[nxb - 1];
	k = vv_1.jsol[nx - 1] + 1;
	io___983.ciunit = *noutpt;
	s_wsfe(&io___983);
	do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	do_fio(&c__1, gg_1.uxtype + (k - 1 << 5), (ftnlen)32);
	e_wsfe();
	io___984.ciunit = *noutpt;
	s_wsfe(&io___984);
	e_wsfe();
	ncpt = vv_1.ncomp[nx - 1];

	i__2 = ncpt;
	for (ik = 1; ik <= i__2; ++ik) {
	    nm = an_1.nend[ik + nx * 20 - 21];
	    if (nm == 0) {
		goto L1305;
	    }
	    if (ka_1.jmflag[nm - 1] >= 2) {
		goto L1305;
	    }
	    xlamda = texp_(&vv_1.lamlg[ik + nx * 20 - 21]);
	    actxlg = uu_1.xbarlg[ik + nx * 20 - 21] + vv_1.lamlg[ik + nx * 20 
		    - 21];
	    actx = texp_(&actxlg);
	    if (vv_1.xbar[ik + nx * 20 - 21] <= 1e-4) {
		io___988.ciunit = *noutpt;
		s_wsfe(&io___988);
		do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&vv_1.xbar[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&xlamda, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&actx, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&uu_1.xbarlg[ik + nx * 20 - 21], (
			ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&vv_1.lamlg[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&actxlg, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else {
		io___989.ciunit = *noutpt;
		s_wsfe(&io___989);
		do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&vv_1.xbar[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&xlamda, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&actx, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&uu_1.xbarlg[ik + nx * 20 - 21], (
			ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&vv_1.lamlg[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&actxlg, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
L1305:
	    ;
	}

/* L1310: */
    }

/*     compute hypothetical saturation states for solid solutions. */

L1495:
    io___990.ciunit = *noutpt;
    s_wsfe(&io___990);
    e_wsfe();
    io___991.ciunit = *noutpt;
    s_wsfe(&io___991);
    e_wsfe();

    i__1 = *nxt;
    for (nx = 1; nx <= i__1; ++nx) {

	if (ka_1.jxflag[nx - 1] == 4) {
	    goto L1530;
	}
	hpsat_(axx, uu_1.si, uu_1.affx, vv_1.lamlg, uu_1.xbarlg, vv_1.xbar, 
		an_1.w, xbarh, xqkx, xx_1.xlkm, uu_1.afflcx, uu_1.siss, aff, &
		eqlpp_1.al10, &cc_1.fo2lg, &hh_1.tempk, &eqlpp_1.rconst, 
		uuc_1.ussnp, gg_1.umin, an_1.nend, ka_1.jsflag, ka_1.jmflag, 
		ka_1.jxflag, vv_1.ncomp, vv_1.jsol, itracx, nsb, nsq, nsq1, &
		nnm1, iktmax, &nx, &ier, &nn, &op1_1.iopr9, &c__0, (ftnlen)24,
		 (ftnlen)24);

/*     bypass output below if ss has no components present */

	io___999.ciunit = *noutpt;
	s_wsfe(&io___999);
	e_wsfe();

	if ((real) nn >= 1.f) {
	    goto L1396;
	}
	io___1000.ciunit = *noutpt;
	s_wsfe(&io___1000);
	do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	e_wsfe();
	goto L1530;

/*     check to see if dsiplx converged ok */

L1396:
	if (ier == 0) {
	    goto L1500;
	}
	if (ier <= 3) {
	    io___1001.ciunit = *noutpt;
	    s_wsfe(&io___1001);
	    do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	    e_wsfe();
	}
	if (ier > 3) {
	    io___1002.ciunit = *noutpt;
	    s_wsfe(&io___1002);
	    do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&ier, (ftnlen)sizeof(integer));
	    e_wsfe();
	}

L1500:
	if ((d__1 = uu_1.afflcx[nx - 1], abs(d__1)) <= ps_1.tolsat) {
	    io___1003.ciunit = *noutpt;
	    s_wsfe(&io___1003);
	    do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&uu_1.siss[nx - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&uu_1.afflcx[nx - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	    ++nxhsat;
	} else if (uu_1.afflcx[nx - 1] < 0.f) {
	    io___1004.ciunit = *noutpt;
	    s_wsfe(&io___1004);
	    do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&uu_1.siss[nx - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&uu_1.afflcx[nx - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	} else {
	    io___1005.ciunit = *noutpt;
	    s_wsfe(&io___1005);
	    do_fio(&c__1, gg_1.usolx + (nx - 1) * 24, (ftnlen)24);
	    do_fio(&c__1, (char *)&uu_1.siss[nx - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&uu_1.afflcx[nx - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	    ++kxhsat;
	}

	i__2 = vv_1.ncomp[nx - 1];
	for (ik = 1; ik <= i__2; ++ik) {
	    nm = an_1.nend[ik + nx * 20 - 21];
	    if (nm == 0) {
/*     component not present */
		io___1006.ciunit = *noutpt;
		s_wsfe(&io___1006);
		do_fio(&c__1, uuc_1.ussnp + (ik + nx * 20 - 21) * 24, (ftnlen)
			24);
		e_wsfe();
	    } else {
		io___1007.ciunit = *noutpt;
		s_wsfe(&io___1007);
		do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&uu_1.si[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&uu_1.affx[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		e_wsfe();
	    }
/* L1525: */
	}

	if (vv_1.jsol[nx - 1] == 6) {
	    goto L1530;
	}
	k = vv_1.jsol[nx - 1] + 1;
	io___1008.ciunit = *noutpt;
	s_wsfe(&io___1008);
	do_fio(&c__1, gg_1.uxtype + (k - 1 << 5), (ftnlen)32);
	e_wsfe();
	io___1009.ciunit = *noutpt;
	s_wsfe(&io___1009);
	e_wsfe();
	ncpt = vv_1.ncomp[nx - 1];

	icount = 0;
	i__2 = ncpt;
	for (ik = 1; ik <= i__2; ++ik) {
	    nm = an_1.nend[ik + nx * 20 - 21];
	    if (nm == 0) {
		goto L1545;
	    }
	    if (ka_1.jmflag[nm - 1] >= 2) {
		goto L1545;
	    }
	    xlamda = texp_(&vv_1.lamlg[ik + nx * 20 - 21]);
	    actxlg = uu_1.xbarlg[ik + nx * 20 - 21] + vv_1.lamlg[ik + nx * 20 
		    - 21];
	    actx = texp_(&actxlg);
	    ++icount;

	    if (vv_1.xbar[ik + nx * 20 - 21] <= 1e-4f) {
		io___1011.ciunit = *noutpt;
		s_wsfe(&io___1011);
		do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&vv_1.xbar[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&xlamda, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&actx, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&uu_1.xbarlg[ik + nx * 20 - 21], (
			ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&vv_1.lamlg[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&actxlg, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else {
		io___1012.ciunit = *noutpt;
		s_wsfe(&io___1012);
		do_fio(&c__1, gg_1.umin + (nm - 1) * 24, (ftnlen)24);
		do_fio(&c__1, (char *)&vv_1.xbar[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&xlamda, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&actx, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&uu_1.xbarlg[ik + nx * 20 - 21], (
			ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&vv_1.lamlg[ik + nx * 20 - 21], (ftnlen)
			sizeof(doublereal));
		do_fio(&c__1, (char *)&actxlg, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }

L1545:
	    ;
	}
	if (icount == 0) {
	    io___1013.ciunit = *noutpt;
	    s_wsfe(&io___1013);
	    e_wsfe();
	}
L1530:
	;
    }
L1315:
    io___1014.ciunit = *noutpt;
    s_wsfe(&io___1014);
    do_fio(&c__1, (char *)&nsat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nxsat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nxhsat, (ftnlen)sizeof(integer));
    e_wsfe();
    io___1015.ciunit = *noutpt;
    s_wsfe(&io___1015);
    do_fio(&c__1, (char *)&ksat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&kxsat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&kxhsat, (ftnlen)sizeof(integer));
    e_wsfe();

/*     compute and print gas fugacities */
/*     these may have no absolute validity, but refer only to the */
/*     reactions as they are currently written in the cdrg arrays. */

    gases_();

    io___1016.ciunit = *noutpt;
    s_wsfe(&io___1016);
    e_wsfe();
    io___1017.ciunit = *noutpt;
    s_wsfe(&io___1017);
    e_wsfe();

    i__1 = *ngt;
    for (ng = 1; ng <= i__1; ++ng) {
	if (ka_1.jgflag[ng - 1] >= 2) {
	    goto L1325;
	}
	io___1019.ciunit = *noutpt;
	s_wsfe(&io___1019);
	do_fio(&c__1, gg_1.ugas + (ng - 1) * 24, (ftnlen)24);
	do_fio(&c__1, (char *)&fg_1.fug[ng - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fg_1.fuglg[ng - 1], (ftnlen)sizeof(doublereal))
		;
	e_wsfe();
L1325:
	;
    }

    io___1020.ciunit = *noutpt;
    s_wsfe(&io___1020);
    e_wsfe();

    return 0;
} /* scripx_ */

/* setup    last revised 08/01/87 by tjw */
/* Subroutine */ int setup_(void)
{
    /* Format strings */
    static char fmt_605[] = "(/1x,\002an undefined jflag value of \002,i5"
	    ",\002 was specified\002,\002 for \002,a18,/)";
    static char fmt_320[] = "(1x,\002----- terminating due to input errors f"
	    "lagged by\002,\002 setup -----\002)";
    static char fmt_322[] = "(\002 * input errors flagged by setup\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer ns, jfl;
    static doublereal wfs;
    static logical qstop;

    /* Fortran I/O blocks */
    static cilist io___1025 = { 0, 0, 0, fmt_605, 0 };
    static cilist io___1026 = { 0, 0, 0, fmt_320, 0 };
    static cilist io___1027 = { 0, 0, 0, fmt_322, 0 };



/*     this routine converts input csp data which are not on the */
/*     molal concentration scale to that scale. */


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
/* gg.h */
/* -------------------------------------------------------------------- */
/* hh.h */
/* ----------------------------------------------------------------------- */
/* jj.h */

/* -------------------------------------------------------------------- */
/* oo.h */
/* -------------------------------------------------------------------- */
/* op.h */
/* -------------------------------------------------------------------- */
/* un.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* ww.h */

/* -------------------------------------------------------------------- */
/* xx.h */

/* ------------------------------------------------------------------ */

/* eqlpp.h */
/* -------------------------------------------------------------------- */
    qstop = FALSE_;
    if (jj_1.tdspkg > 0.f) {
	goto L5;
    }
    if (jj_1.tdspl <= 0.f) {
	goto L5;
    }
    jj_1.tdspkg = jj_1.tdspl / jj_1.rho;
L5:
    wfs = (1e6f - jj_1.tdspkg) / 1e6f;

/*     convert input p e- value to eh */

    if (op_1.iopt1 == -2) {
	jj_1.eh = jj_1.pe * eqlpp_1.ehfac;
    }

    i__1 = tt_1.nsq;
    for (ns = 2; ns <= i__1; ++ns) {
	jfl = jj_1.jflag[ns - 1];
	if (jfl <= 0) {
	    goto L310;
	}
	if (jfl == 30) {
	    goto L310;
	}
	if (jfl == 16) {
	    goto L310;
	}
	if (jfl == 4) {
	    goto L310;
	}
	if (jfl == 10) {
	    goto L310;
	}
	if (jfl == 12) {
	    goto L310;
	}
	if (jfl == 19) {
	    goto L310;
	}
	if (jfl == 20) {
	    goto L310;
	}
	if (jfl == 21) {
	    goto L310;
	}
	if (jfl == 27) {
	    goto L310;
	}
	if (jfl != 1) {
	    goto L10;
	}

/*     convert total molarity to total molality */

	ww_1.csp[ns - 1] /= jj_1.rho * wfs;
	jj_1.jflag[ns - 1] = 0;
	goto L310;
L10:
	if (jfl != 2) {
	    goto L20;
	}

/*     convert total mg/l to total molality */

	ww_1.csp[ns - 1] = ww_1.csp[ns - 1] * .001f / (oo_1.mwtss[ns - 1] * 
		jj_1.rho * wfs);
	jj_1.jflag[ns - 1] = 0;
	goto L310;
L20:
	if (jfl != 3) {
	    goto L30;
	}

/*     convert total mg/kg solution to molality */

	ww_1.csp[ns - 1] = ww_1.csp[ns - 1] * .001f / (oo_1.mwtss[ns - 1] * 
		wfs);
	jj_1.jflag[ns - 1] = 0;
	goto L310;
L30:
	if (jfl != 5) {
	    goto L40;
	}

/*     convert free molarity to free molality */

	ww_1.csp[ns - 1] /= jj_1.rho * wfs;
	jj_1.jflag[ns - 1] = 4;
	goto L310;
L40:
	if (jfl != 6) {
	    goto L50;
	}

/*     convert free mg/l to free molality */

	ww_1.csp[ns - 1] = ww_1.csp[ns - 1] * .001f / (oo_1.mwtss[ns - 1] * 
		jj_1.rho * wfs);
	jj_1.jflag[ns - 1] = 4;
	goto L310;
L50:
	if (jfl != 7) {
	    goto L60;
	}

/*     convert free mg/kg to free mg/kg */

	ww_1.csp[ns - 1] = ww_1.csp[ns - 1] * .001f / (oo_1.mwtss[ns - 1] * 
		wfs);
	jj_1.jflag[ns - 1] = 4;
	goto L310;
L60:
	if (jfl != 8) {
	    goto L80;
	}

/*     convert cc stp gas/cc solution to free molality */

	ww_1.csp[ns - 1] = ww_1.csp[ns - 1] * 1e3f / (eqlpp_1.volg * jj_1.rho 
		* wfs);
	jj_1.jflag[ns - 1] = 4;
	goto L310;
L80:
	if (jfl != 11) {
	    goto L110;
	}

/*     convert titration alkalinity eq/l to eq/kg h20 */

	ww_1.csp[ns - 1] /= jj_1.rho * wfs;
	jj_1.jflag[ns - 1] = 10;
	goto L310;
L110:
	if (jfl != 13) {
	    goto L200;
	}

/*     convert carbonate alkalinity eq/l to eq/kg h20 */

	ww_1.csp[ns - 1] /= jj_1.rho * wfs;
	jj_1.jflag[ns - 1] = 12;
	goto L310;

L200:
	io___1025.ciunit = un_1.noutpt;
	s_wsfe(&io___1025);
	do_fio(&c__1, (char *)&jfl, (ftnlen)sizeof(integer));
	do_fio(&c__1, gg_1.uspec + (ns - 1) * 24, (ftnlen)24);
	e_wsfe();
	qstop = TRUE_;
L310:
	;
    }
    if (! qstop) {
	goto L999;
    }
    io___1026.ciunit = un_1.noutpt;
    s_wsfe(&io___1026);
    e_wsfe();
    io___1027.ciunit = un_1.nttyo;
    s_wsfe(&io___1027);
    e_wsfe();
    s_stop("", (ftnlen)0);

L999:
    return 0;
} /* setup_ */

/* sxterm   last revised 05/20/87 by rlh */
/* Subroutine */ int sxterm_(integer *nx)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static doublereal a, b, c__;
    static integer k;
    static doublereal a12, a13, a23;
    static integer ik, jk;
    static doublereal zx, zx1, zx2, zx3, fac;
    static integer ncpt;
    static doublereal term;


/*     24jul86 by tjw */

/*     this routine computes the sx(ik,jk) array which is used */
/*     in treating changing activity coefficients of solid-solution */
/*     component end members. */

/*     sx(ik,jk) is the formal partial derivative of lamlg(ik,nx) */
/*     with respect to xbar(jk,nx).  sx(ik,jk)=0 when ik=jk */
/*     because we have chosen to formally write the logarithm of the */
/*     activity coefficient of an end-member as a function solely of the */
/*     mole fractions of the other end-members. */


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
/* an.h */
/* -------------------------------------------------------------------- */
/* hh.h */
/* -------------------------------------------------------------------- */
/* tt.h */
/* -------------------------------------------------------------------- */
/* vv.h */

/* ------------------------------------------------------------------ */

/* eqlpp.h */
/* -------------------------------------------------------------------- */
    k = vv_1.jsol[*nx - 1];
    ncpt = vv_1.ncomp[*nx - 1];
    i__1 = ncpt;
    for (ik = 1; ik <= i__1; ++ik) {
	i__2 = ncpt;
	for (jk = 1; jk <= i__2; ++jk) {
	    an_1.sx[ik + jk * 20 - 21] = 0.f;
/* L2: */
	}
/* L3: */
    }

    if (k != 0) {
	goto L15;
    }

/*     ideal solution */

    goto L150;

L15:
    if (k != 1) {
	goto L25;
    }

/*     binary solution, third-order maclaurin expansion */
/*     original pathi solid solution model */

    zx = vv_1.xbar[*nx * 20 - 19];
    an_1.sx[20] = zx * zx * (-an_1.w[*nx * 20 - 19] - an_1.w[*nx * 20 - 18] * 
	    zx);
    zx = vv_1.xbar[*nx * 20 - 20];
    an_1.sx[1] = zx * zx * (-an_1.w[*nx * 20 - 19] - an_1.w[*nx * 20 - 18] + 
	    an_1.w[*nx * 20 - 18] * zx);
    goto L150;

L25:
    if (k != 2) {
	goto L35;
    }

/*     binary solution, parabolic maclaurin expansion */

    zx = vv_1.xbar[*nx * 20 - 19];
    an_1.sx[20] = an_1.w[*nx * 20 - 20] * 2.f * zx * zx;
    zx = vv_1.xbar[*nx * 20 - 20];
    an_1.sx[1] = an_1.w[*nx * 20 - 20] * 2.f * zx * zx;
    goto L150;

L35:
    if (k != 3) {
	goto L45;
    }

/*     binary solution, cubic maclaurin (p,t dependent) */

    zx = vv_1.xbar[*nx * 20 - 19];
    an_1.sx[20] = zx * zx * (an_1.w[*nx * 20 - 19] * 4.f - an_1.w[*nx * 20 - 
	    20] * 2.f + (an_1.w[*nx * 20 - 20] - an_1.w[*nx * 20 - 19]) * 6.f 
	    * zx);
    zx = vv_1.xbar[*nx * 20 - 20];
    an_1.sx[1] = zx * zx * (an_1.w[*nx * 20 - 20] * 4.f - an_1.w[*nx * 20 - 
	    19] * 2.f + (an_1.w[*nx * 20 - 19] - an_1.w[*nx * 20 - 20]) * 6.f 
	    * zx);
    goto L150;

L45:
    if (k != 4) {
	goto L55;
    }

/*     binary solution, guggenheim polynomial (t dependent) */

    zx = vv_1.xbar[*nx * 20 - 19];
    a = an_1.w[*nx * 20 - 20] * 2.f + an_1.w[*nx * 20 - 19] * 6.f + an_1.w[*
	    nx * 20 - 18] * 10.f;
    b = an_1.w[*nx * 20 - 19] * -12.f - an_1.w[*nx * 20 - 18] * 48.f;
    c__ = an_1.w[*nx * 20 - 18] * 48.f;
    an_1.sx[20] = zx * zx * (a + b * zx + c__ * zx * zx);
    zx = vv_1.xbar[*nx * 20 - 20];
    a = an_1.w[*nx * 20 - 20] * 2.f - an_1.w[*nx * 20 - 19] * 6.f + an_1.w[*
	    nx * 20 - 18] * 10.f;
    b = an_1.w[*nx * 20 - 19] * 12.f - an_1.w[*nx * 20 - 18] * 48.f;
    an_1.sx[1] = zx * zx * (a + b * zx + c__ * zx * zx);
    goto L150;

L55:
    if (k != 5) {
	goto L150;
    }

/*     ternary regular solution (prigogine and defay, p. 257) */

    a12 = an_1.w[*nx * 20 - 20];
    a13 = an_1.w[*nx * 20 - 19];
    a23 = an_1.w[*nx * 20 - 18];
    zx1 = vv_1.xbar[*nx * 20 - 20];
    zx2 = vv_1.xbar[*nx * 20 - 19];
    zx3 = vv_1.xbar[*nx * 20 - 18];
    term = (a12 - a23 + a13) * zx3 * zx2;
    an_1.sx[20] = a12 * 2.f * zx2 * zx2 + term;
    an_1.sx[40] = a13 * 2.f * zx3 * zx3 + term;
    term = (a12 - a13 + a23) * zx3 * zx1;
    an_1.sx[1] = a12 * 2.f * zx1 * zx1 + term;
    an_1.sx[41] = a23 * 2.f * zx3 * zx3 + term;
    term = (a13 - a12 + a23) * zx1 * zx2;
    an_1.sx[2] = a13 * 2.f * zx1 * zx1 + term;
    an_1.sx[22] = a23 * 2.f * zx2 * zx2 + term;
    goto L150;

L150:
    fac = 1.f / (eqlpp_1.rconst * hh_1.tempk);
    i__1 = ncpt;
    for (ik = 1; ik <= i__1; ++ik) {
	i__2 = ncpt;
	for (jk = 1; jk <= i__2; ++jk) {
	    an_1.sx[ik + jk * 20 - 21] = fac * an_1.sx[ik + jk * 20 - 21];
/* L155: */
	}
/* L160: */
    }
/* L200: */

    return 0;
} /* sxterm_ */

/* Subroutine */ int data_(void)
{
    return 0;
} /* data_ */


/* -------------------------------------------------------------------- */
/* implicit.h */
/*   standard implicit statement for 32 bit machines */
/*   for eq3/6 codes generally requiring 64 bit arithmetic */
/* -------------------------------------------------------------------- */
/* gg.h */
/* -------------------------------------------------------------------- */
/* un.h */

/* -------------------------------------------------------------------- */
/* eqlver.h */



/* Main program alias */ int eq3nr_ () { MAIN__ (); return 0; }


