/*
 * File: direction.h
 * ------------------------------------------------------
 * This interface exports an enumerated type called Direction whose elements
 * are the 4 compass points: NORTH, EAST, SOUTH, WEST
 */

#ifndef _direction_h
#define _direction_h
#include <string>

enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

Direction leftFrom(Direction dir);
Direction rightFrom(Direction dir);
std::string directionToString(Direction dir);
std::ostream &operator<<(std::ostream &os, Direction dir);
Direction operator++(Direction &dir);
Direction operator++(Direction &dir, int);

#endif