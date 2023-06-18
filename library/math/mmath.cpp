/*
 * File: mmath.cpp
 * -----------------------------------------------
 * Implement my useful math functions
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "mmath.h"
#include "../error/error.h"
#include "../error/error.cpp"
using namespace std;

/*
 * Function: addNInput
 * Usage: double result = addNInput(int n);
 * -----------------------------------------------
 * Return total value users input into the program
 */

double addNInput(int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double value;
        cout << "The " << i + 1 << " value is: ";
        cin >> value;
        result += value;
    }
    return result;
}

/*
 * Function: addToN
 * Usage: int total = addToN(int n);
 * -----------------------------------------------
 * Return total value the program from 1 to n
 */

int addToN(int n)
{
    int total = 0;
    for (int i = 0; i <= n; i++)
    {
        total += i;
    }
    return total;
}

/* Function: reverseNum
 * Usage: int num = reverseNum(int n);
 * -----------------------------------------------
 * Returns the reverse number of n
 */

int reverseNum(int n)
{
    int result = 0;
    while (n >= 1)
    {
        result = (result * 10) + (n % 10);
        n /= 10;
    }
    return result;
}

/*
 * Function: factorial
 * Usage: int result = fact(int n)
 * -----------------------------------------------
 * Returns the factorial of n, which is the product of all
 * the integers between 1 and n, inclusive
 */

int factorial(int n)
{
    int result = 1;
    for (int i = n; i > 1; i--)
    {
        result *= i;
    }
    return result;
}

/*
 * Function: gcd
 * Usage: int result = gcd(int x, int y)
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
    int r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

/*
 * Function: combinations(n,k)
 * Usage: int nWays = combinations(int n, int k)
 * -----------------------------------------------
 * Returns the mathematical combinations function C(n,k),
 * which is the number of ways one can choose k elements
 * from a set of size n
 */

int combinations(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

/*
 * Function: permutations(n,k)
 * Usage: int nWays = permutations(int n, int k)
 * -----------------------------------------------
 * Returns number of ways a particular set can be arranged
 */

int permutations(int n, int k)
{
    int result = 1;
    for (int i = n; k > 0; i--)
    {
        result *= i;
        k -= 1;
    }
    return result;
}

/*
 * Function: square(n)
 * Usage: int result = square(int num);
 * -----------------------------------------------
 * Returns the square of x
 */

int square(int x)
{
    return x * x;
}

/*
 * Function: power
 * Usage: int p = power(int n, int k);
 * -----------------------------------------------
 * Returns the integer n raised to the kth power
 */

int power(int n, int k)
{
    int result = 1;
    for (int i = 0; i < k; i++)
    {
        result *= n;
    }
    return result;
}

/*
 * File: roundToNearestInt
 * Usage: int result = roundToNearestInt(n);
 * -----------------------------------------------
 * Returns n to the nearest integer
 */

int roundToNearestInt(double n)
{
    return int(n + 0.5);
}

/*
 * File: roundTo2
 * Usage: double result = roundTo2(double n);
 * -----------------------------------------------
 * Returns n to the floating number that only has 2 decimals
 */

double roundTo2(double n)
{
    return ceil(n * 100) / 100;
}

/*
 * File: sqrt
 * Usage: double result = sqrt(double n);
 * -----------------------------------------------
 * Implements sqrt function without using the library version
 * by using successive approximation
 */

double sqrt(double n)
{
    double g = roundTo2(n / 2);
    double dividedResult = roundTo2(n / g);
    while (g != dividedResult)
    {
        g = roundTo2((g + dividedResult) / 2);
        dividedResult = roundTo2(n / g);
    }
    return g;
}

/*
 * Function: isPerfect
 * Usage: isPerfect(int n);
 * -----------------------------------------------
 * Return true if n is a perfect number. Perfect number is the one
 * that equals to the sum of their proper divisors, ex: 6 and 28
 */

bool isPerfect(int n)
{
    int squareRoot = int(sqrt(n)) + 1;
    int result = 1;
    for (int i = 2; i < squareRoot; i++)
    {
        if (n % i == 0)
            result = result + n / i + i;
    }
    return result == n;
}

/*
 * Function: isEven
 * Usage: isEven(int n);
 * -----------------------------------------------
 * Returns true if n is even, if odd returns false
 */

bool isEven(int n)
{
    return n % 2 == 0;
}

/*
 * Function: isPrime
 * Usage: isPrime(int n);
 * -----------------------------------------------
 * Returns true if n is prime, if not returns false
 */

bool isPrime(int n)
{
    int squareRoot = int(sqrt(n)) + 1;
    bool count = true;
    for (int i = 2; i < squareRoot; i++)
    {
        if (n % i == 0)
        {
            count = !count;
            break;
        }
    }
    return count;
}

/*
 * Function: primeFactorization
 * Usage: primeFactorization(int n);
 * -----------------------------------------------
 * Factors the n
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
        {
            start += 1;
        }
    }
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