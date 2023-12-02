/***********************************************************************
 * Source File:
 *    starlink : Methods related to starlink satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return starlink parts
 ************************************************************************/

#pragma once
#include "starlink.h"
#include "part.h"
/************************************************************************
* breakApart
*    Takes
*    INPUT      gout:   graphical output
*               starlink: Starlink object
************************************************************************/
void Starlink::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   Position downPos(position);
   Position upPos(position);
   upPos.addPixelsY(4);
   downPos.addPixelsY(-4);

   //Starlink parts
   Part* upStarlink = new Part();
   upStarlink->setRotation(rotation.getAngle());
   upStarlink->getPosition();
   upStarlink->setVelocity(Velocity(velocity));

   Part* downStarlink = new Part();
   downStarlink->setRotation(rotation.getAngle());
   downStarlink->setPosition(downPos);
   downStarlink->setVelocity(Velocity(velocity));

   //Add to Vector
   orbitObjects.push_back(upStarlink);
   orbitObjects.push_back(downStarlink);

}