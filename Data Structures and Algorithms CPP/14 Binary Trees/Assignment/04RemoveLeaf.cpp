#include <iostream>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
BinaryTreeNode<T> *removeLeafNodes(BinaryTreeNode<T> *root)
{
    if (!root || (!root->left && !root->right))
    {
        delete root;
        return nullptr;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    root = removeLeafNodes(root);
    printTreeLW(root);
    delete root;
    return 0;
}