#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    BSTree<int> *bst = new BSTree<int>;
    bst->insertNode(4);
    bst->insertNode(1);
    bst->insertNode(2);
    bst->insertNode(7);
    bst->insertNode(5);
    bst->insertNode(6);
    bst->insertNode(3);
    bst->insertNode(8);

    bst->printBST();

    cout << (bst->hasNode(5) ? "true" : "false") << "\n";
    cout << (bst->hasNode(9) ? "true" : "false") << "\n";

    bst->deleteNode(1);
    bst->printBST();

    bst->deleteNode(7);
    bst->printBST();

    delete bst;
    return 0;
}