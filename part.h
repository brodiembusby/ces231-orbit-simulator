/***********************************************************************
 * Header File:
 *    Part : Classes related to all parts
 * Author:
 *    Brodie Busby
 * Summary:
 *   All Classes with draw functions for various parts
 ************************************************************************/

#pragma once

#include "orbitObject.h"
#include <functional>

 /*******************************
  * PART
  * Base class for a large part of a destroyed satellite.
  ********************************/
class Part : public OrbitObject
{
private:
   int fragmentCount;
public:
   Part(int fragmentCount) : fragmentCount(fragmentCount), OrbitObject() {}

   void draw(ogstream& gout) const override {  };
   virtual void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;
};

/*******************************
 * GPS Parts
 ******************************/
class GPSRight : public Part
{
public:
   GPSRight() : Part(3) {}
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawGPSRight(position, rotation.getAngle(), rightPos); }
   const double getRadius() const override { return 2; }
};

class GPSLeft : public Part
{
public:
   GPSLeft() : Part(3) {}
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawGPSLeft(position, rotation.getAngle(), leftPos); }
   const double getRadius() const override { return 2; }
};

class GPSCenter : public Part
{
public:
   GPSCenter() : Part(3) {}
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(10);  gout.drawGPSCenter(position, rotation.getAngle()); }
   const double getRadius() const override { return 2; }
};

/*******************************
 * Hubble Parts
 ******************************/
class HubbleRight : public Part
{
public:
   HubbleRight() : Part(2) {}
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawHubbleRight(position, rotation.getAngle(), rightPos); }
   const double getRadius() const override { return 2; }
};

class HubbleLeft : public Part
{
public:
   HubbleLeft() : Part(2) {}
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawHubbleLeft(position, rotation.getAngle(), leftPos); }
   const double getRadius() const override { return 2; }
};

class HubbleComputer : public Part
{
public:
   HubbleComputer() : Part(2) {}
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(10);  gout.drawHubbleComputer(position, rotation.getAngle(), upPos); }
   const double getRadius() const override { return 2; }
};

class HubbleTelescope : public Part
{
public:
   HubbleTelescope() : Part(3) {}
   void draw(ogstream& gout) const override { Position downPos; downPos.addPixelsY(-10); gout.drawHubbleTelescope(position, rotation.getAngle(), downPos); }
   const double getRadius() const override { return 2; }
};

/*******************************
 * Starlink Parts
 ******************************/
class StarlinkBody : public Part
{
public:
   StarlinkBody() : Part(3) {}
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawStarlinkArray(position, rotation.getAngle(), rightPos); }
   const double getRadius() const override { return 2; }
};

class StarlinkArray : public Part
{
public:
   StarlinkArray() : Part(3) {}
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawStarlinkBody(position, rotation.getAngle(), leftPos); }
   const double getRadius() const override { return 2; }
};

/*******************************
 * CrewDragon Parts
 ******************************/
class CrewDragonRight : public Part
{
public:
   CrewDragonRight() : Part(2) {}
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawCrewDragonRight(position, rotation.getAngle(), rightPos); }
   const double getRadius() const override { return 2; }
};

class CrewDragonLeft : public Part
{
public:
   CrewDragonLeft() : Part(2) {}
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawCrewDragonLeft(position, rotation.getAngle(), leftPos); }
   const double getRadius() const override { return 2; }
};

class CrewDragonCenter : public Part
{
public:
   CrewDragonCenter() : Part(4) {}
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(10);  gout.drawCrewDragonCenter(position, rotation.getAngle()); }
   const double getRadius() const override { return 2; }
};