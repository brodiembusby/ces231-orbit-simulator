#include "velocity.h"


/************************************************************************
 * VELOCITYWITHCONSTANTACCELERATION
 * Calculate the final velocity after a certain time with a constant acceleration.
 *    INPUT  initialVelocity     The starting velocity
 *           acceleration        The acceleration
 *           time                Time 
 *    OUTPUT                     Final velocity after the specified time
 ************************************************************************/
double Velocity::velocitywithConstantAcceleration(double initialVelocity, double acceleration, double time) {
   return initialVelocity + (acceleration * time);
}

/************************************************************************
 * DX
 * Calculate the horizontal velocity after a certain time with a given horizontal acceleration.
 *    INPUT  initalHorizontalVelocity The starting horizontal velocity
 *           ddx                      The horizontal acceleration
 *           time                     Time 
 *    OUTPUT                          Horizontal velocity after the specified time
 ************************************************************************/
double Velocity::dx(double initalHorizontalVelocity, double ddx, double time) {
   return initalHorizontalVelocity + (ddx * time);
}

/************************************************************************
 * DY
 * Calculate the vertical velocity after a certain time with a given vertical acceleration.
 *    INPUT  initalVerticalVelocity   The starting vertical velocity
 *           ddy                      The vertical acceleration
 *           time                     Time 
 *    OUTPUT                          Vertical velocity after the specified time
 ************************************************************************/
double Velocity::dy(double initalVerticalVelocity, double ddy, double time) {
   return initalVerticalVelocity + (ddy * time);
}

/************************************************************************
 * MOTIONWITHCONSTANTVELOCITY
 * Calculate the new position (distance) after a certain time with a constant velocity.
 *    INPUT  initialDistance          The starting position (distance)
 *           velocity                 The constant velocity
 *           time                     Time duration
 *    OUTPUT                          New position (distance) after the specified time
 ************************************************************************/
double Velocity::motionWithConstantVelocity(double initialDistance, double velocity, double time) {
   return initialDistance + (velocity * time);
}