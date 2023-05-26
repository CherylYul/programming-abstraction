/*
 * File: WindChillTable.cpp
 * ---------------------------------
 * This programs returns WindChill value in tables
 */

#include <iostream>
#include <iomanip>
#include "converter.h"
#include "converter.cpp"
using namespace std;

void windChillTable();

int main()
{
    cout << right << fixed;
    windChillTable();
    return 0;
}

void windChillTable()
{
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