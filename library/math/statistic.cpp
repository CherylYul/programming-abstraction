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