#include <iostream>
#include <climits>
#include <cmath>
#include "..\01BSTrees.h"
using namespace std;

class Quadruplet
{
public:
    int minimum, maximum;
    bool isBST;
    int heightBST;

    Quadruplet() {}
    Quadruplet(int minimum, int maximum, bool isBST, int heightBST) :
    minimum(minimum), maximum(maximum), isBST(isBST), heightBST(heightBST) {}

    void operator=(const Quadruplet &q)
    {
        minimum = q.minimum;
        maximum = q.maximum;
        isBST = q.isBST;
        heightBST = q.heightBST;
    }
};

Quadruplet largestBSTHeight(BSTNode<int> *root)
{
    if (!root)
        return Quadruplet(INT_MAX, INT_MIN, true, 0);
    Quadruplet leftAns = largestBSTHeight(root->left), rightAns = largestBSTHeight(root->right);
    Quadruplet ans(min(root->data, min(leftAns.minimum, rightAns.minimum)),
                    max(root->data, max(leftAns.maximum, rightAns.maximum)),
                    leftAns.isBST && rightAns.isBST && leftAns.maximum < root->data && root->data <= rightAns.minimum,
                    max(leftAns.heightBST, rightAns.heightBST));
    if (ans.isBST)
        ans.heightBST++;
    return ans;
}

int main()
{
    BSTNode<int> *root = takeInputLW();
    cout << largestBSTHeight(root).heightBST << "\n";
    delete root;
    return 0;
}