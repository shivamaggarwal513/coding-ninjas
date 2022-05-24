#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    int t, i, data;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        cin >> i;
        data = ithNode(head, i);
        if (data != -1)
            cout << data;
        cout << "\n";
    }
    return 0;
}