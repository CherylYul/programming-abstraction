#include <iostream>
using namespace std;

int additiveSeq(int n, int t0, int t1);
int fibSeq(int n);

int main()
{
    cout << additiveSeq(8, 7, 10) << endl;
    cout << fibSeq(12) << endl;
    return 0;
}

int additiveSeq(int n, int t0, int t1)
{
    if (n == 0)
        return t0;
    if (n == 1)
        return t1;
    return additiveSeq(n - 1, t1, t0 + t1);
}

int fibSeq(int n) { return additiveSeq(n, 0, 1); }