#include <iostream>
#include <vector>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
void pathSumRootToLeaf(BSTNode<T> *root, T k, vector<T> ans = {})
{
    if (!root)
        return;
    ans.push_back(root->data);
    if (!root->left && !root->right)
    {
        if (k == root->data)
        {
            for (T &a: ans)
                cout << a << " ";
            cout << "\n";
        }
        return;
    }
    pathSumRootToLeaf(root->left, k - root->data, ans);
    pathSumRootToLeaf(root->right, k - root->data, ans);
}

int main()
{
    int k;
    BSTNode<int> *root = takeInputLW();
    cin >> k;
    pathSumRootToLeaf(root, k);
    delete root;
    return 0;
}