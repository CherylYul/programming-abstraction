/*
 * File: direction.h
 * ------------------------------------------------------
 * This interface exports an enumerated type called Direction
 * whose elements are the 4 compass points: NORTH, EAST, SOUTH, WEST
 */

#ifndef _direction_h
#define _direction_h
#include <string>

/*
 * Type: Direction
 * ------------------------------------------------------
 * This enumerated type is used to represent 4 compass direction
 */

enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

/*
 * Function: leftFrom
 * Usage: Direction newdir = leftFrom(dir);
 * ------------------------------------------------------
 * Returns the direction to the left of the argument
 * leftFrom(SOUTH) will return EAST
 */

Direction leftFrom(Direction dir);

/*
 * Function: rightFrom
 * Usage: Direction newdir = rightFrom(dir);
 * ------------------------------------------------------
 * Returns the direction to the right of the argument
 * leftFrom(SOUTH) will return WEST
 */

Direction rightFrom(Direction dir);

/*
 * Function: directionToString
 * Usage: string str = directionToString(dir);
 * ------------------------------------------------------
 * Returns the name of direction
 */

std::string directionToString(Direction dir);

std::ostream &operator<<(std::ostream &os, Direction dir);
Direction operator++(Direction &dir);
Direction operator++(Direction &dir, int);

#endif