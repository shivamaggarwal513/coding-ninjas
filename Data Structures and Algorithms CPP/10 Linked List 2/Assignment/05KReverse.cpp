#include <iostream>
#include "..\..\09 Linked List 1\01LinkedList.h"
using namespace std;

class nodeClass
{
public:
    Node *head;
    Node *tail;
    Node *nextHead;
    nodeClass(Node *head, Node *tail, Node *nextHead)
    {
        this->head = head;
        this->tail = tail;
        this->nextHead = nextHead;
    }
};

nodeClass reverseLL(Node *head, int k)
{
    if (!head)
        return nodeClass(nullptr, nullptr, nullptr);
    
    int i = 0;
    Node *temp = head, *prev = nullptr, *tempNext;
    while (i < k - 1 && temp->next)
    {
        tempNext = temp->next;
        temp->next = prev;
        prev = temp;
        temp = tempNext;
        i++;
    }
    Node *nextHead = temp->next;
    temp->next = prev;
    return nodeClass(temp, head, nextHead);
}

Node *kReverse(Node *head, int k)
{
    if (!head || !k)
        return head;
    
    nodeClass subK = reverseLL(head, k);
    Node *newHead = subK.head, *temp = subK.nextHead;
    Node *prevTail = subK.tail;
    while (temp)
    {
        subK = reverseLL(temp, k);
        prevTail->next = subK.head;
        prevTail = subK.tail;
        temp = subK.nextHead;
    }
    return newHead;
}

int main()
{
    int t, k;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        cin >> k;
        head = kReverse(head, k);
        printLL(head);
    }
    return 0;
}