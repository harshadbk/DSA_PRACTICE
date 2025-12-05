#include <iostream>
using namespace std;

void partitioning_array(int arr[], int pivot, int size)
{
    int high = size - 1;
    int low = 0;
    int mid = 0;

    while (mid <= high)
    {
        if (arr[mid] < pivot)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] > pivot)
        {
            swap(arr[high], arr[mid]);
            high--;
        }
        else
        {
            mid++;
        }
    }
    cout << "Partitioning Array :" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {9, 7, 11, 23, 20, 10, 4, 7, 8, 11};
    int pivot = 11;
    int size = sizeof(arr) / sizeof(arr[0]);
    partitioning_array(arr, pivot, size);
    return 0;
}