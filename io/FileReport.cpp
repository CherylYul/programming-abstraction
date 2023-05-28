/*
 * File: FileReport.cpp
 * ----------------------------------------
 * This program read a file and report how many lines, words
 * and characters appear in it
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
    int chCount = 0;
    int wCount = 0;
    int lCount = 0;
    promptUserForFile(infile, "Input file: ");
    reportLineWordChar(infile, chCount, wCount, lCount);
    infile.close();
    cout << chCount << endl;
    cout << wCount << endl;
    cout << lCount << endl;
    return 0;
}