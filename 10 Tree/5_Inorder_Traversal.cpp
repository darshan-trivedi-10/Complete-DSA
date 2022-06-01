// https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }

        return inorder;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}