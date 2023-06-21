/*
 * CS 106B, Chris Piech
 * This program demonstrates the use of the Stanford C++ Set class.
 * A set is a collection without duplicates that efficiently supports
 * the core operations of adding, removing, and searching for elements.
 */

#include "console.h"
#include "filelib.h"
#include "hashset.h"
#include "lexicon.h"
#include "set.h"
#include "timer.h"
#include "vector.h"
#include <fstream>
#include <iomanip>
#include <iostream>

// possible choices: VECTOR, SET, HASHSET
#define VECTOR

using namespace std;

// function prototype declarations
bool contains(Vector<string> &v, string &s);
void wordCount(string filename);

int main() {
    // use a timer to see how long the function takes to run
    Timer timer;

#ifdef VECTOR
    Vector<string> uniqueWords;
#elif defined SET
    Set<string> uniqueWords;
#elif defined HASHSET
    HashSet<string> uniqueWords;
#endif
    cout << "Reading in Moby Dick." << endl;
    ifstream input;
    openFile(input, "res/mobydick.txt");
    string word;
    cout << "Starting test..." << endl;
    int wordCount = 0;
    timer.start();
    while (input >> word) { // read one word
        wordCount++;
        if (wordCount % 10000 == 0) {
            cout << wordCount << "..." << endl;
        }
#ifdef VECTOR
        // for Vector, check and see if the word is already present
        bool wordFound = false;
        for (int i = 0; i < uniqueWords.size(); i++) {
            string nextWord = uniqueWords[i];
            if (nextWord == word) {
                wordFound = true;
                break;
            }
        }
        if (!wordFound)
#endif
            uniqueWords.add(word);
    }
    uniqueWords.add(word);
}

cout << endl;
cout << "Found " << uniqueWords.size() << " unique words " << endl;
cout << "Took " << timer.stop() << " ms." << endl;

return 0;
}
