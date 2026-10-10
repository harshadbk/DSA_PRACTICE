#include <iostream>
#include <climits>  
using namespace std;

int main() {
    int arr[] = {1, 10, 2, 7, 4, 5, 9, 12, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallest = INT_MAX;
    int largest = INT_MIN;
    int smallIndex = -1;
    int largeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallIndex = i;
        }
        if (arr[i] > largest) {
            largest = arr[i];
            largeIndex = i;
        }
    }

    cout << "Largest element: " << largest << " at index " << largeIndex << endl;
    cout << "Smallest element: " << smallest << " at index " << smallIndex << endl;

    return 0;
}
