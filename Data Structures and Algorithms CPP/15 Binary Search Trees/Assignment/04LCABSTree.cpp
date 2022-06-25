#include <iostream>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
T LCABSTree(BSTNode<T> *root, T n1, T n2)
{
    if (!root)
        return -1;
    if (root->data == n1 || root->data == n2)
        return root->data;
    else if (n1 < root->data && n2 < root->data)
        return LCABSTree(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2)
        return LCABSTree(root->right, n1, n2);
    else
    {
        T leftLCA = LCABSTree(root->left, n1, n2), rightLCA = LCABSTree(root->right, n1, n2);
        if (leftLCA == -1 || rightLCA == -1)
            return leftLCA == -1 ? rightLCA : leftLCA;
        return root->data;
    }
}

int main()
{
    int n1, n2;
    BSTNode<int> *root = takeInputLW();
    cin >> n1 >> n2;
    cout << LCABSTree(root, n1, n2) << "\n";
    delete root;
    return 0;
}