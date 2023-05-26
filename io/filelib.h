/*
 * filelib.h
 * -----------------------------------------
 * This interface export useful function for file handling
 */

#pragma once
#ifndef _filelib_h
#define _filelib_h

std::string promptUserForFile(std::ifstream &infile, std::string prompt = "");

void copyStream(std::istream &is, std::ostream &os);
void displayChar(std::ifstream &infile);
void displayLine(std::ifstream &infile);
// void readEntireFile(istream &is, Vector<string> &lines);

int getInteger(std::string prompt);
int stringToInteger(std::string str);
std::string integerToString(int n);

void printLongestLine(std::ifstream &infile);
void reportLineWordChar(std::ifstream &infile, int &charCount, int &wordCount, int &lineCount);
int countSpace(std::string str);
std::string getExtension(const std::string &filename);
std::string getRoot(const std::string &filename);
std::string defaultExtension(const std::string filename, const std::string ext);

void error(std::string msg);
#endif