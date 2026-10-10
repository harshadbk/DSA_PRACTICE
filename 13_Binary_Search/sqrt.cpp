#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num = 12;
    int ans = 0;

    int i = 0;
    int j = num / 2;
    while(i<j){
        int mid = i + (j-i) / 2;
        if(mid*mid == num){
            cout << mid;
            return 1;
        }
        else if(mid*mid < num){
            ans = mid;
            i = mid+1;
        }
        else {
            j = mid-1;
        }
    }
    cout << ans;
    return 0;
}