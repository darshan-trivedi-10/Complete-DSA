// https://leetcode.com/problems/diameter-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
    int maxHeight(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int h1 = maxHeight(root->left, ans);
        int h2 = maxHeight(root->right, ans);

        ans = max(ans, abs(h1 + h2));

        return 1 + max(h1, h2);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        int height = maxHeight(root, ans);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}