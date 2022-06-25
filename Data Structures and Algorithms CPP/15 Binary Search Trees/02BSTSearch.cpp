#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    int x;
    BSTNode<int> *root = takeInputLW();
    cin >> x;
    cout << (BSTSearch(root, x) ? "true" : "false") << "\n";
    delete root;
    return 0;
}