#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

void deleteAlternateLL(Node *head)
{
    Node *temp = head, *toDel;
    while (temp && temp->next)
    {
        toDel = temp->next;
        temp->next = temp->next->next;
        delete toDel;
        temp = temp->next;
    }
}

int main()
{
    Node *head = takeInput();
    deleteAlternateLL(head);
    printLL(head);
    return 0;
}