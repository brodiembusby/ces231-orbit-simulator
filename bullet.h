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
private:
   int aliveTime;

protected:
   void updateCallback(Acceleration& acceleration) override;  // Disable gravity.

public:
   // Constants
   const int LIFETIME = 70;   // How many frames the bullet is alive for.

   // Operations
   void draw(ogstream& gout) const override { gout.drawProjectile(position); }
   const double getRadius() const override { return 0.5; }
   void breakApart(std::vector<OrbitObject*>& _) const override {}
   void update(const double time) override;
};