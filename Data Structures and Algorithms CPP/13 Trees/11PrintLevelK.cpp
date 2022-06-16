#include <iostream>
#include "02Trees.h"
using namespace std;

int main()
{
    int k;
    TreeNode<int> *root = takeInputLW<int>();
    cin >> k;
    printAtLevelK(root, k);
    cout << "\n";
    delete root;
    return 0;
}