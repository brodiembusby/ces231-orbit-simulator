/***********************************************************************
 * Header File:
 *    Test Vector2D : Test the Vector2D class
 * Author:
 *   Aaron Fox
 * Summary:
 *    All the unit tests for Vector2D
 ************************************************************************/

#pragma once

 /*********************************************
  * TEST Vector2D
  * Test suite for the Vector2D class.
  *********************************************/
class TestVector2D
{
public:
   void run() const;

private:
   void testHorizontalComponentAngle() const;
   void testHoriztontalComponentMagnitude() const;
   void testVerticalComponentAngle() const;
   void testverticalComponentMagnitude() const;
   void testAssignment() const;
   void testIncrement() const;
   void testComparison() const;
   void testComparisonUnequal() const;
};

