#include <iostream>
#include <vector>
#include "..\14 Binary Trees\01BinaryTrees.h"
using namespace std;

template <typename T>
vector<T> *longestLeafToRoot(BinaryTreeNode<T> *root)
{
    if (!root)
        return new vector<T>;
    vector<T> *leftPath = longestLeafToRoot(root->left), *rightPath = longestLeafToRoot(root->right);
    if (leftPath->size() > rightPath->size())
    {
        leftPath->push_back(root->data);
        return leftPath;
    }
    else
    {
        rightPath->push_back(root->data);
        return rightPath;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    vector<int> *ans = longestLeafToRoot(root);
    for (int &n: *ans)
        cout << n << " ";
    cout << "\n";
    delete ans;
    delete root;
    return 0;
}