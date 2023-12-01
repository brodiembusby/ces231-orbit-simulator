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
class Starlink :
    public OrbitObject
{
public:
   void draw(ogstream& gout) const override { gout.drawStarlink(position, rotation.getAngle()); }
   void breakApart(ogstream& gout, Starlink& starlink);
};

