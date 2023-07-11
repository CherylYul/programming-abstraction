/*
 * File: charstack.h
 * ---------------------------------------
 * This interface defines the charstack class, which implements the
 * stack abstraction characters
 */

#ifndef _charstack_h
#define _charstack_h
#include <vector>

class CharStackVec
{
public:
    CharStackVec();
    ~CharStackVec();
    int size();
    bool isEmpty();
    void clear();
    void push(char ch);
    char pop();
    char peek();

private:
    static const int INITIAL_CAPACITY = 10;
    char *array;
    int capacity;
    int count;
    std::vector<char> elements;

    void expandCapacity();
};

class CharStack
{
public:
    CharStack();
    ~CharStack();
    int size() const;
    bool isEmpty() const;
    void clear();
    void push(char ch);
    char pop();
    char peek() const;

    /*
     * Copy constructor: CharStack
     * ---------------------------------------
     * Initializes the current object to be a deep copy of the specified source
     */
    CharStack(const CharStack &src);

    /*
     * Operator: =
     * Usage: dst = src;
     * ---------------------------------------
     * Assigns src to dst so that the 2 stacks are independent copies
     */
    CharStack &operator=(const CharStack &src);

private:
    static const int INITIAL_CAPACITY = 10;
    char *array;
    int capacity;
    int count;
    void deepCopy(const CharStack &src);
    void expandCapacity();
};

#endif