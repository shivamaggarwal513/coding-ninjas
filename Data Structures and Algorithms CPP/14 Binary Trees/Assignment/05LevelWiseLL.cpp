#include <iostream>
#include <vector>
#include <queue>
#include "..\01BinaryTrees.h"
using namespace std;

template <typename T>
class ListNode
{
public:
    T data;
    ListNode* next;

    ListNode() {}
    
    ListNode(T data)
    {
        this->data = data;
        next = nullptr;
    }

    ~ListNode()
    {
        delete next;
    }
};

template <typename T>
vector<ListNode<T> *> levelWiseLL(BinaryTreeNode<T> *root)
{
    if (!root)
        return {};
    vector<ListNode<T> *> listHeads;
    ListNode<T> *levelHead = nullptr, *levelTail;
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
            levelHead = nullptr;
            q.push(nullptr);
            continue;
        }
        if (!levelHead)
        {
            levelHead = new ListNode<int>(curr->data);
            levelTail = levelHead;
            listHeads.push_back(levelHead);
        }
        else
        {
            levelTail->next = new ListNode<int>(curr->data);
            levelTail = levelTail->next;
        }
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return listHeads;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLW();
    vector<ListNode<int> *> listHeads = levelWiseLL(root);
    ListNode<int> *temp;
    for (int i = 0; i < listHeads.size(); i++)
    {
        temp = listHeads[i];
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
        delete listHeads[i];
    }
    delete root;
    return 0;
}