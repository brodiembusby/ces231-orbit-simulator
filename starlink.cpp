/***********************************************************************
 * Source File:
 *    Starlink : Methods related to starlink satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return starlink parts
 ************************************************************************/

#pragma once

#include "starlink.h"
#include "part.h"

 /************************************************************************
 * BREAK APART
 * Called when the satellite collides with something.
 *    INPUT  orbitObjects      List of all active orbit objects in the same during this frame.
 *                             Passed by reference to allow modification.
 ************************************************************************/
void Starlink::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   //Instatiate Parts
   Position downPos(position);
   Position upPos(position);
   // Add Pixels to separate parts
   upPos.addPixelsY(20);
   downPos.addPixelsY(-20);
   Velocity vel(velocity);
   vel.addMetersX(1000);

   //Starlink parts
   StarlinkArray* upStarlink = new StarlinkArray();
   upStarlink->setRotation(rotation.getAngle());
   upStarlink->getPosition();
   upStarlink->setVelocity(Velocity(vel));

   StarlinkBody* downStarlink = new StarlinkBody();
   downStarlink->setRotation(rotation.getAngle());
   downStarlink->setPosition(downPos);
   downStarlink->setVelocity(Velocity(vel));

   //Add to Vector
   orbitObjects.push_back(upStarlink);
   orbitObjects.push_back(downStarlink);

}