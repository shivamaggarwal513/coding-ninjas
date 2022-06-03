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

int main()
{
    int t;
    Node *head, *mid;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        mid = midPointLL(head);
        if (mid)
            cout << mid->data;
        cout << "\n";
    }
    return 0;
}