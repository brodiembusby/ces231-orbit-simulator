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
class Satellite :
    public OrbitObject
{

public:

   void update(const double time) override;  // updates rotation on object
};

