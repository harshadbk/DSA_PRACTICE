#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void nextgreaterele(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    unordered_map<int, int> mp;

    int n = nums2.size();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() < nums2[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        else
        {
            mp[nums2[i]] = -1;
            st.push(nums2[i]);
        }
    }

    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mp[nums1[i]]);
    }
}

int main()
{
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};

    nextgreaterele(nums1, nums2);
    return 0;
}