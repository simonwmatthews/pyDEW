# import eq3nr

import numpy as np
import eqlibr


# NEW SEGFAULT IN GCSTS: first bit of commented out code. The issue is with qbassw.
# CODE SEEMS TO BE RANDOMLY READING SOME VARIABLES AS POINTER VALUES NOT ACTUAL VALUES...

# Segfaults also come from noutpt- change to nttyo

# THE SEGFAULT IS OCURRING IN ARRSIM

# import os
# print(eq3nr.__file__)
# print(os.getcwd())
# eq3nr.cy_main_loop()

ars = np.zeros([5*2*679])
ars[0] = 8.794
ars[10] = 7.310

amn = np.zeros([5*2*750])
ags = np.zeros([5*2*15])

cess = np.zeros([70*750])
cess[0]=1.0
cess[1]=2.0
cess[71]=1.0
cess[142]=1.0
cess[213]=1.0
cess[280]=1.0
cess[281]=1.0
cess[350]=2.0

cdrs = np.zeros([101*679])
cdrs[0] = 1.0
cdrs[1] = -1.0
cdrs[5] = -1.0
cdrs[105] = 1.0
cdrs[106] = -1.0

cdrm = np.zeros([101*750])

cdrg = np.zeros([101*15])
cdrg[4] = 1.0

# Have moved calc of csts into arrset
# csts = np.zeros([101*750])

cstor = np.zeros([2*750])
cstor[0] = 1.0
cstor[1] = 2.0
cstor[101] = 1.0
cstor[202] = 1.0
cstor[303] = 1.0
cstor[404] = 1.0
cstor[500] = 1.0
cstor[501] = 1.0
cstor[505] = -1.0
cstor[600] = 2.0
cstor[604] = 1.0
cstor[605] = -1.0
cstor[707] = 1.0
cstor[750 + 1] = 1.0
cstor[750 + 102] = 1.0
cstor[750 + 203] = 1.0
cstor[750 + 304] = 1.0
cstor[750 + 400] = 1.0
cstor[750 + 401] = 1.0
cstor[750 + 405] = -1.0
cstor[750 + 500] = 2.0
cstor[750 + 504]= 1.0
cstor[750 + 505] = -1.0
cstor[750 + 607] = 1.0
cstor[750 + 708] = 1.0


xbarlg = np.zeros([20*20])
lamlg = np.zeros([20*20])

csp = np.zeros([101])
csp[0] = 0.0
csp[1] = -5.0
csp[2] = 0.1
csp[3] = 0.1

cxistq = np.zeros([750])
cxistq[3] = 1.0

mwtss = np.zeros([750])
mwtss[0] = 18.015
mwtss[1] = 1.008
mwtss[2] = 22.99
mwtss[3] = 35.453
mwtss[4] = 0.0
mwtss[5] = 17.007
mwtss[6] = 31.999

z = np.zeros([750])
z[1] = 1.0
z[2] = 1.0
z[3] = -1.0
z[5] = -1.0

zsq2 = np.zeros([750])
zsq2[1] = 0.5
zsq2[2] = 0.5
zsq2[3] = 0.5
zsq2[5] = 0.5

titr = np.zeros([750])
titr[5] = 1.0
titr[6] = 1.0

azero = np.zeros([750])
azero[1] = 3.7
azero[2] = 3.7
azero[3] = 3.7
azero[5] = 3.7
azero[6] = -0.5

hydn = np.zeros([750])

xlkeh = np.zeros([1])
ehfac = np.zeros([1])
tempc = np.array([400.0])
tempk = np.array([400.0 + 273.15])
press = np.array([1000.0])
fo2lg = np.array([-12.6])
eh = np.array([0.0])


uspec = np.array([b' ']*18000)
uspec[0] = b'H'
uspec[1] = b'2'
uspec[2] = b'O'
uspec[24+0] = b'H'
uspec[24+1] = b'+'
uspec[48+0] = b'N'
uspec[48+1] = b'A'
uspec[48+2] = b'+'
uspec[72+0] = b'C'
uspec[72+1] = b'L'
uspec[72+3] = b'-'
uspec[96+0] = b'O'
uspec[96+1] = b'2'
uspec[96+2] = b'('
uspec[96+3] = b'G'
uspec[96+4] = b')'
uspec[120+0] = b'O'
uspec[120+1] = b'H'
uspec[120+2] = b'-'
uspec[144+0] = b'O'
uspec[144+1] = b'2'
uspec[144+2] = b'('
uspec[144+3] = b'A'
uspec[144+4] = b'Q'
uspec[144+5] = b')'


umin = np.array([b' ']*18000)
ugas = np.array([b' ']*360)
ujtype = np.array([b' ']*744)
nend = np.array([0]*400, dtype=np.int64)

jflag = np.array([0]*100, dtype=np.int64)
jflag[1] = 16

nsp = np.array([0]*100, dtype=np.int64)


nspec = np.array([0]*100, dtype=np.int64)
nspec[0] = 3
nspec[1] = 4
nspec[2] = 2

jsflag = np.array([0]*750, dtype=np.int64)
jsflag[4] = 2

jsort = np.array([0]*750, dtype=np.int64)
for i in range(len(jsort)):
    jsort[i] = i+1

# iindx1 = np.array([0]*100, dtype=np.int32)
ibswx = np.array([0]*100, dtype=np.int64)

iopt1 = 0
iopt2 = 0

iopg1 = 0

iodb1 = 0
iodb2 = 0

ntpr = 1
iacion = 4
iebal = 2
nhydr = 2
nchlor = 4
nct = 4
nsb = 5
nsb1 = 6
nsq = 5
nsqb = 3
nsq1 = 6
nst = 7
# nst = np.uint64(7) # 7
nrst = 2
nmt = 0
ngt = 1
nxt = 0
kct = 4
ksb = 0
ksq = 0
kebal = 0
kdim = 0
kmax = 100
nctmax = 70
nsqmax = 100
nsqmx1 = 101
nstmax = 750
iktmax = 20
narxmx = 5
ntprmx = 2
noutpt = 0
nttyo = 0
qbswx = True
qhydth = True
qpt4 = True
qbassw = False


ret, iindx1, ker, zvclg1, concbs, xisteq, dshm, shm, uzvec1, ir = eqlibr.cy_arrset(
                                                                        ars, amn, ags, cess, cdrs, 
                                                                        cdrm, cdrg, #csts, 
                                                                        cstor, xbarlg, 
                                                                        lamlg, csp, cxistq, mwtss, z, 
                                                                        zsq2, titr, azero, hydn,
                                                                        xlkeh, ehfac,
                                                                        tempc, 
                                                                        tempk, press, fo2lg, 
                                                                        eh, uspec, umin, ugas, ujtype, 
                                                                        nend, jflag, nsp, nspec, jsflag, jsort, 
                                                                        #iindx1, 
                                                                        ibswx, iopt1, 
                                                                        iopt2, iopg1, iodb1, iodb2, ntpr, iacion, 
                                                                        iebal, nhydr, nchlor, nct, nsb, nsb1, nsq, 
                                                                        nsqb, nsq1, nst, nrst, nmt, ngt, nxt, 
                                                                        kct, ksb, ksq, kebal, kdim, kmax,
                                                                        nctmax, nsqmax, nsqmx1, nstmax, iktmax, narxmx, 
                                                                        ntprmx, noutpt, nttyo, qhydth, qpt4,
                                                                        qbswx, qbassw,
                                                            )

# ret = eqlibr.cy_testbool(True)

# ret = eqlibr.cy_test_array_pass(np.array([1.0,2.0,3.0,4.0,5.0,6.0,7.0]))

print(ret)
print(iindx1)
print(ker)
print(type(zvclg1))


screwd = 2.0
screwn = 1.0
tolbt = 0.0 # I think these will take default values if set to zero
toldl = 0.0 # I think these will take default values if set to zero
uqdel = np.array([b' ']*8) # I don't think length matters- arbitrary value chosen
uqdel[0] = b'm' # Either moles or conc
uqdel[1] = b'o'
uqdel[2] = b'l'
uqdel[3] = b'e'
uqdel[4] = b's'
uqbeta = np.array([b' ']*8) # I don't think length matters- arbitrary value chosen
uqbeta[0] = b'm' # Either moles or conc
uqbeta[1] = b'o'
uqbeta[2] = b'l'
uqbeta[3] = b'e'
uqbeta[4] = b's'
itermx = 30
qpra = 0
qprb = 0
qprc = 0
ncarb = 0 # I don't think this is ever used in the EQ3 code


# conc = np.zeros([750]) # I am not sure this needs to be set in advance or not- trying to see if it doesn't

conc, glg, xi, = eqlibr.cy_newton(cdrs, np.array(zvclg1), 
                                cxistq, z, zsq2, 
                                azero, hydn, np.array(concbs), 
                                screwd, screwn, tolbt, toldl, tempc, press,
                                xisteq, dshm, shm, 
                                uspec, uzvec1, uqdel, uqbeta,
                                jsflag, jsort, np.array(ir), itermx,
                                iacion, kmax, kdim, nsqmx1, nsb, nsq, nst, nhydr,
                                nchlor,
                                qpra, qprb, qprc, ncarb)

print(conc)
print(glg)
print(xi)