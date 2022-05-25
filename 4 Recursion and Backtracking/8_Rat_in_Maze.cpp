// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    bool isValid(int i, int j, int n)
    {
        return (i >= 0 and j >= 0 and i < n and j < n);
    }
    void getPath(vector<vector<int>> &arr, vector<string> &ans, string path, int n, int i, int j)
    {
        if (i == n - 1 and j == n - 1)
        {
            ans.push_back(path);
            return;
        }

        // Up{i-1, j}, down{i+1 ,j}, left(i, j-1), right{i,j+1}
        string der = "UDLR";
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int idx = 0; idx < 4; idx++)
        {
            int newI = i + dx[idx];
            int newJ = j + dy[idx];
            if (isValid(newI, newJ, n) and arr[newI][newJ] == 1)
            {
                arr[i][j] = 0;
                getPath(arr, ans, path + der[idx], n, newI, newJ);
                arr[i][j] = 1;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        string path = "";
        if (m[0][0] == 1)
        {
            getPath(m, ans, path, n, 0, 0);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
