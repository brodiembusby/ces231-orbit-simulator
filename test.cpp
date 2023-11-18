/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testAcceleration.h"
#include "testRotation.h"
#include "testVector2D.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestPosition().run();
   TestAcceleration().run();
   TestRotation().run();
   TestVector2D().run();
   cout << "All test pass";
}


// function to resolve floating point differences
bool closeEnough(double value, double test, double tolerance) {
   double difference = value - test;
   return(difference >= -tolerance) && (difference <= tolerance);
}
