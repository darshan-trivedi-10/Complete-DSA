// https://leetcode.com/problems/subsets-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    void findSubset(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, int idx)
    {
        int n = nums.size();
        ans.push_back(ds);
        for (int i = idx; i < n; i++)
        {
            if (i > idx and nums[i] == nums[i - 1])
            {
                continue;
            }

            ds.push_back(nums[i]);
            findSubset(nums, ans, ds, i + 1);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findSubset(nums, ans, ds, 0);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}