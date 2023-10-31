#include <iostream>
using namespace std;

int combinations(int n, int k);
int internalComb(int n, int k);

int main()
{
    cout << combinations(6, 2) << endl;
    return 0;
}

// PASCAL TRIANGLES
int combinations(int n, int k)
{
    int mid = n / 2;
    if (k > mid)
        return internalComb(n, n - k);
    return internalComb(n, k);
}

int internalComb(int n, int k)
{
    if (k < 1)
        return 1;
    return double(n) / double(k) * internalComb(n - 1, k - 1);
}