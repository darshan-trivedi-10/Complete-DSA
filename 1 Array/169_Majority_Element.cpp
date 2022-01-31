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
        int ans = nums[0], counter = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (counter == 0)
            {
                counter = 1;
                ans = nums[i];
            }
            else if (ans == nums[i])
            {
                counter++;
            }
            else
            {
                counter--;
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