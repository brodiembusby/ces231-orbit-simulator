/***********************************************************************
 * Source File:
 *    Vector 2D: Base class for any 2-dimensional component.
 * Author:
 *    Aaron Fox
 * Summary:
 *    Contains basic members and operations for 2D math.
 ************************************************************************/

#include "vector2D.h"
#include <cmath>

Vector2D::Vector2D(double x, double y) : x(0.0), y(0.0)
{
   setMetersX(x);
   setMetersY(y);
}

/******************************************
 * Vector2D : ASSIGNMENT
 * Assign a point
 *****************************************/
Vector2D& Vector2D::operator = (const Vector2D& pt)
{
   x = pt.x;
   y = pt.y;
   return *this;
}

/******************************************
 * Vector2D : Comparison
 * compares two points
 *****************************************/
bool Vector2D::operator == (const Vector2D& pt)
{
   return this->x == pt.x && this->y == pt.y;
}
/******************************************
 * Vector2D : INCREMENT
 * Adds the components
 *****************************************/
void Vector2D::operator += (const Vector2D& pt)
{
   x += pt.x;
   y += pt.y;
}

/************************************************************************
 * GET HORIZONTAL COMPONENT
 * Calculates the horizontal component of a vector.
 *    INPUT  magnitude           The length of the vector.
 *    INPUT  angle               The angle of the vector.
 *    OUTPUT                     The horizontal component of the vector.
 ************************************************************************/
double Vector2D::getHorizontalComponent(const double magnitude, const double angle)
{
   return magnitude * std::cos(angle);
}

/************************************************************************
 * GET VERTICAL COMPONENT
 * Calculates the vertical component of a vector.
 *    INPUT  magnitude           The length of the vector.
 *    INPUT  angle               The angle of the vector.
 *    OUTPUT                     The vertical component of the vector.
 ************************************************************************/
double Vector2D::getVerticalComponent(const double magnitude, const double angle)
{
   return magnitude * std::sin(angle);
}