/*
 * File: mmath.h
 * ---------------------------------------------
 * This interface exports my special useful math function
 */

#pragma once
#ifndef _mmath_h
#define _mmath_h
#include <iostream>
#include <cmath>

int addToN(int n);
double addNInput(int n);
int reverseNum(int n);

int factorial(int n);
int combinations(int n, int k);
int permutations(int n, int k);
int square(int n);
int power(int n, int k);
int roundToNearestInt(double n);
double roundTo2(double n);
double sqrt(double n);

bool isPerfect(int n);
bool isEven(int n);
bool isPrime(int n);

void primeFactorization(int n);
void solveQuadratic(double a, double b, double c, double &x1, double &x2);
void error(string msg);

#endif