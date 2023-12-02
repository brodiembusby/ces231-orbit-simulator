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
   void breakApart(std::vector<OrbitObject*>& orbitObjects) const override;

};

//GPS Classes
class GPSRight : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(1);  gout.drawGPSRight(position, rotation.getAngle(), rightPos); }
};
class GPSLeft : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-1);  gout.drawGPSLeft(position, rotation.getAngle(), leftPos); }
};
class GPSCenter : public Part
{
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(4);  gout.drawGPSCenter(position, rotation.getAngle()); }
};
// Hubble Classes
class HubbleRight : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(4);  gout.drawHubbleRight(position, rotation.getAngle(), rightPos); }
};
class HubbleLeft : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-4);  gout.drawHubbleLeft(position, rotation.getAngle(), leftPos); }
};
class HubbleComputer : public Part
{
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(4);  gout.drawHubbleComputer(position, rotation.getAngle(), upPos); }
};
class HubbleTelescope : public Part
{
   void draw(ogstream& gout) const override { Position downPos; downPos.addPixelsY(4); gout.drawHubbleTelescope(position, rotation.getAngle(), downPos); }
};
// Starlink Classes
class StarlinkBody : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(4);  gout.drawStarlinkArray(position, rotation.getAngle(), rightPos); }
};
class StarlinkArray : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-4);  gout.drawStarlinkBody(position, rotation.getAngle(), leftPos); }
};
// CrewqDragon Classes
class CrewDragonRight : public Part
{
   void draw(ogstream& gout) const override { Position rightPos; rightPos.addPixelsX(1);  gout.drawCrewDragonRight(position, rotation.getAngle(), rightPos); }
};
class CrewDragonLeft : public Part
{
   void draw(ogstream& gout) const override { Position leftPos; leftPos.addPixelsX(-1);  gout.drawCrewDragonLeft(position, rotation.getAngle(), leftPos); }
};
class CrewDragonCenter : public Part
{
   void draw(ogstream& gout) const override { Position upPos; upPos.addPixelsY(4);  gout.drawCrewDragonCenter(position, rotation.getAngle()); }
};