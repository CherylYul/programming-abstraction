/*
 * File: queueLinkedList.h
 * ---------------------------------------
 * This interface exports a template version of the queue class
 * (linked list-based stack)
 */

#ifndef _queueLinkedList_h
#define _queueLinkedList_h

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
    struct Cell
    {
        ValueType data;
        Cell *link;
    };
    Cell *head; /* Pointer to Cell at the head */
    Cell *tail; /* Pointer to Cell at the tail */
    int count;
    void deepCopy(const Queue<ValueType> &src);
};

#endif