/***********************************************************************
 * Source File:
 *    Sputnik : Methods related to Sputnik satellite
 * Author:
 *    Brodie Busby
 * Summary:
 *    Derived class of OrbitObject. Methods that return sputnik fragments
 ************************************************************************/

#pragma once

#include "sputnik.h"
#include "fragment.h"

 /************************************************************************
 * BREAK APART
 * Called when the satellite collides with something.
 *    INPUT  orbitObjects      List of all active orbit objects in the same during this frame.
 *                             Passed by reference to allow modification.
 ************************************************************************/
void Sputnik::breakApart(std::vector<OrbitObject*>& orbitObjects) const {
   const int fragmentCount = 4; // Number of fragments
   const int spacing = 90; // Spacing in degrees (for a circular pattern)

   for (int i = 0; i < fragmentCount; i++)
   {
      orbitObjects.push_back(createFragment(spacing * i));
   }
}