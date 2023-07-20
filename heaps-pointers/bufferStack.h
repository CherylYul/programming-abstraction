/*
 * File: bufferStack.h
 * ---------------------------------------
 * This file defines the interface for the EditorBuffer class in
 * stack verion
 */

#ifndef _bufferStack_h
#define _bufferStack_h
#include <string>
#include "charstack.h"
#include "charstack.cpp"

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
    EditorBuffer(const EditorBuffer &value) {}
    const EditorBuffer &operator=(const EditorBuffer &rhs) { return *this; }
    CharStack before;
    CharStack after;
};

#endif