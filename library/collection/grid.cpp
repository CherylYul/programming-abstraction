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

/*
 * Function: reshapre
 * Usage: reshapre(grid, nRows, nCols);
 * ---------------------------------------
 * Resizes the grid and fills in data from original grid:
 * Ex: [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
 * 1. The new grid includes enough space: turn to 4r, 3c
 *     [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]]
 * 2. The new grid does not have enough space, drop elements: turn to 2r, 5c
 *     [[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]]
 * 3. The new grid has spare space, set default values: turn to 4r, 4c
 *     [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [0, 0, 0, 0]]
 */

vector<vector<int>> reshape(vector<vector<int>> grid, int nRows, int nCols)
{
    vector<int> vec = flatten(grid);
    vector<vector<int>> newGrid(nRows);
    int i = 0;
    for (int r = 0; r < nRows; r++)
        for (int c = 0; c < nCols; c++)
            if (i < vec.size())
            {
                newGrid[r].push_back(vec[i]);
                i++;
            }
            else
                newGrid[r].push_back(0);
    return newGrid;
}

void reshapeInPlace(vector<vector<int>> &grid, int nRows, int nCols)
{
    grid = reshape(grid, nRows, nCols);
}

/*
 * Function: flatten
 * Usage: vector<int> vec = flatten(grid);
 * ---------------------------------------
 * Flatten the element in the grid, and store it in a vector
 */

vector<int> flatten(vector<vector<int>> grid)
{
    vector<int> vec;
    for (vector<int> v : grid)
        for (int i : v)
            vec.push_back(i);
    return vec;
}

void operator+=(vector<vector<int>> &grid, vector<int> vec)
{
    if (grid[0].size() != vec.size())
        cout << "vector's length and grid's width didn't match!" << endl;
    grid.push_back(vec);
}

string toString(vector<vector<int>> grid)
{
    string str = "[\n";
    for (vector<int> v : grid)
    {
        str += toString(v);
        str += "\n";
    }
    str += "]";
    return str;
}

ostream &operator<<(ostream &os, vector<vector<int>> grid)
{
    return os << toString(grid);
}

/*
 * Function: sumRow
 * Usage: vector = sumRow(grid);
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
 * Usage: vector = sumColumn(grid);
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
 * Usage: vector = sumDiagonal(squareGrid);
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