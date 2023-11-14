/***********************************************************************
 * Source File:
 *    testRotation : The rotation of an object
 * Author:
 *    Cameron Lybbert
 * Summary:
 *    A file to test methods in Rotation class
 ************************************************************************/
#include "testRotation.h"
#include "rotation.h"
#include "assert.h"        // For asserts
#define _USE_MATH_DEFINES  // For PI
#include <math.h>          // For PI

void TestRotation::run()
{
   testUpdateSmallTime();
   testUpdateBigTime();
   testSetFromRotation();
   testSetAngle();
   testSetSpeed();
}

void TestRotation::testUpdateSmallTime()
{
   // SETUP
   Rotation EarthRot;
   EarthRot.angle = .03;
   EarthRot.speed = 3;
   double time = 4;

   // EXERCISE
   EarthRot.update(time);

   // VERIFY
   assert(EarthRot.getAngle() == 12.03);

   // TEARDOWN
}
void TestRotation::testUpdateBigTime()
{
   // SETUP
   Rotation EarthRot;
   EarthRot.angle = .03;
   EarthRot.speed = 3;
   double time = 30;

   // EXERCISE
   EarthRot.update(time);

   // VERIFY
   assert(EarthRot.getAngle() == 90.03);

   // TEARDOWN
}
void TestRotation::testSetFromRotation()
{
   // SETUP
   Rotation EarthRot;
   EarthRot.angle = .03;
   EarthRot.speed = 3;

   // EXERCISE
   Rotation GPS(EarthRot);

   // VERIFY

   assert(GPS.getAngle() == EarthRot.getAngle());
   assert(GPS.getAngle() == .03);
   assert(GPS.getSpeed() == EarthRot.getSpeed());
   assert(GPS.getSpeed() == 3);



   // TEARDOWN
}
void TestRotation::testSetAngle()
{
   // SETUP
   Rotation EarthRot;
   double angle = 4;

   // EXERCISE
   EarthRot.setAngle(angle);

   // VERIFY
   assert(EarthRot.getAngle() == angle);

   // TEARDOWN
}
void TestRotation::testSetSpeed()
{
   // SETUP
   Rotation EarthRot;
   EarthRot.angle = .03;
   EarthRot.speed = 3;
   double speed = 43;

   // EXERCISE
   EarthRot.setSpeed(speed);

   // VERIFY
   assert(EarthRot.getSpeed() == speed);

   // TEARDOWN
}
