/*
 * File: Statistic.cpp
 * ---------------------------------------
 * This implements usefuls function to calculate common statistical measure.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include "statistic.h"
using namespace std;

/*
 * Function: fact
 * Usage: int result = fact(n)
 * ---------------------------------------
 * Calculate factorial - the product of all integers between 1 and n
 */

int fact(int n)
{
    // int result = 1;
    // for (int i = n; i > 1; i--)
    //      result *= i;
    // return result;

    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

/*
 * Function: combinations
 * Usage: int nWays = combinations(n, k)
 * ---------------------------------------
 * Returns the mathematical combinations function C(n,k), which is the number
 * of ways one can choose k elements from a set of size n
 * 1. Take the advantage of factorial function to calculate
 * 2. Use Pascal's Triangle:
 *                     c(0, 0)                                 1
 *                 c(1, 0)  c(1, 1)                          1   1
 *             c(2, 0)  c(2, 1)  c(2, 2)                   1   2   1
 *         c(3, 0)  c(3, 1)  c(3, 2)  c(3, 3)            1   3   3   1
 *     c(4, 0)  c(4, 1)  c(4, 2)  c(4, 3)  c(4, 4)     1   4   6   4   1
 * Caculate the results based on value along the diagonal:
 *      c(n, k) = c(n - 1, k - 1) x n/k
 *      c(n, 0) = 1
 */

int combinations(int n, int k)
{
    // return fact(n) / (fact(k) * fact(n - k));
    int mid = n / 2;
    if (k > mid)
        return internalComb(n, n - k);
    else
        return internalComb(n, k);
}

int internalComb(int n, int k)
{
    if (k < 1)
        return 1;
    return double(n) / double(k) * internalComb(n - 1, k - 1);
}

/*
 * Function: permutations
 * Usage: int nWays = permutations(n, k)
 * ---------------------------------------
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
 * Function: permute
 * Usage: permute("", "abcd");
 * ---------------------------------------
 * Solving anagram problems, ex, permute the result of word "abcd" will
 * return 24 different results
 */

void permute(string str) { permute1("", str); }
void permute1(string soFar, string rest)
{
    if (rest == "")
    {
        cout << soFar << endl;
        return;
    }
    for (int i = 0; i < rest.length(); i++)
    {
        string remaining = rest.substr(0, i) + rest.substr(i + 1);
        permute1(soFar + rest[i], remaining);
    }
}

void permute2(string str, int lhp, int rhp)
{
    if (lhp == rhp)
        cout << str << endl;
    else
    {
        for (int i = lhp; i <= rhp; i++)
        {
            swap(str[lhp], str[i]);      // swapping
            permute2(str, lhp + 1, rhp); // recursion call
            swap(str[lhp], str[i]);      // backtracking
        }
    }
}

/*
 * Functions: listSubsets
 * ---------------------------------------
 * Find all possible subsets of S. Ex subset of ABC will have 8 cases:
 * {ABC}, {A}, {B}, {C}, {AB}, {AC}, {BC}, {}, we can choose A or not, B or not,
 * C or not, finally have 2^N choices. Same problem solving for string bits and
 * flip coins
 */

void listSubsets(string input, string soFar)
{
    if (input == "")
        cout << soFar << endl;
    else
    {
        char consider = input[0];
        listSubsets(input.substr(1), soFar);            // explore without
        listSubsets(input.substr(1), soFar + consider); // explore with
    }
}

double sum(vector<double> &data)
{
    double sum = 0;
    for (vector<double>::iterator i = data.begin(); i != data.end(); ++i)
        sum += *i;
    return sum;
}

double mean(vector<double> &data) { return sum(data) / data.size(); }

double var(vector<double> &data)
{
    double sum = 0;
    double avg = mean(data);
    for (vector<double>::iterator i = data.begin(); i != data.end(); ++i)
        sum = sum + pow(avg - *i, 2);
    return sum / data.size();
}

double stddev(vector<double> &data) { return sqrt(var(data)); }

void histogram(vector<double> &data, int divisor)
{
    int start = floor(minVec(data)) - 1;
    int end = ceil(maxVec(data)) + 1;
    double range = (end - start) / divisor;
    map<double, string> histRecord;
    sort(data.begin(), data.end());
    int j = 0;
    for (double i = start; i < end; i = i + range)
    {
        histRecord[i] = "";
        while (true)
        {
            if (data[j] >= i && data[j] < i + range)
            {
                histRecord[i] += "*";
                j += 1;
            }
            else
                break;
        }
        cout << "from " << i << ": " << histRecord[i] << endl;
    }
}

double minVec(vector<double> &data)
{
    double minValue = numeric_limits<int>::max();
    for (vector<double>::iterator i = data.begin(); i != data.end(); ++i)
        if (*i < minValue)
            minValue = *i;
    return minValue;
}

double maxVec(vector<double> &data)
{
    double maxValue = numeric_limits<int>::min();
    for (vector<double>::iterator i = data.begin(); i != data.end(); ++i)
        if (*i > maxValue)
            maxValue = *i;
    return maxValue;
}

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = a;
}