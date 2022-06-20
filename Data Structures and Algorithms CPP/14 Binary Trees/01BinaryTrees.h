#include <iostream>
#include <cmath>
#include <queue>
#include <utility>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode()
    {
        left = right = nullptr;
    }

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};


template <typename T>
void printTreeRec(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    std::cout << root->data << ": ";
    if (root->left)
        std::cout << "L" << root->left->data << " ";
    if (root->right)
        std::cout << "R" << root->right->data;
    std::cout << "\n";
    printTreeRec(root->left);
    printTreeRec(root->right);
}

BinaryTreeNode<int> *takeInputRec()
{
    int data;
    std::cin >> data;
    if (data == -1)
        return nullptr;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    root->left = takeInputRec();
    root->right = takeInputRec();
    return root;
}

BinaryTreeNode<int> *takeInputLW()
{
    int data;
    // std::cout << "Enter data: ";
    std::cin >> data;
    if (data == -1)
        return nullptr;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data), *subRoot;
    std::queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        subRoot = q.front();
        q.pop();
        // std::cout << "Enter left child of " << subRoot->data << ": ";
        std::cin >> data;
        if (data != -1)
        {
            subRoot->left = new BinaryTreeNode<int>(data);
            q.push(subRoot->left);
        }
        // std::cout << "Enter right child of " << subRoot->data << ": ";
        std::cin >> data;
        if (data != -1)
        {
            subRoot->right = new BinaryTreeNode<int>(data);
            q.push(subRoot->right);
        }
    }
    return root;
}

template<typename T>
void printTreeLW(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    std::queue<BinaryTreeNode<T> *> q;
    BinaryTreeNode<T> *temp;
    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        std::cout << temp->data << ":";
        if (temp->left)
        {
            std::cout << "L:" << temp->left->data << ",";
            q.push(temp->left);
        }
        else
            std::cout << "L:-1,";
        if (temp->right)
        {
            std::cout << "R:" << temp->right->data << "\n";
            q.push(temp->right);
        }
        else
            std::cout << "R:-1\n";
    }
}

template <typename T>
int numNodes(BinaryTreeNode<T> *root)
{
    if (!root)
        return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

template <typename T>
bool isPresent(BinaryTreeNode<T> *root, T x)
{
    if (!root)
        return false;
    if (root->data == x)
        return true;
    return isPresent(root->left, x) || isPresent(root->right, x);
}

template <typename T>
int heightTree(BinaryTreeNode<T> *root)
{
    if (!root)
        return 0;
    return 1 + std::max(heightTree(root->left), heightTree(root->right));
}

template <typename T>
void mirrorBinaryTree(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    std::swap(root->left, root->right);
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

template <typename T>
void inOrderPrint(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    inOrderPrint(root->left);
    std::cout << root->data << " ";
    inOrderPrint(root->right);
}

template <typename T>
void preOrderPrint(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    std::cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

template <typename T>
void postOrderPrint(BinaryTreeNode<T> *root)
{
    if (!root)
        return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    std::cout << root->data << " ";
}

template <typename T>
BinaryTreeNode<T> *constructTreePreIn(T *preArr, T *inArr, int n)
{
    if (!n)
        return nullptr;
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(preArr[0]);
    int i; for (i = 0; i < n && inArr[i] != preArr[0]; i++);
    root->left = constructTreePreIn(preArr + 1, inArr, i);
    root->right = constructTreePreIn(preArr + i + 1, inArr + i + 1, n - i - 1);
    return root;
}

template <typename T>
BinaryTreeNode<T> *constructTreePostIn(T *postArr, T *inArr, int n)
{
    if (!n)
        return nullptr;
    BinaryTreeNode<T> *root = new BinaryTreeNode<T>(postArr[n - 1]);
    int i; for (i = 0; i < n && inArr[i] != postArr[n - 1]; i++);
    root->left = constructTreePostIn(postArr, inArr, i);
    root->right = constructTreePostIn(postArr + i, inArr + i + 1, n - i - 1);
    return root;
}

template <typename T>
int diameterTree(BinaryTreeNode<T> *root)
{
    if (!root)
        return 0;
    return std::max(heightTree(root->left) + heightTree(root->right), 
                    std::max(diameterTree(root->left), diameterTree(root->right)));
}

template <typename T>
std::pair<int, int> heightDiameterTree(BinaryTreeNode<T> *root)
{
    if (!root)
        return std::make_pair(0, 0);
    std::pair<int, int> leftHD = heightDiameterTree(root->left), rightHD = heightDiameterTree(root->right);
    return std::make_pair(std::max(leftHD.first, rightHD.first) + 1, 
                        std::max(leftHD.first + rightHD.first, std::max(leftHD.second, rightHD.second)));
}

template <typename T>
std::pair<BinaryTreeNode<T> *, BinaryTreeNode<T> *> minMaxTree(BinaryTreeNode<T> *root)
{
    if (!root)
        return std::make_pair(nullptr, nullptr);
    if (!root->left && !root->right)
        return std::make_pair(root, root);
    std::pair<BinaryTreeNode<T> *, BinaryTreeNode<T> *> leftMinMax = minMaxTree(root->left), rightMinMax = minMaxTree(root->right);
    BinaryTreeNode<T> *minTree = root, *maxTree = root;
    if (leftMinMax.first && leftMinMax.first->data < minTree->data)
        minTree = leftMinMax.first;
    if (rightMinMax.first && rightMinMax.first->data < minTree->data)
        minTree = rightMinMax.first;
    if (leftMinMax.second && leftMinMax.second->data > maxTree->data)
        maxTree = leftMinMax.second;
    if (rightMinMax.second && rightMinMax.second->data > maxTree->data)
        maxTree = rightMinMax.second;
    return std::make_pair(minTree, maxTree);
}