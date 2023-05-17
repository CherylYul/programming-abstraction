/*
 * File: calendar.h
 * -------------------------------------------
 * This interface exports the Month type along with function
 * calculating days in month and checking if it is leap year
 */

#ifndef _calendar_h
#define _calendar_h
#include <string>

bool isLeapYear(int year);
int daysInMonth(int month, int year);
std::string monthToString(int month);

#endif