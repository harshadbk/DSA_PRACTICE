#include<iostream>
using namespace std;

int minswap(string s){
    int open = 0;
    int close = 0;
    int minswap = 0;
    for(char c:s){
        if(c=='['){
            open++;
        }
        else{
            close++;
        }
        if(close>open){
            minswap++;
            close--;
            open++;
        }
    }
    return minswap;
}

int main(){
    string s = "][[[]]";
    cout << minswap(s);
    return 0;
}