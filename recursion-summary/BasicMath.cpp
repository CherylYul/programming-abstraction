/*
 * This file is a summary of basic recursion problems:
 * 1. Raise to power
 * 2. Greatest common divisor (GCD)
 * 3. Fibonacci and additive sequence
 * 4. Digit sum and digital root
 * 5. Pascal triangles
 */

#include <iostream>
using namespace std;

int raiseToPower(int n, int k);
int GCD(int x, int y);
int additiveSeq(int n, int t0, int t1);
int fibSeq(int n);
int digitSum(int n);
int digitSum(int n, int div);
int digitalRoot(int n);
int combinations(int n, int k);
int internalComb(int n, int k);
void swap(int &x, int &y);

int main()
{
    // Testing...
    cout << raiseToPower(2, 5) << endl;
    cout << GCD(180, 24) << endl;
    cout << additiveSeq(8, 7, 10) << endl;
    cout << fibSeq(12) << endl;
    cout << digitSum(1729) << endl;
    cout << digitalRoot(1729) << endl;
    cout << combinations(6, 2) << endl;
    return 0;
}

// RAISE TO POWER
int raiseToPower(int n, int k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    return n * raiseToPower(n, k - 1);
}

// GCD
int GCD(int x, int y)
{
    if (y > x)
        swap(x, y);
    if (x % y == 0)
        return y;
    return GCD(y, x % y);
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// FIB & ADDITIVE SEQUENCE
int additiveSeq(int n, int t0, int t1)
{
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;
    return additiveSeq(n - 1, t1, t0 + t1);
}

int fibSeq(int n) { return additiveSeq(n, 0, 1); }

// DIGIT SUM & DIGITAL ROOT
int digitSum(int n) { return digitSum(n, 1); }
int digitSum(int n, int div)
{
    if (n < div)
        return 0;
    return (n / div) % 10 + digitSum(n, div * 10);
}

int digitalRoot(int n)
{
    if (n < 10)
        return n;
    return digitalRoot(digitSum(n));
}

// PASCAL TRIANGLES
int combinations(int n, int k)
{
    int mid = n / 2;
    if (k > mid)
        return internalComb(n, n - k);
    return internalComb(n, k);
}

int internalComb(int n, int k)
{
    if (k < 1)
        return 1;
    return double(n) / double(k) * internalComb(n - 1, k - 1);
}