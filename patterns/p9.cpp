#include <iostream>
using namespace std;

int main() {
    int n=8;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){ // first spaces
            cout <<" ";
        }
        for(int k=1;k<=i+1;k++){ // digits
            cout << k;
        }

        for(int l=i;l>=1;l--){ //2nd set of digits
            cout << l;
        }
        cout << endl;
    }
    return 0;
}