/*
 * Function: halfLife
 * -----------------------------------------------
 * Half-life is the length of time it takes for half of the radioactive
 * atoms of a specific radionuclide to decay
 */

#include <iostream>
#include "random/random.h"
#include "random/random.cpp"
using namespace std;

void halfLife(int startTime);
double atomsDecayProb();

int main()
{
    halfLife(10000);
    return 0;
}

void halfLife(int startAtom)
{
    cout << "There are " << startAtom << " atoms initially." << endl;
    int year = 0;
    while (startAtom != 0)
    {
        year++;
        double p = atomsDecayProb();
        startAtom *= p;
        cout << "There are " << startAtom << " at the end of year " << year << endl;
    }
}

double atomsDecayProb()
{
    initRandomSeed();
    while (true)
    {
        double prob = rand() / (double(RAND_MAX) + 1);
        if (prob > 0.4 && prob < 0.5)
            return prob;
    }
}