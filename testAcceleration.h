#pragma once

class TestAcceleration
{
public:
   void run();

private:
   void testGravitySeaLevel();
   void testGravity100k();
   void testGravtiyAngleUp();
   void testGravityAngle45();
   void testGravityComponentStraightUpSeaLevel();
   void testGravityComponentDiagonal();
};
