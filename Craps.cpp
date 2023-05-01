/*
 * Function: Craps.cpp
 * ------------------------------------------------------
 * This program plays the casino game called craps, which is
 * played using a pair of dice. At the beginning of the game,
 * we roll the dice and compute the total. If we first roll
 * is 7 or 11, we win what glambers call a "natural"
 * If we roll is 2, 3 or 12 we lose by crapping out. In other
 * cases, the first roll becomes point. We will continue roll
 * the dice until
 * - We roll a point again, we win
 * - We roll a 7, we lose
 * Other rolls, 2, 3, 11 and 12 have no effect during this phase
 * of the game
 */

#include <iostream>
#include "random.h"
using namespace std;

/* Function prototype */

bool tryToMakePoint(int Point);
int rollTwoDice();

/* Main program */

int main()
{
    cout << "This program plays a game of craps." << endl;
    int point = rollTwoDice();
    switch (point)
    {
    case 7:
    case 11:
        cout << "That's a natural. You win." << endl;
    case 2:
    case 3:
    case 12:
        cout << "That's craps. You lose." << endl;
        break;
    default:
        cout << "Your point is " << point << "." << endl;
        if (tryToMakePoint(point))
        {
            cout << "You made your point. You win." << endl;
        }
        else
        {
            cout << "You rolled a seven. You lose." << endl;
        }
    }
    return 0;
}

/*
 * Function: tryToMakePoint
 * Usage: flag = tryToMakePoint(point);
 * ------------------------------------------------------
 * Rolls the dice repeatedly until you either make your point
 * or roll a 7. Return true when make your point, false when
 * roll to a 7
 */

bool tryToMakePoint(int point)
{
    while (true)
    {
        int total = rollTwoDice();
        if (total == point)
            return true;
        if (total == 7)
            return false;
    }
}

/*
 * Function rollTwoDice
 * Usage: total = rollTwoDice();
 * ------------------------------------------------------
 * Simulate the process of rolling 2 dice
 */

int rollTwoDice()
{
    cout << "Rolling the dice..." << endl;
    int d1 = randomInteger(1, 6);
    int d2 = randomInteger(1, 6);
    int total = d1 + d2;
    cout << "You rolled " << d1 << " and " << d2 << " - that's "
         << total << endl;
    return total;
}