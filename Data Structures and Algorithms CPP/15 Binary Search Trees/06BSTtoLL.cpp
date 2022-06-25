#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    BSTNode<int> *root = takeInputLW();
    ListNode<int> *head = BSTtoLL(root).first;
    printLL(head);
    delete head;
    delete root;
    return 0;
}