#include "maze.h"
#include <iostream>
using namespace std;

/*
 * Constructor: Maze
 * Usage: Maze maze(maze, start);
 * ---------------------------------------
 * Construct a new maze with a string grid which has 'x' represents a block and ''
 * represents a way can pass by.
 */

Maze::Maze(vector<vector<char>> maze, Point start)
{
    m = maze;
    mazeWidth = m[0].size();
    mazeHeight = m.size();
    startPos = start;
    for (int i = 1; i < mazeWidth - 1; i++)
    {
        if (m[0][i] == ' ')
            endPosList.push_back(Point(0, i));
        if (m[mazeHeight - 1][i] == ' ')
            endPosList.push_back(Point(mazeHeight - 1, i));
    }
    for (int i = 1; i < mazeHeight - 1; i++)
    {
        if (m[i][0] == ' ')
            endPosList.push_back(Point(i, 0));
        if (m[i][mazeWidth - 1] == ' ')
            endPosList.push_back(Point(i, mazeWidth - 1));
    }
    for (Point pos : endPosList)
        if (pos != startPos)
            endPos = pos;
}

/*
 * Function: getStartPosition, getEndPosition
 * Usage: getStartPosition(), getEndPosition()
 * ---------------------------------------
 * Return starting points and solved points of this maze.
 */

Point Maze::getStartPosition() { return startPos; };
Point Maze::getEndPosition() { return endPos; };

/*
 * Function: solveMaze
 * Usage: solveMaze();
 * ---------------------------------------
 * Attempts to generate a solution to the current maze with specified start point.
 * It returns true when finding solution. Use recursion to solve submazes resulting
 * from marking the current square and moving 1 step along each open passage.
 */

bool Maze::solveMaze()
{
    vector<vector<bool>> path(mazeHeight);
    for (int i = 0; i < mazeHeight; i++)
    {
        vector<bool> w(mazeWidth, false);
        path[i] = w;
    }
    return internalSolveMaze(startPos, path);
}

bool Maze::internalSolveMaze(Point pos, vector<vector<bool>> &mark)
{
    int x = pos.getX();
    int y = pos.getY();
    if (pos == endPos)
        return true;
    if (mark[x][y])
        return false;
    mark[x][y] = true;
    for (Direction dir = NORTH; dir <= WEST; dir++)
    {
        if (isMovable(pos, dir))
        {
            // cout << "Start:" << endl;
            // printVec(mark);
            if (internalSolveMaze(nextPosition(pos, dir), mark))
                return true;
            // cout << "Out:" << endl;
            // printVec(mark);
        }
    }
    mark[x][y] = false;
    return false;
}

/*
 * Function: nextPosition
 * Usage: Point nextPos = nextPosition(pos, dir);
 * ---------------------------------------
 * Returns the position that results from moving one square to the next square
 * in the direction specified by dir.
 */

Point Maze::nextPosition(Point pos, Direction dir)
{
    switch (dir)
    {
    case NORTH:
        return Point(pos.getX() - 1, pos.getY());
    case EAST:
        return Point(pos.getX(), pos.getY() + 1);
    case SOUTH:
        return Point(pos.getX() + 1, pos.getY());
    case WEST:
        return Point(pos.getX(), pos.getY() - 1);
    }
    return pos;
}

/*
 * Function: isMovable
 * Usage: isMovable(pos, dir);
 * ---------------------------------------
 * Check if we can move on a specified direction with a certain position
 */

bool Maze::isMovable(Point pos, Direction dir)
{
    Point nextPos = nextPosition(pos, dir);
    int x = nextPos.getX();
    int y = nextPos.getY();
    return m[x][y] == ' ';
}

/*
 * Function: shortestPathLength
 * Usage: maze.shortestPathLength();
 * ---------------------------------------
 * Show all solutions for maze and returns the shortest path!
 */

void Maze::shortestPathLength()
{
    vector<vector<bool>> path(mazeHeight);
    for (int i = 0; i < mazeHeight; i++)
    {
        vector<bool> w(mazeWidth, false);
        path[i] = w;
    }
    int steps = 0;
    int countSols = 0;
    vector<int> sols;
    internalShortestPathLength(startPos, path, steps, countSols, sols);

    cout << "Total Solutions: " << countSols << endl;
    cout << "Steps for each solutions: ";
    for (int i : sols)
        cout << i << " ";
    cout << endl;
    cout << "Shortest Path: ";
    if (sols.size() > 0)
    {
        int minPath = sols[0];
        for (int i = 1; i < sols.size(); i++)
            if (sols[i] < minPath)
                minPath = sols[i];
        cout << minPath << endl;
    }
}

void Maze::internalShortestPathLength(Point pos, vector<vector<bool>> &mark,
                                      int &steps, int &countSols, vector<int> &sols)
{
    if (pos == endPos)
    {
        cout << "Solve maze with: " << steps << endl;
        cout << "Solve maze with mark: " << endl;
        printVec(mark);
        sols.push_back(steps);
        ++countSols;
    }
    int x = pos.getX();
    int y = pos.getY();
    if (mark[x][y])
        return;
    mark[x][y] = true;
    ++steps;
    for (Direction dir = NORTH; dir <= WEST; dir++)
    {
        if (isMovable(pos, dir))
            internalShortestPathLength(nextPosition(pos, dir), mark, steps, countSols, sols);
    }
    mark[x][y] = false;
    --steps;
}

/*
 * Function: toString
 * Usage: maze.toString();
 * ---------------------------------------
 * Print the maze
 */

string Maze::toString()
{
    string str = "";
    for (vector<char> row : m)
    {
        for (char c : row)
            str += c;
        str += "\n";
    }
    return str;
}

/*
 * Function: printVec
 * Usage: printVec(vec);
 * ---------------------------------------
 * Print the bool vec which represents the solution path of the maze
 */

void printVec(vector<vector<bool>> vec)
{
    for (vector<bool> v : vec)
    {
        for (bool b : v)
            cout << b;
        cout << endl;
    }
}