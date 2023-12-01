#pragma once
#include "orbitObject.h"
class Starlink :
    public OrbitObject
{
public:
   void draw(ogstream& gout) const override { gout.drawStarlink(position, angle); }
};

