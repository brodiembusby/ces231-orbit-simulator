/************************************
* Header File:
*     Star.h
* Authors:
*     Cameron Lybbert
* Description:
*     This handles all the stars in the world.
***************************************/
#pragma once
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include <iostream>
class Star
{
private:
   Position pos;
   unsigned char phase;

public:

   // The defualt gives a random position and phase.
   Star() { pos = Position(random(0, 100), random(0, 100)); phase = random(0, 50); };

   // We can set both.
   Star(Position pos, unsigned char phase) : pos(pos), phase(phase) {};

   // Draws the star.
   void draw(ogstream& gout) const { gout.drawStar(pos, phase); }

   // Update just changes the phase.
   void update() { phase++; }
};

