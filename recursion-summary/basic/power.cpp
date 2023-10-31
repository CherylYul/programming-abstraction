#include <iostream>
using namespace std;

int raiseToPower(int n, int k);

int main()
{
    cout << raiseToPower(2, 5) << endl;
    return 0;
}

int raiseToPower(int n, int k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    return n * raiseToPower(n, k - 1);
}