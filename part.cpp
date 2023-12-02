#include "part.h"
#include "fragment.h"
#pragma once
void Part::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   Position leftPos(position);
   Position rightPos(position);
   leftPos.addPixelsX(-40);
   rightPos.addPixelsX(40);
   Velocity vel(velocity);
   vel.addMetersX(1000);
   
   Fragment* fragments[7];

   //for (int i = 0; i <= 6; i++) {
   //   fragments[i] = new Fragment();
   //   Position pos(position);
   //   pos.addPixelsX(i);
   //   pos.addPixelsY(i);
   //   fragments[i]->setRotation(rotation.getAngle());
   //   fragments[i]->getPosition();
   //   fragments[i]->setVelocity(vel);
   //   orbitObjects.push_back(fragments[i]);
   //}


}

//reference for the moment

//void Part::draw(ogstream& gout) const {
//   //Instatiate Pixels
//   Position leftPos(position);
//   Position rightPos(position);
//   Position downPos(position);
//   Position upPos(position);
//   // Add Pixels to separate
//   leftPos.addPixelsX(-4);
//   rightPos.addPixelsX(4);
//   upPos.addPixelsY(4);
//   downPos.addPixelsY(-4);
//   if (name == "centerGPS")
//      gout.drawGPSCenter(position, rotation.getAngle());
//   if (name == "leftGPS")
//      gout.drawGPSLeft(position, rotation.getAngle(), leftPos);
//   if (name == "rightGPS")
//      gout.drawGPSRight(position, rotation.getAngle(), rightPos);
//
//   if (name == "Starlink") {
//      // draw each starlink part
//      gout.drawStarlinkBody(position, rotation.getAngle(), leftPos);
//      gout.drawStarlinkArray(position, rotation.getAngle(), leftPos);
//   }
//
//   if (name == "Hubble") {
//      gout.drawHubbleTelescope(position, rotation.getAngle(), upPos);
//      gout.drawHubbleComputer(position, rotation.getAngle(), downPos);
//      gout.drawHubbleLeft(position, rotation.getAngle(), leftPos);
//      gout.drawHubbleRight(position, rotation.getAngle(), rightPos);
//   }
//
//}