#include <iostream>
#include <stack>
using namespace std;

int pres(char ch){

    if(ch == '^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch == '+' || ch=='-'){
        return 1;
    }
    else {
        return 0;
    }
}

string postfix(string s){
    string result;
    stack<char> c;
    // check operand if operand is there add it into result;

    for(int i=0;i<s.size();i++){
        if((s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= 'A' && s[i] <= 'Z') ||
           (s[i] >= '0' && s[i] <= '9')){
            result += s[i];
           }

        else if(s[i]=='('){
            c.push(s[i]);
        }

        else if(s[i] == ')'){
            while(c.top() != '('){
                result+=c.top();
                c.pop();
            }
            c.pop();
        }

        else {
            while(c.top() != '(' && pres(c.top()) >= pres(s[i])){
                result += c.top();
                c.pop();
            }
            c.push(s[i]);
        }
    }

    while(!c.empty()){
        result += c.top();
        c.pop();
    }

    return result;
}

int main() {
    string infix = "(a+b)*(c*d)/(e*f/(g-h))";
    string result = postfix(infix);
    cout << result;
    return 0;
}