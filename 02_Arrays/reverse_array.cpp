#include<iostream>
#include<algorithm>
using namespace std;

void reverse_array(int arr[],int size){
   int start=0,end=size-1;

   while(start<end){
    swap(arr[start],arr[end]);
    start++;
    end--;
   }
};

int main(){
    int arr[]={1,3,5,7,9,2};
    int size = 6;
    reverse_array(arr,size);
    for(int i=0;i<size;i++){
        cout << arr[i] << endl;
    }
    return 0;
}