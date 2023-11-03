/*
 * File: towerHanoi.cpp
 * ---------------------------------------
 * This program solves the Tower of Hanoi puzzle. The goal is moving
 * all the n disks from start column to finish column
 */

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

void moveTower(int n, char start, char finish, char temp);
void moveSingleDisk(char firstCol, char secondCol);
int countHanoiMoves(int disks);

void moveTowerStack(int n, char start, char finish, char temp);
void oddCase(int num, stack<int> &source, stack<int> &dest, stack<int> &aux,
             char &start, char &finish, char &temp);
void evenCase(int num, stack<int> &source, stack<int> &dest, stack<int> &aux,
              char &start, char &finish, char &temp);
void transferDisk(stack<int> &firstCol, char &first, stack<int> &secondCol, char &second);

int main()
{
    moveTower(3, 'A', 'B', 'C');
    moveTowerStack(3, 'A', 'B', 'C');
    return 0;
}

/*
 * Function: moveTower
 * Usage: moveTower(n, start, finish, temp);
 * ---------------------------------------
 * Using recursion method to move a tower of size n from start spire to
 * finish spire using temp spire as a temporary repository.
 */

void moveTower(int n, char start, char finish, char temp)
{
    if (n == 0)
        return;
    if (n == 1)
        moveSingleDisk(start, finish);
    else
    {
        moveTower(n - 1, start, temp, finish);
        moveSingleDisk(start, finish);
        moveTower(n - 1, temp, finish, start);
    }
}

void moveSingleDisk(char firstCol, char secondCol) { cout << firstCol << " -> " << secondCol << endl; }

/*
 * Function: moveTowerStack
 * Usage: moveTowerStack(n, start, finish, temp);
 * ---------------------------------------
 * Using stack to move a tower of size n from start spire to finish
 * spire using temp spire as a temporary repository.
 */

void moveTowerStack(int n, char start, char finish, char temp)
{
    stack<int> source;
    stack<int> dest;
    stack<int> aux;
    int num = countHanoiMoves(n);
    for (int i = n; i > 0; i--)
        source.push(i);
    if (n % 2 == 0)
        evenCase(num, source, dest, aux, start, finish, temp);
    else
        oddCase(num, source, dest, aux, start, finish, temp);
}

void evenCase(int num, stack<int> &source, stack<int> &dest, stack<int> &aux,
              char &start, char &finish, char &temp)
{
    for (int i = 0; i < num; i++)
    {
        if (i % 3 == 0)
            transferDisk(source, start, aux, temp);
        else if (i % 3 == 1)
            transferDisk(source, start, dest, finish);
        else
            transferDisk(aux, temp, dest, finish);
    }
}

void oddCase(int num, stack<int> &source, stack<int> &dest, stack<int> &aux,
             char &start, char &finish, char &temp)
{
    for (int i = 0; i < num; i++)
    {
        if (i % 3 == 0)
            transferDisk(source, start, dest, finish);
        else if (i % 3 == 1)
            transferDisk(source, start, aux, temp);
        else
            transferDisk(aux, temp, dest, finish);
    }
}

void transferDisk(stack<int> &firstCol, char &first, stack<int> &secondCol, char &second)
{
    if (secondCol.empty() || (!firstCol.empty() && secondCol.top() > firstCol.top()))
    {
        secondCol.push(firstCol.top());
        firstCol.pop();
        moveSingleDisk(first, second);
    }
    else
    {
        firstCol.push(secondCol.top());
        secondCol.pop();
        moveSingleDisk(second, first);
    }
}

/*
 * Function: countHanoiMoves
 * Usage: int n = countHanoiMoves(disks);
 * ---------------------------------------
 * Number of moves required to solve the Towers of Hanoi puzzle for n disks
 */

int countHanoiMoves(int disks) { return pow(2, disks) - 1; }