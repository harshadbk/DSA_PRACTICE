#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int totalsubarray(vector<int> &nums){
    sort(nums.begin(),nums.end());

    int ceven = 0;
    int codd = 0;

    for(int i=0;i<nums.size();i++){
        int prev = nums[0];
        if(prev==nums[i])
        {
            continue;
        }
        else{
            if(nums[i] % 2 == 0){
                ceven ++;
            }
            else{
                codd ++;
            }
        }
    }
cout << ceven;
cout << codd;
}

int main(){
    vector<int> nums {2,3,4,2,5};
    totalsubarray(nums);
    return 0;
}