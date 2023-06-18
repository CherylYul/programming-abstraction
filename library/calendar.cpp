/*
 * File: calendar.cpp
 * -----------------------------------------------
 * Implements calendar.h interface
 */

#include <iostream>
#include "calendar.h"
using namespace std;

/*
 * Function: daysInMonth
 * Usage: int results = daysInMonth(month, year);
 * -----------------------------------------------
 * Returns the number of days from the input month and year.
 */

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

/*
 * Function: isLeapYear
 * Usage: isLeapYear(year);
 * -----------------------------------------------
 * Checking if the input year is leap year.
 */

bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/*
 * Function: monthToString
 * Usage: string str = monthToString(month);
 * -----------------------------------------------
 * Converts month number into string type and returns it.
 */

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

/*
 * Function: findEaster
 * Usage: findEaster(year, month, day);
 * -----------------------------------------------
 * Calculate the Easter Date from 1900-2099. Easter Date is the first
 * Sunday after the full Moon that occurs on or after the spring equinox.
 */

void findEaster(int year, string &month, int &day)
{
    int d = 225 - 11 * (year % 19);
    while (d > 50)
        d -= 30;
    if (d > 48)
        d -= 1;
    int e = (year + (year / 4) + d + 1) % 7;
    int q = d + 7 - e;
    if (q < 32)
    {
        month = "March";
        day = q;
    }
    else
    {
        month = "April";
        day = q - 31;
    }
}