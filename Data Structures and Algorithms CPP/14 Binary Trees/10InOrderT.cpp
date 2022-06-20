#include <iostream>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    inOrderPrint(root);
    cout << "\n";
    delete root;
    return 0;
}