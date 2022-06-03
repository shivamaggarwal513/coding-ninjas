#include <iostream>
#include "..\..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *swapItoJ(Node *head, int i, int j)
{
    int ij = 0;
    Node *iN1 = head, *jN1 = head;
    while (iN1 && jN1 && ij < j - 1)
    {
        if (ij < i - 1)
            iN1 = iN1->next;
        jN1 = jN1->next;
        ij++;
    }

    Node *iN2 = i ? iN1->next : iN1, *jN2 = jN1->next;
    Node *tjN3 = jN2->next;
    
    if (i)
        iN1->next = jN2;
    jN2->next = (j - i == 1) ? iN2 : iN2->next;
    if (j - i > 1)
        jN1->next = iN2;
    iN2->next = tjN3;
    return i ? head : jN2;
}

int main()
{
    int t, i, j;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        cin >> i >> j;
        head = swapItoJ(head, i, j);
        printLL(head);
    }
    return 0;
}