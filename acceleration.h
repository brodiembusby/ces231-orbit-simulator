#pragma once
class Acceleration
{
private:
   double angle;


public:
   double horizontalComponentOfAcceleration(double totalAcceleration, double angle);
   double verticalComponentOfAcceleration(double totalAcceleration, double angle);
};

