#include <iostream>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    int x;
    BinaryTreeNode<int> *root = takeInputLW();
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false") << "\n";
    delete root;
    return 0;
}