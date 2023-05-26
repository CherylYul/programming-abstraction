/*
 * File: converter.cpp
 * -----------------------------------------------
 * Implement the converter interfaces.
 */

#include <iostream>
#include <cmath>
#include "converter.h"
using namespace std;

/*
 * Function: degC2F
 * Usage: double results = degC2F(double deg);
 * -----------------------------------------------
 * Convert Celsius degree to Fahrenheit degrees
 */

double degC2F(double deg)
{
    return (9 / 5) * deg + 32;
}

/*
 * Function: degF2C
 * Usage: double results = degF2C(double deg);
 * -----------------------------------------------
 * Convert Fahrenheit degree to Celsius degrees
 */

double degF2C(double deg)
{
    return (deg - 32) * (5 / 9);
}

/*
 * Function: distM2I
 * Usage: distM2I(dist);
 * -----------------------------------------------
 * Convert meters to inches
 */

double distM2I(double dist)
{
    return dist / (12 * 0.0254);
}

/*
 * Function: distI2M
 * Usage: distI2M(dist);
 * -----------------------------------------------
 * Convert inches to meters
 */

double distI2M(double dist)
{
    return dist * 12 * 0.0254;
}

/*
 * Function: distM2F
 * Usage: distM2F(dist);
 * -----------------------------------------------
 * Convert meters to feets
 */

double distM2F(double dist)
{
    return dist / 0.0254;
}

/*
 * Function: distF2M
 * Usage: distF2M(dist);
 * -----------------------------------------------
 * Convert feets to meters
 */

double distF2M(double dist)
{
    return dist * 0.0254;
}

/*
 * Function: distF2I
 * Usage: distF2I(dist);
 * -----------------------------------------------
 * Convert feets to inches
 */

double distF2I(double dist)
{
    return dist * 12;
}

/*
 * Function: distI2F
 * Usage: distI2F(dist);
 * -----------------------------------------------
 * Convert inches to feets
 */
double distI2F(double dist)
{
    return dist / 12;
}

/*
 * Function: windChill
 * Usage: double result = windChill(windSpeed, degF);
 * -----------------------------------------------
 * Returns windChill based on windspeed (miles per hour) and temperature (F degree)
 */

double windChill(double windSpeed, double degF)
{
    if (degF > 40)
        error("The windchill is undefined!");
    if (windSpeed == 0)
        return degF;
    return 35.74 + 0.6215 * degF - 35.75 * pow(windSpeed, 0.16) + 0.4275 * degF * pow(windSpeed, 0.16);
}

/*
 * Function: error
 * Usage: error(msg);
 * -----------------------------------------------------------------
 * Write error message to the cerr stream and then exit the program
 * indicating that a failure has occured
 */

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}