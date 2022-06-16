#include <iostream>
#include "02Trees.h"
using namespace std;

int main()
{
    TreeNode<int> *root = takeInputRec<int>();
    printTreeRec(root);
    delete root;
    return 0;
}