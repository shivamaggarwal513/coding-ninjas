#include <iostream>
#include "01LinkedList.h"
using namespace std;

int main()
{
    Node *head = takeInput();
    cout << lengthLLRec(head) << "\n";
    return 0;
}