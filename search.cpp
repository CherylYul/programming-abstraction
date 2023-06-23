#include <iostream>
#include <vector>
using namespace std;

int linearSearch(int key, vector<int> &vec);
int binarySearch(int key, vector<int> &vec);
int binarySearch(int key, vector<int> &vec, int lhp, int rhp);

/*
 * Function: linearSearch
 * Usage: int pos = linearSearch(key, vec);
 * ---------------------------------------
 * Linear search goes through each element and finds the matching value
 * with the key and return its position, if not found return -1
 * ! Carefully, it may need more than half a day to run with 100000 inputs
 */

int linearSearch(int key, vector<int> &vec)
{
    int vecSize = vec.size();
    for (int i = 0; i < vecSize; i++)
        if (vec[i] == key)
            return i;
    return -1;
}

/*
 * Function: binarySearch
 * Usage: int pos = binarySearch(key, vec);
 *        int pos = binarySearch(key, vec, lhp, rhp);
 * ---------------------------------------
 * Binary search takes the advantage of sorted list and finds the matching
 * value by comparing the middle value, then eliminate the half size until
 * find out the exact key, if key not found return -1
 */

int binarySearch(int key, vector<int> &vec)
{
    int lh = 0;
    int rh = vec.size() - 1;
    int mid = vec.size() / 2;
    while (lh <= rh)
    {
        int mid = (lh + rh) / 2;
        if (vec[mid] == key)
            return mid;
        if (key < vec[mid])
            rh = mid - 1;
        else
            lh = mid + 1;
    }
    return -1;
}

int binarySearch(int key, vector<int> &vec, int lhp, int rhp)
{
    if (lhp > rhp)
        return -1;
    int mid = (lhp + rhp) / 2;
    if (key == vec[mid])
        return mid;
    if (key < vec[mid])
        return binarySearch(key, vec, lhp, mid - 1);
    else
        return binarySearch(key, vec, mid + 1, rhp);
}