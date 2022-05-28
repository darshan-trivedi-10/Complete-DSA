// https://leetcode.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int left = 0, right = 0;
        int len = 0;
        for (int i = 1; i < n; i++)
        {
            int l = i - 1, r = i;
            // case-1 when palindrome is like abcddcba
            while (l >= 0 and r < n and s[l] == s[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    left = l, right = r;
                }
                l--, r++;
            }

            l = i - 1, r = i + 1;
            // case-2 when palindrome is like abcdedcba
            while (l >= 0 and r < n and s[l] == s[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    left = l, right = r;
                }
                l--, r++;
            }
        }

        string ans = "";
        for (int i = left; i <= right; i++)
        {
            ans.push_back(s[i]);
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