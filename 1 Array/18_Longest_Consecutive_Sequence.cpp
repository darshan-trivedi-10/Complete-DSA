// https://leetcode.com/problems/longest-consecutive-sequence/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[nums[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int currElem = nums[i];
            if (mpp.find(currElem - 1) == mpp.end())
            {
                int currentStreck = 1;
                while (mpp.find(currElem + 1) != mpp.end())
                {
                    currElem++;
                    currentStreck++;
                }

                ans = max(ans, currentStreck);
            }
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