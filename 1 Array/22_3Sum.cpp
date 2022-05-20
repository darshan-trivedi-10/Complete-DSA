// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

/*

1 --> Using 3 nested Loop.
2 --> Using two nested loop and HashMap.
3 --> Select one element and two pointer.

*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++)
        {
            if (i == 0 || (i > 0 and nums[i] != nums[i - 1]))
            {
                int target = 0 - nums[i];
                int j = i + 1, k = n - 1;
                while (j < k)
                {
                    int cSum = nums[j] + nums[k];
                    if (cSum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k]});
                        while (j < k and nums[j] == nums[j + 1])
                        {
                            j++;
                        }

                        while (j < k and nums[k] == nums[k - 1])
                        {
                            k--;
                        }

                        j++, k--;
                    }
                    else if (cSum > target)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
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


