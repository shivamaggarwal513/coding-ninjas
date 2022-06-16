#include <iostream>
#include "..\02Trees.h"
using namespace std;

template <typename T>
class TreeNodePair
{
public:
    TreeNode<T> *first;
    TreeNode<T> *second;

    TreeNodePair() { first = second = nullptr; }
    TreeNodePair(TreeNode<T> *first, TreeNode<T> *second) : first(first), second(second) {}
    void operator=(const TreeNodePair &pair)
    {
        first = pair.first;
        second = pair.second;
    }
};

template<typename T>
TreeNodePair<T> secondLargest(TreeNode<T> *root)
{
    if (!root || root->children.empty())
        return TreeNodePair<T>(root, nullptr);
    TreeNodePair<T> FSPair(root, nullptr), FSPairRec;
    TreeNode<T> *temp;
    for (int i = 0; i < root->children.size(); i++)
    {
        FSPairRec = secondLargest(root->children[i]);
        if ((FSPair.first->data > FSPairRec.first->data) && 
            (!FSPair.second || (FSPair.second->data < FSPairRec.first->data)))
            FSPair.second = FSPairRec.first;
        else if (FSPair.first->data < FSPairRec.first->data)
        {
            temp = FSPair.first;
            FSPair.first = FSPairRec.first;
            FSPair.second = FSPairRec.second ? (temp->data > FSPairRec.second->data ? temp : FSPairRec.second) : temp;
        }
        else if (FSPairRec.second)
            FSPair.second = FSPair.second ? (FSPair.second->data > FSPairRec.second->data ? FSPair.second : FSPairRec.second) : FSPairRec.second;
    }
    return FSPair;
}

int main()
{
    TreeNode<int> *root = takeInputLW<int>();
    TreeNodePair<int> ans = secondLargest(root);
    if (ans.second)
        cout << ans.second->data << "\n";
    delete root;
    return 0;
}