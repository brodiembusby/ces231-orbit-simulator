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
   void draw(ogstream& gout) const override { gout.drawSputnik(position, rotation.getAngle()); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;
   const double getRadius() const override { return 4; }

};

