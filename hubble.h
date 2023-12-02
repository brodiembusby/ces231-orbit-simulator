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
class Hubble : public OrbitObject
{

public:
   void draw(ogstream& gout) const override { gout.drawHubble(position, rotation.getAngle()); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;
   const double getRadius() const override { return 10; }

};

