#include "spaceship.h"
#include "acceleration.h"
#include "vector2D.h"
#include "bullet.h"
#include "velocity.h"
#include <vector>

Position rotate(const Position& origin, double x, double y, double rotation);

/************************************************************************
* ACCELERATE CALLBACK
* Adds acceleration if the user is using the thruster.
*    INPUT  acceleration                The current acceleration of the spaceship.
************************************************************************/
void Spaceship::accelerateCallback(Acceleration& acceleration) const {
   if (isThrusting) {
      const double horizontalThrust = Vector2D::getVerticalComponent(THRUST_AMOUNT, rotation.getAngle());   // Functions are swapped because 0 angles draws up, not to the right.
      const double verticalThrust = Vector2D::getHorizontalComponent(THRUST_AMOUNT, rotation.getAngle());
      acceleration.addMetersX(horizontalThrust);
      acceleration.addMetersY(verticalThrust);
   }
}

/************************************************************************
* SHOOT
* Shoots a projectile in the forward direction.
*    OUTPUT  bullet       The projectile fired.
************************************************************************/
void Spaceship::shoot(std::vector<OrbitObject*>& orbitObjects) const {
   // Get bullet spawn point.
   Position ptShipFront = rotate(position, 0.0, 19.0, rotation.getAngle());

   // Get bullet velocity.
   Velocity newVelocity = Velocity(velocity);
   double deltaX = Vector2D::getVerticalComponent(PROJECTILE_SPEED, rotation.getAngle());
   double deltaY = Vector2D::getHorizontalComponent(PROJECTILE_SPEED, rotation.getAngle());
   newVelocity.addMetersX(deltaX);
   newVelocity.addMetersY(deltaY);

   // Create bullet.
   Bullet* bullet = new Bullet();
   bullet->setPosition(ptShipFront);
   bullet->setVelocity(newVelocity);
   
   orbitObjects.push_back(bullet);
}

void Spaceship::breakApart(std::vector<OrbitObject*>& orbitObjects) const {
   //TODO
   
}