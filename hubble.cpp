/***********************************************************************
 * Source File:
 *    Hubble : Methods related to hubble satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return hubble parts
 ************************************************************************/

#pragma once
#include "hubble.h"



/************************************************************************
* breakApart
*    Takes
*    INPUT      gout   graphical output
*               hubble Hubble object
************************************************************************/
void Hubble::breakApart(ogstream& gout, Hubble& hubble) {

   // I dont know what rotation does but it does some wild things
   double rotation = 10;
   // Instatiate new positions for each part
   Position initPosition(hubble.getPosition());
   Position leftPos(hubble.getPosition());
   Position rightPos(hubble.getPosition());
   Position computerPos(hubble.getPosition());
   Position telescopePos(hubble.getPosition());
   // Add four pixels so they don't collide
   leftPos.addPixelsX(10);
   rightPos.addPixelsX(-10);
   computerPos.addPixelsY(10);
   telescopePos.addPixelsY(-10);
   // draw each hubble part
   gout.drawHubbleComputer(initPosition, rotation, telescopePos);
   gout.drawHubbleComputer(initPosition, rotation, computerPos);
   gout.drawHubbleLeft(initPosition, rotation, leftPos);
   gout.drawHubbleRight(initPosition, rotation, rightPos);

}