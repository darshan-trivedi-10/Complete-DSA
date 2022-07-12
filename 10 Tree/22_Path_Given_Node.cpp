// https://www.interviewbit.com/problems/path-to-given-node/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool findPath(TreeNode *root, vector<int> &ans, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->val == target)
    {
        ans.push_back(root->val);
        return true;
    }

    bool left = findPath(root->left, ans, target);
    bool right = findPath(root->right, ans, target);
    if (left || right)
    {
        ans.push_back(root->val);
    }
    return left || right;
}

vector<int> solve(TreeNode *root, int target)
{
    vector<int> ans;
    findPath(root, ans, target);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}