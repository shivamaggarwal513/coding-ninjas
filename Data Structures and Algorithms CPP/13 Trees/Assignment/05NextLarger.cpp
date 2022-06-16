#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
TreeNode<T> *nextLarger(TreeNode<T> *root, T n)
{
    if (!root)
        return nullptr;
    TreeNode<T> *larger = (root->data > n) ? root : nullptr, *subLarger;
    for (int i = 0; i < root->children.size(); i++)
    {
        subLarger = nextLarger(root->children[i], n);
        if (subLarger && (!larger || larger->data > subLarger->data))
            larger = subLarger;
    }
    return larger;
}

int main()
{
    int n;
    TreeNode<int> *root = takeInputLW<int>();
    cin >> n;
    TreeNode<int> *ans = nextLarger(root, n);
    if (ans)
        cout << ans->data << "\n";
    delete root;
    return 0;
}