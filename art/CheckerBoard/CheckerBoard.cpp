/*
 * File: CheckerBoard.cpp
 * -----------------------------------------------
 * This program draws a checker board based on graphics.h library on
 * Qt framework
 */

#include <iostream>
#include "gwindow.h"
using namespace std;

static const int TILES = 50;
static const int PIECES = 40;
static const int SCREEN_WIDTH = TILES * 8;
static const int SCREEN_HEIGHT = SCREEN_WIDTH;
void drawCheckerBoard(GWindow &gw);
void putPieces(GWindow &gw);

int main()
{
    GWindow gw(SCREEN_WIDTH, SCREEN_HEIGHT);
    drawCheckerBoard(gw);
    return 0;
}

void drawCheckerBoard(GWindow &gw) {
    bool tileCol = false;
    for (int x = 0; x < SCREEN_WIDTH; x += TILES) {
        tileCol = !tileCol;
        for (int y = 0; y < SCREEN_HEIGHT; y += TILES) {
            if (tileCol)
                gw.setColor("white");
            else {
                gw.setColor("lightgray");
                gw.fillRect(x, y, TILES, TILES);
                if (y < 150) {
                    gw.setColor("red");
                    gw.fillOval(x + 5, y + 5, PIECES, PIECES);
                }
                if (y > 200) {
                    gw.setColor("black");
                    gw.fillOval(x + 5, y + 5, PIECES, PIECES);
                }
            }
            tileCol = !tileCol;
        }
    }
}


