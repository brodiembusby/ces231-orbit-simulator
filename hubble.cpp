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
void Hubble::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   //Instatiate Pixels
   Position leftPos(position);
   Position rightPos(position);
   // Add Pixels to separate parts
   leftPos.addPixelsX(-4);
   rightPos.addPixelsX(4);


   //Hubble parts
   Hubble* HubbleTelescope = new Hubble();
   HubbleTelescope->setRotation(rotation.getAngle());
   HubbleTelescope->getPosition();
   HubbleTelescope->setVelocity(Velocity(velocity));

   Hubble* HubbleComputer = new Hubble();
   HubbleComputer->setRotation(rotation.getAngle());
   HubbleComputer->setPosition(rightPos);
   HubbleComputer->setVelocity(Velocity(velocity));

   Hubble* HubbleLeft = new Hubble();
   HubbleLeft->setRotation(rotation.getAngle());
   HubbleLeft->setPosition(leftPos);
   HubbleLeft->setVelocity(Velocity(velocity));

   Hubble* HubbleRight = new Hubble();
   HubbleRight->setRotation(rotation.getAngle());
   HubbleRight->setPosition(leftPos);
   HubbleRight->setVelocity(Velocity(velocity));

   //Add to Vector
   orbitObjects.push_back(HubbleRight);
   orbitObjects.push_back(HubbleLeft);
   orbitObjects.push_back(HubbleComputer);
   orbitObjects.push_back(HubbleTelescope);



}