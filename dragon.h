#pragma once
#include "orbitObject.h"
class Dragon :
    public OrbitObject
{
public:
   void draw(ogstream& gout) const override { gout.drawCrewDragon(position, angle); }
};

