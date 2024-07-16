c eq3nr    version 3245R110, last revised 12/26/87 by tjw                       
c*eq3nr f77 rewrite 02/23/87 by tjw                                             
c     Be sure to put the correct release and stage numbers in                   
c     in parameters urelno and ustage.                                          
c                                                                               
      program eq3nr                                                             
c                                                                               
c     This is the main program of the EQ3NR computer code, part of the          
c     EQ3/6 software package.  This computer code is copyrighted as             
c     follows-                                                                  
c                                                                               
c     Copyright (c) 1987 The Regents of the University of California,           
c     Lawrence Livermore National Laboratory. All rights reserved.              
c                                                                               
c          The person responsible for this code is                              
c                                                                               
c               Thomas J. Wolery                                                
c               L-219                                                           
c               Lawrence Livermore National Laboratory                          
c               P.O. Box 808                                                    
c               Livermore, CA  94550                                            
c               (415) 422-5789                                                  
c               FTS 532-5789                                                    
c                                                                               
c        Comments on this code are welcome.  Users are encouraged               
c     to report suspected or documented errors or other problems.               
c     LLNL maintains a mailing list of known users.  If you                     
c     are using this code, you should make it a point to have your              
c     name on it in order to receive notification of errors and                 
c     recommended fixes, announcements of new releases, and copies of           
c     future reports.                                                           
c                                                                               
c        The primary reference for this code is--                               
c                                                                               
c      Wolery, T.J., 1983, EQ3NR, A Geochemical Aqueous Speciation-             
c        Solubility Code, UCRL-53414, Lawrence Livermore National               
c        Laboratory, Livermore, California.                                     
c                                                                               
c     This report is available from LLNL as long as the supply                  
c     lasts.                                                                    
c                                                                               
c        The code is well-documented internally.  The internal                  
c     documentation is the final authority on matters pertaining                
c     to the operation of this code.  Users are advised to pay                  
c     particular attention to the comment lines in the main program             
c     and subprograms READX (reads the problem input), INDATX (reads            
c     the secondary data file called data1), and NEWTON (solves for             
c     the aqueous species distribution).                                        
c                                                                               
c        This code computes chemical models of aqueous solutions.               
c     It is similar in that function to other codes such as WATEQ               
c     and SOLMNEQ.  EQ3NR can be used by itself is the user desires             
c     only to determine aqueous speciation and fluid-mineral saturation         
c     relations.  The other usage of EQ3NR to front-end the EQ6                 
c     code, which calculates reaction-progess models, including kinetic         
c     models, of rock/water interaction.                                        
c                                                                               
c        Information is passed from  EQ3NR to EQ6 through a file called         
c     PICKUP, which EQ3NR writes after processing a problem input.              
c     PICKUP is then normally used as the bottom half of the EQ6 input          
c     file, although it can be read separately by EQ6.  If an EQ3NR             
c     run is to be used to iniitialize an EQ6 run, do not forget to             
c     save the PICKUP file.                                                     
c                                                                               
c        Solid-solution coding dealing only with molecular mixing               
c     models exists and can be activated by setting the option                  
c     parameter iopt4 to 1 or 2.                                                
c                                                                               
c        The user defines the run parameters on the file called INPUT.          
c     The file called DATA1 provides the basic supporting                       
c     thermodynamic, etc., data.  EQ3NR writes PICKUP and an output             
c     file called OUTPUT.                                                       
c                                                                               
c        The source code for EQ3NR is broken up into two files,                 
c     a .SRC file and a .INC file.  The .SRC file contains the                  
c     "source" of the main program and each subprogram.  It is                  
c     normally split into a set of .F files using the LLNL utility              
c     GETALL.  The .INC file is normally split into a set of .H files           
c     (INCLUDE files) using the LLNL utility GETINC.  Most of the .H            
c     files contain common blocks.  PARSET.H contains the majo                  
c     dimensioning parameters.  IMPLICIT.H contains the standard                
c     implicit statement (see below).                                           
c                                                                               
c        This code requires routines from the EQLIB library, which              
c     is part of the EQ3/6 package.                                             
c                                                                               
c        This code has been written for use on 32 and 64 bit machines.          
c     The standard implicit statement is located in the INCLUDE file            
c     implicit.h (part of the .INC file).                                       
c                                                                               
c     The modification history has been moved to eq3nr.his.                     
c

c     This is a modified version of the code for doing DEW calculations.

c     Contact Simon Matthews (simonm at hi.is) for more information.

c----------------------------------------------------------------------         
      include "implicit.h"                                                     
      include "parset.h"                                                        
      include "blank.h"                                                         
      include "an.h"                                                            
      include "bt.h"                                                            
      include "cc.h"                                                            
      include "ee.h"                                                            
      include "eqlver.h"                                                        
      include "fg.h"                                                            
      include "gg.h"                                                            
      include "hh.h"                                                            
      include "jj.h"                                                            
      include "ka.h"                                                            
      include "ki.h"                                                            
      include "nn.h"                                                            
      include "nx.h"                                                            
      include "oo.h"                                                            
      include "op.h"                                                            
      include "op1.h"                                                           
      include "op2.h"                                                           
      include "ps.h"                                                            
      include "si.h"                                                            
      include "st.h"                                                            
      include "te.h"                                                            
      include "ti.h"                                                            
      include "tt.h"                                                            
      include "tu.h"                                                            
      include "un.h"                                                            
      include "uu.h"                                                            
      include "vv.h"                                                            
      include "vw.h"                                                            
      include "ww.h"                                                            
      include "xx.h"                                                            
      include "yy.h"                                                            
      include "zg.h"                                                            
      include "eqldd.h"                                         
      include "eqlej.h"                                         
      include "eqlelm.h"                                        
      include "eqleps.h"                                        
      include "eqlgp.h"                                         
      include "eqlpp.h"                                         
      include "eqlsz.h"                                         
      include "eqlsza.h"                                        
      include "eqltxp.h"                                        
c                                                                               
      character*24 usave(nsqpar),utemp,unamsp                                   
      character*8 uqdel(kpar),uqbeta(kpar)                                      
c                                                                               
c     note- timear is a special array used to obtain the user and cpu           
c     times via the etime routine.  itself works on the sun 3's           
c     and ridge 32's.  it may not work on other computers.                      
c                                                                               
      real*4 timear(2)                                                          
c                                                                               
      dimension ars(narxpa,ntprpa,nrstpa),amn(narxpa,ntprpa,nmtpar),            
     $ ags(narxpa,ntprpa,ngtpar),ac2(narxpa,ntprpa,4),                          
     $ awo(narxpa,ntprpa,4),apress(narxpa,ntprpa),aadh(narxpa,ntprpa),          
     $ abdh(narxpa,ntprpa),abdot(narxpa,ntprpa),aeh(narxpa,ntprpa)              
c                                                                               
      dimension betao(kpar),delo(kpar),glgx(nstpar),cxistq(nstpar),             
     $ concbs(nsqpar)                                                           
c                                                                               
      external matrix,ncmpx,betas                                               
c                                                                               
c     screwd and screwn are under-relaxation control parameters                 
c                                                                               
      data screwd/2.0/,screwn/0.10/                                             
      data udata1/'data1   '/,uhco3/'HCO3-   '/,uco3/'CO3--   '/,               
     $     ublank/'        '/,upick1/'PICK1.  '/,unone/'NONE    '/,             
     $     uo2aq/'O2(AQ)  '/,uh2aq/'H2(AQ)  '/,uconc/'CONC    '/,               
     $     usodiu/'NA+     '/                                                   
c                                                                               
c     table limits in common arrays                                             
c                                                                               
      data uoff/'off     '/                                                     
      data nleni/80/
      data ninpts/20/                                                            
C
c     
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     get time and date                                                         
c                                                                               
CDAS      call timdat(udate0,utime0)                                                
CDAS      timear(1)=SECNDS(0.0)
c                                                                               
c     open files                                                                
c                                                                               
       call openou('output','formatted',noutpt)                                  
       call openin('data1','unformatted',nad1)                                   
       call openin('input','formatted',ninpt)                                    
c                                                                               
       call openou('inputs','formatted',ninpts)                                  
      call stripl(ninpt,ninpts,nleni)                                           
      close(ninpt)                                                              
      rewind ninpts                                                             
c                                                                               
c     print version numbers and copyright notice                                
c                                                                               
      write (noutpt,1000) urelno,ustage                                         
      write (nttyo,1000) urelno,ustage                                          
c                                                                               
 1000 format(/' EQ3NR, version ',a4,a4,//                                       
     $ '   Copyright (c) 1987 The Regents of the University of',                
     $ ' California,',/'   Lawrence Livermore National Laboratory. All',        
     $ ' rights reserved.')                                                     
c                                                                               
c     get eqlib release and stage number identification                         
c                                                                               
      call eqlib(ueqlrn,ueqlst,noutpt,nttyo,qtrue,qfalse)                       
c                                                                               
      write(noutpt,1005) utime0,udate0                                          
      write(nttyo,1005) utime0,udate0                                           
 1005 format(' Run',2(2x,a8),//)                                                
c                                                                               
c     initialize max values, array dimensions                                   
c                                                                               
      kmax = kpar                                                               
      nxmdmx = nxmdpa                                                           
      ntitmx = ntitpa                                                           
      nsqmax = nsqpar                                                           
      nstmax = nstpar                                                           
      nrstmx = nrstpa                                                           
      nmtmax = nmtpar                                                           
      ngtmax = ngtpar                                                           
      nxtmax = nxtpar                                                           
      iktmax = iktpar                                                           
      nctmax = nctpar                                                           
      nsqmx1 = nsqpa1                                                           
      iapxmx = iapxpa                                                           
      narxmx = narxpa                                                           
      ntprmx = ntprpa                                                           
c                                                                               
c     initialize some useful constants                                          
c                                                                               
c     gas constant = 1.98726 cal/mole-deg                                       
c     volume of perfect gas at stp = 22413.6 cm3                                
c     stp = 0 deg c and 1 atm pressure                                          
c     faraday constant = 23062.3 cal/equiv-volt                                 
c                                                                               
      rconst=1.98726                                                            
      volg=22413.6                                                              
      farad=23062.3                                                             
      qtxppr=.false.                                                            
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     initialize some arrays.  the label 20 is a return point for               
c     processing another problem input.                                         
c                                                                               
   20 continue                                                                  
c                                                                               
      do 410 nrs = 1,nrstmx                                                     
      do 405 ns = 1,nsqmx1                                                      
      cdrs(ns,nrs) = 0.                                                         
  405 continue                                                                  
  410 continue                                                                  
c                                                                               
      do 414 ns = 1,nstmax                                                      
      do 412 nc = 1,nctmax                                                      
      cess(nc,ns) = 0.                                                          
  412 continue                                                                  
  414 continue                                                                  
c                                                                               
      do 420 nm = 1,nmtmax                                                      
      do 415 ns = 1,nsqmx1                                                      
      cdrm(ns,nm) = 0.                                                          
  415 continue                                                                  
  420 continue                                                                  
c                                                                               
      do 430 ng = 1,ngtmax                                                      
      do 425 ns = 1,nsqmx1                                                      
      cdrg(ns,ng) = 0.                                                          
  425 continue                                                                  
  430 continue                                                                  
c                                                                               
      do 15 ns = 1,nsqmax                                                       
      csp(ns)=0.                                                                
      nsp(ns)=0                                                                 
      nspec(ns)=0                                                               
      uqdel(ns) = uconc                                                         
      uqbeta(ns) = uconc                                                        
   15 continue                                                                  
c                                                                               
      do 12 nc=1,nctmax                                                         
      jcflag(nc)=0                                                              
   12 continue                                                                  
c                                                                               
      do 1420 ns=1,nstmax                                                       
      jsort(ns)=ns                                                              
      conc(ns)=0.                                                               
      conclg(ns)=-999.                                                          
      act(ns)=0.                                                                
      actlg(ns)=-999.                                                           
      glg(ns)=0.                                                                
      azero(ns)=0.                                                              
      hydn(ns)=0.                                                               
 1420 continue                                                                  
c                                                                               
      do 7 nx=1,nxtmax                                                          
      do 3 ik=1,iktmax                                                          
      xbar(ik,nx)=0.                                                            
      xbarlg(ik,nx)=-999.                                                       
      lamlg(ik,nx)=0.                                                           
    3 continue                                                                  
    7 continue                                                                  
c                                                                               
      do 201 kcol=1,kmax                                                        
      zvclg1(kcol)=-999.                                                        
  201 continue                                                                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     read the problem input.                                                   
c                                                                               
      call readx(ninpts,qend)                                                   
c                                                                               
      if (qend) then                                                            
c                                                                               
c       get end time and date                                                   
c                                                                               
CDAS        call timdat(udate1,utime1)                                              
c                                                                               
        write (noutpt,1208) utime0,udate0,utime1,udate1                         
        write (nttyo,1208) utime0,udate0,utime1,udate1                          
 1208   format(/,10x,'start time = ',a8,2x,a8,/12x,                             
     $  'end time = ',a8,2x,a8)                                                 
c                                                                               
c       the etime call below works on sun 3's and ridge 32's.                   
c       it may not work on other machines.                                      
c 
c       timdum = SECNDS(timear(1))
		timdum = 0.0
        write (noutpt,1211) timdum                                  
        write (nttyo,1211) timdum                                   
 1211   format(/10x,'user time = ',f10.3)             
cc        timdum = etime(timear)                                                
cc        write (noutpt,1211) (timear(n), n=1,2)                                
cc        write (nttyo,1211) (timear(n), n=1,2)                                 
cc 1211   format(/10x,'user time = ',f10.3,/10x,' cpu time = ',f10.3)           
c                                                                               
        if (iodb1.eq.0) close (ninpts,status='delete')                          
        write (noutpt,1007)                                                     
        write (nttyo,1007)                                                      
 1007   format(' normal exit')                                                  
        stop                                                                    
      endif                                                                     
c                                                                               
      call gntpr(tempc,al10,rconst,farad,tempk,afcnst,                          
     $ ehfac,ntpr,iopg8)
c                                                                               
       if (iopt3.ne.-1) then                                                     
       inquire(file='pickup',opened=qop)                                         
       if (.not.qop) call openou('pickup','formatted',npkup)                     
       endif                                                                     
      if (iodb7.gt.0) then                                                      
      inquire(file='rlist',opened=qop)                                          
      if (.not.qop) call openou('rlist','formatted',nrlst)                      
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     get name of the option for estimating the activity coefficients           
c     of aqueous species                                                        
c                                                                               
      call nactop                                                               
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     read the supporting data file data1                                       
c                                                                               
      call indatx(cess,cdrs,cdrm,cdrg,cstor,ac2,awo,ars,                        
     $ amn,ags,apress,aadh,abdh,abdot,aeh,apx,xbar,xbarlg,xbarlm,               
     $ z,titr,azero,hydn,mwtss,atwt,xlkmod,tempc,press,afcnst,                  
     $ ussnp,udrxd,uspec,umin,ugas,usolx,uelem,uxmod,utitld,uredox,             
     $ nend,jflag,jcflag,ncomp,jsol,nxmod,jxmod,kxmod,iopt8,iopr1,              
     $ iodb1,nct,nsb,nsb1,nsq,nsq1,nsqb,nst,nrst,nmt,ngt,                       
     $ nxt,ist,irst,imt,igt,ntpr,nctmax,nsqmax,nsqmx1,nstmax,nmtmax,            
     $ ngtmax,nxtmax,iktmax,narxmx,ntprmx,iapxmx,noutpt,nttyo,                  
     $ nad1,nahv)                                                               
c                                                                               
c     get the indices of the hydrogen and chloride ions                         
c                                                                               
      call gspion(uspec,nst,nhydr,nchlor)                                       
c                                                                               
c     set species status flags                                                  
c                                                                               
      call flgstx(ars,amn,ags,uspec,umin,ugas,usolx,uxmod,                      
     $ jkflag,nend,jsflag,jmflag,jgflag,jxflag,jflag,ncomp,jxmod,               
     $ kxmod,iopt4,jst,jmt,jgt,jxt,nxmod,ntpr,nsb,nsq,nst,nrst,                 
     $ nmt,ngt,nxt,iktmax,narxmx,ntprmx,noutpt,nttyo)                           
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     compute the thermodynamic parameters that are functions of                
c     temperature and pressure                                                  
c                                                                               
      call evdata(tempc,press,ars,amn,ags,ac2,awo,apress,                       
     $ aadh,abdh,abdot,aeh,apx,w,xlks,xlkm,xlkg,cco2,ch2o,al10,                 
     $ rconst,ehfac,tempk,pgrid,adh,bdh,bdot,xlkeh,aphi,bt,uspec,               
     $ usolx,jsol,iopt1,iopt4,iopg1,nrst,nst,nmt,ngt,nxt,ntpr,                  
     $ narxmx,ntprmx,iktmax,iapxmx,noutpt,nttyo)                                
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
      om=1000./mwtss(1)                                                         
      omi=1./om                                                                 
      omlg=log10(om)                                                            
      shmlim = om - 1.0                                                         
c                                                                               
c     make up z*z/2  for later use                                              
c                                                                               
      do 58 ns=1,nst                                                            
      zz = z(ns)                                                                
      zsq2(ns) = zz*zz/2.                                                       
   58 continue                                                                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     if not using pitzer equations then skip next sections                     
c                                                                               
      if (iopg1.ne.1) then                                                      
	if (iopr9 .ne. 0) then                                                         
	  write (noutpt,1171)                                                          
 1171     format(' input value for iopr9 was inconsistent with iopg1 ',         
     $           'choice',/,' (activity coefficient selection).  '              
     $           'therefore, iopr9 was reset to 0')                             
	  iopr9 = 0                                                                    
	endif                                                                          
	go to 57                                                                       
      endif                                                                     
c                                                                               
c     read the pitzer parameters.  note that this call must follow              
c     call to indatx                                                            
c                                                                               
      call inupt(uspec,jsflag,nad1,nst,iopr9)                                   
c                                                                               
      if (iopt8 .eq. 1) then                                                    
        call getlu(nahv,nerr)                                                   
        if (nerr .ne. 0) then                                                   
          write(nttyo,1181)                                                     
 1181     format(' * no lu available')                                          
          stop                                                                  
        endif                                                                   
        open(nahv,file='ahv',status='old',err=904)                              
        go to 62                                                                
c                                                                               
  904   write(nttyo,1191)                                                       
 1191   format(' * error opening ahv')                                          
        stop                                                                    
      endif                                                                     
   62 continue                                                                  
c                                                                               
      write (noutpt,1010)                                                       
 1010 format(' --- pitzer data has been successfully read from',                
     $   ' file data1 ---')                                                     
c                                                                               
c     build s-lambda index arrays                                               
c                                                                               
      call bdslx(nst)                                                           
c                                                                               
c     build mu index arrays                                                     
c                                                                               
      call bdmlx(nst)                                                           
c                                                                               
   57 continue                                                                  
c                                                                               
c              read in hkf data if iopg1 = 5                                    
      if (iopg1 .eq. 5) call hkfrd(uspec,jsflag,nad1,nst)                       
c                                                                               
c     get charge constants                                                      
c                                                                               
      call zsrt(z,nst,jsflag,izm,izoff)                                         
c                                                                               
c     set zero charge values of e-lambda sums to zero                           
c                                                                               
      selm(izoff) = 0.                                                          
      selmp(izoff) = 0.                                                         
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     check default redox constraints for conflicts                             
c                                                                               
      isb=0                                                                     
      do 101 ns=1,nsqb                                                          
      is=nspec(ns)                                                              
      if (is.eq.nsb) then                                                       
        isb=ns                                                                  
        go to 102                                                               
      endif                                                                     
  101 continue                                                                  
  102 continue                                                                  
c                                                                               
      jfdum=jflag(nsb)                                                          
      if (iopt1.ne.-3 .and. jfdum.ne.0) then                                    
        write (noutpt,104)                                                      
  104   format(1x,'----- conflicting redox options -----')                      
        write (noutpt,123) iopt1,jfdum                                          
  123   format(/6x,'iopt1 = ',i2,' overrides jflag(o2(g)) = ',i2,/)             
        jflag(nsb)=0                                                            
        csp(nsb)=-999.                                                          
        nsp(nsb)=0                                                              
        jflagb(isb)=0                                                           
        cspb(isb)=-999.                                                         
        uphas1(nsb)=ublank                                                      
        uphas2(nsb)=ublank                                                      
      endif                                                                     
c                                                                               
      if (iopt1.ne.1 .and. uredox(1:8).ne.ublank(1:8)) then                     
        write (noutpt,104)                                                      
        write (noutpt,127) iopt1,uredox                                         
  127   format(/6x,'iopt1 = ',i2,' overrides uredox = ',a16,/)                  
        uredox=ublank                                                           
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     set default values                                                        
c                                                                               
      if (itermx .le. 0) itermx = 30                                            
      if (rho .eq. 0.) rho = 1.0000                                             
      if (tdspkg .lt. 0.) tdspkg = 0.                                           
      if (tdspl .lt. 0.) tdspl = 0.                                             
      if (tolbt .le. 0.) tolbt = 1.e-6                                          
      if (toldl .le. 0.) toldl = 1.e-6                                          
      if (tolsat .le. 0.) tolsat = 0.5                                          
      tolxat = tolsat*0.1                                                       
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     print an echo of the processed card data on the aqueous solution          
c                                                                               
      call echox                                                                
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     call routine setup to convert concentration data not on                   
c     the molal scale to that scale.                                            
c                                                                               
      call setup                                                                
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     find the index of the species (na+ or cl-) that is to define the          
c     equivalent stoichiometric ionic strength of a sodium chloride             
c     solution.  choose one if necessary.                                       
c                                                                               
      iacion=0                                                                  
      if (iopg1.ne.0) go to 239                                                 
      utemp=unone                                                               
      udum1=unone                                                               
      udum2=ublank                                                              
      cdum1 = 0.                                                                
      cdum2 = 0.                                                                
c                                                                               
      if (uacion(1:8).eq.ublank) go to 233                                      
      nsodiu = 0                                                                
      do 208 ns = 2,nst                                                         
      if (uspec(ns)(1:8) .eq. usodiu(1:8)) then                                 
        nsodiu = ns                                                             
        go to 210                                                               
      endif                                                                     
  208 continue                                                                  
  210 if (nsodiu .gt. 0) then                                                   
        cdum1=csp(nsodiu)                                                       
        jfdum=jflag(nsodiu)                                                     
        if (jfdum.ne.0) cdum1=0.                                                
        if (ibasis(nsodiu).ne.nsodiu) cdum1=0.                                  
      endif                                                                     
c                                                                               
      if (nchlor .gt. 0) then                                                   
        cdum2=csp(nchlor)                                                       
        jfdum=jflag(nchlor)                                                     
        if (jfdum.ne.0) cdum2=0.                                                
        if (ibasis(nchlor).ne.nchlor) cdum2=0.                                  
      endif                                                                     
c                                                                               
      if (cdum1.le.0.and.cdum2.le.0) go to 233                                  
      if (uacion(1:8).eq.upick1) go to 357                                      
c                                                                               
      if (uacion(1:8).eq.uspec(nsodiu)(1:8)) then                               
        if (cdum1.le.0.) go to 357                                              
        iacion=nsodiu                                                           
        go to 360                                                               
      elseif (uacion(1:8).eq.uspec(nchlor)(1:8)) then                           
        if (cdum2.le.0.) go to 357                                              
        iacion=nchlor                                                           
        go to 360                                                               
      endif                                                                     
c                                                                               
c     try to pick an ion.                                                       
c                                                                               
  357 iacion=nsodiu                                                             
      if (cdum1.lt.cdum2) iacion=nchlor                                         
  360 utemp=uspec(iacion)                                                       
  233 uacion=utemp                                                              
      write (noutpt,235) utemp                                                  
  235 format(/1x,'the ion that defines equiv. stoich. ionic strength',          
     $ /1x'  is ',a24,/)                                                        
c                                                                               
  239 continue                                                                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     find the index of the species to be adjusted for electrical               
c     balance, if any.  choose one if necessary.                                
c                                                                               
      iebal=0                                                                   
      if (uebal(1:8).eq.ublank(1:8)) go to 387                                  
      if (uebal(1:8).eq.unone(1:8)) go to 387                                   
      if (uebal(1:8).eq.upick1(1:8)) go to 370                                  
c                                                                               
      do 857 ns=2,nsq                                                           
      if (uebal(1:18).eq.uspec(ns)(1:18)) then                                  
        iebal=ns                                                                
        go to 858                                                               
      endif                                                                     
  857 continue                                                                  
c                                                                               
      write (noutpt,853) uebal                                                  
  853 format(' --- ',a24,' specified for electrical balancing',                 
     $ /3x,'is not in the master set ---',/)                                    
      go to 370                                                                 
c                                                                               
c        does the ion selected for electrical balancing have charge             
c                                                                               
  858 if (z(iebal).eq.0.) then                                                  
        write (noutpt,870) uebal                                                
  870   format(/' --- ',a24,' specified for electrical balancing',              
     $  /3x,'has no charge ---',/)                                              
        go to 370                                                               
      endif                                                                     
c                                                                               
c        is the ion selected for electrical balancing in the model              
c                                                                               
      if (jsflag(iebal).le.0) go to 385                                         
      write (noutpt,874) uebal                                                  
  874 format(/' --- ',a24,' specified for electrical balancing',                
     $ /3x,'is not in the model ---',/)                                         
c                                                                               
c        pick an ion for electrical balancing.                                  
c                                                                               
  370 write (noutpt,852)                                                        
  852 format(/,' picking an ion for electrical balancing',/)                    
      iebal=0                                                                   
      charge=0.                                                                 
      do 380 ns=1,nsq                                                           
      if (jflag(ns).ne.0) go to 380                                             
      zdum=z(ns)                                                                
      if (zdum.eq.0.) go to 380                                                 
      if (ns.ne.ibasis(ns)) go to 380                                           
      cdum=csp(ns)                                                              
      if (cdum.le.0.) go to 380                                                 
      charg1=abs(cdum*zdum)                                                     
      if (charg1.gt.charge) then                                                
        charge=charg1                                                           
        iebal=ns                                                                
      endif                                                                     
  380 continue                                                                  
c                                                                               
      if (iebal.le.0) then                                                      
        write (noutpt,880)                                                      
  880   format(/1x,'--- no such ion was selected ---',/)                        
        go to 387                                                               
      else                                                                      
        uebal=uspec(iebal)                                                      
      endif                                                                     
c                                                                               
  385 continue                                                                  
c                                                                               
      write (noutpt,255) uebal                                                  
  255 format(' electrical balance will be achieved by adjusting',               
     $ /'   the concentration of ',a24,/)                                       
c                                                                               
  387 continue                                                                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c       temporary fix pending incorporation of the auxiliary basis              
c         concept into eq6.  save the names of the basis species as they        
c         were read off the data file.                                          
      do 505 ns=1,nsq                                                           
      usave(ns)=uspec(ns)                                                       
  505 continue                                                                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     call routine switch to perform basis switching.  at this point            
c     (before the call to routine elim) do only those switches which            
c     pair a species in the strict basis with a species in the auxiliary        
c     basis.  the other switches are executed after the call to                 
c     routine elim.  the species h2o, h+, and uacion (na+ or cl-)               
c     can not be switched.                                                      
c                                                                               
c     a switch that pairs a strict basis species with an auxiliary              
c     basis species is termed discretionary if the jflag of the                 
c     species that ends up in the auxiliary basis is not 30.                    
c     discretionary switches are forgotten as soon as they are                  
c     executed (i.e., the record in the ibasis array is wiped                   
c     clean).  the record of all other switches is maintained.                  
c                                                                               
      if (iodb7 .ge. 1)                                                         
     $ call echolk(1,nrlst,tempc,press,cdrs,cdrm,cdrg,ars,                      
     $ amn,ags,xlks,xlkm,xlkg,uspec,umin,ugas,jsflag,jmflag,                    
     $ jgflag,nsb,nsq,nsq1,nrst,nst,nmt,ngt,nxt,ntpr,nsqmx1,                    
     $ narxmx,ntprmx)                                                           
c                                                                               
      qbassw=.false.                                                            
      nerr=0                                                                    
      do 1160 ns1=2,nsq                                                         
      ns2=ibasis(ns1)                                                           
      if (ns2.gt.nsq) go to 1160                                                
      if (ns2.le.ns1) go to 1160                                                
      call switch(ns1,ns2,3,ars,amn,ags,cess,cdrs,cdrm,                         
     $ cdrg,cxistq,mwtss,z,zsq2,titr,azero,hydn,csp,uspec,jflag,                
     $ jsflag,ibasis,nsp,iopg1,iacion,iebal,nhydr,nchlor,nct,nsb,               
     $ nsq,nsq1,nst,nrst,nmt,ngt,nctmax,nsqmx1,narxmx,ntprmx,nerr,              
     $ noutpt,nttyo,qhydth,qpt4,qbassw)                                         
c                                                                               
      jdum=jsflag(ns1)                                                          
      jsflag(ns1)=jsflag(ns2)                                                   
      jsflag(ns2)=jdum                                                          
      cdum=cstor(ns1,1)                                                         
      cstor(ns1,1)=cstor(ns2,1)                                                 
      cstor(ns2,1)=cdum                                                         
      cdum=cstor(ns1,2)                                                         
      cstor(ns1,2)=cstor(ns2,2)                                                 
      cstor(ns2,2)=cdum                                                         
      if (jflag(ns2).eq.30) go to 1160                                          
      ibasis(ns1)=ns1                                                           
      ibasis(ns2)=ns2                                                           
 1160 continue                                                                  
      if (iebal .ne. 0) iebal = ibasis(iebal)                                   
c                                                                               
      if (nerr.gt.0) then                                                       
        write (noutpt,257)                                                      
        write (nttyo,257)                                                       
  257   format(' * error- terminating due to basis switching errors')           
        stop                                                                    
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     print a list of inactive species                                          
c                                                                               
      write (noutpt,240)                                                        
  240 format(/21x,'--- inactive aqueous species ---',/)                         
      ns3=0                                                                     
      unam24(1)=unone                                                           
c                                                                               
      do 220 ns=1,nst                                                           
      jdum=jsflag(ns)                                                           
      if (jdum.ge.3) go to 220                                                  
      if (jdum.le.0) go to 220                                                  
      if (ns.eq.nsb) go to 220                                                  
      ns3=ns3+1                                                                 
      unam24(ns3)=uspec(ns)                                                     
      if (ns3.eq.4) then                                                        
        write (noutpt,222) (unam24(n), n=1,ns3)                                 
  222   format(4(2x,a24))                                                       
        ns3=0                                                                   
      endif                                                                     
  220 continue                                                                  
c                                                                               
      if (ns3.gt.0) write (noutpt,222) (unam24(n), n=1,ns3)                     
      write (noutpt,223)                                                        
  223 format(1x)                                                                
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     if iopt1.ge.1, find the index of the reaction associated with             
c     the species whose name is uredox.                                         
c                                                                               
      if (iopt1.ge.1) then                                                      
        do 2225 ns=nsb1,nsq                                                     
        if (uspec(ns)(1:18).eq.uredox(1:18)) then                               
          iopt1=ns-nsb                                                          
          go to 2200                                                            
        endif                                                                   
 2225   continue                                                                
c                                                                               
        write (noutpt,2226) uredox                                              
        write (nttyo,2226) uredox                                               
 2226   format(' * error- 'a24,' (for default redox couple) is not',            
     $  /'   in the auxiliary basis')                                           
        stop                                                                    
      endif                                                                     
 2200 continue                                                                  
c                                                                               
c     check to see that no species in the strict basis has a jflag              
c     value of 30 at this point.                                                
c                                                                               
      nerr=0                                                                    
      do 1250 ns=1,nsb                                                          
      if (jflag(ns).eq.30) then                                                 
        write (noutpt,1245) uspec(ns),jflag(ns)                                 
        write (nttyo,1245) uspec(ns),jflag(ns)                                  
 1245   format(' * error-- the strict basis species ',a24,                      
     $  /,' has an illegal jflag value of ',i2)                                 
        nerr=nerr+1                                                             
      endif                                                                     
 1250 continue                                                                  
c                                                                               
      if (nerr .ge. 1) then                                                     
        write (noutpt,1002)                                                     
        write (nttyo,1002)                                                      
 1002   format(' * error- nerr= ',i4)                                           
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     call routine elim to rewrite the reaction equations (cdr-                 
c     arrays) so that auxiliary basis variables with jflag=30                   
c     are eliminated in all reactions except cross-link reactions.              
c                                                                               
      qelim = .false.                                                           
      do 1257 nse=nsb1,nsq                                                      
      if (jflag(nse).eq.30) then                                                
        if (jsflag(nse).gt.0) then                                              
          csp(nse)=0.                                                           
        else                                                                    
          qelim = .true.                                                        
          call elim(nse,ars,amn,ags,cdrs,cdrm,cdrg,eps100,                      
     $    nsb,nsq1,nrst,nmt,ngt,nsqmx1,narxmx,ntprmx,noutpt,nttyo)              
        endif                                                                   
      endif                                                                     
 1257 continue                                                                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     call routine switch to perform basis switching.  at this point            
c     do those switches which bring non-basis species into the expanded         
c     basis.                                                                    
c                                                                               
      nerr=0                                                                    
      do 1260 ns1=2,nsq                                                         
      ns2=ibasis(ns1)                                                           
      if (ns2.gt.nsq .and. ns2.gt.ns1) then                                     
        call switch(ns1,ns2,3,ars,amn,ags,cess,cdrs,cdrm,                       
     $  cdrg,cxistq,mwtss,z,zsq2,titr,azero,hydn,csp,uspec,jflag,               
     $  jsflag,ibasis,nsp,iopg1,iacion,iebal,nhydr,nchlor,nct,nsb,              
     $  nsq,nsq1,nst,nrst,nmt,ngt,nctmax,nsqmx1,narxmx,ntprmx,nerr,             
     $  noutpt,nttyo,qhydth,qpt4,qbassw)                                        
c                                                                               
        ibasis(ns2)=ns1                                                         
      endif                                                                     
 1260 continue                                                                  
c                                                                               
      if (nerr.gt.0) then                                                       
        write (noutpt,257)                                                      
        write (nttyo,257)                                                       
        stop                                                                    
      endif                                                                     
c                                                                               
      if (iodb7 .ge. 1)                                                         
     $ call echolk(1,nrlst,tempc,press,cdrs,cdrm,cdrg,ars,                      
     $ amn,ags,xlks,xlkm,xlkg,uspec,umin,ugas,jsflag,jmflag,                    
     $ jgflag,nsb,nsq,nsq1,nrst,nst,nmt,ngt,nxt,ntpr,nsqmx1,                    
     $ narxmx,ntprmx)                                                           
c                                                                               
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     echo input data after modification.                                       
c                                                                               
      write (noutpt,1100)                                                       
 1100 format(//32x,'--- modified input constraints ---',                        
     $ //5x,'species          csp       jflag ',                                
     $ ' type of input      controlling phase',/)                               
      do 1150 nse=2,nsq                                                         
      jk=jflag(nse)                                                             
      if (jk.lt.0) then                                                         
        if (nse.le.nct) go to 1150                                              
        nrs=nse-nsb                                                             
        do 305 ns=2,nsq                                                         
        if (cdrs(ns,nrs).ne.0.) then                                            
          if (jflag(ns).le.-1) go to 1150                                       
        endif                                                                   
  305   continue                                                                
      endif                                                                     
c                                                                               
      cdum=csp(nse)                                                             
      k=jk+1                                                                    
      if (jk.eq.19) then                                                        
        nm=nsp(nse)                                                             
        write (noutpt,1105) uspec(nse),cdum,jk,ujtype(k),umin(nm)               
 1105   format(3x,a24,3x,e12.5,3x,i2,3x,a24,3x,a24)                             
        unamsp = umin(nm)                                                       
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                
c                                                                               
        go to 1150                                                              
      endif                                                                     
c                                                                               
      if (jk.eq.20) then                                                        
        ndum=nsp(nse)                                                           
        ndum=ndum-50000                                                         
        nx=int(ndum/100.)                                                       
        ik=ndum-100*nx                                                          
        nm=nend(ik,nx)                                                          
        write (noutpt,1105) uspec(nse),cdum,jk,ujtype(k),usolx(nx)              
        unamsp = umin(nm)                                                       
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                
        go to 1150                                                              
      endif                                                                     
c                                                                               
      if (jk.eq.21) then                                                        
        ng=nsp(nse)                                                             
        write (noutpt,1105) uspec(nse),cdum,jk,ujtype(k),ugas(ng)               
        unamsp = ugas(ng)                                                       
        call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,noutpt)                
        write (noutpt,1105) uspec(nse),cdum,jk,ujtype(k)                        
        go to 1150                                                              
      endif                                                                     
c                                                                               
      if (nse.ne.nsb) then                                                      
        if (k.gt.0) then                                                        
          write (noutpt,1105) uspec(nse),cdum,jk,ujtype(k)                      
          go to 1150                                                            
        else                                                                    
          write (noutpt,315) uspec(nse)                                         
  315     format(3x,a24,23x,'not present in the model')                         
        endif                                                                   
      endif                                                                     
c                                                                               
 1150 continue                                                                  
c                                                                               
      write (noutpt,317)                                                        
  317 format(//,1x)                                                             
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     call lamda to compute activity coefficients of solid-solution             
c     end-members.                                                              
c                                                                               
      if (iopt4.eq.2) then                                                      
        do 363 nx=1,nxt                                                         
        call lamda(al10,jsol,lamlg,ncomp,nx,rconst,tempk,xbar,w,                
     $  iktmax)                                                                 
  363   continue                                                                
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     the following section is an attempt at idiot-proofing.  it is             
c     intended to catch the most likely errors that users are likely to         
c     make and thus spare the author of this code the blame).  idiots           
c     are generally creative, however.  there is no guarantee that              
c     the following section will flag all bad input.                            
c                                                                               
c     nwarn accumulates the no. of errors.  if nwarn has a final value          
c     which is not zero, the computation is terminated.                         
c                                                                               
      nwarn=0                                                                   
c                                                                               
c     if using hydration theory, are there any non-zero hydration               
c     numbers                                                                   
c                                                                               
      if (qhydth) then                                                          
        do 367 ns=2,nst                                                         
        if (hydn(ns).gt.0.) go to 368                                           
  367   continue                                                                
        write (noutpt,366)                                                      
        write (nttyo,366)                                                       
  366   format(' * error- use of hydration theory with no',                     
     $  ' non-zero hydration numbers')                                          
        nwarn=nwarn+1                                                           
      endif                                                                     
  368 continue                                                                  
c                                                                               
c     check the iopt1.eq.-3 option for the needed input constraints.            
c                                                                               
      if (iopt1.eq.-3) then                                                     
        jfdum=jflag(nsb)                                                        
        if (jfdum.ne.19 .and. jfdum.ne.20 .and. jfdum.ne.21) then               
          write (noutpt,2009)                                                   
          write (nttyo,2009)                                                    
 2009     format(' * error- iopt1.eq.-3 but jflag is not',                      
     $    ' 19, 20, or 21')                                                     
          nwarn=nwarn+1                                                         
          go to 2020                                                            
        endif                                                                   
      endif                                                                     
c                                                                               
c     check the iopt1.ge.1 option to make sure it implies a redox               
c     reaction                                                                  
c                                                                               
      if (iopt1.le.0) go to 2020                                                
c                                                                               
      ns=iopt1+nsb                                                              
      if (cdrs(nsb,iopt1).eq.0.) then                                           
        write (noutpt,2015) uredox                                              
        write (nttyo,2015) uredox                                               
 2015   format(' * error- ',a16,' specifies redox control',                     
     $   ' by a non-redox reaction')                                            
        unamsp = uspec(ns)                                                      
        call prreac(cdrs,uspec,unamsp,iopt1,nsq,nsq1,nsqmx1,noutpt)             
        call prreac(cdrs,uspec,unamsp,iopt1,nsq,nsq1,nsqmx1,nttyo)              
        nwarn=nwarn+1                                                           
      endif                                                                     
c                                                                               
c     check for the needed input constraints on the iopt1.ge.1 option.          
c                                                                               
      if (jflag(ns).lt.16) then                                                 
        if (csp(ns).gt.0.) go to 1290                                           
        write (noutpt,1281) uspec(ns)                                           
        write (nttyo,1281) uspec(ns)                                            
 1281   format(' * error- there is no ',a24,                                    
     $   ' in the system to define a redox couple')                             
        nwarn=nwarn+1                                                           
        go to 1290                                                              
      endif                                                                     
c                                                                               
      if (jflag(ns).eq.27 .or. jflag(ns).eq.30) then                            
        write (noutpt,1283) uspec(ns),jflag(ns)                                 
 1283   format(' * error- redox couple species ',a24,' has illegal ',           
     $  /'     jflag value of ',i2)                                             
        nwarn=nwarn+1                                                           
      endif                                                                     
c                                                                               
 1290 continue                                                                  
c                                                                               
      udum1=uspec(ns)(1:8)                                                      
      if (udum1.ne.uo2aq .and. udum1.ne.uh2aq) then                             
        do 1292 ns=2,nct                                                        
        if (ns.ne.nhydr) then                                                   
          if (cdrs(ns,iopt1).ne.0.) go to 1294                                  
        endif                                                                   
 1292   continue                                                                
c                                                                               
        write (noutpt,1293)                                                     
        write (nttyo,1293)                                                      
 1293   format(' * error- can not find the strict basis species for ',          
     $  /'     the cross-link reaction specified by uredox')                    
        nwarn=nwarn+1                                                           
        go to 2020                                                              
c                                                                               
 1294   if (jflag(ns).lt.16 .and. csp(ns).le.0.) then                           
          write (noutpt,1281) uspec(ns)                                         
          write (nttyo,1281) uspec(ns)                                          
          nwarn=nwarn+1                                                         
        endif                                                                   
      endif                                                                     
 2020 continue                                                                  
c                                                                               
c     check some jflag, csp, nsp combinations                                   
c                                                                               
      do 2090 ns=2,nsq                                                          
      jk=jflag(ns)                                                              
c                                                                               
c     check for negative values for non-negative csp quantities                 
c                                                                               
      if (jk.le.15) then                                                        
        if (csp(ns).lt.0. .and. ns.ne.nsb) then                                 
          write (noutpt,2025) uspec(ns),csp(ns)                                 
          write (nttyo,2025) uspec(ns),csp(ns)                                  
 2025     format(' * error- illegal negative csp value for ',a24,               
     $    ' = ',e13.6)                                                          
          nwarn=nwarn+1                                                         
        endif                                                                   
      endif                                                                     
c                                                                               
c     check for alkalinity constraint on a species other than hco3-             
c     or co3--                                                                  
c                                                                               
      if (jk.eq.10 .or. jk.eq.12) then                                          
        if (uspec(ns)(1:8).ne.uhco3 .and. uspec(ns)(1:8).ne.uco3) then          
          write (noutpt,2035) uspec(ns)                                         
          write (nttyo,2035) uspec(ns)                                          
 2035     format(' * error- illegal alkalinity constraint on ',a24,             
     $    /'     this option only works for hco3- or co3--')                    
          nwarn=nwarn+1                                                         
        endif                                                                   
      endif                                                                     
c                                                                               
c     check for nsp values for heterogeneous reaction constraints.              
c                                                                               
      if (jk.eq.19) then                                                        
        nm=nsp(ns)                                                              
        if (cdrm(ns,nm).eq.0. .or. jmflag(nm).gt.0) then                        
          write (noutpt,407) uspec(ns)                                          
          write (nttyo,407) uspec(ns)                                           
  407     format(' * error-',a24,' can not be constrained by the ',             
     $    /'     following reaction-',/)                                        
          unamsp = umin(nm)                                                     
          call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)              
          call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,nttyo)               
          nwarn=nwarn+1                                                         
        endif                                                                   
        go to 2050                                                              
      endif                                                                     
c                                                                               
      if (jk.eq.20) then                                                        
        ndum=nsp(ns)                                                            
        if (iopt4.ne.2) then                                                    
          write (noutpt,2047) uspec(ns),iopt4                                   
          write (nttyo,2047) uspec(ns),iopt4                                    
 2047     format(' * error- ',a24,' can not be constrained by a ',              
     $    /'     solid-solution equilibrium because iopt4 = ',i2,               
     $    ', not 2')                                                            
          nwarn=nwarn+1                                                         
          go to 2050                                                            
        endif                                                                   
        ndum=ndum-50000                                                         
        nx=int(ndum/100.)                                                       
        ik=ndum-100*nx                                                          
        nm=nend(ik,nx)                                                          
        if (cdrm(ns,nm).eq.0. .or. jmflag(nm).gt.0) then                        
          write (noutpt,407) uspec(ns)                                          
          write (nttyo,407) uspec(ns)                                           
          unamsp = umin(nm)                                                     
          call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)              
          call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,nttyo)               
          nwarn=nwarn+1                                                         
        endif                                                                   
        go to 2050                                                              
      endif                                                                     
c                                                                               
      if (jk.eq.21) then                                                        
        ng=nsp(ns)                                                              
        if (cdrg(ns,ng).eq.0. .or. jgflag(ng).gt.0) then                        
          write (noutpt,407) uspec(ns)                                          
          write (nttyo,407) uspec(ns)                                           
          unamsp = ugas(ng)                                                     
          call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,noutpt)              
          call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,nttyo)               
          nwarn=nwarn+1                                                         
        endif                                                                   
      endif                                                                     
c                                                                               
 2050 continue                                                                  
c                                                                               
c     check for illegal 27 or 30 jflag value in the strict basis                
c                                                                               
      if (jk.eq.27 .or. jk.eq.30) then                                          
        if (ns.le.nsb) then                                                     
          write (noutpt,2055) uspec(ns),jk                                      
          write (nttyo,2055) uspec(ns),jk                                       
 2055     format(' * error- bad jflag value for ',a24,' = ',i3)                 
          nwarn=nwarn+1                                                         
        endif                                                                   
      endif                                                                     
c                                                                               
 2090 continue                                                                  
c                                                                               
c     check to see that a heterogeneous reaction constraint has                 
c     not been applied more than once.                                          
c                                                                               
      do 2092 ns=1,nsq                                                          
      jk=jflag(ns)                                                              
      if (jk.ne.19 .and. jk.ne.20 .and. jk.ne.21) go to 2092                    
      do 2091 ns2=1,nsq                                                         
      if (ns.eq.ns2) go to 2091                                                 
      jk2=jflag(ns2)                                                            
      if (jk2.ne.19 .and. jk.ne.20 .and. jk2.ne.21) go to 2091                  
      if (jk .ne. jk2) go to 2091                                               
      if (nsp(ns) .ne. nsp(ns2)) go to 2091                                     
      write (noutpt,2093)                                                       
      write (nttyo,2093)                                                        
 2093 format(' * error- the following heterogeneous reaction',                  
     $ 'constraint has been used more than once-',/)                            
      if (jk .eq. 19) then                                                      
        nm = nsp(ns)                                                            
        unamsp = umin(nm)                                                       
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,nttyo)                 
      elseif (jk .eq. 20) then                                                  
        nloc=nsp(ns)                                                            
        nloc=nloc-50000                                                         
        nx=int(nloc/100.)                                                       
        ik=nloc-100*nx                                                          
        nm=nend(ik,nx)                                                          
        unamsp = umin(nm)                                                       
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,nttyo)                 
      elseif (jk .eq. 21) then                                                  
        ng = nsp(ns)                                                            
        unamsp = ugas(ng)                                                       
        call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,noutpt)                
        call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,nttyo)                 
      endif                                                                     
      nerr=nerr+1                                                               
      go to 2092                                                                
 2091 continue                                                                  
c                                                                               
 2092 continue                                                                  
c                                                                               
c     check to see that jflag(nsb) .ne. 19, 20, or 21 unless                    
c     iopt1.eq.-3                                                               
c                                                                               
      if (iopt1.ne.-3) then                                                     
        jfdum=jflag(nsb)                                                        
        if (jfdum.eq.19) then                                                   
          write (noutpt,2003) jfdum                                             
          write (nttyo,2003) jfdum                                              
 2003     format(' * error- jflag(o2(g) = ',i2,' but iopt1 is not 0')           
          nwarn=nwarn+1                                                         
        elseif (jfdum.eq.20) then                                               
          write (noutpt,2003) jfdum                                             
          write (nttyo,2003) jfdum                                              
          nwarn=nwarn+1                                                         
        elseif (jfdum.eq.21) then                                               
          write (noutpt,2003) jfdum                                             
          write (nttyo,2003) jfdum                                              
          nwarn=nwarn+1                                                         
        endif                                                                   
      endif                                                                     
c                                                                               
      if (nwarn.ge.1) then                                                      
        write (noutpt,450) nwarn                                                
        write (nttyo,450) nwarn                                                 
  450   format(' * error- the input has failed ',i4,' idiot-proofing',          
     $  ' tests')                                                               
        go to 20                                                                
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     save value of titration or carbonate alkalinity.  if using                
c     carbonate alkalinity, zero the titration factors of non-carbonate         
c     species.                                                                  
c                                                                               
      do 204 ns = 2,nst                                                         
      if (uspec(ns)(1:8).eq.uco3(1:8)                                           
     $ .or. uspec(ns)(1:8) .eq. uhco3(1:8)) then                                
        ncarb = ns                                                              
        go to 206                                                               
      endif                                                                     
  204 continue                                                                  
  206 alk=0.                                                                    
      if (ncarb.gt.0) then                                                      
        jk=jflag(ncarb)                                                         
        if (jk.eq.10 .or. jk.eq.12) then                                        
          alk=csp(ncarb)                                                        
          if (jk.eq.12) then                                                    
            do 463 ns=1,nst                                                     
            if (titr(ns).ne.0.) then                                            
              if (ns.le.nsb) then                                               
                if (ns.ne.ncarb) titr(ns)=0.                                    
              else                                                              
                nrs=ns-nsb                                                      
                if (cdrs(ncarb,nrs).eq.0.) titr(ns)=0.                          
              endif                                                             
            endif                                                               
  463       continue                                                            
          endif                                                                 
        endif                                                                   
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     recompute equilibrium constants if the reactions have been                
c     modified by elimination of auxiliary basis species or                     
c     by basis switching.                                                       
c                                                                               
      if (qelim .or. qbassw)                                                    
     $ call evdatr(tempc,tempk,press,pgrid,ars,amn,ags,                         
     $ xlks,xlkm,xlkg,rconst,nrst,nst,nmt,ngt,nxt,ntpr,narxmx,                  
     $ ntprmx,noutpt,nttyo)                                                     
c                                                                               
      if (iopr2 .ge. 1)                                                         
     $ call echolk(iopr2,noutpt,tempc,press,cdrs,cdrm,cdrg,ars,                 
     $ amn,ags,xlks,xlkm,xlkg,uspec,umin,ugas,jsflag,jmflag,                    
     $ jgflag,nsb,nsq,nsq1,nrst,nst,nmt,ngt,nxt,ntpr,nsqmx1,                    
     $ narxmx,ntprmx)                                                           
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     compute the csts array of stoichiometric factors.  this is                
c     calculated from the cdrs array of reaction coefficients.                  
c                                                                               
      call gcsts(csts,cdrs,cstor,ibasis,jsflag,jflag,                           
     $ nhydr,nct,nsb,nsb1,nsq,nsq1,nst,nsqmax,nsqmx1,nstmax,
     $ qbassw)                    
c                                                                               
c     get weights for computing the equivalent stoichiometric                   
c     ionic strength                                                            
c                                                                               
      if (iopg1.eq.0 .and. iacion.gt.0) then                                    
        do 110 ns = 1,nst                                                       
        cxistq(ns) = csts(iacion,ns)                                            
  110   continue                                                                
      endif                                                                     
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     set up the matrix for newton-raphson iteration and compute                
c     starting values of the matrix variables.                                  
c                                                                               
      call arrset(ars,amn,ags,cess,cdrs,cdrm,cdrg,csts,                         
     $ cstor,xbarlg,lamlg,aa,gm,csp,concbs,cte,mte,zvclg1,cxistq,               
     $ conc,conclg,act,actlg,glg,glgx,xlks,xlkm,xlkg,mwtss,z,zsq2,              
     $ titr,azero,hydn,rhs,ee,res,al10,rconst,xlkeh,ehfac,om,omlg,              
     $ omi,tempc,tempk,press,xi,xisteq,fo2lg,eh,dshm,shm,shmlim,                
     $ uzvec1,uspec,umin,ugas,ujtype,nend,jflag,nsp,nspec,jsflag,               
     $ jsort,iindx1,ibswx,ibasis,ir,kill,iopt1,iopt2,iopg1,iodb1,               
     $ iodb2,ntpr,iacion,iebal,nhydr,nchlor,nct,nsb,nsb1,nsq,                   
     $ nsqb,nsq1,nst,nrst,nmt,ngt,nxt,kct,ksb,ksq,kebal,kdim,kmax,              
     $ khydr,nctmax,nsqmax,nsqmx1,nstmax,iktmax,narxmx,ntprmx,                  
     $ ker,nloop,noutpt,nttyo,qhydth,qpt4,qbswx,qbassw)                         
c                                                                               
      if (ker.ge.2) go to 20                                                    
      if (qretry.and.nloop.le.0) go to 20                                       
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     initialize some parameters.                                               
c                                                                               
      qpra = .true.                                                             
      qprb = iodb4 .ge. 1                                                       
      qprc = iodb4 .ge. 2                                                       
      kcarb = 0                                                                 
      if (ncarb .gt. 0) then                                                    
        do 212 kcol = 2,ksq                                                     
        ns = iindx1(kcol)                                                       
        if (ns .eq. ncarb) then                                                 
          kcarb = kcol                                                          
          go to 214                                                             
        endif                                                                   
  212   continue                                                                
  214   continue                                                                
      endif                                                                     
c                                                                               
c     call routine newton to calculate the distribution of aqueous              
c     species.                                                                  
c
c
      call newton(cdrs,aa,gm,zvclg1,del,rhs,ee,res,conc,cxistq,                 
     $ beta,alpha,z,zsq2,azero,hydn,glg,glgx,betao,delo,concbs,screwd,          
     $ screwn,tolbt,toldl,tempc,press,betamx,bbig,bneg,bgamx,xi,xisteq,         
     $ dshm,shm,shmlim,uspec,uzvec1,uqdel,uqbeta,ubbig,ubneg,ubgamx,            
     $ jsflag,jsort,ir,iter,itermx,idelmx,ibetmx,iacion,kmax,kdim,              
     $ nsqmx1,nsb,nsq,nst,nhydr,nchlor,ier,matrix,ncmpx,betas,                  
     $ qpra,qprb,qprc,ncarb)                                                          
c
c
      if (ier.gt.0) then                                                        
        write (noutpt,1408) iter                                                
        write (nttyo,1408) iter                                                 
 1408   format(//' * trouble- hybrid newton-raphson iteration failed',          
     $  ' after ',i3,' steps',/)                                                
        call ndiagx(del,screwd,jflag,iindx1,idelmx,iebal,ksb,                   
     $  kebal,khydr,kcarb,nhydr)                                                
        go to 20                                                                
      endif                                                                     
c                                                                               
      write (noutpt,1437) iter                                                  
      write (nttyo,1437) iter
 1437 format(//,' hybrid newton-raphson iteration converged in ',i3,            
     $ ' steps '/)
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     output the computed solution parameters.                                  
c                                                                               
      call scripx(ars,amn,ags,cdrs,cdrm,cdrg,csts,cess,concbs,                  
     $ sigzi,eps100,nct,nsb,nsb1,nsq,nsq1,nst,nrst,nmt,ngt,nxt,nctmax,          
     $ nsqmax,nsqmx1,nstmax,iktmax,narxmx,ntprmx,noutpt,nttyo)                  
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
c     write interfacing output (the pickup file)                                
c                                                                               
      call scribx(sigzi,usave)                                                  
c                                                                               
c     go look for another problem on the input file                             
c                                                                               
      go to 20                                                                  
      end                                                                       
c arrset   last revised 12/15/87 by tjw                                         
c*arrset f77 rewrite 02/24/87 by tjw                                            
      subroutine arrset(ars,amn,ags,cess,cdrs,cdrm,cdrg,csts,                   
     $ cstor,xbarlg,lamlg,aa,gm,csp,concbs,cte,mte,zvclg1,cxistq,               
     $ conc,conclg,act,actlg,glg,glgx,xlks,xlkm,xlkg,mwtss,z,zsq2,              
     $ titr,azero,hydn,rhs,ee,res,al10,rconst,xlkeh,ehfac,om,omlg,              
     $ omi,tempc,tempk,press,xi,xisteq,fo2lg,eh,dshm,shm,shmlim,                
     $ uzvec1,uspec,umin,ugas,ujtype,nend,jflag,nsp,nspec,jsflag,               
     $ jsort,iindx1,ibswx,ibasis,ir,kill,iopt1,iopt2,iopg1,iodb1,               
     $ iodb2,ntpr,iacion,iebal,nhydr,nchlor,nct,nsb,nsb1,nsq,                   
     $ nsqb,nsq1,nst,nrst,nmt,ngt,nxt,kct,ksb,ksq,kebal,kdim,kmax,              
     $ khydr,nctmax,nsqmax,nsqmx1,nstmax,iktmax,narxmx,ntprmx,                  
     $ ker,nloop,noutpt,nttyo,qhydth,qpt4,qbswx,qbassw)                         
c                                                                               
c     build the iindx1 array.  set up the matrix structure for newton-          
c     raphson and provide starting values for the iteration variables.          
c     ker is returned 0 if all went well, as 1 if the input constraints         
c     look suspiciously poor, and as 2 if they look really bad.                 
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "bt.h"                                                           
c                                                                               
      character*(*) uzvec1(*),uspec(*),umin(*),ugas(*),ujtype(*)                
      character*24 udef,ueb,ueh,ured,ust1,ust2                                  
c                                                                               
      dimension ars(narxmx,ntprmx,*),amn(narxmx,ntprmx,*),                      
     $ ags(narxmx,ntprmx,*),cess(nctmax,*),cdrs(nsqmx1,*),                      
     $ cdrm(nsqmx1,*),cdrg(nsqmx1,*),csts(nsqmax,*),xbarlg(iktmax,*),           
     $ lamlg(iktmax,*),aa(kmax,*),gm(kmax,*),csp(*),concbs(*),                  
     $ cte(*),mte(*),zvclg1(*),cxistq(*),conc(*),conclg(*),                     
     $ act(*),actlg(*),glg(*),glgx(*),xlks(*),xlkm(*),xlkg(*),                  
     $ mwtss(*),z(*),zsq2(*),titr(*),azero(*),hydn(*),rhs(*),ee(*),             
     $ res(*),nend(iktmax,*),jflag(*),nsp(*),nspec(*),jsflag(*),                
     $ jsort(*),iindx1(*),ibswx(*),ibasis(*),ir(*),kill(*)                      
c                                                                               
      dimension kkndex(nsqpar)                                                  
c                                                                               
      data udef /'defining equation       '/,                                   
     $     ueb  /'elect. balance          '/,                                   
     $      ueh /'eh                      '/,                                   
     $     ured /'aq redox reaction       '/                                    
      data ublank /'        '/,ukilld /'killed  '/                              
c                                                                               
c   nlopmx is the maximum number of auto basis switching loops.                 
c                                                                               
c   nplim is the maximum number of passes in the estimation.  passes            
c   refine estimates of ionic strength, activity of water, activity             
c   coefficients, and (if hydration theory is used) sigma(hm).                  
c                                                                               
c   ncylim is the maximum number of cycles in the estimation.  cycles           
c   may occur within passes, and are used to refine estimates of                
c   species concentrations before new estimates of ionic strength, etc.,        
c   are made.                                                                   
c                                                                               
      data nlopmx/12/,nplim/4/,ncylim/7/                                        
      data nttyi/5/                                                             
c                                                                               
c     qcfrac = flag to routine betas to get efac array for continued            
c       fraction calculations                                                   
c                                                                               
      data qcfrac/.true./,qfalse/.false./                                       
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      qabsw=iopt2.ge.1                                                          
c                                                                               
      qpr1=iodb2.ge.1                                                           
      qpr2=iodb2.ge.2                                                           
      qpr3=iodb2.ge.3                                                           
      if (qpr1) write (noutpt,2)                                                
    2 format(' --- arrset ---')                                                 
c                                                                               
c     set up the structure of the iteration matrix.  its contents may be        
c     altered subsequently by automatic basis switching.                        
c                                                                               
c       build the iindx1 array, find ksq,kdim,...                               
c                                                                               
      kebal=0                                                                   
      iindx1(1)=1                                                               
      uzvec1(1)=uspec(1)                                                        
      ksq=1                                                                     
      kkndex(1)=0                                                               
c                                                                               
      do 20 ns=2,nsq                                                            
      kkndex(ns)=0                                                              
      jfl=jflag(ns)                                                             
      if (jfl.ne.-1 .and. jfl.ne.30) then                                       
        ksq=ksq+1                                                               
        iindx1(ksq)=ns                                                          
        uzvec1(ksq)=uspec(ns)(1:8)                                              
        if (ns.eq.nsb) ksb=ksq                                                  
        if (ns.eq.nhydr) khydr=ksq                                              
      endif                                                                     
   20 continue                                                                  
      kct=ksb-1                                                                 
      kdim = ksq                                                                
c                                                                               
c     the label below is a return point after an automatic basis switch         
c                                                                               
c     nloop is the loop counter for auto basis switching                        
c                                                                               
      nloop=-1                                                                  
c                                                                               
   25 nloop=nloop+1                                                             
      if (qpr1) write (noutpt,33) nloop                                         
   33 format(5x,'nloop= ',i2)                                                   
c                                                                               
c     get stoichiometric coefficients for the equivalent                        
c     stoichiometric ionic strength.                                            
c                                                                               
c     print the iteration matrix structure.  execute any killer options.        
c     killer options are set only once.  they carry through after any           
c     automatic basis switching.                                                
c                                                                               
      if (qpr1) write (noutpt,30)                                               
   30 format(/16x,'--- iteration matrix structure ---',//)                      
      if (iodb3 .ne. 0) write (nttyo,1050)                                      
 1050 format(/,' iteration variables')                                          
c                                                                               
      do 70 kcol=1,kdim                                                         
      ns=iindx1(kcol)                                                           
      ust2=udef                                                                 
      if (kcol.le.ksq) then                                                     
        ust1=uspec(ns)                                                          
        jfl=jflag(ns)                                                           
        if (ns .eq. iebal) then                                                 
          kebal = kcol                                                          
          ust2 = ueb                                                            
        elseif (ns .eq. nsb) then                                               
          if ((iopt1 .eq. -1) .or. (iopt1 .eq. -2)) then                        
            ust2 = ueh                                                          
          elseif (iopt1 .eq. 1) then                                            
            ust2 = ured                                                         
          endif                                                                 
        else                                                                    
            jflp1 = jfl + 1                                                     
            ust2 = ujtype(jflp1)                                                
        endif                                                                   
      endif                                                                     
c                                                                               
      if (iodb3.ne.0 .and. nloop.eq.0) then                                     
        write (nttyo,1052) kcol,ns,ust1,ust2                                    
 1052   format(1x,2i5,3x,a24,3x,a24)                                            
        write (nttyo,1054)                                                      
 1054   format('  kill this variable? (y/n)')                                   
        read (nttyi,1056) uyn                                                   
 1056   format(a8)                                                              
        kill(kcol) = 0                                                          
        if (uyn .eq. 'y     ') kill(kcol) = 1                                   
      endif                                                                     
c                                                                               
      if (qpr1) then                                                            
        ust3=ublank                                                             
        if (iodb3.ne.0 .and. kill(kcol).ge.1) ust3=ukilld                       
        write (noutpt,65) kcol,ns,ust1,ust2,ust3                                
   65   format(12x,2i5,3x,a24,3x,a24,2x,a8)                                     
      endif                                                                     
c                                                                               
   70 continue                                                                  
c                                                                               
      if (qpr1) write (noutpt,75)                                               
   75 format(/1x)                                                               
c                                                                               
c     echo killer option data                                                   
c                                                                               
      if (iodb3 .gt. 0) then                                                    
        write (nttyo,1060)                                                      
 1060   format(' variables killed are in columns')                              
        tally = 0                                                               
        do 232 kcol=1,kdim                                                      
        if (kill(kcol) .ne. 0) then                                             
          tally = tally+1                                                       
          write (nttyo,1062) kcol                                               
 1062     format(3x,i3)                                                         
        endif                                                                   
  232   continue                                                                
c                                                                               
        if (tally .eq. 0) write (nttyo,1064)                                    
 1064   format(3x,'none')                                                       
      endif                                                                     
c                                                                               
c     set up preliminary estimates of basis species concentrations              
c                                                                               
      do 823 ns = 1,nst                                                         
      conc(ns) = 0.                                                             
  823 continue                                                                  
c                                                                               
      do 800 kcol = 2,ksq                                                       
      if (kcol .eq. ksb) go to 800                                              
      ns=iindx1(kcol)                                                           
      jfl=jflag(ns)                                                             
      if (jfl.le.9) then                                                        
c                                                                               
c       concentrations, total and free                                          
c                                                                               
        conc(ns)=csp(ns)                                                        
      elseif (jfl.le.12) then                                                   
c                                                                               
c       alkalinity                                                              
c                                                                               
        conc(ns)=csp(ns)/titr(ns)                                               
      elseif (jfl.eq.16) then                                                   
c                                                                               
c       activity                                                                
c                                                                               
        cdum=csp(ns)                                                            
        conc(ns)=texp(cdum)                                                     
      else                                                                      
c                                                                               
c       all other cases                                                         
c                                                                               
        conc(ns)=1.e-7                                                          
      endif                                                                     
  800 continue                                                                  
c                                                                               
c     calculate a starting value for the ionic strength, treating               
c     the calculated charge imbalance among the basis species as                
c     the equivalent of a monovalent ion.                                       
c                                                                               
      call gxi(zsq2,conc,jsort,nst,xic)                                         
      zdel=0.                                                                   
      do 805 ns=2,nsq                                                           
      zdel=zdel+z(ns)*conc(ns)                                                  
  805 continue                                                                  
      xi=xic+0.5*abs(zdel)                                                      
c                                                                               
c     calculate the equivalent stoichiometric ionic strength                    
c                                                                               
      xisteq=0.                                                                 
      if (iopg1.eq.0 .and. iacion.gt.0) xisteq=csp(iacion)                      
c                                                                               
c     calculate the dshm factor for hydration theory.                           
c     'dshm' = 1 - ( (sigma)i mi)/omega )                                       
c                                                                               
      if (qhydth) then                                                          
        call gshm(hydn,conc,jsort,nst,shmc,dshmc)                               
        if (shmc .gt. shmlim) then                                              
          shmc=shmlim                                                           
          dshmc = 1.0 - (shmc/om)                                               
        endif                                                                   
        shm=shmc                                                                
        dshm=dshmc                                                              
      endif                                                                     
c                                                                               
c     calculate the activity coefficients                                       
c                                                                               
      if (qpt4) call molint(conc,nsq,nst,cdrs,nsqmx1,nsb,3,concbs)              
      call gcoeff(conc,z,zsq2,azero,hydn,concbs,glgx,xi,xisteq,                 
     $ dshm,tempc,press,jsflag,jsort,iacion,nsb,nst,nsq,nhydr,nchlor)           
c                                                                               
      do 202 ns=1,nst                                                           
      glg(ns)=glgx(ns)                                                          
  202 continue                                                                  
c                                                                               
c     load the master species part of the conclg array.                         
c                                                                               
      do 910 kcol=2,ksq                                                         
      ns=iindx1(kcol)                                                           
      cdum=conc(ns)                                                             
      conclg(ns)=tlg(cdum)                                                      
  910 continue                                                                  
c                                                                               
c     npass is the pass counter                                                 
c                                                                               
      npass=0                                                                   
c                                                                               
c     the label below is a return point for subsequent passes.  a pass          
c     is an adjustment for xi, xisteq, dshm, the activity of water,             
c     and the activity coefficients of the solute species.                      
c                                                                               
 3210 npass=npass+1                                                             
      if (npass.gt.1) qabsw=iopt2.ge.1                                          
c                                                                               
      if (qpr1) then                                                            
        write (noutpt,3) npass                                                  
    3   format(10x,'npass= ',i2)                                                
        write (noutpt,6) xi                                                     
    6   format(12x,'xi = ',1pe12.5)                                             
        if (iopg1 .eq. 0)  write (noutpt,4) xisteq                              
    4   format(12x,'xisteq= ',1pe12.5)                                          
        if (qhydth) write (noutpt,7) shm,dshm                                   
    7   format(12x,'shm= ',1pe12.5,', dshm= ',1pe12.5)                          
      endif                                                                     
c                                                                               
c   ncycle is the cycle counter                                                 
c                                                                               
      ncycle=0                                                                  
c                                                                               
c     the label below is a return point for beginning a new cycle.              
c     a cycle is an adjustment within a pass to get basis species               
c     concentration estimates in range to make a reasonable new estimate        
c     of ionic strength.                                                        
c                                                                               
 3220 ncycle=ncycle+1                                                           
      if (qpr1) write (noutpt,742) ncycle                                       
  742 format(15x,'ncycle= ',i2)                                                 
      ker=0                                                                     
      if (ncycle.gt.1) qabsw=.false.                                            
c                                                                               
c     make starting estimates for the iteration variables (the                  
c     elements of the zvclg1 array).  the iteration variables represent         
c     base ten logarithms of molalities and oxygen fugacity.                    
c                                                                               
      zvclg1(1)=omlg                                                            
      do 95 krow=2,ksq                                                          
      ns=iindx1(krow)                                                           
      jfl=jflag(ns)                                                             
      if (jfl.lt.16) then                                                       
        zvclg1(krow)=conclg(ns)                                                 
      elseif (jfl.eq.16) then                                                   
        cdum=csp(ns)-glgx(ns)                                                   
        zvclg1(krow)=cdum                                                       
      endif                                                                     
   95 continue                                                                  
c                                                                               
      if (iopt1.eq.0) zvclg1(ksb)=fo2lg                                         
c                                                                               
c        make starting estimates that must be evaluated simultaneously.         
c        these include all cases of equilibrium constraints and also            
c        that in which log fo2 is constrained by eh, pe-, or a redox            
c        couple.                                                                
c                                                                               
      call arrsim(kkndex,npass,ker,eh,ehfac,nsb,nsq,nsq1,nsqb,                  
     $ nsqmax,nsqmx1,nhydr,iktmax,glgx,uspec,umin,ugas,jflag,                   
     $ iindx1,nend,xbarlg,lamlg)                                                
c                                                                               
      call ncmpx                                                                
      call betas(qcfrac,qabsw)                                                  
c                                                                               
c     print values of master iteration variables                                
c                                                                               
      if (qpr2) then                                                            
        write (noutpt,3247)                                                     
 3247   format(/10x,'--- pre-iteration summary ---',//                          
     $  3x,'krow  iindx1  name     zvclg1       zvec1      beta',/)             
        do 745 krow=1,kdim                                                      
        idum=iindx1(krow)                                                       
        zdum1=zvclg1(krow)                                                      
        zdum2=texp(zdum1)                                                       
        udum=uzvec1(krow)                                                       
        bdum=beta(krow)                                                         
        write (noutpt,3250) krow,idum,udum,zdum1,zdum2,bdum                     
 3250   format(1x,2i5,2x,a8,2x,f10.4,2x,1pe12.5,2x,1pe12.5)                     
  745   continue                                                                
        write (noutpt,75)                                                       
      endif                                                                     
c                                                                               
c     if the same species dominates more than one mass balance,                 
c     then the continued fraction algorithm can be applied to only              
c     one of the associated master species.  otherwise, oscillatory             
c     behavior will occur.  in each set of mass balances with a common          
c     dominating species, find the mass balance with the greatest               
c     residual and complete the calculation of its bfac factor by               
c     doing the appropriate exponentiation.  set bfac to unity for              
c     the others in the set.                                                    
c                                                                               
      if (qpr2) then                                                            
        write (noutpt,642)                                                      
  642   format(/5x,'--- mass balance dominants ---',/)                          
        write (noutpt,643)                                                      
  643   format(3x,'master species',14x,'dominant species',/)                    
        do 645 kcol=2,ksq                                                       
        ns=iindx1(kcol)                                                         
        ns2=nfac(kcol)                                                          
        if (ns2.gt.0)  write (noutpt,644) uspec(ns),uspec(ns2)                  
  644   format(2x,a24,5x,a24)                                                   
  645   continue                                                                
      endif                                                                     
c                                                                               
      call gbfac(nfac,beta,efac,ksq,bfac)                                       
c                                                                               
      if (qpr3 .and. .not.qbswx) then                                           
        write (noutpt,647)                                                      
  647   format(//5x,'--- factors for continued fraction',                       
     $  ' corrections ---',/)                                                   
        write (noutpt,648)                                                      
  648   format(3x,'master species',14x,'bfac'10x,'efac',/)                      
        do 650 kcol=2,ksq                                                       
        if (bfac(kcol).gt.0.) then                                              
          ns=iindx1(kcol)                                                       
          write (noutpt,649) uspec(ns),bfac(kcol),efac(kcol)                    
  649     format(2x,a24,3x,1pe12.5,3x,1pe12.5)                                  
        endif                                                                   
  650   continue                                                                
      endif                                                                     
c                                                                               
c     in automatic basis switching mode (iopt2.ge.1), try to first              
c     reduce the magntiude of large positive mass balance residuals             
c     by making one or more basis switches.                                     
c                                                                               
      if (.not.qbswx) go to 3275                                                
      if (nloop.ge.nlopmx) go to 3275                                           
c                                                                               
      if (qpr2) then                                                            
        write (noutpt,553)                                                      
  553   format(/11x,'--- candidate basis switches ---',/)                       
        do 570 kcol=2,ksq                                                       
        ns1=iindx1(kcol)                                                        
        ns2=ibswx(kcol)                                                         
        if (ns2.gt.0) write (noutpt,557) uspec(ns1),uspec(ns2)                  
  557   format(6x,a12,' could be switched with ',a12)                           
  570   continue                                                                
      write (noutpt,559)                                                        
  559 format(/1x)                                                               
      endif                                                                     
c                                                                               
c     resolve any conflicts in candidate basis switches                         
c                                                                               
      call gabswx(beta,ksq,ibswx)                                               
c                                                                               
      if (qpr1) then                                                            
        write (noutpt,573)                                                      
  573   format(/11x,'--- auto basis switches ---',/)                            
        do 575 kcol = 2,ksq                                                     
        ns1 = iindx1(kcol)                                                      
        ns2 = ibswx(kcol)                                                       
        if (ns2.gt.0) write (noutpt,554) uspec(ns1),uspec(ns2)                  
  554   format(6x,a24,' will be switched with ',a24)                            
  575   continue                                                                
      write (noutpt,559)                                                        
      endif                                                                     
c                                                                               
c     make the basis switches called for                                        
c                                                                               
      call autosw(3,ars,amn,ags,cess,cdrs,cdrm,cdrg,                            
     $ cxistq,mwtss,z,zsq2,titr,azero,hydn,csp,uzvec1,uspec,jflag,              
     $ jsflag,iindx1,ibswx,ibasis,nsp,iopg1,iacion,iebal,nhydr,                 
     $ nchlor,nct,nsb,nsq,nsq1,nst,nrst,nmt,ngt,ksq,nctmax,nsqmx1,              
     $ narxmx,ntprmx,nerr,noutpt,nttyo,qhydth,qpt4,qbassw)                      
c                                                                               
      if (nerr.gt.0) then                                                       
        write (nttyo,420) nloop                                                 
        write (noutpt,420) nloop                                                
  420   format(' * error- auto basis switching error in loop ',                 
     $  i2,' (arrset)')                                                         
        stop                                                                    
      endif                                                                     
c                                                                               
c     recompute the log k values for aqueous dissocation reactions              
c     and mineral and gas dissolution reactions                                 
c                                                                               
      call evdatr(tempc,tempk,press,pgrid,ars,amn,ags,                          
     $ xlks,xlkm,xlkg,rconst,nrst,nst,nmt,ngt,nxt,ntpr,narxmx,                  
     $ ntprmx,noutpt,nttyo)                                                     
c                                                                               
c     recompute the csts array of stoichiometric factors.  this is              
c     calculated from the cdrs array of reaction coefficients.                  
c                                                                               
      call gcsts(csts,cdrs,cstor,ibasis,jsflag,jflag,                           
     $ nhydr,nct,nsb,nsb1,nsq,nsq1,nst,nsqmax,nsqmx1,nstmax,
     $ qbassw)                    
c                                                                               
      go to 25                                                                  
c                                                                               
 3275 continue                                                                  
c                                                                               
c     calculate the electrical balance residual.                                
c                                                                               
      bxecor=0.                                                                 
      xecorr=0.                                                                 
      if (kebal.gt.0) then                                                      
        cecorr=-alpha(kebal)/z(iebal)                                           
        xecorr=zsq2(iebal)*cecorr                                               
        call gszm(z,conc,jsort,nst,sigzc,sigza,sigzm,sigzi)                     
        bxecor=abs(xecorr)/sigzm                                                
      endif                                                                     
c                                                                               
c     test the balance residuals for mass and alkalinity to see if              
c     another cycle should be made before attempting to make an improved        
c     estimate of the ionic strength.                                           
c                                                                               
      if (qpr1) write (noutpt,155) betamx,bbig,ubbig,bneg,ubneg                 
  155 format(17x,'betamx= ',1pe12.5,                                            
     $ /17x,'bbig= ',1pe12.5,', ubbig= ',a24,                                   
     $ /17x,'bneg= ',1pe12.5,', ubneg= ',a24)                                   
c                                                                               
      qtestc=bbig.le.0.5.and.bneg.ge.-0.1                                       
      qtestc=qtestc.and.bxecor.le.0.25                                          
c                                                                               
      if (qtestc) go to 3240                                                    
      if (ncycle.ge.ncylim) go to 3240                                          
c                                                                               
c     make improvements in concentration estimates and go back for              
c     another cycle.  the algorithm employed here is the modified               
c     continued fraction method proposed by t. j. wolery in                     
c     memo gcc-85-1.  the bfac array is calculated in routine betas.            
c                                                                               
      do 830 kcol=2,ksq                                                         
      ns=iindx1(kcol)                                                           
      if (ns.eq.iebal) go to 830                                                
      jfl=jflag(ns)                                                             
      bdum=beta(kcol)                                                           
      bdum1=bdum+1.                                                             
      if (jfl.eq.0) then                                                        
        ddum=bfac(kcol)                                                         
        if (bdum1.le.0.) ddum=1.e-20                                            
        ldum=tlg(ddum)                                                          
        ldum=min(ldum,+20.d0)                                                   
        conclg(ns)=conclg(ns)-ldum                                              
      elseif (jfl.eq.10 .or. jfl.eq.12) then                                    
        if (bdum1.le.0.) bdum1=1.e-20                                           
        ldum=tlg(bdum1)                                                         
        ldum=min(ldum,+20.d0)                                                   
        conclg(ns)=conclg(ns)-ldum                                              
      endif                                                                     
  830 continue                                                                  
c                                                                               
      if (iebal.gt.0) then                                                      
        clgo=conclg(iebal)                                                      
        cnew=conc(iebal)+cecorr                                                 
        if (cecorr.ge.0.) then                                                  
          clg=tlg(cnew)                                                         
          clim=clgo+2.                                                          
          conclg(iebal)=min(clg,clim)                                           
        else                                                                    
          cnew=max(cnew,0.d0)                                                   
          clg=tlg(cnew)                                                         
          clim=clgo-2.                                                          
          conclg(iebal)=max(clg,clim)                                           
        endif                                                                   
      endif                                                                     
c                                                                               
c     go back for another cycle                                                 
c                                                                               
      go to 3220                                                                
c                                                                               
c     the cycles for the current pass have been completed.  test to             
c     see if another pass should be made.                                       
c                                                                               
 3240 call gxi(zsq2,conc,jsort,nst,xic)                                         
      bxi=(xic-xi)/xi                                                           
      if (qpr1) write (noutpt,162) bxi                                          
  162 format(7x,'bxi= ',1pe12.5)                                                
      abxi=abs(bxi)                                                             
      qxi=abxi.le.0.1                                                           
c                                                                               
      qxistq=.true.                                                             
      if (iacion.gt.0) then                                                     
        call gxistq(cxistq,conc,jsort,nst,xistqc)                               
        bxistq=(xistqc-xisteq)/xisteq                                           
        if (qpr1) write (noutpt,163) bxistq                                     
  163   format(7x,'bxistq= ',1pe12.5)                                           
        abxstq=abs(bxistq)                                                      
        qxistq=abxstq.le.0.1                                                    
      endif                                                                     
c                                                                               
      qdshm=.true.                                                              
      if (qhydth) then                                                          
        call gshm(hydn,conc,jsort,nst,shmc,dshmc)                               
        if (shmc .gt. shmlim) then                                              
          shmc=shmlim                                                           
          dshmc = 1.0 - (shmc/om)                                               
        endif                                                                   
        bshm=(shmc-shm)/shm                                                     
        if (qpr1) write (noutpt,164) bshm                                       
  164   format(7x,'bshm= ',1pe12.5)                                             
        abshm=abs(bshm)                                                         
        qdshm=abshm.le.0.1                                                      
      endif                                                                     
c                                                                               
      if (qpt4) call molint(conc,nsq,nst,cdrs,nsqmx1,nsb,3,concbs)              
      call gcoeff(conc,z,zsq2,azero,hydn,concbs,glgx,xi,xisteq,                 
     $ dshm,tempc,press,jsflag,jsort,iacion,nsb,nst,nsq,nhydr,nchlor)           
c                                                                               
       call betgam(uspec,conc,glgx,glg,nst,bgamx,ubgamx)                        
c                                                                               
      if (qpr1) write (noutpt,177) bgamx,ubgamx                                 
  177 format(5x,'bgamx= ',1pe12.5,', ubgamx= ',a24)                             
      qgm=bgamx.le.0.1                                                          
c                                                                               
      qtestp=qxi.and.qxistq.and.qdshm.and.qgm                                   
c                                                                               
c     are pass criteria satisfied?                                              
c                                                                               
      if (.not.qtestp) then                                                     
c                                                                               
c       pass criteria are not satisfied                                         
c                                                                               
c       test for maximum no. of passes                                          
c                                                                               
        if (npass.ge.nplim) then                                                
c                                                                               
c         quit- optimization ended outside requested limits                     
c         because pass requirements were not satisfied                          
c                                                                               
          write (noutpt,210)                                                    
          write (nttyo,210)                                                     
  210     format(' * note- optimization ended outside requested',               
     $    ' limits (arrset)',/)                                                 
          go to 999                                                             
        endif                                                                   
c                                                                               
c       set up for another pass                                                 
c                                                                               
        go to 10                                                                
      endif                                                                     
c                                                                               
c     are cycle criteria satisfied?                                             
c                                                                               
      if (qtestc) then                                                          
c                                                                               
c       optimization achieved within requested limits                           
c                                                                               
        write (noutpt,190)                                                      
  190   format(' --- arrset - optimization ended within requested',             
     $  ' limits ---',/)                                                        
        go to 999                                                               
c                                                                               
c     pass criteria are satisfied, but the cycle criteria are not               
c                                                                               
      elseif (npass.le.2) then                                                  
c                                                                               
c     try another pass                                                          
c                                                                               
        go to 10                                                                
      else                                                                      
c                                                                               
c       quit- optimization ended outside requested limits                       
c       because cycle requirements were not met                                 
c                                                                               
        if (qpr1) write (noutpt,210)                                            
        go to 999                                                               
      endif                                                                     
c                                                                               
c     make new estimates of the ionic strength, activity of water,              
c     activity coefficients, and, where appropriate, the equivalent             
c     stoichiometric ionic strength or sigma(hm).                               
c                                                                               
c     include a contribution from the electrical imbalance in the new           
c     ionic strength estimate if electrical balance is a constraint.            
c     xecorr is the value of the full correction.  use one-half of this         
c     to prevent oscillation.  if xecorr is negative, limit it to twenty        
c     per cent of xic, the latest calculated value of ionic strength.           
c                                                                               
   10 xlim=22.                                                                  
      xdel=0.5*xecorr                                                           
      if (xdel.lt.0.) then                                                      
        xdel1=-0.2*xic                                                          
        xdel=max(xdel,xdel1)                                                    
      endif                                                                     
      xinew=xic+xdel                                                            
      xdiff=xinew-xi                                                            
      xdel=xdiff/xi                                                             
      xi=xinew                                                                  
      xi=min(xi,xlim)                                                           
c                                                                               
      if (iopg1.eq.0 .and. iacion.gt.0) then                                    
       xdel=xistqc-xisteq                                                       
        if (xdel.lt.0.) then                                                    
          xdel=-0.2*xdel                                                        
          xdel=max(xdel,xdel1)                                                  
        endif                                                                   
        xisteq=xisteq+xdel                                                      
        xisteq=min(xisteq,xlim)                                                 
      endif                                                                     
c                                                                               
      if (qhydth) then                                                          
        if (shmc .gt. shmlim) then                                              
          shmc=shmlim                                                           
          dshmc = 1.0 - (shmc/om)                                               
        endif                                                                   
        shm=shmc                                                                
        dshm=dshmc                                                              
      endif                                                                     
c                                                                               
      if (qpt4) call molint(conc,nsq,nst,cdrs,nsqmx1,nsb,3,concbs)              
      call gcoeff(conc,z,zsq2,azero,hydn,concbs,glgx,xi,xisteq,                 
     $ dshm,tempc,press,jsflag,jsort,iacion,nsb,nst,nsq,nhydr,nchlor)           
c                                                                               
      do 205 ns=1,nst                                                           
      glg(ns)=glgx(ns)                                                          
  205 continue                                                                  
c                                                                               
c     go back for another pass                                                  
c                                                                               
      go to 3210                                                                
c                                                                               
  999 continue                                                                  
      end                                                                       
c arrsim   last revised 12/11/87 by tjw                                         
      subroutine arrsim(kkndex,npass,ker,eh,ehfac,nsb,nsq,nsq1,nsqb,            
     $ nsqmax,nsqmx1,nhydr,iktmax,glgx,uspec,umin,ugas,jflag,                   
     $ iindx1,nend,xbarlg,lamlg)                                                
c                                                                               
c     this routine supports arrset.  it makes starting estimates of             
c     concentrations that must be evaluated simultaneously.                     
c     these include all cases of equilibrium constraints and also that          
c     in which log fo2 is constrained by eh, pe-, or a redox couple.            
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "ki.h"                                                           
      include "nn.h"                                                           
      include "op.h"                                                           
      include "op2.h"                                                          
      include "un.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "zg.h"                                                           
      include "eqleps.h"                                       
c                                                                               
      dimension jjndex(nsqpar),kkndex(*),glgx(*),jflag(*),                      
     $ iindx1(*),nend(iktpar,*),xbarlg(iktpar,*),lamlg(iktpar,*)                
c                                                                               
      character*(*) uspec(*),umin(*),ugas(*)                                    
c                                                                               
      character*24 ueh,ured,uaqeq,ublank,ust1,ust2,ust3,unamsp                  
c                                                                               
      data ublank/'                        '/                                   
      data ueh   /'eh                      '/                                   
      data ured  /'aq. redox reaction       '/                                  
      data uaqeq /'aq. equilibrium         '/                                   
      data qfalse/.false./                                                      
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      qpr3=iodb2.ge.3                                                           
c                                                                               
c           build a structure for a matrix equation.                            
c                                                                               
      isq=0                                                                     
      isb=0                                                                     
      ihydr=0                                                                   
c                                                                               
      do 530 krow=2,ksq                                                         
      ns=iindx1(krow)                                                           
      jfdum=jflag(ns)                                                           
      if (jfdum.eq.19) go to 500                                                
      if (jfdum.eq.20) go to 500                                                
      if (jfdum.eq.21) go to 500                                                
      if (jfdum.eq.27) go to 500                                                
      go to 510                                                                 
c                                                                               
  500 continue                                                                  
      isq=isq+1                                                                 
      jjndex(isq)=ns                                                            
      kkndex(ns)=1                                                              
      if (ns.ne.nhydr) go to 530                                                
      ihydr=isq                                                                 
      go to 530                                                                 
c                                                                               
  510 continue                                                                  
      if (ns.ne.nsb) go to 530                                                  
      if (iopt1.eq.0) go to 530                                                 
      isq=isq+1                                                                 
      isb=isq                                                                   
      jjndex(isq)=ns                                                            
      kkndex(ns)=1                                                              
  530 continue                                                                  
      if (isq.le.0) go to 740                                                   
c                                                                               
      if (.not.qpr3) go to 570                                                  
      write (noutpt,532)                                                        
  532 format(7x,'--- structure for simultaneous evaluation of',                 
     $ ' starting estimates ---',//)                                            
c                                                                               
      do 565 irow=1,isq                                                         
      ns1=jjndex(irow)                                                          
      ust1=uspec(ns1)                                                           
      ust3=ublank                                                               
      if (ns1.ne.nsb) go to 561                                                 
      if (nsp(ns1).eq.0) go to 535                                              
c                                                                               
  561 jfdum=jflag(ns1)                                                          
      if (jfdum.ne.27) go to 562                                                
      ust2=uaqeq                                                                
      go to 560                                                                 
c                                                                               
  562 continue                                                                  
      do 563 ns=1,nsqb                                                          
      ns2=nspec(ns)                                                             
      if (ns1.eq.ns2) go to 564                                                 
  563 continue                                                                  
c                                                                               
  564 continue                                                                  
      ust2=uphas1(ns)                                                           
      ust3=uphas2(ns)                                                           
      go to 560                                                                 
c                                                                               
  535 continue                                                                  
      if (iopt1.lt.0) go to 540                                                 
      ust2=ured                                                                 
      go to 560                                                                 
c                                                                               
  540 continue                                                                  
      ust2=ueh                                                                  
c                                                                               
  560 continue                                                                  
      write (noutpt,65) irow,ns,ust1,ust2,ust3                                  
   65 format(4x,2i5,3x,a24,/20x,a24,3x,a24)                                     
  565 continue                                                                  
c                                                                               
      write (noutpt,75)                                                         
   75 format(/1x)                                                               
      write (noutpt,717)                                                        
  717 format(/10x,'--- zvclg1, glgx values ---',/)                              
c                                                                               
      do 567 krow=1,ksq                                                         
      idum=iindx1(krow)                                                         
      kdum=kkndex(idum)                                                         
      if (kdum.ge.1) go to 567                                                  
      zdum1=zvclg1(krow)                                                        
      udum=uzvec1(krow)                                                         
      gdum=glgx(idum)                                                           
      write (noutpt,720) krow,idum,udum,zdum1,gdum                              
  720 format(2x,2i5,3x,a6,3x,f10.4,3x,f10.4)                                    
  567 continue                                                                  
c                                                                               
      write (noutpt,75)                                                         
  570 continue                                                                  
c           build the matrix.                                                   
c                                                                               
      do 580 icol=1,isq                                                         
      do 575 irow=1,isq                                                         
      aa(irow,icol)=0.                                                          
  575 continue                                                                  
  580 continue                                                                  
c                                                                               
      do 605 irow=1,isq                                                         
      nse=jjndex(irow)                                                          
      jfdum=jflag(nse)                                                          
c                                                                               
      if (jfdum.ne.27) go to 583                                                
      nrs=nse-nsb                                                               
c                                                                               
      do 582 icol=1,isq                                                         
      ns1=jjndex(icol)                                                          
      aa(irow,icol)=cdrs(ns1,nrs)                                               
  582 continue                                                                  
c                                                                               
      aa(irow,irow)=cdrs(nsq1,nrs)                                              
      go to 605                                                                 
c                                                                               
  583 continue                                                                  
      if (jfdum.ne.19) go to 585                                                
      nm=nsp(nse)                                                               
c                                                                               
      do 584 icol=1,isq                                                         
      ns1=jjndex(icol)                                                          
      aa(irow,icol)=cdrm(ns1,nm)                                                
  584 continue                                                                  
      go to 605                                                                 
c                                                                               
  585 continue                                                                  
      if (jfdum.ne.20) go to 590                                                
      ndum=nsp(nse)                                                             
      ndum=ndum-50000                                                           
      nx=int(ndum/100.)                                                         
      ik=ndum-100*nx                                                            
      nm=nend(ik,nx)                                                            
c                                                                               
      do 588 icol=1,isq                                                         
      ns1=jjndex(icol)                                                          
      aa(irow,icol)=cdrm(ns1,nm)                                                
  588 continue                                                                  
      go to 605                                                                 
c                                                                               
  590 continue                                                                  
      if (jfdum.ne.21) go to 595                                                
      ng=nsp(nse)                                                               
c                                                                               
      do 594 icol=1,isq                                                         
      ns1=jjndex(icol)                                                          
      aa(irow,icol)=cdrg(ns1,ng)                                                
  594 continue                                                                  
      go to 605                                                                 
c                                                                               
  595 continue                                                                  
      if (iopt1.ge.0) go to 600                                                 
      aa(irow,isb)=1.                                                           
      if (ihydr.le.0) go to 605                                                 
      aa(irow,ihydr)=4.                                                         
      go to 605                                                                 
c                                                                               
  600 continue                                                                  
      nsc=iopt1+nsb                                                             
c                                                                               
      do 604 icol=1,isq                                                         
      ns1=jjndex(icol)                                                          
      if (kkndex(ns1).le.0) go to 604                                           
      if (ns1.ne.nsc) go to 603                                                 
      aa(irow,icol)=cdrs(nsq1,iopt1)                                            
      go to 604                                                                 
c                                                                               
  603 continue                                                                  
      aa(irow,icol)=cdrs(ns1,iopt1)                                             
  604 continue                                                                  
c                                                                               
  605 continue                                                                  
c                                                                               
      if (.not.qpr3) go to 609                                                  
      write (noutpt,606)                                                        
  606 format(/10x,'----- matrix -----',/)                                       
c                                                                               
      do 608 irow=1,isq                                                         
      write (noutpt,607) (aa(irow,icol), icol=1,isq)                            
  607 format(2x,10(f7.2,2x))                                                    
  608 continue                                                                  
c                                                                               
      write (noutpt,75)                                                         
  609 continue                                                                  
c                                                                               
c           build the right-hand-side vector.                                   
c                                                                               
      awlg=glgx(1)                                                              
      do 690 irow=1,isq                                                         
      nse=jjndex(irow)                                                          
      jfdum=jflag(nse)                                                          
c                                                                               
      if (jfdum.ne.27) go to 615                                                
      nrs=nse-nsb                                                               
      if (qpr3) then                                                            
        unamsp = uspec(nse)                                                     
        call prreac(cdrs,uspec,unamsp,nrs,nsq,nsq1,nsqmx1,noutpt)               
      endif                                                                     
c                                                                               
      rdum=xlks(nrs)-cdrs(1,nrs)*awlg                                           
c                                                                               
      do 612 krow=2,ksq                                                         
      ns=iindx1(krow)                                                           
      cdum=cdrs(ns,nrs)                                                         
      if (ns.eq.nse) cdum=cdrs(nsq1,nrs)                                        
      rdum=rdum-cdum*glgx(ns)                                                   
      if (kkndex(ns).ge.1) go to 612                                            
      rdum=rdum-cdum*zvclg1(krow)                                               
  612 continue                                                                  
c                                                                               
      rhs(irow)=rdum                                                            
      go to 690                                                                 
c                                                                               
  615 continue                                                                  
      if (jfdum.ne.19) go to 620                                                
      nm=nsp(nse)                                                               
      if (qpr3) then                                                            
        unamsp = umin(nm)                                                       
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                
      endif                                                                     
c                                                                               
      rdum=xlkm(nm)-cdrm(1,nm)*awlg                                             
c                                                                               
      do 617 krow=2,ksq                                                         
      ns=iindx1(krow)                                                           
      cdum=cdrm(ns,nm)                                                          
      rdum=rdum-cdum*glgx(ns)                                                   
      if (kkndex(ns).ge.1) go to 617                                            
      rdum=rdum-cdum*zvclg1(krow)                                               
  617 continue                                                                  
c                                                                               
      rhs(irow)=rdum                                                            
      go to 690                                                                 
c                                                                               
  620 continue                                                                  
      if (jfdum.ne.20) go to 640                                                
      ndum=nsp(nse)                                                             
      ndum=ndum-50000                                                           
      nx=int(ndum/100.)                                                         
      ik=ndum-100*nx                                                            
      nm=nend(ik,nx)                                                            
      if (qpr3) then                                                            
        unamsp = umin(nm)                                                       
        call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                
      endif                                                                     
c                                                                               
      rdum=xlkm(nm)-cdrm(1,nm)*awlg                                             
      rdum=rdum-cdrm(nsq1,nm)*(xbarlg(ik,nx)+lamlg(ik,nx))                      
c                                                                               
      do 630 krow=2,ksq                                                         
      ns=iindx1(krow)                                                           
      cdum=cdrm(ns,nm)                                                          
      rdum=rdum-cdum*glgx(ns)                                                   
      if (kkndex(ns).ge.1) go to 630                                            
      rdum=rdum-cdum*zvclg1(krow)                                               
  630 continue                                                                  
c                                                                               
      rhs(irow)=rdum                                                            
      go to 690                                                                 
c                                                                               
  640 continue                                                                  
      if (jfdum.ne.21) go to 660                                                
      ng=nsp(nse)                                                               
      if (qpr3) then                                                            
        unamsp = ugas(ng)                                                       
        call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,noutpt)                
      endif                                                                     
c                                                                               
      rdum=xlkg(ng)-cdrg(1,ng)*awlg                                             
      rdum=rdum-cdrg(nsq1,ng)*csp(nse)                                          
c                                                                               
      do 650 krow=2,ksq                                                         
      ns=iindx1(krow)                                                           
      cdum=cdrg(ns,ng)                                                          
      rdum=rdum-cdum*glgx(ns)                                                   
      if (kkndex(ns).ge.1) go to 650                                            
      rdum=rdum-cdum*zvclg1(krow)                                               
  650 continue                                                                  
c                                                                               
      rhs(irow)=rdum                                                            
      go to 690                                                                 
c                                                                               
  660 continue                                                                  
      if (iopt1.ge.0) go to 670                                                 
      rdum=(4.*eh)/ehfac                                                        
      rdum=rdum+xlkeh+2.*awlg                                                   
      rdum=rdum-4.*glgx(nhydr)                                                  
      if (kkndex(nhydr).ge.1) go to 665                                         
      rdum=rdum-4.*zvclg1(khydr)                                                
  665 continue                                                                  
      rhs(irow)=rdum                                                            
      go to 690                                                                 
c                                                                               
  670 continue                                                                  
      nsc=iopt1+nsb                                                             
      rdum=xlks(iopt1)-cdrs(1,iopt1)*awlg                                       
c                                                                               
      do 675 ksc=2,ksq                                                          
      ns1=iindx1(ksc)                                                           
      if (ns1.eq.nsc) go to 680                                                 
  675 continue                                                                  
c                                                                               
  680 continue                                                                  
      cdum=cdrs(nsq1,iopt1)                                                     
      rdum=rdum-cdum*glgx(nsc)                                                  
      if (kkndex(nsc).ge.1) go to 682                                           
      rdum=rdum-cdum*zvclg1(ksc)                                                
  682 continue                                                                  
c                                                                               
      do 685 krow=2,ksq                                                         
      if (krow.eq.ksc) go to 685                                                
      ns=iindx1(krow)                                                           
      cdum=cdrs(ns,iopt1)                                                       
      rdum=rdum-cdum*glgx(ns)                                                   
      if (kkndex(ns).ge.1) go to 685                                            
      rdum=rdum-cdum*zvclg1(krow)                                               
  685 continue                                                                  
c                                                                               
      rhs(irow)=rdum                                                            
c                                                                               
  690 continue                                                                  
c                                                                               
      if (.not.qpr3) go to 689                                                  
      write (noutpt,686)                                                        
  686 format(/10x,'----- right-hand-side vector -----',/)                       
c                                                                               
      do 688 irow=1,isq                                                         
      idum=jjndex(irow)                                                         
      rdum=rhs(irow)                                                            
      write (noutpt,687) irow,jjndex(irow),rhs(irow)                            
  687 format(2x,2i5,3x,e13.6)                                                   
  688 continue                                                                  
c                                                                               
      write (noutpt,75)                                                         
  689 continue                                                                  
c                                                                               
  120 continue                                                                  
c                                                                               
      call msolvr(aa,gm,rhs,del,res,ee,ir,isq,kmax,ier,qfalse,                  
     $ qfalse)                                                                  
      if (ier .gt. 0) then                                                      
        write (noutpt,695)                                                      
  695   format(' --- msolvr (matrix solver) failed (arrsim)')                   
        write (noutpt,697)                                                      
        write (nttyo,697)                                                       
  697   format(/' * trouble- the speciation model appears to be',               
     $  ' singular (arrsim)',                                                   
     $  /7x,'probable apparent phase rule violation',/)                         
        stop                                                                    
      endif                                                                     
c                                                                               
      icol=0                                                                    
c                                                                               
      do 715 kcol=2,ksq                                                         
      ns1=iindx1(kcol)                                                          
      if (kkndex(ns1).le.0) go to 715                                           
      icol=icol+1                                                               
      zvclg1(kcol)=del(icol)                                                    
  715 continue                                                                  
c                                                                               
      if (.not.qpr3) go to 725                                                  
      write (noutpt,717)                                                        
c                                                                               
      do 723 irow=1,isq                                                         
      idum=jjndex(irow)                                                         
      ddum=del(irow)                                                            
      udum=uspec(idum)(1:8)                                                     
      write (noutpt,720) irow,idum,udum,ddum                                    
  723 continue                                                                  
c                                                                               
      write (noutpt,75)                                                         
  725 continue                                                                  
c                                                                               
c     check possible effects of large concentrations resulting from             
c     equilibrium constraints.                                                  
c                                                                               
      idum=isq                                                                  
      if (isb.gt.0) idum=idum-1                                                 
      if (idum.le.0) go to 740                                                  
      nerr=0                                                                    
c                                                                               
      do 735 krow=1,ksq                                                         
      ns=iindx1(krow)                                                           
      if (kkndex(ns).le.0) go to 735                                            
      if (ns.eq.nsb) go to 735                                                  
      zdum=zvclg1(krow)                                                         
      cdum=texp(zdum)                                                           
      if (cdum.le.20.) go to 735                                                
      ker=1                                                                     
      write (noutpt,727) uspec(ns),cdum                                         
  727 format(/' --- ',a12,' has a required concentration',                      
     $ ' near ',g12.5,' molal ---')                                             
      if (npass.le.1) go to 735                                                 
      if (cdum.le.100.) go to 735                                               
      nerr=nerr+1                                                               
  735 continue                                                                  
c                                                                               
      if (nerr.le.0) go to 738                                                  
      write (noutpt,737)                                                        
  737 format(/' --- reconsider your choice of input',                           
     $ ' constraints ---')                                                      
      ker=2                                                                     
      go to 999                                                                 
c                                                                               
  738 continue                                                                  
      if (ker.eq.1) write (noutpt,729)                                          
  729 format(6x,'this run may crash because of',                                
     $ ' poor choice of input constraints')                                     
c                                                                               
  740 continue                                                                  
  999 continue                                                                  
      end                                                                       
c balcon   last revised 10/30/87 by tjw                                         
      subroutine balcon(weight,jrs,krow)                                        
c                                                                               
c     local routine for  routine matrix                                         
c     compute matrix entries for one of the following -                         
c      mass balance constraint                                                  
c      charge balance constraint                                                
c      alkalinity balance constraint                                            
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      dimension stor1(nrstpa),jrs(*),weight(*)                                  
c                                                                               
      include "blank.h"                                                        
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nn.h"                                                           
      include "op.h"                                                           
      include "st.h"                                                           
      include "tt.h"                                                           
      include "yy.h"                                                           
      include "eqlgp.h"                                        
      include "eqlpp.h"                                        
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
c      build stor1 array                                                        
c                                                                               
      do 35 nrr=1,nrst                                                          
      stor1(nrr)=0.                                                             
      nrs=jrs(nrr)                                                              
      nsc=nrs+nsb                                                               
      if (nsc.gt.nsq) go to 32                                                  
      if (jflag(nsc).lt.30) go to 35                                            
   32 stor1(nrr)=conc(nsc)*weight(nsc)/cdrs(nsq1,nrs)                           
   35 continue                                                                  
c                                                                               
c     first column currently unused                                             
c                                                                               
c     build columns 2 to ksq                                                    
c                                                                               
      do 50 kcol=2,ksq                                                          
      nsc=iindx1(kcol)                                                          
      dum2=0.                                                                   
c                                                                               
      do 45 nrr=1,nrst                                                          
      nrs=jrs(nrr)                                                              
      dum2=dum2-stor1(nrr)*cdrs(nsc,nrs)                                        
   45 continue                                                                  
c                                                                               
      dum2=dum2+weight(nsc)*conc(nsc)                                           
      aa(krow,kcol)=al10*dum2                                                   
   50 continue                                                                  
c                                                                               
      sum1=0.                                                                   
      do 40 nrr=1,nrst                                                          
      nrs=jrs(nrr)                                                              
      sum1=sum1-stor1(nrr)*cdrs(1,nrs)                                          
   40 continue                                                                  
c                                                                               
  999 continue                                                                  
      end                                                                       
c betas    last revised 12/14/87 by tjw                                         
      subroutine betas(qcfrac,qabsw)                                            
c                                                                               
c     this routine computes the newton-raphson residual functions.              
c     the calling sequence of betas.f must be identical in form to              
c     that of eq6's betaz.f, because both are referenced by eqlib's             
c     nrstep.f via a dummy external.                                            
c                                                                               
c     input                                                                     
c       qcfrac = flag to get bfac array for continued fraction                  
c         calculations in arrset                                                
c       qabsw = flag to find choices for auto basis switching                   
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "an.h"                                                           
      include "bt.h"                                                           
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nn.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "st.h"                                                           
      include "tt.h"                                                           
      include "tu.h"                                                           
      include "un.h"                                                           
      include "uu.h"                                                           
      include "vv.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "eqldd.h"                                        
      include "eqlgp.h"                                        
      include "eqlpp.h"                                        
c                                                                               
      data unone/'none    '/                                                    
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      do 2 krow=1,kdim                                                          
      alpha(krow)=0.                                                            
      beta(krow)=0.                                                             
    2 continue                                                                  
c                                                                               
      do 3 krow=1,ksq                                                           
      ibswx(krow)=0                                                             
      nfac(krow)=0                                                              
      bfac(krow)=1.0                                                            
      efac(krow)=1.0                                                            
    3 continue                                                                  
      qbswx=.false.                                                             
c                                                                               
c     first residual currently defined as zero                                  
c                                                                               
c     compute residuals 2 through ksq.                                          
c                                                                               
c - - - - - - - - - - begin main loop - - - - - - - - - - - - - - - - -         
      do 400 krow=2,ksq                                                         
      nse=iindx1(krow)                                                          
c      test for charge balance                                                  
      if (nse.eq.iebal) go to 30                                                
      jfdum=jflag(nse)                                                          
c      test for mineral equilibrium                                             
      if (jfdum.eq.19) go to 170                                                
      if (jfdum.eq.20) go to 170                                                
c      test for gas equilibrium                                                 
      if (jfdum.eq.21) go to 220                                                
c      test for log fo2                                                         
      if (nse.eq.nsb) go to 300                                                 
c      test for mass balance                                                    
      if (jfdum.eq.0) go to 5                                                   
c      test for alkalinity balance                                              
      if (jfdum.eq.10) go to 70                                                 
c      test for specified activity                                              
      if (jfdum.eq.16) go to 110                                                
c      test for aqueous homogeneous equilibrium                                 
      if (jfdum.eq.27) go to 700                                                
c      test for alkalinity balance                                              
      if (jfdum.eq.12) go to 70                                                 
c      test for free concentration                                              
      if (jfdum.eq.4) go to 140                                                 
      write (noutpt,1000) jfdum,uspec(nse)                                      
 1000 format(1x,'illegal jflag value = ',i5,' encountered for ',                
     $ a18,' in betas')                                                         
      write(nttyo,1010)                                                         
 1010 format(' * illegal jflag value, routine betas')                           
      stop                                                                      
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c        mass balance.                                                          
c                                                                               
    5 do 7 ns = 1,nst                                                           
      store(ns) = csts(nse,ns)                                                  
    7 continue                                                                  
c                                                                               
      dum = 0.                                                                  
      do 10 nss = 1,nst                                                         
      ns = jsort(nss)                                                           
      dum = dum + store(ns)*conc(ns)                                            
   10 continue                                                                  
c                                                                               
      ctot=csp(nse)                                                             
      adum=dum-ctot                                                             
      alpha(krow)=adum                                                          
      bdum=adum/ctot                                                            
      beta(krow)=bdum                                                           
c                                                                               
c     find the species that makes the largest contribution to the               
c     mass balance.                                                             
c                                                                               
      if (qcfrac) then                                                          
        call fdomsp(nse,jsort,store,conc,nst,nsj,sdum)                          
        efac(krow)=1./sdum                                                      
        nfac(krow)=nsj                                                          
      endif                                                                     
c                                                                               
c     pick candidates for automatic basis switching.  this involves             
c     a search similar to the one above, but with a variety of special          
c     constraints.  the indices of candidates are stored in the array           
c     ibswx.                                                                    
c                                                                               
      if (qabsw) then                                                           
        ibswx(krow)=0                                                           
        call fbassw(nse,jsort,store,conc,ibasis,jflag,nsb,nsq,nst,              
     $  nsi,si)                                                                 
        if (nsi.gt.0) then                                                      
          rconc=conc(nsi)/conc(nse)                                             
          if (rconc.gt.10.) then                                                
            ibswx(krow)=nsi                                                     
            qbswx=.true.                                                        
          endif                                                                 
        endif                                                                   
      endif                                                                     
c                                                                               
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        charge balance.                                                        
c                                                                               
   30 continue                                                                  
c                                                                               
      call gszm(z,conc,jsort,nst,sigzc,sigza,sigzm,sigzi)                       
c                                                                               
      alpha(krow)=sigzi                                                         
      beta(krow)=sigzi/sigzm                                                    
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        alkalinity balance.                                                    
c                                                                               
   70 continue                                                                  
      dum=0.                                                                    
c                                                                               
      do 75 nss=1,nst                                                           
      ns=jsort(nss)                                                             
      dum=dum+titr(ns)*conc(ns)                                                 
   75 continue                                                                  
c                                                                               
      atot=csp(nse)                                                             
      adum=dum-atot                                                             
      alpha(krow)=adum                                                          
      beta(krow)=adum/atot                                                      
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        specified activity.                                                    
c                                                                               
  110 continue                                                                  
      dum=conclg(nse)+glg(nse)-csp(nse)                                         
      alpha(krow)=dum                                                           
      beta(krow)=dum                                                            
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        specified free concentration.                                          
c                                                                               
  140 continue                                                                  
      alpha(krow)=0.                                                            
      beta(krow)=0.                                                             
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        specified mineral equilibrium.                                         
c                                                                               
  170 continue                                                                  
      nm=nsp(nse)                                                               
      cdum=0.                                                                   
      if (nm.lt.50000) go to 175                                                
      nm=nm-50000                                                               
      nx=int(nm/100.)                                                           
      ik=nm-100*nx                                                              
      nm=nend(ik,nx)                                                            
      cdum=-cdrm(nsq1,nm)*(xbarlg(ik,nx)+lamlg(ik,nx))                          
  175 continue                                                                  
      cdum=cdum+xlkm(nm)-cdrm(1,nm)*actlg(1)-cdrm(nse,nm)*glg(nse)              
      if (nse.eq.nsb) go to 180                                                 
      cdum=cdum-cdrm(nsb,nm)*fo2lg                                              
  180 continue                                                                  
c                                                                               
      do 185 kcol=2,ksq                                                         
      if (kcol.eq.ksb) go to 185                                                
      if (kcol.eq.krow) go to 185                                               
      ns=iindx1(kcol)                                                           
      cdum=cdum-cdrm(ns,nm)*(conclg(ns)+glg(ns))                                
  185 continue                                                                  
c                                                                               
      cdum=cdum/cdrm(nse,nm)                                                    
      cdum1=conclg(nse)                                                         
      if (nse.eq.nsb) cdum1=fo2lg                                               
      dum=cdum-cdum1                                                            
      alpha(krow)=dum                                                           
      beta(krow)=dum                                                            
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        specified gas equilibrium.                                             
c                                                                               
  220 continue                                                                  
      ng=nsp(nse)                                                               
      cdum=-cdrg(nsq1,ng)*csp(nse)                                              
      cdum=cdum+xlkg(ng)-cdrg(1,ng)*actlg(1)-cdrg(nse,ng)*glg(nse)              
      if (nse.eq.nsb) go to 225                                                 
      cdum=cdum-cdrg(nsb,ng)*fo2lg                                              
  225 continue                                                                  
c                                                                               
      do 230 kcol=2,ksq                                                         
      if (kcol.eq.ksb) go to 230                                                
      if (kcol.eq.krow) go to 230                                               
      ns=iindx1(kcol)                                                           
      cdum=cdum-cdrg(ns,ng)*(conclg(ns)+glg(ns))                                
  230 continue                                                                  
c                                                                               
      cdum=cdum/cdrg(nse,ng)                                                    
      cdum1=conclg(nse)                                                         
      if (nse.eq.nsb) cdum1=fo2lg                                               
      dum=cdum-cdum1                                                            
      alpha(krow)=dum                                                           
      beta(krow)=dum                                                            
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        specified aqueous homogeneous equilibrium.                             
c                                                                               
  700 continue                                                                  
      nrs=nse-nsb                                                               
      cdum=xlks(nrs)-cdrs(1,nrs)*actlg(1)-cdrs(nsq1,nrs)*glg(nse)               
      cdum=cdum-cdrs(nsb,nrs)*fo2lg                                             
c                                                                               
      do 705 kcol=2,ksq                                                         
      if (kcol.eq.ksb) go to 705                                                
      if (kcol.eq.krow) go to 705                                               
      ns=iindx1(kcol)                                                           
      cdum=cdum-cdrs(ns,nrs)*(conclg(ns)+glg(ns))                               
  705 continue                                                                  
c                                                                               
      cdum=cdum/cdrs(nsq1,nrs)                                                  
      cdum1=conclg(nse)                                                         
      dum=cdum-cdum1                                                            
      alpha(krow)=dum                                                           
      beta(krow)=dum                                                            
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        compute the log fo2 residual.                                          
c                                                                               
  300 continue                                                                  
      if (iopt1.ne.0) go to 310                                                 
c                                                                               
c           log fo2 directly specified                                          
c                                                                               
      alpha(krow)=0.                                                            
      beta(krow)=0.                                                             
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c           eh residual (note--an input p e- value has been                     
c           converted to an eh value by routine setup)                          
c                                                                               
  310 continue                                                                  
      if (iopt1.ge.1) go to 330                                                 
      fdum=(4*eh)/ehfac                                                         
      fdum=fdum+xlkeh+2.*actlg(1)-4.*(conclg(nhydr)+glg(nhydr))                 
      dum=fdum-fo2lg                                                            
      alpha(krow)=dum                                                           
      beta(krow)=dum                                                            
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c           cross-linking (homogeneous aqueous redox) equilibrium.              
c                                                                               
  330 continue                                                                  
      fdum=xlks(iopt1)-cdrs(1,iopt1)*actlg(1)                                   
      nsc=iopt1+nsb                                                             
      fdum=fdum-cdrs(nsq1,iopt1)*(conclg(nsc)+glg(nsc))                         
c                                                                               
      do 335 kcol=2,ksq                                                         
      if (kcol.eq.ksb) go to 335                                                
      ns=iindx1(kcol)                                                           
      fdum=fdum-cdrs(ns,iopt1)*(conclg(ns)+glg(ns))                             
  335 continue                                                                  
c                                                                               
      fdum=fdum/cdrs(nsb,iopt1)                                                 
      dum=fdum-fo2lg                                                            
      alpha(krow)=dum                                                           
      beta(krow)=dum                                                            
c                                                                               
  400 continue                                                                  
c - - - - - - - - - - end main loop - - - - - - - - - - - - - - - - - -         
c                                                                               
      betamx=0.                                                                 
      ibetmx=0                                                                  
c                                                                               
c      test for kill debug option                                               
c                                                                               
      if (iodb3 .le. 0) go to 549                                               
      do 547 kcol=1,kdim                                                        
      if (kill(kcol) .eq. 0) go to 547                                          
      alpha(kcol) = 0.                                                          
      beta(kcol) = 0.                                                           
  547 continue                                                                  
  549 continue                                                                  
c                                                                               
c     get characteristic residual parameters                                    
c       betamx = value of largest abs(beta)                                     
c       ibetmx = iindx1 of largest abs(beta)                                    
c       bbig = value of largest (positive) mass balance residual                
c       ubbig = name of corresponding species                                   
c       bneg = value of largest (negative) mass balance residual                
c       ubneg = name of corresponding species                                   
c                                                                               
      do 550 kcol=1,kdim                                                        
      abeta=abs(beta(kcol))                                                     
      if (abeta.le.betamx) go to 550                                            
      betamx=abeta                                                              
      ibetmx=kcol                                                               
  550 continue                                                                  
c                                                                               
      bbig=0.                                                                   
      bneg=0.                                                                   
      ubbig=unone                                                               
      ubneg=unone                                                               
      do 725 kcol=2,ksq                                                         
      if (kcol.eq.ksb) go to 725                                                
      ns=iindx1(kcol)                                                           
      if (ns.eq.nhydr) go to 725                                                
      if (jflag(ns).gt.15) go to 725                                            
      bdum=beta(kcol)                                                           
      if (bdum.lt.bneg) then                                                    
        bneg=bdum                                                               
        ubneg=uspec(ns)                                                         
      elseif (bdum.gt.bbig) then                                                
        bbig=bdum                                                               
        ubbig=uspec(ns)                                                         
      endif                                                                     
  725 continue                                                                  
c                                                                               
      end                                                                       
c echox    last revised 12/11/87 by tjw                                         
      subroutine echox                                                          
c                                                                               
c     this routine echoes the problem input defining the compositional          
c     constraints on the aqueous solution being modeled and the                 
c     options and tolerances selected.                                          
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "an.h"                                                           
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nx.h"                                                           
      include "oo.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "ps.h"                                                           
      include "si.h"                                                           
      include "te.h"                                                           
      include "ti.h"                                                           
      include "tt.h"                                                           
      include "un.h"                                                           
      include "uu.h"                                                           
      include "eqlver.h"                                                       
      include "vv.h"                                                           
      include "vw.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "eqlpp.h"                                        
      include "eqldd.h"                                        
      include "eqlgp.h"                                        
c                                                                               
      character*24 uvacnt,ublank,unone,unamsp                                   
c                                                                               
      data uvacnt/'vacant                  '/                                   
      data ublank/'                        '/                                   
      data unone/'none                    '/                                    
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      write (noutpt,265)                                                        
  265 format(//////1x,                                                          
     $ 'eeee   qqq   33333  n   n  rrrr   ',/1x,                                
     $ 'e     q   q      3  nn  n  r   r  ',/1x,                                
     $ 'eeee  q   q    33   n n n  rrrr   ',/1x,                                
     $ 'e     q q q      3  n  nn  r  r   ',/1x,                                
     $ 'eeee   qqq   3333   n   n  r   r  ',/1x,                                
     $ '          q                       ',///,

     $ 'MODIFIED FOR DEW CALCULATIONS     ',///)                                
      write(noutpt,267) urelno,ustage,ueqlrn,ueqlst                             
  267 format(1x,'eq3nr.',a4,a4,/,2x,'supported by eqlib.',a4,a4,//)             
c                                                                               
      do 284 n=1,ntitl                                                          
      write (noutpt,285) utitl(n)                                               
  285 format(1x,a80)                                                            
  284 continue                                                                  
c                                                                               
      write (noutpt,270)                                                        
  270 format(1x)                                                                
c                                                                               
      do 272 n=1,4                                                              
      write (noutpt,285) utitld(n)                                              
  272 continue                                                                  
c                                                                               
      write (noutpt,730) uactop                                                 
  730 format(/3x,'the activity coefficients of aqueous solute species',/        
     $ 1x,'and the activity of water are calculated according to',/             
     $ 1x,a32,/)                                                                
      if (qhydth) then                                                          
        if (iopg4.eq.0) then                                                    
          write (noutpt,750)                                                    
  750     format(3x,'dh(o/c)a = debye-huckel-osmotic-azero form')               
        else                                                                    
          write (noutpt,757)                                                    
  757     format(3x,'dh(o/c)a = debye-huckel-charging-azero form')              
        endif                                                                   
      endif                                                                     
      if (iopg1.eq.1) then                                                      
        write(noutpt,285) udpitz                                                
      elseif (iopg1 .eq. 5) then                                                
        write(noutpt,285) udhkf                                                 
      endif                                                                     
      if (iopg1.ge.1) write (noutpt,732) uelam                                  
  732 format(/3x,'uelam= ',a6)                                                  
      if (qhydth) then                                                          
        if (iopr8.ge.0) then                                                    
          write (noutpt,731)                                                    
  731     format(/7x,'species',7x,'ion size',3x,'hydr. no.',/)                  
          do 736 ns=2,nst                                                       
          if (jsflag(ns).gt.0) go to 736                                        
          write (noutpt,734) uspec(ns),azero(ns),hydn(ns)                       
  734     format(5x,a12,3x,f7.3,3x,f7.3)                                        
  736     continue                                                              
        endif                                                                   
      endif                                                                     
c                                                                               
      write (noutpt,270)                                                        
      write (noutpt,275) tempc,press                                            
  275 format(/1x,'temperature= ',f6.2,' degrees celsius',                       
     $ /1x,'pressure= ',f9.4,' bars',/)                                         
c                                                                               
      write (noutpt,270)                                                        
      kct=0                                                                     
      do 245 nc=1,nct                                                           
      if (jcflag(nc).le.0) go to 245                                            
      kct=kct+1                                                                 
  245 continue                                                                  
      write (noutpt,280) nct,nctmax,kct                                         
  280 format(6x,i5,' elements are in the data base',/                           
     $ 6x,i5,' elements can be loaded into memory',/                            
     $ 6x,i5,' elements are active in this problem',//)                         
      write (noutpt,281) ist,nst,nstmax,jst,irst,nrst,nrstmx                    
  281 format(6x,i5,' aqueous species are in the data base',/                    
     $ 6x,i5,' aqueous species were loaded into memory',/                       
     $ 6x,i5,' aqueous species can be loaded into memory',/                     
     $ 6x,i5,' aqueous species are active in this problem',//                   
     $ 6x,i5,' aqueous reactions are in the data base',/                        
     $ 6x,i5,' aqueous reactions were loaded into memory',/                     
     $ 6x,i5,' aqueous reactions can be loaded into memory',//)                 
      write (noutpt,282) imt,nmt,nmtmax,jmt,nxt,nxtmax                          
  282 format(11x,i5,' minerals are in the data base',/                          
     $ 11x,i5,' minerals were loaded into memory',/                             
     $ 11x,i5,' minerals can be loaded into memory',/                           
     $ 11x,i5,' minerals are active in this problem',//                         
     $ 11x,i5,' solid solutions are in the data base',/                         
     $ 11x,i5,' solid solutions can be loaded into memory',/                    
     $ 11x,i5,' solid solutions are active in this problem',//)                 
      write (noutpt,283) igt,ngt,ngtmax,jgt                                     
  283 format(11x,i5,' gases are in the data base',/                             
     $ 11x,i5,' gases were loaded into memory',/                                
     $ 11x,i5,' gases can be loaded into memory',/                              
     $ 11x,i5,' gases are active in this problem',//)                           
      write (noutpt,295) iopt1,iopt2,iopt3,iopt4,iopt5,iopt6,iopt7,             
     $ iopt8,iopt9,iopt10                                                       
  295 format(//6x,'iopt1  = ',i2,' (redox option switch)',/                     
     $ 6x,'iopt2  = ',i2,' (automatic basis switching switch)',/                
     $ 6x,'iopt3  = ',i2,' (interfacing output control switch)',/               
     $ 6x,'iopt4  = ',i2,' (turn-on solid solutions switch)',/                  
     $ 6x,'iopt5  = ',i2,' (not used)',/                                        
     $ 6x,'iopt6  = ',i2,' (conv. test criteria switch)',/                      
     $ 6x,'iopt7  = ',i2,' (0/1 3245/post-3245 pickup file)',/                  
     $ 6x,'iopt8  = ',i2,' (not used)',/                                        
     $ 6x,'iopt9  = ',i2,' (not used)',/                                        
     $ 6x,'iopt10 = ',i2,' (not used)',/)                                       
      write (noutpt,298) iopg1,iopg2,iopg3,iopg4,iopg5,iopg6,iopg7,             
     $ iopg8,iopg9,iopg10                                                       
  298 format(//11x,'iopg1  = ',i2,' (act. coeff. choice)',/                     
     $ 11x,'iopg2  = ',i2,' (ph scale convention switch)',/                     
     $ 11x,'iopg3  = ',i2,' (iopg1=3 - 0/1 uelam= on/onplus)',/                 
     $ 11x,'iopg4  = ',i2,' (iopg1=3 or 4 - f switch - 0/1 dhoa/dhca)',/        
     $ 11x,'iopg5  = ',i2,' (gamC 0: omega-hat (C is 2nd bs), 1: bdot*xi)',/
     $ 11x,'iopg6  = ',i2,' (approx. of j(x) function)',/                       
     $ 11x,'iopg7  = ',i2,' (a(H2O)=1 if =0, a(H2O)=X(H2O) if =1)',/
     $ 11x,'iopg8  = ',i2,' (if =1 then uses high T range 650-1000 C)',/
     $ 11x,'iopg9  = ',i2,' (position of C in the datafile)',/                            
     $ 11x,'iopg10 = ',i2,' (not used)',/)                                      
      write (noutpt,296) iopr1,iopr2,iopr3,iopr4,iopr5,iopr6,iopr7,             
     $ iopr8,iopr9,iopr10                                                       
  296 format(/16x,'iopr1  = ',i2,' (list loading of species)',/                 
     $ 16x,'iopr2  = ',i2,' (list reactions and log k values)',/                
     $ 16x,'iopr3  = ',i2,' (aqueous species print order control)',/            
     $ 16x,'iopr4  = ',i2,' (aqueous species print cut-off control)',/          
     $ 16x,'iopr5  = ',i2,' (mass balance percentages print control)',/         
     $ 16x,'iopr6  = ',i2,' (mean ionic act coeff print control)',/             
     $ 16x,'iopr7  = ',i2,' (mineral affinity print control)',/                 
     $ 16x,'iopr8  = ',i2,' (ion size and hydr. no. print control)',/           
     $ 16x,'iopr9  = ',i2,' (pitzer coefficients tabulation)',/                 
     $ 16x,'iopr10 = ',i2,' (print concbs array)')                              
      write (noutpt,420) iopr11,iopr12,iopr13,iopr14,iopr15,                    
     $ iopr16,iopr17,iopr18,iopr19,iopr20                                       
  420 format(16x,'iopr11 = ',i2,' (not used)',/                                 
     $ 16x,'iopr12 = ',i2,' (not used)',/                                       
     $ 16x,'iopr13 = ',i2,' (not used)',/                                       
     $ 16x,'iopr14 = ',i2,' (not used)',/                                       
     $ 16x,'iopr15 = ',i2,' (not used)',/                                       
     $ 16x,'iopr16 = ',i2,' (not used)',/                                       
     $ 16x,'iopr17 = ',i2,' (not used)',/                                       
     $ 16x,'iopr18 = ',i2,' (not used)',/                                       
     $ 16x,'iopr19 = ',i2,' (not used)',/                                       
     $ 16x,'iopr20 = ',i2,' (not used)',/)                                      
      write (noutpt,297) iodb1,iodb2,iodb3,iodb4,iodb5,iodb6,iodb7,             
     $   iodb8,iodb9,iodb10                                                     
  297 format(/21x,'iodb1  = ',i2,' (print info. messages switch)',/             
     $ 21x,'iodb2  = ',i2,' (print pre-newton-raphson optimizations',           
     $ ' switch)',/                                                             
     $ 21x,'iodb3  = ',i2,' (request iteration variables to kill)',/            
     $ 21x,'iodb4  = ',i2,' (print newton-raphson iterations switch)',/         
     $ 21x,'iodb5  = ',i2,' (list stoichiometric equivalences)',/               
     $ 21x,'iodb6  = ',i2,' (controls iodb5 level of detail)',/                 
     $ 21x,'iodb7  = ',i2,' (write reactions on file rlist switch)',/,          
     $ 21x,'iodb8  = ',i2,' (not used)',/,                                      
     $ 21x,'iodb9  = ',i2,' (not used)',/,                                      
     $ 21x,'iodb10 = ',i2,' (not used)',/)                                      
c                                                                               
      jfdum=jflag(nsb)                                                          
      if (iopt1.le.0) go to 410                                                 
      write (noutpt,405) uredox                                                 
  405 format(/6x,'the default redox state is constrained by the',               
     $ ' couple associated with',/6x,'the auxiliary basis species ',            
     $ a12)                                                                     
      go to 309                                                                 
c                                                                               
  410 if (iopt1.ne.0) go to 423                                                 
      write (noutpt,303) fo2lg                                                  
  303 format(/6x,'the default redox state is constrained by',                   
     $ ' log fo2 = ',f12.4,' (log bars)')                                       
      go to 309                                                                 
c                                                                               
  423 if (iopt1.ne.-3) go to 309                                                
      write (noutpt,427)                                                        
  427 format(/6x,'the default redox state is controlled by a',                  
     $ ' heterogeneous reaction -- see below')                                  
      go to 309                                                                 
c                                                                               
  307 if (iopt1.ne.-1) go to 308                                                
      write (noutpt,301) eh                                                     
  301 format(/6x,'the default redox state is constrained by eh = ',             
     $ f8.5,' volts')                                                           
      go to 309                                                                 
c                                                                               
  308 write (noutpt,302) pe                                                     
  302 format(/6x,'the default redox state is constrained by pe = ',             
     $ e13.6)                                                                   
c                                                                               
  309 write (noutpt,300) rho,tdspkg,tdspl                                       
  300 format(//16x,'solution density = ',f8.5,' g/ml',//                        
     $ 16x,'total dissolved salts = ',f10.2,' mg/kg solution',/                 
     $ 16x,'total dissolved salts = ',f10.2,' mg/l',/)                          
      write (noutpt,305) tolbt,toldl,tolsat                                     
  305 format(/11x,'tolbt  = ',e12.5,' (convergence tolerance on',               
     $ ' residual functions)',/11x,'toldl  = ',e12.5,' (convergence',           
     $ ' tolerance on correction terms)',/11x,'tolsat = ',e12.5,                
     $ ' (phase saturation tolerance, does not affect',/33x,                    
     $ ' convergence)',/)                                                       
c                                                                               
      write (noutpt,287)                                                        
  287 format(//36x,'----- input constraints -----',/)                           
      write (noutpt,290)                                                        
  290 format(5x,'species          csp       jflag ',                            
     $ ' type of input      controlling phase',/)                               
c                                                                               
      do 520 ns=1,nsqb                                                          
      jk=jflagb(ns)                                                             
      if(jk .lt. 0) go to 520                                                   
      cdum=cspb(ns)                                                             
      if (jk.eq.0.and.cdum.eq.0.) go to 520                                     
      k=jk+1                                                                    
      ns1=nspec(ns)                                                             
      ns2=ibasis(ns1)                                                           
      if (ns2.eq.ns1) go to 292                                                 
      write (noutpt,315) uspecb(ns),cdum,jk,ujtype(k),uphas1(ns)                
  315 format(3x,a24,3x,e12.5,3x,i2,3x,a24,3x,a24)                               
      write (noutpt,316) uspec(ns2)                                             
  316 format(5x,'switch with ',a24)                                             
      go to 293                                                                 
  292 write (noutpt,315) uspecb(ns),cdum,jk,ujtype(k),uphas1(ns)                
  293 if (jk.ne.19.and.jk.ne.20) go to 425                                      
      nx=0                                                                      
      nm=nsp(ns1)                                                               
      if (nm.le.50000) go to 415                                                
      nm=nm-50000                                                               
      nx=int(nm/100.)                                                           
      ik=nm-100*nx                                                              
      nm=nend(ik,nx)                                                            
  415 unamsp = umin(nm)                                                         
      call prreac(cdrm,uspec,unamsp,nm,nsq,nsq1,nsqmx1,noutpt)                  
c                                                                               
      go to 185                                                                 
  425 if (jk.ne.21) go to 185                                                   
      ng=nsp(ns1)                                                               
      unamsp = ugas(ng)                                                         
      call prreac(cdrg,uspec,unamsp,ng,nsq,nsq1,nsqmx1,noutpt)                  
c                                                                               
  185 continue                                                                  
c                                                                               
      if (ns1.le.nsb) go to 520                                                 
      nrs=ns1-nsb                                                               
      do 510 ndum=2,nsq                                                         
      cdum=cdrs(ndum,nrs)                                                       
      if (cdum.eq.0.) go to 510                                                 
      if (jflag(ndum).ge.0) go to 510                                           
      if (ndum.eq.ns2) go to 510                                                
      write (noutpt,505) uspec(ndum)                                            
  505 format(' --- note- ',a12,' is not in the model ---',/)                    
  510 continue                                                                  
c                                                                               
  520 continue                                                                  
c                                                                               
      if (iopt4.ne.2) go to 195                                                 
      if (nxtb.le.0) go to 195                                                  
      write (noutpt,323)                                                        
  323 format(//21x,'----- input solid solution compositions -----',/)           
      do 190 nx=1,nxt                                                           
      ncpt=ncomp(nx)                                                            
      do 327 ik=1,ncpt                                                          
      xdum=xbar(ik,nx)                                                          
      if (xdum.ne.0.) go to 329                                                 
  327 continue                                                                  
      go to 190                                                                 
  329 continue                                                                  
      write (noutpt,325) usolx(nx)                                              
  325 format(/6x,a18,/)                                                         
      write (noutpt,328)                                                        
  328 format(30x,'mole fraction')                                               
      do 188 ik=1,ncpt                                                          
      nm=nend(ik,nx)                                                            
      write (noutpt,330) umin(nm),xbar(ik,nx)                                   
  330 format(12x,a18,3x,f6.4)                                                   
  188 continue                                                                  
  190 continue                                                                  
  195 continue                                                                  
      write (noutpt,270)                                                        
c                                                                               
      end                                                                       
c flgstx   last revised 12/09/87 by tjw                                         
      subroutine flgstx(ars,amn,ags,uspec,umin,ugas,usolx,uxmod,                
     $ jkflag,nend,jsflag,jmflag,jgflag,jxflag,jflag,ncomp,jxmod,               
     $ kxmod,iopt4,jst,jmt,jgt,jxt,nxmod,ntpr,nsb,nsq,nst,nrst,                 
     $ nmt,ngt,nxt,iktmax,narxmx,ntprmx,noutpt,nttyo)                           
c                                                                               
c     this routine sets up the status arrays jsflag, jmflag,jkflag,             
c     jxflag, and jgflag.                                                       
c                                                                               
      include "implicit.h"                                                      
c                                                                               
      character*(*) uspec(*),umin(*),ugas(*),usolx(*),uxmod(*)                  
c                                                                               
      dimension ars(narxmx,ntprmx,*),amn(narxmx,ntprmx,*),                      
     $ ags(narxmx,ntprmx,*),jkflag(iktmax,*),nend(iktmax,*),                    
     $ jsflag(*),jmflag(*),jgflag(*),jxflag(*),jflag(*),ncomp(*),               
     $ jxmod(*),kxmod(*)                                                        
c                                                                               
c------------------------------------------------------------------             
c                                                                               
c        jsflag = control array for aqueous species                             
c           = 0   normal status                                                 
c           = 2   thermodynamically suppressed                                  
c           = 3   not present in a system of this composition                   
c                   or suppressed by jflag = -1 on the input file               
c                                                                               
c        jmflag = control array for pure minerals                               
c           = 0   normal status                                                 
c           = 2   thermodynamically suppressed                                  
c                                                                               
c        jkflag = control array for solid-solution end-members                  
c           (same as for jmflag)                                                
c                                                                               
c        jxflag = control array for solid-solution phases                       
c           = 0   normal status                                                 
c           = 4   ignored, components are not present or are                    
c              thermodynamically suppressed                                     
c                                                                               
c        jgflag = control array for gas species                                 
c           (same as for jmflag)                                                
c                                                                               
c------------------------------------------------------------------             
c                                                                               
      do 3 ns=1,nst                                                             
      jsflag(ns)=0                                                              
    3 continue                                                                  
      jsflag(nsb)=2                                                             
c                                                                               
      do 15 nrs=1,nrst                                                          
      nsc=nrs+nsb                                                               
      if (nsc.gt.nsq) go to 10                                                  
      if (jflag(nsc).eq.27) go to 10                                            
      if (jflag(nsc).eq.30) go to 10                                            
      go to 15                                                                  
   10 if (ars(1,ntpr,nrs).ge.500.) jsflag(nsc)=2                                
   15 continue                                                                  
c                                                                               
      do 45 ns=1,nsq                                                            
      if (jflag(ns).lt.0) jsflag(ns)=3                                          
   45 continue                                                                  
c                                                                               
      do 65 nm=1,nmt                                                            
      jmflag(nm)=0                                                              
      if (amn(1,ntpr,nm).ge.500.) jmflag(nm)=2                                  
   65 continue                                                                  
c                                                                               
      do 145 ng=1,ngt                                                           
      jgflag(ng)=0                                                              
      if (ags(1,ntpr,ng).ge.500.) jgflag(ng)=2                                  
  145 continue                                                                  
c                                                                               
      if (iopt4.le.0) go to 115                                                 
      if (nxt.le.0) go to 115                                                   
      do 95 nx=1,nxt                                                            
      jxflag(nx)=0                                                              
      nsupc=0                                                                   
      ncpt=ncomp(nx)                                                            
      do 90 ik=1,ncpt                                                           
      nm=nend(ik,nx)                                                            
      if (nm.le.0) go to 87                                                     
      jdum=jmflag(nm)                                                           
      if (jdum.lt.2) go to 88                                                   
   87 jdum=4                                                                    
      nsupc=nsupc+1                                                             
   88 jkflag(ik,nx)=jdum                                                        
   90 continue                                                                  
      if ((ncpt-nsupc).gt.1) go to 95                                           
      jxflag(nx)=4                                                              
   95 continue                                                                  
  115 continue                                                                  
c                                                                               
      call supprs(nxmod,jxmod,kxmod,uxmod,uspec,umin,ugas,                      
     $ usolx,jsflag,jmflag,jgflag,jxflag,nst,nmt,ngt,nxt,noutpt,nttyo)          
c                                                                               
      jst=0                                                                     
      do 50 ns=1,nst                                                            
      if (jsflag(ns).le.0) jst=jst+1                                            
   50 continue                                                                  
c                                                                               
      jmt=0                                                                     
      do 80 nm=1,nmt                                                            
      if (jmflag(nm).le.0) jmt=jmt+1                                            
   80 continue                                                                  
c                                                                               
      jgt=0                                                                     
      do 150 ng=1,ngt                                                           
      if (jgflag(ng).le.0) jgt=jgt+1                                            
  150 continue                                                                  
c                                                                               
      jxt=0                                                                     
      if (iopt4.le.0) go to 999                                                 
      do 110 nx=1,nxt                                                           
      if (jxflag(nx).le.0) jxt=jxt+1                                            
  110 continue                                                                  
c                                                                               
  999 continue                                                                  
      end                                                                       
c gases    last revised 05/20/87 by rlh                                         
      subroutine gases                                                          
c                                                                               
c     24jul86 by tjw                                                            
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "bt.h"                                                           
      include "cc.h"                                                           
      include "fg.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "tt.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "eqldd.h"                                        
      include "eqlpp.h"                                        
c                                                                               
c-------------------------------------------------------------------            
c                                                                               
      do 30 ng=1,ngt                                                            
      fuglg(ng)=-999.                                                           
      fug(ng)=0.                                                                
      if (jgflag(ng).ge.2) go to 30                                             
      fdum=-xlkg(ng)+cdrg(nsb,ng)*fo2lg                                         
      fdum=fdum+cdrg(1,ng)*actlg(1)                                             
      do 25 ns=2,nsq                                                            
      cdum=cdrg(ns,ng)                                                          
      if (cdum.eq.0.) go to 25                                                  
      if (ns.eq.nsb) go to 25                                                   
      if (jsflag(ns).ge.2) go to 30                                             
      fdum=fdum+cdum*actlg(ns)                                                  
   25 continue                                                                  
      fdum=-fdum/cdrg(nsq1,ng)                                                  
      fuglg(ng)=fdum                                                            
      fug(ng)=texp(fdum)                                                        
   30 continue                                                                  
c                                                                               
      end                                                                       
c gcsp     last revised 12/19/87 by tjw                                         
c*gcsp created in f77 12/18/87 by tjw                                           
      subroutine gcsp(csp,cspb,uspecb,uspecd,jflag,jflagb,                      
     $ nspec,is,nsqb,nsb,nerr,noutpt,nttyo)                                     
c                                                                               
c     this routine sets up the jflag and csp arrays for aqueous                 
c     species in the basis set.  the nsp array is set up in routine             
c     indatx after the minerals, gases, and solid solutions have                
c     been read in.                                                             
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      character*(*) uspecb(*),uspecd                                            
c                                                                               
      dimension csp(*),cspb(*),jflag(*),jflagb(*),nspec(*)                      
c                                                                               
c------------------------------------------------------------------             
c                                                                               
      jflag(is) = -1                                                            
      if (is .gt. nsb) jflag(is) = 30                                           
      csp(is) = 0.                                                              
c                                                                               
      do 100 ns = 1,nsqb                                                        
      if (uspecd(1:18) .ne. uspecb(ns)(1:18)) go to 100                         
      if (nspec(ns) .gt. 0) then                                                
        write (noutpt,1000) uspecd                                              
        write (nttyo,1000) uspecd                                               
 1000   format(/' * error- ',a24,' was specified more than',                    
     $  /7x,'once on the input file (gcsp)')                                    
        nerr = nerr + 1                                                         
        go to 999                                                               
      endif                                                                     
      nspec(ns) = is                                                            
      jflagi = jflagb(ns)                                                       
      cspi = cspb(ns)                                                           
      if (jflagi .le. 15) then                                                  
        if (cspi.le.0.) jflagi = -1                                             
      endif                                                                     
      jflag(is) = jflagi                                                        
      csp(is) = cspi                                                            
      go to 999                                                                 
c                                                                               
  100 continue                                                                  
c                                                                               
  999 continue                                                                  
      end                                                                       
c indatx   last revised 12/22/87 by tjw                                         
      subroutine indatx(cess,cdrs,cdrm,cdrg,cstor,ac2,awo,ars,                  
     $ amn,ags,apress,aadh,abdh,abdot,aeh,apx,xbar,xbarlg,xbarlm,               
     $ z,titr,azero,hydn,mwtss,atwt,xlkmod,tempc,press,afcnst,                  
     $ ussnp,udrxd,uspec,umin,ugas,usolx,uelem,uxmod,utitld,uredox,             
     $ nend,jflag,jcflag,ncomp,jsol,nxmod,jxmod,kxmod,iopt8,iopr1,              
     $ iodb1,nct,nsb,nsb1,nsq,nsq1,nsqb,nst,nrst,nmt,ngt,                       
     $ nxt,ist,irst,imt,igt,ntpr,nctmax,nsqmax,nsqmx1,nstmax,nmtmax,            
     $ ngtmax,nxtmax,iktmax,narxmx,ntprmx,iapxmx,noutpt,nttyo,                  
     $ nad1,nahv)                                                               
c                                                                               
c     this routine reads the supporting data file data1.  the first             
c     line of this file is read by the main program and is skipped here.        
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "vw.h"                                                           
      include "ww.h"                                                           
c                                                                               
      include "eqldd.h"                                        
      include "eqlej.h"                                        
      include "eqlgp.h"                                        
c                                                                               
      character*(*) ussnp(iktmax,*),udrxd(*),uspec(*),umin(*),                  
     $ ugas(*),usolx(*),uelem(*),uxmod(*),utitld(*),uredox                      
      character*(8) uelemd(nctpar),uoxide(nctpar)                               
c                                                                               
      dimension cess(nctmax,*),cdrs(nsqmx1,*),cdrm(nsqmx1,*),                   
     $ cdrg(nsqmx1,*),cstor(nstmax,*),ac2(narxmx,ntprmx,*),                     
     $ awo(narxmx,ntprmx,*),ars(narxmx,ntprmx,*),                               
     $ amn(narxmx,ntprmx,*),ags(narxmx,ntprmx,*),apress(narxmx,*),              
     $ aadh(narxmx,*),abdh(narxmx,*),abdot(narxmx,*),aeh(narxmx,*),             
     $ apx(iapxmx,*),xbar(iktmax,*),xbarlg(iktmax,*),                           
     $ xbarlm(iktmax,*),z(*),titr(*),azero(*),hydn(*),mwtss(*),                 
     $ atwt(*),xlkmod(*),jflag(*),jcflag(*),ncomp(*),jsol(*),                   
     $ nxmod(*),jxmod(*),kxmod(*),nend(iktmax,*)                                
c                                                                               
      dimension ard(narxpa,ntprpa),cessi(nctpar),cessd(nctpar),                 
     $ cdrsd(nsqpa1),oxfac(nctpar)                                              
c                                                                               
      character*24 uspecd,uspecj                                                
      character*80 ustr80                                                       
c                                                                               
      data uendit/'endit.  '/,ublank/'        '/                                
      data uo2aq/'O2(AQ)  '/,uh2aq/'H2(AQ)  '/,uh/'H       '/                   
      data udata1/'data1   '/                                                   
c                                                                               
      data nttlmx/30/                                                           
c                                                                               
c                                                                               
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      nerr = 0                                                                  
      write (noutpt,4001)                                                       
      write (nttyo,4001)                                                        
 4001 format(/' --- reading the data1 file ---')                                
c                                                                               
c     read file data1, unit number is nad1                                      
c                                                                               
      rewind nad1                                                               
      read (nad1) ustr                                                          
c                                                                               
      if (ustr .ne. udata1) then                                                
        write (noutpt,3000) ustr                                                
        write (nttyo,3000) ustr                                                 
 3000   format(' * error- wrong file header = ',a8,' on data1')                 
        stop                                                                    
      endif                                                                     
c                                                                               
c     check consistency between the activity coefficient option and the         
c     data1 file                                                                
c                                                                               
      read (nad1) uflag                                                         
      call gkey(uflag,udata1)                                                   
c                                                                               
      read (nad1) nct,nsq                                                       
c                                                                               
      nsb = nct + 1                                                             
      nsb1 = nsb + 1                                                            
      nsq1 = nsq + 1                                                            
      if (nct .gt. nctmax) then                                                 
        write (noutpt,116) nct,nctmax                                           
        write (nttyo,116) nct,nctmax                                            
  116   format(' * error- nct= ',i5,' exceeds the dimensioned',                 
     $  /7x,'limit nctmax= ',i5,' (indatx)')                                    
        stop                                                                    
      endif                                                                     
c                                                                               
      if (nsq .gt. nsqmax) then                                                 
        write (noutpt,118) nsq,nsqmax                                           
        write (nttyo,118) nsq,nsqmax                                            
  118   format(' * error- nsq= ',i5,' exceeds the dimensioned',                 
     $  /7x,'limit nsqmax= ',i5,' (indatx)')                                    
        stop                                                                    
      endif                                                                     
c                                                                               
      ntitld=0                                                                  
      do 3 n = 1,nttlmx                                                         
      read (nad1) utitld(n)                                                     
      ntitld = ntitld + 1                                                       
      if (utitld(n)(1:8) .eq. uendit) go to 4                                   
      if (ntitld .ge. 4) go to 4                                                
    3 continue                                                                  
    4 continue                                                                  
c                                                                               
      read (nad1) ustr80                                                        
c                                                                               
c     read elements data                                                        
c                                                                               
      do 3020 nc = 1,nct                                                        
      read (nad1) uelem(nc),atwt(nc),uoxide(nc),oxfac(nc)                       
 3020 continue                                                                  
      oxfac(1) = 0.                                                             
c                                                                               
      call indatc(apress,nad1,narxmx,ntprmx)                                    
      call indatc(aadh,nad1,narxmx,ntprmx)                                      
      call indatc(abdh,nad1,narxmx,ntprmx)                                      
      call indatc(abdot,nad1,narxmx,ntprmx)                                     
c                                                                               
      do 70 k = 1,4                                                             
      call indatk(k,ac2,nad1,narxmx,ntprmx)                                     
   70 continue                                                                  
c                                                                               
      do 75 k = 1,4                                                             
      call indatk(k,awo,nad1,narxmx,ntprmx)                                     
   75 continue                                                                  
c                                                                               
      call indatc(aeh,nad1,narxmx,ntprmx)                                       
c                                                                               
c     the following calls read now obsolete data for xlko2,xlkh2,xlkn2          
c                                                                               
      call indatc(ard,nad1,narxmx,ntprmx)                                       
      call indatc(ard,nad1,narxmx,ntprmx)                                       
      call indatc(ard,nad1,narxmx,ntprmx)                                       
c                                                                               
c     grab the necessary aqueous species, mineral, and gas data                 
c                                                                               
c        nst = aqueous species tally                                            
c        nmt = minerals tally                                                   
c        ngt = gases tally                                                      
c                                                                               
      nst = 0                                                                   
      nmt = 0                                                                   
      ngt = 0                                                                   
c                                                                               
      jcflag(1) = 1                                                             
c                                                                               
c---------- main loop -------------------------------------------------         
c                                                                               
c                             *----------------------------------------         
c                             * ilim = 1/2/3 for                                
c                             *  aqueous species/minerals/gases                 
c                             *----------------------------------------         
      do 3175 ilim = 1,3                                                        
      read (nad1) ustr,ustr2,ustr3                                              
c                                                                               
c - - - - - - data input loop - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
      do 3170 is = 1,10000                                                      
      read (nad1) uspecd,ncts,ndrst,ndum1,ndum2,ndum3                           
      if (uspecd(1:8) .eq. uendit(1:8)) go to 3325                              
c                                                                               
c----------------                                                               
      if (ilim.le.1 .and. is.le.nsq) then                                       
      call gcsp(csp,cspb,uspecb,uspecd,jflag,jflagb,                            
     $ nspec,is,nsqb,nsb,nerr,noutpt,nttyo)                                     
      endif                                                                     
c----------------                                                               
c                                                                               
      read (nad1) mwtssd,zd,titrd,azerod,hydnd                                  
c                                                                               
      if (ncts .le. 0) go to 3075                                               
      read (nad1) (cessd(n),uelemd(n), n = 1,ncts)                              
c                                                                               
 3075 do 3080 nc = 1,nctmax                                                     
      cessi(nc) = 0.                                                            
 3080 continue                                                                  
c                                                                               
      qload = .true.                                                            
      if (ncts .le. 0) then                                                     
        if (is.ne.nsb .or. ilim.ge.2) qload = .false.                           
        go to 3105                                                              
      endif                                                                     
c                                                                               
      do 3100 n = 1,ncts                                                        
c                                                                               
      do 3085 nc = 1,nct                                                        
      if (uelemd(n)(1:8) .eq. uelem(nc)(1:8)) go to 3095                        
 3085 continue                                                                  
c                                                                               
c     error, no match                                                           
c                                                                               
      write (noutpt,3083) uspecd,uelemd(n)                                      
      write (nttyo,3083) uspecd,uelemd(n)                                       
 3083 format(/' * error- ',a24,' has bad element name ',a8,                     
     $ /7x,' on file data1 (indatx)')                                           
      stop                                                                      
c                                                                               
 3095 cessi(nc) = cessd(n)                                                      
      if (cessi(nc) .eq. 0.) go to 3100                                         
      if (ilim.ge.2 .or. is.gt.nsq) then                                        
        if (jcflag(nc) .ne. 1) qload=.false.                                    
        go to 3100                                                              
      endif                                                                     
      if (jflag(is) .le. 15) then                                               
c----------------------------------------                                       
        if (csp(is) .gt. 0.) jcflag(nc) = 1                                     
c----------------------------------------                                       
        go to 3100                                                              
      endif                                                                     
      if (jflag(is).ne.27 .and. jflag(is).ne.30) then                           
        jcflag(nc) = 1                                                          
      endif                                                                     
 3100 continue                                                                  
c                                                                               
c        read the associated reaction data, if any                              
c                                                                               
 3105 if (ndrst .gt. 0) then                                                    
        read (nad1) (cdrsd(n),udrxd(n), n = 1,ndrst)                            
        read (nad1) (ard(i,1), i = 1,narxmx),                                   
     $              (ard(i,2), i = 1,narxmx)                                    
      endif                                                                     
c                                                                               
      if (iopr1 .ge. 1) then                                                    
        if (qload) then                                                         
          write (noutpt,3114) uspecd                                            
 3114     format(15x,'loading ',a24,' into memory')                             
        else                                                                    
          write (noutpt,3111) uspecd                                            
 3111     format(20x,a24,' not loaded into memory')                             
        endif                                                                   
      endif                                                                     
      if (.not.qload) go to 3170                                                
c                                                                               
c        load the species and associated data into memory                       
c                                                                               
c       test for minerals                                                       
      if (ilim .eq. 2) go to 3130                                               
c                                                                               
c       test for gases                                                          
      if (ilim .ge. 3) go to 3150                                               
c                                                                               
c                             -----------------------------------------         
c                             * aqueous species                                 
c                             -----------------------------------------         
c                                                                               
      nst = nst +1                                                              
      if (nst .gt. nstmax) then                                                 
        write (noutpt,3115) nstmax                                              
        write (nttyo,3115) nstmax                                               
 3115   format(/' * error- the maximum ',i5,' aqueous species have',            
     $  /7x,'been exceeded reading the file data1 (indatx)')                    
        stop                                                                    
      endif                                                                     
c                                                                               
      uspec(nst)=uspecd                                                         
c                                                                               
      do 3125 nc = 1,nct                                                        
      cess(nc,nst) = cessi(nc)                                                  
 3125 continue                                                                  
c                                                                               
      mwtss(nst) = mwtssd                                                       
      z(nst) = zd                                                               
      titr(nst) = titrd                                                         
      azero(nst) = azerod                                                       
      hydn(nst) = hydnd                                                         
      if (nst .le. nsb) go to 3170                                              
      nrs = nst - nsb                                                           
c                                                                               
      do 3123 ns = 1,nsq                                                        
      cdrs(ns,nrs) = 0.                                                         
 3123 continue                                                                  
c                                                                               
      cdrs(nsq1,nrs) = cdrsd(1)                                                 
c                                                                               
      do 3129 n = 2,ndrst                                                       
c                                                                               
      do 3127 ns = 1,nsq                                                        
      if (udrxd(n)(1:12) .eq. uspec(ns)(1:12)) go to 3128                       
 3127 continue                                                                  
c                                                                               
c     error, not found                                                          
c                                                                               
      write (noutpt,3126) uspecd,udrxd(n)                                       
      write (nttyo,3126) uspecd,udrxd(n)                                        
 3126 format(/' * error- ',a24,' has bad species name ',a24,                    
     $ /7x,'in its associated reaction on the data file (indatx)')              
      stop                                                                      
c                                                                               
 3128 cdrs(ns,nrs) = cdrsd(n)                                                   
 3129 continue                                                                  
c                                                                               
      do 4110 j = 1,ntprmx                                                      
      do 4105 i = 1,narxmx                                                      
      ars(i,j,nrs) = ard(i,j)                                                   
 4105 continue                                                                  
 4110 continue                                                                  
c                                                                               
      go to 3170                                                                
c                                                                               
c                             -----------------------------------------         
c                             * minerals                                        
c                             -----------------------------------------         
c                                                                               
 3130 nmt = nmt + 1                                                             
      if (nmt .gt. nmtmax) then                                                 
        write (noutpt,3135) nmtmax                                              
        write (nttyo,3135) nmtmax                                               
 3135   format(/' * error- the maximum ',i5,' pure minerals have ',             
     $  /7x,'been exceeded reading the data file (indatx)')                     
        stop                                                                    
      endif                                                                     
c                                                                               
      umin(nmt) = uspecd                                                        
c                                                                               
c---------------------------------                                              
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c---------------------------------                                              
      do 3143 ns = 1,nsq                                                        
      cdrm(ns,nmt) = 0.                                                         
 3143 continue                                                                  
c                                                                               
      cdrm(nsq1,nmt) = cdrsd(1)                                                 
c                                                                               
c       search for name in uspec                                                
c                                                                               
      do 3149 n = 2,ndrst                                                       
c                                                                               
      do 3147 ns = 1,nsq                                                        
      if (udrxd(n)(1:12) .eq. uspec(ns)(1:12)) go to 3148                       
 3147 continue                                                                  
c                                                                               
c     error, not found                                                          
c                                                                               
      write (noutpt,3126) uspecd,udrxd(n)                                       
      write (nttyo,3126) uspecd,udrxd(n)                                        
      stop                                                                      
c                                                                               
 3148 cdrm(ns,nmt) = cdrsd(n)                                                   
 3149 continue                                                                  
c                                                                               
      do 4120 j = 1,ntprmx                                                      
      do 4115 i = 1,narxmx                                                      
      amn(i,j,nmt) = ard(i,j)                                                   
 4115 continue                                                                  
 4120 continue                                                                  
c                                                                               
      go to 3170                                                                
c                                                                               
c                             -----------------------------------------         
c                             * gases                                           
c                             -----------------------------------------         
c                                                                               
 3150 ngt = ngt + 1                                                             
      if (ngt .gt. ngtmax) then                                                 
        write (noutpt,3155) ngtmax                                              
        write (nttyo,3155) ngtmax                                               
 3155   format(/' * error- the maximum ',i5,' gas species have ',               
     $  /7x,'been exceeded reading the data file (indatx)')                     
        stop                                                                    
      endif                                                                     
c                                                                               
      ugas(ngt) = uspecd                                                        
c                                                                               
c---------------------------------                                              
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c                                                                               
c---------------------------------                                              
      do 3163 ns = 1,nsq                                                        
      cdrg(ns,ngt) = 0.                                                         
 3163 continue                                                                  
c                                                                               
      cdrg(nsq1,ngt) = cdrsd(1)                                                 
c                                                                               
c       search for name in uspec                                                
c                                                                               
      do 3169 n=2,ndrst                                                         
      do 3167 ns=1,nsq                                                          
      if (udrxd(n)(1:12) .eq. uspec(ns)(1:12)) go to 3168                       
 3167 continue                                                                  
c                                                                               
c     error, not found                                                          
c                                                                               
      write (noutpt,3126) uspecd,udrxd(n)                                       
      write (nttyo,3126) uspecd,udrxd(n)                                        
      stop                                                                      
c                                                                               
 3168 cdrg(ns,ngt) = cdrsd(n)                                                   
 3169 continue                                                                  
c                                                                               
      do 4130 j = 1,ntprmx                                                      
      do 4125 i = 1,narxmx                                                      
      ags(i,j,ngt) = ard(i,j)                                                   
 4125 continue                                                                  
 4130 continue                                                                  
c                                                                               
 3170 continue                                                                  
c                                                                               
c - - - - - end of data loop - - - - - - - - - - - - - - - - - - - - - -        
c                                                                               
 3325 if (ilim .eq. 1) then                                                     
        ist = is - 1                                                            
        irst = ist - nsb                                                        
      elseif (ilim .eq. 2) then                                                 
        imt = is - 1                                                            
      else                                                                      
        igt = is - 1                                                            
      endif                                                                     
c                                                                               
 3175 continue                                                                  
c                                                                               
c----------- end of main loop ------------------------------------------        
c                                                                               
      nrst = nst - nsb                                                          
c                                                                               
      do 243 ns = 1,nsqb                                                        
      is = nspec(ns)                                                            
      if (is .le. 0) then                                                       
        nerr = nerr + 1                                                         
        write (noutpt,237) uspecb(ns)                                           
        write (nttyo,237) uspecb(ns)                                            
  237   format(' * error- ',a24,' was on input but was not read',               
     $  /7x,'from the data file (indatx)')                                      
      endif                                                                     
  243 continue                                                                  
c                                                                               
c     complete setting of the jflag array                                       
c                                                                               
c        set jflag for o2(aq) and h2(aq) to 27, unless the current              
c        jflag = 30 (normal default for auxiliary basis species).               
c                                                                               
      jflag(1)=0                                                                
      if (jflag(nsb).lt.19 .or. jflag(nsb).gt.21) jflag(nsb)=0                  
      kount=0                                                                   
c                                                                               
      do 3178 ns=nsb1,nsq                                                       
      ustr1=uspec(ns)(1:8)                                                      
      if (ustr1.eq.uo2aq.or.ustr1.eq.uh2aq) then                                
        kount=kount+1                                                           
        if (jflag(ns).eq.30) jflag(ns)=27                                       
        if (kount.ge.2) go to 3179                                              
      endif                                                                     
 3178 continue                                                                  
 3179 continue                                                                  
c                                                                               
c        set jflag to -1 for auxiliary basis species that                       
c        can not appear in the model                                            
c                                                                               
      do 205 nsc=nsb1,nsq                                                       
      if (jflag(nsc).ge.27) then                                                
        nrs=nsc-nsb                                                             
        do 203 ns=1,nsq                                                         
        if (cdrs(ns,nrs).ne.0.) then                                            
          if (jflag(ns).lt.0) then                                              
	    jflag(nsc)=-1                                                              
	    go to 205                                                                  
          endif                                                                 
        endif                                                                   
  203   continue                                                                
      endif                                                                     
  205 continue                                                                  
c                             *----------------------------------------         
c                             * read solid solution data                        
c                             *----------------------------------------         
      nxt=0                                                                     
      read (nad1) ustr,ustr2,ustr3                                              
c                                                                               
      do 3215 nx=1,10000                                                        
      read (nad1) uspecd,ndum,jdum,ndum4,ndum5,ndum6                            
      if (uspecd(1:8).eq.uendit) go to 4005                                     
      if (ndum.le.0) go to 3215                                                 
      read (nad1) (xbarlm(n,nx),udrxd(n), n=1,ndum)                             
      ndum2=0                                                                   
c                                                                               
      do 3210 n=1,ndum                                                          
c                                                                               
      do 3195 nm=1,nmt                                                          
      if (udrxd(n)(1:18).ne.umin(nm)(1:18)) go to 3195                          
      go to 3205                                                                
c                                                                               
 3195 continue                                                                  
      nend(n,nx)=0                                                              
c                                                                               
c     collect the names of endmembers not present                               
c                                                                               
      ussnp(n,nx) = udrxd(n)                                                    
      go to 3210                                                                
c                                                                               
 3205 continue                                                                  
      nend(n,nx)=nm                                                             
      ndum2=ndum2+1                                                             
 3210 continue                                                                  
c                                                                               
      nxt=nxt+1                                                                 
      if (nxt .gt. nxtmax) then                                                 
        write (noutpt,3132) nxtmax                                              
        write (nttyo,3132) nxtmax                                               
 3132   format(/' * error- the maximum ',i5,' solid solutions have ',           
     $  /7x,'been exceeded reading the data file (indatx)')                     
        stop                                                                    
      endif                                                                     
c                                                                               
      if (iopr1.ge.1) write (noutpt,3114) uspecd                                
      usolx(nx)=uspecd                                                          
      ncomp(nx)=ndum                                                            
      jsol(nx)=jdum                                                             
      read (nad1) (apx(i,nx), i=1,iapxmx)                                       
 3215 continue                                                                  
c                                                                               
 4005 continue                                                                  
c                                                                               
c     check to see that all expanded basis aqueous species on the               
c     input file were matched with those on the data file.  set up the          
c     array ibasis.                                                             
c                                                                               
      do 233 ns=1,nst                                                           
      ibasis(ns)=ns                                                             
  233 continue                                                                  
c                                                                               
      do 245 ns=1,nsqb                                                          
      is=nspec(ns)                                                              
      if (is .le. 0) go to 245                                                  
      if (ubasis(ns)(1:8) .eq. ublank(1:8)) go to 245                           
      if (ubasis(ns)(1:24) .eq. uspecb(ns)(1:24)) go to 245                     
c                                                                               
      do 253 nsc=1,nst                                                          
c                                                                               
      if (ubasis(ns)(1:18).ne.uspec(nsc)(1:18)) go to 253                       
c                                                                               
      isc=ibasis(nsc)                                                           
      if (isc.eq.nsc) go to 251                                                 
      if (isc.eq.is) go to 245                                                  
      nerr=nerr+1                                                               
      write (noutpt,254) uspec(nsc),uspec(is),uspec(isc)                        
      write (nttyo,254) uspec(nsc),uspec(is),uspec(isc)                         
  254 format(' * error- ',a24,' is specified to switch with both ',             
     $ /7x,a24,' and ',a24,' (indatx)')                                         
  251 ibasis(is)=nsc                                                            
      ibasis(nsc)=is                                                            
      go to 245                                                                 
c                                                                               
  253 continue                                                                  
      nerr=nerr+1                                                               
      write (noutpt,258) ubasis(ns),uspecb(ns)                                  
      write (nttyo,258) ubasis(ns),uspecb(ns)                                   
  258 format(' error- ',a24,' is specified to switch with ',a24,                
     $ /7x,'but is not in the list of aqueous species (indatx)')                
  245 continue                                                                  
c                                                                               
      do 300 ns=1,nsqb                                                          
      jflagi=jflagb(ns)                                                         
      if (jflagi.ne.19) go to 270                                               
c                                                                               
      do 250 nm=1,nmt                                                           
c                                                                               
      if (uphas1(ns)(1:18).ne.umin(nm)(1:18)) go to 250                         
c                                                                               
      is=nspec(ns)                                                              
      nsp(is)=nm                                                                
      go to 300                                                                 
c                                                                               
  250 continue                                                                  
      nerr=nerr+1                                                               
      write (noutpt,255) uphas1(ns)                                             
      write (nttyo,255) uphas1(ns)                                              
  255 format(' * error- ',a24,' is required for a heterogeneous',               
     $ /7x,'equilibrium constraint but was not read from the',                  
     $ /7x,'the data file (indatx)')                                            
      go to 300                                                                 
c                                                                               
  270 continue                                                                  
      if (jflagi.ne.20) go to 280                                               
c                                                                               
      do 277 nx=1,nxt                                                           
c                                                                               
      if (uphas1(ns)(1:18).ne.usolx(nx)(1:18)) go to 277                        
c                                                                               
      ikt=ncomp(nx)                                                             
c                                                                               
      do 276 ik=1,ikt                                                           
      nm=nend(ik,nx)                                                            
      if (umin(nm)(1:18).ne.uphas2(ns)(1:18)) go to 276                         
      is=nspec(ns)                                                              
      nsp(is)=50000+100*nx+ik                                                   
      go to 300                                                                 
c                                                                               
  276 continue                                                                  
      nerr=nerr+1                                                               
      write (noutpt,255) uphas2(ns)                                             
      write (nttyo,255) uphas2(ns)                                              
      go to 300                                                                 
c                                                                               
  277 continue                                                                  
      nerr=nerr+1                                                               
      write (noutpt,255) uphas1(ns)                                             
      write (nttyo,255) uphas1(ns)                                              
      go to 300                                                                 
c                                                                               
  280 continue                                                                  
      if (jflagi.ne.21) go to 300                                               
c                                                                               
      do 287 ng=1,ngt                                                           
c                                                                               
      if (uphas1(ns).ne.ugas(ng)) go to 287                                     
c                                                                               
      is=nspec(ns)                                                              
      nsp(is)=ng                                                                
      go to 300                                                                 
c                                                                               
  287 continue                                                                  
      nerr=nerr+1                                                               
      write (noutpt,255) uphas1(ns)                                             
      write (nttyo,255) uphas1(ns)                                              
  300 continue                                                                  
c                                                                               
      if (iodb1.le.1) go to 842                                                 
      write (noutpt,800)                                                        
  800 format(/' --- list of decoded input data ---',//7x,                       
     $ 'ns',6x,'species',9x,'csp',8x,'jflag',4x,'nsp',/)                        
c                                                                               
      do 840 ns=1,nsq                                                           
      write(noutpt,805) ns,uspec(ns),csp(ns),jflag(ns),nsp(ns)                  
  805 format(6x,i3,3x,a12,3x,e12.5,3x,i3,3x,i5)                                 
  840 continue                                                                  
c                                                                               
  842 continue                                                                  
      if (iodb1.le.1) go to 850                                                 
      write (noutpt,843)                                                        
  843 format(/' --- matching of species from input and data1',                  
     $ ' ---',/)                                                                
c                                                                               
      do 847 ns=1,nsqb                                                          
      is=nspec(ns)                                                              
      write (noutpt,846) ns,uspecb(ns),is,uspec(is)                             
  846 format(3x,i3,3x,a12,5x,i3,3x,a12)                                         
  847 continue                                                                  
c                                                                               
  850 continue                                                                  
c                                                                               
c     unpack input solid solution compositions, if any                          
c                                                                               
      if (nxtb.le.0) go to 350                                                  
c                                                                               
      do 340 nxb=1,nxtb                                                         
      nxspec(nxb)=0                                                             
      uspecj=usolb(nxb)                                                         
c                                                                               
      do 330 nx=1,nxt                                                           
      if (uspecj(1:18).eq.usolx(nx)(1:18)) go to 333                            
  330 continue                                                                  
c                                                                               
      nerr=nerr+1                                                               
      write (noutpt,237) ustr1,ustr2                                            
      write (nttyo,237) ustr1,ustr2                                             
      go to 350                                                                 
c                                                                               
  333 continue                                                                  
      nxspec(nxb)=nx                                                            
      ikt=ncomp(nx)                                                             
      iktb=ncompb(nxb)                                                          
      if (iktb.le.0) go to 350                                                  
c                                                                               
      do 340 ikb=1,iktb                                                         
      uspecj=umemb(ikb,nxb)                                                     
c                                                                               
      do 335 ik=1,ikt                                                           
      nm=nend(ik,nx)                                                            
      if (uspecj(1:18).ne.umin(nm)(1:18)) go to 335                             
      go to 337                                                                 
c                                                                               
  335 continue                                                                  
c                                                                               
      nerr=nerr+1                                                               
      write (noutpt,237) uspecj                                                 
      write (nttyo,237) uspecj                                                  
      go to 340                                                                 
c                                                                               
  337 continue                                                                  
      xdum=xbarb(ikb,nxb)                                                       
      xbar(ik,nx)=xdum                                                          
      xbarlg(ik,nx)=tlg(xdum)                                                   
  340 continue                                                                  
c                                                                               
  350 continue                                                                  
c                                                                               
c     stop if name match errors have been encountered                           
c                                                                               
      if (nerr .gt. 0) then                                                     
        write (noutpt,853) nerr                                                 
        write (nttyo,853) nerr                                                  
  853   format(/' * error- ',i5,' errors matching data from input',             
     $  /7x,'and the data file (indatx)')                                       
        stop                                                                    
      endif                                                                     
c                                                                               
c     alter any log k values as directed by the input file                      
c                                                                               
      call alters(nxmod,jxmod,kxmod,xlkmod,uxmod,ars,                           
     $ amn,ags,apress,cdrs,cdrm,cdrg,tempc,afcnst,uspec,umin,                   
     $ ugas,usolx,nsb,nsq,nsq1,nst,nmt,ngt,nxt,ntpr,nsqmx1,narxmx,              
     $ ntprmx,noutpt,nttyo)                                                     
c                                                                               
c     set stochiometric equivalences of aqueous species for h2o                 
c     (o--) and h+ (h+).                                                        
c                                                                               
      cstor(nsb,1)=2.0                                                          
      cstor(nsb,2)=0.                                                           
c                                                                               
      nh = 0                                                                    
      do 401 nc = 1,nct                                                         
      if (uelem(nc)(1:8) .eq. uh(1:8)) then                                     
        nh = nc                                                                 
        go to 402                                                               
      endif                                                                     
  401 continue                                                                  
  402 continue                                                                  
c                                                                               
      do 890 ic=1,2                                                             
      nc=1                                                                      
      if (ic.ge.2) nc = nh                                                      
c                                                                               
      do 860 ns=1,nct                                                           
      cstor(ns,ic)=cess(nc,ns)                                                  
  860 continue                                                                  
c                                                                               
      do 885 nsc=nsb1,nst                                                       
      dum1=0.                                                                   
      if (nsc.gt.nsq) go to 870                                                 
      jfl=jflag(nsc)                                                            
      if (jfl.eq.30) go to 870                                                  
      if (jfl.eq.27) go to 870                                                  
      uspecj=uspec(nsc)                                                         
      if (uspecj(1:18).ne.uredox(1:18)) go to 872                               
      go to 870                                                                 
c                                                                               
c        the names of any auxiliary basis species with oxygen or                
c        hydrogen in valence states other than -2 or +1, respectively,          
c        must be identified below.  iodb6=1 can be specified on the             
c        input file to check that correct stoichiometric numbers are            
c        calculated.                                                            
c                                                                               
  872 if (ustr1.eq.uo2aq) go to 880                                             
      if (ustr1.eq.uh2aq) go to 880                                             
  870 continue                                                                  
      nrs=nsc-nsb                                                               
      nlim=nsc-1                                                                
      nlim=min0(nlim,nsq)                                                       
c                                                                               
      do 875 ns=1,nlim                                                          
      dum2=cdrs(ns,nrs)                                                         
      dum3=cstor(ns,ic)                                                         
      dum1=dum1+dum2*dum3                                                       
  875 continue                                                                  
c                                                                               
      dum1=-dum1/cdrs(nsq1,nrs)                                                 
  880 continue                                                                  
      cstor(nsc,ic)=dum1                                                        
  885 continue                                                                  
c                                                                               
  890 continue                                                                  
      cstor(nsb,1)=0.                                                           
c                                                                               
      write (noutpt,4007)                                                       
      write (nttyo,4007)                                                        
 4007 format(/' --- the data1 file has been successfully read ---')             
c                                                                               
c      test for mods to azeros and hydration numbers                            
c                                                                               
      if (iopt8 .eq. 1 .and. qhydth)                                            
     $ call modah(nahv,nst,azero,uspec,hydn)                                    
c                                                                               
      end                                                                       
c matrix   last revised 12/14/87 by tjw                                         
      subroutine matrix                                                         
c                                                                               
c     this routine builds the jacobian matrix aa(kdim,kdim).                    
c     the matrix is written row-by-row.                                         
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      dimension jrs(nrstpa)                                                     
c                                                                               
      include "blank.h"                                                        
      include "an.h"                                                           
      include "bt.h"                                                           
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nn.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "ps.h"                                                           
      include "st.h"                                                           
      include "tt.h"                                                           
      include "tu.h"                                                           
      include "un.h"                                                           
      include "uu.h"                                                           
      include "vv.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "zg.h"                                                           
      include "eqldd.h"                                        
      include "eqlpp.h"                                        
      include "eqlgp.h"                                        
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
c     initialize array aa to zeroes                                             
c                                                                               
      do 10 krow=1,kdim                                                         
      do 5 kcol=1,kdim                                                          
      aa(krow,kcol)=0.                                                          
    5 continue                                                                  
   10 continue                                                                  
c                                                                               
c     arrange the reactions in order of increasing concentration of             
c     the associated aqueous species.                                           
c                                                                               
      nrr=0                                                                     
      do 15 nss=1,nst                                                           
      nsc=jsort(nss)                                                            
      nrs=nsc-nsb                                                               
      if (nrs.le.0) go to 15                                                    
      nrr=nrr+1                                                                 
      jrs(nrr)=nrs                                                              
   15 continue                                                                  
c                                                                               
c     the first row/column is currently unused                                  
c                                                                               
      aa(1,1)=1.                                                                
c                                                                               
c- - - - - - - - - - begin main loop - - - - - - - - - - - - - - - - - -        
c                                                                               
c     write rows 2 through ksq.                                                 
c                                                                               
      do 400 krow=2,ksq                                                         
      nse=iindx1(krow)                                                          
c                                                                               
c      test for various constraints                                             
c                                                                               
c      test for charge balance                                                  
      if (nse.eq.iebal) go to 70                                                
      jfdum=jflag(nse)                                                          
c      test for mineral equilibrium                                             
      if (jfdum.eq.19) go to 200                                                
      if (jfdum.eq.20) go to 200                                                
c      test for gas equilibrium                                                 
      if (jfdum.eq.21) go to 250                                                
c      test for log fo2                                                         
      if (nse.eq.nsb) go to 300                                                 
c      test for mass balance                                                    
      if (jfdum.eq.0) go to 30                                                  
c      test for alkalinity balance                                              
      if (jfdum.eq.10) go to 110                                                
c      test for log activity                                                    
      if (jfdum.eq.16) go to 170                                                
c      test for aqueous homogeneous equilibrium                                 
      if (jfdum.eq.27) go to 700                                                
c      test for free concentration                                              
      if (jfdum.eq.4) go to 175                                                 
c      test for alkalinity balance                                              
      if (jfdum.eq.12) go to 110                                                
      write (noutpt,1000) jfdum,uspec(nse)                                      
 1000 format(1x,'illegal jflag value = ',i5,' encountered for ',                
     $ a18,' in matrix')                                                        
      stop                                                                      
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        mass balance constraint.                                               
c                                                                               
   30 do 35 ns = 1,nst                                                          
      store(ns) = csts(nse,ns)                                                  
   35 continue                                                                  
c                                                                               
      call balcon(store,jrs,krow)                                               
c                                                                               
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        charge balance constraint.                                             
c                                                                               
   70 continue                                                                  
c                                                                               
      call balcon(z,jrs,krow)                                                   
c                                                                               
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        alkalinity balance constraint.                                         
c                                                                               
  110 continue                                                                  
c                                                                               
      call balcon(titr,jrs,krow)                                                
c                                                                               
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        log activity constraint.                                               
c                                                                               
  170 continue                                                                  
      aa(krow,krow)=1.0                                                         
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        free concentration constraint.                                         
c                                                                               
  175 continue                                                                  
      aa(krow,krow)=1.                                                          
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        mineral equilibrium constraint.                                        
c                                                                               
  200 continue                                                                  
      nm=nsp(nse)                                                               
      if (nm.lt.50000) go to 205                                                
      nm=nm-50000                                                               
      nx = nm/100                                                               
      ik=nm-100*nx                                                              
      nm=nend(ik,nx)                                                            
  205 continue                                                                  
c                                                                               
      do 215 kcol=2,ksq                                                         
      if (kcol.eq.krow) go to 215                                               
      ns=iindx1(kcol)                                                           
      aa(krow,kcol) = -cdrm(ns,nm)/cdrm(nse,nm)                                 
  215 continue                                                                  
c                                                                               
      aa(krow,krow)=-1.0                                                        
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        gas equilibrium constraint.                                            
c                                                                               
  250 continue                                                                  
      ng=nsp(nse)                                                               
c                                                                               
      do 260 kcol=2,ksq                                                         
      if (kcol.eq.krow) go to 260                                               
      ns=iindx1(kcol)                                                           
      aa(krow,kcol) = -cdrg(ns,ng)/cdrg(nse,ng)                                 
  260 continue                                                                  
c                                                                               
      aa(krow,krow)=-1.0                                                        
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        aqueous homogeneous equilibrium constraint.                            
c                                                                               
  700 continue                                                                  
      nrs=nse-nsb                                                               
c                                                                               
      do 705 kcol=2,ksq                                                         
      if (kcol.eq.krow) go to 705                                               
      ns=iindx1(kcol)                                                           
      aa(krow,kcol) = -cdrs(ns,nrs)/cdrs(nsq1,nrs)                              
  705 continue                                                                  
c                                                                               
      aa(krow,krow)=-1.0                                                        
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c        log fo2 constraints.                                                   
c                                                                               
c           identity constraint.                                                
c                                                                               
  300 continue                                                                  
      if (iopt1.ne.0) go to 310                                                 
      aa(krow,ksb)=1.                                                           
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c           eh constraint (note--an input p e- value has been                   
c           converted to an eh value by routine setup)                          
c                                                                               
  310 continue                                                                  
      if (iopt1.ge.1) go to 330                                                 
      aa(krow,khydr)=-4.0                                                       
      aa(krow,krow)=-1.0                                                        
      go to 400                                                                 
c - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         
c                                                                               
c           cross-linking (homogeneous aqueous redox) equilibrium.              
c                                                                               
  330 continue                                                                  
      nsc=iopt1+nsb                                                             
      aa(krow,ksb)=-1.0                                                         
c                                                                               
      do 340 kcol=2,ksq                                                         
      if (kcol.eq.ksb) go to 340                                                
      ns=iindx1(kcol)                                                           
      if (ns.eq.nsc) then                                                       
        aa(krow,kcol) = -cdrs(nsq1,iopt1)/cdrs(nsb,iopt1)                       
      else                                                                      
      aa(krow,kcol) = -cdrs(ns,iopt1)/cdrs(nsb,iopt1)                           
      endif                                                                     
  340 continue                                                                  
  400 continue                                                                  
c                                                                               
c - - - - - - - - - - end of main loop - - - - - - - - - - - - - - - - -        
c                                                                               
      if (iodb3 .gt. 0) then                                                    
c                                                                               
c       variable-killer option here                                             
c                                                                               
        do 495 k=1,kdim                                                         
        if (kill(k) .eq. 0) go to 495                                           
        do 492 krow=1,kdim                                                      
        aa(krow,k) = 0.                                                         
  492   continue                                                                
        do 493 kcol=1,kdim                                                      
        aa(k,kcol) = 0.                                                         
  493   continue                                                                
        aa(k,k) = 1.                                                            
  495   continue                                                                
      endif                                                                     
c                                                                               
  999 continue                                                                  
      end                                                                       
c ncmpx    last revised 10/30/87 by tjw                                         
      subroutine ncmpx                                                          
c                                                                               
c     this routine computes all parameters necessary to write                   
c     the matrix from the zvclg1 array.                                         
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "an.h"                                                           
      include "bt.h"                                                           
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nn.h"                                                           
      include "nx.h"                                                           
      include "oo.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "ps.h"                                                           
      include "st.h"                                                           
      include "tt.h"                                                           
      include "un.h"                                                           
      include "uu.h"                                                           
      include "vv.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "zg.h"                                                           
      include "eqlgp.h"                                        
      include "eqldd.h"                                        
      include "eqlpp.h"                                        
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      do 5 kcol=2,ksq                                                           
      ns=iindx1(kcol)                                                           
      cdum=zvclg1(kcol)                                                         
      conclg(ns)=cdum                                                           
      conc(ns)=texp(cdum)                                                       
    5 continue                                                                  
c                                                                               
      conclg(nsb)=-999.                                                         
      conc(nsb)=0.                                                              
      fo2lg=zvclg1(ksb)                                                         
      fo2=texp(fo2lg)                                                           
c                                                                               
        awlg=glg(1)                                                             
        actlg(1)=awlg                                                           
        act(1)=texp(awlg)                                                       
c                                                                               
      do 35 kcol=2,ksq                                                          
      ns=iindx1(kcol)                                                           
      adum=conclg(ns)+glg(ns)                                                   
      actlg(ns)=adum                                                            
      act(ns)=texp(adum)                                                        
   35 continue                                                                  
c                                                                               
      do 20 nsc=nsb1,nst                                                        
      if (jsflag(nsc) .ge. 2) go to 20                                          
      if (nsc .gt. nsq) go to 10                                                
      if (jflag(nsc) .eq. 30) go to 10                                          
      go to 20                                                                  
c                                                                               
   10 continue                                                                  
      nrs=nsc-nsb                                                               
      cdum=-xlks(nrs)+cdrs(1,nrs)*awlg                                          
      cdum=cdum+cdrs(nsb,nrs)*fo2lg                                             
      cdum=cdum+cdrs(nsq1,nrs)*glg(nsc)                                         
c                                                                               
      do 15 ns=2,nsq                                                            
      adum=cdrs(ns,nrs)                                                         
      if (adum .eq. 0.) go to 15                                                
      if (ns .eq. nsb) go to 15                                                 
      if (conclg(ns) .gt. -999.) go to 12                                       
      conclg(nsc)=-999.                                                         
      go to 20                                                                  
c                                                                               
   12 continue                                                                  
      cdum=cdum+adum*actlg(ns)                                                  
   15 continue                                                                  
c                                                                               
      cdum=-cdum/cdrs(nsq1,nrs)                                                 
      conclg(nsc)=cdum                                                          
      conc(nsc)=texp(cdum)                                                      
      adum=cdum+glg(nsc)                                                        
      actlg(nsc)=adum                                                           
      act(nsc)=texp(adum)                                                       
   20 continue                                                                  
c                                                                               
      call qsort(conclg,csort,nst,jsort,istack,jstack)                          
c                                                                               
      do 25 nss=1,nst                                                           
      ns=jsort(nss)                                                             
      csort(nss)=conc(ns)                                                       
   25 continue                                                                  
c                                                                               
      end                                                                       
c ndiagx   last revised 11/18/87 by tjw                                         
c*created in f77 11/18/87 by tjw                                                
      subroutine ndiagx(del,screwd,jflag,iindx1,idelmx,iebal,ksb,               
     $ kebal,khydr,kcarb,nhydr)                                                 
c                                                                               
c     this routine attempts to generate diagnostics if hybrid newton-           
c     raphson iteration has failed.                                             
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "un.h"                                                           
c                                                                               
      include "eqleps.h"                                       
c                                                                               
      dimension del(*),jflag(*),iindx1(*)                                       
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
c     try to diagnose why the iteration crashed.  first look for                
c     clues in the del vector.  then look at the condition of                   
c     the ionic strength and related parameters.                                
c                                                                               
c     a common error is a bad input constraint associated with either           
c     electrical balancing or titration alkalinity.                             
c                                                                               
      if (idelmx.eq.0) go to 350                                                
c                                                                               
c        check to see if the ion being adjusted for electrical balance          
c        was crashing to zero.  this implies that an ion of opposite            
c        charge must be used to achieve electrical balance.                     
c                                                                               
      qdltst = (del(idelmx) + screwd) .le. eps100                               
      if (idelmx.eq.kebal .and. qdltst) then                                    
        write (noutpt,305)                                                      
        write (nttyo,305)                                                       
  305   format(/' * note- the ion adjusted for electrical balance',             
     $  /7x,'is crashing to zero.   electrical balancing requires an',          
     $  /7x,'ion of opposite charge (ndiagx)',/)                                
        go to 999                                                               
      endif                                                                     
c                                                                               
c        check to see if the ion associated with titration alkalinity           
c        balance is crashing to zero.  this implies that non-carbonate          
c        alkalinity is greater than or equal to carbonate alkalinity.           
c        sulfide alkalinity is a likely culprit.                                
c                                                                               
      if (idelmx.eq.kcarb .and. qdltst) then                                    
        ns=iindx1(idelmx)                                                       
        if (jflag(ns).eq.10) then                                               
          write (noutpt,315)                                                    
          write (nttyo,315)                                                     
  315     format(/' *note- carbonate or bicarbonate is crashing to',            
     $    /7x,'zero because non-carbonate alkalinity exceeds the',              
     $    /7x,' specified titration alkalinity (ndiagx)',/)                     
          go to 999                                                             
        endif                                                                   
      endif                                                                     
c                                                                               
c        check to see if fo2 is crashing.  this could be due to                 
c        a bad combination of constraining the redox state by a                 
c        non-fo2 option and divergence to zero of an associated                 
c        ion that is constrained by electrical balance.                         
c                                                                               
      qadtst = (delmax - screwd) .le. eps100                                    
      if (idelmx.eq.ksb .and. qadtst) then                                      
        if (iopt1.eq.-1 .and. iebal.eq.nhydr) then                              
          dum=0.1*screwd                                                        
          adum=abs(del(khydr))                                                  
          if (adum.ge.dum) then                                                 
            write (noutpt,333)                                                  
            write (nttyo,333)                                                   
  333       format(/' * note- fo2 is crashing, probably because',               
     $      /7x,'a bad electrical balance constraint on h+ is causing',         
     $      /7x,'the concentration of h+ to crash to zero (ndiagx)',/)          
            go to 999                                                           
          endif                                                                 
        endif                                                                   
c                                                                               
        if (iopt1.gt.1) then                                                    
          write (noutpt,337)                                                    
          write (nttyo,337)                                                     
  337     format(/' * note- fo2 is crashing, probably because',                 
     $    /7x,'of a bad constraint on one of the aqueous species',              
     $    /7x,' appearing in the redox reaction that is being',                 
     $    /7x,' used to constrain the fo2 (ndiagx)',/)                          
          go to 999                                                             
        endif                                                                   
      endif                                                                     
c                                                                               
  350 continue                                                                  
c                                                                               
      write (noutpt,355)                                                        
      write (nttyo,355)                                                         
  355 format(/' * note- no diagnostics were generated from the',                
     $ /7x,'iteration crash.  look at the del and beta info. in the',           
     $ /7x,'iteration summary for clues (ndiagx)',/)                            
c                                                                               
  999 continue                                                                  
      end                                                                       
c readx    last revised 12/22/87 by tjw                                         
      subroutine readx(infile,qend)                                             
c                                                                               
c     this subprogram reads the input data which define a distribution-         
c     of-species problem.                                                       
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "an.h"                                                           
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "nx.h"                                                           
      include "oo.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "ps.h"                                                           
      include "ti.h"                                                           
      include "tt.h"                                                           
      include "un.h"                                                           
      include "uu.h"                                                           
      include "vv.h"                                                           
      include "vw.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "eqlgp.h"                                        
      include "eqldd.h"                                        
      include "eqlpp.h"                                        
      include "eqltxp.h"                                       
c                                                                               
      character*24 udum1,udum2,ublank                                           
c                                                                               
      data ublank/'                        '/                                   
      data uendit/'endit.  '/,uo2g/'O2(G)   '/                                  
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
c     qend is a flag which is true if the end of the input file has             
c     been reached.                                                             
c                                                                               
      qend=.false.                                                              
c                                                                               
c     utitl consists of up to thirty lines of text.  if there are less          
c     than thirty lines, utitl is terminated by a line beginning with           
c     'endit.'                                                                  
c                                                                               
      write (noutpt,37)                                                         
      write (nttyo,37)                                                          
   37 format(/' --- reading the input file ---')                                
c                                                                               
      ntitl=1                                                                   
      read(infile,70,end=25) utitl(ntitl)                                       
   70 format(a80)                                                               
      go to 31                                                                  
c                                                                               
   25 continue                                                                  
      write (noutpt,30)                                                         
      write (nttyo,30)                                                          
   30 format(/' --- no further input found ---')                                
      qend=.true.                                                               
      go to 999                                                                 
c                                                                               
   31 continue                                                                  
      write (noutpt,71) utitl(ntitl)                                            
   71 format(1x,a80)                                                            
      if (utitl(ntitl)(1:8).ne.uendit) go to 33                                 
      write (noutpt,32)                                                         
      write (nttyo,32)                                                          
   32 format(' * error- input file has no title (readx)')                       
      stop                                                                      
c                                                                               
   33 continue                                                                  
      do 34 n=2,ntitmx                                                          
      read (infile,70) utitl(n)                                                 
      write (noutpt,71) utitl(n)                                                
      if (utitl(n)(1:8).eq.uendit) go to 35                                     
      ntitl=n                                                                   
   34 continue                                                                  
   35 continue                                                                  
c                                                                               
c     tempc=temperature, degrees centigrade                                     
c                                                                               
      read(infile,80) tempc                                                     
   80 format(3(12x,e12.5))                                                      
      write (noutpt,500) tempc                                                  
  500 format(7x,'tempc= ',e12.5)                                                
c                                                                               
c     rho = density of solution in g/ml                                         
c     tdspkg = total dissolved salts, mg/kg solution                            
c     tdspl = total dissolved salts, mg/l                                       
c     (enter only one of tdspkg and tdspl)                                      
c                                                                               
      read(infile,80) rho,tdspkg,tdspl                                          
      write (noutpt,505) rho,tdspkg,tdspl                                       
  505 format(9x,'rho= ',e12.5,4x,'tdspkg= ',e12.5,5x,'tdspl= ',e12.5)           
c                                                                               
c     default redox parameters (fo2lg/eh/pe)                                    
c                                                                               
c        fep = one of fo2lg, eh, or pe (iopt1 = 0, -1, or -2,                   
c          respectively)                                                        
c        fo2lg = log oxygen fugacity                                            
c        eh = eh, oxidation-reduction parameter                                 
c        pe = p e-, electron activity                                           
c        uredox = name (all 24 letters) of an                                   
c           auxiliary basis species that is part of a redox couple              
c           that will be used to distribute other redox couples                 
c        note- heterogeneous equilibria can be used also by setting             
c        iopt1=0, fep=0., and jflag(o2(g))= 19, 20, or 21.                      
c                                                                               
      read(infile,705) fep,uredox                                               
  705 format(12x,e12.5,12x,a24)                                                 
      write (noutpt,510) fep,uredox                                             
  510 format(9x,'fep= ',e12.5,4x,'uredox= ',a24)                                
c                                                                               
c     tolbt = convergence tolerance on residual functions                       
c     tolxi = convergence tolerance on correction terms                         
c     tolsat = saturation tolerance for minerals, in kcal.  tolsat              
c              controls the printing of flags in the mineral saturation         
c              state listing.  it does not affect convergence.                  
c                                                                               
      read(infile,80) tolbt,toldl,tolsat                                        
      write (noutpt,515) tolbt,toldl,tolsat                                     
  515 format(7x,'tolbt= ',e12.5,5x,'toldl= ',e12.5,4x,'tolsat= ',e12.5)         
c                                                                               
c     itermx = maximum number of newton-raphson iterations                      
c                                                                               
      read(infile,76) itermx                                                    
   76 format(12x,i2)                                                            
      write (noutpt,516) itermx                                                 
  516 format(5x,'itermx= ',i2)                                                  
c                                                                               
c     iopt1  = option switch for default redox coupling (this is                
c             equivalent to assuming a pool of redox couples are in             
c             equiilbrium with one another and specifying their mutual          
c             redox state by one of the following means                         
c                                                                               
c                 parameters required for any of the options below              
c                 are read in on the 'fep' line above                           
c                                                                               
c          =  0   fo2lg (log fo2(g)) specified                                  
c          = -1   eh specified in volts                                         
c          = -2   p e- specified                                                
c          = -3   fo2lg/eh/pe is specified indirectly by a                      
c                 heterogeneous equilibrium specified below on the              
c                 individual species constraint line for o2(g).                 
c                 jflag must be 19, 20, or 21, and uphas1 must                  
c                 contain the name of the associated mineral or gas             
c                 species.  if the mineral is a solid solution,                 
c                 an end-member must be specified in uphas2.                    
c          =  1   fo2lg/eh/pe is specified indirectly by a redox                
c                 couple such as o2(aq)/h2o, hs-/so4--, or fe++/fe++.           
c                 this option must be supported by independent                  
c                 compositional constraints on each member of the               
c                 couple (except h2o, as in o2(aq)/h2o).  one member            
c                 must be in the strict basis after initial basis               
c                 switching, if any; the other must be in the auxiliary         
c                 basis.  the couple is specified by the first two              
c                 parts (first twelve letters) of the name of the               
c                 auxiliary basis variable.  these are read above into          
c                 the variable uredox.                                          
c     iopt2  = option switch, controls automatic basis switching                
c          =  0   automatic basis switching is turned off                       
c          =  1   automatic basis switching is turned on                        
c     iopt3  = option switch for producing interfacing output                   
c          = -1   no pickup file for input to eq6 is generated                  
c          =  0   a pickup file is generated                                    
c     iopt4  = option switch for solid solutions                                
c          =  0   ignores all solid solutions                                   
c          =  1   processes hypothetical solid solutions                        
c          =  2   reads in solid solution compositions and processes            
c                 both input and hypothetical solid solutions.                  
c     iopt5  = option switch, not currently used                                
c     iopt6  = option switch, controls convergence criteria                     
c          = -1   only the residual functions are tested                        
c          =  0   both residual functions and correction terms are              
c                 tested for convergence of newton-raphson iteration            
c     iopt7  = option switch, controls pickup file format                       
c          =  0   3245 version pickup file is written                           
c          =  1   post-3245 version pickup file is written                      
c     iopt8  = allows and alternate set of azero and hydration                  
c               numbers to be read from file ahv                                
c          = 1  reads ahv                                                       
c          = 0 does not read ahv                                                
c     iopt9  = option switch, not currently used                                
c     iopt10 = option switch, not currently used                                
c                                                                               
      write (noutpt,525)                                                        
  525 format(17x,'1    2    3    4    5    6    7    8    9   10')              
      read(infile,300) iopt1,iopt2,iopt3,iopt4,iopt5,iopt6,iopt7,iopt8,         
     $ iopt9,iopt10                                                             
  300 format(12x,10i5)                                                          
      write (noutpt,305) iopt1,iopt2,iopt3,iopt4,iopt5,iopt6,iopt7,             
     $ iopt8,iopt9,iopt10                                                       
  305 format(3x,'iopt1-10= ',10i5)                                              
      fo2lg=-999.                                                               
      if (iopt1.ge.1) go to 703                                                 
      if (iopt1.le.-3) go to 703                                                
      if (iopt1.le.-1) go to 701                                                
      fo2lg=fep                                                                 
      go to 703                                                                 
  701 if (iopt1.ne.-1) go to 702                                                
      eh=fep                                                                    
      go to 703                                                                 
  702 pe=fep                                                                    
  703 continue                                                                  
      fo2=texp(fo2lg)                                                           
c                                                                               
c     iopg1  = option switch, activity coefficients                             
c                                                                               
c           =  -1   uses davies equation instead of b-dot equation              
c                    (analogous to b-dot) (not implemented)                     
c           =   0   uses b-dot equation                                         
c           =   1   pitzer equations, standard                                  
c           =   2   not used                                                    
c           =   3   w-j hydration theory equations with e-lambda terms          
c           =   4   w-j hydration theory equations w/o e-lambda terms           
c           =   5   not implemented -- hkf equations -- part iv                 
c                                                                               
c     iopg2  = option switch, activity coefficients                             
c           =  -1   use the 'internal' ph scale for a given activity            
c                   coefficient model (specified by iopg1)                      
c           =   0   convert the activity coefficient model to make it           
c                   consistent with the modified nbs ph scale.                  
c                   log gamma cl- is defined by the bates-guggenheim            
c                   expression.  the nbs scale is ambiguous about               
c                   the precise definition of ionic strength, other than        
c                   that it is molal as opposed to molar  (e.g., what           
c                   set of species is to be presumed in its calculation?).      
c                   even the so-called 'stoichiometric' ionic strength is       
c                   always unambiguously definable independent of the           
c                   presumed set of solute species.  here the ionic             
c                   strength is taken as the 'true' ionic strength that         
c                   corresponds to the speciation model used in the present     
c                   application of the code.  the user should be aware          
c                   that even this model may vary according to the data         
c                   file and activity coefficient option employed.  in          
c                   dilute solutions (less dilute say, than seawater, in        
c                   which the ionic strength is about 0.7 molal), this is       
c                   not too much of a problem, numerically speaking.  in        
c                   more concentrated solutions, however, it becomes            
c                   obvious that it was a mistake for the nbs to have           
c                   defined a standard convention in terms of a model           
c                   dependent parameter.  hence the proposed use of the         
c                   rational ph scale (see below).  in this code, no            
c                   upper limit is placed on the value of the ionic             
c                   strength.  the nbs convention has a formal upper limit      
c                   of 0.10 molal.)                                             
c           =   1   convert the activity coefficient model to make it           
c                   consistent with the rational ph scale.                      
c                   (log gamma h+ = 0, so ph = log molality of h+.)             
c                   note that this convention does not depend on any            
c                   model dependent parameters.                                 
c     iopg3  = option switch for iopg1 = 3                                      
c           = 0   use uelam=on                                                  
c           = 1   use uelam=onplus                                              
c     iopg4  = option switch for iopg1 = 3 or 4                                 
c           = 0   compute f(dho)a                                               
c           = 1   compute f(dhc)c                                               
c     iopg5  = option switch for bdot model (iopg1 = 1)                         
c           = 0   use the polynomial for the activity coefficient of            
c                 aqueous co2 to estimate the activity coefficients             
c                 of non-polar neutral solute species                           
c           = 1   substitute a bdot term instead of the polynomial              
c                 for the activity coefficient of aqueous co2                   
c     iopg6  = option switch, activity coefficients                             
c           = 0   use pitzer j                                                  
c           = 1   use harvie j in aqueous species activity                      
c                 coefficient calculation                                       
c     iopg7  = option switch, not currently used                                
c     iopg8  = option switch, not currently used                                
c     iopg9  = option switch, not currently used                                
c     iopg10 = option switch, not currently used                                
c                                                                               
      read(infile,300) iopg1,iopg2,iopg3,iopg4,iopg5,iopg6,iopg7,iopg8,         
     $ iopg9,iopg10                                                             
      write (noutpt,307) iopg1,iopg2,iopg3,iopg4,iopg5,iopg6,iopg7,             
     $ iopt8,iopg9,iopg10                                                       
  307 format(3x,'iopg1-10= ',10i5)                                              
c                                                                               
c     iopr1  = print control option switch                                      
c          =  0   does nothing                                                  
c          =  1   lists the loading of species into memory                      
c     iopr2  = print control option switch                                      
c          =  0   does nothing                                                  
c          =  1   lists all reactions (this can be quite lengthy)               
c          =  2   also prints the log k values                                  
c          =  3   also prints the coefficients of the interpolating             
c                 polynomials                                                   
c     iopr3  = print control option switch                                      
c          =  0   the aqueous species properties are listed in                  
c                 decreasing order of concentration                             
c          =  1   the aqueous species properties are listed in the              
c                 order that the species appear on the thermodynamic            
c                 data file                                                     
c     iopr4  = print control option switch                                      
c          =  0   all species are printed                                       
c          = -1   only species with concentrations .ge. 1.e-20                  
c                 are printed                                                   
c          = -2   only species with concentrations .ge. 1.e-12                  
c                 are printed                                                   
c          = -3   the aqueous species distribution is not printed               
c     iopr5  = print control option switch                                      
c          = -1   turns off printout summarizing the major                      
c                 species contributing to aqueous mass balances                 
c          =  0   this information is printed                                   
c          =  1   the printout includes all aqueous species                     
c                 contributing to each mass balance                             
c     iopr6  = print control option switch                                      
c          =  0   does nothing                                                  
c          =  1   prints the mean ionic properties                              
c     iopr7  = print control option switch                                      
c          = -1   turns off the affinity printout for minerals                  
c          =  0   minerals with affinities less than -10 kcal                   
c                 are not printed                                               
c          =  1   all minerals in memory are printed                            
c     iopr8 = print control option switch                                       
c          = -1   no print                                                      
c          =  0   prints a list of species, ion sizes, and hydration            
c                 numbers                                                       
c     iopr9 =  print control option switch                                      
c          = 0 print only warnings for pitzer coefficients                      
c          = 1 print species in model and number of pitzer coefficients         
c          = 2 print species in model and names of pitzer coefficients          
c     iopr10 = print control option switch                                      
c          =  0   does nothing                                                  
c          =  1   prints the concbs array (stoichiometric                       
c                 concentrations of master species)                             
c     iopr11-20 = print control option switches, not used                       
c                                                                               
      read(infile,300) iopr1,iopr2,iopr3,iopr4,iopr5,iopr6,iopr7,               
     $ iopr8,iopr9,iopr10                                                       
      write (noutpt,310) iopr1,iopr2,iopr3,iopr4,iopr5,iopr6,iopr7,             
     $ iopr8,iopr9,iopr10                                                       
  310 format(3x,'iopr1-10= ',10i5)                                              
c                                                                               
      read(infile,300) iopr11,iopr12,iopr13,iopr14,iopr15,iopr16,               
     $ iopr17,iopr18,iopr19,iopr20                                              
      write(noutpt,312) iopr11,iopr12,iopr13,iopr14,iopr15,iopr16,              
     $ iopr17,iopr18,iopr19,iopr20                                              
  312 format(2x,'iopr11-20= ',10i5)                                             
c                                                                               
c     iodb1  = debugging print option switch                                    
c          =  0   does nothing                                                  
c          =  1   prints some informational messages.  also                     
c                 prevents the stripped input file from being                   
c                 deleted at the end of a run.                                  
c          =  2   same as = 1, but prints more informational messages           
c     iodb2  = debugging print option switch                                    
c          =  0   does nothing                                                  
c          =  1   generates prints of pre-newton-raphson optimizations,         
c                 including automatic basis switching                           
c          =  2   generates prints giving more detailed information             
c                 on pre-newton-raphson optimizations                           
c     iodb3  = debugging print option switch                                    
c          =  0   does nothing                                                  
c          =  1   requests iteration variables to be killed                     
c     iodb4  = debugging print option switch                                    
c          =  0   prints newton-raphson iteration summary                       
c          =  1   prints newton-raphson iteration in detail                     
c     iodb5  = debugging print option switch                                    
c          =  0   does nothing                                                  
c          =  1   prints stoichiometric equivalences for oxygen and             
c                 hydrogen mass balances only                                   
c          =  2   prints stoichiometric equivalences for all mass               
c                 balances                                                      
c     iodb6  = debugging print option switch                                    
c          =  0   does nothing                                                  
c          =  1   prints details of stoichiometric equivalence                  
c                 calculations                                                  
c     iodb7  = debugging print option switch                                    
c          =  0   does nothing                                                  
c          =  1   writes reactions among aqueous species on the file            
c                 called rlist, both as they are written on the data            
c                 file and also after they are re-written after                 
c                 basis switching operations have been done.                    
c     iodb8  = not used debug switch                                            
c     iodb9  = not used switch                                                  
c     iodb10 = not used switch                                                  
c                                                                               
      read(infile,300) iodb1,iodb2,iodb3,iodb4,iodb5,iodb6,iodb7,               
     $  iodb8,iodb9,iodb10                                                      
      write (noutpt,320) iodb1,iodb2,iodb3,iodb4,iodb5,iodb6,iodb7,             
     $  iodb8,iodb9,iodb10                                                      
  320 format(3x,'iodb1-10= ',10i5)                                              
      if (iodb1.ge.1) qtxppr=.true.                                             
c                                                                               
c     uebal = name (all 24 letters) of a charged basis species whose            
c             concentration will be adjusted to achieve electrical              
c             balance.  leave blank if no adjustment is desired.  enter         
c             'pick1.' to have the program pick an ion.                         
c                                                                               
      read(infile,710) uebal                                                    
  710 format(12x,a24)                                                           
      write (noutpt,530) uebal                                                  
  530 format(6x,'uebal= ',a24)                                                  
c                                                                               
c     uacion = name (all 24 letters) of a species (na+ or cl-) that             
c             defines the equivalent stoichiometric ionic strength of           
c             a sodium chloride solution (used to estimate the activity         
c             of water).  enter 'pick1.' to have the program pick one.          
c                                                                               
      read(infile,710) uacion                                                   
      write (noutpt,531) uacion                                                 
  531 format(5x,'uacion= ',a24)                                                 
c                                                                               
c     read in the numbers of aqueous, mineral, gas, and solid solution          
c     species that are to be suppressed or whose associated reactions           
c     are to have their log k values altered from those input from the          
c     file adat1.  note that solid solutions can only be suppressed.            
c     suppression or alteration can not apply to aqueous species in             
c     the strict basis at the time the changes are made effective,              
c     because these species have no assoicated reactions.  at the               
c     present time, the changes are effected in routine indatx, just            
c     after the data on file adat1 have been read.                              
c                                                                               
c        nxmod = the number of suppressed/altered species/reactions             
c                                                                               
      read(infile,76) nxmod                                                     
      write (noutpt,325) nxmod                                                  
  325 format(6x,'nxmod= ',i2)                                                   
c                                                                               
c        uxmod = the name (all 24 letters) of the species                       
c        jxmod = type of species                                                
c           0 aqueous species                                                   
c           1 mineral                                                           
c           2 gas                                                               
c           3 solid solution                                                    
c        kxmod = alteration code                                                
c          -1  the species is suppressed                                        
c           0  the log k is replaced by xlkmod                                  
c           1  the log k is augmented by xlkmod                                 
c           2  same as kxmod=1, but xlkmod is input in units of kcal            
c                 per mole of the associated species                            
c        xlkmod = log k value alteration function defined above                 
c                                                                               
      nerr=0                                                                    
      if (nxmod.gt.0) then                                                      
        if (nxmod.gt.nxmdmx) then                                               
          write (noutpt,1638) nxmdmx                                            
 1638     format(1x,'----- this exceeds the maximum of ',i2,' -----')           
          nerr=nerr+1                                                           
        endif                                                                   
        do 105 n=1,nxmod                                                        
        read(infile,73) uxmod(n),jxmod(n),kxmod(n),xlkmod(n)                    
   73   format(12x,a24,/12x,i2,22x,i2,22x,e12.5)                                
        write (noutpt,540) uxmod(n),jxmod(n),kxmod(n),xlkmod(n)                 
  540   format(4x,'species= ',a24,/7x,'type= ',i2,14x,'option= ',i2,            
     $  14x,'xlkmod= ',e12.5)                                                   
  105   continue                                                                
      endif                                                                     
      if (nerr.gt.0) then                                                       
        write(nttyo,545)                                                        
  545   format(' * nerr .gt. zero')                                             
        stop                                                                    
      endif                                                                     
c                                                                               
c     read data and constraints on aqueous species                              
c                                                                               
c        uspecb = name of an aqueous species in the expanded basis set.         
c        ubasis = name of an aqueous species to be switched with the            
c           corresponding expanded basis species (if no switch is               
c           to be specified, enter blanks or repeat the name of the             
c           expanded basis species).  again, only the first two                 
c           parts of the name are used.                                         
c        jflag = switch defining the meaning of the csp parameter.              
c           jflag values on the input file are read into the                    
c           array jflagb.                                                       
c        csp = a floating point datum (concentration, activity, etc.)           
c           whose meaning is specified by the jflag parameter.                  
c           csp values on the input file are read into the array cspb.          
c        uphas1 = the name of a species which must be designated                
c           to complete a specification for the jflag = 17, 19,                 
c           20 or 21 options.  for jflag = 19, the species specified            
c           is a mineral taken to be in equilbrium with the aqueous             
c           solution.  for jflag = 20, the species is a solid solution          
c           taken to be in equilibrium with the aqueous solution,               
c           and the name of a specific end-member must be specified             
c           in uphas2.                                                          
c        uphas2 = the name of an end-member of a solid solution                 
c           specified in uphas1 for the jflag = 20 option.                      
c                                                                               
c     if a species in the auxiliary basis is being switched into the            
c     strict basis, the switch is indicated by specifying the name              
c     of the former as the ubasis value for the latter.  the switch is          
c     not specified twice, as by specifying the name of the                     
c     strict basis species as the ubasis value for the auxiliary                
c     basis species.  in such an intra-basis switch, the                        
c     input properties (jflag, csp, uphas1, uphas2) follow the species          
c     they are originally assigned to.  in the case of an extra-basis           
c     switch, the input properties are reassigned to the species brought        
c     into the basis.  if the csp property is a total concentration,            
c     it is recalculated for stoichiometric consistency with the                
c     specification for the original basis species.                             
c                                                                               
c     quick summary of the jflag conventions--                                  
c                                                                               
c        = -1   not present in the system as implied by jflag.le.15             
c                  and csp=0.  this value is assigned internally by the         
c                  code and need not be entered on the input file.              
c        =  0   total concentration, molal (csp)                                
c                  note- enter jflag=0 for water and o2(g).  the                
c                  csp parameter for o2(g) is always log fugacity.              
c                  a line for o2(g) is not entered here unless                  
c                  iopt1 = -3                                                   
c        =  1   total concentration, molar (csp)                                
c        =  2   total concentration, mg/l (csp)                                 
c        =  3   total concentration, mg/kg solution (csp)                       
c        =  4   free concentration, molal (csp)                                 
c        =  5   free concentration, molar (csp)                                 
c        =  6   free concentration, mg/l (csp)                                  
c        =  7   free concentration, mg/kg (csp)                                 
c        =  8   free concentration, cc stp/cc solution (csp)                    
c        = 10   titration alkalinity, eq/kg h20 (csp)                           
c                  (this is a slightly dangerous option)                        
c                                                                               
c        = 11   titration alkalinity, eq/l (csp)                                
c                  (this is a slightly dangerous option)                        
c                                                                               
c        = 12   carbonate alkalinity, eq/kg h20 (csp)                           
c        = 13   carbonate alkalinity, eq/l h20 (csp)                            
c        = 16   log activity (molal scale) (csp)                                
c        = 17   log mean activity of the neutral electrolyte                    
c                  composed of the ions specified by uspecb                     
c                  and uphas1 (not currently implemented)                       
c                                                                               
c        = 19   mineral solubility equilibrium-- uphas1 = name of               
c                  pure mineral.  do not use the same mineral twice.            
c                  do not expect the program to find a solution if you          
c                  program a real or apparent violation of the phase            
c                  rule.  the csp parameter is not used.  (this is              
c                  a slightly dangerous option)                                 
c                                                                               
c        = 20   solid solution solubility equilibrium-- uphas1 =                
c                  name of the solid solution and uphas2 =                      
c                  the name of one of its components.                           
c                  see comments above on jflag=19.                              
c                                                                               
c        = 21   gas solubility equilibrium-- uphas1 = name of the gas,          
c                  csp is its log fugacity.  see comments above on              
c                  jflag=19.                                                    
c                                                                               
c        = 27   dependent variable-- the species must be in the                 
c                  auxiliary basis when the calculation commences;              
c                  it and its 'complexes' are treated as 'complexes'            
c                  of the corresponding species in the strict basis,            
c                  but are not limited by the total concentration, if           
c                  there is one, for that corresponding species.  this          
c                  option is intended to be applied mainly to dissolved         
c                  gases (e.g., to estimate ch4(aq) from hco3-).  it            
c                  is a dangerous option if used otherwise.  the danger         
c                  is that unconstrained masses may blow up, not because        
c                  the code is at fault, but because the problem input          
c                  is bad.  in this case the user should rethink what           
c                  the input constraints should be.                             
c                                                                               
c                  for example, suppose you have a sulfate analysis             
c                  of a water and you expect that sulfide species               
c                  may be significant and possibly in equilibrium with          
c                  sulfate.  if you think the sulfate analysis                  
c                  measured both sulfate and sulfide, enter the                 
c                  analytical value as the total concentration of               
c                  sulfate and specify jflag(hs-)=30.  if you think             
c                  the analysis measured only sulfate proper, then              
c                  enter jflag(hs-)=27 instead.  if the redox state of          
c                  the water is very reducing you may get an infinite           
c                  or near-infinite amount of calculated sulfide.               
c                                                                               
c                  no csp datum is required.  use the jflag=30                  
c                  option if you are not sure how jflag=27 works.               
c                                                                               
c        = 30   eliminated variable-- the species is treated as above,          
c                  but it and its 'complexes' are constrained by the            
c                  total concentration entered for the corresponding            
c                  strict basis species.  no csp datum is required.             
c                                                                               
      nlim=nsqmax+1                                                             
      do 250 ns=1,nlim                                                          
      read(infile,97) udum,udum1                                                
   97 format(a8,18x,a24)                                                        
      if (udum(1:8).eq.uendit) then                                             
        write (noutpt,97) uendit                                                
        go to 730                                                               
      endif                                                                     
      write (noutpt,98) udum1                                                   
   98 format(1x,'data file master species= ',a24)                               
      uspecb(ns)=udum1                                                          
c                                                                               
      read(infile,99) udum2                                                     
   99 format(24x,a24)                                                           
      write (noutpt,101) udum2                                                  
  101 format(4x,'switch with species= ',a24)                                    
      ubasis(ns)=udum2                                                          
c                                                                               
      read (infile,102) jdum,cdum                                               
  102 format(10x,i2,8x,e17.9)                                                   
      write (noutpt,103) jdum,cdum                                              
  103 format(4x,'jflag= ',i2,3x,'csp= ',e17.9)
      jflagb(ns)=jdum                                                           
      cspb(ns)=cdum                                                             
      uphas1(ns)=ublank                                                         
      uphas2(ns)=ublank                                                         
c                                                                               
      udum=udum1(1:8)                                                           
      if (udum.eq.uo2g.and.iopt1.ne.-3) then                                    
        write (noutpt,729)                                                      
  729   format(1x,'----- o2(g) input line will be ignored because',             
     $  ' iopt1.ne.-3 -----')                                                   
        jflagb(ns)=0                                                            
        cspb(ns)=0.                                                             
        go to 250                                                               
      endif                                                                     
c                                                                               
      if (jdum.ge.17.and.jdum.le.21) then                                       
        read (infile,104) udum1,udum2                                           
  104   format(11x,a24,11x,a24)                                                 
        write (noutpt,107) udum1,udu                                            
  107   format(12x,'uphas1= ',a24,3x,'uphas2= ',a24)                            
        uphas1(ns)=udum1                                                        
        uphas2(ns)=udum2                                                        
      endif                                                                     
c                                                                               
  250 continue                                                                  
c                                                                               
      write (noutpt,735) nsqmax                                                 
  735 format(/1x,'----- the number of basis species read in exceeds',           
     $ ' the maximum nsqmax = ',i3,' -----')                                    
      write(nttyo,737)                                                          
  737 format(' * nsq .gt. nsqmax')                                              
      stop                                                                      
  730 nsqb=ns-1                                                                 
c                                                                               
c     xbar=mole fraction of end member in a solid solution                      
c                                                                               
      if (iopt4.le.1) go to 65                                                  
      write (noutpt,565)                                                        
  565 format(1x,'solid solutions')                                              
      nxtb=0                                                                    
      nlim=nxtmax+1                                                             
      ilim=iktmax+1                                                             
      do 60 nxb=1,nlim                                                          
      read(infile,370) udum1                                                    
  370 format(3x,a24)                                                            
      write (noutpt,371) udum1                                                  
  371 format(4x,a24)                                                            
      udum=udum1(1:8)                                                           
      if (udum.eq.uendit) go to 65                                              
      nxtb=nxtb+1                                                               
      usolb(nxb)=udum1                                                          
      write (noutpt,570)                                                        
  570 format(1x,'component     mole fraction')                                  
      ndum=0                                                                    
c                                                                               
      do 377 ikb=1,ilim                                                         
      read(infile,375) udum1,xdum                                               
  375 format(6x,a24,3x,f10.4)                                                   
      udum=udum1(1:8)                                                           
      if (udum.eq.uendit) go to 378                                             
      write (noutpt,376) udum1,xdum                                             
  376 format(6x,a24,3x,f10.4)                                                   
      ndum=ndum+1                                                               
      umemb(ikb,nxb)=udum1                                                      
      xbarb(ikb,nxb)=xdum                                                       
  377 continue                                                                  
      go to 379                                                                 
c                                                                               
  378 write (noutpt,376) udum1                                                  
  379 continue                                                                  
      ncompb(nxb)=ndum                                                          
c                                                                               
c     normalize the mole fractions of the input solid-solutions                 
c                                                                               
      sum=0.                                                                    
      do 50 ikb=1,ndum                                                          
      sum=sum+xbar(ikb,nxb)                                                     
   50 continue                                                                  
      if (sum.eq.0.) sum=1.                                                     
      do 55 ikb=1,ndum                                                          
      xbarb(ikb,nxb)=xbarb(ikb,nxb)/sum                                         
   55 continue                                                                  
   60 continue                                                                  
   65 continue                                                                  
c                                                                               
      write (noutpt,2047)                                                       
      write (nttyo,2047)                                                        
 2047 format(/' --- the input file has been successfuly',                       
     $ ' read ---')                                                             
c                                                                               
  999 continue                                                                  
      end                                                                       
c scribx   last revised 12/22/87 by tjw                                         
      subroutine scribx(sigzi,usave)                                            
c                                                                               
c     this routine writes the pickup file, which is used to                     
c     communicate data from eq3nr to eq6.                                       
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "blank.h"                                                        
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nx.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "st.h"                                                           
      include "te.h"                                                           
      include "ti.h"                                                           
      include "tt.h"                                                           
      include "tu.h"                                                           
      include "un.h"                                                           
      include "eqlver.h"                                                       
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "zg.h"                                                           
      include "eqlgp.h"                                        
      include "eqlpp.h"                                        
c                                                                               
      dimension indxn(nsqpar)                                                   
c                                                                               
      character*24 usave(*),udum1,udum2,unone                                   
c                                                                               
      data uxistq/'xisteq'/,uxi/'xi    '/,udshm/'dshm  '/,                      
     $ uact/'act   '/,ugam/'gamma '/,ublank/'      '/,uelect/'electr'/,         
     $ uendit/'endit.'/                                                         
      data unone/'none                    '/                                    
c                                                                               
c     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *         
c                                                                               
      if (iopt3.ge.0) go to 733                                                 
      write (noutpt,737)                                                        
  737 format(1x,'----- no pickup file written -----')                           
      go to 999                                                                 
c                                                                               
  733 continue                                                                  
      write(npkup,1603) urelno,ustage,ueqlrn,ueqlst                             
 1603 format('* pickup file written by eq3nr.'a4,a4,/,                          
     $  '*  supported by eqlib.'a4,a4)                                          
      if (iopt7.ge.1) write (npkup,105)                                         
  105 format('* post-3245 format')                                              
      nerr=0                                                                    
c                                                                               
      do 775 n=1,ntitl                                                          
      write (npkup,1605) utitl(n)                                               
 1605 format(a80)                                                               
  775 continue                                                                  
      if (ntitl.lt.ntitmx) write (npkup,1606) uendit                            
 1606 format(a6)                                                                
c                                                                               
c     uacion is used only with the bdot option                                  
c                                                                               
      udum1=unone                                                               
      if (iopg1 .eq. 0) udum1=uacion                                            
      write (npkup,705) udum1                                                   
  705 format(4x,'uacion= ',a12)                                                 
c                                                                               
      write (npkup,1602) tempc                                                  
 1602 format(4x,'tempci= ',e12.5)                                               
      write (npkup,1600) nxmod                                                  
 1600 format(5x,'nxmod= ',i2)                                                   
c                                                                               
      if (nxmod.le.0) go to 1625                                                
      do 1650 n=1,nxmod                                                         
      kdum=kxmod(n)                                                             
      write (npkup,1643) uxmod(n),jxmod(n),kxmod(n),xlkmod(n)                   
 1643 format(3x,'species= ',a18,/,6x,'type= ',i2,14x,'option= ',i2,             
     $ 14x,'xlkmod= ',e12.5)                                                    
 1650 continue                                                                  
 1625 continue                                                                  
c                                                                               
      write (npkup,1652) iopg1,iopg2,iopg3,iopg4,iopg5,iopg6,                   
     $ iopg7,iopg8,iopg9,iopg10                                                 
 1652 format(5x,'iopg1= ',i2,15x,'iopg2= ',i2,15x,'iopg3= ',i2,/                
     $ 5x,'iopg4= ',i2,15x,'iopg5= ',i2,15x,'iopg6= ',i2,/                      
     $ 5x,'iopg7= ',i2,15x,'iopg8= ',i2,15x,'iopg9= ',i2,/                      
     $ 4x,'iopg10= ',i2)                                                        
c                                                                               
c     restructure the iindx1 and zvclg1 arrays                                  
c        a. for hydration theory or pitzer equations the activity of            
c           water and activity coefficients of the solute species are in        
c           the matrix                                                          
c        b. if iopt7.ge.1, use post-3245 format, which may include              
c           an auxiliary basis set of aqueous species.  component               
c           mass balances are given by cte instead of mte.                      
c                                                                               
c      move iindx1 array to indxn array                                         
c                                                                               
      do 120 kcol=1,ksb                                                         
      indxn(kcol) = iindx1(kcol)                                                
  120 continue                                                                  
c                                                                               
c      build new indxn array                                                    
c                                                                               
      kcol=ksb                                                                  
      if (iopt7.le.0) go to 135                                                 
      do 130 ns=nsb1,nsq                                                        
      if (jsflag(ns).gt.0) go to 130                                            
      if (jflag(ns).eq.30) go to 130                                            
      kcol=kcol+1                                                               
      indxn(kcol)=ns                                                            
      zvclg1(kcol)=conclg(ns)                                                   
  130 continue                                                                  
  135 continue                                                                  
      ksq=kcol                                                                  
      kdim=ksq                                                                  
c                                                                               
      write (npkup,1675) kct,ksq,kdim,kdim,kdim                                 
 1675 format(7x,'kct= ',i2,17x,'ksq= ',i2,17x,'kmt= ',i2,/,                     
     $       7x,'kxt= ',i2,16x,'kdim= ',i2,16x,'kprs=  0')                      
c                                                                               
c     write the components and mass balance totals                              
c                                                                               
      if (iopt7.ge.1) go to 170                                                 
      do 1632 kcol=1,kct                                                        
      nc=indxn(kcol)                                                            
      write (npkup,1612) uelem(nc),mte(nc)                                      
 1612 format(3x,a6,9x,e25.15)                                                   
 1632 continue                                                                  
      go to 190                                                                 
c                                                                               
  170 continue                                                                  
      do 185 kcol=1,kct                                                         
      ns=indxn(kcol)                                                            
      write (npkup,180) uspec(ns),cte(ns)                                       
  180 format(3x,a16,3x,e25.15)                                                  
  185 continue                                                                  
  190 continue                                                                  
c                                                                               
      write (npkup,1612) uelect,sigzi                                           
c                                                                               
      if (ksq.le.ksb) go to 220                                                 
      ksb1=ksb+1                                                                
      do 215 kcol=ksb1,ksq                                                      
      ns=indxn(kcol)                                                            
      write (npkup,180) uspec(ns),cte(ns)                                       
  215 continue                                                                  
  220 continue                                                                  
c                                                                               
c     write the basis variable information                                      
c                                                                               
      do 1635 kcol=1,ksq                                                        
      ns=indxn(kcol)                                                            
      is=ibasis(ns)                                                             
      udum2=usave(ns)                                                           
      if (iopt7.le.0) go to 230                                                 
      udum2=uspec(is)                                                           
  230 continue                                                                  
      write (npkup,1615) uspec(ns),udum2,zvclg1(kcol)                           
 1615 format(3x,a16,3x,a16,3x,e25.15)                                           
      if (jflag(ns).ge.0) go to 1635                                            
      write (noutpt,787)                                                        
      write (npkup,787)                                                         
  787 format(1x,'----- the basis species above is not in',                      
     $ ' the model -----')                                                      
      nerr=nerr+1                                                               
 1635 continue                                                                  
c                                                                               
      if (nerr.gt.0) go to 793                                                  
      write (noutpt,790)                                                        
  790 format(1x,'----- pickup file successfully written -----')                 
      go to 999                                                                 
c                                                                               
  793 write (noutpt,795)                                                        
      write (npkup,795)                                                         
  795 format(1x,'----- bad pickup file written -----')                          
c                                                                               
  999 continue                                                                  
      end                                                                       
c scripx   last revised 12/22/87 by tjw                                         
      subroutine scripx(ars,amn,ags,cdrs,cdrm,cdrg,csts,cess,concbs,            
     $ sigzi,eps100,nct,nsb,nsb1,nsq,nsq1,nst,nrst,nmt,ngt,nxt,nctmax,          
     $ nsqmax,nsqmx1,nstmax,iktmax,narxmx,ntprmx,noutpt,nttyo)                  
c                                                                               
c     print the output describing the computed model of the aqueous             
c     solution.                                                                 
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "an.h"                                                           
      include "cc.h"                                                           
      include "ee.h"                                                           
      include "fg.h"                                                           
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "ka.h"                                                           
      include "ki.h"                                                           
      include "nx.h"                                                           
      include "oo.h"                                                           
      include "op.h"                                                           
      include "op1.h"                                                          
      include "op2.h"                                                          
      include "ps.h"                                                           
      include "st.h"                                                           
      include "te.h"                                                           
      include "tu.h"                                                           
      include "uu.h"                                                           
      include "vv.h"                                                           
      include "vw.h"                                                           
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "yy.h"                                                           
      include "zg.h"                                                           
      include "eqldd.h"                                        
      include "eqlpp.h"                                        
      include "eqlgp.h"                                        
c                                                                               
      character*24 una(2),udm1,udm2                                             
      character*8 us(2)                                                         
c                                                                               
      dimension ars(narxmx,ntprmx,*),amn(narxmx,ntprmx,*),                      
     $ ags(narxmx,ntprmx,*),cdrs(nsqmx1,*),cdrm(nsqmx1,*),                      
     $ cdrg(nsqmx1,*),csts(nsqmax,*),cess(nctmax,*),concbs(*)                   
c                                                                               
      dimension axx(iktpar,iktpar),xbarh(iktpar),xqkx(iktpar),                  
     $ itracx(iktpar),aff(nmtpar),xq(2),af(2)                                   
c                                                                               
      data ublank/'        '/,usat/'satd    '/,ussat/'ssatd   '/,               
     $ undef/'undef   '/,uinput/'input   '/,                                    
     $ ufinal/'final   '/,uadj/'adj     '/,                                     
     $ unone/'none    '/                                                        
      data uhydx/'oh-     '/                                                    
      data qfalse/.false./                                                      
c                                                                               
c----------------------------------------------------------------------         
c                                                                               
      write (noutpt,1332)                                                       
 1332 format(//21x,'----- Summary of the Aqueous Phase -----',/)                
c                                                                               
c     compute the mole totals of the elements in the aqueous phase              
c                                                                               
      write (noutpt,1348)                                                       
 1348 format(/11x,'----- Elemental composition of the aqueous phase',           
     $ ' -----',/)                                                              
      write (noutpt,1350)                                                       
 1350 format(/8x,'element      mg/l',11x,'mg/kg',12x,'moles/kg',/)              
      wfs=(1000000.-tdspkg)/1000000.                                            
c                                                                               
      do 1230 nc=1,nct                                                          
      mte(nc)=0.                                                                
      if (jcflag(nc).le.0) go to 1230                                           
      dum1=0.                                                                   
c                                                                               
      do 1225 nss=1,nst                                                         
      ns=jsort(nss)                                                             
      dum1 = dum1 + cess(nc,ns)*conc(ns)                                        
 1225 continue                                                                  
      dum1 = dum1 + cess(nc,1)*om                                               
c                                                                               
      mte(nc)=dum1                                                              
      dum3=1000.*dum1*atwt(nc)*wfs                                              
      dum2=dum3*rho                                                             
      write (noutpt,1345) uelem(nc),dum2,dum3,dum1                              
 1345 format(10x,a3,2(3x,f13.4),3x,e17.10)                                      
 1230 continue                                                                  
c                                                                               
c     compute the mole totals of the elements (as their corresponding           
c     strict basis species) in the aqueous phase                                
c                                                                               
      write (noutpt,1748)                                                       
 1748 format(//11x,'----- elemental composition as strict',                     
     $ ' basis species -----',/)                                                
      write (noutpt,1750)                                                       
 1750 format(/8x,'species     mg/l',11x,'mg/kg',12x,'moles/kg',/)               
      wfs=(1000000.-tdspkg)/1000000.                                            
c                                                                               
      do 1730 nc=1,nct                                                          
      if (jcflag(nc).le.0) go to 1730                                           
      ns=ibasis(nc)                                                             
      dum1=mte(nc)                                                              
      dum3=1000.*dum1*mwtss(ns)*wfs                                             
      dum2=dum3*rho                                                             
      write (noutpt,1745) uspec(ns),dum2,dum3,dum1                              
 1745 format(10x,a6,f13.4,3x,f13.4,3x,e17.10)                                   
 1730 continue                                                                  
c                                                                               
c     compute and save the calculated total concentration of the                
c     species adjusted for electrical balance                                   
c                                                                               
      if (iebal.le.0) go to 1770                                                
      ctebal=0.                                                                 
      do 1765 nss=1,nst                                                         
      ns = jsort(nss)                                                           
      ctebal = ctebal + csts(iebal,ns)*conc(ns)                                 
 1765 continue                                                                  
 1770 continue                                                                  
c                                                                               
c     compute and output the equivalent mole totals of the elements             
c                                                                               
c        reset jflag parameters implying equilibrium with the                   
c        corresponding strict basis species to 30                               
c                                                                               
      if (iopt1 .gt. 0) then                                                    
        nse = iopt1 + nsb                                                       
        jflag(nse) = 30                                                         
        call elim(nse,ars,amn,ags,cdrs,cdrm,cdrg,eps100,                        
     $  nsb,nsq1,nrst,nmt,ngt,nsqmx1,narxmx,ntprmx,noutpt,nttyo)                
      endif                                                                     
c                                                                               
      do 204 nse=nsb1,nsq                                                       
      if (jflag(nse) .eq. 27) then                                              
        jflag(nse)=30                                                           
        call elim(nse,ars,amn,ags,cdrs,cdrm,cdrg,eps100,                        
     $  nsb,nsq1,nrst,nmt,ngt,nsqmx1,narxmx,ntprmx,noutpt,nttyo)                
      endif                                                                     
  204 continue                                                                  
c                                                                               
      call gcsts(csts,cdrs,cstor,ibasis,jsflag,jflag,                           
     $ nhydr,nct,nsb,nsb1,nsq,nsq1,nst,nsqmax,nsqmx1,nstmax,
     $ qbassw)                    
c                                                                               
      write (noutpt,205)                                                        
  205 format(//11x,'--- equivalent composition of the',                         
     $ ' aqueous phase (cte balances) ---',//                                   
     $ 12x,'original basis',24x,'existing basis')                               
      write (noutpt,210)                                                        
  210 format(/2(3x,'species              moles/kg h2o'),/)                      
c                                                                               
      do 230 nse = 1,nsq                                                        
      cte(nse) = 0.                                                             
      if (jsflag(nse) .gt. 0) go to 230                                         
      if (jflag(nse) .eq. 30) go to 230                                         
      if (nse .eq. nsb) go to 230                                               
      ctot  =  0.                                                               
      do 225 nss = 1,nst                                                        
      ns = jsort(nss)                                                           
      ctot = ctot + csts(nse,ns)*conc(ns)                                       
  225 continue                                                                  
      ctot = ctot + csts(nse,1)*om                                              
      cte(nse) = ctot                                                           
      ise = ibasis(nse)                                                         
C
C     ctoti = ctot/csts(nse,ise)                                                
      CTOTI = 5.0
C
      write (noutpt,227) uspec(ise),ctoti,uspec(nse),ctot                       
  227 format(2(5x,a12,3x,e17.10))                                               
  230 continue                                                                  
c                                                                               
      call molint(conc,nsq,nst,cdrs,nsqmx1,nsb,3,concbs)                        
      if (iopr10 .ge. 1) then                                                   
        write (noutpt,242)                                                      
  242   format(//11x,'--- stoichiometric composition of the',                   
     $  ' aqueous phase (concbs) ---',/)                                        
        write (noutpt,244)                                                      
  244   format(/3x,'species              moles/kg h2o',/)                       
        do 245 nse = 2,nsq                                                      
        if (jsflag(nse) .le. 0) then                                            
          write (noutpt,227) uspec(nse),concbs(nse)                             
        endif                                                                   
  245   continue                                                                
      endif                                                                     
c                                                                               
c     compute and print ph, eh, and pe, all with reference to                   
c     appropriate ph scales.  compute and print phcl.                           
c                                                                               
      qnochb = .false.                                                          
      call gpheh(actlg,glg,fo2lg,xi,adh,xlkeh,ehfac,ph,                         
     $ phnbs,phrat,phcl,eh,ehnbs,ehrat,pe,penbs,perat,iopg2,                    
     $ nhydr,nchlor,qnochb)                                                     
c                                                                               
      call prpheh(ph,phnbs,phrat,phcl,eh,ehnbs,ehrat,pe,                        
     $ penbs,perat,iopg2,nchlor,noutpt,qnochb)                                  
c                                                                               
      alw = glg(1)                                                              
      aw = texp(alw)                                                            
      write (noutpt,1331) aw,alw                                                
 1331 format(/29x,'activity of water = ',f10.5,                                 
     $ /25x,'log activity of water = ',f10.5)                                   
c                                                                               
      call gsigm(conc,jsort,nst,sigmam)                                         
      sigstm = 0.                                                               
      do 240 ns = 2,nsq                                                         
      sigstm = sigstm + concbs(ns)                                              
  240 continue                                                                  
c                                                                               
      osfac = - om * log(aw)                                                    
      osc = osfac/sigmam                                                        
      stosc = osfac/sigstm                                                      
      write (noutpt,1112) osc,stosc                                             
 1112 format(/20x,'true osmotic coefficient= ',f10.5,                           
     $ /10x,'stoichiometric osmotic coefficient= ',f10.5)                       
                                                                                
      write (noutpt,1110) sigmam,sigstm                                         
 1110 format(/20x,'sum of true molalities= ',f18.13,                            
     $ /10x,'sum of stoichiometric molalities= ',f18.13)                        
                                                                                
      if (tempc .le. 50.) then                                                  
        alkt=0.0                                                                
        do 1235 nss=1,nst                                                       
        ns=jsort(nss)                                                           
        alkt=alkt+titr(ns)*conc(ns)                                             
 1235   continue                                                                
        jflc=10                                                                 
        if (ncarb.gt.0) then                                                    
          jflc=jflag(ncarb)                                                     
        endif                                                                   
        if (jflc.eq.10) then                                                    
          write (noutpt,1375) alkt                                              
 1375     format(/20x,'titration alkalinity= ',f18.13,' eq/kg h2o')             
        elseif (jflc.eq.12) then                                                
          write (noutpt,105)  alkt                                              
  105     format(/20x,'carbonate alkalinity= ',f18.13,' eq/kg h2o')             
        endif                                                                   
      endif                                                                     
c                                                                               
      call gxisto(zsq2,conc,nsq,concbs,xistoc)                                  
      write (noutpt,1330) xi,xistoc                                             
 1330 format(/20x,'true ionic strength= ',f18.13,                               
     $ /10x,'stoichiometric ionic strength= ',f18.13)                           
c                                                                               
      if (iopg1.eq.0) then                                                      
        if (iacion.gt.0) then                                                   
        write (noutpt,1233) uspec(iacion),xisteq                                
 1233   format(/8x,'equiv. stoich. ionic strength (',a6,') = ',                 
     $  f18.13)                                                                 
       endif                                                                    
      elseif (qhydth) then                                                      
        write (noutpt,1327) shm,dshm                                            
 1327   format(8x,'sigma(hm) = ',f18.13,/                                       
     $  8x,'( 1.0 - (sigma(hm)/55.51) ) = ',f18.13)                             
      endif                                                                     
c                                                                               
c     calculate and print the electrical balance and the cation and             
c     anion contributions                                                       
c                                                                               
      call gszm(z,conc,jsort,nst,sigzc,sigza,sigzm,sigzi)                       
c                                                                               
      msigzm=0.5*sigzm                                                          
      sanion = - sigza                                                          
c                                                                               
      write (noutpt,1792)                                                       
 1792 format(/11x,'----- electrical balance totals -----',///                   
     $ 47x,'equiv/kg',/)                                                        
      write (noutpt,1794) sigzc,sanion,sigzm,msigzm,sigzi                       
 1794 format(22x,'sigma(mz) cations = ',3x,e17.10,/                             
     $ 22x,'sigma(mz) anions  = ',3x,e17.10,/                                   
     $ 27x,'total charge = ',3x,e17.10,/28x,'mean charge = ',3x,e17.10,/        
     $ 23x,'charge imbalance = ',3x,e17.10,//                                   
     $ 12x,'total charge = sigma(mz) cations + abs ( sigma(mz) anions )'        
     $ ,/12x,'mean charge = 1/2 total charge')                                  
      dum=100.*sigzi                                                            
      dum1=dum/sigzm                                                            
      dum2=dum/msigzm                                                           
      dum3=dum/sigzc                                                            
      dum4=-dum/sanion                                                          
      write (noutpt,1793) dum1,dum2,dum3,dum4                                   
 1793 format(//12x,'the electrical imbalance is ',//                            
     $ 25x,f8.2,' per cent of the total charge',/                               
     $ 25x,f8.2,' per cent of the mean charge',/                                
     $ 25x,f8.2,' per cent of sigma(mz) cations',/                              
     $ 25x,f8.2,' per cent of abs ( sigma(mz) anions )')                        
c                                                                               
c     print results of electrical balancing                                     
c                                                                               
      if (iebal.le.0) go to 1790                                                
      jfdum=jflag(iebal)                                                        
      udum1=uinput                                                              
      udum2=ufinal                                                              
      udum3=uadj                                                                
      write (noutpt,1775) uspec(iebal)                                          
 1775 format(//11x,'----- electrical balancing on ',a6,' -----')                
      if (jfdum.ne.0) go to 1778                                                
      cdum1=csp(iebal)                                                          
      write (noutpt,1777)                                                       
 1777 format(/8x,'            mg/l',11x,'mg/kg',12x,'moles/kg',/)               
      cdum3=1000.*cdum1*mwtss(iebal)*wfs                                        
      cdum2=cdum3*rho                                                           
      write (noutpt,1745) udum1,cdum2,cdum3,cdum1                               
      cdum1=ctebal                                                              
      cdum3=1000.*cdum1*mwtss(iebal)*wfs                                        
      cdum2=cdum3*rho                                                           
      write (noutpt,1745) udum2,cdum2,cdum3,cdum1                               
      cdum1=ctebal-csp(iebal)                                                   
      cdum3=1000.*cdum1*mwtss(iebal)*wfs                                        
      cdum2=cdum3*rho                                                           
      write (noutpt,1745) udum3,cdum2,cdum3,cdum1                               
      go to 1790                                                                
c                                                                               
 1778 if (jfdum.ne.16) go to 1790                                               
      write (noutpt,1779)                                                       
 1779 format(/8x,'        log activity',/)                                      
      cdum1=csp(iebal)                                                          
      cdum2=actlg(iebal)                                                        
      write (noutpt,1745) udum1,cdum1                                           
      write (noutpt,1745) udum2,cdum2                                           
      cdum3=cdum2-cdum1                                                         
      write (noutpt,1745) udum3,cdum3                                           
 1790 continue                                                                  
c                                                                               
c     compute and print activity ratios of cations to hydrogen ion              
c                                                                               
      write (noutpt,28)                                                         
   28 format(//21x,'----- activity ratios of ions -----',/)                     
      acthyd=actlg(nhydr)                                                       
c                                                                               
      do 20 ns=2,nsq                                                            
      if (ns.eq.nhydr) go to 20                                                 
      ks=ibasis(ns)                                                             
      if (jsflag(ks).ge.2) go to 20                                             
      if (ks.gt.nsq) go to 29                                                   
      if (jflag(ks).le.-1) go to 20                                             
   29 continue                                                                  
      zz=z(ks)                                                                  
      actrat=actlg(ks)                                                          
      if (zz.ne.0.) go to 21                                                    
      write (noutpt,22) uspec(ks),actrat                                        
   22 format(11x,'log ( act(',a12,')               ) = ',2x,f9.4)               
      go to 20                                                                  
c                                                                               
   21 continue                                                                  
      iz=int(abs(zz)+0.001)                                                     
      actrat=actrat-zz*acthyd                                                   
      if (zz.gt.0.) go to 23                                                    
      write (noutpt,30) uspec(ks),iz,actrat                                     
   30 format(11x,'log ( act(',a12,') x act(h+)xx',i2,' ) = ',2x,f9.4)           
      go to 20                                                                  
c                                                                               
   23 continue                                                                  
      write (noutpt,27) uspec(ks),iz,actrat                                     
   27 format(11x,'log ( act(',a12,') / act(h+)xx',i2,' ) = ',2x,f9.4)           
   20 continue                                                                  
c                                                                               
c     print the aqueous species distribution                                    
c                                                                               
      if (iopr4.le.-3) go to 1222                                               
      write (noutpt,705)                                                        
  705 format(//11x,'----- distribution of aqueous species -----',/)             
      if (iopr4.ge.0) go to 720                                                 
      if (iopr4.le.-2) go to 710                                                
      write (noutpt,707)                                                        
  707 format(16x,'(species with concentrations .lt. 1.e-20 are',                
     $ ' not listed)',/)                                                        
      go to 720                                                                 
c                                                                               
  710 continue                                                                  
      write (noutpt,712)                                                        
  712 format(16x,'(species with concentrations .lt. 1.e-12 are',                
     $ ' not listed)',/)                                                        
  720 write (noutpt,1335)                                                       
 1335 format(7x,'species',10x,'molal conc',3x,'log conc',                       
     $ 6x,'log g',4x,'activity',5x,'log act',/)                                 
c                                                                               
      do 1220 nnn=1,nst                                                         
      if (iopr3.ge.1) go to 722                                                 
      nss=nst+1-nnn                                                             
      ns=jsort(nss)                                                             
      go to 723                                                                 
  722 continue                                                                  
      ns=ibasis(nnn)                                                            
  723 continue                                                                  
      if (jsflag(ns).ge.2) go to 1220                                           
      cdum=conclg(ns)                                                           
      if (cdum.le.-999.) go to 1220                                             
      if (iopr4.ge.0) go to 1221                                                
      if (iopr4.ne.-1) go to 1223                                               
      if (cdum.ge.-20.) go to 1221                                              
      if (iopr3.le.0) go to 1222                                                
      go to 1220                                                                
c                                                                               
 1223 continue                                                                  
      if (cdum.ge.-12.) go to 1221                                              
      if (iopr3.le.0) go to 1222                                                
      go to 1220                                                                
c                                                                               
 1221 continue                                                                  
      write (noutpt,1340) uspec(ns),conc(ns),cdum,                              
     $ glg(ns),act(ns),actlg(ns)                                                
 1340 format(3x,a18,2x,e16.9,2x,f9.4,2x,f9.4,2x,e16.9,2x,
     $ f9.4)                                                                    
 1220 continue                                                                  
 1222 continue                                                                  
      if(iopr6 .eq. 0) go to 275                                                
c                                                                               
c      output the mean ionic activity coefficients                              
c                                                                               
      write (noutpt,1116)                                                       
 1116 format(//,11x,'----- mean ionic properties -----',/)                      
      write (noutpt,1118)                                                       
 1118 format(52x,'true (a)',12x,'stoichiometric (b)',//                         
     $ 3x,'species',2x,'species',3x,'log a(+/-)',4x,'a(+/-)',6x,                
     $ 'm(+/-)',6x,'g(+/-)',6x,'m(+/-)',6x,'g(+/-)',/)                          
c                                                                               
      do 270 n1 = 2,nsq                                                         
      ns1=ibasis(n1)                                                            
      z1 = z(ns1)                                                               
      if (z1.le.0.) go to 270                                                   
      if (jsflag(ns1).gt.0) go to 270                                           
      cte1=cte(ns1)                                                             
      if (ns1.eq.nhydr) cte1=cte1-om                                            
c                                                                               
      do 260 n2 = 2,nsq                                                         
      ns2=ibasis(n2)                                                            
      z2=z(ns2)                                                                 
      if (z2.ge.0.) go to 260                                                   
      if (jsflag(ns2).gt.0) go to 260                                           
c   skip the h+ and oh- pair                                                    
      if (ns1.ne.nhydr) go to 262                                               
      if (uspec(ns2)(1:8) .ne. uhydx(1:8)) go to 262                            
      go to 260                                                                 
c                                                                               
  262 zdum=z1-z2                                                                
      almean= (z1*actlg(ns2) - z2*actlg(ns1))/zdum                              
      amean=texp(almean)                                                        
      cdum= (z1*conclg(ns2) - z2*conclg(ns1))/zdum                              
      cfree=texp(cdum)                                                          
      gdum = (z1*glg(ns2) - z2*glg(ns1))/zdum                                   
      gfree = texp(gdum)                                                        
      cte2=cte(ns2)                                                             
      if (uspec(ns2)(1:8) .eq. uhydx(1:8)) cte2=cte(1)-om                       
      if (cte1.le.0.) go to 263                                                 
      if (cte2.le.0.) go to 263                                                 
      ctelg1=tlg(cte1)                                                          
      ctelg2=tlg(cte2)                                                          
      cdum1= (z1*ctelg2 - z2*ctelg1)/zdum                                       
      cstoi=texp(cdum1)                                                         
      gdum1=almean-cdum1                                                        
      gstoi=texp(gdum1)                                                         
c                                                                               
      write (noutpt,1120) uspec(ns1),uspec(ns2),                                
     $    almean,amean,cfree,gfree,cstoi,gstoi                                  
      go to 260                                                                 
  263 write (noutpt,1120) uspec(ns1),uspec(ns2),                                
     $    almean,amean,cfree,gfree                                              
 1120 format(3x,2(2x,a6),2x,f10.5,5(2x,1pe10.3))                                
  260 continue                                                                  
c                                                                               
  270 continue                                                                  
      write (noutpt,1117)                                                       
 1117 format(/3x,'(a) true quantities consistent with the speciation',          
     $ ' model',/3x,'(b) stoichiometric quantities consistent with the',        
     $ ' cte mass',/3x,' balance lumpings, except that',/                       
     $ 3x,'   1. effective cte(h+)  = cte(h+) - conc(h2o)',/                    
     $ 3x,'   2. effective cte(oh-) = cte(h2o) - conc(h2o)',/)                  
c                                                                               
  275 continue                                                                  
c                                                                               
c     print the contributions of aqueous species to each mass balance           
c                                                                               
      if (iopr5.le.-1) go to 875                                                
      if (iopr5.ge.1) go to 807                                                 
      write (noutpt,805)                                                        
  805 format(//11x,'----- major aqueous species contributing',                  
     $ ' to mass balances -----',/)                                             
      go to 809                                                                 
c                                                                               
  807 continue                                                                  
      write (noutpt,808)                                                        
  808 format(//11x,'----- aqueous species by contribution to mass',             
     $ ' balances -----',/)                                                     
  809 continue                                                                  
c                                                                               
      do 870 nse=2,nsq                                                          
      if (nse.eq.nsb) go to 870                                                 
      if (nse.eq.nhydr) go to 870                                               
      jfdum=jflag(nse)                                                          
      if (jfdum.eq.-1) go to 870                                                
      if (jfdum.eq.30) go to 870                                                
      ise=ibasis(nse)                                                           
      if (iopr5.ge.1) go to 811                                                 
      write (noutpt,810) uspec(ise)                                             
  810 format(/,' aqueous species accounting for 99% or more of ',a18,           
     $ //,5x,'species',12x,'molal conc',4x,'per cent',/)                        
      go to 814                                                                 
c                                                                               
  811 continue                                                                  
      write (noutpt,812) uspec(ise)                                             
  812 format(/1x,'aqueous species accounting for ',a18,                         
     $ //5x,'species',12x,'molal conc',4x,'per cent',/)                         
  814 continue                                                                  
c                                                                               
      cdum1=cte(nse)                                                            
      if(cdum1 .eq. 0.) cdum1 = 1e-20                                           
      cdum2=100./cdum1                                                          
      pdum1=0.                                                                  
c                                                                               
      do 820 ndum=1,nst                                                         
      nss=nst+1-ndum                                                            
      ns=jsort(nss)                                                             
      cdum=csts(nse,ns)                                                         
      if (cdum.eq.0.) go to 820                                                 
      cdum3=conc(ns)                                                            
      cdum4=cdum*cdum3                                                          
      pdum=cdum4*cdum2                                                          
      pdum1=pdum1+pdum                                                          
      write (noutpt,815) uspec(ns),cdum3,pdum                                   
  815 format(3x,a18,3x,e11.4,3x,f6.2)                                           
      if (pdum1.lt.99.0) go to 820                                              
      if (iopr5.le.0) go to 860                                                 
  820 continue                                                                  
c                                                                               
  860 write (noutpt,865) pdum1                                                  
  865 format(1x,'- - - - - - - - - - - - - - - - - - - - - - -',/               
     $ 3x,'total',30x,f6.2,/)                                                   
  870 continue                                                                  
c                                                                               
  875 continue                                                                  
c                                                                               
c     compute and print the state of aqueous redox reactions                    
c                                                                               
      write (noutpt,305)                                                        
  305 format(//11x,'----- summary of aqueous redox reactions -----',//          
     $ 6x,'couple',9x,'eh, volts',6x,'pe-',7x,'log fo2',5x,'ah, kcal',/)        
      ahfac=0.001*farad                                                         
      eh=(ehfac/4.)*(fo2lg+4.*actlg(nhydr)-2.*alw-xlkeh)                        
      pe=eh/ehfac                                                               
      ah=ahfac*eh                                                               
      write (noutpt,314) eh,pe,fo2lg,ah                                         
  314 format(3x,'default',11x,f7.3,3x,e11.4,3x,f8.3,4x,f8.3)                    
c                                                                               
      do 350 nsc=nsb1,nsq                                                       
      if (jsflag(nsc).ge.2) go to 350                                           
      if (nsc.gt.nsq) go to 312                                                 
      if (jflag(nsc).le.-1) go to 350                                           
  312 continue                                                                  
      nrs=nsc-nsb                                                               
      cdum1=cdrs(nsb,nrs)                                                       
      if (cdum1.eq.0.) go to 350                                                
      isc=ibasis(nsc)                                                           
      udm1=uspec(isc)                                                           
      udm2=uspec(1)                                                             
      fdum=xlks(nrs)-cdrs(1,nrs)*alw-cdrs(nsq1,nrs)*actlg(nsc)                  
c                                                                               
      do 310 ns=2,nsq                                                           
      if (ns.eq.nsb) go to 310                                                  
      cdum=cdrs(ns,nrs)                                                         
      if (cdum.eq.0.) go to 310                                                 
      if (jsflag(ns).ge.2) go to 350                                            
      fdum=fdum-cdum*actlg(ns)                                                  
      if (ns.eq.nhydr) go to 310                                                
      is=ibasis(ns)                                                             
      udm2=uspec(is)                                                            
  310 continue                                                                  
c                                                                               
      fdum=fdum/cdum1                                                           
      edum=(ehfac/4.)*(fdum+4.*actlg(nhydr)-2.*alw-xlkeh)                       
      pdum=edum/ehfac                                                           
      adum=ahfac*edum                                                           
      write (noutpt,315) udm1,udm2,edum,pdum,fdum,adum                          
  315 format(3x,a8,'/',a8,1x,f7.3,3x,e11.4,3x,f8.3,4x,f8.3)                     
  350 continue                                                                  
c                                                                               
c     compute and print the state of aqueous non-equilibrium, non-redox         
c     reactions                                                                 
c                                                                               
      write (noutpt,420)                                                        
  420 format(//11x,'----- summary of aqueous non-equilibrium',                  
     $ ' non-redox reactions -----',//6x,'couple',7x,                           
     $ 'affinity, kcal',/)                                                      
      kount=0                                                                   
c                                                                               
      do 450 nsc=nsb1,nsq                                                       
      if (jsflag(nsc).ge.2) go to 450                                           
      jfdum=jflag(nsc)                                                          
      if (jfdum.le.-1) go to 450                                                
      if (jfdum.eq.30) go to 450                                                
      if (jfdum.eq.27) go to 450                                                
      nrs=nsc-nsb                                                               
      cdum=cdrs(nsb,nrs)                                                        
      if (cdum.ne.0.) go to 450                                                 
      ise=ibasis(nsc)                                                           
      udum1=uspec(ise)(1:8)                                                     
      udum2=uspec(1)(1:8)                                                       
      kount=kount+1                                                             
      afdum=-xlks(nrs)+cdrs(1,nrs)*alw+cdrs(nsq1,nrs)*actlg(nsc)                
c                                                                               
      do 430 ns=2,nsq                                                           
      cdum=cdrs(ns,nrs)                                                         
      if (cdum.eq.0.) go to 430                                                 
      if (jsflag(ns).ge.2) go to 450                                            
      adum=actlg(ns)                                                            
      afdum=afdum+cdum*adum                                                     
      if (ns.eq.nhydr) go to 430                                                
      is=ibasis(ns)                                                             
      udum2=uspec(is)(1:8)                                                      
  430 continue                                                                  
      afdum=afcnst*afdum                                                        
      write (noutpt,435) udum1,udum2,afdum                                      
  435 format(6x,a6,'/',a6,2x,f8.3)                                              
  450 continue                                                                  
c                                                                               
      if (kount.le.0) write (noutpt,455)                                        
  455 format(6x,'none')                                                         
c                                                                               
c     compute and print mineral saturation states.  these results               
c     refer to the mineral dissolution reactions as they are currently          
c     written in the cdrm array.                                                
c                                                                               
c        nsat = no. of saturations of pure minerals                             
c        ksat = no. of supersaturations of pure minerals                        
c        nxsat = no. of saturated solid-solution end-members among              
c           solid solutions of input composition.                               
c        kxsat = no. of supersaturated end-members among the                    
c           solid solutions of input composition                                
c        nxhsat = no. of saturated end-members among the hypothetical           
c           solid solutions                                                     
c        kxhsat = no. of hypothetically supersaturated solid-solution           
c           phases                                                              
c                                                                               
      nsat=0                                                                    
      nxsat=0                                                                   
      nxhsat=0                                                                  
      ksat=0                                                                    
      kxsat=0                                                                   
      kxhsat=0                                                                  
c                                                                               
      do 1265 nm=1,nmt                                                          
      aff(nm)=-999.                                                             
      xlqk(nm)=-999.                                                            
      xlq=cdrm(nsb,nm)*fo2lg                                                    
c                                                                               
      do 1240 ns=1,nsq                                                          
      if (ns.eq.nsb) go to 1240                                                 
      cdum=cdrm(ns,nm)                                                          
      if (cdum.eq.0.) go to 1240                                                
      if (jsflag(ns).ge.2) go to 1265                                           
      xlq=xlq+cdum*actlg(ns)                                                    
 1240 continue                                                                  
c                                                                               
      xlqk(nm)=xlq-xlkm(nm)                                                     
      aff(nm)=afcnst*xlqk(nm)                                                   
 1265 continue                                                                  
c                                                                               
c     print a saturation state summary for stoichiometric minerals              
c                                                                               
      if (iopr7.le.-1) go to 950                                                
      write (noutpt,905)                                                        
  905 format(//11x,'----- summary of stoichiometric mineral',                   
     $ ' saturation states -----',/)                                            
      if (iopr7.eq.0) write (noutpt,910)                                        
  910 format(11x,'(minerals with affinities .lt. -10 kcal are not',             
     $ ' listed)',/)                                                            
      write (noutpt,915)                                                        
  915 format(/3x,'mineral',7x,'log q/k',3x,'aff, kcal',2x,                      
     $ 'state',11x,'mineral',7x,'log q/k',3x,'aff, kcal',2x,'state',/)          
      num=0                                                                     
      kount=0                                                                   
c                                                                               
      do 940 nm=1,nmt                                                           
      if (jmflag(nm).ge.2) go to 925                                            
      if (iopr7.ge.1) go to 920                                                 
      if (aff(nm).lt.-10.0) go to 925                                           
  920 continue                                                                  
      num=num+1                                                                 
      kount=kount+1                                                             
      us(num)=ublank                                                            
      afdum=aff(nm)                                                             
      adum=abs(afdum)                                                           
      if (adum.gt.tolsat) go to 922                                             
      nsat=nsat+1                                                               
      us(num)=usat                                                              
      go to 923                                                                 
c                                                                               
  922 continue                                                                  
      if (afdum.lt.0.) go to 923                                                
      ksat=ksat+1                                                               
      us(num)=ussat                                                             
  923 continue                                                                  
      una(num)=umin(nm)                                                         
      xq(num)=xlqk(nm)                                                          
      af(num)=aff(nm)                                                           
  925 continue                                                                  
      if (num.le.0) go to 940                                                   
      if (num.ge.2) go to 930                                                   
      if (nm.lt.nmt) go to 940                                                  
  930 continue                                                                  
      write (noutpt,935) (una(n),xq(n),af(n),us(n),                             
     $ n=1,num)                                                                 
  935 format(1x,a12,2(2x,f9.3),2x,a5,10x,a12,2(2x,f9.3),2x,a5)                  
      num=0                                                                     
  940 continue                                                                  
c                                                                               
      if (kount.le.0) write (noutpt,935) unone                                  
  950 continue                                                                  
c                                                                               
      if (iopt4.eq.0) go to 1315                                                
      if (iopt4.ne.2) go to 1495                                                
c                                                                               
c     compute saturation states for input solid-solution compositions.          
c                                                                               
      write (noutpt,1432)                                                       
 1432 format('1',//31x,'----- summary of input solid solutions -----',/)        
      write (noutpt,1380)                                                       
 1380 format(7x,'mineral',13x,'log q/k',8x,'aff, kcal',6x,                      
     $ 'state',/)                                                               
c                                                                               
      do 1300 nxb=1,nxtb                                                        
      nx=nxspec(nxb)                                                            
      write (noutpt,1355) usolx(nx)                                             
 1355 format(/4x,a18,/)                                                         
      ncpt=ncomp(nx)                                                            
c                                                                               
      ssum = 0.                                                                 
      do 1295 ik=1,ncpt                                                         
      nm=nend(ik,nx)                                                            
      if(nm.eq.0) go to 1295                                                    
c    skip if comp not present                                                   
      if (jmflag(nm).ge.2) go to 1295                                           
      affx(ik,nx)=-999.                                                         
      xdum=xlqk(nm)                                                             
      if (xdum.le.-999.) go to 1272                                             
      xlqkx=xdum+cdrm(nsq1,nm)*(xbarlg(ik,nx)+lamlg(ik,nx))                     
      affx(ik,nx)=afcnst*xlqkx                                                  
c    add up contribution for each endmember                                     
      ssum = ssum + xbar(ik,nx)*xlqkx                                           
 1272 if (abs(affx(ik,nx)).le.tolsat) go to 1275                                
      go to 1280                                                                
c                                                                               
 1275 continue                                                                  
      nxsat=nxsat+1                                                             
      write (noutpt,1385) umin(nm),xlqkx,affx(ik,nx)                            
 1385 format(/,3x,a18,2(2x,f13.7),5x,'approx. saturated')                       
      go to 1295                                                                
c                                                                               
 1280 continue                                                                  
      if (affx(ik,nx).lt.0.) go to 1285                                         
      go to 1290                                                                
c                                                                               
 1285 continue                                                                  
      write (noutpt,1390) umin(nm),xlqkx,affx(ik,nx)                            
 1390 format(/,3x,a18,2(2x,f13.7),5x,'undersaturated')                          
      go to 1295                                                                
c                                                                               
 1290 continue                                                                  
      kxsat=kxsat+1                                                             
      write (noutpt,1395) umin(nm),xlqkx,affx(ik,nx)                            
 1395 format(/,3x,a18,2(2x,f13.7),5x,'supersaturated')                          
 1295 continue                                                                  
      afss = afcnst*ssum                                                        
      write (noutpt,1394)                                                       
 1394 format(/,4x,'For fixed composition solid solution phase:')                
      write (noutpt,1399) usolx(nx),ssum,afss                                   
 1399 format(/,3x,a18,2(2x,f13.7))                                              
 1300 continue                                                                  
c                                                                               
      do 1310 nxb=1,nxtb                                                        
      nx=nxspec(nxb)                                                            
      k=jsol(nx)+1                                                              
      write (noutpt,1440) usolx(nx),uxtype(k)                                   
 1440 format(/1x,a18,/6x,a30,/)                                                 
      write (noutpt,1435)                                                       
 1435 format(27x,'xbar',9x,'lamda',9x,'activity',5x,'log xbar',5x,              
     $ 'log lamda',4x,'log act',/)                                              
      ncpt=ncomp(nx)                                                            
c                                                                               
      do 1305 ik=1,ncpt                                                         
      nm=nend(ik,nx)                                                            
      if (nm.eq.0 ) go to 1305                                                  
      if (jmflag(nm).ge.2) go to 1305                                           
      xlamda=texp(lamlg(ik,nx))                                                 
      actxlg=xbarlg(ik,nx)+lamlg(ik,nx)                                         
      actx=texp(actxlg)                                                         
      if(xbar(ik,nx).le.1.0d-4) then                                            
      write (noutpt,1546) umin(nm),xbar(ik,nx),xlamda,actx,                     
     $ xbarlg(ik,nx),lamlg(ik,nx),actxlg                                        
1546  format(8x,a12,2x,e10.3,4x,f10.4,4x,e10.3,3(4x,f10.4))                     
      else                                                                      
      write (noutpt,1445) umin(nm),xbar(ik,nx),xlamda,actx,                     
     $ xbarlg(ik,nx),lamlg(ik,nx),actxlg                                        
 1445 format(8x,a12,2x,6(f10.4,4x))                                             
      end if                                                                    
 1305 continue                                                                  
c                                                                               
 1310 continue                                                                  
c                                                                               
c     compute hypothetical saturation states for solid solutions.               
c                                                                               
 1495 continue                                                                  
      write (noutpt,1433)                                                       
 1433 format('1',/31x,'----- summary of hypothetical solid solutions ',         
     $ '-----',/)                                                               
      write (noutpt,1380)                                                       
c                                                                               
      do 1530 nx=1,nxt                                                          
c                                                                               
      if (jxflag(nx).eq.4) go to 1530                                           
      call hpsat(axx,si,affx,lamlg,xbarlg,xbar,w,xbarh,xqkx,                    
     $ xlkm,afflcx,siss,aff,al10,fo2lg,tempk,rconst,ussnp,umin,                 
     $ nend,jsflag,jmflag,jxflag,ncomp,jsol,itracx,nsb,nsq,nsq1,                
     $ nnm1,iktmax,nx,ier,nn,iopr9,0)                                           
c                                                                               
c     bypass output below if ss has no components present                       
c                                                                               
      write(noutpt,1512)                                                        
1512  format(/,'__________________________________________________',            
     *'___________________')                                                    
c                                                                               
      if (nn.ge.1.0) go to 1396                                                 
      write(noutpt,1393) usolx(nx)                                              
1393  format(/,3x,a18,3x,'solid solution not present in the model')             
      go to 1530                                                                
c                                                                               
c     check to see if dsiplx converged ok                                       
c                                                                               
1396  if (ier.eq.0) go to 1500                                                  
      if (ier.le.3) write (noutpt,1397) usolx(nx)                               
1397  format(//,3x,a18,16x,'failed in simplx routine')                          
      if (ier.gt.3) write (noutpt,1398) usolx(nx),ier                           
1398  format(//,3x,a18,3x,'oscillatory solution - log diff = -',i1)             
c                                                                               
1500  continue                                                                  
      if (abs(afflcx(nx)).le.tolsat) then                                       
        write (noutpt,1385) usolx(nx),siss(nx),afflcx(nx)                       
        nxhsat = nxhsat+1                                                       
      else if (afflcx(nx).lt.0.) then                                           
        write (noutpt,1390) usolx(nx),siss(nx),afflcx(nx)                       
      else                                                                      
        write (noutpt,1395) usolx(nx),siss(nx),afflcx(nx)                       
        kxhsat = kxhsat+1                                                       
      end if                                                                    
c                                                                               
      do 1525 ik=1,ncomp(nx)                                                    
      nm=nend(ik,nx)                                                            
      if (nm.eq.0) then                                                         
c     component not present                                                     
        write(noutpt,1392) ussnp(ik,nx)                                         
      else                                                                      
        write(noutpt,1391) umin(nm),si(ik,nx),affx(ik,nx)                       
      end if                                                                    
 1391 format(5x,a18,2(f13.7,2x))                                                
 1392 format(5x,a18,' endmember not present or is user suppressed')             
 1525 continue                                                                  
c                                                                               
      if (jsol(nx).eq.6) go to 1530                                             
      k=jsol(nx)+1                                                              
      write (noutpt,1441) uxtype(k)                                             
1441  format(/5x,a30)                                                           
      write (noutpt,1435)                                                       
      ncpt=ncomp(nx)                                                            
c                                                                               
      icount=0                                                                  
      do 1545 ik=1,ncpt                                                         
      nm=nend(ik,nx)                                                            
      if(nm.eq.0) go to 1545                                                    
      if (jmflag(nm).ge.2) go to 1545                                           
      xlamda=texp(lamlg(ik,nx))                                                 
      actxlg=xbarlg(ik,nx)+lamlg(ik,nx)                                         
      actx=texp(actxlg)                                                         
      icount = icount+1                                                         
c                                                                               
      if (xbar(ik,nx).le.1.0e-4) then                                           
        write (noutpt,1546) umin(nm),xbar(ik,nx),xlamda,actx,                   
     $  xbarlg(ik,nx),lamlg(ik,nx),actxlg                                       
      else                                                                      
        write (noutpt,1445) umin(nm),xbar(ik,nx),xlamda,actx,                   
     $  xbarlg(ik,nx),lamlg(ik,nx),actxlg                                       
      end if                                                                    
c                                                                               
1545  continue                                                                  
      if (icount.eq.0) write(noutpt,1446)                                       
1446  format(8x,'no components present in model')                               
1530  continue                                                                  
1315  continue                                                                  
      write (noutpt,1400) nsat,nxsat,nxhsat                                     
 1400 format(//1x,i5,' approx. saturated pure minerals',/                       
     $ 1x,i5,' approx. saturated end-members of specified',                     
     $ ' solid solutions',/                                                     
     $ 1x,i5,' saturated end-members of hypothetical solid',                    
     $ ' solutions',/)                                                          
      write (noutpt,1405) ksat,kxsat,kxhsat                                     
 1405 format(/1x,i5,' supersaturated pure minerals',/                           
     $ 1x,i5,' supersatd. end-members of specified solid solutions',            
     $ /1x,i5,' supersatd. hypothetical solid solution phases',//)              
c                                                                               
c     compute and print gas fugacities                                          
c     these may have no absolute validity, but refer only to the                
c     reactions as they are currently written in the cdrg arrays.               
c                                                                               
      call gases                                                                
c                                                                               
      write (noutpt,1360)                                                       
 1360 format(//21x,'----- summary of gases -----',/)                            
      write (noutpt,1362)                                                       
 1362 format(/7x,'gas ',18x,'fugacity',4x,'log fugacity',/)                     
c                                                                               
      do 1325 ng=1,ngt                                                          
      if (jgflag(ng).ge.2) go to 1325                                           
      write (noutpt,1365) ugas(ng),fug(ng),fuglg(ng)                            
 1365 format(3x,a18,5x,e13.6,3x,f10.5)                                          
 1325 continue                                                                  
c                                                                               
      write (noutpt,1410)                                                       
 1410 format(/1x,'----- end of output -----')                                   
c                                                                               
      end                                                                       
c setup    last revised 08/01/87 by tjw                                         
      subroutine setup                                                          
c                                                                               
c     this routine converts input csp data which are not on the                 
c     molal concentration scale to that scale.                                  
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "gg.h"                                                           
      include "hh.h"                                                           
      include "jj.h"                                                           
      include "oo.h"                                                           
      include "op.h"                                                           
      include "un.h"                                                           
      include "tt.h"                                                          
      include "ww.h"                                                           
      include "xx.h"                                                           
      include "eqlpp.h"                                        
c                                                                               
c------------------------------------------------------------------             
c                                                                               
      qstop=.false.                                                             
      if (tdspkg.gt.0.) go to 5                                                 
      if (tdspl.le.0.) go to 5                                                  
      tdspkg=tdspl/rho                                                          
    5 wfs=(1000000.-tdspkg)/1000000.                                            
c                                                                               
c     convert input p e- value to eh                                            
c                                                                               
      if (iopt1.eq.-2) eh=pe*ehfac                                              
c                                                                               
      do 310 ns=2,nsq                                                           
      jfl=jflag(ns)                                                             
      if (jfl.le.0) go to 310                                                   
      if (jfl.eq.30) go to 310                                                  
      if (jfl.eq.16) go to 310                                                  
      if (jfl.eq.4) go to 310                                                   
      if (jfl.eq.10) go to 310                                                  
      if (jfl.eq.12) go to 310                                                  
      if (jfl.eq.19) go to 310                                                  
      if (jfl.eq.20) go to 310                                                  
      if (jfl.eq.21) go to 310                                                  
      if (jfl.eq.27) go to 310                                                  
      if (jfl.ne.1) go to 10                                                    
c                                                                               
c     convert total molarity to total molality                                  
c                                                                               
      csp(ns)=csp(ns)/(rho*wfs)                                                 
      jflag(ns)=0                                                               
      go to 310                                                                 
   10 if (jfl.ne.2) go to 20                                                    
c                                                                               
c     convert total mg/l to total molality                                      
c                                                                               
      csp(ns)=csp(ns)*1.e-3/(mwtss(ns)*rho*wfs)                                 
      jflag(ns)=0                                                               
      go to 310                                                                 
   20 if (jfl.ne.3) go to 30                                                    
c                                                                               
c     convert total mg/kg solution to molality                                  
c                                                                               
      csp(ns)=csp(ns)*1.e-3/(mwtss(ns)*wfs)                                     
      jflag(ns)=0                                                               
      go to 310                                                                 
   30 if (jfl.ne.5) go to 40                                                    
c                                                                               
c     convert free molarity to free molality                                    
c                                                                               
      csp(ns)=csp(ns)/(rho*wfs)                                                 
      jflag(ns)=4                                                               
      go to 310                                                                 
   40 if (jfl.ne.6) go to 50                                                    
c                                                                               
c     convert free mg/l to free molality                                        
c                                                                               
      csp(ns)=csp(ns)*1.e-3/(mwtss(ns)*rho*wfs)                                 
      jflag(ns)=4                                                               
      go to 310                                                                 
   50 if (jfl.ne.7) go to 60                                                    
c                                                                               
c     convert free mg/kg to free mg/kg                                          
c                                                                               
      csp(ns)=csp(ns)*1.e-3/(mwtss(ns)*wfs)                                     
      jflag(ns)=4                                                               
      go to 310                                                                 
   60 if (jfl.ne.8) go to 80                                                    
c                                                                               
c     convert cc stp gas/cc solution to free molality                           
c                                                                               
      csp(ns)=csp(ns)*1000./(volg*rho*wfs)                                      
      jflag(ns)=4                                                               
      go to 310                                                                 
   80 if (jfl.ne.11) go to 110                                                  
c                                                                               
c     convert titration alkalinity eq/l to eq/kg h20                            
c                                                                               
      csp(ns)=csp(ns)/(rho*wfs)                                                 
      jflag(ns)=10                                                              
      go to 310                                                                 
  110 if (jfl.ne.13) go to 200                                                  
c                                                                               
c     convert carbonate alkalinity eq/l to eq/kg h20                            
c                                                                               
      csp(ns)=csp(ns)/(rho*wfs)                                                 
      jflag(ns)=12                                                              
      go to 310                                                                 
c                                                                               
  200 write (noutpt,605) jfl,uspec(ns)                                          
  605 format(/1x,'an undefined jflag value of ',i5,' was specified',            
     $ ' for ',a18,/)                                                           
      qstop=.true.                                                              
  310 continue                                                                  
      if (.not.qstop) go to 999                                                 
      write (noutpt,320)                                                        
  320 format(1x,'----- terminating due to input errors flagged by',             
     $ ' setup -----')                                                          
      write(nttyo,322)                                                          
  322 format(' * input errors flagged by setup')                                
      stop                                                                      
c                                                                               
  999 continue                                                                  
      end                                                                       
c sxterm   last revised 05/20/87 by rlh                                         
      subroutine sxterm(nx)                                                     
c                                                                               
c     24jul86 by tjw                                                            
c                                                                               
c     this routine computes the sx(ik,jk) array which is used                   
c     in treating changing activity coefficients of solid-solution              
c     component end members.                                                    
c                                                                               
c     sx(ik,jk) is the formal partial derivative of lamlg(ik,nx)                
c     with respect to xbar(jk,nx).  sx(ik,jk)=0 when ik=jk                      
c     because we have chosen to formally write the logarithm of the             
c     activity coefficient of an end-member as a function solely of the         
c     mole fractions of the other end-members.                                  
c                                                                               
      include "implicit.h"                                                     
c                                                                               
      include "parset.h"                                                       
c                                                                               
      include "an.h"                                                           
      include "hh.h"                                                           
      include "tt.h"                                                           
      include "vv.h"                                                           
      include "eqlpp.h"                                        
c                                                                               
c------------------------------------------------------------------             
c                                                                               
      k=jsol(nx)                                                                
      ncpt=ncomp(nx)                                                            
      do 3 ik=1,ncpt                                                            
      do 2 jk=1,ncpt                                                            
      sx(ik,jk)=0.                                                              
    2 continue                                                                  
    3 continue                                                                  
c                                                                               
      if (k.ne.0) go to 15                                                      
c                                                                               
c     ideal solution                                                            
c                                                                               
      go to 150                                                                 
c                                                                               
   15 if (k.ne.1) go to 25                                                      
c                                                                               
c     binary solution, third-order maclaurin expansion                          
c     original pathi solid solution model                                       
c                                                                               
      zx=xbar(2,nx)                                                             
      sx(1,2)=zx*zx*(-w(2,nx)-w(3,nx)*zx)                                       
      zx=xbar(1,nx)                                                             
      sx(2,1)=zx*zx*(-w(2,nx)-w(3,nx)+w(3,nx)*zx)                               
      go to 150                                                                 
c                                                                               
   25 if (k.ne.2) go to 35                                                      
c                                                                               
c     binary solution, parabolic maclaurin expansion                            
c                                                                               
      zx=xbar(2,nx)                                                             
      sx(1,2)=2.*w(1,nx)*zx*zx                                                  
      zx=xbar(1,nx)                                                             
      sx(2,1)=2.*w(1,nx)*zx*zx                                                  
      go to 150                                                                 
c                                                                               
   35 if (k.ne.3) go to 45                                                      
c                                                                               
c     binary solution, cubic maclaurin (p,t dependent)                          
c                                                                               
      zx=xbar(2,nx)                                                             
      sx(1,2)=zx*zx*(4.*w(2,nx)-2.*w(1,nx)+6.*(w(1,nx)-w(2,nx))*zx)             
      zx=xbar(1,nx)                                                             
      sx(2,1)=zx*zx*(4.*w(1,nx)-2.*w(2,nx)+6.*(w(2,nx)-w(1,nx))*zx)             
      go to 150                                                                 
c                                                                               
   45 if (k.ne.4) go to 55                                                      
c                                                                               
c     binary solution, guggenheim polynomial (t dependent)                      
c                                                                               
      zx=xbar(2,nx)                                                             
      a=2.*w(1,nx)+6.*w(2,nx)+10.*w(3,nx)                                       
      b=-12.*w(2,nx)-48.*w(3,nx)                                                
      c=48.*w(3,nx)                                                             
      sx(1,2)=zx*zx*(a+b*zx+c*zx*zx)                                            
      zx=xbar(1,nx)                                                             
      a=2.*w(1,nx)-6.*w(2,nx)+10.*w(3,nx)                                       
      b=12.*w(2,nx)-48.*w(3,nx)                                                 
      sx(2,1)=zx*zx*(a+b*zx+c*zx*zx)                                            
      go to 150                                                                 
c                                                                               
   55 if (k.ne.5) go to 150                                                     
c                                                                               
c     ternary regular solution (prigogine and defay, p. 257)                    
c                                                                               
      a12=w(1,nx)                                                               
      a13=w(2,nx)                                                               
      a23=w(3,nx)                                                               
      zx1=xbar(1,nx)                                                            
      zx2=xbar(2,nx)                                                            
      zx3=xbar(3,nx)                                                            
      term=(a12-a23+a13)*zx3*zx2                                                
      sx(1,2)=2.*a12*zx2*zx2+term                                               
      sx(1,3)=2.*a13*zx3*zx3+term                                               
      term=(a12-a13+a23)*zx3*zx1                                                
      sx(2,1)=2.*a12*zx1*zx1+term                                               
      sx(2,3)=2.*a23*zx3*zx3+term                                               
      term=(a13-a12+a23)*zx1*zx2                                                
      sx(3,1)=2.*a13*zx1*zx1+term                                               
      sx(3,2)=2.*a23*zx2*zx2+term                                               
      go to 150                                                                 
c                                                                               
  150 continue                                                                  
      fac=1./(rconst*tempk)                                                     
      do 160 ik=1,ncpt                                                          
      do 155 jk=1,ncpt                                                          
      sx(ik,jk)=fac*sx(ik,jk)                                                   
  155 continue                                                                  
  160 continue                                                                  
  200 continue                                                                  
c                                                                               
      end                                                                       
	BLOCK DATA data
      parameter(nxtpar=20,ngtpar=15,nctpar=70,nmtpar=750,nstpar=750)
      parameter(nctpa1=nctpar+1)
      include "implicit.h"                                                     
c  
      include "gg.h"
      include "un.h"
      include "eqlver.h"
c                                                                               
      DATA NOUTPT/18/, NAD1/17/, NINPT/19/, NPKUP/21/
      data nttyo /0/                                                            
      data ucode /'eq3nr   '/, urelno /'3245    '/, ustage /'R110    '/         

      data ujtype(1)  /'tot conc, molal         '/                              
      data ujtype(2)  /'tot conc, molar         '/                              
      data ujtype(3)  /'tot conc, mg/l          '/                              
      data ujtype(4)  /'tot conc, mg/kg         '/                              
      data ujtype(5)  /'free conc, molal        '/                              
      data ujtype(6)  /'free conc, molar        '/                              
      data ujtype(7)  /'free conc, mg/l         '/                              
      data ujtype(8)  /'free conc, mg/kg        '/                              
      data ujtype(9)  /'free conc, cc/cc        '/                              
      data ujtype(10) /' jflag error            '/                              
      data ujtype(11) /'tit alk, eq/kg h2o      '/                              
      data ujtype(12) /'tit alk, eq/l           '/                              
      data ujtype(13) /'co3 alk, eq/kg h2o      '/                              
      data ujtype(14) /'co3 alk, eq/l           '/                              
      data ujtype(15) /' jflag error            '/                              
      data ujtype(16) /' jflag error            '/                              
      data ujtype(17) /'log activity            '/                              
      data ujtype(18) /' jflag error            '/                              
      data ujtype(19) /' jflag error            '/                              
      data ujtype(20) /'mineral equilibrium     '/                              
      data ujtype(21) /'solid solution equil    '/                              
      data ujtype(22) /'gas equilibrium         '/                              
      data ujtype(23) /' jflag error            '/                              
      data ujtype(24) /' jflag error            '/                              
      data ujtype(25) /' jflag error            '/                              
      data ujtype(26) /' jflag error            '/                              
      data ujtype(27) /' jflag error            '/                              
      data ujtype(28) /'dependent species       '/                              
      data ujtype(29) /' jflag error            '/                              
      data ujtype(30) /' jflag error            '/                              
      data ujtype(31) /'eliminated species      '/                              
c                                                                               
      data uxtype(1)  /'ideal solution                  '/                      
      data uxtype(2)  /'binary, third-order maclaurin   '/                      
      data uxtype(3)  /'binary, parabolic maclaurin     '/                      
      data uxtype(4)  /'binary, cubic maclaurin (p,t)   '/                      
      data uxtype(5)  /'binary, guggenheim  (t)         '/                      
      data uxtype(6)  /'ternary, regular                '/                      
c                                                                               
	END
	
