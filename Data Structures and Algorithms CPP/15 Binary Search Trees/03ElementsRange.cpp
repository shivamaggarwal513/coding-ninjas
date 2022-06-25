#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    int k1, k2;
    BSTNode<int> *root = takeInputLW();
    cin >> k1 >> k2;
    printElementsInRange(root, k1, k2);
    cout << "\n";
    delete root;
    return 0;
}