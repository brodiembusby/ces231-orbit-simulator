#pragma once
#include "orbitObject.h"
class Part : public OrbitObject
{
public:
   
   void draw(ogstream& gout) const override;
   void breakApart(std::vector<OrbitObject*>& orbitObjects, OrbitObject& obj);


};

