#include <iostream>
#include <queue>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
void levelOrderPrint(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    BinaryTreeNode<T> *curr;
    queue<BinaryTreeNode<T> *> q;
    q.push(root);
    q.push(nullptr);
    while (q.size() != 1)
    {
        curr = q.front();
        q.pop();
        if (!curr)
        {
            cout << "\n";
            q.push(nullptr);
            continue;
        }
        cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    levelOrderPrint(root);
    delete root;
    return 0;
}