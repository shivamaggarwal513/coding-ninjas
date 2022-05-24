#include <iostream>
#include "..\01LinkedList.h"
using namespace std;

Node *appendLtoF(Node *head, int n)
{
    if (n == 0)
        return head;
    int size = lengthLL(head);
    int i = 0;
    Node *temp = head;
    while (i < size - n - 1)
    {
        temp = temp->next;
        i++;
    }
    Node *newTail = temp, *newHead = temp->next;
    while (temp->next)
        temp = temp->next;
    newTail->next = nullptr;
    temp->next = head;
    return newHead;
}

int main()
{
    int t, n;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        cin >> n;
        head = appendLtoF(head, n);
        printLL(head);
    }
    return 0;
}