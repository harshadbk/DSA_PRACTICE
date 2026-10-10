#include<iostream>
#include<vector>
using namespace std;

bool issorted(vector<int> &arr,int size){
    if(size==0||size==1){
        return true;
    }
    return arr[size-1] >= arr[size-2] && issorted(arr,size-1);
}

int main(){

    vector<int> arr = {2,3,8,6,7,9};
    int size = arr.size();
    cout << issorted(arr,size);
    return 0;
}