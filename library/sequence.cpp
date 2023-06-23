/*
 * File: sequence.cpp
 * -----------------------------------------------
 * Implement my special sequence: sequence.h
 */

#include <iostream>
#include <cmath>
using namespace std;

int const SIMULATION = 10000;

/*
 * Function: triangularNumbers
 * Usage: int total = triangularNumbers(n);
 * -----------------------------------------------
 * The nth triangular number is the number of dots in the triangular arrangement
 * with n dots, equal to the sum of the n natural numbers from 1 to n
 *      formula: n(n+1) / 2
 *      pic: n=4    o
 *                 o o
 *                o o o
 *               o o o o
 */

int triangularNumbers(int n)
{
    int total = 0;
    for (int i = 0; i <= n; i++)
        total += i;
    return total;
}

/*
 * Function: fib
 * Usage: int f = fib(n);
 * -----------------------------------------------
 * Returns nth term in the Fibonacci sequence using recursion:
 * fib(0) = 0; fib(1) = 1; fib(n) = fib(n-1) + fib(n-2)
 */

int fib(int n)
{
    return additiveSequence(n, 0, 1);
}

/*
 * Function: additiveSequence
 * Usage: int seq = additiveSequence(n, t0, t1);
 * -----------------------------------------------
 * Fibonacci generate same values at each position, additive sequence allows us
 * to change the first 2 values of sequence.
 * Ex: 7, 10, 17, 27, 44, 71, 155, 186, 301
 */

int additiveSequence(int n, int t0, int t1)
{
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;
    return additiveSequence(n - 1, t1, t0 + t1);
}

/*
 * Function: hailstoneSequence
 * Usage: hailstoneSequence(int n)
 * -----------------------------------------------
 * This program read in an interger, then repeatedly executing the hailstone
 * sequence rules until it reachs 1:
 * 1. If n = 1, stop program
 * 2. If n is even, divide by 2
 * 3. If n is odd, multiply by 3 and add 1
 */

void HailstoneSequence(int n)
{
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            cout << n << " is even, so I divide it by 2 to get ";
            n /= 2;
            cout << n << endl;
        }
        else
        {
            cout << n << " is odd, so I multiply by 3 and add 1 to get ";
            n = n * 3 + 1;
            cout << n << endl;
        }
    }
}

/*
 * Function: LeibnizSeries
 * Usage: LeibnizSeries();
 * -----------------------------------------------
 * Calculate approximate π according to Leibniz rules:
 *      1 - 1/3 + 1/5 - 1/7 + 1/9 ... = π/4
 */

void LeibnizSeries()
{
    double start = 1;
    double result = 0;
    cout << "This program calculate π according to Leibniz's series." << endl;
    cout << "Calculates an approximation of π consisting of the first 10,000 terms." << endl;
    for (int i = 0; i < SIMULATION; i++)
    {
        if (i % 2 == 1)
            result = result - (1 / start);
        else
            result = result + (1 / start);
        start += 2;
    }
    cout << "π is " << result << endl;
}

/*
 * Function: rectangleCircle
 * Usage: rectangleCircle(r);
 * -----------------------------------------------
 * Computes the area of the quarter circle by dividing it into 10,000 rectangles
 * with the given radius
 */

void rectangleCircle(int r)
{
    double area = 0;
    double w = r / SIMULATION;
    for (int i = 0; i < SIMULATION; i++)
    {
        int k = i + 1;
        double h = sqrt(r * r - (k * w) * (k * w));
        area = area + h * w;
    }
    cout << "The area of the quarter circle is " << area << endl;
}