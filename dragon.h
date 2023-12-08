/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Brodie Busby, Cameron Lybbert
 * Summary:
 *    header file for Dragon
 ************************************************************************/

#pragma once
#include "satellite.h"
class Dragon : public Satellite
{
public:
   void draw(ogstream& gout) const override { gout.drawCrewDragon(position, rotation.getAngle()); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;
   const double getRadius() const override { return 7; }

};

