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
  
   //Instatiate Positions
   Position leftPos(position);
   Position rightPos(position);
   Position centerPos(position);

   // Add Pixels to separate parts
   leftPos.addPixelsX(-20);
   rightPos.addPixelsX(20);
   centerPos.addPixelsY(20);
   Velocity vel(velocity);
   vel.addMetersX(2000);

   //GPS parts
   GPSCenter* centerGPS = new GPSCenter();
   centerGPS->setRotation(rotation.getAngle());
   centerGPS->setPosition(centerPos);
   centerGPS->setVelocity(vel);

   GPSRight* rightGPS = new GPSRight();
   rightGPS->setRotation(rotation.getAngle());
   rightGPS->setPosition(rightPos);
   rightGPS->setVelocity(Velocity(vel));

   
   GPSLeft* leftGPS = new GPSLeft();
   leftGPS->setRotation(rotation.getAngle());
   leftGPS->setPosition(leftPos);
   leftGPS->setVelocity(Velocity(vel));
  
   //Add to Vector
   orbitObjects.push_back(rightGPS);
   orbitObjects.push_back(leftGPS);
   orbitObjects.push_back(centerGPS);

}
