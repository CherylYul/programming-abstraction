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

bool isEven(unsigned int n);
bool isOdd(unsigned int n);
bool isPerfect(int n);
bool isPrime(int n);
void primeFactorization(int n);
void solveQuadratic(double a, double b, double c, double &x1, double &x2);

#endif