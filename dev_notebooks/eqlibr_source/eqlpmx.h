c--------------------------------------------------------------------           
c eqlpmx.h                                                                      
c      base values (25c)                                                        
c                                                                               
c      bmu   mu values                                                          
c      dmu   derivatives wrt temp                                               
c                                                                               
c                                                                               
c     derived index arrays, mu data                                             
c                                                                               
c     nmxt   max number of entries in array nmxx                                
c                                                                               
c     nmlx   actual number of entries in use                                    
c                                                                               
c     nmxi  array of pairs, indexed by species index                            
c      1) index in array nmxx to first occurrence, this species                 
c      2) index of last ocurrence in nmxx                                       
c           ( may = first index-1 if no entries)                                
c                                                                               
c      nmxx  array of triples                                                   
c       1) second species index from nmux                                       
c       2) third species index from nmux                                        
c       3) index into pmu, nmux,...                                             
c                                                                               
      common /eqlpmx/ nmxt,nmlx,nmxi(2,nstpar),nmxx(3,nmxpar)                   
