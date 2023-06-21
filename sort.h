/*
 * sort.h
 * ---------------------------------------
 * This interface exports list of sort algorithm
 */

#ifndef _sort_h
#define _sort_h
#include <string>

void insertionSort(std::vector<int> &vec);
void selectionSort(std::vector<int> &vec);
void swap(int &valueOne, int &valueTwo);
void mergeSort(std::vector<int> &vec);
void merge(std::vector<int> &vec, std::vector<int> &v1, std::vector<int> &v2);
void quickSort(std::vector<int> &vec);
void quickSort(std::vector<int> &vec, int start, int finish);
int partition(std::vector<int> &vec, int start, int finish);
void countingSort(std::vector<int> &vec);
void radixSort(std::vector<int> &vec, int digit);
void countingSortOnDigit(std::vector<int> &vec, int digit);

#endif