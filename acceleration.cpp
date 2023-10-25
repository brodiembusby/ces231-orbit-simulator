#include "acceleration.h"
#include <math.h> // for sin and cos



// ddx
double Acceleration::horizontalComponentOfAcceleration(double totalAcceleration, double angle) {
   return totalAcceleration * sin(angle);
}
//ddy
double Acceleration::verticalComponentOfAcceleration(double totalAcceleration, double angle) {
   return totalAcceleration * cos(angle);
}