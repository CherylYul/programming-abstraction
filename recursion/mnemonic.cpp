/*
 * File: Mnemonic.cpp
 * ---------------------------------------
 * On a telephone keypad, the digits are mapped onto the alphabet,
 * ex: 2 -> ABC, 8 -> TUV. This program writes a function list mnemonics
 * that generates all possible letter combinations, ex ("82") will return
 * AT, AU, AV, BT, BU, BV, CT, CU, CV
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

static map<int, string> keypad = {{0, ""},
                                  {1, ""},
                                  {2, "ABC"},
                                  {3, "DEF"},
                                  {4, "GHI"},
                                  {5, "JKL"},
                                  {6, "MNO"},
                                  {7, "PQRS"},
                                  {8, "TUV"},
                                  {9, "WXYZ"}};

void listMnemonics(int num);
void mnemonics(string soFar, vector<int> digits, int currentIndex);
vector<int> digitsVec(int num);

int main()
{
    listMnemonics(123);
    return 0;
}

void listMnemonics(int num)
{
    vector<int> digits = digitsVec(num);
    for (int i = 0; i < digits.size(); i++)
        if (digits[i] == 0 || digits[i] == 1)
            digits.erase(digits.begin() + i);
    mnemonics("", digits, digits.size() - 1);
}

void mnemonics(string soFar, vector<int> digits, int currentIndex)
{
    if (soFar.length() == digits.size())
    {
        cout << soFar << " ";
        return;
    }
    // Access the current digit
    int currentDigit = digits[currentIndex];
    // Access the length of string compatible with its digit
    int currentDigitLength = keypad[currentDigit].length();
    currentIndex--;
    for (int i = 0; i < currentDigitLength; i++)
        mnemonics(soFar + keypad[currentDigit][i], digits, currentIndex);
}

vector<int> digitsVec(int num)
{
    vector<int> digits;
    int div = 1;
    while (num > div)
    {
        digits.push_back(num / div % 10);
        div *= 10;
    }
    return digits;
}