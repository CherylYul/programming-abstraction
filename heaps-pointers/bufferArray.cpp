#include <cctype>
#include <iostream>
#include "bufferArray.h"
using namespace std;

EditorBuffer::EditorBuffer()
{
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    savedCharacter = ' ';
    length = 0;
    cursor = 0;
}
EditorBuffer::~EditorBuffer() { delete[] array; }
void EditorBuffer::moveCursorForward() // O(1)
{
    if (cursor < length)
        cursor++;
}

void EditorBuffer::moveWordForward()
{
    while (array[cursor] != ' ' && cursor < length)
        cursor++;
    this->moveCursorForward();
}

void EditorBuffer::moveCursorBackward() // O(1)
{
    if (cursor > 0)
        cursor--;
}

void EditorBuffer::moveWordBackward()
{
    while (array[cursor] != ' ' && cursor > 0)
        cursor--;
    this->moveCursorBackward();
}

void EditorBuffer::moveCursorToStart() { cursor = 0; }    // O(1)
void EditorBuffer::moveCursorToEnd() { cursor = length; } // O(1)
void EditorBuffer::copyCharacter() { savedCharacter = array[cursor]; }
void EditorBuffer::cutCharacter()
{
    savedCharacter = array[cursor];
    this->deleteCharacter();
}
void EditorBuffer::pasteCharacter() { this->insertCharacter(savedCharacter); }
bool EditorBuffer::search(string str)
{
    string text = this->getText();
    int strLength = str.length();
    for (int i = 0; i <= length - strLength; i++)
        if (text.substr(i, strLength) == str)
        {
            cursor = i + strLength;
            return true;
        }
    cout << "Search failed." << endl;
    return false;
}

void EditorBuffer::insertCharacter(char ch) // O(n)
{
    if (length == capacity)
        expandCapacity();
    for (int i = length; i > cursor; i--)
        array[i] = array[i - 1];
    array[cursor] = ch;
    length++;
    cursor++;
}
void EditorBuffer::deleteCharacter() // O(n)
{
    if (cursor < length)
    {
        for (int i = cursor + 1; i < length; i++)
            array[i - 1] = array[i];
        length--;
    }
}

void EditorBuffer::deleteWord()
{
    if (cursor < length)
    {
        this->moveWordBackward();
        if (cursor != 0)
            this->moveCursorForward();
        int count = 1;
        while (array[cursor + count] != ' ' && cursor + count < length)
            count++;
        for (int i = cursor + count; i < length; i++)
            array[i - count] = array[i];
        length = length - count;
    }
}

string EditorBuffer::getText() const { return string(array, length); }
int EditorBuffer::getCursor() const { return cursor; }
void EditorBuffer::expandCapacity()
{
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i < length; i++)
        array[i] = oldArray[i];
    delete[] oldArray;
}
