#include <iostream>
using namespace std;

void binary_search(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        else if (target > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << "No element found" << endl;
}

int main() {
    int arr[] = {1, 3, 4, 5, 8, 9, 12, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 1;

    binary_search(arr, size, target);

    return 0;
}
