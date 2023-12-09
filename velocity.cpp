/***********************************************************************
 * Source File:
 *    Velocity : Velocity based on acceleration and time
 * Author:
 *    Aaron Fox, Brodie Busby
 * Summary:
 *    Derived class of Vector2D, calculates DeltaPosition
 ************************************************************************/

#include "velocity.h"
#include "position.h"

/************************************************************************
 * GET DELTA POSITION
 * Calculates the delta position resultant from this Velocity after the given time.
 *    INPUT  time                Time
 *    OUTPUT                     Delta position after the specified time
 ************************************************************************/
const Position Velocity::getDeltaPosition(const double time) const
{
   Position delta(x * time, y * time);
   return delta;
}
