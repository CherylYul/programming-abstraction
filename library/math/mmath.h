/*
 * File: mmath.h
 * ---------------------------------------------
 * This interface exports my special useful math function
 */

#pragma once
#ifndef _mmath_h
#define _mmath_h

int reverseN(int n);
int squareN(int n);
double sqrtN(double n);
int powerN(int n, int k);
int roundN(double n);
double roundToDecimals(double n, int d);
int gcd(int x, int y);

int internalDigitSum(int n, int div);
int digitSum(int n);
int digitalRoot(int n);

bool isEven(unsigned int n);
bool isOdd(unsigned int n);
bool isPerfect(int n);
bool isPrime(int n);
void primeFactorization(int n);
void sievePrime(int n);
void solveQuadratic(double a, double b, double c, double &x1, double &x2);

void swap(int &x, int &y);

#endif