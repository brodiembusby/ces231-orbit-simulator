/***********************************************************************
 * Source File:
 *    testVector2D :testing for Base class for any 2-dimensional component.
 * Author:
 *    Brodie Busby, Aaron Fox
 * Summary:
 *    A file to test methods in Vector2D class
 ************************************************************************/

#include "testAcceleration.h"	// For testAcceleration header
#include "vector2D.h"			// For Vector2D
#include "position.h"			// For Position (assignment/increment)
#include "assert.h"				// For asserts
#define _USE_MATH_DEFINES		// For PI
#include <math.h>				   // For PI

#include "testVector2D.h"

void TestVector2D::run() const
{
   testHorizontalComponentAngle();
   testHoriztontalComponentMagnitude();
   testVerticalComponentAngle();
   testverticalComponentMagnitude();
   testAssignment();
   testIncrement();
   testComparison();
   testComparisonUnequal();
}

void TestVector2D::testHorizontalComponentAngle() const {
   // SETUP

   //EXERCISE
   auto component = Vector2D::getHorizontalComponent(1, M_PI / 2);

   //VERIFY
   assert(component == 0);
}

void TestVector2D::testHoriztontalComponentMagnitude() const {
   // SETUP

   //EXERCISE
   auto component = Vector2D::getHorizontalComponent(12, M_PI);

   //VERIFY
   assert(component == -12);
}

void TestVector2D::testVerticalComponentAngle() const {
   // SETUP

   //EXERCISE
   auto component = Vector2D::getVerticalComponent(1, M_PI / 2);

   //VERIFY
   assert(component == 1);
}

void TestVector2D::testverticalComponentMagnitude() const {
   // SETUP

   //EXERCISE
   auto component = Vector2D::getVerticalComponent(12, M_PI / 4);

   //VERIFY
   assert(component == 12 * sin(M_PI / 4));
}

void TestVector2D::testAssignment() const {
   // SETUP
   Position pos1(0, 0);
   Position pos2(1, 2);

   //EXERCISE
   pos1 = pos2;

   //VERIFY
   assert(&pos1 != &pos2);
}

void TestVector2D::testIncrement() const {
   // SETUP
   Position pos1(0, 0);
   Position pos2(1, 2);

   //EXERCISE
   pos1 += pos2;

   //VERIFY
   assert(pos1 == pos2);
}

void TestVector2D::testComparison() const {
   // SETUP
   Position pos1(1, 2);
   Position pos2(1, 2);

   //EXERCISE
   bool equal = pos1 == pos2;

   //VERIFY
   assert(equal);
}

void TestVector2D::testComparisonUnequal() const {
   // SETUP
   Position pos1(1, 2);
   Position pos2(1, 2);

   //EXERCISE
   bool equal = pos1 == pos2;

   //VERIFY
   assert(equal);
}