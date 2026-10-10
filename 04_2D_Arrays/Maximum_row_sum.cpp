#include<iostream>
using namespace std;

int maxsum(int arr[][5],int rows,int cols){
    int maxsum = 0;
    for(int i=0;i<rows;i++){
        int curr_sum = 0;
        for(int j=0;j<cols;j++){
            curr_sum += arr[i][j];
        }
        maxsum = max(maxsum,curr_sum);
    }
    return maxsum;
}

int main(){
      int arr[4][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {1,1,1,1,1},
        {2,2,2,2,2}
    };
    int row = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    cout << maxsum(arr,row,cols);
    return 0;
}