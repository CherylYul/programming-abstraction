/*
 * File: random.h
 * ------------------------------------------------------
 * The interface exports function for generating pseudorandom numbers
 */

#ifndef _random_h
#define _random_h

/*
 * Function: randomInteger
 * Usage: int n = randomInteger(low, high);
 * ------------------------------------------------------
 * Returns a random integer in the range low to high
 */

int randomInteger(int low, int high);

/*
 * Function: randomReal
 * Usage: double n = randomReal(low, high);
 * ------------------------------------------------------
 * Returns a random real number in the half-open interval [low...high)
 * A half-open interval includes the first endpoint but not the second,
 * means that the result is greater than or equal to low but less than high
 */

double randomReal(double low, double high);

/*
 * Function: randomChance
 * Usage: if (randomChance(p)) ...
 * ------------------------------------------------------
 * Returns true with the probability indicated by p. The argument p is a
 * floating-point number between 0 (never) and 1 (always)
 */

bool randomChance(double p);

/*
 * Function: setRandomSeed
 * Usage: setRandomSeed(seed);
 * ------------------------------------------------------
 * Sets the internal random number seed to the specified value.
 * Use this function to specific starting point for the pseudorandom
 * sequence or to ensure that program behavior is repeatable during
 * the debugging phase
 */

void setRandomSeed(int seed);
#endif