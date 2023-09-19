/*
 * File: EvaluateStyle.cpp
 * -------------------------------
 * Evaluate style of input file by changing the letter to random letter
 */

#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>
#include "random/random.h"
#include "random/random.cpp"
using namespace std;

string lowerAlpha = "abcdefghijklmnopqrstuvwxyz";
string upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string randomLetters(string file);
int main()
{
    ifstream infile;
    string filename;
    cout << "Input a file: " << endl;
    getline(cin, filename);
    infile.open(filename);
    string line;
    string result = "";
    while (getline(infile, line))
    {
        result += line + "\n";
        cout << line << endl;
    }
    cout << randomLetters(result) << endl;
    infile.close();
    return 0;
}

string randomLetters(string file)
{
    string output = "";
    for (int i = 0; i < file.length(); i++)
    {
        if (isalpha(file[i]))
        {
            int idx = randomInteger(0, 25);
            if (isupper(file[i]))
                output += upperAlpha[idx];
            else
                output += lowerAlpha[idx];
        }
        else
            output += file[i];
    }
    return output;
}
