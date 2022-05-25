// https://leetcode.com/problems/n-queens/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{

    bool is_safe(vector<string> &boards, int row, int col, int n)
    {

        int r1 = row;
        int c1 = col;
        while (row >= 0 && col >= 0)
        {
            if (boards[row][col] == 'Q')
            {
                return false;
            }

            row--;
            col--;
        }

        col = c1;
        row = r1;

        while (col >= 0)
        {
            if (boards[row][col] == 'Q')
            {
                return false;
            }

            col--;
        }

        row = r1;
        col = c1;

        while (col >= 0 && row < n)
        {
            if (boards[row][col] == 'Q')
            {
                return false;
            }

            row++;
            col--;
        }

        return true;
    }

    void Helper(vector<vector<string>> &ans, vector<string> &board, int n, int col)
    {

        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (is_safe(board, row, col, n))
            {
                board[row][col] = 'Q';
                Helper(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> ds(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            ds[i] = s;
        }

        Helper(ans, ds, n, 0);
        return ans;
    }
};

class Solution
{
    void Helper(vector<vector<string>> &ans, vector<string> &ds, int col, int n, vector<bool> &leftRow, vector<bool> &lowerDiagonal, vector<bool> &upperDiagonal)
    {
        if (col == n)
        {
            ans.push_back(ds);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (!leftRow[row] and !lowerDiagonal[row + col] and !upperDiagonal[n - 1 + col - row])
            {
                ds[row][col] = 'Q';
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = true;
                Helper(ans, ds, col + 1, n, leftRow, lowerDiagonal, upperDiagonal);
                ds[row][col] = '.';
                leftRow[row] = lowerDiagonal[row + col] = upperDiagonal[n - 1 + col - row] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> ds(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            ds[i] = s;
        }
        vector<bool> leftRow(n, false), lowerDiagonal(2 * n - 1, false), upperDiagonal(2 * n - 1, false);
        Helper(ans, ds, 0, n, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}