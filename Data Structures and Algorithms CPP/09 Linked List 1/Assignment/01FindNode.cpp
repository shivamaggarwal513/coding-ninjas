#include <iostream>
#include "..\01LinkedList.h"
using namespace std;

int searchLL(Node *head, int x)
{
    int index = 0;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == x)
            return index;
        index++;
        temp = temp->next;
    }
    return -1;
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
        cout << searchLL(head, n) << "\n";
    }
    return 0;
}