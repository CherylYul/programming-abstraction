/*
 * File: DickenMeasure
 * ---------------------------------------
 * Merchants measured commodities by using weights and a two-pan balance.
 * This program writes a recursive function, that determines whether it is
 * possible to measure out the desired target amount with a given set of
 * weights
 * Ex: Given 1 and 3 ounce weight, we can measure objects with 1, 2, 3, 4
 * ounces
 *          objects                        \1/ \3/
 *           -----------------∆-----------------
 */

#include <iostream>
#include <vector>
using namespace std;

bool isMeasurable(int target, vector<int> &weights);

int main()
{
    vector<int> v = {1, 3};
    cout << isMeasurable(2, v) << endl;
    return 0;
}

bool isMeasurable(int target, vector<int> &weights)
{
    if (weights.empty())
        return target == 0;
    int value = weights.back();
    weights.pop_back();
    return isMeasurable(target - value, weights) ||
           isMeasurable(target, weights) || isMeasurable(target + value, weights);
}