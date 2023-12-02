#pragma once
#include "orbitObject.h"
class Fragment : public OrbitObject
{
private:
   double radius;

public:
   Fragment(double radius) : radius(radius){}

   const double getRadius() const override { return radius; }
   void draw(ogstream& gout) const override { gout.drawFragment(position, rotation.getAngle()); }
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override; 
};

