#include "orbitObject.h"
#include "acceleration.h"
#include "velocity.h"

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