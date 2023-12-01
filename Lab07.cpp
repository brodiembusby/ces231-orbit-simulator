/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "gps.h"        // for GPS satellite
#include "velocity.h"   // for Velocity class
#include "rotation.h"   // for Rotation class
#include "spaceship.h"  // for Spaceship class
#include "constants.h"
#include <set>          // For orbit objects
#include "test.h"       // for TEST

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight), orbitObjects(),
      rotationEarth(0, EARTH_SPEED),
      rotationMoon(0, MOON_SPEED),
      ship()
   {
      // Initialize GPS satellite.
      GPS* gps = new GPS();
      gps->getPosition().setMetersY(42164000.0);
      gps->getPosition().setMetersX(0.0);
      gps->setVelocity(Velocity(-3100, 0));
      orbitObjects.insert(gps);

      // Initialize spaceship
      ship.getPosition().setPixelsX(-450);
      ship.getPosition().setPixelsY(450);
      ship.setVelocity(Velocity(0, -2000));
      orbitObjects.insert(&ship);
   }

   set<OrbitObject*> orbitObjects;
   Position ptUpperRight;
   Rotation rotationEarth;
   Rotation rotationMoon;
   Spaceship ship;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // Spaceship interaction
   //

   // Rotate
   if (pUI->isLeft())
      pDemo->ship.rotateLeft();
   if (pUI->isRight())
      pDemo->ship.rotateRight();

   // Thrust
   pDemo->ship.setThrustActive(pUI->isDown());

   // Shoot
   if (pUI->isSpace()) {
      auto bullet = pDemo->ship.shoot();
      pDemo->orbitObjects.insert(bullet);
   }

   // rotate the earth and moon
   pDemo->rotationEarth.update(TIME);
   pDemo->rotationMoon.update(TIME);

   Position drawPoint;
   ogstream gout;

   for (const auto obj : pDemo->orbitObjects)
   {
      // Move the object.
      obj->update(TIME);

      // Draw the object.
      obj->draw(gout);
   }

   // draw the earth
   drawPoint.setPixelsX(0);
   drawPoint.setPixelsY(0);
   gout.drawEarth(drawPoint, pDemo->rotationEarth.getAngle());

   drawPoint.setPixelsX(500);
   drawPoint.setPixelsY(500);
   Position moonPoint;

   gout.drawMoon(moonPoint, pDemo->rotationMoon.getAngle());
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
