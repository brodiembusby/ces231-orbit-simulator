/***********************************************************************
 * Source File:
 *    OrbitObject : Any object that orbits the Earth.
 * Author:
 *    Aaron Fox, Cameron Lybbert
 * Summary:
 *    Base class for supporting orbiting objects.
 ************************************************************************/

#include "orbitObject.h"
#include "acceleration.h"
#include "velocity.h"
#include "fragment.h"
#include <random>

std::default_random_engine re;

/************************************************************************
* GET RANDOM DOUBLE
* Utility function that generates and returns a random double.
* some time.
*    INPUT  min            The lowest acceptable number.
*           max            The highest acceptable number.
************************************************************************/
double OrbitObject::getRandomDouble(double min, double max)
{
   std::uniform_real_distribution<double> unif(min, max);
   return unif(re);
}

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

/************************************************************************
* CHECK COLLISION
* Checks if this object is colliding with another.
*    Position  pos               The position of the other object.
*    double    radius            The radius of the other object.
************************************************************************/
Fragment* OrbitObject::createFragment(const double angle) const
{
   Fragment* fragment = new Fragment();
   Position pos(position);

   double angle_rad = angle * (M_PI / 180);

   // Calculate the position for each fragment in a circular pattern
   float xOffset = cos(angle_rad) * 4; // 4 pixels away from the center
   float yOffset = sin(angle_rad) * 4;

   pos.addPixelsX(xOffset);
   pos.addPixelsY(yOffset);

   // Create a random speed in that direction.
   Velocity vel(velocity);

   // Get random delta magnitude
   double dv = getRandomDouble(0, 4000);

   // Add magnitude with their directions.
   vel.addMetersX(Vector2D::getHorizontalComponent(dv, angle_rad));
   vel.addMetersY(Vector2D::getVerticalComponent(dv, angle_rad));
   fragment->setVelocity(vel);

   // Generate a random rotation for each fragment
   float randomRotation = getRandomDouble(0, 359);
   float randomRotateSpeed = getRandomDouble(10, 20);

   fragment->getRotation().setAngle(randomRotation);
   fragment->getRotation().setSpeed(randomRotateSpeed);
   fragment->setPosition(pos);
   return fragment;
}