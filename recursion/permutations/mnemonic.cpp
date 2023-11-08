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

void mnemonics(int num);
void mnemonics(string soFar, vector<int> digits, int currentIndex);
vector<int> digits(int num);

int main()
{
    mnemonics(723);
    return 0;
}

void mnemonics(int num)
{
    vector<int> originalVec = digits(num);
    vector<int> resultVec;
    for (int digit : originalVec)
        if (digit != 0 && digit != 1)
            resultVec.push_back(digit);
    mnemonics("", resultVec, resultVec.size() - 1);
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

vector<int> digits(int num)
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