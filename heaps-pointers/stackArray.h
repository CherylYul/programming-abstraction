/*
 * File: stackArray.h
 * ---------------------------------------
 * This interface exports a template version of the stack class
 * (array-based stack)
 */

#ifndef _stackArray_h
#define _stackArray_h

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
    static const int INITIAL_CAPACITY = 10;
    ValueType *array;
    int capacity; /* allocated size of array */
    int count;    /* number of elements */
    void deepCopy(const Stack<ValueType> &src);
    void expandCapacity();
};

#endif