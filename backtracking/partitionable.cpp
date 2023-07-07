/*
 * Partitionable.cpp
 * ---------------------------------------
 * Takes a vector of ints and returns true if it is possible to divide
 * the ints into two groups such that each group has the same sum.
 * Ex: {1, 1, 2, 3, 5} : true because {1, 2, 3} = {1, 5}
 *     {1,4,5,6} : false because it can't split into 2
 */

#include <vector>
#include <iostream>
using namespace std;

struct vectorPair
{
    vector<int> v1;
    vector<int> v2;
};

bool partitionable(vector<int> &num);
bool partitionable(vector<int> &rest, int sum1, int sum2);
bool partitionable(vector<int> &rest, vector<int> &v1, vector<int> &v2);
void partitionable(vector<int> &rest, vector<int> &v1, vector<int> &v2, vector<vectorPair> &allSolutions);

int main()
{
    vector<int> vec = {1, 1, 2, 3, 5};
    cout << partitionable(vec) << endl;
    return 0;
}

bool partitionable(vector<int> &num) { return partitionable(num, 0, 0); }
bool partitionable(vector<int> &rest, int sum1, int sum2)
{
    if (rest.empty())
        return sum1 == sum2;
    else
    {
        int n = rest.back();
        rest.pop_back();
        bool answer = partitionable(rest, sum1 + n, sum2) || partitionable(rest, sum1, sum2 + n);
        rest.push_back(n);
        return answer;
    }
}

// actually find a correct partition

bool partitionable(vector<int> &rest, vector<int> &v1, vector<int> &v2)
{
    if (rest.size() == 0)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int val : v1)
            sum1 += val;
        for (int val : v2)
            sum2 += val;
        return sum1 == sum2;
    }
    else
    {
        int n = rest.back();
        rest.pop_back();

        v1.push_back(n);
        bool answer1 = partitionable(rest, v1, v2);
        if (answer1)
        {
            rest.push_back(n);
            return true;
        }
        v1.pop_back();

        v2.push_back(n);
        bool answer2 = partitionable(rest, v1, v2);
        rest.push_back(n);
        if (answer2)
            return true;
        v2.pop_back();
        return false;
    }
}

// keep track all solutions, need a vector of set solutions, no return early,
// we need to search until exhausted the search space
void partitionable(vector<int> &rest, vector<int> &v1, vector<int> &v2, vector<vectorPair> &allSolutions)
{
    if (rest.size() == 0)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int val : v1)
            sum1 += val;
        for (int val : v2)
            sum2 += val;
        if (sum1 == sum2)
        {
            vectorPair vp;
            vp.v1 = v1;
            vp.v2 = v2;
            allSolutions.push_back(vp);
        }
    }
    else
    {
        int n = rest.back();
        rest.pop_back();

        v1.push_back(n);
        partitionable(rest, v1, v2, allSolutions);
        v1.pop_back();

        v2.push_back(n);
        partitionable(rest, v1, v2, allSolutions);
        v2.pop_back();

        rest.push_back(n);
    }
}