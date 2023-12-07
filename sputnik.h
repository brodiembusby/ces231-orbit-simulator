/***********************************************************************
 * Header File:
 *    Sputnik
 * Author:
 *    Brodie Busby, Cameron Lybbert
 * Summary:
 *    header file for Sputnik
 ************************************************************************/
#pragma once
#include "orbitObject.h"
class Sputnik : public OrbitObject
{

public:
   // Draws the satellite.
   void draw(ogstream& gout) const override { gout.drawSputnik(position, rotation.getAngle()); }

   // Called when satellite collides with something.
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;

   // Returns the radius of the part.
   const double getRadius() const override { return 4; }

};

