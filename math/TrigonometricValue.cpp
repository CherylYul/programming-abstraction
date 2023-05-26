/*
 * File: TrigonometricValues.cpp
 * ------------------------------------
 * This file display a table of trigonometric sines and cosines
 */

#include <iostream>
#include <iomanip>
#include "gmath.h"
#include "gmath.cpp"
using namespace std;

void trigonometricTable();

int main()
{
    cout << right << fixed;
    trigonometricTable();
    return 0;
}

void trigonometricTable()
{
    cout << " theta | sin(theta) | cos(theta) " << endl;
    cout << "-------+------------+------------" << endl;
    for (int i = -90; i <= 90; i = i + 15)
    {
        cout << " " << setw(6) << setprecision(7) << i << "|";
        cout << " " << setw(11) << setprecision(7) << sinDegrees(i) << "|";
        cout << " " << setw(11) << setprecision(7) << cosDegrees(i) << "|" << endl;
    }
}