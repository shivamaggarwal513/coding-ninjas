#include <iostream>
#include "01BSTrees.h"
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    BSTNode<int> *root = constructBST(arr, n);
    preOrderPrint(root);
    delete []arr;
    delete root;
    return 0;
}