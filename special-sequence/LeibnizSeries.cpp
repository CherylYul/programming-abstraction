/*
 * File: LeibnizSeries.cpp
 * ---------------------------------------------------------------
 * This program calculate approximate π according to Leibniz rules
 * If we start with 1, subtract one-third, add one-fifth and so on
 */

#include <iostream>
using namespace std;

/* main program */
int main()
{
    double start = 1;
    double result = 0;
    cout << "This program calculate π according to Leibniz's series." << endl;
    cout << "Calculates an approximation of π consisting of the first 10,000 terms." << endl;
    for (int i = 0; i < 10000; i++)
    {
        if (i % 2 == 1)
        {
            result = result - (1 / start);
        }
        else
        {
            result = result + (1 / start);
        }
        start += 2;
    }
    cout << "π is " << result * 4 << endl;
    return 0;
}