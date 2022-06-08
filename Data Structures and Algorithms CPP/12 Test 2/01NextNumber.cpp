#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

Node *nextNumber(Node *head)
{
    int sum, carry = 1;
    Node *temp, *curTail = nullptr;
    while (head != curTail)
    {
        temp = head;
        while (temp->next != curTail)
            temp = temp->next;
        sum = temp->data + carry;
        carry = sum / 10;
        temp->data = sum % 10;
        if (!carry)
            break;
        curTail = temp;
    }
    if (carry)
    {
        Node *newHead = new Node(1);
        newHead->next = head;
        head = newHead;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    head = nextNumber(head);
    printLL(head);
    return 0;
}