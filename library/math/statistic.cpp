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
 * -----------------------------------------------
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
 * -----------------------------------------------
 * Returns the mathematical combinations function C(n,k), which is the number
 * of ways one can choose k elements from a set of size n
 */

int combinations(int n, int k)
{
    return fact(n) / (fact(k) * fact(n - k));
}

/*
 * Function: permutations
 * Usage: int nWays = permutations(n, k)
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
 * Function: permute
 * Usage: permute("", "abcd");
 * -----------------------------------------------
 * Solving anagram problems, ex, permute the result of word "abcd" will
 * return 24 different results
 */

void permute(string soFar, string rest)
{
    if (rest == "")
    {
        cout << soFar << endl;
        return;
    }
    for (int i = 0; i < rest.length(); i++)
    {
        string remaining = rest.substr(0, i) + rest.substr(i + 1);
        permute(soFar + rest[i], remaining);
    }
}

double mean(vector<double> &data)
{
    double sum = 0;
    for (vector<double>::iterator i = data.begin(); i != data.end(); ++i)
        sum += *i;
    return sum / data.size();
}

double var(vector<double> &data)
{
    double sum = 0;
    double avg = mean(data);
    for (vector<double>::iterator i = data.begin(); i != data.end(); ++i)
        sum = sum + pow(avg - *i, 2);
    return sum / data.size();
}

double stddev(vector<double> &data)
{
    return sqrt(var(data));
}

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