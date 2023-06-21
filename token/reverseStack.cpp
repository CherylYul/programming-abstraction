/*
 * File: reverseStack.cpp
 * ---------------------------------------
 * Uses stack to reverse list input of integers
 */

#include <iostream>
#include <stack>
#include "../string/strlib.h"
#include "../string/strlib.cpp"
using namespace std;

const int SENTINEL = 0;

int main()
{
    stack<int> s;
    while (true)
    {
        cout << "? ";
        int value;
        cin >> value;
        if (value == SENTINEL)
            break;
        s.push(value);
    }
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}