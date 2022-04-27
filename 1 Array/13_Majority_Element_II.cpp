// https://leetcode.com/problems/majority-element-ii/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int n = nums.size();
        int num1, num2;
        int occ1 = 0, occ2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (occ1 == 0 && nums[i] != num2)
            {
                num1 = nums[i];
                occ1++;
            }
            else if (nums[i] == num1)
            {
                occ1++;
            }
            else if (occ2 == 0)
            {
                num2 = nums[i];
                occ2++;
            }
            else if (nums[i] == num2)
            {
                occ2++;
            }
            else
            {
                occ1--, occ2--;
            }
        }

        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (num1 == nums[i])
            {
                c1++;
            }
            else if (num2 == nums[i])
            {
                c2++;
            }
        }

        vector<int> ans;
        if (c1 > (n / 3))
        {
            ans.push_back(num1);
        }

        if (c2 > (n / 3))
        {
            ans.push_back(num2);
        }

        return ans;
    }
};

int main()
{

    return 0;
}