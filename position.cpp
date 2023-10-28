/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
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

const double Position::getAltitude() const {
   // The current height above the earth
   return sqrt(pow(x, 2.0) + pow(y, 2.0)) - RADIUS_EARTH;
}

const Acceleration& Position::getGravity() const
{
   return Acceleration::getGravityComponent(*this);
}

// xT
double Position::horizontalPositionConstantVelocity(double initialHorizontalPostion, double dx, double time) {
   return initialHorizontalPostion + (dx * time);
}

// yT
double Position::verticalPositionConstantVeloctity(double initialVerticalPostion, double dy, double time) {
   return initialVerticalPostion + (dy + time);
}

// acceleration will be ddx or ddy
double Position::distanceFormula(double initialDistance, double velocity, double  time, double acceleration) {
   return initialDistance + (velocity * time) + (1 / 2) * (acceleration * pow(time, 2.0));
}

//returns an an angle in radians  pointing to center of earth 
double Position::directionOfGravityPull(double Xe, double Ye, double Xs, double Ys) {
   return atan2(Ye - Ys,Xe - Xs);
}
