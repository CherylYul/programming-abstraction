/*
 * File: gobjects.h
 * --------------------------------------------
 * This interfaces defines the points, dimensions and rectangles
 */

#ifndef _gobjects_h
#define _gobjects_h
#include <string>

class Point
{
public:
    /*
     * Constructor: Point
     * Usage: Point origin;
     *        Point pt(xc, yc);
     * --------------------------------------------
     * 1. Default constructor sets the coordinates to 0
     * 2. Sets the coordinates to xc and yc
     */

    Point();
    Point(double xc, double yc);

    /*
     * Methods: getX, getY
     * Usage: int x = pt.getX();
     *        int y = pt.getY();
     * --------------------------------------------
     * These methods returns the x and y coordinates of the point
     */

    double getX();
    double getY();

    /*
     * Method: toString
     * Usage: string str = pt.toString();
     * --------------------------------------------
     * Returns a string representation of the Point in the form "(x, y)"
     */

    std::string toString();

    /* Friend declaration */

    double x;
    double y;

private:
    friend bool operator==(Point p1, Point p2);
    friend bool operator>(Point p1, Point p2);
    friend Point operator*(Point &p, double scale);
};

std::ostream &operator<<(std::ostream &os, Point pt);
bool operator==(Point p1, Point p2);
bool operator!=(Point p1, Point p2);
bool operator>=(Point p1, Point p2);
bool operator<=(Point p1, Point p2);
bool operator>(Point p1, Point p2);
bool operator<(Point p1, Point p2);
Point operator*(Point &p, double scale);

class Rectangle
{
public:
    Rectangle(double xp, double yp, double width, double height);
    Rectangle(Point p, double width, double height);
    Rectangle(double xp, double yp);
    Rectangle(Point p);

    double getX();
    double getY();
    double getWidth();
    double getHeight();
    Point getPoint();
    std::string toString();

    bool contains(double xp, double yp);
    bool contains(Point p);
    bool contains(Rectangle rect);

    Rectangle enlargeBy(double amount);
    bool intersect(Rectangle rect);
    bool isEmpty();

private:
    double x;
    double y;
    double w;
    double h;
    friend bool operator==(Rectangle r1, Rectangle r2);
    friend bool operator!=(Rectangle r1, Rectangle r2);
    friend bool operator<(Rectangle r1, Rectangle r2);
    friend bool operator>(Rectangle r1, Rectangle r2);
    friend bool operator<=(Rectangle r1, Rectangle r2);
    friend bool operator>=(Rectangle r1, Rectangle r2);
};

std::ostream &operator<<(std::ostream &os, Rectangle rect);
bool operator==(Rectangle r1, Rectangle r2);
bool operator!=(Rectangle r1, Rectangle r2);
bool operator<(Rectangle r1, Rectangle r2);
bool operator>(Rectangle r1, Rectangle r2);
bool operator<=(Rectangle r1, Rectangle r2);
bool operator>=(Rectangle r1, Rectangle r2);

#endif