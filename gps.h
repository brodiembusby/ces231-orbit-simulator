/***********************************************************************
 * Header File:
 *    GPS: GPS satellite in geosynchronous orbit.
 * Author:
 *    Aaron Fox, Brodie Busby
 * Summary:
 *    The class for the GPS satellite type.
 ************************************************************************/

#pragma once

#include "orbitObject.h"
#include "uiDraw.h"     // for RANDOM and DRAW*

class GPS : public OrbitObject
{
public:
   void draw(ogstream& gout) const override { gout.drawGPS(position, rotation.getAngle()); }
   void breakApart(ogstream& gout, GPS& gps);
   const double getRadius() const override { return 12; }
};

