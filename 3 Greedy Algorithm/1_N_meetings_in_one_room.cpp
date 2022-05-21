// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({start[i], end[i]});
        }

        sort(arr.begin(), arr.end(), cmp);
        int ans = 1;
        int eTime = arr[0].second;
        for (int i = 1; i < n; i++)
        {
            if (eTime < arr[i].first)
            {
                eTime = arr[i].second;
                ans++;
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