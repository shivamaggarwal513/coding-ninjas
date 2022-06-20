#include <iostream>
#include <utility>
#include <cmath>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
pair<bool, int> isBalanced(BinaryTreeNode<T> *root)
{
    if (!root)
        return make_pair(true, 0);
    pair<bool, int> leftISB = isBalanced(root->left), rightISB = isBalanced(root->right);
    return make_pair(leftISB.first && rightISB.first && abs(leftISB.second - rightISB.second) <= 1, 
                    max(leftISB.second, rightISB.second) + 1);
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    cout << (isBalanced(root).first ? "true" : "false") << "\n";
    delete root;
    return 0;
}