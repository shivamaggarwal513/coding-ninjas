#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *midPointLL(Node *head)
{
    if (!(head && head->next))
        return head;
    Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *mergeSortedLL(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;
    
    if (head1->data < head2->data)
    {
        head1->next = mergeSortedLL(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = mergeSortedLL(head1, head2->next);
        return head2;
    }
}

Node *mergeSortLL(Node *head1)
{
    if (!(head1 && head1->next))
        return head1;
    
    Node *mid = midPointLL(head1);
    Node *head2 = mid->next;
    mid->next = nullptr;
    head1 = mergeSortLL(head1);
    head2 = mergeSortLL(head2);
    Node *head = mergeSortedLL(head1, head2);
    return head;
}

int main()
{
    int t;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        head = mergeSortLL(head);
        printLL(head);
    }
    return 0;
}