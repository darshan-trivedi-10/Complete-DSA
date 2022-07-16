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
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right and prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return inorder;
    }
};

class Solution
{
public:
    vector<int> PreorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;

        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right and prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return preorder;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}