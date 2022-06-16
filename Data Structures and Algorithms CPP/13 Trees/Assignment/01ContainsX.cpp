#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
bool containsX(TreeNode<T> *root, T x)
{
    if (!root)
        return false;
    if (root->data == x)
        return true;
    for (int i = 0; i < root->children.size(); i++)
        if (containsX(root->children[i], x))
            return true;
    return false;
}

int main()
{
    int x;
    TreeNode<int> *root = takeInputLW<int>();
    cin >> x;
    cout << (containsX(root, x) ? "true" : "false") << "\n";
    delete root;
    return 0;
}