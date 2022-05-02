// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int num = target - nums[i];
            if (mpp.find(num) != mpp.end())
            {
                ans.push_back(i);
                ans.push_back(mpp[num]);
                break;
            }

            mpp[nums[i]] = i;
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