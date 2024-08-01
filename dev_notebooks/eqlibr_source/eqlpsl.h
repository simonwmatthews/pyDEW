c-------------------------------------------------------------------            
c eqlpsl.h                                                                      
c     derived index arrays, s-lambda data                                       
c                                                                               
c     nsxt   max number of entries in array nsxx                                
c                                                                               
c     nslx   actual number of entries in use                                    
c                                                                               
c     nsxi  array of pairs, indexed by species index                            
c      1) index in array nsxx to first occurrence, this species                 
c      2)  index of last occurrence in nsxx                                     
c             (may = first index-1 if no entries)                               
c                                                                               
c     nsxx  array of pairs, in sets corresponding to species index              
c      1) second species index from nslmx                                       
c      2) index into pslam, nslmx, ...                                          
c                                                                               
      common /eqlpsl/ nsxt,nslx,nsxi(2,nstpar),nsxx(2,nsxpar)                   
