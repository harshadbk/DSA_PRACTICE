#include<iostream>
#include<vector>
using namespace std;

int reversepair(vector<int>&arr,int size){
    int count = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j] * 2){
                count ++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> arr = {2,4,3,5,1};
    int size = arr.size();
    cout << reversepair(arr,size);
    return 0;
}