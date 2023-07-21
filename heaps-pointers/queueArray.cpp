#include <iostream>
#include "queueArray.h"
using namespace std;

template <typename ValueType>
Queue<ValueType>::Queue()
{
    capacity = INITIAL_CAPACITY;
    array = new ValueType[capacity];
    head = 0;
    tail = 0;
}

template <typename ValueType>
int Queue<ValueType>::size() const { return (tail + capacity - head) % capacity; }

template <typename ValueType>
bool Queue<ValueType>::isEmpty() const { return head == tail; }

template <typename ValueType>
void Queue<ValueType>::clear() { head = tail = 0; }

template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value)
{
    if (size() == capacity - 1)
        expandCapacity();
    array[tail] = value;
    tail = (tail + 1) % capacity;
}

template <typename ValueType>
void Queue<ValueType>::dequeue()
{
    if (isEmpty())
        cout << "dequeue: Attempting to dequeue an empty queue" << endl;
    ValueType result = array[head];
    head = (head + 1) % capacity;
    return result;
}

template <typename ValueType>
ValueType Queue<ValueType>::peek() const
{
    if (isEmpty())
        cout << "dequeue: Attempting to dequeue an empty queue" << endl;
    return array[head];
}

template <typename ValueType>
Queue<ValueType>::Queue(const Queue<ValueType> &src) { deepCopy(src); }

template <typename ValueType>
Queue<ValueType> &Queue<ValueType>::operator=(const Queue<ValueType> &src)
{
    if (this != &src)
    {
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void Queue<ValueType>::deepCopy(const Queue<ValueType> &src)
{
    int count = src.size();
    capacity = count + INITIAL_CAPACITY;
    array = new ValueType[capacity];
    for (int i = 0; i < count; i++)
        array[i] = src.array[(src.head + i) % src.capacity];
    head = 0;
    tail = count;
}

template <typename ValueType>
void Queue<ValueType>::expandCapacity()
{
    int count = size();
    ValueType *oldArray = array;
    array = new ValueType[2 * capacity];
    for (int i = 0; i < count; i++)
        array[i] oldArray[(head + i) % capacity];
    capacity *= 2;
    head = 0;
    tail = count;
    delete[] oldArray;
}