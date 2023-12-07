#include "fragment.h"

#pragma once


/************************************************************************
* UPDATE CALLBACK
* Method called once per update. In this case, the fragment expires after
* some time.
*    INPUT  _                The acceleration for this frame (unused).
************************************************************************/
void Fragment::updateCallback(Acceleration& _) {
   // Increase lifetime and destroy if it's too old.
   aliveTime++;
   if (aliveTime >= deadTime)
      isDestroyed = true;
}