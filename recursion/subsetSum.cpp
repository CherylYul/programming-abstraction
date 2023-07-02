/*
 * File: subsetSum.cpp
 * ---------------------------------------
 * Given a set of integers and a target value, determine whether it
 * is possible to find a subset of those integers whose sum is equal
 * to the specified target.
 * Ex: {-2, 1, 3, 8} and target 7 will return true
 */

#include <iostream>
#include <ostream>
#include <set>
#include "../library/string/strlib.h"
#include "../library/string/strlib.cpp"
using namespace std;

bool subsetSumExists(set<int> &s, int target);
int countSubsetSumWays(set<int> &s, int target);
set<int> operator-(set<int> s, int element);
ostream &operator<<(ostream &os, set<int> s);
string toString(set<int> s);

int main()
{
    set<int> s = {4, 3, 5, 1};
    cout << countSubsetSumWays(s, 4) << endl;
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
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }
    int element = *s.begin();
    set<int> rest = s - element;
    return countSubsetSumWays(rest, target) + countSubsetSumWays(rest, target - element);
}

set<int> operator-(set<int> s, int element)
{
    if (s.empty())
        return s;
    if (s.size() == 1 && *s.begin() == element)
    {
        s.clear();
        return s;
    }
    for (int i : s)
        if (i == element)
            s.erase(i);
    return s;
}

string toString(set<int> s)
{
    string str = "(";
    for (int i : s)
        str += integerToString(i) + ", ";
    str += ")";
    return str;
}

ostream &operator<<(ostream &os, set<int> s)
{
    return os << toString(s);
}