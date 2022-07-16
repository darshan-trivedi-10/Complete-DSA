// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"
class Solution
{
    TreeNode *builder(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inMap)
    {

        if (preStart > preEnd or inStart > inEnd)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;
        // cout<<numLeft<<" ";
        // cout<<root->val<<" "<<preStart+1<<" "<<preStart+numLeft<<"\n";

        root->left = builder(preorder, preStart + 1, preStart + numLeft, inorder, inStart, inRoot - 1, inMap);
        root->right = builder(preorder, preStart + numLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // preorder --> [3,9,20,15,7] (root, left, right)
        // inorder  --> [9,3,15,20,7] (left, root, right)
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = builder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
        return root;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}