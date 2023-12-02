/***********************************************************************
 * Source File:
 *    GPS : Methods related to GPS satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return GPS parts
 ************************************************************************/

#pragma once
#include "gps.h"



/************************************************************************
* breakApart
*    Takes
*    INPUT      gout   graphical output
*               gps gps object
************************************************************************/
void GPS::breakApart(std::vector<OrbitObject*>& orbitObjects) const  {
  
   Position leftPos(position);
   Position rightPos(position);
   leftPos.addPixelsX(-4);
   rightPos.addPixelsX(4);

   //GPS parts
   GPS* centerGPS = new GPS();
   centerGPS->setRotation(rotation.getAngle());
   centerGPS->getPosition();
   centerGPS->setVelocity(Velocity(velocity));

   GPS* rightGPS = new GPS();
   rightGPS->setRotation(rotation.getAngle());
   rightGPS->setPosition(rightPos);
   rightGPS->setVelocity(Velocity(velocity));

   GPS* leftGPS = new GPS();
   leftGPS->setRotation(rotation.getAngle());
   leftGPS->setPosition(leftPos);
   leftGPS->setVelocity(Velocity(velocity));

   //Add to Vector
   orbitObjects.push_back(centerGPS);
   orbitObjects.push_back(rightGPS);
   orbitObjects.push_back(leftGPS);

}