/*
 * File: charstack.cpp
 * ---------------------------------------
 * This file implements the CharStack class using a vector<char> as the
 * underlying representation
 */

#include "charstack.h"
#include <iostream>
using namespace std;

CharStackVec::CharStackVec() {}
CharStackVec::~CharStackVec() {}
int CharStackVec::size() { return elements.size(); }
bool CharStackVec::isEmpty() { return elements.empty(); }
void CharStackVec::clear() { return elements.clear(); }
void CharStackVec::push(char ch) { elements.push_back(ch); }

char CharStackVec::pop()
{
    if (isEmpty())
        cout << "Attempting to pop an empty stack" << endl;
    char result = elements[elements.size() - 1];
    elements.pop_back();
    return result;
}

char CharStackVec::peek()
{
    if (isEmpty())
        cout << "Attempting to peek at an empty stack" << endl;
    return elements[elements.size() - 1];
}

CharStack::CharStack()
{
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}

CharStack::~CharStack() { delete[] array; }
int CharStack::size() const { return count; }
bool CharStack::isEmpty() const { return count == 0; }
void CharStack::clear() { count = 0; }

void CharStack::push(char ch)
{
    if (count == capacity)
        expandCapacity();
    array[count++] = ch;
}

char CharStack::pop()
{
    if (isEmpty())
        cout << "Attempting to pop an empty stack" << endl;
    return array[--count];
}

char CharStack::peek() const
{
    if (isEmpty())
        cout << "Attempting to peek at an empty stack" << endl;
    return array[count - 1];
}

// double the capacity of elements array whenever it runs out of space
void CharStack::expandCapacity()
{
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < count; i++)
        array[i] = oldArray[i];
    delete[] oldArray;
}

CharStack::CharStack(const CharStack &src) { deepCopy(src); }
CharStack &CharStack::operator=(const CharStack &src)
{
    if (this != &src)
    {
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object. All dynamic
 * memory is reallocated to create a "deep copy" in which the current object
 * and the source object are independent.
 */

void CharStack::deepCopy(const CharStack &src)
{
    array = new char[src.count];
    for (int i = 0; i < src.count; i++)
        array[i] = src.array[i];
    count = src.count;
    capacity = src.capacity;
}