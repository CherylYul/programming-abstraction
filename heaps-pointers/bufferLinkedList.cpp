#include <cctype>
#include <iostream>
#include "bufferLinkedList.h"
using namespace std;

/*
 * Constructor: EditorBuffer
 * ---------------------------------------
 * This function initializes an empty editor buffer represented as a linked list.
 * In this representation, the empty buffer contains a "dummy" cell whose ch field
 * is never used. The constructor must allocate this dummy cell and set the internal
 * pointers correctly.
 */

EditorBuffer::EditorBuffer()
{
    start = cursor = new Cell;
    start->link = NULL;
}

/*
 * Destructor: EditorBuffer
 * ---------------------------------------
 * Delete every cell in the buffer. This implementation copies the link pointer before
 * calling delete.
 */

EditorBuffer::~EditorBuffer()
{
    Cell *cp = start;
    while (cp != NULL)
    {
        Cell *next = cp->link;
        delete cp;
        cp = next;
    }
}

void EditorBuffer::moveCursorForward() // O(1)
{
    if (cursor->link != NULL)
        cursor = cursor->link;
}

void EditorBuffer::moveCursorBackward() // O(n)
{
    Cell *cp = start;
    if (cursor != start)
    {
        while (cp->link != cursor)
            cp = cp->link;
        cursor = cp;
    }
}

void EditorBuffer::moveCursorToStart() { cursor = start; } // O(1)

void EditorBuffer::moveCursorToEnd() // O(n)
{
    while (cursor->link != NULL)
        cursor = cursor->link;
}

/*
 * Insertion: insertCharacter
 * ---------------------------------------
 * 1. Allocate a new cell, and put the new character in it.
 * 2. Copy the pointer indicating the rest of the list into the link.
 * 3. Update the link in the current cell to point to the new one.
 * 4. Move the cursor forward over the inserted character.
 */

void EditorBuffer::insertCharacter(char ch)
{
    Cell *cp = new Cell;
    cp->ch = ch;
    cp->link = cursor->link;
    cursor->link = cp;
    cursor = cp;
}

/*
 * Delete: deleteChracter
 * ---------------------------------------
 * 1. Remove the current cell by pointing to its successor.
 * 2. Free the cell to reclaim the memory.
 */

void EditorBuffer::deleteCharacter()
{
    if (cursor->link != NULL)
    {
        Cell *oldCell = cursor->link;
        cursor->link = cursor->link->link;
        delete oldCell;
    }
}

string EditorBuffer::getText() const
{
    string str = "";
    for (Cell *cp = start->link; cp != cursor; cp = cp->link)
        str += cp->ch;
    return str;
}

int EditorBuffer::getCursor() const
{
    int nChars = 0;
    for (Cell *cp = start; cp != cursor; cp = cp->link)
        nChars++;
    return nChars;
}