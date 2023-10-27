#pragma once
class Rotation
{
public:

   Rotation() : angle(0), speed(1) {}

   double getAngle() const { return angle; }
   void setAngle(double angle) { this->angle = angle; }

   double getSpeed() const { return speed; }
   void setSpeed(double speed) { this->speed = speed; }

   /*
   * Will update the angle that the object is facing.
   */
   void update(double angle);
   
   /*
   * Will update the angle that the earth is facing.
   */
   void updateEarth();

   /*
   * Will update the angle that the satallite is facing.
   */
   void updateSatellite();

private:
   double angle;
   double speed;
};

