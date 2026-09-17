#include <iostream>
using namespace std;

void printn(int n){
    if(n==0){
        cout << 0 << " ";
        return;
    }
    cout << n << " ";
    printn(n-1);
}

int main() {
    printn(34);
    return 0;
}