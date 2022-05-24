#include <iostream>
#include "..\01LinkedList.h"
using namespace std;

Node *deleteDup(Node *head)
{
    if (!(head && head->next))
        return head;
    
    head->next = deleteDup(head->next);

    if (head->data == head->next->data)
    {
        Node *toDel = head->next;
        head->next = head->next->next;
        delete toDel;
    }
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
        head = deleteDup(head);
        printLL(head);
    }
    return 0;
}