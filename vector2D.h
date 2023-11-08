/***********************************************************************
 * Header File:
 *    Vector 2D : The base class for a 2D vectory (x- and y-components).
 * Author:
 *    Aaron Fox
 * Summary:
 *    Contains basic data members and operations for supporting 2D mathematics.
 ************************************************************************/

#pragma once

class Vector2D
{
private:
   static double metersFromPixels;

protected:
   double x;
   double y;

public:
   // constructors
   Vector2D() : x(0.0), y(0.0) {}
   Vector2D(double x, double y);
   Vector2D(const Vector2D& pt) : x(pt.x), y(pt.y) {}
   Vector2D& operator = (const Vector2D& pt);
   bool operator == (const Vector2D& pt);
   void operator += (const Vector2D& pt);

   // getters
   double getMetersX()       const { return x; }
   double getMetersY()       const { return y; }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }

   // setters
   void setMeters(double xMeters, double yMeters) { x = xMeters; y = yMeters; }
   void setMetersX(double xMeters) { x = xMeters; }
   void setMetersY(double yMeters) { y = yMeters; }
   void setPixelsX(double xPixels) { x = xPixels * metersFromPixels; }
   void setPixelsY(double yPixels) { y = yPixels * metersFromPixels; }
   void addMetersX(double dxMeters) { setMetersX(getMetersX() + dxMeters); }
   void addMetersY(double dyMeters) { setMetersY(getMetersY() + dyMeters); }
   void addPixelsX(double dxPixels) { setPixelsX(getPixelsX() + dxPixels); }
   void addPixelsY(double dyPixels) { setPixelsY(getPixelsY() + dyPixels); }

   // component operations
   static double getHorizontalComponent(const double magnitude, const double angle);
   static double getVerticalComponent(const double magnitude, const double angle);

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }
};

