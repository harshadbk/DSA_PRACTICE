#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> t_sum(vector<int> &nums,int size){
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i=0;i<size;i++){
        int j=i+1;
        int k = size-1;
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        while (j<k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while (j<k && nums[j]==nums[j-1])
                {
                    j++;
                }
                while (j<k && nums[k]==nums[k-1])
                {
                    k--;
                }
            }
        }       
    }
    return ans; 
}

int main(){

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int size = nums.size();

    vector<vector<int>> result = t_sum(nums, size);

    cout << "Triplets are:\n";
    for(auto &triplet : result){
        cout << "[ ";
        for(int x : triplet){
            cout << x << " ";
        }
        cout << "]\n";
    }
    return 0;
}