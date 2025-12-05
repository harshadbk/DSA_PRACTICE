#include <iostream>
using namespace std;

void sorting_even_odd(int arr[], int size)
{
    int i = 0;
    int j = 1;

    while (i < size && j < size)
    {
        if (arr[i] % 2 == 0)
        {
            i += 2;
        }
        else if (arr[j] % 2 == 1)
        {
            j += 2;
        }
        else
        {
            swap(arr[i], arr[j]);
            i += 2;
            j += 2;
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {2, 5, 6, 8, 3, 9, 12, 27, 54, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    sorting_even_odd(arr, size);
    return 0;
}