#include <iostream>
using namespace std;

int single_element_in_sorted_array(int arr[], int size) {
    int s = 0;
    int end = size - 1;

    if (arr[0] != arr[1]) return arr[0];
    if (arr[size - 1] != arr[size - 2]) return arr[size - 1];

    while (s <= end) {
        int mid = s + (end - s) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            return arr[mid];
        }

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
            s = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int single = single_element_in_sorted_array(arr, size);
    cout << "Single element: " << single << endl;

    return 0;
}
