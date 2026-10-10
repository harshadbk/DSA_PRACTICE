#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string ptp(string prefix)
{
    int n = prefix.size();

    stack<string> st;

    for (int i = n - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(t1 + t2 + ch);
        }
    }

    return st.top();
}

int main()
{
    string prefix = "/*+ab*cd/*ef-gh";
    string ans = ptp(prefix);
    cout << ans;
    return 0;
}