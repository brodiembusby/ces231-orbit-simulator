/***********************************************************************
 * Source File:
 *    testAcceleration : Acceleration due to gravity and velocity
 * Author:
 *    Brodie Busby
 * Summary:
 *    A file to test methods in Acceleration class
 ************************************************************************/

#include "testAcceleration.h"  // For testAcceleration header
#include "acceleration.h"  // For acceleration
#include "assert.h"        // For asserts
#define _USE_MATH_DEFINES  // For PI
#include <math.h>          // For PI

// The asserts i believe will not be exact I read something about epsilon values but haven't looked at it
// in depth


void testAcceleration::run()
{
   testGravitySeaLevel();
   testGravity100k();
   testGravtiyAngleUp();
   testGravityAngle45();
   testGravityComponentStraightUpSeaLevel();
   testGravityComponentDiagonal();
}


void testAcceleration::testGravitySeaLevel() {

   // SETUP
   Acceleration a;

   //EXERCISE
   double gravity = a.getGravity(6378000);
   //VERIFY
   assert(gravity == 9.80665);
}
void testAcceleration::testGravity100k() {
 
   // SETUP
   Acceleration a;

   //EXERCISE
   double gravity = a.getGravity(6478000);
   //VERIFY
   assert(gravity == 9.5);
}
void testAcceleration::testGravtiyAngleUp() {
  
   // SETUP
   Acceleration a;
   Position pos(0,6378000);
   //EXERCISE
   double gravity = a.getGravityAngle(pos);
   double testPi = (-M_PI / 2);
   //VERIFY
   assert(gravity == testPi);
}
void testAcceleration::testGravityAngle45() {
 
   // SETUP
   Acceleration a;
   Position pos(-6478000, 6478000);
   //EXERCISE
   double gravity = a.getGravityAngle(pos);
   double testPi = (-M_PI / 4);
   //VERIFY
   assert(gravity == testPi);
}
void testAcceleration::testGravityComponentStraightUpSeaLevel() {
   
   // SETUP
   Position pos(0, 6378000);

   //EXERCISE
   Acceleration a = a.getGravityComponent(pos);
   Acceleration testAcc(0, -9.80665);
   //VERIFY
   assert(a == testAcc);

}
void testAcceleration::testGravityComponentDiagonal() {
   // SETUP
   Position pos(-6478000, 6478000);

   //EXERCISE
   Acceleration a = a.getGravityComponent(pos);
   Acceleration testAcc(3.361, -3.361);
   //VERIFY
   assert(a == testAcc);
}
