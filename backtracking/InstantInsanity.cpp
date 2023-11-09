/*
 * Program: InstantInsanity.cpp
 * --------------------------------------
 * Instant Insanity is a puzzle which consists of 4 cubes with faces painted the colors
 * red, blue, green, and white. The goal is to arrange the cubes in a row or column such
 * that no color is duplicated on a side.
 *
 * Cube 1:           Solution (Total 8 solutions)
 *         G                 G                        Top
 * W | B | B | R     W | B | B | R      Back | Left | Front | Right
 *         G                 G                        Bottom
 *
 * Cube 2:
 *         R                 B
 * W | W | G | B     G | R | W | G      Cube 1: W | B | B | R
 *         G                 W          Cube 2: G | R | W | G
 *                                      Cube 3: B | G | R | W
 * Cube 3:                              Cube 4: R | W | G | B
 *         W                 R
 * R | R | W | B     B | G | R | W
 *         G                 W
 *
 * Cube 4:
 *         B                 R
 * G | R | R | R     R | W | G | B
 *         W                 R
 */

#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

enum Face
{
    BOTTOM,
    RIGHT,
    FRONT,
    LEFT,
    TOP,
    BACK,
};

enum Color
{
    W,
    B,
    R,
    G
};

const vector<string> COLOR_NAME = {"W", "B", "R", "G"};
const vector<string> FACE_NAME = {"BOTTOM", "RIGHT", "FRONT", "LEFT", "TOP", "BACK"};
void solution(vector<map<Face, Color>> cubes);
void solution(vector<map<Face, Color>> &cubes,
              vector<map<Face, Color>> &solvedCubes,
              vector<map<Color, bool>> &mark,
              vector<vector<Face>> &faceList);
bool isValid(map<Face, Color> cube,
             vector<Face> onFace,
             vector<map<Color, bool>> mark);
void check(map<Face, Color> cube,
           vector<Face> onFace,
           vector<map<Color, bool>> &mark,
           vector<vector<Face>> &faceList);
void uncheck(map<Face, Color> cube,
             vector<Face> onFace,
             vector<map<Color, bool>> &mark,
             vector<vector<Face>> &faceList);
vector<Face> offFace(Face face);
vector<Face> rotate(vector<Face> oldSides, int pos);
void printSolution(vector<map<Face, Color>> cubes, vector<vector<Face>> faceList);
Face operator++(Face &dir);
Face operator++(Face &dir, int);
ostream &operator<<(ostream &os, map<Face, Color> cube);
string toString(map<Face, Color> cube);

int main()
{
    map<Face, Color> cube4 = {{FRONT, B}, {BACK, W}, {TOP, G}, {BOTTOM, G}, {LEFT, B}, {RIGHT, R}};
    map<Face, Color> cube3 = {{FRONT, G}, {BACK, W}, {TOP, R}, {BOTTOM, G}, {LEFT, W}, {RIGHT, B}};
    map<Face, Color> cube2 = {{FRONT, W}, {BACK, R}, {TOP, W}, {BOTTOM, G}, {LEFT, R}, {RIGHT, B}};
    map<Face, Color> cube1 = {{FRONT, R}, {BACK, G}, {TOP, B}, {BOTTOM, W}, {LEFT, R}, {RIGHT, R}};
    vector<map<Face, Color>> cubes = {cube1, cube2, cube3, cube4};
    solution(cubes);
    return 0;
}

/*
 * Function: solution
 * Usage: solution(cubes);
 * --------------------------------------
 * Print out the 4 color cubes can be arranged side by side such that no color
 * repeats on a side.
 */

void solution(vector<map<Face, Color>> cubes)
{
    vector<map<Face, Color>> solvedCubes;
    vector<vector<Face>> faceList;
    vector<map<Color, bool>> mark = {
        {{W, false}, {B, false}, {R, false}, {G, false}},
        {{W, false}, {B, false}, {R, false}, {G, false}},
        {{W, false}, {B, false}, {R, false}, {G, false}},
        {{W, false}, {B, false}, {R, false}, {G, false}}};
    solution(cubes, solvedCubes, mark, faceList);
}

void solution(vector<map<Face, Color>> &cubes,
              vector<map<Face, Color>> &solvedCubes,
              vector<map<Color, bool>> &mark,
              vector<vector<Face>> &faceList)
{
    if (solvedCubes.size() == 4)
    {
        printSolution(solvedCubes, faceList);
        return;
    }
    solvedCubes.push_back(cubes.back());
    cubes.pop_back();
    for (Face face = BOTTOM; face <= BACK; face++)
    {
        vector<Face> onFace = offFace(face);
        for (int pos = 0; pos < 4; pos++)
        {
            vector<Face> onFacePos = rotate(onFace, pos);
            if (isValid(solvedCubes.back(), onFacePos, mark))
            {
                check(solvedCubes.back(), onFacePos, mark, faceList);
                solution(cubes, solvedCubes, mark, faceList);
                uncheck(solvedCubes.back(), onFacePos, mark, faceList);
            }
        }
    }
    cubes.push_back(solvedCubes.back());
    solvedCubes.pop_back();
}

/*
 * Function: isValid
 * Usage: if (isValid(cube, onFace, mark)) ...
 * --------------------------------------
 * Access the color of each side of the cube and check if the color is duplicated on
 * a side.
 * Access the Face: onFace[0] // Ex: FRONT
 * Acesss the color of the Face: cube[onFace[0]] // Ex: B
 * Acesss the mark table on side 1: mark[0][cube[onFace[0]]]  // Ex: mark[0][B] = false
 */

bool isValid(map<Face, Color> cube, vector<Face> onFace, vector<map<Color, bool>> mark)
{
    return !mark[0][cube[onFace[0]]] &&
           !mark[1][cube[onFace[1]]] &&
           !mark[2][cube[onFace[2]]] &&
           !mark[3][cube[onFace[3]]];
}

void check(map<Face, Color> cube,
           vector<Face> onFace,
           vector<map<Color, bool>> &mark,
           vector<vector<Face>> &faceList)
{
    faceList.push_back(onFace);
    mark[0][cube[onFace[0]]] = true;
    mark[1][cube[onFace[1]]] = true;
    mark[2][cube[onFace[2]]] = true;
    mark[3][cube[onFace[3]]] = true;
}

void uncheck(map<Face, Color> cube,
             vector<Face> onFace,
             vector<map<Color, bool>> &mark,
             vector<vector<Face>> &faceList)
{
    mark[0][cube[onFace[0]]] = false;
    mark[1][cube[onFace[1]]] = false;
    mark[2][cube[onFace[2]]] = false;
    mark[3][cube[onFace[3]]] = false;
    faceList.pop_back();
}

/*
 * Function: offFace
 * Usage: vector<Face> onFace = offFace(face);
 * --------------------------------------
 * Set the face on the ground off, this time the faces of 4 sides change.
 */

vector<Face> offFace(Face face)
{
    switch (face)
    {
    case TOP:
        return vector<Face>{FRONT, LEFT, BACK, RIGHT};
    case BOTTOM:
        return vector<Face>{BACK, LEFT, FRONT, RIGHT};
    case FRONT:
        return vector<Face>{BOTTOM, LEFT, TOP, RIGHT};
    case BACK:
        return vector<Face>{BOTTOM, RIGHT, TOP, LEFT};
    case LEFT:
        return vector<Face>{BOTTOM, BACK, TOP, FRONT};
    case RIGHT:
        return vector<Face>{BOTTOM, FRONT, TOP, BACK};
    }
}

/*
 * Function: rotate
 * Usage: vector<Face> newSides = rotate(oldSides, 1);
 * --------------------------------------
 * For each face down on the ground, we totally have 4 different position to arrange the
 * sides. When we rotate the cube to the right 90 degree, 180 degree, 270 degree, we
 * alter the position of each sides.
 *
 * For example: place the front face down on the ground, we have:
 *                          side 1     side 2     side 3     side 4
 * 0   degree (not rotate)  bottom     left       top        right   (Assume position 0)
 * 90  degree               left       top        right      bototm  (Assume position 1)
 * 180 degree               top        right      bottom     left    (Assume position 2)
 * 270 degree               right      bottom     left       top     (Assume position 3)
 */
vector<Face> rotate(vector<Face> oldSides, int pos)
{
    switch (pos)
    {
    case 1:
        return vector<Face>{oldSides[1], oldSides[2], oldSides[3], oldSides[0]};
    case 2:
        return vector<Face>{oldSides[2], oldSides[3], oldSides[0], oldSides[1]};
    case 3:
        return vector<Face>{oldSides[3], oldSides[0], oldSides[1], oldSides[2]};
    default:
        return oldSides;
    }
}

Face operator++(Face &dir)
{
    dir = Face(dir + 1);
    return dir;
}

Face operator++(Face &dir, int)
{
    Face old = dir;
    dir = Face(dir + 1);
    return old;
}

ostream &operator<<(ostream &os, map<Face, Color> cube) { return os << toString(cube); }
string toString(map<Face, Color> cube)
{
    string result = "[";
    for (map<Face, Color>::iterator it = cube.begin(); it != cube.end(); ++it)
        result += COLOR_NAME[it->second] + " " + FACE_NAME[it->first] + " ";
    return result + "]\n";
}

void printSolution(vector<map<Face, Color>> cubes, vector<vector<Face>> faceList)
{
    cout << "Solution: " << endl;
    // print out face name
    for (vector<Face> faces : faceList)
    {
        for (Face face : faces)
            cout << FACE_NAME[face] << " ";
        cout << endl;
    }
    // print out color name
    for (int i = 0; i < cubes.size(); i++)
    {
        for (int j = 0; j < faceList.size(); j++)
            cout << COLOR_NAME[cubes[i][faceList[i][j]]] << " ";
        cout << endl;
    }
}