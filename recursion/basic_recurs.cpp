#include <iostream>
using namespace std;

int calcfact(int n){
    if(n==1){
        cout << 1;
    }
    else{
        return n*calcfact(n-1);
    }
}

int main() {
   int ans =  calcfact(5);
    cout << ans;
    return 0;
}