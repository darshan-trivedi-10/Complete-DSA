// https://takeuforward.org/data-structure/nth-root-of-a-number-using-binary-search/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

double multiply(double num, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * num;
    }

    return ans;
}

double findNthRootOfM(int n, long long m)
{
    // find (m) ^ (1/n)
    double high = m, low = 1;
    double eps = 1e-6;

    while ((high - low) > eps)
    {
        double mid = (high + low) / 2.0;
        // we can use pow function instead of multiply function.
        if (multiply(mid, n) > m)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}
