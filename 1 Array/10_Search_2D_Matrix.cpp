// https://leetcode.com/problems/search-a-2d-matrix/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'



//  Time Complexity : O(LogN)
// Space Complexity : O(1)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int s = 0, e = n * m - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int currEle = matrix[mid / m][mid % m];
            if (target == currEle)
            {
                return true;
            }
            else if (target > currEle)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}