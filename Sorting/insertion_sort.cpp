#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    for(int i=0;i<size;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}


void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 1, 2, 8, 7, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    insertion_sort(arr, size);
    return 0;
}