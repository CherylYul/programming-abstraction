/*
 * File: calendar.h
 * -----------------------------------------------
 * This interfaces export useful function for handling or calculating
 * day problems
 */

#ifndef _calendar_h
#define _calendar_h
#include <string>

bool isLeapYear(int year);
int daysInMonth(int month, int year);
std::string monthToString(int month);
void findEaster(int year, std::string &month, int &day);

#endif