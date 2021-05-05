//
//  DEWDielectricConstant.m
//  ThermoFit
//
//  Created by Mark Ghiorso on 10/29/15.
//  Copyright © 2015 Mark Ghiorso. All rights reserved.
//

#import "DEWDielectricConstant.h"
#import "GenericH2O.h"

#define VERY_SMALL 0.01 // K or bars
#define R   8.3144598
#define MW 18.01528

@implementation DEWDielectricConstant

#pragma mark -
#pragma mark Initialize Sverjensky constants and Fluid properties

- (instancetype)init {
    self = [super init];
    if (self) {
        _tLast         = -1.0;
        _pLast         = -1.0;
        _rhoLast       = -1.0;
        _DrhoDtLast    = -1.0;
        _DrhoDpLast    = -1.0;
        _D2rhoDt2Last  = -1.0;
        _D2rhoDtDpLast = -1.0;
        _D2rhoDp2Last  = -1.0;
        
        // This is the generalized (+CO2) of Zhang & Duian (2005)
        _genericH2O = [[GenericH2O alloc] init];
        
        // These constants are from Sverjensky et at. (2014), GCA, 129, 125-145
        a1 = -1.57637700752506e-3;
        a2 =  6.81028783422197e-2;
        a3 =  7.54875480393944e-1;
        
        b1 = -8.01665106535394e-5;
        b2 = -6.87161761831994e-2;
        b3 =  4.74797272182151e0;
        
        // "a" coefficient on a Kelvin basis
        aTK1 = -5.8274486041453000E-02;
        aTK2 =  2.2389805995733700E+00;
        aTK3 = -2.0249736922093000E+01;
        
        // "b" coefficient on a Kelvin basis
        bTK1 =  5.7128535105795700E-02;
        bTK2 = -2.2591436511452200E+00;
        bTK3 =  2.6398103834434400E+01;
    }
    return self;
}

#pragma mark -
#pragma mark Private functions to update fluid properties

- (void)loadDensityPropertiesWithT:(double)t andWithP:(double)p {
    self.tLast = t;
    self.pLast = p;
    double v       = 10.0*[self.genericH2O getVolumeFromT:t andP:p];
    double dvdt    = 10.0*[self.genericH2O getDvDtFromT:t andP:p];
    double dvdp    = 10.0*[self.genericH2O getDvDpFromT:t andP:p];
    double d2vdt2  = 10.0*[self.genericH2O getD2vDt2FromT:t andP:p];
    double d2vdtdp = 10.0*[self.genericH2O getD2vDtDpFromT:t andP:p];
    double d2vdp2  = 10.0*[self.genericH2O getD2vDp2FromT:t andP:p];
    
    self.rhoLast       = MW/v;
    self.DrhoDtLast    = -MW*dvdt/v/v;
    self.DrhoDpLast    = -MW*dvdp/v/v;
    self.D2rhoDt2Last  = MW*(2.0*dvdt*dvdt/v/v/v - d2vdt2/v/v);
    self.D2rhoDtDpLast = MW*(2.0*dvdt*dvdp/v/v/v - d2vdtdp/v/v);
    self.D2rhoDp2Last  = MW*(2.0*dvdp*dvdp/v/v/v - d2vdp2/v/v);
}

#pragma mark -
#pragma mark Dielectric constants and t, p derivatives

- (double)epsilonFromT:(double)t andP:(double)p {
    if (!(fabs(t-self.tLast) < VERY_SMALL) || !(fabs(p-self.pLast) < VERY_SMALL)) [self loadDensityPropertiesWithT:t andWithP:p];
    double tc = t - 273.15;
    double rho = self.rhoLast;
    double rhoExponent = 0.0, expExponent = 0.0;
    if (tc > 0.0) {
        rhoExponent = a1*tc + a2*sqrt(tc) + a3;
        expExponent = b1*tc + b2*sqrt(tc) + b3;

    } else {
        rhoExponent = aTK1*t + aTK2*sqrt(t) + aTK3;
        expExponent = bTK1*t + bTK2*sqrt(t) + bTK3;
    }
    double epsilon = exp(expExponent)*pow(rho, rhoExponent);
    return epsilon;
}

- (double)dEpsilonDtFromT:(double)t andP:(double)p {
    if (!(fabs(t-self.tLast) < VERY_SMALL) || !(fabs(p-self.pLast) < VERY_SMALL)) [self loadDensityPropertiesWithT:t andWithP:p];
    double tc = t - 273.15;
    if (tc < 0.0) return 0.0;
    double  rho   = self.rhoLast;
    double DrhoDt = self.DrhoDtLast;
    double  rhoExponent   = a1*tc + a2*sqrt(tc) + a3;
    double DrhoExponentDt = a1 + a2/2.0/sqrt(tc);
    double  expExponent = b1*tc + b2*sqrt(tc) + b3;
    double DexpExponentDt = b1 + b2/2.0/sqrt(tc);
    
    // d f(t,p)^g(t) / dt = g(t) * f(t,p)^[g(t)-1] * f'(t*,p) + f(t,p)^g(t) * ln[f(t,p)] * g'(t)
    double DepsilonDt = DexpExponentDt*exp(expExponent)*pow(rho, rhoExponent)
                      + exp(expExponent)*(  rhoExponent*pow(rho, rhoExponent-1.0)*DrhoDt
                                          + pow(rho, rhoExponent)*log(rho)*DrhoExponentDt
                                         );
    return DepsilonDt;
}

- (double)dEpsilonDpFromT:(double)t andP:(double)p {
    if (!(fabs(t-self.tLast) < VERY_SMALL) || !(fabs(p-self.pLast) < VERY_SMALL)) [self loadDensityPropertiesWithT:t andWithP:p];
    double tc = t - 273.15;
    if (tc < 0.0) return 0.0;
    double  rho   = self.rhoLast;
    double DrhoDp = self.DrhoDpLast;
    double  rhoExponent = a1*tc + a2*sqrt(tc) + a3;
    double  expExponent = b1*tc + b2*sqrt(tc) + b3;

    // d f(t,p)^g(t) / dp = g(t) * f(t,p)^[g(t)-1] * f'(t,p*)
    double DepsilonDp = exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*DrhoDp;
    return DepsilonDp;
}

- (double)d2EpsilonDt2FromT:(double)t andP:(double)p {
    if (!(fabs(t-self.tLast) < VERY_SMALL) || !(fabs(p-self.pLast) < VERY_SMALL)) [self loadDensityPropertiesWithT:t andWithP:p];
    double tc = t - 273.15;
    if (tc < 0.0) return 0.0;
    double   rho    = self.rhoLast;
    double  DrhoDt  = self.DrhoDtLast;
    double D2rhoDt2 = self.D2rhoDt2Last;
    double  rhoExponent     = a1*tc + a2*sqrt(tc) + a3;
    double  DrhoExponentDt  = a1 + a2/2.0/sqrt(tc);
    double D2rhoExponentDt2 = - a2/2.0/2.0/pow(tc, 3.0/2.0);
    double   expExponent    = b1*tc + b2*sqrt(tc) + b3;
    double  DexpExponentDt  = b1 + b2/2.0/sqrt(tc);
    double D2expExponentDt2 = - b2/2.0/2.0/pow(tc, 3.0/2.0);
    
    double DpowOfRowToTheRhoExponent   =       rhoExponent*pow(rho, rhoExponent-1.0)*DrhoDt + pow(rho, rhoExponent)    *log(rho)*DrhoExponentDt;
    double DpowOfRowToTheRhoExponentM1 = (rhoExponent-1.0)*pow(rho, rhoExponent-2.0)*DrhoDt + pow(rho, rhoExponent-1.0)*log(rho)*DrhoExponentDt;
    
    double DepsilonDt = D2expExponentDt2*exp(expExponent)*pow(rho, rhoExponent)
                      + DexpExponentDt*DexpExponentDt*exp(expExponent)*pow(rho, rhoExponent)
                      + DexpExponentDt*exp(expExponent)*DpowOfRowToTheRhoExponent
                      + DexpExponentDt*exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*DrhoDt
                      + exp(expExponent)*DrhoExponentDt*pow(rho, rhoExponent-1.0)*DrhoDt
                      + exp(expExponent)*rhoExponent*DpowOfRowToTheRhoExponentM1*DrhoDt
                      + exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*D2rhoDt2
                      + DexpExponentDt*exp(expExponent)*pow(rho, rhoExponent)*log(rho)*DrhoExponentDt
                      + exp(expExponent)*DpowOfRowToTheRhoExponent*log(rho)*DrhoExponentDt
                      + exp(expExponent)*pow(rho, rhoExponent)*(DrhoDt/rho)*DrhoExponentDt
                      + exp(expExponent)*pow(rho, rhoExponent)*log(rho)*D2rhoExponentDt2;
    return DepsilonDt;
}

- (double)d2EpsilonDtDpFromT:(double)t andP:(double)p {
    if (!(fabs(t-self.tLast) < VERY_SMALL) || !(fabs(p-self.pLast) < VERY_SMALL)) [self loadDensityPropertiesWithT:t andWithP:p];
    double tc = t - 273.15;
    if (tc < 0.0) return 0.0;
    double   rho     = self.rhoLast;
    double  DrhoDp   = self.DrhoDpLast;
    double  DrhoDt   = self.DrhoDtLast;
    double D2rhoDtDp = self.D2rhoDtDpLast;
    double  rhoExponent   = a1*tc + a2*sqrt(tc) + a3;
    double DrhoExponentDt = a1 + a2/2.0/sqrt(tc);
    double  expExponent = b1*tc + b2*sqrt(tc) + b3;
    double DexpExponentDt = b1 + b2/2.0/sqrt(tc);
    
    // d2 f(t,p)^g(t) / dtdp = g(t) * [g(t)-1] * f(t,p)^[g(t)-2] * f'(t*,p) * f'(t,p*)
    //                       + g(t) * f(t,p)^[g(t)-1] * f''(t*,p*)
    //                       + g(t) * f(t,p)^[g(t)-1] * ln[f(t,p)] * g'(t) * f'(t,p*)
    //                       + f(t,p)^[g(t)-1] * f'(t,p*) * g'(t)
    double D2epsilonDtDp = DexpExponentDt*exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*DrhoDp
                         + exp(expExponent)*rhoExponent*(rhoExponent-1.0)*pow(rho, rhoExponent-2.0)*DrhoDt*DrhoDp
                         + exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*D2rhoDtDp
                         + exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*log(rho)*DrhoExponentDt*DrhoDp
                         + exp(expExponent)*pow(rho, rhoExponent-1.0)*DrhoExponentDt*DrhoDp;
    
    return D2epsilonDtDp;
}

- (double)d2EpsilonDp2FromT:(double)t andP:(double)p {
    if (!(fabs(t-self.tLast) < VERY_SMALL) || !(fabs(p-self.pLast) < VERY_SMALL)) [self loadDensityPropertiesWithT:t andWithP:p];
    double tc = t - 273.15;
    if (tc < 0.0) return 0.0;
    double   rho    = self.rhoLast;
    double  DrhoDp  = self.DrhoDpLast;
    double D2rhoDp2 = self.D2rhoDp2Last;
    double  rhoExponent = a1*tc + a2*sqrt(tc) + a3;
    double  expExponent = b1*tc + b2*sqrt(tc) + b3;
    
    // d2 f(t,p)^g(t) / dp2 = g(t) * [g(t)-1] * f(t,p)^[g(t)-2] * f'(t,p*) * f'(t,p*) + g(t) * f(t,p)^[g(t)-1] * f''(t,p**)
    double D2epsilonDp2 = exp(expExponent)*rhoExponent*(rhoExponent-1.0)*pow(rho, rhoExponent-2.0)*DrhoDp*DrhoDp
                        + exp(expExponent)*rhoExponent*pow(rho, rhoExponent-1.0)*D2rhoDp2;
    return D2epsilonDp2;
}

#pragma mark -
#pragma mark Born functions and their dervatives

- (double)QfromT:(double)t andP:(double)p {
    double epsilon = [self epsilonFromT:t andP:p];
    double DepsilonDp = [self dEpsilonDpFromT:t andP:p];
    return DepsilonDp/epsilon/epsilon;
}

- (double)NfromT:(double)t andP:(double)p {
    double epsilon = [self epsilonFromT:t andP:p];
    double DepsilonDp = [self dEpsilonDpFromT:t andP:p];
    double D2epsilonDp2 = [self d2EpsilonDp2FromT:t andP:p];
    return - 2.0*DepsilonDp*DepsilonDp/epsilon/epsilon/epsilon  + D2epsilonDp2/epsilon/epsilon;
}

- (double)UfromT:(double)t andP:(double)p {
    double epsilon = [self epsilonFromT:t andP:p];
    double DepsilonDt = [self dEpsilonDtFromT:t andP:p];
    double DepsilonDp = [self dEpsilonDpFromT:t andP:p];
    double D2epsilonDtDp = [self d2EpsilonDtDpFromT:t andP:p];
    return D2epsilonDtDp/epsilon/epsilon - 2.0*DepsilonDp*DepsilonDt/epsilon/epsilon/epsilon;
}

- (double)YfromT:(double)t andP:(double)p {
    double epsilon = [self epsilonFromT:t andP:p];
    double DepsilonDt = [self dEpsilonDtFromT:t andP:p];
    return DepsilonDt/epsilon/epsilon;
}

- (double)XfromT:(double)t andP:(double)p {
    double epsilon = [self epsilonFromT:t andP:p];
    double DepsilonDt = [self dEpsilonDtFromT:t andP:p];
    double D2epsilonDt2 = [self d2EpsilonDt2FromT:t andP:p];
    
    double  dlnEpsilonDt  = DepsilonDt/epsilon;
    double d2lnEpsilonDt2 = -DepsilonDt*DepsilonDt/epsilon/epsilon + D2epsilonDt2/epsilon;
    
    return (d2lnEpsilonDt2 - dlnEpsilonDt*dlnEpsilonDt)/epsilon;
}

#define EPS 1.0e-6

#pragma mark -
#pragma mark Born functions - Numerical derivatives of higher order functions

- (double)dUdTfromT:(double)t andP:(double)p {
    [self loadDensityPropertiesWithT:t*(1.0+EPS) andWithP:p]; // must be forced to recompute rho and derivatives
    double Uplus = [self UfromT:t*(1.0+EPS) andP:p];
    [self loadDensityPropertiesWithT:t*(1.0-EPS) andWithP:p]; // must be forced to recompute rho and derivatives
    double Uminus = [self UfromT:t*(1.0-EPS) andP:p];
    return (Uplus-Uminus)/2.0/(t*EPS);
}

- (double)dUdPfromT:(double)t andP:(double)p {
    [self loadDensityPropertiesWithT:t andWithP:p*(1.0+EPS)]; // must be forced to recompute rho and derivatives
    double Uplus = [self UfromT:t andP:p*(1.0+EPS)];
    [self loadDensityPropertiesWithT:t andWithP:p*(1.0-EPS)]; // must be forced to recompute rho and derivatives
    double Uminus = [self UfromT:t andP:p*(1.0-EPS)];
    return (Uplus-Uminus)/2.0/(p*EPS);
}

- (double)dNdTfromT:(double)t andP:(double)p {
    return [self dUdPfromT:t andP:p];
}

- (double)dNdPfromT:(double)t andP:(double)p {
    [self loadDensityPropertiesWithT:t andWithP:p*(1.0+EPS)]; // must be forced to recompute rho and derivatives
    double Nplus = [self NfromT:t andP:p*(1.0+EPS)];
    [self loadDensityPropertiesWithT:t andWithP:p*(1.0-EPS)]; // must be forced to recompute rho and derivatives
    double Nminus = [self NfromT:t andP:p*(1.0-EPS)];
    return (Nplus-Nminus)/2.0/(p*EPS);
}

- (double)dXdTfromT:(double)t andP:(double)p {
    [self loadDensityPropertiesWithT:t*(1.0+EPS) andWithP:p]; // must be forced to recompute rho and derivatives
    double Xplus = [self XfromT:t*(1.0+EPS) andP:p];
    [self loadDensityPropertiesWithT:t*(1.0-EPS) andWithP:p]; // must be forced to recompute rho and derivatives
    double Xminus = [self XfromT:t*(1.0-EPS) andP:p];
    return (Xplus-Xminus)/2.0/(t*EPS);
}

#pragma mark -
#pragma mark Private helper functions and their dervatives

// private
- (double)dAgammaDtFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDt = [self dEpsilonDtFromT:t andP:p];
    double dRhoDt = self.DrhoDtLast;
    return 1.824829238e6*dRhoDt/2.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
    - 3.0*1.824829238e6*sqrt(rho)*(dEpsilonDt*t + epsilon)/2.0/pow(epsilon*t, 5.0/2.0);
}

// private
- (double)dAgammaDpFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDp = [self dEpsilonDpFromT:t andP:p];
    double dRhoDp = self.DrhoDpLast;
    return 1.824829238e6*dRhoDp/2.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0) - 3.0*1.824829238e6*sqrt(rho)*dEpsilonDp*t/2.0/pow(epsilon*t, 5.0/2.0);
}

// private
- (double)d2AgammaDt2FromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDt = [self dEpsilonDtFromT:t andP:p];
    double dRhoDt = self.DrhoDtLast;
    double d2EpsilonDt2 = [self d2EpsilonDt2FromT:t andP:p];
    double d2RhoDt2 = self.D2rhoDt2Last;
    double result = 1.824829238e6*d2RhoDt2/2.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
    - 1.824829238e6*dRhoDt*dRhoDt/4.0/pow(rho, 3.0/2.0)/pow(epsilon*t, 3.0/2.0)
    - 3.0*1.824829238e6*dRhoDt*(dEpsilonDt*t+epsilon)/4.0/sqrt(rho)/pow(epsilon*t, 5.0/2.0)
    - 3.0*1.824829238e6*dRhoDt*(dEpsilonDt*t+epsilon)/4.0/sqrt(rho)/pow(epsilon*t, 5.0/2.0)
    - 3.0*1.824829238e6*sqrt(rho)*(d2EpsilonDt2*t+2.0*dEpsilonDt)/2.0/pow(epsilon*t, 5.0/2.0)
    + 15.0*1.824829238e6*sqrt(rho)*(dEpsilonDt*t+epsilon)*(dEpsilonDt*t+epsilon)/4.0/pow(epsilon*t, 7.0/2.0);
    return result;
}

// private
- (double)d2AgammaDtDpFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDt = [self dEpsilonDtFromT:t andP:p];
    double dRhoDt = self.DrhoDtLast;
    double dEpsilonDp = [self dEpsilonDpFromT:t andP:p];
    double dRhoDp = self.DrhoDpLast;
    double d2EpsilonDtDp = [self d2EpsilonDtDpFromT:t andP:p];
    double d2RhoDtDp = self.D2rhoDtDpLast;
    
    double result = 1.824829238e6*d2RhoDtDp/2.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
                  - 1.824829238e6*dRhoDt*dRhoDp/4.0/pow(rho, 3.0/2.0)/pow(epsilon*t, 3.0/2.0)
                  - 3.0*1.824829238e6*dRhoDt*dEpsilonDp*t/4.0/sqrt(rho)/pow(epsilon*t, 5.0/2.0)
                  - 3.0*1.824829238e6*dRhoDp*(dEpsilonDt*t + epsilon)/sqrt(rho)/4.0/pow(epsilon*t, 5.0/2.0)
                  - 3.0*1.824829238e6*sqrt(rho)*(d2EpsilonDtDp*t + dEpsilonDp)/2.0/pow(epsilon*t, 5.0/2.0)
                  + 5.0*3.0*1.824829238e6*sqrt(rho)*(dEpsilonDt*t + epsilon)*dEpsilonDp*t/4.0/pow(epsilon*t, 7.0/2.0);
    return result;
}

// private
- (double)d2AgammaDp2FromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDp = [self dEpsilonDpFromT:t andP:p];
    double dRhoDp = self.DrhoDpLast;
    double d2EpsilonDp2 = [self d2EpsilonDp2FromT:t andP:p];
    double d2RhoDp2 = self.D2rhoDp2Last;
    double result = 1.824829238e6*d2RhoDp2/2.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
                  - 1.824829238e6*dRhoDp*dRhoDp/4.0/pow(rho, 3.0/2.0)/pow(epsilon*t, 3.0/2.0)
                  - 3.0*1.824829238e6*dRhoDp*dEpsilonDp*t/4.0/sqrt(rho)/pow(epsilon*t, 5.0/2.0)
                  - 3.0*1.824829238e6*dRhoDp*dEpsilonDp*t/4.0/sqrt(rho)/pow(epsilon*t, 5.0/2.0)
                  - 3.0*1.824829238e6*sqrt(rho)*d2EpsilonDp2*t/2.0/pow(epsilon*t, 5.0/2.0)
                  + 5.0*3.0*1.824829238e6*sqrt(rho)*dEpsilonDp*t*dEpsilonDp*t/4.0/pow(epsilon*t, 7.0/2.0);
    return result;
}


// private
- (double)dBgammaDtFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDt = [self dEpsilonDtFromT:t andP:p];
    double dRhoDt = self.DrhoDtLast;
    return 50.29158649e8*dRhoDt/2.0/sqrt(rho)/sqrt(epsilon*t) - 50.29158649e8*(dEpsilonDt*t+epsilon)*sqrt(rho)/2.0/pow(epsilon*t, 3.0/2.0);
}

// private
- (double)dBgammaDpFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDp = [self dEpsilonDpFromT:t andP:p];
    double dRhoDp = self.DrhoDpLast;
    return 50.29158649e8*dRhoDp/2.0/sqrt(rho)/sqrt(epsilon*t) - 50.29158649e8*sqrt(rho)*dEpsilonDp*t/2.0/pow(epsilon*t, 3.0/2.0);
}

// private
- (double)d2BgammaDt2FromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDt = [self dEpsilonDtFromT:t andP:p];
    double dRhoDt = self.DrhoDtLast;
    double d2EpsilonDt2 = [self d2EpsilonDt2FromT:t andP:p];
    double d2RhoDt2 = self.D2rhoDt2Last;
    double result = 50.29158649e8*d2RhoDt2/2.0/sqrt(rho)/sqrt(epsilon*t)
    - 50.29158649e8*dRhoDt*dRhoDt/4.0/pow(rho, 3.0/2.0)/sqrt(epsilon*t)
    - 50.29158649e8*dRhoDt*(dEpsilonDt*t+epsilon)/4.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
    - 50.29158649e8*(d2EpsilonDt2*t+2.0*dEpsilonDt)*sqrt(rho)/2.0/pow(epsilon*t, 3.0/2.0)
    - 50.29158649e8*(dEpsilonDt*t+epsilon)*dRhoDt/sqrt(rho)/4.0/pow(epsilon*t, 3.0/2.0)
    + 3.0*50.29158649e8*(dEpsilonDt*t+epsilon)*sqrt(rho)*(dEpsilonDt*t+epsilon)/4.0/pow(epsilon*t, 5.0/2.0);
    return result;
}

// private
- (double)d2BgammaDtDpFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDt = [self dEpsilonDtFromT:t andP:p];
    double dRhoDt = self.DrhoDtLast;
    double dEpsilonDp = [self dEpsilonDpFromT:t andP:p];
    double dRhoDp = self.DrhoDpLast;
    double d2EpsilonDtDp = [self d2EpsilonDtDpFromT:t andP:p];
    double d2RhoDtDp = self.D2rhoDtDpLast;
    double result = 50.29158649e8*d2RhoDtDp/2.0/sqrt(rho)/sqrt(epsilon*t)
                  - 50.29158649e8*dRhoDt*dRhoDp/4.0/pow(rho, 3.0/2.0)/sqrt(epsilon*t)
                  - 50.29158649e8*dRhoDt*dEpsilonDp*t/4.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
                  - 50.29158649e8*(d2EpsilonDtDp*t+dEpsilonDp)*sqrt(rho)/2.0/pow(epsilon*t, 3.0/2.0)
                  - 50.29158649e8*(dEpsilonDt*t+epsilon)*dRhoDp/4.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
                  + 3.0*50.29158649e8*(dEpsilonDt*t+epsilon)*sqrt(rho)*dEpsilonDp*t/4.0/pow(epsilon*t, 5.0/2.0);
    return result;
}

// private
- (double)d2BgammaDp2FromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    double dEpsilonDp = [self dEpsilonDpFromT:t andP:p];
    double dRhoDp = self.DrhoDpLast;
    double d2EpsilonDp2 = [self d2EpsilonDp2FromT:t andP:p];
    double d2RhoDp2 = self.D2rhoDp2Last;
    double result = 50.29158649e8*d2RhoDp2/2.0/sqrt(rho)/sqrt(epsilon*t)
                  - 50.29158649e8*dRhoDp*dRhoDp/4.0/pow(rho, 3.0/2.0)/sqrt(epsilon*t)
                  - 50.29158649e8*dRhoDp*dEpsilonDp*t/4.0/sqrt(rho)/pow(epsilon*t, 3.0/2.0)
                  - 50.29158649e8*dEpsilonDp*t*dRhoDp/sqrt(rho)/4.0/pow(epsilon*t, 3.0/2.0)
                  - 50.29158649e8*sqrt(rho)*d2EpsilonDp2*t/2.0/pow(epsilon*t, 3.0/2.0)
                  + 3.0*50.29158649e8*sqrt(rho)*dEpsilonDp*t*dEpsilonDp*t/4.0/pow(epsilon*t, 5.0/2.0);
    return result;
}



#pragma mark -
#pragma mark Debye-Huckel functions and their dervatives

- (double)AgammaFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    return 1.824829238e6*sqrt(rho)/pow(epsilon*t, 3.0/2.0);
}

- (double)BgammaFromT:(double)t andP:(double)p {
    // order here is important epsilon first
    double epsilon = [self epsilonFromT:t andP:p];
    double rho = self.rhoLast;
    return 50.29158649e8*sqrt(rho)/sqrt(epsilon*t);
}

#pragma mark -

- (double)AsubGfromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*t*[self AgammaFromT:t andP:p];
}

- (double)AsubHfromT:(double)t andP:(double)p {
    double dAGoverTdT = -2.0*log(10.0)*R*[self dAgammaDtFromT:t andP:p];
    return -dAGoverTdT*t*t;
}

- (double)AsubJfromT:(double)t andP:(double)p {
    double  dAGoverTdT  = -2.0*log(10.0)*R*[self dAgammaDtFromT:t andP:p];
    double d2AGoverTdT2 = -2.0*log(10.0)*R*[self d2AgammaDt2FromT:t andP:p];
    return -d2AGoverTdT2*t*t - 2.0*dAGoverTdT*t;
}

- (double)AsubVfromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*t*[self dAgammaDpFromT:t andP:p];
}

- (double)AsubKappaFromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*t*[self d2AgammaDp2FromT:t andP:p];
}

- (double)AsubExFromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*[self dAgammaDpFromT:t andP:p] - 2.0*log(10.0)*R*t*[self d2AgammaDtDpFromT:t andP:p];
}

#pragma mark -

- (double)BsubGfromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*t*[self BgammaFromT:t andP:p];
}

- (double)BsubHfromT:(double)t andP:(double)p {
    return 2.0*log(10.0)*R*t*t*[self dBgammaDtFromT:t andP:p];
}

- (double)BsubJfromT:(double)t andP:(double)p {
    return 4.0*log(10.0)*R*t*[self dBgammaDtFromT:t andP:p] + 2.0*log(10.0)*R*t*t*[self d2BgammaDt2FromT:t andP:p];
}

- (double)BsubVfromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*t*[self dBgammaDpFromT:t andP:p];
}

- (double)BsubKappaFromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*t*[self d2BgammaDp2FromT:t andP:p];
}

- (double)BsubExFromT:(double)t andP:(double)p {
    return -2.0*log(10.0)*R*[self dBgammaDpFromT:t andP:p] - 2.0*log(10.0)*R*t*[self d2BgammaDtDpFromT:t andP:p];
}

#pragma mark -
#pragma mark NSSecureCoding protocol

- (id)initWithCoder:(NSCoder *)aDecoder {
    if ((self = [super init])) {
        _tLast         = -1.0;
        _pLast         = -1.0;
        _rhoLast       = -1.0;
        _DrhoDtLast    = -1.0;
        _DrhoDpLast    = -1.0;
        _D2rhoDt2Last  = -1.0;
        _D2rhoDtDpLast = -1.0;
        _D2rhoDp2Last  = -1.0;
        
        // This is the generalized (+CO2) of Zhang & Duian (2005)
        _genericH2O = [[GenericH2O alloc] init];
        
        // These constants are from Sverjensky et at. (2014), GCA, 129, 125-145
        a1 = -1.576377e-3;
        a2 =  6.810288e-2;
        a3 =  7.548755e-1;
        
        b1 = -8.016651e-5;
        b2 = -6.871618e-2;
        b3 =  4.747973e0;
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder {
    if ([aCoder isKindOfClass:[NSKeyedArchiver class]]) {
        // encode permanent instance variables - none exist
    } else [NSException raise:NSInvalidArchiveOperationException format:@"Class DEWDielectricConstant only supports NSKeyedArchiver coders."];
}

+ (BOOL)supportsSecureCoding {
    return YES;
}

@end
