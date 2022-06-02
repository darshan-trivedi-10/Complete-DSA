// https://leetcode.com/problems/balanced-binary-tree/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
    int findAns(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = findAns(root->left, ans);
        int h2 = findAns(root->right, ans);
        ans = max(ans, abs(h1 - h2));

        return 1 + max(h1, h2);
    }

public:
    bool isBalanced(TreeNode *root)
    {
        int ans = 0;
        findAns(root, ans);
        return ans <= 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}