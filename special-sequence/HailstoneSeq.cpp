/*
 * File: HailstoneSeq
 * -----------------------------------------
 * This program read in an interger, then repeatedly executing
 * the hailstone sequence rules:
 * 1. If n = 1, stop program
 * 2. If n is even, divide by 2
 * 3. If n is odd, multiply by 3 and add 1
 */

#include <iostream>
using namespace std;

int main()
{
    int value;
    cout << "Enter a number: ";
    cin >> value;
    while (value != 1)
    {
        if (value % 2 == 0)
        {
            cout << value << " is even, so I divide it by 2 to get ";
            value /= 2;
            cout << value << endl;
        }
        else
        {
            cout << value << " is odd, so I multiply by 3 and add 1 to get ";
            value = value * 3 + 1;
            cout << value << endl;
        }
    }
    return 0;
}