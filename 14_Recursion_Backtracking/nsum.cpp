#include <iostream>
using namespace std;

int sum(int n){
    if(n==1){
        return 1;
    }
    return sum(n-1)+n;
}

int main() {
    cout << sum(5);
    return 0;
}