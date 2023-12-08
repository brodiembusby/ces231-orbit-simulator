/***********************************************************************
 * Header File:
 *    Fragment : Fragment piece broken off satellite.
 * Author:
 *    Aaron Fox
 * Summary:
 *    The class containing all functionality for fragments.
 ************************************************************************/

#pragma once
#include "orbitObject.h"
#include "acceleration.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include <vector>

 /*******************************
  * Fragment
  * A piece broken off a destroyed satellite.
  ********************************/
class Fragment : public OrbitObject
{
private:
   int aliveTime;
   int deadTime;

protected:
   void updateCallback(Acceleration& acceleration) override;  // Alive countdown.

public:
   Fragment() : aliveTime(0), deadTime(0), OrbitObject() {
      deadTime = (int)getRandomDouble(50, 100);
   }

   const double getRadius() const override { return 2; }
   void draw(ogstream& gout) const override { gout.drawFragment(position, rotation.getAngle()); }
};
