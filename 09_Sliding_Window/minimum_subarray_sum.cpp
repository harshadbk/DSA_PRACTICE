#include <iostream>
using namespace std;

int minimum_subarray_sum(int arr[], int size, int target)
{
    int sum = 0;
    int left = 0;
    int minLen = INT16_MAX;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        while (sum >= target)
        {
           minLen = min(minLen,i-left+1);
           sum -= arr[left];
           left++;
        }
    }
    return (minLen==INT16_MAX) ? 0 : minLen;
}

int main()
{
    int arr[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << minimum_subarray_sum(arr, size, target);

    return 0;
}