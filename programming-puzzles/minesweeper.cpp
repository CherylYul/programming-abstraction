/*
 * File: minesweeper.cpp
 * ---------------------------------------
 * Write a program that count the mines of adjacent locations.
 */

#include <iostream>
#include <vector>
using namespace std;

// vector<vector<bool>> randomPlaceMines();
vector<vector<int>> countMines(vector<vector<bool>> &minesLocations);

int main()
{
    vector<vector<bool>> mineGrids = {{1, 0, 0, 0, 0, 1},
                                      {0, 0, 0, 0, 0, 1},
                                      {1, 1, 0, 1, 0, 1},
                                      {1, 0, 0, 0, 0, 0},
                                      {0, 0, 1, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0}};
    vector<vector<int>> mineResults = countMines(mineGrids);
    for (vector<int> v : mineResults)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

vector<vector<int>> countMines(vector<vector<bool>> &minesLocations)
{
    int squareLength = minesLocations.size();
    vector<vector<int>> countMines(squareLength);
    for (int i = 0; i < squareLength; i++)
    {
        for (int j = 0; j < squareLength; j++)
        {
            int count = 0;
            if (minesLocations[i][j])
                count++; // Center
            if (i > 0 && minesLocations[i - 1][j])
                count++; // North
            if (i > 0 && j < squareLength - 1 && minesLocations[i - 1][j + 1])
                count++; // North East
            if (j > 0 && i > 0 && minesLocations[i - 1][j - 1])
                count++; // North West
            if (i < squareLength - 1 && minesLocations[i + 1][j])
                count++; // South
            if (i < squareLength - 1 && j < squareLength - 1 && minesLocations[i + 1][j + 1])
                count++; // South East
            if (j > 0 && i < squareLength - 1 && minesLocations[i + 1][j - 1])
                count++; // South West
            if (j > 0 && minesLocations[i][j - 1])
                count++; // West
            if (j < squareLength - 1 && minesLocations[i][j + 1])
                count++; // East
            countMines[i].push_back(count);
        }
    }
    return countMines;
}