/***********************************************************************
 * Source File:
 *    GPS: GPS satellite in geosynchronous orbit.
 * Author:
 *    Aaron Fox
 * Summary:
 *    The class for the GPS satellite type.
 ************************************************************************/

#pragma once

#include "orbitObject.h"
#include "uiDraw.h"     // for RANDOM and DRAW*

class GPS : public OrbitObject
{
public:
   void draw(ogstream& gout) const override { gout.drawGPS(position, angle); }
};

