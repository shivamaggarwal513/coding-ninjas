#include <iostream>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
void printAtLevelK(BSTNode<T> *root, int k)
{
    if (!root || k < 0)
        return;
    if (!k)
    {
        cout << root->data << "\n";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
}

template <typename T>
int printNodesAtK(BSTNode<T> *root, T n, int k)
{
    if (!root)
        return -1;
    
    if (root->data == n)
    {
        printAtLevelK(root, k);
        return 0;
    }

    int leftDistance = printNodesAtK(root->left, n, k);
    if (leftDistance != -1)
    {
        if (leftDistance + 1 == k)
            cout << root->data << "\n";
        else
            printAtLevelK(root->right, k - leftDistance - 2);
        return leftDistance + 1;
    }

    int rightDistance = printNodesAtK(root->right, n, k);
    if (rightDistance != -1)
    {
        if (rightDistance + 1 == k)
            cout << root->data << "\n";
        else
            printAtLevelK(root->left, k - rightDistance - 2);
        return rightDistance + 1;
    }

    return -1;
}

int main()
{
    int n, k;
    BSTNode<int> *root = takeInputLW();
    cin >> n >> k;
    printNodesAtK(root, n, k);
    delete root;
    return 0;
}