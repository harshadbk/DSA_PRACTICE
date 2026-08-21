#include <iostream>
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

string postfixExpression(string infix)
{
    stack<char> c;
    string result;

    for (int i = 0; i < infix.size(); i++)
    {
        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            result += ch;
        }

        else if (ch == '(')
        {
            c.push(ch);
        }

        else if (ch == ')')
        {
            while (c.top() != '(')
            {
                result += c.top();
                c.pop();
            }
            c.pop(); // pop ) from stack
            
        }

        // if operator is scanned

        else
        {
            while (!c.empty() &&  c.top() != '(' && pres(c.top()) >= pres(ch))
            {
                result += c.top();
                c.pop();
            }
            c.push(ch); // push current elememt into stack
        }
    }

    // remaining elements
    while (!c.empty())
    {
        result += c.top();
        c.pop();
    }

    return result;
}

int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression " << exp << endl;
    string postfix = postfixExpression(exp);

    cout << postfix;

    return 0;
}