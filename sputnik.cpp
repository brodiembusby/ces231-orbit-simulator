/***********************************************************************
 * Source File:
 *    starlink : Methods related to starlink satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return sputnik fragments
 ************************************************************************/


#pragma once
#include "sputnik.h"
#include "fragment.h"
//Sputnik should only have fragments but i kept getting a compiler error
//without this idk
void Sputnik::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

   Velocity vel(velocity);
   vel.addMetersX(1000);

   Fragment* fragments[3];
   int spacing = 10;
   for (int i = 0; i <= 2; i++) {
      fragments[i] = new Fragment();
      Position pos(position);
      pos.addPixelsX(i += spacing);
      pos.addPixelsY(i -= spacing);
      fragments[i]->setRotation(rotation.getAngle());
      fragments[i]->setPosition(pos);
      fragments[i]->setVelocity(vel);
      orbitObjects.push_back(fragments[i]);
   }

}