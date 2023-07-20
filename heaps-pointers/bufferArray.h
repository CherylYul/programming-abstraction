/*
 * File: bufferArray.h
 * ---------------------------------------
 * This file defines the interface for the EditorBuffer class with
 * the array version
 */

#ifndef _bufferArray_h
#define _bufferArray_h
#include <string>

class EditorBuffer
{
public:
    EditorBuffer();
    ~EditorBuffer();
    void moveCursorForward();
    void moveWordForward();
    void moveCursorBackward();
    void moveWordBackward();
    void moveCursorToStart();
    void moveCursorToEnd();
    void copyCharacter();
    void cutCharacter();
    void pasteCharacter();
    bool search(std::string str);
    void insertCharacter(char ch);
    void deleteCharacter();
    void deleteWord();
    std::string getText() const;
    int getCursor() const;

private:
    static const int INITIAL_CAPACITY = 10;
    char *array;  /* dynamic array of characters */
    int capacity; /* allocated size of that array */
    int length;   /* number of character in buffer */
    int cursor;   /* index of character after cursor */
    char savedCharacter;
    EditorBuffer(const EditorBuffer &value) {}
    const EditorBuffer &operator=(const EditorBuffer &rhs) { return *this; }
    void expandCapacity();
};

#endif