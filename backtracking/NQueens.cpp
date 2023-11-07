/*
 * File: NQueens.cpp
 * ---------------------------------------
 * Place N Queens on an NxN chessboard so that none of them can move to
 * a square occupied by any of the others in a single turn.
 */

#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

void nQueenSolution(int chessBoardLength);
void nQueen(int r, int c, vector<bool> &col, vector<vector<bool>> &chessBoard);
bool checkDiagonal(int row, int col, vector<vector<bool>> chessBoard);
bool checkOffDiagonal(int row, int col, vector<vector<bool>> chessBoard);
ostream &operator<<(ostream &os, vector<vector<bool>> vec);
string toString(vector<vector<bool>> vec);
string boolToString(bool b);

int main()
{
    nQueenSolution(4);
    nQueenSolution(8);
    return 0;
}

void nQueenSolution(int chessBoardLength)
{
    vector<bool> col(chessBoardLength, false);
    vector<vector<bool>> chessBoard(chessBoardLength);
    for (int i = 0; i < chessBoardLength; i++)
    {
        vector<bool> temp(chessBoardLength, false);
        chessBoard[i] = temp;
    }
    for (int i = 0; i < chessBoardLength; i++)
        nQueen(0, i, col, chessBoard);
}

void nQueen(int r, int c, vector<bool> &col, vector<vector<bool>> &chessBoard)
{
    chessBoard[r][c] = true;
    col[c] = true;
    if (r == col.size() - 1)
    {
        cout << "Result: " << endl;
        cout << chessBoard << endl;
        chessBoard[r][c] = false;
        col[c] = false;
        return;
    }
    ++r;
    for (int i = 0; i < col.size(); i++)
        if (!col[i] && checkDiagonal(r, i, chessBoard) && checkOffDiagonal(r, i, chessBoard))
            nQueen(r, i, col, chessBoard);
    --r;
    chessBoard[r][c] = false;
    col[c] = false;
}

// return false if it is on the diagonal
bool checkDiagonal(int row, int col, vector<vector<bool>> chessBoard)
{
    int r = row;
    int c = col;
    while (r > 0 && c > 0)
        if (chessBoard[--r][--c])
            return false;
    return true;
}

// return false if it is on the off-diagonal
bool checkOffDiagonal(int row, int col, vector<vector<bool>> chessBoard)
{
    int r = row;
    int c = col;
    while (r > 0 && c < chessBoard.size() - 1)
        if (chessBoard[--r][++c])
            return false;
    return true;
}

string boolToString(bool b)
{
    ostringstream stream;
    stream << b;
    return stream.str();
}
ostream &operator<<(ostream &os, vector<vector<bool>> vec) { return os << toString(vec); }
string toString(vector<vector<bool>> vec)
{
    string str = "";
    for (vector<bool> v : vec)
    {
        for (bool b : v)
            str += boolToString(b);
        str += "\n";
    }
    return str;
}