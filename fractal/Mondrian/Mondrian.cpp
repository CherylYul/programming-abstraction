/*
 * File: Mondrian.cpp
 * ---------------------------------------
 * This program creates a line drawing in a style reminiscent of Mondrian.
 */

#include <iostream>
#include <vector>
#include "random.h"
#include "gwindow.h"
#include "gobjects.h"
using namespace std;

static const double SCREEN_WIDTH = 700;
static const double SCREEN_HEIGHT = 500;
static const double LINE_HEIGHT = 10;
static const double MIN_AREA = 10000; /* smallest square that will be split */
static const double MIN_EDGE = 20;    /* smallest edge length allowed */
vector<string> RECT_COLOR = {"cyan", "brown", "magenta", "lightgray", "orange", "darkgray", "yellow", "blue", "purple", "green"};
int COLOR_INDEX = 0;

void subdivideCanvas(GWindow &gw, double x, double y, double width, double height);
void drawThickLine(GWindow &gw, double x, double y, double width, double height);
void fillRect(GWindow &gw, double x, double y, double width, double height);

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    gw.setBackground("white");
    gw.setColor("black");
    subdivideCanvas(gw, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    return 0;
}

/*
 * Function: subdivideCanvas
 * Usage: subdivideCanvas(gw, x, y, width, height);
 * ---------------------------------------
 * Decomposes the specified rectangular region on the canvas recursively by
 * splitting that rectangle randomly along its larger dimension. The recursion
 * continues until the area falls below the constant MIN_AREA
 */

void subdivideCanvas(GWindow &gw, double x, double y, double width, double height)
{
    if (width * height >= MIN_AREA)
    {
        if (width > height)
        {
            double mid = randomReal(MIN_EDGE, width - MIN_EDGE);
            subdivideCanvas(gw, x, y, mid, height);
            subdivideCanvas(gw, x + mid + LINE_HEIGHT, y, width - mid - LINE_HEIGHT, height);
            // gw.drawLine(x + mid, y, x + mid, y + height);
            drawThickLine(gw, x + mid, y, LINE_HEIGHT, height);
        }
        else
        {
            double mid = randomReal(MIN_EDGE, height - MIN_EDGE);
            subdivideCanvas(gw, x, y, width, mid);
            subdivideCanvas(gw, x, y + mid + LINE_HEIGHT, width, height - mid - LINE_HEIGHT);
            // gw.drawLine(x, y + mid, x + width, y+mid);
            drawThickLine(gw, x, y + mid, width, LINE_HEIGHT);
        }
        pause(500);
    } else
        fillRect(gw, x, y, width, height);
}

void drawThickLine(GWindow &gw, double x, double y, double width, double height) {
    GRect *rect = new GRect(0, 0, width, height);
    rect->setFilled(true);
    gw.add(rect, x, y);
}

void fillRect(GWindow &gw, double x, double y, double width, double height) {
    GRect *rect = new GRect(0, 0, width, height);
    if (COLOR_INDEX > 9)
        COLOR_INDEX = 0;
    else
        COLOR_INDEX++;
    rect->setFillColor(RECT_COLOR[COLOR_INDEX]);
    gw.add(rect, x, y);
}
