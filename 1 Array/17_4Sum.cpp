// https://leetcode.com/problems/4sum/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            int a = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                int b = nums[j];
                int cd = target - a - b;
                int s = j + 1, e = n - 1;
                while (s < e)
                {
                    int twoSum = nums[s] + nums[e];
                    if (twoSum < cd)
                    {
                        s++;
                    }
                    else if (twoSum > cd)
                    {
                        e--;
                    }
                    else
                    {
                        vector<int> temp;
                        temp.push_back(a);
                        temp.push_back(b);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);
                        ans.push_back(temp);
                        while (s < e && nums[s] == temp[2])
                        {
                            s++;
                        }
                        while (s < e && nums[e] == temp[3])
                        {
                            e--;
                        }
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                {
                    j++;
                }
            }

            while (i + 1 < n && nums[i + 1] == nums[i])
            {
                i++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}