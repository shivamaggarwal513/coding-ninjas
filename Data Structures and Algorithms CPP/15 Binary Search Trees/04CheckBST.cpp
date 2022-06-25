#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    BSTNode<int> *root = takeInputLW();
    cout << (checkBST1(root) ? "true" : "false") << "\n";
    cout << (checkBST2(root).isBST ? "true" : "false") << "\n";
    cout << (checkBST3(root) ? "true" : "false") << "\n";
    delete root;
    return 0;
}