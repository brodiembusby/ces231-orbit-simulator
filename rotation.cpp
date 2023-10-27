#include "rotation.h"
#include "uiDraw.h"     // for RANDOM and DRAW*

#define PI 3.141592653589793238462

void Rotation::update(double angle)
{
   this->angle += angle;
}

void Rotation::updateEarth()
{
   double td = 24 * 60;
   double angle = -(2 * PI / 30) * (td / 86400);
   update(angle);
}

void Rotation::updateSatellite()
{
   double angle = random(.1, 1.0);
   update(angle);
}