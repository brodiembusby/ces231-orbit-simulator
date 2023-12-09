/***********************************************************************
 * Header File:
 *    Satellite : Satellite for objects
 * Author:
 *    Cameron Lybbert
 * Summary:
 *    A class holding all items need for the satellites.
 ************************************************************************/

#pragma once

#include "orbitObject.h"

 /*********************************************
  * Satellite
  * Base class for all satellites.
  *********************************************/
class Satellite : public OrbitObject
{
public:

   void update(const double time) override;  // updates rotation on object
};

