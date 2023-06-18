/*
 * File: vector.h
 * ---------------------------------------
 * This interfaces export useful function to calculate common
 * statistical measure.
 */

#ifndef _statistic_h
#define _statistic_h
#include <string>

double mean(std::vector<double> &data);
double var(std::vector<double> &data);
double stddev(std::vector<double> &data);
void histogram(std::vector<double> &data, int divisor);
double minVec(std::vector<double> &data);
double maxVec(std::vector<double> &data);

#endif