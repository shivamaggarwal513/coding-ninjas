#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
void replaceWithDepth(TreeNode<T> *root, int rootDepth = 0)
{
    if (!root)
        return;
    root->data = rootDepth;
    for (int i = 0; i < root->children.size(); i++)
        replaceWithDepth(root->children[i], rootDepth + 1);
}

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    replaceWithDepth(root);
    printTreeLW(root);
    delete root;
    return 0;
}