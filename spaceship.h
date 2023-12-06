/***********************************************************************
 * Source File:
 *    Spaceship : The spaceship that the user controls.
 * Author:
 *    Aaron Fox
 * Summary:
 *    The class that controls the spaceship that the user flies.
 ************************************************************************/

#pragma once

#include "orbitObject.h"
#include "acceleration.h"
#include "bullet.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include <vector>

class Spaceship : public OrbitObject
{
private:
   bool isThrusting;

protected:
   void updateCallback(Acceleration& acceleration) override;

public:

   // Constants
   const double THRUST_AMOUNT = 2.0;      // Thrust in m/s^2
   const double ROTATION_SPEED = 0.1;     // Amount of radians the ship rotates every frame if the user holds an arrow key down.
   const double PROJECTILE_SPEED = 9000;  // Projectile speed in m/s.

   // Getters
   const double getRadius() const override { return 10; }

   // Setters
   void setThrustActive(bool active) { this->isThrusting = active; }   // Set whether the spaceship thruster is active.

   // Operations
   void draw(ogstream& gout) const override { gout.drawShip(position, rotation.getAngle(), isThrusting); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override; //TODO
   void rotateLeft() { rotation.addAngle(-ROTATION_SPEED); }
   void rotateRight() { rotation.addAngle(ROTATION_SPEED); }
   void shoot(std::vector<OrbitObject*>& orbitObjects) const;
   void update(const double time) override;
};

