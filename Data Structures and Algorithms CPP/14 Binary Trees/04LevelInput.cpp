#include <iostream>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    printTreeRec(root);
    delete root;
    return 0;
}