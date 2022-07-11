// https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool isLeaf(TreeNode<int> *node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

void addLeft(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            ans.push_back(cur->data);

        if (cur->left)
            cur = cur->left;

        else
            cur = cur->right;
    }
}

void addRight(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *cur = root->right;
    vector<int> temp;
    while (cur)
    {

        if (!isLeaf(cur))
            temp.push_back(cur->data);

        if (cur->right)
            cur = cur->right;

        else
            cur = cur->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void addLeaves(TreeNode<int> *node, vector<int> &ans)
{
    if (isLeaf(node))
    {
        ans.push_back(node->data);
        return;
    }
    if (node->left)
        addLeaves(node->left, ans);

    if (node->right)
        addLeaves(node->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    if (!isLeaf(root))
    {
        ans.push_back(root->data);
    }

    addLeft(root, ans);
    addLeaves(root, ans);
    addRight(root, ans);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}