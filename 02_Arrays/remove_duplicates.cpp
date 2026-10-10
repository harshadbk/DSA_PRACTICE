#include <iostream>
using namespace std;

int removeduplicates(int arr[], int size)
{
    if (size <= 2)
    {
        return size;
    }
    int k = 2;
    for (int i = 2; i < size; i++)
    {
        if (arr[i] != arr[k - 2])
        {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

int main()
{
    int arr[]={1,1,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << removeduplicates(arr,size);
    return 0;
}