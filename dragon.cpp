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
#include "part.h"
/************************************************************************
* breakApart
*    Takes
*    INPUT      gout   graphical output 
*               dragon dragon object       
************************************************************************/
void Dragon::breakApart(std::vector<OrbitObject*>& orbitObjects) const {


   // Add Pixels to separate parts
   Position leftPos(position);
   Position rightPos(position);
   Position centerPos(position);
   // Add Pixels to separate parts
   leftPos.addPixelsX(-4);
   rightPos.addPixelsX(4);
   centerPos.addPixelsY(20);
   
   //CrewDragon parts
   CrewDragonCenter* centerDragon = new CrewDragonCenter();
   centerDragon->setRotation(rotation.getAngle());
   centerDragon->setPosition(centerPos);
   centerDragon->setVelocity(Velocity(velocity));

   CrewDragonLeft* leftDragon = new CrewDragonLeft();
   leftDragon->setRotation(rotation.getAngle());
   leftDragon->setPosition(leftPos);
   leftDragon->setVelocity(Velocity(velocity));

   CrewDragonRight* DragonRight = new CrewDragonRight();
   DragonRight->setRotation(rotation.getAngle());
   DragonRight->setPosition(rightPos);
   DragonRight->setVelocity(Velocity(velocity));

   //Add to Vector
   orbitObjects.push_back(centerDragon);
   orbitObjects.push_back(leftDragon);
   orbitObjects.push_back(DragonRight);

}