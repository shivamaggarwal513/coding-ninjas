#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

template <typename T>
class BSTNode
{
public:
    T data;
    BSTNode<T> *left;
    BSTNode<T> *right;

    BSTNode()
    {
        left = right = nullptr;
    }

    BSTNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    BSTNode(T data, BSTNode<T> *left, BSTNode<T> *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    ~BSTNode()
    {
        delete left;
        delete right;
    }
};


template <typename T>
void printTreeRec(BSTNode<T> *root)
{
    if (!root)
        return;
    std::cout << root->data << ":";
    if (root->left)
        std::cout << "L:" << root->left->data << ",";
    if (root->right)
        std::cout << "R:" << root->right->data;
    std::cout << "\n";
    printTreeRec(root->left);
    printTreeRec(root->right);
}

BSTNode<int> *takeInputRec()
{
    int data;
    std::cin >> data;
    if (data == -1)
        return nullptr;
    BSTNode<int> *root = new BSTNode<int>(data);
    root->left = takeInputRec();
    root->right = takeInputRec();
    return root;
}

BSTNode<int> *takeInputLW()
{
    int data;
    // std::cout << "Enter data: ";
    std::cin >> data;
    if (data == -1)
        return nullptr;
    BSTNode<int> *root = new BSTNode<int>(data), *subRoot;
    std::queue<BSTNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        subRoot = q.front();
        q.pop();
        // std::cout << "Enter left child of " << subRoot->data << ": ";
        std::cin >> data;
        if (data != -1)
        {
            subRoot->left = new BSTNode<int>(data);
            q.push(subRoot->left);
        }
        // std::cout << "Enter right child of " << subRoot->data << ": ";
        std::cin >> data;
        if (data != -1)
        {
            subRoot->right = new BSTNode<int>(data);
            q.push(subRoot->right);
        }
    }
    return root;
}

template<typename T>
void printTreeLW(BSTNode<T> *root)
{
    if (!root)
        return;
    std::queue<BSTNode<T> *> q;
    BSTNode<T> *temp;
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
int numNodes(BSTNode<T> *root)
{
    if (!root)
        return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

template <typename T>
int heightTree(BSTNode<T> *root)
{
    if (!root)
        return 0;
    return 1 + std::max(heightTree(root->left), heightTree(root->right));
}

template <typename T>
void mirrorBinaryTree(BSTNode<T> *root)
{
    if (!root)
        return;
    std::swap(root->left, root->right);
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

template <typename T>
void levelOrderPrint(BSTNode<T> *root)
{
    if (!root)
        return;
    BSTNode<T> *curr;
    std::queue<BSTNode<T> *> q;
    q.push(root);
    q.push(nullptr);
    while (q.size() != 1)
    {
        curr = q.front();
        q.pop();
        if (!curr)
        {
            std::cout << "\n";
            q.push(nullptr);
            continue;
        }
        std::cout << curr->data << " ";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

template <typename T>
void inOrderPrint(BSTNode<T> *root)
{
    if (!root)
        return;
    inOrderPrint(root->left);
    std::cout << root->data << " ";
    inOrderPrint(root->right);
}

template <typename T>
void preOrderPrint(BSTNode<T> *root)
{
    if (!root)
        return;
    std::cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

template <typename T>
void postOrderPrint(BSTNode<T> *root)
{
    if (!root)
        return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    std::cout << root->data << " ";
}

template <typename T>
BSTNode<T> *constructTreePreIn(T *preArr, T *inArr, int n)
{
    if (!n)
        return nullptr;
    BSTNode<T> *root = new BSTNode<T>(preArr[0]);
    int i; for (i = 0; i < n && inArr[i] != preArr[0]; i++);
    root->left = constructTreePreIn(preArr + 1, inArr, i);
    root->right = constructTreePreIn(preArr + i + 1, inArr + i + 1, n - i - 1);
    return root;
}

template <typename T>
BSTNode<T> *constructTreePostIn(T *postArr, T *inArr, int n)
{
    if (!n)
        return nullptr;
    BSTNode<T> *root = new BSTNode<T>(postArr[n - 1]);
    int i; for (i = 0; i < n && inArr[i] != postArr[n - 1]; i++);
    root->left = constructTreePostIn(postArr, inArr, i);
    root->right = constructTreePostIn(postArr + i, inArr + i + 1, n - i - 1);
    return root;
}

template <typename T>
int diameterTree(BSTNode<T> *root)
{
    if (!root)
        return 0;
    return std::max(heightTree(root->left) + heightTree(root->right), 
                    std::max(diameterTree(root->left), diameterTree(root->right)));
}

template <typename T>
std::pair<int, int> heightDiameterTree(BSTNode<T> *root)
{
    if (!root)
        return std::make_pair(0, 0);
    std::pair<int, int> leftHD = heightDiameterTree(root->left), rightHD = heightDiameterTree(root->right);
    return std::make_pair(std::max(leftHD.first, rightHD.first) + 1, 
                        std::max(leftHD.first + rightHD.first, std::max(leftHD.second, rightHD.second)));
}

template <typename T>
std::pair<BSTNode<T> *, BSTNode<T> *> minMaxBinaryTree(BSTNode<T> *root)
{
    if (!root)
        return std::make_pair(nullptr, nullptr);
    if (!root->left && !root->right)
        return std::make_pair(root, root);
    std::pair<BSTNode<T> *, BSTNode<T> *> leftMinMax = minMaxBinaryTree(root->left), rightMinMax = minMaxBinaryTree(root->right);
    BSTNode<T> *minTree = root, *maxTree = root;
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

template <typename T>
BSTNode<T> *BSTSearch(BSTNode<T> *root, T x)
{
    if (!root)
        return nullptr;
    if (root->data == x)
        return root;
    return root->data > x ? BSTSearch(root->left, x) : BSTSearch(root->right, x);
}

template <typename T>
void printElementsInRange(BSTNode<T> *root, T k1, T k2)
{
    if (!root)
        return;
    if (k1 < root->data)
        printElementsInRange(root->left, k1, k2);
    if (k1 <= root->data && root->data <= k2)
        std::cout << root->data << " ";
    if (root->data < k2)
        printElementsInRange(root->right, k1, k2);
}

int minBinaryTree(BSTNode<int> *root)
{
    if (!root)
        return INT_MAX;
    return std::min(root->data, std::min(minBinaryTree(root->left), minBinaryTree(root->right)));
}

int maxBinaryTree(BSTNode<int> *root)
{
    if (!root)
        return INT_MIN;
    return std::max(root->data, std::max(maxBinaryTree(root->left), maxBinaryTree(root->right)));
}

class Triplet
{
public:
    int minimum, maximum;
    bool isBST;

    Triplet() {}
    Triplet(int minimum, int maximum, bool isBST) : 
    minimum(minimum), maximum(maximum), isBST(isBST) {}

    void operator=(const Triplet &t)
    {
        minimum = t.minimum;
        maximum = t.maximum;
        isBST = t.isBST;
    }
};

bool checkBST1(BSTNode<int> *root)
{
    if (!root)
        return true;
    return maxBinaryTree(root->left) < root->data && 
            root->data <= minBinaryTree(root->right) && 
            checkBST1(root->left) && 
            checkBST1(root->right);
}

Triplet checkBST2(BSTNode<int> *root)
{
    if (!root)
        return Triplet(INT_MAX, INT_MIN, true);
    Triplet leftAns = checkBST2(root->left);
    Triplet rightAns = checkBST2(root->right);
    return Triplet(std::min(root->data, std::min(leftAns.minimum, rightAns.minimum)),
                    std::max(root->data, std::max(leftAns.maximum, rightAns.maximum)),
                    leftAns.isBST && rightAns.isBST && leftAns.maximum < root->data && root->data <= rightAns.minimum);
}

bool checkBST3(BSTNode<int> *root, int lowerLimit = INT_MIN, int upperLimit = INT_MAX)
{
    if (!root)
        return true;
    if (lowerLimit >= root->data || upperLimit < root->data)
        return false;
    return checkBST3(root->left, lowerLimit, root->data - 1) && 
            checkBST3(root->right, root->data, upperLimit);
}

template <typename T>
BSTNode<T> *constructBST(T *arr, int n)
{
    if (!n)
        return nullptr;
    BSTNode<T> *root = new BSTNode<T>(arr[(n - 1) / 2]);
    root->left = constructBST(arr, (n - 1) / 2);
    root->right = constructBST(arr + (n + 1) / 2, n / 2);
    return root;
}

template <typename T>
class ListNode
{
public:
    T data;
    ListNode *next;

    ListNode() : next(nullptr) {}
    ListNode(T data) : data(data), next(nullptr) {}
    ListNode(T data, ListNode<T> *next) : data(data), next(next) {}

    ~ListNode()
    {
        delete next;
    }
};

template <typename T>
void printLL(ListNode<T> *head)
{
    ListNode<T> *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

template <typename T>
std::pair<ListNode<T> *, ListNode<T> *> BSTtoLL(BSTNode<T> *root)
{
    if (!root)
        return std::make_pair(nullptr, nullptr);
    std::pair<ListNode<T> *, ListNode<T> *> leftAns = BSTtoLL(root->left), rightAns = BSTtoLL(root->right);
    ListNode<T> *midNode = new ListNode<T>(root->data, rightAns.first);
    if (leftAns.second)
        leftAns.second->next = midNode;
    return std::make_pair(leftAns.second ? leftAns.first : midNode,
                    rightAns.first ? rightAns.second : midNode);
}

template <typename T>
std::vector<T> *findPathinBinaryTree(BSTNode<T> *root, T k)
{
    if (!root)
        return nullptr;
    if (root->data == k)
        return new std::vector<T>(1, root->data);
    std::vector<T> *leftPath = findPathinBinaryTree(root->left, k);
    if (leftPath)
    {
        leftPath->push_back(root->data);
        return leftPath;
    }
    std::vector<T> *rightPath = findPathinBinaryTree(root->right, k);
    if (rightPath)
    {
        rightPath->push_back(root->data);
        return rightPath;
    }
    return nullptr;
}

template <typename T>
BSTNode<T> *insertBST(BSTNode<T> *root, T data)
{
    if (!root)
        return new BSTNode<T>(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else
        root->right = insertBST(root->right, data);
    return root;
}

template <typename T>
BSTNode<T> *deleteBST(BSTNode<T> *root, T data)
{
    if (!root)
        return nullptr;
    if (data < root->data)
        root->left = deleteBST(root->left, data);
    else if (data > root->data)
        root->right = deleteBST(root->right, data);
    else
    {
        BSTNode<T> *leftSubTree = root->left, *rightSubTree = root->right;
        root->left = root->right = nullptr;
        delete root;
        if (!leftSubTree || !rightSubTree)
            return leftSubTree ? leftSubTree : rightSubTree;
        BSTNode<T> *minimum = rightSubTree;
        while (minimum->left)
            minimum = minimum->left;
        T minimumData = minimum->data;
        rightSubTree = deleteBST(rightSubTree, minimumData);
        root = new BSTNode<T>(minimumData, leftSubTree, rightSubTree);
    }
    return root;
}

template <typename T>
class BSTree
{
private:
    BSTNode<T> *root;

public:
    BSTree() : root(nullptr) {}

    void insertNode(T data) { root = insertBST(root, data); }

    void deleteNode(T data) { root = deleteBST(root, data); }

    bool hasNode(T data)
    {
        BSTNode<T> *ans = BSTSearch(root, data);
        return ans ? true : false;
    }

    void printBST() { printTreeRec(root); }

    ~BSTree() { delete root; }
};