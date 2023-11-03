/*
 * File: embeddedWords
 * ---------------------------------------
 * Find all words formed by taking some subset of letters from a given
 * starting word in consecutive order.
 * Ex: love => lo, lv, le, ov, oe, ve, lov, loe, lve, ove, love
 * (2^n - 1- n cases)
 */

#include <iostream>
#include <ostream>
#include <set>
using namespace std;

void embeddedWords(string str);
void embeddedWords(string &str, string result, set<string> &s, int pos);
ostream &operator<<(ostream &os, set<string> s);
string toString(set<string> s);

int main()
{
    string str1 = "happy";
    embeddedWords(str1);
    string str2 = "love";
    embeddedWords(str2);
    return 0;
}

void embeddedWords(string str)
{
    set<string> s;
    embeddedWords(str, "", s, 0);
    cout << s << endl;
}

void embeddedWords(string &str, string result, set<string> &s, int pos)
{
    if (pos >= str.length())
    {
        if (result.length() > 1)
            s.insert(result);
        return;
    }
    pos++;
    embeddedWords(str, result, s, pos); // skip the first character (exclude)
    result += str[pos - 1];
    embeddedWords(str, result, s, pos); // take the first character (include)
}

ostream &operator<<(ostream &os, set<string> s) { return os << toString(s); }
string toString(set<string> s)
{
    string result = "(";
    for (string str : s)
        result += str + ", ";
    return result + ")";
}