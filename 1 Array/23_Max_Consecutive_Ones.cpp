// https://leetcode.com/problems/max-consecutive-ones/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                int j = i;
                while (j < n and arr[j] == 1)
                {
                    j++;
                }
                ans = max(ans, j - i);
                i = j;
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