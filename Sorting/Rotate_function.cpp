#include<iostream>
using namespace std;

int max_rotate(int arr[],int size){
    int total_sum = 0;
    int f0 = 0;

    for(int i=0;i<size;i++){
        total_sum += arr[i];
        f0 += i * arr[i];
    }

    int current = f0;
    int result = f0;

    for(int i=1;i<size;i++){
        current = current + total_sum - size * arr[size-i];
        result = max(result,current);
    }

    return result;
}

int main(){
    int arr[] = {4,3,2,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << max_rotate(arr,size);
    return 0;
}