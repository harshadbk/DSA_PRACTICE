#include<iostream>
#include<vector>
using namespace std;

int totalprime(int n){
    int count = 0;
    vector<bool> isprime (n+1,true);
    for(int i=2;i<n;i++){
        if(isprime[i]){
            count++;
        }
        for(int j=i*2;j<n;j=i+j){
            isprime[j] = false;
        }
    }
    return count;
}

int main(){
    cout<<totalprime(4);
    return 0;
}