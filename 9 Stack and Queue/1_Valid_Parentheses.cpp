// https://leetcode.com/problems/valid-parentheses/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    bool _equal(char c1, char c2)
    {
        if (c1 == '(' && c2 == ')')
            return true;
        if (c1 == '[' && c2 == ']')
            return true;
        if (c1 == '{' && c2 == '}')
            return true;
        return false;
    }

public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
            }
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (st.empty())
                {
                    return false;
                }
                int ob = st.top();
                st.pop();
                if (!_equal(ob, ch))
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}