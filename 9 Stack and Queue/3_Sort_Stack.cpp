#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

void sortStack(stack<int> &st)
{
    multiset<int> ms;
    while (!st.empty())
    {
        ms.insert(st.top());
        st.pop();
    }
    for (auto it : ms)
    {
        st.push(it);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}