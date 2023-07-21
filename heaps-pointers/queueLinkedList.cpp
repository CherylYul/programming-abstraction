#include <iostream>
#include "queueLinkedList.h"
using namespace std;

template <typename ValueType>
Queue<ValueType>::Queue()
{
    head = tail = NULL;
    count = 0;
}

template <typename ValueType>
Queue<ValueType>::~Queue() { clear(); }

/*
 * while (_front != NULL) {
 *    Node *temp = _front;
 *    _front = _front->link;
 *    delete temp;
 * }
 */

template <typename ValueType>
int Queue<ValueType>::size() const { return count; }

template <typename ValueType>
bool Queue<ValueType>::isEmpty() const { return count == 0; }

template <typename ValueType>
void Queue<ValueType>::clear()
{
    while (count > 0)
        dequeue();
}

template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value)
{
    Cell *cp = new Cell;
    cp->data = value;
    cp->link = NULL;
    if (head == NULL) // enqueue an empty queue
        head = cp;
    else
        tail->link = cp;
    tail = cp;
    count++;
}

template <typename ValueType>
void Queue<ValueType>::dequeue()
{
    if (isEmpty())
        cout << "dequeue: Attempting to dequeue an empty queue" << endl;
    Cell *cp = head;
    ValueType result = cp->data;
    head = cp->link;
    if (head == NULL)
        tail = NULL;
    delete cp;
    count--;
    return result;
}

template <typename ValueType>
ValueType Queue<ValueType>::peek() const
{
    if (isEmpty())
        cout << "peek: Attempting to peek an empty queue" << endl;
    return head->data;
}

template <typename ValueType>
Queue<ValueType>::Queue(const Queue<ValueType> &src) { deepCopy(src); }

template <typename ValueType>
Queue<ValueType> &Queue<ValueType>::operator=(const Queue<ValueType> &src)
{
    if (this != &src)
    {
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void deepCopy(const Queue<ValueType> &src)
{
    head = NULL;
    tail = NULL;
    count = 0;
    for (Cell *cp = src.head; cp != NULL; cp = cp->link)
        enqueue(cp->data);
}