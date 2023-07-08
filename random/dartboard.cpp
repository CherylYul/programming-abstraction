/*
 * File: dartboard
 * -----------------------------------------------
 * Simulates the actions of throw a whole bunch of darts completely randomly,
 * (Monte Carlo integration techniques) to a dartboard that consists of a circle
 * on a square backdrop.
 * The results will be approximate to:
 *      darts falling inside the circle   area inside circle   πr^2    π
 *      ------------------------------- = ------------------ = ---- = ---
 *      darts falling inside the square   area inside square   4r^2    4
 */

#include <iostream>
#include <cmath>
#include "library/graphics/gobjects.h"
#include "library/graphics/gobjects.cpp"
#include "random.h"
#include "random.cpp"
using namespace std;

void dartboardSimulation(int boardLength);
double EuclideanDistance(double x, double y);
Point randomPoint(int range);

int main()
{
    dartboardSimulation(2);
    return 0;
}

void dartboardSimulation(int boardLength)
{
    int insideCircle = 0;
    double radius = boardLength / 2;
    for (int i = 0; i < 10000; i++)
    {
        Point pt = randomPoint(boardLength);
        if (EuclideanDistance(pt.x, pt.y) <= radius)
            insideCircle++;
    }
    cout << double(insideCircle) / 10000 << endl;
}

Point randomPoint(int range)
{
    initRandomSeed();
    double x_coor = (rand() / (double(RAND_MAX) + 1)) * range - range / 2;
    double y_coor = (rand() / (double(RAND_MAX) + 1)) * range - range / 2;
    Point pt(x_coor, y_coor);
    return pt;
}

double EuclideanDistance(double x, double y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}