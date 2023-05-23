/*
 * File: direction.cpp
 * ------------------------------------------------------
 * This implements direction.h interface
 */

#include <string>
#include "direction.h"
using namespace std;

/*
 * Implmentation notes: leftFrom, rightFrom
 * ------------------------------------------------------
 * These functions use the remainder operator to cycle through
 * the internal values of the enumerated type. leftFrom function
 * cannot subtract 1 which leads to negative, instead adding 3
 * would be better as it ensures values remain positive
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
 * Implmentation notes: directionToString
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