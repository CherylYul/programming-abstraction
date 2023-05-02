/*
 * File: Converter.cpp
 * ----------------------------------------------------------
 * This program can:
 * 1. read in a temperature in degrees Celsius and
 * displays the corresponding temperature in degrees Fahrenheit
 * 2. read in distance in meters and convert it to corresponding
 * inches and feets
 */

#include <iostream>
using namespace std;

/* Function Prototypes */
double ConvertDeg(double deg);
void ConvertDistance(double value, double &inches, double &feets);

/* Main Program */
int main()
{
    int convertChoice;
    double value;
    cout << "Convert Celsius to Fahrenheit, Press 0" << endl;
    cout << "Convert meter to inches or feets, Press 1" << endl;
    cin >> convertChoice;
    if (convertChoice == 0)
    {
        cout << "The celsius degree is " << endl;
        cin >> value;
        cout << "The Fahrenheit degrees is " << ConvertDeg(value) << endl;
    }
    else
    {
        double inches;
        double feets;
        cout << "The meters distance is " << endl;
        cin >> value;
        ConvertDistance(value, inches, feets);
        cout << "meters to inches: " << inches << " and "
             << "meters to feets: " << feets;
    }
    return 0;
}

/*
 * Function: ConvertDeg
 * Usage: double deg = ConvertDeg(value);
 * ----------------------------------------------------------
 * Returns Fahrenheit degrees from Celsius input
 */

double ConvertDeg(double deg)
{
    return (9 / 5) * deg + 32;
}

/*
 * Function: ConvertDistance
 * Usage: ConvertDistance(value, inches, feets);
 * ----------------------------------------------------------
 * Returns inches and feets from meters input
 */

void ConvertDistance(double value, double &inches, double &feets)
{
    feets = value / 0.0254;
    inches = value / (12 * 0.0254);
}