/*
 * File: queueArray.h
 * ---------------------------------------
 * This interface exports a template version of Queue class
 * (array-based version)
 */

#ifndef _queueArray_h
#define _queueArray_h

template <typename ValueType>
class Queue
{
public:
    Queue();
    ~Queue();
    int size() const;
    bool isEmpty() const;
    void clear();
    void enqueue(ValueType value);
    void dequeue();
    ValueType peek() const;
    Queue(const Queue<ValueType> &src);
    Queue<ValueType> &operator=(const Queue<ValueType> &src);

private:
    static const int INITIAL_CAPACITY = 10;
    ValueType *array;
    int capacity;
    int head;
    int tail;
    void deepCopy(const Queue<ValueType> &src);
    void expandCapacity();
};

#endif