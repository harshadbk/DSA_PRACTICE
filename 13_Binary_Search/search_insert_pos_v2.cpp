#include<iostream>
using namespace std;

int searchinsert(int arr[],int target){
  int st = 0;int end = 9;
  while (st<=end)
  {
    int mid = st + (end-st) /2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        st = mid + 1;
    }
    else{
        end = mid -1;
    }
  }
  return st;
}

int main(){
    int arr [] = {1,2,3,4,5,6,8,9,10};
    int target = 7;
    cout << searchinsert(arr,target);
    return 0;
}