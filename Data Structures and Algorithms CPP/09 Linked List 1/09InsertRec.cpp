#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    int idx, x;
    Node *head = takeInput();
    cin >> idx >> x;
    head = insertNodeRec(head, idx, x);
    printLL(head);
    return 0;
}