/***********************************************************************
 * Source File:
 *    dragon : Methods related to dragon
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return dragon parts
 ************************************************************************/

#pragma once
#include "dragon.h"



/************************************************************************
* breakApart
*    Takes
*    INPUT      gout   graphical output 
*               dragon dragon object       
************************************************************************/
void Dragon::breakApart(ogstream& gout, Dragon& dragon) {
   
   // I dont know what rotation does but it does some wild things
   double rotation = 10;
   // Instatiate new positions for each part
   Position initPosition(dragon.getPosition());
   Position leftPos(dragon.getPosition());
   Position rightPos(dragon.getPosition());
   // Add four pixels so they don't collide
   leftPos.addPixelsX(-4);
   rightPos.addPixelsX(4);
   // draw each dragon part
   gout.drawCrewDragonCenter(initPosition, rotation);
   gout.drawCrewDragonLeft(initPosition, rotation, leftPos);
   gout.drawCrewDragonRight(initPosition, rotation, rightPos);

}