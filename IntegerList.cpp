/*
 * Files: Integer List
 * ------------------------------------------------------------
 * This program is a list of input integers, the end of program
 * is signal by a sentinel value, users can choose to:
 * 1. Calculate total input value
 * 2. Calculate average input value
 * 3. Find the top 3 highest value
 */

#include <iostream>
using namespace std;

const int SENTINEL = 0;

/* main program */
int main()
{
    cout << "This program calculate list of integers from your input, use "
         << SENTINEL << " to signal end" << endl;
    int number = 0;
    int total = 0;
    int max1 = 0;
    int max2 = 0;
    int max3 = 0;
    double average;
    while (true)
    {
        int value;
        cout << "Your " << number++ << " integer: ";
        cin >> value;
        if (value == SENTINEL)
        {
            break;
        }
        total += value;
        average = total / number;
        if (value > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = value;
        }
        else if (value > max2)
        {
            max3 = max2;
            max2 = value;
        }
        else if (value > max3)
        {
            max3 = value;
        }
    }
    cout << "The total is " << total << endl;
    cout << "The average is " << average << endl;
    cout << "Top 3 values are: " << max1 << ", " << max2 << ", " << max3 << endl;
    return 0;
}