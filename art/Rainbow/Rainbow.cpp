/*
 * File: Rainbow.cpp
 * -----------------------------------------------
 * This program draws a rainbow based on graphics.h library on
 * Qt framework
 */

#include <iostream>
#include <vector>
#include "gwindow.h"
using namespace std;

static const int SCREEN_WIDTH = 500;
static const int SCREEN_HEIGHT = SCREEN_WIDTH * 0.5;
static const int DIAMETER = SCREEN_WIDTH * 2;
static const int RAINBOW_WIDTH = 30;
static const int DEPTH = 6;
static const double BASE_X = -250;
vector<string> RAINBOW_COLOR = {"red", "orange", "yellow", "green", "blue", "white"};

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    for (int i = 0; i < DEPTH; i++) {
        gw.setColor(RAINBOW_COLOR[i]);
        gw.fillOval(BASE_X, RAINBOW_WIDTH * (i + 1), 1000, 1000);
    }
    return 0;
}
