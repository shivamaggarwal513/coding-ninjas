#include <iostream>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(3);
    delete root;
    return 0;
}