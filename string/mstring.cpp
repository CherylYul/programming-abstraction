/*
 * File: mstring.cpp
 * -----------------------------------------------
 * Implement my useful functions to handle string related problems
 */

#include <string>
#include <cctype>
#include <optional>
#include "mstring.h"
using namespace std;

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
 * Function: countSpaces
 * Usage: int numSpaces = countSpaces(str);
 * -----------------------------------------------
 * Returns total number of spaces in the string
 */

int countSpaces(string str)
{
    int numSpaces = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
            numSpaces++;
    }
    return numSpaces;
}

/*
 * Function: startsWith
 * Usage: startsWith(str, prefix);
 * -----------------------------------------------
 * Returns true if a string begins with the particular prefix
 */

bool startsWith(string str, string prefix)
{
    if (str.length() < prefix.length())
        return false;
    for (int i = 0; i < prefix.length(); i++)
    {
        if (str[i] != prefix[i])
            return false;
    }
    return true;
}

/*
 * Function: endsWith
 * Usage: endsWith(str, suffix);
 * -----------------------------------------------
 * Returns true if a string ends with the particular suffix
 */

bool endsWith(string str, string suffix)
{
    if (str.length() < suffix.length())
        return false;
    int distance = str.length() - suffix.length();
    for (int i = 0; i < suffix.length(); i++)
    {
        if (suffix[i] != str[i + distance])
            return false;
    }
    return true;
}

/*
 * Function: repeatChar
 * Usage: string result = repeatChar(ch, k);
 * -----------------------------------------------
 * Repeat the character ch k times
 */

string repeatChar(char ch, int k)
{
    string str = "";
    for (int i = 0; i < k; i++)
    {
        str += ch;
    }
    return str;
}

/*
 * Function: reverse
 * Usage: string result = reverse(str);
 * -----------------------------------------------
 * Reverse the argument string so that "desserts" turn to "stressed"
 */

string reverse(string str)
{
    string rev = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        rev += str[i];
    }
    return rev;
}

/*
 * Function: isDigitString
 * Usage: isDigitString(str);
 * -----------------------------------------------
 * Returns true if the argument str is a nonempty string of digits
 */

bool isDigitString(string str)
{
    if (str.length() == 0)
        return false;
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

/*
 * Function: equalsIgnoreCase
 * Usage: equalsIgnoreCase(str1, str2);
 * -----------------------------------------------
 * Returns true if string str1 and str2 are equals, ignoring differences in case
 */

bool equalsIgnoreCase(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;
    for (int i = 0; i < str1.length(); i++)
    {
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;
    }
    return true;
}

/*
 * Function: topUpperCaseInPlace
 * Usage: topUpperCaseInPlace(str);
 * -----------------------------------------------
 * The procedure changes the contents argument string from lower to upper case
 */

void toUpperCaseInPlace(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

/*
 * Function: topLowerCaseInPlace
 * Usage: topLowerCaseInPlace(str);
 * -----------------------------------------------
 * The procedure changes the contents argument string from upper to lower case
 */

void toLowerCaseInPlace(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
}

/*
 * Function: topUpperCase
 * Usage: topUpperCase(str);
 * -----------------------------------------------
 * Returns an uppercase copy of its argument without changing the original
 */

string toUpperCase(string str)
{
    toUpperCaseInPlace(str);
    return str;
}

/*
 * Function: topLowerCase
 * Usage: topLowerCase(str);
 * -----------------------------------------------
 * Returns an lowercase copy of its argument without changing the original
 */

string toLowerCase(string str)
{
    toLowerCaseInPlace(str);
    return str;
}

/*
 * Function: isPalindrome
 * Usage: isPalindrome(str);
 * -----------------------------------------------
 * Returns true if a string is a palindrome. A palindrome is a word that
 * reads identically backward and forward
 */

bool isPalindrome(string str)
{
    return str == reverse(str);
}

/*
 * Function: secondHalf
 * Usage: string result = secondHalf(str);
 * -----------------------------------------------
 * Returns the second half of parameter str
 */

string secondHalf(string str)
{
    return str.substr(str.length() / 2);
}

/*
 * Function: trim
 * Usage: string result = trim(str);
 * -----------------------------------------------
 * Returns new string formed by removing all whitespace characters
 * from the beginning and end of str
 */

string trim(string str)
{
    string str2 = str;
    trimStartInPlace(str2);
    trimEndInPlace(str2);
    return str2;
}

/*
 * Function: trimEndInPlace
 * Usage: trimEndInPlace(str);
 * -----------------------------------------------
 * Remove the space at the end of the string
 */

void trimEndInPlace(string &str)
{
    int finish = str.length();
    while (finish > 0 && isspace(str[finish - 1]))
        finish--;
    if (finish < str.length())
        str.erase(finish, str.length() - finish);
}

/*
 * Function: trimStartInPlace
 * Usage: trimStartInPlace(str);
 * -----------------------------------------------
 * Remove the space at the beginning of the string
 */

void trimStartInPlace(string &str)
{
    int start = 0;
    while (start <= str.length() - 1 && isspace(str[start]))
        start++;
    if (start > 0)
        str.erase(0, start);
}

/*
 * Function: trimEnd
 * Usage: trimEnd(str);
 * -----------------------------------------------
 * Remove the space at the end of the string and returns new string
 */

string trimEnd(string str)
{
    string str2 = str;
    trimEndInPlace(str2);
    return str2;
}

/*
 * Function: trimStart
 * Usage: trimStart(str);
 * -----------------------------------------------
 * Remove the space at the beginning of the string and returns new string
 */

string trimStart(string str)
{
    string str2 = str;
    trimStartInPlace(str2);
    return str2;
}

/*
 * Function: substrOne
 * Usage: string str = substrOne(str, pos, n);
 * -----------------------------------------------
 * Returns the substring of str beginning at position pos
 * and containing at most character n
 */

string substrOne(string str, int pos, char n)
{
    if (pos > str.length())
        error("position should smaller than the length of the string!");

    int end = 0;
    for (int i = str.length() - 1; i > pos; i--)
    {
        if (str[i] == n)
        {
            end = i;
            break;
        }
    }

    string result;
    if (end != 0)
    {
        for (int i = pos; i < end; i++)
            result += str[i];
        return result;
    }
    return "not found";
}

/*
 * Function: capitalize
 * Usage: string str = capitalize(str);
 * -----------------------------------------------
 * Convert the initial character into uppercase, other to lowercase
 */

std::string capitalize(std::string str)
{
    char initialChar = toupper(str[0]);
    string newStr;
    for (int i = 1; i < str.length(); i++)
    {
        newStr += tolower(str[i]);
    }
    return initialChar + newStr;
}

/*
 * Function: acronym
 * Usage: string str = acronym(str);
 * -----------------------------------------------
 * Returns acronym form of string. Acronym is a new word formed by combining,
 * order, initial letters of series of words.
 */

std::string acronym(std::string str)
{
    string newStr;
    if (isalpha(str[0]))
        newStr += str[0];
    for (int i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]) || !isalpha(str[i]))
            newStr += str[i + 1];
    }
    return newStr;
}

/*
 * Function: removeCharacters
 * Usage: string str = removeCharacters(str, removeStr);
 * -----------------------------------------------
 * Returns a new string after removing all instances of the characters in
 * removeStr without changing the original one.
 */

string removeCharacters(string str, string removeStr)
{
    string str2 = str;
    removeCharactersInPlace(str2, removeStr);
    return str2;
}

/*
 * Function: removeCharactersInPlace
 * Usage: removeCharactersInPlace(str, removeStr);
 * -----------------------------------------------
 * Change str into a new string after removing all instances of the characters in removeStr
 */

void removeCharactersInPlace(string &str, string removeStr)
{
    string newStr = str;
    int count = 0;
    for (int i = 0; i < newStr.length(); i++)
        for (int j = 0; j < removeStr.length(); j++)
            if (newStr[i] == removeStr[j])
            {
                str.erase(i - count, 1);
                count++;
            }
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}