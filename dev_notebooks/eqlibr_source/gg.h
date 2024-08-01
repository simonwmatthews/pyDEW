c--------------------------------------------------------------------           
c gg.h                                                                          
      character*32 uxtype                                                       
      character*24 ujtype,uspec,umin,ugas,usolx                                 
      common /gg/ uxtype(10),ujtype(31),uspec(nstpar),umin(nmtpar),             
     $ ugas(ngtpar),usolx(nxtpar),uelem(nctpa1)                                 
