#include <iostream>
using namespace std;

int peak_element_in_mountain(int arr[], int size) {
    int start = 1;         
    int end = size - 2;  

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        else if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 4, 5, 7, 9, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = peak_element_in_mountain(arr, size);
    if (peakIndex != -1) {
        cout << "Peak element index: " << peakIndex << endl;
        cout << "Peak element value: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak found" << endl;
    }

    return 0;
}
