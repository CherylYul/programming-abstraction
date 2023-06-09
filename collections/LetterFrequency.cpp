/*
 * File: LetterFrequency.cpp
 * -----------------------------------------
 * This program counts the frequency of letters in a data files.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "../io/filelib.h"
#include "../io/filelib.cpp"
#include "../vector/veclib.h"
#include "../vector/veclib.cpp"
#include "vector.h"

static const int COLUMNS = 7;

int main()
{
    Vector<int> letterCounts(26);
    ifstream infile;
    promptUserForFile(infile, "Input File: ");
    char ch;
    while (infile.get(ch))
        if (isalpha(ch))
            letterCounts[toupper(ch) - 'A']++;
    infile.close();
    for (char ch = 'A'; ch <= 'Z', ch++)
        cout << setw(COLUMNS) << letterCounts[ch - 'A'] << " " << ch << endl;
    return 0;
}