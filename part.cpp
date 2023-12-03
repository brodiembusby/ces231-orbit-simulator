#include "part.h"
#include "fragment.h"
#pragma once
void Part::breakApart(std::vector<OrbitObject*>& orbitObjects) const {
	double angle = fragmentCount / 360.0;
	for (int i = 0; i < fragmentCount; i++)
	{
		orbitObjects.push_back(createFragment(angle * i));
	}
}
