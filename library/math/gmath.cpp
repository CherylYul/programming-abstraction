/*
 * File: gmath.cpp
 * ---------------------------------------
 * This file implements the gmath interface
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include "gmath.h"

extern const double PI = 3.14159265358979323846;

/*
 * Function: sinDegrees, cosDegrees
 * Usage: double sine = sinDegrees(angle);
 *        double cose = cosDegrees(angle);
 * ---------------------------------------
 * Returns the trigonometric sine and cosine of angle expressed in degrees
 */

double sinDegrees(double angle) { return sin(toRadians(angle)); }
double cosDegrees(double angle) { return cos(toRadians(angle)); }

/*
 * Function: toDegrees, toRadians
 * Usage: double degrees = toDegrees(radians);
 *        double radians = toRadians(degrees);
 * ---------------------------------------
 * Converts an angle from radians to degrees and vice versa
 */

double toDegrees(double radians) { return radians * 180 / PI; }
double toRadians(double degrees) { return degrees * PI / 180; }

/*
 * Function: TrigonometricValues
 * Usage: trigonometricTable();
 * ------------------------------------
 * Display a table of trigonometric sines and cosines
 */

void trigonometricTable()
{
    cout << right << fixed;
    cout << " theta | sin(theta) | cos(theta) " << endl;
    cout << "-------+------------+------------" << endl;
    for (int i = -90; i <= 90; i = i + 15)
    {
        cout << " " << setw(6) << setprecision(7) << i << "|";
        cout << " " << setw(11) << setprecision(7) << sinDegrees(i) << "|";
        cout << " " << setw(11) << setprecision(7) << cosDegrees(i) << "|" << endl;
    }
}