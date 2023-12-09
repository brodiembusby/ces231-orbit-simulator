/***********************************************************************
 * Source File:
 *    Fragment : Small fragment created from destroyed satellite.
 * Author:
 *    Aaron Fox
 * Summary:
 *    Functions that make a fragment work.
 ************************************************************************/

#include "fragment.h"

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