#include <iostream>
using namespace std;

int linearsearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 7, 3, 5, 12, 9, 8, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int index = linearsearch(arr, size, target);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in array" << endl;
    }

    return 0;
}
