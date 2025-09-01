#include <iostream>
using namespace std;

void unique_value(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;  
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;   
            }
        }
        if (count == 1) {
            cout << arr[i] << " ";
        }
    }
}

void unique_value2(int arr [],int size){
    int result =0;
    for(int i=0;i<size;i++){
        result ^= arr[i];
    }
    cout <<endl<<result;
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unique values: ";
    unique_value(arr, size);

    unique_value2(arr, size);

    return 0;
}