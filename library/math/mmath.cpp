/*
 * File: mmath.cpp
 * -----------------------------------------------
 * Implement my useful math functions
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdlib>
#include "mmath.h"
#include "../error/error.h"
#include "../error/error.cpp"
using namespace std;

/* Function: reverseN
 * Usage: int num = reverseN(int n);
 * -----------------------------------------------
 * Returns the reverseN number of n
 */

int reverseN(int n)
{
    int div = 1;
    vector<int> digits;
    while (n > div)
    {
        digits.push_back((n / div) % 10);
        div *= 10;
    }
    int reverseNum = 0;
    for (int i : digits)
    {
        div /= 10;
        reverseNum = reverseNum + (i * div);
    }
    return reverseNum;
}

/*
 * Function: squareN
 * Usage: int result = squareN(int num);
 * -----------------------------------------------
 * Returns the squareN of x
 */

int squareN(int x) { return x * x; }

/*
 * Function: sqrtN
 * Usage: double result = sqrtN(double n);
 * -----------------------------------------------
 * Implements sqrt function without using the library version
 * by using successive approximation
 */

double sqrtN(double n)
{
    double g = roundToDecimals(n / 2, 2);
    double dividedResult = roundToDecimals(n / g, 2);
    while (g != dividedResult)
    {
        g = roundToDecimals((g + dividedResult) / 2, 2);
        dividedResult = roundToDecimals(n / g, 2);
    }
    return g;
}

/*
 * Function: powerN
 * Usage: int p = powerN(int n, int k);
 * -----------------------------------------------
 * Returns the integer n raised to the kth power
 */

int powerN(int n, int k)
{
    // if (k == 1)
    //     return n;
    // int mid = k / 2;
    // return powerN(n, mid) * powerN(n, k - mid);

    // int result = 1;
    // for (int i = 0; i < k; i++)
    //     result *= n;
    // return result;

    if (k == 0)
        return 1;
    return n * powerN(n, k - 1);
}

/*
 * Function: roundN
 * Usage: int result = roundN(n);
 * -----------------------------------------------
 * Returns n to the nearest integer
 */

int roundN(double n) { return int(n + 0.5); }

/*
 * Function: roundToDecimals
 * Usage: double result = roundToDecimals(n, d);
 * -----------------------------------------------
 * Returns n to the floating number that has d decimals
 */

double roundToDecimals(double n, int d) { return roundN(n * powerN(10, d)) / powerN(10, d); }

/*
 * Function: gcd
 * Usage: int result = gcd(x, y)
 * -----------------------------------------------
 * Uses Euclid's algorithm to calculate the greatest common divisor.
 * Ex: the gcd of 35 and 49 is 7. GCD includes 3 steps:
 *
 * 1. Divide x by y and compute the remainder r
 * 2. If r = 0, the algorithm is complete, and the answer is y
 * 3. If not, set x to the old value of y, set y = r, repeat the process.
 */

int gcd(int x, int y)
{
    if (y == 0 || x == 0)
        error("The 2 integers must be greater than 0!");
    // int r = x % y;
    // while (r != 0)
    // {
    //     x = y;
    //     y = r;
    //     r = x % y;
    // }
    // return y;
    if (x < y)
        swap(x, y);
    if (x % y == 0)
        return y;
    return gcd(y, x % y);
}

/*
 * Function: digitSum
 * Usage: int result = digitSum(n);
 * -----------------------------------------------
 * Sum the digit of values, ex: 1729 = 1+7+2+9 = 19
 */

int digitSum(int n) { return internalDigitSum(n, 1); }
int internalDigitSum(int n, int div)
{
    if (n < div)
        return 0;
    return (n / div) % 10 + internalDigitSum(n, div * 10);
}

/*
 * Function: digitalRoot
 * Usage: int result = digitalRoot(n);
 * -----------------------------------------------
 * Digital root is the result of summing the digits repeatedly until
 * only a single digit remains
 * Ex: 1729 = 1 + 7 + 2 + 9 = 19 = 1 + 9 = 10 = 1 + 0 = 1
 */

int digitalRoot(int n)
{
    if (n < 10)
        return n;
    return digitalRoot(digitSum(n));
}

/*
 * Function: isEven, isOdd
 * Usage: isEven(n); isOdd(n);
 * -----------------------------------------------
 * isEven returns true if n is even else returns false, isOdd vice versa.
 * A number is even when either it is 0 or its predecessor is odd.
 */

bool isEven(unsigned int n)
{
    if (n == 0)
        return true;
    return isOdd(n - 1);
    // return n % 2 == 0;
}

bool isOdd(unsigned int n)
{
    return !isEven(n);
    // return n % 2 == 1;
}

/*
 * Function: isPerfect
 * Usage: isPerfect(n);
 * -----------------------------------------------
 * Return true if n is a perfect number. Perfect number is the one that
 * equals to the sum of their proper divisors, ex: 6 and 28
 */

bool isPerfect(int n)
{
    int squareRoot = int(sqrt(n)) + 1;
    int result = 1;
    for (int i = 2; i < squareRoot; i++)
        if (n % i == 0)
            result = result + n / i + i;
    return result == n;
}

/*
 * Function: isPrime
 * Usage: isPrime(n);
 * -----------------------------------------------
 * Returns true if n is prime, if not returns false
 */

bool isPrime(int n)
{
    int squareRoot = int(sqrt(n)) + 1;
    bool count = true;
    for (int i = 2; i < squareRoot; i++)
        if (n % i == 0)
        {
            count = !count;
            break;
        }
    return count;
}

/*
 * Function: primeFactorization
 * Usage: primeFactorization(n);
 */

void primeFactorization(int n)
{
    int start = 2;
    while (n != 1)
    {
        if (n % start == 0)
        {
            cout << start;
            n /= start;
            if (n != 1)
                cout << " x ";
        }
        else
            start += 1;
    }
}

/*
 * Function: sievePrime
 * Usage: sievePrime(n);
 * -----------------------------------------------
 * Sieve of Eratosthenes is the algorithm that finds out the prime number
 * by circle the first number in range from 2 to N, then cross off every
 * multiple of 2, continue to circle next element which wasn't been crossed
 * and repeat the process
 */

void sievePrime(int n)
{
    map<int, bool> numList;
    numList[0] = false;
    numList[1] = false;
    for (int i = 2; i < n; i++)
        numList[i] = true;
    for (int p = 2; p <= sqrt(n); p++)
        if (numList[p])
            for (int i = p * p; i <= n; i += p)
                numList[i] = false;
    for (int i = 2; i < n; i++)
        if (numList[i])
            cout << i << endl;
}

/*
 * Function: solveQuadratic
 * Usage: solveQuadratic(a, b, c, x1, x2);
 * ------------------------------------------------------
 * Solve a quadratic equation for the coefficients a,b and c
 * The roots are returned in the reference parameters x1 and x2
 */

void solveQuadratic(double a, double b, double c, double &x1, double &x2)
{
    if (a == 0)
        error("The coefficient a must be nonzero.");
    double disc = b * b - 4 * a * c;
    if (disc < 0)
        error("This equation has no real roots.");
    double sqrtDisc = sqrt(disc);
    x1 = (-b + sqrtDisc) / (2 * a);
    x2 = (-b - sqrtDisc) / (2 * a);
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}