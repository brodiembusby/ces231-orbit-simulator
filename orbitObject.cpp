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
#pragma once
 /************************************************************************
 * UPDATE
 * Performs a physics tick and updates the object's components.
 *    INPUT  time                The amount of time in seconds to simulate.
 ************************************************************************/
void OrbitObject::update(const double time)
{
   // Set acceleration to gravity
   Acceleration acceleration(position.getGravity());
   accelerateCallback(acceleration);

   // Update velocity
   const Velocity& dV = acceleration.getDeltaVelocity(time);
   velocity += dV;

   // Update position
   const Position dP = velocity.getDeltaPosition(time);
   position += dP;
}


/************************************************************************
* CHECK COLLISION
* Checks if this object is colliding with another.
*    OrbitObject  other          The other object.
************************************************************************/
const bool OrbitObject::checkCollision(const OrbitObject& other) const 
{
   const double distance = Position::getDistance(position, other.position);
   return distance <= (getRadius() + other.getRadius()) * position.getZoom();
}

void OrbitObject::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   
}