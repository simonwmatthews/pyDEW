c--------------------------------------------------------------------           
c eqleps.h                                                                      
c                                                                               
c       eps = the real*8 machine epsilon                                        
c       eps10 = 10*eps                                                          
c       eps100 = 100*eps                                                        
c       smpos = smallest positive real*8 number                                 
c       smp10 = 10*smpos                                                        
c       smp100 = 100*smpos                                                      
c       irang = int ( -log (smpos ) )                                           
c                                                                               
      common /eqleps/ eps,smpos,eps10,eps100,smp10,smp100,irang                 
