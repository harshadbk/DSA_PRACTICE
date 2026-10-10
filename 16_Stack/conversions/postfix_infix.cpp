#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string pti(string postfix)
{
    string ans = "";
    stack<string> st;

    for (int i = 0; i < postfix.size(); i++)
    {
        char ch = postfix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            st.push(string(1, ch));
        }
        else
        {
            string ele1 = st.top();
            st.pop();
            string ele2 = st.top();
            st.pop();
            st.push("(" + ele2 + ch + ele1 + ")");
        }
    }
    return st.top();
}

int main()
{
    string postfix = "ab+cd**ef*gh-//";
    string ans = pti(postfix);
    cout << ans;
    return 0;
}