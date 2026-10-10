#include <iostream>
using namespace std;

int fact = 1;

void factorial(int n){
    if(n==0 || n==1){
        cout << fact;
        return;
    }
    fact = fact*n;
    factorial(n-1);
}

int main() {
    factorial(2);
    return 0;
}