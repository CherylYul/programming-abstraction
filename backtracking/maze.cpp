#include "maze.h"
#include <iostream>
#include <ostream>
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
    endPos = this->findEndPos();
}

Point Maze::findEndPos()
{
    vector<Point> listEndPos;
    for (int i = 1; i < mazeWidth - 1; i++)
    {
        if (m[0][i] == ' ')
            listEndPos.push_back(Point(0, i));
        if (m[mazeHeight - 1][i] == ' ')
            listEndPos.push_back(Point(mazeHeight - 1, i));
    }
    for (int i = 1; i < mazeHeight - 1; i++)
    {
        if (m[i][0] == ' ')
            listEndPos.push_back(Point(i, 0));
        if (m[i][mazeWidth - 1] == ' ')
            listEndPos.push_back(Point(i, mazeWidth - 1));
    }
    for (Point pos : listEndPos)
        if (pos != startPos)
            return pos;
    return Point(0, 0);
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
 * Function: findShortestPath()
 * Usage: maze.findShortestPath()
 * ---------------------------------------
 * Find the shortest path if the maze exists solutions, otherwise returns 0.
 */

int Maze::findShortestPath()
{
    if (!listSolutions.empty())
    {
        cout << "Total Solutions: " << listSolutions.size() << endl;
        cout << "Steps for each solutions: " << listSolutions << endl;
        int minStep = listSolutions[0];
        for (int step : listSolutions)
            if (step < minStep)
                minStep = step;
        return minStep;
    }
    cout << "You must call maze.solveMaze() before calling maze.findShortestPath()." << endl;
    return 0;
}

/*
 * Function: solveMaze
 * Usage: maze.solveMaze();
 * ---------------------------------------
 * Attempts to generate a solution to the current maze with specified start point
 * by using recursion to solve submazes resulting from marking the current square
 * and moving 1 step along each open passage.
 * 1. internalSolveMaze(pos, mark): returns true when find a solution.
 * 2. internalSolveMaze(pos, mark, steps): show all solutions for maze and therefore
 * can show the shortest path.
 */

bool Maze::solveMaze()
{
    vector<vector<bool>> mark = this->copyMazeMark();
    internalSolveMaze(startPos, mark, 0);
    return !listSolutions.empty();
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
            if (internalSolveMaze(nextPosition(pos, dir), mark))
                return true;
        }
    }
    mark[x][y] = false;
    return false;
}

void Maze::internalSolveMaze(Point pos, vector<vector<bool>> &mark, int steps)
{
    if (pos == endPos)
    {
        // cout << "Solve maze with: " << steps << endl;
        // cout << mark << endl;
        listSolutions.push_back(steps);
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
            internalSolveMaze(nextPosition(pos, dir), mark, steps);
    }
    mark[x][y] = false;
    --steps;
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
 * Function: copyMazeMark
 * Usage: maze.copyMazeMark();
 * ---------------------------------------
 * Create a boolean table that suports for checking whether the object crosses
 * over the position or not
 */

vector<vector<bool>> Maze::copyMazeMark()
{
    vector<vector<bool>> mark(mazeHeight);
    for (int i = 0; i < mazeHeight; i++)
    {
        vector<bool> width(mazeWidth, false);
        mark[i] = width;
    }
    return mark;
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

ostream &operator<<(ostream &os, vector<int> vec) { return os << toString(vec); }
string toString(vector<int> vec)
{
    string str = "[";
    for (int i : vec)
        str += integerToString(i) + ", ";
    return str + "]";
}

ostream &operator<<(ostream &os, vector<vector<bool>> vec) { return os << toString(vec); }
string toString(vector<vector<bool>> vec)
{
    string str = "";
    for (vector<bool> v : vec)
    {
        for (bool b : v)
            str += integerToString(b) + ", ";
        str += "\n";
    }
    return str;
}