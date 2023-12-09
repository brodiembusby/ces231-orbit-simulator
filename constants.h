/***********************************************************************
 * Header File:
 *    Constants : All constants used in the program
 * Author:
 *    Aaron Fox
 * Summary:
 *    Every constant used in the program is defined here.
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES  // For PI
#include <math.h>          // For PI

constexpr   double   RADIUS_EARTH = 6378000.0;                       // Radius of Earth in meters.
constexpr   double   GRAVITY_SEA_LEVEL = 9.80665;                    // Gravity at sea level.
constexpr   double   HOURS_DAY = 24;                                 // Hours per day.
constexpr   double   MINUTES_HOUR = 60;                              // Minutes per hour.
constexpr   double   SECONDS_MINUTE = 60;                            // Seconds per minute.
constexpr   int      FRAMERATE = 30;                                 // Frames per second.
const       double   TIME = HOURS_DAY * MINUTES_HOUR / FRAMERATE;    // Simulation seconds per frame.
const       double   EARTH_SPEED = -(2 * M_PI) / HOURS_DAY / MINUTES_HOUR / SECONDS_MINUTE;     // Earth rotation angle per frame.
const       double   MOON_SPEED = -(2 * M_PI) / HOURS_DAY / MINUTES_HOUR / SECONDS_MINUTE / 4;  // Moon rotation angle per frame.
