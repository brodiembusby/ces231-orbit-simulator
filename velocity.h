#pragma once
class Velocity
{
   double geoSpeed;  //inital geoSpeed
   double dx0;    //initialHorizontalVelocity;
   double dy0;     //initialVerticalVelocity;


public:
   
   //Velocity(double speed, double initialHorizontalVelocity, double initialVerticalVelocity) { geoSpeed = speed; dx0 = initialHorizontalVelocity; dy0 = initialVerticalVelocity; }
  
   Velocity() : dx0(0.0), dy0(0.0) {}
   Velocity( double initialHorizontalVelocity, double initialVerticalVelocity) { dx0 = initialHorizontalVelocity; dy0 = initialVerticalVelocity; }

   // I dont know what these do exactly
   double motionWithConstantVelocity(double initialDistance, double velocity, double time);
   double velocitywithConstantAcceleration(double initalVelocity, double acceleration, double time);

   // horizontalVelocityWithConstantAcceleration
   double dx(double initalHorizontalVelocity, double ddx, double time);
   // verticalVelocityWithConstantAcceleration
   double dy(double initalVerticalVelocity, double ddy, double time);

   // Setters
   void setGeoSpeed(double speed) { this->geoSpeed = speed; }
   void setdx0(double dx) { this->dx0 = dx; }
   void setdy0(double dy) { this->dy0 = dy; }

   // Getters 
   double getGeoSpeed() { return geoSpeed; }
   double getdx0() { return dx0; }
   double getdy0() { return dy0; }

};

