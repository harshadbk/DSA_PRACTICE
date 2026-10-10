#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 3;
    int sum = (n * (n+1)) / 2;
    int leftsum = 0;
    for(int i=1;i<=8;i++){
        leftsum += i;
        if(leftsum == (sum - leftsum + i)){
            cout << i;
            break;
        }
    }
    cout << -1;
    return 0;
}