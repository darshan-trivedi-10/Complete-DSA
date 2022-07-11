#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }

        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto p = q.front();
                q.pop();

                Node *temp = p.first;
                int level = p.second;

                mpp[level] = temp->data;

                if (temp->left)
                {
                    q.push({temp->left, level - 1});
                }

                if (temp->right)
                {
                    q.push({temp->right, level + 1});
                }
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
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