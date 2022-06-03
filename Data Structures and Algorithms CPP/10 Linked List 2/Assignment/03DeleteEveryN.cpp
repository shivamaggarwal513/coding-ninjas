#include <iostream>
#include "..\..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *deleteNafterM(Node *head, int m, int n)
{
    if (!n)
        return head;
    
    Node *temp = head, *tail = head, *toDel;
    int im, in;
    while (temp)
    {
        im = in = 0;
        while (temp && im < m)
        {
            tail = temp;
            temp = temp->next;
            im++;
        }
        while (temp && in < n)
        {
            toDel = temp;
            temp = temp->next;
            delete toDel;
            in++;
        }
        if (m)
            tail->next = temp;
        else
            head = tail = temp;
    }
    return head;
}

int main()
{
    int t, m, n;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        cin >> m >> n;
        head = deleteNafterM(head, m, n);
        printLL(head);
    }
    return 0;
}