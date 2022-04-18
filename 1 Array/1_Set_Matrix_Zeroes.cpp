// https://leetcode.com/problems/set-matrix-zeroes/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

// Space Complexity : O(N) + O(M)
// Time Complexity :  O(N*M) + O(N*k) + O(M*k);
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        bool row[n], colmun[m];
        memset(row, false, sizeof row);
        memset(colmun, false, sizeof colmun);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = colmun[j] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (row[i])
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (colmun[j])
            {
                for (int i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
            {
                col0 = 0;
            }

            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }

            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}