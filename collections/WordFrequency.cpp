/*
 * File: WordFrequency.cpp
 * ---------------------------------------
 * Computes the frequency of words in a text file
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
#include <map>
#include <vector>
#include "../io/filelib.h"
#include "../io/filelib.cpp"
#include "../string/mstring.h"
#include "../string/mstring.cpp"
using namespace std;

void countWords(istream &stream, map<string, int> &wordCounts);
void displayWordCounts(map<string, int> &wordCounts);
void extractWords(string line, vector<string> &word);

int main()
{
    ifstream infile;
    map<string, int> wordCounts;
    promptUserForFile(infile, "Input file: ");
    countWords(infile, wordCounts);
    infile.close();
    displayWordCounts(wordCounts);
    return 0;
}

/*
 * Function: countWords
 * Usage: countWords(stream, wordCounts);
 * ---------------------------------------
 * Counts words in input stream, store result in wordCounts
 */
void countWords(istream &stream, map<string, int> &wordCounts)
{
    vector<string> lines, words;
    readEntireFile(stream, lines);
    for (string line : lines)
    {
        extractWords(line, words);
        for (string word : words)
            wordCounts[toLowerCase(word)]++;
    }
}

/*
 * Function: displayWordCounts
 * Usage: displayWordCounts(wordCount);
 * ---------------------------------------
 * Display the count associated with each word in the wordCount map
 */

void displayWordCounts(map<string, int> &wordCounts)
{
    for (map<string, int>::iterator word = wordCounts.begin(); word != wordCounts.end(); ++word)
        cout << left << setw(15) << word->first << right << setw(5) << word->second << endl;
}

/*
 * Function: extractWords
 * Usage: extractWords(line, words);
 * ---------------------------------------
 * Extract words from the line into the string vector words
 */

void extractWords(string line, vector<string> &words)
{
    words.clear();
    int start = -1;
    for (int i = 0; i < line.length(); i++)
    {
        if (isalpha(line[i]))
        {
            if (start == -1)
                start = i;
        }
        else
        {
            if (start >= 0)
            {
                words.push_back(line.substr(start, i - start));
                start = -1;
            }
        }
    }
    if (start >= 0)
        words.push_back(line.substr(start));
}