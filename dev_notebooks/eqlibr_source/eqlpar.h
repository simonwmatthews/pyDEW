c--------------------------------------------------------------------           
c eqlpar.h  last revised 11/25/87 by tjw                                        
c                                                                               
c     warning- do not duplicate any parameters here that belong to              
c              eq3nr, eq6, mcrt, or any other code that uses the               
c              eqlib library.  as necessary, make up work arrays                
c              in the calling programs and pass them to eqlib                   
c              routines.                                                        
c                                                                               
c     one exception, not yet eliminated                                         
c                                                                               
        parameter(nstpar=750)                                                     
c                                                                               
c-------------------------------------------------------------------            
c                                                                               
c     parameters for polynomial fitting (used in polx and lsqp)                 
c                                                                               
c       ipfpar = maximum number of points                                       
c       ipfpa1 = ipfpar+1                                                       
c       ipfdpa = 2*ipfpa1                                                       
c                                                                               
      parameter(ipfpar=10,ipfpa1=ipfpar+1,ipfdpa=2*ipfpa1)                      
c                                                                        
c                                                                               
c  parameters for pitzer and hkf subroutines                                    
c      nmupar   = nmut       dimension of mu array                              
c      nslpar   = nslmt      dimension of lambda array                          
c      nappar   = napt       dimension of palpha array                          
c      ibjpar   = ibjmax     max. no of hkf pairs                               
c      nsxpar   = nsxt       max. no of arrays of triples - pitzer              
c      nmxpar   = nmxt       max. no of arrays of pairs- pitzer                 
c      islpar   = islmax     max. no. of hypothetical salts - hkf               
c                            (arrays mslt and islt)                             
c                                                                               
      parameter(nmupar=500,nslpar=500,nappar=5,ibjpar=500,                      
     $          nsxpar=500,nmxpar=1000,islpar=50)                         
