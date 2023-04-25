/*
 * File: ConvertCToF.cpp
 * ----------------------------------------------------------
 * This program reads in a temperature in degrees Celsius and
 * displays the corresponding temperature in degrees Fahrenheit
 */

#include <iostream>
using namespace std;

int main()
{
    double deg;
    cout << "How is the celsius degrees now? ";
    cin >> deg;
    double convert = (9 / 5) * deg + 32;
    cout << "The Fahrenheit degrees is " << convert << endl;
    return 0;
}