#include<iostream>
using namespace std;

int main(){
    long long fact = 1;
    for(long long i=1;i<=13;i++){
        fact*=i;
    }
    cout << fact;
    return 0;
}