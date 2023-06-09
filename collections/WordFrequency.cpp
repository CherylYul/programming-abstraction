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
#include "../io/filelib.h"
#include "../io/filelib.cpp"
#include "map.h"
#include "vector.h"
using namespace std;

void countWords(istream &stream, Map<string, int> &wordCounts);
void displayWordCounts(Map<string, int> &wordCounts);
void extractWords(string line, Vector<string> &word);

int main()
{
    ifstream infile;
    Map<string, int> wordCounts;
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
void countWords(istream &stream, Map<string, int> &wordCounts)
{
    Vector<string> lines, words;
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

void displayWordCounts(Map<string, int> &wordCounts)
{
    for (string word : wordCounts)
        cout << left << setw(15) << word << right << setw(5) << wordCounts[word] << endl;
}

/*
 * Function: extractWords
 * Usage: extractWords(line, words);
 * ---------------------------------------
 * Extract words from the line into the string vector words
 */

void extractWords(string line, Vector<string> &words)
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
                words.add(line.substr(start, i - start));
                start = -1;
            }
        }
    }
    if (start >= 0)
        words.add(line.substr(start));
}