/***********************************************************************
 * Source File:
 *    GPS : Methods related to GPS satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return GPS parts
 ************************************************************************/


#include "gps.h"
#include "part.h"
#pragma once
/************************************************************************
* breakApart
*    Takes
*    INPUT      gout   graphical output
*               gps gps object
************************************************************************/
void GPS::breakApart(std::vector<OrbitObject*>& orbitObjects) const  {
  
   Position leftPos(position);
   Position rightPos(position);
   leftPos.addPixelsX(-40);
   rightPos.addPixelsX(40);
   Velocity vel(velocity);
   vel.addMetersX(1000);

   //GPS parts
   Part* centerGPS = new Part();
   centerGPS->setRotation(rotation.getAngle());
   centerGPS->getPosition();
   centerGPS->setVelocity(vel);

   Part* rightGPS = new Part();
   rightGPS->setRotation(rotation.getAngle());
   rightGPS->setPosition(rightPos);
   rightGPS->setVelocity(Velocity(vel));

   
   Part* leftGPS = new Part();
   leftGPS->setRotation(rotation.getAngle());
   leftGPS->setPosition(leftPos);
   leftGPS->setVelocity(Velocity(vel));
   //Add to Vector

   orbitObjects.push_back(rightGPS);
   orbitObjects.push_back(leftGPS);
   orbitObjects.push_back(centerGPS);

}
