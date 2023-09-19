/*
 * File: CeasarCipher.cpp
 * --------------------------------------
 * The technique by Julius Ceasar which replace each letter in the orginal
 * message by the letter that appear a fixed distance a head in the alphabet.
 */

#include <iostream>
#include <cctype>
#include <vector>
#include "library/string/strlib.h"
#include "library/string/strlib.cpp"

using namespace std;

vector<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

string encodeCeasarCipher(string str, int shift);
string encodeSubstitution(string str, string sub);
string invertKey(string encodeMessage, string encryptionKey);
int getIndex(vector<char> v, char ch);

int main()
{
    string cipherKey;
    cout << "Enter a 26-letter key: " << endl;
    getline(cin, cipherKey);
    string line;
    cout << "Encoded message: " << endl;
    getline(cin, line);
    cout << "Encrypt: " << invertKey(line, cipherKey) << endl;
    return 0;
}

string encodeCeasarCipher(string str, int shift)
{
    string result = "";
    shift = shift % 26;
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            int idx = getIndex(alpha, tolower(str[i]));
            int encode = idx + shift < 26 ? idx + shift : idx + shift - 26;
            result += alpha[encode];
        }
        else if (isspace(str[i]))
            result += " ";
        else
            result += str[i];
    }
    return result;
}

int getIndex(vector<char> v, char ch)
{
    auto it = find(v.begin(), v.end(), ch);
    if (it != v.end())
        return it - v.begin();
    return -1;
}

string encodeSubstitution(string str, string sub)
{
    string result = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
        {
            int idx = getIndex(alpha, tolower(str[i]));
            result += sub[idx];
        }
        else if (isspace(str[i]))
            result += " ";
        else
            result += str[i];
    }
    return result;
}

string invertKey(string encodeMessage, string encryptionKey)
{
    string result;
    for (int i = 0; i < encodeMessage.length(); i++)
    {
        if (isalpha(encodeMessage[i]))
        {
            int idx = encryptionKey.find(toupper(encodeMessage[i]));
            result += alpha[idx];
        }
        else if (isspace(encodeMessage[i]))
            result += " ";
        else
            result += encodeMessage[i];
    }
    return result;
}