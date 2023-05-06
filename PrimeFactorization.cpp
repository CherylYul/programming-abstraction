/*
 * File: PrimeFactorization
 * ---------------------------------------------
 * Display the prime factorization of a number n
 */

#include <iostream>
using namespace std;

int main()
{
    int value;
    int p = 2;
    cout << "This program factors a number." << endl;
    cout << "Enter number to be factored: ";
    cin >> value;
    while (value != 1)
    {
        if (value % p == 0)
        {
            cout << p;
            value /= p;
            if (value != 1)
                cout << " x ";
        }
        else
        {
            p += 1;
        }
    }
    return 0;
}