// https://leetcode.com/problems/unique-paths/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    int findPath(vector<vector<int>> &dp, int m, int n, int i, int j)
    {
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        if (i >= n || j >= m || i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int right = findPath(dp, m, n, i, j + 1);                                  
        int bottom = findPath(dp, m, n, i + 1, j);
        return dp[i][j] = right + bottom;
    }

public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int totalPath = findPath(dp, m, n, 0, 0);
        return totalPath;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}