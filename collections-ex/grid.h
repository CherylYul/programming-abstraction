/*
 * File: grid.h
 * ---------------------------------------
 * This interfaces export useful function to work with grids
 */

#ifndef _grid_h
#define _grid_h
#include <string>

void fillGrid(std::vector<std::vector<int>> &grid, std::vector<int> &vec);
void operator+=(std::vector<std::vector<int>> &grid, std::vector<int> vec);
std::string toString(std::vector<std::vector<int>> grid);
std::ostream &operator<<(std::ostream &os, std::vector<std::vector<int>> grid);

std::vector<int> sumRow(std::vector<std::vector<int>> grid);
std::vector<int> sumColumn(std::vector<std::vector<int>> grid);
std::vector<int> sumDiagonal(std::vector<std::vector<int>> squareGrid);

bool isMagicSquare(std::vector<std::vector<int>> &squareGrid);

#endif
