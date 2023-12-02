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
#include <cmath> // Include cmath for trigonometric functions
#include <cstdlib> // Include for random number generation

void Sputnik::breakApart(std::vector<OrbitObject*>& orbitObjects) const {
   Velocity vel(velocity);
   vel.addMetersX(1000);

   const int fragmentCount = 5; // Number of fragments
   Fragment* fragments[fragmentCount];
   const int spacing = 100; // Spacing in degrees (for a circular pattern)

   for (int i = 0; i < fragmentCount; i++) {
      fragments[i] = new Fragment();
      Position pos(position);

      // Calculate the position for each fragment in a circular pattern
      float angle = (spacing * i) * (M_PI / 180.0); // Convert degrees to radians
      float xOffset = cos(angle) * 10; // 10 is the radius of the circle
      float yOffset = sin(angle) * 10;

      pos.addPixelsX(xOffset);
      pos.addPixelsY(yOffset);

      // Generate a random rotation for each fragment
      float randomRotation = static_cast<float>(rand() % 360); // Random angle between 0 and 359 degrees

      fragments[i]->setRotation(randomRotation);
      fragments[i]->setPosition(pos);
      fragments[i]->setVelocity(vel);
      orbitObjects.push_back(fragments[i]);
   }
}