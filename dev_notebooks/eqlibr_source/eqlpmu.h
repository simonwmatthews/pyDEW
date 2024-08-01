c-------------------------------------------------------------------            
c eqlpmu.h                                                                      
c                                                                               
c      nmu = actual number of entries in use                                    
c      nmut = maximum number of entries allowed                                 
c      nmux = triples of aqueous species indices                                
c      pmu = mu(ijk) values array                                               
c                                                                               
      common /eqlpmu/ pmu(nmupar),nmu,nmut,nmux(3,nmupar)                       
