#include "velocity.h"


// Velocity in meters or newVelocity
double Velocity::velocitywithConstantAcceleration(double initialVelocity, double acceleration, double time) {
   return initialVelocity + (acceleration * time);
}
// horizontalVelocity
double Velocity::horizontalVelocityWithConstantAcceleration(double initalHorizontalVelocity, double ddx, double time) {
   return initalHorizontalVelocity + (ddx * time);
}

double Velocity::motionWithConstantVelocity(double initialDistance, double velocity, double time) {
   return initialDistance + (velocity * time);
}
