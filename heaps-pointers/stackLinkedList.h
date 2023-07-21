/*
 * File: stackLinkedList.h
 * ---------------------------------------
 * This interface exports a template version of the stack class
 * (linked list-based stack)
 *  |   list  |---> | e2 |      ,---->| e1 |
 *  |count = 2|     |  --|------'     |NULL|
 */

#ifndef _stackLinkedList_h
#include _stackLinkedList_h

template <typename ValueType>
class Stack
{
public:
    Stack();
    ~Stack();
    int size() const;
    bool isEmpty() const;
    void clear();
    void push(ValueType value);
    ValueType pop();
    ValueType peek() const;
    Stack(const Stack<ValueType> &src);
    Stack<ValueType> &operator=(const Stack<ValueType> &src);

private:
    struct Cell
    {
        ValueType data;
        Cell *link;
    };
    Cell *list;
    int count;
    void deepCopy(const Stack<ValueType> &src);
};

#endif