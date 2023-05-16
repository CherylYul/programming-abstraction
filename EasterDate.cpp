/*
 * File: EasterDate.cpp
 * ----------------------------------
 * The programs calculate the Easter Date from 1900-2099.
 * Easter Date is the first Sunday after the full Moon
 * that occurs on or after the spring equinox.
 */

#include <iostream>
using namespace std;

void findEaster(int year, string &month, int &day);

int main()
{
    int year;
    string month;
    int day;
    cout << "Easter Date of the year: ";
    cin >> year;
    findEaster(year, month, day);
    cout << month << " " << day << endl;
    return 0;
}

void findEaster(int year, string &month, int &day)
{
    int d = 225 - 11 * (year % 19);
    while (d > 50)
    {
        d -= 30;
    }
    if (d > 48)
    {
        d -= 1;
    }
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