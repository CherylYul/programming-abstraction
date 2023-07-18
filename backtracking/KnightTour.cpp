/*
 * File: KnightTour.cpp
 * ---------------------------------------
 * This program finds a Knight's tour, which is a path for the knight
 * moves through all the square without repeating a square.
 * Knight's moves:
 *          x       x
 *      x               x
 *              K
 *      x               x
 *          x       x
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int chessBoardLength = 5;

enum Direction
{
    NORTHRIGHT,
    EASTTOP,
    EASTBOTTOM,
    SOUTHRIGHT,
    SOUTHLEFT,
    WESTBOTTOM,
    WESTTOP,
    NORTHLEFT
};
Direction operator++(Direction &dir);
Direction operator++(Direction &dir, int);
void knightTour(int x, int y);
bool internalKnight(int x, int y, int step, vector<vector<int>> &chessboard);
void nextStep(int &x, int &y, Direction dir);
bool isMovable(int x, int y, vector<vector<int>> chessboard);
void printChessBoard(vector<vector<int>> vec);

int main()
{
    knightTour(2, 2);
    return 0;
}

Direction operator++(Direction &dir)
{
    dir = Direction(dir + 1);
    return dir;
}

Direction operator++(Direction &dir, int)
{
    Direction old = dir;
    dir = Direction(dir + 1);
    return old;
}

void knightTour(int x, int y)
{
    vector<vector<int>> chessboard(chessBoardLength);
    for (int i = 0; i < chessBoardLength; i++)
    {
        vector<int> temp(chessBoardLength, 0);
        chessboard[i] = temp;
    }
    cout << internalKnight(x, y, 0, chessboard) << endl;
    printChessBoard(chessboard);
}

bool internalKnight(int x, int y, int step, vector<vector<int>> &chessboard)
{
    cout << step << endl;
    if (step == chessBoardLength * chessBoardLength)
    {
        printChessBoard(chessboard);
        return true;
    }
    for (Direction dir = NORTHRIGHT; dir <= NORTHLEFT; dir++)
    {
        int nextX = x;
        int nextY = y;
        nextStep(nextX, nextY, dir);
        if (isMovable(nextX, nextY, chessboard))
        {
            chessboard[x][y] = step + 1;
            bool isSuccessful = internalKnight(nextX, nextY, step + 1, chessboard);
            if (isSuccessful)
                return true;
            chessboard[x][y] = 0;
        }
    }
    return false;
}

bool isMovable(int x, int y, vector<vector<int>> chessboard)
{
    return ((x >= 0 && x < chessBoardLength) &&
            (y >= 0 && y < chessBoardLength) &&
            chessboard[x][y] == 0);
}

void nextStep(int &x, int &y, Direction dir)
{
    switch (dir)
    {
    case NORTHRIGHT:
        x -= 2;
        y += 1;
        break;
    case EASTTOP:
        x -= 1;
        y += 2;
        break;
    case EASTBOTTOM:
        x += 1;
        y += 2;
        break;
    case SOUTHRIGHT:
        x += 2;
        y += 1;
        break;
    case SOUTHLEFT:
        x += 2;
        y -= 1;
        break;
    case WESTBOTTOM:
        x += 1;
        y -= 2;
        break;
    case WESTTOP:
        x -= 1;
        y -= 2;
        break;
    case NORTHLEFT:
        x -= 2;
        y -= 1;
        break;
    }
}

void printChessBoard(vector<vector<int>> vec)
{
    cout << "Chessboard: " << endl;
    for (vector<int> v : vec)
    {
        for (int i : v)
            cout << " " << setw(2) << i;
        cout << endl;
    }
}