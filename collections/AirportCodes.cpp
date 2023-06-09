/*
 * File: AirportCodes.cpp
 * ---------------------------------------
 * Looks up 3 letters airport code in a Map object
 */

#include <iostream>
#include <fstream>
#include <string>
#include "../error/error.h"
#include "../error/error.cpp"
#include "map.h"
using namespace std;

void readCodeFile(string filename, Map<string, string> &map);

int main()
{
    Map<string, string> airportCodes;
    readCodeFile("AirportCodes.txt", airportCodes);
    while (true)
    {
        string line;
        cout << "Airport code: ";
        getline(cin, line);
        if (line == "")
            break;
        string code = toUpperCase(line);
        if (airportCodes.containsKey(code))
            cout << airportCodes.get(code) << endl;
        else
            cout << "Not found" << endl;
    }
    return 0;
}

void readCodeFile(string filename, Map<string, string> &map)
{
    ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail())
        error("Can't read the data file");
    string line;
    while (getline(infile, line))
    {
        if (line.length() < 4 || line[3] != '=')
            error("Illegal data line: " + line);
        string code = toUpperCase(line.substr(0, 3));
        map.put(code, line.substr(4));
    }
    infile.close();
}