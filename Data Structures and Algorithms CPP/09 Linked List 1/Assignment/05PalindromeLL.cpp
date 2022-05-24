#include <iostream>
#include "..\01LinkedList.h"
using namespace std;

bool isPalindromeLL(Node *head)
{
    if (!(head && head->next))
        return true;
    int size = lengthLL(head), i = 0;
    int *arr = new int[size / 2];
    Node *temp = head;
    while (i < size / 2)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    while (temp)
    {
        if (temp->data != arr[--i])
        {
            delete []arr;
            return false;
        }
        temp = temp->next;
    }
    delete []arr;
    return true;
}

int main()
{
    int t;
    Node *head;
    cin >> t;
    while (t--)
    {
        head = takeInput();
        cout << (isPalindromeLL(head) ? "true" : "false") << "\n";
    }
    return 0;
}