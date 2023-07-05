/*
 * File: YinYang.cpp
 * --------------------------------
 * This is a graphics program that draws a YinYang symbols
 */

#include <iostream>
#include "gwindow.h"
using namespace std;

static const int SCREEN_WIDTH = 500;
static const int SCREEN_HEIGHT = SCREEN_WIDTH;
static const double DIAMETER = 300;
static const double HALF_DIAMETER = DIAMETER * 0.5;
static const double SMALL_DIAMETER = DIAMETER * 0.1;
static const double BASE_X = (SCREEN_WIDTH - DIAMETER) * 0.5;
static const double BASE_Y = BASE_X;

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    // draw semi-circle
    gw.setColor("black");
    gw.drawOval(BASE_X, BASE_Y, DIAMETER, DIAMETER);
    gw.fillArc(BASE_X, BASE_Y, DIAMETER, DIAMETER, -90, 180);
    // draw half-circle
    double x = BASE_X + (DIAMETER - HALF_DIAMETER) * 0.5;
    gw.fillOval(x, BASE_Y + HALF_DIAMETER, HALF_DIAMETER, HALF_DIAMETER);
    gw.setColor("white");
    gw.fillOval(x, BASE_Y, HALF_DIAMETER, HALF_DIAMETER);
    // draw small-circle
    x = BASE_X + (DIAMETER - SMALL_DIAMETER) * 0.5;
    gw.fillOval(x, BASE_Y + SMALL_DIAMETER * 7, SMALL_DIAMETER, SMALL_DIAMETER);
    gw.setColor("black");
    gw.fillOval(x, BASE_Y + SMALL_DIAMETER * 2, SMALL_DIAMETER, SMALL_DIAMETER);
    return 0;
}
