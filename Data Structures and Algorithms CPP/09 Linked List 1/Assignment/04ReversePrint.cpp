#include <iostream>
#include "..\01LinkedList.h"
using namespace std;

void printRev(Node *head)
{
    if (!head)
        return;
    printRev(head->next);
    cout << head->data << " ";
}

int main()
{
    int t;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        printRev(head);
        cout << "\n";
    }
    return 0;
}