#include "fragment.h"

#pragma once

void Fragment::updateCallback(Acceleration& acceleration) {
   // Increase lifetime and destroy if it's too old.
   aliveTime++;
   if (aliveTime >= deadTime)
      isDestroyed = true;
}