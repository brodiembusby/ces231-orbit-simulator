/*************************************************************
 * 1. Name:
 *      Cameron Lybbert
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. File Description:
 *      Helps simulate the rotation of objects.
 *****************************************************************/
#pragma once

#include "constants.h"

class Rotation
{
   friend class TestRotation;
public:

   Rotation() : angle(0), speed(0) {}
   Rotation(double angle) : angle(angle), speed(0) {}
   Rotation(double angle, double speed) : angle(angle), speed(speed) {}
   Rotation(const Rotation& rhs)
   {
      this->angle = rhs.angle;
      this->speed = rhs.speed;
   }

   double getAngle() const { return angle; }
   double getSpeed() const { return speed; }

   void setAngle(double angle) { this->angle = angle; }
   void setSpeed(double speed) { this->speed = speed; }

   void addAngle(double delta) { this->angle += delta; }
   void update(const double time) { angle += speed * time; }

private:
   double angle;
   double speed;
};

