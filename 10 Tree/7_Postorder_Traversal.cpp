// https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"


// Using two Stack

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> postorder;
        stack<TreeNode *> s1, s2;
        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            s2.push(temp);

            if (temp->left)
            {
                s1.push(temp->left);
            }

            if (temp->right)
            {
                s1.push(temp->right);
            }
        }

        while (!s2.empty())
        {
            postorder.push_back(s2.top()->val);
            s2.pop();
        }

        return postorder;
    }
};

// Using Only one stack
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<int> postorder;
        stack<TreeNode *> s1;
        s1.push(root);

        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            postorder.push_back(temp->val);

            if (temp->left)
            {
                s1.push(temp->left);
            }

            if (temp->right)
            {
                s1.push(temp->right);
            }
        }

        reverse(postorder.begin(), postorder.end());

        return postorder;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}