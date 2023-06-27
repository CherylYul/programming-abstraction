/*
 * File: converter.cpp
 * -----------------------------------------------
 * Implement the converter interfaces.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include "converter.h"
using namespace std;

/*
 * Function: degC2F, degF2C
 * Usage: double results = degC2F(deg);
 *        double results = degF2C(deg);
 * -----------------------------------------------
 * Convert Celsius degree to Fahrenheit degrees and vice versa.
 */

double degC2F(double deg) { return (9 / 5) * deg + 32; }
double degF2C(double deg) { return (deg - 32) * (5 / 9); }

/*
 * Function: distM2I, distI2M, distM2F, distF2M, distF2I, distI2F
 * Usage: distM2I(dist); distI2M(dist);
 *        distM2F(dist); distF2M(dist);
 *        distF2I(dist); distI2F(dist);
 * -----------------------------------------------
 * Convert meters, inches, feets these 3 measure together.
 */

double distM2I(double dist) { return dist / (12 * 0.0254); }
double distI2M(double dist) { return dist * 12 * 0.0254; }
double distM2F(double dist) { return dist / 0.0254; }
double distF2M(double dist) { return dist * 0.0254; }
double distF2I(double dist) { return dist * 12; }
double distI2F(double dist) { return dist / 12; }

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

void windChillTable()
{
    cout << right << fixed;
    cout << setw(4) << "Calm"
         << "|";
    for (int temp = 40; temp >= -45; temp = temp - 5)
        cout << setw(4) << temp << "|";
    cout << endl;
    for (int speed = 5; speed <= 60; speed = speed + 5)
    {
        cout << setw(4) << speed << "|";
        for (int temp = 40; temp >= -45; temp = temp - 5)
            cout << setw(4) << setprecision(0) << windChill(speed, temp) << "|";
        cout << endl;
    }
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