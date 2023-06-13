/*
 * File: veclib.cpp
 * -----------------------------------------------
 * Implement useful function for vector handling.
 */

#include <iostream>
#include "veclib.h"
using namespace std;

/*
 * Function: printVector
 * Usage: printVector(vec);
 * -----------------------------------------------
 * Writes out the contents of the vector vec as a comma-separated list
 * enclosed in square brackets.
 */

void printVector(Vector<int> &vec)
{
    cout << "[";
    for (int i = 0; i < vec.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << vec[i];
    }
    cout << "]" << endl;
}

/*
 * Function: removeZeroElements
 * Usage: removeZeroElements(vec);
 * -----------------------------------------------
 * Deletes any zero-valued elements from a vector of integers
 */

void removeZeroElements(Vector<int> &vec)
{
    for (int i = vec.size() - 1; i >= 0; i--)
        if (vec[i] == 0)
            vec.removeAt(i);
}
