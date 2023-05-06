/*
 * File: DigitSum.cpp
 * ------------------------------------------------------
 * This program read in an integer and then displays the
 * number that has the same digits in the reverse orders
 */

#include <iostream>
using namespace std;

/* Function Prototype */
int digitSum(int num);

/* Main program */
int main()
{
    int value;
    cout << "This program reverses the digits in an integer." << endl;
    cout << "Enter a positive integer: ";
    cin >> value;
    cout << "The reversed integer is " << digitSum(value) << endl;
    return 0;
}

/* Function: digitSum
 * Usage: int num = digitSum(num);
 * ------------------------------------------
 * Returns the reverse number
 */

int digitSum(int num)
{
    int result = 0;
    while (num >= 1)
    {
        result = (result * 10) + (num % 10);
        num /= 10;
    }
    return result;
}