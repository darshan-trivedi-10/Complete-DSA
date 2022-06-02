// https://leetcode.com/problems/same-tree/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q)
        {
            return p == q;
        }

        if (p->val != q->val)
        {
            return false;
        }

        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}