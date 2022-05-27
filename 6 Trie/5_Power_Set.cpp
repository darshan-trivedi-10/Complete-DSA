// https://practice.geeksforgeeks.org/problems/power-set4302/1#
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

/*
---> Using Bit Manipulation, Basically, we traverse from 0 to 2^(n)-1 and check for every number if their bit is set or not. If the bit is set add that character to your subsequence. and last we sort the data structure in which we have store the subsequence

---> Find all the subsequence using recursion(Backtracking) store it in a data structure. Now sort the data structure in lexicographically sorted order.

*/
class Solution
{

public:
    vector<string> AllPossibleStrings(string s)
    {
        int n = s.size();
        vector<string> ans;
        for (int num = 0; num < (1 << n); num++)
        {
            string sub = "";
            for (int i = 0; i < 32; i++)
            {
                // check is the i-th bit is set or not
                if (num & (1 << i))
                {
                    sub.push_back(s[i]);
                }
            }

            if (sub.length() > 0)
            {
                ans.push_back(sub);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Solution s;
    vector<string> ans = s.AllPossibleStrings("abc");
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << ans[i] << " " << ans[i].size() << endl;
    }

    return 0;
}