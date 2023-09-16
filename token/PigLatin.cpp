/*
 * File: PigLatin.cpp
 * -------------------------------------------------------------------------------
 * This program converts lines from English to Pig Latin
 * This dialect of Pig Latin applies the following rules:
 *
 * 1. If the word contains no vowels, return the original word unchanged
 * 2. If the word begins with a consonant, extract the set of consonants up to the
 *    first vowel, move that set of consonants to the end of the word, and add "ay"
 * 3. If the word begins with a vowel, add "way" to the end  of the word
 */

#include <iostream>
#include <string>
#include <cctype>
// #include "lexicon.h"
using namespace std;

/* Function Prototype */
string lineToPigLatin(string line);
string wordToPigLatin(string word, bool isCap);
int findFirstVowel(string word);
bool isVowel(char ch);
void pigEnglish();

/* main program */
int main()
{
    cout << "This program translates English to Pig Latin." << endl;
    string line;
    cout << "Enter English text: ";
    getline(cin, line);
    string translation = lineToPigLatin(line);
    cout << "Pig Latin output: " << translation << endl;
    return 0;
}

/*
 * Function: lineToPigLatin
 * Usage: string translation = lineToPigLatin(line);
 * -------------------------------------------------------------------------------
 * Translation each word in the line to Pig Latin, leaving all other charaters unchanged.
 * The variable start keeps track of the index position at which the current word begins.
 * As a special case, the code sets start to -1 to indicate the the beginning of the current
 * word has not yet been encountered
 *
 * string lineToPigLatin(string line) {
 *      TokenScanner scanner(line);
 *      string result = "";
 *      while (scanner.hasMoreTokens()) {
 *          string word = scanner.nextToken();
 *          if (isalpha(word[0])) word = wordToPigLatin(word);
 *          result += word;
 *      }
 *      return result;
 * }
 */

string lineToPigLatin(string line)
{
    string result;
    int start = -1;
    for (int i = 0; i < line.length(); i++)
    {
        bool isText = isalpha(line[i]);
        if (isText && start == -1)
            start = i;
        if (!isText && start >= 0)
        {
            result += wordToPigLatin(line.substr(start, i - start), isupper(line[start])) + line[i];
            start = -1;
        }
    }
    if (start >= 0)
        result += wordToPigLatin(line.substr(start), isupper(line[start]));
    return result;
}

/*
 * Function: wordToPigLatin
 * Usage: string translation = wordToPigLatin(word);
 * -------------------------------------------------------------------------------
 * This function translates a word from English to Pig Latin using the rules
 * specified in the text. The translated word is returned as the value of the function.
 */

string wordToPigLatin(string word, bool isCap)
{
    int vp = findFirstVowel(word);
    if (vp == -1)
        return word;
    if (vp == 0)
        return word + "way";
    char oldStart = isCap ? tolower(word[0]) : word[0];
    char newStart = isCap ? toupper(word[vp]) : word[vp];
    string head = word.substr(1, vp - 1);
    string tail = word.substr(vp + 1);
    return newStart + tail + oldStart + head + "ay";
}

/*
 * Function: findFirstVowel
 * Usage: int k = findFirstVowel(word);
 * --------------------------------------------------------------
 * Returns the index position of the first vowel in word. If word
 * does not contain a vowel, findFirstVowel returns -1
 */

int findFirstVowel(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (isVowel(word[i]))
            return i;
    }
    return -1;
}

/*
 * Function: isVowel
 * Usage: if (isVowel(ch)) ...
 * --------------------------------------------------------------
 * Returns true if character ch is a vowel
 */
bool isVowel(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'E':
    case 'O':
    case 'U':
    case 'I':
    case 'a':
    case 'e':
    case 'o':
    case 'u':
    case 'i':
        return true;
    default:
        return false;
    }
}

/*
 * Function: pigEnglish();
 * ---------------------------------------
 * Find all English words that remain words when convert to Pig Latin
 */

// void pigEnglish()
// {
//     Lexicon english("EnglishWords.dat");
//     for (string word : english)
//     {
//         string pig = wordToPigLatin(word);
//         if (pig != word && english.contains(pig))
//         {
//             cout << word << " -> " << pig << endl;
//         }
//     }
// }