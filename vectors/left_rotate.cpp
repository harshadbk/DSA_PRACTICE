#include <iostream>
#include <algorithm>
using namespace std;

void leftrotate(int arr[],int k,int n){
    int i=0,j=k-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

    i=k,j=n-1;
    while(i<=j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

    i=0,j=n-1;
    while (i<=j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
}

int main() {
    int arr [] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    leftrotate(arr,k,n);
    printarr(arr,n);
    return 0;
}