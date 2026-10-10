#include <iostream>
#include <algorithm>
using namespace std;

void min_max_swap(int arr[], int size) {
    int min_val = arr[0];
    int max_val = arr[0];
    int min_index = 0;
    int max_index = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_index = i;
        }
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_index = i;
        }
    }

    swap(arr[min_index], arr[max_index]);
}

int main() {
    int arr[] = {3, 1, 4, 6, 9, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    min_max_swap(arr, size);

    cout << "Array after swapping min and max: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}