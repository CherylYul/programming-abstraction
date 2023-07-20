/*
 * File: tokenscanner.cpp
 * ---------------------------------------
 * This file implements the TokenScanner class. Most of the methods
 * are straightforward enough to require no additional documentation
 */

#include <cctype>
#include <string>
#include "tokenscanner.h"
using namespace std;

tokenScanner::tokenScanner() {}
tokenScanner::tokenScanner(string str)
{
    setInput(str);
}
void tokenScanner::setInput(string str)
{
    buffer = str;
    cp = 0;
}
bool tokenScanner::hasMoreTokens()
{
    if (ignoreWhitespaceFlag)
        skipWhitespace();
    return cp < buffer.length();
}

/*
 * Implementation notes: nextToken
 * ---------------------------------------
 * Starts looking at the character at the current character indicated
 * by the index cp. If that index is past the end of the string, nextToken returns
 * the empty string. If that character is alphanumeric, nextToken scans ahead until
 * it finds the end of that word; if not, nextToken returns that character as a
 * one-character string.
 */

string tokenScanner::nextToken()
{
    if (ignoreWhitespaceFlag)
        skipWhitespace();
    if (cp >= buffer.length())
        return "";
    else if (isalnum(buffer[cp]))
    {
        int start = cp;
        while (cp < buffer.length() && isalnum(buffer[cp]))
            cp++;
        return buffer.substr(start, cp - start);
    }
    else
        return string(1, buffer[cp++]);
}

/*
 * Implementation notes: ignoreWhitespace and skipWhitespace
 * ---------------------------------------
 * This ignoreWhitespace method simply sets a flag. The private method
 * skipWhitespace is called only if that flag is true.
 */

void tokenScanner::ignoreWhiteSpace()
{
    ignoreWhitespaceFlag = true;
}

void tokenScanner::skipWhitespace()
{
    while (cp < buffer.length() && isspace(buffer[cp]))
        cp++;
}

/*
 * Function: scanCPlusPlusTokens
 * Usage: scanCPlusPlusTokens(scanner);
 * ---------------------------------------
 * Set the necessaray options for the scanner so that it can
 * read C++ source code
 */

void scanCPlusPlusTokens(tokenScanner &scanner)
{
    scanner.ignoreWhiteSpace();
    scanner.ignoreComments();
    scanner.scanNumbers();
    scanner.scanStrings();
    scanner.addWordCharacters("_");
    scanner.addOperator("++");
    scanner.addOperator("--");
    scanner.addOperator("==");
    scanner.addOperator("!=");
    scanner.addOperator("<=");
    scanner.addOperator(">=");
    scanner.addOperator(">>");
    scanner.addOperator("<<");
    scanner.addOperator("&&");
    scanner.addOperator("||");
    scanner.addOperator("+=");
    scanner.addOperator("-=");
    scanner.addOperator("*=");
    scanner.addOperator("%=");
    scanner.addOperator("^=");
    scanner.addOperator("&=");
    scanner.addOperator("|=");
    scanner.addOperator("<<=");
    scanner.addOperator(">>=");
    scanner.addOperator("->");
    scanner.addOperator("::");
}