#include <iostream>
#include <stack>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
void minimumPush(BSTNode<T> *root, stack<BSTNode<T> *> &s)
{
    while (root)
    {
        s.push(root);
        root = root->left;
    }
}

template <typename T>
void maximumPush(BSTNode<T> *root, stack<BSTNode<T> *> &s)
{
    while (root)
    {
        s.push(root);
        root = root->right;
    }
}

template <typename T>
void pairSumBST(BSTNode<T> *root, T s)
{
    if (!root)
        return;
    
    stack<BSTNode<T> *> s1, s2;
    BSTNode<T> *s1top, *s2top;
    int scanned = 0, n = numNodes(root) - 1;
    T currSum;

    minimumPush(root, s1);
    maximumPush(root, s2);

    while (scanned < n)
    {
        s1top = s1.top(); s2top = s2.top();
        currSum = s1top->data + s2top->data;
        
        if (currSum == s)
        {
            cout << s1top->data << " " << s2top->data << "\n";
            s1.pop(); s2.pop();
            minimumPush(s1top->right, s1);
            maximumPush(s2top->left, s2);
            scanned++;
        }
        else if (currSum < s)
        {
            s1.pop();
            minimumPush(s1top->right, s1);
        }
        else
        {
            s2.pop();
            maximumPush(s2top->left, s2);
        }
        scanned++;
    }
}

int main()
{
    int s;
    BSTNode<int> *root = takeInputLW();
    cin >> s;
    pairSumBST(root, s);
    delete root;
    return 0;
}