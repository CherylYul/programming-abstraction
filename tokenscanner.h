/*
 * File: tokenscanner.h
 * ---------------------------------------
 * This file exports a simple TokenScanner class that divides a string
 * into individual logical units called tokens.
 */

#ifndef _tokenscanner_h
#define _tokenscanner_h
#include <string>

/*
 * Class: TokenScanner
 * ---------------------------------------
 * This class is used to represent a single instance of a scanner,
 * tokens come in 2 forms:
 *
 * 1. Strings of consecutive letters and ditgits representing words
 * 2. One-character strings representing punctuation or separators
 *
 * The use of the TokenScanner class is illustrated by the following
 * code pattern, which reads the tokens in the string variable input:
 *
 *      TokenScanner scanner;
 *      scanner.setInput(input);
 *      while (scanner.hasMoreTokens()) {
 *          string token = scanner.nextToken();
 *          ...process the token...
 *      }
 */

class tokenScanner
{
public:
    /*
     * Constructor: TokenScanner
     * Usage: TokenScanner scanner;
     *        TokenScanner scanner(str);
     * ---------------------------------------
     * Initializes a scanner object:
     *
     * 1. Default constructor creates a scanner with an empty token stream
     * 2. Initial token stream comes from the str if it is specified
     */
    tokenScanner();
    tokenScanner(std::string str);

    /*
     * Method: setInput
     * Usage: scanner.setInput(str);
     * ---------------------------------------
     * Sets the input for this scanner to the specified string. Any previous
     * input string is discarded
     */
    void setInput(std::string str);

    /*
     * Method: hasMoreTokens
     * Usage: if (scanner.hasMoreTokens())...
     * ---------------------------------------
     * Returns true if there are additional tokens for this scanner to read
     */
    bool hasMoreTokens();

    /*
     * Method: nextToken
     * Usage: token = scanner.nextToken();
     * ---------------------------------------
     * Returns the next token from this scanner. If called when no tokens are
     * available, nextToken returns the empty string
     */
    std::string nextToken();

    /*
     * Method: ignoreWhitespace()
     * Usage: scanner.ignoreWhitespace();
     * ---------------------------------------
     * Tells the scanner to ignore whitespace characters. By default, the nextToken
     * method treats whitespace characters just like any other punctuation and returns
     * them as single-character tokens. Calling this make scanner change behavior
     */
    void ignoreWhiteSpace();

    void ignoreComments();
    void scanNumbers();
    void scanStrings();
    void addWordCharacters(std::string str);
    void addOperator(std::string op);

private:
    std::string buffer;        /* input string */
    int cp;                    /* current position of buffer */
    bool ignoreWhitespaceFlag; /* flag set by call to ignore white space */
    void skipWhitespace();
};

void scanCPlusPlusTokens(tokenScanner &scanner);

#endif