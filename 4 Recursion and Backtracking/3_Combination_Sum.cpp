// https://leetcode.com/problems/combination-sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    void Helper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int idx, int target)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        if (idx >= arr.size())
        {
            return;
        }

        if (arr[idx] <= target)
        {
            ds.push_back(arr[idx]);
            Helper(arr, ans, ds, idx, target - arr[idx]);
            ds.pop_back();
        }

        Helper(arr, ans, ds, idx + 1, target);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        Helper(candidates, ans, ds, 0, target);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}