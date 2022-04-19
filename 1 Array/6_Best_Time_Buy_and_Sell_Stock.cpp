// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int profit = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            minPrice = min(prices[i], minPrice);
            profit = max(profit, prices[i] - minPrice);
        }

        return profit;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}