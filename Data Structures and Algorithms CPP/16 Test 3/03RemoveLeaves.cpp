#include <iostream>
#include "..\13 Trees\02Trees.h"
using namespace std;

template <typename T>
TreeNode<T> *removeLeafNodes(TreeNode<T> *root)
{
    if (!root)
        return nullptr;
    if (!root->children.size())
    {
        delete root;
        return nullptr;
    }
    for (int i = 0; i < root->children.size(); i++)
        root->children[i] = removeLeafNodes(root->children[i]);
    int i = 0, j = 0;
    while (j < root->children.size())
    {
        if (root->children[j])
            root->children[i++] = root->children[j++];
        else
            j++;
    }
    root->children.resize(i);
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    root = removeLeafNodes(root);
    printTreeLW(root);
    delete root;
    return 0;
}