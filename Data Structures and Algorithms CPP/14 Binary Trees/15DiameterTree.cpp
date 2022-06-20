#include <iostream>
#include <utility>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    cout << diameterTree(root) << "\n";
    cout << heightDiameterTree(root).second << "\n";
    delete root;
    return 0;
}