#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    int t, idx;
    cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        cin >> idx;
        head = deleteNode(head, idx);
        printLL(head);
    }
    return 0;
}