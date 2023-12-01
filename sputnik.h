#pragma once
#include "orbitObject.h"
class Sputnik :
    public OrbitObject
{

public:
   void draw(ogstream& gout) const override { gout.drawHubble(position, angle); }
};

