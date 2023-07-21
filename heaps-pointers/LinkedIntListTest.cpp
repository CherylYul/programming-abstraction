#include "LinkedIntList.h"
// #include "console.h"
#include <iostream>
using namespace std;

int main()
{
    // node1 -> 42 -> 17 -> -3 -> 9 /
    LinkedIntList list;
    list.addBack(42);
    list.addBack(17);
    list.addBack(-3);
    list.addBack(9);

    // insert 88 at front of list
    list.addFront(88);

    // print the values
    cout << list << endl;

    list.addBack(777);
    cout << list << endl;

    list.removeFront();
    cout << "After removeFront(), here is the list again: " << endl;
    cout << list << endl;

    list.removeValue(17);
    cout << "After remove(17), here is the list again: " << endl;
    cout << list << endl;

    return 0;
}
