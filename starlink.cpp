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



/************************************************************************
* breakApart
*    Takes
*    INPUT      gout:   graphical output
*               starlink: Starlink object
************************************************************************/
void Starlink::breakApart(ogstream& gout, Starlink& starlink) {

   // I dont know what rotation does but it does some wild things
   double rotation = 10;
   // Instatiate new positions for each part
   Position initPosition(starlink.getPosition());
   Position bodyPos(starlink.getPosition());
   Position arrayPos(starlink.getPosition());
   // Add four pixels so they don't collide
   bodyPos.addPixelsX(4);
   arrayPos.addPixelsX(4);
   // draw each starlink part
   gout.drawStarlinkBody(initPosition, rotation, bodyPos);
   gout.drawStarlinkArray(initPosition, rotation, arrayPos);

}