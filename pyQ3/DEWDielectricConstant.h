//
//  DEWDielectricConstant.h
//  ThermoFit
//
//  Created by Mark Ghiorso on 10/29/15.
//  Copyright © 2015 Mark Ghiorso. All rights reserved.
//

#import <Foundation/Foundation.h>

@class GenericH2O;

@interface DEWDielectricConstant : NSObject <NSSecureCoding> {
    double a1, a2, a3, b1, b2, b3;
    double aTK1, aTK2, aTK3, bTK1, bTK2, bTK3;
}

@property (assign) double tLast;   // K
@property (assign) double pLast;   // bars

@property (assign) double rhoLast;       // g/cc
@property (assign) double DrhoDtLast;    // g/cc/K
@property (assign) double DrhoDpLast;    // g/cc/bar
@property (assign) double D2rhoDt2Last;  // g/cc/K/K
@property (assign) double D2rhoDtDpLast; // g/cc/K/bar
@property (assign) double D2rhoDp2Last;  // g/cc/bar/bar

@property (strong) GenericH2O *genericH2O;

- (void)loadDensityPropertiesWithT:(double)t andWithP:(double)p;

//
// T (K), P (bars) => dielectric constant
- (double)epsilonFromT:(double)t andP:(double)p;

// T (K), P (bars) => d(epsilon)/dT ( 1/K)
- (double)dEpsilonDtFromT:(double)t andP:(double)p;

// T (K), P (bars) => d(epsilon)/dP ( 1/bar)
- (double)dEpsilonDpFromT:(double)t andP:(double)p;

// T (K), P (bars) => d2(epsilon)/dT2 ( 1/K/K)
- (double)d2EpsilonDt2FromT:(double)t andP:(double)p;

// T (K), P (bars) => d2(epsilon)/dTdP ( 1/K/bar)
- (double)d2EpsilonDtDpFromT:(double)t andP:(double)p;

// T (K), P (bars) => d2(epsilon)/dP2 ( 1/bar/bar)
- (double)d2EpsilonDp2FromT:(double)t andP:(double)p;

//
// T (K), P (bars) => Q Born parameter
- (double)QfromT:(double)t andP:(double)p;

// T (K), P (bars) => N Born parameter
- (double)NfromT:(double)t andP:(double)p;

// T (K), P (bars) => U Born parameter
- (double)UfromT:(double)t andP:(double)p;

// T (K), P (bars) => Y Born parameter
- (double)YfromT:(double)t andP:(double)p;

// T (K), P (bars) => X Born parameter
- (double)XfromT:(double)t andP:(double)p;

// Numerical derivatives
- (double)dUdTfromT:(double)t andP:(double)p;
- (double)dUdPfromT:(double)t andP:(double)p;
- (double)dNdTfromT:(double)t andP:(double)p;
- (double)dNdPfromT:(double)t andP:(double)p;
- (double)dXdTfromT:(double)t andP:(double)p;

//
// T (K), P (bars) => A gamma Debye-Huckel parameter
- (double)AgammaFromT:(double)t andP:(double)p;

// T (K), P (bars) => B gamma Debye-Huckel parameter
- (double)BgammaFromT:(double)t andP:(double)p;

//
// T (K), P (bars) => A sub G Debye-Huckel parameter (J)
- (double)AsubGfromT:(double)t andP:(double)p;

// T (K), P (bars) => A sub H Debye-Huckel parameter (J)
- (double)AsubHfromT:(double)t andP:(double)p;

// T (K), P (bars) => A sub J Debye-Huckel parameter (J)
- (double)AsubJfromT:(double)t andP:(double)p;

// T (K), P (bars) => A sub V Debye-Huckel parameter (J)
- (double)AsubVfromT:(double)t andP:(double)p;

// T (K), P (bars) => A sub Kappa Debye-Huckel parameter (J)
- (double)AsubKappaFromT:(double)t andP:(double)p;

// T (K), P (bars) => A sub Ex Debye-Huckel parameter (J)
- (double)AsubExFromT:(double)t andP:(double)p;

//
// T (K), P (bars) => B sub G Debye-Huckel parameter (J)
- (double)BsubGfromT:(double)t andP:(double)p;

// T (K), P (bars) => B sub H Debye-Huckel parameter (J)
- (double)BsubHfromT:(double)t andP:(double)p;

// T (K), P (bars) => B sub J Debye-Huckel parameter (J)
- (double)BsubJfromT:(double)t andP:(double)p;

// T (K), P (bars) => B sub V Debye-Huckel parameter (J)
- (double)BsubVfromT:(double)t andP:(double)p;

// T (K), P (bars) => B sub Kappa Debye-Huckel parameter (J)
- (double)BsubKappaFromT:(double)t andP:(double)p;

// T (K), P (bars) => B sub Ex Debye-Huckel parameter (J)
- (double)BsubExFromT:(double)t andP:(double)p;

@end
