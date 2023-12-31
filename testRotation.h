/***********************************************************************
 * Header File:
 *    Test Rotation : Test the Rotation class
 * Author:
 *    Cameron Lybbert
 * Summary:
 *    All the unit tests for Rotation
 ************************************************************************/

#pragma once

 /*********************************************
  * TEST Rotation
  * Test suite for the Rotation class.
  *********************************************/
class TestRotation
{
public:
   void run();

private:
   void testUpdateSmallTime();
   void testUpdateBigTime();
   void testSetFromRotation();
   void testSetAngle();
   void testSetSpeed();
};

