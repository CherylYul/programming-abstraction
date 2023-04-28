/*
 * File: ConvertMeters.cpp
 * -----------------------------------------
 * This program converts meters into English
 * distance feet and inches
 */

#include <iostream>
using namespace std;

int main()
{
    double n;
    int choice;
    cout << "The number of meters you would like to converts: " << endl;
    cin >> n;
    cout << "If you would like to convert in feets press 0, to inches press 1" << endl;
    cin >> choice;
    if (choice == 0)
    {
        cout << "The results value is " << n / 0.0254 << endl;
    }
    else
    {
        cout << "The results value is " << n / (12 * 0.0254) << endl;
    }
    return 0;
}