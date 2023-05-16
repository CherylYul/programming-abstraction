/*
 * File: RandTest.cpp
 * ------------------------------------------------------
 * This program tests the random number generator in C++
 * and produces the values used in the examples in test
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int n_trials = 10;

int main()
{
    cout << "RAND_MAX is " << RAND_MAX << endl;
    cout << "The first " << n_trials << " calls to rand: " << endl;
    for (int i = 0; i < n_trials; i++)
    {
        cout << setw(10) << rand() << endl;
    }
    return 0;
}