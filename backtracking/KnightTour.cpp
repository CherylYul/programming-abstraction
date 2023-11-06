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

const int chessBoardLength = 8;
struct Position
{
    int x;
    int y;
};

enum Direction
{
    SOUTHRIGHT,
    EASTBOTTOM,
    EASTTOP,
    NORTHRIGHT,
    NORTHLEFT,
    WESTTOP,
    WESTBOTTOM,
    SOUTHLEFT,
};
Direction operator++(Direction &dir);
Direction operator++(Direction &dir, int);
void knightTour(Position start);
bool internalKnight(Position pos, int step, vector<vector<int>> &chessboard);
vector<Position> validMoves(Position pos, vector<vector<int>> chessboard);
Position nextStep(Position pos, Direction dir);
bool isMovable(Position pos, vector<vector<int>> chessboard);
void printChessBoard(vector<vector<int>> vec);

int main()
{
    Position start;
    start.x = 7;
    start.y = 0;
    knightTour(start);
    return 0;
}

void knightTour(Position start)
{
    vector<vector<int>> chessboard(chessBoardLength);
    for (int i = 0; i < chessBoardLength; i++)
    {
        vector<int> temp(chessBoardLength, 0);
        chessboard[i] = temp;
    }
    if (internalKnight(start, 1, chessboard))
        cout << "Find Knight Tour!" << endl;
    printChessBoard(chessboard);
}

bool internalKnight(Position pos, int step, vector<vector<int>> &chessboard)
{
    cout << step << endl;
    chessboard[pos.x][pos.y] = step;
    printChessBoard(chessboard);
    if (step == chessBoardLength * chessBoardLength)
        return true;
    vector<Position> moves = validMoves(pos, chessboard);
    for (Position p : moves)
        if (internalKnight(p, step + 1, chessboard))
            return true;
    chessboard[pos.x][pos.y] = 0;
    return false;
}

vector<Position> validMoves(Position pos, vector<vector<int>> chessboard)
{
    vector<Position> moves;
    for (Direction dir = SOUTHRIGHT; dir <= SOUTHLEFT; dir++)
    {
        Position nextPos = nextStep(pos, dir);
        if (isMovable(nextPos, chessboard))
            moves.push_back(nextPos);
    }
    return moves;
}

bool isMovable(Position pos, vector<vector<int>> chessboard)
{
    return ((pos.x >= 0 && pos.x < chessBoardLength) &&
            (pos.y >= 0 && pos.y < chessBoardLength) &&
            chessboard[pos.x][pos.y] == 0);
}

Position nextStep(Position pos, Direction dir)
{
    Position nextPos;
    switch (dir)
    {
    case NORTHRIGHT:
        nextPos.x = pos.x - 2;
        nextPos.y = pos.y + 1;
        return nextPos;
    case EASTTOP:
        nextPos.x = pos.x - 1;
        nextPos.y = pos.y + 2;
        return nextPos;
    case EASTBOTTOM:
        nextPos.x = pos.x + 1;
        nextPos.y = pos.y + 2;
        return nextPos;
    case SOUTHRIGHT:
        nextPos.x = pos.x + 2;
        nextPos.y = pos.y + 1;
        return nextPos;
    case SOUTHLEFT:
        nextPos.x = pos.x + 2;
        nextPos.y = pos.y - 1;
        return nextPos;
    case WESTBOTTOM:
        nextPos.x = pos.x + 1;
        nextPos.y = pos.y - 2;
        return nextPos;
    case WESTTOP:
        nextPos.x = pos.x - 1;
        nextPos.y = pos.y - 2;
        return nextPos;
    case NORTHLEFT:
        nextPos.x = pos.x - 2;
        nextPos.y = pos.y - 1;
        return nextPos;
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