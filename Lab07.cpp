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
#include "sputnik.h"    // for sputink satellite
#include "hubble.h"     // for hubble satellite
#include "dragon.h"     // for dragon satellite
#include "starlink.h"   // for Starlink satellite
#include "star.h"       // for Star
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
      /**********************************************************
      * GPS objects
         Position	                              Velocity
         ( 0.0 m, 26,560,000.0 m)	         (-3,880.0 m/s, 0.0 m/s)
         ( 23,001,634.72 m, 13,280,000.0 m)	( -1,940.00 m/s, 3,360.18 m/s)
         ( 23,001,634.72 m, -13,280,000.0 m)	( 1,940.00 m/s, 3,360.18 m/s)
         ( 0.0 m, -26560000.0 m)	         ( 3880.0 m/s, 0.0 m/s)
         (-23001634.72 m, -13280000.0 m)	( 1940.00 m/s, -3360.18 m/s)
         (-23001634.72 m, 13280000.0 m)	( -1940.00 m/s, -3360.18 m/s)
      *******************************************************/
      // Initialize GPS 1 satellite.
      GPS* gps1 = new GPS();
      gps1->getPosition().setMeters(0, 26560000);
      gps1->setVelocity(Velocity(-3880, 0));
      orbitObjects.push_back(gps1);

      // Initialize GPS 2 satellite.
      GPS* gps2 = new GPS();
      gps2->getPosition().setMeters(23001634.72, 13280000);
      gps2->setVelocity(Velocity(-1940, 3360.18));
      orbitObjects.push_back(gps2);

      // Initialize GPS 3 satellite.
      GPS* gps3 = new GPS();
      gps3->getPosition().setMeters(23001634.72, -13280000);
      gps3->setVelocity(Velocity(1940, 3360.18));
      orbitObjects.push_back(gps3);

      // Initialize GPS 4 satellite.
      GPS* gps4 = new GPS();
      gps4->getPosition().setMeters(0, -26560000.0);
      gps4->setVelocity(Velocity(3880.0, 0));
      orbitObjects.push_back(gps4);

      // Initialize GPS 5 satellite.
      GPS* gps5 = new GPS();
      gps5->getPosition().setMeters(-23001634.72, -13280000);
      gps5->setVelocity(Velocity(1940, -3360.18));
      orbitObjects.push_back(gps5);

      // Initialize GPS 6 satellite.
      GPS* gps6 = new GPS();
      gps6->getPosition().setMeters(-23001634.72, 13280000);
      gps6->setVelocity(Velocity(-1940, -3360.18));
      orbitObjects.push_back(gps6);

      // Initialize sputnik.
      Sputnik* sputnik = new Sputnik();
      sputnik->getPosition().setMeters(-36515095.13, 21082000.0);
      sputnik->setVelocity(Velocity(2050.0, 2684.68));
      orbitObjects.push_back(sputnik);

      // We will start with the telescope at (0.0 m, -42,164,000.0 m) with a velocity of (3,100.0 m/s, 0.0 m/s)
      Hubble* hubble = new Hubble();
      hubble->getPosition().setMeters(0, -42164000);
      hubble->setVelocity(Velocity(3100, 0));
      orbitObjects.push_back(hubble);

      // We will put this satellite in a low earth orbit at (0.0 m, 8,000,000.0 m) with a velocity of (-7,900.0 m/s, 0.0 m/s).
      Dragon* dragon = new Dragon();
      dragon->getPosition().setMeters(0, 8000000);
      dragon->setVelocity(Velocity(-7900, 0));
      orbitObjects.push_back(dragon);

      // We will therefore put our Starlink satellite at (0.0 m, -13,020,000.0 m) with a velocity of (5,800.0 m/s, 0.0 m/s).

      Starlink* starlink = new Starlink();
      starlink->getPosition().setMeters(0, -13020000);
      starlink->setVelocity(Velocity(5800, 0));
      orbitObjects.push_back(starlink);

      // Initialize spaceship
      ship = new Spaceship();
      ship->getPosition().setPixelsX(-450);
      ship->getPosition().setPixelsY(450);
      ship->setVelocity(Velocity(0, -2000));
      orbitObjects.push_back(ship);

      // Give 100 stars
      for (int i = 0; i < 200; i++)
      {
         unsigned char phase = random(0, 200);
         Position starpos;
         starpos.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
         starpos.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));


         Star* star = new Star(starpos, phase);

         stars.push_back(star);
      }
   }

   vector<OrbitObject*> orbitObjects;
   vector<Star*> stars;
   Position ptUpperRight;
   Rotation rotationEarth;
   Rotation rotationMoon;
   Spaceship* ship;
};

/************************************************************************
* DESTROY OBJECT
* Destroys an object in orbit, removing it from the collection and deleting it from memory.
*    Demo*        pDemo                   The game instance.
*    OrbitObject* obj                     The object to delete.
*    int          index                   The index of the object to delete.
************************************************************************/
void destroyObject(Demo* pDemo, OrbitObject* obj, const int index) {

   // Check if the object is the spaceship.
   if (obj == pDemo->ship)
   {
      pDemo->ship = nullptr;
      assert(false);          // Not sure what to do when main ship crashes.
   }

   pDemo->orbitObjects.erase(pDemo->orbitObjects.begin() + index);
   obj->breakApart(pDemo->orbitObjects);
   delete obj;
}

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

   if (pDemo->ship != nullptr) {
      // Rotate
      if (pUI->isLeft())
         pDemo->ship->rotateLeft();
      if (pUI->isRight())
         pDemo->ship->rotateRight();

      // Thrust
      pDemo->ship->setThrustActive(pUI->isDown());

      // Shoot
      if (pUI->isSpace() && pDemo->ship != nullptr)
         pDemo->ship->shoot(pDemo->orbitObjects);
   }

   // rotate the earth and moon
   pDemo->rotationEarth.update(TIME);
   pDemo->rotationMoon.update(TIME);
   Position drawPoint;
   ogstream gout;

   // Collision detection
   for (int i = 0; i < pDemo->orbitObjects.size(); i++)
   {
      auto obj1 = pDemo->orbitObjects[i];
      if (!obj1->getIsDestroyed())
      {
         for (int n = i + 1; n < pDemo->orbitObjects.size(); n++)
         {
            auto obj2 = pDemo->orbitObjects[n];
            if (!obj2->getIsDestroyed() && obj1->checkCollision(*obj2))
            {
               destroyObject(pDemo, obj1, i);
               destroyObject(pDemo, obj2, n - 1);

               // We *need* to stop iterating over the next elements because obj1 is now destroyed.
               break;
            }
         }

         // Does obj1 collide with earth
         if (!obj1->getIsDestroyed() && obj1->checkCollision(Position(0, 0), 55))
         {
            // If it does.
            destroyObject(pDemo, obj1, i);
         }
      }
   }

   // Update and draw all the stars
   for (const auto star : pDemo->stars)
   {
      // Update the phase
      star->update();

      // Draw it
      star->draw(gout);
   }

   // Delete destroyed objects (usually bullets).
   for (int i = 0; i < pDemo->orbitObjects.size(); i++)
   {
      auto obj = pDemo->orbitObjects[i];
      if (obj->getIsDestroyed())
      {
         destroyObject(pDemo, obj, i);
         i--;        // Need to adjust index because we're modifying array in place.
      }
   }

   // Update and draw all orbit objects
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
