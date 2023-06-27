/*
 * File: gmath.h
 * ---------------------------------
 * This file exports the constant PI along with a few degree-based
 * trigonometric functions, which are typically easier to use
 */

#ifndef _gmath_h
#define _gmath_h
extern const double PI;

double sinDegrees(double angle);
double cosDegrees(double angle);
double toDegrees(double radians);
double toRadians(double degrees);
void trigonometricTable();

#endif