/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Brodie Busby, Cameron Lybbert
 * Summary:
 *    header file for Dragon
 ************************************************************************/

#pragma once
#include "orbitObject.h"
class Dragon : public OrbitObject
{
public:
   void draw(ogstream& gout) const override { gout.drawCrewDragon(position, rotation.getAngle()); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;
};

