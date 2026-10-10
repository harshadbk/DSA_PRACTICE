#include <iostream>
using namespace std;

int main() {
    int n =5;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){  // space on left
            printf(" ");
        }
        for(int k=0;k<2*i+1;k++){   // printing stars
            printf("*");
        }
         for(int j=0;j<n-i-1;j++){  // space on right
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}