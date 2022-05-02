// https://leetcode.com/problems/reverse-pairs/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int pairs = 0;
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && arr[i] > (2LL * arr[j]))
            {
                j++;
            }
            pairs += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return pairs;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
        {
            return 0;
        }
        int mid = (low + high) / 2;
        int totalPair = mergeSort(arr, low, mid);
        totalPair += mergeSort(arr, mid + 1, high);
        totalPair += merge(arr, low, mid, high);
        return totalPair;
    }

public:
    int reversePairs(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
