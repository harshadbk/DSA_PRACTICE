#include <iostream>
using namespace std;

int rotated_binary_search(int arr[], int target, int size) {
    int st = 0;
    int end = size - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        // Found the target
        if (arr[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (arr[st] <= arr[mid]) {
            if (arr[st] <= target && target < arr[mid]) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (arr[mid] < target && target <= arr[end]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    return -1; // target not found
}

int main() {
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    int target = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    int index = rotated_binary_search(arr, target, size);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
