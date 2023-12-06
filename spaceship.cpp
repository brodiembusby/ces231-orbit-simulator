#include "spaceship.h"
#include "acceleration.h"
#include "vector2D.h"
#include "bullet.h"
#include "velocity.h"
#include <vector>
#include "fragment.h"

Position rotate(const Position& origin, double x, double y, double rotation);

/************************************************************************
* UPDATE CALLBACK
* Called every frame if any specific objects need to perform custom logic.
* In this case, we want to add thrust.
*    INPUT  acceleration                The current acceleration of the spaceship.
************************************************************************/
void Spaceship::updateCallback(Acceleration& acceleration) {
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
   double angle = 3 / 360;
   for (int i = 0; i < 3; i++)
   {
      orbitObjects.push_back(createFragment(angle*i));
   }
}

void Spaceship::update(const double time)
{
   // Set acceleration to gravity
   Acceleration acceleration(position.getGravity());
   updateCallback(acceleration);

   // Update velocity
   const Velocity& dV = acceleration.getDeltaVelocity(time);
   velocity += dV;

   // Update position
   const Position dP = velocity.getDeltaPosition(time);
   position += dP;
}