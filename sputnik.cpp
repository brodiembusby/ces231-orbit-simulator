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
   const int fragmentCount = 4; // Number of fragments
   const int spacing = 90; // Spacing in degrees (for a circular pattern)

   for (int i = 0; i < fragmentCount; i++)
   {
      orbitObjects.push_back(createFragment(spacing * i));
   }
}