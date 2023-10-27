#include "Math.h" // our math class

#include <math.h> // for sin,cos,pow, atan2


// I dont think these will be in the velocity, acceleration  or position class. If you have written these already math.h and math.cpp 
// can be deleted entirely



double Math::directionOfGravityPull(double Xe, double Ye, double Xs, double Ys) {
   return atan2(Xe - Xs, Ye - Ys);
}



