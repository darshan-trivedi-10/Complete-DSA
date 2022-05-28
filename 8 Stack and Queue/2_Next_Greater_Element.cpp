// https://leetcode.com/problems/next-greater-element-i/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> nums1, vector<int> nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mpp;
        vector<int> ans;
        stack<int> st;
        for (int i = n2 - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                mpp.insert({nums2[i], -1});
                st.push(nums2[i]);
            }
            else
            {
                int topEle = st.top();
                while (!st.empty() and st.top() <= nums2[i])
                {
                    st.pop();
                    if (!st.empty())
                        topEle = st.top();
                }
                if (st.empty())
                {
                    mpp.insert({nums2[i], -1});
                    st.push(nums2[i]);
                }
                else
                {
                    mpp.insert({nums2[i], topEle});
                    st.push(nums2[i]);
                }
            }
        }

        for (int i = 0; i < n1; i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), temp(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> temp[i];
    }

    Solution s;
    arr = s.nextGreaterElement(temp, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}