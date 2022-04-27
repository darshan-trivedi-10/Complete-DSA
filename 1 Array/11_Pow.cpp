// https://leetcode.com/problems/powx-n/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
    double fastPower(double x, long long int n)
    {
        double ans = 1.00;
        while (n > 0)
        {
            if (n & 1)
            {
                ans = ans * x;
            }

            x *= x;
            n /= 2;
        }

        return ans;
    }

public:
    double myPow(double x, int n)
    {

        double ans = fastPower(x, abs(n - 0));
        cout << ans << " ";
        if (n < 0)
        {
            return (double(1.000)) / ans;
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