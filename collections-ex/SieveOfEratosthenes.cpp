/*
 * Function: SieveOfEratosthenes
 * ---------------------------------------
 * Sieve of Eratosthenes is the algorithm that finds out the prime number
 * by circle the first number in range from 2 to N, then cross off every
 * multiple of 2, continue to circle next element which wasn't been crossed
 * and repeat the process
 */

#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<int, bool> sieveOfEratosthenes(int n);

int main()
{
    map<int, bool> prime = sieveOfEratosthenes(1000);
    for (map<int, bool>::iterator i = prime.begin(); i != prime.end(); ++i)
        if (i->second)
            cout << i->first << endl;
    return 0;
}

map<int, bool> sieveOfEratosthenes(int n)
{
    map<int, bool> prime;
    for (int i = 2; i < n; i++)
        prime[i] = true;
    for (int p = 2; p <= sqrt(n); p++)
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    return prime;
}