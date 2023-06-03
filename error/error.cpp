/*
 * File: error.cpp
 * -----------------------------------------------
 * Implement the error.h interface
 */

#include <iostream>
#include "error.h"
using namespace std;

/*
 * Function: error
 * Usage: error(msg);
 * ------------------------------------------------------
 * Writes the string msg to the cerr stream and then exit
 * the program with a standard status value indicating that
 * a failure has occurred
 */

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}