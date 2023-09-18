/*
 * File: Obenglobish.cpp
 * -----------------------------------
 * Obenglobish is a transformation of English, in which words are created by
 * adding letters ob before the vowels (a, e, i, o, u) in English word
 * Ex: English => Obenglobish
 * Notes: ob should added before every vowel in English word except:
 *  1. Vowels that follow other vowels
 *  2. An e occurs at the end of the word
 */

#include <iostream>
#include <cctype>
using namespace std;

string lineToObenglobish(string line);
string wordToObenglobish(string word);
bool isVowel(char ch);

int main()
{
    cout << "Enter English text: " << endl;
    string line;
    getline(cin, line);
    cout << lineToObenglobish(line) << endl;
    return 0;
}

string lineToObenglobish(string line)
{
    string result = "";
    int start = -1;
    for (int i = 0; i < line.length(); i++)
    {
        bool isText = isalpha(line[i]);
        if (isText && start == -1)
            start = i;
        if (!isText && start >= 0)
        {
            result += wordToObenglobish(line.substr(start, i - start)) + line[i];
            start = -1;
        }
    }
    if (start >= 0)
        result += wordToObenglobish(line.substr(start));
    return result;
}

string wordToObenglobish(string word)
{
    string result = "";

    for (int i = 0; i < word.length() - 1; i++)
    {
        if (isVowel(word[i]))
        {
            if (i == 0 || !isVowel(word[i - 1]))
                result += "ob" + word.substr(i, 1);
        }
        else
            result += word.substr(i, 1);
    }
    int lastPos = word.length() - 1;
    if (isVowel(word[lastPos]) && word[lastPos] != 'e' && word[lastPos] != 'E')
        return result + "ob" + word[lastPos];
    return result + word[lastPos];
}

bool isVowel(char ch)
{
    switch (ch)
    {
    case 'a':
    case 'e':
    case 'o':
    case 'u':
    case 'i':
    case 'A':
    case 'E':
    case 'O':
    case 'U':
    case 'I':
        return true;
    default:
        return false;
    }
}