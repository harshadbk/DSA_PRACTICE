#include <iostream>
#include<algorithm>
using namespace std;

void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }

        swap(arr[i],arr[min]);
    }
}

void bubble_sort(int arr[],int size){
    for(int i=size;i>=1;i--){
        int didswap = 0;
        for(int j=0;j<i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap = 1;
            }
        }
        if(didswap==0){
            break;
        }
    }
}

void insertion_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j = i;

        while(j>0 && arr[j] < arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {12,45,23,65,11,29,60,100,21};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    printarr(arr,n);
    return 0;
}