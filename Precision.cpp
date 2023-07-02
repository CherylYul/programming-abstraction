/*
 * File: Precision.cpp
 * ---------------------------------------------------
 * This program demonstrates various options for floating-point output
 * by displaying 3 different constants: pi, speed of light in meters/second,
 * and the fine-structure constant
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double pi = 3.14159265358979323846;
const double light_speed = 2.99792458E+8;
const double fine_structure = 7.2573525E-3;

void printPrecisionTable();

int main()
{
    cout << uppercase << right;
    cout << "Default format: " << endl
         << endl;
    printPrecisionTable();
    cout << endl
         << "Fixed format: " << fixed << endl
         << endl;
    printPrecisionTable();
    cout << endl
         << "Scientific format: " << scientific << endl
         << endl;
    printPrecisionTable();
    return 0;
}

void printPrecisionTable()
{
    cout << " prec |      pi      |  speed of light  | fine-structure " << endl;
    cout << "------+--------------+------------------+----------------" << endl;
    for (int prec = 0; prec <= 6; prec += 2)
    {
        cout << setw(4) << prec << "  |";
        cout << " " << setw(12) << setprecision(prec) << pi << " |";
        cout << " " << setw(16) << setprecision(prec) << light_speed << " |";
        cout << " " << setw(14) << setprecision(prec) << fine_structure << " |" << endl;
    }
}