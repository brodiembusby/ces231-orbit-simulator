/***********************************************************************
 * Source File:
 *    Hubble : Methods related to hubble satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return hubble parts
 ************************************************************************/

#include "hubble.h"
#include "part.h"

 /************************************************************************
 * BREAK APART
 * Called when the part collides with something.
 * some time.
 *    INPUT  orbitObjects           All orbit objects active in the scene this frame.
 *												Passed by reference to allow modification.
 ************************************************************************/
void Hubble::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   //Instatiate Positions
   Position leftPos(position);
   Position rightPos(position);
   Position upPos(position);
   Position downPos(position);
   // Add Pixels to separate parts
   leftPos.addPixelsX(-20);
   rightPos.addPixelsX(20);
   upPos.addPixelsY(-20);
   downPos.addPixelsY(20);
   Velocity vel(velocity);
   vel.addMetersX(1000);

   //Hubble parts
   HubbleTelescope* TelscopeHubble = new HubbleTelescope();
   TelscopeHubble->setRotation(rotation.getAngle());
   TelscopeHubble->setPosition(upPos);
   TelscopeHubble->setVelocity(Velocity(vel));

   HubbleComputer* ComputerHubble = new HubbleComputer();
   ComputerHubble->setRotation(rotation.getAngle());
   ComputerHubble->setPosition(downPos);
   ComputerHubble->setVelocity(Velocity(vel));

   HubbleLeft* leftHubble = new HubbleLeft();
   leftHubble->setRotation(rotation.getAngle());
   leftHubble->setPosition(leftPos);
   leftHubble->setVelocity(Velocity(vel));

   HubbleRight* rightHubble = new HubbleRight();
   rightHubble->setRotation(rotation.getAngle());
   rightHubble->setPosition(rightPos);
   rightHubble->setVelocity(Velocity(vel));

   //Add to Vector
   orbitObjects.push_back(rightHubble);
   orbitObjects.push_back(leftHubble);
   orbitObjects.push_back(ComputerHubble);
   orbitObjects.push_back(TelscopeHubble);



}