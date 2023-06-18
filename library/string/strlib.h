/*
 * File: strlib.h
 * -----------------------------------------
 * This interface export useful function to convert string and integers
 */

#pragma once
#ifndef _strlib_h
#define _strlib_h
#include <string>

int getInteger(std::string prompt);
int stringToInteger(std::string str);
double stringToDouble(std::string str);
std::string integerToString(int n);
std::string doubleToString(double n);

#endif