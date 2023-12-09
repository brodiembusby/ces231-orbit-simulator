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

class Fragment;

/*******************************
 * OrbitObject
 * Base class for any object that orbits the Earths. Implements gravity and inertia.
 ********************************/
class OrbitObject
{
protected:
   bool isDestroyed;
   Position position;
   Velocity velocity;
   Rotation rotation;
   virtual void updateCallback(Acceleration& acceleration) {}
public:
   OrbitObject() : isDestroyed(false) {}
   OrbitObject(const Position& position, const Velocity& velocity) : OrbitObject()
   {
      this->position = position;
      this->velocity = velocity;
   }

   // Getters
   Position& getPosition() { return position; }
   Velocity& getVelocity() { return velocity; }
   Rotation& getRotation() { return rotation; }
   bool getIsDestroyed() const { return isDestroyed; }
   virtual const double getRadius() const = 0;
   const bool checkCollision(const OrbitObject& other) const;
   const bool checkCollision(const Position& pos, const double radius) const;
   static double getRandomDouble(double min, double max);

   // Setters
   void setPosition(const Position& position) { this->position = position; }
   void setVelocity(const Velocity& velocity) { this->velocity = velocity; }
   void setRotation(const Rotation& rotation) { this->rotation = rotation; }

   // Operations
   virtual void update(const double time);
   Fragment* createFragment(const double angle) const;

   // Abstract
   virtual void draw(ogstream& gout) const = 0;
   virtual void breakApart(std::vector<OrbitObject*>& orbitObjects) const {};
};

