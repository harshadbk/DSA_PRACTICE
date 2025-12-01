#include <iostream>
using namespace std;

int main() {
    cout << "Enter 1st array of 3X3:\n";
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter 2nd array of 3X3:\n";
    int b[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> b[i][j];
        }
    }

    cout << "Addition of matrices:\n";
    int sum[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// done
