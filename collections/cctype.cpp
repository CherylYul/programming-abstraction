#include <string>
#include <set>
using namespace std;

set<char> setFromString(string str);
set<char> concatSet(set<char> setA, set<char> setB);

const set<char> DIGIT_SET = setFromString("0123456789");
const set<char> LOWER_SET = setFromString("abcdefghijklmnopqrstuvwxyz");
const set<char> UPPER_SET = setFromString("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const set<char> PUNCT_SET = setFromString("!\"#$%&'()*+,-./:;<=>?@[\\]^_`(|)");
const set<char> SPACE_SET = setFromString(" \t\v\f\n\r");
const set<char> XDIGIT_SET = setFromString("0123456789ABCDEFabcdef");
const set<char> ALPHA_SET = concatSet(LOWER_SET, UPPER_SET);
const set<char> ALNUM_SET = concatSet(ALPHA_SET, DIGIT_SET);
const set<char> SPEC_SET = concatSet(PUNCT_SET, SPACE_SET);
const set<char> PRINT_SET = concatSet(ALNUM_SET, SPEC_SET);

bool isalnum(char ch)
{
    for (set<char>::iterator i = ALNUM_SET.begin(); i != ALNUM_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool isalpha(char ch)
{
    for (set<char>::iterator i = ALPHA_SET.begin(); i != ALPHA_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool isdigit(char ch)
{
    for (set<char>::iterator i = DIGIT_SET.begin(); i != DIGIT_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool islower(char ch)
{
    for (set<char>::iterator i = LOWER_SET.begin(); i != LOWER_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool isprint(char ch)
{
    for (set<char>::iterator i = PRINT_SET.begin(); i != PRINT_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool ispunct(char ch)
{
    for (set<char>::iterator i = PUNCT_SET.begin(); i != PUNCT_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool isspace(char ch)
{
    for (set<char>::iterator i = SPACE_SET.begin(); i != SPACE_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool isupper(char ch)
{
    for (set<char>::iterator i = UPPER_SET.begin(); i != UPPER_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

bool isxdigit(char ch)
{
    for (set<char>::iterator i = XDIGIT_SET.begin(); i != XDIGIT_SET.end(); ++i)
    {
        if (ch == *i)
            return true;
    }
    return false;
}

set<char> setFromString(string str)
{
    set<char> setx;
    for (int i = 0; i < str.length(); i++)
        setx.insert(str[i]);
    return setx;
}

set<char> concatSet(set<char> setA, set<char> setB)
{
    set<char> newSet = setA;
    for (char i : setB)
        newSet.insert(i);
    return newSet;
}