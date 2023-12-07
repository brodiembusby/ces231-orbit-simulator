/***********************************************************************
 * Header File:
 *    Starlink
 * Author:
 *    Brodie Busby, Cameron Lybbert
 * Summary:
 *    header file for Starlink
 ************************************************************************/

#pragma once
#include "orbitObject.h"
class Starlink : public OrbitObject
{
public:
   // Draws the satellite.
   void draw(ogstream& gout) const override { gout.drawStarlink(position, rotation.getAngle()); }
   // Called when collides with something.
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;
   // Returns the radius of the object.
   const double getRadius() const override { return 6; }

};

