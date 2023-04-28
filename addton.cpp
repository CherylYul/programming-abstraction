/*
 * Files: Add to N integers
 * -------------------------------
 * Adding from 1 to N integers we want
 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cout << "What is the number you would like to add from 1 to?" << endl;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    cout << "Total value from 1 to " << n << " is " << sum << endl;
    return 0;
}