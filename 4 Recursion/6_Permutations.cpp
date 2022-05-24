// https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    void Helper(vector<int> &nums, vector<vector<int>> &ans, int idx)
    {
        int n = nums.size();
        if (idx == n)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            swap(nums[i], nums[idx]);
            Helper(nums, ans, i + 1);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        Helper(nums, ans, 0);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}