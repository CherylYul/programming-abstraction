/*
 * File: PrintLongestLine
 * -------------------------------
 * This file print the longest line in a file chosen by users
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include "filelib.h"
#include "filelib.cpp"
using namespace std;

int main()
{
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    printLongestLine(infile);
    infile.close();
    return 0;
}