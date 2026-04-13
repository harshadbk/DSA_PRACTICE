#include <iostream>
using namespace std;

int main() {
    int count = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            count += 1;
            cout<< count << " ";
        }
        printf("\n");
    }
    return 0;
}