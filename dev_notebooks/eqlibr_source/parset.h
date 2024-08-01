c--------------------------------------------------------------------           
c parset.h  last modified 12/01/87 by tjw                                       
c                                                                               
c     nctpar = nctmax = no. of elements                                         
c     nsqpar = nsqmax = maximum no. of expanded basis species                   
c     nstpar = nstmax = maximum no. of aqueous species                          
c     nrstpa = nrstmx = maximum no. of aqueous reactions                        
c     nmtpar = nmtmax = maximum number of pure minerals                         
c     ngtpar = ngtmax = maximum no. of gases                                    
c     nxtpar = nxtmax = maximum no. of solid-solutions                          
c     iktpar = iktmax = maximum no. of solid-solution end-members               
c     iapxpa = iapxmx = leading dimension of the apx array,                     
c                       solid solution non-ideality parameters                  
c     kpar   = kmax   = maximum dimension of the jacobian matrix                
c     narxpa = narxmx = maximum number of coefficients in a fitting             
c                       polynomial describing the temperature dependence        
c                       of a thermodynamic property                             
c     ntprpa = ntprmx = maximum number of temperature ranges for                
c                       polynomial coefficients describing a                    
c                       thermodynamic property                                  
c                                                                               
      parameter(nctpar=70,nsqpar=100,nstpar=750,ngtpar=15,                      
     $ nxtpar=20,iktpar=20,iapxpa=12,nmtpar=750,nxmdpa=20,                      
     $ ntitpa=30,narxpa=5,ntprpa=2)                                             
c                                                                               
      parameter(nrstpa=nstpar-nctpar-1,                                         
     $          kpar=nsqpar,nsqpa1=nsqpar+1,                                    
     $          nctpa1=nctpar+1,nctpa5=nctpar+5)                                
