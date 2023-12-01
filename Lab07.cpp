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
#include "constants.h"
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
      ptUpperRight(ptUpperRight), gps(),
      rotationEarth(0, EARTH_SPEED)
   {
      // Initialize GPS satellite.
      gps.getPosition().setMetersY(42164000.0);
      gps.getPosition().setMetersX(0.0);
      Velocity vel(-3100.0, 0.0);
      gps.setVelocity(vel);
   }

   GPS gps;
   Position ptUpperRight;
   Rotation rotationEarth;
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
   // perform all the game logic
   //

   // rotate the earth
   pDemo->rotationEarth.update(TIME);

   // Move the satellite
   pDemo->gps.update(TIME);


   //
   // draw everything
   //

   Position drawPoint(pDemo->gps.getPosition());
   ogstream gout(drawPoint);

   // draw satellites
   pDemo->gps.draw(gout);

   // draw the earth
   drawPoint.setPixelsX(0);
   drawPoint.setPixelsY(0);
   gout.drawEarth(drawPoint, pDemo->rotationEarth.getAngle());
   
   drawPoint.setPixelsX(500);
   drawPoint.setPixelsY(500);
   Position moonPoint;

   gout.drawMoon(moonPoint, pDemo->rotationEarth.getAngle());
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

   //testRunner();

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
