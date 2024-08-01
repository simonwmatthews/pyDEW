c--------------------------------------------------------------------           
c eqlhkf.h                                                                      
c      ibjmax= maximum number of single interaction parameters allowed          
c      ibjuse= actual number of entries for single parameters                   
c      icnt = number of salts created                                           
c      indx1 = index to species for single interaction parameters               
c      bj    = individual ion interaction parameter                             
c      omega = omega variable                                                   
c      mslt  = molality of salts                                                
c      hkfaz = azero used in hkf eqns = 1/n * sum over j of azero sub j         
c                                                                               
c      ibjimx= maximum number of ion-ion interaction parameters allowed         
c      ibjius= actual number of entries for ion-ion parameters                  
c      indx2 = indexes to both species in ion-ion interaction parameter         
c      bij   = ion-ion interaction parameter                                    
c      islt  = indices and stoich. rxn. coeff for salts                         
c                                                                               
      common /eqlhkf/ hkfaz,omega(ibjpar),bji(ibjpar),mslt(islpar),             
     $ ibjmax,ibjuse,ibjius,icnt,indx1(ibjpar),                                 
     $ indx2(2,ibjpar),islt(4,islpar)                                           
