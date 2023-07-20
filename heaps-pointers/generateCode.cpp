/*
 * File: generateCode
 * ---------------------------------------
 */

#include <iostream>
#include <vector>
using namespace std;

void generateBinaryCode(int n);
void binaryCode(string str, int n);
void generateGrayCode(int n);
vector<string> grayCode(int n);
string toHexadecimal(int n);
string toBinary(int n);
int hexToDec(string str);
int biToDec(string str);

static const string HEXADECIMAL = "0123456789ABCDEF";
static const string BINARY = "01";

int main()
{
    cout << toHexadecimal(267) << endl;
    cout << toBinary(28) << endl;
    cout << hexToDec("0x2A") << endl;
    cout << biToDec("0b101010") << endl;
    cout << toHexadecimal(hexToDec("0xFEED") - hexToDec("0xCAFE")) << endl;
    return 0;
}

/*
 * Function: generateBinaryCode(n);
 * ---------------------------------------
 * Generates the bit patterns for the binary representation of all integers
 * that can be represented using the specified number of bits.
 */

void generateBinaryCode(int n)
{
    string str = "";
    binaryCode(str, n);
}

void binaryCode(string str, int n)
{
    if (n == 0)
    {
        cout << str << endl;
        return;
    }
    binaryCode(str + "0", n - 1);
    binaryCode(str + "1", n - 1);
}

/*
 * Function: generateGrayCode(n);
 * ---------------------------------------
 * Generates the bit patterns which is an ordering of the binary numeral system
 * such that two successive values differ in only one bit (binary digit).
 */

void generateGrayCode(int n)
{
    vector<string> strList;
    strList = grayCode(n);
    for (int i = 0; i < strList.size(); i++)
        cout << strList[i] << endl;
}

vector<string> grayCode(int n)
{
    if (n <= 0)
        return {"0"};
    if (n == 1)
        return {"0", "1"};
    vector<string> recAns = grayCode(n - 1);
    vector<string> mainAns;
    for (int i = 0; i < recAns.size(); i++)
    {
        string s = recAns[i];
        mainAns.push_back("0" + s);
    }
    for (int i = recAns.size() - 1; i >= 0; i--)
    {
        string s = recAns[i];
        mainAns.push_back("1" + s);
    }
    return mainAns;
}

/*
 * Implementation notes:
 * 267 => 0x10B
 * (267 / 1) % 16 = 11 => B
 * (267 / 16) % 16 = 0 => 0
 * (267 / 256) % 16 = 1 => 1
 */

string toHexadecimal(int n)
{
    int div = 1;
    string result = "0x";
    string temp = "";
    while (div <= n)
    {
        temp += HEXADECIMAL[(n / div) % 16];
        div *= 16;
    }
    for (int i = temp.length() - 1; i >= 0; i--)
        result += temp[i];
    return result;
}

string toBinary(int n)
{
    int div = 1;
    string result = "0b";
    string temp = "";
    while (div <= n)
    {
        temp += BINARY[(n / div) % 2];
        div *= 2;
    }
    for (int i = temp.length() - 1; i >= 0; i--)
        result += temp[i];
    return result;
}

/*
 * Implementation notes:
 * 0x2A => A * 1 + 2 * 16 = 10 + 32 = 42
 */

int hexToDec(string str)
{
    int result = 0;
    int multiplier = 1;
    while (str.length() > 2)
    {
        result += HEXADECIMAL.find(str.substr(str.length() - 1)) * multiplier;
        str = str.substr(0, str.length() - 1);
        multiplier *= 16;
    }
    return result;
}

int biToDec(string str)
{
    int result = 0;
    int multiplier = 1;
    while (str.length() > 2)
    {
        result += BINARY.find(str.substr(str.length() - 1)) * multiplier;
        str = str.substr(0, str.length() - 1);
        multiplier *= 2;
    }
    return result;
}
