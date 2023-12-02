/***********************************************************************
 * Source File:
 *    Bullet : Projectile fired from the spaceship.
 * Author:
 *    Aaron Fox
 * Summary:
 *    The class containing all functionality for the bullet.
 ************************************************************************/

#pragma once
#include "orbitObject.h"
#include "uiDraw.h"     // for RANDOM and DRAW*

class Bullet : public OrbitObject
{
protected:
   void accelerateCallback(Acceleration& acceleration) const { acceleration.setMeters(0, 0); }  // Disable gravity.

public:
   // Operations
   void draw(ogstream& gout) const override { gout.drawProjectile(position); }
   const double getRadius() const override { return 0.5; }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override; // TODO
}; 