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
void Dragon::breakApart(std::vector<OrbitObject*>& orbitObjects) const {


   //Instatiate Pixels
   Position leftPos(position);
   Position rightPos(position);
   // Add Pixels to separate parts
   leftPos.addPixelsX(-4);
   rightPos.addPixelsX(4);

   //CrewDragon parts
   Dragon* CrewDragonCenter = new Dragon();
   CrewDragonCenter->setRotation(rotation.getAngle());
   CrewDragonCenter->getPosition();
   CrewDragonCenter->setVelocity(Velocity(velocity));

   Dragon* CrewDragonLeft = new Dragon();
   CrewDragonLeft->setRotation(rotation.getAngle());
   CrewDragonLeft->setPosition(leftPos);
   CrewDragonLeft->setVelocity(Velocity(velocity));

   Dragon* CrewDragonRight = new Dragon();
   CrewDragonRight->setRotation(rotation.getAngle());
   CrewDragonRight->setPosition(rightPos);
   CrewDragonRight->setVelocity(Velocity(velocity));

   //Add to Vector
   orbitObjects.push_back(CrewDragonRight);
   orbitObjects.push_back(CrewDragonLeft);
   orbitObjects.push_back(CrewDragonCenter);

}