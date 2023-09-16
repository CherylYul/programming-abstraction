/*
 * File: mstring.h
 * ---------------------------------------------
 * This interface exports my special useful string function
 */

#pragma once
#ifndef _mstring_h
#define _mstring_h
#include <string>

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
bool isSubstrPalindrome(std::string str, int lsp, int rsp);
bool isSentencePalindrome(std::string str);

std::string secondHalf(std::string str);

std::string trim(std::string str);
void trimEndInPlace(std::string &str);
void trimStartInPlace(std::string &str);
std::string trimEnd(std::string str);
std::string trimStart(std::string str);

std::string substrOne(std::string str, int pos, char n);
std::string capitalize(std::string str);
std::string acronym(std::string str);

std::string removeCharacters(std::string str, std::string removeStr);
void removeCharactersInPlace(std::string &str, std::string removeStr);

std::string removeDoubledLetters(std::string str);
std::string replaceAll(std::string str, char c1, char c2);
std::string replaceAll(std::string str, std::string s1, std::string s2);

std::string createRegularPlural(std::string word);
std::string createOrdinalForm(int n);
std::string addCommas(int digits);

int strlen(char str[]);
int strlen(char *cp);

void printNTimes(char c, int n);

#endif