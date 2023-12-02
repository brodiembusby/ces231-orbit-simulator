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
#include "fragment.h"
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
   updateCallback(acceleration);

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
   return checkCollision(other.position, other.getRadius());
}


/************************************************************************
* CHECK COLLISION
* Checks if this object is colliding with another.
*    Position  pos               The position of the other object.
*    double    radius            The radius of the other object.
************************************************************************/
const bool OrbitObject::checkCollision(const Position& pos, const double radius) const
{
   const double distance = Position::getDistance(position, pos);
   return distance <= (getRadius() + radius) * position.getZoom();
}

void OrbitObject::breakApart(std::vector<OrbitObject*>& orbitObjects) const {
   Velocity vel(velocity);
   vel.addMetersX(1000);

   const int fragmentCount = 5; // Number of fragments
   Fragment* fragments[fragmentCount];
   const int spacing = 100; // Spacing in degrees (for a circular pattern)

   //for (int i = 0; i < fragmentCount; i++) {
   //   fragments[i] = new Fragment();
   //   Position pos(position);

   //   // Calculate the position for each fragment in a circular pattern
   //   float angle = (spacing * i) * (M_PI / 180.0); // Convert degrees to radians
   //   float xOffset = cos(angle) * 10; // 10 is the radius of the circle
   //   float yOffset = sin(angle) * 10;

   //   pos.addPixelsX(xOffset);
   //   pos.addPixelsY(yOffset);

   //   // Generate a random rotation for each fragment
   //   float randomRotation = static_cast<float>(rand() % 360); // Random angle between 0 and 359 degrees

   //   fragments[i]->setRotation(randomRotation);
   //   fragments[i]->setPosition(pos);
   //   fragments[i]->setVelocity(vel);
   //   orbitObjects.push_back(fragments[i]);
   //}
   //
}