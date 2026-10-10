#include <iostream>
using namespace std;

int main() {
    int n =5;
    int count = 0;
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            // count++;
            cout << j << " ";
        }
        printf("\n");
    }
    return 0;
}