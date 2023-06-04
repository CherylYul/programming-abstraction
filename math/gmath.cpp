/*
 * File: gmath.cpp
 * ---------------------------------------
 * This file implements the gmath interface. In all cases, the
 * implementation for each function requires only one line of code,
 * which makes detailed documentation unnecessary.
 */

#include <cmath>
#include "gmath.h"

extern const double PI = 3.14159265358979323846;

/*
 * Function: sinDegrees
 * Usage: double sine = sinDegrees(angle);
 * ---------------------------------------
 * Returns the trigonometric sine of angle expressed in degrees
 */

double sinDegrees(double angle)
{
    return sin(toRadians(angle));
}

/*
 * Function: cosDegrees
 * Usage: double cose = cosDegrees(angle);
 * ---------------------------------------
 * Returns the trigonometric cose of angle expressed in degrees
 */

double cosDegrees(double angle)
{
    return cos(toRadians(angle));
}

/*
 * Function: toDegrees
 * Usage: double degrees = toDegrees(radians);
 * ---------------------------------------
 * Converts an angle from radians to degrees
 */

double toDegrees(double radians)
{
    return radians * 180 / PI;
}

/*
 * Function: toRadians
 * Usage: double radians = toRadians(degrees);
 * ---------------------------------------
 * Converts an angle from degrees to radians
 */

double toRadians(double degrees)
{
    return degrees * PI / 180;
}