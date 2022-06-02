// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool leftright = true;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> level(sz);
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                int idx = leftright ? i : (sz - i - 1);
                level[idx] = temp->val;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(level);
            leftright = !leftright;
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}