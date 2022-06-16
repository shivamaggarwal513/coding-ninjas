#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
TreeNode<T> *maxChildSum(TreeNode<T> *root, T sum = 0)
{
    if (!root)
        return nullptr;
    T maxSum = root->data, subMaxSum;
    TreeNode<T> *max = root, *subMax;
    for (int i = 0; i < root->children.size(); i++)
        maxSum += root->children[i]->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        subMax = maxChildSum(root->children[i]);
        subMaxSum = subMax->data;
        for (int j = 0; j < subMax->children.size(); j++)
            subMaxSum += subMax->children[j]->data;
        if (subMaxSum > maxSum)
        {
            maxSum = subMaxSum;
            max = root->children[i];
        }
    }
    return max;
}

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    cout << maxChildSum(root)->data << "\n";
    delete root;
    return 0;
}