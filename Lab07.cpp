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

#define _USE_MATH_DEFINES  // For PI

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POINT
#include "gps.h"        // for GPS satellite
#include "velocity.h"   // for Velocity class
#include <math.h>       // For PI

using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight), gps()
   {
      //ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptGPS.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptGPS.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      //ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      //angleShip = 0.0;
      //phaseStar = 0;

      // Initialize GPS satellite.

      gps.getPosition().setMetersY(42164000);
      gps.getPosition().setMetersX(0);
      gps.setAngle(M_PI_2);
      Velocity vel(-3100.0, 0.0);
      gps.setVelocity(vel);
      angleEarth = 0.0;
   }

   GPS gps;
   //Position ptHubble;
   //Position ptSputnik;
   //Position ptStarlink;
   //Position ptCrewDragon;
   //Position ptShip;
   //Position ptGPS;
   //Position ptStar;
   Position ptUpperRight;

   //unsigned char phaseStar;

   //double angleShip;
   double angleEarth;
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
   // accept input
   //

   // move by a little
   //if (pUI->isUp())
   //   pDemo->ptShip.addPixelsY(1.0);
   //if (pUI->isDown())
   //   pDemo->ptShip.addPixelsY(-1.0);
   //if (pUI->isLeft())
   //   pDemo->ptShip.addPixelsX(-1.0);
   //if (pUI->isRight())
   //   pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   pDemo->angleEarth += 0.01;
   //pDemo->angleShip += 0.02;
   //pDemo->phaseStar++;

   //
   // draw everything
   //

   //Seconds per frame
   double time = 48.0; // Time shouldnt change for whole simulation
   
   Position pt;
   Velocity gpsVel;
   Acceleration gpsAcc;
   ogstream gout(pt);

   //Positonal Variables 
   double radiusEarth = 6378000.0;  // radius of the earth
  

   // TODO:
   // double initalX;
   // double initalY;


   // Inital x and y would be here however he wants us to set it off by 30 degrees first giving us those hard coded numbers
   double heightAboveEarth = pt.heightAboveTheEarth(pDemo->gps.getPosition().getMetersX(), pDemo->gps.getPosition().getMetersY(),radiusEarth); // Height above earth 
   
   // Finding out acceleration for gps
   double gravitationHeight = gpsAcc.gravityH(gpsAcc.getGravity(), radiusEarth, heightAboveEarth); // I think objects height above earth
   double radians = gpsAcc.degreeToRadian(pDemo->gps.getAngle()); // Convert degrees to radians
   double ddx = gpsAcc.ddx(gravitationHeight, radians);  // Horizontal acceleration
   double ddy = gpsAcc.ddy(gravitationHeight, radians);  // Vertical acceleration

   // Finding out Velocity for gps
   
   // TODO:
   double dx = gpsVel.dx(pDemo->gps.getVelocity().getdx0(), ddx, time); // horizontal velocity
   double dy = gpsVel.dy(pDemo->gps.getVelocity().getdy0(), ddy, time);  // vertical velocity

   pDemo->gps.getVelocity().setdx0(dx);
   pDemo->gps.getVelocity().setdy0(dy);

   // Finding a new position
   double x = pt.distanceFormula(pDemo->gps.getPosition().getMetersX(), dx, time, ddx); // new x position
   double y = pt.distanceFormula(pDemo->gps.getPosition().getMetersY(), dy, time, ddy);// new y position
   Position newPos(x, y);
   pDemo->gps.setPosition(newPos);  // Setting new position

   // draw satellites
   //gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   //gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   //gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS(pDemo->gps.getPosition(), pDemo->gps.getAngle());

   // draw parts
   //pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   //gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   //gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   //gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   //gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   //// draw fragments
   //pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);
   //pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);

   //// draw a single star
   //gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
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

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
