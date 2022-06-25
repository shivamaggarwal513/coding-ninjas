#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    int k;
    BSTNode<int> *root = takeInputLW();
    cin >> k;
    vector<int> *ans = findPathinBinaryTree(root, k);
    if (ans)
        for (int &n: *ans)
            cout << n << " ";
    cout << "\n";
    delete ans;
    delete root;
    return 0;
}