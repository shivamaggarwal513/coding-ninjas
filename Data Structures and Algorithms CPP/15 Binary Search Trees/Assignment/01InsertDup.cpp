#include <iostream>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
void insertDuplicateNodes(BSTNode<T> *root)
{
    if (!root)
        return;
    BSTNode<T> *newNode = new BSTNode<T>(root->data, root->left, nullptr);
    root->left = newNode;
    insertDuplicateNodes(newNode->left);
    insertDuplicateNodes(root->right);
}

int main()
{
    BSTNode<int> *root = takeInputLW();
    insertDuplicateNodes(root);
    levelOrderPrint(root);
    delete root;
    return 0;
}