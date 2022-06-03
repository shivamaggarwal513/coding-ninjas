#include <iostream>
#include "..\..\09 Linked List 1\01LinkedList.h"
using namespace std;

void swapNodes(Node *prevN, Node *currN, Node *nextN)
{
    if (prevN)
        prevN->next = nextN;
    currN->next = nextN->next;
    nextN->next = currN;
}

Node *bubbleSortLL(Node *head)
{
    if (!head)
        return nullptr;
    
    Node *temp, *prevN = nullptr, *subTail = nullptr;
    while (head->next != subTail)
    {
        temp = head;
        prevN = nullptr;
        while (temp->next != subTail)
        {
            if (temp->data > temp->next->data)
            {
                if (temp == head)
                    head = temp->next;
                swapNodes(prevN, temp, temp->next);
            }
            else
                temp = temp->next;
            prevN = prevN ? prevN->next : head;
        }
        subTail = temp;
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
        head = bubbleSortLL(head);
        printLL(head);
    }
    return 0;
}