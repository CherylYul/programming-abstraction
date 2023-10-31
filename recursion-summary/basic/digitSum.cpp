#include <iostream>
using namespace std;

int digitSum(int n);
int digitSum(int n, int div);
int digitalRoot(int n);

int main()
{
    cout << digitSum(1729) << endl;
    cout << digitalRoot(1729) << endl;
    return 0;
}

int digitSum(int n) { return digitSum(n, 1); }
int digitSum(int n, int div)
{
    if (n < div)
        return 0;
    return (n / div) % 10 + digitSum(n, div * 10);
}

int digitalRoot(int n)
{
    if (n < 10)
        return n;
    return digitalRoot(digitSum(n));
}