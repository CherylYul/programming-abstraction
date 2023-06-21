#include "../string/mstring.h"
#include "../string/mstring.cpp"
#include "../io/filelib.h"
#include "../io/filelib.cpp"
#include <map>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void wordTally();
string alphaOnly(string s);

int main()
{
    wordTally();
    return 0;
}

void wordTally()
{

    ifstream input;
    promptUserForFile(input, "Input file: ");
    map<string, int> tally;

    string word;
    while (input >> word)
    { // read one word
        word = alphaOnly(word);
        word = toLowerCase(word);
        tally[word]++;
    }

    while (true)
    {
        string word;
        cout << "Word to search for (Enter to quit)? " << endl;
        getline(cin, word);
        toLowerCaseInPlace(word);
        if (word == "")
            break;
        else
        {
            int count = tally[word];
            cout << word << " occurs " << count << " times." << endl;
        }
    }
}

string alphaOnly(string fullStr)
{
    // walk through the string and just keep the alpha characters
    string alphaStr;
    for (char c : fullStr)
    {
        if (isalpha(c))
        {
            alphaStr += c;
        }
    }
    return alphaStr;
}
