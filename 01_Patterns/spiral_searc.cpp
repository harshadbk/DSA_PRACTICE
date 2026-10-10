#include <iostream>
#include <vector>
using namespace std;

void traverse(vector<vector<int>> &nums){
    int top = 0;
    int l = 0;
    int r = nums[0].size()-1;
    int bottom = nums.size()-1;

    while(top <= bottom && l <= r){
        for(int i=l;i<=r;i++){
            cout << nums[top][i] << " ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout << nums[i][r] << " ";
        }
        r--;
        if(top<=bottom){
        for(int i=r;i>=l;i--){
            cout << nums[bottom][i] << " ";
        }
        bottom--;
    }

    if(l<=r){
        for(int i=bottom;i>=top;i--){
            cout << nums[i][l] << " ";
        }
        l++;
    }
    }
}

int main() {
    vector<vector<int>> nums {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    traverse(nums);
    return 0;
}