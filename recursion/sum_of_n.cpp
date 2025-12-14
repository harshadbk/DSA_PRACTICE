#include<iostream>
using namespace std;

int sum_n(int n){
    if(n==1){
        return 1;
    }
    else{
        return n + sum_n(n-1);
    }
}

int main(){
    cout<<sum_n(5);
    return 0;
}