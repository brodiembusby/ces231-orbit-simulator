/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich, Brodie Busby, Aaron Fox
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/

#include "position.h"
#include "acceleration.h"
#include <cassert>
#include "constants.h"

/******************************************
 * POSITION insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream& operator << (std::ostream& out, const Position& pt)
{
   out << "(" << pt.getMetersX() << "m , " << pt.getMetersY() << "m)";
   return out;
}
   
/*******************************************
* POSITION extraction
*       Prompt for coordinates
******************************************/
std::istream& operator >> (std::istream& in, Position& pt)
{
   double x;
   double y;
   in >> x >> y;

   pt.setMetersX(x);
   pt.setMetersY(y);

   return in;
}

/************************************************************************
 * GET ALTITUDE
 * Calculates the altitude of this position above sea level.
 *    OUTPUT                     The altitude in meters above sea level.
 ************************************************************************/
const double Position::getAltitude() const {
   // The current height above the earth
   return sqrt(pow(x, 2.0) + pow(y, 2.0)) - RADIUS_EARTH;
}

/************************************************************************
 * GET GRAVITY
 * Calculates gravity component that is effective at this position.
 *    OUTPUT                     An acceleration containing the components of gravity at that position.
 ************************************************************************/
const Acceleration& Position::getGravity() const
{
   return Acceleration::getGravityComponent(*this);
}