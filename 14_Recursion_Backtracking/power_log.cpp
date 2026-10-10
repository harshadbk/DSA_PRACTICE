#include <iostream>
using namespace std;

int calcpower(int a,int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int x = calcpower(a,b/2);
    if(b%2==0){
        return x*x;
    }
    else{
        return x*x*a;
    }
}

int main() {
    int a = calcpower(2,5);
    cout << a;
    return 0;
}