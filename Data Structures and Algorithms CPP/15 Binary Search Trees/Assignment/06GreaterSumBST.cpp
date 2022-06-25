#include <iostream>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
void greaterSumBST(BSTNode<T> *root)
{
    if (!root)
        return;
    static int sum = 0;
    greaterSumBST(root->right);
    sum += root->data;
    root->data = sum;
    greaterSumBST(root->left);
}

int main()
{
    BSTNode<int> *root = takeInputLW();
    greaterSumBST(root);
    levelOrderPrint(root);
    delete root;
    return 0;
}