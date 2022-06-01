#include <bits/stdc++.h>
using namespace std;
#include "tree.h"

class Solution
{
public:
    void AllTraversal(TreeNode *root)
    {

        stack<pair<TreeNode *, int>> s;
        vector<int> pre, post, in;
        s.push({root, 1});
        if (root == NULL)
        {
            return;
        }
        while (!s.empty())
        {
            auto it = s.top();
            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                s.top().second++;
                if (it.first->left != NULL)
                {
                    s.push({it.first->left, 1});
                }
            }
            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                s.top().second++;
                if (it.first->right != NULL)
                {
                    s.push({it.first->right, 1});
                }
            }
            else
            {
                s.pop();
                post.push_back(it.first->val);
            }
        }
        for (int i = 0; i < pre.size(); i++)
        {
            cout << pre[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < in.size(); i++)
        {
            cout << in[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < post.size(); i++)
        {
            cout << post[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);

    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);

    s.AllTraversal(t);

    return 0;
}