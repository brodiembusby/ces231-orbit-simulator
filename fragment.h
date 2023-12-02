#pragma once
#include "orbitObject.h"
class Fragment : public OrbitObject
{
public:

   void draw(ogstream& gout) const override { gout.drawFragment(position, rotation.getAngle()); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override; 
};

