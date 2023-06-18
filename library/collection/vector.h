/*
 * File: vector.h
 * ---------------------------------------
 * This interfaces export useful function to work with vectors
 */

#ifndef _vector_h
#define _vector_h
#include <string>

std::vector<int> operator+(std::vector<int> v1, std::vector<int> v2);
std::vector<int> operator-(std::vector<int> v1, std::vector<int> v2);
std::string toString(std::vector<int> vec);
std::ostream &operator<<(std::ostream &os, std::vector<int> vec);
int sumVector(std::vector<int> vec);

std::string promptUserForFile(std::ifstream &infile, std::string prompt);
void readVector(std::istream &is, std::vector<int> &vec);
void readVector(std::istream &is, std::vector<double> &vec);
void readVector(std::istream &is, std::vector<std::string> &vec);

void removeElements(std::vector<int> &vec, int element);

#endif