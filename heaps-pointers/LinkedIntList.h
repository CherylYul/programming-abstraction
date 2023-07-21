#pragma once
#include <ostream>

using namespace std;

struct ListNode {
    int data;
    ListNode *next;
    ListNode(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedIntList {
  public:
    LinkedIntList();
    ~LinkedIntList();
    void addFront(int value);
    void addBack(int value);
    bool isEmpty();
    bool removeValue(int value);
    void removeFront();
    friend ostream &operator<<(ostream &out, LinkedIntList &list);

  private:
    ListNode *_front; // null if empty
    void removeAfter(ListNode *prev);
};
