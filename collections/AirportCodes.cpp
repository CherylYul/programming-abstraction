/*
 * File: AirportCodes.cpp
 * ---------------------------------------
 * Looks up 3 letters airport code in a Map object
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "../string/mstring.h"
#include "../string/mstring.cpp"
using namespace std;

void readCodeFile(string filename, map<string, string> &map);

int main()
{
    map<string, string> airportCodes;
    readCodeFile("AirportCodes.txt", airportCodes);
    while (true)
    {
        string line;
        cout << "Airport code: ";
        getline(cin, line);
        if (line == "")
            break;
        string code = toUpperCase(line);
        if (airportCodes.find(code) != airportCodes.end())
            cout << airportCodes[code] << endl;
        else
            cout << "Not found" << endl;
    }
    return 0;
}

void readCodeFile(string filename, map<string, string> &map)
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
        map.insert(std::pair<string, string>(code, line.substr(4)));
    }
    infile.close();
}