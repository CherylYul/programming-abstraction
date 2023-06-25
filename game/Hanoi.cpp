/*
 * File: Hanoi.cpp
 * ---------------------------------------
 * This program solves the Tower of Hanoi puzzle. The goal is moving
 * all the n disks from colA to colC
 */

#include <iostream>
using namespace std;

void moveTower(int n, char colA, char colB, char temp);
void moveSingleDisk(char firstCol, char secondCol);

int main()
{
    moveTower(3, 'A', 'B', 'C');
    return 0;
}

/*
 * Function: moveTower
 * Usage: moveTower(n, colA, colB, temp);
 * ---------------------------------------
 * Moves a tower of size n from column A spire to column B spire using column
 * temp spire as a temporary repository.
 */

void moveTower(int n, char colA, char colB, char temp)
{
    if (n == 1)
        moveSingleDisk(colA, colB);
    else
    {
        moveTower(n - 1, colA, temp, colB);
        moveSingleDisk(colA, colB);
        moveTower(n - 1, temp, colB, colA);
    }
}

/*
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(firstCol, secondCol);
 * ---------------------------------------
 * Executes the transfer of a single disk from first column to second column
 */
void moveSingleDisk(char firstCol, char secondCol)
{
    cout << firstCol << " -> " << secondCol << endl;
}
