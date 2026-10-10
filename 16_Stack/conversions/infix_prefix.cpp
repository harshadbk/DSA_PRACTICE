#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int pres(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

string getprefix(string infix)
{
    reverse(infix.begin(), infix.end());
    stack<char> st;
    string ans = "";

    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            ans += ch;
        }

        else if (ch == ')')
        {
            st.push(ch);
        }

        else if (ch == '(')
        {
            while (st.top() != ')')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && st.top() != ')' && (pres(ch) < pres(st.top()) || (ch=='^' && st.top() == '^')))
            {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string infix = "(p+q)*(m-n*k)";
    string prefix = getprefix(infix);

    cout << prefix;
    return 0;
}