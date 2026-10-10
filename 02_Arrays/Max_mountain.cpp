#include <iostream>
using namespace std;
int Max_mountain(int arr[], int size)
{
    int largest = 0;
    for(int i=1;i<size;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            int left = i-1;
            int right = i+1;

            //expand left
            while (left > 0 && arr[left]>arr[left-1])
            {
                left--;
            }

            // expand right
            while (right<size-1 && arr[right]<arr[right++])
            {
                right++;
            }
            
            largest = max(largest,right-left+1);
        }
    }

    return largest;
}
int main()
{
    int arr[] = {2, 1, 4, 7, 3, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << Max_mountain(arr,size);
    return 0;
}