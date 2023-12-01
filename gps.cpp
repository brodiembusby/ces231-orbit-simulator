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
void GPS::breakApart(ogstream& gout, GPS& gps) {

   // I dont know what rotation does but it does some wild things
   double rotation = 10;
   // Instatiate new positions for each part
   Position initPosition(gps.getPosition());
   Position leftPos(gps.getPosition());
   Position rightPos(gps.getPosition());
   // Add four pixels so they don't collide
   leftPos.addPixelsX(10);
   rightPos.addPixelsX(-10);
   // draw each gps part
   gout.drawGPSCenter(initPosition, rotation);
   gout.drawGPSLeft(initPosition, rotation, leftPos);
   gout.drawGPSRight(initPosition, rotation, rightPos);

}