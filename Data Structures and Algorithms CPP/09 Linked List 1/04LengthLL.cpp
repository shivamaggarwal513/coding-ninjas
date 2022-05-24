#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        Node *head = takeInput();
        cout << lengthLL(head) << "\n";
    }
    return 0;
}