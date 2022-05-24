#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    Node *head = takeInput();
    int idx, x;
    cin >> idx >> x;
    cout << "Before insertion: ";
    printLL(head);
    head = insertNode(head, idx, x);
    cout << "After insertion: ";
    printLL(head);
    return 0;
}