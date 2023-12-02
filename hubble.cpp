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
#include "part.h"
void Hubble::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   //Instatiate Positions
   Position leftPos(position);
   Position rightPos(position);
   Position upPos(position);
   Position downPos(position);
   // Add Pixels to separate parts
   leftPos.addPixelsX(-4);
   rightPos.addPixelsX(4);
   upPos.addPixelsX(-4);
   downPos.addPixelsX(4);

   //Hubble parts
   HubbleTelescope* TelscopeHubble = new HubbleTelescope();
   TelscopeHubble->setRotation(rotation.getAngle());
   TelscopeHubble->setPosition(upPos);
   TelscopeHubble->setVelocity(Velocity(velocity));

   HubbleComputer* ComputerHubble = new HubbleComputer();
   ComputerHubble->setRotation(rotation.getAngle());
   ComputerHubble->setPosition(downPos);
   ComputerHubble->setVelocity(Velocity(velocity));

   HubbleLeft* leftHubble = new HubbleLeft();
   leftHubble->setRotation(rotation.getAngle());
   leftHubble->setPosition(leftPos);
   leftHubble->setVelocity(Velocity(velocity));

   HubbleRight* rightHubble = new HubbleRight();
   rightHubble->setRotation(rotation.getAngle());
   rightHubble->setPosition(rightPos);
   rightHubble->setVelocity(Velocity(velocity));

   //Add to Vector
   orbitObjects.push_back(rightHubble);
   orbitObjects.push_back(leftHubble);
   orbitObjects.push_back(ComputerHubble);
   orbitObjects.push_back(TelscopeHubble);



}