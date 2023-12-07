/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Brodie Busby, Cameron Lybbert
 * Summary:
 *    header file for Hubble
 ************************************************************************/
#pragma once

#include "orbitObject.h"

 /*******************************
  * HUBBLE
  * The Hubble (telescope) satellite.
  ********************************/
class Hubble : public OrbitObject
{

public:
   // Will draw the hubble object.
   void draw(ogstream& gout) const override { gout.drawHubble(position, rotation.getAngle()); }

   // Called when the object is hit.
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;

   // Returns the radius of the hubble.
   const double getRadius() const override { return 10; }
};
