/*
 * File: sequence.h
 * ---------------------------------------------
 * This interface exports my special mathematical sequence when solving
 * problems in Programming Abstraction book
 */

#pragma once
#ifndef _sequence_h
#define _sequence_h

int triangularNumbers(int n);
int fib(int n);
int additiveSequence(int n, int t0, int t1);
void HailstoneSequence(int n);
void LeibnizSeries();
void rectangleCircle(int r);

#endif