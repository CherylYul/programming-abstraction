/*
 * File: domino.cpp
 * ---------------------------------------
 * This file implement Domino class.
 */

#include <string>
#include "domino.h"
#include "string/strlib.h"
#include "string/strlib.cpp"
#include "error/error.h"
#include "error/error.cpp"
using namespace std;

Domino::Domino()
{
    leftDots = 0;
    rightDots = 0;
}

Domino::Domino(int x, int y)
{
    if (x > 6 && y > 6)
        error("Domino value must from 1 to 6!");
    leftDots = x;
    rightDots = y;
}

string Domino::toString()
{
    return integerToString(leftDots) + "|" + integerToString(rightDots);
}

int Domino::getLeftDots()
{
    return leftDots;
}

int Domino::getRightDots()
{
    return rightDots;
}

int Domino::getTotalDots()
{
    return leftDots + rightDots;
}

ostream &operator<<(ostream &os, Domino d)
{
    return os << d.toString();
}

Domino operator+(Domino d1, Domino d2)
{
    return Domino(d1.leftDots + d2.leftDots, d1.rightDots + d2.rightDots);
}