/*
 * File: random.cpp
 * ------------------------------------------------------
 * This file implements a random.h interface
 */

#include <cstdlib>
#include <cmath>
#include <ctime>
#include "random.h"
using namespace std;

/* Private function prototype */
void initRandomSeed();

/*
 * Implement notes: randomInteger
 * ------------------------------------------------------
 * Produce number in 4 steps:
 * 1. Generate random real number d in range [0...1)
 * 2. Scale number to range [0...N), N is the number of value
 * 3. Translate the number to range starts at the appropriate value
 * 4. Convert result to the next lower integer
 * The implementation is complicated because RAND_MAX + 1 and high-low+1
 * can overflow the integer range. These calculations must therefore be
 * performed using doubles instead of ints
 */

int randomInteger(int low, int high)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return int(floor(low + s));
}

/*
 * Implementation notes: randomReal
 * ------------------------------------------------------
 * The code for randomReal is similar to that for randomInteger,
 * without the final conversion step
 */

double randomReal(double low, double high)
{
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (double(high) - low + 1);
    return low + s;
}

/*
 * Implementation notes: randomReal
 * ------------------------------------------------------
 * The code for randomAverage calls randomReal(0, 1) trials times then
 * return average values
 */

double randomAverage(int trials)
{
    initRandomSeed();
    double result = 0;
    for (int i = 0; i < trials; i++)
    {
        double d = rand() / (double(RAND_MAX) + 1);
        result += d;
    }
    return result / trials;
}

/*
 * Implementation notes: randomChance
 * ------------------------------------------------------
 * The code for randomChance calls randomReal(0, 1) and then
 * checks whether the result is less than the requested probability
 */

bool randomChance(int p)
{
    initRandomSeed();
    return randomReal(0, 1) < p;
}

/*
 * Implementation notes: setRandomSeed
 * ------------------------------------------------------
 * The setRandomSeed function simply forwards its argument to srand.
 * The call to initRandomSeed is required to set the initialized flag
 */

void setRandomSeed(int seed)
{
    initRandomSeed();
    srand(seed);
}

/*
 * Implementation notes: initRandomSeed
 * ------------------------------------------------------
 * Declares a static variables that keeps track of whether the
 * seed has been initialized. The first time initRandomSeed is called
 * initialized is false, so the seed is set to current time
 */

void initRandomSeed()
{
    static bool initialized = false;
    if (!initialized)
    {
        srand(int(time(NULL)));
        initialized = true;
    }
}
