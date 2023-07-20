/*
 * File: bufferLinkedList.h
 * ---------------------------------------
 * This file defines the interface for the EditorBuffer class with
 * the linked list version
 */

#ifndef _bufferLinkedList_h
#define _bufferLinkedList_h
#include <string>

class EditorBuffer
{
public:
    EditorBuffer();
    ~EditorBuffer();
    void moveCursorForward();
    void moveCursorBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void insertCharacter(char ch);
    void deleteCharacter();
    std::string getText() const;
    int getCursor() const;

private:
    struct Cell
    {
        char ch;
        Cell *link;
    };
    Cell *start;  /* Pointer to the dummy cell */
    Cell *cursor; /* Pointer to cell before cursor */
    /* Make it illegal to copy editor buffers */
    EditorBuffer(const EditorBuffer &value) {}
    const EditorBuffer &operator=(const EditorBuffer &rhs) { return *this; }
};

#endif