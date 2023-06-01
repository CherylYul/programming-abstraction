/*
 * File: rational.cpp
 * ---------------------------------------
 * This file implement Rational class.
 */

#include <string>
#include <cstdlib>
#include "rational.h"
#include "math/mmath.cpp"
#include "math/mmath.h"
#include "string/strlib.cpp"
#include "string/strlib.h"
using namespace std;

/*
 * Implementation notes: Constructors
 * ---------------------------------------
 * There are 3 constructors for Rational class:
 *
 * 1. Default constructor creates a Rational with a zero value
 * 2. One-argument form converts an integer to a Rational
 * 3. Two-arguments specify a fraction
 *
 * Notes:
 *
 * 1. The fraction is always reduced to lowest terms
 * 2. The denominator is always positive
 * 3. Zero is always represented as 0/1
 */

Rational::Rational()
{
    num = 0;
    den = 1;
}

Rational::Rational(int n)
{
    num = n;
    den = 1;
}

Rational::Rational(int x, int y)
{
    if (y == 0)
        error("Rational: Division by zero!");
    if (x == 0)
    {
        num = 0;
        den = 1;
    }
    else
    {
        int g = gcd(abs(x), abs(y));
        num = x / g;
        den = abs(y) / g;
        if (y < 0)
            num = -num;
    }
}

string Rational::toString()
{
    if (den == 1)
        return integerToString(num);
    else
        return integerToString(num) + "/" + integerToString(den);
}

ostream &operator<<(ostream &os, Rational rat)
{
    return os << rat.toString();
}

Rational operator+(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(Rational r1, Rational r2)
{
    return Rational(r1.num * r2.den, r1.den * r2.num);
}