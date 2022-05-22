// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    void sum(vector<int> &arr, vector<int> &ans, int s, int i)
    {
        if (i == arr.size())
        {
            ans.push_back(s);
            return;
        }

        sum(arr, ans, s + arr[i], i + 1);
        sum(arr, ans, s, i + 1);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        sum(arr, ans, 0, 0);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}