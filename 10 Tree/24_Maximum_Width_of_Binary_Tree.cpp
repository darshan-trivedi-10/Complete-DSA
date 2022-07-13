// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int sz = q.size();
            int mmin = q.front().second;
            int left, right;
            for (int i = 0; i < sz; i++)
            {
                TreeNode *temp = q.front().first;
                int currId = q.front().second - mmin;
                q.pop();
                if (i == 0)
                {
                    left = currId;
                }
                if (i == sz - 1)
                {
                    right = currId;
                }

                if (temp->left)
                {
                    q.push({temp->left, currId * 2LL + 1});
                }

                if (temp->right)
                {
                    q.push({temp->right, currId * 2LL + 2});
                }
            }

            ans = max(ans, right - left + 1);
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