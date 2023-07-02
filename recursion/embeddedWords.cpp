/*
 * File: embeddedWords
 * ---------------------------------------
 * Find all words formed by taking some subset of letters in order
 * from a given starting word in consecutive order.
 * Ex: love => lo, lv, le, ov, oe, ve, lov, loe, lve, ove, love
 * (2^n - 1- n cases)
 */

#include <iostream>
#include <vector>
using namespace std;

void embeddedWords(string str);
void embeddedWords(string &str, string result, vector<string> &v, int pos);

int main()
{
    string str = "happy";
    embeddedWords(str);
    return 0;
}

void embeddedWords(string str)
{
    vector<string> vec;
    embeddedWords(str, "", vec, 0);
}

void embeddedWords(string &str, string result, vector<string> &v, int pos)
{
    if (pos >= str.length())
    {
        if (result == "" || result.length() < 2)
            return;
        for (string s : v)
            if (result == s)
                return;
        v.push_back(result);
        cout << result << endl;
        return;
    }
    pos++;
    embeddedWords(str, result, v, pos); // skip the first character
    result += str[pos - 1];
    embeddedWords(str, result, v, pos); // take the first character
}

void permute(string soFar, string rest)
{
    if (rest == "")
    {
        cout << soFar << endl;
        return;
    }
    for (int i = 0; i < rest.length(); i++)
    {
        string remaining = rest.substr(0, i) + rest.substr(i + 1);
        permute(soFar + rest[i], remaining);
    }
}
