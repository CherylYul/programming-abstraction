/*
 * File: maze.h
 * ---------------------------------------
 * This interface exports the maze class
 */

#ifndef _maze_h
#define _maze_h
#include <vector>
#include "../library/graphics/gobjects.h"
#include "../library/graphics/gobjects.cpp"
#include "../library/direction.h"
#include "../library/direction.cpp"

class Maze
{
public:
    Maze(std::vector<std::vector<char>> maze, Point start);
    Point findEndPos();
    Point getStartPosition();
    Point getEndPosition();
    int findShortestPath();
    bool solveMaze();
    bool internalSolveMaze(Point pos, std::vector<std::vector<bool>> &mark);
    void internalSolveMaze(Point pos, std::vector<std::vector<bool>> &mark, int steps);
    Point nextPosition(Point pos, Direction dir);
    bool isMovable(Point pos, Direction dir);
    vector<vector<bool>> copyMazeMark();
    std::string toString();

private:
    std::vector<std::vector<char>> m;
    int mazeWidth;
    int mazeHeight;
    Point startPos;
    Point endPos;
    vector<int> listSolutions;
};

std::ostream &operator<<(std::ostream &os, std::vector<int> vec);
std::string toString(std::vector<int> vec);
std::ostream &operator<<(std::ostream &os, std::vector<vector<bool>> vec);
std::string toString(std::vector<std::vector<bool>> vec);

#endif