// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int removeDuplicates(vector<int> &arr)
    {
        int dummy = INT_MAX;
        int n = arr.size();
        int last, k = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                last = arr[i];
            }
            else
            {
                if (arr[i] == last)
                {
                    arr[i] = dummy;
                    k++;
                }
                else
                {
                    last = arr[i];
                }
            }
        }

        int i = 0, j = 0;
        while (i < n and j < n)
        {
            if (arr[i] != dummy and arr[j] != dummy)
            {
                j++;
                i++;
            }
            else if (arr[j] != dummy and arr[i] == dummy)
            {
                swap(arr[i], arr[j]);
                i++;
            }
            else
            {
                j++;
            }
        }

        return n - k;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}