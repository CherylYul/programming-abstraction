/*
 * File: Coastline.cpp
 * ---------------------
 * This program draws a coastline of a constant depth on the screen.
 */

#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "gobjects.h"
#include "random.h"
using namespace std;

static const double COS_60 = 0.5;
static const double SIN_60 = sqrt(3) * 0.5;
static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = SCREEN_WIDTH;
static const int FRACTAL_DEPTH = 4;
static const double BASE_X_LEFT = SCREEN_WIDTH * 0.2;
static const double BASE_X_RIGHT = SCREEN_WIDTH - SCREEN_WIDTH * 0.2;
static const double BASE_Y = SCREEN_HEIGHT * 0.5;

void drawCoastline(GWindow &gw, GPoint start, GPoint end, int level);
GPoint thirdEquilateralPoint(GPoint bottomLeft, GPoint otherPoint);
GPoint pointBetween(GPoint left, GPoint right, double fraction);

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    gw.setColor("black");
    GPoint start(BASE_X_LEFT, BASE_Y);
    GPoint end(BASE_X_RIGHT, BASE_Y);
    drawCoastline(gw, start, end, FRACTAL_DEPTH);
    return 0;
}

void drawCoastline(GWindow &gw, GPoint start, GPoint end, int level)
{
    if (level == 0) {
        gw.drawLine(start, end);
    }
    else
    {
        GPoint a = pointBetween(start, end, 1.0 / 3);
        GPoint b = pointBetween(start, end, 2.0 / 3);
        GPoint t = thirdEquilateralPoint(a, b);
        drawCoastline(gw, start, a, level - 1);
        drawCoastline(gw, a, t, level - 1);
        drawCoastline(gw, t, b, level - 1);
        drawCoastline(gw, b, end, level - 1);
    }
}

GPoint thirdEquilateralPoint(GPoint bottomLeft, GPoint otherPoint)
{
    double deltaX = otherPoint.x - bottomLeft.x;
    double deltaY = otherPoint.y - bottomLeft.y;
    double x = bottomLeft.x + (COS_60 * deltaX + deltaY * SIN_60);
    double y;
    if (randomChance(.50))
        y = bottomLeft.y + (deltaY * COS_60 - SIN_60 * deltaX);
    else
        y = bottomLeft.y - (deltaY * COS_60 - SIN_60 * deltaX);
    GPoint newPoint(x, y);
    return newPoint;
}

GPoint pointBetween(GPoint left, GPoint right, double fraction)
{
    double deltaX = right.x - left.x;
    double deltaY = right.y - left.y;
    double x = left.x + fraction * deltaX;
    double y = left.y + fraction * deltaY;
    GPoint newPoint(x, y);
    return newPoint;
}
