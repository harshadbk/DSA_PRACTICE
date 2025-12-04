#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }

    // sorted Array

    for(int i=0;i<size;i++){
        cout << arr[i]<<endl;
    }
}

int main(){
    int arr[] = {4,1,5,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    return 0;
}