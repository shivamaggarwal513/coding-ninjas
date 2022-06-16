#include <iostream>
#include "02Trees.h"
using namespace std;

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    printTreeLW(root);
    delete root;
    return 0;
}