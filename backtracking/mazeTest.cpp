/*
 * File: mazeTest.cpp
 * ---------------------------------------
 * Test maze class
 */

#include <iostream>
#include "maze.h"
#include "maze.cpp"
using namespace std;

int main()
{
    vector<vector<char>> maze1 = {
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', ' ', ' ', 'x', ' ', ' ', ' ', ' '},
        {'x', ' ', 'x', 'x', 'x', ' ', 'x', ' ', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};
    Point start1(3, 1);
    Maze labyrinth1(maze1, start1);

    cout << "Labyrinth 1: " << endl;
    cout << labyrinth1.toString() << endl;
    cout << labyrinth1.getStartPosition() << endl;
    cout << labyrinth1.getEndPosition() << endl;
    if (labyrinth1.solveMaze())
        cout << "Solved!" << endl;
    else
        cout << "Cant get way out!" << endl;
    labyrinth1.findShortestPath();

    vector<vector<char>> maze2 = {
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'x', ' ', ' ', ' ', 'x'},
        {'x', ' ', 'x', 'x', 'x', 'x', 'x', ' ', 'x', 'x', 'x', ' ', 'x'},
        {'x', ' ', ' ', ' ', ' ', ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', ' ', 'x', 'x', 'x', ' ', 'x', ' ', 'x', 'x', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', ' ', ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', 'x', 'x', ' ', 'x', 'x', 'x', ' ', 'x', ' ', 'x', ' ', 'x'},
        {'x', ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x', ' ', 'x', ' ', 'x'},
        {'x', ' ', 'x', 'x', 'x', ' ', 'x', 'x', 'x', ' ', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', 'x', ' ', 'x', ' ', ' ', ' ', ' ', ' ', 'x'},
        {'x', 'x', 'x', ' ', 'x', ' ', 'x', ' ', 'x', 'x', 'x', 'x', 'x'},
        {'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
    };
    Point start2(1, 1);
    Maze labyrinth2(maze2, start2);

    cout << "Labyrinth 2: " << endl;
    cout << labyrinth2.toString() << endl;
    cout << labyrinth2.getStartPosition() << endl;
    cout << labyrinth2.getEndPosition() << endl;
    if (labyrinth2.solveMaze())
        cout << "Solved!" << endl;
    else
        cout << "Cant get way out!" << endl;
    labyrinth2.findShortestPath();

    return 0;
}