#include <iostream>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
void nodesWithoutSiblings(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    if (!root->left && root->right)
        cout << root->right->data << " ";
    else if(root->left && !root->right)
        cout << root->left->data << " ";
    nodesWithoutSiblings(root->left);
    nodesWithoutSiblings(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    nodesWithoutSiblings(root);
    delete root;
    return 0;
}