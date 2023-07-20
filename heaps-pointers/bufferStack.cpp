#include <cctype>
#include <iostream>
#include "bufferStack.h"
using namespace std;

/*
 * All dynamic allocation is managed by the CharStack class, which
 * means there is no work for EditorBuffer to do.
 */

EditorBuffer::EditorBuffer() {}
EditorBuffer::~EditorBuffer() {}

void EditorBuffer::moveCursorForward() // O(1)
{
    if (!after.isEmpty())
        before.push(after.pop());
}

void EditorBuffer::moveCursorBackward() // O(1)
{
    if (!before.isEmpty())
        after.push(before.pop());
}

void EditorBuffer::moveCursorToStart() // O(N)
{
    while (!before.isEmpty())
        after.push(before.pop());
}

void EditorBuffer::moveCursorToEnd() // O(N)
{
    while (!after.isEmpty())
        before.push(after.pop());
}

void EditorBuffer::insertCharacter(char ch) { before.push(ch); } // O(1)
void EditorBuffer::deleteCharacter()                             // O(1)
{
    if (!after.isEmpty())
        after.pop();
}

string EditorBuffer::getText() const
{
    CharStack beforeCopy = before;
    CharStack afterCopy = after;
    string str = " ";
    while (!beforeCopy.isEmpty())
        str = beforeCopy.pop() + str;
    while (!afterCopy.isEmpty())
        str += afterCopy.pop();
    return str;
}

int EditorBuffer::getCursor() const { return before.size(); }
