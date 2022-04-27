// https://leetcode.com/problems/majority-element/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans = nums[0];
        int occ = 1;
        for (int i = 1; i < n; i++)
        {
            if (occ == 0)
            {
                ans = nums[i];
                occ++;
            }
            else if (nums[i] == ans)
            {
                occ++;
            }
            else
            {
                occ--;
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