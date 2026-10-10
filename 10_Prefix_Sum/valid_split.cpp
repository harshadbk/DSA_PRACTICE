#include<iostream>
#include<vector>
using namespace std;

int totalsplit(vector<int> &nums){
     int validsplit = 0;
        int totalsum = 0;
        for(int n:nums){
            totalsum += n;
        }
        int leftsum = 0;
        for(int i=0;i<nums.size()-1;i++){
            leftsum += nums[i];
            int right_sum = totalsum - leftsum;
            if(right_sum<leftsum){
                validsplit++;
            }
        }
        return validsplit;
}

int main(){
    vector<int> arr = {10,4,-8,7};
    cout<<totalsplit(arr);
    return 0;
}