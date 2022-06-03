#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *reverseLL(Node *head)
{
    if (!head)
        return nullptr;
    
    Node *temp = head, *prev = nullptr, *tempNext;
    while (temp->next)
    {
        tempNext = temp->next;
        temp->next = prev;
        prev = temp;
        temp = tempNext;
    }
    temp->next = prev;
    return temp;
}

int main()
{
    int t;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        head = reverseLL(head);
        printLL(head);
    }
    return 0;
}