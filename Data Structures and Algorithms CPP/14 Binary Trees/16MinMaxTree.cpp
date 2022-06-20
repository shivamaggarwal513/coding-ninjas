#include <iostream>
#include <utility>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    pair<BinaryTreeNode<int> *, BinaryTreeNode<int> *> minMax = minMaxTree(root);
    cout << minMax.first->data << " " << minMax.second->data << "\n";
    delete root;
    return 0;
}