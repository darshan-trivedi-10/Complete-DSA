// https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    bool isValid(char ch)
    {
        return (ch <= '9' and ch >= '0') || (ch <= 'a' and ch >= 'z') || (ch <= 'A' and ch >= 'Z');
    }

public:
    string reverseWords(string s)
    {
        int n = s.size();
        string ans = "";
        bool space = false;
        for (int i = 0; i < n; i++)
        {
            if (isValid(s[i]))
            {
                space = true;
                ans.push_back(s[i]);
            }
            else if (space)
            {
                ans += " ";
                space = false;
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