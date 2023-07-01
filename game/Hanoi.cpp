/*
 * File: Hanoi.cpp
 * ---------------------------------------
 * This program solves the Tower of Hanoi puzzle. The goal is moving
 * all the n disks from colA to colC
 */

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void moveTowerRecursion(int n, char colA, char colB, char temp);
void moveTowerStack(int n, char colA, char colB, char temp);
void transferDisk(stack<int> &firstCol, char &name1, stack<int> &secondCol, char &name2);
void moveSingleDisk(char firstCol, char secondCol);
int countHanoiMoves(int disks);
void oddCase(int num, stack<int> &colSource, stack<int> &colDest, stack<int> &colAux,
             char &colA, char &colB, char &temp);
void evenCase(int num, stack<int> &colSource, stack<int> &colDest, stack<int> &colAux,
              char &colA, char &colB, char &temp);

int main()
{
    moveTowerStack(4, 'A', 'C', 'B');
    return 0;
}

/*
 * Function: moveTowerRecursion, moveTowerStack
 * Usage: moveTowerRecursion(n, colA, colB, temp);
 *        moveTowerStack(n, colA, colB, temp);
 * ---------------------------------------
 * Moves a tower of size n from column A spire to column B spire using column
 * temp spire as a temporary repository.
 */

void moveTowerRecursion(int n, char colA, char colB, char temp)
{
    if (n == 0)
        return;
    if (n == 1)
        moveSingleDisk(colA, colB);
    else
    {
        moveTowerRecursion(n - 1, colA, temp, colB);
        moveSingleDisk(colA, colB);
        moveTowerRecursion(n - 1, temp, colB, colA);
    }
}

void moveTowerStack(int n, char colA, char colB, char temp)
{
    stack<int> colSource;
    stack<int> colDest;
    stack<int> colAux;
    int num = countHanoiMoves(n);
    for (int i = n; i > 0; i--)
        colSource.push(i);
    if (n % 2 == 0)
        evenCase(num, colSource, colDest, colAux, colA, colB, temp);
    else
        oddCase(num, colSource, colDest, colAux, colA, colB, temp);
}

void oddCase(int num, stack<int> &colSource, stack<int> &colDest, stack<int> &colAux,
             char &colA, char &colB, char &temp)
{
    for (int i = 0; i < num; i++)
    {
        if (i % 3 == 0)
            transferDisk(colSource, colA, colDest, colB);
        else if (i % 3 == 1)
            transferDisk(colSource, colA, colAux, temp);
        else
            transferDisk(colAux, temp, colDest, colB);
    }
}

void evenCase(int num, stack<int> &colSource, stack<int> &colDest, stack<int> &colAux,
              char &colA, char &colB, char &temp)
{
    for (int i = 0; i < num; i++)
    {
        if (i % 3 == 0)
            transferDisk(colSource, colA, colAux, temp);
        else if (i % 3 == 1)
            transferDisk(colSource, colA, colDest, colB);
        else
            transferDisk(colAux, temp, colDest, colB);
    }
}

/*
 * Function: transferDisk
 * Usage: transferDisk(firstCol, name1, secondCol, name2));
 * ---------------------------------------
 * Number of moves required to solve the Towers of Hanoi puzzle for n disks
 */

void transferDisk(stack<int> &firstCol, char &name1, stack<int> &secondCol, char &name2)
{
    if (secondCol.empty() || (!firstCol.empty() && secondCol.top() > firstCol.top()))
    {
        secondCol.push(firstCol.top());
        firstCol.pop();
        moveSingleDisk(name1, name2);
    }
    else
    {
        firstCol.push(secondCol.top());
        secondCol.pop();
        moveSingleDisk(name2, name1);
    }
}

/*
 * Function: moveSingleDisk
 * Usage: moveSingleDisk(firstCol, secondCol);
 * ---------------------------------------
 * Executes the transfer of a single disk from first column to second column
 */

void moveSingleDisk(char firstCol, char secondCol) { cout << firstCol << " -> " << secondCol << endl; }

/*
 * Function: countHanoiMoves
 * Usage: int n = countHanoiMoves(disks);
 * ---------------------------------------
 * Number of moves required to solve the Towers of Hanoi puzzle for n disks
 */

int countHanoiMoves(int disks) { return pow(2, disks) - 1; }