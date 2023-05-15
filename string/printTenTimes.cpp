#include <iostream>
#include <cmath>

using namespace std;

void printTenTimes(char c);

int main()
{
    printTenTimes('-');
    return 0;
}

void printTenTimes(char c)
{
    for (int i = 0; i < 10; i++)
    {
        cout << c;
    }
    cout << endl;
}