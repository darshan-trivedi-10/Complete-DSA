// https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int arr[n];
    unordered_map<int, int> count(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int occ = count[arr[i]];
        if (occ > (n / k))
        {
            cout << arr[i] << " ";
            count[arr[i]] = 0;
        }
    }

    return 0;
}