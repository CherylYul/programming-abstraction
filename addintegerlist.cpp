/*
 * File: AddIntegerList.cpp
 * ---------------------------
 * This program add a list of intergers. The end of input is indicated by
 * entering a sentinel value, which is defined by setting the value of
 * the constant SENTINEL
 */

#include <iostream>
using namespace std;

const int SENTINEL = 0;

/* main program */
int main()
{
    cout << "This program adds a list of numbers." << endl;
    cout << "Use " << SENTINEL << " to signal the end." << endl;
    int total = 0;
    while (true)
    {
        int value;
        cout << " ? ";
        cin >> value;
        if (value == SENTINEL)
            break;
        total += value;
    }
    cout << "The total is " << total << endl;
    return 0;
}