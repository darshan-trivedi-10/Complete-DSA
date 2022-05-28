// https://www.interviewbit.com/problems/nearest-smaller-element/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'


vector<int> prevSmaller(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            ans.push_back(-1);
            st.push(arr[i]);
        }
        else
        {
            int topElem = st.top();
            while (!st.empty() and arr[i] <= topElem)
            {
                st.pop();
                if (!st.empty())
                    topElem = st.top();
            }

            if (st.empty())
            {
                ans.push_back(-1);
                st.push(arr[i]);
            }
            else
            {
                ans.push_back(topElem);
                st.push(arr[i]);
            }
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> temp = prevSmaller(arr);

    return 0;
}