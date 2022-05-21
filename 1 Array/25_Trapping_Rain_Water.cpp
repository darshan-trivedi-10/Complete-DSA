// https://leetcode.com/problems/trapping-rain-water/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left[n], right[n];
        int j = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                left[i] = height[i], right[j] = height[j];
            }
            else
            {
                left[i] = max(left[i - 1], height[i]);
                right[j] = max(right[j + 1], height[j]);
            }

            j--;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};

//  Optimal Solution Using Two Pointer
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        int i = 0, j = n - 1;

        while (i <= j)
        {
            if (height[i] <= height[j])
            {
                if (leftMax <= height[i])
                {
                    leftMax = height[i];
                }
                else
                {
                    ans += (leftMax - height[i]);
                }

                i++;
            }
            else
            {
                if (rightMax <= height[j])
                {
                    rightMax = height[j];
                }
                else
                {
                    ans += (rightMax - height[j]);
                }

                j--;
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