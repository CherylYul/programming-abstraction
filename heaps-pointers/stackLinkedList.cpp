#include <iostream>
#include "stackLinkedList.h"
using namespace std;

template <typename ValueType>
Stack<ValueType>::Stack()
{
    list = NULL;
    count = 0;
}

template <typename ValueType>
Stack<ValueType>::~Stack() { clear(); }

template <typename ValueType>
int Stack<ValueType>::size() const { return count; }

template <typename ValueType>
bool Stack<ValueType>::isEmpty() const { return count == 0; }

template <typename ValueType>
void Stack<ValueType>::clear()
{
    while (count > 0)
        pop();
}

/*
 * while (list != NULL) {
 *    Cell *cp = list
 *    list = list->link;
 *    delete cp;
 * }
 */

template <typename ValueType>
void Stack<ValueType>::push(ValueType value)
{
    Cell *cp = new Cell;
    cp->data = value;
    cp->link = list;
    list = cp;
    count++;
}

template <typename ValueType>
ValueType Stack<ValueType>::pop()
{
    if (isEmpty())
        cout << "pop: Attempting to pop an empty stack" << endl;
    Cell *cp = list; // this is to avoid memory leak
    Valuetype result = cp->data;
    list = list->link;
    count--;
    delete cp; // this is to avoid memory leak
    return result;
}

template <typename ValueType>
ValueType Stack<ValueType>::peek() const
{
    if (isEmpty())
        cout << "pop: Attempting to pop an empty stack" << endl;
    return list->data;
}

template <typename ValueType>
Stack<ValueType>::Stack(const Stack<ValueType> &src) { deepCopy(src); }

template <typename ValueType>
Stack<ValueType> &Stack<ValueType>::operator=(const Stack<ValueType> &src)
{
    if (this != &src)
    {
        clear();
        deepCopy(src);
    }
    return *this;
}

template <typename ValueType>
void Stack<ValueType>::deepCopy(const Stack<ValueType> &src)
{
    count = src.count;
    Cell *tail = NULL;
    for (Cell *cp = src.list; cp != NULL; cp = cp->link)
    {
        Cell *ncp = new Cell;
        ncp->data = cp->data;
        if (tail == NULL)
            list = ncp;
        else
            tail->link = ncp;
        tail = ncp;
    }
    if (tail != NULL)
        tail->link = NULL;
}
