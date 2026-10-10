#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums {-1,2,1,-4};
    sort(nums.begin(),nums.end());
    int target = 1;
    int closestsum = nums[0] + nums[1] + nums[2];

    for(int i=0;i<nums.size()-2;i++){
        int left = i+1;
        int rit = nums.size()-1;

        while(left < rit){
            int currsum = nums[i] + nums[left] + nums[rit];
            if(abs(currsum-target) < abs(closestsum-target)){
                closestsum = currsum;
            }
            else if(currsum > target){
                rit--;
            }
            else if(currsum < target){
                left++;
            }
            else {
                cout << currsum;
                return 0;
            }
        }
    }
    cout << closestsum;
    return 0;
}