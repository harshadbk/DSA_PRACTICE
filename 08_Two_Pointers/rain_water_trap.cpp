#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {4,2,0,3,2,5};
    int maxleft = 0;
    int maxrit = 0;
    int l =0;
    int r = nums.size()-1;
    int water = 0;

    while(l<r){
        if(nums[l] <= nums[r]){
            if(maxleft >= nums[l]){
                water += maxleft - nums[l];
            }
            else 
              maxleft = nums[l];
            l++;
        }
        else {
            if(maxrit >= nums[r]){
                water += maxrit - nums[r];
            }
            else 
              maxrit = nums[r];
            r--;
        }
    }

    cout << water;

    return 0;
}