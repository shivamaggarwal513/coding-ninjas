#include <iostream>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
T LCABinaryTree(BSTNode<T> *root, T n1, T n2)
{
    if (!root)
        return -1;
    if (root->data == n1 || root->data == n2)
        return root->data;
    T leftLCA = LCABinaryTree(root->left, n1, n2), rightLCA = LCABinaryTree(root->right, n1, n2);
    if (leftLCA == -1 || rightLCA == -1)
        return leftLCA == -1 ? rightLCA : leftLCA;
    return root->data;
}

int main()
{
    int n1, n2;
    BSTNode<int> *root = takeInputLW();
    cin >> n1 >> n2;
    cout << LCABinaryTree(root, n1, n2) << "\n";
    delete root;
    return 0;
}