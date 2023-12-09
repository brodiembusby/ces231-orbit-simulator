/***********************************************************************
 * Source File:
 *    Satellite : An object in space
 * Author:
 *    Cameron Lybbert
 * Summary:
 *    Methods relating to satellite
 ************************************************************************/

#include "satellite.h"

 /************************************************************************
 * UPDATE
 * Called once per frame. In this case, Satellite will modify and update its rotation.
 *    INPUT  time           The time that has passed since the last frame.
 ************************************************************************/
void Satellite::update(const double time)
{
   OrbitObject::update(time);

   // If we are not rotating slowly, rotate slowly.
   if (rotation.getSpeed() == 0)
   {
      // assign it a random starting angle.
      rotation.setAngle(random(0, 180));

      // assign it a slow rotating speed.
      rotation.setSpeed(.0001);
   }

   // Has a random chance to make a satellite start rotating .1 faster 
   // causing them to randomly go "out of control".
   if (random(0, 4000) == random(0, 4000))
   {
      double speed = rotation.getSpeed();
      rotation.setSpeed(speed += .001);
   }

   // Update the rotation.
   rotation.update(TIME);
}