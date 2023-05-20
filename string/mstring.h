/*
 * File: mstring.h
 * ---------------------------------------------
 * This interface exports my special useful string function
 */

#pragma once
#ifndef _mstring_h
#define _mstring_h
#include <iostream>
#include <sstream>
#include <fstream>

int getInteger(std::string prompt);
void copyStream(std::istream &is, std::ostream &os);

int countSpaces(std::string str);

bool startsWith(std::string str, std::string prefix);
bool endsWith(std::string str, std::string suffix);

std::string repeatChar(char ch, int k);
std::string reverse(std::string str);

bool isDigitString(std::string str);
bool equalsIgnoreCase(std::string str1, std::string str2);

void toUpperCaseInPlace(std::string &str);
void toLowerCaseInPlace(std::string &str);

std::string toUpperCase(std::string str);
std::string toLowerCase(std::string str);

bool isPalindrome(std::string str);

std::string secondHalf(std::string str);

std::string trim(std::string str);
void trimEndInPlace(std::string &str);
void trimStartInPlace(std::string &str);
std::string trimEnd(std::string str);
std::string trimStart(std::string str);

#endif