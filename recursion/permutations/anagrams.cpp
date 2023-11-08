/*
 * File: permutations
 * ---------------------------------------
 * Generates all permutations from the input string.
 */

#include <iostream>
#include <ostream>
#include <set>
using namespace std;

void permuteStr(string str);
void permuteStr(string soFar, string rest);
void permuteStr(string str, int lhp, int rhp);
set<string> generatePermutations(string str);
void operator+=(set<string> &s, string str);
ostream &operator<<(ostream &os, set<string> s);
string toString(set<string> s);

int main()
{
    permuteStr("abcd");
    cout << generatePermutations("aabb") << endl;
    return 0;
}

/*
 * Function: permuteStr
 * Usage: permuteStr("abcd");
 * ---------------------------------------
 * Solving anagram problems, the result permutations of the  word "abcd" will
 * return 24 different results.
 */

void permuteStr(string str) { permuteStr("", str); }
void permuteStr(string soFar, string rest)
{
    if (rest == "")
    {
        cout << soFar << endl;
        return;
    }
    for (int i = 0; i < rest.length(); i++)
    {
        string remaining = rest.substr(0, i) + rest.substr(i + 1);
        permuteStr(soFar + rest[i], remaining);
    }
}

void permuteStr(string str, int lhp, int rhp)
{
    if (lhp == rhp)
        cout << str << endl;
    else
    {
        for (int i = lhp; i <= rhp; i++)
        {
            swap(str[lhp], str[i]);        // swapping
            permuteStr(str, lhp + 1, rhp); // recursion call
            swap(str[lhp], str[i]);        // backtracking
        }
    }
}

/*
 * Function: generatePermutations
 * Usage: set<string> permutations = generatePermutations("aabb")
 * ---------------------------------------
 * Returns a set consisting of all permutations of the specified string, using the
 * recursive insight that we can generate all permutations of string by selecting
 * each character in turn, generating all permutations of the string without that
 * character, and then concatenating the selected character on the front of each
 * string generated.
 */

set<string> generatePermutations(string str)
{
    set<string> result;
    if (str == "")
        result += "";
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            string rest = str.substr(0, i) + str.substr(i + 1);
            for (string s : generatePermutations(rest))
                result += ch + s;
        }
    }
    return result;
}

void operator+=(set<string> &s, string str) { s.insert(str); }
ostream &operator<<(ostream &os, set<string> s) { return os << toString(s); }
string toString(set<string> s)
{
    string result = "(";
    for (string str : s)
        result += str + ", ";
    return result + ")";
}