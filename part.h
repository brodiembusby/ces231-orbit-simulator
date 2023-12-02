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

class Part : public OrbitObject
{
public:
   
   void draw(ogstream& gout) const override {  };
   virtual void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;

};

//GPS Classes
class GPSRight : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawGPSRight(position, rotation.getAngle(), rightPos); }
};
class GPSLeft : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawGPSLeft(position, rotation.getAngle(), leftPos); }
};
class GPSCenter : public Part
{
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(10);  gout.drawGPSCenter(position, rotation.getAngle()); }
};
// Hubble Classes
class HubbleRight : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawHubbleRight(position, rotation.getAngle(), rightPos); }
};
class HubbleLeft : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawHubbleLeft(position, rotation.getAngle(), leftPos); }
};
class HubbleComputer : public Part
{
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(10);  gout.drawHubbleComputer(position, rotation.getAngle(), upPos); }
};
class HubbleTelescope : public Part
{
   void draw(ogstream& gout) const override { Position downPos; downPos.addPixelsY(-10); gout.drawHubbleTelescope(position, rotation.getAngle(), downPos); }
};
// Starlink Classes
class StarlinkBody : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawStarlinkArray(position, rotation.getAngle(), rightPos); }
};
class StarlinkArray : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawStarlinkBody(position, rotation.getAngle(), leftPos); }
};
// CrewqDragon Classes
class CrewDragonRight : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(10);  gout.drawCrewDragonRight(position, rotation.getAngle(), rightPos); }
};
class CrewDragonLeft : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-10);  gout.drawCrewDragonLeft(position, rotation.getAngle(), leftPos); }
};
class CrewDragonCenter : public Part
{
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(10);  gout.drawCrewDragonCenter(position, rotation.getAngle()); }
};