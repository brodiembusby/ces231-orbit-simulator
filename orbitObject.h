/***********************************************************************
 * Source File:
 *    Orbit Object : Any object that exhibits orbital behavior.
 * Author:
 *    Aaron Fox
 * Summary:
 *    The base class for objects that will orbit around the Earth.
 ************************************************************************/

#pragma once

#include "position.h"

class OrbitObject
{
private:
   Position position;
   //Velocity velocity;

public:
   Position& getPosition() { return position; }

   void setPosition(const Position& position) { this->position = position; }
};

