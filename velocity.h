#pragma once
class Velocity
{


public:
   double motionWithConstantVelocity(double initialDistance, double velocity, double time);
   double velocitywithConstantAcceleration(double initalVelocity, double acceleration, double time);
   double horizontalVelocityWithConstantAcceleration(double initalHorizontalVelocity, double ddx, double time);
};

