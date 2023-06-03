/*
 * File: point.cpp
 * --------------------------------------------
 * The file implements the point.h interface
 */

#include <string>
#include "string/strlib.h"
#include "string/strlib.cpp"
#include "point.h"
using namespace std;

/*
 * Implmentation notes: Constructors
 * --------------------------------------------
 * The constructors initialize the instance variables x and y. In the second form
 * of the constructor, the parameter names are xc and yc to avoid the problem of
 * shadowing the instance variables
 */

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(int xc, int yc)
{
    x = xc;
    y = yc;
}

/*
 * Implmentation notes: Getters
 * --------------------------------------------
 * The getters returns the value of the coressponding instance variable.
 * No setters are provided to ensure the Point objects are mutable.
 */

int Point::getX()
{
    return x;
}

int Point::getY()
{
    return y;
}

/*
 * Implmentation notes: toString
 * --------------------------------------------
 * The implementation of toString uses the integerToString function from
 * filelib library
 */

string Point::toString()
{
    return "(" + integerToString(x) + ", " + integerToString(y) + ")";
}

bool operator==(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(Point p1, Point p2)
{
    return !(p1 == p2);
}

ostream &operator<<(ostream &os, Point pt)
{
    return os << pt.toString();
}