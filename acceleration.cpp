#include "acceleration.h"
#include <math.h>       // For PI
# define M_PI 3.14159265358979323846


/************************************************************************
 * DDX
 * Calculate the horizontal component of the acceleration based on the given
 * gravitational height and angle.
 *    INPUT  gravitational height   The current height above earth
 *           angle               Angle in radians
 *    OUTPUT                     Horizontal acceleration component
 ************************************************************************/
double Acceleration::ddx(double gravitationalHeight, double angle) {
   return gravitationalHeight * sin(angle);
}

/************************************************************************
 * DDY
 * Calculate the vertical component of the acceleration based on the given
 * gravitational height and angle.
 *    INPUT  gravitational height   The current height above earth
 *           angle               Angle in radians
 *    OUTPUT                     Vertical acceleration component
 ************************************************************************/
double Acceleration::ddy(double gravitationalHeight, double angle) {
   return gravitationalHeight * cos(angle);
}

/************************************************************************
 * GRAVITYH
 * Calculate the gravitational acceleration at a specific height above
 * a planet's surface.
 *    INPUT  gravity             Gravitational constant of the planet
 *           radius              Radius of the planet
 *           height              Height above the planet's surface
 *    OUTPUT                     Gravitational acceleration at the specified height
 ************************************************************************/
double Acceleration::gravityH(double gravity, double radius, double height) {
   return gravity * pow((radius / (radius + height)), 2.0);
}

/************************************************************************
 * DEGREETORADIAN
 * Convert an angle value from degrees to radians.
 *    INPUT  degree              Angle in degrees
 *    OUTPUT                     Angle in radians
 ************************************************************************/
double Acceleration::degreeToRadian(double degree) {
   // M_PI_2 wasnt working for me so i defined my own
   return degree * (M_PI / 180);
}