/*
 * File: gobjects.cpp
 * --------------------------------------------
 * The file implements classes in the gobjects interface
 */

#include <string>
#include <iostream>
#include "../string/strlib.h"
#include "../string/strlib.cpp"
#include "gobjects.h"
using namespace std;

/* Point implementation */

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double xc, double yc)
{
    x = xc;
    y = yc;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

string Point::toString()
{
    return "(" + doubleToString(x) + ", " + doubleToString(y) + ")";
}

ostream &operator<<(ostream &os, Point pt)
{
    return os << pt.toString();
}

bool operator==(Point p1, Point p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(Point p1, Point p2)
{
    return !(p1 == p2);
}

bool operator>(Point p1, Point p2)
{
    return (p1.x > p2.x || (p1.x == p2.x && p1.y > p2.y));
}

bool operator>=(Point p1, Point p2)
{
    return p1 == p2 || p1 > p2;
}

bool operator<(Point p1, Point p2)
{
    return p1 < p2;
}

bool operator<=(Point p1, Point p2)
{
    return p1 < p2 || p1 == p2;
}

Point operator*(Point &p, double scale)
{
    return Point(p.x * scale, p.y * scale);
}

/* Rectangle implementation */

Rectangle::Rectangle(double xp, double yp, double width, double height)
{
    x = xp;
    y = yp;
    w = width;
    h = height;
}

Rectangle::Rectangle(Point p, double width, double height)
{
    x = p.x;
    y = p.y;
    w = width;
    h = height;
}

Rectangle::Rectangle(double xp, double yp)
{
    x = xp;
    y = yp;
    w = 0;
    h = 0;
}

Rectangle::Rectangle(Point p)
{
    x = p.x;
    y = p.y;
    w = 0;
    h = 0;
}

double Rectangle::getX()
{
    return x;
}

double Rectangle::getY()
{
    return y;
}

double Rectangle::getWidth()
{
    return w;
}

double Rectangle::getHeight()
{
    return h;
}

Point Rectangle::getPoint()
{
    return Point(x, y);
}

string Rectangle::toString()
{
    return "(" + doubleToString(x) + ", " + doubleToString(y) + ", " + doubleToString(w) + ", " + doubleToString(h) + ")";
}

bool Rectangle::contains(double xp, double yp)
{
    return (xp >= x && yp >= y) && (xp <= x + w && yp <= y + h);
}

bool Rectangle::contains(Point p)
{
    return contains(p.x, p.y);
}

bool Rectangle::contains(Rectangle rect)
{
    return contains(rect.x, rect.y) && contains(rect.x + rect.w - 1, rect.y + rect.h - 1);
}

Rectangle Rectangle::enlargeBy(double amount)
{
    return Rectangle(x - amount, y - amount, w + 2 * amount, h + 2 * amount);
}

bool Rectangle::intersect(Rectangle rect)
{
    return !(rect.x > x + w || rect.y > y + h || rect.x + rect.w < x || rect.y + rect.h < y);
}

bool Rectangle::isEmpty()
{
    return w <= 0 || h <= 0;
}

ostream &operator<<(ostream &os, Rectangle rect)
{
    return os << rect.toString();
}

bool operator==(Rectangle r1, Rectangle r2)
{
    return r1.x == r2.x && r1.y == r2.y && r1.w == r2.w && r1.h == r2.h;
}

bool operator!=(Rectangle r1, Rectangle r2)
{
    return !(r1 == r2);
}

bool operator<(Rectangle r1, Rectangle r2)
{
    return (r1.x < r1.x && r1.y < r1.y) || (r1.x == r1.x && r1.y == r1.y && r1.w < r2.w && r1.h < r2.w);
}

bool operator>(Rectangle r1, Rectangle r2)
{
    return r1 > r2;
}

bool operator<=(Rectangle r1, Rectangle r2)
{
    return r1 < r2 || r1 == r2;
}

bool operator>=(Rectangle r1, Rectangle r2)
{
    return r1 > r2 || r1 == r2;
}