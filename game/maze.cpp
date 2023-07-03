/*
 * File: maze.cpp
 * ---------------------------------------
 * Implements maze.h interface
 */

#include <iostream>
#include "maze.h"
using namespace std;

/*
 * Function: solveMaze
 * Usage: solveMaze(maze, start);
 * ---------------------------------------
 * Attempts to generate a solution to the current maze with specified start
 * point. It returns true when finding solution. Use recursion to solve
 * submazes resulting from marking the current square and moving 1 step
 * along each open passage.
 */

bool solveMaze(Maze &maze, Point start)
{
    if (maze.isOutside(start))
        return true;
    if (maze.isMarked(start))
        return false;
    maze.markSquare(start);
    for (Direction dir = NORTH; dir <= WEST; dir++)
    {
        if (!maze.wallExists(start, dir))
            if (solveMaze(maze, adjacentPoint(start, dir)))
                return true;
    }
    maze.unmarkSquare(start);
    return false;
}

/*
 * Function: adjacentPoint
 * Usage: Point finish = adjacentPoint(start, dir);
 * ---------------------------------------
 * Returns the point that results from moving one square from start in the
 * direction specified by dir.
 * Ex: pt(1,1) calling adjacentPoint(pt, EAST) returns pt(2, 1)
 * To maintain the consistency with graphic package, y coor - when moving
 * NORTH and y coor + when moving SOUTH
 */

Point adjacentPoint(Point start, Direction dir)
{
    switch (dir)
    {
    case NORTH:
        return Point(start.getX(), start.getY() - 1);
    case EAST:
        return Point(start.getX() + 1, start.getY());
    case SOUTH:
        return Point(start.getX(), start.getY() + 1);
    case WEST:
        return Point(start.getX() - 1, start.getY());
    }
    return start;
}