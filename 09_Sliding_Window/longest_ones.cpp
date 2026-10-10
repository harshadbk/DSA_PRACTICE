#include<iostream>
using namespace std;

int longest_ones(int arr[], int size, int k) {
    int i = 0;
    int zeros = 0;
    int max_len = 0;

    for (int j = 0; j < size; j++) {

        if (arr[j] == 0)
            zeros++;

        while (zeros > k) {
            if (arr[i] == 0)
                zeros--;
            i++;
        }

        max_len = max(max_len, j - i + 1);
    }
    return max_len;
}

int main() {
    int arr[] = {1,1,1,0,0,0,1,1,1,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout << longest_ones(arr, size, k);
    return 0;
}
