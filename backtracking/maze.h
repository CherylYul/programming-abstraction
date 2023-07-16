/*
 * File: maze.h
 * ---------------------------------------
 * This iinterface exports the maze class
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
    Point getStartPosition();
    Point getEndPosition();
    bool solveMaze();
    bool internalSolveMaze(Point pos, std::vector<std::vector<bool>> &mark);
    Point nextPosition(Point pos, Direction dir);
    bool isMovable(Point pos, Direction dir);
    void shortestPathLength();
    void internalShortestPathLength(Point pos, std::vector<std::vector<bool>> &mark,
                                    int &steps, int &countSols, vector<int> &sols);
    std::string toString();

private:
    std::vector<std::vector<char>> m;
    int mazeWidth;
    int mazeHeight;
    Point startPos;
    Point endPos;
    vector<Point> endPosList;
};

void printVec(vector<vector<bool>> vec);

#endif