/***********************************************************************
 * Source File:
 *    Orbit Object : Any object that exhibits orbital behavior.
 * Author:
 *    Aaron Fox
 * Summary:
 *    The base class for objects that will orbit around the Earth.
 ************************************************************************/

#pragma once

#include "position.h"
#include "velocity.h"
#include "acceleration.h"
#include "uiDraw.h"     // for RANDOM and DRAW*

class OrbitObject
{
protected:
   Position position;
   Velocity velocity;
   Acceleration acceleration;
   double angle;

public:
   OrbitObject() : position(), velocity(), acceleration(), angle(0.0) {}

   Position& getPosition() { return position; }
   Velocity& getVelocity() { return velocity; }
   Acceleration& getAcceleration() { return acceleration; }
   double& getAngle() { return angle; }

   void setPosition(const Position& position) { this->position = position; }
   void setVelocity(const Velocity& velocity) { this->velocity = velocity; }
   void setAcceleration(const Acceleration& acceleration) { this->acceleration = acceleration; }
   void setAngle(const double angle) { this->angle = angle; }

   virtual void draw(ogstream gout) const = 0;
};

