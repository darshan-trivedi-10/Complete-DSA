// https://leetcode.com/problems/symmetric-tree/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{

    bool Helper(TreeNode *left, TreeNode *right)
    {
        if (left == NULL || right == NULL)
        {
            return left == right;
        }

        if (left->val != right->val)
        {
            return false;
        }

        bool l = Helper(left->left, right->right);
        bool r = Helper(left->right, right->left);

        return (l & r);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return Helper(root->left, root->right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}