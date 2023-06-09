#include <iostream>
#include <vector>
#include <cmath>
#include "sort.h"
#include "library/collection/vector.h"
#include "library/collection/vector.cpp"
using namespace std;

/*
 * Function: insertionSort
 * ---------------------------------------
 * Insertion sort goes through each element and finds the right position
 * by comparing the previous element until reaching the smaller one then
 * insert in front of that value.
 */

void insertionSort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int pos = i - 1;
        int currentElement = vec[i];
        while (pos >= 0 && currentElement < vec[pos])
        {
            vec[pos + 1] = vec[pos];
            pos--;
        }
        vec[pos + 1] = currentElement;
    }
}

/*
 * Function: selectionSort
 * ---------------------------------------
 * Selection sort goes through each element position and finds the value
 * that should occupy that position in the sorted vector. When it finds
 * the appropriate element, the algorithm exchanges it with the occupied
 * value
 */

void selectionSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int currentSmallestPos = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[currentSmallestPos])
                currentSmallestPos = j;
        }
        swap(vec[i], vec[currentSmallestPos]);
    }
}

void swap(int &valueOne, int &valueTwo)
{
    int temp = valueOne;
    valueOne = valueTwo;
    valueTwo = temp;
}

/*
 * Function: mergeSort
 * ---------------------------------------
 * Merge sort take the advantage of divide-and-conquer strategy:
 * 1. Base case: check if vector is empty or has 1 element, return it
 * 2. Divide into 2 halves, sort each of it recursively
 * 3. Merge 2 vectors back into the original one
 */

void mergeSort(vector<int> &vec)
{
    int vecSize = vec.size();
    if (vecSize <= 1)
        return;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < vecSize; i++)
        if (i < vecSize / 2)
            v1.push_back(vec[i]);
        else
            v2.push_back(vec[i]);
    mergeSort(v1);
    mergeSort(v2);
    vec.clear();
    merge(vec, v1, v2);
}

/*
 * Function: merge
 * ---------------------------------------
 * Merge merges 2 sorted vectors, v1 and v2, into the vector vec.
 * v1 and v2 are sorted, so only need to select the smaller element
 * of each vector into vec.
 */

void merge(vector<int> &vec, vector<int> &v1, vector<int> &v2)
{
    int v1Size = v1.size();
    int v2Size = v2.size();
    int v1Pos = 0;
    int v2Pos = 0;
    while (v1Pos < v1Size && v2Pos < v2Size)
        if (v1[v1Pos] < v2[v2Pos])
            vec.push_back(v1[v1Pos++]);
        else
            vec.push_back(v2[v2Pos++]);
    while (v1Pos < v1Size)
        vec.push_back(v1[v1Pos++]);
    while (v2Pos < v2Size)
        vec.push_back(v2[v2Pos++]);
}

/*
 * Function: quickSort
 * ---------------------------------------
 * 1. Choose a pivot as a boundary between small and large elements
 * 2. Partitioning by rearranging the elements in the vector so that
 * large elements towards the end and small elements towards the beginning
 * 3. Sort the elements in each of the partial vectors
 */

void quickSort(vector<int> &vec)
{
    quickSort(vec, 0, vec.size() - 1);
}

void quickSort(vector<int> &vec, int start, int finish)
{
    if (start >= finish)
        return;
    int boundary = partition(vec, start, finish);
    quickSort(vec, start, boundary - 1);
    quickSort(vec, boundary + 1, finish);
}

/*
 * Function: partition
 * ---------------------------------------
 * Partition rearranges the elements of the vector so that small elements
 * are grouped at the left, the large elements are grouped at the right by
 * comparing it with pivot value.
 */

int partition(vector<int> &vec, int start, int finish)
{
    int pivot = vec[start];
    int lhp = start + 1;
    int rhp = finish;
    while (true)
    {
        while (lhp < rhp && vec[rhp] >= pivot)
            rhp--;
        while (lhp < rhp && vec[lhp] < pivot)
            lhp++;
        if (lhp == rhp)
            break;
        swap(vec[lhp], vec[rhp]);
    }
    if (vec[lhp] >= pivot)
        return start;
    vec[start] = vec[lhp];
    vec[lhp] = pivot;
    return lhp;
}

/*
 * Function: countingSort
 * ---------------------------------------
 * This sort takes the advantage of knowing the integer range value,
 * ususally from 0 - 9, if larger we will corporate with radix sort,
 * so it can run in linear time.
 */

void countingSort(vector<int> &vec)
{
    if (vec.size() <= 1)
        return;
    vector<int> vecResult(vec.size());
    vector<int> countVal(10);
    for (int i : vec)
        countVal[i]++;
    for (int i = 1; i < 10; i++)
        countVal[i] += countVal[i - 1];
    for (int i : vec)
    {
        vecResult[countVal[i] - 1] = i;
        countVal[i]--;
    }
    vec = vecResult;
}

/*
 * Function: radixSort
 * ---------------------------------------
 * Radix sort is a linear sort that sorts elements by processing them
 * digit by digit, it wiil combine with counting sort on digit which can
 * sort with O(d(n+k)) times.
 */

void radixSort(vector<int> &vec, int digit)
{
    for (int d = 1; d < digit + 1; d++)
        countingSortOnDigit(vec, d);
}

void countingSortOnDigit(vector<int> &vec, int digit)
{
    if (vec.size() <= 1)
        return;
    int div = pow(10, digit - 1);
    vector<int> vecResult(vec.size());
    vector<int> countVal(10);
    for (int i : vec)
    {
        int d = (i / div) % 10;
        countVal[d]++;
    }
    for (int i = 1; i < countVal.size(); i++)
        countVal[i] += countVal[i - 1];
    for (int i = vec.size() - 1; i >= 0; i--)
    {
        int d = (vec[i] / div) % 10;
        vecResult[countVal[d] - 1] = vec[i];
        countVal[d]--;
    }
    vec = vecResult;
}
