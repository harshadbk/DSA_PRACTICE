#include<iostream>
using namespace std;

void sorted_colors(int arr[],int size){
    int low = 0;
    int high = size-1;
    int mid = 0;
    while (mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }

    cout << "Sorted Colors :"<<endl;

    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }

    
}

int main(){
    int arr[] = {2,1,0,2,1,1,2,0,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    sorted_colors(arr,size);
    return 0;
}