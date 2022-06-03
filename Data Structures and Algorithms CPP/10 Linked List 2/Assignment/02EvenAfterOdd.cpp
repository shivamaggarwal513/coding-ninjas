#include <iostream>
#include "..\..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *evenAfterOdd(Node *head)
{
    Node *oddH = new Node(0), *evenH = new Node(0);
    Node *oddT = oddH, *evenT = evenH, *temp = head;
    while (temp)
    {
        if (temp->data & 1)
        {
            oddT->next = temp;
            oddT = temp;
            temp = temp->next;
            oddT->next = nullptr;
        }
        else
        {
            evenT->next = temp;
            evenT = temp;
            temp = temp->next;
            evenT->next = nullptr;
        }
    }
    oddT->next = evenH->next;
    return oddH->next;
}

int main()
{
    int t;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        head = evenAfterOdd(head);
        printLL(head);
    }
    return 0;
}