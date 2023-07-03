/*
 * File: maze.h
 * ---------------------------------------
 * This interface exports the maze class
 */

#ifndef _maze_h
#define _maze_h
#include <string>
#include "../library/graphics/gobjects.h"
#include "../library/graphics/gobjects.cpp"
#include "../library/direction.h"
#include "../library/direction.cpp"
#include "grid.h"
#include "gwindow.h"
/*
 * Class: Maze
 * ---------------------------------------
 * Represents 2-dim maze contained in a rectangular grid of squares. Characters
 * '+', '-' and '|' represent corners, horizontal walls and vertical walls. Spaces
 * represent open passageway squares. The starting position is indicated by 'S':
 *      +-+-+-+-+-+
 *      |     |
 *      + +-+ + +-+
 *      |S  |     |
 *      +-+-+-+-+-+
 */

class Maze
{
public:
    /*
     * Constructor: Maze
     * Usage: Maze maze(filename);
     *        Maze maze(filename, gw);
     * ---------------------------------------
     * Constructs a new maze by reading the specified data file. If the second argument
     * is supplied, the maze is displayed in the center of graphics window.
     */
    Maze(std::string filename);
    Maze(std::string filename, GWindow &gw);

    Point getStartPosition();
    bool isOutside(Point pt);
    bool wallExists(Point pt, Direction dir);
    void markSquare(Point pt);
    void unmarkSquare(Point pt);
    bool isMarked(Point pt);
};

#endif