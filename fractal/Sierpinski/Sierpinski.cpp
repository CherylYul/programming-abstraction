/*
 * File: Sierpinski Triangle
 * ---------------------------------------
 * Draw the Sierpinski Triangle fractal
 */

#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;
static const int SCREEN_WIDTH = 500;
static const int SCREEN_HEIGHT = 500;
static const int TRIANGLE_EDGE = 300;
static const double BASE_X = (SCREEN_WIDTH - TRIANGLE_EDGE) * 0.5;
static const double BASE_Y = SCREEN_HEIGHT * 0.5 + TRIANGLE_EDGE * sqrt(3) * 0.25;
static const int FRACTAL_DEPTH = 5;

void subdivideTriangle(GWindow & gw, GPoint p1, GPoint p2, GPoint p3, int level);
GPoint midPoint(GPoint &p1, GPoint &p2);

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    gw.setColor("black");
    GPoint p1(BASE_X, BASE_Y);
    GPoint p2 = gw.drawPolarLine(p1, TRIANGLE_EDGE, 0);
    GPoint p3 = gw.drawPolarLine(p2, TRIANGLE_EDGE, 120);
    gw.drawPolarLine(p3, TRIANGLE_EDGE, -120);
    subdivideTriangle(gw, p1, p2, p3, FRACTAL_DEPTH);
    return 0;
}

void subdivideTriangle(GWindow & gw, GPoint p1, GPoint p2, GPoint p3, int level) {
    if (level == 0) return;

    GPoint p12 = midPoint(p1, p2);
    GPoint p23 = midPoint(p2, p3);
    GPoint p31 = midPoint(p3, p1);

    gw.drawLine(p12, p23);
    gw.drawLine(p23, p31);
    gw.drawLine(p31, p12);

    subdivideTriangle(gw, p1, p12, p31, level - 1);
    subdivideTriangle(gw, p12, p2, p23, level - 1);
    subdivideTriangle(gw, p31, p23, p3, level - 1);
}

GPoint midPoint(GPoint &p1, GPoint &p2) {
    double x = (p1.x + p2.x) * 0.5;
    double y = (p1.y + p2.y) * 0.5;
    GPoint newPoint(x,y);
    return newPoint;
}
