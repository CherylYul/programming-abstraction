/*
 * File: filelib.cpp
 * -----------------------------------------------
 * Implement my useful functions to handle file.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include "filelib.h"
using namespace std;

/*
 * Function: promptUserForFile
 * Usage: string filename = promptUserForFile(infile, prompt);
 * -----------------------------------------------
 * Asks the user for the name of an input file and opens the reference parameter
 * infile using that name, which is returned as the result of the function. If
 * the requested file does not exist, the user is given additional chances to
 * enter a valid file name. The optional prompt argument is used to give the
 * user more information about the desired input file.
 */

string promptUserForFile(ifstream &infile, string prompt)
{
    while (true)
    {
        cout << prompt;
        string filename;
        getline(cin, filename);
        infile.open(filename.c_str());
        if (!infile.fail())
            return filename;
        infile.clear();
        cout << "Unable to open that file. Try again." << endl;
        if (prompt == "")
            prompt = "Input file: ";
    }
}

/*
 * Function: copyStream
 * Usage: copyStream(infile, outfile);
 * -----------------------------------------------
 * Copies all the characters from one input stream to another
 */

void copyStream(istream &is, ostream &os)
{
    char ch;
    while (is.get())
        os.put(ch);
}

/*
 * Function: displayChar
 * Usage: displayChar(infile);
 * -----------------------------------------------
 * Display content in the file character by character
 */

void displayChar(ifstream &infile)
{
    char ch;
    while (infile.get(ch))
        cout.put(ch);
}

/*
 * Function: displayLine
 * Usage: displayLine(infile);
 * -----------------------------------------------
 * Display content in the file line by line
 */

void displayLine(ifstream &infile)
{
    string line;
    while (getline(infile, line))
        cout << line << endl;
}

/*
 * Function: readEntireFile
 * Usage: readEntireFile(is, lines);
 * -----------------------------------------------
 * Reads the entire contents of the specified input stream into the string
 * vector lines. The client is responsible for opening and closing the stream.
 */

// void readEntireFile(istream &is, Vector<string> &lines)
//{
//     string line;
//     while (getline(is, line))
//         lines.add(line);
// }

/*
 * Function: getInteger
 * Usage: int n = getInteger(prompt);
 * -----------------------------------------------
 * Requests an integer value from user, if input is not a legal integer
 * the implementation will give the user a chance to reenter the value
 */

int getInteger(string prompt)
{
    int value;
    string line;
    while (true)
    {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        stream >> value >> ws;
        if (!stream.fail() && stream.eof())
            break;
        cout << "Illegal integer format. Try again." << endl;
    }
    return value;
}

/*
 * Function: stringToInteger
 * Usage: int n = stringToInteger(str);
 * -----------------------------------------------
 * Requests an integer value from user, if input is not a legal integer,
 * extracts error message
 */

int stringToInteger(string str)
{
    int value;
    istringstream stream(str);
    stream >> value >> ws;
    if (stream.fail() || !stream.eof())
        error("stringToInteger: Illegal integer format");
    return value;
}

/*
 * Function: integerToString
 * Usage: string str = integerToString(n);
 * -----------------------------------------------
 * Turn an integer value to string type
 */

string integerToString(int n)
{
    ostringstream stream;
    stream << n;
    return stream.str();
}

/*
 * Function: printLongestLine
 * Usage: printLongestLine(n);
 * -----------------------------------------------
 * Print the longest line in the file
 */

void printLongestLine(ifstream &infile)
{
    string line;
    int longest = 0;
    string longestline;
    while (getline(infile, line))
        if (line.length() > longest)
        {
            longest = line.length();
            longestline = line;
        }
    cout << longestline << endl;
}

/*
 * Function: reportLineWordChar
 * Usage: reportLineWordChar(infile, charCount, wordCount, lineCount);
 * -----------------------------------------------
 * Calculate numbers of line, word and character in a file
 */

void reportLineWordChar(ifstream &infile, int &charCount, int &wordCount, int &lineCount)
{
    string line;
    while (getline(infile, line))
    {
        charCount += line.length();
        wordCount = wordCount + countSpace(line) + 1;
        lineCount++;
    }
}

/*
 * Function: countSpace
 * Usage: int n = countSpace(str);
 * -----------------------------------------------
 * Calculate numbers of space in a string
 */

int countSpace(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
        if (isspace(str[i]))
            count++;
    return count;
}

/*
 * Function: getExtension
 * Usage: string ext = getExtension(filename);
 * -----------------------------------------------
 * Returns the extension of filename, the extension include seperating dot
 * and all subsequent characters. If dot not exist returns empty string
 */

string getExtension(const string &filename)
{
    int dot = -1;
    for (int i = 0; i < filename.length(); i++)
    {
        char ch = filename[i];
        if (ch == '.')
            dot = i;
        if (ch == '/' || ch == '\\')
            dot = -1;
    }
    if (dot == -1)
        return "";
    else
        return filename.substr(dot);
}

/*
 * Function: getRoot
 * Usage: string str = getRoot(filename);
 * ------------------------------------------------------
 * Returns the root of filename, the root consists of everything in filename
 * up to the last dot and the subsequent extension.  If no dot appears
 * returns the entire name.
 */

string getRoot(const string &filename)
{
    int dot = -1;
    for (int i = 0; i < filename.length(); i++)
    {
        char ch = filename[i];
        if (ch == '.')
            dot = i;
        if (ch == '/' || ch == '\\')
            dot = -1;
    }
    if (dot == -1)
        return filename;
    else
        return filename.substr(0, dot);
}

/*
 * Function: defaultExtension
 * Usage: string str = defaultExtension(filename, ext);
 * ------------------------------------------------------
 * Add the ext to filename if it does not have extension, if it has,
 * would ignore the specified ext and return the original filename, if ext
 * has a star before a dot add the new ext anyway.
 */

string defaultExtension(const string filename, const string ext)
{
    int dot = -1;
    string extCopy = ext;
    for (int i = 0; i < filename.length(); i++)
    {
        char ch = filename[i];
        if (ch == '.')
            dot = i;
        if (ch == '/' || ch == '\\')
            dot = -1;
    }
    bool star = (ext[0] == '*');
    if (star)
        extCopy = ext.substr(1);
    if (dot == -1)
    {
        dot = filename.length();
        star = true;
    }
    if (star)
        return filename.substr(0, dot) + extCopy;
    return filename;
}

/*
 * Function: error
 * Usage: error(msg);
 * ------------------------------------------------------
 * Writes the string msg to the cerr stream and then exit
 * the program with a standard status value indicating that
 * a failure has occurred
 */

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}