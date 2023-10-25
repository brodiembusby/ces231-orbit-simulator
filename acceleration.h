#pragma once
class Acceleration
{
private:
   double angle; // initalize angle

   // I dont know where we are calling gravity  so i called it here because of 
   // Bro helfrich video
   double gravity; // initalize gravity


public:
   
   double degreeToRadian(double degree); // convert degrees to radians
  
   // Gn on helfritchs board
   double gravityH(double gravity, double radius, double height);

   double ddx(double totalAcceleration, double angle);
   double ddy(double totalAcceleration, double angle);

   // Setters
   void setGravity(double gravy) { this->gravity = gravy; }

   // Getters 
   double getGeoSpeed() { return gravity; }

};

