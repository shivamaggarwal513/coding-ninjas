#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class TreeNode
{
public:
    T data;
    std::vector<TreeNode<T> *> children;

    TreeNode() {}

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
            delete children[i];
    }
};

template <typename T>
void printTreeRec(TreeNode<T> *root)
{
    if (!root)
        return;
    std::cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
        std::cout << root->children[i]->data << " ";
    std::cout << "\n";
    for (int i = 0; i < root->children.size(); i++)
        printTreeRec(root->children[i]);
}

template <typename T>
TreeNode<T> *takeInputRec()
{
    T data;
    int n;
    std::cout << "Enter data: ";
    std::cin >> data;
    TreeNode<T> *root = new TreeNode<T>(data);
    std::cout << "Enter number of children of " << data << ": ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
        root->children.push_back(takeInputRec<T>());
    return root;
}

template <typename T>
TreeNode<T> *takeInputLW()
{
    T data;
    int n;
    // std::cout << "Enter data: ";
    std::cin >> data;
    TreeNode<T> *root = new TreeNode<T>(data);
    std::queue<TreeNode<T> *> q;
    q.push(root);
    TreeNode<T> *subRoot, *child;
    while (!q.empty())
    {
        subRoot = q.front();
        q.pop();
        // std::cout << "Enter number of children of " << subRoot->data << ": ";
        std::cin >> n;
        // if (n)
        //     std::cout << "Enter children of " << subRoot->data << ": ";
        for (int i = 0; i < n; i++)
        {
            std::cin >> data;
            child = new TreeNode<T>(data);
            subRoot->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

template <typename T>
void printTreeLW(TreeNode<T> *root)
{
    if (!root)
        return;
    std::queue<TreeNode<T> *> q;
    q.push(root);
    TreeNode<T> *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        std::cout << temp->data << ":";
        if (temp->children.size())
        {
            for (int i = 0; i < temp->children.size() - 1; i++)
            {
                std::cout << temp->children[i]->data << ",";
                q.push(temp->children[i]);
            }
            std::cout << temp->children[temp->children.size() - 1]->data;
            q.push(temp->children[temp->children.size() - 1]);
        }
        std::cout << "\n";
    }
}

template <typename T>
int numNodes(TreeNode<T> *root)
{
    if (!root)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
        ans += numNodes(root->children[i]);
    return ans;
}

template <typename T>
int sumNodes(TreeNode<T> *root)
{
    if (!root)
        return 0;
    T ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
        ans += sumNodes(root->children[i]);
    return ans;
}

template <typename T>
TreeNode<T> *maxNode(TreeNode<T> *root)
{
    if (!root)
        return nullptr;
    TreeNode<T> *max = root, *subMax;
    for (int i = 0; i < root->children.size(); i++)
    {
        subMax = maxNode(root->children[i]);
        if (subMax->data > max->data)
            max = subMax;
    }
    return max;
}

template <typename T>
int heightTree(TreeNode<T> *root)
{
    if (!root)
        return 0;
    int subHeight, maxSubHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        subHeight = heightTree(root->children[i]);
        if (subHeight > maxSubHeight)
            maxSubHeight = subHeight;
    }
    return maxSubHeight + 1;
}

template <typename T>
void printAtLevelK(TreeNode<T> *root, int k)
{
    if (!root)
        return;
    if (!k)
    {
        std::cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
        printAtLevelK(root->children[i], k - 1);
}

template <typename T>
int numLeaves(TreeNode<T> *root)
{
    if (!root)
        return 0;
    if (root->children.empty())
        return 1;
    int leaves = 0;
    for (int i = 0; i < root->children.size(); i++)
        leaves += numLeaves(root->children[i]);
    return leaves;
}

template <typename T>
void preOrderPrint(TreeNode<T> *root)
{
    if (!root)
        return;
    std::cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
        preOrderPrint(root->children[i]);
}

template <typename T>
void postOrderPrint(TreeNode<T> *root)
{
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
        postOrderPrint(root->children[i]);
    std::cout << root->data << " ";
}