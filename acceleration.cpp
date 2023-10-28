#include "acceleration.h"
#include "position.h"
#include "velocity.h"
#include "constants.h"
#include <cmath>

/************************************************************************
 * GET GRAVITY COMPONENT
 * Calculates the gravity component at the provided position.
 *    INPUT  pos                 The current position in absolute space.
 *    OUTPUT                     An acceleration containing the components of gravity.
 ************************************************************************/
const Acceleration Acceleration::getGravityComponent(const Position& pos)
{
   const double gravity = getGravity(pos.getAltitude());
   const double angle = getGravityAngle(pos);
   double x = getHorizontalComponent(gravity, angle);
   double y = getVerticalComponent(gravity, angle);
   return Acceleration(x, y);
}

/************************************************************************
 * GET GRAVITY ANGLE
 * Gets the angle of gravity towards the planet.
 *    INPUT  pos                 The current position in absolute space.
 *    OUTPUT                     The angle in radians of the gravity vector.
 ************************************************************************/
const double Acceleration::getGravityAngle(const Position& pos)
{
   return (const double)std::atan2(-pos.getMetersY(), -pos.getMetersX());
}

/************************************************************************
 * GET GRAVITY
 * Calculates the magnitude of gravity at the provided altitude above sea level.
 *    INPUT  height              The altitude in meters above sea level.
 *    OUTPUT                     The magnitude of gravity in m/s^2.
 ************************************************************************/
const double Acceleration::getGravity(const double height)
{
   return GRAVITY_SEA_LEVEL * std::pow(RADIUS_EARTH / (RADIUS_EARTH + height), 2);
}

/************************************************************************
 * GET DELTA VELOCITY
 * Calculates the resulting velocity change over time from this acceleration.
 *    INPUT  time                The amount of time this acceleration is active.
 *    OUTPUT                     A velocity containing the deltas.
 ************************************************************************/
const Velocity Acceleration::getDeltaVelocity(const double time) const
{
   return Velocity(x * time, y * time);
}