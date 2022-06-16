#include <iostream>
#include "02Trees.h"
using namespace std;

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    cout << heightTree(root) << "\n";
    delete root;
    return 0;
}