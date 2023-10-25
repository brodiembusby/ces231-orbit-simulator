#include "Math.h" // our math class

#include <math.h> // for sin,cos,pow, atan2


// I dont think these will be in the velocity, acceleration  or position class. If you have written these already math.h and math.cpp 
// can be deleted entirely


double Math::gravityEquation(double gravity, double radius, double height) {
   return gravity * pow((radius / radius + height), 2.0);
}

double Math::directionOfGravityPull(double Xe, double Ye, double Xs, double Ys) {
   return atan2(Xe - Xs, Ye - Ys);
}

double Math::distanceFormula(double initialDistance, double velocity, double  time, double acceleration) {
   return initialDistance + (velocity * time) + (1 / 2) * (acceleration * pow(time, 2.0));
}

