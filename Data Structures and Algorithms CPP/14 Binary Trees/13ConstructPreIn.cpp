#include <iostream>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int *preArr = new int[n];
    int *inArr = new int[n];
    for (i = 0; i < n; i++)
        cin >> preArr[i];
    for (i = 0; i < n; i++)
        cin >> inArr[i];
    BinaryTreeNode<int> *root = constructTreePreIn(preArr, inArr, n);
    printTreeLW(root);
    delete []preArr;
    delete []inArr;
    delete root;
    return 0;
}