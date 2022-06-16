#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
bool isIdentical(TreeNode<T> *root1, TreeNode<T> *root2)
{
    if (!root1 || !root2)
        return root1 == root2;
    if ((root1->children.size() != root2->children.size()) || (root1->data != root2->data))
        return false;
    for (int i = 0; i < root1->children.size(); i++)
        if (!isIdentical(root1->children[i], root2->children[i]))
            return false;
    return true;
}

int main()
{
    TreeNode<int> *root1 = takeInputLW<int>();
    TreeNode<int> *root2 = takeInputLW<int>();
    cout << (isIdentical(root1, root2) ? "true" : "false") << "\n";
    delete root1;
    delete root2;
    return 0;
}