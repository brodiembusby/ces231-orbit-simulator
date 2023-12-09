/***********************************************************************
 * Header File:
 *    Velocity : Velocity based on acceleration and time
 * Author:
 *    Aaron Fox, Brodie Busby
 * Summary:
 *    Derived class of Vector2D, contains constructors and getDeltaPosition
 ************************************************************************/

#pragma once

#include "vector2D.h"
#include "position.h"

 /*********************************************
  * Velocity
  * Speed in x- and y-components in meters/second.
  *********************************************/
class Velocity : public Vector2D
{

public:
   Velocity() : Vector2D() {}
   Velocity(double x, double y) : Vector2D(x, y) {}
   Velocity(const Velocity& pt) : Vector2D(pt) {}
   
   const Position getDeltaPosition(const double time) const;
};

