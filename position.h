/***********************************************************************
 * Header File:
 *    Point : The representation of a position
 * Author:
 *    Br. Helfrich, Brodie Busby, Aaron Fox
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/


#pragma once

#include <iostream> 
#include <cmath>
#include "vector2D.h"


class TestPosition;
class Acceleration;
class Velocity;
class Acceleration;

/*********************************************
 * Position
 * A single position on the field in Meters
 *********************************************/
class Position : public Vector2D
{
public:
   friend TestPosition;

   Position() : Vector2D() {}
   Position(double x, double y) : Vector2D(x, y) {}
   Position(const Position& pt) : Vector2D(pt) {}

   // Math relating to position
   // The current position above the earth
   const double getAltitude() const;
   const Acceleration& getGravity() const;
   static const double getDistance(const Position& p1, const Position& p2);
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
      (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Position& pt);
std::istream& operator >> (std::istream& in, Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


