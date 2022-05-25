// https://leetcode.com/problems/combination-sum-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    void Helper(vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int idx, int target)
    {
        int n = arr.size();
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            if (i > idx and arr[i] == arr[i - 1])
            {
                continue;
            }

            if (arr[i] > target)
            {
                break;
            }

            ds.push_back(arr[i]);
            Helper(arr, ans, ds, i + 1, target - arr[i]);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
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