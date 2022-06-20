#include <iostream>
#include <deque>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
void printZigZag(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    int currLevel = 1;
    BinaryTreeNode<T> *curr;
    deque<BinaryTreeNode<T> *> dq;
    dq.push_back(root);
    dq.push_back(nullptr);
    while (dq.size() != 1)
    {
        curr = currLevel & 1 ? dq.front() : dq.back();

        if (curr)
            currLevel & 1 ? dq.pop_front() : dq.pop_back();
        else
        {
            cout << "\n";
            currLevel++;
            continue;
        }
        
        cout << curr->data << " ";
        
        if (currLevel & 1)
        {
            if (curr->left)
                dq.push_back(curr->left);
            if (curr->right)
                dq.push_back(curr->right);
        }
        else
        {
            if (curr->right)
                dq.push_front(curr->right);
            if (curr->left)
                dq.push_front(curr->left);
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    printZigZag(root);
    delete root;
    return 0;
}