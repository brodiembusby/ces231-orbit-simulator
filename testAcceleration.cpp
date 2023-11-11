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


void TestAcceleration::run()
{
   testGravitySeaLevel();
   testGravity100k();
   testGravtiyAngleUp();
   testGravityAngle45();
   testGravityComponentStraightUpSeaLevel();
   testGravityComponentDiagonal();
}

/*
   TEST GRAVITY SEA LEVEL
   Tests that gravity is accurate at sea level.
*/
void TestAcceleration::testGravitySeaLevel() {

   // SETUP
   Acceleration a;

   //EXERCISE
   double gravity = a.getGravity(6378000);
   //VERIFY
   assert(gravity == 9.80665);
}

/*
   TEST GRAVITY 100K
   Tests gravity at 100km altitude to verify it's using the correct algorithm.
*/
void TestAcceleration::testGravity100k() {
 
   // SETUP
   Acceleration a;

   //EXERCISE
   double gravity = a.getGravity(6478000);
   //VERIFY
   assert(gravity == 9.5);
}

/*
   TEST GRAVITY ANGLE UP
   Tests the angle of gravity at straight up (i.e. gravity is pulling straight down).
*/
void TestAcceleration::testGravtiyAngleUp() {
  
   // SETUP
   Acceleration a;
   Position pos(0,6378000);
   //EXERCISE
   double gravity = a.getGravityAngle(pos);
   double testPi = (-M_PI / 2);
   //VERIFY
   assert(gravity == testPi);
}

/*
   TEST GRAVITY ANGLE 45
   Tests the angle of gravity at a 45 degree angle.
*/
void TestAcceleration::testGravityAngle45() {
 
   // SETUP
   Acceleration a;
   Position pos(-6478000, 6478000);
   //EXERCISE
   double gravity = a.getGravityAngle(pos);
   double testPi = (-M_PI / 4);
   //VERIFY
   assert(gravity == testPi);
}

/*
   TEST GRAVITY COMPONENT STRAIGHT UP SEA LEVEL
   Tests the gravity component at sea level straight up (i.e. gravity is pulling straight down).
*/
void TestAcceleration::testGravityComponentStraightUpSeaLevel() {
   
   // SETUP
   Position pos(0, 6378000);

   //EXERCISE
   Acceleration a = a.getGravityComponent(pos);
   Acceleration testAcc(0, -9.80665);
   //VERIFY
   assert(a == testAcc);

}

/*
   TEST GRAVITY COMPONENT DIAGONAL
   Tests gravity component at 100km at a 45 degree angle.
*/
void TestAcceleration::testGravityComponentDiagonal() {
   // SETUP
   Position pos(-6478000, 6478000);

   //EXERCISE
   Acceleration a = a.getGravityComponent(pos);
   Acceleration testAcc(3.361, -3.361);
   //VERIFY
   assert(a == testAcc);
}
