#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        int maxLen = 0;
        int prefixSum = 0;
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            prefixSum += arr[i];
            if (prefixSum == 0)
            {
                maxLen = i + 1;
            }
            else
            {
                if (mpp.find(prefixSum) != mpp.end())
                {
                    maxLen = max(maxLen, i - mpp[prefixSum] );
                }
                else
                {
                    mpp[prefixSum] = i;
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}