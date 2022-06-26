#include <iostream>
#include <utility>
#include "..\14 Binary Trees\01BinaryTrees.h"
using namespace std;

template <typename T>
pair<int, BinaryTreeNode<T> *> getDepthParent(BinaryTreeNode<T> *root, T n)
{
    if (!root)
        return make_pair(-1, nullptr);
    if ((root->left && root->left->data == n) ||
        (root->right && root->right->data == n))
        return make_pair(1, root);
    pair<int, BinaryTreeNode<T> *> leftAns = getDepthParent(root->left, n);
    if (leftAns.second)
        return make_pair(leftAns.first + 1, leftAns.second);
    pair<int, BinaryTreeNode<T> *> rightAns = getDepthParent(root->right, n);
    if (rightAns.second)
        return make_pair(rightAns.first + 1, rightAns.second);
    return make_pair(-1, nullptr);
}

template <typename T>
bool checkCousins(BinaryTreeNode<T> *root, T n1, T n2)
{
    pair<int, BinaryTreeNode<T> *> ans1 = getDepthParent(root, n1), ans2 = getDepthParent(root, n2);
    if (ans1.first == ans2.first && ans1.second != ans2.second)
        return true;
    return false;
}

int main()
{
    int n1, n2;
    BinaryTreeNode<int> *root = takeInputLW();
    cin >> n1 >> n2;
    cout << (checkCousins(root, n1, n2) ? "true" : "false") << "\n";
    delete root;
    return 0;
}