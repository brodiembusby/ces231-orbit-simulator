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
 * Vector2D : INCREMENT
 * Adds the components
 *****************************************/
void Vector2D::operator += (const Vector2D& pt)
{
   x += pt.x;
   y += pt.y;
}

double Vector2D::getHorizontalComponent(const double magnitude, const double angle)
{
   return magnitude * std::cos(angle);
}

double Vector2D::getVerticalComponent(const double magnitude, const double angle)
{
   return magnitude * std::sin(angle);
}