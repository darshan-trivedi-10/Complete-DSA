// https://www.codingninjas.com/codestudio/problems/1115652
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    int count = 0;
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
        if (xorr == x)
        {
            count++;
        }

        int num = x ^ xorr;
        if (mpp.find(num) != mpp.end())
        {
            count += mpp[num];
        }

        mpp[xorr]++;
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}