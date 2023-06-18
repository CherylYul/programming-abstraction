/*
 * File: grid.cpp
 * ---------------------------------------
 * This programs implements vector.h interface
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "../string/strlib.h"
#include "../string/strlib.cpp"
#include "vector.h"
using namespace std;

vector<int> operator+(vector<int> v1, vector<int> v2)
{
    if (v1.size() != v2.size())
        cout << "The 2 vector length need to be the same!" << endl;
    vector<int> vec(v1.size());
    for (int i = 0; i < vec.size(); i++)
        vec[i] = v1[i] + v2[i];
    return vec;
}

vector<int> operator-(vector<int> v1, vector<int> v2)
{
    if (v1.size() != v2.size())
        cout << "The 2 vector length need to be the same!" << endl;
    vector<int> vec(v1.size());
    for (int i = 0; i < vec.size(); i++)
        vec[i] = v1[i] - v2[i];
    return vec;
}

/*
 * Function: toString
 * Usage: toString(vec);
 * -----------------------------------------------
 * Returns contents of the vector vec as a comma-separated list enclosed
 * in square brackets.
 */

string toString(vector<int> vec)
{
    string str = "[";
    for (int i : vec)
        str += integerToString(i) + ", ";
    str += "]";
    return str;
}

ostream &operator<<(ostream &os, vector<int> vec)
{
    return os << toString(vec);
}

int sumVector(std::vector<int> vec)
{
    int sum = 0;
    for (int i : vec)
        sum += i;
    return sum;
}

/*
 * Function: promptUserForFile
 * Usage: ifstream infile;
 *        promptUserForFile(infile, "Input file: ");
 *        // getline act... //
 *        infile.close();
 * ---------------------------------------
 * Request user input a file then return file content to work with it
 */

string promptUserForFile(ifstream &infile, string prompt)
{
    while (true)
    {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if (!infile.fail())
            return filename;
        infile.clear();
        cout << "Unable to open that file. Try again" << endl;
        if (prompt == "")
            prompt = "Input file: ";
    }
}

void readVector(istream &is, vector<int> &vec)
{
    string line;
    while (getline(is, line))
        vec.push_back(stringToInteger(line));
}

void readVector(istream &is, vector<double> &vec)
{
    string line;
    while (getline(is, line))
        vec.push_back(stringToDouble(line));
}

void readVector(istream &is, vector<string> &vec)
{
    string line;
    while (getline(is, line))
        vec.push_back(line);
}

/*
 * Function: removeElements
 * Usage: removeElements(vec);
 * -----------------------------------------------
 * Deletes specified element from a vector of integers
 */

void removeElements(vector<int> &vec, int element)
{
    int vecLength = vec.size();
    for (int i = 0; i < vecLength; i++)
        if (vec[i] == element)
            vec.erase(vec.begin() + i);
}
