#include<iostream>
#include<vector>
using namespace std;

int maxsum(vector<vector<int>> &nums){
    int sum = 0;
    int mine = INT16_MAX;
    int negcount = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val = nums[i][j];
            if(val<0){
                negcount ++;
            }
            sum += abs(val);
            mine = min(mine,abs(val));
        }
    }
    if(negcount%2==1){
        sum-=2*mine;
    }

    return sum;
    
}

int main(){
    vector<vector<int>> nums = {{1,2,3},{-1,-2,-3},{1,2,3}};
    cout << maxsum(nums);
    return 0;
}