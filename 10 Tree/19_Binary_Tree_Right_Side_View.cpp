#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
    void Helper(TreeNode *root, vector<int> &ans, int level)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == ans.size())
        {
            ans.push_back(root->val);
        }

        Helper(root->right, ans, level + 1);
        Helper(root->left, ans, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        // Main Idea is to take first element in level when we move from right to left in level.
        // We can do this using recursion (Root, right, left)

        vector<int> ans;
        Helper(root, ans, 0);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}