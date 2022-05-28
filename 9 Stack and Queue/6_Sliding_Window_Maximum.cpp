// https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() and dq.front() == i - k)
                dq.pop_front();

            while (!dq.empty() and nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);
            if (i >= (k - 1))
                ans.push_back(nums[dq.front()]);
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