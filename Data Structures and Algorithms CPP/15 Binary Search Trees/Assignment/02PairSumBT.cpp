#include <iostream>
#include <algorithm>
#include <vector>
#include "..\01BSTrees.h"
using namespace std;

template <typename T>
void BinaryTreetoArray(BSTNode<T> *root, vector<T> &arr)
{
    if (!root)
        return;
    arr.push_back(root->data);
    BinaryTreetoArray(root->left, arr);
    BinaryTreetoArray(root->right, arr);
}

template <typename T>
void pairSumBinaryTree(BSTNode<T> *root, T s)
{
    if (!root)
        return;
    vector<int> arr;
    BinaryTreetoArray(root, arr);
    sort(arr.begin(), arr.end());
    int currSum, i = 0, j = arr.size() - 1;
    while (i < j)
    {
        currSum = arr[i] + arr[j];
        if (currSum == s)
            cout << arr[i++] << " " << arr[j--] << "\n";
        else if (currSum < s)
            i++;
        else
            j--;
    }
}

int main()
{
    int s;
    BSTNode<int> *root = takeInputLW();
    cin >> s;
    pairSumBinaryTree(root, s);
    delete root;
    return 0;
}