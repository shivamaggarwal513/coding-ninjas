#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *mergeSortedLL(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    
    Node *temp, *head;
    if (head1->data < head2->data)
    {
        head = temp = head1;
        head1 = head1->next;
    }
    else
    {
        head = temp = head2;
        head2 = head2->next;
    }
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    if (!head1)
        head1 = head2;
    temp->next = head1;
    return head;
}

int main()
{
    int t;
    Node *head1, *head2, *head;
    cin >> t;
    while (t--)
    {
        head1 = takeInput();
        head2 = takeInput();
        head = mergeSortedLL(head1, head2);
        printLL(head);
    }
    return 0;
}