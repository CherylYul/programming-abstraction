/*
 * File: bufferTest.cpp
 * ---------------------------------------
 * This program implements a simple command-driven text editor, which is
 * used to test the EditorBuffer class.
 */

#include <cctype>
#include <iostream>
#include <regex>
#include "bufferArray.h"
#include "bufferArray.cpp"
using namespace std;

void executeCommand(EditorBuffer &buffer, string line);
void executeComplexCommand(EditorBuffer &buffer, string line);
void moveForward(EditorBuffer &buffer, string line);
void displayBuffer(EditorBuffer &buffer);
void printHelpText();
void printBuffer(EditorBuffer &buffer);

int main()
{
    EditorBuffer buffer;
    while (true)
    {
        string cmd;
        cout << "*";
        // getline(cin, cmd, '.'); reads text on subsequent lines ending when enter '.'
        getline(cin, cmd);
        if (cmd != "")
        {
            if (regex_match(cmd, regex("[\\[0-9]+(F)")))
                moveForward(buffer, cmd);
            else if (cmd == "FW" || cmd == "BW" || cmd == "DW")
                executeComplexCommand(buffer, cmd);
            else
                executeCommand(buffer, cmd);
        }
    }
    return 0;
}

/*
 * executeCommand(buffer, line);
 * ---------------------------------------
 * Executes the command specified by line on the editor buffer.
 */

void executeCommand(EditorBuffer &buffer, string line)
{
    switch (line[0])
    {
    case 'I':
        for (int i = 1; i < line.length(); i++)
            buffer.insertCharacter(line[i]);
        displayBuffer(buffer);
        break;
    case 'D':
        buffer.deleteCharacter();
        displayBuffer(buffer);
        break;
    case 'F':
        buffer.moveCursorForward();
        displayBuffer(buffer);
        break;
    case 'B':
        buffer.moveCursorBackward();
        displayBuffer(buffer);
        break;
    case 'J':
        buffer.moveCursorToStart();
        displayBuffer(buffer);
        break;
    case 'E':
        buffer.moveCursorToEnd();
        displayBuffer(buffer);
        break;
    case 'C':
        buffer.copyCharacter();
        cout << "Copy success!" << endl;
        break;
    case 'X':
        buffer.cutCharacter();
        displayBuffer(buffer);
        break;
    case 'P':
        buffer.pasteCharacter();
        displayBuffer(buffer);
        break;
    case 'S':
        buffer.search(line.substr(1));
        displayBuffer(buffer);
        break;
    case 'T':
        printBuffer(buffer);
        break;
    case 'H':
        printHelpText();
        break;
    case 'Q':
        exit(0);
    default:
        cout << "Illegal command" << endl;
        break;
    }
}

void executeComplexCommand(EditorBuffer &buffer, string line)
{
    if (line == "FW")
    {
        buffer.moveWordForward();
        displayBuffer(buffer);
    }
    else if (line == "BW")
    {
        buffer.moveWordBackward();
        displayBuffer(buffer);
    }
    else
    {
        buffer.deleteWord();
        displayBuffer(buffer);
    }
}

void moveForward(EditorBuffer &buffer, string line)
{
    smatch m;
    string result = "";
    regex_search(line, m, regex("[\\[0-9]+F"));
    for (int i = 0; i < m.length() - 1; i++)
        result += line[i];
    cout << result << endl;
    int n = stoi(result);
    while (n > 0)
    {
        --n;
        buffer.moveCursorForward();
    }
    displayBuffer(buffer);
}

void printBuffer(EditorBuffer &buffer)
{
    string str = buffer.getText();
    for (int i = 0; i < str.length(); i++)
        cout << str[i];
    cout << endl;
}

/*
 * displayBuffer(buffer);
 * ---------------------------------------
 * Displays the state of the buffer including the position of the cursor.
 */

void displayBuffer(EditorBuffer &buffer)
{
    string str = buffer.getText();
    for (int i = 0; i < str.length(); i++)
        cout << str[i];
    cout << endl;
    cout << string(buffer.getCursor(), ' ') << "^" << endl;
}

void printHelpText()
{
    cout << "Editor commands: " << endl;
    cout << "Iabc Inserts the characters abc at the cursor position" << endl;
    cout << "F    Moves the cursor forward one character" << endl;
    cout << "FW   Moves forward to the end of the word" << endl;
    cout << "B    Moves the cursor backward one character" << endl;
    cout << "BW   Move backward to the beginning of the word" << endl;
    cout << "D    Deletes the character after the cursor" << endl;
    cout << "DW   Delete the entire word, if cursor not point to the empty space" << endl;
    cout << "J    Jumps to the beginning of the buffer" << endl;
    cout << "E    Jumps to the end of the buffer" << endl;
    cout << "C    Copy the character at the cursor position" << endl;
    cout << "X    Cut the character at the cursor position" << endl;
    cout << "P    Paste the cut or copy character at the cursor position" << endl;
    cout << "Sabc Search the string abc and put the cursor at the end of the string" << endl;
    cout << "T    Prints the contents of the buffer as a string" << endl;
    cout << "H    Prints this message" << endl;
    cout << "Q    Exits from the editor program" << endl;
}