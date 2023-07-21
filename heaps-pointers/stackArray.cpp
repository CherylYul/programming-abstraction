#include <iostream>
#include "stackArray.h"
using namespace std;

template <typename ValueType>
Stack<ValueType>::Stack()
{
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    count = 0;
}

template <typename ValueType>
Stack<ValueType>::~Stack() { delete[] array; }

template <typename ValueType>
int Stack<ValueType>::size() const { return count; }

template <typename ValueType>
bool Stack<ValueType>::isEmpty() const { return count == 0; }

template <typename ValueType>
void Stack<ValueType>::clear() { count = 0; }

template <typename ValueType>
void Stack<ValueType>::push(ValueType value)
{
    if (count == capacity)
        expandCapacity();
    array[count++] = value;
}

template <typename ValueType>
ValueType Stack<ValueType>::pop()
{
    if (isEmpty())
        cout << "pop: Attempting to pop an empty stack" << endl;
    return array[--count];
}

template <typename ValueType>
ValueType Stack<ValueType>::peek() const
{
    if (isEmpty())
        cout << "peek: Attempting to peek an empty stack" << endl;
    return array[count - 1];
}

template <typename ValueType>
Stack<ValueType>::Stack(const Stack<ValueType> &src) { deepCopy(src); }

template <typename ValueType>
Stack<ValueType> &Stack<ValueType>::operator=(const Stack<ValueType> &src)
{
    if (this != &src)
    {
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void Stack<ValueType>::deepCopy(const Stack<ValueType> &src)
{
    capacity = src.count + INITIAL_CAPACITY;
    this->array = new ValueType[capacity];
    for (int i = 0; i < src.count; i++)
        array[i] = src.array[i];
    count = src.count;
}

template <typename ValueType>
void Stack<ValueType>::expandCapacity()
{
    ValueType *oldArray = array;
    capacity *= 2;
    array = new ValueType[capacity];
    for (int i = 0; i < count; i++)
        array[i] = oldArray[i];
    delete[] oldArray;
}