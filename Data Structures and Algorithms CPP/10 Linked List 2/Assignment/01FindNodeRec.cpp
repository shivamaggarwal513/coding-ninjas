#include <iostream>
#include "..\..\09 Linked List 1\01LinkedList.h"
using namespace std;

int searchLLRec(Node *head, int x)
{
    if (!head)
        return -1;
    if (head->data == x)
        return 0;
    
    int idx = searchLLRec(head->next, x);
    return (idx == -1) ? -1 : 1 + idx;
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
        cout << searchLLRec(head, n) << "\n";
    }
    return 0;
}