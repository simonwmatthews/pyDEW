c--------------------------------------------------------------------           
c eqlpsa.h                                                                      
c      nslm  = number of entries in use                                         
c      nslmt = maximum number allowed                                           
c      nslmx = species index pairs                                              
c      pslm =  lambda triples from file data1p                                  
c      nalpha = indices into palpha array                                       
c                                                                               
      common /eqlpsa/ pslm(3,nslpar),nslm,nslmt,nslmx(2,nslpar),                
     $                nalpha(nslpar)                                            
