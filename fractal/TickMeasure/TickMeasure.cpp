/*
 * File: TickMeasure.cpp
 * ------------------------------------------
 * This program draws a ruler with longest tick mark falls half-inch position,
 * 2 smaller tick marks indicate the quarter inches, and even smaller ones.
 */

#include <iostream>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

static const double SCREEN_WIDTH = 500;
static const double SCREEN_HEIGHT = SCREEN_WIDTH;
static const double TICK_LENGTH = 10;
static const double MIN_LENGTH = 5;
static const double BASE_X_LEFT = SCREEN_WIDTH * 0.2;
static const double BASE_X_RIGHT = SCREEN_WIDTH - SCREEN_WIDTH * 0.2;
static const double BASE_Y = SCREEN_HEIGHT * 0.5;
static const int FRACTAL_DEPTH = 5;

void drawTick(GWindow &gw, GPoint start, GPoint end, int level);
GPoint midPoint(GPoint left, GPoint right);

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    gw.setColor("Black");
    gw.drawLine(BASE_X_LEFT, BASE_Y, BASE_X_RIGHT, BASE_Y);
    GPoint start(BASE_X_LEFT, BASE_Y);
    GPoint end(BASE_X_RIGHT, BASE_Y);
    drawTick(gw, start, end, FRACTAL_DEPTH);
    return 0;
}

void drawTick(GWindow &gw, GPoint start, GPoint end, int level)
{
    if (level == 0)
        return;
    GPoint mid = midPoint(start, end);
    gw.drawLine(mid.x, mid.y, mid.x, mid.y - (TICK_LENGTH * level));
    drawTick(gw, start, mid, level - 1);
    drawTick(gw, mid, end, level - 1);
    pause(500);
}

GPoint midPoint(GPoint left, GPoint right)
{
    double mid = (right.x - left.x) / 2;
    GPoint newPoint(left.x + mid, left.y);
    return newPoint;
}
