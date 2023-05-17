/*
 * File: calendar.cpp
 * -----------------------------------
 * Implements calendar.h interface
 */

#include <iostream>
#include "calendar.h"
using namespace std;

int main()
{
    int year;
    cout << "Enter a year: ";
    cin >> year;
    for (int i = 1; i < 13; i++)
    {
        cout << monthToString(i) << " has " << daysInMonth(i, year) << " days." << endl;
    }
    return 0;
}

int daysInMonth(int month, int year)
{
    switch (month)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return (isLeapYear(year)) ? 29 : 28;
    default:
        return 31;
    }
}

bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

string monthToString(int month)
{
    switch (month)
    {
    case 1:
        return "JANUARAY";
    case 2:
        return "FEBRUARY";
    case 3:
        return "MARCH";
    case 4:
        return "APRIL";
    case 5:
        return "MAY";
    case 6:
        return "JUNE";
    case 7:
        return "JULY";
    case 8:
        return "AUGUST";
    case 9:
        return "SEPTEMBER";
    case 10:
        return "OCTOBER";
    case 11:
        return "NOVEMBER";
    case 12:
        return "DECEMBER";
    }
}