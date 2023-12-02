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

//Sputnik should only have fragments but i kept getting a compiler error
//without this idk
void Sputnik::breakApart(std::vector<OrbitObject*>& orbitObjects) const {

}