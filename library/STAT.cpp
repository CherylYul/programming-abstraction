/*
 * Files: STAT.cpps
 * ---------------------------------------
 * This program takes list of input integers and is signal to stop by SENTINEL
 * value, then report an overview of data.
 */

#include <iostream>
#include <vector>
#include "math/statistic.h"
#include "math/statistic.cpp"
using namespace std;

const int SENTINEL = 0;

int main()
{
    cout << "Input value, use " << SENTINEL << " to signal end" << endl;
    vector<double> v;
    while (true)
    {
        int value;
        cout << ">> ";
        cin >> value;
        if (value == SENTINEL)
            break;
        v.push_back(value);
    }
    cout << "Total value: " << sum(v) << endl;
    cout << "Mean: " << mean(v) << endl;
    cout << "Highest value: " << maxVec(v) << endl;
    cout << "Lowest value: " << minVec(v) << endl;
    return 0;
}