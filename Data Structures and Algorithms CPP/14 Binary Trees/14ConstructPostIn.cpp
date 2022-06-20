#include <iostream>
#include "01BinaryTrees.h"
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int *postArr = new int[n];
    int *inArr = new int[n];
    for (i = 0; i < n; i++)
        cin >> postArr[i];
    for (i = 0; i < n; i++)
        cin >> inArr[i];
    BinaryTreeNode<int> *root = constructTreePostIn(postArr, inArr, n);
    printTreeLW(root);
    delete []postArr;
    delete []inArr;
    delete root;
    return 0;
}