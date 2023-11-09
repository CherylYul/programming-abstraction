/*
 * File: Painting.cpp
 * ---------------------------------------
 * This program simulates the operation of the paint - bucket tool by
 * painting in black all white pixels reachable from the specified row
 * and column without corssing an existing black pixel.
 */

#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../library/direction.h"
#include "../library/direction.cpp"
using namespace std;

void fillRegion(vector<vector<bool>> &pixels, int row, int col);
void nextPixel(vector<vector<bool>> pixels, int row, int col, Direction dir, int &nextRow, int &nextCol);
ostream &operator<<(ostream &os, vector<vector<bool>> vec);
string toString(vector<vector<bool>> vec);
string boolToString(bool b);

int main()
{
    vector<vector<bool>> pixels =
        {{
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
         },
         {
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
         },
         {
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
         },
         {
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
         },
         {
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
         },
         {
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
         },
         {
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
         },
         {
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
         },
         {
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             1,
             1,
             1,
             1,
             0,
             0,
             0,
             0,
             0,
             1,
             1,
             1,
             1,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             1,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             1,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             1,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             1,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             1,
             1,
             1,
             1,
             0,
             0,
             0,
             0,
             0,
             1,
             1,
             1,
             1,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             1,
             1,
             1,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             1,
             0,
             0,
             0,
             0,
             0,
             0,
             1,
         },
         {
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
             1,
         }};
    cout << pixels << endl;
    fillRegion(pixels, 1, 9);
    cout << pixels << endl;
    return 0;
}

void fillRegion(vector<vector<bool>> &pixels, int row, int col)
{
    if (!pixels[row][col])
    {
        pixels[row][col] = true;
        for (Direction dir = NORTH; dir <= WEST; dir++)
        {
            int nextRow;
            int nextCol;
            nextPixel(pixels, row, col, dir, nextRow, nextCol);
            fillRegion(pixels, nextRow, nextCol);
        }
    }
}

void nextPixel(vector<vector<bool>> pixels, int row, int col, Direction dir, int &nextRow, int &nextCol)
{
    switch (dir)
    {
    case NORTH:
        if (row != 0)
        {
            nextRow = row - 1;
            nextCol = col;
            break;
        }
    case EAST:
        if (col != pixels[0].size())
        {
            nextRow = row;
            nextCol = col + 1;
            break;
        }
    case SOUTH:
        if (row != pixels.size())
        {
            nextRow = row + 1;
            nextCol = col;
            break;
        }
    case WEST:
        if (col != 0)
        {
            nextRow = row;
            nextCol = col - 1;
            break;
        }
    }
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