#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string ptp(string postfix)
{
    string ans = "";
    stack<string> st;

    int n = postfix.size();

    for (int i = 0; i < n; i++)
    {
        char ch = postfix[i];

        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            st.push(ch+top2+top1);
        }
    }
    return st.top();
}

int main()
{

    string postfix = "ab+cd**ef*gh-//";

    string ans = ptp(postfix);

    cout << ans;

    return 0;
}