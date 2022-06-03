#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *reverseLLRec(Node *head)
{
    if (!(head && head->next))
        return head;
    Node *newHead = reverseLLRec(head->next);
    Node *temp = newHead;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    int t;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        head = reverseLLRec(head);
        printLL(head);
    }
    return 0;
}