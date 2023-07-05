/*
 * File: TreeFractal.cpp
 * ---------------------------------------
 * Picture drawn by Mark Wallinger a tree like Y-shaped, its branches
 * will continue to form two lines Y-shaped until a certain level.
 */

#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

static const int SCREEN_WIDTH = 1000;
static const int SCREEN_HEIGHT = 1000;
static const int FRACTAL_DEPTH = 9;
static const double BASE_X = SCREEN_WIDTH * 0.5;
static const double BASE_Y = SCREEN_HEIGHT * 0.8;
static const double TREE_LENGTH = 2.5;

void fractalTree(GWindow &gw, GPoint root, int level, double angle)
{
    if (level == 0)
        return;
    double x = root.x + cos(toRadians(angle)) * TREE_LENGTH * pow(sqrt(3), level);
    double y = root.y + sin(toRadians(angle)) * TREE_LENGTH * pow(sqrt(3), level);
    GPoint newPoint(x, y);
    gw.drawLine(root, newPoint);
    fractalTree(gw, newPoint, level - 1, angle - 45);
    fractalTree(gw, newPoint, level - 1, angle + 45);
}

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    gw.setColor("black");
    GPoint root(BASE_X, BASE_Y);
    fractalTree(gw, root, FRACTAL_DEPTH, -90);
    return 0;
}
