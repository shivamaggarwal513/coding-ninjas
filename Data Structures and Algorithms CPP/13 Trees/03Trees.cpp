#include <iostream>
#include <vector>
#include "02Trees.h"
using namespace std;

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *c1 = new TreeNode<int>(2);
    TreeNode<int> *c2 = new TreeNode<int>(3);
    root->children.push_back(c1);
    root->children.push_back(c2);
    delete root;
    return 0;
}