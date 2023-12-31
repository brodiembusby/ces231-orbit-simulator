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

 /*********************************************
  * Dragon
  * The Dragon satellite.
  *********************************************/
class Dragon : public Satellite
{
public:
   
   void draw(ogstream& gout) const override { gout.drawCrewDragon(position, rotation.getAngle()); } // calls specific draw function
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;   // adds dragon part objects
   const double getRadius() const override { return 7; }

};

