/*
 * File: subsetSum.cpp
 * ---------------------------------------
 * Given a set of integers and a target value, determine whether it
 * is possible to find a subset of those integers whose sum is equal
 * to the specified target.
 * Ex: {-2, 1, 3, 8} and target 7 will return true (-2, 1, 8)
 *     {-2, 1, 3, 8} and target 5 will return false
 */

#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <set>
using namespace std;

bool subsetSumExists(set<int> &s, int target);
int countSubsetSumWays(set<int> &s, int target);
set<int> operator-(set<int> s, int element);
ostream &operator<<(ostream &os, set<int> s);
string toString(set<int> s);
string integerToString(int n);

int main()
{
    set<int> s1 = {-2, 1, 3, 8};
    cout << "Test subsetSumExists: " << subsetSumExists(s1, 7) << endl;
    set<int> s2 = {-2, 1, 3, 8};
    cout << "Test subsetSumExists: " << subsetSumExists(s2, 5) << endl;
    set<int> s3 = {4, 3, 5, 1};
    cout << "Test countSubsetSumWays: " << countSubsetSumWays(s3, 4) << endl;
    return 0;
}

bool subsetSumExists(set<int> &s, int target)
{
    if (s.empty())
        return target == 0;
    int element = *s.begin();
    set<int> rest = s - element;
    return subsetSumExists(rest, target) || subsetSumExists(rest, target - element);
}

int countSubsetSumWays(set<int> &s, int target)
{
    if (s.empty())
        return target == 0;
    int element = *s.begin();
    set<int> rest = s - element;
    return countSubsetSumWays(rest, target) + countSubsetSumWays(rest, target - element);
}

set<int> operator-(set<int> s, int element)
{
    for (int i : s)
        if (i == element)
        {
            s.erase(i);
            return s;
        }
    return s;
}

ostream &operator<<(ostream &os, set<int> s) { return os << toString(s); }
string toString(set<int> s)
{
    string str = "(";
    for (int i : s)
        str += integerToString(i) + ", ";
    str += ")";
    return str;
}

string integerToString(int n)
{
    ostringstream stream;
    stream << n;
    return stream.str();
}