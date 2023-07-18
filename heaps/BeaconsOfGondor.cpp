/*
 * File: BeaconsOfGondor.cpp
 * ---------------------------------------
 * This program illustrates the concept of a linked list by simulating
 * the Beacons of Gondor story from J.R.R.Tolkien's Return of the King.
 */

#include <iostream>
#include <string>
using namespace std;

struct Tower
{
    string name;
    Tower *link;
};

Tower *createBeaconsOfGondor();
Tower *createTower(string name, Tower *link);
void signal(Tower *start);
void freeList(Tower *list);

int main()
{
    Tower *list = createBeaconsOfGondor();
    signal(list);
    return 0;
}

Tower *createBeaconsOfGondor()
{
    Tower *tp = createTower("Rohan", NULL);
    tp = createTower("Halifirien", tp);
    tp = createTower("Calenhad", tp);
    tp = createTower("Min-Rimmon", tp);
    tp = createTower("Erelas", tp);
    tp = createTower("Nardol", tp);
    tp = createTower("Eilenach", tp);
    tp = createTower("Amon Din", tp);
    return createTower("Minas Tirith", tp);
}

Tower *createTower(string name, Tower *link)
{
    Tower *tp = new Tower;
    tp->name = name;
    tp->link = link;
    return tp;
}

/*
 * tp = tp->link: changes the value of tp to the value of the link pointer
 * in the current Tower structure, thereby advancing tp to the next tower
 * in the list.
 * Method 2:
 * void signal(Tower *start) {
 *      if (start != NULL) {
 *          cout << "Lighting " << start->name << endl;
 *          signal(start->link);
 *      }
 * }
 */
void signal(Tower *start)
{
    for (Tower *tp = start; tp != NULL; tp = tp->link)
        cout << "Lighting " << tp->name << endl;
}

void freeList(Tower *list) {
    if (list != NULL) {
        freeList(list->link);
        delete list;
    }
}