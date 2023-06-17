/*
 * File: grid.cpp
 * ---------------------------------------
 * This programs implements grid.h interface
 */

#include <iostream>
#include <vector>
#include "vector.h"
#include "vector.cpp"
#include "grid.h"
using namespace std;

void fillGrid(vector<vector<int>> &grid, vector<int> &vec)
{
    grid += vec;
}

void operator+=(vector<vector<int>> &grid, vector<int> vec)
{
    if (grid[0].size() != vec.size())
        cout << "vector's length and grid's width didn't match!" << endl;
    grid.push_back(vec);
}

string toString(vector<vector<int>> grid)
{
    string str = "[";
    for (vector<int> v : grid)
        str += toString(v);
    str += "]";
    return str;
}

ostream &operator<<(ostream &os, vector<vector<int>> grid)
{
    return os << toString(grid);
}

/*
 * Function: sumRow
 * Usage: sumRow(grid);
 * ---------------------------------------
 * Return the vector that contains the sum of each rows in the grid.
 * If the grid is empty, simply return a vector with 0 value.
 */

vector<int> sumRow(vector<vector<int>> grid)
{
    vector<int> vec(grid.size(), 0);
    int i = 0;
    for (vector<int> v : grid)
    {
        vec[i] = sumVector(v);
        i++;
    }
    return vec;
}

/*
 * Function: sumColumn
 * Usage: sumColumn(grid);
 * ---------------------------------------
 * Return the vector that contains the sum of each columns in matrix.
 * If the grid is not a matrix, simply return a vector with 0 value.
 */

vector<int> sumColumn(vector<vector<int>> grid)
{
    if (grid.size() == 0 && grid[0].size())
        cout << "Length of grid row is not equal!" << endl;
    vector<int> vec(grid[0].size(), 0);
    for (vector<int> v : grid)
    {
        if (v.size() != vec.size())
            cout << "Length of grid row is not equal!" << endl;
        for (int i = 0; i < vec.size(); i++)
            vec[i] += v[i];
    }
    return vec;
}

/*
 * Function: sumDiagonal
 * Usage: sumDiagonal(squareGrid);
 * ---------------------------------------
 * This checks if a grid is a square grid. If so, return the vector that contains
 * the sum the diagonal and the off-diagonal in the matrix.
 */

vector<int> sumDiagonal(vector<vector<int>> squareGrid)
{
    vector<int> vec(2, 0);
    if (squareGrid.size() != squareGrid[0].size())
        return vec;
    int start = 0;
    int end = squareGrid.size() - 1;
    for (vector<int> v : squareGrid)
    {
        vec[0] += v[start];
        start++;
        vec[1] += v[end];
        end--;
    }
    return vec;
}

/*
 * Function: isMagicSquare
 * Usage: isMagicsquare(squareGrid);
 * ---------------------------------------
 * This checks if a grid is a magic square. A magic square is a 2-dim integers
 * which rows, columns, and diagonals all add up to the same value.
 * Ex: [[8, 1, 6], [3, 5, 7], [4, 9, 2]]
 *     [[16, 3, 2, 13], [5, 10, 11, 8], [9, 6, 7, 12], [4, 15, 14, 1]]
 */

bool isMagicSquare(vector<vector<int>> &squareGrid)
{
    if (squareGrid.size() == 0 || squareGrid.size() != squareGrid[0].size())
        return false;
    vector<int> diagonal = sumDiagonal(squareGrid);
    vector<int> row = sumRow(squareGrid);
    vector<int> column = sumColumn(squareGrid);
    if (diagonal[0] != diagonal[1])
        return false;
    for (int i : row)
        if (diagonal[0] != i)
            return false;
    for (int i : column)
        if (diagonal[0] != i)
            return false;
    return true;
}