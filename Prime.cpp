/*
 * File: Prime.cpp
 * ---------------------------------------------
 * This program checks if a number is prime and
 * factorize that number
 */

#include <iostream>
#include <cmath>
using namespace std;

/* function protoype */
bool isPrime(int num);
void primeFactorization(int num);
void error(string msg);

/* main program */
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (num == 1)
        error("This program reads in number greater than 1.");
    if (isPrime(num))
    {
        cout << num << " is prime.";
    }
    else
    {
        cout << num << " is not prime." << endl;
        primeFactorization(num);
    }
    return 0;
}

/*
 * Function: isPrime
 * Usage: isPrime(int num);
 * ---------------------------------------------
 * Returns true if num is prime
 */

bool isPrime(int num)
{
    int squareRoot = int(sqrt(num)) + 1;
    bool count = true;
    for (int i = 2; i < squareRoot; i++)
    {
        if (num % i == 0)
        {
            count = !count;
            break;
        }
    }
    return count;
}

/*
 * Function: primeFactorization
 * Usage: primeFactorization(int num);
 * ---------------------------------------------
 * Factors the num
 */

void primeFactorization(int num)
{
    int start = 2;
    while (num != 1)
    {
        if (num % start == 0)
        {
            cout << start;
            num /= start;
            if (num != 1)
                cout << " x ";
        }
        else
        {
            start += 1;
        }
    }
}

/*
 * Function: error
 * Usage: error(msg);
 * -----------------------------------------------------------------
 * Write error message to the cerr stream and then exit the program
 * indicating that a failure has occured
 */

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}