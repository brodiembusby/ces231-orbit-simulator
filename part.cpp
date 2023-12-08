/***********************************************************************
 * Source File:
 *    Part : A large part of a broken satellite
 * Author:
 *    Aaron Fox
 * Summary:
 *    Functions that make parts work
 ************************************************************************/

#pragma once

#include "part.h"
#include "fragment.h"

 /************************************************************************
 * BREAK APART
 * Called when the part collides with something.
 * some time.
 *    INPUT  orbitObjects           All orbit objects active in the scene this frame.
 *												Passed by reference to allow modification.
 ************************************************************************/
void Part::breakApart(std::vector<OrbitObject*>& orbitObjects) const {
	double angle = fragmentCount / 360.0;
	for (int i = 0; i < fragmentCount; i++)
	{
		orbitObjects.push_back(createFragment(angle * i));
	}
}
