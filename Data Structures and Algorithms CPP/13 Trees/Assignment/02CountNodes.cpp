#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
int countNodes(TreeNode<T> *root, T x)
{
    if (!root)
        return 0;
    int ans = 0;
    if (root->data > x)
        ans++;
    for (int i = 0; i < root->children.size(); i++)
        ans += countNodes(root->children[i], x);
    return ans;
}

int main()
{
    int x;
    TreeNode<int> *root = takeInputLW<int>();
    cin >> x;
    cout << countNodes(root, x) << "\n";
    delete root;
    return 0;
}