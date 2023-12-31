/***********************************************************************
 * Source File:
 *    Bullet : Bullet fired from the spaceship
 * Author:
 *    Aaron Fox, Cameron Lybbert
 * Summary:
 *    Functions that make bullets work
 ************************************************************************/

#include "bullet.h"

/************************************************************************
 * UPDATE CALLBACK
 * Called once per frame. In this case, we use it to negate gravity and die after some time.
 *    INPUT  acceleration                The acceleration for this frame.
 ************************************************************************/
void Bullet::updateCallback(Acceleration& acceleration) {
   // Remove gravity.
   acceleration.setMeters(0, 0);

   // Increase lifetime and destroy if it's too old.
   aliveTime++;
   if (aliveTime >= LIFETIME)
      isDestroyed = true;
}