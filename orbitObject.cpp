/***********************************************************************
 * Source File:
 *    OrbitObject : Any object that orbits the Earth.
 * Author:
 *    Aaron Fox.
 * Summary:
 *    Base class for supporting orbiting objects.
 ************************************************************************/

#include "orbitObject.h"
#include "acceleration.h"
#include "velocity.h"

/************************************************************************
* UPDATE
* Performs a physics tick and updates the object's components.
*    INPUT  time                The amount of time in seconds to simulate.
************************************************************************/
void OrbitObject::update(const double time)
{
   // Set acceleration to gravity
   const Acceleration& gravity = position.getGravity();
   acceleration = gravity;

   // Update velocity
   const Velocity& dV = acceleration.getDeltaVelocity(time);
   velocity += dV;

   // Update position
   const Position dP = velocity.getDeltaPosition(time);
   position += dP;
}