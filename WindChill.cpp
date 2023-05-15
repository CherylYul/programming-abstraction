/*
 * File: WindChill.cpp
 * ---------------------------------------------------
 * This program reads in values Fahrenheit temperature
 * and wind speed in miles per hours to returns the
 * wind chill value
 */

#include <iostream>
#include <cmath>
using namespace std;

/* function prototype */
double windChill(double windSpeed, double tempF);
void error(string msg);

/* main program */
int main()
{
    double tempF;
    cout << "The Fahrenheit temperature is: ";
    cin >> tempF;
    double windSpeed;
    cout << "The wind speed in miles per hours is: ";
    cin >> windSpeed;
    cout << windChill(windSpeed, tempF);
    return 0;
}

/*
 * Function: windChill
 * Usage: double result = windChill(double windSpeed, double tempF);
 * -----------------------------------------------------------------
 * Returns windChill based on windspeed and temperature
 */

double windChill(double windSpeed, double tempF)
{
    if (tempF > 40)
        error("The windchill is undefined!");
    if (windSpeed == 0)
        return tempF;
    return 35.74 + 0.6215 * tempF - 35.75 * pow(windSpeed, 0.16) + 0.4275 * tempF * pow(windSpeed, 0.16);
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
