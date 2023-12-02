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
#include "rotation.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include <vector>
class OrbitObject
{
protected:
   
   Position position;
   Velocity velocity;
   Rotation rotation;
   virtual void accelerateCallback(Acceleration& acceleration) const {}
public:
   OrbitObject() : position(), velocity(), rotation() {}
   OrbitObject(const Position& position, const Velocity& velocity) : OrbitObject()
   {
      this->position = position;
      this->velocity = velocity;
   }

   // Getters
   Position& getPosition() { return position; }
   Velocity& getVelocity() { return velocity; }
   Rotation& getRotation() { return rotation; }
   virtual const double getRadius() const { return 0; }
   const bool checkCollision(const OrbitObject& other) const;

   // Setters
   void setPosition(const Position& position) { this->position = position; }
   void setVelocity(const Velocity& velocity) { this->velocity = velocity; }
   void setRotation(const Rotation& rotation) { this->rotation = rotation; }

   // Operations
   void update(const double time);

   // Abstract
   virtual void draw(ogstream& gout) const = 0;
   virtual void breakApart(std::vector<OrbitObject*>& orbitObjects) const = 0;
};

