#include "LinkedIntList.h"

LinkedIntList::LinkedIntList()
{
    _front = nullptr;
}

LinkedIntList::~LinkedIntList()
{
    while (_front != nullptr)
    {
        ListNode *temp = _front;
        _front = _front->next;
        delete temp;
    }
}

void LinkedIntList::addFront(int value)
{
    ListNode *newNode = new ListNode(value);
    newNode->next = _front;
    _front = newNode;
}

void LinkedIntList::addBack(int value)
{
    ListNode *newNode = new ListNode(value);

    if (_front == nullptr)
    {
        _front = newNode;
    }
    else
    {
        ListNode *curr = _front;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        // at this point, we're at the back
        curr->next = newNode;
    }
}

bool LinkedIntList::isEmpty()
{
    return _front == nullptr;
}

bool LinkedIntList::removeValue(int value)
{
    // Removes the first instance of value in the list
    // We need to find the node before
    // the one we want to remove
    ListNode *temp;

    // traverse the list to the end, if necessary
    ListNode *curr = _front;
    ListNode *prev = nullptr;

    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr)
    { // first element
        removeFront();
        return true;
    }

    if (curr == nullptr)
    {
        // did not find value
        return false;
    }
    removeAfter(prev);
    return true;
}

void LinkedIntList::removeAfter(ListNode *prev)
{
    ListNode *temp = prev->next;
    prev->next = temp->next;
    delete temp;
}

void LinkedIntList::removeFront()
{
    if (_front != nullptr)
    {
        ListNode *temp = _front;
        _front = _front->next;
        delete temp;
    }
}

ostream &operator<<(ostream &out, LinkedIntList &list)
{
    out << "{";
    if (!list.isEmpty())
    {
        out << list._front->data;
        ListNode *curr = list._front->next;
        while (curr != nullptr)
        {
            out << ", " << curr->data;
            curr = curr->next;
        }
    }
    out << "}";
    return out;
}
