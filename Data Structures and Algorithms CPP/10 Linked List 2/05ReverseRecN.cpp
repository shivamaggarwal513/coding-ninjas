#include <iostream>
#include "..\09 Linked List 1\01LinkedList.h"
using namespace std;

class NodePair
{
public:
    Node *head;
    Node *tail;

    NodePair() { head = tail = nullptr; }
    NodePair(Node *head, Node *tail) : head(head), tail(tail) {}
    void operator=(const NodePair &pair)
    {
        head = pair.head;
        tail = pair.tail;
    }
};

NodePair reverseLLRecN(Node *head)
{
    if (!(head && head->next))
        return NodePair(head, head);
    NodePair newPair = reverseLLRecN(head->next);
    newPair.tail->next = head;
    head->next = nullptr;
    return NodePair(newPair.head, head);
}

int main()
{
    int t;
    NodePair HTpair;
    cin >> t;
    while (t--)
    {
        HTpair.head = takeInput();
        HTpair = reverseLLRecN(HTpair.head);
        printLL(HTpair.head);
    }
    return 0;
}