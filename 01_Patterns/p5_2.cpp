#include <iostream>
using namespace std;

int main() {

    int n = 5;

    // Upper half
    for(int i = 0; i < n; i++) {

        // left space
        for(int j = 0; j < n-i-1; j++) {
            cout << " ";
        }

        // *
        for(int k = 0; k < i*2+1; k++) {
            cout << "*";
        }

        cout << endl;
    }


    // Lower half
    for(int i = 0; i < n-1; i++) {

        // left space
        for(int j = 0; j < i+1; j++) {
            cout << " ";
        }

        // *
        for(int k = 0; k < 2*n-2*i-3; k++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}