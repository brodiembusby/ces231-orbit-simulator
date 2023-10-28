#pragma once

#include "vector2D.h"
#include "position.h"

class Velocity : public Vector2D
{

public:
   Velocity() : Vector2D() {}
   Velocity(double x, double y) : Vector2D(x, y) {}
   Velocity(const Velocity& pt) : Vector2D(pt) {}
   
   const Position getDeltaPosition(const double time) const;
};

