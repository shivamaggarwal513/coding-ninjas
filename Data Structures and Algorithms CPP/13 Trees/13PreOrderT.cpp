#include <iostream>
#include "02Trees.h"
using namespace std;

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    preOrderPrint(root);
    cout << "\n";
    delete root;
    return 0;
}