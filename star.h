/***********************************************************************
 * Header File:
 *    Star : A star on the screen
 * Author:
 *    Aaron Fox
 * Summary:
 *    Everything we need to know about a star in the sky
 ************************************************************************/

#pragma once

#include "position.h"

class Star
{
private:
   Position position;
   unsigned char phase;

public:
   Star(const Position& position)
      : position(position), phase(0)
   {}

   Position& getPosition() { return position; }
   unsigned char getPhase() { return phase; }

   void setPosition(const Position& position) { this->position = position; }
};

