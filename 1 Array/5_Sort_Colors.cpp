// https://leetcode.com/problems/sort-colors/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;     // for 0
        int j = n - 1; // for 2
        int k = 0;     // for travel in an array

        while (k <= j)
        {
            if (nums[k] == 1)
            {
                k++;
            }
            else if (nums[k] == 0)
            {
                swap(nums[i], nums[k]);
                i++, k++;
            }
            else if (nums[k] == 2)
            {
                swap(nums[j], nums[k]);
                j--;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}