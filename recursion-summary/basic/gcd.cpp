#include <iostream>
using namespace std;

int GCD(int x, int y);
void swap(int &x, int &y);

int main()
{
    cout << GCD(180, 24) << endl;
    return 0;
}

int GCD(int x, int y)
{
    if (y > x)
        swap(x, y);
    if (x % y == 0)
        return y;
    return GCD(y, x % y);
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}