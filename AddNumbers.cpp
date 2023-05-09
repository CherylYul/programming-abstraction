/*
 * File: AddNumbers.cpp
 * ---------------------------------------------------
 * This program adds number together, user can choose:
 * 1. Add arbitrary n floating number together
 * 2. Add from 1 to n integer users want
 */

#include <iostream>
using namespace std;

/* Prototype Function */
double addArbitraryNum(int num);
int addToN(int num);

/* Main program */
int main()
{
    int userChoice;
    int num;
    cout << "This program adds numbers together:" << endl;
    cout << "Add arbitrary n floating number from your input: Press Key 1" << endl;
    cout << "Add from 1 to n interger: Press Key 2" << endl;
    cin >> userChoice;
    if (userChoice == 1)
    {
        cout << "How many numbers would you like to add together?" << endl;
        cin >> num;
        double sum = addArbitraryNum(num);
        cout << "The sum is: " << sum << endl;
    }
    else
    {
        cout << "What is the integer you want to add from 1 to it?" << endl;
        cin >> num;
        int total = addToN(num);
        cout << "The total is: " << total << endl;
    }
    return 0;
}

/*
 * Function: addArbitraryNum
 * Usage: double result = addArbitraryNum(int num);
 * -----------------------------------------------
 * Return total value the program reads in
 */

double addArbitraryNum(int num)
{
    double result = 0;
    for (int i = 0; i < num; i++)
    {
        double value;
        cout << "The " << i + 1 << " value is: ";
        cin >> value;
        result += value;
    }
    return result;
}

/*
 * Function: addToN
 * Usage: int total = addToN(int num);
 * -----------------------------------------------
 * Return total value the program from 1 to num
 */

int addToN(int num)
{
    int total = 0;
    for (int i = 0; i <= num; i++)
    {
        total += i;
    }
    return total;
}