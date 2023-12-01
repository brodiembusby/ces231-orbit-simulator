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

   Star() { pos = Position(random(0, 100), random(0, 100)); phase = random(0, 50); };
   Star(Position pos, unsigned char phase) : pos(pos), phase(phase) {};

   
   void draw(ogstream& gout) const { gout.drawStar(pos, phase); }

   void update() { phase++; }
};

