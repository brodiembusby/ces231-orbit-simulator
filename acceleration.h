/***********************************************************************
 * Source File:
 *    Velocity : Velocity based on acceleration and time
 * Author:
 *    Aaron Fox, Brodie Busby
 * Summary:
 *    Derived class of Vector2D. contains assets to compute velocity in space
 ************************************************************************/
#pragma once

#include "vector2D.h"
#include "position.h"

class Acceleration : public Vector2D
{
   friend testAcceleration;
private:
   static const double getGravity(const double height);
   static const double getGravityAngle(const Position& pos);

public:
   Acceleration() : Vector2D() {}
   Acceleration(double x, double y) : Vector2D(x, y) {}
   Acceleration(const Acceleration& pt) : Vector2D(pt) {}

   static const Acceleration getGravityComponent(const Position& pos);

   const Velocity getDeltaVelocity(const double time) const;
};

