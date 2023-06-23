/*
 * File: direction.cpp
 * ------------------------------------------------------
 * This implements direction.h interface
 */

#include <string>
#include "direction.h"
using namespace std;

/*
 * Function: leftFrom, rightFrom
 * Usage: Direction newdir = leftFrom(dir);
 *        Direction newdir = rightFrom(dir);
 * ------------------------------------------------------
 * Returns the direction to the left or right of the argument
 * Ex: leftFrom(SOUTH) will return EAST
 */

Direction leftFrom(Direction dir)
{
    return Direction((dir + 3) % 4);
}

Direction rightFrom(Direction dir)
{
    return Direction((dir + 1) % 4);
}

/*
 * Function: directionToString
 * Usage: string str = directionToString(dir);
 * ------------------------------------------------------
 * Default clause to make function return a string
 */

string directionToString(Direction dir)
{
    switch (dir)
    {
    case NORTH:
        return "NORTH";
    case EAST:
        return "EAST";
    case SOUTH:
        return "SOUTH";
    case WEST:
        return "WEST";
    default:
        return "???";
    }
}

ostream &operator<<(ostream &os, Direction dir)
{
    return os << directionToString(dir);
}

/*
 * Operators: ++
 * Usage: for (Direction dir = NORTH; dir <= WEST; dir++) ...
 * ------------------------------------------------------
 * Overload the prefix and suffix ++ to make dir++ work
 */

Direction operator++(Direction &dir)
{
    dir = Direction(dir + 1);
    return dir;
}

Direction operator++(Direction &dir, int)
{
    Direction old = dir;
    dir = Direction(dir + 1);
    return old;
}