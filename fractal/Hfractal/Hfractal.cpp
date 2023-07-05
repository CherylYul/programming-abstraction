/*
 * File: Hfractal.cpp
 * ---------------------------------------
 * H-fractal, the repeated pattern is shaped like an elongated letter H
 * in which the horizontal bar and vertical lines on the sides have the
 * same length.
 */

#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

static const int SCREEN_WIDTH = 500;
static const int SCREEN_HEIGHT = 500;
static const int H_SIZE = 20;
static const int FRACTAL_DEPTH = 3;
static const double BASE_X = SCREEN_WIDTH * 0.5;
static const double BASE_Y = SCREEN_HEIGHT * 0.5;

void drawHFractal(GWindow &gw, GPoint mid, int level);

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    gw.setColor("black");
    GPoint mid(BASE_X, BASE_Y);
    drawHFractal(gw, mid, FRACTAL_DEPTH);
    return 0;
}

void drawHFractal(GWindow &gw, GPoint mid, int level)
{
    if (level == 0)
        return;
    double halfSize = H_SIZE * pow(2, level) * 0.5;
    // draw the horizontal line
    GPoint left(mid.x - halfSize, mid.y);
    GPoint right(mid.x + halfSize, mid.y);
    gw.drawLine(left, right);
    // draw the left vertical line
    GPoint leftTop(left.x, left.y - halfSize);
    GPoint leftBottom(left.x, left.y + halfSize);
    gw.drawLine(leftTop, leftBottom);
    // draw the right horizontal line
    GPoint rightTop(right.x, right.y - halfSize);
    GPoint rightBottom(right.x, right.y + halfSize);
    gw.drawLine(rightTop, rightBottom);
    // recursion
    drawHFractal(gw, leftTop, level - 1);
    drawHFractal(gw, leftBottom, level - 1);
    drawHFractal(gw, rightTop, level - 1);
    drawHFractal(gw, rightBottom, level - 1);
}
