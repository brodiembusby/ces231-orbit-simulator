#pragma once
class Acceleration
{
private:
   double angle; // initalize angle

   // I dont know where we are calling gravity  so i called it here because of 
   // Bro helfrich video
   double gravity = -9.8067 ; // initalize gravity -9.8067 m/s2


public:
   
   Acceleration() {};

   double degreeToRadian(double degree); // convert degrees to radians
  
   // Gn on helfritchs board
   double gravityH(double gravity, double radius, double height);

   // horizontal component of acceleration
   double ddx(double totalAcceleration, double angle);
   // vertical component of acceleration
   double ddy(double totalAcceleration, double angle);

   // Setters
   void setGravity(double gravy) { this->gravity = gravy; }

   // Getters 
   double getGravity() { return gravity; }

};

