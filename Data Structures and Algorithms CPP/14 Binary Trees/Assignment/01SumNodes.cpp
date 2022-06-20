#include <iostream>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
int sumNodes(BinaryTreeNode<T> *root)
{
    if (!root)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    cout << sumNodes(root) << "\n";
    delete root;
    return 0;
}