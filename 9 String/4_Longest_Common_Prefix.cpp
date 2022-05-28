// https://leetcode.com/problems/longest-common-prefix/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    string longestCommonPrefix(vector<string> &str)
    {
        int n = str.size();
        sort(str.begin(), str.end());
        string a = str[0], b = str[n - 1];
        string ans = "";
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == b[i])
            {
                ans.push_back(a[i]);
            }
            else
            {
                break;
            }
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