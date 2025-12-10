#include <iostream>
using namespace std;

pair<int,int> isfound(int arr[][5], int row, int cols, int target){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cols; j++){
            if(arr[i][j] == target){
                return {i, j}; 
            }
        }
    }
    return {-1, -1};
}

int main(){
    int arr[4][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20}
    };

    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);
    int target = 9;

    pair<int,int> ans = isfound(arr, rows, cols, target);

    if(ans.first == -1)
        cout << "Not Found";
    else
        cout << "Found at (" << ans.first << ", " << ans.second << ")";

    return 0;
}