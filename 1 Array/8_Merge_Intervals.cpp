// https://leetcode.com/problems/merge-intervals/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int rangeS = intervals[0][0], rangeE = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] <= rangeE)
            {
                rangeE = max(intervals[i][1], rangeE);
            }
            else
            {
                ans.push_back({rangeS, rangeE});
                rangeS = intervals[i][0], rangeE = intervals[i][1];
            }
        }

        ans.push_back({rangeS, rangeE});

        return ans;
    }
};

int main()
{
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin>>a>>b;
        arr.push_back({a,b});
    }
    

    return 0;
}