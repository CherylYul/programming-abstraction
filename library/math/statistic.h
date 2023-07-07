/*
 * File: vector.h
 * ---------------------------------------
 * This interfaces export useful function to calculate common
 * statistical measure.
 */

#ifndef _statistic_h
#define _statistic_h
#include <string>

int fact(int n);
int combinations(int n, int k);
int internalComb(int n, int k);
int permutations(int n, int k);
void permute(std::string str);
void permute1(std::string soFar, std::string rest);
void permute2(std::string str, int lhp, int rhp);
void listSubsets(std::string input, std::string soFar);

double sum(std::vector<double> &data);
double mean(std::vector<double> &data);
double var(std::vector<double> &data);
double stddev(std::vector<double> &data);
void histogram(std::vector<double> &data, int divisor);
double minVec(std::vector<double> &data);
double maxVec(std::vector<double> &data);

void swap(char &a, char &b);

#endif