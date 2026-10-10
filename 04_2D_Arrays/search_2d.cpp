#include<iostream>
#include<vector>
using namespace std;

bool rowcheck(vector<vector<int>> &arr,int target,int row){
    int n = arr[0].size();
    int st = 0;
    int ed = n-1;
    while (st <= ed)
    {
        int mid = st + (ed-st)/2;
        if(arr[row][mid]==target){
            return true;
        }
        else if(arr[row][mid]>target) {
            ed = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    return false;
    
}

bool is_available(vector<vector<int>> &arr,int target){
  int m = arr.size();
  int n = arr[0].size();
  int strow = 0;
  int edrow = m-1;
  while (strow<=edrow)
  {
    int mid = strow + (edrow-strow)/2;
    if(target >= arr[mid][0] && target <= arr[mid][n-1]){ // target found
        return rowcheck(arr,target,mid);
    }
    else if(target <= arr[mid][0]){
        edrow = mid - 1;
    }
    else {
        strow = mid + 1;
    }
  }
  return false;
  
}

int main(){
    vector<vector<int>> arr {
        {2,5,7,9},
        {10,12,16,20},
        {22,23,28,29},
        {30,33,34,38}};

    int target = 23;
    cout << is_available(arr,target);
    return 0;
}