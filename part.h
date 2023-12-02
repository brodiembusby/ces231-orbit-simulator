#pragma once
#include "orbitObject.h"
#include <functional>

class Part : public OrbitObject
{
public:
  
   //ogstream DrawFunctionType = std::function<void( Position, Rotation)>;

   void draw(ogstream& gout) const override { gout.drawCrewDragonCenter(position, rotation.getAngle()); };
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;


};

