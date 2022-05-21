// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Job
{
    int id;
    int dead;
    int profit;
};

class Solution
{
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];
        memset(slot, -1, sizeof slot);
        int countJob = 0, profit = 0;
        for (int i = 0; i < n; i++)
        {
            int j = arr[i].dead;
            while (j > 0)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    countJob++;
                    profit += arr[i].profit;
                    break;
                }
                j--;
            }
        }

        return {countJob, profit};
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}