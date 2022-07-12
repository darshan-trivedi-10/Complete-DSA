// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to return a list containing elements of left view of the binary tree.
void Helper(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }

    Helper(root->left, ans, level + 1);
    Helper(root->right, ans, level + 1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    Helper(root, ans, 0);
    return ans;
}

int main()
{

    return 0;
}
