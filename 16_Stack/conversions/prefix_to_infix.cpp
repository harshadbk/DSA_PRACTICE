#include <iostream>
#include <stack>
using namespace std;

string pti(string prefix){
    stack<string> s;
    int n = prefix.size();
    for(int i=n-1;i>=0;i--){
        if(isalnum(prefix[i])){
            s.push(string(1,prefix[i]));
        }
        else{
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            s.push("("+op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}



int main() {
    string prefix = "*+pq-m*nk";
    string infix_s = pti(prefix);

    cout << infix_s;
    return 0;
}