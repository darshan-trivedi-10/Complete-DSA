// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Item
{
    int value;
    int weight;
};

class Solution
{
    bool static cmp(Item a, Item b)
    {
        return ((double)a.value / (double)a.weight) > ((double)b.value / (double)b.weight);
    }

public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, cmp);
        double totalItem = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                W -= arr[i].weight;
                totalItem += arr[i].value;
            }
            else if (W > 0)
            {
                totalItem += (arr[i].value / (double)arr[i].weight) * (double)W;
                W = 0;
            }
        }

        return totalItem;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}