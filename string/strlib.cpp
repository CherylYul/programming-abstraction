/*
 * File: strlib.cpp
 * -----------------------------------------------
 * Implement the strlib.h
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "strlib.h"
#include "../error/error.h"
#include "../error/error.cpp"
using namespace std;

/*
 * Function: getInteger
 * Usage: int n = getInteger(prompt);
 * -----------------------------------------------
 * Requests an integer value from user, if input is not a legal integer
 * the implementation will give the user a chance to reenter the value
 */

int getInteger(string prompt)
{
    int value;
    string line;
    while (true)
    {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        stream >> value >> ws;
        if (!stream.fail() && stream.eof())
            break;
        cout << "Illegal integer format. Try again." << endl;
    }
    return value;
}

/*
 * Function: stringToInteger, stringToDouble
 * Usage: int n = stringToInteger(str);
 *        double n = stringToDouble(str);
 * -----------------------------------------------
 * Requests an integer or float num from user, if input is not legal,
 * extracts error message
 */

int stringToInteger(string str)
{
    int value;
    istringstream stream(str);
    stream >> value >> ws;
    if (stream.fail() || !stream.eof())
        error("stringToInteger: Illegal integer format");
    cout << "stringToInteger: Illegal integer format" << endl;
    return value;
}

double stringToDouble(string str)
{
    double value;
    istringstream stream(str);
    stream >> value >> ws;
    if (stream.fail() || !stream.eof())
        error("stringToInteger: Illegal integer format");
    cout << "stringToInteger: Illegal integer format" << endl;
    return value;
}

/*
 * Function: integerToString, doubleToString
 * Usage: string str = integerToString(n);
 *        string str = doubleToString(n)
 * -----------------------------------------------
 * Turn value to string type
 */

string integerToString(int n)
{
    ostringstream stream;
    stream << n;
    return stream.str();
}

string doubleToString(double n)
{
    ostringstream stream;
    stream << n;
    return stream.str();
}
