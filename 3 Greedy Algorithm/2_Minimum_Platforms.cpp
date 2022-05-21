// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int plat_needed = 1, result = 1;
        int i = 1, j = 0;

        while (i < n and j < n)
        {
            if (arr[i] <= dep[j])
            {
                i++;
                plat_needed++;
            }
            else if (arr[i] > dep[j])
            {
                plat_needed--;
                j++;
            }

            result = max(result, plat_needed);
        }
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}