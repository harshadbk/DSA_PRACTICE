#include <iostream>
using namespace std;

int rounded_sqrt(int x) {
    if (x == 0 || x == 1) return x;

    int left = 1, right = x / 2;
    int floorVal = 1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sq = mid * mid;

        if (sq == x) return mid;

        if (sq < x) {
            floorVal = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    long long remainder = x - 1LL * floorVal * floorVal;

    long long nextSquare = 1LL * (floorVal + 1) * (floorVal + 1);
    long long gap = nextSquare - x;

    if (remainder == 0) return floorVal;         
    if (remainder >= gap) return floorVal + 1;    
    return floorVal;                              
}

int main() {
    cout << rounded_sqrt(17) << endl;
    cout << rounded_sqrt(8) << endl;
    cout << rounded_sqrt(24) << endl; 
    cout << rounded_sqrt(26) << endl;
}
