#include "bullet.h"

void Bullet::updateCallback(Acceleration& acceleration) {
   // Remove gravity.
   acceleration.setMeters(0, 0);

   // Increase lifetime and destroy if it's too old.
   aliveTime++;
   if (aliveTime >= LIFETIME)
      isDestroyed = true;
}