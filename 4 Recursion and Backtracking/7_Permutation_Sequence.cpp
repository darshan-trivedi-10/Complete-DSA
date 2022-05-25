// https://leetcode.com/problems/permutation-sequence/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);

        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + (k / fact));
            if (nums.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / nums.size();
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