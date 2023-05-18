/*
 * File: RectangleCircle.cpp
 * ----------------------------------------------------
 * This program computes the area of the quarter circle
 * by dividing it into 10,000 rectangles
 */

#include <iostream>
#include <cmath>
using namespace std;

/* main program */
int main()
{
    cout << "This program calculates the area of the quarter circle." << endl;
    double r;
    cout << "Please input radius: ";
    cin >> r;
    double area = 0;
    double w = r / 10000;
    for (int i = 0; i < 10000; i++)
    {
        int k = i + 1;
        double h = sqrt(r * r - (k * w) * (k * w));
        area = area + h * w;
    }
    cout << "The area of the quarter circle is " << area;
    return 0;
}