#pragma once
#include "orbitObject.h"
class Fragment :public OrbitObject
{
public:
   void draw(ogstream gout) { gout.drawFragment(position,rotation.getAngle());} 
};

