// https://leetcode.com/problems/maximum-subarray/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int cs = 0, ms = INT_MIN;
        for (auto element : nums)
        {
            cs += element;
            ms = max({cs, ms, element});
            cs = max(cs, 0);
        }

        return ms;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}