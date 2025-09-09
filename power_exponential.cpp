#include <iostream>
using namespace std;

double mypow(double base, int exponent) {
    long long binForm = exponent;
    if (exponent < 0) {
        base = 1.0 / base;
        binForm = -binForm;
    }

    double ans = 1.0;
    while (binForm > 0) {
        if (binForm % 2 == 1) {
            ans *= base;
        }
        base *= base;
        binForm /= 2;
    }

    return ans;
}

int main() {
    double num = 2;
    int exponent = 3;
    cout << mypow(num, exponent) << endl;
    return 0;
}
