/*
 * File: ScrabbleScore.cpp
 * ---------------------------------------
 * Scrabble is the table word game, each letter in a word is
 * scored according to its point value, which is inversely proportional
 * to its frequency in English words
 */

#include <iostream>
#include <cctype>
using namespace std;

int scrabblePoint(char ch);

int main()
{
    string line;
    cout << "Input word: ";
    getline(cin, line);
    int point = 0;
    for (int i = 0; i < line.length(); i++)
        point += scrabblePoint(line[i]);
    cout << point << endl;
    return 0;
}

int scrabblePoint(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
        return 1;
    case 'D':
    case 'G':
        return 2;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
        return 3;
    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
        return 4;
    case 'K':
        return 5;
    case 'J':
    case 'X':
        return 8;
    case 'Q':
    case 'Z':
        return 10;
    default:
        return 0;
    }
}